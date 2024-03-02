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

#ifndef __SP_AHB_H____
#define __SP_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_SP_AHB_BASE
#define CTL_SP_AHB_BASE                 SCI_IOMAP(0x50820000)
#endif

/* registers definitions for CTL_SP_AHB, 0x50820000 */
#define REG_SP_AHB_CM4_EB                                   SCI_ADDR(CTL_SP_AHB_BASE, 0x0000)
#define REG_SP_AHB_CM4_SOFT_RST                             SCI_ADDR(CTL_SP_AHB_BASE, 0x0004)
#define REG_SP_AHB_SLP_CTL                                  SCI_ADDR(CTL_SP_AHB_BASE, 0x0008)
#define REG_SP_AHB_CM4_CORE_CFG                             SCI_ADDR(CTL_SP_AHB_BASE, 0x000C)
#define REG_SP_AHB_CM4_CORE_AUXFAULT_CFG                    SCI_ADDR(CTL_SP_AHB_BASE, 0x0010)
#define REG_SP_AHB_CM4_MAIN_STATOUT                         SCI_ADDR(CTL_SP_AHB_BASE, 0x0014)
#define REG_SP_AHB_CM4_HWDATAD_STAT                         SCI_ADDR(CTL_SP_AHB_BASE, 0x0018)
#define REG_SP_AHB_CM4_INT_STAT                             SCI_ADDR(CTL_SP_AHB_BASE, 0x001C)
#define REG_SP_AHB_CM4_CLK_EMC_CTRL                         SCI_ADDR(CTL_SP_AHB_BASE, 0x0020)
#define REG_SP_AHB_CM4_MTX_LP_CTRL                          SCI_ADDR(CTL_SP_AHB_BASE, 0x0024)
#define REG_SP_AHB_DUMMY                                    SCI_ADDR(CTL_SP_AHB_BASE, 0x0040)

/* bits definitions for REG_SP_AHB_CM4_EB, [0x50820000] */
#define BIT_SP_AHB_CM4_GPIO_EB                              ( BIT(10) )
#define BIT_SP_AHB_CM4_UART_EB                              ( BIT(9) )
#define BIT_SP_AHB_CM4_TMR_EB                               ( BIT(8) )
#define BIT_SP_AHB_CM4_SYST_EB                              ( BIT(7) )
#define BIT_SP_AHB_CM4_WDG_EB                               ( BIT(6) )
#define BIT_SP_AHB_CM4_EIC_EB                               ( BIT(5) )
#define BIT_SP_AHB_CM4_INTC_EB                              ( BIT(4) )
#define BIT_SP_AHB_CM4_IMC_EB                               ( BIT(2) )

/* bits definitions for REG_SP_AHB_CM4_SOFT_RST, [0x50820004] */
#define BIT_SP_AHB_CM4_GPIO_SOFT_RST                        ( BIT(10) )
#define BIT_SP_AHB_CM4_UART_SOFT_RST                        ( BIT(9) )
#define BIT_SP_AHB_CM4_TMR_SOFT_RST                         ( BIT(8) )
#define BIT_SP_AHB_CM4_SYST_SOFT_RST                        ( BIT(7) )
#define BIT_SP_AHB_CM4_WDG_SOFT_RST                         ( BIT(6) )
#define BIT_SP_AHB_CM4_EIC_SOFT_RST                         ( BIT(5) )
#define BIT_SP_AHB_CM4_INTC_SOFT_RST                        ( BIT(4) )
#define BIT_SP_AHB_CM4_IMC_SOFT_RST                         ( BIT(2) )
#define BIT_SP_AHB_CM4_ARCH_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_SP_AHB_SLP_CTL, [0x50820008] */
#define BIT_SP_AHB_SYS_AUTO_GATE_EN                         ( BIT(2) )
#define BIT_SP_AHB_CORE_AUTO_GATE_EN                        ( BIT(0) )

/* bits definitions for REG_SP_AHB_CM4_CORE_CFG, [0x5082000C] */
#define BIT_SP_AHB_SOFT_EXRESPD                             ( BIT(9) )
#define BIT_SP_AHB_SOFT_TSCLK_CHG                           ( BIT(7) )
#define BIT_SP_AHB_SOFT_FIX_MSTTYPE                         ( BIT(6) )
#define BIT_SP_AHB_SOFT_DBG_RESTART                         ( BIT(5) )
#define BIT_SP_AHB_SOFT_EDBGRQ                              ( BIT(4) )
#define BIT_SP_AHB_SOFT_SLEEP_HOLD_REQ_N                    ( BIT(3) )
#define BIT_SP_AHB_SOFT_EXRESPS                             ( BIT(2) )
#define BIT_SP_AHB_SOFT_CGBYPASS                            ( BIT(1) )
#define BIT_SP_AHB_SOFT_RSTBYPASS                           ( BIT(0) )

/* bits definitions for REG_SP_AHB_CM4_CORE_AUXFAULT_CFG, [0x50820010] */
#define BIT_SP_AHB_SOFT_AUXFAULT(x)                         ( (x) )

/* bits definitions for REG_SP_AHB_CM4_MAIN_STATOUT, [0x50820014] */
#define BIT_SP_AHB_WICENACK_STAT                            ( BIT(31) )
#define BIT_SP_AHB_GATEHCLK_STAT                            ( BIT(30) )
#define BIT_SP_AHB_WAKEUP_STAT                              ( BIT(29) )
#define BIT_SP_AHB_SLEEPHOLDACKN_STAT                       ( BIT(28) )
#define BIT_SP_AHB_SLEEPINGDEEP_STAT                        ( BIT(27) )
#define BIT_SP_AHB_SLEEPING_STAT                            ( BIT(26) )
#define BIT_SP_AHB_DBGRESTARTED_STAT                        ( BIT(24) )
#define BIT_SP_AHB_HALTED_STAT                              ( BIT(23) )
#define BIT_SP_AHB_BRCHSTAT_STAT(x)                         ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_SP_AHB_EXREQS_STAT                              ( BIT(18) )
#define BIT_SP_AHB_MEMATTRS_STAT(x)                         ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_SP_AHB_HMASTLOCKS_STAT                          ( BIT(15) )
#define BIT_SP_AHB_HMASTERS_STAT(x)                         ( (x) << 13 & (BIT(13)|BIT(14)) )
#define BIT_SP_AHB_HWRITED_STAT                             ( BIT(12) )
#define BIT_SP_AHB_EXREQD_STAT                              ( BIT(11) )
#define BIT_SP_AHB_MEMATTRD_STAT(x)                         ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_SP_AHB_HMASTERD_STAT(x)                         ( (x) << 7  & (BIT(7)|BIT(8)) )
#define BIT_SP_AHB_MEMATTRI_STAT(x)                         ( (x) << 5  & (BIT(5)|BIT(6)) )
#define BIT_SP_AHB_SWV_STAT                                 ( BIT(4) )
#define BIT_SP_AHB_CDBGPWRUPREQ_STAT                        ( BIT(0) )

/* bits definitions for REG_SP_AHB_CM4_HWDATAD_STAT, [0x50820018] */
#define BIT_SP_AHB_HWDATAD_STAT(x)                          ( (x) )

/* bits definitions for REG_SP_AHB_CM4_INT_STAT, [0x5082001C] */
#define BIT_SP_AHB_CURRPRI_STAT(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_SP_AHB_CM4_CLK_EMC_CTRL, [0x50820020] */
#define BIT_SP_AHB_CM4_CLK_EMC_SEL(x)                       ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_SP_AHB_CM4_CLK_EMC_DIV(x)                       ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_SP_AHB_CM4_MTX_LP_CTRL, [0x50820024] */
#define BIT_SP_AHB_LP_FORCE_ACK                             ( BIT(19) )
#define BIT_SP_AHB_LP_FORCE                                 ( BIT(18) )
#define BIT_SP_AHB_LP_STAT                                  ( BIT(17) )
#define BIT_SP_AHB_LP_EB                                    ( BIT(16) )
#define BIT_SP_AHB_LP_NUM(x)                                ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_SP_AHB_DUMMY, [0x50820040] */
#define BIT_SP_AHB_DUMMY_DEF1(x)                            ( (x) << 16 & (0xFFFF0000) )
#define BIT_SP_AHB_DUMMY_DEF0(x)                            ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_SP_AHB */


#endif /* __SP_AHB_H____ */
