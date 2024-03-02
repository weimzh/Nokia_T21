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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/SHARKL6_RTL_0.5_DV_00/PUB_SYS/SharkL6 PUB QOSC AHB Control Register.xls;PUB_QOSC_AHB_REG
 *     Revision : 201290
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __PUB_QOSC_AHB_H____
#define __PUB_QOSC_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_PUB_QOSC_AHB_BASE
#define CTL_PUB_QOSC_AHB_BASE           SCI_IOMAP(0x60210000)
#endif

/* registers definitions for CTL_PUB_QOSC_AHB, 0x60210000 */
#define REG_PUB_QOSC_AHB_LATMON_EB                          SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0800)
#define REG_PUB_QOSC_AHB_LATMON_RESET                       SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0804)
#define REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM0                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0808)
#define REG_PUB_QOSC_AHB_URGENT_RATIO_LM0                   SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x080C)
#define REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM0                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0810)
#define REG_PUB_QOSC_AHB_LATMON_HW_DFS_CFG                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0814)
#define REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM1                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0820)
#define REG_PUB_QOSC_AHB_URGENT_RATIO_LM1                   SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0824)
#define REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM1                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0828)
#define REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM2                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0830)
#define REG_PUB_QOSC_AHB_URGENT_RATIO_LM2                   SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0834)
#define REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM2                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0838)
#define REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM3                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0840)
#define REG_PUB_QOSC_AHB_URGENT_RATIO_LM3                   SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0844)
#define REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM3                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0848)
#define REG_PUB_QOSC_AHB_LATMON_LM0_STATUS0                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0900)
#define REG_PUB_QOSC_AHB_LATMON_LM0_STATUS1                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0904)
#define REG_PUB_QOSC_AHB_LATMON_LM0_STATUS2                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0908)
#define REG_PUB_QOSC_AHB_LATMON_LM0_STATUS3                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x090C)
#define REG_PUB_QOSC_AHB_LATMON_LM1_STATUS0                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0910)
#define REG_PUB_QOSC_AHB_LATMON_LM1_STATUS1                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0914)
#define REG_PUB_QOSC_AHB_LATMON_LM1_STATUS2                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0918)
#define REG_PUB_QOSC_AHB_LATMON_LM1_STATUS3                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x091C)
#define REG_PUB_QOSC_AHB_LATMON_LM2_STATUS0                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0920)
#define REG_PUB_QOSC_AHB_LATMON_LM2_STATUS1                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0924)
#define REG_PUB_QOSC_AHB_LATMON_LM2_STATUS2                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0928)
#define REG_PUB_QOSC_AHB_LATMON_LM2_STATUS3                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x092C)
#define REG_PUB_QOSC_AHB_LATMON_LM3_STATUS0                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0930)
#define REG_PUB_QOSC_AHB_LATMON_LM3_STATUS1                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0934)
#define REG_PUB_QOSC_AHB_LATMON_LM3_STATUS2                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0938)
#define REG_PUB_QOSC_AHB_LATMON_LM3_STATUS3                 SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x093C)
#define REG_PUB_QOSC_AHB_LATMON_STATUS                      SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0940)
#define REG_PUB_QOSC_AHB_BWMON_EB                           SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A00)
#define REG_PUB_QOSC_AHB_BWMON0_UP_WBW_SET                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A04)
#define REG_PUB_QOSC_AHB_BWMON0_UP_RBW_SET                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A08)
#define REG_PUB_QOSC_AHB_BWMON1_UP_WBW_SET                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A0C)
#define REG_PUB_QOSC_AHB_BWMON1_UP_RBW_SET                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A10)
#define REG_PUB_QOSC_AHB_BWMON2_UP_WBW_SET                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A14)
#define REG_PUB_QOSC_AHB_BWMON2_UP_RBW_SET                  SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A18)
#define REG_PUB_QOSC_AHB_BWMON_STATUS                       SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A70)
#define REG_PUB_QOSC_AHB_BWMON0_WBW_CNT                     SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A80)
#define REG_PUB_QOSC_AHB_BWMON0_RBW_CNT                     SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A84)
#define REG_PUB_QOSC_AHB_BWMON1_WBW_CNT                     SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A88)
#define REG_PUB_QOSC_AHB_BWMON1_RBW_CNT                     SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A8C)
#define REG_PUB_QOSC_AHB_BWMON2_WBW_CNT                     SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A90)
#define REG_PUB_QOSC_AHB_BWMON2_RBW_CNT                     SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0A94)
#define REG_PUB_QOSC_AHB_DUMMY_REG0                         SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0E10)
#define REG_PUB_QOSC_AHB_DUMMY_REG1                         SCI_ADDR(CTL_PUB_QOSC_AHB_BASE, 0x0E14)

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_EB, [0x60210800] */
#define BIT_PUB_QOSC_AHB_LATMON_SW_TIMER_EN(x)              ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_QOSC_AHB_LATMON_TIMER_SEL(x)                ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_LATMON2_SEL                        ( BIT(16) )
#define BIT_PUB_QOSC_AHB_LATMON_AUTO_GATE_EN(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_QOSC_AHB_LATMON_CLK_TICK_ENABLE(x)          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_QOSC_AHB_LATMON_ENABLE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_RESET, [0x60210804] */
#define BIT_PUB_QOSC_AHB_LATMON_COUNT_RESET(x)              ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_QOSC_AHB_LATMON_RESET(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM0, [0x60210808] */
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_RD_LM0(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_WR_LM0(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_QOSC_AHB_URGENT_RATIO_LM0, [0x6021080C] */
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_RD_LM0(x)       ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_WR_LM0(x)       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_RD_LM0(x)        ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_WR_LM0(x)        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM0, [0x60210810] */
#define BIT_PUB_QOSC_AHB_LATMON_INIT_URGENT_DEB_LM0(x)      ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_SEL_LM0(x)           ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_VALUE_LM0(x)         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_LAT_SUB_ALL_RATIO_LM0(x)           ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_PERIOD_LM0(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_HW_DFS_CFG, [0x60210814] */
#define BIT_PUB_QOSC_AHB_LATMON_HW_DFS_TRIGGER_SEL_LM3(x)   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_QOSC_AHB_LATMON_HW_DFS_TRIGGER_SEL_LM2(x)   ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_QOSC_AHB_LATMON_HW_DFS_TRIGGER_SEL_LM1(x)   ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_QOSC_AHB_LATMON_HW_DFS_TRIGGER_SEL_LM0(x)   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_QOSC_AHB_LATMON_HW_DFS_TRIGGER_EN(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM1, [0x60210820] */
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_RD_LM1(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_WR_LM1(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_QOSC_AHB_URGENT_RATIO_LM1, [0x60210824] */
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_RD_LM1(x)       ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_WR_LM1(x)       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_RD_LM1(x)        ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_WR_LM1(x)        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM1, [0x60210828] */
#define BIT_PUB_QOSC_AHB_LATMON_INIT_URGENT_DEB_LM1(x)      ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_SEL_LM1(x)           ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_VALUE_LM1(x)         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_LAT_SUB_ALL_RATIO_LM1(x)           ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_PERIOD_LM1(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM2, [0x60210830] */
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_RD_LM2(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_WR_LM2(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_QOSC_AHB_URGENT_RATIO_LM2, [0x60210834] */
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_RD_LM2(x)       ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_WR_LM2(x)       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_RD_LM2(x)        ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_WR_LM2(x)        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM2, [0x60210838] */
#define BIT_PUB_QOSC_AHB_LATMON_INIT_URGENT_DEB_LM2(x)      ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_SEL_LM2(x)           ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_VALUE_LM2(x)         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_LAT_SUB_ALL_RATIO_LM2(x)           ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_PERIOD_LM2(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_TAR_LAT_OFFSET_LM3, [0x60210840] */
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_RD_LM3(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_TAR_LAT_OFFSET_WR_LM3(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_QOSC_AHB_URGENT_RATIO_LM3, [0x60210844] */
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_RD_LM3(x)       ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_QOSC_AHB_URGENT_ULTRA_RATIO_WR_LM3(x)       ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_RD_LM3(x)        ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_QOSC_AHB_URGENT_HIGH_RATIO_WR_LM3(x)        ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_SUB_CFG_LM3, [0x60210848] */
#define BIT_PUB_QOSC_AHB_LATMON_INIT_URGENT_DEB_LM3(x)      ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_SEL_LM3(x)           ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_VALUE_LM3(x)         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_QOSC_AHB_LAT_SUB_ALL_RATIO_LM3(x)           ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_QOSC_AHB_TIMER_LAT_SUB_PERIOD_LM3(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM0_STATUS0, [0x60210900] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_WR_LM0(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM0_STATUS1, [0x60210904] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_WR_LM0(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM0_STATUS2, [0x60210908] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_RD_LM0(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM0_STATUS3, [0x6021090C] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_RD_LM0(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM1_STATUS0, [0x60210910] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_WR_LM1(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM1_STATUS1, [0x60210914] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_WR_LM1(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM1_STATUS2, [0x60210918] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_RD_LM1(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM1_STATUS3, [0x6021091C] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_RD_LM1(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM2_STATUS0, [0x60210920] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_WR_LM2(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM2_STATUS1, [0x60210924] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_WR_LM2(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM2_STATUS2, [0x60210928] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_RD_LM2(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM2_STATUS3, [0x6021092C] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_RD_LM2(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM3_STATUS0, [0x60210930] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_WR_LM3(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM3_STATUS1, [0x60210934] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_WR_LM3(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM3_STATUS2, [0x60210938] */
#define BIT_PUB_QOSC_AHB_LATENCY_ACTUAL_RD_LM3(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_LM3_STATUS3, [0x6021093C] */
#define BIT_PUB_QOSC_AHB_LATENCY_TARGET_RD_LM3(x)           ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_LATMON_STATUS, [0x60210940] */
#define BIT_PUB_QOSC_AHB_LATMON3_UPDATE_FLAG_CLR            ( BIT(23) )
#define BIT_PUB_QOSC_AHB_LATMON2_UPDATE_FLAG_CLR            ( BIT(22) )
#define BIT_PUB_QOSC_AHB_LATMON1_UPDATE_FLAG_CLR            ( BIT(21) )
#define BIT_PUB_QOSC_AHB_LATMON0_UPDATE_FLAG_CLR            ( BIT(20) )
#define BIT_PUB_QOSC_AHB_LATMON3_UPDATE_FLAG                ( BIT(19) )
#define BIT_PUB_QOSC_AHB_LATMON2_UPDATE_FLAG                ( BIT(18) )
#define BIT_PUB_QOSC_AHB_LATMON1_UPDATE_FLAG                ( BIT(17) )
#define BIT_PUB_QOSC_AHB_LATMON0_UPDATE_FLAG                ( BIT(16) )
#define BIT_PUB_QOSC_AHB_LATMON_COUNTER_OV_ST(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON_EB, [0x60210A00] */
#define BIT_PUB_QOSC_AHB_BWMON_F_UP_REQ_EN(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_QOSC_AHB_BWMON_RBW_EN(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_QOSC_AHB_BWMON_WBW_EN(x)                    ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_QOSC_AHB_BWMON_ENABLE(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON0_UP_WBW_SET, [0x60210A04] */
#define BIT_PUB_QOSC_AHB_BWMON0_UP_WBW_SET(x)               ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON0_UP_RBW_SET, [0x60210A08] */
#define BIT_PUB_QOSC_AHB_BWMON0_UP_RBW_SET(x)               ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON1_UP_WBW_SET, [0x60210A0C] */
#define BIT_PUB_QOSC_AHB_BWMON1_UP_WBW_SET(x)               ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON1_UP_RBW_SET, [0x60210A10] */
#define BIT_PUB_QOSC_AHB_BWMON1_UP_RBW_SET(x)               ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON2_UP_WBW_SET, [0x60210A14] */
#define BIT_PUB_QOSC_AHB_BWMON2_UP_WBW_SET(x)               ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON2_UP_RBW_SET, [0x60210A18] */
#define BIT_PUB_QOSC_AHB_BWMON2_UP_RBW_SET(x)               ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON_STATUS, [0x60210A70] */
#define BIT_PUB_QOSC_AHB_BWMON2_UPDATE_FLAG_CLR             ( BIT(10) )
#define BIT_PUB_QOSC_AHB_BWMON1_UPDATE_FLAG_CLR             ( BIT(9) )
#define BIT_PUB_QOSC_AHB_BWMON0_UPDATE_FLAG_CLR             ( BIT(8) )
#define BIT_PUB_QOSC_AHB_BWMON2_UPDATE_FLAG                 ( BIT(2) )
#define BIT_PUB_QOSC_AHB_BWMON1_UPDATE_FLAG                 ( BIT(1) )
#define BIT_PUB_QOSC_AHB_BWMON0_UPDATE_FLAG                 ( BIT(0) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON0_WBW_CNT, [0x60210A80] */
#define BIT_PUB_QOSC_AHB_BWMON0_WBW_CNT(x)                  ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON0_RBW_CNT, [0x60210A84] */
#define BIT_PUB_QOSC_AHB_BWMON0_RBW_CNT(x)                  ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON1_WBW_CNT, [0x60210A88] */
#define BIT_PUB_QOSC_AHB_BWMON1_WBW_CNT(x)                  ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON1_RBW_CNT, [0x60210A8C] */
#define BIT_PUB_QOSC_AHB_BWMON1_RBW_CNT(x)                  ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON2_WBW_CNT, [0x60210A90] */
#define BIT_PUB_QOSC_AHB_BWMON2_WBW_CNT(x)                  ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_BWMON2_RBW_CNT, [0x60210A94] */
#define BIT_PUB_QOSC_AHB_BWMON2_RBW_CNT(x)                  ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_DUMMY_REG0, [0x60210E10] */
#define BIT_PUB_QOSC_AHB_DUMMY_REG0(x)                      ( (x) )

/* bits definitions for REG_PUB_QOSC_AHB_DUMMY_REG1, [0x60210E14] */
#define BIT_PUB_QOSC_AHB_DUMMY_REG1(x)                      ( (x) )

/* vars definitions for controller CTL_PUB_QOSC_AHB */


#endif /* __PUB_QOSC_AHB_H____ */
