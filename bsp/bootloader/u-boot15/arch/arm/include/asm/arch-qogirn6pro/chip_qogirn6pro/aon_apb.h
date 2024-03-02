/*
 * Copyright (C) 2018 Unigroup Spreadtrum & RDA Technologies Co., Ltd.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 ********************************************************************
 * Auto generated c code from ASIC Documentation, PLEASE DONOT EDIT *
 ********************************************************************
 */

/*
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0635_cq_goodcode_202010131505/reg/aon/aon_apb_rf.xls;AON_APB_REG
 *     Revision : 248562
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AON_APB_H____
#define __AON_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_APB_BASE
#define CTL_AON_APB_BASE                SCI_IOMAP(0x64900000)
#endif

#ifndef REG_AON_APB_BOND_OPT0
#define REG_AON_APB_BOND_OPT0		SCI_ADDR(0x64161000, (142*4))
#endif

/* registers definitions for CTL_AON_APB, 0x64900000 */
#define REG_AON_APB_APB_EB0                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0000)
#define REG_AON_APB_APB_EB1                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0004)
#define REG_AON_APB_APB_EB2                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0008)
#define REG_AON_APB_APB_RST0                                SCI_ADDR(CTL_AON_APB_BASE, 0x000C)
#define REG_AON_APB_APB_RST1                                SCI_ADDR(CTL_AON_APB_BASE, 0x0010)
#define REG_AON_APB_APB_RST2                                SCI_ADDR(CTL_AON_APB_BASE, 0x0014)
#define REG_AON_APB_APB_RTC_EB0                             SCI_ADDR(CTL_AON_APB_BASE, 0x0018)
#define REG_AON_APB_PWR_CTRL                                SCI_ADDR(CTL_AON_APB_BASE, 0x0024)
#define REG_AON_APB_TS_CFG                                  SCI_ADDR(CTL_AON_APB_BASE, 0x0028)
#define REG_AON_APB_BOOT_MODE                               SCI_ADDR(CTL_AON_APB_BASE, 0x002C)
#define REG_AON_APB_BB_BG_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0030)
#define REG_AON_APB_CP_ARM_JTAG_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0034)
#define REG_AON_APB_DCXO_LC_REG0                            SCI_ADDR(CTL_AON_APB_BASE, 0x003C)
#define REG_AON_APB_DCXO_LC_REG1                            SCI_ADDR(CTL_AON_APB_BASE, 0x0040)
#define REG_AON_APB_AUDCP_BOOT_PROT                         SCI_ADDR(CTL_AON_APB_BASE, 0x0078)
#define REG_AON_APB_AON_APB_CLK_SEL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0080)
#define REG_AON_APB_DAP_DJTAG_SEL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0084)
#define REG_AON_APB_USER_RSV_FLAG1                          SCI_ADDR(CTL_AON_APB_BASE, 0x0088)
#define REG_AON_APB_CH_SYS_SOFT_RST                         SCI_ADDR(CTL_AON_APB_BASE, 0x008C)
#define REG_AON_APB_SP_SYS_SOFT_RST                         SCI_ADDR(CTL_AON_APB_BASE, 0x0090)
#define REG_AON_APB_CLK_AON_APB_DFS_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x0094)
#define REG_AON_APB_MDAR_SYS_HSDL_CFG                       SCI_ADDR(CTL_AON_APB_BASE, 0x00C0)
#define REG_AON_APB_AUTO_GATE_CTRL0                         SCI_ADDR(CTL_AON_APB_BASE, 0x00D0)
#define REG_AON_APB_AUTO_GATE_CTRL1                         SCI_ADDR(CTL_AON_APB_BASE, 0x00D4)
#define REG_AON_APB_AP_AXI_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x00D8)
#define REG_AON_APB_PLATFORM_ID_L                           SCI_ADDR(CTL_AON_APB_BASE, 0x00E0)
#define REG_AON_APB_PLATFORM_ID_H                           SCI_ADDR(CTL_AON_APB_BASE, 0x00E4)
#define REG_AON_APB_PROJECT_ID_L                            SCI_ADDR(CTL_AON_APB_BASE, 0x00E8)
#define REG_AON_APB_PROJECT_ID_H                            SCI_ADDR(CTL_AON_APB_BASE, 0x00EC)
#define REG_AON_APB_DERIVED_ID                              SCI_ADDR(CTL_AON_APB_BASE, 0x00F0)
#define REG_AON_APB_MANUFACTURE_ID                          SCI_ADDR(CTL_AON_APB_BASE, 0x00F4)
#define REG_AON_APB_IMPLEMENTATION_ID                       SCI_ADDR(CTL_AON_APB_BASE, 0x00F8)
#define REG_AON_APB_CCIR_RCVR_CFG                           SCI_ADDR(CTL_AON_APB_BASE, 0x0100)
#define REG_AON_APB_PLL_BG_CFG                              SCI_ADDR(CTL_AON_APB_BASE, 0x0108)
#define REG_AON_APB_LVDSDIS_SEL                             SCI_ADDR(CTL_AON_APB_BASE, 0x010C)
#define REG_AON_APB_AUTO_GATE_CTRL3                         SCI_ADDR(CTL_AON_APB_BASE, 0x0118)
#define REG_AON_APB_APCPU_CTRL0                             SCI_ADDR(CTL_AON_APB_BASE, 0x011C)
#define REG_AON_APB_CGM_ESE                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0120)
#define REG_AON_APB_CH_CFG_BUS                              SCI_ADDR(CTL_AON_APB_BASE, 0x0124)
#define REG_AON_APB_SP_CFG_BUS                              SCI_ADDR(CTL_AON_APB_BASE, 0x0128)
#define REG_AON_APB_APB_RST3                                SCI_ADDR(CTL_AON_APB_BASE, 0x0130)
#define REG_AON_APB_RC100M_CFG                              SCI_ADDR(CTL_AON_APB_BASE, 0x0134)
#define REG_AON_APB_CGM_REG1                                SCI_ADDR(CTL_AON_APB_BASE, 0x0138)
#define REG_AON_APB_CGM_CLK_TOP_REG1                        SCI_ADDR(CTL_AON_APB_BASE, 0x013C)
#define REG_AON_APB_AUDCP_DSP_CTRL0                         SCI_ADDR(CTL_AON_APB_BASE, 0x0140)
#define REG_AON_APB_AUDCP_DSP_CTRL1                         SCI_ADDR(CTL_AON_APB_BASE, 0x0144)
#define REG_AON_APB_AUDCP_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x014C)
#define REG_AON_APB_CDMA2K_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x0160)
#define REG_AON_APB_PSCP_AON_EB                             SCI_ADDR(CTL_AON_APB_BASE, 0x0170)
#define REG_AON_APB_PSCP_SOFT_RST                           SCI_ADDR(CTL_AON_APB_BASE, 0x0174)
#define REG_AON_APB_PSCP_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0178)
#define REG_AON_APB_VECTOR_VDSP                             SCI_ADDR(CTL_AON_APB_BASE, 0x017C)
#define REG_AON_APB_AON_SOC_USB_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0190)
#define REG_AON_APB_ESE_INT_MASK                            SCI_ADDR(CTL_AON_APB_BASE, 0x0194)
#define REG_AON_APB_SOFT_RST_AON_ADD1                       SCI_ADDR(CTL_AON_APB_BASE, 0x01A0)
#define REG_AON_APB_VDSP_INT_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x01A4)
#define REG_AON_APB_ISE_SYS_CTRL                            SCI_ADDR(CTL_AON_APB_BASE, 0x01A8)
#define REG_AON_APB_EB_AON_ADD1                             SCI_ADDR(CTL_AON_APB_BASE, 0x01B0)
#define REG_AON_APB_DBG_DJTAG_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x01C0)
#define REG_AON_APB_PAD_DBG_BUS_DATA_A                      SCI_ADDR(CTL_AON_APB_BASE, 0x01F0)
#define REG_AON_APB_PAD_DBG_BUS_DATA_B                      SCI_ADDR(CTL_AON_APB_BASE, 0x01F4)
#define REG_AON_APB_PAD_DBG_BUS_DATA_OUT                    SCI_ADDR(CTL_AON_APB_BASE, 0x01F8)
#define REG_AON_APB_MBIST_EFUSE_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x01FC)
#define REG_AON_APB_OTG_PHY_TUNE                            SCI_ADDR(CTL_AON_APB_BASE, 0x0200)
#define REG_AON_APB_OTG_PHY_TEST                            SCI_ADDR(CTL_AON_APB_BASE, 0x0204)
#define REG_AON_APB_OTG_PHY_CTRL                            SCI_ADDR(CTL_AON_APB_BASE, 0x0208)
#define REG_AON_APB_OTG_CTRL0                               SCI_ADDR(CTL_AON_APB_BASE, 0x020C)
#define REG_AON_APB_OTG_CTRL1                               SCI_ADDR(CTL_AON_APB_BASE, 0x0210)
#define REG_AON_APB_USB_CLK_REF_SEL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0214)
#define REG_AON_APB_LVDSRF_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x0218)
#define REG_AON_APB_THM0_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x021C)
#define REG_AON_APB_THM1_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0220)
#define REG_AON_APB_THM2_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0224)
#define REG_AON_APB_THM3_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0228)
#define REG_AON_APB_OVERHEAT_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x022C)
#define REG_AON_APB_PSCP_SIM1_TOP_CTRL                      SCI_ADDR(CTL_AON_APB_BASE, 0x0230)
#define REG_AON_APB_PSCP_SIM2_TOP_CTRL                      SCI_ADDR(CTL_AON_APB_BASE, 0x0234)
#define REG_AON_APB_PSCP_SIM3_TOP_CTRL                      SCI_ADDR(CTL_AON_APB_BASE, 0x0238)
#define REG_AON_APB_AP_SIM_TOP_CTRL                         SCI_ADDR(CTL_AON_APB_BASE, 0x023C)
#define REG_AON_APB_AUX0_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0240)
#define REG_AON_APB_AUX1_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0244)
#define REG_AON_APB_AUX2_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0248)
#define REG_AON_APB_PROBE_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x024C)
#define REG_AON_APB_AON_MISC_CTRL_REG                       SCI_ADDR(CTL_AON_APB_BASE, 0x0250)
#define REG_AON_APB_UFS_REF_CLK_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0254)
#define REG_AON_APB_APCPU_MONITOR_STATUS                    SCI_ADDR(CTL_AON_APB_BASE, 0x0280)
#define REG_AON_APB_APCPU_CLUSTER_ATB_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x028C)
#define REG_AON_APB_APCPU_CLUSTER_APB_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0290)
#define REG_AON_APB_APCPU_CLUSTER_GIC_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0294)
#define REG_AON_APB_APCPU_GIC600_GIC_LPC_CTRL               SCI_ADDR(CTL_AON_APB_BASE, 0x0298)
#define REG_AON_APB_APCPU_DBG_BLK_LPC_CTRL                  SCI_ADDR(CTL_AON_APB_BASE, 0x029C)
#define REG_AON_APB_APCPU_TOP_MTX_LPC_CTRL                  SCI_ADDR(CTL_AON_APB_BASE, 0x0300)
#define REG_AON_APB_APCPU_TOP_MTX_LPC_PU_NUM_CTRL           SCI_ADDR(CTL_AON_APB_BASE, 0x0304)
#define REG_AON_APB_APCPU_MTX_LP_NUM_S0S1                   SCI_ADDR(CTL_AON_APB_BASE, 0x0308)
#define REG_AON_APB_APCPU_MTX_LP_NUM_S2S3                   SCI_ADDR(CTL_AON_APB_BASE, 0x030C)
#define REG_AON_APB_APCPU_MTX_LP_NUM_M1M2                   SCI_ADDR(CTL_AON_APB_BASE, 0x0310)
#define REG_AON_APB_APCPU_MTX_LP_NUM_M3M4                   SCI_ADDR(CTL_AON_APB_BASE, 0x0314)
#define REG_AON_APB_APCPU_AON_AB_LPC_CTRL                   SCI_ADDR(CTL_AON_APB_BASE, 0x0318)
#define REG_AON_APB_APCPU_CLUSTER_SCU_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0320)
#define REG_AON_APB_APCPU_DDR_AB_LPC_CTRL                   SCI_ADDR(CTL_AON_APB_BASE, 0x0324)
#define REG_AON_APB_APCPU_QOS_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0328)
#define REG_AON_APB_MPLL_LIT_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x032C)
#define REG_AON_APB_MPLL_MID_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0330)
#define REG_AON_APB_MPLL_BIG_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0334)
#define REG_AON_APB_MPLL_SCU_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0338)
#define REG_AON_APB_APCPU_URGENCY_CTRL                      SCI_ADDR(CTL_AON_APB_BASE, 0x033C)
#define REG_AON_APB_DPLL_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0340)
#define REG_AON_APB_PUB_CLK_GATING_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0344)
#define REG_AON_APB_MIPI_CSI_POWER_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0350)
#define REG_AON_APB_AON_MTX_MAIN_LPC_CTRL                   SCI_ADDR(CTL_AON_APB_BASE, 0x0368)
#define REG_AON_APB_AON_MTX_M0_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x036C)
#define REG_AON_APB_AON_MTX_M1_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0370)
#define REG_AON_APB_AON_MTX_M2_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0374)
#define REG_AON_APB_AON_MTX_M3_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0378)
#define REG_AON_APB_AON_MTX_M4_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x037C)
#define REG_AON_APB_AON_MTX_M5_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0380)
#define REG_AON_APB_AON_MTX_M6_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0384)
#define REG_AON_APB_AON_MTX_M7_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0388)
#define REG_AON_APB_AON_MTX_M8_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x038C)
#define REG_AON_APB_AON_MTX_M9_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0390)
#define REG_AON_APB_AON_MTX_M11_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x0398)
#define REG_AON_APB_AON_MTX_S0_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x039C)
#define REG_AON_APB_AON_MTX_S1_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03A0)
#define REG_AON_APB_AON_MTX_S2_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03A4)
#define REG_AON_APB_AON_MTX_S3_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03A8)
#define REG_AON_APB_AON_MTX_S4_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03AC)
#define REG_AON_APB_AON_MTX_S5_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03B0)
#define REG_AON_APB_AON_MTX_S6_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03B4)
#define REG_AON_APB_AON_MTX_S7_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03B8)
#define REG_AON_APB_AON_MTX_S8_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03BC)
#define REG_AON_APB_AON_MTX_S9_LPC_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x03C0)
#define REG_AON_APB_AON_MTX_S10_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03C4)
#define REG_AON_APB_AON_MTX_S11_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03C8)
#define REG_AON_APB_AON_MTX_S12_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03CC)
#define REG_AON_APB_AON_MTX_S13_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03D0)
#define REG_AON_APB_AON_MTX_S14_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03D4)
#define REG_AON_APB_AON_MTX_S15_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03D8)
#define REG_AON_APB_AON_MTX_S16_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03DC)
#define REG_AON_APB_AON_MTX_S17_LPC_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x03E0)
#define REG_AON_APB_AUDCP2EMC_ASYNC_BRG_LPC_CTRL            SCI_ADDR(CTL_AON_APB_BASE, 0x03E4)
#define REG_AON_APB_AI2EMC_ASYNC_BRG_LPC_CTRL               SCI_ADDR(CTL_AON_APB_BASE, 0x03E8)
#define REG_AON_APB_AP2EMC_ASYNC_BRG_LPC_CTRL               SCI_ADDR(CTL_AON_APB_BASE, 0x03EC)
#define REG_AON_APB_APCPU2EMC_ASYNC_BRG_LPC_CTRL            SCI_ADDR(CTL_AON_APB_BASE, 0x03F0)
#define REG_AON_APB_MMLL2EMC_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x03F4)
#define REG_AON_APB_DPU2EMC_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x03F8)
#define REG_AON_APB_DPU12EMC_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x03FC)
#define REG_AON_APB_GPU2EMC_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0400)
#define REG_AON_APB_IPA2EMC_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0404)
#define REG_AON_APB_ISE2EMC_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0408)
#define REG_AON_APB_MMHB2EMC_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x040C)
#define REG_AON_APB_PCIE2EMC_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x0410)
#define REG_AON_APB_PHYCP2EMC_ASYNC_BRG_LPC_CTRL            SCI_ADDR(CTL_AON_APB_BASE, 0x0414)
#define REG_AON_APB_PHYCP_ACC2EMC_ASYNC_BRG_LPC_CTRL        SCI_ADDR(CTL_AON_APB_BASE, 0x0418)
#define REG_AON_APB_PSCP2EMC_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x041C)
#define REG_AON_APB_PSCP_ACC2EMC_ASYNC_BRG_LPC_CTRL         SCI_ADDR(CTL_AON_APB_BASE, 0x0420)
#define REG_AON_APB_VPU2EMC_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0424)
#define REG_AON_APB_AON2EMC_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0428)
#define REG_AON_APB_AON2AP_ASYNC_BRG_LPC_CTRL               SCI_ADDR(CTL_AON_APB_BASE, 0x0430)
#define REG_AON_APB_AON2DPU_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0434)
#define REG_AON_APB_AON2IPA_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0438)
#define REG_AON_APB_AON2MM_ASYNC_BRG_LPC_CTRL               SCI_ADDR(CTL_AON_APB_BASE, 0x043C)
#define REG_AON_APB_AON2PCIE_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x0440)
#define REG_AON_APB_AON2AI_ASYNC_BRG_LPC_CTRL               SCI_ADDR(CTL_AON_APB_BASE, 0x0444)
#define REG_AON_APB_AON2AUD_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0448)
#define REG_AON_APB_AON2GPU_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x044C)
#define REG_AON_APB_AON2PUB_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x0450)
#define REG_AON_APB_IPA2PCIE_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x0454)
#define REG_AON_APB_IPA2PSCP_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x045C)
#define REG_AON_APB_PCIE2IPA_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x0460)
#define REG_AON_APB_PHYCP2IPA_ASYNC_BRG_LPC_CTRL            SCI_ADDR(CTL_AON_APB_BASE, 0x0464)
#define REG_AON_APB_PSCP2IPA_ASYNC_BRG_LPC_CTRL             SCI_ADDR(CTL_AON_APB_BASE, 0x0468)
#define REG_AON_APB_USB2AON_ASYNC_BRG_LPC_CTRL              SCI_ADDR(CTL_AON_APB_BASE, 0x046C)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL0                  SCI_ADDR(CTL_AON_APB_BASE, 0x0500)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL1                  SCI_ADDR(CTL_AON_APB_BASE, 0x0504)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL2                  SCI_ADDR(CTL_AON_APB_BASE, 0x0508)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL3                  SCI_ADDR(CTL_AON_APB_BASE, 0x050C)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL4                  SCI_ADDR(CTL_AON_APB_BASE, 0x0510)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL5                  SCI_ADDR(CTL_AON_APB_BASE, 0x0514)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL6                  SCI_ADDR(CTL_AON_APB_BASE, 0x0518)
#define REG_AON_APB_APCPU_INT_ENABLE_CTRL7                  SCI_ADDR(CTL_AON_APB_BASE, 0x051C)
#define REG_AON_APB_SDIO0_CTRL_REG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0520)
#define REG_AON_APB_SDIO1_CTRL_REG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0524)
#define REG_AON_APB_SDIO2_CTRL_REG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0528)
#define REG_AON_APB_EMMC_CTRL_REG                           SCI_ADDR(CTL_AON_APB_BASE, 0x052C)
#define REG_AON_APB_WDG_RST_FLAG                            SCI_ADDR(CTL_AON_APB_BASE, 0x0A24)
//#define REG_AON_APB_BOND_OPT0                               SCI_ADDR(CTL_AON_APB_BASE, 0x0A3C)
#define REG_AON_APB_DEVICE_LIFE_CYCLE                       SCI_ADDR(CTL_AON_APB_BASE, 0x0A40)
#define REG_AON_APB_RES_REG0                                SCI_ADDR(CTL_AON_APB_BASE, 0x0A44)
#define REG_AON_APB_RES_REG1                                SCI_ADDR(CTL_AON_APB_BASE, 0x0A48)
#define REG_AON_APB_ANA_INT_POL_SEL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0A4C)
#define REG_AON_APB_AON_MTX_PROT_CFG                        SCI_ADDR(CTL_AON_APB_BASE, 0x0A58)
#define REG_AON_APB_PLL_LOCK_OUT_SEL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0A64)
#define REG_AON_APB_LEAKAGE_MAGIC_WORD                      SCI_ADDR(CTL_AON_APB_BASE, 0x0B00)
#define REG_AON_APB_LEAKAGE_SWITCH                          SCI_ADDR(CTL_AON_APB_BASE, 0x0B04)
#define REG_AON_APB_FUNC_TEST_BOOT_ADDR                     SCI_ADDR(CTL_AON_APB_BASE, 0x0B10)
#define REG_AON_APB_CGM_RESCUE                              SCI_ADDR(CTL_AON_APB_BASE, 0x0B14)
#define REG_AON_APB_AON_SDIO                                SCI_ADDR(CTL_AON_APB_BASE, 0x0B2C)
#define REG_AON_APB_ANALOG_PD_STATUS0                       SCI_ADDR(CTL_AON_APB_BASE, 0x0B30)
#define REG_AON_APB_ANALOG_PD_STATUS1                       SCI_ADDR(CTL_AON_APB_BASE, 0x0B34)
#define REG_AON_APB_ANALOG_PD_STATUS2                       SCI_ADDR(CTL_AON_APB_BASE, 0x0B38)
#define REG_AON_APB_CH_WAKEUP_MASK_EN0                      SCI_ADDR(CTL_AON_APB_BASE, 0x0B80)
#define REG_AON_APB_CH_WAKEUP_MASK_EN1                      SCI_ADDR(CTL_AON_APB_BASE, 0x0B84)
#define REG_AON_APB_SP_WAKEUP_MASK_EN0                      SCI_ADDR(CTL_AON_APB_BASE, 0x0B88)
#define REG_AON_APB_SP_WAKEUP_MASK_EN1                      SCI_ADDR(CTL_AON_APB_BASE, 0x0B8C)
#define REG_AON_APB_SP_WAKEUP_MASK_EN2                      SCI_ADDR(CTL_AON_APB_BASE, 0x0B90)
#define REG_AON_APB_SDIO_EMMC_POWER_STATUS                  SCI_ADDR(CTL_AON_APB_BASE, 0x0B9C)
#define REG_AON_APB_SDIO_EMMC_POWER_STATUS_1                SCI_ADDR(CTL_AON_APB_BASE, 0x0BA0)
#define REG_AON_APB_SCC_DBG_BUS                             SCI_ADDR(CTL_AON_APB_BASE, 0x0C00)
#define REG_AON_APB_AON_FUNC_CTRL_0                         SCI_ADDR(CTL_AON_APB_BASE, 0x0C04)
#define REG_AON_APB_AON_FUNC_CTRL_1                         SCI_ADDR(CTL_AON_APB_BASE, 0x0C08)
#define REG_AON_APB_DP_HPD                                  SCI_ADDR(CTL_AON_APB_BASE, 0x0C0C)
#define REG_AON_APB_RFSPI_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0C10)
#define REG_AON_APB_UFSHC_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0C14)
#define REG_AON_APB_PHYCP_FUNC_CTRL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0C18)
#define REG_AON_APB_MIPI_DSI8_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0C30)
#define REG_AON_APB_RPLL_CTRL_REG0                          SCI_ADDR(CTL_AON_APB_BASE, 0x0C34)
#define REG_AON_APB_RPLL_CTRL_REG1                          SCI_ADDR(CTL_AON_APB_BASE, 0x0C38)
#define REG_AON_APB_RPLL_CTRL_REG2                          SCI_ADDR(CTL_AON_APB_BASE, 0x0C3C)
#define REG_AON_APB_RPLL_CTRL_REG3                          SCI_ADDR(CTL_AON_APB_BASE, 0x0C40)
#define REG_AON_APB_RPLL_CTRL_ARRAY_SEL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0C48)
#define REG_AON_APB_PSCP_CP_TW_CTRL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0C50)
#define REG_AON_APB_PSCP_BOOT_VECTOR                        SCI_ADDR(CTL_AON_APB_BASE, 0x0C54)
#define REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL0              SCI_ADDR(CTL_AON_APB_BASE, 0x0C60)
#define REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL1              SCI_ADDR(CTL_AON_APB_BASE, 0x0C64)
#define REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL2              SCI_ADDR(CTL_AON_APB_BASE, 0x0C68)
#define REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL3              SCI_ADDR(CTL_AON_APB_BASE, 0x0C6C)
#define REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN0              SCI_ADDR(CTL_AON_APB_BASE, 0x0C70)
#define REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN1              SCI_ADDR(CTL_AON_APB_BASE, 0x0C74)
#define REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN2              SCI_ADDR(CTL_AON_APB_BASE, 0x0C78)
#define REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN3              SCI_ADDR(CTL_AON_APB_BASE, 0x0C7C)
#define REG_AON_APB_GLB_BUS_CGM_GATE_AUTO_SEL               SCI_ADDR(CTL_AON_APB_BASE, 0x0C80)
#define REG_AON_APB_GLB_BUS_CGM_GATE_FORCE_EN               SCI_ADDR(CTL_AON_APB_BASE, 0x0C84)
#define REG_AON_APB_RC6M_CFG0                               SCI_ADDR(CTL_AON_APB_BASE, 0x0C88)
#define REG_AON_APB_RC6M_CFG1                               SCI_ADDR(CTL_AON_APB_BASE, 0x0C8C)
#define REG_AON_APB_RC60M_CFG0                              SCI_ADDR(CTL_AON_APB_BASE, 0x0C90)
#define REG_AON_APB_RC60M_CFG1                              SCI_ADDR(CTL_AON_APB_BASE, 0x0C94)
#define REG_AON_APB_DDCPLL_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x0C98)
#define REG_AON_APB_URGENCY_REG                             SCI_ADDR(CTL_AON_APB_BASE, 0x0C9C)
#define REG_AON_APB_AQOS_REG                                SCI_ADDR(CTL_AON_APB_BASE, 0x0CA0)
#define REG_AON_APB_RC150M_CFG0                             SCI_ADDR(CTL_AON_APB_BASE, 0x0CA4)
#define REG_AON_APB_RC100M_CFG1                             SCI_ADDR(CTL_AON_APB_BASE, 0x0CA8)
#define REG_AON_APB_PHY_CR8_REG                             SCI_ADDR(CTL_AON_APB_BASE, 0x0CB0)
#define REG_AON_APB_FORCE_DIVN_ON                           SCI_ADDR(CTL_AON_APB_BASE, 0x0CB4)
#define REG_AON_APB_PHY_CP_TW_REG                           SCI_ADDR(CTL_AON_APB_BASE, 0x0CC0)
#define REG_AON_APB_PHY_CP_ROBU_CLK_CTRL                    SCI_ADDR(CTL_AON_APB_BASE, 0x0CC4)
#define REG_AON_APB_PS_CP_ROBU_CLK_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0CC8)
#define REG_AON_APB_PHYCP_CGM_XO_EB                         SCI_ADDR(CTL_AON_APB_BASE, 0x0CD0)
#define REG_AON_APB_DDC_CTRL_EB                             SCI_ADDR(CTL_AON_APB_BASE, 0x0CD4)
#define REG_AON_APB_IPA_ACCESS_CFG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0CD8)
#define REG_AON_APB_AON_TMR_RST                             SCI_ADDR(CTL_AON_APB_BASE, 0x0CE0)
#define REG_AON_APB_RCO150M_TEST_FR_EN                      SCI_ADDR(CTL_AON_APB_BASE, 0x0CE4)
#define REG_AON_APB_UFSDEV_REG                              SCI_ADDR(CTL_AON_APB_BASE, 0x0CE8)
#define REG_AON_APB_RST_ASYNCB_REG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0CEC)
#define REG_AON_APB_BUSMON_EB_AON_MAIN_MTX                  SCI_ADDR(CTL_AON_APB_BASE, 0x0CF0)
#define REG_AON_APB_PSCP_CR8_LOW_POWER_DEBUG                SCI_ADDR(CTL_AON_APB_BASE, 0x0CF4)
#define REG_AON_APB_PHYCP_CR8_LOW_POWER_DEBUG               SCI_ADDR(CTL_AON_APB_BASE, 0x0CF8)
#define REG_AON_APB_USB31PLL_CTRL_MISC                      SCI_ADDR(CTL_AON_APB_BASE, 0x0CFC)
#define REG_AON_APB_RFFE_MUX_PHYCP_AON_0_REG                SCI_ADDR(CTL_AON_APB_BASE, 0x0D00)
#define REG_AON_APB_RFFE_MUX_PHYCP_AON_1_REG                SCI_ADDR(CTL_AON_APB_BASE, 0x0D04)
#define REG_AON_APB_PHYCP_DBG_FRC_ON                        SCI_ADDR(CTL_AON_APB_BASE, 0x0D08)
#define REG_AON_APB_LVDS_PHY_EN                             SCI_ADDR(CTL_AON_APB_BASE, 0x0D0C)
#define REG_AON_APB_USB31_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0D10)
#define REG_AON_APB_USB31DPCOMBPHY_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0D14)
#define REG_AON_APB_AUD_ADDX_SEL                            SCI_ADDR(CTL_AON_APB_BASE, 0x0D18)
#define REG_AON_APB_AXI_LP_CTRL_DISABLE                     SCI_ADDR(CTL_AON_APB_BASE, 0x0D1C)
#define REG_AON_APB_AUX3_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0D20)
#define REG_AON_APB_LCM_RSTN                                SCI_ADDR(CTL_AON_APB_BASE, 0x0D24)
#define REG_AON_APB_ACCESS_EN_REG                           SCI_ADDR(CTL_AON_APB_BASE, 0x0D28)
#define REG_AON_APB_ANLG_PHY_G12                            SCI_ADDR(CTL_AON_APB_BASE, 0x0D2C)
#define REG_AON_APB_CDMA_INT_REQ_ENABLE                     SCI_ADDR(CTL_AON_APB_BASE, 0x0D30)
#define REG_AON_APB_PSCP_SIM1_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0D34)
#define REG_AON_APB_BW_VOTE_CTRL                            SCI_ADDR(CTL_AON_APB_BASE, 0x0D38)
#define REG_AON_APB_PUB_CFG_EARLY_RESP_CTRL                 SCI_ADDR(CTL_AON_APB_BASE, 0x0D3C)
#define REG_AON_APB_RESERVE_H                               SCI_ADDR(CTL_AON_APB_BASE, 0x0FE8)
#define REG_AON_APB_RESERVE_L                               SCI_ADDR(CTL_AON_APB_BASE, 0x0FEC)

/* bits definitions for REG_AON_APB_APB_EB0, [0x64900000] */
#define BIT_AON_APB_DSI_CFG_EB                              ( BIT(31) )
#define BIT_AON_APB_CH_AHB_CLK_SOFT_EB                      ( BIT(30) )
#define BIT_AON_APB_AON_MATRIX_AXI_REGU_EB                  ( BIT(29) )
#define BIT_AON_APB_RTM_ATB_CLK_EB                          ( BIT(23) )
#define BIT_AON_APB_RTM_APB_CLK_EB                          ( BIT(22) )
#define BIT_AON_APB_DPU_VSP_EB                              ( BIT(21) )
#define BIT_AON_APB_SERDES_DPHY_REF_EB                      ( BIT(20) )
#define BIT_AON_APB_SERDES_DPHY_CFG_EB                      ( BIT(19) )
#define BIT_AON_APB_LVDIS_PLL_DIV_EN                        ( BIT(18) )
#define BIT_AON_APB_CSSYS_PUB_EB                            ( BIT(17) )
#define BIT_AON_APB_CSSYS_APB_EB                            ( BIT(16) )
#define BIT_AON_APB_CSSYS_EB                                ( BIT(15) )
#define BIT_AON_APB_APCPU_DAP_EB                            ( BIT(14) )
#define BIT_AON_APB_AI_EB                                   ( BIT(13) )
#define BIT_AON_APB_MSPI_EB                                 ( BIT(12) )
#define BIT_AON_APB_GPU_EB                                  ( BIT(11) )
#define BIT_AON_APB_SP_AHB_CLK_SOFT_EB                      ( BIT(10) )
#define BIT_AON_APB_MM_EB                                   ( BIT(9) )
#define BIT_AON_APB_PROBE_EB                                ( BIT(7) )
#define BIT_AON_APB_AUX2_EB                                 ( BIT(6) )
#define BIT_AON_APB_AUX1_EB                                 ( BIT(5) )
#define BIT_AON_APB_AUX0_EB                                 ( BIT(4) )
#define BIT_AON_APB_DJTAG_EB                                ( BIT(3) )
#define BIT_AON_APB_RFTI_EB                                 ( BIT(1) )
#define BIT_AON_APB_RC100M_CAL_EB                           ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_EB1, [0x64900004] */
#define BIT_AON_APB_BISR_EB                                 ( BIT(31) )
#define BIT_AON_APB_AUX3_EB                                 ( BIT(30) )
#define BIT_AON_APB_AON_SW_RFFE_EB                          ( BIT(29) )
#define BIT_AON_APB_APCPU_DVFS_TOP_EB                       ( BIT(28) )
#define BIT_AON_APB_RC150M_CAL_EB                           ( BIT(27) )
#define BIT_AON_APB_RC6M_CAL_EB                             ( BIT(26) )
#define BIT_AON_APB_RC60M_CAL_EB                            ( BIT(25) )
#define BIT_AON_APB_BB_SW_RFSPI_MST_EB                      ( BIT(24) )
#define BIT_AON_APB_AON_SERDES_CTRL2_EB                     ( BIT(23) )
#define BIT_AON_APB_AON_SERDES_CTRL1_EB                     ( BIT(22) )
#define BIT_AON_APB_CS_CC_EB                                ( BIT(21) )
#define BIT_AON_APB_AON_SCC_EB                              ( BIT(20) )
#define BIT_AON_APB_AON_IIS_MST_EB                          ( BIT(19) )
#define BIT_AON_APB_APB_BUSMON_EB                           ( BIT(18) )
#define BIT_AON_APB_APCPU_TS_EB                             ( BIT(17) )
#define BIT_AON_APB_ISE_APB_EB                              ( BIT(16) )
#define BIT_AON_APB_UFS_AO_EB                               ( BIT(15) )
#define BIT_AON_APB_APCPU_BUSMON_ENABLE                     ( BIT(14) )
#define BIT_AON_APB_AON_CLK_TOP_EB                          ( BIT(13) )
#define BIT_AON_APB_ANA_EB                                  ( BIT(12) )
#define BIT_AON_APB_PIN_REG_EB                              ( BIT(11) )
#define BIT_AON_APB_AON_SPINLOCK_EB                         ( BIT(10) )
#define BIT_AON_APB_OTG_PHY_EB                              ( BIT(9) )
#define BIT_AON_APB_AON_USB2_TOP_EB                         ( BIT(8) )
#define BIT_AON_APB_AON_DVFS_TOP_EB                         ( BIT(7) )
#define BIT_AON_APB_AON_TMR_EB                              ( BIT(6) )
#define BIT_AON_APB_AP_SYST_EB                              ( BIT(5) )
#define BIT_AON_APB_AON_SYST_EB                             ( BIT(4) )
#define BIT_AON_APB_AON_KPD_EB                              ( BIT(3) )
#define BIT_AON_APB_AON_MBOX_EB                             ( BIT(2) )
#define BIT_AON_APB_AON_GPIO_EB                             ( BIT(1) )
#define BIT_AON_APB_AON_EFUSE_EB                            ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_EB2, [0x64900008] */
#define BIT_AON_APB_AON_SERDES_CTRL0_EB                     ( BIT(31) )
#define BIT_AON_APB_APCPU_WDG_EB                            ( BIT(30) )
#define BIT_AON_APB_AP_WDG_EB                               ( BIT(29) )
#define BIT_AON_APB_AON_PWM3_EB                             ( BIT(28) )
#define BIT_AON_APB_AON_PWM2_EB                             ( BIT(27) )
#define BIT_AON_APB_AON_PWM1_EB                             ( BIT(26) )
#define BIT_AON_APB_AON_PWM0_EB                             ( BIT(25) )
#define BIT_AON_APB_AP_TMR2_EB                              ( BIT(24) )
#define BIT_AON_APB_AP_TMR1_EB                              ( BIT(23) )
#define BIT_AON_APB_AP_TMR0_EB                              ( BIT(22) )
#define BIT_AON_APB_LP_ISE_INTC_EB                          ( BIT(21) )
#define BIT_AON_APB_LP_PHYCP_INTC_EB                        ( BIT(20) )
#define BIT_AON_APB_LP_PSCP_INTC_EB                         ( BIT(19) )
#define BIT_AON_APB_LP_AP_INTC7_EB                          ( BIT(18) )
#define BIT_AON_APB_LP_AP_INTC6_EB                          ( BIT(17) )
#define BIT_AON_APB_LP_AP_INTC5_EB                          ( BIT(16) )
#define BIT_AON_APB_LP_AP_INTC4_EB                          ( BIT(15) )
#define BIT_AON_APB_LP_AP_INTC3_EB                          ( BIT(14) )
#define BIT_AON_APB_LP_AP_INTC2_EB                          ( BIT(13) )
#define BIT_AON_APB_LP_AP_INTC1_EB                          ( BIT(12) )
#define BIT_AON_APB_LP_AP_INTC0_EB                          ( BIT(11) )
#define BIT_AON_APB_AON_EIC_EB                              ( BIT(10) )
#define BIT_AON_APB_AON_ADI_EB                              ( BIT(9) )
#define BIT_AON_APB_PMU_TOP_EB                              ( BIT(8) )
#define BIT_AON_APB_LP_AUDCP_INTC_EB                        ( BIT(7) )
#define BIT_AON_APB_PSCP_SIM2_AON_TOP_EB                    ( BIT(6) )
#define BIT_AON_APB_PSCP_SIM1_AON_TOP_EB                    ( BIT(5) )
#define BIT_AON_APB_PSCP_SIM0_AON_TOP_EB                    ( BIT(4) )
#define BIT_AON_APB_AON_THM3_EB                             ( BIT(3) )
#define BIT_AON_APB_AON_THM2_EB                             ( BIT(2) )
#define BIT_AON_APB_AON_THM1_EB                             ( BIT(1) )
#define BIT_AON_APB_AON_THM0_EB                             ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST0, [0x6490000C] */
#define BIT_AON_APB_LVDS_PHY_SOFT_RST                       ( BIT(15) )
#define BIT_AON_APB_AON_SW_RFFE_SOFT_RST                    ( BIT(14) )
#define BIT_AON_APB_RC6M_CAL_SOFT_RST                       ( BIT(13) )
#define BIT_AON_APB_RC60M_CAL_SOFT_RST                      ( BIT(12) )
#define BIT_AON_APB_RC150M_CAL_SOFT_RST                     ( BIT(11) )
#define BIT_AON_APB_BB_SW_RFSPI_MST_SOFT_RST                ( BIT(10) )
#define BIT_AON_APB_SERDES_DPHY_APB_SOFT_RST                ( BIT(9) )
#define BIT_AON_APB_SERDES_DPHY_SOFT_RST                    ( BIT(8) )
#define BIT_AON_APB_LVDSDIS_SOFT_RST                        ( BIT(7) )
#define BIT_AON_APB_DAP_MTX_SOFT_RST                        ( BIT(6) )
#define BIT_AON_APB_MSPI1_SOFT_RST                          ( BIT(5) )
#define BIT_AON_APB_MSPI0_SOFT_RST                          ( BIT(4) )
#define BIT_AON_APB_BB_CAL_SOFT_RST                         ( BIT(3) )
#define BIT_AON_APB_DCXO_LC_SOFT_RST                        ( BIT(2) )
#define BIT_AON_APB_RFTI_SOFT_RST                           ( BIT(1) )
#define BIT_AON_APB_RC100M_CAL_SOFT_RST                     ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST1, [0x64900010] */
#define BIT_AON_APB_THM3_OVERHEAT_SOFT_RST                  ( BIT(26) )
#define BIT_AON_APB_THM2_OVERHEAT_SOFT_RST                  ( BIT(25) )
#define BIT_AON_APB_THM1_OVERHEAT_SOFT_RST                  ( BIT(24) )
#define BIT_AON_APB_THM0_OVERHEAT_SOFT_RST                  ( BIT(23) )
#define BIT_AON_APB_SERDES0_SOFT_RST                        ( BIT(22) )
#define BIT_AON_APB_SERDES1_SOFT_RST                        ( BIT(21) )
#define BIT_AON_APB_SCC_SOFT_RST                            ( BIT(20) )
#define BIT_AON_APB_AON_IIS_SOFT_RST                        ( BIT(19) )
#define BIT_AON_APB_DEBUG_FILTER_SOFT_RST                   ( BIT(18) )
#define BIT_AON_APB_APCPU_TS0_SOFT_RST                      ( BIT(17) )
#define BIT_AON_APB_UFS_AO_SOFT_RST                         ( BIT(15) )
#define BIT_AON_APB_CKG_SOFT_RST                            ( BIT(13) )
#define BIT_AON_APB_ANA_SOFT_RST                            ( BIT(12) )
#define BIT_AON_APB_PIN_SOFT_RST                            ( BIT(11) )
#define BIT_AON_APB_SPLK_SOFT_RST                           ( BIT(10) )
#define BIT_AON_APB_OTG_PHY_SOFT_RST                        ( BIT(9) )
#define BIT_AON_APB_OTG_UTMI_SOFT_RST                       ( BIT(8) )
#define BIT_AON_APB_DVFS_TOP_SOFT_RST                       ( BIT(7) )
#define BIT_AON_APB_AP_SYST_SOFT_RST                        ( BIT(5) )
#define BIT_AON_APB_AON_SYST_SOFT_RST                       ( BIT(4) )
#define BIT_AON_APB_KPD_SOFT_RST                            ( BIT(3) )
#define BIT_AON_APB_MBOX_SOFT_RST                           ( BIT(2) )
#define BIT_AON_APB_GPIO_SOFT_RST                           ( BIT(1) )
#define BIT_AON_APB_EFUSE_SOFT_RST                          ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST2, [0x64900014] */
#define BIT_AON_APB_APCPU_WDG_SOFT_RST                      ( BIT(30) )
#define BIT_AON_APB_AP_WDG_SOFT_RST                         ( BIT(29) )
#define BIT_AON_APB_PWM3_SOFT_RST                           ( BIT(28) )
#define BIT_AON_APB_PWM2_SOFT_RST                           ( BIT(27) )
#define BIT_AON_APB_PWM1_SOFT_RST                           ( BIT(26) )
#define BIT_AON_APB_PWM0_SOFT_RST                           ( BIT(25) )
#define BIT_AON_APB_LP_ISE_INTC_SOFT_RST                    ( BIT(21) )
#define BIT_AON_APB_LP_PHYCP_INTC_SOFT_RST                  ( BIT(20) )
#define BIT_AON_APB_LP_PSCP_INTC_SOFT_RST                   ( BIT(19) )
#define BIT_AON_APB_LP_AP_INTC7_SOFT_RST                    ( BIT(18) )
#define BIT_AON_APB_LP_AP_INTC6_SOFT_RST                    ( BIT(17) )
#define BIT_AON_APB_LP_AP_INTC5_SOFT_RST                    ( BIT(16) )
#define BIT_AON_APB_LP_AP_INTC4_SOFT_RST                    ( BIT(15) )
#define BIT_AON_APB_LP_AP_INTC3_SOFT_RST                    ( BIT(14) )
#define BIT_AON_APB_LP_AP_INTC2_SOFT_RST                    ( BIT(13) )
#define BIT_AON_APB_LP_AP_INTC1_SOFT_RST                    ( BIT(12) )
#define BIT_AON_APB_LP_AP_INTC0_SOFT_RST                    ( BIT(11) )
#define BIT_AON_APB_EIC_SOFT_RST                            ( BIT(10) )
#define BIT_AON_APB_ADI_SOFT_RST                            ( BIT(9) )
#define BIT_AON_APB_PMU_SOFT_RST                            ( BIT(8) )
#define BIT_AON_APB_LP_AUDCP_INTC_SOFT_RST                  ( BIT(7) )
#define BIT_AON_APB_PSCP_SIM2_AON_TOP_SOFT_RST              ( BIT(6) )
#define BIT_AON_APB_PSCP_SIM1_AON_TOP_SOFT_RST              ( BIT(5) )
#define BIT_AON_APB_PSCP_SIM0_AON_TOP_SOFT_RST              ( BIT(4) )
#define BIT_AON_APB_THM3_SOFT_RST                           ( BIT(3) )
#define BIT_AON_APB_THM2_SOFT_RST                           ( BIT(2) )
#define BIT_AON_APB_THM1_SOFT_RST                           ( BIT(1) )
#define BIT_AON_APB_THM0_SOFT_RST                           ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RTC_EB0, [0x64900018] */
#define BIT_AON_APB_BB_CAL_RTC_EB                           ( BIT(13) )
#define BIT_AON_APB_DCXO_LC_RTC_EB                          ( BIT(12) )
#define BIT_AON_APB_AP_TMR2_RTC_EB                          ( BIT(11) )
#define BIT_AON_APB_AP_TMR1_RTC_EB                          ( BIT(10) )
#define BIT_AON_APB_AP_TMR0_RTC_EB                          ( BIT(9) )
#define BIT_AON_APB_APCPU_WDG_RTC_EB                        ( BIT(8) )
#define BIT_AON_APB_AP_WDG_RTC_EB                           ( BIT(7) )
#define BIT_AON_APB_EIC_RTCDV5_EB                           ( BIT(6) )
#define BIT_AON_APB_EIC_RTC_EB                              ( BIT(5) )
#define BIT_AON_APB_AON_TMR_RTC_EB                          ( BIT(4) )
#define BIT_AON_APB_AP_SYST_RTC_EB                          ( BIT(3) )
#define BIT_AON_APB_AON_SYST_RTC_EB                         ( BIT(2) )
#define BIT_AON_APB_KPD_RTC_EB                              ( BIT(1) )
#define BIT_AON_APB_ARCH_RTC_EB                             ( BIT(0) )

/* bits definitions for REG_AON_APB_PWR_CTRL, [0x64900024] */
#define BIT_AON_APB_EFUSE_PWON_RD_END_FLAG                  ( BIT(2) )

/* bits definitions for REG_AON_APB_TS_CFG, [0x64900028] */
#define BIT_AON_APB_DBG_TRACE_CTRL_EN                       ( BIT(16) )
#define BIT_AON_APB_EVENTACK_RESTARTREQ_TS01                ( BIT(4) )
#define BIT_AON_APB_EVENT_RESTARTREQ_TS01                   ( BIT(1) )
#define BIT_AON_APB_EVENT_HALTREQ_TS01                      ( BIT(0) )

/* bits definitions for REG_AON_APB_BOOT_MODE, [0x6490002C] */
#define BIT_AON_APB_USB_SW                                  ( BIT(10) )
#define BIT_AON_APB_USB_INSERT                              ( BIT(9) )
#define BIT_AON_APB_PTEST_FUNC_ATSPEED_SEL                  ( BIT(8) )
#define BIT_AON_APB_PTEST_FUNC_MODE                         ( BIT(7) )
#define BIT_AON_APB_FUNCTST_DMA_EB                          ( BIT(6) )
#define BIT_AON_APB_PTEST_BIST_MODE                         ( BIT(5) )
#define BIT_AON_APB_USB_DLOAD_EN                            ( BIT(4) )
#define BIT_AON_APB_ARM_BOOT_MD3                            ( BIT(3) )
#define BIT_AON_APB_ARM_BOOT_MD2                            ( BIT(2) )
#define BIT_AON_APB_ARM_BOOT_MD1                            ( BIT(1) )
#define BIT_AON_APB_ARM_BOOT_MD0                            ( BIT(0) )

/* bits definitions for REG_AON_APB_BB_BG_CTRL, [0x64900030] */
#define BIT_AON_APB_BB_BG_AUTO_PD_EN                        ( BIT(3) )
#define BIT_AON_APB_BB_BG_SLP_PD_EN                         ( BIT(2) )
#define BIT_AON_APB_BB_BG_FORCE_ON                          ( BIT(1) )
#define BIT_AON_APB_BB_BG_FORCE_PD                          ( BIT(0) )

/* bits definitions for REG_AON_APB_CP_ARM_JTAG_CTRL, [0x64900034] */
#define BIT_AON_APB_AGCP_DSP_JTAG_MODE                      ( BIT(3) )
#define BIT_AON_APB_CP_ARM_JTAG_PIN_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_DCXO_LC_REG0, [0x6490003C] */
#define BIT_AON_APB_DCXO_LC_FLAG                            ( BIT(8) )
#define BIT_AON_APB_DCXO_LC_FLAG_CLR                        ( BIT(1) )
#define BIT_AON_APB_DCXO_LC_CNT_CLR                         ( BIT(0) )

/* bits definitions for REG_AON_APB_DCXO_LC_REG1, [0x64900040] */
#define BIT_AON_APB_DCXO_LC_CNT(x)                          ( (x) )

/* bits definitions for REG_AON_APB_AUDCP_BOOT_PROT, [0x64900078] */
#define BIT_AON_APB_AUDCP_BOOTCTRL_PROT                     ( BIT(31) )
#define BIT_AON_APB_AUDCP_REG_PROT_VAL(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_AON_APB_CLK_SEL, [0x64900080] */
#define BIT_AON_APB_CGM_AON_APB_LP_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_DAP_DJTAG_SEL, [0x64900084] */
#define BIT_AON_APB_DAP_DBGPWRUP_SOFT_EN                    ( BIT(2) )
#define BIT_AON_APB_DAP_SYSPWRUP_SOFT_EN                    ( BIT(1) )
#define BIT_AON_APB_DAP_DJTAG_EN                            ( BIT(0) )

/* bits definitions for REG_AON_APB_USER_RSV_FLAG1, [0x64900088] */
#define BIT_AON_APB_USER_RSV_FLAG1_B1                       ( BIT(1) )
#define BIT_AON_APB_USER_RSV_FLAG1_B0                       ( BIT(0) )

/* bits definitions for REG_AON_APB_CH_SYS_SOFT_RST, [0x6490008C] */
#define BIT_AON_APB_CH_SYS_SOFT_RST                         ( BIT(4) )
#define BIT_AON_APB_CH_CORE_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_SYS_SOFT_RST, [0x64900090] */
#define BIT_AON_APB_SP_SYS_SOFT_RST                         ( BIT(4) )
#define BIT_AON_APB_SP_CORE_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_AON_APB_CLK_AON_APB_DFS_CTRL, [0x64900094] */
#define BIT_AON_APB_AON_APB_MASTER_BUSY(x)                  ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_APB_AON_APB_FREQ_CTRL_EN                    ( BIT(4) )
#define BIT_AON_APB_AON_APB_IDLE_EN                         ( BIT(3) )
#define BIT_AON_APB_CGM_AON_APB_DFS_OVERRIDE(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_MDAR_SYS_HSDL_CFG, [0x649000C0] */
#define BIT_AON_APB_MDAR_SYS_HSDL_CFG(x)                    ( (x) )

/* bits definitions for REG_AON_APB_AUTO_GATE_CTRL0, [0x649000D0] */
#define BIT_AON_APB_CGM_AP_MM_FORCE_EN                      ( BIT(30) )
#define BIT_AON_APB_CGM_AP_MM_AUTO_GATE_SEL                 ( BIT(29) )
#define BIT_AON_APB_CGM_EMC_FORCE_EN                        ( BIT(28) )
#define BIT_AON_APB_CGM_EMC_AUTO_GATE_SEL                   ( BIT(27) )
#define BIT_AON_APB_CGM_MM_ISP_RAW_FORCE_EN                 ( BIT(26) )
#define BIT_AON_APB_CGM_MM_ISP_RAW_AUTO_GATE_SEL            ( BIT(25) )
#define BIT_AON_APB_CGM_MM_ISP_YUV_FORCE_EN                 ( BIT(24) )
#define BIT_AON_APB_CGM_MM_ISP_YUV_AUTO_GATE_SEL            ( BIT(23) )
#define BIT_AON_APB_CGM_AON_APB_PUB_FORCE_EN                ( BIT(22) )
#define BIT_AON_APB_CGM_AON_APB_PUB_AUTO_GATE_SEL           ( BIT(21) )
#define BIT_AON_APB_CGM_AON_APB_AUDCP_FORCE_EN              ( BIT(20) )
#define BIT_AON_APB_CGM_AON_APB_AUDCP_AUTO_GATE_SEL         ( BIT(19) )
#define BIT_AON_APB_CGM_AON_APB_PSCP_FORCE_EN               ( BIT(18) )
#define BIT_AON_APB_CGM_AON_APB_PSCP_AUTO_GATE_SEL          ( BIT(17) )
#define BIT_AON_APB_CGM_AON_APB_PHYCP_FORCE_EN              ( BIT(16) )
#define BIT_AON_APB_CGM_AON_APB_PHYCP_AUTO_GATE_SEL         ( BIT(15) )
#define BIT_AON_APB_CGM_AON_APB_AP_FORCE_EN                 ( BIT(14) )
#define BIT_AON_APB_CGM_AON_APB_AP_AUTO_GATE_SEL            ( BIT(13) )
#define BIT_AON_APB_CGM_AP_AXI_FORCE_EN                     ( BIT(12) )
#define BIT_AON_APB_CGM_AP_AXI_AUTO_GATE_SEL                ( BIT(11) )
#define BIT_AON_APB_CGM_ESE_SYS_FORCE_EN                    ( BIT(10) )
#define BIT_AON_APB_CGM_ESE_SYS_AUTO_GATE_SEL               ( BIT(9) )
#define BIT_AON_APB_CGM_AP_GPU_FORCE_EN                     ( BIT(8) )
#define BIT_AON_APB_CGM_AP_GPU_AUTO_GATE_SEL                ( BIT(7) )
#define BIT_AON_APB_CGM_AP_AI_FORCE_EN                      ( BIT(6) )
#define BIT_AON_APB_CGM_AP_AI_AUTO_GATE_SEL                 ( BIT(5) )
#define BIT_AON_APB_CGM_GPU_MEM_FORCE_EN                    ( BIT(4) )
#define BIT_AON_APB_CGM_GPU_MEM_AUTO_GATE_SEL               ( BIT(3) )
#define BIT_AON_APB_CGM_APCPU_PMU_AUTO_GATE_SEL             ( BIT(2) )
#define BIT_AON_APB_CGM_APCPU_PMU_FORCE_EN                  ( BIT(1) )
#define BIT_AON_APB_MBOX_AUTO_GATE_SEL                      ( BIT(0) )

/* bits definitions for REG_AON_APB_AUTO_GATE_CTRL1, [0x649000D4] */
#define BIT_AON_APB_CGM_DMC_REF_AUTO_GATE_SEL               ( BIT(4) )
#define BIT_AON_APB_CGM_TOP_DVFS_ROOT_AUTO_GATE_SEL         ( BIT(3) )
#define BIT_AON_APB_CGM_TOP_DVFS_ROOT_FORCE_EN              ( BIT(2) )
#define BIT_AON_APB_CGM_AON_APB_ESE_AUTO_GATE_SEL           ( BIT(1) )
#define BIT_AON_APB_CGM_AON_APB_ESE_FORCE_EN                ( BIT(0) )

/* bits definitions for REG_AON_APB_AP_AXI_CTRL, [0x649000D8] */
#define BIT_AON_APB_CGM_AP_AXI_AUTO_FREQ_DOWN_CTRL_SEL      ( BIT(3) )
#define BIT_AON_APB_CGM_AP_AXI_AUTO_FREQ_DOWN_EN            ( BIT(2) )
#define BIT_AON_APB_CGM_AP_AXI_SEL_IDLE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_PLATFORM_ID_L, [0x649000E0] */
#define BIT_AON_APB_PLATFORM_ID_L(x)                        ( (x) )

/* bits definitions for REG_AON_APB_PLATFORM_ID_H, [0x649000E4] */
#define BIT_AON_APB_PLATFORM_ID_H(x)                        ( (x) )

/* bits definitions for REG_AON_APB_PROJECT_ID_L, [0x649000E8] */
#define BIT_AON_APB_PROJECT_ID_L(x)                         ( (x) )

/* bits definitions for REG_AON_APB_PROJECT_ID_H, [0x649000EC] */
#define BIT_AON_APB_PROJECT_ID_H(x)                         ( (x) )

/* bits definitions for REG_AON_APB_DERIVED_ID, [0x649000F0] */
#define BIT_AON_APB_FULL_LAYER_ID(x)                        ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_METAL_FIX_ID(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_APB_MANUFACTURE_ID, [0x649000F4] */
#define BIT_AON_APB_PROCESS_ID(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_FOUNDRY_ID(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_IMPLEMENTATION_ID, [0x649000F8] */
#define BIT_AON_APB_MEM_COMPILER(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_STD_CELL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_CCIR_RCVR_CFG, [0x64900100] */
#define BIT_AON_APB_ANALOG_PLL_RSV(x)                       ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_ANALOG_TESTMUX(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_PLL_BG_CFG, [0x64900108] */
#define BIT_AON_APB_PLL_BG_RSV(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_LVDSDIS_SEL, [0x6490010C] */
#define BIT_AON_APB_LVDSDIS_LOG_SEL(x)                      ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_AON_APB_LVDSDIS_DBG_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_APB_AUTO_GATE_CTRL3, [0x64900118] */
#define BIT_AON_APB_CGM_PERIPH_AUTO_GATE_EN                 ( BIT(13) )
#define BIT_AON_APB_CGM_GIC_AUTO_GATE_EN                    ( BIT(12) )
#define BIT_AON_APB_CGM_ACP_AUTO_GATE_EN                    ( BIT(11) )
#define BIT_AON_APB_CGM_AXI_PERIPH_AUTO_GATE_EN             ( BIT(10) )
#define BIT_AON_APB_CGM_ACE_AUTO_GATE_EN                    ( BIT(9) )
#define BIT_AON_APB_CGM_SCU_AUTO_GATE_EN                    ( BIT(8) )
#define BIT_AON_APB_CGM_CORE7_AUTO_GATE_EN                  ( BIT(7) )
#define BIT_AON_APB_CGM_CORE6_AUTO_GATE_EN                  ( BIT(6) )
#define BIT_AON_APB_CGM_CORE5_AUTO_GATE_EN                  ( BIT(5) )
#define BIT_AON_APB_CGM_CORE4_AUTO_GATE_EN                  ( BIT(4) )
#define BIT_AON_APB_CGM_CORE3_AUTO_GATE_EN                  ( BIT(3) )
#define BIT_AON_APB_CGM_CORE2_AUTO_GATE_EN                  ( BIT(2) )
#define BIT_AON_APB_CGM_CORE1_AUTO_GATE_EN                  ( BIT(1) )
#define BIT_AON_APB_CGM_CORE0_AUTO_GATE_EN                  ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_CTRL0, [0x6490011C] */
#define BIT_AON_APB_APCPU_PERIPH_CO_SCLK                    ( BIT(3) )
#define BIT_AON_APB_APCPU_DEEP_CO_QACTIVE                   ( BIT(2) )
#define BIT_AON_APB_APCPU_CORE_WAKEUP_ACE_CLK_EN            ( BIT(1) )
#define BIT_AON_APB_APCPU_CORE_WAKEUP_SCU_CLK_EN            ( BIT(0) )

/* bits definitions for REG_AON_APB_CGM_ESE, [0x64900120] */
#define BIT_AON_APB_REG_ESE_AUTO_SWITCH_RCO_BYPASS          ( BIT(2) )
#define BIT_AON_APB_CGM_ESE_SOURCE_SEL(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_CH_CFG_BUS, [0x64900124] */
#define BIT_AON_APB_MMTX_SLEEP_CH_PUB_WR                    ( BIT(3) )
#define BIT_AON_APB_MMTX_SLEEP_CH_PUB_RD                    ( BIT(2) )
#define BIT_AON_APB_INT_REQ_CH_CORE_SOFT                    ( BIT(1) )
#define BIT_AON_APB_CH_CFG_BUS_SLEEP                        ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_CFG_BUS, [0x64900128] */
#define BIT_AON_APB_INT_REQ_SP_CORE_SOFT                    ( BIT(1) )
#define BIT_AON_APB_SP_CFG_BUS_SLEEP                        ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST3, [0x64900130] */
#define BIT_AON_APB_MPHY_RSV1_SOFT_RST                      ( BIT(19) )
#define BIT_AON_APB_MPHY_RSV0_SOFT_RST                      ( BIT(18) )
#define BIT_AON_APB_MPHY_PHY_RESET_SOFT_RST                 ( BIT(17) )
#define BIT_AON_APB_DJTAG_UFSPHY_SOFT_RST                   ( BIT(16) )
#define BIT_AON_APB_DJTAG_SOFT_RST                          ( BIT(15) )
#define BIT_AON_APB_DJTAG_CDMA_SOFT_RST                     ( BIT(14) )
#define BIT_AON_APB_DJTAG_ISE_SOFT_RST                      ( BIT(13) )
#define BIT_AON_APB_DJTAG_DPU_SOFT_RST                      ( BIT(12) )
#define BIT_AON_APB_DJTAG_MM_SOFT_RST                       ( BIT(11) )
#define BIT_AON_APB_DJTAG_AI_SOFT_RST                       ( BIT(10) )
#define BIT_AON_APB_DJTAG_G3PHY_SOFT_RST                    ( BIT(9) )
#define BIT_AON_APB_DJTAG_IPA_SOFT_RST                      ( BIT(8) )
#define BIT_AON_APB_DJTAG_AON_SOFT_RST                      ( BIT(7) )
#define BIT_AON_APB_DJTAG_PUB0_SOFT_RST                     ( BIT(6) )
#define BIT_AON_APB_DJTAG_AUDCP_SOFT_RST                    ( BIT(5) )
#define BIT_AON_APB_DJTAG_GPU_SOFT_RST                      ( BIT(4) )
#define BIT_AON_APB_DJTAG_PHYCP_SOFT_RST                    ( BIT(3) )
#define BIT_AON_APB_DJTAG_PSCP_SOFT_RST                     ( BIT(2) )
#define BIT_AON_APB_DJTAG_APCPU_SOFT_RST                    ( BIT(1) )
#define BIT_AON_APB_DJTAG_AP_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_AON_APB_RC100M_CFG, [0x64900134] */
#define BIT_AON_APB_CAL100M_MODE_SEL                        ( BIT(30) )
#define BIT_AON_APB_RTC100M_CAL_CTL(x)                      ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_RTC100M_CAL_SEL                         ( BIT(21) )
#define BIT_AON_APB_RTC100M_CAL_PRECISION(x)                ( (x) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AON_APB_RC100M_DIV(x)                           ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AON_APB_RC100M_CAL_DONE                         ( BIT(6) )
#define BIT_AON_APB_RC100M_CAL_START                        ( BIT(5) )
#define BIT_AON_APB_RC100M_ANA_SOFT_RST                     ( BIT(4) )
#define BIT_AON_APB_RF100M_CLK_DISABLE_TIME(x)              ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_RC100M_FORCE_EN                         ( BIT(1) )
#define BIT_AON_APB_RC100M_AUTO_GATE_EN                     ( BIT(0) )

/* bits definitions for REG_AON_APB_CGM_REG1, [0x64900138] */
#define BIT_AON_APB_LTE_PCCSCC_RFTI_CLK_SW_CFG(x)           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_CGM_UFS_AO_EN                           ( BIT(23) )
#define BIT_AON_APB_CGM_USB_SUSPEND_EN                      ( BIT(22) )
#define BIT_AON_APB_CGM_RC60M_FDK_EN                        ( BIT(20) )
#define BIT_AON_APB_CGM_RC60M_REF_EN                        ( BIT(19) )
#define BIT_AON_APB_DET_32K_EB                              ( BIT(18) )
#define BIT_AON_APB_CGM_DEBOUNCE_EN                         ( BIT(17) )
#define BIT_AON_APB_CGM_RC100M_FDK_EN                       ( BIT(16) )
#define BIT_AON_APB_CGM_RC100M_REF_EN                       ( BIT(15) )
#define BIT_AON_APB_CGM_TMR_EN                              ( BIT(14) )
#define BIT_AON_APB_CGM_TSEN_EN                             ( BIT(13) )
#define BIT_AON_APB_CGM_OTG_REF_EN                          ( BIT(12) )
#define BIT_AON_APB_CGM_DMC_REF_EN                          ( BIT(11) )
#define BIT_AON_APB_CGM_DPHY_REF_EN                         ( BIT(10) )
#define BIT_AON_APB_CGM_DJTAG_TCK_EN                        ( BIT(9) )
#define BIT_AON_APB_CGM_DSI_CSI_TEST_EB                     ( BIT(8) )
#define BIT_AON_APB_CGM_MDAR_CHK_EN                         ( BIT(7) )
#define BIT_AON_APB_CGM_26M_LVDSDIS_EN                      ( BIT(6) )
#define BIT_AON_APB_CGM_LVDSRF_CALI_EN                      ( BIT(5) )
#define BIT_AON_APB_CGM_RFTI2_LTH_EN                        ( BIT(4) )
#define BIT_AON_APB_CGM_RFTI2_XO_EN                         ( BIT(3) )
#define BIT_AON_APB_CGM_RFTI1_LTH_EN                        ( BIT(2) )
#define BIT_AON_APB_CGM_RFTI1_XO_EN                         ( BIT(1) )
#define BIT_AON_APB_CGM_RFTI_SBI_EN                         ( BIT(0) )

/* bits definitions for REG_AON_APB_CGM_CLK_TOP_REG1, [0x6490013C] */
#define BIT_AON_APB_SOFT_DDR0_CKG_1X_EN                     ( BIT(26) )
#define BIT_AON_APB_CGM_CH_TMR2_EN                          ( BIT(25) )
#define BIT_AON_APB_CGM_SP_TMR2_EN                          ( BIT(24) )
#define BIT_AON_APB_SOFT_DDR0_DATA_RET                      ( BIT(23) )
#define BIT_AON_APB_LIGHT_SLEEP_DDR0_DATA_RET_EN            ( BIT(21) )
#define BIT_AON_APB_EMC0_CKG_SEL_LOAD                       ( BIT(19) )
#define BIT_AON_APB_CLK_DEBUG_TS_EB                         ( BIT(18) )
#define BIT_AON_APB_ESE_EFUSE_CTRL_EB                       ( BIT(17) )
#define BIT_AON_APB_AAPC_CLK_TEST_EB                        ( BIT(16) )
#define BIT_AON_APB_CGM_CPHY_CFG_EN                         ( BIT(15) )
#define BIT_AON_APB_ALL_PLL_TEST_EB                         ( BIT(14) )
#define BIT_AON_APB_CGM_RC6M_FDK_EN                         ( BIT(11) )
#define BIT_AON_APB_CGM_RC6M_REF_EN                         ( BIT(10) )
#define BIT_AON_APB_CGM_EMMC_2X_EN                          ( BIT(9) )
#define BIT_AON_APB_CGM_EMMC_1X_EN                          ( BIT(8) )
#define BIT_AON_APB_CGM_SDIO2_1X_EN                         ( BIT(7) )
#define BIT_AON_APB_CGM_SDIO2_2X_EN                         ( BIT(6) )
#define BIT_AON_APB_CGM_SDIO1_1X_EN                         ( BIT(5) )
#define BIT_AON_APB_CGM_SDIO1_2X_EN                         ( BIT(4) )
#define BIT_AON_APB_CGM_SDIO0_1X_EN                         ( BIT(3) )
#define BIT_AON_APB_CGM_SDIO0_2X_EN                         ( BIT(2) )
#define BIT_AON_APB_CGM_AP_AXI_EN                           ( BIT(1) )
#define BIT_AON_APB_CGM_CSSYS_EN                            ( BIT(0) )

/* bits definitions for REG_AON_APB_AUDCP_DSP_CTRL0, [0x64900140] */
#define BIT_AON_APB_AUDCP_DSP_BOOT_VECTOR(x)                ( (x) )

/* bits definitions for REG_AON_APB_AUDCP_DSP_CTRL1, [0x64900144] */
#define BIT_AON_APB_AUDCP_STCK_DSP                          ( BIT(13) )
#define BIT_AON_APB_AUDCP_STMS_DSP                          ( BIT(12) )
#define BIT_AON_APB_AUDCP_STDO_DSP                          ( BIT(11) )
#define BIT_AON_APB_AUDCP_STDI_DSP                          ( BIT(10) )
#define BIT_AON_APB_AUDCP_STRTCK_DSP                        ( BIT(9) )
#define BIT_AON_APB_AUDCP_SW_JTAG_ENA_DSP                   ( BIT(8) )
#define BIT_AON_APB_AUDCP_DSP_EXTERNAL_WAIT                 ( BIT(1) )
#define BIT_AON_APB_AUDCP_DSP_BOOT                          ( BIT(0) )

/* bits definitions for REG_AON_APB_AUDCP_CTRL, [0x6490014C] */
#define BIT_AON_APB_CH_2_AUD_ACCESS_EN                      ( BIT(6) )
#define BIT_AON_APB_AP_2_AUD_ACCESS_EN                      ( BIT(5) )
#define BIT_AON_APB_PSCP_2_AUD_ACCESS_EN                    ( BIT(4) )
#define BIT_AON_APB_PHYCP_2_AUD_ACCESS_EN                   ( BIT(3) )
#define BIT_AON_APB_AUDCP_FRC_CLK_DSP_EN                    ( BIT(1) )
#define BIT_AON_APB_AON_2_AUD_ACCESS_EN                     ( BIT(0) )

/* bits definitions for REG_AON_APB_CDMA2K_CTRL, [0x64900160] */
#define BIT_AON_APB_AHBNI_CLK_ENB_SOFT_CTL                  ( BIT(3) )
#define BIT_AON_APB_CDMA2K_NI_ACTIVE_SOFT_CTL               ( BIT(2) )
#define BIT_AON_APB_AHBNI_CLK_ENB_AUTO_SEL                  ( BIT(1) )
#define BIT_AON_APB_CDMA2K_NI_ACTIVE_AUTO_SEL               ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_AON_EB, [0x64900170] */
#define BIT_AON_APB_PSCP_WDG_RTC_EB                         ( BIT(13) )
#define BIT_AON_APB_PSCP_SYST_RTC_EB                        ( BIT(12) )
#define BIT_AON_APB_PSCP_TMR_RTC_EB                         ( BIT(11) )
#define BIT_AON_APB_PSCP_TMR_EB                             ( BIT(10) )
#define BIT_AON_APB_PSCP_SYST_EB                            ( BIT(8) )
#define BIT_AON_APB_PSCP_WDG_EB                             ( BIT(7) )
#define BIT_AON_APB_CPALL_EIC                               ( BIT(4) )
#define BIT_AON_APB_CPALL_EIC_RTCDV5_EB                     ( BIT(3) )
#define BIT_AON_APB_CPALL_EIC_RTC_EB                        ( BIT(2) )

/* bits definitions for REG_AON_APB_PSCP_SOFT_RST, [0x64900174] */
#define BIT_AON_APB_PSCP_CR8_BLK_SW_RST                     ( BIT(14) )
#define BIT_AON_APB_PSCP_CR8_PS_CORE_SW_RST(x)              ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_APB_PSCP_CR8_BLK_DBG_SW_RST                 ( BIT(11) )
#define BIT_AON_APB_PSCP_CR8_PS_CORE_DBG_SW_RST(x)          ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_AON_APB_PSCP_CR8_ETM_SOFT_RST                   ( BIT(8) )
#define BIT_AON_APB_PSCP_CR8_MP_SOFT_RST                    ( BIT(7) )
#define BIT_AON_APB_PSCP_CR8_CS_DBG_SOFT_RST                ( BIT(6) )
#define BIT_AON_APB_PSCP_SYST_SOFT_RST                      ( BIT(4) )
#define BIT_AON_APB_PSCP_WDG_SOFT_RST                       ( BIT(3) )
#define BIT_AON_APB_CPALL_EIC_SOFT_RST                      ( BIT(2) )

/* bits definitions for REG_AON_APB_PSCP_CTRL, [0x64900178] */
#define BIT_AON_APB_PSCP_CR8_FORCE_DIVN_ON                  ( BIT(9) )
#define BIT_AON_APB_PSCP_CR8_MFILTEREN                      ( BIT(8) )
#define BIT_AON_APB_PSCP_CR8_TEINIT(x)                      ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AON_APB_PSCP_CR8_VINITHI(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_APB_PSCP_CR8_NMFI(x)                        ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_PSCP_CR8_CFG_ENDIAN(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_VECTOR_VDSP, [0x6490017C] */
#define BIT_AON_APB_VECTOR_VDSP(x)                          ( (x) )

/* bits definitions for REG_AON_APB_AON_SOC_USB_CTRL, [0x64900190] */
#define BIT_AON_APB_USB20_ISO_SW_EN                         ( BIT(4) )
#define BIT_AON_APB_USB20_CTRL_MUX_REG                      ( BIT(3) )
#define BIT_AON_APB_USB_BUSCLK_SEL_SOC                      ( BIT(2) )
#define BIT_AON_APB_USB_DIVN_MUX_SEL                        ( BIT(1) )
#define BIT_AON_APB_AON_IIS_SEL                             ( BIT(0) )

/* bits definitions for REG_AON_APB_ESE_INT_MASK, [0x64900194] */
#define BIT_AON_APB_INT_REQ_ESE_TO_CP_SWITCH                ( BIT(4) )
#define BIT_AON_APB_INT_REQ_ESE_TO_CP_MASK                  ( BIT(3) )
#define BIT_AON_APB_INT_REQ_ESE_TO_CP_MASK_CM4              ( BIT(2) )
#define BIT_AON_APB_INT_REQ_ESE_TO_APCPUREE_MASK            ( BIT(1) )
#define BIT_AON_APB_INT_REQ_ESE_TO_APCPUTEE_MASK            ( BIT(0) )

/* bits definitions for REG_AON_APB_SOFT_RST_AON_ADD1, [0x649001A0] */
#define BIT_AON_APB_RFTI_RESETB_SOFT_RST                    ( BIT(9) )
#define BIT_AON_APB_RFTI_APB_SOFT_RST                       ( BIT(8) )
#define BIT_AON_APB_BSMTMR_SOFT_RST                         ( BIT(7) )
#define BIT_AON_APB_RFTI2_LTH_SOFT_RST                      ( BIT(6) )
#define BIT_AON_APB_RFTI1_LTH_SOFT_RST                      ( BIT(5) )
#define BIT_AON_APB_CSSYS_SOFT_RST                          ( BIT(4) )
#define BIT_AON_APB_DET_32K_SOFT_RST                        ( BIT(3) )
#define BIT_AON_APB_ARCH_RTC_SOFT_RSTY                      ( BIT(2) )
#define BIT_AON_APB_RFTI_SBI_SOFT_RST                       ( BIT(1) )
#define BIT_AON_APB_LVDSRF_CALI_SOFT_RST                    ( BIT(0) )

/* bits definitions for REG_AON_APB_VDSP_INT_CTRL, [0x649001A4] */
#define BIT_AON_APB_INT_REQ_DCAM2_ARM_STAT                  ( BIT(9) )
#define BIT_AON_APB_INT_REQ_DCAM1_ARM_STAT                  ( BIT(8) )
#define BIT_AON_APB_INT_REQ_DCAM0_ARM_STAT                  ( BIT(7) )
#define BIT_AON_APB_INT_REQ_ISP_CH1_STAT                    ( BIT(6) )
#define BIT_AON_APB_INT_REQ_ISP_CH0_STAT                    ( BIT(5) )
#define BIT_AON_APB_INT_REQ_DCAM2_ARM_MASK                  ( BIT(4) )
#define BIT_AON_APB_INT_REQ_DCAM1_ARM_MASK                  ( BIT(3) )
#define BIT_AON_APB_INT_REQ_DCAM0_ARM_MASK                  ( BIT(2) )
#define BIT_AON_APB_INT_REQ_ISP_CH1_MASK                    ( BIT(1) )
#define BIT_AON_APB_INT_REQ_ISP_CH0_MASK                    ( BIT(0) )

/* bits definitions for REG_AON_APB_ISE_SYS_CTRL, [0x649001A8] */
#define BIT_AON_APB_INT_REQ_ISE_WDG_RST                     ( BIT(2) )
#define BIT_AON_APB_ISE_CORE_1_SOFT_RST                     ( BIT(1) )
#define BIT_AON_APB_ISE_CORE_0_SOFT_RST                     ( BIT(0) )

/* bits definitions for REG_AON_APB_EB_AON_ADD1, [0x649001B0] */
#define BIT_AON_APB_BUSMON_CSTMR_PUB2                       ( BIT(4) )
#define BIT_AON_APB_BUSMON_CSTMR_IPA                        ( BIT(3) )
#define BIT_AON_APB_BUSMON_CSTMR_PUB0                       ( BIT(2) )
#define BIT_AON_APB_BUSMON_CSTMR_PUB1                       ( BIT(1) )

/* bits definitions for REG_AON_APB_DBG_DJTAG_CTRL, [0x649001C0] */
#define BIT_AON_APB_DBGSYS_CSSYS_STM_NSGUAREN               ( BIT(16) )
#define BIT_AON_APB_DJTAG_SRC_MUX_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PAD_DBG_BUS_DATA_A, [0x649001F0] */
#define BIT_AON_APB_PAD_DBG_BUS_DATA_A(x)                   ( (x) )

/* bits definitions for REG_AON_APB_PAD_DBG_BUS_DATA_B, [0x649001F4] */
#define BIT_AON_APB_PAD_DBG_BUS_DATA_B(x)                   ( (x) )

/* bits definitions for REG_AON_APB_PAD_DBG_BUS_DATA_OUT, [0x649001F8] */
#define BIT_AON_APB_PAD_DBG_BUS_DATA_OUT(x)                 ( (x) )

/* bits definitions for REG_AON_APB_MBIST_EFUSE_CTRL, [0x649001FC] */
#define BIT_AON_APB_FUSEBOX_SEL_CTRL                        ( BIT(1) )
#define BIT_AON_APB_FUSEBOX_SEL_BUF_SW                      ( BIT(0) )

/* bits definitions for REG_AON_APB_OTG_PHY_TUNE, [0x64900200] */
#define BIT_AON_APB_OTG_TXPREEMPPULSETUNE                   ( BIT(20) )
#define BIT_AON_APB_OTG_TXRESTUNE(x)                        ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_AON_APB_OTG_TXHSXVTUNE(x)                       ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AON_APB_OTG_TXVREFTUNE(x)                       ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_OTG_TXPREEMPAMPTUNE(x)                  ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AON_APB_OTG_TXRISETUNE(x)                       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_APB_OTG_TXFSLSTUNE(x)                       ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_OTG_SQRXTUNE(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_OTG_PHY_TEST, [0x64900204] */
#define BIT_AON_APB_OTG_ATERESET                            ( BIT(31) )
#define BIT_AON_APB_USB30_POWER_PRESENT                     ( BIT(25) )
#define BIT_AON_APB_OTG_VBUS_VALID_PHYREG                   ( BIT(24) )
#define BIT_AON_APB_OTG_VBUS_VALID_PHYREG_SEL               ( BIT(23) )
#define BIT_AON_APB_OTG_VBUS_VALID_EXT                      ( BIT(22) )
#define BIT_AON_APB_OTG_TESTBURNIN                          ( BIT(21) )
#define BIT_AON_APB_OTG_LOOPBACKENB                         ( BIT(20) )
#define BIT_AON_APB_OTG_TESTDATAOUT(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_OTG_VATESTENB(x)                        ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AON_APB_OTG_TESTCLK                             ( BIT(13) )
#define BIT_AON_APB_OTG_TESTDATAOUTSEL                      ( BIT(12) )
#define BIT_AON_APB_OTG_TESTADDR(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_OTG_TESTDATAIN(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_OTG_PHY_CTRL, [0x64900208] */
#define BIT_AON_APB_USB2_CON_TESTMODE                       ( BIT(31) )
#define BIT_AON_APB_UTMI_WIDTH_SEL                          ( BIT(30) )
#define BIT_AON_APB_USB2_DATABUS16_8                        ( BIT(29) )
#define BIT_AON_APB_OTG_SS_SCALEDOWNMODE(x)                 ( (x) << 25 & (BIT(25)|BIT(26)) )
#define BIT_AON_APB_OTG_TXBITSTUFFENH                       ( BIT(23) )
#define BIT_AON_APB_OTG_TXBITSTUFFEN                        ( BIT(22) )
#define BIT_AON_APB_OTG_DMPULLDOWN                          ( BIT(21) )
#define BIT_AON_APB_OTG_DPPULLDOWN                          ( BIT(20) )
#define BIT_AON_APB_OTG_DMPULLUP                            ( BIT(9) )
#define BIT_AON_APB_OTG_COMMONONN                           ( BIT(8) )
#define BIT_AON_APB_USB2_PHY_IDDIG                          ( BIT(3) )
#define BIT_AON_APB_OTG_FSEL(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_OTG_CTRL0, [0x6490020C] */
#define BIT_AON_APB_USB20_TUNEHSAMP(x)                      ( (x) << 30 & (BIT(30)|BIT(31)) )
#define BIT_AON_APB_USB20_TUNEPLLS(x)                       ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_AON_APB_USB20_TUNERISE(x)                       ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_AON_APB_USB20_TUNEDSC(x)                        ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_AON_APB_USB20_TUNEOTG(x)                        ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_USB20_TUNESQ(x)                         ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AON_APB_USB20_RESERVED(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_OTG_CTRL1, [0x64900210] */
#define BIT_AON_APB_USB20_BIST_MODE(x)                      ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_USB20_BYPASS_DRV_DM                     ( BIT(22) )
#define BIT_AON_APB_USB20_BYPASS_DRV_DP                     ( BIT(21) )
#define BIT_AON_APB_USB20_SAMPLER_SEL                       ( BIT(20) )
#define BIT_AON_APB_HSIC_PLLON                              ( BIT(16) )
#define BIT_AON_APB_USB20_REXTENABLE                        ( BIT(15) )
#define BIT_AON_APB_USB20_S_ID                              ( BIT(14) )
#define BIT_AON_APB_USB20_TFREGRES(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AON_APB_USB20_TFHSRES(x)                        ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_USB20_TUNEEQ(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_USB_CLK_REF_SEL, [0x64900214] */
#define BIT_AON_APB_USB_REF_CLK_MUX_SEL                     ( BIT(0) )

/* bits definitions for REG_AON_APB_LVDSRF_CTRL, [0x64900218] */
#define BIT_AON_APB_LVDSRF_ISO_EN                           ( BIT(2) )
#define BIT_AON_APB_LVDSRF_PD_PD_L                          ( BIT(1) )
#define BIT_AON_APB_LVDSRF_PS_PD_S                          ( BIT(0) )

/* bits definitions for REG_AON_APB_THM0_CTRL, [0x6490021C] */
#define BIT_AON_APB_THM0_CALI_RSVD(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_THM1_CTRL, [0x64900220] */
#define BIT_AON_APB_THM1_CALI_RSVD(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_THM2_CTRL, [0x64900224] */
#define BIT_AON_APB_THM2_CALI_RSVD(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_THM3_CTRL, [0x64900228] */
#define BIT_AON_APB_THM3_CALI_RSVD(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_OVERHEAT_CTRL, [0x6490022C] */
#define BIT_AON_APB_THM3_INT_ADIE_EN                        ( BIT(11) )
#define BIT_AON_APB_THM2_INT_ADIE_EN                        ( BIT(10) )
#define BIT_AON_APB_THM1_INT_ADIE_EN                        ( BIT(9) )
#define BIT_AON_APB_THM0_INT_ADIE_EN                        ( BIT(8) )
#define BIT_AON_APB_THM3_OVERHEAT_ALARM_ADIE_EN             ( BIT(7) )
#define BIT_AON_APB_THM2_OVERHEAT_ALARM_ADIE_EN             ( BIT(6) )
#define BIT_AON_APB_THM1_OVERHEAT_ALARM_ADIE_EN             ( BIT(5) )
#define BIT_AON_APB_THM0_OVERHEAT_ALARM_ADIE_EN             ( BIT(4) )
#define BIT_AON_APB_THM3_OVERHEAT_RST_DDIE_EN               ( BIT(3) )
#define BIT_AON_APB_THM2_OVERHEAT_RST_DDIE_EN               ( BIT(2) )
#define BIT_AON_APB_THM1_OVERHEAT_RST_DDIE_EN               ( BIT(1) )
#define BIT_AON_APB_THM0_OVERHEAT_RST_DDIE_EN               ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_SIM1_TOP_CTRL, [0x64900230] */
#define BIT_AON_APB_CP_SIM1_CLK_PL                          ( BIT(5) )
#define BIT_AON_APB_CP_SIM1_DETECT_EN                       ( BIT(4) )
#define BIT_AON_APB_CP_BAT1_DETECT_EN                       ( BIT(3) )
#define BIT_AON_APB_CP_SIM1_DETECT_POL                      ( BIT(2) )
#define BIT_AON_APB_CP_BAT1_DETECT_POL                      ( BIT(1) )
#define BIT_AON_APB_CP_SIM1_OFF_PD_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_SIM2_TOP_CTRL, [0x64900234] */
#define BIT_AON_APB_CP_SIM2_CLK_PL                          ( BIT(5) )
#define BIT_AON_APB_CP_SIM2_DETECT_EN                       ( BIT(4) )
#define BIT_AON_APB_CP_BAT2_DETECT_EN                       ( BIT(3) )
#define BIT_AON_APB_CP_SIM2_DETECT_POL                      ( BIT(2) )
#define BIT_AON_APB_CP_BAT2_DETECT_POL                      ( BIT(1) )
#define BIT_AON_APB_CP_SIM2_OFF_PD_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_SIM3_TOP_CTRL, [0x64900238] */
#define BIT_AON_APB_CP_SIM3_CLK_PL                          ( BIT(5) )
#define BIT_AON_APB_CP_SIM3_DETECT_EN                       ( BIT(4) )
#define BIT_AON_APB_CP_BAT3_DETECT_EN                       ( BIT(3) )
#define BIT_AON_APB_CP_SIM3_DETECT_POL                      ( BIT(2) )
#define BIT_AON_APB_CP_BAT3_DETECT_POL                      ( BIT(1) )
#define BIT_AON_APB_CP_SIM3_OFF_PD_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AP_SIM_TOP_CTRL, [0x6490023C] */
#define BIT_AON_APB_AP_SIM_CLK_PL                           ( BIT(5) )
#define BIT_AON_APB_AP_SIM_DETECT_EN                        ( BIT(4) )
#define BIT_AON_APB_AP_BAT_DETECT_EN                        ( BIT(3) )
#define BIT_AON_APB_AP_SIM_DETECT_POL                       ( BIT(2) )
#define BIT_AON_APB_AP_BAT_DETECT_POL                       ( BIT(1) )
#define BIT_AON_APB_AP_SIM_OFF_PD_EN                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AUX0_CTRL, [0x64900240] */
#define BIT_AON_APB_AUX0_MUX(x)                             ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_AUX0_DIVN(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_AUX1_CTRL, [0x64900244] */
#define BIT_AON_APB_AUX1_MUX(x)                             ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_AUX1_DIVN(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_AUX2_CTRL, [0x64900248] */
#define BIT_AON_APB_AUX2_MUX(x)                             ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_AUX2_DIVN(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_PROBE_CTRL, [0x6490024C] */
#define BIT_AON_APB_PROBE_MUX(x)                            ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_PROBE_DIVN(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_AON_MISC_CTRL_REG, [0x64900250] */
#define BIT_AON_APB_ALL_PLL_TEST_EN                         ( BIT(4) )
#define BIT_AON_APB_LVDSRF_RX_CLKDIG_TEST_SEL(x)            ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_LVDSRF_TX_CLKDIG_TEST_SEL(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_UFS_REF_CLK_CTRL, [0x64900254] */
#define BIT_AON_APB_DEV_REF_CLOCK_EN_DELAY                  ( BIT(26) )
#define BIT_AON_APB_CNT_VALUE_1023US(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AON_APB_CNT_VALUE_1US(x)                        ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_CNT_CLR                                 ( BIT(10) )
#define BIT_AON_APB_REFCLK_GATE_TIME(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_AON_APB_APCPU_MONITOR_STATUS, [0x64900280] */
#define BIT_AON_APB_MONITOR_GATE_AUTO_EN_STATUS(x)          ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_MONITOR_WAIT_EN_STATUS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_APCPU_CLUSTER_ATB_LPC_CTRL, [0x6490028C] */
#define BIT_AON_APB_APCPU_CLUSTER_ATB_LP_NUM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_CLUSTER_ATB_LP_EB                 ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_CLUSTER_APB_LPC_CTRL, [0x64900290] */
#define BIT_AON_APB_APCPU_CLUSTER_APB_LP_NUM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_CLUSTER_APB_LP_EB                 ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_CLUSTER_GIC_LPC_CTRL, [0x64900294] */
#define BIT_AON_APB_APCPU_CLUSTER_GIC_LP_NUM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_CLUSTER_GIC_LP_EB                 ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_GIC600_GIC_LPC_CTRL, [0x64900298] */
#define BIT_AON_APB_APCPU_GIC600_GIC_LP_NUM(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_GIC600_GIC_LP_EB                  ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_DBG_BLK_LPC_CTRL, [0x6490029C] */
#define BIT_AON_APB_APCPU_DBG_BLK_LP_NUM(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_DBG_BLK_LP_EB                     ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_TOP_MTX_LPC_CTRL, [0x64900300] */
#define BIT_AON_APB_APCPU_MTX_MAIN_LP_NUM(x)                ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_APCPU_MTX_MAIN_LP_EB                    ( BIT(10) )
#define BIT_AON_APB_APCPU_MTX_S3_LP_EB                      ( BIT(9) )
#define BIT_AON_APB_APCPU_MTX_S2_LP_EB                      ( BIT(8) )
#define BIT_AON_APB_APCPU_MTX_S1_LP_EB                      ( BIT(7) )
#define BIT_AON_APB_APCPU_MTX_S0_LP_EB                      ( BIT(6) )
#define BIT_AON_APB_APCPU_MTX_M4_LP_EB                      ( BIT(4) )
#define BIT_AON_APB_APCPU_MTX_M3_LP_EB                      ( BIT(3) )
#define BIT_AON_APB_APCPU_MTX_M2_LP_EB                      ( BIT(2) )
#define BIT_AON_APB_APCPU_MTX_M1_LP_EB                      ( BIT(1) )
#define BIT_AON_APB_APCPU_MTX_M0_LP_EB                      ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_TOP_MTX_LPC_PU_NUM_CTRL, [0x64900304] */
#define BIT_AON_APB_APCPU_MTX_PU_NUM(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_APCPU_ACE_PU_NUM(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_APCPU_MTX_LP_NUM_S0S1, [0x64900308] */
#define BIT_AON_APB_APCPU_MTX_S1_LP_NUM(x)                  ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_APCPU_MTX_S0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_APCPU_MTX_LP_NUM_S2S3, [0x6490030C] */
#define BIT_AON_APB_APCPU_MTX_S3_LP_NUM(x)                  ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_APCPU_MTX_S2_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_APCPU_MTX_LP_NUM_M1M2, [0x64900310] */
#define BIT_AON_APB_APCPU_MTX_M2_LP_NUM(x)                  ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_APCPU_MTX_M1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_APCPU_MTX_LP_NUM_M3M4, [0x64900314] */
#define BIT_AON_APB_APCPU_MTX_M4_LP_NUM(x)                  ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_APCPU_MTX_M3_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_APCPU_AON_AB_LPC_CTRL, [0x64900318] */
#define BIT_AON_APB_APCPU_AON_AB_LP_NUM(x)                  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_AON_AB_LP_EB                      ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_CLUSTER_SCU_LPC_CTRL, [0x64900320] */
#define BIT_AON_APB_APCPU_CLUSTER_SCU_LP_NUM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_CLUSTER_SCU_LP_EB                 ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_DDR_AB_LPC_CTRL, [0x64900324] */
#define BIT_AON_APB_APCPU_DDR_AB_LP_NUM(x)                  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_APCPU_DDR_AB_LP_EB                      ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_QOS_CTRL, [0x64900328] */
#define BIT_AON_APB_QOS_CPS_APCPU(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_QOS_DAP_APCPU(x)                        ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_QOS_ETR_APCPU(x)                        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_ARQOS_THRESHOLD_APCPU(x)                ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_AWQOS_THRESHOLD_APCPU(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_ARQOS_APCPU(x)                          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_AWQOS_APCPU(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_MPLL_LIT_CTRL, [0x6490032C] */
#define BIT_AON_APB_JITTER_MON_MPLL_LIT_SEL(x)              ( (x) << 17 & (BIT(17)|BIT(18)) )
#define BIT_AON_APB_JITTER_MON_EN                           ( BIT(16) )
#define BIT_AON_APB_CGM_MPLL_LIT_APCPU_FORCE_EN             ( BIT(9) )
#define BIT_AON_APB_CGM_MPLL_LIT_APCPU_AUTO_GATE_SEL        ( BIT(8) )
#define BIT_AON_APB_MPLL_LIT_WAIT_FORCE_EN                  ( BIT(2) )
#define BIT_AON_APB_MPLL_LIT_WAIT_AUTO_GATE_SEL             ( BIT(1) )
#define BIT_AON_APB_MPLL_LIT_SOFT_CNT_DONE                  ( BIT(0) )

/* bits definitions for REG_AON_APB_MPLL_MID_CTRL, [0x64900330] */
#define BIT_AON_APB_CGM_MPLL_MID_APCPU_FORCE_EN             ( BIT(9) )
#define BIT_AON_APB_CGM_MPLL_MID_APCPU_AUTO_GATE_SEL        ( BIT(8) )
#define BIT_AON_APB_MPLL_MID_WAIT_FORCE_EN                  ( BIT(2) )
#define BIT_AON_APB_MPLL_MID_WAIT_AUTO_GATE_SEL             ( BIT(1) )
#define BIT_AON_APB_MPLL_MID_SOFT_CNT_DONE                  ( BIT(0) )

/* bits definitions for REG_AON_APB_MPLL_BIG_CTRL, [0x64900334] */
#define BIT_AON_APB_CGM_MPLL_BIG_APCPU_FORCE_EN             ( BIT(9) )
#define BIT_AON_APB_CGM_MPLL_BIG_APCPU_AUTO_GATE_SEL        ( BIT(8) )
#define BIT_AON_APB_MPLL_BIG_WAIT_FORCE_EN                  ( BIT(2) )
#define BIT_AON_APB_MPLL_BIG_WAIT_AUTO_GATE_SEL             ( BIT(1) )
#define BIT_AON_APB_MPLL_BIG_SOFT_CNT_DONE                  ( BIT(0) )

/* bits definitions for REG_AON_APB_MPLL_SCU_CTRL, [0x64900338] */
#define BIT_AON_APB_CGM_MPLL_SCU_APCPU_FORCE_EN             ( BIT(9) )
#define BIT_AON_APB_CGM_MPLL_SCU_APCPU_AUTO_GATE_SEL        ( BIT(8) )
#define BIT_AON_APB_MPLL_SCU_WAIT_FORCE_EN                  ( BIT(2) )
#define BIT_AON_APB_MPLL_SCU_WAIT_AUTO_GATE_SEL             ( BIT(1) )
#define BIT_AON_APB_MPLL_SCU_SOFT_CNT_DONE                  ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_URGENCY_CTRL, [0x6490033C] */
#define BIT_AON_APB_ARURGENCY_M4(x)                         ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_AON_APB_AWURGENCY_M4(x)                         ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AON_APB_ARURGENCY_M3(x)                         ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AON_APB_AWURGENCY_M3(x)                         ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_APB_ARURGENCY_M2(x)                         ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AON_APB_AWURGENCY_M2(x)                         ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_APB_ARURGENCY_M1(x)                         ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AON_APB_AWURGENCY_M1(x)                         ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_APB_ARURGENCY_M0(x)                         ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_AWURGENCY_M0(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_DPLL_CTRL, [0x64900340] */
#define BIT_AON_APB_DPLL2_WAIT_AUTO_GATE_SEL                ( BIT(18) )
#define BIT_AON_APB_DPLL2_SOFT_CNT_DONE                     ( BIT(17) )
#define BIT_AON_APB_DPLL2_WAIT_FORCE_EN                     ( BIT(16) )
#define BIT_AON_APB_CGM_DPLL0_PUB_AUTO_GATE_SEL             ( BIT(15) )
#define BIT_AON_APB_CGM_DPLL1_PUB_AUTO_GATE_SEL             ( BIT(14) )
#define BIT_AON_APB_CGM_DPLL2_PUB_AUTO_GATE_SEL             ( BIT(13) )
#define BIT_AON_APB_CGM_DPLL0_PUB_FORCE_EN                  ( BIT(12) )
#define BIT_AON_APB_CGM_DPLL1_PUB_FORCE_EN                  ( BIT(11) )
#define BIT_AON_APB_CGM_DPLL2_PUB_FORCE_EN                  ( BIT(10) )
#define BIT_AON_APB_CGM_DPLL1_1600M_PUB_FORCE_EN            ( BIT(9) )
#define BIT_AON_APB_CGM_DPLL0_2666M_PUB_FORCE_EN            ( BIT(8) )
#define BIT_AON_APB_CGM_DPLL1_1600M_PUB_AUTO_GATE_SEL       ( BIT(7) )
#define BIT_AON_APB_CGM_DPLL0_2666M_PUB_AUTO_GATE_SEL       ( BIT(6) )
#define BIT_AON_APB_DPLL1_WAIT_FORCE_EN                     ( BIT(5) )
#define BIT_AON_APB_DPLL0_WAIT_FORCE_EN                     ( BIT(4) )
#define BIT_AON_APB_DPLL1_WAIT_AUTO_GATE_SEL                ( BIT(3) )
#define BIT_AON_APB_DPLL0_WAIT_AUTO_GATE_SEL                ( BIT(2) )
#define BIT_AON_APB_DPLL1_SOFT_CNT_DONE                     ( BIT(1) )
#define BIT_AON_APB_DPLL0_SOFT_CNT_DONE                     ( BIT(0) )

/* bits definitions for REG_AON_APB_PUB_CLK_GATING_CTRL, [0x64900344] */
#define BIT_AON_APB_PUB_APB_FW_EB                           ( BIT(17) )
#define BIT_AON_APB_PUB_REG_EB                              ( BIT(16) )
#define BIT_AON_APB_DMC_EB                                  ( BIT(15) )

/* bits definitions for REG_AON_APB_MIPI_CSI_POWER_CTRL, [0x64900350] */
#define BIT_AON_APB_ANALOG_BB_TOP_SINDRV_LVDSPHY_ENA_AUTO_EN ( BIT(19) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_LVDSPHY_ENA_ADC ( BIT(18) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_LVDSPHY_ENA_DVFS ( BIT(17) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_LVDSPHY_ENA_CAL ( BIT(16) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_LVDSPHY_ENA    ( BIT(15) )
#define BIT_AON_APB_ANALOG_BB_TOP_SINDRV_PCIE_ENA_AUTO_EN   ( BIT(14) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_PCIE_ENA_ADC   ( BIT(13) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_PCIE_ENA_DVFS  ( BIT(12) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_PCIE_ENA_CAL   ( BIT(11) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_PCIE_ENA       ( BIT(10) )
#define BIT_AON_APB_ANALOG_BB_TOP_SINDRV_ENA_AUTO_EN        ( BIT(9) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_ENA_ADC        ( BIT(8) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_ENA_DVFS       ( BIT(7) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_ENA_CAL        ( BIT(6) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_ENA            ( BIT(5) )
#define BIT_AON_APB_M2G_ANALOG_BB_TOP_SINDRV_ENA            ( BIT(4) )
#define BIT_AON_APB_R2G_ANALOG_BB_TOP_SINDRV_ENA_SQUARE     ( BIT(3) )
#define BIT_AON_APB_C2G_ANALOG_BB_TOP_CLK26MHZ_AUD_EN       ( BIT(2) )
#define BIT_AON_APB_C2G_ANALOG_USB20_USB20_PS_PD_S          ( BIT(1) )
#define BIT_AON_APB_C2G_ANALOG_USB20_USB20_PS_PD_L          ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_MAIN_LPC_CTRL, [0x64900368] */
#define BIT_AON_APB_AON_MTX_MAIN_LP_SYNC_SEL                ( BIT(31) )
#define BIT_AON_APB_AON_MTX_MAIN_LP_NUM(x)                  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_MAIN_LP_EB                      ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M0_LPC_CTRL, [0x6490036C] */
#define BIT_AON_APB_AON_MTX_M0_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M0_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M0_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M1_LPC_CTRL, [0x64900370] */
#define BIT_AON_APB_AON_MTX_M1_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M1_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M1_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M2_LPC_CTRL, [0x64900374] */
#define BIT_AON_APB_AON_MTX_M2_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M2_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M2_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M3_LPC_CTRL, [0x64900378] */
#define BIT_AON_APB_AON_MTX_M3_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M3_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M3_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M4_LPC_CTRL, [0x6490037C] */
#define BIT_AON_APB_AON_MTX_M4_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M4_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M4_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M5_LPC_CTRL, [0x64900380] */
#define BIT_AON_APB_AON_MTX_M5_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M5_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M5_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M6_LPC_CTRL, [0x64900384] */
#define BIT_AON_APB_AON_MTX_M6_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M6_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M6_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M7_LPC_CTRL, [0x64900388] */
#define BIT_AON_APB_AON_MTX_M7_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M7_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M7_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M8_LPC_CTRL, [0x6490038C] */
#define BIT_AON_APB_AON_MTX_M8_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M8_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M8_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M9_LPC_CTRL, [0x64900390] */
#define BIT_AON_APB_AON_MTX_M9_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M9_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M9_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_M11_LPC_CTRL, [0x64900398] */
#define BIT_AON_APB_AON_MTX_M11_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_M11_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_M11_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S0_LPC_CTRL, [0x6490039C] */
#define BIT_AON_APB_AON_MTX_S0_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S0_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S0_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S1_LPC_CTRL, [0x649003A0] */
#define BIT_AON_APB_AON_MTX_S1_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S1_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S1_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S2_LPC_CTRL, [0x649003A4] */
#define BIT_AON_APB_AON_MTX_S2_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S2_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S2_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S3_LPC_CTRL, [0x649003A8] */
#define BIT_AON_APB_AON_MTX_S3_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S3_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S3_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S4_LPC_CTRL, [0x649003AC] */
#define BIT_AON_APB_AON_MTX_S4_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S4_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S4_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S5_LPC_CTRL, [0x649003B0] */
#define BIT_AON_APB_AON_MTX_S5_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S5_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S5_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S6_LPC_CTRL, [0x649003B4] */
#define BIT_AON_APB_AON_MTX_S6_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S6_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S6_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S7_LPC_CTRL, [0x649003B8] */
#define BIT_AON_APB_AON_MTX_S7_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S7_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S7_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S8_LPC_CTRL, [0x649003BC] */
#define BIT_AON_APB_AON_MTX_S8_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S8_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S8_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S9_LPC_CTRL, [0x649003C0] */
#define BIT_AON_APB_AON_MTX_S9_LP_SYNC_SEL                  ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S9_LP_NUM(x)                    ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S9_LP_EB                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S10_LPC_CTRL, [0x649003C4] */
#define BIT_AON_APB_AON_MTX_S10_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S10_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S10_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S11_LPC_CTRL, [0x649003C8] */
#define BIT_AON_APB_AON_MTX_S11_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S11_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S11_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S12_LPC_CTRL, [0x649003CC] */
#define BIT_AON_APB_AON_MTX_S12_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S12_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S12_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S13_LPC_CTRL, [0x649003D0] */
#define BIT_AON_APB_AON_MTX_S13_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S13_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S13_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S14_LPC_CTRL, [0x649003D4] */
#define BIT_AON_APB_AON_MTX_S14_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S14_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S14_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S15_LPC_CTRL, [0x649003D8] */
#define BIT_AON_APB_AON_MTX_S15_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S15_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S15_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S16_LPC_CTRL, [0x649003DC] */
#define BIT_AON_APB_AON_MTX_S16_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S16_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S16_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_S17_LPC_CTRL, [0x649003E0] */
#define BIT_AON_APB_AON_MTX_S17_LP_SYNC_SEL                 ( BIT(31) )
#define BIT_AON_APB_AON_MTX_S17_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_AON_MTX_S17_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AUDCP2EMC_ASYNC_BRG_LPC_CTRL, [0x649003E4] */
#define BIT_AON_APB_SYNC_SEL_AUDCP2EMC_ASYNC_BRIDGE_W       ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AUDCP2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AUDCP2EMC_ASYNC_BRIDGE_W     ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AUDCP2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AUDCP2EMC_ASYNC_BRIDGE_W(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AUDCP2EMC_ASYNC_BRIDGE_W          ( BIT(0) )

/* bits definitions for REG_AON_APB_AI2EMC_ASYNC_BRG_LPC_CTRL, [0x649003E8] */
#define BIT_AON_APB_SYNC_SEL_AI2EMC_ASYNC_BRIDGE_W          ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AI2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AI2EMC_ASYNC_BRIDGE_W        ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AI2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AI2EMC_ASYNC_BRIDGE_W(x)         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AI2EMC_ASYNC_BRIDGE_W             ( BIT(0) )

/* bits definitions for REG_AON_APB_AP2EMC_ASYNC_BRG_LPC_CTRL, [0x649003EC] */
#define BIT_AON_APB_SYNC_SEL_AP2EMC_ASYNC_BRIDGE_W          ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AP2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AP2EMC_ASYNC_BRIDGE_W        ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AP2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AP2EMC_ASYNC_BRIDGE_W(x)         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AP2EMC_ASYNC_BRIDGE_W             ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU2EMC_ASYNC_BRG_LPC_CTRL, [0x649003F0] */
#define BIT_AON_APB_SYNC_SEL_APCPU2EMC_ASYNC_BRIDGE_W       ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_APCPU2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_APCPU2EMC_ASYNC_BRIDGE_W     ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_APCPU2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_APCPU2EMC_ASYNC_BRIDGE_W(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_APCPU2EMC_ASYNC_BRIDGE_W          ( BIT(0) )

/* bits definitions for REG_AON_APB_MMLL2EMC_ASYNC_BRG_LPC_CTRL, [0x649003F4] */
#define BIT_AON_APB_SYNC_SEL_MMLL2EMC_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_MMLL2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_MMLL2EMC_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_MMLL2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_MMLL2EMC_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_MMLL2EMC_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_DPU2EMC_ASYNC_BRG_LPC_CTRL, [0x649003F8] */
#define BIT_AON_APB_SYNC_SEL_DPU2EMC_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_DPU2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_DPU2EMC_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_DPU2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_DPU2EMC_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_DPU2EMC_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_DPU12EMC_ASYNC_BRG_LPC_CTRL, [0x649003FC] */
#define BIT_AON_APB_SYNC_SEL_DPU12EMC_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_DPU12EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_DPU12EMC_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_DPU12EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_DPU12EMC_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_DPU12EMC_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_GPU2EMC_ASYNC_BRG_LPC_CTRL, [0x64900400] */
#define BIT_AON_APB_SYNC_SEL_GPU2EMC_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_GPU2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_GPU2EMC_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_GPU2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_GPU2EMC_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_GPU2EMC_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_IPA2EMC_ASYNC_BRG_LPC_CTRL, [0x64900404] */
#define BIT_AON_APB_SYNC_SEL_IPA2EMC_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_IPA2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_IPA2EMC_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_IPA2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_IPA2EMC_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_IPA2EMC_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_ISE2EMC_ASYNC_BRG_LPC_CTRL, [0x64900408] */
#define BIT_AON_APB_SYNC_SEL_ISE2EMC_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_ISE2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_ISE2EMC_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_ISE2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_ISE2EMC_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_ISE2EMC_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_MMHB2EMC_ASYNC_BRG_LPC_CTRL, [0x6490040C] */
#define BIT_AON_APB_SYNC_SEL_MMHB2EMC_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_MMHB2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_MMHB2EMC_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_MMHB2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_MMHB2EMC_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_MMHB2EMC_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_PCIE2EMC_ASYNC_BRG_LPC_CTRL, [0x64900410] */
#define BIT_AON_APB_SYNC_SEL_PCIE2EMC_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PCIE2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PCIE2EMC_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PCIE2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PCIE2EMC_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PCIE2EMC_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_PHYCP2EMC_ASYNC_BRG_LPC_CTRL, [0x64900414] */
#define BIT_AON_APB_SYNC_SEL_PHYCP2EMC_ASYNC_BRIDGE_W       ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PHYCP2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PHYCP2EMC_ASYNC_BRIDGE_W     ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PHYCP2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PHYCP2EMC_ASYNC_BRIDGE_W(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PHYCP2EMC_ASYNC_BRIDGE_W          ( BIT(0) )

/* bits definitions for REG_AON_APB_PHYCP_ACC2EMC_ASYNC_BRG_LPC_CTRL, [0x64900418] */
#define BIT_AON_APB_SYNC_SEL_PHYCP_ACC2EMC_ASYNC_BRIDGE_W   ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PHYCP_ACC2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PHYCP_ACC2EMC_ASYNC_BRIDGE_W ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PHYCP_ACC2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PHYCP_ACC2EMC_ASYNC_BRIDGE_W(x)  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PHYCP_ACC2EMC_ASYNC_BRIDGE_W      ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP2EMC_ASYNC_BRG_LPC_CTRL, [0x6490041C] */
#define BIT_AON_APB_SYNC_SEL_PSCP2EMC_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PSCP2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PSCP2EMC_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PSCP2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PSCP2EMC_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PSCP2EMC_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_ACC2EMC_ASYNC_BRG_LPC_CTRL, [0x64900420] */
#define BIT_AON_APB_SYNC_SEL_PSCP_ACC2EMC_ASYNC_BRIDGE_W    ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PSCP_ACC2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PSCP_ACC2EMC_ASYNC_BRIDGE_W  ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PSCP_ACC2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PSCP_ACC2EMC_ASYNC_BRIDGE_W(x)   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PSCP_ACC2EMC_ASYNC_BRIDGE_W       ( BIT(0) )

/* bits definitions for REG_AON_APB_VPU2EMC_ASYNC_BRG_LPC_CTRL, [0x64900424] */
#define BIT_AON_APB_SYNC_SEL_VPU2EMC_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_VPU2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_VPU2EMC_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_VPU2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_VPU2EMC_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_VPU2EMC_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2EMC_ASYNC_BRG_LPC_CTRL, [0x64900428] */
#define BIT_AON_APB_SYNC_SEL_AON2EMC_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2EMC_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2EMC_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2EMC_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2EMC_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2EMC_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2AP_ASYNC_BRG_LPC_CTRL, [0x64900430] */
#define BIT_AON_APB_SYNC_SEL_AON2AP_ASYNC_BRIDGE_W          ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2AP_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2AP_ASYNC_BRIDGE_W        ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2AP_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2AP_ASYNC_BRIDGE_W(x)         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2AP_ASYNC_BRIDGE_W             ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2DPU_ASYNC_BRG_LPC_CTRL, [0x64900434] */
#define BIT_AON_APB_SYNC_SEL_AON2DPU_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2DPU_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2DPU_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2DPU_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2DPU_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2DPU_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2IPA_ASYNC_BRG_LPC_CTRL, [0x64900438] */
#define BIT_AON_APB_SYNC_SEL_AON2IPA_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2IPA_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2IPA_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2IPA_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2IPA_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2IPA_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2MM_ASYNC_BRG_LPC_CTRL, [0x6490043C] */
#define BIT_AON_APB_SYNC_SEL_AON2MM_ASYNC_BRIDGE_W          ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2MM_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2MM_ASYNC_BRIDGE_W        ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2MM_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2MM_ASYNC_BRIDGE_W(x)         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2MM_ASYNC_BRIDGE_W             ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2PCIE_ASYNC_BRG_LPC_CTRL, [0x64900440] */
#define BIT_AON_APB_SYNC_SEL_AON2PCIE_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2PCIE_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2PCIE_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2PCIE_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2PCIE_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2PCIE_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2AI_ASYNC_BRG_LPC_CTRL, [0x64900444] */
#define BIT_AON_APB_SYNC_SEL_AON2AI_ASYNC_BRIDGE_W          ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2AI_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2AI_ASYNC_BRIDGE_W        ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2AI_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2AI_ASYNC_BRIDGE_W(x)         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2AI_ASYNC_BRIDGE_W             ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2AUD_ASYNC_BRG_LPC_CTRL, [0x64900448] */
#define BIT_AON_APB_SYNC_SEL_AON2AUD_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2AUD_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2AUD_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2AUD_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2AUD_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2AUD_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2GPU_ASYNC_BRG_LPC_CTRL, [0x6490044C] */
#define BIT_AON_APB_SYNC_SEL_AON2GPU_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2GPU_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2GPU_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2GPU_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2GPU_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2GPU_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_AON2PUB_ASYNC_BRG_LPC_CTRL, [0x64900450] */
#define BIT_AON_APB_SYNC_SEL_AON2PUB_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_AON2PUB_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_AON2PUB_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_AON2PUB_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_AON2PUB_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_AON2PUB_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_IPA2PCIE_ASYNC_BRG_LPC_CTRL, [0x64900454] */
#define BIT_AON_APB_SYNC_SEL_IPA2PCIE_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_IPA2PCIE_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_IPA2PCIE_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_IPA2PCIE_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_IPA2PCIE_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_IPA2PCIE_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_IPA2PSCP_ASYNC_BRG_LPC_CTRL, [0x6490045C] */
#define BIT_AON_APB_SYNC_SEL_IPA2PSCP_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_IPA2PSCP_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_IPA2PSCP_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_IPA2PSCP_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_IPA2PSCP_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_IPA2PSCP_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_PCIE2IPA_ASYNC_BRG_LPC_CTRL, [0x64900460] */
#define BIT_AON_APB_SYNC_SEL_PCIE2IPA_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PCIE2IPA_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PCIE2IPA_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PCIE2IPA_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PCIE2IPA_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PCIE2IPA_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_PHYCP2IPA_ASYNC_BRG_LPC_CTRL, [0x64900464] */
#define BIT_AON_APB_SYNC_SEL_PHYCP2IPA_ASYNC_BRIDGE_W       ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PHYCP2IPA_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PHYCP2IPA_ASYNC_BRIDGE_W     ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PHYCP2IPA_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PHYCP2IPA_ASYNC_BRIDGE_W(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PHYCP2IPA_ASYNC_BRIDGE_W          ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP2IPA_ASYNC_BRG_LPC_CTRL, [0x64900468] */
#define BIT_AON_APB_SYNC_SEL_PSCP2IPA_ASYNC_BRIDGE_W        ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_PSCP2IPA_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_PSCP2IPA_ASYNC_BRIDGE_W      ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_PSCP2IPA_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_PSCP2IPA_ASYNC_BRIDGE_W(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_PSCP2IPA_ASYNC_BRIDGE_W           ( BIT(0) )

/* bits definitions for REG_AON_APB_USB2AON_ASYNC_BRG_LPC_CTRL, [0x6490046C] */
#define BIT_AON_APB_SYNC_SEL_USB2AON_ASYNC_BRIDGE_W         ( BIT(31) )
#define BIT_AON_APB_BRIDGE_TRANS_IDLE_USB2AON_ASYNC_BRIDGE_W ( BIT(22) )
#define BIT_AON_APB_RST_SUBSYS_USB2AON_ASYNC_BRIDGE_W       ( BIT(21) )
#define BIT_AON_APB_AXI_DETECT_OVERFLOW_USB2AON_ASYNC_BRIDGE_W ( BIT(20) )
#define BIT_AON_APB_LP_NUM_USB2AON_ASYNC_BRIDGE_W(x)        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_LP_EB_USB2AON_ASYNC_BRIDGE_W            ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL0, [0x64900500] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL0(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL1, [0x64900504] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL1(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL2, [0x64900508] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL2(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL3, [0x6490050C] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL3(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL4, [0x64900510] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL4(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL5, [0x64900514] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL5(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL6, [0x64900518] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL6(x)               ( (x) )

/* bits definitions for REG_AON_APB_APCPU_INT_ENABLE_CTRL7, [0x6490051C] */
#define BIT_AON_APB_APCPU_INT_ENABLE_CTRL7(x)               ( (x) )

/* bits definitions for REG_AON_APB_SDIO0_CTRL_REG, [0x64900520] */
#define BIT_AON_APB_SDIO0_EMMC_PROT_CLK_32K                 ( BIT(22) )
#define BIT_AON_APB_SDIO0_EMMC_CARD_PRESENT_32K             ( BIT(21) )
#define BIT_AON_APB_SDIO0_EMMC_CARD_PROTECT_32K             ( BIT(20) )
#define BIT_AON_APB_SDIO0_EMMC_BATTERY_PRESENT_32K          ( BIT(19) )
#define BIT_AON_APB_SDIO0_EMMC_BATTERY_DEB_EN_32K           ( BIT(18) )
#define BIT_AON_APB_SDIO0_EMMC_BATTERY_DBNC_THD_32K(x)      ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AON_APB_SDIO0_EMMC_BATTERY_DBNC_EN_32K          ( BIT(9) )
#define BIT_AON_APB_SDIO0_EMMC_CARDDET_DBNC_THD_32K(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AON_APB_SDIO0_EMMC_CARDDET_DBNC_EN_32K          ( BIT(0) )

/* bits definitions for REG_AON_APB_SDIO1_CTRL_REG, [0x64900524] */
#define BIT_AON_APB_SDIO1_EMMC_PROT_CLK_32K                 ( BIT(22) )
#define BIT_AON_APB_SDIO1_EMMC_CARD_PRESENT_32K             ( BIT(21) )
#define BIT_AON_APB_SDIO1_EMMC_CARD_PROTECT_32K             ( BIT(20) )
#define BIT_AON_APB_SDIO1_EMMC_BATTERY_PRESENT_32K          ( BIT(19) )
#define BIT_AON_APB_SDIO1_EMMC_BATTERY_DEB_EN_32K           ( BIT(18) )
#define BIT_AON_APB_SDIO1_EMMC_BATTERY_DBNC_THD_32K(x)      ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AON_APB_SDIO1_EMMC_BATTERY_DBNC_EN_32K          ( BIT(9) )
#define BIT_AON_APB_SDIO1_EMMC_CARDDET_DBNC_THD_32K(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AON_APB_SDIO1_EMMC_CARDDET_DBNC_EN_32K          ( BIT(0) )

/* bits definitions for REG_AON_APB_SDIO2_CTRL_REG, [0x64900528] */
#define BIT_AON_APB_SDIO2_EMMC_PROT_CLK_32K                 ( BIT(22) )
#define BIT_AON_APB_SDIO2_EMMC_CARD_PRESENT_32K             ( BIT(21) )
#define BIT_AON_APB_SDIO2_EMMC_CARD_PROTECT_32K             ( BIT(20) )
#define BIT_AON_APB_SDIO2_EMMC_BATTERY_PRESENT_32K          ( BIT(19) )
#define BIT_AON_APB_SDIO2_EMMC_BATTERY_DEB_EN_32K           ( BIT(18) )
#define BIT_AON_APB_SDIO2_EMMC_BATTERY_DBNC_THD_32K(x)      ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AON_APB_SDIO2_EMMC_BATTERY_DBNC_EN_32K          ( BIT(9) )
#define BIT_AON_APB_SDIO2_EMMC_CARDDET_DBNC_THD_32K(x)      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AON_APB_SDIO2_EMMC_CARDDET_DBNC_EN_32K          ( BIT(0) )

/* bits definitions for REG_AON_APB_EMMC_CTRL_REG, [0x6490052C] */
#define BIT_AON_APB_EMMC_EMMC_PROT_CLR_32K                  ( BIT(22) )
#define BIT_AON_APB_EMMC_EMMC_CARD_PRESENT_32K              ( BIT(21) )
#define BIT_AON_APB_EMMC_EMMC_CARD_PROTECT_32K              ( BIT(20) )
#define BIT_AON_APB_EMMC_EMMC_BATTERY_PRESENT_32K           ( BIT(19) )
#define BIT_AON_APB_EMMC_EMMC_BATTERY_DEB_EN_32K            ( BIT(18) )
#define BIT_AON_APB_EMMC_EMMC_BATTERY_DBNC_THD_32K(x)       ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AON_APB_EMMC_EMMC_BATTERY_DBNC_EN_32K           ( BIT(9) )
#define BIT_AON_APB_EMMC_EMMC_CARDDET_DBNC_THD_32K(x)       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AON_APB_EMMC_EMMC_CARDDET_DBNC_EN_32K           ( BIT(0) )

/* bits definitions for REG_AON_APB_WDG_RST_FLAG, [0x64900A24] */
#define BIT_AON_APB_ISE_WDG_RST_FLAG                        ( BIT(7) )
#define BIT_AON_APB_AP_WDG_RST_FLAG                         ( BIT(6) )
#define BIT_AON_APB_PSCP_WDG_RST_FLAG                       ( BIT(5) )
#define BIT_AON_APB_PHYCP_LTE_WDG_RST_FLAG                  ( BIT(4) )
#define BIT_AON_APB_CH_WDG_RST_FLAG                         ( BIT(3) )
#define BIT_AON_APB_AUDCP_WDG_RST_FLAG                      ( BIT(2) )
#define BIT_AON_APB_APCPU_WDG_RST_FLAG                      ( BIT(1) )
#define BIT_AON_APB_SEC_WDG_RST_FLAG                        ( BIT(0) )

/* bits definitions for REG_AON_APB_BOND_OPT0, [0x64900A3C] */
#define BIT_AON_APB_BOND_OPTION0(x)                         ( (x) )

/* bits definitions for REG_AON_APB_DEVICE_LIFE_CYCLE, [0x64900A40] */
#define BIT_AON_APB_BOND_OPTION1(x)                         ( (x) )

/* bits definitions for REG_AON_APB_RES_REG0, [0x64900A44] */
#define BIT_AON_APB_RES_REG0(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG1, [0x64900A48] */
#define BIT_AON_APB_RES_REG1(x)                             ( (x) )

/* bits definitions for REG_AON_APB_ANA_INT_POL_SEL, [0x64900A4C] */
#define BIT_AON_APB_ANA_INT_POL_SEL2                        ( BIT(2) )
#define BIT_AON_APB_ANA_INT_POL_SEL1                        ( BIT(1) )
#define BIT_AON_APB_ANA_INT_POL_SEL0                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_PROT_CFG, [0x64900A58] */
#define BIT_AON_APB_HPROT_DMAW(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_HPROT_DMAR(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_PLL_LOCK_OUT_SEL, [0x64900A64] */
#define BIT_AON_APB_REC_26MHZ_0_BUF_PD                      ( BIT(8) )
#define BIT_AON_APB_SLEEP_PLLLOCK_SEL                       ( BIT(7) )
#define BIT_AON_APB_PLL_LOCK_SEL(x)                         ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_APB_SLEEP_DBG_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_LEAKAGE_MAGIC_WORD, [0x64900B00] */
#define BIT_AON_APB_LEAKAGE_MAGIC_WORD(x)                   ( (x) )

/* bits definitions for REG_AON_APB_LEAKAGE_SWITCH, [0x64900B04] */
#define BIT_AON_APB_LEAKAGE_SWITCH                          ( BIT(0) )

/* bits definitions for REG_AON_APB_FUNC_TEST_BOOT_ADDR, [0x64900B10] */
#define BIT_AON_APB_FUNC_TEST_BOOT_ADDR(x)                  ( (x) )

/* bits definitions for REG_AON_APB_CGM_RESCUE, [0x64900B14] */
#define BIT_AON_APB_CGM_RESCUE(x)                           ( (x) )

/* bits definitions for REG_AON_APB_AON_SDIO, [0x64900B2C] */
#define BIT_AON_APB_SDIO2_SLICE_EN                          ( BIT(3) )
#define BIT_AON_APB_CP_SDIO_ENABLE                          ( BIT(2) )
#define BIT_AON_APB_AP_SDIO_ENABLE                          ( BIT(1) )
#define BIT_AON_APB_SDIO_MODULE_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_APB_ANALOG_PD_STATUS0, [0x64900B30] */
#define BIT_AON_APB_ANALOG_PD_STATUS0(x)                    ( (x) )

/* bits definitions for REG_AON_APB_ANALOG_PD_STATUS1, [0x64900B34] */
#define BIT_AON_APB_ANALOG_PD_STATUS1(x)                    ( (x) )

/* bits definitions for REG_AON_APB_ANALOG_PD_STATUS2, [0x64900B38] */
#define BIT_AON_APB_ANALOG_PD_STATUS2(x)                    ( (x) )

/* bits definitions for REG_AON_APB_CH_WAKEUP_MASK_EN0, [0x64900B80] */
#define BIT_AON_APB_CH_INT_REQ_WAKEUP_EN_LOW32B(x)          ( (x) )

/* bits definitions for REG_AON_APB_CH_WAKEUP_MASK_EN1, [0x64900B84] */
#define BIT_AON_APB_CH_INT_REQ_WAKEUP_EN_HIGH32B(x)         ( (x) )

/* bits definitions for REG_AON_APB_SP_WAKEUP_MASK_EN0, [0x64900B88] */
#define BIT_AON_APB_SP_INT_REQ_WAKEUP_EN_31_0B(x)           ( (x) )

/* bits definitions for REG_AON_APB_SP_WAKEUP_MASK_EN1, [0x64900B8C] */
#define BIT_AON_APB_SP_INT_REQ_WAKEUP_EN_63_32B(x)          ( (x) )

/* bits definitions for REG_AON_APB_SP_WAKEUP_MASK_EN2, [0x64900B90] */
#define BIT_AON_APB_SP_INT_REQ_WAKEUP_EN_NMI                ( BIT(31) )
#define BIT_AON_APB_SP_INT_REQ_WAKEUP_EN_94_64B(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )

/* bits definitions for REG_AON_APB_SDIO_EMMC_POWER_STATUS, [0x64900B9C] */
#define BIT_AON_APB_EMMC_LDO_POWER_OFF_DELAY                ( BIT(11) )
#define BIT_AON_APB_SDIO2_LDO_POWER_OFF_DELAY               ( BIT(10) )
#define BIT_AON_APB_SDIO1_LDO_POWER_OFF_DELAY               ( BIT(9) )
#define BIT_AON_APB_SDIO0_LDO_POWER_OFF_DELAY               ( BIT(8) )
#define BIT_AON_APB_EMMC_LDO_POWER_OFF                      ( BIT(7) )
#define BIT_AON_APB_SDIO2_LDO_POWER_OFF                     ( BIT(6) )
#define BIT_AON_APB_SDIO1_LDO_POWER_OFF                     ( BIT(5) )
#define BIT_AON_APB_SDIO0_LDO_POWER_OFF                     ( BIT(4) )
#define BIT_AON_APB_EMMC_IO_POWER_OFF                       ( BIT(3) )
#define BIT_AON_APB_SDIO2_IO_POWER_OFF                      ( BIT(2) )
#define BIT_AON_APB_SDIO1_IO_POWER_OFF                      ( BIT(1) )
#define BIT_AON_APB_SDIO0_IO_POWER_OFF                      ( BIT(0) )

/* bits definitions for REG_AON_APB_SDIO_EMMC_POWER_STATUS_1, [0x64900BA0] */
#define BIT_AON_APB_EMMC_BATTERY_RMLDO_EN                   ( BIT(7) )
#define BIT_AON_APB_EMMC_CARD_RMLDO_EN                      ( BIT(6) )
#define BIT_AON_APB_SDIO2_BATTERY_RMLDO_EN                  ( BIT(5) )
#define BIT_AON_APB_SDIO2_CARD_RMLDO_EN                     ( BIT(4) )
#define BIT_AON_APB_SDIO1_BATTERY_RMLDO_EN                  ( BIT(3) )
#define BIT_AON_APB_SDIO1_CARD_RMLDO_EN                     ( BIT(2) )
#define BIT_AON_APB_SDIO0_BATTERY_RMLDO_EN                  ( BIT(1) )
#define BIT_AON_APB_SDIO0_CARD_RMLDO_EN                     ( BIT(0) )

/* bits definitions for REG_AON_APB_SCC_DBG_BUS, [0x64900C00] */
#define BIT_AON_APB_SCC_DBG_BUS(x)                          ( (x) )

/* bits definitions for REG_AON_APB_AON_FUNC_CTRL_0, [0x64900C04] */
#define BIT_AON_APB_AON_FUNC_CTRL_0(x)                      ( (x) )

/* bits definitions for REG_AON_APB_AON_FUNC_CTRL_1, [0x64900C08] */
#define BIT_AON_APB_AON_FUNC_CTRL_1(x)                      ( (x) )

/* bits definitions for REG_AON_APB_DP_HPD, [0x64900C0C] */
#define BIT_AON_APB_DP_HPD                                  ( BIT(0) )

/* bits definitions for REG_AON_APB_RFSPI_CTRL, [0x64900C10] */
#define BIT_AON_APB_RFSPI_SEL_AON_RFSPI                     ( BIT(0) )

/* bits definitions for REG_AON_APB_UFSHC_CTRL, [0x64900C14] */
#define BIT_AON_APB_UFSHC_HCLK_EN                           ( BIT(7) )
#define BIT_AON_APB_UFSHC_PCLK_EN                           ( BIT(6) )
#define BIT_AON_APB_TX_SYMBOCLK_SEL                         ( BIT(5) )
#define BIT_AON_APB_RX_SYMBOCLK_1_SEL                       ( BIT(4) )
#define BIT_AON_APB_RX_SYMBOCLK_0_SEL                       ( BIT(3) )
#define BIT_AON_APB_LP_CG_CLK_TREQ_SW                       ( BIT(2) )
#define BIT_AON_APB_CG_CLK_TREQ_SW                          ( BIT(1) )

/* bits definitions for REG_AON_APB_PHYCP_FUNC_CTRL, [0x64900C18] */
#define BIT_AON_APB_PHYCP_FUNC_CTRL(x)                      ( (x) )

/* bits definitions for REG_AON_APB_MIPI_DSI8_CTRL, [0x64900C30] */
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_AOD_EN_M             ( BIT(13) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_AOD_PD_M             ( BIT(12) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_AOD_MOD_M(x)         ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_HL_P_M               ( BIT(8) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_HL_N_M               ( BIT(7) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_AOD_EN_S             ( BIT(6) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_AOD_PD_S             ( BIT(5) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_AOD_MOD_S(x)         ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_HL_P_S               ( BIT(1) )
#define BIT_AON_APB_MIPI_DSI_8LANE_DSI_HL_N_S               ( BIT(0) )

/* bits definitions for REG_AON_APB_RPLL_CTRL_REG0, [0x64900C34] */
#define BIT_AON_APB_RPLL_CP_OFFSET_REG(x)                   ( (x) << 29 & (BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_RPLL_LDO_TRIM_REG(x)                    ( (x) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AON_APB_RPLL_ICP_REG(x)                         ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AON_APB_RPLL_REF_SEL_REG(x)                     ( (x) << 19 & (BIT(19)|BIT(20)) )
#define BIT_AON_APB_RPLL_LPF_REG(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_AON_APB_RPLL_RESERVED_REG(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_RPLL_CTRL_REG1, [0x64900C38] */
#define BIT_AON_APB_RPLL_SSC_CTRL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_RPLL_CTRL_REG2, [0x64900C3C] */
#define BIT_AON_APB_RPLL_POSTDIV_REG(x)                     ( (x) << 21 & (BIT(21)|BIT(22)) )
#define BIT_AON_APB_RPLL_26M_DIV_REG(x)                     ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AON_APB_RPLL_N_REG(x)                           ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AON_APB_RPLL_DIV_S_REG                          ( BIT(2) )
#define BIT_AON_APB_RPLL_MOD_EN_REG                         ( BIT(1) )
#define BIT_AON_APB_RPLL_SDM_EN_REG                         ( BIT(0) )

/* bits definitions for REG_AON_APB_RPLL_CTRL_REG3, [0x64900C40] */
#define BIT_AON_APB_RPLL_KINT_REG(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_APB_RPLL_NINT_REG(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_RPLL_CTRL_ARRAY_SEL, [0x64900C48] */
#define BIT_AON_APB_RPLL_CTRL_ARRARY_SEL_BB_SW              ( BIT(16) )
#define BIT_AON_APB_RPLL_CTRL_ARRARY_SEL_AON_APB            ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_CP_TW_CTRL, [0x64900C50] */
#define BIT_AON_APB_PSCP_CP_TW_CTL                          ( BIT(1) )
#define BIT_AON_APB_PSCP_CP_TW_BUS_CTRL                     ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_BOOT_VECTOR, [0x64900C54] */
#define BIT_AON_APB_PSCP_BOOT_VECTOR_16_10(x)               ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL0, [0x64900C60] */
#define BIT_AON_APB_AON_APB_CGM_GATE_AUTO_SEL0(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL1, [0x64900C64] */
#define BIT_AON_APB_AON_APB_CGM_GATE_AUTO_SEL1(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL2, [0x64900C68] */
#define BIT_AON_APB_AON_APB_CGM_GATE_AUTO_SEL2(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_AUTO_SEL3, [0x64900C6C] */
#define BIT_AON_APB_AON_APB_CGM_GATE_AUTO_SEL3(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN0, [0x64900C70] */
#define BIT_AON_APB_AON_APB_CGM_GATE_FORCE_EN0(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN1, [0x64900C74] */
#define BIT_AON_APB_AON_APB_CGM_GATE_FORCE_EN1(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN2, [0x64900C78] */
#define BIT_AON_APB_AON_APB_CGM_GATE_FORCE_EN2(x)           ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_CGM_GATE_FORCE_EN3, [0x64900C7C] */
#define BIT_AON_APB_AON_APB_CGM_GATE_FORCE_EN3(x)           ( (x) )

/* bits definitions for REG_AON_APB_GLB_BUS_CGM_GATE_AUTO_SEL, [0x64900C80] */
#define BIT_AON_APB_GLB_BUS_CGM_GATE_AUTO_SEL(x)            ( (x) )

/* bits definitions for REG_AON_APB_GLB_BUS_CGM_GATE_FORCE_EN, [0x64900C84] */
#define BIT_AON_APB_GLB_BUS_CGM_GATE_FORCE_EN(x)            ( (x) )

/* bits definitions for REG_AON_APB_RC6M_CFG0, [0x64900C88] */
#define BIT_AON_APB_CAL6M_MODE_SEL                          ( BIT(30) )
#define BIT_AON_APB_RTC6M_CAL_CTL(x)                        ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_RTC6M_CAL_SEL                           ( BIT(21) )
#define BIT_AON_APB_RTC6M_CAL_PRECISION(x)                  ( (x) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AON_APB_RC6M_DIV(x)                             ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AON_APB_RC6M_CAL_DONE                           ( BIT(6) )
#define BIT_AON_APB_RC6M_CAL_START                          ( BIT(5) )
#define BIT_AON_APB_RC6M_ANA_SOFT_RST                       ( BIT(4) )
#define BIT_AON_APB_RF6M_CLK_DISABLE_TIME(x)                ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_RC6M_FORCE_EN                           ( BIT(1) )
#define BIT_AON_APB_RC6M_AUTO_GATE_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_RC6M_CFG1, [0x64900C8C] */
#define BIT_AON_APB_CAL_RCO6M_AUTO_GATE_EN                  ( BIT(19) )
#define BIT_AON_APB_RF6M_AUTO_CAL_INTERVAL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_AON_APB_RC60M_CFG0, [0x64900C90] */
#define BIT_AON_APB_CAL60M_MODE_SEL                         ( BIT(30) )
#define BIT_AON_APB_RTC60M_CAL_CTL(x)                       ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_RTC60M_CAL_SEL                          ( BIT(21) )
#define BIT_AON_APB_RTC60M_CAL_PRECISION(x)                 ( (x) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AON_APB_RC60M_DIV(x)                            ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AON_APB_RC60M_CAL_DONE                          ( BIT(6) )
#define BIT_AON_APB_RC60M_CAL_START                         ( BIT(5) )
#define BIT_AON_APB_RC60M_ANA_SOFT_RST                      ( BIT(4) )
#define BIT_AON_APB_RF60M_CLK_DISABLE_TIME(x)               ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_RC60M_FORCE_EN                          ( BIT(1) )
#define BIT_AON_APB_RC60M_AUTO_GATE_EN                      ( BIT(0) )

/* bits definitions for REG_AON_APB_RC60M_CFG1, [0x64900C94] */
#define BIT_AON_APB_RF60M_AUTO_CAL_INTERVAL(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_AON_APB_DDCPLL_CTRL, [0x64900C98] */
#define BIT_AON_APB_DDCPLL_CLKOUT_EN                        ( BIT(1) )
#define BIT_AON_APB_DDCPLL_DIV32_EN                         ( BIT(0) )

/* bits definitions for REG_AON_APB_URGENCY_REG, [0x64900C9C] */
#define BIT_AON_APB_M9_ARURGENCY1                           ( BIT(11) )
#define BIT_AON_APB_M9_AWURGENCY1                           ( BIT(10) )
#define BIT_AON_APB_M9_ARURGENCY0                           ( BIT(9) )
#define BIT_AON_APB_M9_AWURGENCY0                           ( BIT(8) )
#define BIT_AON_APB_M7_ARURGENCY1                           ( BIT(7) )
#define BIT_AON_APB_M7_AWURGENCY1                           ( BIT(6) )
#define BIT_AON_APB_M7_ARURGENCY0                           ( BIT(5) )
#define BIT_AON_APB_M7_AWURGENCY0                           ( BIT(4) )
#define BIT_AON_APB_M5_ARURGENCY1                           ( BIT(3) )
#define BIT_AON_APB_M5_AWURGENCY1                           ( BIT(2) )
#define BIT_AON_APB_M5_ARURGENCY0                           ( BIT(1) )
#define BIT_AON_APB_M5_AWURGENCY0                           ( BIT(0) )

/* bits definitions for REG_AON_APB_AQOS_REG, [0x64900CA0] */
#define BIT_AON_APB_M9_AWQOS3                               ( BIT(23) )
#define BIT_AON_APB_M9_ARQOS3                               ( BIT(22) )
#define BIT_AON_APB_M9_AWQOS2                               ( BIT(21) )
#define BIT_AON_APB_M9_ARQOS2                               ( BIT(20) )
#define BIT_AON_APB_M9_AWQOS1                               ( BIT(19) )
#define BIT_AON_APB_M9_ARQOS1                               ( BIT(18) )
#define BIT_AON_APB_M9_AWQOS0                               ( BIT(17) )
#define BIT_AON_APB_M9_ARQOS0                               ( BIT(16) )
#define BIT_AON_APB_M7_AWQOS3                               ( BIT(15) )
#define BIT_AON_APB_M7_ARQOS3                               ( BIT(14) )
#define BIT_AON_APB_M7_AWQOS2                               ( BIT(13) )
#define BIT_AON_APB_M7_ARQOS2                               ( BIT(12) )
#define BIT_AON_APB_M7_AWQOS1                               ( BIT(11) )
#define BIT_AON_APB_M7_ARQOS1                               ( BIT(10) )
#define BIT_AON_APB_M7_AWQOS0                               ( BIT(9) )
#define BIT_AON_APB_M7_ARQOS0                               ( BIT(8) )
#define BIT_AON_APB_M5_AWQOS3                               ( BIT(7) )
#define BIT_AON_APB_M5_ARQOS3                               ( BIT(6) )
#define BIT_AON_APB_M5_AWQOS2                               ( BIT(5) )
#define BIT_AON_APB_M5_ARQOS2                               ( BIT(4) )
#define BIT_AON_APB_M5_AWQOS1                               ( BIT(3) )
#define BIT_AON_APB_M5_ARQOS1                               ( BIT(2) )
#define BIT_AON_APB_M5_AWQOS0                               ( BIT(1) )
#define BIT_AON_APB_M5_ARQOS0                               ( BIT(0) )

/* bits definitions for REG_AON_APB_RC150M_CFG0, [0x64900CA4] */
#define BIT_AON_APB_RC150M_CAL_DONE                         ( BIT(5) )
#define BIT_AON_APB_RC150M_CAL_START                        ( BIT(4) )

/* bits definitions for REG_AON_APB_RC100M_CFG1, [0x64900CA8] */
#define BIT_AON_APB_RF100M_AUTO_CAL_INTERVAL(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_AON_APB_PHY_CR8_REG, [0x64900CB0] */
#define BIT_AON_APB_PHY_CR8_MFILTEREN                       ( BIT(14) )
#define BIT_AON_APB_PHY_CR8_CORE_SW_RST(x)                  ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_APB_PHY_CR8_BLK_SW_RST                      ( BIT(11) )
#define BIT_AON_APB_PHY_CR8_CORE_DBG_SW_RST(x)              ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_AON_APB_PHY_CR8_BLK_DBG_SW_RST                  ( BIT(8) )
#define BIT_AON_APB_PHY_CR8_CFG_ENDIAN(x)                   ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AON_APB_PHY_CR8_CFG_NMFI(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_APB_PHY_CR8_VINITHI(x)                      ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_PHY_CR8_TEINIT(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_FORCE_DIVN_ON, [0x64900CB4] */
#define BIT_AON_APB_FORCE_DIVN_ON                           ( BIT(0) )

/* bits definitions for REG_AON_APB_PHY_CP_TW_REG, [0x64900CC0] */
#define BIT_AON_APB_PHY_CP_TW_BUS_CTL                       ( BIT(1) )
#define BIT_AON_APB_PHY_CP_TW_CTL                           ( BIT(0) )

/* bits definitions for REG_AON_APB_PHY_CP_ROBU_CLK_CTRL, [0x64900CC4] */
#define BIT_AON_APB_PHY_CP_ROBU_CLK_PLUS_EB                 ( BIT(17) )
#define BIT_AON_APB_PHY_CP_ROBU_CLK_SET_EB                  ( BIT(16) )
#define BIT_AON_APB_PHY_CP_ROBU_CLK_CTRL_WIDTH(x)           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_PS_CP_ROBU_CLK_CTRL, [0x64900CC8] */
#define BIT_AON_APB_PS_CP_ROBU_CLK_PLUS_EB                  ( BIT(17) )
#define BIT_AON_APB_PS_CP_ROBU_CLK_SET_EB                   ( BIT(16) )
#define BIT_AON_APB_PS_CP_ROBU_CLK_CTRL_WIDTH(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_PHYCP_CGM_XO_EB, [0x64900CD0] */
#define BIT_AON_APB_PHYCP_CGM_XO_EB                         ( BIT(0) )

/* bits definitions for REG_AON_APB_DDC_CTRL_EB, [0x64900CD4] */
#define BIT_AON_APB_DDC_CTRL_EB                             ( BIT(1) )
#define BIT_AON_APB_DDC_ANALOG_EB                           ( BIT(0) )

/* bits definitions for REG_AON_APB_IPA_ACCESS_CFG, [0x64900CD8] */
#define BIT_AON_APB_AON_ACCESS_PCIE_EN                      ( BIT(1) )
#define BIT_AON_APB_AON_TO_IPA_ACCESS_EN                    ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_TMR_RST, [0x64900CE0] */
#define BIT_AON_APB_AP_TMR22_SOFT_RST                       ( BIT(14) )
#define BIT_AON_APB_AP_TMR21_SOFT_RST                       ( BIT(13) )
#define BIT_AON_APB_AP_TMR20_SOFT_RST                       ( BIT(12) )
#define BIT_AON_APB_AP_TMR12_SOFT_RST                       ( BIT(11) )
#define BIT_AON_APB_AP_TMR11_SOFT_RST                       ( BIT(10) )
#define BIT_AON_APB_AP_TMR10_SOFT_RST                       ( BIT(9) )
#define BIT_AON_APB_AP_TMR02_SOFT_RST                       ( BIT(8) )
#define BIT_AON_APB_AP_TMR01_SOFT_RST                       ( BIT(7) )
#define BIT_AON_APB_AP_TMR00_SOFT_RST                       ( BIT(6) )
#define BIT_AON_APB_PSCP_TMR2_SOFT_RST                      ( BIT(5) )
#define BIT_AON_APB_PSCP_TMR1_SOFT_RST                      ( BIT(4) )
#define BIT_AON_APB_PSCP_TMR0_SOFT_RST                      ( BIT(3) )
#define BIT_AON_APB_AON_TMR2_SOFT_RST                       ( BIT(2) )
#define BIT_AON_APB_AON_TMR1_SOFT_RST                       ( BIT(1) )
#define BIT_AON_APB_AON_TMR0_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_AON_APB_RCO150M_TEST_FR_EN, [0x64900CE4] */
#define BIT_AON_APB_RCO150M_TEST_FR_EN                      ( BIT(0) )

/* bits definitions for REG_AON_APB_UFSDEV_REG, [0x64900CE8] */
#define BIT_AON_APB_UFSDEV_REFCLK_EN_SEL_SW                 ( BIT(2) )
#define BIT_AON_APB_UFSDEV_REFCLK_EN                        ( BIT(1) )
#define BIT_AON_APB_UFSDEV_SOFT_RST                         ( BIT(0) )

/* bits definitions for REG_AON_APB_RST_ASYNCB_REG, [0x64900CEC] */
#define BIT_AON_APB_RST_ASYNCB_APB_SOFT                     ( BIT(0) )

/* bits definitions for REG_AON_APB_BUSMON_EB_AON_MAIN_MTX, [0x64900CF0] */
#define BIT_AON_APB_BUSMON_EB_AON_MAIN_MTX                  ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_CR8_LOW_POWER_DEBUG, [0x64900CF4] */
#define BIT_AON_APB_PSCP_CR8_LOW_POWER_DEBUG(x)             ( (x) )

/* bits definitions for REG_AON_APB_PHYCP_CR8_LOW_POWER_DEBUG, [0x64900CF8] */
#define BIT_AON_APB_PHYCP_CR8_LOW_POWER_DEBUG(x)            ( (x) )

/* bits definitions for REG_AON_APB_USB31PLL_CTRL_MISC, [0x64900CFC] */
#define BIT_AON_APB_REG_ANALOG_USB31PLLV_REF2USB20_EN       ( BIT(3) )
#define BIT_AON_APB_REG_ANALOG_USB31PLLV_REF2USB3_EN        ( BIT(2) )
#define BIT_AON_APB_REG_ANALOG_USB31PLLV_REF2UFS_DEVICE_EN  ( BIT(1) )
#define BIT_AON_APB_REG_ANALOG_USB31PLLV_REF2MPHY_EN        ( BIT(0) )

/* bits definitions for REG_AON_APB_RFFE_MUX_PHYCP_AON_0_REG, [0x64900D00] */
#define BIT_AON_APB_SEL_RFFE_SDA_OUT(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_SEL_RFFE_SDA_OE(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_SEL_RFFE_SDA_IE(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_SEL_RFFE_SDA_IN(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_RFFE_MUX_PHYCP_AON_1_REG, [0x64900D04] */
#define BIT_AON_APB_SEL_RFFE_SCK_OUT(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_PHYCP_DBG_FRC_ON, [0x64900D08] */
#define BIT_AON_APB_DBG_APB_FRC_ON                          ( BIT(1) )
#define BIT_AON_APB_DBG_ATB_FRC_ON                          ( BIT(0) )

/* bits definitions for REG_AON_APB_LVDS_PHY_EN, [0x64900D0C] */
#define BIT_AON_APB_LVDS_PHY_EN                             ( BIT(0) )

/* bits definitions for REG_AON_APB_USB31_CTRL, [0x64900D10] */
#define BIT_AON_APB_USB31_CONNECT_STATE_U3PMU               ( BIT(7) )
#define BIT_AON_APB_USB31_CONNECT_STATE_U2PMU               ( BIT(6) )
#define BIT_AON_APB_U3PMU_DISABLE                           ( BIT(5) )
#define BIT_AON_APB_U2PMU_DISABLE                           ( BIT(4) )
#define BIT_AON_APB_HOST_U3_PORT_DISABLE                    ( BIT(3) )
#define BIT_AON_APB_POWERPRESET_VALID                       ( BIT(2) )
#define BIT_AON_APB_VBUSVALID_VALID                         ( BIT(1) )
#define BIT_AON_APB_HOST_U2_PORT_DISABLE                    ( BIT(0) )

/* bits definitions for REG_AON_APB_USB31DPCOMBPHY_CTRL, [0x64900D14] */
#define BIT_AON_APB_SYS_VBUSVALID                           ( BIT(2) )
#define BIT_AON_APB_PHY_TEST_POWERDOWN                      ( BIT(1) )
#define BIT_AON_APB_PG_MODE_EN                              ( BIT(0) )

/* bits definitions for REG_AON_APB_AUD_ADDX_SEL, [0x64900D18] */
#define BIT_AON_APB_AUD_ADDX_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_APB_AXI_LP_CTRL_DISABLE, [0x64900D1C] */
#define BIT_AON_APB_AXI_LP_CTRL_DISABLE                     ( BIT(0) )

/* bits definitions for REG_AON_APB_AUX3_CTRL, [0x64900D20] */
#define BIT_AON_APB_AUX3_MUX(x)                             ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_AUX3_DIVN(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_LCM_RSTN, [0x64900D24] */
#define BIT_AON_APB_LCM1_RSTN                               ( BIT(1) )
#define BIT_AON_APB_LCM0_RSTN                               ( BIT(0) )

/* bits definitions for REG_AON_APB_ACCESS_EN_REG, [0x64900D28] */
#define BIT_AON_APB_APCPU_AP_ACCESS_EN                      ( BIT(1) )
#define BIT_AON_APB_CH_AP_ACCESS_EN                         ( BIT(0) )

/* bits definitions for REG_AON_APB_ANLG_PHY_G12, [0x64900D2C] */
#define BIT_AON_APB_ATE_TEST_SEL                            ( BIT(1) )
#define BIT_AON_APB_CR_PARA_SEL                             ( BIT(0) )

/* bits definitions for REG_AON_APB_CDMA_INT_REQ_ENABLE, [0x64900D30] */
#define BIT_AON_APB_INT_REQ_DO_SLP_EB                       ( BIT(1) )
#define BIT_AON_APB_INT_REQ_1X_SLP_EB                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PSCP_SIM1_CTRL, [0x64900D34] */
#define BIT_AON_APB_PSCP_SIM2_CTRL                          ( BIT(1) )
#define BIT_AON_APB_PSCP_SIM1_CTRL                          ( BIT(0) )

/* bits definitions for REG_AON_APB_BW_VOTE_CTRL, [0x64900D38] */
#define BIT_AON_APB_DPU1_BW_VOTE_CTRL                       ( BIT(1) )
#define BIT_AON_APB_DPU0_BW_VOTE_CTRL                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PUB_CFG_EARLY_RESP_CTRL, [0x64900D3C] */
#define BIT_AON_APB_AON2PUB_TRANS_IDLE                      ( BIT(1) )
#define BIT_AON_APB_PUB_CFG_EARLY_RESP_EN                   ( BIT(0) )

/* bits definitions for REG_AON_APB_RESERVE_H, [0x64900FE8] */
#define BIT_AON_APB_RESERVE_H(x)                            ( (x) )

/* bits definitions for REG_AON_APB_RESERVE_L, [0x64900FEC] */
#define BIT_AON_APB_RESERVE_L(x)                            ( (x) )

/* vars definitions for controller CTL_AON_APB */


#endif /* __AON_APB_H____ */
