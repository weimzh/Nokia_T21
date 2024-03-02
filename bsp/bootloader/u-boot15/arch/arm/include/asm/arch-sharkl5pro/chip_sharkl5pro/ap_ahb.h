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
#define CTL_AP_AHB_BASE                 SCI_IOMAP(0x20100000)
#endif

/* registers definitions for CTL_AP_AHB, 0x20100000 */
#define REG_AP_AHB_AHB_EB                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0000)
#define REG_AP_AHB_AHB_RST                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0004)
#define REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG                   SCI_ADDR(CTL_AP_AHB_BASE, 0x000C)
#define REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG                    SCI_ADDR(CTL_AP_AHB_BASE, 0x0010)
#define REG_AP_AHB_HOLDING_PEN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0014)
#define REG_AP_AHB_CLOCK_FREQUENCY_DOWN                     SCI_ADDR(CTL_AP_AHB_BASE, 0x0018)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0020)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0024)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0028)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1                   SCI_ADDR(CTL_AP_AHB_BASE, 0x002C)
#define REG_AP_AHB_MISC_CKG_EN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0040)
#define REG_AP_AHB_VDSP_ASYNC_BRG                           SCI_ADDR(CTL_AP_AHB_BASE, 0x004C)
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
#define REG_AP_AHB_S7_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x00A8)
#define REG_AP_AHB_MERGE_M0_LPC                             SCI_ADDR(CTL_AP_AHB_BASE, 0x00A0)
#define REG_AP_AHB_MERGE_M1_LPC                             SCI_ADDR(CTL_AP_AHB_BASE, 0x00A4)
#define REG_AP_AHB_MERGE_S0_LPC                             SCI_ADDR(CTL_AP_AHB_BASE, 0x00AC)
#define REG_AP_AHB_AP_QOS0                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00B0)
#define REG_AP_AHB_AP_QOS1                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00B8)
#define REG_AP_AHB_AP_QOS2                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00BC)
#define REG_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW               SCI_ADDR(CTL_AP_AHB_BASE, 0x00C0)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP         SCI_ADDR(CTL_AP_AHB_BASE, 0x00C8)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP           SCI_ADDR(CTL_AP_AHB_BASE, 0x00CC)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VDSP         SCI_ADDR(CTL_AP_AHB_BASE, 0x00D0)
#define REG_AP_AHB_AP_QOS3                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x00D4)
#define REG_AP_AHB_AP_QOS3_SEL                              SCI_ADDR(CTL_AP_AHB_BASE, 0x00D8)
#define REG_AP_AHB_MERGE_VDSP_M0_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0100)
#define REG_AP_AHB_MERGE_VDSP_M1_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0104)
#define REG_AP_AHB_MERGE_VDSP_M2_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0108)
#define REG_AP_AHB_MERGE_VDSP_M3_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x010C)
#define REG_AP_AHB_MERGE_VDSP_MAIN_LPC                      SCI_ADDR(CTL_AP_AHB_BASE, 0x0110)
#define REG_AP_AHB_MERGE_VDSP_S0_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0114)
#define REG_AP_AHB_MERGE_VDSP_S1_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0118)
#define REG_AP_AHB_MERGE_VDMA_M0_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x011C)
#define REG_AP_AHB_MERGE_VDMA_M1_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0120)
#define REG_AP_AHB_MERGE_VDMA_S0_LPC                        SCI_ADDR(CTL_AP_AHB_BASE, 0x0124)
#define REG_AP_AHB_SYS_RST                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x3010)
#define REG_AP_AHB_CACHE_EMMC_SDIO                          SCI_ADDR(CTL_AP_AHB_BASE, 0x3014)
#define REG_AP_AHB_AP_QOS_CFG                               SCI_ADDR(CTL_AP_AHB_BASE, 0x301C)
#define REG_AP_AHB_DSI_PHY                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x3034)
#define REG_AP_AHB_VDSP_FUNC_CTRL                           SCI_ADDR(CTL_AP_AHB_BASE, 0x3084)
#define REG_AP_AHB_VDSP_FATAL_INFO_LOW                      SCI_ADDR(CTL_AP_AHB_BASE, 0x3088)
#define REG_AP_AHB_VDSP_FATAL_INFO_HIGH                     SCI_ADDR(CTL_AP_AHB_BASE, 0x308C)
#define REG_AP_AHB_VDSP_LP_CTRL                             SCI_ADDR(CTL_AP_AHB_BASE, 0x3090)
#define REG_AP_AHB_VDSP_INT_CTRL                            SCI_ADDR(CTL_AP_AHB_BASE, 0x3094)
#define REG_AP_AHB_CHIP_ID                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x30FC)

/* bits definitions for REG_AP_AHB_AHB_EB, [0x20100000] */
#define BIT_AP_AHB_BUSMON_CLOCK_EB                          ( BIT(8) )
#define BIT_AP_AHB_CKG_EB                                   ( BIT(7) )
#define BIT_AP_AHB_IPI_EB                                   ( BIT(6) )
#define BIT_AP_AHB_DMA_EB                                   ( BIT(5) )
#define BIT_AP_AHB_DMA_ENABLE                               ( BIT(4) )
#define BIT_AP_AHB_VDMA_EB                                  ( BIT(3) )
#define BIT_AP_AHB_VSP_EB                                   ( BIT(2) )
#define BIT_AP_AHB_DISPC_EB                                 ( BIT(1) )
#define BIT_AP_AHB_DSI_EB                                   ( BIT(0) )

/* bits definitions for REG_AP_AHB_AHB_RST, [0x20100004] */
#define BIT_AP_AHB_DISPC_VAU_SOFT_RST                       ( BIT(14) )
#define BIT_AP_AHB_VSP_SOFT_RST                             ( BIT(13) )
#define BIT_AP_AHB_VPP_SOFT_RST                             ( BIT(12) )
#define BIT_AP_AHB_VSP_GLOBAL_SOFT_RST                      ( BIT(11) )
#define BIT_AP_AHB_VDSP_DEBUG_SOFT_RST                      ( BIT(10) )
#define BIT_AP_AHB_VDSP_SOFT_RST                            ( BIT(9) )
#define BIT_AP_AHB_DMA_SOFT_RST                             ( BIT(8) )
#define BIT_AP_AHB_VDMA_SOFT_RST                            ( BIT(7) )
#define BIT_AP_AHB_IPI_SOFT_RST                             ( BIT(6) )
#define BIT_AP_AHB_VDMA_VAU_SOFT_RST                        ( BIT(5) )
#define BIT_AP_AHB_VDSP_MSTI_VAU_SOFT_RST                   ( BIT(4) )
#define BIT_AP_AHB_VDSP_MSTD_VAU_SOFT_RST                   ( BIT(3) )
#define BIT_AP_AHB_VDSP_IDMA_VAU_SOFT_RST                   ( BIT(2) )
#define BIT_AP_AHB_DISPC_SOFT_RST                           ( BIT(1) )
#define BIT_AP_AHB_DSI_SOFT_RST                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG, [0x2010000C] */
#define BIT_AP_AHB_AXI_LP_CTRL_DISABLE                      ( BIT(3) )
#define BIT_AP_AHB_PERI_FORCE_ON                            ( BIT(2) )
#define BIT_AP_AHB_PERI_FORCE_OFF                           ( BIT(1) )
#define BIT_AP_AHB_CGM_CLK_AP_AXI_AUTO_GATE_EN              ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG, [0x20100010] */
#define BIT_AP_AHB_AP_MAINMTX_LP_DISABLE                    ( BIT(6) )
#define BIT_AP_AHB_AP_AHB_AUTO_GATE_EN                      ( BIT(5) )
#define BIT_AP_AHB_AP_EMC_AUTO_GATE_EN                      ( BIT(4) )

/* bits definitions for REG_AP_AHB_HOLDING_PEN, [0x20100014] */
#define BIT_AP_AHB_HOLDING_PEN(x)                           ( (x) )

/* bits definitions for REG_AP_AHB_CLOCK_FREQUENCY_DOWN, [0x20100018] */
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_SDIO2             ( BIT(9) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_SDIO1             ( BIT(8) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_SDIO0             ( BIT(7) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_EMMC              ( BIT(6) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_APCPU             ( BIT(5) )
#define BIT_AP_AHB_AP_AXI_BUS_IDLE_BYPASS_DMA               ( BIT(4) )
#define BIT_AP_AHB_AP_APB_AUTO_CONTROL_SEL                  ( BIT(3) )
#define BIT_AP_AHB_AP_APB_AUTO_MUX_SEL(x)                   ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_AP_AHB_AP_APB_AUTO_MUX_EN                       ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0, [0x20100020] */
#define BIT_AP_AHB_VDSP_M_FRC_OFF                           ( BIT(30) )
#define BIT_AP_AHB_VDSP_FRC_OFF                             ( BIT(29) )
#define BIT_AP_AHB_VSP_FRC_OFF                              ( BIT(28) )
#define BIT_AP_AHB_SIM0_32K_FRC_OFF                         ( BIT(27) )
#define BIT_AP_AHB_SDIO2_32K_FRC_OFF                        ( BIT(26) )
#define BIT_AP_AHB_SDIO1_32K_FRC_OFF                        ( BIT(25) )
#define BIT_AP_AHB_SDIO0_32K_FRC_OFF                        ( BIT(24) )
#define BIT_AP_AHB_EMMC_32K_FRC_OFF                         ( BIT(23) )
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

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1, [0x20100024] */
#define BIT_AP_AHB_IPI_FRC_OFF                              ( BIT(6) )
#define BIT_AP_AHB_SIM_FRC_OFF                              ( BIT(5) )
#define BIT_AP_AHB_DSI_APB_FRC_OFF                          ( BIT(4) )
#define BIT_AP_AHB_DPHY_CFG_FRC_OFF                         ( BIT(3) )
#define BIT_AP_AHB_DPHY_REF_FRC_OFF                         ( BIT(2) )
#define BIT_AP_AHB_DISP_DPI_FRC_OFF                         ( BIT(1) )
#define BIT_AP_AHB_DISP_FRC_OFF                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0, [0x20100028] */
#define BIT_AP_AHB_VDSP_M_FRC_ON                            ( BIT(30) )
#define BIT_AP_AHB_VDSP_FRC_ON                              ( BIT(29) )
#define BIT_AP_AHB_VSP_FRC_ON                               ( BIT(28) )
#define BIT_AP_AHB_SIM0_32K_FRC_ON                          ( BIT(27) )
#define BIT_AP_AHB_SDIO2_32K_FRC_ON                         ( BIT(26) )
#define BIT_AP_AHB_SDIO1_32K_FRC_ON                         ( BIT(25) )
#define BIT_AP_AHB_SDIO0_32K_FRC_ON                         ( BIT(24) )
#define BIT_AP_AHB_EMMC_32K_FRC_ON                          ( BIT(23) )
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

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1, [0x2010002C] */
#define BIT_AP_AHB_IPI_FRC_ON                               ( BIT(6) )
#define BIT_AP_AHB_SIM_FRC_ON                               ( BIT(5) )
#define BIT_AP_AHB_DSI_APB_FRC_ON                           ( BIT(4) )
#define BIT_AP_AHB_DPHY_CFG_FRC_ON                          ( BIT(3) )
#define BIT_AP_AHB_DPHY_REF_FRC_ON                          ( BIT(2) )
#define BIT_AP_AHB_DISP_DPI_FRC_ON                          ( BIT(1) )
#define BIT_AP_AHB_DISP_FRC_ON                              ( BIT(0) )

/* bits definitions for REG_AP_AHB_MISC_CKG_EN, [0x20100040] */
#define BIT_AP_AHB_DPHY_REF_CKG_EN                          ( BIT(1) )
#define BIT_AP_AHB_DPHY_CFG_CKG_EN                          ( BIT(0) )

/* bits definitions for REG_AP_AHB_VDSP_ASYNC_BRG, [0x2010004C] */
#define BIT_AP_AHB_VDSP_ASYNC_BRG_PU_NUM(x)                 ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_VDSP_ASYNC_BRG_LP_NUM(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_VDSP_ASYNC_BRG_LP_EB                     ( BIT(0) )

/* bits definitions for REG_AP_AHB_DISP_ASYNC_BRG, [0x20100050] */
#define BIT_AP_AHB_DISP_ASYNC_BRG_PU_NUM(x)                 ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AP_AHB_DISP_CSYSACK_SYNC_SEL                    ( BIT(18) )
#define BIT_AP_AHB_DISP_CACTIVE_SYNC_SEL                    ( BIT(17) )
#define BIT_AP_AHB_DISP_ASYNC_BRG_LP_NUM(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_DISP_ASYNC_BRG_LP_EB                     ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_ASYNC_BRG, [0x2010005C] */
#define BIT_AP_AHB_AP_ASYNC_BRG_PU_NUM(x)                   ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_LP_NUM(x)                   ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_LP_EB                       ( BIT(0) )

/* bits definitions for REG_AP_AHB_M0_LPC, [0x20100060] */
#define BIT_AP_AHB_MAIN_M0_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M0_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M0_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M1_LPC, [0x20100064] */
#define BIT_AP_AHB_MAIN_M1_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M1_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M1_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M2_LPC, [0x20100068] */
#define BIT_AP_AHB_MAIN_M2_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M2_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M2_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M3_LPC, [0x2010006C] */
#define BIT_AP_AHB_MAIN_M3_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M3_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M3_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M4_LPC, [0x20100070] */
#define BIT_AP_AHB_MAIN_M4_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M4_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M4_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M5_LPC, [0x20100074] */
#define BIT_AP_AHB_MAIN_M5_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M5_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M5_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M6_LPC, [0x20100078] */
#define BIT_AP_AHB_MAIN_M6_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M6_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M6_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M7_LPC, [0x2010007C] */
#define BIT_AP_AHB_MAIN_M7_PU_NUM(x)                        ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MAIN_M7_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M7_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MAIN_LPC, [0x20100088] */
#define BIT_AP_AHB_MAIN_PU_NUM(x)                           ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MATRIX_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_LP_EB                               ( BIT(16) )
#define BIT_AP_AHB_MAIN_LP_NUM(x)                           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S0_LPC, [0x2010008C] */
#define BIT_AP_AHB_MAIN_S0_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S0_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S0_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S0_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S1_LPC, [0x20100090] */
#define BIT_AP_AHB_MAIN_S1_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S1_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S1_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S1_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S2_LPC, [0x20100094] */
#define BIT_AP_AHB_MAIN_S2_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S2_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S2_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S2_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S3_LPC, [0x20100098] */
#define BIT_AP_AHB_MAIN_S3_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S3_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S3_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S3_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S4_LPC, [0x2010009C] */
#define BIT_AP_AHB_MAIN_S4_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S4_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S4_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S4_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S5_LPC, [0x20100058] */
#define BIT_AP_AHB_MAIN_S5_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S5_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S5_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S5_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S6_LPC, [0x20100054] */
#define BIT_AP_AHB_MAIN_S6_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S6_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S6_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S6_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S7_LPC, [0x201000A8] */
#define BIT_AP_AHB_MAIN_S7_PU_NUM(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MTX_S7_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S7_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S7_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_M0_LPC, [0x201000A0] */
#define BIT_AP_AHB_MERGE_M0_PU_NUM(x)                       ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_M0_LP_EB                           ( BIT(16) )
#define BIT_AP_AHB_MERGE_M0_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_M1_LPC, [0x201000A4] */
#define BIT_AP_AHB_MERGE_M1_PU_NUM(x)                       ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_M1_LP_EB                           ( BIT(16) )
#define BIT_AP_AHB_MERGE_M1_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_S0_LPC, [0x201000AC] */
#define BIT_AP_AHB_MERGE_S0_PU_NUM(x)                       ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MERGE_S0_AUTO_GATE_EN                ( BIT(17) )
#define BIT_AP_AHB_MERGE_S0_LP_EB                           ( BIT(16) )
#define BIT_AP_AHB_MERGE_S0_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_QOS0, [0x201000B0] */
#define BIT_AP_AHB_ARQOS_CE(x)                              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_CE(x)                              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_DMA(x)                             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_DMA(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )

/* bits definitions for REG_AP_AHB_AP_QOS1, [0x201000B8] */
#define BIT_AP_AHB_ARQOS_SDIO0(x)                           ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWQOS_SDIO0(x)                           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARQOS_SDIO1(x)                           ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_SDIO1(x)                           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_SDIO2(x)                           ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_SDIO2(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_EMMC(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_EMMC(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS2, [0x201000BC] */
#define BIT_AP_AHB_ARQOS_THRESHHOLD_VDSP(x)                 ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWQOS_THRESHHOLD_VDSP(x)                 ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARQOS_THRESHHOLD_MAIN(x)                 ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_THRESHHOLD_MAIN(x)                 ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_THRESHHOLD_MERGE(x)                ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_THRESHHOLD_MERGE(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_THRESHHOLD_DISP(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_THRESHHOLD_DISP(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW, [0x201000C0] */
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_AP                 ( BIT(5) )
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_DISP               ( BIT(4) )
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_VDSP               ( BIT(3) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_AP                     ( BIT(2) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_DISP                   ( BIT(1) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_VDSP                   ( BIT(0) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP, [0x201000C8] */
#define BIT_AP_AHB_DISP_BRIDGE_DEBUG_SIGNAL_W(x)            ( (x) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP, [0x201000CC] */
#define BIT_AP_AHB_AP_BRIDGE_DEBUG_SIGNAL_W(x)              ( (x) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VDSP, [0x201000D0] */
#define BIT_AP_AHB_VDSP_BRIDGE_DEBUG_SIGNAL_W(x)            ( (x) )

/* bits definitions for REG_AP_AHB_AP_QOS3, [0x201000D4] */
#define BIT_AP_AHB_ARQOS_VDSP_MSTI(x)                       ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_ARQOS_VDSP_MSTD(x)                       ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_VDSP_MSTD(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_VDSP_IDMA(x)                       ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_VDSP_IDMA(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_VDMA(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_VDMA(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS3_SEL, [0x201000D8] */
#define BIT_AP_AHB_ARQOS_VDSP_MSTI_SEL                      ( BIT(6) )
#define BIT_AP_AHB_ARQOS_VDSP_MSTD_SEL                      ( BIT(5) )
#define BIT_AP_AHB_AWQOS_VDSP_MSTD_SEL                      ( BIT(4) )
#define BIT_AP_AHB_ARQOS_VDSP_IDMA_SEL                      ( BIT(3) )
#define BIT_AP_AHB_AWQOS_VDSP_IDMA_SEL                      ( BIT(2) )
#define BIT_AP_AHB_ARQOS_VDMA_SEL                           ( BIT(1) )
#define BIT_AP_AHB_AWQOS_VDMA_SEL                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_M0_LPC, [0x20100100] */
#define BIT_AP_AHB_MERGE_VDSP_M0_PU_NUM(x)                  ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_VDSP_M0_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_M0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_M1_LPC, [0x20100104] */
#define BIT_AP_AHB_MERGE_VDSP_M1_PU_NUM(x)                  ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_VDSP_M1_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_M1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_M2_LPC, [0x20100108] */
#define BIT_AP_AHB_MERGE_VDSP_M2_PU_NUM(x)                  ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_VDSP_M2_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_M2_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_M3_LPC, [0x2010010C] */
#define BIT_AP_AHB_MERGE_VDSP_M3_PU_NUM(x)                  ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_VDSP_M3_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_M3_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_MAIN_LPC, [0x20100110] */
#define BIT_AP_AHB_MERGE_VDSP_MAIN_PU_NUM(x)                ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MERGE_VDSP_MATRIX_AUTO_GATE_EN       ( BIT(17) )
#define BIT_AP_AHB_MERGE_VDSP_MAIN_LP_EB                    ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_MAIN_LP_NUM(x)                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_S0_LPC, [0x20100114] */
#define BIT_AP_AHB_MERGE_VDSP_S0_PU_NUM(x)                  ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MERGE_VDSP_S0_AUTO_GATE_EN           ( BIT(17) )
#define BIT_AP_AHB_MERGE_VDSP_S0_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_S0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDSP_S1_LPC, [0x20100118] */
#define BIT_AP_AHB_MERGE_VDSP_S1_PU_NUM(x)                  ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MERGE_VDSP_S1_AUTO_GATE_EN           ( BIT(17) )
#define BIT_AP_AHB_MERGE_VDSP_S1_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDSP_S1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDMA_M0_LPC, [0x2010011C] */
#define BIT_AP_AHB_MERGE_VDMA_M0_PU_NUM(x)                  ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_VDMA_M0_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDMA_M0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDMA_M1_LPC, [0x20100120] */
#define BIT_AP_AHB_MERGE_VDMA_M1_PU_NUM(x)                  ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MERGE_VDMA_M1_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDMA_M1_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MERGE_VDMA_S0_LPC, [0x20100124] */
#define BIT_AP_AHB_MERGE_VDMA_S0_PU_NUM(x)                  ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )
#define BIT_AP_AHB_CGM_MERGE_VDMA_S0_AUTO_GATE_EN           ( BIT(17) )
#define BIT_AP_AHB_MERGE_VDMA_S0_LP_EB                      ( BIT(16) )
#define BIT_AP_AHB_MERGE_VDMA_S0_LP_NUM(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_SYS_RST, [0x20103010] */
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_VDMA                    ( BIT(3) )
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_GSP                     ( BIT(2) )
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_DISP                    ( BIT(1) )
#define BIT_AP_AHB_SYS_SOFT_RST_REQ_VSP                     ( BIT(0) )

/* bits definitions for REG_AP_AHB_CACHE_EMMC_SDIO, [0x20103014] */
#define BIT_AP_AHB_ARCACHE_SDIO2(x)                         ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWCACHE_SDIO2(x)                         ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARCACHE_SDIO1(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWCACHE_SDIO1(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARCACHE_SDIO0(x)                         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWCACHE_SDIO0(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARCACHE_EMMC(x)                          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWCACHE_EMMC(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS_CFG, [0x2010301C] */
#define BIT_AP_AHB_DISP_FRAME_LINE_SEL_FOR_DDR_DFS          ( BIT(9) )
#define BIT_AP_AHB_DISP_FRAME_LINE_SEL_FOR_DVFS             ( BIT(8) )

/* bits definitions for REG_AP_AHB_DSI_PHY, [0x20103034] */
#define BIT_AP_AHB_MIPI_DSI_RESERVED(x)                     ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_AP_AHB_MIPI_DSI_TX_RCTL(x)                      ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_AHB_MIPI_DSI_TRIMBG(x)                       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_AHB_MIPI_DSI_IF_SEL                          ( BIT(0) )

/* bits definitions for REG_AP_AHB_VDSP_FUNC_CTRL, [0x20103084] */
#define BIT_AP_AHB_PRID(x)                                  ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_AHB_DBGEN                                    ( BIT(11) )
#define BIT_AP_AHB_NIDEN                                    ( BIT(10) )
#define BIT_AP_AHB_SPIDEN                                   ( BIT(9) )
#define BIT_AP_AHB_SPNIDEN                                  ( BIT(8) )
#define BIT_AP_AHB_VDSP_TRIGOUT_IDMA(x)                     ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AP_AHB_VDSP_TRIGIN_IDMA(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AP_AHB_STAT_VECTOR_SEL                          ( BIT(3) )
#define BIT_AP_AHB_RUN_STALL_ON_RESET                       ( BIT(2) )
#define BIT_AP_AHB_DCACHE_DRAM_FLUSH(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_AHB_VDSP_FATAL_INFO_LOW, [0x20103088] */
#define BIT_AP_AHB_VDSP_PFAULTINFO_LOW(x)                   ( (x) )

/* bits definitions for REG_AP_AHB_VDSP_FATAL_INFO_HIGH, [0x2010308C] */
#define BIT_AP_AHB_VDSP_PFAULTINFO_HIGH(x)                  ( (x) )

/* bits definitions for REG_AP_AHB_VDSP_LP_CTRL, [0x20103090] */
#define BIT_AP_AHB_VDSP_PWAITMODE                           ( BIT(5) )
#define BIT_AP_AHB_VDSP_M_AUTO_GATE_EN                      ( BIT(4) )
#define BIT_AP_AHB_VDSP_CLK_FRC_ON                          ( BIT(3) )
#define BIT_AP_AHB_VDSP_STOP_EN                             ( BIT(2) )
#define BIT_AP_AHB_VDSP_FRC_SLEEP                           ( BIT(1) )
#define BIT_AP_AHB_VDSP_AUTO_GATE_EN                        ( BIT(0) )

/* bits definitions for REG_AP_AHB_VDSP_INT_CTRL, [0x20103094] */
#define BIT_AP_AHB_INT_REQ_VDMA_MASK                        ( BIT(16) )
#define BIT_AP_AHB_INT_REQ_VDMA_VAU_MASK                    ( BIT(15) )
#define BIT_AP_AHB_INT_REQ_VDSP_VAU_MASK                    ( BIT(14) )
#define BIT_AP_AHB_VDSP_ALL_INT_MASK                        ( BIT(13) )
#define BIT_AP_AHB_INT_REQ_DCAM2_MASK                       ( BIT(12) )
#define BIT_AP_AHB_INT_REQ_DCAM1_MASK                       ( BIT(11) )
#define BIT_AP_AHB_INT_TO_VDSP_BYIPI_MASK_3                 ( BIT(10) )
#define BIT_AP_AHB_INT_TO_VDSP_BYIPI_MASK_2                 ( BIT(9) )
#define BIT_AP_AHB_INT_TO_VDSP_BYIPI_MASK_1                 ( BIT(8) )
#define BIT_AP_AHB_INT_REQ_GPIO_MASK                        ( BIT(7) )
#define BIT_AP_AHB_INT_REQ_DCAM0_MASK                       ( BIT(6) )
#define BIT_AP_AHB_INT_TO_VDSP_BYIPI_MASK_0                 ( BIT(5) )
#define BIT_AP_AHB_INT_REQ_I2C4_MASK                        ( BIT(4) )
#define BIT_AP_AHB_INT_REQ_I2C3_MASK                        ( BIT(3) )
#define BIT_AP_AHB_INT_REQ_I2C2_MASK                        ( BIT(2) )
#define BIT_AP_AHB_INT_REQ_I2C1_MASK                        ( BIT(1) )
#define BIT_AP_AHB_INT_REQ_I2C0_MASK                        ( BIT(0) )

/* bits definitions for REG_AP_AHB_CHIP_ID, [0x201030FC] */
#define BIT_AP_AHB_CHIP_ID(x)                               ( (x) )

/* vars definitions for controller CTL_AP_AHB */


#endif /* __AP_AHB_H____ */
