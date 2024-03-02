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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/SHARKL6_RTL_0.5_DV_00/Analog/Analog_G0 Control Register.xls;Analog_G0
 *     Revision : 201340
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __ANLG_PHY_G0_H____
#define __ANLG_PHY_G0_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_G0_BASE
#define CTL_ANLG_PHY_G0_BASE            SCI_IOMAP(0x64550000)
#endif

/* registers definitions for CTL_ANLG_PHY_G0, 0x64550000 */
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANA_DPLL_DUMY       SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x0000)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL0          SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x0004)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL2          SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x0008)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL3          SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x000C)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL4          SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x0010)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL5          SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x0014)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL13         SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x0018)
#define REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_REG_SEL_CFG_0       SCI_ADDR(CTL_ANLG_PHY_G0_BASE, 0x001C)

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANA_DPLL_DUMY, [0x64550000] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANALOG_DPLL_DUMY_IN(x) ( (x) << 16 & (0xFFFF0000) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_ANALOG_DPLL_DUMY_OUT(x) ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL0, [0x64550004] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_LOCK_DONE     ( BIT(18) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_N(x)          ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_ICP(x)        ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_ICP_FS(x)     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_SDM_EN        ( BIT(1) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_DIV_S         ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL2, [0x64550008] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_NINT(x)       ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_KINT(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL3, [0x6455000C] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_DIV_SEL(x)    ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CLKDIV_EN     ( BIT(13) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_IL_DIV        ( BIT(12) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CCS_CTRL(x)   ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_MOD_EN        ( BIT(3) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CLKOUT_EN     ( BIT(2) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_RST           ( BIT(1) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_PD            ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL4, [0x64550010] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CP_OFFSET(x)  ( (x) << 5  & (BIT(5)|BIT(6)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_CP_EN         ( BIT(4) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_R3_SEL(x)     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_R2_SEL(x)     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL5, [0x64550014] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_RESERVED(x)   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL_CTRL13, [0x64550018] */
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_BIST_EN       ( BIT(16) )
#define BIT_ANLG_PHY_G0_ANALOG_DPLL_TOP_DPLL0_BIST_CNT(x)   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G0_ANALOG_DPLL_TOP_REG_SEL_CFG_0, [0x6455001C] */
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_DIV_SEL ( BIT(4) )
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_CLKDIV_EN ( BIT(3) )
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_CLKOUT_EN ( BIT(2) )
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_RST   ( BIT(1) )
#define BIT_ANLG_PHY_G0_DBG_SEL_ANALOG_DPLL_TOP_DPLL0_PD    ( BIT(0) )

/* vars definitions for controller CTL_ANLG_PHY_G0 */


#endif /* __ANLG_PHY_G0_H____ */
