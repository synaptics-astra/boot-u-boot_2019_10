// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016~2023 Synaptics Incorporated. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 or
 * later as published by the Free Software Foundation.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS," AND
 * SYNAPTICS EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE, AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY
 * INTELLECTUAL PROPERTY RIGHTS. IN NO EVENT SHALL SYNAPTICS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, OR
 * CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED AND
 * BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF
 * COMPETENT JURISDICTION DOES NOT PERMIT THE DISCLAIMER OF DIRECT
 * DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS' TOTAL CUMULATIVE LIABILITY
 * TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S. DOLLARS.
 */

#include <common.h>
#include <command.h>
#include <stdlib.h>
#include <env.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <asm/global_data.h>
#include <asm/io.h>
#include <linux/libfdt.h>
#include "mem_region_userdata.h"
#include "mem_init.h"
#include "Galois_memmap.h"
#include "global.h"
#include "fastboot_syna.h"
#include "misc_syna.h"
#include "pmic.h"

#define DTB_SPACE (0x20000 - 0x100)
#define BERLIN_HEAP_COMPATIBLE_NAME "syna,berlin-heaps"
#define POOL_NUM "pool-num"
#define ATTR_NUM_PER_POOL "attributes-num-per-pool"
#define POOL_ATTRIBUTES "pool-attributes"
#define MAX_SYSTEM_SLOT (MAX_SYSTEM_POOL_NUM + 1) /* max_system_pool_num + 1 */

#define ROOTFS_CONFIG_LINE "root=/dev/mmcblk"
#define ROOTFS_A "rootfs_a"
#define ROOTFS_B "rootfs_b"

extern int f_mmc_get_part_index(char *part_name);

static void setup_cma_param(char *bootargs)
{
	char tmp_buf[128];

	/* Notice: strict check for the cma_pool_addr should be non-zero */
	if (get_cma_size() && get_cma_addr()) {
		memset(tmp_buf, 0x0, sizeof(tmp_buf));
		snprintf(tmp_buf, (sizeof(tmp_buf) - 1), "cma=%d@%d", get_cma_size(), get_cma_addr());
		strcat(bootargs, tmp_buf);
	}
}

static int setup_reserved_mem(void *fdt, struct mem_region *reserved_mem, int reserved_num)
{
	struct fdt_header *header = (struct fdt_header *)fdt;
	u32 offset = fdt32_to_cpu(header->off_mem_rsvmap);
	struct fdt_reserve_entry *mem_reserve;
	int i;

	if (reserved_num <= 0 || !reserved_mem)
		return -1;

	mem_reserve = (struct fdt_reserve_entry *)(((unsigned char *)fdt) + offset);

	for (i = 0; ; i++) {
		mem_reserve += i;

		if (i < reserved_num) {
			mem_reserve->address = cpu_to_fdt64(reserved_mem[i].base);
			mem_reserve->size = cpu_to_fdt64(reserved_mem[i].size);
		} else {
			if (!fdt64_to_cpu(mem_reserve->size))
				break;
			mem_reserve->address = cpu_to_fdt64(0x0);
			mem_reserve->size = cpu_to_fdt64(0x0);
		}
	}

	return 0;
}

static int setup_ion_mem(void *fdt, struct mem_region *ion_mem, int ion_num)
{
	u32 mem_region_property[4 * MAX_REGION_COUNT];
	int offset;
	int i, ret, len, memcount = 0;
	char reg_names[MAX_REGION_COUNT * 16];

	if (ion_num <= 0 || !ion_mem)
		return -1;

	/* let's give it all the room it could need */
	ret = fdt_open_into(fdt, fdt, DTB_SPACE);
	if (ret < 0)
		return ret;

	offset = fdt_node_offset_by_compatible(fdt, -1, BERLIN_HEAP_COMPATIBLE_NAME);
	if (offset == -FDT_ERR_NOTFOUND) {
		printf("can't find ion node in dtb\n");
		return offset;
	}

	fdt_get_property(fdt, offset, POOL_NUM, &len);
	mem_region_property[0] = cpu_to_fdt32(ion_num);
	fdt_setprop(fdt, offset, POOL_NUM, mem_region_property, 4);

	for (memcount = 0, i = 0; i < ion_num; i++) {
		mem_region_property[memcount++] = cpu_to_fdt32(0x0);
		mem_region_property[memcount++] = cpu_to_fdt32(ion_mem[i].base);
		mem_region_property[memcount++] = cpu_to_fdt32(0x0);
		mem_region_property[memcount++] = cpu_to_fdt32(ion_mem[i].size);
	}

	fdt_setprop(fdt, offset, "reg", mem_region_property, 4 * memcount);

	for (len = 0, i = 0; i < ion_num; i++) {
		strcpy(reg_names + len, ion_mem[i].name);
		len += strlen(ion_mem[i].name) + 1;
	}
	ret = fdt_setprop(fdt, offset, "reg-names", reg_names, len);

	mem_region_property[0] = cpu_to_fdt32(2);
	fdt_setprop(fdt, offset, ATTR_NUM_PER_POOL, mem_region_property, 4);

	for (memcount = 0, i = 0; i < ion_num; i++) {
		mem_region_property[memcount++] = cpu_to_fdt32(TEE_MR_ION_ALG(ion_mem + i));
		mem_region_property[memcount++] = cpu_to_fdt32(TEE_MR_ION_ATTRIB(ion_mem + i));
	}
	fdt_setprop(fdt, offset, POOL_ATTRIBUTES, mem_region_property, 4 * memcount);

	return fdt_pack(fdt);
}

static int setup_system_mem(void *fdt, struct mem_region *system_mem, int system_num)
{
	u32 mem_region_property[4 * MAX_SYSTEM_SLOT];
	int memcount = 0;
	int offset = 0;
	int len = 0, i = 0;
	int ret;

	if (system_num > MAX_SYSTEM_SLOT || system_num <= 0)
		return -1;

	/* let's give it all the room it could need */
	ret = fdt_open_into(fdt, fdt, DTB_SPACE);
	if (ret < 0)
		return ret;

	offset = fdt_path_offset(fdt, "/memory");
	fdt_get_property(fdt, offset, "reg", &len);

	for (i = 0; i < system_num; i++) {
		mem_region_property[memcount++] = cpu_to_fdt32(0x0);
		mem_region_property[memcount++] = cpu_to_fdt32(system_mem[i].base);

		mem_region_property[memcount++] = cpu_to_fdt32(0x0);
		mem_region_property[memcount++] = cpu_to_fdt32(system_mem[i].size);
	}

	fdt_setprop(fdt, offset, "reg", mem_region_property, 4 * memcount);

	return fdt_pack(fdt);
}

int setup_tz_mem(void *fdt)
{
	struct mem_region ion_mem[MAX_REGION_COUNT];
	struct mem_region system_mem[MAX_SYSTEM_POOL_NUM];
	struct mem_region bl_mem[1];
	struct mem_region reserved_mem[MAX_REGION_COUNT];

	int ion_num = 0, system_num = 0, bl_num = 0, reserved_num = 0;

	memset(system_mem, 0x0, sizeof(system_mem));
	get_system_mem(system_mem, &system_num);

	memset(bl_mem, 0x0, sizeof(bl_mem));
	get_bl_mem(bl_mem, &bl_num);
	if (bl_num) {
		if (bl_num == 1 && system_num < MAX_SYSTEM_SLOT)
			memcpy(system_mem + system_num++, bl_mem, sizeof(struct mem_region));
		else
			printf("NO system slot for Bootloader\n");
	}

	if (system_num)
		setup_system_mem(fdt, system_mem, system_num);

	memset(ion_mem, 0x0, sizeof(ion_mem));
	get_ion_mem(ion_mem, &ion_num);
	if (ion_num)
		setup_ion_mem(fdt, ion_mem, ion_num);

	/* reserved mem is the overlap between system and ion */
	memset(reserved_mem, 0x0, sizeof(reserved_mem));
	get_reserved_mem(reserved_mem, &reserved_num);
	if (reserved_num)
		setup_reserved_mem(fdt, reserved_mem, reserved_num);

	return 0;
}

static void setup_rootfs(char *bootargs)
{
	int index = -1, mmc_dev = -1;
	char index_str[8];

	mmc_dev = get_mmc_active_dev();
	if (mmc_dev != 0 && mmc_dev != 1)
		return;

	/*update rootfs partition*/
	strcat(bootargs, ROOTFS_CONFIG_LINE);
	if (get_current_slot() == BOOTSEL_A)
		index = f_mmc_get_part_index(ROOTFS_A);
	else
		index = f_mmc_get_part_index(ROOTFS_B);

	if (index >= 0) {
		sprintf(index_str, "%dp%d", mmc_dev, index);
		strcat(bootargs, index_str);
		strcat(bootargs, " ro");
	}
}

int setup_bootargs(void *fdt)
{
	int len = 0;
	char *newbootargs = NULL;
	char *bootargs = env_get("bootargs");

	if (!bootargs) {
		printf("Don't see bootargs ENV, skip updating\n");
		return 0;
	}

	len = strlen(bootargs);
	newbootargs = malloc(len + 256);
	if (!newbootargs) {
		printf("Error: malloc in %s failed!\n", __func__);
		return -ENOMEM;
	}

	strcpy(newbootargs, bootargs);
	strcat(newbootargs, " ");

	setup_rootfs(newbootargs);
	strcat(newbootargs, " ");

	setup_cma_param(newbootargs);
	env_set("bootargs", newbootargs);

	return 0;
}

static int get_volt(struct leakage_table *lt, int leakage)
{
	struct leakage_table *p = NULL;

	if (!lt) {
		printf("No PV table found!!!!\n");
		return -1;
	}

	if (leakage > 0xffff) {
		printf("Invalid Leakage value %x!!!!\n", leakage);
		return -1;
	}

	p = lt;
	while (p) {
		if (leakage <= p->info)
			return p->volt;
		p++;
	}

	return -1;
}

static int get_vh_vl(struct freq_leakage_table *flt, int leakage, unsigned int *opp)
{
	int volt = 0;
	unsigned int count = 0;

	if (!flt) {
		printf("No PV table found!!!!\n");
		goto error;
	}

	/* vl */
	if (flt->freq <= 0)
		goto error;

	volt = get_volt(flt->lt, leakage);
	if (volt > 0)
		opp[count++] = volt;

	/* vh */
	flt++;
	if (flt->freq <= 0)
		goto error;

	volt = get_volt(flt->lt, leakage);
	if (volt > 0)
		opp[count++] = volt;

	if (count > 1) {
		debug("Got %d value for vl(%d) and vh(%d)\n", count, opp[0], opp[1]);
		return 0;
	}

error:
	printf("###### wrong value for vl and vh!!!!!!!!\n");
	return -1;
}

static int get_vh_freq(struct freq_leakage_table *flt)
{
	if (!flt) {
		printf("No PV table found!!!!\n");
		goto error;
	}

	/* vh */
	flt++;
	if (flt->freq <= 0 || flt->freq > 2500)
		goto error;

	return flt->freq;

error:
	printf("###### wrong value for vh frequency!!!!!!!!\n");
	return 0;
}

static void update_opp_node(void *buf, int offset, unsigned int vh, unsigned int vl, unsigned int vh_freq)
{
	int node;
	const unsigned int *p;
	unsigned int v1, v3, vol_h[3], vol_l[3];
	char vh_freq_name[20];

	/* opp-microvolt = <vh vh vh>; */
	vol_h[2] = cpu_to_fdt32(vh);
	vol_h[1] = cpu_to_fdt32(vh);
	vol_h[0] = cpu_to_fdt32(vh);

	/* opp-microvolt = <vl vl vh>; */
	vol_l[2] = cpu_to_fdt32(vh);
	vol_l[1] = cpu_to_fdt32(vl);
	vol_l[0] = cpu_to_fdt32(vl);

	for (node = fdt_first_subnode(buf, offset); node >= 0;
			node = fdt_next_subnode(buf, node)) {
		p = fdt_getprop(buf, node, "opp-microvolt", NULL);
		if (!p)
			continue;
		v1 = fdt32_to_cpu(*p);
		p += 2;
		v3 = fdt32_to_cpu(*p);
		if (v1 < v3) {
			fdt_setprop(buf, node, "opp-microvolt", vol_l, sizeof(vol_l));
		} else {
			if (vh_freq > 0 && vh_freq < 2500) {
				snprintf(vh_freq_name, 20, "opp@%lu", vh_freq * 1000000);
				fdt_set_name(buf, node, vh_freq_name);
			}
			fdt_setprop(buf, node, "opp-microvolt", vol_h, sizeof(vol_h));
		}
	}
}

static void update_opp_vcpu(void *fdt, unsigned int vcpuh, unsigned int vcpul, unsigned int vcpuh_freq)
{
	int offset;

	offset = fdt_path_offset(fdt, "/cpus/opp_table0");
	if (offset < 0) {
		debug("didn't find point of /cpus/opp_table0\n");
		return;
	}

	update_opp_node(fdt, offset, vcpuh, vcpul, vcpuh_freq);
}

static void update_opp_vcore(void *fdt, unsigned int vcoreh, unsigned int vcorel, unsigned int vcoreh_freq)
{
	int offset;

	offset = fdt_path_offset(fdt, "/soc/vcore_opp_table");
	if (offset < 0) {
		debug("didn't find point of /soc/vcore_opp_table\n");
		return;
	}

	update_opp_node(fdt, offset, vcoreh, vcorel, vcoreh_freq);
}

static int setup_opp(void *fdt)
{
	u32 opp[2];
	int ret = 0;
	int leakage = get_leakage();
	struct freq_leakage_table *flt = NULL;

	if (leakage < 0) {
		printf("leakage value error\n");
		return -1;
	}

	flt = get_vcpu_leakage_table();
	ret = get_vh_vl(flt, leakage, opp);
	if (ret == 0)
		update_opp_vcpu(fdt, opp[1], opp[0], get_vh_freq(flt));

	opp[0] = 0u;
	opp[1] = 0u;
	flt = get_vcore_leakage_table();
	ret = get_vh_vl(flt, leakage, opp);
	if (ret == 0)
		update_opp_vcore(fdt, opp[1], opp[0], get_vh_freq(flt));

	return 0;
}

int fdt_update(struct fdt_header *fdt)
{
	setup_tz_mem(fdt);
	setup_bootargs(fdt);
	setup_opp(fdt);

	return 0;
}

