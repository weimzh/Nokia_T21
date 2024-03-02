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
#include <asm/arch/ufs_cfg.h>
#include <asm/arch/common.h>
#include <sprd_ufs.h>

const struct ufs_cfg_info ufs_ctrl_info[1] = {

	SPRD_UFS_HCI_PHYS,

	REG_AP_APB_APB_EB1,
	BIT_AP_APB_UFS_UTP_EB | BIT_AP_APB_UFS_EB | BIT_AP_APB_UFS_UNIPRO_EB | BIT_AP_APB_UFS_HCI_EB,

	REG_AON_APB_APB_EB1,
	BIT_AON_APB_UFS_AO_EB,

	REG_AP_CLK_CORE_CGM_UFS_TX_CFG,
	BIT_1,

	REG_AP_CLK_CORE_CGM_UFS_RX_CFG,
	BIT_1,

	REG_AON_APB_APB_RST1,
	BIT_AON_APB_UFS_AO_SOFT_RST,

	REG_AP_APB_APB_RST,
	BIT_AP_APB_UFS_UTP_SOFT_RST | BIT_AP_APB_UFS_HCI_SOFT_RST | BIT_AP_APB_UFS_UNIPRO_SOFT_RST | BIT_AP_APB_UFS_SOFT_RST,

	SPRD_UFS_AO_PHYS + 0x1C,
	BIT_1,

	SPRD_UFS_UTP_PHYS + 0x100,
	BIT_0 | BIT_1,

	REG_ANLG_PHY_G1_ANALOG_MIPI_MPHY_1T1R_MPHY_APB_REG,
	BIT_3,

	REG_ANLG_PHY_G1_ANALOG_MIPI_MPHY_1T1R_REG_SEL_CFG_0,
	BIT_6 | BIT_7 | BIT_8,

	REG_PMU_APB_UFS_PWR_GATE_BYP_CFG,
	BIT_PMU_APB_UFS_PWR_GATE_BYP,

	"vddgen",
	"vddemmccore",
};

const struct unipro_cfg_info unipro_ctrl_info[1] = {

	SPRD_UFS_UNIPRO_PHYS,

	SPRD_UFS_UNIPRO_PHYS + 0x3c,
	BIT_24 | BIT_25 | BIT_26 | BIT_27 | BIT_28 | BIT_29,

	SPRD_UFS_UNIPRO_PHYS + 0x40,
	BIT_0,

	SPRD_UFS_UNIPRO_PHYS + 0x84,
	BIT_1,

	SPRD_UFS_UNIPRO_PHYS + 0xc0,
	BIT_4,

	SPRD_UFS_UNIPRO_PHYS + 0xd0,
	BIT_2,

};

struct ufs_cfg_info *get_ufscontrol_info()
{
	return	&ufs_ctrl_info[0];
}

struct unipro_cfg_info *get_uniprocontrol_info()
{
	return	&unipro_ctrl_info[0];
}

 void init_global_reg(void)
{
	struct ufs_cfg_info *sprd_ufs_info;
	struct unipro_cfg_info *sprd_unipro_info;

	sprd_ufs_info = get_ufscontrol_info();
	sprd_unipro_info = get_uniprocontrol_info();

	ufs_info.base_addr = sprd_ufs_info->ufshci_regbase;

	if (sprd_ufs_info->ldo_core != 0)
		regulator_enable(sprd_ufs_info->ldo_core);
	if (sprd_ufs_info->ldo_io != 0)
		regulator_enable(sprd_ufs_info->ldo_io);

	debugf("ufs ldo_core:%s, ldo_io:%s\n",
		sprd_ufs_info->ldo_core, sprd_ufs_info->ldo_io);
	udelay(1000);

	CHIP_REG_SET(sprd_ufs_info->ufs_tx_clk_cfg,
		     sprd_ufs_info->ufs_tx_clk_val);

	CHIP_REG_SET(sprd_ufs_info->ufs_rx_clk_cfg,
		     sprd_ufs_info->ufs_rx_clk_val);

	CHIP_REG_OR(sprd_ufs_info->apb_enable_reg,
		    sprd_ufs_info->apb_enable_bit);
	CHIP_REG_OR(sprd_ufs_info->ao_aon_apb_enable_reg,
		    sprd_ufs_info->ao_aon_apb_enable_bit);

	/*enable mipi use c2g trim value without efuse*/
	CHIP_REG_OR(sprd_ufs_info->anlg_phy_g1_trim_sel_reg,
		    sprd_ufs_info->anlg_phy_g1_trim_bit);

	/*as defaut byp ufs_pwr_gate, as use ufs,we will clear it*/
	CHIP_REG_AND(sprd_ufs_info->pmu_bypass_enable_reg,
		     ~(sprd_ufs_info->pmu_bypass_enable_bit));

	/*reset mphy */
	CHIP_REG_AND(sprd_ufs_info->anlg_phy_g1_reg,
		     ~(sprd_ufs_info->anlg_phy_g1_reset_bit));
	udelay(1000);
	CHIP_REG_OR(sprd_ufs_info->anlg_phy_g1_reg,
		    sprd_ufs_info->anlg_phy_g1_reset_bit);

	CHIP_REG_OR(sprd_ufs_info->apb_reset_reg,
		    sprd_ufs_info->apb_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_ufs_info->apb_reset_reg,
		     ~(sprd_ufs_info->apb_reset_bit));

	CHIP_REG_OR(sprd_ufs_info->ao_aon_apb_reset_reg,
		    sprd_ufs_info->ao_aon_apb_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_ufs_info->ao_aon_apb_reset_reg,
		     ~(sprd_ufs_info->ao_aon_apb_reset_bit));

	/*reset unipro data-link network transport dme */
	CHIP_REG_OR(sprd_unipro_info->dl_reset_reg,
		    sprd_unipro_info->dl_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_unipro_info->dl_reset_reg,
		     ~(sprd_unipro_info->dl_reset_bit));

	CHIP_REG_OR(sprd_unipro_info->n_reset_reg,
		    sprd_unipro_info->n_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_unipro_info->n_reset_reg,
		     ~(sprd_unipro_info->n_reset_bit));

	CHIP_REG_OR(sprd_unipro_info->t_reset_reg,
		    sprd_unipro_info->t_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_unipro_info->t_reset_reg,
		     ~(sprd_unipro_info->t_reset_bit));

	CHIP_REG_OR(sprd_unipro_info->dme_reset_reg,
		    sprd_unipro_info->dme_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_unipro_info->dme_reset_reg,
		     ~(sprd_unipro_info->dme_reset_bit));

	CHIP_REG_OR(ufs_info.base_addr + DW_UFS_RESET_MISC, (BIT_12 | BIT_28));

	CHIP_REG_AND(sprd_ufs_info->utp_reset_reg,
		     ~(sprd_ufs_info->utp_reset_bit));
	udelay(1000);
	CHIP_REG_OR(sprd_ufs_info->utp_reset_reg,
		    sprd_ufs_info->utp_reset_bit);

	udelay(1000);
	CHIP_REG_AND(ufs_info.base_addr + DW_UFS_RESET_MISC, ~(BIT_12 | BIT_28));

	CHIP_REG_OR(sprd_ufs_info->ao_regbase,
		    sprd_ufs_info->ao_rest_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_ufs_info->ao_regbase,
		     ~(sprd_ufs_info->ao_rest_bit));

	CHIP_REG_OR(sprd_unipro_info->pa_rxtx_reset_reg,
		    sprd_unipro_info->pa_rxtx_reset_bit);
	udelay(1000);
	CHIP_REG_AND(sprd_unipro_info->pa_rxtx_reset_reg,
		     ~(sprd_unipro_info->pa_rxtx_reset_bit));
	//fix osc error
	CHIP_REG_OR(0x719000A4,BIT_29);

	//WORKAROUND no rsp data abort error
	CHIP_REG_AND(0x71a00104,~0xff);
	CHIP_REG_OR(0x71a00104,0x4);

	CHIP_REG_OR(0x323B808C,BIT_15);
	CHIP_REG_OR(0x323B801C,BIT_24);

	//WORKAROUND no rsp data abort erro
	CHIP_REG_OR(0x323b4008,0xff);
	CHIP_REG_AND(0x323b801c,~(0x7 << 14));
	CHIP_REG_OR(0x323b801c,0x4 << 14);

	CHIP_REG_OR(0x71800148,BIT_0);
 }

