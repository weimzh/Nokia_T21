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

#ifndef __AP_APB_H____
#define __AP_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AP_APB_BASE
#define CTL_AP_APB_BASE                 SCI_IOMAP(0x71300000)
#endif

/* registers definitions for CTL_AP_APB, 0x71300000 */
#define REG_AP_APB_APB_EB                                   SCI_ADDR(CTL_AP_APB_BASE, 0x0000)
#define REG_AP_APB_APB_RST                                  SCI_ADDR(CTL_AP_APB_BASE, 0x0004)
#define REG_AP_APB_APB_MISC_CTRL                            SCI_ADDR(CTL_AP_APB_BASE, 0x3000)
#define REG_AP_APB_APB_PERI_FRC_SLEEP                       SCI_ADDR(CTL_AP_APB_BASE, 0x3004)
#define REG_AP_APB_APB_PCLK_AUTO_GATE                       SCI_ADDR(CTL_AP_APB_BASE, 0x3008)
#define REG_AP_APB_APB_PCLK_AUTO_SLOW_SEL0                  SCI_ADDR(CTL_AP_APB_BASE, 0x300C)
#define REG_AP_APB_APB_PCLK_AUTO_SLOW_SEL1                  SCI_ADDR(CTL_AP_APB_BASE, 0x3010)

/* bits definitions for REG_AP_APB_APB_EB, [0x71300000] */
#define BIT_AP_APB_I2C6_EB                                  ( BIT(21) )
#define BIT_AP_APB_I2C5_EB                                  ( BIT(20) )
#define BIT_AP_APB_SPI3_EB                                  ( BIT(19) )
#define BIT_AP_APB_SIM0_32K_EB                              ( BIT(18) )
#define BIT_AP_APB_UART4_EB                                 ( BIT(17) )
#define BIT_AP_APB_UART3_EB                                 ( BIT(16) )
#define BIT_AP_APB_UART2_EB                                 ( BIT(15) )
#define BIT_AP_APB_UART1_EB                                 ( BIT(14) )
#define BIT_AP_APB_UART0_EB                                 ( BIT(13) )
#define BIT_AP_APB_I2C4_EB                                  ( BIT(12) )
#define BIT_AP_APB_I2C3_EB                                  ( BIT(11) )
#define BIT_AP_APB_I2C2_EB                                  ( BIT(10) )
#define BIT_AP_APB_I2C1_EB                                  ( BIT(9) )
#define BIT_AP_APB_I2C0_EB                                  ( BIT(8) )
#define BIT_AP_APB_SPI2_EB                                  ( BIT(7) )
#define BIT_AP_APB_SPI1_EB                                  ( BIT(6) )
#define BIT_AP_APB_SPI0_EB                                  ( BIT(5) )
#define BIT_AP_APB_IIS2_EB                                  ( BIT(3) )
#define BIT_AP_APB_IIS1_EB                                  ( BIT(2) )
#define BIT_AP_APB_IIS0_EB                                  ( BIT(1) )
#define BIT_AP_APB_SIM0_EB                                  ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_RST, [0x71300004] */
#define BIT_AP_APB_I2C6_SOFT_RST                            ( BIT(21) )
#define BIT_AP_APB_I2C5_SOFT_RST                            ( BIT(20) )
#define BIT_AP_APB_SPI3_SOFT_RST                            ( BIT(19) )
#define BIT_AP_APB_SIM0_32K_SOFT_RST                        ( BIT(18) )
#define BIT_AP_APB_UART4_SOFT_RST                           ( BIT(17) )
#define BIT_AP_APB_UART3_SOFT_RST                           ( BIT(16) )
#define BIT_AP_APB_UART2_SOFT_RST                           ( BIT(15) )
#define BIT_AP_APB_UART1_SOFT_RST                           ( BIT(14) )
#define BIT_AP_APB_UART0_SOFT_RST                           ( BIT(13) )
#define BIT_AP_APB_I2C4_SOFT_RST                            ( BIT(12) )
#define BIT_AP_APB_I2C3_SOFT_RST                            ( BIT(11) )
#define BIT_AP_APB_I2C2_SOFT_RST                            ( BIT(10) )
#define BIT_AP_APB_I2C1_SOFT_RST                            ( BIT(9) )
#define BIT_AP_APB_I2C0_SOFT_RST                            ( BIT(8) )
#define BIT_AP_APB_SPI2_SOFT_RST                            ( BIT(7) )
#define BIT_AP_APB_SPI1_SOFT_RST                            ( BIT(6) )
#define BIT_AP_APB_SPI0_SOFT_RST                            ( BIT(5) )
#define BIT_AP_APB_IIS2_SOFT_RST                            ( BIT(3) )
#define BIT_AP_APB_IIS1_SOFT_RST                            ( BIT(2) )
#define BIT_AP_APB_IIS0_SOFT_RST                            ( BIT(1) )
#define BIT_AP_APB_SIM0_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_MISC_CTRL, [0x71303000] */
#define BIT_AP_APB_SPI3_LCD_FMARK_IN_EB                     ( BIT(11) )
#define BIT_AP_APB_SPI2_LCD_FMARK_IN_EB                     ( BIT(10) )
#define BIT_AP_APB_SPI1_LCD_FMARK_IN_EB                     ( BIT(9) )
#define BIT_AP_APB_SPI0_LCD_FMARK_IN_EB                     ( BIT(8) )
#define BIT_AP_APB_SPI3_FMARK_POLARITY_INV                  ( BIT(7) )
#define BIT_AP_APB_SPI2_FMARK_POLARITY_INV                  ( BIT(6) )
#define BIT_AP_APB_SPI1_FMARK_POLARITY_INV                  ( BIT(5) )
#define BIT_AP_APB_SPI0_FMARK_POLARITY_INV                  ( BIT(4) )
#define BIT_AP_APB_SIM_CLK_POLARITY                         ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_PERI_FRC_SLEEP, [0x71303004] */
#define BIT_AP_APB_SIM0_FRC_SLEEP                           ( BIT(19) )
#define BIT_AP_APB_SPI3_FRC_SLEEP                           ( BIT(18) )
#define BIT_AP_APB_SPI2_FRC_SLEEP                           ( BIT(17) )
#define BIT_AP_APB_SPI1_FRC_SLEEP                           ( BIT(16) )
#define BIT_AP_APB_SPI0_FRC_SLEEP                           ( BIT(15) )
#define BIT_AP_APB_IIS2_FRC_SLEEP                           ( BIT(14) )
#define BIT_AP_APB_IIS1_FRC_SLEEP                           ( BIT(13) )
#define BIT_AP_APB_IIS0_FRC_SLEEP                           ( BIT(12) )
#define BIT_AP_APB_I2C6_FRC_SLEEP                           ( BIT(11) )
#define BIT_AP_APB_I2C5_FRC_SLEEP                           ( BIT(10) )
#define BIT_AP_APB_I2C4_FRC_SLEEP                           ( BIT(9) )
#define BIT_AP_APB_I2C3_FRC_SLEEP                           ( BIT(8) )
#define BIT_AP_APB_I2C2_FRC_SLEEP                           ( BIT(7) )
#define BIT_AP_APB_I2C1_FRC_SLEEP                           ( BIT(6) )
#define BIT_AP_APB_I2C0_FRC_SLEEP                           ( BIT(5) )
#define BIT_AP_APB_UART4_FRC_SLEEP                          ( BIT(4) )
#define BIT_AP_APB_UART3_FRC_SLEEP                          ( BIT(3) )
#define BIT_AP_APB_UART2_FRC_SLEEP                          ( BIT(2) )
#define BIT_AP_APB_UART1_FRC_SLEEP                          ( BIT(1) )
#define BIT_AP_APB_UART0_FRC_SLEEP                          ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_PCLK_AUTO_GATE, [0x71303008] */
#define BIT_AP_APB_SIM0_PCLK_AUTO_GATE_EB                   ( BIT(19) )
#define BIT_AP_APB_SPI3_PCLK_AUTO_GATE_EB                   ( BIT(18) )
#define BIT_AP_APB_SPI2_PCLK_AUTO_GATE_EB                   ( BIT(17) )
#define BIT_AP_APB_SPI1_PCLK_AUTO_GATE_EB                   ( BIT(16) )
#define BIT_AP_APB_SPI0_PCLK_AUTO_GATE_EB                   ( BIT(15) )
#define BIT_AP_APB_IIS2_PCLK_AUTO_GATE_EB                   ( BIT(14) )
#define BIT_AP_APB_IIS1_PCLK_AUTO_GATE_EB                   ( BIT(13) )
#define BIT_AP_APB_IIS0_PCLK_AUTO_GATE_EB                   ( BIT(12) )
#define BIT_AP_APB_I2C6_PCLK_AUTO_GATE_EB                   ( BIT(11) )
#define BIT_AP_APB_I2C5_PCLK_AUTO_GATE_EB                   ( BIT(10) )
#define BIT_AP_APB_I2C4_PCLK_AUTO_GATE_EB                   ( BIT(9) )
#define BIT_AP_APB_I2C3_PCLK_AUTO_GATE_EB                   ( BIT(8) )
#define BIT_AP_APB_I2C2_PCLK_AUTO_GATE_EB                   ( BIT(7) )
#define BIT_AP_APB_I2C1_PCLK_AUTO_GATE_EB                   ( BIT(6) )
#define BIT_AP_APB_I2C0_PCLK_AUTO_GATE_EB                   ( BIT(5) )
#define BIT_AP_APB_UART4_PCLK_AUTO_GATE_EB                  ( BIT(4) )
#define BIT_AP_APB_UART3_PCLK_AUTO_GATE_EB                  ( BIT(3) )
#define BIT_AP_APB_UART2_PCLK_AUTO_GATE_EB                  ( BIT(2) )
#define BIT_AP_APB_UART1_PCLK_AUTO_GATE_EB                  ( BIT(1) )
#define BIT_AP_APB_UART0_PCLK_AUTO_GATE_EB                  ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_PCLK_AUTO_SLOW_SEL0, [0x7130300C] */
#define BIT_AP_APB_I2C4_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AP_APB_I2C3_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AP_APB_I2C2_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_APB_I2C1_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AP_APB_I2C0_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AP_APB_UART4_PCLK_AUTO_SLOW_SEL(x)              ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AP_APB_UART3_PCLK_AUTO_SLOW_SEL(x)              ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_APB_UART2_PCLK_AUTO_SLOW_SEL(x)              ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_APB_UART1_PCLK_AUTO_SLOW_SEL(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_APB_UART0_PCLK_AUTO_SLOW_SEL(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_APB_APB_PCLK_AUTO_SLOW_SEL1, [0x71303010] */
#define BIT_AP_APB_SIM0_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AP_APB_SPI3_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AP_APB_SPI2_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AP_APB_SPI1_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_AP_APB_SPI0_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_AP_APB_IIS2_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AP_APB_IIS1_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_APB_IIS0_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_APB_I2C6_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_APB_I2C5_PCLK_AUTO_SLOW_SEL(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* vars definitions for controller CTL_AP_APB */


#endif /* __AP_APB_H____ */
