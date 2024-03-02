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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/AP_SYS/SharkL6 AP AHB Control Register.xls;AP_AHB_REG
 *     Revision : 239430
 *     Author   : {author}
 *     Date     : {date}
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
#define CTL_AP_AHB_BASE                 SCI_IOMAP(0x20400000)
#endif

/* registers definitions for CTL_AP_AHB, 0x20400000 */
#define REG_AP_AHB_AHB_EB                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0000)
#define REG_AP_AHB_AHB_RST                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0004)
#define REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG                   SCI_ADDR(CTL_AP_AHB_BASE, 0x000C)
#define REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG                    SCI_ADDR(CTL_AP_AHB_BASE, 0x0010)
#define REG_AP_AHB_HOLDING_PEN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0014)
#define REG_AP_AHB_CLOCK_FREQUENCY_DOWN                     SCI_ADDR(CTL_AP_AHB_BASE, 0x0018)
#define REG_AP_AHB_UFS_CLK_EN_FORCE_ON_OFF                  SCI_ADDR(CTL_AP_AHB_BASE, 0x001C)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0020)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0024)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0028)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1                   SCI_ADDR(CTL_AP_AHB_BASE, 0x002C)
#define REG_AP_AHB_MISC_CKG_EN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0040)
#define REG_AP_AHB_DISP_ASYNC_BRG                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0050)
#define REG_AP_AHB_AP_ASYNC_BRG                             SCI_ADDR(CTL_AP_AHB_BASE, 0x005C)
#define REG_AP_AHB_M0_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0060)
#define REG_AP_AHB_M1_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0064)
#define REG_AP_AHB_M2_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0068)
#define REG_AP_AHB_M3_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x006C)
#define REG_AP_AHB_M4_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0070)
#define REG_AP_AHB_M5_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0074)
#define REG_AP_AHB_M6_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0078)
#define REG_AP_AHB_M7_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x007C)
#define REG_AP_AHB_MAIN_LPC                                 SCI_ADDR(CTL_AP_AHB_BASE, 0x0088)
#define REG_AP_AHB_S0_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x008C)
#define REG_AP_AHB_S1_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0090)
#define REG_AP_AHB_S2_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0094)
#define REG_AP_AHB_S3_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0098)
#define REG_AP_AHB_S4_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x009C)
#define REG_AP_AHB_S5_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0058)
#define REG_AP_AHB_S6_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0054)
#define REG_AP_AHB_MERGE_M0_LPC                             SCI_ADDR(CTL_AP_AHB_BASE, 0x00A0)
#define REG_AP_AHB_MERGE_M1_LPC                             SCI_ADDR(CTL_AP_AHB_BASE, 0x00A4)
#define REG_AP_AHB_MERGE_S0_LPC                             SCI_ADDR(CTL_AP_AHB_BASE, 0x00AC)
#define REG_AP_AHB_AP_QOS0                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00B0)
#define REG_AP_AHB_AP_QOS1                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00B8)
#define REG_AP_AHB_AP_QOS2                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00BC)
#define REG_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW               SCI_ADDR(CTL_AP_AHB_BASE, 0x00C0)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP         SCI_ADDR(CTL_AP_AHB_BASE, 0x00C8)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP           SCI_ADDR(CTL_AP_AHB_BASE, 0x00CC)
#define REG_AP_AHB_SYS_RST                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x3010)
#define REG_AP_AHB_CACHE_EMMC_SDIO                          SCI_ADDR(CTL_AP_AHB_BASE, 0x3014)
#define REG_AP_AHB_CACHE_UFS                                SCI_ADDR(CTL_AP_AHB_BASE, 0x3018)
#define REG_AP_AHB_AP_QOS_CFG                               SCI_ADDR(CTL_AP_AHB_BASE, 0x301C)
#define REG_AP_AHB_DSI_PHY                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x3034)
#define REG_AP_AHB_CHIP_ID                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x30FC)
#define REG_AP_AHB_UFS_LP_CTRL_0                            SCI_ADDR(CTL_AP_AHB_BASE, 0x3100)
#define REG_AP_AHB_UFS_LP_CTRL_1                            SCI_ADDR(CTL_AP_AHB_BASE, 0x3104)
#define REG_AP_AHB_UFS_CONTROLLER                           SCI_ADDR(CTL_AP_AHB_BASE, 0x3108)
#define REG_AP_AHB_MPHY_TX_TEST_OBSERVE                     SCI_ADDR(CTL_AP_AHB_BASE, 0x310C)
#define REG_AP_AHB_MPHY_RX_TEST_OBSERVE                     SCI_ADDR(CTL_AP_AHB_BASE, 0x3110)
#define REG_AP_AHB_MPHY_CB_TEST_OBSERVE                     SCI_ADDR(CTL_AP_AHB_BASE, 0x3114)
#define REG_AP_AHB_MPHY_RESERVE_IO                          SCI_ADDR(CTL_AP_AHB_BASE, 0x3118)
#define REG_AP_AHB_MPHY_CB_CHANNEL_0                        SCI_ADDR(CTL_AP_AHB_BASE, 0x311C)
#define REG_AP_AHB_MPHY_CB_CHANNEL_1                        SCI_ADDR(CTL_AP_AHB_BASE, 0x3120)
#define REG_AP_AHB_UFS_CLK_CTRL                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3124)
#define REG_AP_AHB_MTX_BUS_EN                               SCI_ADDR(CTL_AP_AHB_BASE, 0x3128)
#define REG_AP_AHB_UFS_CONTROLLER_STATUS                    SCI_ADDR(CTL_AP_AHB_BASE, 0x312C)

/* bits definitions for REG_AP_AHB_AHB_EB, [0x20400000] */
#define BIT_AP_AHB_DMA_EB                                   ( BIT(5) )
#define BIT_AP_AHB_DMA_ENABLE                               ( BIT(4) )
#define BIT_AP_AHB_VSP_EB                                   ( BIT(2) )
#define BIT_AP_AHB_DISPC_EB                                 ( BIT(1) )
#define BIT_AP_AHB_DSI_EB                                   ( BIT(0) )

/* bits definitions for REG_AP_AHB_AHB_RST, [0x20400004] */
#define BIT_AP_AHB_DISPC_VAU_SOFT_RST                       ( BIT(14) )
#define BIT_AP_AHB_VSP_SOFT_RST                             ( BIT(13) )
#define BIT_AP_AHB_VPP_SOFT_RST                             ( BIT(12) )
#define BIT_AP_AHB_VSP_GLOBAL_SOFT_RST                      ( BIT(11) )
#define BIT_AP_AHB_VSP_VAU_SOFT_RST                         ( BIT(10) )
#define BIT_AP_AHB_DMA_SOFT_RST                             ( BIT(8) )
#define BIT_AP_AHB_DISPC_SOFT_RST                           ( BIT(1) )
#define BIT_AP_AHB_DSI_SOFT_RST                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG, [0x2040000C] */
#define BIT_AP_AHB_AXI_LP_CTRL_DISABLE                      ( BIT(3) )
#define BIT_AP_AHB_PERI_FORCE_ON                            ( BIT(2) )
#define BIT_AP_AHB_PERI_FORCE_OFF                           ( BIT(1) )
#define BIT_AP_AHB_CGM_CLK_AP_AXI_AUTO_GATE_EN              ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG, [0x20400010] */
#define BIT_AP_AHB_AP_MAINMTX_LP_DISABLE                    ( BIT(6) )
#define BIT_AP_AHB_AP_AHB_AUTO_GATE_EN                      ( BIT(5) )
#define BIT_AP_AHB_AP_EMC_AUTO_GATE_EN                      ( BIT(4) )

/* bits definitions for REG_AP_AHB_HOLDING_PEN, [0x20400014] */
#define BIT_AP_AHB_HOLDING_PEN(x)                           ( (x) )

/* bits definitions for REG_AP_AHB_CLOCK_FREQUENCY_DOWN, [0x20400018] */
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_UFS               ( BIT(10) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_SDIO2             ( BIT(9) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_SDIO1             ( BIT(8) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_SDIO0             ( BIT(7) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_EMMC              ( BIT(6) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_APCPU             ( BIT(5) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_DMA               ( BIT(4) )
#define BIT_AP_AHB_AP_APB_AUTO_CONTROL_SEL                  ( BIT(3) )
#define BIT_AP_AHB_AP_APB_AUTO_MUX_SEL(x)                   ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_AP_AHB_AP_APB_AUTO_MUX_EN                       ( BIT(0) )

/* bits definitions for REG_AP_AHB_UFS_CLK_EN_FORCE_ON_OFF, [0x2040001C] */
#define BIT_AP_AHB_UFS_HCLK_FRC_ON                          ( BIT(15) )
#define BIT_AP_AHB_UFS_TX_FRC_ON                            ( BIT(14) )
#define BIT_AP_AHB_UFS_RX_FRC_ON                            ( BIT(13) )
#define BIT_AP_AHB_UFS_RX_1_FRC_ON                          ( BIT(12) )
#define BIT_AP_AHB_UFS_CFG_FRC_ON                           ( BIT(11) )
#define BIT_AP_AHB_UFS_PCLK_FRC_ON                          ( BIT(10) )
#define BIT_AP_AHB_UFS_REF_FRC_ON                           ( BIT(9) )
#define BIT_AP_AHB_UFS_XTAL_FRC_ON                          ( BIT(8) )
#define BIT_AP_AHB_UFS_HCLK_FRC_OFF                         ( BIT(7) )
#define BIT_AP_AHB_UFS_TX_FRC_OFF                           ( BIT(6) )
#define BIT_AP_AHB_UFS_RX_FRC_OFF                           ( BIT(5) )
#define BIT_AP_AHB_UFS_RX_1_FRC_OFF                         ( BIT(4) )
#define BIT_AP_AHB_UFS_CFG_FRC_OFF                          ( BIT(3) )
#define BIT_AP_AHB_UFS_PCLK_FRC_OFF                         ( BIT(2) )
#define BIT_AP_AHB_UFS_REF_FRC_OFF                          ( BIT(1) )
#define BIT_AP_AHB_UFS_XTAL_FRC_OFF                         ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0, [0x20400020] */
#define BIT_AP_AHB_VSP_FRC_OFF                              ( BIT(28) )
#define BIT_AP_AHB_SIM0_32K_FRC_OFF                         ( BIT(27) )
#define BIT_AP_AHB_I2C6_FRC_OFF                             ( BIT(24) )
#define BIT_AP_AHB_I2C5_FRC_OFF                             ( BIT(23) )
#define BIT_AP_AHB_CE_FRC_OFF                               ( BIT(22) )
#define BIT_AP_AHB_IIS2_FRC_OFF                             ( BIT(21) )
#define BIT_AP_AHB_IIS1_FRC_OFF                             ( BIT(20) )
#define BIT_AP_AHB_IIS0_FRC_OFF                             ( BIT(19) )
#define BIT_AP_AHB_SPI3_FRC_OFF                             ( BIT(18) )
#define BIT_AP_AHB_SPI2_FRC_OFF                             ( BIT(17) )
#define BIT_AP_AHB_SPI1_FRC_OFF                             ( BIT(16) )
#define BIT_AP_AHB_SPI0_FRC_OFF                             ( BIT(15) )
#define BIT_AP_AHB_I2C4_FRC_OFF                             ( BIT(14) )
#define BIT_AP_AHB_I2C3_FRC_OFF                             ( BIT(13) )
#define BIT_AP_AHB_I2C2_FRC_OFF                             ( BIT(12) )
#define BIT_AP_AHB_I2C1_FRC_OFF                             ( BIT(11) )
#define BIT_AP_AHB_I2C0_FRC_OFF                             ( BIT(10) )
#define BIT_AP_AHB_UART2_FRC_OFF                            ( BIT(9) )
#define BIT_AP_AHB_UART1_FRC_OFF                            ( BIT(8) )
#define BIT_AP_AHB_UART0_FRC_OFF                            ( BIT(7) )
#define BIT_AP_AHB_AP_APB_FRC_OFF                           ( BIT(6) )
#define BIT_AP_AHB_EMMC_1X_FRC_OFF                          ( BIT(5) )
#define BIT_AP_AHB_EMMC_2X_FRC_OFF                          ( BIT(4) )
#define BIT_AP_AHB_SDIO1_1X_FRC_OFF                         ( BIT(3) )
#define BIT_AP_AHB_SDIO1_2X_FRC_OFF                         ( BIT(2) )
#define BIT_AP_AHB_SDIO0_1X_FRC_OFF                         ( BIT(1) )
#define BIT_AP_AHB_SDIO0_2X_FRC_OFF                         ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1, [0x20400024] */
#define BIT_AP_AHB_SIM_FRC_OFF                              ( BIT(5) )
#define BIT_AP_AHB_DSI_APB_FRC_OFF                          ( BIT(4) )
#define BIT_AP_AHB_DPHY_CFG_FRC_OFF                         ( BIT(3) )
#define BIT_AP_AHB_DPHY_REF_FRC_OFF                         ( BIT(2) )
#define BIT_AP_AHB_DISP_DPI_FRC_OFF                         ( BIT(1) )
#define BIT_AP_AHB_DISP_FRC_OFF                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0, [0x20400028] */
#define BIT_AP_AHB_VSP_FRC_ON                               ( BIT(28) )
#define BIT_AP_AHB_SIM0_32K_FRC_ON                          ( BIT(27) )
#define BIT_AP_AHB_I2C6_FRC_ON                              ( BIT(24) )
#define BIT_AP_AHB_I2C5_FRC_ON                              ( BIT(23) )
#define BIT_AP_AHB_CE_FRC_ON                                ( BIT(22) )
#define BIT_AP_AHB_IIS2_FRC_ON                              ( BIT(21) )
#define BIT_AP_AHB_IIS1_FRC_ON                              ( BIT(20) )
#define BIT_AP_AHB_IIS0_FRC_ON                              ( BIT(19) )
#define BIT_AP_AHB_SPI3_FRC_ON                              ( BIT(18) )
#define BIT_AP_AHB_SPI2_FRC_ON                              ( BIT(17) )
#define BIT_AP_AHB_SPI1_FRC_ON                              ( BIT(16) )
#define BIT_AP_AHB_SPI0_FRC_ON                              ( BIT(15) )
#define BIT_AP_AHB_I2C4_FRC_ON                              ( BIT(14) )
#define BIT_AP_AHB_I2C3_FRC_ON                              ( BIT(13) )
#define BIT_AP_AHB_I2C2_FRC_ON                              ( BIT(12) )
#define BIT_AP_AHB_I2C1_FRC_ON                              ( BIT(11) )
#define BIT_AP_AHB_I2C0_FRC_ON                              ( BIT(10) )
#define BIT_AP_AHB_UART2_FRC_ON                             ( BIT(9) )
#define BIT_AP_AHB_UART1_FRC_ON                             ( BIT(8) )
#define BIT_AP_AHB_UART0_FRC_ON                             ( BIT(7) )
#define BIT_AP_AHB_AP_APB_FRC_ON                            ( BIT(6) )
#define BIT_AP_AHB_EMMC_1X_FRC_ON                           ( BIT(5) )
#define BIT_AP_AHB_EMMC_2X_FRC_ON                           ( BIT(4) )
#define BIT_AP_AHB_SDIO1_1X_FRC_ON                          ( BIT(3) )
#define BIT_AP_AHB_SDIO1_2X_FRC_ON                          ( BIT(2) )
#define BIT_AP_AHB_SDIO0_1X_FRC_ON                          ( BIT(1) )
#define BIT_AP_AHB_SDIO0_2X_FRC_ON                          ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1, [0x2040002C] */
#define BIT_AP_AHB_SIM_FRC_ON                               ( BIT(5) )
#define BIT_AP_AHB_DSI_APB_FRC_ON                           ( BIT(4) )
#define BIT_AP_AHB_DPHY_CFG_FRC_ON                          ( BIT(3) )
#define BIT_AP_AHB_DPHY_REF_FRC_ON                          ( BIT(2) )
#define BIT_AP_AHB_DISP_DPI_FRC_ON                          ( BIT(1) )
#define BIT_AP_AHB_DISP_FRC_ON                              ( BIT(0) )

/* bits definitions for REG_AP_AHB_MISC_CKG_EN, [0x20400040] */
#define BIT_AP_AHB_DPHY_REF_CKG_EN                          ( BIT(1) )
#define BIT_AP_AHB_DPHY_CFG_CKG_EN                          ( BIT(0) )

/* bits definitions for REG_AP_AHB_DISP_ASYNC_BRG, [0x20400050] */
#define BIT_AP_AHB_DISP_ASYNC_BRG_PU_NUM(x)                 ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AP_AHB_DISP_CSYSACK_SYNC_SEL                    ( BIT(18) )
#define BIT_AP_AHB_DISP_CACTIVE_SYNC_SEL                    ( BIT(17) )
#define BIT_AP_AHB_DISP_ASYNC_BRG_LP_NUM(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_DISP_ASYNC_BRG_LP_EB                     ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_ASYNC_BRG, [0x2040005C] */
#define BIT_AP_AHB_AP_ASYNC_BRG_PU_NUM(x)                   ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AP_AHB_M0_LPC, [0x20400060] */
#define BIT_AP_AHB_MAIN_M0_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M0_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M0_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M1_LPC, [0x20400064] */
#define BIT_AP_AHB_MAIN_M1_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M1_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M1_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M2_LPC, [0x20400068] */
#define BIT_AP_AHB_MAIN_M2_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M2_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M2_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M3_LPC, [0x2040006C] */
#define BIT_AP_AHB_MAIN_M3_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M3_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M3_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M4_LPC, [0x20400070] */
#define BIT_AP_AHB_MAIN_M4_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M4_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M4_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M5_LPC, [0x20400074] */
#define BIT_AP_AHB_MAIN_M5_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M5_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M5_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M6_LPC, [0x20400078] */
#define BIT_AP_AHB_MAIN_M6_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M6_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M6_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M7_LPC, [0x2040007C] */
#define BIT_AP_AHB_MAIN_M7_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M7_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M7_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MAIN_LPC, [0x20400088] */
#define BIT_AP_AHB_MAIN_PU_NUM(x)                           ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MATRIX_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_LP_EB                               ( BIT(16) )
#define BIT_AP_AHB_MAIN_LP_NUM(x)                           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S0_LPC, [0x2040008C] */
#define BIT_AP_AHB_MAIN_S0_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S0_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S0_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S0_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S1_LPC, [0x20400090] */
#define BIT_AP_AHB_MAIN_S1_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S1_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S1_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S1_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S2_LPC, [0x20400094] */
#define BIT_AP_AHB_MAIN_S2_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S2_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S2_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S2_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S3_LPC, [0x20400098] */
#define BIT_AP_AHB_MAIN_S3_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S3_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S3_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S3_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S4_LPC, [0x2040009C] */
#define BIT_AP_AHB_MAIN_S4_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S4_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S4_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S4_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S5_LPC, [0x20400058] */
#define BIT_AP_AHB_MAIN_S5_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S5_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S5_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S5_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S6_LPC, [0x20400054] */
#define BIT_AP_AHB_MAIN_S6_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S6_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S6_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S6_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_M0_LPC, [0x204000A0] */
#define BIT_AP_AHB_MERGE_M0_PU_NUM(x)                       ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_M0_LP_EB                           ( BIT(16) )
#define BIT_AP_AHB_MERGE_M0_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_M1_LPC, [0x204000A4] */
#define BIT_AP_AHB_MERGE_M1_PU_NUM(x)                       ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_M1_LP_EB                           ( BIT(16) )
#define BIT_AP_AHB_MERGE_M1_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_S0_LPC, [0x204000AC] */
#define BIT_AP_AHB_MERGE_S0_PU_NUM(x)                       ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MERGE_S0_AUTO_GATE_EN                ( BIT(17) )
#define BIT_AP_AHB_MERGE_S0_LP_EB                           ( BIT(16) )
#define BIT_AP_AHB_MERGE_S0_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_QOS0, [0x204000B0] */
#define BIT_AP_AHB_ARQOS_CE(x)                              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_CE(x)                              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_DMA(x)                             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_DMA(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_UFS(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_UFS(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS1, [0x204000B8] */
#define BIT_AP_AHB_ARQOS_SDIO0(x)                           ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWQOS_SDIO0(x)                           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARQOS_SDIO1(x)                           ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_SDIO1(x)                           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_SDIO2(x)                           ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_SDIO2(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_EMMC(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_EMMC(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS2, [0x204000BC] */
#define BIT_AP_AHB_ARQOS_THRESHOLD_MAIN(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_THRESHOLD_MAIN(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_THRESHOLD_MERGE(x)                 ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_THRESHOLD_MERGE(x)                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_THRESHOLD_DISP(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_THRESHOLD_DISP(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW, [0x204000C0] */
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_AP                 ( BIT(5) )
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_DISP               ( BIT(4) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_AP                     ( BIT(2) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_DISP                   ( BIT(1) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP, [0x204000C8] */
#define BIT_AP_AHB_DISP_BRIDGE_DEBUG_SIGNAL_W(x)            ( (x) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP, [0x204000CC] */
#define BIT_AP_AHB_AP_BRIDGE_DEBUG_SIGNAL_W(x)              ( (x) )

/* bits definitions for REG_AP_AHB_SYS_RST, [0x20403010] */
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_GSP                     ( BIT(2) )
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_DISP                    ( BIT(1) )
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_VSP                     ( BIT(0) )

/* bits definitions for REG_AP_AHB_CACHE_EMMC_SDIO, [0x20403014] */
#define BIT_AP_AHB_ARCACHE_SDIO2(x)                         ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWCACHE_SDIO2(x)                         ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARCACHE_SDIO1(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWCACHE_SDIO1(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARCACHE_SDIO0(x)                         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWCACHE_SDIO0(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARCACHE_EMMC(x)                          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWCACHE_EMMC(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_CACHE_UFS, [0x20403018] */
#define BIT_AP_AHB_ARCACHE_UFS(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWCACHE_UFS(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS_CFG, [0x2040301C] */
#define BIT_AP_AHB_DISP_FRAME_LINE_SEL_FOR_DDR_DFS          ( BIT(9) )
#define BIT_AP_AHB_DISP_FRAME_LINE_SEL_FOR_DVFS             ( BIT(8) )

/* bits definitions for REG_AP_AHB_DSI_PHY, [0x20403034] */
#define BIT_AP_AHB_MIPI_DSI_RESERVED(x)                     ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MIPI_DSI_TX_RCTL(x)                      ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_AHB_MIPI_DSI_TRIMBG(x)                       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_AHB_MIPI_DSI_IF_SEL                          ( BIT(0) )

/* bits definitions for REG_AP_AHB_CHIP_ID, [0x204030FC] */
#define BIT_AP_AHB_CHIP_ID(x)                               ( (x) )

/* bits definitions for REG_AP_AHB_UFS_LP_CTRL_0, [0x20403100] */
#define BIT_AP_AHB_UFS_POWER_ON_WAIT_CNT(x)                 ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_AHB_UFS_POWER_DOWN_WAIT_CNT(x)               ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_UFS_LP_CTRL_1, [0x20403104] */
#define BIT_AP_AHB_UFS_EXTERNAL_EVENT                       ( BIT(31) )
#define BIT_AP_AHB_UFS_CG_LP_PWR_READY_BYPASS               ( BIT(30) )
#define BIT_AP_AHB_UFS_FORCE_LP_PWR_READY                   ( BIT(29) )
#define BIT_AP_AHB_UFS_SEL_LP_PWR_READY                     ( BIT(28) )
#define BIT_AP_AHB_UFS_FORCE_LP_ISOL_EN                     ( BIT(27) )
#define BIT_AP_AHB_UFS_SEL_LP_ISOL_EN                       ( BIT(26) )
#define BIT_AP_AHB_UFS_FORCE_LP_RESET_N                     ( BIT(25) )
#define BIT_AP_AHB_UFS_SEL_LP_RESET_N                       ( BIT(24) )
#define BIT_AP_AHB_UFS_ISO_WAIT_CNT(x)                      ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_UFS_PWR_READY_WAIT_CNT(x)                ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_UFS_TRESET_WAIT_CNT(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_UFS_CONTROLLER, [0x20403108] */
#define BIT_AP_AHB_MPX_TX_ADAPTACTIVE(x)                    ( (x) << 25 & (BIT(25)|BIT(26)) )
#define BIT_AP_AHB_MPX_TX_ADAPTREQ(x)                       ( (x) << 23 & (BIT(23)|BIT(24)) )
#define BIT_AP_AHB_TX_PHYDIRDYIN(x)                         ( (x) << 21 & (BIT(21)|BIT(22)) )
#define BIT_AP_AHB_RX_LCCRDDET(x)                           ( (x) << 19 & (BIT(19)|BIT(20)) )
#define BIT_AP_AHB_MP_EXTACC                                ( BIT(18) )
#define BIT_AP_AHB_TX_EXTACC                                ( BIT(17) )
#define BIT_AP_AHB_TX_CFGBUSY(x)                            ( (x) << 15 & (BIT(15)|BIT(16)) )
#define BIT_AP_AHB_RX_EXTACC                                ( BIT(14) )
#define BIT_AP_AHB_RX_CFGBUSY(x)                            ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AP_AHB_TX_PLL_ON                                ( BIT(11) )
#define BIT_AP_AHB_TX_PWRENBL(x)                            ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_AP_AHB_RX_PWRENBL(x)                            ( (x) << 7  & (BIT(7)|BIT(8)) )
#define BIT_AP_AHB_TX_MK2EXTENSIONPHASE                     ( BIT(6) )
#define BIT_AP_AHB_RX_MK2EXTENSIONPHASE                     ( BIT(5) )
#define BIT_AP_AHB_TX_MK2EXTENSIONEN                        ( BIT(4) )
#define BIT_AP_AHB_RX_MK2DEEPEXIT                           ( BIT(3) )
#define BIT_AP_AHB_LP_RESET_COMPLETE                        ( BIT(2) )
#define BIT_AP_AHB_UFS_IDLE_IND                             ( BIT(1) )
#define BIT_AP_AHB_IES_EN_MASK                              ( BIT(0) )

/* bits definitions for REG_AP_AHB_MPHY_TX_TEST_OBSERVE, [0x2040310C] */
#define BIT_AP_AHB_TX_TST_RTOBSERVE_1(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_TX_TST_RTCONTROL_1(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_TX_TST_RTOBSERVE_0(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_TX_TST_RTCONTROL_0(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AP_AHB_MPHY_RX_TEST_OBSERVE, [0x20403110] */
#define BIT_AP_AHB_RX_TST_RTOBSERVE_1(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_RX_TST_RTCONTROL_1(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_RX_TST_RTOBSERVE_0(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_RX_TST_RTCONTROL_0(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AP_AHB_MPHY_CB_TEST_OBSERVE, [0x20403114] */
#define BIT_AP_AHB_CB_TST_RTOBSERVE(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_CB_TST_RTCONTROL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AP_AHB_MPHY_RESERVE_IO, [0x20403118] */
#define BIT_AP_AHB_MPHY_RESERVEDO(x)                        ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_AHB_MPHY_RESERVEDI(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MPHY_CB_CHANNEL_0, [0x2040311C] */
#define BIT_AP_AHB_CB_CFGUPDT                               ( BIT(31) )
#define BIT_AP_AHB_CB_INLNCFG                               ( BIT(30) )
#define BIT_AP_AHB_CB_CFGENBL                               ( BIT(29) )
#define BIT_AP_AHB_CB_ATTRWRN                               ( BIT(28) )
#define BIT_AP_AHB_CB_ATTRWRVAL(x)                          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_CB_ATTRRDVAL(x)                          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_CB_ATTRID(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_CB_ATTRRESET                             ( BIT(3) )
#define BIT_AP_AHB_CB_RESET                                 ( BIT(2) )
#define BIT_AP_AHB_CB_CFGCLK                                ( BIT(1) )
#define BIT_AP_AHB_REFCLKON                                 ( BIT(0) )

/* bits definitions for REG_AP_AHB_MPHY_CB_CHANNEL_1, [0x20403120] */
#define BIT_AP_AHB_CB_CFGCLK_DIV                            ( BIT(9) )
#define BIT_AP_AHB_CB_CFGCLK_FREQ(x)                        ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_AHB_CB_CFGRDYN                               ( BIT(0) )

/* bits definitions for REG_AP_AHB_UFS_CLK_CTRL, [0x20403124] */
#define BIT_AP_AHB_CG_CFGCLK_SW                             ( BIT(6) )
#define BIT_AP_AHB_TX_SYMBOLCLKREQ_SW                       ( BIT(5) )
#define BIT_AP_AHB_HCK_SW                                   ( BIT(4) )
#define BIT_AP_AHB_CG_SYSCLK_SW                             ( BIT(3) )
#define BIT_AP_AHB_CG_CLK_TREQ_SW                           ( BIT(2) )
#define BIT_AP_AHB_CG_LP_CLK_TREQ_SW                        ( BIT(1) )
#define BIT_AP_AHB_CG_PCLKREQ_SW                            ( BIT(0) )

/* bits definitions for REG_AP_AHB_MTX_BUS_EN, [0x20403128] */
#define BIT_AP_AHB_BUSMON_ENABLE_VSP                        ( BIT(1) )
#define BIT_AP_AHB_BUSMON_ENABLE_AP                         ( BIT(0) )

/* bits definitions for REG_AP_AHB_UFS_CONTROLLER_STATUS, [0x2040312C] */
#define BIT_AP_AHB_LP_SM_STATE(x)                           ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AH8_FSM_STATE(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_LP_RESET_N                               ( BIT(7) )
#define BIT_AP_AHB_LP_ISO_EN                                ( BIT(6) )
#define BIT_AP_AHB_LP_PWR_READY                             ( BIT(5) )
#define BIT_AP_AHB_LP_PWR_GATE                              ( BIT(4) )
#define BIT_AP_AHB_CG_SYSCLKREQ                             ( BIT(3) )
#define BIT_AP_AHB_CG_CLK_TREQ                              ( BIT(2) )
#define BIT_AP_AHB_CG_LP_CLK_TREQ                           ( BIT(1) )
#define BIT_AP_AHB_CG_PCLKREQ                               ( BIT(0) )

/* vars definitions for controller CTL_AP_AHB */


#endif /* __AP_AHB_H____ */
