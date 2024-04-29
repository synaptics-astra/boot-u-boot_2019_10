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
#include <dm.h>
#include <reset.h>
#include <sdhci.h>
#include <clk.h>

/* Host Controller */
#define SDHCI_P_VENDOR_SPECIFIC_AREA	0xe8
#define SDHCI_P_VENDOR_SPECIFIC_AREA_MASK 0xfff
#define SDHCI_EMMC_CTRL_OFFSET			0x2c

#define PHY_AT_CTRL_R_REG_OFFSET 0x40
#define CARD_IS_EMMC BIT(0)
#define EMMC_RST_N BIT(2)
#define EMMC_RST_N_OE BIT(3)
#define TUNE_CLK_STOP_EN BIT(16)
#define PRE_CHANGE_DLY_SFT 17
#define PRE_CHANGE_DLY_MSK	(0x3 << PRE_CHANGE_DLY_SFT)
#define POST_CHANGE_DLY_SFT 19
#define POST_CHANGE_DLY_MSK (0x3 << POST_CHANGE_DLY_SFT)

/* PHY */
#define PHY_REG_BASE 0x300
#define PHY_REG(off) (PHY_REG_BASE + (off))

#define PHY_CNFG_REG PHY_REG(0)
#define PHY_RSTN BIT(0)
#define PHY_PWRGOOD BIT(1)

/* PHY PAD */
#define PHY_CMDPAD_CNFG_REG PHY_REG(0x4)
#define PHY_DATPAD_CNFG_REG PHY_REG(0x6)
#define PHY_CLKPAD_CNFG_REG PHY_REG(0x8)
#define PHY_STBPAD_CNFG_REG PHY_REG(0xa)
#define PHY_RSTNPAD_CNFG_REG PHY_REG(0xc)

/*PHY PAD GENERAL modes */
#define PAD_SP_8    0x8
#define PAD_SP_9    0x9
#define PAD_SN_8    0x8

/* PHY RX SEL modes */
#define RXSELOFF        0x0
#define SCHMITT1P8      0x1
#define SCHMITT3P3      0x2
#define SCHMITT1P2      0x3
#define COMPARATOR1P8   0x4
#define COMPARATOR1P2   0x5
#define COMPARATOR1P82  0x6
#define INTERNALLPBK    0x7

/* PHY WEAKPULL_EN modes */
#define WPE_DISABLE  0x0
#define WPE_PULLUP   0x1
#define WPE_PULLDOWN 0x2

/* PHY TXSLEW_CTRL_P modes */
#define TX_SLEW_P_0    0x0
#define TX_SLEW_P_2    0x2
#define TX_SLEW_P_3    0x3

/* PHY TXSLEW_CTRL_N modes */
#define TX_SLEW_N_2    0x2
#define TX_SLEW_N_3    0x3

#define PHY_COMMDL_CNFG_REG PHY_REG(0x1c)
#define DLSTEP_SEL BIT(0)
#define DLOUT_EN BIT(1)

#define PHY_SDCLKDL_CNFG_REG PHY_REG(0x1d)
#define EXTDLY_EN BIT(0)
#define BYPASS_EN BIT(1)
#define INPSEL_CNFG_SFT 2
#define INPSEL_CNFG_MSK (0x3 << INPSEL_CNFG_SFT)
#define UPDATE_DC BIT(4)

#define PHY_SDCLKDL_DC_REG PHY_REG(0x1e)
#define CCKDL_DC_SFT 0
#define CCKDL_DC_MSK (0x7f << CCKDL_DC_SFT)

#define PHY_SMPLDL_CNFG_REG PHY_REG(0x20)
#define SEXTDLY_EN BIT(0)
#define SBYPASS_EN BIT(1)
#define SINPSEL_CNFG_SFT 2
#define SINPSEL_CNFG_MSK (0x3 << SINPSEL_CNFG_SFT)
#define SINPSEL_OVERRIDE BIT(4)

#define PHY_ATDL_CNFG_REG PHY_REG(0x21)
#define AEXTDLY_EN BIT(0)
#define ABYPASS_EN BIT(1)
#define AINPSEL_CNFG_SFT 2
#define AINPSEL_CNFG_MSK (0x3 << AINPSEL_CNFG_SFT)

#define PHY_GEN_SETTING(pad_sp, pad_sn) \
	 ((((pad_sp) & 0x0f) << 16) | \
	 (((pad_sn) & 0x0f) << 20))
#define PHY_GEN_MASK PHY_GEN_SETTING(0xf, 0xf)

struct phy_gen_setting {
	u32 reg;
	u32 mask;
	u32 setting;
};

#define PHY_PAD_SETTING(rxsel, weakpull_en, txslew_ctrl_p, txslew_ctrl_n) \
	(((rxsel) & 0x3) | \
	(((weakpull_en) & 0x3) << 3) | \
	(((txslew_ctrl_p) & 0xf) << 5) | \
	((txslew_ctrl_n) & 0xf) << 9)
#define PHY_PAD_MASK PHY_PAD_SETTING(0x3, 0x3, 0xf, 0xf)
#define PHY_PAD_SETTING_NUM 5

struct phy_pad_setting {
	u32 reg;
	u16 mask;
	u16 setting;
};

struct dwcmshc_sdhci_plat {
	struct mmc_config cfg;
	struct mmc mmc;
	struct reset_ctl_bulk reset_ctl;
	u32 sdclkdl_dc;
};

struct phy_gen_setting gen_setting_1v8 = {PHY_CNFG_REG, PHY_GEN_MASK, PHY_GEN_SETTING(PAD_SP_8, PAD_SN_8)};
struct phy_pad_setting pad_setting_1v8[PHY_PAD_SETTING_NUM] = {
	{PHY_CMDPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT1P8, WPE_PULLUP, TX_SLEW_P_0, TX_SLEW_N_3)},
	{PHY_DATPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT1P8, WPE_PULLUP, TX_SLEW_P_0, TX_SLEW_N_3)},
	{PHY_CLKPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(RXSELOFF, WPE_DISABLE, TX_SLEW_P_0, TX_SLEW_N_3)},
	{PHY_STBPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT1P8, WPE_PULLDOWN, TX_SLEW_P_0, TX_SLEW_N_3)},
	{PHY_RSTNPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT1P8, WPE_PULLUP, TX_SLEW_P_0, TX_SLEW_N_3) }
};

struct phy_gen_setting gen_setting_3v3 = {PHY_CNFG_REG, PHY_GEN_MASK, PHY_GEN_SETTING(PAD_SP_9, PAD_SN_8)};
struct phy_pad_setting pad_setting_3v3[PHY_PAD_SETTING_NUM] = {
	{PHY_CMDPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT3P3, WPE_PULLUP, TX_SLEW_P_3, TX_SLEW_N_2)},
	{PHY_DATPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT3P3, WPE_PULLUP, TX_SLEW_P_3, TX_SLEW_N_2)},
	{PHY_CLKPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(RXSELOFF, WPE_DISABLE, TX_SLEW_P_3, TX_SLEW_N_2)},
	{PHY_STBPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT3P3, WPE_PULLDOWN, TX_SLEW_P_3, TX_SLEW_N_2)},
	{PHY_RSTNPAD_CNFG_REG, PHY_PAD_MASK, PHY_PAD_SETTING(SCHMITT3P3, WPE_PULLUP, TX_SLEW_P_3, TX_SLEW_N_2) }
};

void dwcmshc_reset_phy(struct sdhci_host *host, int rst)
{
	volatile u16 valw;

	valw = sdhci_readw(host, PHY_CNFG_REG);
	valw &= ~PHY_RSTN;
	valw |= rst;
	sdhci_writew(host, valw, PHY_CNFG_REG);
}

static void dwcmshc_set_control_reg(struct sdhci_host *host)
{
	sdhci_set_control_reg(host);
}

const struct sdhci_ops dwcmshc_ops = {
	.set_control_reg = &dwcmshc_set_control_reg,
};

static void dwcmshc_reset(struct dwcmshc_sdhci_plat *plat,
			  struct sdhci_host *host)
{
	u32 offset, val;

	/* Reset Host */
	reset_assert_bulk(&plat->reset_ctl);
	mdelay(1);
	reset_deassert_bulk(&plat->reset_ctl);

	/* eMMC reset device */
	offset = sdhci_readl(host, SDHCI_P_VENDOR_SPECIFIC_AREA);
	offset &= SDHCI_P_VENDOR_SPECIFIC_AREA_MASK;
	offset += SDHCI_EMMC_CTRL_OFFSET;
	val = sdhci_readl(host, offset);
	val |= CARD_IS_EMMC;
	val |= EMMC_RST_N_OE;
	val &= ~EMMC_RST_N;
	sdhci_writel(host, val, offset);
	mdelay(1);
	val = sdhci_readl(host, offset);
	val |= EMMC_RST_N;
	sdhci_writel(host, val, offset);
	mdelay(1);
	val = sdhci_readl(host, offset);
}

static void dwcmshc_setup_phy_datapath(struct udevice *dev)
{
	struct sdhci_host *host = dev_get_priv(dev);
	u8 valb;

	valb = sdhci_readb(host, PHY_COMMDL_CNFG_REG);
	valb &= ~DLSTEP_SEL;
	valb &= ~DLOUT_EN;
	sdhci_writeb(host, valb, PHY_COMMDL_CNFG_REG);

	valb = sdhci_readb(host, PHY_SDCLKDL_CNFG_REG);
	valb &= ~EXTDLY_EN;
	valb &= ~BYPASS_EN;
	valb &= ~UPDATE_DC;
	valb &= ~INPSEL_CNFG_MSK;
	sdhci_writeb(host, valb, PHY_SDCLKDL_CNFG_REG);

	valb = sdhci_readb(host, PHY_SMPLDL_CNFG_REG);
	valb &= ~SEXTDLY_EN;
	valb &= ~SBYPASS_EN;
	valb &= ~SINPSEL_OVERRIDE;
	valb &= ~SINPSEL_CNFG_MSK;
	valb |= (3 << SINPSEL_CNFG_SFT);
	sdhci_writeb(host, valb, PHY_SMPLDL_CNFG_REG);

	valb = sdhci_readb(host, PHY_ATDL_CNFG_REG);
	valb &= ~AEXTDLY_EN;
	valb &= ~ABYPASS_EN;
	valb &= ~AINPSEL_CNFG_MSK;
	valb |= (3 << AINPSEL_CNFG_SFT);
	sdhci_writeb(host, valb, PHY_ATDL_CNFG_REG);
}

static void dwcmshc_setup_phy_delayline(struct udevice *dev, u8 delay)
{
	struct sdhci_host *host = dev_get_priv(dev);
	u8 valb;

	valb = sdhci_readb(host, PHY_SDCLKDL_CNFG_REG);
	valb |= UPDATE_DC;
	sdhci_writeb(host, valb, PHY_SDCLKDL_CNFG_REG);

	valb = sdhci_readb(host, PHY_SDCLKDL_DC_REG);
	valb &= ~CCKDL_DC_MSK;
	valb |= delay << CCKDL_DC_SFT;
	sdhci_writeb(host, valb, PHY_SDCLKDL_DC_REG);

	valb = sdhci_readb(host, PHY_SDCLKDL_CNFG_REG);
	valb &= ~UPDATE_DC;
	sdhci_writeb(host, valb, PHY_SDCLKDL_CNFG_REG);
}

static void dwcmshc_setup_phy_tuning(struct udevice *dev)
{
	struct sdhci_host *host = dev_get_priv(dev);
	u32 offset, val;

	offset = sdhci_readl(host, SDHCI_P_VENDOR_SPECIFIC_AREA);
	offset &= SDHCI_P_VENDOR_SPECIFIC_AREA_MASK;
	offset += PHY_AT_CTRL_R_REG_OFFSET;

	val = sdhci_readl(host, offset);
	val &= ~TUNE_CLK_STOP_EN;
	val &= ~POST_CHANGE_DLY_MSK;
	val &= ~PRE_CHANGE_DLY_MSK;
	val |= TUNE_CLK_STOP_EN | (3 << POST_CHANGE_DLY_SFT) | (3 << PRE_CHANGE_DLY_SFT);
	sdhci_writel(host, val, offset);
}

static int dwcmshc_setup_phy_configure(struct udevice *dev)
{
	struct sdhci_host *host = dev_get_priv(dev);
	struct phy_gen_setting *gen_setting = &gen_setting_1v8;
	struct phy_pad_setting *pad_setting = pad_setting_1v8;

	int i;
	volatile u16 valw;
	volatile u32 val;
	int timeout = 100, ret = 0;

	if (host->mmc->signal_voltage == MMC_SIGNAL_VOLTAGE_330) {
		gen_setting = &gen_setting_3v3;
		pad_setting = pad_setting_3v3;
	}

	val = sdhci_readl(host, gen_setting->reg);
	val &= ~(gen_setting->mask);
	val |= gen_setting->setting;
	sdhci_writel(host, val, gen_setting->reg);

	for (i = 0; i < PHY_PAD_SETTING_NUM; i++) {
		valw = sdhci_readw(host, pad_setting[i].reg);
		valw &= ~(pad_setting[i].mask);
		valw |= pad_setting[i].setting;
		sdhci_writew(host, valw, pad_setting[i].reg);
	}

	do {
		mdelay(1);
		val = sdhci_readl(host, PHY_CNFG_REG);

		if (!timeout) {
			printf("EMMC PHY's PowerGood status is not ready !\n");
			ret = -1;
		}
	} while (!(val & PHY_PWRGOOD) && timeout--);

	return ret;
}

static int dwcmshc_setup_phy(struct udevice *dev)
{
	struct dwcmshc_sdhci_plat *plat = dev_get_platdata(dev);

	dwcmshc_setup_phy_datapath(dev);
	dwcmshc_setup_phy_delayline(dev, plat->sdclkdl_dc);
	dwcmshc_setup_phy_tuning(dev);
	dwcmshc_setup_phy_configure(dev);
	return 0;
}

static int dwcmshc_probe(struct udevice *dev)
{
	struct dwcmshc_sdhci_plat *plat = dev_get_platdata(dev);
	struct mmc_uclass_priv *upriv = dev_get_uclass_priv(dev);
	struct sdhci_host *host = dev_get_priv(dev);
	int ret = 0;
	struct clk clk;
	unsigned long clock;

	dwcmshc_reset(plat, host);

	ret = clk_get_by_index(dev, 0, &clk);
	if (ret < 0) {
		dev_err(dev, "failed to get clock\n");
		return ret;
	}

	clock = clk_get_rate(&clk);
	if (IS_ERR_VALUE(clock)) {
		dev_err(dev, "failed to get rate\n");
		return clock;
	}

	host->max_clk = clock;
	host->mmc = &plat->mmc;
	host->mmc->dev = dev;

	host->quirks = SDHCI_QUIRK_NO_1_8_V;
	if (dev_read_bool(dev, "1_8v-signalling"))
		host->mmc->signal_voltage = MMC_SIGNAL_VOLTAGE_180;

	if (dev_read_bool(dev, "3_3v-signalling"))
		host->mmc->signal_voltage = MMC_SIGNAL_VOLTAGE_330;

	plat->sdclkdl_dc = dev_read_u32_default(dev, "sdclkdl-dc", 127);

	ret = sdhci_setup_cfg(&plat->cfg, host, plat->cfg.f_max, 0);
	if (ret)
		return ret;

	upriv->mmc = host->mmc;
	host->mmc->priv = host;

	ret = sdhci_probe(dev);
	if (ret)
		return ret;

	dwcmshc_reset_phy(host, 0);
	dwcmshc_setup_phy(dev);
	dwcmshc_reset_phy(host, 1);

	return ret;
}

static int dwcmshc_ofdata_to_platdata(struct udevice *dev)
{
	struct dwcmshc_sdhci_plat *plat = dev_get_platdata(dev);
	struct sdhci_host *host = dev_get_priv(dev);
	struct mmc_config *cfg = &plat->cfg;
	int ret;

	if (reset_get_bulk(dev, &plat->reset_ctl)) {
		printf("%s: can't get reset index for xenon_sdhci\n", __func__);
		return -ENODEV;
	}
	host->name = dev->name;
	host->ioaddr = (void *)dev_read_addr(dev);

	ret = mmc_of_parse(dev, cfg);
	if (ret)
		return ret;

	host->ops = &dwcmshc_ops;

	return 0;
}

static int dwcmshc_bind(struct udevice *dev)
{
	struct dwcmshc_sdhci_plat *plat = dev_get_platdata(dev);
	int ret;

	ret = sdhci_bind(dev, &plat->mmc, &plat->cfg);
	if (ret)
		return ret;

	return 0;
}

static const struct udevice_id dwcmshc_sdhci_ids[] = {
	{ .compatible = "snps,dwcmshc-sdhci" },
	{ }
};

U_BOOT_DRIVER(dwcmshc_sdhci) = {
	.name	= "dwcmshc-sdhci",
	.id	= UCLASS_MMC,
	.of_match = dwcmshc_sdhci_ids,
	.ofdata_to_platdata = dwcmshc_ofdata_to_platdata,
	.ops	= &sdhci_ops,
	.bind	= dwcmshc_bind,
	.probe	= dwcmshc_probe,
	.priv_auto_alloc_size = sizeof(struct sdhci_host),
	.platdata_auto_alloc_size = sizeof(struct dwcmshc_sdhci_plat),
};
