/*
 * This file is produced by tools!!
 *
 * Copyright (C) 2016 Spreadtrum Communications Inc.
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
#include <asm/arch/sdio_cfg.h>
#include <asm/arch/sdio_reg.h>
#include <asm/arch/common.h>

extern uint32_t (*sdhci_get_delay)(uint32_t device_type);

/*
 * TODO：
 * Now many macros(such as: SPRD_EMMC_BASE, REG_AP_CLK_EMMC_CFG)
 * have not defined in spreadtrum platform, so we use a immediate
 * value instead of it.
 * These immediate values should be removed if the corresponding
 * macros are defined.
 */
const struct sdio_base_info sdio_ctrl_info[2] = {
{
	EMMC,
	SPRD_EMMC_BASE,
#ifdef CONFIG_FPGA
	NULL,
	NULL,
	36000000,
	100000,
#else
	REG_AP_CLK_CGM_EMMC_2X_SEL_CFG,
	BIT_2,
	/* selsect 2x clock source, baseclk = freq / 2 */
	195000000,
	400000,
#endif
	REG_AP_AHB_AHB_EB,
	BIT_AP_AHB_EMMC_EB,
	REG_AP_AHB_AHB_RST,
	BIT_AP_AHB_EMMC_SOFT_RST,
	REG_AON_APB_CGM_CLK_TOP_REG1,
	BIT_AON_APB_CGM_EMMC_2X_EN|BIT_AON_APB_CGM_EMMC_1X_EN,

	"vddgen0",
	"vddemmccore",
	0x3434b760,
},
{
	SD,
	SPRD_SDIO0_BASE,
#ifdef CONFIG_FPGA
	NULL,
	NULL,
	36000000,
	100000,
#else
	REG_AON_CLK_CGM_SDIO0_2X_SEL_CFG,
	BIT_2,
	/* selsect 2x clock source, baseclk = freq / 2 */
	195000000,
	400000,
#endif

	REG_AP_AHB_AHB_EB,
	BIT_AP_AHB_SDIO0_EB,
	REG_AP_AHB_AHB_RST,
	BIT_AP_AHB_SDIO0_SOFT_RST,
	REG_AON_APB_CGM_CLK_TOP_REG1,
	BIT_AON_APB_CGM_SDIO0_2X_EN|BIT_AON_APB_CGM_SDIO0_1X_EN ,

	"vddsdio",
	"vddsdcore",
	0x9a9a1a7f,
}
};

uint32_t get_delay_value(uint32_t device_type)
{
	return sdio_ctrl_info[device_type].hs_dly;
}

struct sdio_base_info *get_sdcontrol_info(uint32_t device_type)
{
	sdhci_get_delay = get_delay_value;
	return  &sdio_ctrl_info[device_type];
}

