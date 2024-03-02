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

#ifndef __ANLG_PHY_WCN_H____
#define __ANLG_PHY_WCN_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_WCN_BASE
#define CTL_ANLG_PHY_WCN_BASE           SCI_IOMAP(0x40366000)
#endif

/* registers definitions for CTL_ANLG_PHY_WCN, 0x40366000 */
#define REG_ANLG_PHY_WCN_WCN_ADC_CLK_SEL                    SCI_ADDR(CTL_ANLG_PHY_WCN_BASE, 0x0000)
#define REG_ANLG_PHY_WCN_WCN_SYS_CFG1                       SCI_ADDR(CTL_ANLG_PHY_WCN_BASE, 0x0004)
#define REG_ANLG_PHY_WCN_WCN_SYS_CFG2                       SCI_ADDR(CTL_ANLG_PHY_WCN_BASE, 0x0008)

/* bits definitions for REG_ANLG_PHY_WCN_WCN_ADC_CLK_SEL, [0x40366000] */
#define BIT_ANLG_PHY_WCN_WCN_OSCADC_CLK_SEL                 ( BIT(1) )
#define BIT_ANLG_PHY_WCN_WCN_TSEADC_CLK_SEL                 ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_WCN_WCN_SYS_CFG1, [0x40366004] */
#define BIT_ANLG_PHY_WCN_WCN_CM4_ADDR_REMAP(x)              ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_ANLG_PHY_WCN_WCN_GNSS_CM4_ADDR_OFFSET(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )

/* bits definitions for REG_ANLG_PHY_WCN_WCN_SYS_CFG2, [0x40366008] */
#define BIT_ANLG_PHY_WCN_WCN_RD_XTAL_REQ_SEL(x)             ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_ANLG_PHY_WCN_WCN_BTWF_SYS_EN                    ( BIT(7) )
#define BIT_ANLG_PHY_WCN_WCN_GNSS_SYS_EN                    ( BIT(6) )
#define BIT_ANLG_PHY_WCN_WCN_BTWF_CM4_DBGRESTART            ( BIT(5) )
#define BIT_ANLG_PHY_WCN_WCN_BTWF_CM4_EDBGREQ               ( BIT(4) )
#define BIT_ANLG_PHY_WCN_WCN_OFFCHIP_XTRL_EN                ( BIT(3) )
#define BIT_ANLG_PHY_WCN_WCN_XTAL_DIF_SEL_H                 ( BIT(2) )
#define BIT_ANLG_PHY_WCN_WCN_GNSS_CM4_DBGRESTART            ( BIT(1) )
#define BIT_ANLG_PHY_WCN_WCN_GNSS_CM4_EDBGREQ               ( BIT(0) )

/* vars definitions for controller CTL_ANLG_PHY_WCN */


#endif /* __ANLG_PHY_WCN_H____ */
