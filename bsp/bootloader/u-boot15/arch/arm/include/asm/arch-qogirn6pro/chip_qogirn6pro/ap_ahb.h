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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/ap/SharkL6Pro_AP_AHB_Control_Register.xls;AP_AHB_REG
 *     Revision : 231409
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
#define CTL_AP_AHB_BASE                 SCI_IOMAP(0x20000000)
#endif

/* registers definitions for CTL_AP_AHB, 0x20000000 */
#define REG_AP_AHB_AHB_EB                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0000)
#define REG_AP_AHB_AHB_RST                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0004)
#define REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG                   SCI_ADDR(CTL_AP_AHB_BASE, 0x000C)
#define REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG                    SCI_ADDR(CTL_AP_AHB_BASE, 0x0010)
#define REG_AP_AHB_HOLDING_PEN                              SCI_ADDR(CTL_AP_AHB_BASE, 0x0014)
#define REG_AP_AHB_CLOCK_FREQUENCY_DOWN                     SCI_ADDR(CTL_AP_AHB_BASE, 0x0018)
#define REG_AP_AHB_AHB_EB1                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x001C)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0020)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0024)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0                   SCI_ADDR(CTL_AP_AHB_BASE, 0x0028)
#define REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1                   SCI_ADDR(CTL_AP_AHB_BASE, 0x002C)
#define REG_AP_AHB_UFSHC_CLK_CTRL                           SCI_ADDR(CTL_AP_AHB_BASE, 0x0040)
#define REG_AP_AHB_AP_ASYNC_BRG_AON                         SCI_ADDR(CTL_AP_AHB_BASE, 0x0054)
#define REG_AP_AHB_AP_ASYNC_BRG_DDR                         SCI_ADDR(CTL_AP_AHB_BASE, 0x0058)
#define REG_AP_AHB_AP_ASYNC_BRG_APCPU                       SCI_ADDR(CTL_AP_AHB_BASE, 0x005C)
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
#define REG_AP_AHB_S5_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x00A0)
#define REG_AP_AHB_S6_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x00A4)
#define REG_AP_AHB_S7_LPC                                   SCI_ADDR(CTL_AP_AHB_BASE, 0x00A8)
#define REG_AP_AHB_AP_URGENCY                               SCI_ADDR(CTL_AP_AHB_BASE, 0x0130)
#define REG_AP_AHB_AP_QOS0                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0140)
#define REG_AP_AHB_AP_QOS1                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x0144)
#define REG_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW               SCI_ADDR(CTL_AP_AHB_BASE, 0x0150)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VDSP         SCI_ADDR(CTL_AP_AHB_BASE, 0x0154)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP         SCI_ADDR(CTL_AP_AHB_BASE, 0x0158)
#define REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP           SCI_ADDR(CTL_AP_AHB_BASE, 0x015C)
#define REG_AP_AHB_CACHE_EMMC_SDIO                          SCI_ADDR(CTL_AP_AHB_BASE, 0x3014)
#define REG_AP_AHB_CACHE_UFS                                SCI_ADDR(CTL_AP_AHB_BASE, 0x3018)
#define REG_AP_AHB_UFSHC_CTRL_STATUS                        SCI_ADDR(CTL_AP_AHB_BASE, 0x301C)
#define REG_AP_AHB_CHIP_ID                                  SCI_ADDR(CTL_AP_AHB_BASE, 0x30FC)

/* bits definitions for REG_AP_AHB_AHB_EB, [0x20000000] */
#define BIT_AP_AHB_I2C9_EB_SEC                              ( BIT(29) )
#define BIT_AP_AHB_I2C8_EB_SEC                              ( BIT(28) )
#define BIT_AP_AHB_I2C7_EB_SEC                              ( BIT(27) )
#define BIT_AP_AHB_I2C6_EB_SEC                              ( BIT(26) )
#define BIT_AP_AHB_I2C5_EB_SEC                              ( BIT(25) )
#define BIT_AP_AHB_I2C4_EB_SEC                              ( BIT(24) )
#define BIT_AP_AHB_I2C3_EB_SEC                              ( BIT(23) )
#define BIT_AP_AHB_I2C2_EB_SEC                              ( BIT(22) )
#define BIT_AP_AHB_I2C1_EB_SEC                              ( BIT(21) )
#define BIT_AP_AHB_I2C0_EB_SEC                              ( BIT(20) )
#define BIT_AP_AHB_I2C9_EB                                  ( BIT(19) )
#define BIT_AP_AHB_I2C8_EB                                  ( BIT(18) )
#define BIT_AP_AHB_I2C7_EB                                  ( BIT(17) )
#define BIT_AP_AHB_I2C6_EB                                  ( BIT(16) )
#define BIT_AP_AHB_I2C5_EB                                  ( BIT(15) )
#define BIT_AP_AHB_I2C4_EB                                  ( BIT(14) )
#define BIT_AP_AHB_I2C3_EB                                  ( BIT(13) )
#define BIT_AP_AHB_I2C2_EB                                  ( BIT(12) )
#define BIT_AP_AHB_I2C1_EB                                  ( BIT(11) )
#define BIT_AP_AHB_I2C0_EB                                  ( BIT(10) )
#define BIT_AP_AHB_AP2EMC_EB                                ( BIT(9) )
#define BIT_AP_AHB_BUSMON_CLOCK_EB                          ( BIT(8) )
#define BIT_AP_AHB_CKG_EB                                   ( BIT(7) )
#define BIT_AP_AHB_UFS_EB                                   ( BIT(6) )
#define BIT_AP_AHB_DMA_EB                                   ( BIT(5) )
#define BIT_AP_AHB_DMA_ENABLE                               ( BIT(4) )
#define BIT_AP_AHB_EMMC_EB                                  ( BIT(3) )
#define BIT_AP_AHB_SDIO2_EB                                 ( BIT(2) )
#define BIT_AP_AHB_SDIO1_EB                                 ( BIT(1) )
#define BIT_AP_AHB_SDIO0_EB                                 ( BIT(0) )

/* bits definitions for REG_AP_AHB_AHB_RST, [0x20000004] */
#define BIT_AP_AHB_I2C9_SOFT_RST                            ( BIT(25) )
#define BIT_AP_AHB_I2C8_SOFT_RST                            ( BIT(24) )
#define BIT_AP_AHB_I2C7_SOFT_RST                            ( BIT(23) )
#define BIT_AP_AHB_I2C6_SOFT_RST                            ( BIT(22) )
#define BIT_AP_AHB_I2C5_SOFT_RST                            ( BIT(21) )
#define BIT_AP_AHB_I2C4_SOFT_RST                            ( BIT(20) )
#define BIT_AP_AHB_I2C3_SOFT_RST                            ( BIT(19) )
#define BIT_AP_AHB_I2C2_SOFT_RST                            ( BIT(18) )
#define BIT_AP_AHB_I2C1_SOFT_RST                            ( BIT(17) )
#define BIT_AP_AHB_I2C0_SOFT_RST                            ( BIT(16) )
#define BIT_AP_AHB_DMA_SOFT_RST                             ( BIT(8) )
#define BIT_AP_AHB_UFS_SOFT_RST                             ( BIT(6) )
#define BIT_AP_AHB_EMMC_SOFT_RST                            ( BIT(3) )
#define BIT_AP_AHB_SDIO2_SOFT_RST                           ( BIT(2) )
#define BIT_AP_AHB_SDIO1_SOFT_RST                           ( BIT(1) )
#define BIT_AP_AHB_SDIO0_SOFT_RST                           ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG, [0x2000000C] */
#define BIT_AP_AHB_AXI_LP_CTRL_DISABLE                      ( BIT(3) )
#define BIT_AP_AHB_PERI_FORCE_ON                            ( BIT(2) )
#define BIT_AP_AHB_PERI_FORCE_OFF                           ( BIT(1) )
#define BIT_AP_AHB_CGM_CLK_AP_AXI_AUTO_GATE_EN              ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_AUTO_SLEEP_CFG, [0x20000010] */
#define BIT_AP_AHB_CACTIVE_SLV3_WAKEUP_EN                   ( BIT(10) )
#define BIT_AP_AHB_LP_AUTO_CTRL_EN                          ( BIT(7) )
#define BIT_AP_AHB_AP_MAINMTX_LP_DISABLE                    ( BIT(6) )
#define BIT_AP_AHB_AP_AHB_AUTO_GATE_EN                      ( BIT(5) )
#define BIT_AP_AHB_AP_EMC_AUTO_GATE_EN                      ( BIT(4) )

/* bits definitions for REG_AP_AHB_HOLDING_PEN, [0x20000014] */
#define BIT_AP_AHB_HOLDING_PEN(x)                           ( (x) )

/* bits definitions for REG_AP_AHB_CLOCK_FREQUENCY_DOWN, [0x20000018] */
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

/* bits definitions for REG_AP_AHB_AHB_EB1, [0x2000001C] */
#define BIT_AP_AHB_UFS_CFG_EB                               ( BIT(3) )
#define BIT_AP_AHB_UFX_RX_1_EB                              ( BIT(2) )
#define BIT_AP_AHB_UFX_RX_0_EB                              ( BIT(1) )
#define BIT_AP_AHB_UFS_TX_EB                                ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_0, [0x20000020] */
#define BIT_AP_AHB_UFS_TX_FRC_OFF                           ( BIT(30) )
#define BIT_AP_AHB_UFS_RX_1_FRC_OFF                         ( BIT(29) )
#define BIT_AP_AHB_UFS_RX_0_FRC_OFF                         ( BIT(28) )
#define BIT_AP_AHB_UFS_CFG_FRC_OFF                          ( BIT(27) )
#define BIT_AP_AHB_CE_FRC_OFF                               ( BIT(26) )
#define BIT_AP_AHB_IIS2_FRC_OFF                             ( BIT(25) )
#define BIT_AP_AHB_IIS1_FRC_OFF                             ( BIT(24) )
#define BIT_AP_AHB_IIS0_FRC_OFF                             ( BIT(23) )
#define BIT_AP_AHB_SPI2_FRC_OFF                             ( BIT(22) )
#define BIT_AP_AHB_SPI1_FRC_OFF                             ( BIT(21) )
#define BIT_AP_AHB_SPI0_FRC_OFF                             ( BIT(20) )
#define BIT_AP_AHB_I2C9_FRC_OFF                             ( BIT(19) )
#define BIT_AP_AHB_I2C8_FRC_OFF                             ( BIT(18) )
#define BIT_AP_AHB_I2C7_FRC_OFF                             ( BIT(17) )
#define BIT_AP_AHB_I2C6_FRC_OFF                             ( BIT(16) )
#define BIT_AP_AHB_I2C5_FRC_OFF                             ( BIT(15) )
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

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_OFF_1, [0x20000024] */
#define BIT_AP_AHB_UFS_ACLK_FRC_OFF                         ( BIT(6) )
#define BIT_AP_AHB_UART3_FRC_OFF                            ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_0, [0x20000028] */
#define BIT_AP_AHB_UFS_TX_FRC_ON                            ( BIT(30) )
#define BIT_AP_AHB_UFS_RX_1_FRC_ON                          ( BIT(29) )
#define BIT_AP_AHB_UFS_RX_0_FRC_ON                          ( BIT(28) )
#define BIT_AP_AHB_UFS_CFG_FRC_ON                           ( BIT(27) )
#define BIT_AP_AHB_CE_FRC_ON                                ( BIT(26) )
#define BIT_AP_AHB_IIS2_FRC_ON                              ( BIT(25) )
#define BIT_AP_AHB_IIS1_FRC_ON                              ( BIT(24) )
#define BIT_AP_AHB_IIS0_FRC_ON                              ( BIT(23) )
#define BIT_AP_AHB_SPI2_FRC_ON                              ( BIT(22) )
#define BIT_AP_AHB_SPI1_FRC_ON                              ( BIT(21) )
#define BIT_AP_AHB_SPI0_FRC_ON                              ( BIT(20) )
#define BIT_AP_AHB_I2C9_FRC_ON                              ( BIT(19) )
#define BIT_AP_AHB_I2C8_FRC_ON                              ( BIT(18) )
#define BIT_AP_AHB_I2C7_FRC_ON                              ( BIT(17) )
#define BIT_AP_AHB_I2C6_FRC_ON                              ( BIT(16) )
#define BIT_AP_AHB_I2C5_FRC_ON                              ( BIT(15) )
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

/* bits definitions for REG_AP_AHB_AP_SYS_CLK_EN_FRC_ON_1, [0x2000002C] */
#define BIT_AP_AHB_UFS_ACLK_FRC_ON                          ( BIT(6) )
#define BIT_AP_AHB_UART3_FRC_ON                             ( BIT(0) )

/* bits definitions for REG_AP_AHB_UFSHC_CLK_CTRL, [0x20000040] */
#define BIT_AP_AHB_CG_CLK_TREQ_SW                           ( BIT(7) )
#define BIT_AP_AHB_LP_CG_CLK_TREQ_SW                        ( BIT(6) )
#define BIT_AP_AHB_HCLK_SW                                  ( BIT(5) )
#define BIT_AP_AHB_CG_SYSCLK_SW                             ( BIT(4) )
#define BIT_AP_AHB_TX_SYMBOLCLKREQ_SW                       ( BIT(1) )
#define BIT_AP_AHB_CG_PCLKREQ_SW                            ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_ASYNC_BRG_AON, [0x20000054] */
#define BIT_AP_AHB_AP_ASYNC_BRG_AON_PU_NUM(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_ASYNC_BRG_AON_AUTO_GATE_EN           ( BIT(17) )
#define BIT_AP_AHB_AP_ASYNC_BRG_AON_LP_NUM(x)               ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_AON_LP_EB                   ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_ASYNC_BRG_DDR, [0x20000058] */
#define BIT_AP_AHB_AP_ASYNC_BRG_DDR_PU_NUM(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_ASYNC_BRG_DDR_AUTO_GATE_EN           ( BIT(17) )
#define BIT_AP_AHB_AP_ASYNC_BRG_DDR_LP_NUM(x)               ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_DDR_LP_EB                   ( BIT(0) )

/* bits definitions for REG_AP_AHB_AP_ASYNC_BRG_APCPU, [0x2000005C] */
#define BIT_AP_AHB_AP_ASYNC_BRG_APCPU_PU_NUM(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_APCPU_LP_NUM(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_AP_AHB_AP_ASYNC_BRG_APCPU_LP_EB                 ( BIT(0) )

/* bits definitions for REG_AP_AHB_M0_LPC, [0x20000060] */
#define BIT_AP_AHB_MAIN_M0_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M0_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M0_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M1_LPC, [0x20000064] */
#define BIT_AP_AHB_MAIN_M1_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M1_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M1_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M2_LPC, [0x20000068] */
#define BIT_AP_AHB_MAIN_M2_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M2_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M2_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M3_LPC, [0x2000006C] */
#define BIT_AP_AHB_MAIN_M3_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M3_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M3_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M4_LPC, [0x20000070] */
#define BIT_AP_AHB_MAIN_M4_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M4_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M4_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M5_LPC, [0x20000074] */
#define BIT_AP_AHB_MAIN_M5_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M5_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M5_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M6_LPC, [0x20000078] */
#define BIT_AP_AHB_MAIN_M6_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M6_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M6_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_M7_LPC, [0x2000007C] */
#define BIT_AP_AHB_MAIN_M7_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_MAIN_M7_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_M7_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_MAIN_LPC, [0x20000088] */
#define BIT_AP_AHB_MAIN_PU_NUM(x)                           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MATRIX_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_LP_EB                               ( BIT(16) )
#define BIT_AP_AHB_MAIN_LP_NUM(x)                           ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S0_LPC, [0x2000008C] */
#define BIT_AP_AHB_MAIN_S0_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S0_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S0_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S0_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S1_LPC, [0x20000090] */
#define BIT_AP_AHB_MAIN_S1_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S1_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S1_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S1_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S2_LPC, [0x20000094] */
#define BIT_AP_AHB_MAIN_S2_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S2_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S2_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S2_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S3_LPC, [0x20000098] */
#define BIT_AP_AHB_MAIN_S3_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S3_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S3_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S3_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S4_LPC, [0x2000009C] */
#define BIT_AP_AHB_MAIN_S4_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S4_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S4_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S4_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S5_LPC, [0x200000A0] */
#define BIT_AP_AHB_MAIN_S5_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S5_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S5_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S5_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S6_LPC, [0x200000A4] */
#define BIT_AP_AHB_MAIN_S6_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S6_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S6_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S6_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_S7_LPC, [0x200000A8] */
#define BIT_AP_AHB_MAIN_S7_PU_NUM(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_CGM_MTX_S7_AUTO_GATE_EN                  ( BIT(17) )
#define BIT_AP_AHB_MAIN_S7_LP_EB                            ( BIT(16) )
#define BIT_AP_AHB_MAIN_S7_LP_NUM(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_AHB_AP_URGENCY, [0x20000130] */
#define BIT_AP_AHB_ARURGENCY_UFS(x)                         ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_AP_AHB_AWURGENCY_UFS(x)                         ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_AP_AHB_ARURGENCY_CE(x)                          ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWURGENCY_CE(x)                          ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_AP_AHB_ARURGENCY_EMMC(x)                        ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_AP_AHB_AWURGENCY_EMMC(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AP_AHB_ARURGENCY_SDIO2(x)                       ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWURGENCY_SDIO2(x)                       ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AP_AHB_ARURGENCY_SDIO1(x)                       ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AP_AHB_AWURGENCY_SDIO1(x)                       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_AP_AHB_ARURGENCY_SDIO0(x)                       ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWURGENCY_SDIO0(x)                       ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AP_AHB_ARURGENCY_DMA(x)                         ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_AP_AHB_AWURGENCY_DMA(x)                         ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_AHB_AP_QOS0, [0x20000140] */
#define BIT_AP_AHB_ARQOS_APCPU(x)                           ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWQOS_APCPU(x)                           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARQOS_CE(x)                              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_CE(x)                              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_DMA(x)                             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_DMA(x)                             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_UFS(x)                             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_UFS(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_AP_QOS1, [0x20000144] */
#define BIT_AP_AHB_ARQOS_SDIO0(x)                           ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWQOS_SDIO0(x)                           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARQOS_SDIO1(x)                           ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWQOS_SDIO1(x)                           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARQOS_SDIO2(x)                           ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWQOS_SDIO2(x)                           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARQOS_EMMC(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWQOS_EMMC(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_IDLE_OVERFLOW, [0x20000150] */
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_APCPU              ( BIT(5) )
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_AON                ( BIT(4) )
#define BIT_AP_AHB_AXI_DETECTOR_OVERFLOW_DDR                ( BIT(3) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_APCPU                  ( BIT(2) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_AON                    ( BIT(1) )
#define BIT_AP_AHB_BRIDGE_TRANS_IDLE_DDR                    ( BIT(0) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_VDSP, [0x20000154] */
#define BIT_AP_AHB_APCPU_BRIDGE_DEBUG_SIGNAL_W(x)           ( (x) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP, [0x20000158] */
#define BIT_AP_AHB_AON_BRIDGE_DEBUG_SIGNAL_W(x)             ( (x) )

/* bits definitions for REG_AP_AHB_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP, [0x2000015C] */
#define BIT_AP_AHB_DDR_BRIDGE_DEBUG_SIGNAL_W(x)             ( (x) )

/* bits definitions for REG_AP_AHB_CACHE_EMMC_SDIO, [0x20003014] */
#define BIT_AP_AHB_ARCACHE_SDIO2(x)                         ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_AHB_AWCACHE_SDIO2(x)                         ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AP_AHB_ARCACHE_SDIO1(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_AHB_AWCACHE_SDIO1(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_AHB_ARCACHE_SDIO0(x)                         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AP_AHB_AWCACHE_SDIO0(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_AHB_ARCACHE_EMMC(x)                          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWCACHE_EMMC(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_CACHE_UFS, [0x20003018] */
#define BIT_AP_AHB_ARCACHE_UFS_SEL                          ( BIT(9) )
#define BIT_AP_AHB_AWCACHE_UFS_SEL                          ( BIT(8) )
#define BIT_AP_AHB_ARCACHE_UFS(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AP_AHB_AWCACHE_UFS(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AP_AHB_UFSHC_CTRL_STATUS, [0x2000301C] */
#define BIT_AP_AHB_RX_PWRENBL(x)                            ( (x) << 5  & (BIT(5)|BIT(6)) )
#define BIT_AP_AHB_TX_PWRENBL(x)                            ( (x) << 3  & (BIT(3)|BIT(4)) )
#define BIT_AP_AHB_LP_RESETCOMPLETE                         ( BIT(2) )
#define BIT_AP_AHB_RX_MK2DEEPEXIT                           ( BIT(1) )
#define BIT_AP_AHB_TX_MK2EXTENSIONEN                        ( BIT(0) )

/* bits definitions for REG_AP_AHB_CHIP_ID, [0x200030FC] */
#define BIT_AP_AHB_CHIP_ID(x)                               ( (x) )

/* vars definitions for controller CTL_AP_AHB */


#endif /* __AP_AHB_H____ */
