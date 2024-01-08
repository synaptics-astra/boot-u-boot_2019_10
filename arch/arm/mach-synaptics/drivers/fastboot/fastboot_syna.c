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

#include <config.h>
#include <common.h>
#include <div64.h>
#include <malloc.h>
#include "mmc.h"
#include "misc_syna.h"
#include "fastboot_syna.h"

#define BOOTCTRL_MAGIC				0x42424100
#define BOOT_CONTROL_VERSION		1
#define ANDROID_AB_COMMAND_KEY		"bootctrl.metadata"
#define BOOTCTRL_HAL_FTS_LENGH		0x20
#define MISC_BOOT_CONTROL_VERSION  2

typedef struct syna_slot_metadata {
	uint8_t priority : 4;
	uint8_t tries_remaining : 3;
	uint8_t successful_boot : 1;
} syna_slot_metadata_t;

typedef struct boot_ctrl {
	u32 magic;		// Magic for identification - '\0ABB' (Boot Contrl Magic)
	u8 version;		// boot ctrl version, 1
	 syna_slot_metadata_t slot_info[2];	// Information about each slot
	u8 reserved;		// reserved
} boot_ctrl_t;

typedef struct misc_slot_metadata {
	u8 priority;
	u8 tries_remaining;
	// 1 if this slot has booted successfully, 0 otherwise.
	u8 successful_boot;
	// 1 if this slot is corrupted from a dm-verity corruption, 0 otherwise.
	u8 verity_corrupted;
	u8 reserved;
} misc_slot_metadata_t;

typedef struct misc_boot_ctrl {
	u32 magic;
	u8 version;
	u8 recovery_tries_remaining;
	misc_slot_metadata_t slot_info[2];
	u8 reserved[16];
} misc_boot_ctrl_t;

static bool is_valid_bootctrl(void *p_bootctrl)
{
	misc_boot_ctrl_t *pbctrl = (misc_boot_ctrl_t *)p_bootctrl;

	return ((pbctrl->magic == BOOTCTRL_MAGIC) && (pbctrl->version == MISC_BOOT_CONTROL_VERSION));
}

static bool slot_is_bootable(misc_slot_metadata_t *p_slot)
{
	return p_slot->priority > 0 && (p_slot->successful_boot || (p_slot->tries_remaining > 0));
}

static int write_bootctrl_metadata(void *p_bootctrl)
{
	if (!p_bootctrl) {
		printf("ERROR: invalid bootctrl metadata for write !\n");
		return -1;
	}

	struct blk_desc *dev_desc;
	disk_partition_t info;
	lbaint_t strat_blk, size_blk;
	int mmc_dev = get_mmc_boot_dev();
	struct mmc *mmc = find_mmc_device(mmc_dev);

	if (!mmc) {
		printf("invalid mmc device\n");
		return -1;
	}

	dev_desc = blk_get_dev("mmc", mmc_dev);
	if (!dev_desc || dev_desc->type == DEV_TYPE_UNKNOWN) {
		printf("invalid mmc device\n");
		return -1;
	}

	char *partition_name = "misc";

	if (part_get_info_by_name(dev_desc, partition_name, &info) == -1) {
		printf("cannot find partition: '%s'\n", partition_name);
		return -1;
	}
	strat_blk = info.start + 4096 / dev_desc->blksz;
	size_blk = (sizeof(misc_boot_ctrl_t) + dev_desc->blksz) / dev_desc->blksz;
	blk_dwrite(dev_desc, strat_blk, size_blk, p_bootctrl);

	return 0;
}

static int get_bootctrl_metadata(void *p_bootctrl)
{
	if (!p_bootctrl) {
		printf("Error: invalid parameter p_bootctrl !\n");
		return -1;
	}

	struct blk_desc *dev_desc;
	disk_partition_t info;
	lbaint_t strat_blk;
	int mmc_dev = get_mmc_boot_dev();
	struct mmc *mmc = find_mmc_device(mmc_dev);
	char *misc_bootctrl;

	if (!mmc) {
		printf("invalid mmc device\n");
		return -1;
	}

	dev_desc = blk_get_dev("mmc", mmc_dev);
	if (!dev_desc || dev_desc->type == DEV_TYPE_UNKNOWN) {
		printf("invalid mmc device\n");
		return -1;
	}

	char *partition_name = "misc";

	if (part_get_info_by_name(dev_desc, partition_name, &info) == -1) {
		printf("cannot find partition: '%s'\n", partition_name);
		return -1;
	}

	misc_bootctrl = (void *)malloc(dev_desc->blksz);
	strat_blk = info.start + 4096 / dev_desc->blksz;
	blk_dread(dev_desc, strat_blk, 1, misc_bootctrl);
	memcpy(p_bootctrl, (void *)misc_bootctrl, sizeof(misc_boot_ctrl_t));

	free(misc_bootctrl);

	return 0;
}

static int init_bootctrl(misc_boot_ctrl_t *p_bootctrl, int default_slot)
{
	if (default_slot > 1) {
		printf("invalid default slot number for bootctrl !\n");
		return -1;
	}

	memset((void *)p_bootctrl, 0, sizeof(misc_boot_ctrl_t));

	p_bootctrl->slot_info[default_slot].priority		    = 8;
	p_bootctrl->slot_info[default_slot].tries_remaining	= 2;
	p_bootctrl->slot_info[default_slot].successful_boot	= 0;

	p_bootctrl->slot_info[1 - default_slot].priority		    = 3;
	p_bootctrl->slot_info[1 - default_slot].tries_remaining	= 2;
	p_bootctrl->slot_info[1 - default_slot].successful_boot	= 0;

	p_bootctrl->version	= MISC_BOOT_CONTROL_VERSION;
	p_bootctrl->magic	= BOOTCTRL_MAGIC;

	if (write_bootctrl_metadata(p_bootctrl)) {
		printf("Error: fail to write misc bootctrl metadata !\n");
		return -1;
	}

	return 0;
}

int get_current_slot(void)
{
	int bootab_sel = BOOTSEL_INVALID;
	misc_boot_ctrl_t bctrl;

	if (get_bootctrl_metadata((void *)&bctrl)) {
		printf("Error: fail to get bootctrl.metadata !\n");
		goto out;
	}

	if (is_valid_bootctrl((void *)&bctrl)) {
		if (slot_is_bootable((void *)&bctrl.slot_info[0]) &&
		    slot_is_bootable((void *)&bctrl.slot_info[1])) {
			if (bctrl.slot_info[0].priority >= bctrl.slot_info[1].priority)
				bootab_sel = BOOTSEL_A;
			else
				bootab_sel = BOOTSEL_B;
		} else if (slot_is_bootable((void *)&bctrl.slot_info[0])) {
			bootab_sel = BOOTSEL_A;
		} else if (slot_is_bootable((void *)&bctrl.slot_info[1])) {
			bootab_sel = BOOTSEL_B;
		} else {
			/* No bootable slots! */
			printf("No bootable slots found !!!\n");
			bootab_sel = BOOTSEL_INVALID;
			goto out;
		}
	} else {
		printf("invalid bootctrl, Magic:0x%x,Ver:0x%x.\n", bctrl.magic, bctrl.version);
		if (!init_bootctrl((void *)&bctrl, BOOTSEL_DEFAULT)) {
			printf("No valid metadata for bootctrl, initialize to default slot %d !\n", BOOTSEL_DEFAULT);
			bootab_sel = BOOTSEL_DEFAULT;
		}
	}

	debug("Slot index=%d got !\n", bootab_sel);

out:
	return bootab_sel;
}

int try_abmode(int abmode_sel)
{
	/* ... and decrement tries remaining, if applicable. */
	misc_boot_ctrl_t bctrl;

	memset((void *)&bctrl, 0, sizeof(misc_boot_ctrl_t));
	if (get_bootctrl_metadata((void *)&bctrl)) {
		printf("Error: fail to get bootctrl.metadata !\n");
		return 1;
	}

	if (is_valid_bootctrl((void *)&bctrl) && bctrl.slot_info[abmode_sel].tries_remaining > 0) {
		bctrl.slot_info[abmode_sel].tries_remaining -= 1;
		write_bootctrl_metadata((void *)&bctrl);
		return 0;
	} else if (is_valid_bootctrl((void *)&bctrl)) {
		bctrl.slot_info[abmode_sel].priority -= 2;
		write_bootctrl_metadata((void *)&bctrl);
		return -1;
	}

	return 1;
}

static struct part_driver *f_part_driver_lookup_type(struct blk_desc *dev_desc)
{
	struct part_driver *drv =
		ll_entry_start(struct part_driver, part_driver);
	const int n_ents = ll_entry_count(struct part_driver, part_driver);
	struct part_driver *entry;

	if (dev_desc->part_type == PART_TYPE_UNKNOWN) {
		for (entry = drv; entry != drv + n_ents; entry++) {
			int ret;

			ret = entry->test(dev_desc);
			if (!ret) {
				dev_desc->part_type = entry->part_type;
				return entry;
			}
		}
	} else {
		for (entry = drv; entry != drv + n_ents; entry++) {
			if (dev_desc->part_type == entry->part_type)
				return entry;
		}
	}

	/* Not found */
	return NULL;
}

static int f_part_get_info_by_name(struct blk_desc *dev_desc, const char *name,
				   disk_partition_t *info)
{
	struct part_driver *part_drv;
	int ret;
	int i;

	part_drv = f_part_driver_lookup_type(dev_desc);
	if (!part_drv)
		return -1;
	for (i = 1; i < part_drv->max_entries; i++) {
		ret = part_drv->get_info(dev_desc, i, info);
		if (ret != 0) {
			/* no more entries in table */
			break;
		}
		if (strcmp(name, (const char *)info->name) == 0) {
			/* matched */
			return i;
		}
	}

	return -1;
}

static int f_part_get_info_by_name_or_alias(struct blk_desc *dev_desc,
					    const char *name, disk_partition_t *info)
{
	int ret;

	ret = f_part_get_info_by_name(dev_desc, name, info);
	if (ret < 0) {
		/* strlen("fastboot_partition_alias_") + 32(part_name) + 1 */
		char env_alias_name[25 + 32 + 1];
		char *aliased_part_name;

		/* check for alias */
		strcpy(env_alias_name, "fastboot_partition_alias_");
		strncat(env_alias_name, name, 32);
		aliased_part_name = env_get(env_alias_name);
		if (aliased_part_name)
			ret = f_part_get_info_by_name(dev_desc,
						      aliased_part_name, info);
	}
	return ret;
}

int f_mmc_get_part_info(char *part_name, struct blk_desc **dev_desc,
			disk_partition_t *part_info)
{
	int r;

	*dev_desc = blk_get_dev("mmc", get_mmc_boot_dev());
	if (!*dev_desc) {
		printf("block device not found");
		return -ENOENT;
	}
	if (!part_name) {
		printf("partition not found");
		return -ENOENT;
	}

	r = f_part_get_info_by_name_or_alias(*dev_desc, part_name, part_info);
	if (r < 0) {
		printf("partition not found");
		return r;
	}

	return r;
}

int f_mmc_get_part_index(char *part_name)
{
	struct blk_desc *dev_desc;
	disk_partition_t part_info;

	return f_mmc_get_part_info(part_name, &dev_desc, &part_info);
}

static void read_raw_image_from_offset(struct blk_desc *dev_desc, disk_partition_t *info,
				       const char *part_name, void *buffer,
		unsigned int read_bytes, unsigned int offset)
{
	lbaint_t blkcnt;
	lbaint_t blks;
	lbaint_t start;

	/* determine number of blocks to write */
	blkcnt = ((read_bytes + (info->blksz - 1)) & ~(info->blksz - 1));
	blkcnt = lldiv(blkcnt, info->blksz);

	start = info->start;

	if (offset % info->blksz) {
		printf("offset should be aligned with block size\n");
		return;
	}

	start += (offset / (info->blksz));

	if (blkcnt > info->size) {
		printf("too large for partition: '%s'\n", part_name);
		return;
	}

	blks = blk_dread(dev_desc, start, blkcnt, buffer);
	if (blks != blkcnt) {
		printf("failed reading to device %d\n", dev_desc->devnum);
		return;
	}
}

void fb_mmc_flash_read_from_offset(const char *cmd, void *read_buffer,
				   unsigned int read_bytes, unsigned int offset)
{
	struct blk_desc *dev_desc;
	disk_partition_t info;
	int mmc_dev = get_mmc_boot_dev();
	struct mmc *mmc = find_mmc_device(mmc_dev);

	if (!mmc) {
		printf("invalid mmc device\n");
		return;
	}

	dev_desc = blk_get_dev("mmc", mmc_dev);
	if (!dev_desc || dev_desc->type == DEV_TYPE_UNKNOWN) {
		printf("invalid mmc device\n");
		return;
	}

	if ((strcmp(cmd, "bootloader") == 0) ||
	    (strcmp(cmd, "bootloader1") == 0)) {
		int ret = blk_dselect_hwpart(dev_desc, 1);

		if (ret) {
			printf("invalid mmc hwpart\n");
			return;
		}
		info.start = 0;
		info.size = dev_desc->lba;
		info.blksz = dev_desc->blksz;
		printf("%lx, %lx, %lx\n", info.start, info.size, info.blksz);
	} else if (strcmp(cmd, "bootloader2") == 0) {
		int ret = blk_dselect_hwpart(dev_desc, 2);

		if (ret) {
			printf("invalid mmc hwpart\n");
			return;
		}
		info.start = 0;
		info.size = dev_desc->lba;
		info.blksz = dev_desc->blksz;
		printf("%lx, %lx, %lx\n", info.start, info.size, info.blksz);
	} else if (f_part_get_info_by_name_or_alias(dev_desc, cmd, &info) < 0) {
		printf("cannot find partition: '%s'\n", cmd);
		return;
	}

	read_raw_image_from_offset(dev_desc, &info, cmd, read_buffer, read_bytes, offset);
}

void fb_mmc_flash_read(const char *cmd, void *read_buffer,
		       unsigned int read_bytes)
{
	fb_mmc_flash_read_from_offset(cmd, read_buffer, read_bytes, 0);
}

