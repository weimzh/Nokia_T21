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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0550_cq_goodcode_202005181536/reg/ipa/SharkL6Pro_IPA_APB_Control_Register.xls;IPA_APB_REG
 *     Revision : 234058
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __IPA_APB_H____
#define __IPA_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_IPA_APB_BASE
#define CTL_IPA_APB_BASE                SCI_IOMAP(0x25000000)
#endif

/* registers definitions for CTL_IPA_APB, 0x25000000 */
#define REG_IPA_APB_IPA_RST                                 SCI_ADDR(CTL_IPA_APB_BASE, 0x0000)
#define REG_IPA_APB_IPA_EB                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0004)
#define REG_IPA_APB_USB_CTL0                                SCI_ADDR(CTL_IPA_APB_BASE, 0x0008)
#define REG_IPA_APB_MISC_CFG                                SCI_ADDR(CTL_IPA_APB_BASE, 0x000C)
#define REG_IPA_APB_M0_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0010)
#define REG_IPA_APB_M1_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0014)
#define REG_IPA_APB_M2_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0018)
#define REG_IPA_APB_M3_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x001C)
#define REG_IPA_APB_M4_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0020)
#define REG_IPA_APB_M5_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0024)
#define REG_IPA_APB_M6_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0028)
#define REG_IPA_APB_M7_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x002C)
#define REG_IPA_APB_M8_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0030)
#define REG_IPA_APB_MAIN_MTX_LPC                            SCI_ADDR(CTL_IPA_APB_BASE, 0x0034)
#define REG_IPA_APB_S0_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0038)
#define REG_IPA_APB_S1_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x003C)
#define REG_IPA_APB_S2_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0040)
#define REG_IPA_APB_S3_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0044)
#define REG_IPA_APB_S4_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0048)
#define REG_IPA_APB_S5_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x004C)
#define REG_IPA_APB_S6_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0050)
#define REG_IPA_APB_S7_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0054)
#define REG_IPA_APB_S8_LPC                                  SCI_ADDR(CTL_IPA_APB_BASE, 0x0058)
#define REG_IPA_APB_ASYNC_BRG_DDR_LPC                       SCI_ADDR(CTL_IPA_APB_BASE, 0x0060)
#define REG_IPA_APB_ASYNC_BRG_PCIE_LPC                      SCI_ADDR(CTL_IPA_APB_BASE, 0x0064)
#define REG_IPA_APB_ASYNC_BRG_AON_LPC                       SCI_ADDR(CTL_IPA_APB_BASE, 0x0068)
#define REG_IPA_APB_ASYNC_BRG_PHYCP_LPC                     SCI_ADDR(CTL_IPA_APB_BASE, 0x006C)
#define REG_IPA_APB_ASYNC_BRG_PSCP_LPC                      SCI_ADDR(CTL_IPA_APB_BASE, 0x0070)
#define REG_IPA_APB_MATRIX_LPC_CTRL                         SCI_ADDR(CTL_IPA_APB_BASE, 0x0078)
#define REG_IPA_APB_MTX_QOS_0                               SCI_ADDR(CTL_IPA_APB_BASE, 0x007C)
#define REG_IPA_APB_MTX_QOS_1                               SCI_ADDR(CTL_IPA_APB_BASE, 0x0080)
#define REG_IPA_APB_MTX_QOS_2                               SCI_ADDR(CTL_IPA_APB_BASE, 0x0084)
#define REG_IPA_APB_NIC400_URGENCY_0                        SCI_ADDR(CTL_IPA_APB_BASE, 0x0088)
#define REG_IPA_APB_NIC400_URGENCY_1                        SCI_ADDR(CTL_IPA_APB_BASE, 0x008C)
#define REG_IPA_APB_IPA_MTX_FREQ_ALLOW_0                    SCI_ADDR(CTL_IPA_APB_BASE, 0x0090)
#define REG_IPA_APB_IPA_MTX_FREQ_ALLOW_1                    SCI_ADDR(CTL_IPA_APB_BASE, 0x0094)
#define REG_IPA_APB_IPA_MTX_FREQ_LSLP_ALLOW_0               SCI_ADDR(CTL_IPA_APB_BASE, 0x0098)
#define REG_IPA_APB_IPA_MTX_FREQ_LSLP_ALLOW_1               SCI_ADDR(CTL_IPA_APB_BASE, 0x009C)
#define REG_IPA_APB_IPA_SYS_STATUS                          SCI_ADDR(CTL_IPA_APB_BASE, 0x00A0)
#define REG_IPA_APB_USB3_DEBUG_0                            SCI_ADDR(CTL_IPA_APB_BASE, 0x00A4)
#define REG_IPA_APB_USB3_DEBUG_1                            SCI_ADDR(CTL_IPA_APB_BASE, 0x00A8)
#define REG_IPA_APB_USB3_DEBUG_2                            SCI_ADDR(CTL_IPA_APB_BASE, 0x00AC)
#define REG_IPA_APB_USB3_DEBUG_3                            SCI_ADDR(CTL_IPA_APB_BASE, 0x00B0)
#define REG_IPA_APB_AP2IPA_BRIDGE_DEBUG_SIGNAL_R            SCI_ADDR(CTL_IPA_APB_BASE, 0x00B4)
#define REG_IPA_APB_PCIE2IPA_BRIDGE_DEBUG_SIGNAL_R          SCI_ADDR(CTL_IPA_APB_BASE, 0x00B8)
#define REG_IPA_APB_PHYCP2IPA_BRIDGE_DEBUG_SIGNAL_R         SCI_ADDR(CTL_IPA_APB_BASE, 0x00BC)
#define REG_IPA_APB_PSCP2IPA_BRIDGE_DEBUG_SIGNAL_R          SCI_ADDR(CTL_IPA_APB_BASE, 0x00C0)
#define REG_IPA_APB_DDR_BRIDGE_DEBUG_SIGNAL_W               SCI_ADDR(CTL_IPA_APB_BASE, 0x00C4)
#define REG_IPA_APB_PCIE_BRIDGE_DEBUG_SIGNAL_W              SCI_ADDR(CTL_IPA_APB_BASE, 0x00C8)
#define REG_IPA_APB_AON_BRIDGE_DEBUG_SIGNAL_W               SCI_ADDR(CTL_IPA_APB_BASE, 0x00CC)
#define REG_IPA_APB_PHYCP_BRIDGE_DEBUG_SIGNAL_W             SCI_ADDR(CTL_IPA_APB_BASE, 0x00D0)
#define REG_IPA_APB_PSCP_BRIDGE_DEBUG_SIGNAL_W              SCI_ADDR(CTL_IPA_APB_BASE, 0x00D4)
#define REG_IPA_APB_IPA_LPC_CTRL                            SCI_ADDR(CTL_IPA_APB_BASE, 0x00DC)
#define REG_IPA_APB_USB_CTL1                                SCI_ADDR(CTL_IPA_APB_BASE, 0x00E0)
#define REG_IPA_APB_USB_CTL2                                SCI_ADDR(CTL_IPA_APB_BASE, 0x00E4)

/* bits definitions for REG_IPA_APB_IPA_RST, [0x25000000] */
#define BIT_IPA_APB_BUSMON_PERF_IPA_M0_SOFT_RST             ( BIT(9) )
#define BIT_IPA_APB_BUSMON_PERF_IPA_WIFI_SOFT_RST           ( BIT(8) )
#define BIT_IPA_APB_BUSMON_PERF_PAM_U3_SOFT_RST             ( BIT(7) )
#define BIT_IPA_APB_PAM_WIFI_SOFT_RST                       ( BIT(3) )
#define BIT_IPA_APB_NIC400_CFG_SOFT_RST                     ( BIT(2) )
#define BIT_IPA_APB_PAM_U3_SOFT_RST                         ( BIT(1) )
#define BIT_IPA_APB_USB_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_IPA_APB_IPA_EB, [0x25000004] */
#define BIT_IPA_APB_BUSMON_BRIDGE_DEBUG_EB                  ( BIT(13) )
#define BIT_IPA_APB_BUSMON_PERF_IPA_M0_EB                   ( BIT(11) )
#define BIT_IPA_APB_BUSMON_PERF_IPA_WIFI_EB                 ( BIT(10) )
#define BIT_IPA_APB_BUSMON_PERF_PAM_U3_EB                   ( BIT(9) )
#define BIT_IPA_APB_PAM_WIFI_EB                             ( BIT(6) )
#define BIT_IPA_APB_PAM_USB_EB                              ( BIT(4) )
#define BIT_IPA_APB_USB_REF_EB                              ( BIT(2) )
#define BIT_IPA_APB_USB_SUSPEND_EB                          ( BIT(1) )
#define BIT_IPA_APB_USB_EB                                  ( BIT(0) )

/* bits definitions for REG_IPA_APB_USB_CTL0, [0x25000008] */
#define BIT_IPA_APB_USB31_SYSBUS_BLOCK_WATERMARK_TIME(x)    ( (x) << 16 & (0xFFFF0000) )
#define BIT_IPA_APB_UTMISRP_BVALID_REG                      ( BIT(15) )
#define BIT_IPA_APB_OTG_VBUS_VALID_PHYREG                   ( BIT(14) )
#define BIT_IPA_APB_OTG_VBUS_VALID_PHYREG_SEL               ( BIT(13) )
#define BIT_IPA_APB_XHC_BME                                 ( BIT(12) )
#define BIT_IPA_APB_BUS_FILTER_BYPASS(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IPA_APB_PME_EN                                  ( BIT(7) )
#define BIT_IPA_APB_USB_FLADJ_30MHZ_REG(x)                  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_IPA_APB_USB_HOST_PORT_POWER_CONTROL_PRESENT     ( BIT(0) )

/* bits definitions for REG_IPA_APB_MISC_CFG, [0x2500000C] */
#define BIT_IPA_APB_IPA_BUS_MONITOR_EN                      ( BIT(0) )

/* bits definitions for REG_IPA_APB_M0_LPC, [0x25000010] */
#define BIT_IPA_APB_MAIN_M0_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M0                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M0                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M0_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M0_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M0_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M1_LPC, [0x25000014] */
#define BIT_IPA_APB_MAIN_M1_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M1                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M1                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M1_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M1_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M1_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M2_LPC, [0x25000018] */
#define BIT_IPA_APB_MAIN_M2_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M2                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M2                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M2_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M2_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M2_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M3_LPC, [0x2500001C] */
#define BIT_IPA_APB_MAIN_M3_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M3                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M3                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M3_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M3_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M3_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M4_LPC, [0x25000020] */
#define BIT_IPA_APB_MAIN_M4_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M4                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M4                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M4_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M4_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M4_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M5_LPC, [0x25000024] */
#define BIT_IPA_APB_MAIN_M5_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M5                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M5                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M5_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M5_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M5_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M6_LPC, [0x25000028] */
#define BIT_IPA_APB_MAIN_M6_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M6                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M6                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M6_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M6_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M6_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M7_LPC, [0x2500002C] */
#define BIT_IPA_APB_MAIN_M7_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M7                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M7                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M7_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M7_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M7_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_M8_LPC, [0x25000030] */
#define BIT_IPA_APB_MAIN_M8_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_M8                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_M8                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_M8_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_M8_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_M8_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_MAIN_MTX_LPC, [0x25000034] */
#define BIT_IPA_APB_MAIN_PU_NUM(x)                          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_MAIN                   ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_MAIN                   ( BIT(21) )
#define BIT_IPA_APB_MAIN_LP_FORCE                           ( BIT(20) )
#define BIT_IPA_APB_MAIN_LP_EB                              ( BIT(16) )
#define BIT_IPA_APB_MAIN_LP_NUM(x)                          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S0_LPC, [0x25000038] */
#define BIT_IPA_APB_MAIN_S0_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S0                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S0                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S0_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S0_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S0_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S1_LPC, [0x2500003C] */
#define BIT_IPA_APB_MAIN_S1_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S1                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S1                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S1_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S1_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S1_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S2_LPC, [0x25000040] */
#define BIT_IPA_APB_MAIN_S2_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S2                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S2                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S2_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S2_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S2_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S3_LPC, [0x25000044] */
#define BIT_IPA_APB_MAIN_S3_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S3                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S3                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S3_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S3_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S3_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S4_LPC, [0x25000048] */
#define BIT_IPA_APB_MAIN_S4_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S4                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S4                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S4_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S4_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S4_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S5_LPC, [0x2500004C] */
#define BIT_IPA_APB_MAIN_S5_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S5                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S5                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S5_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S5_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S5_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S6_LPC, [0x25000050] */
#define BIT_IPA_APB_MAIN_S6_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S6                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S6                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S6_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S6_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S6_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S7_LPC, [0x25000054] */
#define BIT_IPA_APB_MAIN_S7_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S7                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S7                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S7_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S7_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S7_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_S8_LPC, [0x25000058] */
#define BIT_IPA_APB_MAIN_S8_PU_NUM(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_CSYSACK_SYNC_SEL_S8                     ( BIT(22) )
#define BIT_IPA_APB_CACTIVE_SYNC_SEL_S8                     ( BIT(21) )
#define BIT_IPA_APB_MAIN_S8_LP_FORCE                        ( BIT(20) )
#define BIT_IPA_APB_MAIN_S8_LP_EB                           ( BIT(16) )
#define BIT_IPA_APB_MAIN_S8_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_ASYNC_BRG_DDR_LPC, [0x25000060] */
#define BIT_IPA_APB_ASYNC_BRG_DDR_PU_NUM(x)                 ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ASYNC_BRG_DDR_LP_EB                     ( BIT(16) )
#define BIT_IPA_APB_ASYNC_BRG_DDR_LP_NUM(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_ASYNC_BRG_PCIE_LPC, [0x25000064] */
#define BIT_IPA_APB_ASYNC_BRG_PCIE_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ASYNC_BRG_PCIE_LP_EB                    ( BIT(16) )
#define BIT_IPA_APB_ASYNC_BRG_PCIE_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_ASYNC_BRG_AON_LPC, [0x25000068] */
#define BIT_IPA_APB_ASYNC_BRG_AON_PU_NUM(x)                 ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ASYNC_BRG_AON_LP_EB                     ( BIT(16) )
#define BIT_IPA_APB_ASYNC_BRG_AON_LP_NUM(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_ASYNC_BRG_PHYCP_LPC, [0x2500006C] */
#define BIT_IPA_APB_ASYNC_BRG_PHYCP_PU_NUM(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ASYNC_BRG_PHYCP_LP_EB                   ( BIT(16) )
#define BIT_IPA_APB_ASYNC_BRG_PHYCP_LP_NUM(x)               ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_ASYNC_BRG_PSCP_LPC, [0x25000070] */
#define BIT_IPA_APB_ASYNC_BRG_PSCP_PU_NUM(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ASYNC_BRG_PSCP_LP_EB                    ( BIT(16) )
#define BIT_IPA_APB_ASYNC_BRG_PSCP_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_IPA_APB_MATRIX_LPC_CTRL, [0x25000078] */
#define BIT_IPA_APB_APB_AUTO_DPSLP_EN                       ( BIT(19) )
#define BIT_IPA_APB_IPA_APB_FRC_OFF                         ( BIT(18) )
#define BIT_IPA_APB_IPA_APB_AUTO_GATE_EN                    ( BIT(17) )
#define BIT_IPA_APB_IPA_MTX_FRC_OFF                         ( BIT(16) )
#define BIT_IPA_APB_IPA_MTX_AUTO_GATE_EN                    ( BIT(15) )
#define BIT_IPA_APB_IPA_MTX_FREQ_LSLP_DFS_SEL(x)            ( (x) << 13 & (BIT(13)|BIT(14)) )
#define BIT_IPA_APB_IPA_MTX_FREQ_LSLP_DFS_EN                ( BIT(12) )
#define BIT_IPA_APB_IPA_MTX_FREQ_LSLP_DFS_MODE              ( BIT(11) )
#define BIT_IPA_APB_IPA_MTX_FREQ_DFS_MASTER_HW_EN(x)        ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_IPA_APB_IPA_MTX_FREQ_DFS_MODE                   ( BIT(1) )
#define BIT_IPA_APB_AXI_LP_CTRL_DISABLE                     ( BIT(0) )

/* bits definitions for REG_IPA_APB_MTX_QOS_0, [0x2500007C] */
#define BIT_IPA_APB_AWQOS_M3(x)                             ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ARQOS_M3(x)                             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_IPA_APB_AWQOS_M2(x)                             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_IPA_APB_ARQOS_M2(x)                             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_IPA_APB_AWQOS_M1(x)                             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_IPA_APB_ARQOS_M1(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IPA_APB_AWQOS_M0(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_IPA_APB_ARQOS_M0(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_MTX_QOS_1, [0x25000080] */
#define BIT_IPA_APB_AWQOS_M7(x)                             ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_ARQOS_M7(x)                             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_IPA_APB_AWQOS_M6(x)                             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_IPA_APB_ARQOS_M6(x)                             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_IPA_APB_AWQOS_M5(x)                             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_IPA_APB_ARQOS_M5(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IPA_APB_AWQOS_M4(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_IPA_APB_ARQOS_M4(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_MTX_QOS_2, [0x25000084] */
#define BIT_IPA_APB_AWQOS_M8(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_IPA_APB_ARQOS_M8(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_NIC400_URGENCY_0, [0x25000088] */
#define BIT_IPA_APB_ARURGENCY_M7(x)                         ( (x) << 30 & (BIT(30)|BIT(31)) )
#define BIT_IPA_APB_AWURGENCY_M7(x)                         ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_IPA_APB_ARURGENCY_M6(x)                         ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_IPA_APB_AWURGENCY_M6(x)                         ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_IPA_APB_ARURGENCY_M5(x)                         ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_IPA_APB_AWURGENCY_M5(x)                         ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_IPA_APB_ARURGENCY_M4(x)                         ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_IPA_APB_AWURGENCY_M4(x)                         ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_IPA_APB_ARURGENCY_M3(x)                         ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_IPA_APB_AWURGENCY_M3(x)                         ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_IPA_APB_ARURGENCY_M2(x)                         ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_IPA_APB_AWURGENCY_M2(x)                         ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_IPA_APB_ARURGENCY_M1(x)                         ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_IPA_APB_AWURGENCY_M1(x)                         ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_IPA_APB_ARURGENCY_M0(x)                         ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_IPA_APB_AWURGENCY_M0(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_APB_NIC400_URGENCY_1, [0x2500008C] */
#define BIT_IPA_APB_ARURGENCY_M8(x)                         ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_IPA_APB_AWURGENCY_M8(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_IPA_APB_IPA_MTX_FREQ_ALLOW_0, [0x25000090] */
#define BIT_IPA_APB_IMTX_M7_AXI_FREQ_ALLOW(x)               ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_IMTX_M6_AXI_FREQ_ALLOW(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_IPA_APB_IMTX_M5_AXI_FREQ_ALLOW(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_IPA_APB_IMTX_M4_AXI_FREQ_ALLOW(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_IPA_APB_IMTX_M3_AXI_FREQ_ALLOW(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_IPA_APB_IMTX_M2_AXI_FREQ_ALLOW(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IPA_APB_IMTX_M1_AXI_FREQ_ALLOW(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_IPA_APB_IMTX_M0_AXI_FREQ_ALLOW(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_IPA_MTX_FREQ_ALLOW_1, [0x25000094] */
#define BIT_IPA_APB_IMTX_M8_AXI_FREQ_ALLOW(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_IPA_MTX_FREQ_LSLP_ALLOW_0, [0x25000098] */
#define BIT_IPA_APB_IMTX_M7_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_IPA_APB_IMTX_M6_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_IPA_APB_IMTX_M5_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_IPA_APB_IMTX_M4_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_IPA_APB_IMTX_M3_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_IPA_APB_IMTX_M2_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IPA_APB_IMTX_M1_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_IPA_APB_IMTX_M0_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_IPA_MTX_FREQ_LSLP_ALLOW_1, [0x2500009C] */
#define BIT_IPA_APB_IMTX_M8_AXI_FREQ_LSLP_ALLOW(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_IPA_APB_IPA_SYS_STATUS, [0x250000A0] */
#define BIT_IPA_APB_PHYCP_BRIDGE_TRANS_IDLE                 ( BIT(9) )
#define BIT_IPA_APB_PHYCP_BRIDGE_AXI_DETECTOR_OVERFLOW      ( BIT(8) )
#define BIT_IPA_APB_PSCP_BRIDGE_TRANS_IDLE                  ( BIT(7) )
#define BIT_IPA_APB_PSCP_BRIDGE_AXI_DETECTOR_OVERFLOW       ( BIT(6) )
#define BIT_IPA_APB_AON_BRIDGE_TRANS_IDLE                   ( BIT(5) )
#define BIT_IPA_APB_AON_BRIDGE_AXI_DETECTOR_OVERFLOW        ( BIT(4) )
#define BIT_IPA_APB_PCIE_BRIDGE_TRANS_IDLE                  ( BIT(3) )
#define BIT_IPA_APB_PCIE_BRIDGE_AXI_DETECTOR_OVERFLOW       ( BIT(2) )
#define BIT_IPA_APB_DDR_BRIDGE_TRANS_IDLE                   ( BIT(1) )
#define BIT_IPA_APB_DDR_BRIDGE_AXI_DETECTOR_OVERFLOW        ( BIT(0) )

/* bits definitions for REG_IPA_APB_USB3_DEBUG_0, [0x250000A4] */
#define BIT_IPA_APB_USB3_DEBUG_0_31(x)                      ( (x) )

/* bits definitions for REG_IPA_APB_USB3_DEBUG_1, [0x250000A8] */
#define BIT_IPA_APB_USB3_DEBUG_32_63(x)                     ( (x) )

/* bits definitions for REG_IPA_APB_USB3_DEBUG_2, [0x250000AC] */
#define BIT_IPA_APB_USB3_DEBUG_64_95(x)                     ( (x) )

/* bits definitions for REG_IPA_APB_USB3_DEBUG_3, [0x250000B0] */
#define BIT_IPA_APB_HOST_CURRENT_BELT(x)                    ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_IPA_APB_USB3_CLK_GATE_CTRL(x)                   ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_IPA_APB_USB3_HOST_SYSTEM_ERR                    ( BIT(8) )
#define BIT_IPA_APB_USB3_DEBUG_96_103(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_IPA_APB_AP2IPA_BRIDGE_DEBUG_SIGNAL_R, [0x250000B4] */
#define BIT_IPA_APB_AP2IPA_BRIDGE_DEBUG_SIGNAL_R(x)         ( (x) )

/* bits definitions for REG_IPA_APB_PCIE2IPA_BRIDGE_DEBUG_SIGNAL_R, [0x250000B8] */
#define BIT_IPA_APB_PCIE2IPA_BRIDGE_DEBUG_SIGNAL_R(x)       ( (x) )

/* bits definitions for REG_IPA_APB_PHYCP2IPA_BRIDGE_DEBUG_SIGNAL_R, [0x250000BC] */
#define BIT_IPA_APB_PHYCP2IPA_BRIDGE_DEBUG_SIGNAL_R(x)      ( (x) )

/* bits definitions for REG_IPA_APB_PSCP2IPA_BRIDGE_DEBUG_SIGNAL_R, [0x250000C0] */
#define BIT_IPA_APB_PSCP2IPA_BRIDGE_DEBUG_SIGNAL_R(x)       ( (x) )

/* bits definitions for REG_IPA_APB_DDR_BRIDGE_DEBUG_SIGNAL_W, [0x250000C4] */
#define BIT_IPA_APB_DDR_BRIDGE_DEBUG_SIGNAL_W(x)            ( (x) )

/* bits definitions for REG_IPA_APB_PCIE_BRIDGE_DEBUG_SIGNAL_W, [0x250000C8] */
#define BIT_IPA_APB_PCIE_BRIDGE_DEBUG_SIGNAL_W(x)           ( (x) )

/* bits definitions for REG_IPA_APB_AON_BRIDGE_DEBUG_SIGNAL_W, [0x250000CC] */
#define BIT_IPA_APB_AON_BRIDGE_DEBUG_SIGNAL_W(x)            ( (x) )

/* bits definitions for REG_IPA_APB_PHYCP_BRIDGE_DEBUG_SIGNAL_W, [0x250000D0] */
#define BIT_IPA_APB_PHYCP_BRIDGE_DEBUG_SIGNAL_W(x)          ( (x) )

/* bits definitions for REG_IPA_APB_PSCP_BRIDGE_DEBUG_SIGNAL_W, [0x250000D4] */
#define BIT_IPA_APB_PSCP_BRIDGE_DEBUG_SIGNAL_W(x)           ( (x) )

/* bits definitions for REG_IPA_APB_IPA_LPC_CTRL, [0x250000DC] */
#define BIT_IPA_APB_IPA_ACCESS_PCIE_EN                      ( BIT(8) )
#define BIT_IPA_APB_IPA_TIMER_FRC_OFF                       ( BIT(7) )
#define BIT_IPA_APB_IPA_TIMER_AUTO_GATE_EN                  ( BIT(6) )
#define BIT_IPA_APB_USB_REF_FRC_OFF                         ( BIT(5) )
#define BIT_IPA_APB_USB_REF_AUTO_GATE_EN                    ( BIT(4) )
#define BIT_IPA_APB_AP_IPA_APB_FRC_OFF                      ( BIT(3) )
#define BIT_IPA_APB_AP_IPA_APB_AUTO_GATE_EN                 ( BIT(2) )
#define BIT_IPA_APB_AP_IPA_AXI_FRC_OFF                      ( BIT(1) )
#define BIT_IPA_APB_AP_IPA_AXI_AUTO_GATE_EN                 ( BIT(0) )

/* bits definitions for REG_IPA_APB_USB_CTL1, [0x250000E0] */
#define BIT_IPA_APB_USB31_BUS_CLK_BYPASS                    ( BIT(8) )
#define BIT_IPA_APB_USB31_REF_CLK_BYPASS                    ( BIT(7) )
#define BIT_IPA_APB_USB31_DEVSPD_OVRD(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_IPA_APB_USB31_PM_POWER_STATE_REQUEST(x)         ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_IPA_APB_USB31_PWR_GATE                          ( BIT(0) )

/* bits definitions for REG_IPA_APB_USB_CTL2, [0x250000E4] */
#define BIT_IPA_APB_USB31_OK_TO_BLOCK_SUBSYS(x)             ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_IPA_APB_USB31_CURRENT_POWER_STATE_U2PMU(x)      ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_IPA_APB_USB31_PME_GENERATION_U2PMU              ( BIT(5) )
#define BIT_IPA_APB_USB31_CONNECT_STATE_U2PMU               ( BIT(4) )
#define BIT_IPA_APB_USB31_CURRENT_POWER_STATE_U3PMU(x)      ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_IPA_APB_USB31_PME_GENERATION_U3PMU              ( BIT(1) )
#define BIT_IPA_APB_USB31_CONNECT_STATE_U3PMU               ( BIT(0) )

/* vars definitions for controller CTL_IPA_APB */


#endif /* __IPA_APB_H____ */
