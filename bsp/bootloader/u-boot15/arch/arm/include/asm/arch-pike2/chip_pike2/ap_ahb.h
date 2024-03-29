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

#ifndef __AP_AHB_H____
#define __AP_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AP_AHB_BASE
#define CTL_AP_AHB_BASE                 SCI_IOMAP(0x20E00000)
#endif

/* registers definitions for CTL_AP_AHB, 0x20E00000 */
#define REG_AP_AHB_AHB_EB                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0000)
#define REG_AP_AHB_AHB_RST                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0004)
#define REG_AP_AHB_CA7_RST_SET                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0008)
#define REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG                   SCI_ADDR(CTL_AP_AHB_BASE, 0x000C)
#define REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG                    SCI_ADDR(CTL_AP_AHB_BASE, 0x0010)
#define REG_AP_AHB_HOLDING_PEN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0014)
#define REG_AP_AHB_JMP_ADDR_CA7_C0                          SCI_ADDR(CTL_AP_AHB_BASE, 0x0018)
#define REG_AP_AHB_JMP_ADDR_CA7_C1                          SCI_ADDR(CTL_AP_AHB_BASE, 0x001C)
#define REG_AP_AHB_JMP_ADDR_CA7_C2                          SCI_ADDR(CTL_AP_AHB_BASE, 0x0020)
#define REG_AP_AHB_JMP_ADDR_CA7_C3                          SCI_ADDR(CTL_AP_AHB_BASE, 0x0024)
#define REG_AP_AHB_CA7_C0_PU_LOCK                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0028)
#define REG_AP_AHB_CA7_C1_PU_LOCK                           SCI_ADDR(CTL_AP_AHB_BASE, 0x002C)
#define REG_AP_AHB_CA7_C2_PU_LOCK                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0030)
#define REG_AP_AHB_CA7_C3_PU_LOCK                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0034)
#define REG_AP_AHB_CA7_CKG_DIV_CFG                          SCI_ADDR(CTL_AP_AHB_BASE, 0x0038)
#define REG_AP_AHB_MCU_PAUSE                                SCI_ADDR(CTL_AP_AHB_BASE, 0x003C)
#define REG_AP_AHB_MISC_CKG_EN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0040)
#define REG_AP_AHB_CA7_C0_AUTO_FORCE_SHUTDOWN_EN            SCI_ADDR(CTL_AP_AHB_BASE, 0x0044)
#define REG_AP_AHB_CA7_C1_AUTO_FORCE_SHUTDOWN_EN            SCI_ADDR(CTL_AP_AHB_BASE, 0x0048)
#define REG_AP_AHB_CA7_C2_AUTO_FORCE_SHUTDOWN_EN            SCI_ADDR(CTL_AP_AHB_BASE, 0x004C)
#define REG_AP_AHB_CA7_C3_AUTO_FORCE_SHUTDOWN_EN            SCI_ADDR(CTL_AP_AHB_BASE, 0x0050)
#define REG_AP_AHB_CA7_CKG_SEL_CFG                          SCI_ADDR(CTL_AP_AHB_BASE, 0x0054)
#define REG_AP_AHB_MST_FRC_LSLP                             SCI_ADDR(CTL_AP_AHB_BASE, 0x0058)
#define REG_AP_AHB_M0_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0060)
#define REG_AP_AHB_M9_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0084)
#define REG_AP_AHB_S0_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x008C)
#define REG_AP_AHB_S1_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0090)
#define REG_AP_AHB_M_SYNC_LPC                               SCI_ADDR(CTL_AP_AHB_BASE, 0x00A0)
#define REG_AP_AHB_S_SYNC_LPC                               SCI_ADDR(CTL_AP_AHB_BASE, 0x00A4)
#define REG_AP_AHB_AP_GSP_GPV_LPC                           SCI_ADDR(CTL_AP_AHB_BASE, 0x00A8)
#define REG_AP_AHB_AP_GSP_M0_LPC                            SCI_ADDR(CTL_AP_AHB_BASE, 0x00AC)
#define REG_AP_AHB_AP_GSP_M1_LPC                            SCI_ADDR(CTL_AP_AHB_BASE, 0x00B0)
#define REG_AP_AHB_AP_GSP_S0_LPC                            SCI_ADDR(CTL_AP_AHB_BASE, 0x00B4)
#define REG_AP_AHB_AP_IMC_MAIN_LPC                          SCI_ADDR(CTL_AP_AHB_BASE, 0x00B8)
#define REG_AP_AHB_AP_DISP_MAIN_LPC                         SCI_ADDR(CTL_AP_AHB_BASE, 0x00BC)
#define REG_AP_AHB_CA7_TOP_M0_LPC                           SCI_ADDR(CTL_AP_AHB_BASE, 0x00C0)
#define REG_AP_AHB_CA7_TOP_S1_LPC                           SCI_ADDR(CTL_AP_AHB_BASE, 0x00C4)
#define REG_AP_AHB_CA7_TOP_S2_LPC                           SCI_ADDR(CTL_AP_AHB_BASE, 0x00C8)
#define REG_AP_AHB_CA7_ABRG_S0_LPC                          SCI_ADDR(CTL_AP_AHB_BASE, 0x00CC)
#define REG_AP_AHB_TEE_AHB_EB                               SCI_ADDR(CTL_AP_AHB_BASE, 0x00D0)
#define REG_AP_AHB_USB_AHBM2AXI_S0_LPC                      SCI_ADDR(CTL_AP_AHB_BASE, 0x00D4)
#define REG_AP_AHB_CA7_EMC_REG_SLICE_LPC                    SCI_ADDR(CTL_AP_AHB_BASE, 0x00D8)
#define REG_AP_AHB_AP_DUMMY_REG0                            SCI_ADDR(CTL_AP_AHB_BASE, 0x0100)
#define REG_AP_AHB_AP_DUMMY_REG1                            SCI_ADDR(CTL_AP_AHB_BASE, 0x0104)
#define REG_AP_AHB_AP_DUMMY_REG2                            SCI_ADDR(CTL_AP_AHB_BASE, 0x0108)
#define REG_AP_AHB_AP_DUMMY_REG3                            SCI_ADDR(CTL_AP_AHB_BASE, 0x010C)
#define REG_AP_AHB_CA7_DUMMY_REG0                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0120)
#define REG_AP_AHB_CA7_DUMMY_REG1                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0124)
#define REG_AP_AHB_CA7_CORE_INT_DISABLE_EN                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0128)
#define REG_AP_AHB_CA7_STANDBY_STATUS                       SCI_ADDR(CTL_AP_AHB_BASE, 0x3008)
#define REG_AP_AHB_AP_QOS_CFG                               SCI_ADDR(CTL_AP_AHB_BASE, 0x301C)
#define REG_AP_AHB_OTG_PHY_TUNE                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3020)
#define REG_AP_AHB_OTG_PHY_TEST                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3024)
#define REG_AP_AHB_OTG_PHY_CTRL                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3028)
#define REG_AP_AHB_OTG_CTRL0                                SCI_ADDR(CTL_AP_AHB_BASE, 0x302C)
#define REG_AP_AHB_OTG_CTRL1                                SCI_ADDR(CTL_AP_AHB_BASE, 0x3030)
#define REG_AP_AHB_CHIP_ID                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x30FC)
/* for CE */
#define REG_AP_AHB_CE_SEC_EB                        REG_AP_AHB_AHB_EB
#define REG_AP_AHB_CE_SEC_SOFT_RST                  REG_AP_AHB_AHB_RST

/* bits definitions for REG_AP_AHB_AHB_EB, [0x20E00000] */
#define BIT_AP_AHB_NANDC_ECC_EB                             ( BIT(30) )
#define BIT_AP_AHB_SDIO0_32K_EB                             ( BIT(28) )
#define BIT_AP_AHB_EMMC_32K_EB                              ( BIT(27) )
#define BIT_AP_AHB_CE_SEC_EB                                ( BIT(12) )
#define BIT_AP_AHB_EMMC_EB                                  ( BIT(11) )
#define BIT_AP_AHB_NANDC_EB                                 ( BIT(10) )
#define BIT_AP_AHB_SDIO0_EB                                 ( BIT(8) )
#define BIT_AP_AHB_CE_PUB_EB                                ( BIT(6) )
#define BIT_AP_AHB_REE_DMA_EB                               ( BIT(5) )
#define BIT_AP_AHB_OTG_EB                                   ( BIT(4) )
#define BIT_AP_AHB_GSP_EB                                   ( BIT(3) )
#define BIT_AP_AHB_DISPC_EB                                 ( BIT(1) )
#define BIT_AP_AHB_DSI_EB                                   ( BIT(0) )

/* bits definitions for REG_AP_AHB_AHB_RST, [0x20E00004] */
#define BIT_AP_AHB_CE_SEC_SOFT_RST                          ( BIT(15) )
#define BIT_AP_AHB_EMMC_SOFT_RST                            ( BIT(14) )
#define BIT_AP_AHB_NANDC_SOFT_RST                           ( BIT(13) )
#define BIT_AP_AHB_SDIO0_SOFT_RST                           ( BIT(11) )
#define BIT_AP_AHB_CE_PUB_SOFT_RST                          ( BIT(9) )
#define BIT_AP_AHB_DMA_SOFT_RST                             ( BIT(8) )
#define BIT_AP_AHB_OTG_PHY_SOFT_RST                         ( BIT(6) )
#define BIT_AP_AHB_OTG_UTMI_SOFT_RST                        ( BIT(5) )
#define BIT_AP_AHB_OTG_SOFT_RST                             ( BIT(4) )
#define BIT_AP_AHB_GSP_SOFT_RST                             ( BIT(3) )
#define BIT_AP_AHB_DISP_MTX_SOFT_RST                        ( BIT(2) )
#define BIT_AP_AHB_DISPC_SOFT_RST                           ( BIT(1) )
#define BIT_AP_AHB_DSI_SOFT_RST                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_RST_SET, [0x20E00008] */
#define BIT_AP_AHB_CA7_CS_DBG_SOFT_RST                      ( BIT(14) )
#define BIT_AP_AHB_CA7_L2_SOFT_RST                          ( BIT(13) )
#define BIT_AP_AHB_CA7_SOCDBG_SOFT_RST                      ( BIT(12) )
#define BIT_AP_AHB_CA7_ETM_SOFT_RST(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_CA7_DBG_SOFT_RST(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_CA7_CORE_SOFT_RST(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG, [0x20E0000C] */
#define BIT_AP_AHB_MCU_LIGHT_SLEEP_EN_FORCE                 ( BIT(20) )
#define BIT_AP_AHB_AP_DISP_ASYNC_SLEEP                      ( BIT(18) )
#define BIT_AP_AHB_AP_GSP_MTX_SLEEP                         ( BIT(17) )
#define BIT_AP_AHB_AP_IMC_MTX_SLEEP                         ( BIT(16) )
#define BIT_AP_AHB_CA7_C3_AUTO_SLP_EN                       ( BIT(15) )
#define BIT_AP_AHB_CA7_C2_AUTO_SLP_EN                       ( BIT(14) )
#define BIT_AP_AHB_CA7_C1_AUTO_SLP_EN                       ( BIT(13) )
#define BIT_AP_AHB_CA7_C0_AUTO_SLP_EN                       ( BIT(12) )
#define BIT_AP_AHB_CA7_C3_WFI_SHUTDOWN_EN                   ( BIT(11) )
#define BIT_AP_AHB_CA7_C2_WFI_SHUTDOWN_EN                   ( BIT(10) )
#define BIT_AP_AHB_CA7_C1_WFI_SHUTDOWN_EN                   ( BIT(9) )
#define BIT_AP_AHB_CA7_C0_WFI_SHUTDOWN_EN                   ( BIT(8) )
#define BIT_AP_AHB_MCU_CA7_C3_SLEEP                         ( BIT(7) )
#define BIT_AP_AHB_MCU_CA7_C2_SLEEP                         ( BIT(6) )
#define BIT_AP_AHB_MCU_CA7_C1_SLEEP                         ( BIT(5) )
#define BIT_AP_AHB_MCU_CA7_C0_SLEEP                         ( BIT(4) )
#define BIT_AP_AHB_AP_PERI_FORCE_ON                         ( BIT(2) )
#define BIT_AP_AHB_AP_PERI_FORCE_SLP                        ( BIT(1) )
#define BIT_AP_AHB_AP_APB_SLEEP                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG, [0x20E00010] */
#define BIT_AP_AHB_CLKCORE_CHIP_DEEP_SLEEP_EN               ( BIT(20) )
#define BIT_AP_AHB_USB_AHBM2AXI_S0_LP_DISABLE               ( BIT(19) )
#define BIT_AP_AHB_AP_MAINMTX_M9_LP_DISABLE                 ( BIT(18) )
#define BIT_AP_AHB_AP_MAINMTX_M_SYNC_LP_DISABLE             ( BIT(17) )
#define BIT_AP_AHB_AP_MAINMTX_M1_LP_DISABLE                 ( BIT(16) )
#define BIT_AP_AHB_AP_MAINMTX_M0_LP_DISABLE                 ( BIT(15) )
#define BIT_AP_AHB_CA7_TOPMTX_LP_DISABLE                    ( BIT(14) )
#define BIT_AP_AHB_AP_DISPASYNC_LP_DISABLE                  ( BIT(13) )
#define BIT_AP_AHB_AP_GSPMTX_LP_DISABLE                     ( BIT(12) )
#define BIT_AP_AHB_AP_IMCMTX_LP_DISABLE                     ( BIT(11) )
#define BIT_AP_AHB_GSP_CKG_FORCE_EN                         ( BIT(9) )
#define BIT_AP_AHB_GSP_AUTO_GATE_EN                         ( BIT(8) )
#define BIT_AP_AHB_LP_AUTO_CTRL_EN                          ( BIT(7) )
#define BIT_AP_AHB_AP_MAINMTX_LP_DISABLE                    ( BIT(6) )
#define BIT_AP_AHB_AP_AHB_AUTO_GATE_EN                      ( BIT(5) )
#define BIT_AP_AHB_AP_EMC_AUTO_GATE_EN                      ( BIT(4) )
#define BIT_AP_AHB_CA7_EMC_AUTO_GATE_EN                     ( BIT(3) )
#define BIT_AP_AHB_CA7_DBG_FORCE_SLEEP                      ( BIT(2) )
#define BIT_AP_AHB_CA7_DBG_AUTO_GATE_EN                     ( BIT(1) )
#define BIT_AP_AHB_CA7_CORE_AUTO_GATE_EN                    ( BIT(0) )

/* bits definitions for REG_AP_AHB_HOLDING_PEN, [0x20E00014] */
#define BIT_AP_AHB_HOLDING_PEN(x)                           ( (x) )

/* bits definitions for REG_AP_AHB_JMP_ADDR_CA7_C0, [0x20E00018] */
#define BIT_AP_AHB_JMP_ADDR_CA7_C0(x)                       ( (x) )

/* bits definitions for REG_AP_AHB_JMP_ADDR_CA7_C1, [0x20E0001C] */
#define BIT_AP_AHB_JMP_ADDR_CA7_C1(x)                       ( (x) )

/* bits definitions for REG_AP_AHB_JMP_ADDR_CA7_C2, [0x20E00020] */
#define BIT_AP_AHB_JMP_ADDR_CA7_C2(x)                       ( (x) )

/* bits definitions for REG_AP_AHB_JMP_ADDR_CA7_C3, [0x20E00024] */
#define BIT_AP_AHB_JMP_ADDR_CA7_C3(x)                       ( (x) )

/* bits definitions for REG_AP_AHB_CA7_C0_PU_LOCK, [0x20E00028] */
#define BIT_AP_AHB_CA7_C0_PU_LOCK                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C1_PU_LOCK, [0x20E0002C] */
#define BIT_AP_AHB_CA7_C1_PU_LOCK                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C2_PU_LOCK, [0x20E00030] */
#define BIT_AP_AHB_CA7_C2_PU_LOCK                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C3_PU_LOCK, [0x20E00034] */
#define BIT_AP_AHB_CA7_C3_PU_LOCK                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_CKG_DIV_CFG, [0x20E00038] */
#define BIT_AP_AHB_CA7_DBG_CKG_DIV(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_AP_AHB_CA7_AXI_CKG_DIV(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AP_AHB_CA7_MCU_CKG_DIV(x)                       ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_AP_AHB_MCU_PAUSE, [0x20E0003C] */
#define BIT_AP_AHB_CA7_TOP_MTX_SLEEP                        ( BIT(7) )
#define BIT_AP_AHB_GSP_SLEEP_FOLLOW_CA7_EN                  ( BIT(6) )
#define BIT_AP_AHB_DMA_SLEEP_FOLLOW_CA7_EN                  ( BIT(5) )
#define BIT_AP_AHB_MCU_SLEEP_FOLLOW_CA7_EN                  ( BIT(4) )
#define BIT_AP_AHB_MCU_LIGHT_SLEEP_EN                       ( BIT(3) )
#define BIT_AP_AHB_MCU_DEEP_SLEEP_EN                        ( BIT(2) )
#define BIT_AP_AHB_MCU_SYS_SLEEP_EN                         ( BIT(1) )
#define BIT_AP_AHB_MCU_CORE_SLEEP                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_MISC_CKG_EN, [0x20E00040] */
#define BIT_AP_AHB_ASHB_CA7_DBG_VLD                         ( BIT(9) )
#define BIT_AP_AHB_ASHB_CA7_DBG_EN                          ( BIT(8) )
#define BIT_AP_AHB_DPHY_REF_CKG_EN                          ( BIT(1) )
#define BIT_AP_AHB_DPHY_CFG_CKG_EN                          ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C0_AUTO_FORCE_SHUTDOWN_EN, [0x20E00044] */
#define BIT_AP_AHB_CA7_C0_AUTO_FORCE_SHUTDOWN_EN            ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C1_AUTO_FORCE_SHUTDOWN_EN, [0x20E00048] */
#define BIT_AP_AHB_CA7_C1_AUTO_FORCE_SHUTDOWN_EN            ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C2_AUTO_FORCE_SHUTDOWN_EN, [0x20E0004C] */
#define BIT_AP_AHB_CA7_C2_AUTO_FORCE_SHUTDOWN_EN            ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_C3_AUTO_FORCE_SHUTDOWN_EN, [0x20E00050] */
#define BIT_AP_AHB_CA7_C3_AUTO_FORCE_SHUTDOWN_EN            ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_CKG_SEL_CFG, [0x20E00054] */
#define BIT_AP_AHB_CA7_MCU_CKG_SEL(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_AHB_MST_FRC_LSLP, [0x20E00058] */
#define BIT_AP_AHB_CA7_TOP_M0_FRC_LSLP                      ( BIT(17) )
#define BIT_AP_AHB_AP_DISP_MAIN_FRC_LSLP                    ( BIT(16) )
#define BIT_AP_AHB_AP_IMC_MAIN_FRC_LSLP                     ( BIT(15) )
#define BIT_AP_AHB_AP_GSP_GPV_FRC_LSLP                      ( BIT(14) )
#define BIT_AP_AHB_AP_GSP_M0_FRC_LSLP                       ( BIT(13) )
#define BIT_AP_AHB_AP_GSP_M1_FRC_LSLP                       ( BIT(12) )
#define BIT_AP_AHB_AP_GSP_S0_FRC_LSLP                       ( BIT(11) )
#define BIT_AP_AHB_SLV3_FRC_LSLP                            ( BIT(10) )
#define BIT_AP_AHB_MST9_FRC_LSLP                            ( BIT(9) )
#define BIT_AP_AHB_MST8_FRC_LSLP                            ( BIT(8) )
#define BIT_AP_AHB_MST7_FRC_LSLP                            ( BIT(7) )
#define BIT_AP_AHB_MST6_FRC_LSLP                            ( BIT(6) )
#define BIT_AP_AHB_MST4_FRC_LSLP                            ( BIT(4) )
#define BIT_AP_AHB_MST2_FRC_LSLP                            ( BIT(2) )
#define BIT_AP_AHB_MST1_FRC_LSLP                            ( BIT(1) )
#define BIT_AP_AHB_MST0_FRC_LSLP                            ( BIT(0) )

/* bits definitions for REG_AP_AHB_M0_LPC, [0x20E00060] */
#define BIT_AP_AHB_M0_FORCE_ACK                             ( BIT(19) )
#define BIT_AP_AHB_M0_LP_STAT                               ( BIT(18) )
#define BIT_AP_AHB_M0_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M0_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M0_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M9_LPC, [0x20E00084] */
#define BIT_AP_AHB_M9_FORCE_ACK                             ( BIT(19) )
#define BIT_AP_AHB_M9_LP_STAT                               ( BIT(18) )
#define BIT_AP_AHB_M9_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M9_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M9_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S0_LPC, [0x20E0008C] */
#define BIT_AP_AHB_S0_FORCE_ACK                             ( BIT(19) )
#define BIT_AP_AHB_S0_LP_STAT                               ( BIT(18) )
#define BIT_AP_AHB_S0_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S0_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S0_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S1_LPC, [0x20E00090] */
#define BIT_AP_AHB_S1_FORCE_ACK                             ( BIT(19) )
#define BIT_AP_AHB_S1_LP_STAT                               ( BIT(18) )
#define BIT_AP_AHB_S1_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S1_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S1_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M_SYNC_LPC, [0x20E000A0] */
#define BIT_AP_AHB_M_SYNC_FORCE_ACK                         ( BIT(19) )
#define BIT_AP_AHB_M_SYNC_LP_STAT                           ( BIT(18) )
#define BIT_AP_AHB_M_SYNC_LP_FORCE                          ( BIT(17) )
#define BIT_AP_AHB_M_SYNC_LP_EB                             ( BIT(16) )
#define BIT_AP_AHB_M_SYNC_LP_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S_SYNC_LPC, [0x20E000A4] */
#define BIT_AP_AHB_S_SYNC_FORCE_ACK                         ( BIT(19) )
#define BIT_AP_AHB_S_SYNC_LP_STAT                           ( BIT(18) )
#define BIT_AP_AHB_S_SYNC_LP_FORCE                          ( BIT(17) )
#define BIT_AP_AHB_S_SYNC_LP_EB                             ( BIT(16) )
#define BIT_AP_AHB_S_SYNC_LP_NUM(x)                         ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_GSP_GPV_LPC, [0x20E000A8] */
#define BIT_AP_AHB_AP_GSP_GPV_FORCE_ACK                     ( BIT(19) )
#define BIT_AP_AHB_AP_GSP_GPV_LP_STAT                       ( BIT(18) )
#define BIT_AP_AHB_AP_GSP_GPV_LP_FORCE                      ( BIT(17) )
#define BIT_AP_AHB_AP_GSP_GPV_LP_EB                         ( BIT(16) )
#define BIT_AP_AHB_AP_GSP_GPV_LP_NUM(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_GSP_M0_LPC, [0x20E000AC] */
#define BIT_AP_AHB_AP_GSP_M0_FORCE_ACK                      ( BIT(19) )
#define BIT_AP_AHB_AP_GSP_M0_LP_STAT                        ( BIT(18) )
#define BIT_AP_AHB_AP_GSP_M0_LP_FORCE                       ( BIT(17) )
#define BIT_AP_AHB_AP_GSP_M0_LP_EB                          ( BIT(16) )
#define BIT_AP_AHB_AP_GSP_M0_LP_NUM(x)                      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_GSP_M1_LPC, [0x20E000B0] */
#define BIT_AP_AHB_AP_GSP_M1_FORCE_ACK                      ( BIT(19) )
#define BIT_AP_AHB_AP_GSP_M1_LP_STAT                        ( BIT(18) )
#define BIT_AP_AHB_AP_GSP_M1_LP_FORCE                       ( BIT(17) )
#define BIT_AP_AHB_AP_GSP_M1_LP_EB                          ( BIT(16) )
#define BIT_AP_AHB_AP_GSP_M1_LP_NUM(x)                      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_GSP_S0_LPC, [0x20E000B4] */
#define BIT_AP_AHB_AP_GSP_S0_FORCE_ACK                      ( BIT(19) )
#define BIT_AP_AHB_AP_GSP_S0_LP_STAT                        ( BIT(18) )
#define BIT_AP_AHB_AP_GSP_S0_LP_FORCE                       ( BIT(17) )
#define BIT_AP_AHB_AP_GSP_S0_LP_EB                          ( BIT(16) )
#define BIT_AP_AHB_AP_GSP_S0_LP_NUM(x)                      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_IMC_MAIN_LPC, [0x20E000B8] */
#define BIT_AP_AHB_AP_IMC_MAIN_FORCE_ACK                    ( BIT(19) )
#define BIT_AP_AHB_AP_IMC_MAIN_LP_STAT                      ( BIT(18) )
#define BIT_AP_AHB_AP_IMC_MAIN_LP_FORCE                     ( BIT(17) )
#define BIT_AP_AHB_AP_IMC_MAIN_LP_EB                        ( BIT(16) )
#define BIT_AP_AHB_AP_IMC_MAIN_LP_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_DISP_MAIN_LPC, [0x20E000BC] */
#define BIT_AP_AHB_AP_DISP_MAIN_FORCE_ACK                   ( BIT(19) )
#define BIT_AP_AHB_AP_DISP_MAIN_LP_STAT                     ( BIT(18) )
#define BIT_AP_AHB_AP_DISP_MAIN_LP_FORCE                    ( BIT(17) )
#define BIT_AP_AHB_AP_DISP_MAIN_LP_EB                       ( BIT(16) )
#define BIT_AP_AHB_AP_DISP_MAIN_LP_NUM(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_CA7_TOP_M0_LPC, [0x20E000C0] */
#define BIT_AP_AHB_CA7_TOP_M0_FORCE_ACK                     ( BIT(19) )
#define BIT_AP_AHB_CA7_TOP_M0_LP_STAT                       ( BIT(18) )
#define BIT_AP_AHB_CA7_TOP_M0_LP_FORCE                      ( BIT(17) )
#define BIT_AP_AHB_CA7_TOP_M0_LP_EB                         ( BIT(16) )
#define BIT_AP_AHB_CA7_TOP_M0_LP_NUM(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_CA7_TOP_S1_LPC, [0x20E000C4] */
#define BIT_AP_AHB_CA7_TOP_S1_FORCE_ACK                     ( BIT(19) )
#define BIT_AP_AHB_CA7_TOP_S1_LP_STAT                       ( BIT(18) )
#define BIT_AP_AHB_CA7_TOP_S1_LP_FORCE                      ( BIT(17) )
#define BIT_AP_AHB_CA7_TOP_S1_LP_EB                         ( BIT(16) )
#define BIT_AP_AHB_CA7_TOP_S1_LP_NUM(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_CA7_TOP_S2_LPC, [0x20E000C8] */
#define BIT_AP_AHB_CA7_TOP_S2_FORCE_ACK                     ( BIT(19) )
#define BIT_AP_AHB_CA7_TOP_S2_LP_STAT                       ( BIT(18) )
#define BIT_AP_AHB_CA7_TOP_S2_LP_FORCE                      ( BIT(17) )
#define BIT_AP_AHB_CA7_TOP_S2_LP_EB                         ( BIT(16) )
#define BIT_AP_AHB_CA7_TOP_S2_LP_NUM(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_CA7_ABRG_S0_LPC, [0x20E000CC] */
#define BIT_AP_AHB_CA7_ABRG_S0_FORCE_ACK                    ( BIT(19) )
#define BIT_AP_AHB_CA7_ABRG_S0_LP_STAT                      ( BIT(18) )
#define BIT_AP_AHB_CA7_ABRG_S0_LP_FORCE                     ( BIT(17) )
#define BIT_AP_AHB_CA7_ABRG_S0_LP_EB                        ( BIT(16) )
#define BIT_AP_AHB_CA7_ABRG_S0_LP_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_TEE_AHB_EB, [0x20E000D0] */
#define BIT_AP_AHB_TEE_DMA_EB                               ( BIT(0) )

/* bits definitions for REG_AP_AHB_USB_AHBM2AXI_S0_LPC, [0x20E000D4] */
#define BIT_AP_AHB_USB_AHBM2AXI_S0_FORCE_ACK                ( BIT(19) )
#define BIT_AP_AHB_USB_AHBM2AXI_S0_LP_STAT                  ( BIT(18) )
#define BIT_AP_AHB_USB_AHBM2AXI_S0_LP_FORCE                 ( BIT(17) )
#define BIT_AP_AHB_USB_AHBM2AXI_S0_LP_EB                    ( BIT(16) )
#define BIT_AP_AHB_USB_AHBM2AXI_S0_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_CA7_EMC_REG_SLICE_LPC, [0x20E000D8] */
#define BIT_AP_AHB_CA7_EMC_REG_SLICE_FORCE_ACK              ( BIT(19) )
#define BIT_AP_AHB_CA7_EMC_REG_SLICE_LP_STAT                ( BIT(18) )
#define BIT_AP_AHB_CA7_EMC_REG_SLICE_LP_FORCE               ( BIT(17) )
#define BIT_AP_AHB_CA7_EMC_REG_SLICE_LP_EB                  ( BIT(16) )
#define BIT_AP_AHB_CA7_EMC_REG_SLICE_LP_NUM(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_DUMMY_REG0, [0x20E00100] */
#define BIT_AP_AHB_AP_DUMMY_REG0_H16(x)                     ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_AHB_AP_DUMMY_REG0_L16(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_DUMMY_REG1, [0x20E00104] */
#define BIT_AP_AHB_AP_DUMMY_REG1(x)                         ( (x) )

/* bits definitions for REG_AP_AHB_AP_DUMMY_REG2, [0x20E00108] */
#define BIT_AP_AHB_AP_DUMMY_REG2(x)                         ( (x) )

/* bits definitions for REG_AP_AHB_AP_DUMMY_REG3, [0x20E0010C] */
#define BIT_AP_AHB_AP_DUMMY_REG3(x)                         ( (x) )

/* bits definitions for REG_AP_AHB_CA7_DUMMY_REG0, [0x20E00120] */
#define BIT_AP_AHB_CA7_DUMMY_REG0_H16(x)                    ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_AHB_CA7_DUMMY_REG0_L16(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_CA7_DUMMY_REG1, [0x20E00124] */
#define BIT_AP_AHB_CA7_DUMMY_REG1(x)                        ( (x) )

/* bits definitions for REG_AP_AHB_CA7_CORE_INT_DISABLE_EN, [0x20E00128] */
#define BIT_AP_AHB_CA7_C3_CORE_INT_DISABLE_EN               ( BIT(3) )
#define BIT_AP_AHB_CA7_C2_CORE_INT_DISABLE_EN               ( BIT(2) )
#define BIT_AP_AHB_CA7_C1_CORE_INT_DISABLE_EN               ( BIT(1) )
#define BIT_AP_AHB_CA7_C0_CORE_INT_DISABLE_EN               ( BIT(0) )

/* bits definitions for REG_AP_AHB_CA7_STANDBY_STATUS, [0x20E03008] */
#define BIT_AP_AHB_CA7_STANDBYWFIL2                         ( BIT(12) )
#define BIT_AP_AHB_CA7_ETMSTANDBYWFX(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_CA7_STANDBYWFE(x)                        ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_CA7_STANDBYWFI(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS_CFG, [0x20E0301C] */
#define BIT_AP_AHB_HPROT_OTG(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_AP_GSP_M0(x)                       ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_AP_GSP_M0(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_OTG_PHY_TUNE, [0x20E03020] */
#define BIT_AP_AHB_OTG_TXPREEMPPULSETUNE                    ( BIT(20) )
#define BIT_AP_AHB_OTG_TXRESTUNE(x)                         ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_AP_AHB_OTG_TXHSXVTUNE(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AP_AHB_OTG_TXVREFTUNE(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_OTG_TXPREEMPAMPTUNE(x)                   ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AP_AHB_OTG_TXRISETUNE(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AP_AHB_OTG_TXFSLSTUNE(x)                        ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_OTG_SQRXTUNE(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_AHB_OTG_PHY_TEST, [0x20E03024] */
#define BIT_AP_AHB_OTG_ATERESET                             ( BIT(31) )
#define BIT_AP_AHB_OTG_VBUS_VALID_PHYREG                    ( BIT(24) )
#define BIT_AP_AHB_OTG_VBUS_VALID_PHYREG_SEL                ( BIT(23) )
#define BIT_AP_AHB_OTG_VBUS_VALID_EXT                       ( BIT(22) )
#define BIT_AP_AHB_OTG_TESTBURNIN                           ( BIT(21) )
#define BIT_AP_AHB_OTG_LOOPBACKENB                          ( BIT(20) )
#define BIT_AP_AHB_OTG_TESTDATAOUT(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_OTG_VATESTENB(x)                         ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AP_AHB_OTG_TESTCLK                              ( BIT(13) )
#define BIT_AP_AHB_OTG_TESTDATAOUTSEL                       ( BIT(12) )
#define BIT_AP_AHB_OTG_TESTADDR(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_OTG_TESTDATAIN(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AP_AHB_OTG_PHY_CTRL, [0x20E03028] */
#define BIT_AP_AHB_USB2_CON_TESTMODE                        ( BIT(31) )
#define BIT_AP_AHB_UTMI_WIDTH_SEL                           ( BIT(30) )
#define BIT_AP_AHB_USB2_DATABUS16_8                         ( BIT(29) )
#define BIT_AP_AHB_OTG_SS_SCALEDOWNMODE(x)                  ( (x) << 25 & (BIT(25)|BIT(26)) )
#define BIT_AP_AHB_OTG_TXBITSTUFFENH                        ( BIT(23) )
#define BIT_AP_AHB_OTG_TXBITSTUFFEN                         ( BIT(22) )
#define BIT_AP_AHB_OTG_DMPULLDOWN                           ( BIT(21) )
#define BIT_AP_AHB_OTG_DPPULLDOWN                           ( BIT(20) )
#define BIT_AP_AHB_OTG_DMPULLUP                             ( BIT(9) )
#define BIT_AP_AHB_OTG_COMMONONN                            ( BIT(8) )
#define BIT_AP_AHB_USB2_PHY_IDDIG                           ( BIT(3) )
#define BIT_AP_AHB_OTG_FSEL(x)                              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_AHB_OTG_CTRL0, [0x20E0302C] */
#define BIT_AP_AHB_USB20_TUNEHSAMP(x)                       ( (x) << 30 & (BIT(30)|BIT(31)) )
#define BIT_AP_AHB_USB20_TUNEPLLS(x)                        ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_AP_AHB_USB20_TUNERISE(x)                        ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_AP_AHB_USB20_TUNEDSC(x)                         ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_AP_AHB_USB20_TUNEOTG(x)                         ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_USB20_TUNESQ(x)                          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AP_AHB_USB20_RESERVED(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_OTG_CTRL1, [0x20E03030] */
#define BIT_AP_AHB_USB20_BIST_MODE(x)                       ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_USB20_BYPASS_DRV_DM                      ( BIT(22) )
#define BIT_AP_AHB_USB20_BYPASS_DRV_DP                      ( BIT(21) )
#define BIT_AP_AHB_USB20_SAMPLER_SEL                        ( BIT(20) )
#define BIT_AP_AHB_HSIC_PLLON                               ( BIT(16) )
#define BIT_AP_AHB_USB20_REXTENABLE                         ( BIT(15) )
#define BIT_AP_AHB_USB20_S_ID                               ( BIT(14) )
#define BIT_AP_AHB_USB20_TFREGRES(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AP_AHB_USB20_TFHSRES(x)                         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_USB20_TUNEEQ(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_AHB_CHIP_ID, [0x20E030FC] */
#define BIT_AP_AHB_CHIP_ID(x)                               ( (x) )

/* vars definitions for controller CTL_AP_AHB */


#endif /* __AP_AHB_H____ */
