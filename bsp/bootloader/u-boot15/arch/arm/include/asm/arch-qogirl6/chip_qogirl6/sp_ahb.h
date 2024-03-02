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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/AON_SYS/SharkL6 SP AHB Control Register.xls;SP_AHB_RF
 *     Revision : 224985
 *     Author   : {author}
 *     Date     : {date}
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
#define CTL_SP_AHB_BASE                 SCI_IOMAP(0x62000000)
#endif

/* registers definitions for CTL_SP_AHB, 0x62000000 */
#define REG_SP_AHB_CFG_CLK_EB                               SCI_ADDR(CTL_SP_AHB_BASE, 0x0000)
#define REG_SP_AHB_SOFT_RST                                 SCI_ADDR(CTL_SP_AHB_BASE, 0x0004)
#define REG_SP_AHB_DMA_CTRL                                 SCI_ADDR(CTL_SP_AHB_BASE, 0x0008)
#define REG_SP_AHB_SLP_CTL                                  SCI_ADDR(CTL_SP_AHB_BASE, 0x000C)
#define REG_SP_AHB_SP_CORE_SYS_CFG1                         SCI_ADDR(CTL_SP_AHB_BASE, 0x0010)
#define REG_SP_AHB_CM4_CORE_SEC_SYSTICK_CFG                 SCI_ADDR(CTL_SP_AHB_BASE, 0x0014)
#define REG_SP_AHB_CM4_CORE_NSEC_SYSTICK_CFG                SCI_ADDR(CTL_SP_AHB_BASE, 0x0018)
#define REG_SP_AHB_CM4_MAIN_STATOUT                         SCI_ADDR(CTL_SP_AHB_BASE, 0x001C)
#define REG_SP_AHB_CM4_HWDATAD_STAT                         SCI_ADDR(CTL_SP_AHB_BASE, 0x0020)
#define REG_SP_AHB_DDR_BOOT_ADDR                            SCI_ADDR(CTL_SP_AHB_BASE, 0x0024)
#define REG_SP_AHB_WDG_ENABLE                               SCI_ADDR(CTL_SP_AHB_BASE, 0x0028)
#define REG_SP_AHB_CORE_REMAP                               SCI_ADDR(CTL_SP_AHB_BASE, 0x002C)
#define REG_SP_AHB_AHB_MTX_CTL0                             SCI_ADDR(CTL_SP_AHB_BASE, 0x0040)
#define REG_SP_AHB_AHB_MTX_CTL1                             SCI_ADDR(CTL_SP_AHB_BASE, 0x0044)
#define REG_SP_AHB_AHB_MTX_CTL2                             SCI_ADDR(CTL_SP_AHB_BASE, 0x0048)
#define REG_SP_AHB_AHB_MTX_CTL3                             SCI_ADDR(CTL_SP_AHB_BASE, 0x004C)
#define REG_SP_AHB_AHB_MTX_CTL4                             SCI_ADDR(CTL_SP_AHB_BASE, 0x0050)
#define REG_SP_AHB_SP_AON_DDR_EXTEND                        SCI_ADDR(CTL_SP_AHB_BASE, 0x0060)
#define REG_SP_AHB_RES_REG                                  SCI_ADDR(CTL_SP_AHB_BASE, 0x00FC)

/* bits definitions for REG_SP_AHB_CFG_CLK_EB, [0x62000000] */
#define BIT_SP_AHB_BUSM_EB                                  ( BIT(20) )
#define BIT_SP_AHB_CACHE_EB_FRC                             ( BIT(19) )
#define BIT_SP_AHB_CACHE_EB_AUTO                            ( BIT(18) )
#define BIT_SP_AHB_EIC_GPIO_EB                              ( BIT(17) )
#define BIT_SP_AHB_EIC_GPIO_RTC_EB                          ( BIT(16) )
#define BIT_SP_AHB_EIC_GPIO_RTCDV5_EB                       ( BIT(15) )
#define BIT_SP_AHB_SPI_EB                                   ( BIT(14) )
#define BIT_SP_AHB_I3C1_EB                                  ( BIT(13) )
#define BIT_SP_AHB_I3C0_EB                                  ( BIT(12) )
#define BIT_SP_AHB_GPIO_EB                                  ( BIT(11) )
#define BIT_SP_AHB_UART1_EB                                 ( BIT(10) )
#define BIT_SP_AHB_UART0_EB                                 ( BIT(9) )
#define BIT_SP_AHB_TMR_EB                                   ( BIT(8) )
#define BIT_SP_AHB_SYST_EB                                  ( BIT(7) )
#define BIT_SP_AHB_EIC_RTCDV5_EB                            ( BIT(6) )
#define BIT_SP_AHB_EIC_EB                                   ( BIT(5) )
#define BIT_SP_AHB_INTC_EB                                  ( BIT(4) )
#define BIT_SP_AHB_EIC_RTC_EB                               ( BIT(3) )
#define BIT_SP_AHB_IMC_EB                                   ( BIT(2) )
#define BIT_SP_AHB_TIC_EB                                   ( BIT(1) )

/* bits definitions for REG_SP_AHB_SOFT_RST, [0x62000004] */
#define BIT_SP_AHB_CACHE_SOFT_RST                           ( BIT(17) )
#define BIT_SP_AHB_BUSM_SOFT_RST                            ( BIT(16) )
#define BIT_SP_AHB_EIC_GPIO_SOFT_RST                        ( BIT(15) )
#define BIT_SP_AHB_SPI_SOFT_RST                             ( BIT(14) )
#define BIT_SP_AHB_I3C1_SOFT_RST                            ( BIT(13) )
#define BIT_SP_AHB_I3C0_SOFT_RST                            ( BIT(12) )
#define BIT_SP_AHB_GPIO_SOFT_RST                            ( BIT(11) )
#define BIT_SP_AHB_UART1_SOFT_RST                           ( BIT(10) )
#define BIT_SP_AHB_UART0_SOFT_RST                           ( BIT(9) )
#define BIT_SP_AHB_TMR_SOFT_RST                             ( BIT(8) )
#define BIT_SP_AHB_SYST_SOFT_RST                            ( BIT(7) )
#define BIT_SP_AHB_WDG_SOFT_RST                             ( BIT(6) )
#define BIT_SP_AHB_EIC_SOFT_RST                             ( BIT(5) )
#define BIT_SP_AHB_INTC_SOFT_RST                            ( BIT(4) )
#define BIT_SP_AHB_IMC_SOFT_RST                             ( BIT(2) )
#define BIT_SP_AHB_TIC_SOFT_RST                             ( BIT(1) )
#define BIT_SP_AHB_ARCH_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_SP_AHB_DMA_CTRL, [0x62000008] */
#define BIT_SP_AHB_CM4_DMA_SOFT_RST                         ( BIT(9) )
#define BIT_SP_AHB_CM4_DMA_EB                               ( BIT(8) )
#define BIT_SP_AHB_HPROT_CM4_PUB_WR(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SP_AHB_HPROT_CM4_PUB_RD(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_SP_AHB_SLP_CTL, [0x6200000C] */
#define BIT_SP_AHB_SYS_AUTO_GATE_EN                         ( BIT(2) )
#define BIT_SP_AHB_CORE_AUTO_GATE_EN                        ( BIT(0) )

/* bits definitions for REG_SP_AHB_SP_CORE_SYS_CFG1, [0x62000010] */
#define BIT_SP_AHB_SOFT_FPU_EN                              ( BIT(13) )
#define BIT_SP_AHB_SOFT_DSP_EN                              ( BIT(12) )
#define BIT_SP_AHB_SOFT_DAP_EN                              ( BIT(11) )
#define BIT_SP_AHB_SOFT_SEC_EN                              ( BIT(10) )
#define BIT_SP_AHB_SOFT_EXRESPC                             ( BIT(9) )
#define BIT_SP_AHB_CMSTAR_BOOT_FROM_RAM                     ( BIT(8) )
#define BIT_SP_AHB_SOFT_TSCLK_CHG                           ( BIT(7) )
#define BIT_SP_AHB_SOFT_MPUNS_DISABLE                       ( BIT(6) )
#define BIT_SP_AHB_SOFT_DBG_RESTART                         ( BIT(5) )
#define BIT_SP_AHB_SOFT_EDBGRQ                              ( BIT(4) )
#define BIT_SP_AHB_SOFT_SLEEP_HOLD_REQ_N                    ( BIT(3) )
#define BIT_SP_AHB_SOFT_EXRESPS                             ( BIT(2) )
#define BIT_SP_AHB_SOFT_MPUS_DISABLE                        ( BIT(1) )
#define BIT_SP_AHB_SOFT_SAU_DISABLE                         ( BIT(0) )

/* bits definitions for REG_SP_AHB_CM4_CORE_SEC_SYSTICK_CFG, [0x62000014] */
#define BIT_SP_AHB_SOFT_STCALIB(x)                          ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )
#define BIT_SP_AHB_SOFT_STCLK                               ( BIT(0) )

/* bits definitions for REG_SP_AHB_CM4_CORE_NSEC_SYSTICK_CFG, [0x62000018] */
#define BIT_SP_AHB_SOFT_NSTCALIB(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)) )

/* bits definitions for REG_SP_AHB_CM4_MAIN_STATOUT, [0x6200001C] */
#define BIT_SP_AHB_WICENACK_STAT                            ( BIT(31) )
#define BIT_SP_AHB_GATEHCLK_STAT                            ( BIT(30) )
#define BIT_SP_AHB_WAKEUP_STAT                              ( BIT(29) )
#define BIT_SP_AHB_SLEEPHOLDACKN_STAT                       ( BIT(28) )
#define BIT_SP_AHB_SLEEPINGDEEP_STAT                        ( BIT(27) )
#define BIT_SP_AHB_SLEEPING_STAT                            ( BIT(26) )
#define BIT_SP_AHB_DBGRESTARTED_STAT                        ( BIT(24) )
#define BIT_SP_AHB_HALTED_STAT                              ( BIT(23) )
#define BIT_SP_AHB_EXREQS_STAT                              ( BIT(22) )
#define BIT_SP_AHB_MEMATTRS_STAT(x)                         ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_SP_AHB_HMASTLOCKS_STAT                          ( BIT(16) )
#define BIT_SP_AHB_HMASTERS_STAT                            ( BIT(15) )
#define BIT_SP_AHB_JTAGSEL_STAT                             ( BIT(14) )
#define BIT_SP_AHB_SWSEL_STAT                               ( BIT(13) )
#define BIT_SP_AHB_HWRITED_STAT                             ( BIT(12) )
#define BIT_SP_AHB_EXREQC_STAT                              ( BIT(11) )
#define BIT_SP_AHB_MEMATTRC_STAT(x)                         ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_SP_AHB_HMASTERC_STAT                            ( BIT(5) )
#define BIT_SP_AHB_CORE_HINT(x)                             ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_SP_AHB_CUR_SEC_STAT                             ( BIT(1) )
#define BIT_SP_AHB_CDBGPWRUPREQ_STAT                        ( BIT(0) )

/* bits definitions for REG_SP_AHB_CM4_HWDATAD_STAT, [0x62000020] */
#define BIT_SP_AHB_HWDATAD_STAT(x)                          ( (x) )

/* bits definitions for REG_SP_AHB_DDR_BOOT_ADDR, [0x62000024] */
#define BIT_SP_AHB_DDR_BOOT_ADDR(x)                         ( (x) )

/* bits definitions for REG_SP_AHB_WDG_ENABLE, [0x62000028] */
#define BIT_SP_AHB_WDG_EB                                   ( BIT(0) )

/* bits definitions for REG_SP_AHB_CORE_REMAP, [0x6200002C] */
#define BIT_SP_AHB_CMSTAR_ADDR_REMAP(x)                     ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SP_AHB_CMSTAR_ADDR_OFFSET(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for REG_SP_AHB_AHB_MTX_CTL0, [0x62000040] */
#define BIT_SP_AHB_PRI_M3TOS0_ADJ_EN                        ( BIT(31) )
#define BIT_SP_AHB_PRI_M3TOS0_RND_THR(x)                    ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_SP_AHB_PRI_M3TOS0_RND_EN                        ( BIT(26) )
#define BIT_SP_AHB_PRI_M3TOS0_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SP_AHB_PRI_M2TOS0_ADJ_EN                        ( BIT(23) )
#define BIT_SP_AHB_PRI_M2TOS0_RND_THR(x)                    ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_SP_AHB_PRI_M2TOS0_RND_EN                        ( BIT(18) )
#define BIT_SP_AHB_PRI_M2TOS0_SEL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_SP_AHB_PRI_M1TOS0_ADJ_EN                        ( BIT(15) )
#define BIT_SP_AHB_PRI_M1TOS0_RND_THR(x)                    ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_SP_AHB_PRI_M1TOS0_RND_EN                        ( BIT(10) )
#define BIT_SP_AHB_PRI_M1TOS0_SEL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_SP_AHB_PRI_M0TOS0_ADJ_EN                        ( BIT(7) )
#define BIT_SP_AHB_PRI_M0TOS0_RND_THR(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_SP_AHB_PRI_M0TOS0_RND_EN                        ( BIT(2) )
#define BIT_SP_AHB_PRI_M0TOS0_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_SP_AHB_AHB_MTX_CTL1, [0x62000044] */
#define BIT_SP_AHB_PRI_M2TOS1_ADJ_EN                        ( BIT(31) )
#define BIT_SP_AHB_PRI_M2TOS1_RND_THR(x)                    ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_SP_AHB_PRI_M2TOS1_RND_EN                        ( BIT(26) )
#define BIT_SP_AHB_PRI_M2TOS1_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SP_AHB_PRI_M6TOS0_ADJ_EN                        ( BIT(23) )
#define BIT_SP_AHB_PRI_M6TOS0_RND_THR(x)                    ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_SP_AHB_PRI_M6TOS0_RND_EN                        ( BIT(18) )
#define BIT_SP_AHB_PRI_M6TOS0_SEL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_SP_AHB_PRI_M5TOS0_ADJ_EN                        ( BIT(15) )
#define BIT_SP_AHB_PRI_M5TOS0_RND_THR(x)                    ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_SP_AHB_PRI_M5TOS0_RND_EN                        ( BIT(10) )
#define BIT_SP_AHB_PRI_M5TOS0_SEL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_SP_AHB_PRI_M4TOS0_ADJ_EN                        ( BIT(7) )
#define BIT_SP_AHB_PRI_M4TOS0_RND_THR(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_SP_AHB_PRI_M4TOS0_RND_EN                        ( BIT(2) )
#define BIT_SP_AHB_PRI_M4TOS0_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_SP_AHB_AHB_MTX_CTL2, [0x62000048] */
#define BIT_SP_AHB_PRI_M0TOS2_ADJ_EN                        ( BIT(31) )
#define BIT_SP_AHB_PRI_M0TOS2_RND_THR(x)                    ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_SP_AHB_PRI_M0TOS2_RND_EN                        ( BIT(26) )
#define BIT_SP_AHB_PRI_M0TOS2_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SP_AHB_PRI_M6TOS1_ADJ_EN                        ( BIT(23) )
#define BIT_SP_AHB_PRI_M6TOS1_RND_THR(x)                    ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_SP_AHB_PRI_M6TOS1_RND_EN                        ( BIT(18) )
#define BIT_SP_AHB_PRI_M6TOS1_SEL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_SP_AHB_PRI_M5TOS1_ADJ_EN                        ( BIT(15) )
#define BIT_SP_AHB_PRI_M5TOS1_RND_THR(x)                    ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_SP_AHB_PRI_M5TOS1_RND_EN                        ( BIT(10) )
#define BIT_SP_AHB_PRI_M5TOS1_SEL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_SP_AHB_PRI_M4TOS1_ADJ_EN                        ( BIT(7) )
#define BIT_SP_AHB_PRI_M4TOS1_RND_THR(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_SP_AHB_PRI_M4TOS1_RND_EN                        ( BIT(2) )
#define BIT_SP_AHB_PRI_M4TOS1_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_SP_AHB_AHB_MTX_CTL3, [0x6200004C] */
#define BIT_SP_AHB_PRI_M4TOS2_ADJ_EN                        ( BIT(31) )
#define BIT_SP_AHB_PRI_M4TOS2_RND_THR(x)                    ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_SP_AHB_PRI_M4TOS2_RND_EN                        ( BIT(26) )
#define BIT_SP_AHB_PRI_M4TOS2_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SP_AHB_PRI_M3TOS2_ADJ_EN                        ( BIT(23) )
#define BIT_SP_AHB_PRI_M3TOS2_RND_THR(x)                    ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_SP_AHB_PRI_M3TOS2_RND_EN                        ( BIT(18) )
#define BIT_SP_AHB_PRI_M3TOS2_SEL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_SP_AHB_PRI_M0TOS1_ADJ_EN                        ( BIT(15) )
#define BIT_SP_AHB_PRI_M0TOS1_RND_THR(x)                    ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_SP_AHB_PRI_M0TOS1_RND_EN                        ( BIT(10) )
#define BIT_SP_AHB_PRI_M0TOS1_SEL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_SP_AHB_PRI_M1TOS2_ADJ_EN                        ( BIT(7) )
#define BIT_SP_AHB_PRI_M1TOS2_RND_THR(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_SP_AHB_PRI_M1TOS2_RND_EN                        ( BIT(2) )
#define BIT_SP_AHB_PRI_M1TOS2_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_SP_AHB_AHB_MTX_CTL4, [0x62000050] */
#define BIT_SP_AHB_PRI_M2TOS2_ADJ_EN                        ( BIT(31) )
#define BIT_SP_AHB_PRI_M2TOS2_RND_THR(x)                    ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_SP_AHB_PRI_M2TOS2_RND_EN                        ( BIT(26) )
#define BIT_SP_AHB_PRI_M2TOS2_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_SP_AHB_PRI_M1TOS1_ADJ_EN                        ( BIT(23) )
#define BIT_SP_AHB_PRI_M1TOS1_RND_THR(x)                    ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_SP_AHB_PRI_M1TOS1_RND_EN                        ( BIT(18) )
#define BIT_SP_AHB_PRI_M1TOS1_SEL(x)                        ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_SP_AHB_PRI_M6TOS2_ADJ_EN                        ( BIT(15) )
#define BIT_SP_AHB_PRI_M6TOS2_RND_THR(x)                    ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_SP_AHB_PRI_M6TOS2_RND_EN                        ( BIT(10) )
#define BIT_SP_AHB_PRI_M6TOS2_SEL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_SP_AHB_PRI_M5TOS2_ADJ_EN                        ( BIT(7) )
#define BIT_SP_AHB_PRI_M5TOS2_RND_THR(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_SP_AHB_PRI_M5TOS2_RND_EN                        ( BIT(2) )
#define BIT_SP_AHB_PRI_M5TOS2_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_SP_AHB_SP_AON_DDR_EXTEND, [0x62000060] */
#define BIT_SP_AHB_REG_SP_AON_DDR_EXTEND(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_SP_AHB_RES_REG, [0x620000FC] */
#define BIT_SP_AHB_RES_REG_H(x)                             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SP_AHB_RES_REG_L(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* vars definitions for controller CTL_SP_AHB */


#endif /* __SP_AHB_H____ */
