/*
 * This file is produced by tools!!
 *
 * Copyright (C) 2018 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <common.h>
#include <asm/arch/sprd_reg.h>
#include <asm/io.h>
#include <asm/arch/common.h>
#include <sprd_ufs.h>

void init_global_reg(void)
{
	CHIP_REG_OR(REG_AP_APB_APB_EB1, (BIT_AP_APB_UFS_EB |
					 BIT_AP_APB_UFS_REG_EB));

	CHIP_REG_OR(REG_AON_APB_APB_EB1, (BIT_AON_APB_PIN_EB |
					  BIT_AON_APB_ANA_EB));

	CHIP_REG_OR(REG_AP_AHB_UFS_CLK_CTRL,BIT_AP_AHB_CG_CFGCLK_SW);

	CHIP_REG_OR(REG_AP_APB_APB_RST, (BIT_AP_APB_UFS_REG_SOFT_RST |
					 BIT_AP_APB_CKG_SOFT_RST));
	udelay(100);

	CHIP_REG_AND(REG_AP_APB_APB_RST, ~(BIT_AP_APB_UFS_REG_SOFT_RST |
					  BIT_AP_APB_CKG_SOFT_RST));

	CHIP_REG_OR(REG_AP_AHB_MPHY_CB_CHANNEL_0, BIT_AP_AHB_REFCLKON);

	CHIP_REG_OR(REG_AP_AHB_UFS_LP_CTRL_1, (BIT_AP_AHB_UFS_FORCE_LP_PWR_READY |
					       BIT_AP_AHB_UFS_FORCE_LP_RESET_N));

	CHIP_REG_AND(REG_AP_AHB_UFS_LP_CTRL_1, ~(BIT_AP_AHB_UFS_FORCE_LP_ISOL_EN));

	CHIP_REG_OR(REG_AP_AHB_UFS_LP_CTRL_1, (BIT_AP_AHB_UFS_CG_LP_PWR_READY_BYPASS |
					       BIT_AP_AHB_UFS_FORCE_LP_RESET_N));

	CHIP_REG_AND(REG_AP_AHB_MPHY_CB_CHANNEL_0, ~(BIT_AP_AHB_CB_RESET |
						     BIT_AP_AHB_CB_ATTRRESET));

	CHIP_REG_AND(REG_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_REG_1,
		     ~(BIT_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_PRESETN));
	udelay(100);

	CHIP_REG_OR(REG_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_REG_1,
		    BIT_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_PRESETN);
}

int ufshci_enable_bottom()
{
	int ret = 0;

	ufs_writel(DW_UFS_HCLKDIV, 0x1a);
	ret = ufs_readl(DW_UFS_OCPTHRTL) & (~BIT_12);
	ufs_writel(DW_UFS_OCPTHRTL, ret);
	dme_set(0xd086, 0x3a);

	tc_dwc_g240_16nm_config();

	return 0;
}

struct ufs_hba_variant_ops hba_vops = {
	.name = "qogirl6",
	.enable_bottom = ufshci_enable_bottom,
};
