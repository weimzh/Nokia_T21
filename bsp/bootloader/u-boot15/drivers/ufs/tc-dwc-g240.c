// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2019 Synopsys Inc.
 * Authors:
 *	Pedro Sousa <sousa@synopsys.com>
 */
#include <common.h>
//#include "ufshcd.h"
#include "unipro.h"
#include <sprd_ufs.h>
#include "ufshcd-dwc.h"
#include "ufshci-dwc.h"
#include "tc-dwc-g240.h"
#include "ufshci.h"


enum ufs_ref_clk_freq {
	REF_CLK_FREQ_19_2_MHZ =0,
	REF_CLK_FREQ_26_MHZ =1,
	REF_CLK_FREQ_38_4_MHZ =2,
	REF_CLK_FREQ_52_MHZ =3,
	REF_CLK_FREQ_INVAL =-1,
};


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define DME_LOCAL 0

static int tc_refclk = REF_CLK_FREQ_26_MHZ;
//module_param(tc_refclk, int, 0);
//MODULE_PARM_DESC(tc_refclk, "RefClk (0 = 19.2 MHz, 1 = 26 MHz, 38.4 MHz, 52 MHz)");

/**
 * tc_dwc_g240_perform_zcall()
 * This function performs the zcall in Synopsys G240 TC
 * @hba: Pointer to driver structure
 *
 * Returns 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_perform_zcall(void)
{
	int ret;
	int zcall_retries = 10;
	uint32_t zcall_ok = 0;
#if 1
	 const struct ufshcd_dme_attr_val zcall_attrs[] = {
		{ UIC_ARG_MIB_SEL(SFR_ZCALL, SELIND_LN1_TX), 0x03, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_ZCALL, SELIND_LN1_TX), 0x01, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_ZCALL, SELIND_LN1_TX), 0x02, DME_LOCAL },
	};
#endif
//	static const struct ufshcd_dme_attr_val zcall_attrs[] = {
		

	ret = ufshcd_dwc_dme_set_attrs(zcall_attrs,
				       ARRAY_SIZE(zcall_attrs));

	do {
		zcall_ok = dme_get(UIC_ARG_MIB_SEL(SFR_ZCALL_OUT,SELIND_LN1_TX));
		//usleep_range(1, 5);
		udelay(5);

		zcall_retries--;
	} while (!zcall_ok && zcall_retries);

	if (!zcall_ok)
		ret = 1;

	return ret;
}

/**
 * tc_dwc_g240_reset_pll2_idelay()
 * This function resets the PLL idelay values
 *
 * @hba: Pointer to driver structure
 */

static int tc_dwc_g240_reset_pll2_idelay(void)
{
	 const struct ufshcd_dme_attr_val rst_seq[] = {
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX0_VAL_IN, SELIND_LN1_TX), 0x01,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX0_VAL_IN, SELIND_LN1_TX), 0x00,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAYCTRL_RST, SELIND_LN1_TX), 0x31,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAYCTRL_RST, SELIND_LN1_TX), 0x00,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX0_DATA_0, SELIND_LN1_TX), 0x04,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX0_DATA_0, SELIND_LN1_TX), 0x14,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX0_DATA_0, SELIND_LN1_TX), 0x00,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX1_DATA_0, SELIND_LN1_TX), 0x04,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX1_DATA_0, SELIND_LN1_TX), 0x14,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_ODELAY_TX1_DATA_0, SELIND_LN1_TX), 0x00,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAY_RX0_DATA, SELIND_LN1_TX), 0x04,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAY_RX0_DATA, SELIND_LN1_TX), 0x14,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAY_RX0_DATA, SELIND_LN1_TX), 0x00,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAY_TX0_SYMBOL, SELIND_LN1_TX), 0x04,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAY_TX0_SYMBOL, SELIND_LN1_TX), 0x14,
					DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_IDELAY_TX0_SYMBOL, SELIND_LN1_TX), 0x00,
					DME_LOCAL},
	};

	return ufshcd_dwc_dme_set_attrs(rst_seq, ARRAY_SIZE(rst_seq));
}

/**
 * tc_dwc_g240_jtag_reset()
 *
 * This function resets the jtag interface in Synopsys G240 TC
 * @hba: Pointer to driver structure
 *
 * Returns 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_jtag_reset(void)
{
	int ret;
	 const struct ufshcd_dme_attr_val jtag_rst[] = {
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX), 0x00,
					DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX), 0x04,
					DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX), 0x00,
					DME_LOCAL },
	};

	ret =  ufshcd_dwc_dme_set_attrs(jtag_rst, ARRAY_SIZE(jtag_rst));

	//usleep_range(3, 5);
	udelay(5);

	return ret;
}

/**
 * tc_dwc_g240_jtag_init_ir()
 *
 * This function will select the JTAG IR state
 * @hba: Pointer to driver structure
 *
 * Return 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_jtag_init_ir(void)
{
	int ret;
	 const struct ufshcd_dme_attr_val jtag_rst[] = {
		{ UIC_ARG_MIB_SEL(SFR_JTAG_ADDR, SELIND_LN1_TX), 0x31,
					DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX), 0x01,
					DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX), 0x00,
					DME_LOCAL },
	};

	ret =  ufshcd_dwc_dme_set_attrs(jtag_rst, ARRAY_SIZE(jtag_rst));

	//usleep_range(3, 5);
	udelay(5);

	return ret;
}

/**
 * tc_dwc_g240_jtag_write()
 *
 * This function writes to the jtag interface in Synopsys G240 TC
 * @hba: Pointer to driver structure
 * @jtag_reg: JTAG register to write into
 * @jtag_val: JTAG value to be written
 *
 * Returns 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_jtag_write(uint32_t jtag_reg, uint32_t jtag_val)
{
	int ret;
	struct ufshcd_dme_attr_val jtag_write_addr[] = {
		{ UIC_ARG_MIB_SEL(SFR_JTAG_DATA_WR1, SELIND_LN1_TX),
					REG_16_MSB(jtag_reg), DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_JTAG_DATA_WR2, SELIND_LN1_TX),
					REG_16_LSB(jtag_reg), DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_JTAG_CMD, SELIND_LN1_TX),
					SFR_JTAG_CMD_ADDR, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX),
					SFR_JTAG_START_PULSE_HIGH, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX),
					SFR_JTAG_START_PULSE_LOW, DME_LOCAL},
	};
	struct ufshcd_dme_attr_val jtag_write_data[] = {
		{ UIC_ARG_MIB_SEL(SFR_JTAG_DATA_WR1, SELIND_LN1_TX),
					REG_16_MSB(jtag_val), DME_LOCAL },
		{ UIC_ARG_MIB_SEL(SFR_JTAG_DATA_WR2, SELIND_LN1_TX),
					REG_16_LSB(jtag_val), DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_JTAG_CMD, SELIND_LN1_TX),
					SFR_JTAG_CMD_DATA, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX),
					SFR_JTAG_START_PULSE_HIGH, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_JTAG_START, SELIND_LN1_TX),
					SFR_JTAG_START_PULSE_LOW, DME_LOCAL},
	};

	ret =  ufshcd_dwc_dme_set_attrs(jtag_write_addr, ARRAY_SIZE(jtag_write_addr));
	//usleep_range(3, 5);
	udelay(5);

	ret |=  ufshcd_dwc_dme_set_attrs(jtag_write_data, ARRAY_SIZE(jtag_write_data));
//	usleep_range(3, 5);
	udelay(5);
	
	return ret;
}

/**
 * tc_dwc_g240_c10_write()
 *
 * This function writes to the c10 interface in Synopsys G240 TC
 * @hba: Pointer to driver structure
 * @c10_reg: c10 register to write into
 * @c10_val: c10 value to be written
 *
 * Returns 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_c10_write(uint32_t c10_reg, uint32_t c10_val)
{
	int ret;
	struct ufshcd_dme_attr_val c10_write[] = {
		{ UIC_ARG_MIB(CBC_REG_ADDR_LSB), REG_16_LSB(c10_reg),
			DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_ADDR_MSB), REG_16_MSB(c10_reg),
			DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_WR_LSB), REG_16_LSB(c10_val), DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_WR_MSB), REG_16_MSB(c10_val), DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_RD_WR_SEL), CBC_REG_WRITE, DME_LOCAL },
		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL },
	};

	ret = ufshcd_dwc_dme_set_attrs(c10_write, ARRAY_SIZE(c10_write));

	return ret;
}

/**
 * tc_dwc_g240_c10_read()
 *
 * This function reads from the c10 interface in Synopsys G240 TC
 * @hba: Pointer to driver structure
 * @c10_reg: c10 register to read from
 * @c10_val: c10 value read
 *
 * Returns 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_c10_read(uint32_t c10_reg, uint16_t *c10_val)
{
	int ret;
	uint32_t tmp_rd_lsb;
	uint32_t tmp_rd_msb;
	struct ufshcd_dme_attr_val c10_read[] = {
		{ UIC_ARG_MIB(CBC_REG_ADDR_LSB), REG_16_LSB(c10_reg),
			DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_ADDR_MSB), REG_16_MSB(c10_reg),
			DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_WR_LSB), 0xff, DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_WR_MSB), 0xff, DME_LOCAL },
		{ UIC_ARG_MIB(CBC_REG_RD_WR_SEL), CBC_REG_READ, DME_LOCAL },
		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL },
	};

	ret = ufshcd_dwc_dme_set_attrs(c10_read, ARRAY_SIZE(c10_read));

	ret |= dme_set(UIC_ARG_MIB(CBC_REG_RD_LSB), 0x00);
	tmp_rd_lsb = dme_get(UIC_ARG_MIB(CBC_REG_RD_LSB));
	ret |= dme_set(UIC_ARG_MIB(CBC_REG_RD_MSB), 0x00);
	tmp_rd_msb = dme_get(UIC_ARG_MIB(CBC_REG_RD_MSB));

	if (ret)
		goto out;

	*c10_val = (tmp_rd_msb << 8) | tmp_rd_lsb;

out:
	return ret;
}

/**
 * tc_dwc_g240_config_rate()
 * This function configs the rate and refclk of  Synopsys G240 TC
 * @hba: Pointer to driver structure
 * @rate: Rate to configure the phy (it can be PA_HS_MODE_A or PA_HS_MODE_B)
 *
 * Returns 0 on success or non-zero value on failure
 */
static int tc_dwc_g240_config_rate(uint32_t rate)
{
	int ret = 0;
	struct tc_rate_cfg_params *cfg_sel;
	struct tc_rate_cfg_params rate_refclk_cnfgs[][4] = {
		{ /* Rate A */
			/* 19 [MHz] */
			{0x202, 0x4c, 0x618, 0x1e86, 0x618, 0x1e86},
			/* 26 [MHz] */
			{0x260, 0x4b, 0x540, 0x1e87, 0x540, 0x1e87},
			/* 38.4 [MHz] */
			{0x241, 0x47, 0x596, 0x1e8b, 0x596, 0x1e8b},
			/* 52 [MHz] */
			{0x230, 0x46, 0x540, 0x1e8e, 0x540, 0x1e8e},

		}, { /* Rate B */
			/* 19 [MHz] */
			{0x2cc, 0x2d, 0x5f0, 0x1e85, 0x5f0, 0x1e85},
			/* 26 [MHz] */
			{0x270, 0x2b, 0x543, 0x1e86, 0x543, 0x1e86},
			/* 38.4 [MHz] */
			{0x24c, 0x27, 0x558, 0x1e89, 0x558, 0x1e89},
			/* 52 [MHz] */
			{0x238, 0x26, 0x543, 0x1e8c, 0x543, 0x1e8c},
		}
	};

	if (rate != PA_HS_MODE_A && rate != PA_HS_MODE_B) {
		errorf("Invalid Rate request");
		ret = 1;
		goto out;
	}

	if (tc_refclk != REF_CLK_FREQ_19_2_MHZ &&
	    tc_refclk != REF_CLK_FREQ_26_MHZ &&
	    tc_refclk != REF_CLK_FREQ_38_4_MHZ &&
	    tc_refclk != REF_CLK_FREQ_52_MHZ) {
		errorf("Invalid Rate requestes in module param");
		ret = 1;
		goto out;
	}

	/* PA_HS_MODE_A == 1 && PA_HS_MODE_A == 2, "-1" used to map the value to
	 * tc_rate_cfg_params[0] and tc_rate_cfg_params[1] respectively
	 */
	cfg_sel = &rate_refclk_cnfgs[rate - 1][tc_refclk];

	ret |= tc_dwc_g240_jtag_write(JTAG_INIT_REFSEL, 0x0026);
	ret |= tc_dwc_g240_jtag_write(JTAG_INIT_SGEAR, 0x01bf);

	/* Test Chip JTAG Registers dependent on rate/refclk */
	ret |= tc_dwc_g240_jtag_write(JTAG_MPLLA_MULTIPLIER,
				     cfg_sel->mplla_multiplier);
	ret |= tc_dwc_g240_jtag_write(JTAG_MPLLA_BANDWIDTH,
				      cfg_sel->mplla_bandwidth);
	ret |= tc_dwc_g240_jtag_write(JTAG_RX0_VCO_LD_VAL,
				      cfg_sel->rx0_vco_ld_val);
	ret |= tc_dwc_g240_jtag_write(JTAG_RX0_REF_LD_VAL,
				      cfg_sel->rx0_ref_ld_val);
	ret |= tc_dwc_g240_jtag_write(JTAG_RX1_VCO_LD_VAL,
				      cfg_sel->rx1_vco_ld_val);
	ret |= tc_dwc_g240_jtag_write(JTAG_RX1_REF_LD_VAL,
				      cfg_sel->rx1_ref_ld_val);

	ret |= tc_dwc_g240_jtag_write(JTAG_RX0_CDR_VCO_LOW_FREQ, 0x2040);
	ret |= tc_dwc_g240_jtag_write(JTAG_RX1_CDR_VCO_LOW_FREQ, 0x2040);

	ret |= tc_dwc_g240_jtag_write(JTAG_RX0_EQ_DFE_TAP, 0x70);
	ret |= tc_dwc_g240_jtag_write(JTAG_RX1_EQ_DFE_TAP, 0x70);

	ret |= dme_set(UIC_ARG_MIB_SEL(SFR_REF_CLK_SEL,SELIND_LN1_TX),0x1);
	ret |= dme_set(UIC_ARG_MIB(CBRATSEL),0x1);
out:
	return ret;
}

/**
 * tc_dwc_g240_rmmi_config()
 * This function configures Synopsys G240 16nm TC
 * @hba: Pointer to drivers structure
 * @do_call: indication to enable calibration. If this value this parameter
 *	     is 0 the value of @call_val will be used
 * @call_val: Coarse tune value from calibration to be written
 *
 * Returns 0 on success non-zero value on failure
 */
static int tc_dwc_g240_rmmi_config(bool do_call,u16 call_val)
{
	int ret;
	uint32_t temp_reg = 0;
	uint32_t val;

	 const struct ufshcd_dme_attr_val rmmi_config[] = {
		{ UIC_ARG_MIB_SEL(SFR_CFG_CLK, SELIND_LN1_TX), 0x1a, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_TX_WC_BYPASS, SELIND_LN1_TX), 0x2,
			DME_LOCAL},
		{ UIC_ARG_MIB_SEL(SFR_RX_WC_BYPASS, SELIND_LN1_TX), 0x2,
			DME_LOCAL},
		{ UIC_ARG_MIB(RMMI_CBCRCTRL), 0x1, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(RMMI_RXSQCONTROL, SELIND_LN0_RX), 0x1,
			DME_LOCAL},
		{ UIC_ARG_MIB_SEL(RMMI_RXRHOLDCTRLOPT, SELIND_LN0_RX), 0x2,
			DME_LOCAL},
		{ UIC_ARG_MIB_SEL(RMMI_RXSQCONTROL, SELIND_LN1_RX), 0x1,
			DME_LOCAL},
		{ UIC_ARG_MIB_SEL(RMMI_RXRHOLDCTRLOPT, SELIND_LN1_RX), 0x2,
			DME_LOCAL},
		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL},
		{ UIC_ARG_MIB(RMMI_CBENBLCPBATTRWR), 0x1, DME_LOCAL},
		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(RX_HS_G4_SYNC_LENGTH_CAPABILITY,
				  SELIND_LN0_RX), 0x4c, DME_LOCAL},
		{ UIC_ARG_MIB_SEL(RX_HS_G4_SYNC_LENGTH_CAPABILITY,
			SELIND_LN1_RX),	0x4c, DME_LOCAL},
		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL},
		{ UIC_ARG_MIB(RMMI_CBENBLCPBATTRWR), 0x0, DME_LOCAL},
		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL},
	};

	ret = ufshcd_dwc_dme_set_attrs(rmmi_config, ARRAY_SIZE(rmmi_config));
#if 0
	if (hba->hwv_params.device_mode && !do_call) {
		ret |= ufshcd_dme_set_attr(hba, UIC_ARG_MIB(RMMI_CBREFCLKCTRL2),
					   ATTR_SET_NOR, 0x50, DME_LOCAL);

		if (hba->hwv_params.ulp_h8) {
			ret |= ufshcd_dme_get_attr(hba,
						   UIC_ARG_MIB(RMMI_CBUPLH8),
						   &temp_reg, DME_LOCAL);
			ret |= ufshcd_dme_set_attr(hba,
						   UIC_ARG_MIB(RMMI_CBUPLH8),
						   ATTR_SET_NOR, temp_reg | 0x1,
						   DME_LOCAL);
		} else  {
			ret |= ufshcd_dme_get_attr(hba,
						   UIC_ARG_MIB(RMMI_CBUPLH8),
						   &temp_reg, DME_LOCAL);
			ret |= ufshcd_dme_set_attr(hba,
						   UIC_ARG_MIB(RMMI_CBUPLH8),
						   ATTR_SET_NOR,
						   temp_reg & 0xfffe,
						   DME_LOCAL);
		}

	} else if (hba->hwv_params.device_mode && do_call) {
		debugf("Device mode configured\n");
	} else {
#endif
		ret |= dme_set(UIC_ARG_MIB(RMMI_CBREFCLKCTRL2),0x80);
//	}

	if (do_call) {
		ret |= tc_dwc_g240_c10_write(MPLL_PWR_CTL_CAL_CTRL, 0x08);
	} else {
		ret |= dme_set(UIC_ARG_MIB(RMMI_CBREFCLKCTRL2),0x80);

		ret |= tc_dwc_g240_c10_write(MPLL_PWR_CTL_CAL_CTRL, 0x18);
		ret |= tc_dwc_g240_c10_write(MPLL_COARSE_TUNE_VAL, call_val);
		ret |= tc_dwc_g240_c10_write(RAWAONLANEN_DIG_MPLLA_COARSE_TUNE,
					     call_val);
		ret |= dme_set(UIC_ARG_MIB(EXT_COARSE_TUNE_RATEB),call_val);
	}

	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX0_DAC_CTRL_OVRD,0x1);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX0_DAC_CTRL, 0x80);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX0_DAC_CTRL_SEL,0x1a);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX0_ANA_CAL_DAC_CTRL_EN,0x01);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX0_DAC_CTRL_OVRD, 0x0);
	ret |= tc_dwc_g240_c10_write(RAWAONLANEN_DIG_FAST_FLAGS0, 0x04);

	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX1_DAC_CTRL_OVRD, 0x1);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX1_DAC_CTRL, 0x80);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX1_DAC_CTRL_SEL, 0x1a);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX1_ANA_CAL_DAC_CTRL_EN,0x01);
	ret |= tc_dwc_g240_c10_write(LANE_DIG_ANA_RX1_DAC_CTRL_OVRD, 0x0);
	ret |= tc_dwc_g240_c10_write(RAWAONLANEN_DIG_FAST_FLAGS1, 0x04);

	val = dme_get(UIC_ARG_MIB(0x1));

	val = dme_get(0x8114);
	if(val !=0x01)
		errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x8114,val,0x01);

	val = dme_get(0x811F);
	if(val!=0x01)
		errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x811F,val,0x01);

	val = dme_get(0x8132);
        if(val!=0x80)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x8132,val,0x80);

	dme_set(0x8113,0x1);
	dme_set(0xD085,0x00000001);
	dme_set(0x4008F,0x02);
	dme_set(0x5008F,0x02);
	dme_set(0x8113,0x0);
	dme_set(0xD085,0x1);

	val = dme_get(0x48009);
        if(val!=0x1)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x48009,val,0x01);
	val = dme_get(0x48013);
        if(val!=0x02)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x48013,val,0x02);

	val = dme_get(0x4008F);
        if(val!=0x02)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x4008F,val,0x02);

        val = dme_get(0x58009);
        if(val!=0x01)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x58009,val,0x01);

	val = dme_get(0x58013);
        if(val!=0x02)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x580013,val,0x02);

	val = dme_get(0x5008F);
        if(val!=0x02)
                errorf("reg :0x%x val:0x%x!= the set val:0x%x!\n",0x5008F,val,0x02);

	ret |= dme_set(UIC_ARG_MIB(VS_MPHY_DISABLE),0x00);
	ret |= dme_set(UIC_ARG_MIB(VS_DEBUG_SAVE_CFG_TIME),0x3);

	return ret;
}

/**
 * tc_dwc_g240_force_mphy_hs()
 * This function configures the MPHY directly to HS
 * Must be used only during phy initialization
 *
 * @hba: Pointer to drivers structure
 *
 * Returns 0 on success non-zero value on failure
 */
static int tc_dwc_g240_force_mphy_hs(void)
{
	int ret;
	const struct ufshcd_dme_attr_val force_mphy_hs[] = {
		{ UIC_ARG_MIB(TX_HIBERN8_CONTROL), 0x0, DME_LOCAL },
		{ UIC_ARG_MIB(TX_MODE), 0x2, DME_LOCAL },
		{ UIC_ARG_MIB(TX_HSGEAR), 0x1, DME_LOCAL },

		{ UIC_ARG_MIB_SEL(TX_HIBERN8_CONTROL, SELIND_LN1_TX), 0x0,
					DME_LOCAL },
		{ UIC_ARG_MIB_SEL(TX_MODE, SELIND_LN1_TX), 0x2, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(TX_HSGEAR, SELIND_LN1_TX), 0x1, DME_LOCAL },

		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL },

		{ UIC_ARG_MIB_SEL(RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY,
					SELIND_LN0_RX), 0x1, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY,
					SELIND_LN0_RX), 0x1, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(RX_MODE, SELIND_LN0_RX), 0x2, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(RX_HSGEAR, SELIND_LN0_RX), 0x1, DME_LOCAL },

		{ UIC_ARG_MIB_SEL(RX_MIN_SLEEP_NOCONFIG_TIME_CAPABILITY,
					SELIND_LN1_RX), 0x1, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(RX_MIN_STALL_NOCONFIG_TIME_CAPABILITY,
					SELIND_LN1_RX), 0x1, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(RX_MODE, SELIND_LN1_RX), 0x2, DME_LOCAL },
		{ UIC_ARG_MIB_SEL(RX_HSGEAR, SELIND_LN1_RX), 0x1, DME_LOCAL },

		{ UIC_ARG_MIB(VS_MPHYCFGUPDT), 0x1, DME_LOCAL },
	};

	ret = ufshcd_dwc_dme_set_attrs(force_mphy_hs,
				       ARRAY_SIZE(force_mphy_hs));

	return ret;
}

/**
 * __tc_dwc_g240_16nm_config()
 * This function configures Synopsys G240 16nm TC
 *
 * @hba: Pointer to drivers structure
 * @do_call: indication to enable calibration. If this value is 0 the value
 * @call_val: Coarse tune value from calibration to be written
 * of @call_val will be used
 *
 * Returns 0 on success non-zero value on failure
 */
int __tc_dwc_g240_16nm_config( bool do_call, uint16_t call_val)
{
	int ret;

	/*ufshcd_writel(hba, 0x3, 0x20028);*/

	ret = tc_dwc_g240_perform_zcall();

	if (ret) {
		errorf("Zcall failed\n");
		goto out;
	}

	ret = tc_dwc_g240_reset_pll2_idelay();

	if (ret) {
		errorf("Pll and idelay reset failed\n");
		goto out;
	}

	ret = tc_dwc_g240_jtag_reset();

	if (ret) {
		errorf("JTAG reset failed");
		goto out;
	}

	ret = tc_dwc_g240_jtag_init_ir();

	if (ret) {
		errorf("JTAG selecting IR failed");
		goto out;
	}
#if 0
	if (hba->hwv_params.device_mode && !do_call) {
		ret = tc_dwc_g240_jtag_write(hba, JTAG_REF_USE_PAD, 0x0000);
		ufshcd_writel(hba, 0x0, 0x20028);
	} else {
#endif
	ret = tc_dwc_g240_jtag_write(JTAG_REF_USE_PAD, 0x0001);
//	}

	if (ret) {
		errorf("Failed enabling ref_use_pad");
		goto out;
	}

	ret = tc_dwc_g240_config_rate(PA_HS_MODE_A);

	if (ret) {
		errorf("Failed to config rate and refclk");
		goto out;
	}

	ret = tc_dwc_g240_rmmi_config(do_call, call_val);

	if (ret) {
		errorf("Failed to config rmmi");
		goto out;
	}

out:
	return ret;
}

/**
 * tc_dwc_g240_config()
 * This function is a wrapper to configure the Synopsys G240 16nm TC
 * which handles the phy MPLL calibration with __tc_dwc_g240_config()
 *
 * @hba: Pointer to drivers structure
 *
 * Returns 0 on success non-zero value on failure
 */
int tc_dwc_g240_16nm_config()
{
	int ret = 0;

	uint16_t cal_value = 0;

	debugf("Configuring G240 TC\n");

	/* Configure for calibration (cal value '0x0' ignored)
	 */
	ret |= __tc_dwc_g240_16nm_config(0x1, 0x0);
	if (ret)
		goto out;

	/* Force MPHY to HS, this is necessary for MPLL calibration
	 */
	ret |= tc_dwc_g240_force_mphy_hs();
	if (ret)
		goto out;

	/* Wait 10 ms for MPLL calibration
	 */
//	usleep_range(10000, 10500);
	//msleep(10);
	mdelay(10);

	/* Retrieve MPLL Calibration value
	 */
	ret |= tc_dwc_g240_c10_read(MPLL_COARSE_TUNE_VAL, &cal_value);
	if (ret)
		goto out;

	/* Configure TC without MPLL calibration and used the MPLL calibration
	 * value retrieved
	 */
	ret |= __tc_dwc_g240_16nm_config(0x0, cal_value);

	debugf("Config G240 TC end\n");

out:
	return ret;
}
EXPORT_SYMBOL(tc_dwc_g240_16nm_config);
#if 0
int tc_dwc_g240_link_startup_notify(struct ufs_hba *hba,
				    enum ufs_notify_change_status status)
{
	int ret = 0;

	if (status == POST_CHANGE) {
		if (!hba->hwv_params.device_mode)
			/* Necessary for HSG4 FPGA environment */
			ret |= ufshcd_dme_set_attr(hba,
					   UIC_ARG_MIB(DL_AFC0CREDITTHRESHOLD),
					   ATTR_SET_NOR, 0x6a, DME_PEER);
	};

	ret |= ufshcd_dwc_link_startup_notify(hba, status);

	return ret;
}
EXPORT_SYMBOL(tc_dwc_g240_link_startup_notify);

MODULE_AUTHOR("Pedro Sousa <sousa@synopsys.com>");
MODULE_DESCRIPTION("Synopsys DesignWare G240 TC driver");
MODULE_LICENSE("GPL v2");
#endif
