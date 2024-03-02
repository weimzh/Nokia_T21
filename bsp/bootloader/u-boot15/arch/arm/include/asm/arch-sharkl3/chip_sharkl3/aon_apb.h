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
#define CTL_AON_APB_BASE                SCI_IOMAP(0x402E0000)
#endif

/* registers definitions for CTL_AON_APB, 0x402E0000 */
#define REG_AON_APB_APB_EB0                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0000)
#define REG_AON_APB_APB_EB1                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0004)
#define REG_AON_APB_APB_RST0                                SCI_ADDR(CTL_AON_APB_BASE, 0x0008)
#define REG_AON_APB_APB_RST1                                SCI_ADDR(CTL_AON_APB_BASE, 0x000C)
#define REG_AON_APB_APB_RTC_EB                              SCI_ADDR(CTL_AON_APB_BASE, 0x0010)
#define REG_AON_APB_REC_26MHZ_BUF_CFG                       SCI_ADDR(CTL_AON_APB_BASE, 0x0014)
#define REG_AON_APB_SINDRV_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x0018)
#define REG_AON_APB_ADA_SEL_CTRL                            SCI_ADDR(CTL_AON_APB_BASE, 0x001C)
#define REG_AON_APB_VBC_CTRL                                SCI_ADDR(CTL_AON_APB_BASE, 0x0020)
#define REG_AON_APB_PWR_CTRL                                SCI_ADDR(CTL_AON_APB_BASE, 0x0024)
#define REG_AON_APB_TS_CFG                                  SCI_ADDR(CTL_AON_APB_BASE, 0x0028)
#define REG_AON_APB_BOOT_MODE                               SCI_ADDR(CTL_AON_APB_BASE, 0x002C)
#define REG_AON_APB_BB_BG_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0030)
#define REG_AON_APB_CP_ARM_JTAG_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0034)
#define REG_AON_APB_PLL_SOFT_CNT_DONE                       SCI_ADDR(CTL_AON_APB_BASE, 0x0038)
#define REG_AON_APB_DCXO_LC_REG0                            SCI_ADDR(CTL_AON_APB_BASE, 0x003C)
#define REG_AON_APB_DCXO_LC_REG1                            SCI_ADDR(CTL_AON_APB_BASE, 0x0040)
#define REG_AON_APB_AON_CLK_TOP_CFG                         SCI_ADDR(CTL_AON_APB_BASE, 0x0050)
#define REG_AON_APB_SP_SYS_MODULE_EN                        SCI_ADDR(CTL_AON_APB_BASE, 0x0054)
#define REG_AON_APB_CLK_LPF_SEC_REG                         SCI_ADDR(CTL_AON_APB_BASE, 0x0058)
#define REG_AON_APB_LVDSRFPLL_CFG1                          SCI_ADDR(CTL_AON_APB_BASE, 0x0064)
#define REG_AON_APB_LVDSRFPLL_CFG2                          SCI_ADDR(CTL_AON_APB_BASE, 0x0068)
#define REG_AON_APB_AON_REG_PROT                            SCI_ADDR(CTL_AON_APB_BASE, 0x006C)
#define REG_AON_APB_DSI_PHY_CTRL                            SCI_ADDR(CTL_AON_APB_BASE, 0x0070)
#define REG_AON_APB_CSI_2L_PHY_CTRL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0074)
#define REG_AON_APB_CSI_2P2L_S_PHY_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0078)
#define REG_AON_APB_CSI_2P2L_M_PHY_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x007C)
#define REG_AON_APB_CSI_2P2L_DBG_PHY_CTRL                   SCI_ADDR(CTL_AON_APB_BASE, 0x0080)
#define REG_AON_APB_CSI_2P2L_PHY_CTRL                       SCI_ADDR(CTL_AON_APB_BASE, 0x0084)
#define REG_AON_APB_AON_CGM_CFG0                            SCI_ADDR(CTL_AON_APB_BASE, 0x0088)
#define REG_AON_APB_AON_CGM_CFG1                            SCI_ADDR(CTL_AON_APB_BASE, 0x008C)
#define REG_AON_APB_CA53_AUTO_CLKCTRL_DIS                   SCI_ADDR(CTL_AON_APB_BASE, 0x0090)
#define REG_AON_APB_SOFT_DFS_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x00A0)
#define REG_AON_APB_HARD_DFS_CTRL_LO                        SCI_ADDR(CTL_AON_APB_BASE, 0x00A4)
#define REG_AON_APB_HARD_DFS_CTRL_HI                        SCI_ADDR(CTL_AON_APB_BASE, 0x00A8)
#define REG_AON_APB_APB_EB3                                 SCI_ADDR(CTL_AON_APB_BASE, 0x00AC)
#define REG_AON_APB_APB_EB2                                 SCI_ADDR(CTL_AON_APB_BASE, 0x00B0)
#define REG_AON_APB_ROSC_CFG                                SCI_ADDR(CTL_AON_APB_BASE, 0x00C0)
#define REG_AON_APB_ROSC_STATUS                             SCI_ADDR(CTL_AON_APB_BASE, 0x00C4)
#define REG_AON_APB_APB_EB4                                 SCI_ADDR(CTL_AON_APB_BASE, 0x00D0)
#define REG_AON_APB_APB_RST4                                SCI_ADDR(CTL_AON_APB_BASE, 0x00D4)
#define REG_AON_APB_GPIO_CFG_SEL                            SCI_ADDR(CTL_AON_APB_BASE, 0x00D8)
#define REG_AON_APB_SP_CFG_BUS                              SCI_ADDR(CTL_AON_APB_BASE, 0x00DC)
#define REG_AON_APB_AON_CHIP_ID0                            SCI_ADDR(CTL_AON_APB_BASE, 0x00E0)
#define REG_AON_APB_AON_CHIP_ID1                            SCI_ADDR(CTL_AON_APB_BASE, 0x00E4)
#define REG_AON_APB_AON_PLAT_ID0                            SCI_ADDR(CTL_AON_APB_BASE, 0x00E8)
#define REG_AON_APB_AON_PLAT_ID1                            SCI_ADDR(CTL_AON_APB_BASE, 0x00EC)
#define REG_AON_APB_AON_IMPL_ID                             SCI_ADDR(CTL_AON_APB_BASE, 0x00F0)
#define REG_AON_APB_AON_MFT_ID                              SCI_ADDR(CTL_AON_APB_BASE, 0x00F4)
#define REG_AON_APB_AON_VER_ID                              SCI_ADDR(CTL_AON_APB_BASE, 0x00F8)
#define REG_AON_APB_AON_CHIP_ID                             SCI_ADDR(CTL_AON_APB_BASE, 0x00FC)
#define REG_AON_APB_CCIR_RCVR_CFG                           SCI_ADDR(CTL_AON_APB_BASE, 0x0100)
#define REG_AON_APB_PLL_BG_CFG                              SCI_ADDR(CTL_AON_APB_BASE, 0x0108)
#define REG_AON_APB_LVDSDIS_SEL                             SCI_ADDR(CTL_AON_APB_BASE, 0x010C)
#define REG_AON_APB_DJTAG_MUX_SEL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0110)
#define REG_AON_APB_ARM7_SYS_SOFT_RST                       SCI_ADDR(CTL_AON_APB_BASE, 0x0114)
#define REG_AON_APB_PUBCP_WTLCP_ADDR_MSB                    SCI_ADDR(CTL_AON_APB_BASE, 0x0118)
#define REG_AON_APB_AON_DMA_INT_EN                          SCI_ADDR(CTL_AON_APB_BASE, 0x011C)
#define REG_AON_APB_EMC_AUTO_GATE_EN                        SCI_ADDR(CTL_AON_APB_BASE, 0x0120)
#define REG_AON_APB_ARM7_CFG_BUS                            SCI_ADDR(CTL_AON_APB_BASE, 0x0124)
#define REG_AON_APB_RTC4M_0_CFG                             SCI_ADDR(CTL_AON_APB_BASE, 0x0128)
#define REG_AON_APB_RTC4M_1_CFG                             SCI_ADDR(CTL_AON_APB_BASE, 0x012C)
#define REG_AON_APB_APB_RST2                                SCI_ADDR(CTL_AON_APB_BASE, 0x0130)
#define REG_AON_APB_CLK_EB0                                 SCI_ADDR(CTL_AON_APB_BASE, 0x0134)
#define REG_AON_APB_AON_SDIO                                SCI_ADDR(CTL_AON_APB_BASE, 0x0138)
#define REG_AON_APB_MPLL_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x013C)
#define REG_AON_APB_BMPLL_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0140)
#define REG_AON_APB_RPLL_CFG1                               SCI_ADDR(CTL_AON_APB_BASE, 0x0158)
#define REG_AON_APB_RPLL_CFG2                               SCI_ADDR(CTL_AON_APB_BASE, 0x015C)
#define REG_AON_APB_RPLL_CFG3                               SCI_ADDR(CTL_AON_APB_BASE, 0x0160)
#define REG_AON_APB_THM0_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0164)
#define REG_AON_APB_THM1_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0168)
#define REG_AON_APB_BUSMON_DMA_CFG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0170)
#define REG_AON_APB_ANALOG_CFG1                             SCI_ADDR(CTL_AON_APB_BASE, 0x0178)
#define REG_AON_APB_RPLL_BIST_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x017C)
#define REG_AON_APB_DPLL_CTRL                               SCI_ADDR(CTL_AON_APB_BASE, 0x0194)
#define REG_AON_APB_CP_DAP_PAD_CTRL                         SCI_ADDR(CTL_AON_APB_BASE, 0x0200)
#define REG_AON_APB_CA53_PROT_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0204)
#define REG_AON_APB_CSSYS_CFG                               SCI_ADDR(CTL_AON_APB_BASE, 0x0208)
#define REG_AON_APB_SEC_MUX_DBG_EN                          SCI_ADDR(CTL_AON_APB_BASE, 0x020C)
#define REG_AON_APB_CR5_PROT_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0210)
#define REG_AON_APB_DBG_DJTAG_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0214)
#define REG_AON_APB_CCI_PROT_CTRL                           SCI_ADDR(CTL_AON_APB_BASE, 0x0218)
#define REG_AON_APB_CA53_COMM_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x021C)
#define REG_AON_APB_DESPLL_CFG1                             SCI_ADDR(CTL_AON_APB_BASE, 0x0220)
#define REG_AON_APB_WTLCP_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0240)
#define REG_AON_APB_WTL_WCDMA_EB                            SCI_ADDR(CTL_AON_APB_BASE, 0x0244)
#define REG_AON_APB_WTLCP_LDSP_CTRL0                        SCI_ADDR(CTL_AON_APB_BASE, 0x0248)
#define REG_AON_APB_WTLCP_LDSP_CTRL1                        SCI_ADDR(CTL_AON_APB_BASE, 0x024C)
#define REG_AON_APB_WTLCP_TDSP_CTRL0                        SCI_ADDR(CTL_AON_APB_BASE, 0x0250)
#define REG_AON_APB_WTLCP_TDSP_CTRL1                        SCI_ADDR(CTL_AON_APB_BASE, 0x0254)
#define REG_AON_APB_GPU_IOJTAG_CTRL0                        SCI_ADDR(CTL_AON_APB_BASE, 0x025C)
#define REG_AON_APB_PCP_AON_EB                              SCI_ADDR(CTL_AON_APB_BASE, 0x0280)
#define REG_AON_APB_PCP_SOFT_RST                            SCI_ADDR(CTL_AON_APB_BASE, 0x0284)
#define REG_AON_APB_PUBCP_CTRL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0288)
#define REG_AON_APB_MDAR_HSDL_CFG                           SCI_ADDR(CTL_AON_APB_BASE, 0x02B4)
#define REG_AON_APB_SUBSYS_DBG_CFG                          SCI_ADDR(CTL_AON_APB_BASE, 0x02BC)
#define REG_AON_APB_AP_LPC_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x02C0)
#define REG_AON_APB_WTLCP_LPC_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x02C4)
#define REG_AON_APB_PUBCP_LPC_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x02C8)
#define REG_AON_APB_WCN_LPC_CTRL                            SCI_ADDR(CTL_AON_APB_BASE, 0x02CC)
#define REG_AON_APB_MDAR_SOFT_RST                           SCI_ADDR(CTL_AON_APB_BASE, 0x02D0)
#define REG_AON_APB_GLB_WCDMA_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0300)
#define REG_AON_APB_PLL_CLKOUT_GATE                         SCI_ADDR(CTL_AON_APB_BASE, 0x0400)
#define REG_AON_APB_HM_CFG_SEL                              SCI_ADDR(CTL_AON_APB_BASE, 0x0404)
#define REG_AON_APB_HM_PWR_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x0408)
#define REG_AON_APB_HM_RST_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x040C)
#define REG_AON_APB_M_AAPC_CFG                              SCI_ADDR(CTL_AON_APB_BASE, 0x0420)
#define REG_AON_APB_DAP_DJTAG_CTRL                          SCI_ADDR(CTL_AON_APB_BASE, 0x0430)
#define REG_AON_APB_CGM_REG1                                SCI_ADDR(CTL_AON_APB_BASE, 0x0440)
#define REG_AON_APB_TOP_LPC0                                SCI_ADDR(CTL_AON_APB_BASE, 0x0500)
#define REG_AON_APB_TOP_LPC1                                SCI_ADDR(CTL_AON_APB_BASE, 0x0504)
#define REG_AON_APB_TOP_LPC2                                SCI_ADDR(CTL_AON_APB_BASE, 0x0508)
#define REG_AON_APB_TOP_LPC3                                SCI_ADDR(CTL_AON_APB_BASE, 0x050C)
#define REG_AON_APB_OVERHEAT_RST_CTRL                       SCI_ADDR(CTL_AON_APB_BASE, 0x0510)
#define REG_AON_APB_TOP_LPC4                                SCI_ADDR(CTL_AON_APB_BASE, 0x0520)
#define REG_AON_APB_TOP_LPC5                                SCI_ADDR(CTL_AON_APB_BASE, 0x0524)
#define REG_AON_APB_TOP_LPC6                                SCI_ADDR(CTL_AON_APB_BASE, 0x0528)
#define REG_AON_APB_TOP_LPC7                                SCI_ADDR(CTL_AON_APB_BASE, 0x052C)
#define REG_AON_APB_PUBCP_SIM0_TOP_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0540)
#define REG_AON_APB_PUBCP_SIM1_TOP_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0544)
#define REG_AON_APB_PUBCP_SIM2_TOP_CTRL                     SCI_ADDR(CTL_AON_APB_BASE, 0x0548)
#define REG_AON_APB_AP_SIM_TOP_CTRL                         SCI_ADDR(CTL_AON_APB_BASE, 0x054C)
#define REG_AON_APB_WCN_DIG_IN_CLK_SEL                      SCI_ADDR(CTL_AON_APB_BASE, 0x0570)
#define REG_AON_APB_A53_CTRL_0                              SCI_ADDR(CTL_AON_APB_BASE, 0x0600)
#define REG_AON_APB_A53_CTRL_1                              SCI_ADDR(CTL_AON_APB_BASE, 0x0604)
#define REG_AON_APB_A53_BIGCORE_VDROP_RSV                   SCI_ADDR(CTL_AON_APB_BASE, 0x0608)
#define REG_AON_APB_A53_LITCORE_VDROP_RSV                   SCI_ADDR(CTL_AON_APB_BASE, 0x060C)
#define REG_AON_APB_A53_CTRL_2                              SCI_ADDR(CTL_AON_APB_BASE, 0x0610)
#define REG_AON_APB_A53_CTRL_3                              SCI_ADDR(CTL_AON_APB_BASE, 0x0614)
#define REG_AON_APB_A53_CTRL_4                              SCI_ADDR(CTL_AON_APB_BASE, 0x0618)
#define REG_AON_APB_A53_CTRL_5                              SCI_ADDR(CTL_AON_APB_BASE, 0x061C)
#define REG_AON_APB_A53_CTRL_6                              SCI_ADDR(CTL_AON_APB_BASE, 0x0620)
#define REG_AON_APB_APCPU_INT_INFO                          SCI_ADDR(CTL_AON_APB_BASE, 0x0624)
#define REG_AON_APB_JVL_DUMMY                               SCI_ADDR(CTL_AON_APB_BASE, 0x0628)
#define REG_AON_APB_JVL_MT_CFG                              SCI_ADDR(CTL_AON_APB_BASE, 0x062C)
#define REG_AON_APB_RESONANCE_CTRL1                         SCI_ADDR(CTL_AON_APB_BASE, 0x0630)
#define REG_AON_APB_RESONANCE_CTRL2                         SCI_ADDR(CTL_AON_APB_BASE, 0x0634)
#define REG_AON_APB_ASTARTMP                                SCI_ADDR(CTL_AON_APB_BASE, 0x0660)
#define REG_AON_APB_AENDMP                                  SCI_ADDR(CTL_AON_APB_BASE, 0x0664)
#define REG_AON_APB_AWSTASHLPID                             SCI_ADDR(CTL_AON_APB_BASE, 0x0668)
#define REG_AON_APB_SUB_SYS_DBG_SIG5                        SCI_ADDR(CTL_AON_APB_BASE, 0x0714)
#define REG_AON_APB_DBG_BUS_DATA                            SCI_ADDR(CTL_AON_APB_BASE, 0x0740)
#define REG_AON_APB_PAD_DEBUG_STAT                          SCI_ADDR(CTL_AON_APB_BASE, 0x0744)
#define REG_AON_APB_EFUSE_BLK2                              SCI_ADDR(CTL_AON_APB_BASE, 0x0780)
#define REG_AON_APB_EFUSE_BLK3                              SCI_ADDR(CTL_AON_APB_BASE, 0x0784)
#define REG_AON_APB_MBIST_EFUSE_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0788)
#define REG_AON_APB_FW_INT_STATUS                           SCI_ADDR(CTL_AON_APB_BASE, 0x0800)
#define REG_AON_APB_SIM_RETAIN_CFG                          SCI_ADDR(CTL_AON_APB_BASE, 0x0804)
#define REG_AON_APB_AUX0_CAL                                SCI_ADDR(CTL_AON_APB_BASE, 0x0900)
#define REG_AON_APB_AUX0_RESULT                             SCI_ADDR(CTL_AON_APB_BASE, 0x0904)
#define REG_AON_APB_GLB_BUSMON_DEG_EN                       SCI_ADDR(CTL_AON_APB_BASE, 0x0A00)
#define REG_AON_APB_AUD_DIG_MIC_CTRL                        SCI_ADDR(CTL_AON_APB_BASE, 0x0A20)
#define REG_AON_APB_EARLY_WAKEUP_EN                         SCI_ADDR(CTL_AON_APB_BASE, 0x0A40)
#define REG_AON_APB_AP_WPROT_EN1                            SCI_ADDR(CTL_AON_APB_BASE, 0x3004)
#define REG_AON_APB_WTLCP_WPROT_EN1                         SCI_ADDR(CTL_AON_APB_BASE, 0x3008)
#define REG_AON_APB_PUBCP_WPROT_EN1                         SCI_ADDR(CTL_AON_APB_BASE, 0x300C)
#define REG_AON_APB_WCNCP_WPROT_EN1                         SCI_ADDR(CTL_AON_APB_BASE, 0x3010)
#define REG_AON_APB_IO_DLY_CTRL                             SCI_ADDR(CTL_AON_APB_BASE, 0x3014)
#define REG_AON_APB_AP_WPROT_EN0                            SCI_ADDR(CTL_AON_APB_BASE, 0x3018)
#define REG_AON_APB_WTLCP_WPROT_EN0                         SCI_ADDR(CTL_AON_APB_BASE, 0x3020)
#define REG_AON_APB_PUBCP_WPROT_EN0                         SCI_ADDR(CTL_AON_APB_BASE, 0x3024)
#define REG_AON_APB_WCNCP_WPROT_EN0                         SCI_ADDR(CTL_AON_APB_BASE, 0x3028)
#define REG_AON_APB_PMU_RST_MONITOR                         SCI_ADDR(CTL_AON_APB_BASE, 0x302C)
#define REG_AON_APB_THM_RST_MONITOR                         SCI_ADDR(CTL_AON_APB_BASE, 0x3030)
#define REG_AON_APB_AP_RST_MONITOR                          SCI_ADDR(CTL_AON_APB_BASE, 0x3034)
#define REG_AON_APB_CA53_RST_MONITOR                        SCI_ADDR(CTL_AON_APB_BASE, 0x3038)
#define REG_AON_APB_BOND_OPT0                               SCI_ADDR(CTL_AON_APB_BASE, 0x303C)
#define REG_AON_APB_BOND_OPT1                               SCI_ADDR(CTL_AON_APB_BASE, 0x3040)
#define REG_AON_APB_RES_REG0                                SCI_ADDR(CTL_AON_APB_BASE, 0x3044)
#define REG_AON_APB_RES_REG1                                SCI_ADDR(CTL_AON_APB_BASE, 0x3048)
#define REG_AON_APB_AON_QOS_CFG                             SCI_ADDR(CTL_AON_APB_BASE, 0x304C)
#define REG_AON_APB_BB_LDO_CAL_START                        SCI_ADDR(CTL_AON_APB_BASE, 0x3050)
#define REG_AON_APB_AON_MTX_PROT_CFG                        SCI_ADDR(CTL_AON_APB_BASE, 0x3058)
#define REG_AON_APB_LVDS_CFG                                SCI_ADDR(CTL_AON_APB_BASE, 0x3060)
#define REG_AON_APB_PLL_LOCK_OUT_SEL                        SCI_ADDR(CTL_AON_APB_BASE, 0x3064)
#define REG_AON_APB_RTC4M_RC_VAL                            SCI_ADDR(CTL_AON_APB_BASE, 0x3068)
#define REG_AON_APB_FUNCTST_CTRL_0                          SCI_ADDR(CTL_AON_APB_BASE, 0x3070)
#define REG_AON_APB_FUNCTST_CTRL_1                          SCI_ADDR(CTL_AON_APB_BASE, 0x3074)
#define REG_AON_APB_FUNCTST_CTRL_2                          SCI_ADDR(CTL_AON_APB_BASE, 0x3078)
#define REG_AON_APB_WDG_RST_FLAG                            SCI_ADDR(CTL_AON_APB_BASE, 0x3080)
#define REG_AON_APB_CA7_CFG                                 SCI_ADDR(CTL_AON_APB_BASE, 0x3084)
#define REG_AON_APB_RES_REG2                                SCI_ADDR(CTL_AON_APB_BASE, 0x3090)
#define REG_AON_APB_RES_REG3                                SCI_ADDR(CTL_AON_APB_BASE, 0x3094)
#define REG_AON_APB_RES_REG4                                SCI_ADDR(CTL_AON_APB_BASE, 0x3098)
#define REG_AON_APB_RES_REG5                                SCI_ADDR(CTL_AON_APB_BASE, 0x309C)
#define REG_AON_APB_RES_REG6                                SCI_ADDR(CTL_AON_APB_BASE, 0x30A0)
#define REG_AON_APB_RES_REG7                                SCI_ADDR(CTL_AON_APB_BASE, 0x30A4)
#define REG_AON_APB_AON_APB_RSV                             SCI_ADDR(CTL_AON_APB_BASE, 0x30F0)
#define REG_AON_APB_FUNCTION_DMA_BOOT_ADDR                  SCI_ADDR(CTL_AON_APB_BASE, 0x3110)
#define REG_AON_APB_SP_WAKEUP_MASK_EN1                      SCI_ADDR(CTL_AON_APB_BASE, 0x3184)
#define REG_AON_APB_SP_WAKEUP_MASK_EN2                      SCI_ADDR(CTL_AON_APB_BASE, 0x3188)
#define REG_AON_APB_SP_WDG_RST_GLB_EN                       SCI_ADDR(CTL_AON_APB_BASE, 0x318C)
#define REG_AON_APB_SP_EIC_PAD_CTRL0                        SCI_ADDR(CTL_AON_APB_BASE, 0x3190)
#define REG_AON_APB_SP_EIC_PAD_CTRL1                        SCI_ADDR(CTL_AON_APB_BASE, 0x3194)
#define REG_AON_APB_WCN2PUB_AON_REMAP                       SCI_ADDR(CTL_AON_APB_BASE, 0x3198)
#define REG_AON_APB_APCPU_DBG_CMD_EX                        SCI_ADDR(CTL_AON_APB_BASE, 0x3200)
#define REG_AON_APB_PUB_PERI_CK_EB                          SCI_ADDR(CTL_AON_APB_BASE, 0x3210)
#define REG_AON_APB_APCPU_CLUSTER_DUMMY_IN_REG              SCI_ADDR(CTL_AON_APB_BASE, 0x3300)

/* bits definitions for REG_AON_APB_APB_EB0, [0x402E0000] */
#define BIT_AON_APB_I2C_EB                                  ( BIT(31) )
#define BIT_AON_APB_CA53_DAP_EB                             ( BIT(30) )
#define BIT_AON_APB_CA53_TS1_EB                             ( BIT(29) )
#define BIT_AON_APB_CA53_TS0_EB                             ( BIT(28) )
#define BIT_AON_APB_CKG_EB                                  ( BIT(26) )
#define BIT_AON_APB_MM_EB                                   ( BIT(25) )
#define BIT_AON_APB_AP_WDG_EB                               ( BIT(24) )
#define BIT_AON_APB_MSPI_EB                                 ( BIT(23) )
#define BIT_AON_APB_SPLK_EB                                 ( BIT(22) )
#define BIT_AON_APB_IPI_EB                                  ( BIT(21) )
#define BIT_AON_APB_PIN_EB                                  ( BIT(20) )
#define BIT_AON_APB_VBC_EB                                  ( BIT(19) )
#define BIT_AON_APB_AUD_EB                                  ( BIT(18) )
#define BIT_AON_APB_AUDIF_EB                                ( BIT(17) )
#define BIT_AON_APB_ADI_EB                                  ( BIT(16) )
#define BIT_AON_APB_INTC_EB                                 ( BIT(15) )
#define BIT_AON_APB_EIC_EB                                  ( BIT(14) )
#define BIT_AON_APB_EFUSE_EB                                ( BIT(13) )
#define BIT_AON_APB_AP_TMR0_EB                              ( BIT(12) )
#define BIT_AON_APB_AON_TMR_EB                              ( BIT(11) )
#define BIT_AON_APB_AP_SYST_EB                              ( BIT(10) )
#define BIT_AON_APB_AON_SYST_EB                             ( BIT(9) )
#define BIT_AON_APB_KPD_EB                                  ( BIT(8) )
#define BIT_AON_APB_PWM3_EB                                 ( BIT(7) )
#define BIT_AON_APB_PWM2_EB                                 ( BIT(6) )
#define BIT_AON_APB_PWM1_EB                                 ( BIT(5) )
#define BIT_AON_APB_PWM0_EB                                 ( BIT(4) )
#define BIT_AON_APB_GPIO_EB                                 ( BIT(3) )
#define BIT_AON_APB_TPC_EB                                  ( BIT(2) )
#define BIT_AON_APB_FM_EB                                   ( BIT(1) )
#define BIT_AON_APB_ADC_EB                                  ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_EB1, [0x402E0004] */
#define BIT_AON_APB_SERDES_DPHY_EB                          ( BIT(31) )
#define BIT_AON_APB_CROSS_TRIG_EB                           ( BIT(30) )
#define BIT_AON_APB_DBG_EMC_EB                              ( BIT(29) )
#define BIT_AON_APB_DBG_EB                                  ( BIT(28) )
#define BIT_AON_APB_ORP_JTAG_EB                             ( BIT(27) )
#define BIT_AON_APB_CA5_TS0_EB                              ( BIT(26) )
#define BIT_AON_APB_DEF_EB                                  ( BIT(25) )
#define BIT_AON_APB_LVDS_PLL_DIV_EN                         ( BIT(24) )
#define BIT_AON_APB_ARM7_JTAG_EB                            ( BIT(23) )
#define BIT_AON_APB_AON_DMA_EB                              ( BIT(22) )
#define BIT_AON_APB_MBOX_EB                                 ( BIT(21) )
#define BIT_AON_APB_DJTAG_EB                                ( BIT(20) )
#define BIT_AON_APB_RTC4M1_CAL_EB                           ( BIT(19) )
#define BIT_AON_APB_RTC4M0_CAL_EB                           ( BIT(18) )
#define BIT_AON_APB_MDAR_EB                                 ( BIT(17) )
#define BIT_AON_APB_LVDS_TCXO_EB                            ( BIT(16) )
#define BIT_AON_APB_LVDS_TRX_EB                             ( BIT(15) )
#define BIT_AON_APB_MM_VSP_EB                               ( BIT(14) )
#define BIT_AON_APB_GSP_EMC_EB                              ( BIT(13) )
#define BIT_AON_APB_ZIP_EMC_EB                              ( BIT(12) )
#define BIT_AON_APB_DISP_EMC_EB                             ( BIT(11) )
#define BIT_AON_APB_AP_TMR2_EB                              ( BIT(10) )
#define BIT_AON_APB_AP_TMR1_EB                              ( BIT(9) )
#define BIT_AON_APB_CA53_WDG_EB                             ( BIT(8) )
#define BIT_AON_APB_CLK_EMC_REF_EB                          ( BIT(7) )
#define BIT_AON_APB_PROBE_EB                                ( BIT(5) )
#define BIT_AON_APB_AUX2_EB                                 ( BIT(4) )
#define BIT_AON_APB_AUX1_EB                                 ( BIT(3) )
#define BIT_AON_APB_AUX0_EB                                 ( BIT(2) )
#define BIT_AON_APB_THM_EB                                  ( BIT(1) )
#define BIT_AON_APB_PMU_EB                                  ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST0, [0x402E0008] */
#define BIT_AON_APB_CA5_TS0_SOFT_RST                        ( BIT(31) )
#define BIT_AON_APB_I2C_SOFT_RST                            ( BIT(30) )
#define BIT_AON_APB_CA53_TS1_SOFT_RST                       ( BIT(29) )
#define BIT_AON_APB_CA53_TS0_SOFT_RST                       ( BIT(28) )
#define BIT_AON_APB_DAP_MTX_SOFT_RST                        ( BIT(27) )
#define BIT_AON_APB_MSPI1_SOFT_RST                          ( BIT(26) )
#define BIT_AON_APB_MSPI0_SOFT_RST                          ( BIT(25) )
#define BIT_AON_APB_SPLK_SOFT_RST                           ( BIT(24) )
#define BIT_AON_APB_IPI_SOFT_RST                            ( BIT(23) )
#define BIT_AON_APB_CKG_SOFT_RST                            ( BIT(22) )
#define BIT_AON_APB_PIN_SOFT_RST                            ( BIT(21) )
#define BIT_AON_APB_VBC_SOFT_RST                            ( BIT(20) )
#define BIT_AON_APB_AUD_SOFT_RST                            ( BIT(19) )
#define BIT_AON_APB_AUDIF_SOFT_RST                          ( BIT(18) )
#define BIT_AON_APB_ADI_SOFT_RST                            ( BIT(17) )
#define BIT_AON_APB_INTC_SOFT_RST                           ( BIT(16) )
#define BIT_AON_APB_EIC_SOFT_RST                            ( BIT(15) )
#define BIT_AON_APB_EFUSE_SOFT_RST                          ( BIT(14) )
#define BIT_AON_APB_AP_WDG_SOFT_RST                         ( BIT(13) )
#define BIT_AON_APB_AP_TMR0_SOFT_RST                        ( BIT(12) )
#define BIT_AON_APB_AON_TMR_SOFT_RST                        ( BIT(11) )
#define BIT_AON_APB_AP_SYST_SOFT_RST                        ( BIT(10) )
#define BIT_AON_APB_AON_SYST_SOFT_RST                       ( BIT(9) )
#define BIT_AON_APB_KPD_SOFT_RST                            ( BIT(8) )
#define BIT_AON_APB_PWM3_SOFT_RST                           ( BIT(7) )
#define BIT_AON_APB_PWM2_SOFT_RST                           ( BIT(6) )
#define BIT_AON_APB_PWM1_SOFT_RST                           ( BIT(5) )
#define BIT_AON_APB_PWM0_SOFT_RST                           ( BIT(4) )
#define BIT_AON_APB_GPIO_SOFT_RST                           ( BIT(3) )
#define BIT_AON_APB_TPC_SOFT_RST                            ( BIT(2) )
#define BIT_AON_APB_FM_SOFT_RST                             ( BIT(1) )
#define BIT_AON_APB_ADC_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST1, [0x402E000C] */
#define BIT_AON_APB_RTC4M_ANA_SOFT_RST                      ( BIT(31) )
#define BIT_AON_APB_DEF_SLV_INT_SOFT_CLR                    ( BIT(30) )
#define BIT_AON_APB_DEF_SOFT_RST                            ( BIT(29) )
#define BIT_AON_APB_ADC3_SOFT_RST                           ( BIT(28) )
#define BIT_AON_APB_ADC2_SOFT_RST                           ( BIT(27) )
#define BIT_AON_APB_ADC1_SOFT_RST                           ( BIT(26) )
#define BIT_AON_APB_MBOX_SOFT_RST                           ( BIT(25) )
#define BIT_AON_APB_ROSC_SOFT_RST                           ( BIT(24) )
#define BIT_AON_APB_RTC4M1_CAL_SOFT_RST                     ( BIT(23) )
#define BIT_AON_APB_RTC4M0_CAL_SOFT_RST                     ( BIT(22) )
#define BIT_AON_APB_DISP_SOFT_RST                           ( BIT(20) )
#define BIT_AON_APB_DAC3_SOFT_RST                           ( BIT(19) )
#define BIT_AON_APB_DAC2_SOFT_RST                           ( BIT(18) )
#define BIT_AON_APB_DAC1_SOFT_RST                           ( BIT(17) )
#define BIT_AON_APB_ADC3_CAL_SOFT_RST                       ( BIT(16) )
#define BIT_AON_APB_ADC2_CAL_SOFT_RST                       ( BIT(15) )
#define BIT_AON_APB_ADC1_CAL_SOFT_RST                       ( BIT(14) )
#define BIT_AON_APB_MDAR_SOFT_RST                           ( BIT(13) )
#define BIT_AON_APB_LVDSDIS_SOFT_RST                        ( BIT(12) )
#define BIT_AON_APB_BB_CAL_SOFT_RST                         ( BIT(11) )
#define BIT_AON_APB_DCXO_LC_SOFT_RST                        ( BIT(10) )
#define BIT_AON_APB_AP_TMR2_SOFT_RST                        ( BIT(9) )
#define BIT_AON_APB_AP_TMR1_SOFT_RST                        ( BIT(8) )
#define BIT_AON_APB_CA53_WDG_SOFT_RST                       ( BIT(7) )
#define BIT_AON_APB_AON_DMA_SOFT_RST                        ( BIT(6) )
#define BIT_AON_APB_DMC_PHY_SOFT_RST                        ( BIT(4) )
#define BIT_AON_APB_GPU_THMA_SOFT_RST                       ( BIT(3) )
#define BIT_AON_APB_ARM_THMA_SOFT_RST                       ( BIT(2) )
#define BIT_AON_APB_THM_SOFT_RST                            ( BIT(1) )
#define BIT_AON_APB_PMU_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RTC_EB, [0x402E0010] */
#define BIT_AON_APB_BB_CAL_RTC_EB                           ( BIT(18) )
#define BIT_AON_APB_DCXO_LC_RTC_EB                          ( BIT(17) )
#define BIT_AON_APB_AP_TMR2_RTC_EB                          ( BIT(16) )
#define BIT_AON_APB_AP_TMR1_RTC_EB                          ( BIT(15) )
#define BIT_AON_APB_GPU_THMA_RTC_AUTO_EN                    ( BIT(14) )
#define BIT_AON_APB_ARM_THMA_RTC_AUTO_EN                    ( BIT(13) )
#define BIT_AON_APB_GPU_THMA_RTC_EB                         ( BIT(12) )
#define BIT_AON_APB_ARM_THMA_RTC_EB                         ( BIT(11) )
#define BIT_AON_APB_THM_RTC_EB                              ( BIT(10) )
#define BIT_AON_APB_CA53_WDG_RTC_EB                         ( BIT(9) )
#define BIT_AON_APB_AP_WDG_RTC_EB                           ( BIT(8) )
#define BIT_AON_APB_EIC_RTCDV5_EB                           ( BIT(7) )
#define BIT_AON_APB_EIC_RTC_EB                              ( BIT(6) )
#define BIT_AON_APB_AP_TMR0_RTC_EB                          ( BIT(5) )
#define BIT_AON_APB_AON_TMR_RTC_EB                          ( BIT(4) )
#define BIT_AON_APB_AP_SYST_RTC_EB                          ( BIT(3) )
#define BIT_AON_APB_AON_SYST_RTC_EB                         ( BIT(2) )
#define BIT_AON_APB_KPD_RTC_EB                              ( BIT(1) )
#define BIT_AON_APB_ARCH_RTC_EB                             ( BIT(0) )

/* bits definitions for REG_AON_APB_REC_26MHZ_BUF_CFG, [0x402E0014] */
#define BIT_AON_APB_PLL_PROBE_SEL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AON_APB_REC_26MHZ_1_CUR_SEL                     ( BIT(4) )
#define BIT_AON_APB_REC_26MHZ_0_CUR_SEL                     ( BIT(0) )

/* bits definitions for REG_AON_APB_SINDRV_CTRL, [0x402E0018] */
#define BIT_AON_APB_SINDRV_LVL(x)                           ( (x) << 3  & (BIT(3)|BIT(4)) )
#define BIT_AON_APB_SINDRV_CLIP_MODE                        ( BIT(2) )
#define BIT_AON_APB_SINDRV_ENA_SQUARE                       ( BIT(1) )
#define BIT_AON_APB_SINDRV_ENA                              ( BIT(0) )

/* bits definitions for REG_AON_APB_ADA_SEL_CTRL, [0x402E001C] */
#define BIT_AON_APB_TW_MODE_SEL                             ( BIT(3) )
#define BIT_AON_APB_WGADC_DIV_EN                            ( BIT(2) )
#define BIT_AON_APB_AFCDAC_SYS_SEL                          ( BIT(1) )
#define BIT_AON_APB_APCDAC_SYS_SEL                          ( BIT(0) )

/* bits definitions for REG_AON_APB_VBC_CTRL, [0x402E0020] */
#define BIT_AON_APB_AUDIF_CKG_AUTO_EN                       ( BIT(20) )
#define BIT_AON_APB_AUD_INT_SYS_SEL(x)                      ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_AON_APB_VBC_DA23_INT_SYS_SEL(x)                 ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AON_APB_VBC_AD23_INT_SYS_SEL(x)                 ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AON_APB_VBC_AD01_INT_SYS_SEL(x)                 ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_APB_VBC_DA01_INT_SYS_SEL(x)                 ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AON_APB_VBC_AD23_DMA_SYS_SEL(x)                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_APB_VBC_AD01_DMA_SYS_SEL(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AON_APB_VBC_DA01_DMA_SYS_SEL(x)                 ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_APB_VBC_DA23_DMA_SYS_SEL(x)                 ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AON_APB_VBC_DMA_WTLCP_ARM_SEL                   ( BIT(1) )
#define BIT_AON_APB_VBC_DMA_PUBCP_ARM_SEL                   ( BIT(0) )

/* bits definitions for REG_AON_APB_PWR_CTRL, [0x402E0024] */
#define BIT_AON_APB_USB_ISO_SW_EN                           ( BIT(28) )
#define BIT_AON_APB_MIPI_DSI_ISO_SW_EN                      ( BIT(27) )
#define BIT_AON_APB_MIPI_CSI_2P2LANE_ISO_SW_EN              ( BIT(26) )
#define BIT_AON_APB_MIPI_CSI_2LANE_ISO_SW_EN                ( BIT(25) )
#define BIT_AON_APB_MIPI_CSI_4LANE_ISO_SW_EN                ( BIT(24) )
#define BIT_AON_APB_MIPI_CSI_4LANE_PS_PD_S                  ( BIT(23) )
#define BIT_AON_APB_MIPI_CSI_4LANE_PS_PD_L                  ( BIT(22) )
#define BIT_AON_APB_FORCE_DSI_DBG_PHY_SHUTDOWNZ             ( BIT(21) )
#define BIT_AON_APB_FORCE_CSI_S_PHY_SHUTDOWNZ               ( BIT(20) )
#define BIT_AON_APB_HSIC_PLL_EN                             ( BIT(19) )
#define BIT_AON_APB_HSIC_PHY_PD                             ( BIT(18) )
#define BIT_AON_APB_USB_PHY_PD_S                            ( BIT(17) )
#define BIT_AON_APB_USB_PHY_PD_L                            ( BIT(16) )
#define BIT_AON_APB_MIPI_DSI_PS_PD_S                        ( BIT(15) )
#define BIT_AON_APB_MIPI_DSI_PS_PD_L                        ( BIT(14) )
#define BIT_AON_APB_MIPI_CSI_2P2LANE_PS_PD_S                ( BIT(13) )
#define BIT_AON_APB_MIPI_CSI_2P2LANE_PS_PD_L                ( BIT(12) )
#define BIT_AON_APB_MIPI_CSI_2LANE_PS_PD_S                  ( BIT(11) )
#define BIT_AON_APB_MIPI_CSI_2LANE_PS_PD_L                  ( BIT(10) )
#define BIT_AON_APB_CA53_TS1_STOP                           ( BIT(9) )
#define BIT_AON_APB_CA53_TS0_STOP                           ( BIT(8) )
#define BIT_AON_APB_EFUSE_BIST_PWR_ON                       ( BIT(3) )
#define BIT_AON_APB_FORCE_DSI_PHY_SHUTDOWNZ                 ( BIT(2) )
#define BIT_AON_APB_FORCE_CSI_PHY_SHUTDOWNZ                 ( BIT(1) )

/* bits definitions for REG_AON_APB_TS_CFG, [0x402E0028] */
#define BIT_AON_APB_DBG_TRACE_CTRL_EN                       ( BIT(14) )
#define BIT_AON_APB_CSYSACK_TS_LP_2                         ( BIT(13) )
#define BIT_AON_APB_CSYSREQ_TS_LP_2                         ( BIT(12) )
#define BIT_AON_APB_CSYSACK_TS_LP_1                         ( BIT(11) )
#define BIT_AON_APB_CSYSREQ_TS_LP_1                         ( BIT(10) )
#define BIT_AON_APB_CSYSACK_TS_LP_0                         ( BIT(9) )
#define BIT_AON_APB_CSYSREQ_TS_LP_0                         ( BIT(8) )
#define BIT_AON_APB_EVENTACK_RESTARTREQ_TS01                ( BIT(4) )
#define BIT_AON_APB_EVENT_RESTARTREQ_TS01                   ( BIT(1) )
#define BIT_AON_APB_EVENT_HALTREQ_TS01                      ( BIT(0) )

/* bits definitions for REG_AON_APB_BOOT_MODE, [0x402E002C] */
#define BIT_AON_APB_ARM_JTAG_EN                             ( BIT(13) )
#define BIT_AON_APB_WPLL_OVR_FREQ_SEL                       ( BIT(12) )
#define BIT_AON_APB_PTEST_GPU_TO_DDR                        ( BIT(9) )
#define BIT_AON_APB_PTEST_FUNC_ATSPEED_SEL                  ( BIT(8) )
#define BIT_AON_APB_PTEST_FUNC_MODE                         ( BIT(7) )
#define BIT_AON_APB_FUNCTST_DMA_EB                          ( BIT(5) )
#define BIT_AON_APB_USB_DLOAD_EN                            ( BIT(4) )
#define BIT_AON_APB_ARM_BOOT_MD3                            ( BIT(3) )
#define BIT_AON_APB_ARM_BOOT_MD2                            ( BIT(2) )
#define BIT_AON_APB_ARM_BOOT_MD1                            ( BIT(1) )
#define BIT_AON_APB_ARM_BOOT_MD0                            ( BIT(0) )

/* bits definitions for REG_AON_APB_BB_BG_CTRL, [0x402E0030] */
#define BIT_AON_APB_BB_CON_BG                               ( BIT(22) )
#define BIT_AON_APB_BB_BG_RSV(x)                            ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_AON_APB_BB_LDO_V(x)                             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_BB_BG_RBIAS_EN                          ( BIT(15) )
#define BIT_AON_APB_BB_BG_IEXT_IB_EN                        ( BIT(14) )
#define BIT_AON_APB_BB_LDO_REFCTRL(x)                       ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_APB_BB_LDO_AUTO_PD_EN                       ( BIT(11) )
#define BIT_AON_APB_BB_LDO_SLP_PD_EN                        ( BIT(10) )
#define BIT_AON_APB_BB_LDO_FORCE_ON                         ( BIT(9) )
#define BIT_AON_APB_BB_LDO_FORCE_PD                         ( BIT(8) )
#define BIT_AON_APB_BB_BG_AUTO_PD_EN                        ( BIT(3) )
#define BIT_AON_APB_BB_BG_SLP_PD_EN                         ( BIT(2) )
#define BIT_AON_APB_BB_BG_FORCE_ON                          ( BIT(1) )
#define BIT_AON_APB_BB_BG_FORCE_PD                          ( BIT(0) )

/* bits definitions for REG_AON_APB_CP_ARM_JTAG_CTRL, [0x402E0034] */
#define BIT_AON_APB_CP_ARM_JTAG_PIN_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_PLL_SOFT_CNT_DONE, [0x402E0038] */
#define BIT_AON_APB_RC1_SOFT_CNT_DONE                       ( BIT(13) )
#define BIT_AON_APB_RC0_SOFT_CNT_DONE                       ( BIT(12) )
#define BIT_AON_APB_XTLBUF1_SOFT_CNT_DONE                   ( BIT(9) )
#define BIT_AON_APB_XTLBUF0_SOFT_CNT_DONE                   ( BIT(8) )
#define BIT_AON_APB_BMPLL_SOFT_CNT_DONE                     ( BIT(5) )
#define BIT_AON_APB_LVDSPLL_SOFT_CNT_DONE                   ( BIT(4) )
#define BIT_AON_APB_LPLL_SOFT_CNT_DONE                      ( BIT(3) )
#define BIT_AON_APB_TWPLL_SOFT_CNT_DONE                     ( BIT(2) )
#define BIT_AON_APB_DPLL_SOFT_CNT_DONE                      ( BIT(1) )
#define BIT_AON_APB_MPLL_SOFT_CNT_DONE                      ( BIT(0) )

/* bits definitions for REG_AON_APB_DCXO_LC_REG0, [0x402E003C] */
#define BIT_AON_APB_DCXO_LC_FLAG                            ( BIT(8) )
#define BIT_AON_APB_DCXO_LC_FLAG_CLR                        ( BIT(1) )
#define BIT_AON_APB_DCXO_LC_CNT_CLR                         ( BIT(0) )

/* bits definitions for REG_AON_APB_DCXO_LC_REG1, [0x402E0040] */
#define BIT_AON_APB_DCXO_LC_CNT(x)                          ( (x) )

/* bits definitions for REG_AON_APB_AON_CLK_TOP_CFG, [0x402E0050] */
#define BIT_AON_APB_CLK_VSP_EB                              ( BIT(16) )
#define BIT_AON_APB_CLK_MM_VSP_AHB_EB                       ( BIT(15) )
#define BIT_AON_APB_CLK_MM_VSP_EMC_EB                       ( BIT(14) )
#define BIT_AON_APB_CLK_SENSOR1_EB                          ( BIT(13) )
#define BIT_AON_APB_CLK_SENSOR0_EB                          ( BIT(12) )
#define BIT_AON_APB_CLK_HW_I2C_EB                           ( BIT(11) )
#define BIT_AON_APB_CLK_POWER_CPU_EB                        ( BIT(10) )
#define BIT_AON_APB_CLK_CPP_EB                              ( BIT(9) )
#define BIT_AON_APB_CLK_JPG_EB                              ( BIT(8) )
#define BIT_AON_APB_CLK_ISP_EB                              ( BIT(7) )
#define BIT_AON_APB_CLK_DCAM_IF_EB                          ( BIT(6) )
#define BIT_AON_APB_CLK_SENSOR2_EB                          ( BIT(5) )
#define BIT_AON_APB_CLK_MM_AHB_EB                           ( BIT(4) )
#define BIT_AON_APB_CLK_MM_EMC_EB                           ( BIT(3) )
#define BIT_AON_APB_CLK_DISP_EB                             ( BIT(2) )
#define BIT_AON_APB_CLK_WCN_EB                              ( BIT(1) )
#define BIT_AON_APB_CLK_GPU_EB                              ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_SYS_MODULE_EN, [0x402E0054] */
#define BIT_AON_APB_SP_SPI0_EN                              ( BIT(4) )
#define BIT_AON_APB_SP_I2C1_EN                              ( BIT(3) )
#define BIT_AON_APB_SP_I2C0_EN                              ( BIT(2) )
#define BIT_AON_APB_SP_UART1_EN                             ( BIT(1) )
#define BIT_AON_APB_SP_UART0_EN                             ( BIT(0) )

/* bits definitions for REG_AON_APB_CLK_LPF_SEC_REG, [0x402E0058] */
#define BIT_AON_APB_CLK_LPF_SEC_REG(x)                      ( (x) )

/* bits definitions for REG_AON_APB_LVDSRFPLL_CFG1, [0x402E0064] */
#define BIT_AON_APB_LVDSRFPLL_RES(x)                        ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_LVDSRFPLL_LOCK_DONE                     ( BIT(21) )
#define BIT_AON_APB_LVDSRFPLL_DIV_S                         ( BIT(20) )
#define BIT_AON_APB_LVDSRFPLL_MOD_EN                        ( BIT(19) )
#define BIT_AON_APB_LVDSRFPLL_SDM_EN                        ( BIT(18) )
#define BIT_AON_APB_LVDSRFPLL_LPF(x)                        ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AON_APB_LVDSRFPLL_IBIAS(x)                      ( (x) << 11 & (BIT(11)|BIT(12)) )
#define BIT_AON_APB_LVDSRFPLL_N(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_AON_APB_LVDSRFPLL_CFG2, [0x402E0068] */
#define BIT_AON_APB_LVDSRF_PLL_CLKOUT_EN                    ( BIT(30) )
#define BIT_AON_APB_LVDSRFPLL_NINT(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_LVDSRFPLL_KINT(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for REG_AON_APB_AON_REG_PROT, [0x402E006C] */
#define BIT_AON_APB_LDSP_CTRL_PROT                          ( BIT(31) )
#define BIT_AON_APB_REG_PROT_VAL(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_DSI_PHY_CTRL, [0x402E0070] */
#define BIT_AON_APB_DSI_IF_SEL                              ( BIT(24) )
#define BIT_AON_APB_DSI_TRIMBG(x)                           ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_DSI_RCTL(x)                             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_DSI_RES(x)                              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_CSI_2L_PHY_CTRL, [0x402E0074] */
#define BIT_AON_APB_CSI_2L_IF_SEL                           ( BIT(20) )
#define BIT_AON_APB_CSI_2L_RCTL(x)                          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_CSI_2L_RES(x)                           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_CSI_2P2L_S_PHY_CTRL, [0x402E0078] */
#define BIT_AON_APB_CSI_2P2L_TESTCLR_S                      ( BIT(23) )
#define BIT_AON_APB_CSI_2P2L_TESTCLR_S_SEL                  ( BIT(22) )
#define BIT_AON_APB_CSI_2P2L_TESTCLR_S_EN                   ( BIT(21) )
#define BIT_AON_APB_CSI_2P2L_S_IF_SEL                       ( BIT(20) )

/* bits definitions for REG_AON_APB_CSI_2P2L_M_PHY_CTRL, [0x402E007C] */
#define BIT_AON_APB_CSI_2P2L_TESTCLR_M                      ( BIT(23) )
#define BIT_AON_APB_CSI_2P2L_TESTCLR_M_SEL                  ( BIT(22) )
#define BIT_AON_APB_CSI_2P2L_TESTCLR_M_EN                   ( BIT(21) )
#define BIT_AON_APB_CSI_2P2L_M_IF_SEL                       ( BIT(20) )
#define BIT_AON_APB_CSI_2P2L_RCTL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_CSI_2P2L_RES(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_CSI_2P2L_DBG_PHY_CTRL, [0x402E0080] */
#define BIT_AON_APB_CSI_2P2L_DBG_EN                         ( BIT(25) )
#define BIT_AON_APB_CSI_2P2L_DBG_IF_SEL                     ( BIT(24) )
#define BIT_AON_APB_CSI_2P2L_DBG_TRIMBG(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for REG_AON_APB_CSI_2P2L_PHY_CTRL, [0x402E0084] */
#define BIT_AON_APB_CSI_2P2L_MODE_SEL                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_CGM_CFG0, [0x402E0088] */
#define BIT_AON_APB_PROBE_CKG_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AON_APB_AUX2_CKG_SEL(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AON_APB_AUX1_CKG_SEL(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AON_APB_AUX0_CKG_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_APB_AON_CGM_CFG1, [0x402E008C] */
#define BIT_AON_APB_PROBE_CKG_DIV(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_AUX2_CKG_DIV(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_AUX1_CKG_DIV(x)                         ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_AUX0_CKG_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_CA53_AUTO_CLKCTRL_DIS, [0x402E0090] */
#define BIT_AON_APB_CCI_AUTO_CLK_CTRL_DISABLE               ( BIT(3) )
#define BIT_AON_APB_NIC_AUTO_CLK_CTRL_DISABLE               ( BIT(2) )
#define BIT_AON_APB_DAP2CCI_AUTO_CLK_CTRL_DISABLE           ( BIT(1) )

/* bits definitions for REG_AON_APB_SOFT_DFS_CTRL, [0x402E00A0] */
#define BIT_AON_APB_PUB_DFS_DESPLL_RST_WAIT(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_PUB_DFS_SW_SWITCH_PERIOD(x)             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_PUB_DFS_SW_DESPLL_EN                    ( BIT(12) )
#define BIT_AON_APB_PUB_DFS_SW_DESPLL_AUTO_MODE             ( BIT(11) )
#define BIT_AON_APB_PUB_DFS_SW_RATIO(x)                     ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_APB_PUB_DFS_SW_FRQ_SEL(x)                   ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_APB_PUB_DFS_SW_RESP                         ( BIT(3) )
#define BIT_AON_APB_PUB_DFS_SW_ACK                          ( BIT(2) )
#define BIT_AON_APB_PUB_DFS_SW_REQ                          ( BIT(1) )
#define BIT_AON_APB_PUB_DFS_SW_ENABLE                       ( BIT(0) )

/* bits definitions for REG_AON_APB_HARD_DFS_CTRL_LO, [0x402E00A4] */
#define BIT_AON_APB_PUB_DFS_HW_INITIAL_FREQ(x)              ( (x) << 3  & (BIT(3)|BIT(4)) )
#define BIT_AON_APB_PUB_DFS_HW_STOP                         ( BIT(2) )
#define BIT_AON_APB_PUB_DFS_HW_START                        ( BIT(1) )
#define BIT_AON_APB_PUB_DFS_HW_ENABLE                       ( BIT(0) )

/* bits definitions for REG_AON_APB_HARD_DFS_CTRL_HI, [0x402E00A8] */
#define BIT_AON_APB_PUB_DFS_HW_SWITCH_PERIOD(x)             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_PUB_DFS_HW_F3_RATIO(x)                  ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_PUB_DFS_HW_F2_RATIO(x)                  ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_APB_PUB_DFS_HW_F1_RATIO(x)                  ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_AON_APB_PUB_DFS_HW_F0_RATIO(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_AON_APB_APB_EB3, [0x402E00AC] */
#define BIT_AON_APB_PUBCP_SIM2_AON_TOP_EB                   ( BIT(19) )
#define BIT_AON_APB_PUBCP_SIM1_AON_TOP_EB                   ( BIT(18) )
#define BIT_AON_APB_PUBCP_SIM0_AON_TOP_EB                   ( BIT(17) )
#define BIT_AON_APB_AP_SIM_AON_TOP_EB                       ( BIT(16) )

/* bits definitions for REG_AON_APB_APB_EB2, [0x402E00B0] */
#define BIT_AON_APB_AON_AP_EMC_EB                           ( BIT(28) )
#define BIT_AON_APB_SERDES_EB                               ( BIT(27) )
#define BIT_AON_APB_OTG_REF_EB                              ( BIT(26) )
#define BIT_AON_APB_CPHY_CFG_EB                             ( BIT(25) )
#define BIT_AON_APB_DPHY_REF_EB                             ( BIT(24) )
#define BIT_AON_APB_DPHY_CFG_EB                             ( BIT(23) )
#define BIT_AON_APB_SCC_EB                                  ( BIT(22) )
#define BIT_AON_APB_AP_INTC5_EB                             ( BIT(21) )
#define BIT_AON_APB_AP_INTC4_EB                             ( BIT(20) )
#define BIT_AON_APB_AP_INTC3_EB                             ( BIT(19) )
#define BIT_AON_APB_AP_INTC2_EB                             ( BIT(18) )
#define BIT_AON_APB_AP_INTC1_EB                             ( BIT(17) )
#define BIT_AON_APB_AP_INTC0_EB                             ( BIT(16) )
#define BIT_AON_APB_AP_AXI_EB                               ( BIT(15) )
#define BIT_AON_APB_BSMTMR_EB                               ( BIT(14) )
#define BIT_AON_APB_ANLG_APB_EB                             ( BIT(13) )
#define BIT_AON_APB_ANLG_EB                                 ( BIT(11) )
#define BIT_AON_APB_BUSMON_DMA_EB                           ( BIT(10) )
#define BIT_AON_APB_SERDES_DPHY_REF_EB                      ( BIT(9) )
#define BIT_AON_APB_SERDES_DPHY_CFG_EB                      ( BIT(8) )
#define BIT_AON_APB_ROSC_EB                                 ( BIT(7) )
#define BIT_AON_APB_PUB_REG_EB                              ( BIT(6) )
#define BIT_AON_APB_DMC_EB                                  ( BIT(5) )
#define BIT_AON_APB_CSSYS_EB                                ( BIT(4) )
#define BIT_AON_APB_RFTI_RX_EB                              ( BIT(3) )
#define BIT_AON_APB_RFTI_TX_EB                              ( BIT(2) )
#define BIT_AON_APB_WCDMA_ICI_EB                            ( BIT(1) )
#define BIT_AON_APB_WCDMA_EB                                ( BIT(0) )

/* bits definitions for REG_AON_APB_ROSC_CFG, [0x402E00C0] */
#define BIT_AON_APB_ROSC_NUM(x)                             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_ROSC_SEL(x)                             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_ROSC_EN                                 ( BIT(0) )

/* bits definitions for REG_AON_APB_ROSC_STATUS, [0x402E00C4] */
#define BIT_AON_APB_ROSC_CNT(x)                             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AON_APB_ROSC_VALID                              ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_EB4, [0x402E00D0] */
#define BIT_AON_APB_DVFS_EB                                 ( BIT(1) )
#define BIT_AON_APB_GPLUS_EB                                ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST4, [0x402E00D4] */
#define BIT_AON_APB_PUBCP_SIM2_AON_TOP_SOFT_RST             ( BIT(5) )
#define BIT_AON_APB_PUBCP_SIM1_AON_TOP_SOFT_RST             ( BIT(4) )
#define BIT_AON_APB_PUBCP_SIM0_AON_TOP_SOFT_RST             ( BIT(3) )
#define BIT_AON_APB_AP_SIM_AON_TOP_SOFT_RST                 ( BIT(2) )
#define BIT_AON_APB_DVFS_SOFT_RST                           ( BIT(1) )
#define BIT_AON_APB_GPLUS_SOFT_RST                          ( BIT(0) )

/* bits definitions for REG_AON_APB_GPIO_CFG_SEL, [0x402E00D8] */
#define BIT_AON_APB_GPLUS_INT_CHIP_SLEEP                    ( BIT(1) )
#define BIT_AON_APB_GPIO_CTRL_SEL                           ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_CFG_BUS, [0x402E00DC] */
#define BIT_AON_APB_SP_CFG_BUS_AUTO_EN                      ( BIT(8) )
#define BIT_AON_APB_SP_AHB_CLK_SOFT_EN                      ( BIT(7) )
#define BIT_AON_APB_CM3_SLEEPING_STAT                       ( BIT(6) )
#define BIT_AON_APB_CM3_LOCKUP_STAT                         ( BIT(5) )
#define BIT_AON_APB_CM3_SOFT_MPUDIS                         ( BIT(4) )
#define BIT_AON_APB_MMTX_SLEEP_CM3_PUB_WR                   ( BIT(3) )
#define BIT_AON_APB_MMTX_SLEEP_CM3_PUB_RD                   ( BIT(2) )
#define BIT_AON_APB_INT_REQ_CM3_SOFT                        ( BIT(1) )
#define BIT_AON_APB_SP_CFG_BUS_SLEEP                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_CHIP_ID0, [0x402E00E0] */
#define BIT_AON_APB_AON_CHIP_ID0(x)                         ( (x) )

/* bits definitions for REG_AON_APB_AON_CHIP_ID1, [0x402E00E4] */
#define BIT_AON_APB_AON_CHIP_ID1(x)                         ( (x) )

/* bits definitions for REG_AON_APB_AON_PLAT_ID0, [0x402E00E8] */
#define BIT_AON_APB_AON_PLAT_ID0(x)                         ( (x) )

/* bits definitions for REG_AON_APB_AON_PLAT_ID1, [0x402E00EC] */
#define BIT_AON_APB_AON_PLAT_ID1(x)                         ( (x) )

/* bits definitions for REG_AON_APB_AON_IMPL_ID, [0x402E00F0] */
#define BIT_AON_APB_AON_IMPL_ID(x)                          ( (x) )

/* bits definitions for REG_AON_APB_AON_MFT_ID, [0x402E00F4] */
#define BIT_AON_APB_AON_MFT_ID(x)                           ( (x) )

/* bits definitions for REG_AON_APB_AON_VER_ID, [0x402E00F8] */
#define BIT_AON_APB_AON_VER_ID(x)                           ( (x) )

/* bits definitions for REG_AON_APB_AON_CHIP_ID, [0x402E00FC] */
#define BIT_AON_APB_AON_CHIP_ID(x)                          ( (x) )

/* bits definitions for REG_AON_APB_CCIR_RCVR_CFG, [0x402E0100] */
#define BIT_AON_APB_CCIR_SE                                 ( BIT(1) )
#define BIT_AON_APB_CCIR_IE                                 ( BIT(0) )

/* bits definitions for REG_AON_APB_PLL_BG_CFG, [0x402E0108] */
#define BIT_AON_APB_PLL_BG_RSV(x)                           ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_APB_PLL_BG_RBIAS_EN                         ( BIT(3) )
#define BIT_AON_APB_PLL_BG_PD                               ( BIT(2) )
#define BIT_AON_APB_PLL_BG_IEXT_IBEN                        ( BIT(1) )
#define BIT_AON_APB_PLL_CON_BG                              ( BIT(0) )

/* bits definitions for REG_AON_APB_LVDSDIS_SEL, [0x402E010C] */
#define BIT_AON_APB_LVDSDIS_LOG_SEL(x)                      ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_AON_APB_LVDSDIS_DBG_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_APB_DJTAG_MUX_SEL, [0x402E0110] */
#define BIT_AON_APB_DJTAG_MM_VSP_SEL                        ( BIT(8) )
#define BIT_AON_APB_DJTAG_WCN_SEL                           ( BIT(7) )
#define BIT_AON_APB_DJTAG_AON_SEL                           ( BIT(6) )
#define BIT_AON_APB_DJTAG_PUB_SEL                           ( BIT(5) )
#define BIT_AON_APB_DJTAG_PUBCP_SEL                         ( BIT(4) )
#define BIT_AON_APB_DJTAG_WTLCP_SEL                         ( BIT(3) )
#define BIT_AON_APB_DJTAG_GPU_SEL                           ( BIT(2) )
#define BIT_AON_APB_DJTAG_MM_SEL                            ( BIT(1) )
#define BIT_AON_APB_DJTAG_AP_SEL                            ( BIT(0) )

/* bits definitions for REG_AON_APB_ARM7_SYS_SOFT_RST, [0x402E0114] */
#define BIT_AON_APB_ARM7_SYS_SOFT_RST                       ( BIT(4) )
#define BIT_AON_APB_ARM7_CORE_SOFT_RST                      ( BIT(0) )

/* bits definitions for REG_AON_APB_PUBCP_WTLCP_ADDR_MSB, [0x402E0118] */
#define BIT_AON_APB_PUBCP_WTLCP_ADDR_MSB(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_AON_DMA_INT_EN, [0x402E011C] */
#define BIT_AON_APB_AON_DMA_INT_ARM7_EN                     ( BIT(6) )
#define BIT_AON_APB_AON_DMA_INT_AP_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_EMC_AUTO_GATE_EN, [0x402E0120] */

/* bits definitions for REG_AON_APB_ARM7_CFG_BUS, [0x402E0124] */
#define BIT_AON_APB_ARM7_CFG_BUS_SLEEP                      ( BIT(0) )

/* bits definitions for REG_AON_APB_RTC4M_0_CFG, [0x402E0128] */
#define BIT_AON_APB_RTC4M0_RC_CAL_PRECISION(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_RTC4M0_RC_VAL_RESULT(x)                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_APB_RTC4M0_CAL_DONE                         ( BIT(6) )
#define BIT_AON_APB_RTC4M0_CAL_START                        ( BIT(5) )
#define BIT_AON_APB_RTC4M0_CHOP_EN                          ( BIT(4) )
#define BIT_AON_APB_RTC4M0_FORCE_EN                         ( BIT(1) )
#define BIT_AON_APB_RTC4M0_AUTO_GATE_EN                     ( BIT(0) )

/* bits definitions for REG_AON_APB_RTC4M_1_CFG, [0x402E012C] */
#define BIT_AON_APB_RTC4M1_RSV(x)                           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_RTC4M1_I_C(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_RTC4M1_CAL_DONE                         ( BIT(6) )
#define BIT_AON_APB_RTC4M1_CAL_START                        ( BIT(5) )
#define BIT_AON_APB_RTC4M1_CHOP_EN                          ( BIT(4) )
#define BIT_AON_APB_RTC4M1_FORCE_EN                         ( BIT(1) )
#define BIT_AON_APB_RTC4M1_AUTO_GATE_EN                     ( BIT(0) )

/* bits definitions for REG_AON_APB_APB_RST2, [0x402E0130] */
#define BIT_AON_APB_MM_VSP_DJTAG_SOFT_RST                   ( BIT(30) )
#define BIT_AON_APB_WCN_DJTAG_SOFT_RST                      ( BIT(29) )
#define BIT_AON_APB_DISP_DJTAG_SOFT_RST                     ( BIT(28) )
#define BIT_AON_APB_OTG_PHY_SOFT_RST                        ( BIT(27) )
#define BIT_AON_APB_AP_INTC5_SOFT_RST                       ( BIT(26) )
#define BIT_AON_APB_AP_INTC4_SOFT_RST                       ( BIT(25) )
#define BIT_AON_APB_AP_INTC3_SOFT_RST                       ( BIT(24) )
#define BIT_AON_APB_AP_INTC2_SOFT_RST                       ( BIT(23) )
#define BIT_AON_APB_AP_INTC1_SOFT_RST                       ( BIT(22) )
#define BIT_AON_APB_AP_INTC0_SOFT_RST                       ( BIT(21) )
#define BIT_AON_APB_SCC_SOFT_RST                            ( BIT(20) )
#define BIT_AON_APB_THM1_SOFT_RST                           ( BIT(19) )
#define BIT_AON_APB_BSMTMR_SOFT_RST                         ( BIT(18) )
#define BIT_AON_APB_WTLCP_TDSP_CORE_SRST                    ( BIT(17) )
#define BIT_AON_APB_WTLCP_LDSP_CORE_SRST                    ( BIT(16) )
#define BIT_AON_APB_CA53_DJTAG_SOFT_RST                     ( BIT(15) )
#define BIT_AON_APB_ANLG_SOFT_RST                           ( BIT(14) )
#define BIT_AON_APB_SERDES_DPHY_APB_SOFT_RST                ( BIT(13) )
#define BIT_AON_APB_BUSMON_DMA_SOFT_RST                     ( BIT(12) )
#define BIT_AON_APB_SERDES_DPHY_SOFT_RST                    ( BIT(11) )
#define BIT_AON_APB_CROSS_TRIG_SOFT_RST                     ( BIT(10) )
#define BIT_AON_APB_DBG_DJTAG_SOFT_RST                      ( BIT(9) )
#define BIT_AON_APB_DBG_SOFT_RST                            ( BIT(8) )
#define BIT_AON_APB_DJTAG_SOFT_RST                          ( BIT(7) )
#define BIT_AON_APB_AON_DJTAG_SOFT_RST                      ( BIT(6) )
#define BIT_AON_APB_PUB_DJTAG_SOFT_RST                      ( BIT(5) )
#define BIT_AON_APB_GPU_DJTAG_SOFT_RST                      ( BIT(4) )
#define BIT_AON_APB_MM_DJTAG_SOFT_RST                       ( BIT(3) )
#define BIT_AON_APB_PUBCP_DJTAG_SOFT_RST                    ( BIT(2) )
#define BIT_AON_APB_WTLCP_DJTAG_SOFT_RST                    ( BIT(1) )
#define BIT_AON_APB_AP_DJTAG_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_AON_APB_CLK_EB0, [0x402E0134] */
#define BIT_AON_APB_ALL_PLL_TEST_EB                         ( BIT(18) )
#define BIT_AON_APB_LVDSRF_CALI_EB                          ( BIT(17) )
#define BIT_AON_APB_RFTI2_XO_EB                             ( BIT(15) )
#define BIT_AON_APB_RFTI_LTH_EB                             ( BIT(14) )
#define BIT_AON_APB_RFTI1_XO_EB                             ( BIT(13) )
#define BIT_AON_APB_RFTI_SBI_EB                             ( BIT(12) )
#define BIT_AON_APB_TMR_EB                                  ( BIT(11) )
#define BIT_AON_APB_DET_32K_EB                              ( BIT(10) )
#define BIT_AON_APB_AP_HS_SPI_EB                            ( BIT(9) )
#define BIT_AON_APB_CSSYS_CA53_EB                           ( BIT(8) )

/* bits definitions for REG_AON_APB_AON_SDIO, [0x402E0138] */
#define BIT_AON_APB_CP_SDIO_ENABLE                          ( BIT(2) )
#define BIT_AON_APB_AP_SDIO_ENABLE                          ( BIT(1) )
#define BIT_AON_APB_SDIO_MODULE_SEL                         ( BIT(0) )

/* bits definitions for REG_AON_APB_MPLL_CTRL, [0x402E013C] */
#define BIT_AON_APB_CGM_MPLL_CA53_FORCE_EN                  ( BIT(9) )
#define BIT_AON_APB_CGM_MPLL_CA53_AUTO_GATE_SEL             ( BIT(8) )
#define BIT_AON_APB_MPLL_WAIT_FORCE_EN                      ( BIT(2) )
#define BIT_AON_APB_MPLL_WAIT_AUTO_GATE_SEL                 ( BIT(1) )

/* bits definitions for REG_AON_APB_BMPLL_CTRL, [0x402E0140] */
#define BIT_AON_APB_CGM_BMPLL_FORCE_EN                      ( BIT(9) )
#define BIT_AON_APB_CGM_BMPLL_AUTO_GATE_SEL                 ( BIT(8) )
#define BIT_AON_APB_BMPLL_WAIT_FORCE_EN                     ( BIT(2) )
#define BIT_AON_APB_BMPLL_WAIT_AUTO_GATE_SEL                ( BIT(1) )

/* bits definitions for REG_AON_APB_RPLL_CFG1, [0x402E0158] */
#define BIT_AON_APB_RPLL_LOCK_DONE                          ( BIT(21) )
#define BIT_AON_APB_RPLL_DIV_S                              ( BIT(20) )
#define BIT_AON_APB_RPLL_MOD_EN                             ( BIT(19) )
#define BIT_AON_APB_RPLL_SDM_EN                             ( BIT(18) )
#define BIT_AON_APB_RPLL_LPF(x)                             ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AON_APB_RPLL_REFIN(x)                           ( (x) << 13 & (BIT(13)|BIT(14)) )
#define BIT_AON_APB_RPLL_IBIAS(x)                           ( (x) << 11 & (BIT(11)|BIT(12)) )
#define BIT_AON_APB_RPLL_N(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_AON_APB_RPLL_CFG2, [0x402E015C] */
#define BIT_AON_APB_RPLL_NINT(x)                            ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_RPLL_KINT(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_AON_APB_RPLL_CFG3, [0x402E0160] */
#define BIT_AON_APB_RPLL_26M_SEL                            ( BIT(7) )
#define BIT_AON_APB_RPLL_DIV1_EN                            ( BIT(6) )
#define BIT_AON_APB_RPLL_26M_DIV(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_APB_THM0_CTRL, [0x402E0164] */
#define BIT_AON_APB_THM0_CALI_RSVD(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_THM1_CTRL, [0x402E0168] */
#define BIT_AON_APB_THM1_CALI_RSVD(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_BUSMON_DMA_CFG, [0x402E0170] */
#define BIT_AON_APB_BUSMON_DMA_CNT_START                    ( BIT(0) )

/* bits definitions for REG_AON_APB_ANALOG_CFG1, [0x402E0178] */
#define BIT_AON_APB_ANALOG_BB_RSV(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_RPLL_BIST_CTRL, [0x402E017C] */
#define BIT_AON_APB_RPLL_BIST_CNT(x)                        ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_RPLL_BIST_CTRL(x)                       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_AON_APB_RPLL_BIST_EN                            ( BIT(0) )

/* bits definitions for REG_AON_APB_DPLL_CTRL, [0x402E0194] */
#define BIT_AON_APB_MONITOR_DPLL_PRE_DIV_STATUS(x)          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_APB_DPLL_DIV_667M_FORCE_EN                  ( BIT(17) )
#define BIT_AON_APB_DPLL_DIV_667M_AUTO_GATE_SEL             ( BIT(16) )
#define BIT_AON_APB_CGM_DPLL_667M_CA53_FORCE_EN             ( BIT(14) )
#define BIT_AON_APB_CGM_DPLL_667M_CA53_AUTO_GATE_SEL        ( BIT(13) )
#define BIT_AON_APB_CGM_DPLL_41M7_AON_FORCE_EN              ( BIT(10) )
#define BIT_AON_APB_CGM_DPLL_41M7_AON_AUTO_GATE_SEL         ( BIT(9) )
#define BIT_AON_APB_CGM_DPLL_AP_FORCE_EN                    ( BIT(6) )
#define BIT_AON_APB_CGM_DPLL_AP_AUTO_GATE_SEL               ( BIT(5) )
#define BIT_AON_APB_DPLL_DIV_41M7_FORCE_EN                  ( BIT(4) )
#define BIT_AON_APB_DPLL_DIV_41M7_AUTO_GATE_SEL             ( BIT(3) )
#define BIT_AON_APB_DPLL_WAIT_FORCE_EN                      ( BIT(2) )
#define BIT_AON_APB_DPLL_WAIT_AUTO_GATE_SEL                 ( BIT(1) )

/* bits definitions for REG_AON_APB_CP_DAP_PAD_CTRL, [0x402E0200] */
#define BIT_AON_APB_CP_DAP_PAD_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_CA53_PROT_CTRL, [0x402E0204] */
#define BIT_AON_APB_CA53_BIG_SPNIDEN                        ( BIT(28) )
#define BIT_AON_APB_CA53_BIG_SPIDEN                         ( BIT(24) )
#define BIT_AON_APB_CA53_BIG_NIDEN                          ( BIT(20) )
#define BIT_AON_APB_CA53_BIG_DBGEN                          ( BIT(16) )

/* bits definitions for REG_AON_APB_CSSYS_CFG, [0x402E0208] */
#define BIT_AON_APB_DAP_DEVICEEN                            ( BIT(31) )
#define BIT_AON_APB_DAP_DBGEN                               ( BIT(30) )
#define BIT_AON_APB_DAP_SPIDBGEN                            ( BIT(29) )
#define BIT_AON_APB_TG_JTAG_EN                              ( BIT(9) )
#define BIT_AON_APB_LTE_JTAG_EN                             ( BIT(8) )
#define BIT_AON_APB_ARM7_JTAG_EN                            ( BIT(7) )
#define BIT_AON_APB_DJTAG_EN                                ( BIT(6) )
#define BIT_AON_APB_AG_JTAG_EN                              ( BIT(5) )
#define BIT_AON_APB_MJTAG_EN                                ( BIT(4) )
#define BIT_AON_APB_CSSYS_NIDEN                             ( BIT(3) )
#define BIT_AON_APB_CSSYS_SPNIDEN                           ( BIT(2) )
#define BIT_AON_APB_CSSYS_SPIDEN                            ( BIT(1) )
#define BIT_AON_APB_CSSYS_DBGEN                             ( BIT(0) )

/* bits definitions for REG_AON_APB_SEC_MUX_DBG_EN, [0x402E020C] */
#define BIT_AON_APB_DAP_DEVICEEN_S                          ( BIT(25) )
#define BIT_AON_APB_DAP_DBGEN_S                             ( BIT(24) )
#define BIT_AON_APB_DAP_SPIDBGEN_S                          ( BIT(23) )
#define BIT_AON_APB_SP_CM4_DBGEN_S                          ( BIT(19) )
#define BIT_AON_APB_CCI_NIDEN_S                             ( BIT(18) )
#define BIT_AON_APB_CCI_SPNIDEN_S                           ( BIT(17) )
#define BIT_AON_APB_CR5_DBGEN_S                             ( BIT(16) )
#define BIT_AON_APB_CR5_NIDEN_S                             ( BIT(15) )
#define BIT_AON_APB_CSSYS_DBGEN_S                           ( BIT(14) )
#define BIT_AON_APB_CSSYS_NIDEN_S                           ( BIT(13) )
#define BIT_AON_APB_CSSYS_SPIDEN_S                          ( BIT(12) )
#define BIT_AON_APB_CSSYS_SPNIDEN_S                         ( BIT(11) )
#define BIT_AON_APB_CA53_BIG_DBGEN_S                        ( BIT(10) )
#define BIT_AON_APB_CA53_BIG_NIDEN_S                        ( BIT(9) )
#define BIT_AON_APB_CA53_BIG_SPIDEN_S                       ( BIT(8) )
#define BIT_AON_APB_CA53_BIG_SPNIDEN_S                      ( BIT(7) )
#define BIT_AON_APB_CA53_LIT_DBGEN_S                        ( BIT(6) )
#define BIT_AON_APB_CA53_LIT_NIDEN_S                        ( BIT(5) )
#define BIT_AON_APB_CA53_LIT_SPIDEN_S                       ( BIT(4) )
#define BIT_AON_APB_CA53_LIT_SPNIDEN_S                      ( BIT(3) )
#define BIT_AON_APB_DJTAG_EN_S                              ( BIT(2) )
#define BIT_AON_APB_AG_JTAG_EN_S                            ( BIT(1) )
#define BIT_AON_APB_MJTAG_EN_S                              ( BIT(0) )

/* bits definitions for REG_AON_APB_CR5_PROT_CTRL, [0x402E0210] */
#define BIT_AON_APB_CR5_NIDEN                               ( BIT(1) )
#define BIT_AON_APB_CR5_DBGEN                               ( BIT(0) )

/* bits definitions for REG_AON_APB_DBG_DJTAG_CTRL, [0x402E0214] */
#define BIT_AON_APB_DBGSYS_CSSYS_STM_NSGUAREN               ( BIT(0) )

/* bits definitions for REG_AON_APB_CCI_PROT_CTRL, [0x402E0218] */
#define BIT_AON_APB_CCI_NIDEN                               ( BIT(1) )
#define BIT_AON_APB_CCI_SPNIDEN                             ( BIT(0) )

/* bits definitions for REG_AON_APB_CA53_COMM_CTRL, [0x402E021C] */
#define BIT_AON_APB_CA53_BIG_ACINATCM                       ( BIT(26) )
#define BIT_AON_APB_CA53_BIG_DBGL1RSTDISABLE                ( BIT(25) )
#define BIT_AON_APB_CA53_BIG_L2RSTDISABLE                   ( BIT(24) )
#define BIT_AON_APB_CA53_BIG_CFGTE(x)                       ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_CA53_BIG_AA64NAA32(x)                   ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_CA53_LIT_CRYPTO_DISABLE(x)              ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AON_APB_CA53_LIT_ACINATCM                       ( BIT(10) )
#define BIT_AON_APB_CA53_LIT_DBGL1RSTDISABLE                ( BIT(9) )
#define BIT_AON_APB_CA53_LIT_L2RSTDISABLE                   ( BIT(8) )
#define BIT_AON_APB_CA53_LIT_CFGTE(x)                       ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_CA53_LIT_AA64NAA32(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_DESPLL_CFG1, [0x402E0220] */
#define BIT_AON_APB_DSK_MODE_AON                            ( BIT(0) )

/* bits definitions for REG_AON_APB_WTLCP_CTRL, [0x402E0240] */
#define BIT_AON_APB_WTLCP_AON_FRC_WSYS_LT_STOP              ( BIT(4) )
#define BIT_AON_APB_WTLCP_AON_FRC_WSYS_STOP                 ( BIT(3) )

/* bits definitions for REG_AON_APB_WTL_WCDMA_EB, [0x402E0244] */
#define BIT_AON_APB_WTLCP_WCMDA_EB                          ( BIT(16) )
#define BIT_AON_APB_WCDMA_AUTO_GATE_EN                      ( BIT(8) )

/* bits definitions for REG_AON_APB_WTLCP_LDSP_CTRL0, [0x402E0248] */
#define BIT_AON_APB_WTLCP_LDSP_BOOT_VECTOR(x)               ( (x) )

/* bits definitions for REG_AON_APB_WTLCP_LDSP_CTRL1, [0x402E024C] */
#define BIT_AON_APB_WTLCP_STCK_LDSP                         ( BIT(13) )
#define BIT_AON_APB_WTLCP_STMS_LDSP                         ( BIT(12) )
#define BIT_AON_APB_WTLCP_STDO_LDSP                         ( BIT(11) )
#define BIT_AON_APB_WTLCP_STDI_LDSP                         ( BIT(10) )
#define BIT_AON_APB_WTLCP_STRTCK_LDSP                       ( BIT(9) )
#define BIT_AON_APB_WTLCP_SW_JTAG_ENA_LDSP                  ( BIT(8) )
#define BIT_AON_APB_WTLCP_LDSP_EXTERNAL_WAIT                ( BIT(1) )
#define BIT_AON_APB_WTLCP_LDSP_BOOT                         ( BIT(0) )

/* bits definitions for REG_AON_APB_WTLCP_TDSP_CTRL0, [0x402E0250] */
#define BIT_AON_APB_WTLCP_TDSP_BOOT_VECTOR(x)               ( (x) )

/* bits definitions for REG_AON_APB_WTLCP_TDSP_CTRL1, [0x402E0254] */
#define BIT_AON_APB_WTLCP_STCK_TDSP                         ( BIT(13) )
#define BIT_AON_APB_WTLCP_STMS_TDSP                         ( BIT(12) )
#define BIT_AON_APB_WTLCP_STDO_TDSP                         ( BIT(11) )
#define BIT_AON_APB_WTLCP_STDI_TDSP                         ( BIT(10) )
#define BIT_AON_APB_WTLCP_STRTCK_TDSP                       ( BIT(9) )
#define BIT_AON_APB_WTLCP_SW_JTAG_ENA_TDSP                  ( BIT(8) )
#define BIT_AON_APB_WTLCP_TDSP_EXTERNAL_WAIT                ( BIT(1) )
#define BIT_AON_APB_WTLCP_TDSP_BOOT                         ( BIT(0) )

/* bits definitions for REG_AON_APB_GPU_IOJTAG_CTRL0, [0x402E025C] */
#define BIT_AON_APB_GPU_FW_STCK_TDSP                        ( BIT(13) )
#define BIT_AON_APB_GPU_FW_STMS_TDSP                        ( BIT(12) )
#define BIT_AON_APB_GPU_FW_STDO_TDSP                        ( BIT(11) )
#define BIT_AON_APB_GPU_FW_STDI_TDSP                        ( BIT(10) )
#define BIT_AON_APB_GPU_FW_STRTCK_TDSP                      ( BIT(9) )
#define BIT_AON_APB_GPU_FW_SW_JTAG_ENA_TDSP                 ( BIT(8) )

/* bits definitions for REG_AON_APB_PCP_AON_EB, [0x402E0280] */
#define BIT_AON_APB_PUBCP_SYST_RTC_EB                       ( BIT(11) )
#define BIT_AON_APB_PUBCP_TMR_EB                            ( BIT(10) )
#define BIT_AON_APB_PUBCP_TMR_RTC_EB                        ( BIT(9) )
#define BIT_AON_APB_PUBCP_SYST_EB                           ( BIT(8) )
#define BIT_AON_APB_PUBCP_WDG_EB                            ( BIT(7) )
#define BIT_AON_APB_PUBCP_WDG_RTC_EB                        ( BIT(6) )
#define BIT_AON_APB_PUBCP_ARCH_RTC_EB                       ( BIT(5) )
#define BIT_AON_APB_PUBCP_EIC_EB                            ( BIT(4) )
#define BIT_AON_APB_PUBCP_EIC_RTCDV5_EB                     ( BIT(3) )
#define BIT_AON_APB_PUBCP_EIC_RTC_EB                        ( BIT(2) )

/* bits definitions for REG_AON_APB_PCP_SOFT_RST, [0x402E0284] */
#define BIT_AON_APB_PUBCP_CR5_CORE_SOFT_RST                 ( BIT(10) )
#define BIT_AON_APB_PUBCP_CR5_DBG_SOFT_RST                  ( BIT(9) )
#define BIT_AON_APB_PUBCP_CR5_ETM_SOFT_RST                  ( BIT(8) )
#define BIT_AON_APB_PUBCP_CR5_MP_SOFT_RST                   ( BIT(7) )
#define BIT_AON_APB_PUBCP_CR5_CS_DBG_SOFT_RST               ( BIT(6) )
#define BIT_AON_APB_PUBCP_TMR_SOFT_RST                      ( BIT(5) )
#define BIT_AON_APB_PUBCP_SYST_SOFT_RST                     ( BIT(4) )
#define BIT_AON_APB_PUBCP_WDG_SOFT_RST                      ( BIT(3) )
#define BIT_AON_APB_PUBCP_EIC_SOFT_RST                      ( BIT(2) )

/* bits definitions for REG_AON_APB_PUBCP_CTRL, [0x402E0288] */
#define BIT_AON_APB_AON_ACCESS_PUBCP                        ( BIT(13) )
#define BIT_AON_APB_PUBCP_CR5_STANDBYWFI_N                  ( BIT(12) )
#define BIT_AON_APB_PUBCP_CR5_STANDBYWFE_N                  ( BIT(11) )
#define BIT_AON_APB_PUBCP_CR5_CLKSTOPPED0_N                 ( BIT(10) )
#define BIT_AON_APB_PUBCP_CR5_L2IDLE                        ( BIT(9) )
#define BIT_AON_APB_PUBCP_CR5_VALIRQ0_N                     ( BIT(8) )
#define BIT_AON_APB_PUBCP_CR5_VALFIQ0_N                     ( BIT(7) )
#define BIT_AON_APB_PUBCP_CR5_STOP                          ( BIT(6) )
#define BIT_AON_APB_PUBCP_CR5_CSYSACK_ATB                   ( BIT(5) )
#define BIT_AON_APB_PUBCP_CR5_CACTIVE_ATB                   ( BIT(4) )
#define BIT_AON_APB_PUBCP_CR5_CSSYNC_REQ                    ( BIT(3) )
#define BIT_AON_APB_PUBCP_CR5_CSYSREQ_ATB                   ( BIT(2) )
#define BIT_AON_APB_PUBCP_CR5_NODBGCLK                      ( BIT(1) )
#define BIT_AON_APB_PUBCP_CR5_CFGEE                         ( BIT(0) )

/* bits definitions for REG_AON_APB_MDAR_HSDL_CFG, [0x402E02B4] */
#define BIT_AON_APB_MDAR_HSDL_CFG(x)                        ( (x) )

/* bits definitions for REG_AON_APB_SUBSYS_DBG_CFG, [0x402E02BC] */
#define BIT_AON_APB_SUBSYS_DBG_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_APB_AP_LPC_CTRL, [0x402E02C0] */
#define BIT_AON_APB_AP_FRC_STOP_ACK                         ( BIT(8) )
#define BIT_AON_APB_AP_FRC_STOP_REQ                         ( BIT(0) )

/* bits definitions for REG_AON_APB_WTLCP_LPC_CTRL, [0x402E02C4] */
#define BIT_AON_APB_WTLCP_FRC_STOP_ACK                      ( BIT(8) )
#define BIT_AON_APB_WTLCP_FRC_STOP_REQ                      ( BIT(0) )

/* bits definitions for REG_AON_APB_PUBCP_LPC_CTRL, [0x402E02C8] */
#define BIT_AON_APB_PUBCP_FRC_STOP_ACK                      ( BIT(8) )
#define BIT_AON_APB_PUBCP_FRC_STOP_REQ                      ( BIT(0) )

/* bits definitions for REG_AON_APB_WCN_LPC_CTRL, [0x402E02CC] */
#define BIT_AON_APB_WCN_FRC_STOP_ACK                        ( BIT(8) )
#define BIT_AON_APB_WCN_FRC_STOP_REQ                        ( BIT(0) )

/* bits definitions for REG_AON_APB_MDAR_SOFT_RST, [0x402E02D0] */
#define BIT_AON_APB_LVDSRF_CALI_SOFT_RST                    ( BIT(3) )
#define BIT_AON_APB_RFTI_LTH_SOFT_RST                       ( BIT(1) )
#define BIT_AON_APB_RFTI_SBI_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_AON_APB_GLB_WCDMA_CTRL, [0x402E0300] */

/* bits definitions for REG_AON_APB_PLL_CLKOUT_GATE, [0x402E0400] */
#define BIT_AON_APB_BMPLL_CLKOUT_EN                         ( BIT(31) )
#define BIT_AON_APB_RTC4M0_EN                               ( BIT(30) )
#define BIT_AON_APB_LPLL_CLKOUT_EN                          ( BIT(29) )
#define BIT_AON_APB_LPLL_DIV1_EN                            ( BIT(28) )
#define BIT_AON_APB_LPLL_DIV2_EN                            ( BIT(27) )
#define BIT_AON_APB_LPLL_DIV3_EN                            ( BIT(26) )
#define BIT_AON_APB_LPLL_DIV5_EN                            ( BIT(25) )
#define BIT_AON_APB_TWPLL_CLKOUT_EN                         ( BIT(24) )
#define BIT_AON_APB_TWPLL_DIV1_EN                           ( BIT(23) )
#define BIT_AON_APB_TWPLL_DIV2_EN                           ( BIT(22) )
#define BIT_AON_APB_TWPLL_DIV3_EN                           ( BIT(21) )
#define BIT_AON_APB_TWPLL_DIV5_EN                           ( BIT(20) )
#define BIT_AON_APB_TWPLL_DIV7_EN                           ( BIT(19) )
#define BIT_AON_APB_GPLL_CLKOUT_EN                          ( BIT(18) )
#define BIT_AON_APB_DPLL_CLKOUT_EN                          ( BIT(17) )
#define BIT_AON_APB_MPLL_CLKOUT_EN                          ( BIT(16) )
#define BIT_AON_APB_BMPLL_CLKOUT_AUTO_GATE_DIS              ( BIT(15) )
#define BIT_AON_APB_LPLL_CLKOUT_AUTO_GATE_DIS               ( BIT(13) )
#define BIT_AON_APB_LPLL_DIV1_AUTO_GATE_DIS                 ( BIT(12) )
#define BIT_AON_APB_LPLL_DIV2_AUTO_GATE_DIS                 ( BIT(11) )
#define BIT_AON_APB_LPLL_DIV3_AUTO_GATE_DIS                 ( BIT(10) )
#define BIT_AON_APB_LPLL_DIV5_AUTO_GATE_DIS                 ( BIT(9) )
#define BIT_AON_APB_TWPLL_CLKOUT_AUTO_GATE_DIS              ( BIT(8) )
#define BIT_AON_APB_TWPLL_DIV1_AUTO_GATE_DIS                ( BIT(7) )
#define BIT_AON_APB_TWPLL_DIV2_AUTO_GATE_DIS                ( BIT(6) )
#define BIT_AON_APB_TWPLL_DIV3_AUTO_GATE_DIS                ( BIT(5) )
#define BIT_AON_APB_TWPLL_DIV5_AUTO_GATE_DIS                ( BIT(4) )
#define BIT_AON_APB_TWPLL_DIV7_AUTO_GATE_DIS                ( BIT(3) )
#define BIT_AON_APB_GPLL_CLKOUT_AUTO_GATE_DIS               ( BIT(2) )
#define BIT_AON_APB_DPLL_CLKOUT_AUTO_GATE_DIS               ( BIT(1) )
#define BIT_AON_APB_MPLL_CLKOUT_AUTO_GATE_DIS               ( BIT(0) )

/* bits definitions for REG_AON_APB_HM_CFG_SEL, [0x402E0404] */
#define BIT_AON_APB_BMPLL_CFG_SEL                           ( BIT(13) )
#define BIT_AON_APB_MDAR_PMU_RPLL_CFG_SEL                   ( BIT(12) )
#define BIT_AON_APB_LVDSRF_CFG_SEL                          ( BIT(11) )
#define BIT_AON_APB_LVDSRF_PLL_CFG_SEL                      ( BIT(10) )
#define BIT_AON_APB_RPLL_CFG_SEL                            ( BIT(9) )
#define BIT_AON_APB_LPLL_CFG_SEL                            ( BIT(8) )
#define BIT_AON_APB_TWPLL_CFG_SEL                           ( BIT(7) )
#define BIT_AON_APB_GPLL_CFG_SEL                            ( BIT(6) )
#define BIT_AON_APB_DPLL_CFG_SEL                            ( BIT(5) )
#define BIT_AON_APB_MPLL_CFG_SEL                            ( BIT(4) )
#define BIT_AON_APB_RTC4M0_CFG_SEL                          ( BIT(3) )
#define BIT_AON_APB_AAPC_CFG_SEL                            ( BIT(2) )
#define BIT_AON_APB_BB_BG_CFG_SEL                           ( BIT(1) )
#define BIT_AON_APB_XTAL_SIN_CFG_SEL                        ( BIT(0) )

/* bits definitions for REG_AON_APB_HM_PWR_CTRL, [0x402E0408] */
#define BIT_AON_APB_M_AAPC_PD                               ( BIT(16) )
#define BIT_AON_APB_S_AAPC_PD                               ( BIT(15) )
#define BIT_AON_APB_DESPLL_PD                               ( BIT(14) )
#define BIT_AON_APB_BMPLL_PD                                ( BIT(13) )
#define BIT_AON_APB_CPPLL_PD                                ( BIT(12) )
#define BIT_AON_APB_LVDSRF_PD                               ( BIT(11) )
#define BIT_AON_APB_LVDSRF_PLL_PD                           ( BIT(10) )
#define BIT_AON_APB_RPLL_PD                                 ( BIT(9) )
#define BIT_AON_APB_LPLL_PD                                 ( BIT(8) )
#define BIT_AON_APB_TWPLL_PD                                ( BIT(7) )
#define BIT_AON_APB_GPLL_PD                                 ( BIT(6) )
#define BIT_AON_APB_DPLL_PD                                 ( BIT(5) )
#define BIT_AON_APB_MPLL_PD                                 ( BIT(4) )
#define BIT_AON_APB_AAPC_PD                                 ( BIT(3) )
#define BIT_AON_APB_BB_BG_PD                                ( BIT(2) )
#define BIT_AON_APB_XTAL_32M_BUF_PD                         ( BIT(1) )
#define BIT_AON_APB_XTAL_26M_BUF_PD                         ( BIT(0) )

/* bits definitions for REG_AON_APB_HM_RST_CTRL, [0x402E040C] */
#define BIT_AON_APB_DESPLL_RST                              ( BIT(14) )
#define BIT_AON_APB_BMPLL_RST                               ( BIT(13) )
#define BIT_AON_APB_CPPLL_RST                               ( BIT(12) )
#define BIT_AON_APB_LVDSRF_RST                              ( BIT(11) )
#define BIT_AON_APB_LVDSRF_PLL_RST                          ( BIT(10) )
#define BIT_AON_APB_RPLL_RST                                ( BIT(9) )
#define BIT_AON_APB_LPLL_RST                                ( BIT(8) )
#define BIT_AON_APB_TWPLL_RST                               ( BIT(7) )
#define BIT_AON_APB_GPLL_RST                                ( BIT(6) )
#define BIT_AON_APB_DPLL_RST                                ( BIT(5) )
#define BIT_AON_APB_MPLL_RST                                ( BIT(4) )
#define BIT_AON_APB_RTC4M0_RST                              ( BIT(3) )
#define BIT_AON_APB_BB_BG_RST                               ( BIT(1) )

/* bits definitions for REG_AON_APB_M_AAPC_CFG, [0x402E0420] */
#define BIT_AON_APB_AAPC_G1(x)                              ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_AON_APB_AAPC_G0(x)                              ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_AON_APB_AAPC_SEL                                ( BIT(21) )
#define BIT_AON_APB_AAPC_BPRES                              ( BIT(20) )
#define BIT_AON_APB_APCOUT_SEL                              ( BIT(15) )
#define BIT_AON_APB_AAPC_LOW_V_CON                          ( BIT(14) )
#define BIT_AON_APB_AAPC_D(x)                               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_AON_APB_DAP_DJTAG_CTRL, [0x402E0430] */
#define BIT_AON_APB_DAP_DBGPWRUP_SOFT_EN                    ( BIT(2) )
#define BIT_AON_APB_DAP_SYSPWRUP_SOFT_EN                    ( BIT(1) )
#define BIT_AON_APB_DAP_DJTAG_EN                            ( BIT(0) )

/* bits definitions for REG_AON_APB_CGM_REG1, [0x402E0440] */
#define BIT_AON_APB_LTE_PCCSCC_RFTI_CLK_SW_CFG(x)           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_LPLL1_CLKOUT_SW                         ( BIT(23) )
#define BIT_AON_APB_LPLL0_CLKOUT_SW                         ( BIT(22) )

/* bits definitions for REG_AON_APB_TOP_LPC0, [0x402E0500] */
#define BIT_AON_APB_TOP_LPC0_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC0_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC0_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC0_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_TOP_LPC1, [0x402E0504] */
#define BIT_AON_APB_TOP_LPC1_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC1_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC1_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC1_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_TOP_LPC2, [0x402E0508] */
#define BIT_AON_APB_TOP_LPC2_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC2_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC2_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC2_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_TOP_LPC3, [0x402E050C] */
#define BIT_AON_APB_TOP_LPC3_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC3_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC3_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC3_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_OVERHEAT_RST_CTRL, [0x402E0510] */
#define BIT_AON_APB_OVERHEAT_RST_DDIE_EN                    ( BIT(0) )

/* bits definitions for REG_AON_APB_TOP_LPC4, [0x402E0520] */
#define BIT_AON_APB_TOP_LPC4_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC4_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC4_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC4_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_TOP_LPC5, [0x402E0524] */
#define BIT_AON_APB_TOP_LPC5_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC5_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC5_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC5_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_TOP_LPC6, [0x402E0528] */
#define BIT_AON_APB_TOP_LPC6_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC6_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC6_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC6_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_TOP_LPC7, [0x402E052C] */
#define BIT_AON_APB_TOP_LPC7_ACTIVE_SYNC_SEL                ( BIT(18) )
#define BIT_AON_APB_TOP_LPC7_LP_REQ                         ( BIT(17) )
#define BIT_AON_APB_TOP_LPC7_EB                             ( BIT(16) )
#define BIT_AON_APB_TOP_LPC7_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_PUBCP_SIM0_TOP_CTRL, [0x402E0540] */
#define BIT_AON_APB_CP_SIM0_CLK_PL                          ( BIT(5) )
#define BIT_AON_APB_CP_SIM0_DETECT_EN                       ( BIT(4) )
#define BIT_AON_APB_CP_BAT0_DETECT_EN                       ( BIT(3) )
#define BIT_AON_APB_CP_SIM0_DETECT_POL                      ( BIT(2) )
#define BIT_AON_APB_CP_BAT0_DETECT_POL                      ( BIT(1) )
#define BIT_AON_APB_CP_SIM0_OFF_PD_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PUBCP_SIM1_TOP_CTRL, [0x402E0544] */
#define BIT_AON_APB_CP_SIM1_CLK_PL                          ( BIT(5) )
#define BIT_AON_APB_CP_SIM1_DETECT_EN                       ( BIT(4) )
#define BIT_AON_APB_CP_BAT1_DETECT_EN                       ( BIT(3) )
#define BIT_AON_APB_CP_SIM1_DETECT_POL                      ( BIT(2) )
#define BIT_AON_APB_CP_BAT1_DETECT_POL                      ( BIT(1) )
#define BIT_AON_APB_CP_SIM1_OFF_PD_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_PUBCP_SIM2_TOP_CTRL, [0x402E0548] */
#define BIT_AON_APB_CP_SIM2_CLK_PL                          ( BIT(5) )
#define BIT_AON_APB_CP_SIM2_DETECT_EN                       ( BIT(4) )
#define BIT_AON_APB_CP_BAT2_DETECT_EN                       ( BIT(3) )
#define BIT_AON_APB_CP_SIM2_DETECT_POL                      ( BIT(2) )
#define BIT_AON_APB_CP_BAT2_DETECT_POL                      ( BIT(1) )
#define BIT_AON_APB_CP_SIM2_OFF_PD_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_AP_SIM_TOP_CTRL, [0x402E054C] */
#define BIT_AON_APB_AP_SIM_CLK_PL                           ( BIT(5) )
#define BIT_AON_APB_AP_SIM_DETECT_EN                        ( BIT(4) )
#define BIT_AON_APB_AP_BAT_DETECT_EN                        ( BIT(3) )
#define BIT_AON_APB_AP_SIM_DETECT_POL                       ( BIT(2) )
#define BIT_AON_APB_AP_BAT_DETECT_POL                       ( BIT(1) )
#define BIT_AON_APB_AP_SIM_OFF_PD_EN                        ( BIT(0) )

/* bits definitions for REG_AON_APB_WCN_DIG_IN_CLK_SEL, [0x402E0570] */
#define BIT_AON_APB_WCN_DOUT_TSEN_SDADC_SEL                 ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_CTRL_0, [0x402E0600] */
#define BIT_AON_APB_CA53_ARQOSARB_GPU_CCI(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_CA53_AWREGION_GPU_CCI(x)                ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_CA53_ARREGION_GPU_CCI(x)                ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB7                       ( BIT(15) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB6                       ( BIT(14) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB5                       ( BIT(13) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB4                       ( BIT(12) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB3                       ( BIT(11) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB2                       ( BIT(10) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB1                       ( BIT(9) )
#define BIT_AON_APB_CA53_CSYSREQ_ATB0                       ( BIT(8) )
#define BIT_AON_APB_CA53_CCI_CSYSREQ                        ( BIT(7) )
#define BIT_AON_APB_CA53_GICDISABLE                         ( BIT(4) )
#define BIT_AON_APB_CA53_GIC_SOFT_RST                       ( BIT(3) )
#define BIT_AON_APB_CA53_TRACE2LVDS_SOFT_RST                ( BIT(2) )
#define BIT_AON_APB_CA53_CSSYS_SOFT_RST                     ( BIT(1) )
#define BIT_AON_APB_CA53_CCI_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_CTRL_1, [0x402E0604] */
#define BIT_AON_APB_CA53_AW_QOS_RSV(x)                      ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_CA53_AR_QOS_RSV(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for REG_AON_APB_A53_BIGCORE_VDROP_RSV, [0x402E0608] */
#define BIT_AON_APB_CA53_BIG_VDROP0_RSV                     ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_LITCORE_VDROP_RSV, [0x402E060C] */
#define BIT_AON_APB_CA53_LIT_VDROP0_EN                      ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_CTRL_2, [0x402E0610] */
#define BIT_AON_APB_CA53_BIG_AUTO_REG_SOFT_TRIG             ( BIT(29) )
#define BIT_AON_APB_CA53_BIG_SMPEN(x)                       ( (x) << 25 & (BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_AON_APB_CA53_BIG_AUTO_REG_TRIG_SEL              ( BIT(24) )
#define BIT_AON_APB_CA53_BIG_AUTO_REG_SAVE_EN               ( BIT(23) )
#define BIT_AON_APB_CA53_BIG_EDBGRQ(x)                      ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_APB_CA53_BIG_DBG_EN                         ( BIT(18) )
#define BIT_AON_APB_CA53_BIG_ATB_EN                         ( BIT(17) )
#define BIT_AON_APB_CA53_BIG_CORE_EN                        ( BIT(16) )
#define BIT_AON_APB_CA53_LIT_AUTO_REG_SOFT_TRIG             ( BIT(13) )
#define BIT_AON_APB_CA53_LIT_SMPEN(x)                       ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_AON_APB_CA53_LIT_AUTO_REG_TRIG_SEL              ( BIT(8) )
#define BIT_AON_APB_CA53_LIT_AUTO_REG_SAVE_EN               ( BIT(7) )
#define BIT_AON_APB_CA53_LIT_EDBGRQ(x)                      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_APB_CA53_LIT_DBG_EN                         ( BIT(2) )
#define BIT_AON_APB_CA53_LIT_ATB_EN                         ( BIT(1) )
#define BIT_AON_APB_CA53_LIT_CORE_EN                        ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_CTRL_3, [0x402E0614] */
#define BIT_AON_APB_CA53_GIC_IRQOUT(x)                      ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_APB_CA53_GIC_FIQOUT(x)                      ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_APB_CA53_CLK_CCI_EN                         ( BIT(6) )
#define BIT_AON_APB_CA53_CLK_CSSYS_EN                       ( BIT(1) )
#define BIT_AON_APB_CA53_CLK_GIC_EN                         ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_CTRL_4, [0x402E0618] */
#define BIT_AON_APB_CA53_BIG_CTIIRQACK(x)                   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_APB_CA53_BIG_STANDBYWFE(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_CA53_BIG_STANDBYWFI(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_APB_CA53_LIT_CTIIRQACK(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_CA53_LIT_STANDBYWFE(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_CA53_LIT_STANDBYWFI(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_A53_CTRL_5, [0x402E061C] */
#define BIT_AON_APB_CA53_BIG_L2VICTIRAM_LIGHT_SLEEP         ( BIT(24) )
#define BIT_AON_APB_CA53_BIG_L2DATARAM_LIGHT_SLEEP          ( BIT(23) )
#define BIT_AON_APB_CA53_BIG_L2FLUSHDONE                    ( BIT(22) )
#define BIT_AON_APB_CA53_BIG_L2FLUSHREQ                     ( BIT(21) )
#define BIT_AON_APB_CA53_BIG_L2QDENY                        ( BIT(20) )
#define BIT_AON_APB_CA53_BIG_L2QACCEPT_N                    ( BIT(19) )
#define BIT_AON_APB_CA53_BIG_L2QREQ_N                       ( BIT(18) )
#define BIT_AON_APB_CA53_BIG_L2QACTIVE                      ( BIT(17) )
#define BIT_AON_APB_CA53_BIG_L2_STANDBYWFI                  ( BIT(16) )
#define BIT_AON_APB_CA53_LIT_L2VICTIRAM_LIGHT_SLEEP         ( BIT(8) )
#define BIT_AON_APB_CA53_LIT_L2DATARAM_LIGHT_SLEEP          ( BIT(7) )
#define BIT_AON_APB_CA53_LIT_L2FLUSHDONE                    ( BIT(6) )
#define BIT_AON_APB_CA53_LIT_L2FLUSHREQ                     ( BIT(5) )
#define BIT_AON_APB_CA53_LIT_L2QDENY                        ( BIT(4) )
#define BIT_AON_APB_CA53_LIT_L2QACCEPT_N                    ( BIT(3) )
#define BIT_AON_APB_CA53_LIT_L2QREQ_N                       ( BIT(2) )
#define BIT_AON_APB_CA53_LIT_L2QACTIVE                      ( BIT(1) )
#define BIT_AON_APB_CA53_LIT_L2_STANDBYWFI                  ( BIT(0) )

/* bits definitions for REG_AON_APB_A53_CTRL_6, [0x402E0620] */
#define BIT_AON_APB_APCPU_SCU_POR_SOFT_RST                  ( BIT(22) )
#define BIT_AON_APB_APCPU_NIC_TOP_SOFT_RST                  ( BIT(21) )
#define BIT_AON_APB_APCPU_NIC_GIC_SOFT_RST                  ( BIT(20) )
#define BIT_AON_APB_APCPU_NIC_ACE_SOFT_RST                  ( BIT(19) )
#define BIT_AON_APB_APCPU_ASYNC_DDR_SOFT_RST                ( BIT(18) )
#define BIT_AON_APB_APCPU_ASYNC_AP_SOFT_RST                 ( BIT(17) )
#define BIT_AON_APB_APCPU_ASYNC_DAP_SOFT_RST                ( BIT(16) )
#define BIT_AON_APB_APCPU_CSSYS_APB_SOFT_RST                ( BIT(15) )
#define BIT_AON_APB_APCPU_SCU_SOFT_RST                      ( BIT(14) )
#define BIT_AON_APB_APCPU_DEBUG_APB_SOFT_RST                ( BIT(13) )
#define BIT_AON_APB_APCPU_PERIPH_SOFT_RST                   ( BIT(12) )
#define BIT_AON_APB_APCPU_CORE_SOFT_RST(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_APCPU_ATB_SOFT_RST                      ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_INT_INFO, [0x402E0624] */
#define BIT_AON_APB_APCPU_CLUSTER_NFAULTIRQ(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AON_APB_APCPU_CLUSTER_NERRIRQ(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_AON_APB_JVL_DUMMY, [0x402E0628] */
#define BIT_AON_APB_JVL_DUMMY_REG(x)                        ( (x) )

/* bits definitions for REG_AON_APB_JVL_MT_CFG, [0x402E062C] */
#define BIT_AON_APB_JVL_MT_BIG(x)                           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_APB_RESONANCE_CTRL1, [0x402E0630] */
#define BIT_AON_APB_RESONANCE_CTRL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_RESONANCE_CTRL2, [0x402E0634] */
#define BIT_AON_APB_RESONANCE_HI_CNT(x)                     ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_APB_RESONANCE_LO_CNT(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_ASTARTMP, [0x402E0660] */
#define BIT_AON_APB_CPU_ASTARTMP(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_AON_APB_AENDMP, [0x402E0664] */
#define BIT_AON_APB_CPU_AENDMP(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_AON_APB_AWSTASHLPID, [0x402E0668] */
#define BIT_AON_APB_AWSTASHLPIDSS(x)                        ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_AWSTASHLPIDENS                          ( BIT(0) )

/* bits definitions for REG_AON_APB_SUB_SYS_DBG_SIG5, [0x402E0714] */
#define BIT_AON_APB_DBG_MOD_RESERVED(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_DBG_BUS_DATA, [0x402E0740] */
#define BIT_AON_APB_DBG_BUS_PAD_OUT(x)                      ( (x) )

/* bits definitions for REG_AON_APB_PAD_DEBUG_STAT, [0x402E0744] */
#define BIT_AON_APB_VIO_2_MSOUT                             ( BIT(5) )
#define BIT_AON_APB_VSD2_MSOUT                              ( BIT(4) )
#define BIT_AON_APB_VSD0_MSOUT                              ( BIT(3) )
#define BIT_AON_APB_VSIM2_MSOUT                             ( BIT(2) )
#define BIT_AON_APB_VSIM1_MSOUT                             ( BIT(1) )
#define BIT_AON_APB_VSIM0_MSOUT                             ( BIT(0) )

/* bits definitions for REG_AON_APB_EFUSE_BLK2, [0x402E0780] */
#define BIT_AON_APB_EFUSE_BLK2_O(x)                         ( (x) )

/* bits definitions for REG_AON_APB_EFUSE_BLK3, [0x402E0784] */
#define BIT_AON_APB_EFUSE_BLK3_O(x)                         ( (x) )

/* bits definitions for REG_AON_APB_MBIST_EFUSE_CTRL, [0x402E0788] */
#define BIT_AON_APB_FUSEBOX_SEL_CTRL                        ( BIT(1) )
#define BIT_AON_APB_FUSEBOX_SEL_BUF_SW                      ( BIT(0) )

/* bits definitions for REG_AON_APB_FW_INT_STATUS, [0x402E0800] */
#define BIT_AON_APB_MEM_FW_AON_INT_REQ                      ( BIT(10) )
#define BIT_AON_APB_MEM_FW_PUB_INT_REQ                      ( BIT(9) )
#define BIT_AON_APB_MEM_FW_MM_INT_REQ                       ( BIT(8) )
#define BIT_AON_APB_MEM_FW_VSP_INT_REQ                      ( BIT(7) )
#define BIT_AON_APB_MEM_FW_DISP_INT_REQ                     ( BIT(6) )
#define BIT_AON_APB_MEM_FW_AP_INT_REQ                       ( BIT(5) )
#define BIT_AON_APB_MEM_FW_GPU_CPU_CP_INT_REQ               ( BIT(4) )
#define BIT_AON_APB_SLV_FW_AON_INT_REQ                      ( BIT(3) )
#define BIT_AON_APB_SLV_FW_CA53_INT_REQ                     ( BIT(2) )
#define BIT_AON_APB_SLV_FW_AP1_INT_REQ                      ( BIT(1) )
#define BIT_AON_APB_SLV_FW_AP0_INT_REQ                      ( BIT(0) )

/* bits definitions for REG_AON_APB_SIM_RETAIN_CFG, [0x402E0804] */
#define BIT_AON_APB_SIM2_PUPCP_RETAIN_EN                    ( BIT(31) )
#define BIT_AON_APB_SIM2_RST_PUBCP_RETAIN_OUT               ( BIT(28) )
#define BIT_AON_APB_SIM2_DATA_PUBCP_RETAIN_OE               ( BIT(27) )
#define BIT_AON_APB_SIM2_DATA_PUBCP_RETAIN_IE               ( BIT(26) )
#define BIT_AON_APB_SIM2_DATA_PUBCP_RETAIN_OUT              ( BIT(25) )
#define BIT_AON_APB_SIM2_CLK_PUPCP_RETAIN_OUT               ( BIT(24) )
#define BIT_AON_APB_SIM1_PUPCP_RETAIN_EN                    ( BIT(23) )
#define BIT_AON_APB_SIM1_RST_PUBCP_RETAIN_OUT               ( BIT(20) )
#define BIT_AON_APB_SIM1_DATA_PUBCP_RETAIN_OE               ( BIT(19) )
#define BIT_AON_APB_SIM1_DATA_PUBCP_RETAIN_IE               ( BIT(18) )
#define BIT_AON_APB_SIM1_DATA_PUBCP_RETAIN_OUT              ( BIT(17) )
#define BIT_AON_APB_SIM1_CLK_PUPCP_RETAIN_OUT               ( BIT(16) )
#define BIT_AON_APB_SIM0_PUPCP_RETAIN_EN                    ( BIT(15) )
#define BIT_AON_APB_SIM0_RST_PUBCP_RETAIN_OUT               ( BIT(12) )
#define BIT_AON_APB_SIM0_DATA_PUBCP_RETAIN_OE               ( BIT(11) )
#define BIT_AON_APB_SIM0_DATA_PUBCP_RETAIN_IE               ( BIT(10) )
#define BIT_AON_APB_SIM0_DATA_PUBCP_RETAIN_OUT              ( BIT(9) )
#define BIT_AON_APB_SIM0_CLK_PUPCP_RETAIN_OUT               ( BIT(8) )
#define BIT_AON_APB_SIM0_AP_RETAIN_EN                       ( BIT(7) )
#define BIT_AON_APB_SIM0_RST_AP_RETAIN_OUT                  ( BIT(4) )
#define BIT_AON_APB_SIM0_DATA_AP_RETAIN_OE                  ( BIT(3) )
#define BIT_AON_APB_SIM0_DATA_AP_RETAIN_IE                  ( BIT(2) )
#define BIT_AON_APB_SIM0_DATA_AP_RETAIN_OUT                 ( BIT(1) )
#define BIT_AON_APB_SIM0_CLK_AP_RETAIN_OUT                  ( BIT(0) )

/* bits definitions for REG_AON_APB_AUX0_CAL, [0x402E0900] */
#define BIT_AON_APB_AUX0_MAX_RANGE(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_APB_AUX0_MIN_RANGE(x)                       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_AUX0_CAL_EN                             ( BIT(0) )

/* bits definitions for REG_AON_APB_AUX0_RESULT, [0x402E0904] */
#define BIT_AON_APB_AUX0_FREQ(x)                            ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_APB_AUX0_READY                              ( BIT(1) )
#define BIT_AON_APB_AUX0_PASS                               ( BIT(0) )

/* bits definitions for REG_AON_APB_GLB_BUSMON_DEG_EN, [0x402E0A00] */
#define BIT_AON_APB_GLB_BUSMON_DEBUG_EN(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AON_APB_AUD_DIG_MIC_CTRL, [0x402E0A20] */
#define BIT_AON_APB_DMIC_MSEL                               ( BIT(1) )
#define BIT_AON_APB_DMIC_EN2                                ( BIT(0) )

/* bits definitions for REG_AON_APB_EARLY_WAKEUP_EN, [0x402E0A40] */
#define BIT_AON_APB_CACTIVE_PUBCP_ASYNC_BRIDGE_EN           ( BIT(7) )
#define BIT_AON_APB_DAPSYS_AON_MTX_EARLY_WAKEUP_EN          ( BIT(6) )
#define BIT_AON_APB_SPSYS_AON_MTX_EARLY_WAKEUP_EN           ( BIT(5) )
#define BIT_AON_APB_AONDMA_AON_MTX_EARLY_WAKEUP_EN          ( BIT(4) )
#define BIT_AON_APB_WTLCP_AON_MTX_EARLY_WAKEUP_EN           ( BIT(3) )
#define BIT_AON_APB_PUBCP_AON_MTX_EARLY_WAKEUP_EN           ( BIT(2) )
#define BIT_AON_APB_WCNCP_AON_MTX_EARLY_WAKEUP_EN           ( BIT(1) )
#define BIT_AON_APB_APSYS_AON_MTX_EARLY_WAKEUP_EN           ( BIT(0) )

/* bits definitions for REG_AON_APB_AP_WPROT_EN1, [0x402E3004] */
#define BIT_AON_APB_AP_AWADDR_WPROT_EN1(x)                  ( (x) )

/* bits definitions for REG_AON_APB_WTLCP_WPROT_EN1, [0x402E3008] */
#define BIT_AON_APB_WTLCP_AWADDR_WPROT_EN1(x)               ( (x) )

/* bits definitions for REG_AON_APB_PUBCP_WPROT_EN1, [0x402E300C] */
#define BIT_AON_APB_PUBCP_AWADDR_WPROT_EN1(x)               ( (x) )

/* bits definitions for REG_AON_APB_WCNCP_WPROT_EN1, [0x402E3010] */
#define BIT_AON_APB_WCNCP_AWADDR_WPROT_EN1(x)               ( (x) )

/* bits definitions for REG_AON_APB_IO_DLY_CTRL, [0x402E3014] */
#define BIT_AON_APB_CLK_CCIR_DLY_SEL(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_CLK_PUBCPDSP_DLY_SEL(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_CLK_WTLCPDSP_DLY_SEL(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_AP_WPROT_EN0, [0x402E3018] */
#define BIT_AON_APB_AP_AWADDR_WPROT_EN0(x)                  ( (x) )

/* bits definitions for REG_AON_APB_WTLCP_WPROT_EN0, [0x402E3020] */
#define BIT_AON_APB_WTLCP_AWADDR_WPROT_EN0(x)               ( (x) )

/* bits definitions for REG_AON_APB_PUBCP_WPROT_EN0, [0x402E3024] */
#define BIT_AON_APB_PUBCP_AWADDR_WPROT_EN0(x)               ( (x) )

/* bits definitions for REG_AON_APB_WCNCP_WPROT_EN0, [0x402E3028] */
#define BIT_AON_APB_WCNCP_AWADDR_WPROT_EN0(x)               ( (x) )

/* bits definitions for REG_AON_APB_PMU_RST_MONITOR, [0x402E302C] */
#define BIT_AON_APB_PMU_RST_MONITOR(x)                      ( (x) )

/* bits definitions for REG_AON_APB_THM_RST_MONITOR, [0x402E3030] */
#define BIT_AON_APB_THM_RST_MONITOR(x)                      ( (x) )

/* bits definitions for REG_AON_APB_AP_RST_MONITOR, [0x402E3034] */
#define BIT_AON_APB_AP_RST_MONITOR(x)                       ( (x) )

/* bits definitions for REG_AON_APB_CA53_RST_MONITOR, [0x402E3038] */
#define BIT_AON_APB_CA53_RST_MONITOR(x)                     ( (x) )

/* bits definitions for REG_AON_APB_BOND_OPT0, [0x402E303C] */
#define BIT_AON_APB_BOND_OPTION0(x)                         ( (x) )

/* bits definitions for REG_AON_APB_BOND_OPT1, [0x402E3040] */
#define BIT_AON_APB_BOND_OPTION1(x)                         ( (x) )

/* bits definitions for REG_AON_APB_RES_REG0, [0x402E3044] */
#define BIT_AON_APB_RES_REG0(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG1, [0x402E3048] */
#define BIT_AON_APB_RES_REG1(x)                             ( (x) )

/* bits definitions for REG_AON_APB_AON_QOS_CFG, [0x402E304C] */
#define BIT_AON_APB_QOS_R_GPU(x)                            ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_QOS_W_GPU(x)                            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_APB_QOS_R_GSP(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_QOS_W_GSP(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_BB_LDO_CAL_START, [0x402E3050] */
#define BIT_AON_APB_BB_LDO_CAL_START                        ( BIT(0) )

/* bits definitions for REG_AON_APB_AON_MTX_PROT_CFG, [0x402E3058] */
#define BIT_AON_APB_HPROT_DMAW(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_HPROT_DMAR(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_LVDS_CFG, [0x402E3060] */
#define BIT_AON_APB_LVDSDIS_TXCLKDATA(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_APB_LVDSDIS_TXCOM(x)                        ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_APB_LVDSDIS_TXSLEW(x)                       ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AON_APB_LVDSDIS_TXSW(x)                         ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AON_APB_LVDSDIS_TXRERSER(x)                     ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_APB_LVDSDIS_PRE_EMP(x)                      ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_AON_APB_LVDSDIS_TXPD                            ( BIT(0) )

/* bits definitions for REG_AON_APB_PLL_LOCK_OUT_SEL, [0x402E3064] */
#define BIT_AON_APB_SLEEP_PLLLOCK_SEL                       ( BIT(7) )
#define BIT_AON_APB_PLL_LOCK_SEL(x)                         ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_APB_SLEEP_DBG_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_RTC4M_RC_VAL, [0x402E3068] */
#define BIT_AON_APB_RTC4M1_RC_SEL                           ( BIT(31) )
#define BIT_AON_APB_RTC4M1_RC_VAL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AON_APB_RTC4M0_RC_SEL                           ( BIT(15) )
#define BIT_AON_APB_RTC4M0_RC_VAL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_AON_APB_FUNCTST_CTRL_0, [0x402E3070] */
#define BIT_AON_APB_FUNCTST_CTRL_0(x)                       ( (x) )

/* bits definitions for REG_AON_APB_FUNCTST_CTRL_1, [0x402E3074] */
#define BIT_AON_APB_FUNCTST_CTRL_1(x)                       ( (x) )

/* bits definitions for REG_AON_APB_FUNCTST_CTRL_2, [0x402E3078] */
#define BIT_AON_APB_FUNCTST_CTRL_2(x)                       ( (x) )

/* bits definitions for REG_AON_APB_WDG_RST_FLAG, [0x402E3080] */
#define BIT_AON_APB_PCP_WDG_RST_FLAG                        ( BIT(5) )
#define BIT_AON_APB_WTLCP_LTE_WDG_RST_FLAG                  ( BIT(4) )
#define BIT_AON_APB_WTLCP_TG_WDG_RST_FLAG                   ( BIT(3) )
#define BIT_AON_APB_CA53_WDG_RST_FLAG                       ( BIT(1) )
#define BIT_AON_APB_SEC_WDG_RST_FLAG                        ( BIT(0) )

/* bits definitions for REG_AON_APB_CA7_CFG, [0x402E3084] */
#define BIT_AON_APB_READ_ALLOC_MODE_SPRD(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_APB_RES_REG2, [0x402E3090] */
#define BIT_AON_APB_RES_REG2(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG3, [0x402E3094] */
#define BIT_AON_APB_RES_REG3(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG4, [0x402E3098] */
#define BIT_AON_APB_RES_REG4(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG5, [0x402E309C] */
#define BIT_AON_APB_RES_REG5(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG6, [0x402E30A0] */
#define BIT_AON_APB_RES_REG6(x)                             ( (x) )

/* bits definitions for REG_AON_APB_RES_REG7, [0x402E30A4] */
#define BIT_AON_APB_RES_REG7(x)                             ( (x) )

/* bits definitions for REG_AON_APB_AON_APB_RSV, [0x402E30F0] */
#define BIT_AON_APB_AON_APB_RSV(x)                          ( (x) )

/* bits definitions for REG_AON_APB_FUNCTION_DMA_BOOT_ADDR, [0x402E3110] */
#define BIT_AON_APB_FUNCTION_DMA_BOOT_ADDR(x)               ( (x) )

/* bits definitions for REG_AON_APB_SP_WAKEUP_MASK_EN1, [0x402E3184] */
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_31                   ( BIT(31) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_30                   ( BIT(30) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_29                   ( BIT(29) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_28                   ( BIT(28) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_27                   ( BIT(27) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_26                   ( BIT(26) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_25                   ( BIT(25) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_24                   ( BIT(24) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_23                   ( BIT(23) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_22                   ( BIT(22) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_21                   ( BIT(21) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_20                   ( BIT(20) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_19                   ( BIT(19) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_18                   ( BIT(18) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_17                   ( BIT(17) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_16                   ( BIT(16) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_15                   ( BIT(15) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_14                   ( BIT(14) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_13                   ( BIT(13) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_12                   ( BIT(12) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_11                   ( BIT(11) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_10                   ( BIT(10) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_09                   ( BIT(9) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_08                   ( BIT(8) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_07                   ( BIT(7) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_06                   ( BIT(6) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_05                   ( BIT(5) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_04                   ( BIT(4) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_03                   ( BIT(3) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_02                   ( BIT(2) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_01                   ( BIT(1) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN1_00                   ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_WAKEUP_MASK_EN2, [0x402E3188] */
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_31                   ( BIT(31) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_30                   ( BIT(30) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_29                   ( BIT(29) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_28                   ( BIT(28) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_27                   ( BIT(27) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_26                   ( BIT(26) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_25                   ( BIT(25) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_24                   ( BIT(24) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_23                   ( BIT(23) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_22                   ( BIT(22) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_21                   ( BIT(21) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_20                   ( BIT(20) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_19                   ( BIT(19) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_18                   ( BIT(18) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_17                   ( BIT(17) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_16                   ( BIT(16) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_15                   ( BIT(15) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_14                   ( BIT(14) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_13                   ( BIT(13) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_12                   ( BIT(12) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_11                   ( BIT(11) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_10                   ( BIT(10) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_09                   ( BIT(9) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_08                   ( BIT(8) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_07                   ( BIT(7) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_06                   ( BIT(6) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_05                   ( BIT(5) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_04                   ( BIT(4) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_03                   ( BIT(3) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_02                   ( BIT(2) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_01                   ( BIT(1) )
#define BIT_AON_APB_SP_WAKEUP_MASK_EN2_00                   ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_WDG_RST_GLB_EN, [0x402E318C] */
#define BIT_AON_APB_SP_WDG_RST_GLB_EN                       ( BIT(0) )

/* bits definitions for REG_AON_APB_SP_EIC_PAD_CTRL0, [0x402E3190] */
#define BIT_AON_APB_SP_EIC_SEL_PAD3(x)                      ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_SP_EIC_SEL_PAD2(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_SP_EIC_SEL_PAD1(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_SP_EIC_SEL_PAD0(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_SP_EIC_PAD_CTRL1, [0x402E3194] */
#define BIT_AON_APB_SP_EIC_SEL_PAD7(x)                      ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_APB_SP_EIC_SEL_PAD6(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_APB_SP_EIC_SEL_PAD5(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_APB_SP_EIC_SEL_PAD4(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_WCN2PUB_AON_REMAP, [0x402E3198] */
#define BIT_AON_APB_WCN2PUB_REMAP_SIZE_SEL(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_APB_WCN2PUB_REMAP_ADDR(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_APB_APCPU_DBG_CMD_EX, [0x402E3200] */
#define BIT_AON_APB_APCPU_DBG_CONNECTED_CTRL(x)             ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_AON_APB_APCPU_DBG_CONNECTED_SW                  ( BIT(0) )

/* bits definitions for REG_AON_APB_PUB_PERI_CK_EB, [0x402E3210] */
#define BIT_AON_APB_PUB_PERI_AUTO_CK_EB                     ( BIT(0) )

/* bits definitions for REG_AON_APB_APCPU_CLUSTER_DUMMY_IN_REG, [0x402E3300] */
#define BIT_AON_APB_APCPU_CLUSTER_DUMMY_IN_REG(x)           ( (x) )

/* vars definitions for controller CTL_AON_APB */


#endif /* __AON_APB_H____ */
