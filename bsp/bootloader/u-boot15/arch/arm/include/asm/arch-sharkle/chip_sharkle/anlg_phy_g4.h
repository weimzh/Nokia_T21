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

#ifndef __ANLG_PHY_G4_H____
#define __ANLG_PHY_G4_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_G4_BASE
#define CTL_ANLG_PHY_G4_BASE            SCI_IOMAP(0x403F0000)
#endif

/* registers definitions for CTL_ANLG_PHY_G4, 0x403F0000 */
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL0      SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0000)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL1      SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0004)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL2      SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0008)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL3      SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x000C)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_BIST_CTRL  SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0010)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_THM_CTRL   SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0014)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM1_CTRL_0     SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0018)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM1_CTRL_1     SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x001C)
#define REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_ANA_MPLL_DUMY   SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0020)

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL0, [0x403F0000] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_N(x)       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_IBIAS(x)   ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_LPF(x)     ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_SDM_EN     ( BIT(2) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_MOD_EN     ( BIT(1) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_DIV_S      ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL1, [0x403F0004] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_NINT(x)    ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_KINT(x)    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL2, [0x403F0008] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_RESERVED(x) ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_POSTDIV    ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CTRL3, [0x403F000C] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_CCS_CTRL(x) ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_BIST_CTRL, [0x403F0010] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_BIST_EN    ( BIT(24) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_BIST_CTRL(x) ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_BIST_CNT(x) ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_MPLL_THM_CTRL, [0x403F0014] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_TEST_CLK_EN     ( BIT(13) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_TEST_SEL        ( BIT(12) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_TEST_THM_SEL    ( BIT(11) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_ANALOG_PLL_RESERVED(x) ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM1_CTRL_0, [0x403F0018] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM_BG_RBIAS_MODE ( BIT(2) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM_TEST_SEL(x) ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM1_CTRL_1, [0x403F001C] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM_BP_MODE     ( BIT(24) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM_BP_DATA(x)  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_THM_RESERVED(x) ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_ANA_MPLL_DUMY, [0x403F0020] */
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_ANALOG_MPLL_DUMY_IN(x) ( (x) << 16 & (0xFFFF0000) )
#define BIT_ANLG_PHY_G4_ANALOG_MPLL_THM_TOP_ANALOG_MPLL_DUMY_OUT(x) ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_ANLG_PHY_G4 */


#endif /* __ANLG_PHY_G4_H____ */
