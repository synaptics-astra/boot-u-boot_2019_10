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
#include "genimg.h"
#include "fastboot_syna.h"
#include "tee_client.h"
#include "mem_init.h"

#define BL_A_NAME			"bl_a"
#define BL_B_NAME			"bl_b"
#define MAX_PAGESIZE	8192
#define BLK_SIZE		512

#ifdef CONFIG_SYNA_TA_LOGO
static unsigned char *logotabuf;
static u32 logotasize;
#endif

#ifdef CONFIG_SYNA_TA_CYPT
static unsigned char *cypttabuf;
static u32 cypttasize;
#endif

static int syna_load_ta(void)
{
	struct img_info *img_info;
	struct chunk_param *chunk;
	u32 ta_offset = 0, ta_size = 0;
	const char *partition = NULL;
	unsigned char *buf = NULL;
	struct img_header *ta_header = NULL;
	int i;
	int ret = 0;

	if (get_current_slot() == BOOTSEL_A)
		partition = BL_A_NAME;
	else
		partition = BL_B_NAME;

	/* read prepend image info to find the offset of preload_ta */
	buf = malloc_ion_noncacheable(MAX_PAGESIZE);
	if (!buf) {
		printf("load_ta: no enough memory %d\n", MAX_PAGESIZE);
		goto nullmem;
	}

	fb_mmc_flash_read(partition, buf, MAX_PAGESIZE);
	img_info = (struct img_info *)buf;
	if (img_info->magic != IMG_INFO_MAGIC) {
		printf("ERROR: incorrect magic in image info  0x%08x\n", img_info->magic);
		ret = -1;
		goto failure;
	}

	ta_offset = img_info->image_offset + img_info->image_size;
	ta_offset = ALIGN(ta_offset, BLK_SIZE);

	/* find out the ta size */
	free_ion_noncacheable(buf);
	buf = malloc_ion_noncacheable(MAX_PAGESIZE);
	if (!buf) {
		printf("load_ta: no enough memory %d\n", MAX_PAGESIZE);
		ret = -1;
		goto nullmem;
	}

	fb_mmc_flash_read_from_offset(partition, buf, MAX_PAGESIZE, ta_offset);
	ta_header = (struct img_header *)(buf);
	ta_size = ta_header->chunk[ta_header->chunk_num - 1].offset
				+ ta_header->chunk[ta_header->chunk_num - 1].size;

	/* find out TA image */
	free_ion_noncacheable(buf);
	buf = malloc_ion_noncacheable(ta_size);
	if (!buf) {
		printf("load_ta: no enough memory %d\n", ta_size);
		ret = -1;
		goto nullmem;
	}
	fb_mmc_flash_read_from_offset(partition, buf, ta_size, ta_offset);

	for (i = 0; i < ta_header->chunk_num; i++) {
		chunk = &ta_header->chunk[i];

#ifdef CONFIG_SYNA_TA_LOGO
		if (chunk->id == IMAGE_CHUNK_ID_FASTLOGO) {
			debug("####find LOGO TA %x\n", chunk->id);
			logotasize = chunk->size;
			logotabuf = (unsigned char *)(buf + chunk->offset);
		}
#endif

#ifdef CONFIG_SYNA_TA_CYPT
		if (chunk->id == IMAGE_CHUNK_ID_KEYMASTER) {
			debug("####find CYPT TA %x\n", chunk->id);
			cypttasize = chunk->size;
			cypttabuf = (unsigned char *)(buf + chunk->offset);
		}
#endif
	}

failure:
	if (buf)
		free_ion_noncacheable(buf);

nullmem:
	return ret;
}

int syna_register_ta(void)
{
	TEEC_Result result = TEEC_SUCCESS;

	if (syna_load_ta()) {
		printf("failed to load ta\n");
		return -1;
	}

#ifdef CONFIG_SYNA_TA_LOGO
	if (logotasize && logotabuf) {
		result = tee_register_ta(logotabuf, logotasize);
		if (result != TEEC_SUCCESS) {
			printf("register LOGO TA failed, ret = 0x%08x\n", result);
			return -2;
		}
		printf("register LOGO TA succeed\n");
	}
#endif

#ifdef CONFIG_SYNA_TA_CYPT
	if (cypttasize && cypttabuf) {
		result = tee_register_ta(cypttabuf, cypttasize);
		if (result != TEEC_SUCCESS) {
			printf("register CYPT TA failed, ret = 0x%08x\n", result);
			return -2;
		}
		printf("register CYPT TA succeed\n");
	}
#endif

	return 0;
}
