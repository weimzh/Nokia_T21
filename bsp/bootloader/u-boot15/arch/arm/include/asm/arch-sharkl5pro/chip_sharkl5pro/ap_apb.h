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
#define CTL_AP_APB_BASE                 SCI_IOMAP(0x71000000)
#endif

/* registers definitions for CTL_AP_APB, 0x71000000 */
#define REG_AP_APB_APB_EB                                   SCI_ADDR(CTL_AP_APB_BASE, 0x0000)
#define REG_AP_APB_APB_RST                                  SCI_ADDR(CTL_AP_APB_BASE, 0x0004)
#define REG_AP_APB_APB_MISC_CTRL                            SCI_ADDR(CTL_AP_APB_BASE, 0x0008)

/* bits definitions for REG_AP_APB_APB_EB, [0x71000000] */
#define BIT_AP_APB_CE_PUB_EB                                ( BIT(31) )
#define BIT_AP_APB_CE_SEC_EB                                ( BIT(30) )
#define BIT_AP_APB_EMMC_32K_EB                              ( BIT(29) )
#define BIT_AP_APB_SDIO2_32K_EB                             ( BIT(28) )
#define BIT_AP_APB_SDIO1_32K_EB                             ( BIT(27) )
#define BIT_AP_APB_SDIO0_32K_EB                             ( BIT(26) )
#define BIT_AP_APB_EMMC_EB                                  ( BIT(25) )
#define BIT_AP_APB_SDIO2_EB                                 ( BIT(24) )
#define BIT_AP_APB_SDIO1_EB                                 ( BIT(23) )
#define BIT_AP_APB_SDIO0_EB                                 ( BIT(22) )
#define BIT_AP_APB_SPI3_LCD_FMARK_IN_EB                     ( BIT(21) )
#define BIT_AP_APB_SPI2_LCD_FMARK_IN_EB                     ( BIT(20) )
#define BIT_AP_APB_SPI1_LCD_FMARK_IN_EB                     ( BIT(19) )
#define BIT_AP_APB_SPI0_LCD_FMARK_IN_EB                     ( BIT(18) )
#define BIT_AP_APB_SIM0_32K_EB                              ( BIT(17) )
#define BIT_AP_APB_UART2_EB                                 ( BIT(16) )
#define BIT_AP_APB_UART1_EB                                 ( BIT(15) )
#define BIT_AP_APB_UART0_EB                                 ( BIT(14) )
#define BIT_AP_APB_I2C4_EB                                  ( BIT(13) )
#define BIT_AP_APB_I2C3_EB                                  ( BIT(12) )
#define BIT_AP_APB_I2C2_EB                                  ( BIT(11) )
#define BIT_AP_APB_I2C1_EB                                  ( BIT(10) )
#define BIT_AP_APB_I2C0_EB                                  ( BIT(9) )
#define BIT_AP_APB_SPI3_EB                                  ( BIT(8) )
#define BIT_AP_APB_SPI2_EB                                  ( BIT(7) )
#define BIT_AP_APB_SPI1_EB                                  ( BIT(6) )
#define BIT_AP_APB_SPI0_EB                                  ( BIT(5) )
#define BIT_AP_APB_APB_REG_EB                               ( BIT(4) )
#define BIT_AP_APB_IIS2_EB                                  ( BIT(3) )
#define BIT_AP_APB_IIS1_EB                                  ( BIT(2) )
#define BIT_AP_APB_IIS0_EB                                  ( BIT(1) )
#define BIT_AP_APB_SIM0_EB                                  ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_RST, [0x71000004] */
#define BIT_AP_APB_AP_DVFS_SOFT_RST                         ( BIT(22) )
#define BIT_AP_APB_CE_PUB_SOFT_RST                          ( BIT(21) )
#define BIT_AP_APB_CE_SEC_SOFT_RST                          ( BIT(20) )
#define BIT_AP_APB_EMMC_SOFT_RST                            ( BIT(19) )
#define BIT_AP_APB_SDIO2_SOFT_RST                           ( BIT(18) )
#define BIT_AP_APB_SDIO1_SOFT_RST                           ( BIT(17) )
#define BIT_AP_APB_SDIO0_SOFT_RST                           ( BIT(16) )
#define BIT_AP_APB_UART2_SOFT_RST                           ( BIT(15) )
#define BIT_AP_APB_UART1_SOFT_RST                           ( BIT(14) )
#define BIT_AP_APB_UART0_SOFT_RST                           ( BIT(13) )
#define BIT_AP_APB_I2C4_SOFT_RST                            ( BIT(12) )
#define BIT_AP_APB_I2C3_SOFT_RST                            ( BIT(11) )
#define BIT_AP_APB_I2C2_SOFT_RST                            ( BIT(10) )
#define BIT_AP_APB_I2C1_SOFT_RST                            ( BIT(9) )
#define BIT_AP_APB_I2C0_SOFT_RST                            ( BIT(8) )
#define BIT_AP_APB_SPI3_SOFT_RST                            ( BIT(7) )
#define BIT_AP_APB_SPI2_SOFT_RST                            ( BIT(6) )
#define BIT_AP_APB_SPI1_SOFT_RST                            ( BIT(5) )
#define BIT_AP_APB_SPI0_SOFT_RST                            ( BIT(4) )
#define BIT_AP_APB_IIS2_SOFT_RST                            ( BIT(3) )
#define BIT_AP_APB_IIS1_SOFT_RST                            ( BIT(2) )
#define BIT_AP_APB_IIS0_SOFT_RST                            ( BIT(1) )
#define BIT_AP_APB_SIM0_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_AP_APB_APB_MISC_CTRL, [0x71000008] */
#define BIT_AP_APB_I2C4_SEC_EB                              ( BIT(14) )
#define BIT_AP_APB_I2C3_SEC_EB                              ( BIT(13) )
#define BIT_AP_APB_I2C2_SEC_EB                              ( BIT(12) )
#define BIT_AP_APB_I2C1_SEC_EB                              ( BIT(11) )
#define BIT_AP_APB_I2C0_SEC_EB                              ( BIT(10) )
#define BIT_AP_APB_SPI3_SEC_EB                              ( BIT(9) )
#define BIT_AP_APB_SPI2_SEC_EB                              ( BIT(8) )
#define BIT_AP_APB_SPI1_SEC_EB                              ( BIT(7) )
#define BIT_AP_APB_SPI0_SEC_EB                              ( BIT(6) )
#define BIT_AP_APB_SPI3_FMARK_POLARITY_INV                  ( BIT(5) )
#define BIT_AP_APB_SPI2_FMARK_POLARITY_INV                  ( BIT(4) )
#define BIT_AP_APB_SPI1_FMARK_POLARITY_INV                  ( BIT(3) )
#define BIT_AP_APB_SPI0_FMARK_POLARITY_INV                  ( BIT(2) )
#define BIT_AP_APB_SIM_CLK_POLARITY                         ( BIT(1) )

/* vars definitions for controller CTL_AP_APB */


#endif /* __AP_APB_H____ */
