/******************************************************************************
 ** File Name:      pmu.c                                             *
 ** Author:         Zhongfa.Wang                                              *
 ** DATE:           26/12/2016                                                *
 ** Copyright:      2014 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:    This file defines the basic information on chip.          *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 26/12/2016     Zhongfa.Wang		Create.                                   *
 ******************************************************************************/

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
#include <asm/io.h>
#include "adi_hal_internal.h"
//#include "asm/arch/wdg_drvapi.h"
#include "asm/arch-sharkl3/sprd_reg.h"
#include "asm/arch-sharkl3/common.h"
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
extern   "C"
{
#endif

#ifndef CONFIG_FPGA
#define REFIN 26
#define NINT(FREQ,REFIN)	(FREQ/REFIN)
#define KINT(FREQ,REFIN)	((FREQ-(FREQ/REFIN)*REFIN)*(BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_KINT(~0x0)+1)/REFIN)

#define SPRD_PLL_MAX_RATE               (0xFFFFFFFFUL)

struct sprd_ibias_table {
	unsigned long rate;
	u8 ibias;
};

static struct sprd_ibias_table mpll_ibias_table[] = {
	{
		.rate = 1000000000UL,
		.ibias = 0x0,
	},
	{
		.rate = 1200000000UL,
		.ibias = 0x1,
	},
	{
		.rate = 1400000000UL,
		.ibias = 0x2,
	},
	{
		.rate = 1600000000,
		.ibias = 0x3,
	},
	{
		.rate = 1800000000,
		.ibias = 0x4,
	},
	{
		.rate = SPRD_PLL_MAX_RATE,
		.ibias = 0x5,
	},
};

void pmu_commom_config(void)
{
	uint32_t reg_val;

	/*according to spec from asic, configure the follow 3 bit, other bit is disable and can be default*/
	reg_val = CHIP_REG_GET(REG_PMU_APB_CGM_PMU_SEL) & 0xFFFFFFE0;
	CHIP_REG_SET(REG_PMU_APB_CGM_PMU_SEL,
		reg_val |
		BIT_PMU_APB_CGM_PMU_26M_EN |
		BIT_PMU_APB_CGM_PMU_26M_SEL(0x01) |
		BIT_PMU_APB_CGM_PMU_SEL(0x01) |
		0
	);
	/*The all power domains pd_sel can be 0(default) accord to asic*/
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_TOP_CFG,
		//BIT_PMU_APB_PD_CPU_TOP_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_TOP_PD_SEL |
		//BIT_PMU_APB_PD_CPU_TOP_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_CPU_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_TOP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_CPU_TOP_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_CPU_TOP_ISO_ON_DLY(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_LIT_C0_CFG,
		//BIT_PMU_APB_PD_CPU_LIT_C0_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_LIT_C0_PD_SEL |
		BIT_PMU_APB_CPU_LIT_C0_WAKEUP_EN |
		//BIT_PMU_APB_PD_CPU_LIT_C0_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_CPU_LIT_C0_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_LIT_C0_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_LIT_C0_PWR_ON_SEQ_DLY(0x36) |
		BIT_PMU_APB_PD_CPU_LIT_C0_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_LIT_C1_CFG,
		//BIT_PMU_APB_PD_CPU_LIT_C1_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_LIT_C1_PD_SEL |
		//BIT_PMU_APB_CPU_LIT_C1_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_LIT_C1_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_LIT_C1_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_LIT_C1_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_LIT_C1_PWR_ON_SEQ_DLY(0x34) |
		BIT_PMU_APB_PD_CPU_LIT_C1_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_LIT_C2_CFG,
		//BIT_PMU_APB_PD_CPU_LIT_C2_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_LIT_C2_PD_SEL |
		//BIT_PMU_APB_CPU_LIT_C2_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_LIT_C2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_LIT_C2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_LIT_C2_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_LIT_C2_PWR_ON_SEQ_DLY(0x32) |
		BIT_PMU_APB_PD_CPU_LIT_C2_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_LIT_C3_CFG,
		//BIT_PMU_APB_PD_CPU_LIT_C3_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_LIT_C3_PD_SEL |
		//BIT_PMU_APB_CPU_LIT_C3_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_LIT_C3_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_LIT_C3_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_LIT_C3_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_LIT_C3_PWR_ON_SEQ_DLY(0x30) |
		BIT_PMU_APB_PD_CPU_LIT_C3_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA53_LIT_MP2_CFG,
		//BIT_PMU_APB_PD_CA53_LIT_MP2_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CA53_LIT_MP2_PD_SEL |
		//BIT_PMU_APB_PD_CA53_LIT_MP2_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_CA53_LIT_MP2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA53_LIT_MP2_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CA53_LIT_MP2_PWR_ON_SEQ_DLY(0x03) |
		BIT_PMU_APB_PD_CA53_LIT_MP2_ISO_ON_DLY(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_BIG_C0_CFG,
		//BIT_PMU_APB_PD_CPU_BIG_C0_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_BIG_C0_PD_SEL |
		//BIT_PMU_APB_CPU_BIG_C0_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_BIG_C0_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_BIG_C0_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_BIG_C0_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_BIG_C0_PWR_ON_SEQ_DLY(0x36) |
		BIT_PMU_APB_PD_CPU_BIG_C0_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_BIG_C1_CFG,
		//BIT_PMU_APB_PD_CPU_BIG_C1_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_BIG_C1_PD_SEL |
		//BIT_PMU_APB_CPU_BIG_C1_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_BIG_C1_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_BIG_C1_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_BIG_C1_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_BIG_C1_PWR_ON_SEQ_DLY(0x34) |
		BIT_PMU_APB_PD_CPU_BIG_C1_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_BIG_C2_CFG,
		//BIT_PMU_APB_PD_CPU_BIG_C2_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_BIG_C2_PD_SEL |
		//BIT_PMU_APB_CPU_BIG_C2_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_BIG_C2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_BIG_C2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_BIG_C2_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_BIG_C2_PWR_ON_SEQ_DLY(0x32) |
		BIT_PMU_APB_PD_CPU_BIG_C2_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_BIG_C3_CFG,
		//BIT_PMU_APB_PD_CPU_BIG_C3_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_BIG_C3_PD_SEL |
		//BIT_PMU_APB_CPU_BIG_C3_WAKEUP_EN |
		BIT_PMU_APB_PD_CPU_BIG_C3_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CPU_BIG_C3_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_BIG_C3_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_BIG_C3_PWR_ON_SEQ_DLY(0x30) |
		BIT_PMU_APB_PD_CPU_BIG_C3_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CA53_BIG_MP2_CFG,
		//BIT_PMU_APB_PD_CA53_BIG_MP2_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CA53_BIG_MP2_PD_SEL |
		BIT_PMU_APB_PD_CA53_BIG_MP2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_CA53_BIG_MP2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CA53_BIG_MP2_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CA53_BIG_MP2_PWR_ON_SEQ_DLY(0x03) |
		BIT_PMU_APB_PD_CA53_BIG_MP2_ISO_ON_DLY(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AP_SYS_CFG,
		//BIT_PMU_APB_PD_AP_SYS_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_AP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AP_SYS_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_AP_SYS_PWR_ON_SEQ_DLY(0x0) |
		BIT_PMU_APB_PD_AP_SYS_ISO_ON_DLY(0x09) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_MM_TOP_CFG,
		//BIT_PMU_APB_PD_MM_TOP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_MM_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_MM_TOP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_MM_TOP_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_MM_TOP_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_TOP_CFG,
		//BIT_PMU_APB_PD_GPU_TOP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_GPU_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_GPU_TOP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_GPU_TOP_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_GPU_TOP_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_TD_CFG,
		BIT_PMU_APB_PD_WTLCP_TD_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_TD_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_TD_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_TD_PWR_ON_SEQ_DLY(0x44) |
		BIT_PMU_APB_PD_WTLCP_TD_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P1_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P1_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P1_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P1_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_LTE_P1_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_WTLCP_LTE_P1_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P2_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P2_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_LTE_P2_PWR_ON_SEQ_DLY(0x42) |
		BIT_PMU_APB_PD_WTLCP_LTE_P2_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_MM_VSP_CFG,
		//BIT_PMU_APB_PD_MM_VSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_MM_VSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_MM_VSP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_MM_VSP_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_MM_VSP_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LDSP_CFG,
		//BIT_PMU_APB_PD_WTLCP_LDSP_PD_SEL |
		BIT_PMU_APB_PD_WTLCP_LDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LDSP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_LDSP_PWR_ON_SEQ_DLY(0x47) |
		BIT_PMU_APB_PD_WTLCP_LDSP_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_TGDSP_CFG,
		//BIT_PMU_APB_PD_WTLCP_TGDSP_PD_SEL |
		BIT_PMU_APB_PD_WTLCP_TGDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_TGDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_TGDSP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_TGDSP_PWR_ON_SEQ_DLY(0x48) |
		BIT_PMU_APB_PD_WTLCP_TGDSP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_HU3GE_A_CFG,
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_HU3GE_A_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_PWR_ON_SEQ_DLY(0x45) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_HU3GE_B_CFG,
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_HU3GE_B_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_PWR_ON_SEQ_DLY(0x46) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_SYS_CFG,
		BIT_PMU_APB_PD_WTLCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_SYS_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_SYS_PWR_ON_SEQ_DLY(0x40) |
		BIT_PMU_APB_PD_WTLCP_SYS_ISO_ON_DLY(0x05) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_PUBCP_SYS_CFG,
		//BIT_PMU_APB_PD_PUBCP_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUBCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_PUBCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUBCP_SYS_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_PUBCP_SYS_PWR_ON_SEQ_DLY(0x40) |
		BIT_PMU_APB_PD_PUBCP_SYS_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_P3_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_P3_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_P3_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_P3_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WTLCP_LTE_P3_PWR_ON_SEQ_DLY(0x43) |
		BIT_PMU_APB_PD_WTLCP_LTE_P3_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_DISP_CFG,
		//BIT_PMU_APB_PD_DISP_PD_SEL |
		//BIT_PMU_APB_PD_DISP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_DISP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_DISP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_DISP_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_DISP_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_PUB_SYS_CFG,
		//BIT_PMU_APB_PD_PUB_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_PUB_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUB_SYS_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_PUB_SYS_PWR_ON_SEQ_DLY(0x40) |
		BIT_PMU_APB_PD_PUB_SYS_ISO_ON_DLY(0x05) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTL_WAIT_CNT,
		BIT_PMU_APB_XTL1_WAIT_CNT(0x34) |
		BIT_PMU_APB_XTL0_WAIT_CNT(0x34) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTLBUF_WAIT_CNT,
		BIT_PMU_APB_XTLBUF1_WAIT_CNT(0x01) |
		BIT_PMU_APB_XTLBUF0_WAIT_CNT(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT1,
		BIT_PMU_APB_LTEPLL_WAIT_CNT(0x06) |
		BIT_PMU_APB_TWPLL_WAIT_CNT(0x06) |
		BIT_PMU_APB_DPLL0_WAIT_CNT(0x06) |
		BIT_PMU_APB_MPLL0_WAIT_CNT(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT2,
		BIT_PMU_APB_CPPLL_WAIT_CNT(0x06) |
		BIT_PMU_APB_RPLL_WAIT_CNT(0x06) |
		BIT_PMU_APB_GPLL_WAIT_CNT(0x06) |
		BIT_PMU_APB_LVDSDIS_PLL_WAIT_CNT(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT3,
		BIT_PMU_APB_ISPPLL_WAIT_CNT(0x06) |
		BIT_PMU_APB_DPLL1_WAIT_CNT(0x06) |
		BIT_PMU_APB_MPLL2_WAIT_CNT(0x06) |
		BIT_PMU_APB_MPLL1_WAIT_CNT(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WCN_SYS_CFG,
		//BIT_PMU_APB_PD_WCN_SYS_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_WCN_SYS_PD_SEL |
		BIT_PMU_APB_PD_WCN_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WCN_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WCN_SYS_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WCN_SYS_PWR_ON_SEQ_DLY(0x40) |
		BIT_PMU_APB_PD_WCN_SYS_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WIFI_WRAP_CFG,
		//BIT_PMU_APB_PD_WIFI_WRAP_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_WIFI_WRAP_PD_SEL |
		BIT_PMU_APB_PD_WIFI_WRAP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WIFI_WRAP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WIFI_WRAP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_WIFI_WRAP_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_WIFI_WRAP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GNSS_WRAP_CFG,
		//BIT_PMU_APB_PD_GNSS_WRAP_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_GNSS_WRAP_PD_SEL |
		BIT_PMU_APB_PD_GNSS_WRAP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_GNSS_WRAP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_GNSS_WRAP_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_GNSS_WRAP_PWR_ON_SEQ_DLY(0x41) |
		BIT_PMU_APB_PD_GNSS_WRAP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_CPU_MP8_CFG,
		//BIT_PMU_APB_PD_CPU_MP8_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_CPU_MP8_PD_SEL |
		//BIT_PMU_APB_PD_CPU_MP8_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_CPU_MP8_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_CPU_MP8_PWR_ON_DLY(0x10) |
		BIT_PMU_APB_PD_CPU_MP8_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_CPU_MP8_ISO_ON_DLY(0x07) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_DBG_SYS_CFG,
		//BIT_PMU_APB_PD_DBG_SYS_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_DBG_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_DBG_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_DBG_SYS_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_DBG_SYS_PWR_ON_SEQ_DLY(0x40) |
		BIT_PMU_APB_PD_DBG_SYS_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_CORE_CFG,
		//BIT_PMU_APB_PD_GPU_CORE_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_GPU_CORE_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_GPU_CORE_PWR_ON_DLY(0x20) |
		BIT_PMU_APB_PD_GPU_CORE_PWR_ON_SEQ_DLY(0x42) |
		BIT_PMU_APB_PD_GPU_CORE_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_CNT_WAIT_CFG0,
		BIT_PMU_APB_WCN_PWR_WAIT_CNT(0x0) |
		BIT_PMU_APB_PUBCP_PWR_WAIT_CNT(0x0) |
		BIT_PMU_APB_WTLCP_PWR_WAIT_CNT(0x0) |
		BIT_PMU_APB_AP_PWR_WAIT_CNT(0x0) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_CNT_WAIT_CFG1,
		BIT_PMU_APB_EFUSE_PWON_WAIT_CNT(0x0A) |		//default set
		BIT_PMU_APB_SLP_CTRL_CLK_DIV_CFG(0x7C) |
		BIT_PMU_APB_SP_PWR_WAIT_CNT(0x0) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_RC_CNT_WAIT_CFG,
		BIT_PMU_APB_RC1_WAIT_CNT(0x03) |
		BIT_PMU_APB_RC0_WAIT_CNT(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_ST_DEBUG_DLY0,
		BIT_PMU_APB_CGM_OFF_DLY(0x01) |
		BIT_PMU_APB_CGM_ON_DLY(0x01) |
		BIT_PMU_APB_ISO_OFF_DLY(0x01) |
		BIT_PMU_APB_RST_DEASSERT_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_ST_DEBUG_DLY1,
		BIT_PMU_APB_SHUTDOWN_M_D_DLY(0x08) |
		BIT_PMU_APB_PWR_ST_CLK_DIV_CFG(0x07) |
		BIT_PMU_APB_RST_ASSERT_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_ST_DEBUG_DLY3,
		BIT_PMU_APB_CORE_CGM_OFF_DLY(0x01) |
		BIT_PMU_APB_MP2_CGM_OFF_DLY(0x02) |
		BIT_PMU_APB_DCDC_PWR_OFF_DLY(0x0) |
		BIT_PMU_APB_DCDC_PWR_ON_DLY(0x82) |
		0
	);

	reg_val = CHIP_REG_GET(REG_PMU_APB_SLEEP_CTRL3) & 0xFF83FFFF;
	CHIP_REG_SET(REG_PMU_APB_SLEEP_CTRL3,
		reg_val |
		BIT_PMU_APB_GPU_PWR_HS_ACK_EN |
		BIT_PMU_APB_MM_VSP_PWR_HS_ACK_EN |
		BIT_PMU_APB_MM_PWR_HS_ACK_EN |
		BIT_PMU_APB_DISP_PWR_HS_ACK_EN |
		BIT_PMU_APB_AON_DMA_PWR_HS_ACK_EN |
		0
	);

	reg_val = CHIP_REG_GET(REG_PMU_APB_SYS_SOFT_RST_CTRL0) & 0xFFFFFFD7;
	CHIP_REG_SET(REG_PMU_APB_SYS_SOFT_RST_CTRL0, reg_val);
}

extern void tmr_udelay (unsigned long usec);

static int set_clk_mpll(uint32_t clk, uint32_t index)
{
	uint32_t reg1, reg2, reg3, reg4, clk_cfg1, clk_cfg2;
	uint32_t nint, kint;
	struct sprd_ibias_table *itable = mpll_ibias_table;
	uint32_t refin = REFIN;

	///pd mpll0
	CHIP_REG_AND(REG_PMU_APB_MPLL0_REL_CFG, ~BIT_PMU_APB_MPLL0_AP_SEL);

	switch (index) {
	case 0:
		reg1 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_CTRL0;
		reg2 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_CTRL1;
		reg3 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_CTRL2;
		reg4 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_CTRL3;
		break;

	case 1:
		reg1 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL1_CTRL0;
		reg2 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL1_CTRL1;
		reg3 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL1_CTRL2;
		reg4 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL1_CTRL3;
		break;

	case 2:
		reg1 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL2_CTRL0;
		reg2 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL2_CTRL1;
		reg3 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL2_CTRL2;
		reg4 = REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL2_CTRL3;
		break;

	default:
		return -1;
	}

	if (clk < 800000000) {
		CHIP_REG_OR(reg3, BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL2_POSTDIV);
		clk = clk * 2;
	}

	clk = clk/1000000;

	//clk_cfg1 = CHIP_REG_GET(reg1);
	clk_cfg1 = (BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_LPF(4) | BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_N(0x2E));
	clk_cfg1 |= BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_DIV_S | BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_SDM_EN;
	clk_cfg1 &= ~BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_MOD_EN;

	/* calc kint/nint */
	nint = BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_NINT(NINT(clk, refin));
	kint = BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_KINT(KINT(clk, refin));
	clk_cfg2 = CHIP_REG_GET(reg2);
	clk_cfg2 &= ~(BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_NINT(~0) |
		BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_KINT(~0));
	clk_cfg2 |= (nint | kint);

	clk_cfg1 &= ~BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_IBIAS(3);
	CHIP_REG_AND(reg4, ~BIT(22));
	if ((clk > 1600) && (clk < 1800))
		CHIP_REG_OR(reg4, BIT(22));
	else if ( clk >= 1800) {
		CHIP_REG_OR(reg4, BIT(22));
		clk_cfg1 |= BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL0_IBIAS(1);
	} else
		for (; itable->rate <= SPRD_PLL_MAX_RATE; itable++) {
			if (clk*1000000 <= itable->rate) {
				clk_cfg1 |= BIT_ANLG_PHY_G2_ANALOG_PLL_TOP_IPLL_IBIAS(itable->ibias);
				break;
			}
		}

	CHIP_REG_SET(reg1, clk_cfg1);
	CHIP_REG_SET(reg2, clk_cfg2);

  	CHIP_REG_OR(REG_PMU_APB_MPLL0_REL_CFG, BIT_PMU_APB_MPLL0_AP_SEL);
	tmr_udelay(200);

	return 0;
}

static uint32_t clk_mcu_config(uint32_t arm_clk)
{
	set_clk_mpll(arm_clk, 0);
	REG32(REG_APCPU_TOP_CLK_CORE_CGM_CORE0_CFG) |= BIT_APCPU_TOP_CLK_CORE_CGM_CORE0_CFG_CGM_CORE0_SEL(6);
	REG32(REG_APCPU_TOP_CLK_CORE_CGM_CORE1_CFG) |= BIT_APCPU_TOP_CLK_CORE_CGM_CORE1_CFG_CGM_CORE1_SEL(6);
	REG32(REG_APCPU_TOP_CLK_CORE_CGM_CORE2_CFG) |= BIT_APCPU_TOP_CLK_CORE_CGM_CORE2_CFG_CGM_CORE2_SEL(6);
	REG32(REG_APCPU_TOP_CLK_CORE_CGM_CORE3_CFG) |= BIT_APCPU_TOP_CLK_CORE_CGM_CORE3_CFG_CGM_CORE3_SEL(6);

	return 0;
}

/*sharkL3 deepsleep: 0.7V; normal: 0.9V*/
static void dcdc_core_ds_config(uint32_t core_cal_para, uint32_t core_ctrl_para)
{
	ANA_REG_SET(ANA_REG_GLB_DCDC_CORE_SLP_CTRL1,
			BITS_DCDC_CORE_CAL_DS_SW(core_cal_para)|
			BITS_DCDC_CORE_CTRL_DS_SW(core_ctrl_para)
	);
}

void CSP_Init(uint32_t gen_para)
{
	clk_mcu_config(1000000000);
	pmu_commom_config();
	dcdc_core_ds_config(0x0,0x3);
}
#endif

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


