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
#include <sprd_ufs.h>

void init_global_reg(void)
{
	ufs_info.base_addr = SPRD_AP_UFS_AES_BASE;

	CHIP_REG_OR(REG_AP_AHB_MPHY_CB_CHANNEL_0, (BIT_AP_AHB_CB_RESET |
						   BIT_AP_AHB_CB_ATTRRESET));
	udelay(100);

	CHIP_REG_AND(REG_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_REG_1,
		     ~BIT_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_PRESETN);
	udelay(100);

	CHIP_REG_OR(REG_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_REG_1,
		    BIT_ANLG_PHY_G1_ANALOG_MIPI_MPHY_2T2R_MPHY_APB_PRESETN);
	udelay(100);

	CHIP_REG_AND(REG_AP_AHB_MPHY_CB_CHANNEL_0,
		     ~(BIT_AP_AHB_CB_RESET | BIT_AP_AHB_CB_ATTRRESET));
	udelay(100);

	CHIP_REG_AND(REG_AP_AHB_MPHY_CB_CHANNEL_0,
		     ~(BIT_AP_AHB_CB_RESET | BIT_AP_AHB_CB_ATTRRESET));

	CHIP_REG_OR(REG_AP_APB_APB_EB1, (BIT_AP_APB_UFS_EB |
					 BIT_AP_APB_UFS_REG_EB));

	CHIP_REG_OR(REG_AON_APB_APB_EB1,(BIT_AON_APB_PIN_EB |
					 BIT_AON_APB_ANA_EB));
	//remove this first keep the same with the romcode

	CHIP_REG_OR(REG_AP_AHB_UFS_CLK_CTRL,BIT_AP_AHB_CG_CFGCLK_SW);

	CHIP_REG_OR(REG_AP_APB_APB_RST,(BIT_AP_APB_UFS_REG_SOFT_RST |
					BIT_AP_APB_UFS_SOFT_RST));
	udelay(100);
	CHIP_REG_AND(REG_AP_APB_APB_RST,~(BIT_AP_APB_UFS_REG_SOFT_RST |
					  BIT_AP_APB_UFS_SOFT_RST));

	CHIP_REG_OR(REG_AP_AHB_MPHY_CB_CHANNEL_0,BIT_AP_AHB_REFCLKON);

	CHIP_REG_AND(REG_AP_AHB_UFS_LP_CTRL_1,
		     ~BIT_AP_AHB_UFS_FORCE_LP_ISOL_EN);

	CHIP_REG_OR(REG_AP_AHB_UFS_LP_CTRL_1,
		     (BIT_AP_AHB_UFS_SEL_LP_RESET_N | BIT_AP_AHB_UFS_FORCE_LP_RESET_N |
		     BIT_AP_AHB_UFS_SEL_LP_ISOL_EN | BIT_AP_AHB_UFS_SEL_LP_PWR_READY |
		     BIT_AP_AHB_UFS_FORCE_LP_PWR_READY));

	udelay(300);

	CHIP_REG_OR(0x6456c08c,BIT_15);
	CHIP_REG_OR(0x6456c88c,BIT_15);
}

int ufshci_enable_bottom()
{
	return 0;
}

struct ufs_hba_variant_ops hba_vops = {
	.name = "qogirl6",
	.enable_bottom = ufshci_enable_bottom,
};
