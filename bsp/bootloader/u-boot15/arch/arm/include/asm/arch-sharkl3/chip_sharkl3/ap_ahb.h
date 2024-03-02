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
#define REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG                   SCI_ADDR(CTL_AP_AHB_BASE, 0x000C)
#define REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG                    SCI_ADDR(CTL_AP_AHB_BASE, 0x0010)
#define REG_AP_AHB_RESERVED0_REG                            SCI_ADDR(CTL_AP_AHB_BASE, 0x0018)
#define REG_AP_AHB_RESERVED1_REG                            SCI_ADDR(CTL_AP_AHB_BASE, 0x001C)
#define REG_AP_AHB_RESERVED2_REG                            SCI_ADDR(CTL_AP_AHB_BASE, 0x0020)
#define REG_AP_AHB_AP_MTX_WQOS_CFG                          SCI_ADDR(CTL_AP_AHB_BASE, 0x3004)
#define REG_AP_AHB_AP_MTX_RQOS_CFG                          SCI_ADDR(CTL_AP_AHB_BASE, 0x3008)
#define REG_AP_AHB_AP_QOS_CFG                               SCI_ADDR(CTL_AP_AHB_BASE, 0x3010)
#define REG_AP_AHB_AP_URGENCY_BYPASS_ADDRESS                SCI_ADDR(CTL_AP_AHB_BASE, 0x3018)
#define REG_AP_AHB_AP_FRC_URGENCY                           SCI_ADDR(CTL_AP_AHB_BASE, 0x301C)
#define REG_AP_AHB_OTG_PHY_TUNE                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3020)
#define REG_AP_AHB_OTG_PHY_TEST                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3024)
#define REG_AP_AHB_OTG_PHY_CTRL                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3028)
#define REG_AP_AHB_OTG_CTRL1                                SCI_ADDR(CTL_AP_AHB_BASE, 0x3030)
#define REG_AP_AHB_MST_FRC_LSLP                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3034)
#define REG_AP_AHB_MTX_LSLP_LPC_BYPASS                      SCI_ADDR(CTL_AP_AHB_BASE, 0x3038)
#define REG_AP_AHB_MST_PUB_FRC_DSLP                         SCI_ADDR(CTL_AP_AHB_BASE, 0x303C)
#define REG_AP_AHB_MTX_PUB_DSLP_LPC_BYPASS                  SCI_ADDR(CTL_AP_AHB_BASE, 0x3040)
#define REG_AP_AHB_MTX_FRC_DOZE_SLEEP                       SCI_ADDR(CTL_AP_AHB_BASE, 0x3044)
#define REG_AP_AHB_MTX_DOZE_LPC_BYPASS                      SCI_ADDR(CTL_AP_AHB_BASE, 0x3048)
#define REG_AP_AHB_MTX_AXI_FREQ_ALLOW                       SCI_ADDR(CTL_AP_AHB_BASE, 0x304C)
#define REG_AP_AHB_M1_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3064)
#define REG_AP_AHB_M2_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3068)
#define REG_AP_AHB_M3_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x306C)
#define REG_AP_AHB_M4_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3070)
#define REG_AP_AHB_M5_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3074)
#define REG_AP_AHB_M6_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3078)
#define REG_AP_AHB_M7_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x307C)
#define REG_AP_AHB_M8_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3080)
#define REG_AP_AHB_MAIN_LPC                                 SCI_ADDR(CTL_AP_AHB_BASE, 0x3088)
#define REG_AP_AHB_S0_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x308C)
#define REG_AP_AHB_S1_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3090)
#define REG_AP_AHB_S2_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3094)
#define REG_AP_AHB_S3_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x3098)
#define REG_AP_AHB_S4_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x309C)
#define REG_AP_AHB_S5_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x30A0)
#define REG_AP_AHB_M10_LPC                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x30A4)
#define REG_AP_AHB_ASYNC_BRIDGE_AP2DDR_LPC                  SCI_ADDR(CTL_AP_AHB_BASE, 0x30A8)

/* bits definitions for REG_AP_AHB_AHB_EB, [0x20E00000] */
#define BIT_AP_AHB_NANDC_26M_EB                             ( BIT(31) )
#define BIT_AP_AHB_SDIO2_32K_EB                             ( BIT(30) )
#define BIT_AP_AHB_SDIO1_32K_EB                             ( BIT(29) )
#define BIT_AP_AHB_SDIO0_32K_EB                             ( BIT(28) )
#define BIT_AP_AHB_EMMC_32K_EB                              ( BIT(27) )
#define BIT_AP_AHB_EMMC_EB                                  ( BIT(11) )
#define BIT_AP_AHB_SDIO2_EB                                 ( BIT(10) )
#define BIT_AP_AHB_SDIO1_EB                                 ( BIT(9) )
#define BIT_AP_AHB_SDIO0_EB                                 ( BIT(8) )
#define BIT_AP_AHB_NANDC_EB                                 ( BIT(7) )
#define BIT_AP_AHB_CE_EB                                    ( BIT(6) )
#define BIT_AP_AHB_DMA_EB                                   ( BIT(5) )
#define BIT_AP_AHB_OTG_EB                                   ( BIT(4) )

/* bits definitions for REG_AP_AHB_AHB_RST, [0x20E00004] */
#define BIT_AP_AHB_EMMC_32K_SOFT_RST                        ( BIT(20) )
#define BIT_AP_AHB_SDIO2_32K_SOFT_RST                       ( BIT(19) )
#define BIT_AP_AHB_SDIO1_32K_SOFT_RST                       ( BIT(18) )
#define BIT_AP_AHB_SDIO0_32K_SOFT_RST                       ( BIT(17) )
#define BIT_AP_AHB_CE_SEC_SOFT_RST                          ( BIT(15) )
#define BIT_AP_AHB_EMMC_SOFT_RST                            ( BIT(14) )
#define BIT_AP_AHB_SDIO2_SOFT_RST                           ( BIT(13) )
#define BIT_AP_AHB_SDIO1_SOFT_RST                           ( BIT(12) )
#define BIT_AP_AHB_SDIO0_SOFT_RST                           ( BIT(11) )
#define BIT_AP_AHB_NANDC_SOFT_RST                           ( BIT(10) )
#define BIT_AP_AHB_CE_PUB_SOFT_RST                          ( BIT(9) )
#define BIT_AP_AHB_DMA_SOFT_RST                             ( BIT(8) )
#define BIT_AP_AHB_OTG_UTMI_SOFT_RST                        ( BIT(5) )
#define BIT_AP_AHB_OTG_SOFT_RST                             ( BIT(4) )

/* bits definitions for REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG, [0x20E0000C] */
#define BIT_AP_AHB_RESERVED3_REG(x)                         ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_AP_APB_SEL_SLOW(x)                   ( (x) << 7  & (BIT(7)|BIT(8)) )
#define BIT_AP_AHB_AP_DOZE_SLEEP_SLOW_DOWN_EN               ( BIT(6) )
#define BIT_AP_AHB_MCU_SLEEP_FOLLOW_CA53_EN                 ( BIT(5) )
#define BIT_AP_AHB_MCU_CORE_SLEEP                           ( BIT(4) )
#define BIT_AP_AHB_DMA_ACT_LIGHT_EN                         ( BIT(3) )
#define BIT_AP_AHB_AP_PERI_FORCE_ON                         ( BIT(2) )
#define BIT_AP_AHB_AP_PERI_FORCE_SLP                        ( BIT(1) )
#define BIT_AP_AHB_AP_APB_SLEEP                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG, [0x20E00010] */
#define BIT_AP_AHB_CACTIVE_SLV3_WAKEUP_EN                   ( BIT(10) )
#define BIT_AP_AHB_AP_CLK_GATE_LPC_BYP                      ( BIT(8) )
#define BIT_AP_AHB_LP_AUTO_CTRL_EN                          ( BIT(7) )
#define BIT_AP_AHB_AP_MAINMTX_LP_DISABLE                    ( BIT(6) )

/* bits definitions for REG_AP_AHB_RESERVED0_REG, [0x20E00018] */
#define BIT_AP_AHB_RESERVED0_REG(x)                         ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CE_EB2                                   ( BIT(1) )
#define BIT_AP_AHB_DMA_EB2                                  ( BIT(0) )

/* bits definitions for REG_AP_AHB_RESERVED1_REG, [0x20E0001C] */
#define BIT_AP_AHB_RESERVED1_REG(x)                         ( (x) )

/* bits definitions for REG_AP_AHB_RESERVED2_REG, [0x20E00020] */
#define BIT_AP_AHB_RESERVED2_REG(x)                         ( (x) )

/* bits definitions for REG_AP_AHB_AP_MTX_WQOS_CFG, [0x20E03004] */
#define BIT_AP_AHB_AWQOS_M10(x)                             ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWQOS_M8(x)                              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_AWQOS_M7(x)                              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_M6(x)                              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_AWQOS_M5(x)                              ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_M4(x)                              ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_AWQOS_M3(x)                              ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_M2(x)                              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_MTX_RQOS_CFG, [0x20E03008] */
#define BIT_AP_AHB_ARQOS_M10(x)                             ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_ARQOS_M8(x)                              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARQOS_M7(x)                              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_ARQOS_M6(x)                              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_M5(x)                              ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_ARQOS_M4(x)                              ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_M3(x)                              ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_ARQOS_M2(x)                              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS_CFG, [0x20E03010] */
#define BIT_AP_AHB_ARQOS_THRESHHOLD(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_THRESHHOLD(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_URGENCY_BYPASS_ADDRESS, [0x20E03018] */
#define BIT_AP_AHB_URGENCY_BYPASS_M10_RD_ADDRESS            ( BIT(15) )
#define BIT_AP_AHB_URGENCY_BYPASS_M8_RD_ADDRESS             ( BIT(14) )
#define BIT_AP_AHB_URGENCY_BYPASS_M7_RD_ADDRESS             ( BIT(13) )
#define BIT_AP_AHB_URGENCY_BYPASS_M6_RD_ADDRESS             ( BIT(12) )
#define BIT_AP_AHB_URGENCY_BYPASS_M5_RD_ADDRESS             ( BIT(11) )
#define BIT_AP_AHB_URGENCY_BYPASS_M4_RD_ADDRESS             ( BIT(10) )
#define BIT_AP_AHB_URGENCY_BYPASS_M3_RD_ADDRESS             ( BIT(9) )
#define BIT_AP_AHB_URGENCY_BYPASS_M2_RD_ADDRESS             ( BIT(8) )
#define BIT_AP_AHB_URGENCY_BYPASS_M10_WR_ADDRESS            ( BIT(7) )
#define BIT_AP_AHB_URGENCY_BYPASS_M8_WR_ADDRESS             ( BIT(6) )
#define BIT_AP_AHB_URGENCY_BYPASS_M7_WR_ADDRESS             ( BIT(5) )
#define BIT_AP_AHB_URGENCY_BYPASS_M6_WR_ADDRESS             ( BIT(4) )
#define BIT_AP_AHB_URGENCY_BYPASS_M5_WR_ADDRESS             ( BIT(3) )
#define BIT_AP_AHB_URGENCY_BYPASS_M4_WR_ADDRESS             ( BIT(2) )
#define BIT_AP_AHB_URGENCY_BYPASS_M3_WR_ADDRESS             ( BIT(1) )
#define BIT_AP_AHB_URGENCY_BYPASS_M2_WR_ADDRESS             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_FRC_URGENCY, [0x20E0301C] */
#define BIT_AP_AHB_FRC_M10_RD_URGENCY                       ( BIT(15) )
#define BIT_AP_AHB_FRC_M8_RD_URGENCY                        ( BIT(14) )
#define BIT_AP_AHB_FRC_M7_RD_URGENCY                        ( BIT(13) )
#define BIT_AP_AHB_FRC_M6_RD_URGENCY                        ( BIT(12) )
#define BIT_AP_AHB_FRC_M5_RD_URGENCY                        ( BIT(11) )
#define BIT_AP_AHB_FRC_M4_RD_URGENCY                        ( BIT(10) )
#define BIT_AP_AHB_FRC_M3_RD_URGENCY                        ( BIT(9) )
#define BIT_AP_AHB_FRC_M2_RD_URGENCY                        ( BIT(8) )
#define BIT_AP_AHB_FRC_M10_WR_URGENCY                       ( BIT(7) )
#define BIT_AP_AHB_FRC_M8_WR_URGENCY                        ( BIT(6) )
#define BIT_AP_AHB_FRC_M7_WR_URGENCY                        ( BIT(5) )
#define BIT_AP_AHB_FRC_M6_WR_URGENCY                        ( BIT(4) )
#define BIT_AP_AHB_FRC_M5_WR_URGENCY                        ( BIT(3) )
#define BIT_AP_AHB_FRC_M4_WR_URGENCY                        ( BIT(2) )
#define BIT_AP_AHB_FRC_M3_WR_URGENCY                        ( BIT(1) )
#define BIT_AP_AHB_FRC_M2_WR_URGENCY                        ( BIT(0) )

/* bits definitions for REG_AP_AHB_OTG_PHY_TUNE, [0x20E03020] */

/* bits definitions for REG_AP_AHB_OTG_PHY_TEST, [0x20E03024] */
#define BIT_AP_AHB_OTG_VBUS_VALID_PHYREG                    ( BIT(28) )
#define BIT_AP_AHB_OTG_VBUS_VALID_PHYREG_SEL                ( BIT(27) )

/* bits definitions for REG_AP_AHB_OTG_PHY_CTRL, [0x20E03028] */
#define BIT_AP_AHB_USB2_CON_TESTMODE                        ( BIT(31) )
#define BIT_AP_AHB_UTMI_WIDTH_SEL                           ( BIT(30) )

/* bits definitions for REG_AP_AHB_OTG_CTRL1, [0x20E03030] */

/* bits definitions for REG_AP_AHB_MST_FRC_LSLP, [0x20E03034] */
#define BIT_AP_AHB_SLV3_FRC_LSLP                            ( BIT(11) )
#define BIT_AP_AHB_MST10_FRC_LSLP                           ( BIT(10) )
#define BIT_AP_AHB_MST8_FRC_LSLP                            ( BIT(8) )
#define BIT_AP_AHB_MST7_FRC_LSLP                            ( BIT(7) )
#define BIT_AP_AHB_MST6_FRC_LSLP                            ( BIT(6) )
#define BIT_AP_AHB_MST5_FRC_LSLP                            ( BIT(5) )
#define BIT_AP_AHB_MST4_FRC_LSLP                            ( BIT(4) )
#define BIT_AP_AHB_MST3_FRC_LSLP                            ( BIT(3) )
#define BIT_AP_AHB_MST2_FRC_LSLP                            ( BIT(2) )
#define BIT_AP_AHB_MST1_FRC_LSLP                            ( BIT(1) )

/* bits definitions for REG_AP_AHB_MTX_LSLP_LPC_BYPASS, [0x20E03038] */
#define BIT_AP_AHB_LIGHT_S3_LPC_BYPASS                      ( BIT(11) )
#define BIT_AP_AHB_LIGHT_M10_LPC_BYPASS                     ( BIT(10) )
#define BIT_AP_AHB_LIGHT_M8_LPC_BYPASS                      ( BIT(8) )
#define BIT_AP_AHB_LIGHT_M7_LPC_BYPASS                      ( BIT(7) )
#define BIT_AP_AHB_LIGHT_M6_LPC_BYPASS                      ( BIT(6) )
#define BIT_AP_AHB_LIGHT_M5_LPC_BYPASS                      ( BIT(5) )
#define BIT_AP_AHB_LIGHT_M4_LPC_BYPASS                      ( BIT(4) )
#define BIT_AP_AHB_LIGHT_M3_LPC_BYPASS                      ( BIT(3) )
#define BIT_AP_AHB_LIGHT_M2_LPC_BYPASS                      ( BIT(2) )
#define BIT_AP_AHB_LIGHT_M1_LPC_BYPASS                      ( BIT(1) )

/* bits definitions for REG_AP_AHB_MST_PUB_FRC_DSLP, [0x20E0303C] */
#define BIT_AP_AHB_MST10_PUB_FRC_DSLP                       ( BIT(10) )
#define BIT_AP_AHB_MST8_PUB_FRC_DSLP                        ( BIT(8) )
#define BIT_AP_AHB_MST7_PUB_FRC_DSLP                        ( BIT(7) )
#define BIT_AP_AHB_MST6_PUB_FRC_DSLP                        ( BIT(6) )
#define BIT_AP_AHB_MST5_PUB_FRC_DSLP                        ( BIT(5) )
#define BIT_AP_AHB_MST4_PUB_FRC_DSLP                        ( BIT(4) )
#define BIT_AP_AHB_MST3_PUB_FRC_DSLP                        ( BIT(3) )
#define BIT_AP_AHB_MST2_PUB_FRC_DSLP                        ( BIT(2) )
#define BIT_AP_AHB_MST1_PUB_FRC_DSLP                        ( BIT(1) )

/* bits definitions for REG_AP_AHB_MTX_PUB_DSLP_LPC_BYPASS, [0x20E03040] */
#define BIT_AP_AHB_PUB_DSLP_S3_LPC_BYPASS                   ( BIT(11) )
#define BIT_AP_AHB_PUB_DSLP_M10_LPC_BYPASS                  ( BIT(10) )
#define BIT_AP_AHB_PUB_DSLP_M8_LPC_BYPASS                   ( BIT(8) )
#define BIT_AP_AHB_PUB_DSLP_M7_LPC_BYPASS                   ( BIT(7) )
#define BIT_AP_AHB_PUB_DSLP_M6_LPC_BYPASS                   ( BIT(6) )
#define BIT_AP_AHB_PUB_DSLP_M5_LPC_BYPASS                   ( BIT(5) )
#define BIT_AP_AHB_PUB_DSLP_M4_LPC_BYPASS                   ( BIT(4) )
#define BIT_AP_AHB_PUB_DSLP_M3_LPC_BYPASS                   ( BIT(3) )
#define BIT_AP_AHB_PUB_DSLP_M2_LPC_BYPASS                   ( BIT(2) )
#define BIT_AP_AHB_PUB_DSLP_M1_LPC_BYPASS                   ( BIT(1) )

/* bits definitions for REG_AP_AHB_MTX_FRC_DOZE_SLEEP, [0x20E03044] */
#define BIT_AP_AHB_M10_FRC_DOZE                             ( BIT(15) )
#define BIT_AP_AHB_M8_FRC_DOZE                              ( BIT(14) )
#define BIT_AP_AHB_M7_FRC_DOZE                              ( BIT(13) )
#define BIT_AP_AHB_M6_FRC_DOZE                              ( BIT(12) )
#define BIT_AP_AHB_M5_FRC_DOZE                              ( BIT(11) )
#define BIT_AP_AHB_M4_FRC_DOZE                              ( BIT(10) )
#define BIT_AP_AHB_M3_FRC_DOZE                              ( BIT(9) )
#define BIT_AP_AHB_M2_FRC_DOZE                              ( BIT(8) )
#define BIT_AP_AHB_M1_FRC_DOZE                              ( BIT(7) )
#define BIT_AP_AHB_MAIN_FRC_DOZE                            ( BIT(6) )
#define BIT_AP_AHB_S5_FRC_DOZE                              ( BIT(5) )
#define BIT_AP_AHB_S4_FRC_DOZE                              ( BIT(4) )
#define BIT_AP_AHB_S3_FRC_DOZE                              ( BIT(3) )
#define BIT_AP_AHB_S2_FRC_DOZE                              ( BIT(2) )
#define BIT_AP_AHB_S1_FRC_DOZE                              ( BIT(1) )
#define BIT_AP_AHB_S0_FRC_DOZE                              ( BIT(0) )

/* bits definitions for REG_AP_AHB_MTX_DOZE_LPC_BYPASS, [0x20E03048] */
#define BIT_AP_AHB_DOZE_M10_LPC_BYPASS                      ( BIT(15) )
#define BIT_AP_AHB_DOZE_M8_LPC_BYPASS                       ( BIT(14) )
#define BIT_AP_AHB_DOZE_M7_LPC_BYPASS                       ( BIT(13) )
#define BIT_AP_AHB_DOZE_M6_LPC_BYPASS                       ( BIT(12) )
#define BIT_AP_AHB_DOZE_M5_LPC_BYPASS                       ( BIT(11) )
#define BIT_AP_AHB_DOZE_M4_LPC_BYPASS                       ( BIT(10) )
#define BIT_AP_AHB_DOZE_M3_LPC_BYPASS                       ( BIT(9) )
#define BIT_AP_AHB_DOZE_M2_LPC_BYPASS                       ( BIT(8) )
#define BIT_AP_AHB_DOZE_M1_LPC_BYPASS                       ( BIT(7) )
#define BIT_AP_AHB_DOZE_MAIN_LPC_BYPASS                     ( BIT(6) )
#define BIT_AP_AHB_DOZE_S5_LPC_BYPASS                       ( BIT(5) )
#define BIT_AP_AHB_DOZE_S4_LPC_BYPASS                       ( BIT(4) )
#define BIT_AP_AHB_DOZE_S3_LPC_BYPASS                       ( BIT(3) )
#define BIT_AP_AHB_DOZE_S2_LPC_BYPASS                       ( BIT(2) )
#define BIT_AP_AHB_DOZE_S1_LPC_BYPASS                       ( BIT(1) )
#define BIT_AP_AHB_DOZE_S0_LPC_BYPASS                       ( BIT(0) )

/* bits definitions for REG_AP_AHB_MTX_AXI_FREQ_ALLOW, [0x20E0304C] */
#define BIT_AP_AHB_M10_AXI_FREQ_ALLOW(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AP_AHB_M8_AXI_FREQ_ALLOW(x)                     ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_M7_AXI_FREQ_ALLOW(x)                     ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AP_AHB_M6_AXI_FREQ_ALLOW(x)                     ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AP_AHB_M5_AXI_FREQ_ALLOW(x)                     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AP_AHB_M4_AXI_FREQ_ALLOW(x)                     ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_M3_AXI_FREQ_ALLOW(x)                     ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_AHB_M2_AXI_FREQ_ALLOW(x)                     ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_AHB_M1_AXI_FREQ_ALLOW(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_AHB_M1_LPC, [0x20E03064] */
#define BIT_AP_AHB_M1_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M1_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M2_LPC, [0x20E03068] */
#define BIT_AP_AHB_M2_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M2_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M2_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M3_LPC, [0x20E0306C] */
#define BIT_AP_AHB_M3_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M3_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M3_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M4_LPC, [0x20E03070] */
#define BIT_AP_AHB_M4_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M4_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M4_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M5_LPC, [0x20E03074] */
#define BIT_AP_AHB_M5_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M5_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M5_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M6_LPC, [0x20E03078] */
#define BIT_AP_AHB_M6_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M6_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M6_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M7_LPC, [0x20E0307C] */
#define BIT_AP_AHB_M7_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M7_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M7_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M8_LPC, [0x20E03080] */
#define BIT_AP_AHB_M8_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_M8_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_M8_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MAIN_LPC, [0x20E03088] */
#define BIT_AP_AHB_MAIN_LP_EB                               ( BIT(16) )
#define BIT_AP_AHB_MAIN_LP_NUM(x)                           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S0_LPC, [0x20E0308C] */
#define BIT_AP_AHB_S0_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S0_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S1_LPC, [0x20E03090] */
#define BIT_AP_AHB_S1_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S1_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S1_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S2_LPC, [0x20E03094] */
#define BIT_AP_AHB_S2_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S2_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S2_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S3_LPC, [0x20E03098] */
#define BIT_AP_AHB_S3_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S3_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S3_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S4_LPC, [0x20E0309C] */
#define BIT_AP_AHB_S4_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S4_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S4_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S5_LPC, [0x20E030A0] */
#define BIT_AP_AHB_S5_LP_FORCE                              ( BIT(17) )
#define BIT_AP_AHB_S5_LP_EB                                 ( BIT(16) )
#define BIT_AP_AHB_S5_LP_NUM(x)                             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M10_LPC, [0x20E030A4] */
#define BIT_AP_AHB_M10_LP_FORCE                             ( BIT(17) )
#define BIT_AP_AHB_M10_LP_EB                                ( BIT(16) )
#define BIT_AP_AHB_M10_LP_NUM(x)                            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_AP2DDR_LPC, [0x20E030A8] */
#define BIT_AP_AHB_ASYNC_BRIDGE_AP2DDR_LP_FORCE             ( BIT(17) )
#define BIT_AP_AHB_ASYNC_BRIDGE_AP2DDR_LP_EB                ( BIT(16) )
#define BIT_AP_AHB_ASYNC_BRIDGE_AP2DDR_LP_NUM(x)            ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_AP_AHB */


#endif /* __AP_AHB_H____ */
