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
#define REG_AP_APB_APB_MISC_CTRL                            SCI_ADDR(CTL_AP_APB_BASE, 0x0008)
#define REG_AP_APB_AP_DUMMY_REG4                            SCI_ADDR(CTL_AP_APB_BASE, 0x000C)

/* bits definitions for REG_AP_APB_APB_EB, [0x71300000] */
#define BIT_AP_APB_INTC3_EB                                 ( BIT(22) )
#define BIT_AP_APB_INTC2_EB                                 ( BIT(21) )
#define BIT_AP_APB_INTC1_EB                                 ( BIT(20) )
#define BIT_AP_APB_INTC0_EB                                 ( BIT(19) )
#define BIT_AP_APB_SIM0_32K_EB                              ( BIT(18) )
#define BIT_AP_APB_UART1_EB                                 ( BIT(14) )
#define BIT_AP_APB_UART0_EB                                 ( BIT(13) )
#define BIT_AP_APB_I2C2_EB                                  ( BIT(10) )
#define BIT_AP_APB_I2C1_EB                                  ( BIT(9) )
#define BIT_AP_APB_I2C0_EB                                  ( BIT(8) )
#define BIT_AP_APB_SPI0_EB                                  ( BIT(5) )
#define BIT_AP_APB_IIS0_EB                                  ( BIT(1) )
#define BIT_AP_APB_SIM0_EB                                  ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_RST, [0x71300004] */
#define BIT_AP_APB_INTC3_SOFT_RST                           ( BIT(22) )
#define BIT_AP_APB_INTC2_SOFT_RST                           ( BIT(21) )
#define BIT_AP_APB_INTC1_SOFT_RST                           ( BIT(20) )
#define BIT_AP_APB_INTC0_SOFT_RST                           ( BIT(19) )
#define BIT_AP_APB_UART1_SOFT_RST                           ( BIT(14) )
#define BIT_AP_APB_UART0_SOFT_RST                           ( BIT(13) )
#define BIT_AP_APB_I2C2_SOFT_RST                            ( BIT(10) )
#define BIT_AP_APB_I2C1_SOFT_RST                            ( BIT(9) )
#define BIT_AP_APB_I2C0_SOFT_RST                            ( BIT(8) )
#define BIT_AP_APB_SPI1_SOFT_RST                            ( BIT(6) )
#define BIT_AP_APB_SPI0_SOFT_RST                            ( BIT(5) )
#define BIT_AP_APB_IIS0_SOFT_RST                            ( BIT(1) )
#define BIT_AP_APB_SIM0_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_MISC_CTRL, [0x71300008] */
#define BIT_AP_APB_FMARK_POLARITY_INV                       ( BIT(0) )

/* bits definitions for REG_AP_APB_AP_DUMMY_REG4, [0x7130000C] */
#define BIT_AP_APB_AP_DUMMY_REG4_H16(x)                     ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_APB_AP_DUMMY_REG4_L16(x)                     ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_AP_APB */


#endif /* __AP_APB_H____ */
