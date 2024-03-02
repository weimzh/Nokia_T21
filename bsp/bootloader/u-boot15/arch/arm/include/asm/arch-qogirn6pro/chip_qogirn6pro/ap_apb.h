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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/ap/SharkL6Pro_AP_APB_Control_Register.xls;AP_APB_REG
 *     Revision : 231409
 *     Author   : {author}
 *     Date     : {date}
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
#define CTL_AP_APB_BASE                 SCI_IOMAP(0x20100000)
#endif

/* registers definitions for CTL_AP_APB, 0x20100000 */
#define REG_AP_APB_APB_EB                                   SCI_ADDR(CTL_AP_APB_BASE, 0x0000)
#define REG_AP_APB_APB_RST                                  SCI_ADDR(CTL_AP_APB_BASE, 0x0004)
#define REG_AP_APB_APB_MISC_CTRL                            SCI_ADDR(CTL_AP_APB_BASE, 0x0008)
#define REG_AP_APB_EB_SEC                                   SCI_ADDR(CTL_AP_APB_BASE, 0x000C)
#define REG_AP_APB_APB_EB1                                  SCI_ADDR(CTL_AP_APB_BASE, 0x0010)

/* bits definitions for REG_AP_APB_APB_EB, [0x20100000] */
#define BIT_AP_APB_CE_PUB_EB                                ( BIT(31) )
#define BIT_AP_APB_CE_SEC_EB                                ( BIT(30) )
#define BIT_AP_APB_SPI3_LCD_FMARK_IN_EB                     ( BIT(21) )
#define BIT_AP_APB_SPI2_LCD_FMARK_IN_EB                     ( BIT(20) )
#define BIT_AP_APB_SPI1_LCD_FMARK_IN_EB                     ( BIT(19) )
#define BIT_AP_APB_SPI0_LCD_FMARK_IN_EB                     ( BIT(18) )
#define BIT_AP_APB_UART2_EB                                 ( BIT(16) )
#define BIT_AP_APB_UART1_EB                                 ( BIT(15) )
#define BIT_AP_APB_UART0_EB                                 ( BIT(14) )
#define BIT_AP_APB_UART3_EB                                 ( BIT(8) )
#define BIT_AP_APB_SPI2_EB                                  ( BIT(7) )
#define BIT_AP_APB_SPI1_EB                                  ( BIT(6) )
#define BIT_AP_APB_SPI0_EB                                  ( BIT(5) )
#define BIT_AP_APB_APB_REG_EB                               ( BIT(4) )
#define BIT_AP_APB_IIS2_EB                                  ( BIT(3) )
#define BIT_AP_APB_IIS1_EB                                  ( BIT(2) )
#define BIT_AP_APB_IIS0_EB                                  ( BIT(1) )

/* bits definitions for REG_AP_APB_APB_RST, [0x20100004] */
#define BIT_AP_APB_AP_DVFS_SOFT_RST                         ( BIT(22) )
#define BIT_AP_APB_CE_PUB_SOFT_RST                          ( BIT(21) )
#define BIT_AP_APB_CE_SEC_SOFT_RST                          ( BIT(20) )
#define BIT_AP_APB_UART2_SOFT_RST                           ( BIT(15) )
#define BIT_AP_APB_UART1_SOFT_RST                           ( BIT(14) )
#define BIT_AP_APB_UART0_SOFT_RST                           ( BIT(13) )
#define BIT_AP_APB_UART3_SOFT_RST                           ( BIT(7) )
#define BIT_AP_APB_SPI2_SOFT_RST                            ( BIT(6) )
#define BIT_AP_APB_SPI1_SOFT_RST                            ( BIT(5) )
#define BIT_AP_APB_SPI0_SOFT_RST                            ( BIT(4) )
#define BIT_AP_APB_IIS2_SOFT_RST                            ( BIT(3) )
#define BIT_AP_APB_IIS1_SOFT_RST                            ( BIT(2) )
#define BIT_AP_APB_IIS0_SOFT_RST                            ( BIT(1) )

/* bits definitions for REG_AP_APB_APB_MISC_CTRL, [0x20100008] */
#define BIT_AP_APB_SPI3_FMARK_POLARITY_INV                  ( BIT(5) )
#define BIT_AP_APB_SPI2_FMARK_POLARITY_INV                  ( BIT(4) )
#define BIT_AP_APB_SPI1_FMARK_POLARITY_INV                  ( BIT(3) )
#define BIT_AP_APB_SPI0_FMARK_POLARITY_INV                  ( BIT(2) )

/* bits definitions for REG_AP_APB_EB_SEC, [0x2010000C] */
#define BIT_AP_APB_DUMMY_REG(x)                             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_APB_SPI2_EB_SEC                              ( BIT(13) )
#define BIT_AP_APB_SPI1_EB_SEC                              ( BIT(12) )
#define BIT_AP_APB_SPI0_EB_SEC                              ( BIT(11) )

/* bits definitions for REG_AP_APB_APB_EB1, [0x20100010] */
#define BIT_AP_APB_DUMMY_REG_EB_1(x)                        ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AP_APB_NIC400_EB                                ( BIT(9) )

/* vars definitions for controller CTL_AP_APB */


#endif /* __AP_APB_H____ */
