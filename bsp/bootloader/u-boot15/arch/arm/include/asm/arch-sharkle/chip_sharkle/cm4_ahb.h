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

#ifndef __CM4_AHB_H____
#define __CM4_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_CM4_AHB_BASE
#define CTL_CM4_AHB_BASE                SCI_IOMAP(0x50820000)
#endif

/* registers definitions for CTL_CM4_AHB, 0x44020000 */
#define REG_CM4_AHB_CM4_EB                                  SCI_ADDR(CTL_CM4_AHB_BASE, 0x0000)
#define REG_CM4_AHB_CM4_SOFT_RST                            SCI_ADDR(CTL_CM4_AHB_BASE, 0x0004)
#define REG_CM4_AHB_AHB_PAUSE                               SCI_ADDR(CTL_CM4_AHB_BASE, 0x0008)
#define REG_CM4_AHB_CM4_SLP_CTL                             SCI_ADDR(CTL_CM4_AHB_BASE, 0x000C)
#define REG_CM4_AHB_CM4_CLK_EMC_CTRL                        SCI_ADDR(CTL_CM4_AHB_BASE, 0x0010)
#define REG_CM4_AHB_CM4_CORE_SYSTICK_CFG                    SCI_ADDR(CTL_CM4_AHB_BASE, 0x0014)
#define REG_CM4_AHB_CM4_CORE_AUXFAULT_CFG                   SCI_ADDR(CTL_CM4_AHB_BASE, 0x0018)
#define REG_CM4_AHB_CM4_CORE_CFG1                           SCI_ADDR(CTL_CM4_AHB_BASE, 0x001C)
#define REG_CM4_AHB_FPU_CFG                                 SCI_ADDR(CTL_CM4_AHB_BASE, 0x0020)
#define REG_CM4_AHB_CM4_MAIN_STATOUT                        SCI_ADDR(CTL_CM4_AHB_BASE, 0x0024)
#define REG_CM4_AHB_CM4_INT_STAT                            SCI_ADDR(CTL_CM4_AHB_BASE, 0x0028)
#define REG_CM4_AHB_AHB_MTX_CTL0                            SCI_ADDR(CTL_CM4_AHB_BASE, 0x002C)
#define REG_CM4_AHB_AHB_MTX_CTL1                            SCI_ADDR(CTL_CM4_AHB_BASE, 0x0030)
#define REG_CM4_AHB_DMC_CTRL0                               SCI_ADDR(CTL_CM4_AHB_BASE, 0x0034)
#define REG_CM4_AHB_RTC_PERI_EB                             SCI_ADDR(CTL_CM4_AHB_BASE, 0x0038)
#define REG_CM4_AHB_CM4_ARCH_SOFT_RST                       SCI_ADDR(CTL_CM4_AHB_BASE, 0x003C)

/* bits definitions for REG_CM4_AHB_CM4_EB, [0x44020000] */
#define BIT_CM4_AHB_CM4_IMC_EB                              ( BIT(9) )
#define BIT_CM4_AHB_CM4_TIC_EB                              ( BIT(8) )
#define BIT_CM4_AHB_CM4_DAP_EB                              ( BIT(7) )
#define BIT_CM4_AHB_CM4_GPIO_EB                             ( BIT(6) )
#define BIT_CM4_AHB_CM4_UART_EB                             ( BIT(5) )
#define BIT_CM4_AHB_CM4_TMR_EB                              ( BIT(4) )
#define BIT_CM4_AHB_CM4_SYST_EB                             ( BIT(3) )
#define BIT_CM4_AHB_CM4_WDG_EB                              ( BIT(2) )
#define BIT_CM4_AHB_CM4_EIC_EB                              ( BIT(1) )
#define BIT_CM4_AHB_CM4_INTC_EB                             ( BIT(0) )

/* bits definitions for REG_CM4_AHB_CM4_SOFT_RST, [0x44020004] */
#define BIT_CM4_AHB_CM4_IMC_SOFT_RST                        ( BIT(9) )
#define BIT_CM4_AHB_CM4_TIC_SOFT_RST                        ( BIT(8) )
#define BIT_CM4_AHB_CM4_DAP_SOFT_RST                        ( BIT(7) )
#define BIT_CM4_AHB_CM4_GPIO_SOFT_RST                       ( BIT(6) )
#define BIT_CM4_AHB_CM4_UART_SOFT_RST                       ( BIT(5) )
#define BIT_CM4_AHB_CM4_TMR_SOFT_RST                        ( BIT(4) )
#define BIT_CM4_AHB_CM4_SYST_SOFT_RST                       ( BIT(3) )
#define BIT_CM4_AHB_CM4_WDG_SOFT_RST                        ( BIT(2) )
#define BIT_CM4_AHB_CM4_EIC_SOFT_RST                        ( BIT(1) )
#define BIT_CM4_AHB_CM4_INTC_SOFT_RST                       ( BIT(0) )

/* bits definitions for REG_CM4_AHB_AHB_PAUSE, [0x44020008] */

/* bits definitions for REG_CM4_AHB_CM4_SLP_CTL, [0x4402000C] */
#define BIT_CM4_AHB_CM4_EIC_NOTLAT_INT_WAKE_EN              ( BIT(9) )
#define BIT_CM4_AHB_ANA_INT_WAKE_EN                         ( BIT(8) )
#define BIT_CM4_AHB_CM4_GPIO_INT_WAKE_EN                    ( BIT(7) )
#define BIT_CM4_AHB_CM4_WDG_INT_WAKE_EN                     ( BIT(6) )
#define BIT_CM4_AHB_CM4_SYST_INT_WAKE_EN                    ( BIT(5) )
#define BIT_CM4_AHB_CM4_TMR_INT_WAKE_EN                     ( BIT(4) )
#define BIT_CM4_AHB_CM4_EIC_LAT_INT_WAKE_EN                 ( BIT(3) )
#define BIT_CM4_AHB_CM4_UART_INT_WAKE_EN                    ( BIT(2) )
#define BIT_CM4_AHB_SYS_AUTO_GATE_EN                        ( BIT(1) )
#define BIT_CM4_AHB_CORE_AUTO_GATE_EN                       ( BIT(0) )

/* bits definitions for REG_CM4_AHB_CM4_CLK_EMC_CTRL, [0x44020010] */
#define BIT_CM4_AHB_CM4_CLK_EMC_SEL(x)                      ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_CM4_AHB_CM4_CLK_EMC_DIV(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_CM4_AHB_CM4_CORE_SYSTICK_CFG, [0x44020014] */
#define BIT_CM4_AHB_SOFT_STCALIB(x)                         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BIT_CM4_AHB_SOFT_STCLK                              ( BIT(0) )

/* bits definitions for REG_CM4_AHB_CM4_CORE_AUXFAULT_CFG, [0x44020018] */
#define BIT_CM4_AHB_SOFT_AUXFAULT(x)                        ( (x) )

/* bits definitions for REG_CM4_AHB_CM4_CORE_CFG1, [0x4402001C] */
#define BIT_CM4_AHB_SOFT_EXRESPD                            ( BIT(9) )
#define BIT_CM4_AHB_SOFT_TSCLK_CHG                          ( BIT(7) )
#define BIT_CM4_AHB_SOFT_FIX_MSTTYPE                        ( BIT(6) )
#define BIT_CM4_AHB_SOFT_DBG_RESTART                        ( BIT(5) )
#define BIT_CM4_AHB_SOFT_EDBGRQ                             ( BIT(4) )
#define BIT_CM4_AHB_SOFT_SLEEP_HOLD_REQ_N                   ( BIT(3) )
#define BIT_CM4_AHB_SOFT_EXRESPS                            ( BIT(2) )
#define BIT_CM4_AHB_SOFT_CGBYPASS                           ( BIT(1) )
#define BIT_CM4_AHB_SOFT_RSTBYPASS                          ( BIT(0) )

/* bits definitions for REG_CM4_AHB_FPU_CFG, [0x44020020] */
#define BIT_CM4_AHB_FPU_DISABLE                             ( BIT(0) )

/* bits definitions for REG_CM4_AHB_CM4_MAIN_STATOUT, [0x44020024] */
#define BIT_CM4_AHB_WICENACK_STAT                           ( BIT(31) )
#define BIT_CM4_AHB_GATEHCLK_STAT                           ( BIT(30) )
#define BIT_CM4_AHB_WAKEUP_STAT                             ( BIT(29) )
#define BIT_CM4_AHB_SLEEPHOLDACKN_STAT                      ( BIT(28) )
#define BIT_CM4_AHB_SLEEPINGDEEP_STAT                       ( BIT(27) )
#define BIT_CM4_AHB_SLEEPING_STAT                           ( BIT(26) )
#define BIT_CM4_AHB_DBGRESTARTED_STAT                       ( BIT(24) )
#define BIT_CM4_AHB_HALTED_STAT                             ( BIT(23) )
#define BIT_CM4_AHB_BRCHSTAT_STAT(x)                        ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_CM4_AHB_EXREQS_STAT                             ( BIT(18) )
#define BIT_CM4_AHB_MEMATTRS_STAT(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_CM4_AHB_HMASTLOCKS_STAT                         ( BIT(15) )
#define BIT_CM4_AHB_HMASTERS_STAT(x)                        ( (x) << 13 & (BIT(13)|BIT(14)) )
#define BIT_CM4_AHB_HWRITED_STAT                            ( BIT(12) )
#define BIT_CM4_AHB_EXREQD_STAT                             ( BIT(11) )
#define BIT_CM4_AHB_MEMATTRD_STAT(x)                        ( (x) << 9  & (BIT(9)|BIT(10)) )
#define BIT_CM4_AHB_HMASTERD_STAT(x)                        ( (x) << 7  & (BIT(7)|BIT(8)) )
#define BIT_CM4_AHB_MEMATTRI_STAT(x)                        ( (x) << 5  & (BIT(5)|BIT(6)) )
#define BIT_CM4_AHB_SWV_STAT                                ( BIT(4) )
#define BIT_CM4_AHB_LOCKUP_STAT                             ( BIT(3) )
#define BIT_CM4_AHB_CDBGPWRUPREQ_STAT                       ( BIT(0) )

/* bits definitions for REG_CM4_AHB_CM4_INT_STAT, [0x44020028] */
#define BIT_CM4_AHB_CURRPRI_STAT(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_CM4_AHB_AHB_MTX_CTL0, [0x4402002C] */
#define BIT_CM4_AHB_MATRIX_CTRL0(x)                         ( (x) )

/* bits definitions for REG_CM4_AHB_AHB_MTX_CTL1, [0x44020030] */
#define BIT_CM4_AHB_MATRIX_CTRL1(x)                         ( (x) )

/* bits definitions for REG_CM4_AHB_DMC_CTRL0, [0x44020034] */
#define BIT_CM4_AHB_CLK_DMC_SP_SEL(x)                       ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)) )
#define BIT_CM4_AHB_CLK_DMC_2X_SP_DIV(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_CM4_AHB_CLK_DMC_1X_SP_DIV                       ( BIT(2) )
#define BIT_CM4_AHB_CLK_DMC_SEL_HW_SP_EN                    ( BIT(1) )
#define BIT_CM4_AHB_SP_DMC_DFS_EN                           ( BIT(0) )

/* bits definitions for REG_CM4_AHB_RTC_PERI_EB, [0x44020038] */
#define BIT_CM4_AHB_RTC_CM4_EIC_EB                          ( BIT(7) )
#define BIT_CM4_AHB_RTC_CM4_SYST_EB                         ( BIT(6) )
#define BIT_CM4_AHB_RTC_CM4_TMR_EB                          ( BIT(5) )
#define BIT_CM4_AHB_RTC_CM4_WDG_EB                          ( BIT(4) )
#define BIT_CM4_AHB_RTCDV5_CM4_EIC_EB                       ( BIT(3) )
#define BIT_CM4_AHB_RTCDV5_CM4_ARCH_EB                      ( BIT(2) )
#define BIT_CM4_AHB_CM4_TMR_EB_26M                          ( BIT(1) )

/* bits definitions for REG_CM4_AHB_CM4_ARCH_SOFT_RST, [0x4402003C] */
#define BIT_CM4_AHB_CM4_ARCH_SOFT_RST                       ( BIT(0) )

/* vars definitions for controller CTL_CM4_AHB */


#endif /* __CM4_AHB_H____ */
