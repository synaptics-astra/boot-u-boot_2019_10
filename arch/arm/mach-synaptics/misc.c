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
#include <asm/io.h>
#include "Galois_memmap.h"
#include "global.h"
#include "misc_syna.h"

int get_mmc_boot_dev(void)
{
	static int mmc_flash_dev = -1;
	u32 boot_strap, boot_source;

	if (mmc_flash_dev != -1)
		return mmc_flash_dev;

	boot_strap = __raw_readl(MEMMAP_CHIP_CTRL_REG_BASE + RA_Gbl_bootStrap);
	boot_source = (boot_strap & MSK32Gbl_bootStrap_bootSrc) >> LSb32Gbl_bootStrap_bootSrc;

	debug("\tboot_source: %d\n", boot_source);

	if (boot_source == Gbl_bootStrap_bootSrc_ROM_SPI_BOOT)
		mmc_flash_dev = DEV_SD; /* SPI-SD */
	else
		mmc_flash_dev = DEV_EMMC; /* eMMC */

	return mmc_flash_dev;
}

int get_mmc_active_dev(void)
{
	char *s;
	int mmc_dev;

	s = env_get("mmc_dev");
	if (s)
		mmc_dev = !!((int)simple_strtol(s, NULL, 10));
	else
#ifdef CONFIG_SYNA_SUBOOT
		mmc_dev = get_mmc_boot_dev();
#else
		mmc_dev = 0;
#endif

	return mmc_dev;
}

unsigned int get_max_malloc_size(void)
{
	unsigned int max_size = CONFIG_SYS_MALLOC_LEN;
	// depends on the heap size defined in config
	if (max_size > (1 << 30)) // > 1GB
		return (max_size - (100 << 20));
	if (max_size > (400 << 20)) // > 400MB
		return (max_size - (40 << 20));

	//don't hope to come here
	return (max_size - (10 << 20));
}
