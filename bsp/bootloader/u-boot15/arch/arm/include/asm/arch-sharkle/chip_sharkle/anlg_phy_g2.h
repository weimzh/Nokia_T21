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

#ifndef __ANLG_PHY_G2_H____
#define __ANLG_PHY_G2_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_G2_BASE
#define CTL_ANLG_PHY_G2_BASE            SCI_IOMAP(0x403D0000)
#endif

/* registers definitions for CTL_ANLG_PHY_G2, 0x403D0000 */
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CTRL0      SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0000)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CTRL1      SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0004)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CTRL2      SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0008)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_BIST_CTRL  SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x000C)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_THM_CTRL   SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0010)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM0_CTRL_0     SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0014)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM0_CTRL_1     SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0018)
#define REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_ANA_DPLL_DUMY   SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x001C)

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CTRL0, [0x403D0000] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_N(x)       ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_IBIAS(x)   ( (x) << 15 & (BIT(15)|BIT(16)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_LPF(x)     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_SDM_EN     ( BIT(11) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_MOD_EN     ( BIT(10) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_DIV_S      ( BIT(9) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_RESERVED(x) ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_POSTDIV    ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CTRL1, [0x403D0004] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_NINT(x)    ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_KINT(x)    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CTRL2, [0x403D0008] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_CCS_CTRL(x) ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_BIST_CTRL, [0x403D000C] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_BIST_EN    ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_BIST_CTRL(x) ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_BIST_CNT(x) ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_DPLL_THM_CTRL, [0x403D0010] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_TEST_CLK_EN     ( BIT(13) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_TEST_SEL        ( BIT(12) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_TEST_THM_SEL    ( BIT(11) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_ANALOG_PLL_RESERVED(x) ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM0_CTRL_0, [0x403D0014] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM_BG_RBIAS_MODE ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM_TEST_SEL(x) ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM0_CTRL_1, [0x403D0018] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM_BP_MODE     ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM_BP_DATA(x)  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_THM_RESERVED(x) ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_ANA_DPLL_DUMY, [0x403D001C] */
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_ANALOG_DPLL_DUMY_IN(x) ( (x) << 16 & (0xFFFF0000) )
#define BIT_ANLG_PHY_G2_ANALOG_DPLL_THM_TOP_ANALOG_DPLL_DUMY_OUT(x) ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_ANLG_PHY_G2 */


#endif /* __ANLG_PHY_G2_H____ */
