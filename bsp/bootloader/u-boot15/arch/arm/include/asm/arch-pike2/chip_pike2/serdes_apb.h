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

#ifndef __SERDES_APB_H____
#define __SERDES_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_SERDES_APB_BASE
#define CTL_SERDES_APB_BASE             SCI_IOMAP(0x40470000)
#endif

/* registers definitions for CTL_SERDES_APB, 0x40470000 */
#define REG_SERDES_APB_FUNC_EN                              SCI_ADDR(CTL_SERDES_APB_BASE, 0x0000)
#define REG_SERDES_APB_CH_EN                                SCI_ADDR(CTL_SERDES_APB_BASE, 0x0004)
#define REG_SERDES_APB_FUNNEL_EN                            SCI_ADDR(CTL_SERDES_APB_BASE, 0x0008)
#define REG_SERDES_APB_FUNNEL_OVERFLOW                      SCI_ADDR(CTL_SERDES_APB_BASE, 0x000C)
#define REG_SERDES_APB_FSM_CUT_OFF_LEN                      SCI_ADDR(CTL_SERDES_APB_BASE, 0x0010)

/* bits definitions for REG_SERDES_APB_FUNC_EN, [0x40470000] */
#define BIT_SERDES_APB_FUNC_EN_FUNC_EN                  ( BIT(0) )

/* bits definitions for REG_SERDES_APB_CH_EN, [0x40470004] */
#define BIT_SERDES_APB_CH_EN_CH_EN(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_SERDES_APB_FUNNEL_EN, [0x40470008] */
#define BIT_SERDES_APB_FUNNEL_EN_FUNNEL_EN              ( BIT(0) )

/* bits definitions for REG_SERDES_APB_FUNNEL_OVERFLOW, [0x4047000C] */
#define BIT_SERDES_APB_FUNNEL_OVERFLOW_FUNNEL_OVERFLOW  ( BIT(0) )

/* bits definitions for REG_SERDES_APB_FSM_CUT_OFF_LEN, [0x40470010] */
#define BIT_SERDES_APB_FSM_CUT_OFF_LEN_FSM_CUT_OFF(x)   ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_SERDES_APB */


#endif /* __SERDES_APB_H____ */
