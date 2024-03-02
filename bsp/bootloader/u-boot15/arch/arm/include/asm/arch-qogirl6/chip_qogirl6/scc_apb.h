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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/AON_SYS/SharkL6 AON SCC Control Register.xls;AON_AVS
 *     Revision : 229870
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __SCC_APB_H____
#define __SCC_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_SCC_APB_BASE
#define CTL_SCC_APB_BASE                SCI_IOMAP(0x64730000)
#endif

/* registers definitions for CTL_SCC_APB, 0x64730000 */
#define REG_SCC_APB_SCC_TUNE_LMT_CFG                        SCI_ADDR(CTL_SCC_APB_BASE, 0x0000)
#define REG_SCC_APB_SCC_TUNE_STATUS                         SCI_ADDR(CTL_SCC_APB_BASE, 0x0004)
#define REG_SCC_APB_SCC_CFG                                 SCI_ADDR(CTL_SCC_APB_BASE, 0x0008)
#define REG_SCC_APB_SCC_TUNE_STEP_CFG                       SCI_ADDR(CTL_SCC_APB_BASE, 0x000C)
#define REG_SCC_APB_SCC_WAIT_CFG                            SCI_ADDR(CTL_SCC_APB_BASE, 0x0010)
#define REG_SCC_APB_SCC_INT_CFG                             SCI_ADDR(CTL_SCC_APB_BASE, 0x0014)
#define REG_SCC_APB_SCC_TUNE_MARK                           SCI_ADDR(CTL_SCC_APB_BASE, 0x0024)
#define REG_SCC_APB_SCC_FSM_STS                             SCI_ADDR(CTL_SCC_APB_BASE, 0x0028)
#define REG_SCC_APB_SCC_ROSC_MODE                           SCI_ADDR(CTL_SCC_APB_BASE, 0x0100)
#define REG_SCC_APB_SCC_ROSC_CFG                            SCI_ADDR(CTL_SCC_APB_BASE, 0x0104)
#define REG_SCC_APB_SCC_ROSC_CTRL                           SCI_ADDR(CTL_SCC_APB_BASE, 0x0108)
#define REG_SCC_APB_SCC_ROSC_RPT                            SCI_ADDR(CTL_SCC_APB_BASE, 0x010C)
#define REG_SCC_APB_SCC_ROSC_SW_RST                         SCI_ADDR(CTL_SCC_APB_BASE, 0x0110)

/* bits definitions for REG_SCC_APB_SCC_TUNE_LMT_CFG, [0x64730000] */
#define BIT_SCC_APB_VOLT_TUNE_VAL_MAX(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_SCC_APB_VOLT_TUNE_VAL_MIN(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_SCC_APB_SCC_TUNE_STATUS, [0x64730004] */
#define BIT_SCC_APB_VOLT_TUNE_VAL(x)                        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_SCC_APB_VOLT_OBS_VAL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_SCC_APB_SCC_CFG, [0x64730008] */
#define BIT_SCC_APB_VOLT0_SELECT_OVERRIDE                   ( BIT(31) )
#define BIT_SCC_APB_VOLT1_SELECT_OVERRIDE                   ( BIT(30) )
#define BIT_SCC_APB_PAUSE_OCCUR_ERR_EN                      ( BIT(8) )
#define BIT_SCC_APB_VOLT_TUNE_FORBID_EN                     ( BIT(4) )
#define BIT_SCC_APB_VOLT_OBS_FORBID_EN                      ( BIT(0) )

/* bits definitions for REG_SCC_APB_SCC_TUNE_STEP_CFG, [0x6473000C] */
#define BIT_SCC_APB_VOLT_TUNE_DOWN_STEP(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_SCC_APB_VOLT_TUNE_UP_STEP(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_SCC_APB_SCC_WAIT_CFG, [0x64730010] */
#define BIT_SCC_APB_RND_INTVAL_WAIT_NUM(x)                  ( (x) << 16 & (0xFFFF0000) )
#define BIT_SCC_APB_VOLT_STB_WAIT_NUM(x)                    ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_SCC_APB_SCC_INT_CFG, [0x64730014] */
#define BIT_SCC_APB_SCC_TUNE_DONE_INT_MASK_STATUS           ( BIT(13) )
#define BIT_SCC_APB_SCC_TUNE_ERR_INT_MASK_STATUS            ( BIT(12) )
#define BIT_SCC_APB_SCC_TUNE_DONE_INT_RAW_STATUS            ( BIT(9) )
#define BIT_SCC_APB_SCC_TUNE_ERR_INT_RAW_STATUS             ( BIT(8) )
#define BIT_SCC_APB_SCC_TUNE_DONE_INT_CLR                   ( BIT(5) )
#define BIT_SCC_APB_SCC_TUNE_ERR_INT_CLR                    ( BIT(4) )
#define BIT_SCC_APB_SCC_TUNE_DONE_INT_EN                    ( BIT(1) )
#define BIT_SCC_APB_SCC_TUNE_ERR_INT_EN                     ( BIT(0) )

/* bits definitions for REG_SCC_APB_SCC_TUNE_MARK, [0x64730024] */
#define BIT_SCC_APB_SCC_TUNE_DWN_MARK(x)                    ( (x) << 16 & (0xFFFF0000) )
#define BIT_SCC_APB_SCC_TUNE_UP_MARK(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_SCC_APB_SCC_FSM_STS, [0x64730028] */
#define BIT_SCC_APB_SCC_FSM_STS(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_SCC_APB_SCC_ROSC_MODE, [0x64730100] */
#define BIT_SCC_APB_SCC_IDLE_MODE                           ( BIT(31) )
#define BIT_SCC_APB_SCC_TUNE_BYPASS                         ( BIT(30) )
#define BIT_SCC_APB_SCC_INIT_HALT_BYPASS                    ( BIT(29) )
#define BIT_SCC_APB_SCC_AM_CLK_DIVIDER(x)                   ( (x) << 27 & (BIT(27)|BIT(28)) )
#define BIT_SCC_APB_SCC_AM_ENABLE                           ( BIT(26) )
#define BIT_SCC_APB_SCC_AM_OBS_EN                           ( BIT(25) )
#define BIT_SCC_APB_SCC_RPT_READ_CTRL                       ( BIT(12) )
#define BIT_SCC_APB_SCC_ALL_ROSC_CHAIN                      ( BIT(2) )
#define BIT_SCC_APB_SCC_ALL_ROSC_SEQ                        ( BIT(1) )
#define BIT_SCC_APB_SCC_ROSC_REPEAT_MODE                    ( BIT(0) )

/* bits definitions for REG_SCC_APB_SCC_ROSC_CFG, [0x64730104] */
#define BIT_SCC_APB_SCC_ROSC_DURATION(x)                    ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_SCC_APB_SCC_ROSC_SEL_Z(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_SCC_APB_SCC_ROSC_SEL_Y(x)                       ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_SCC_APB_SCC_ROSC_SEL_X(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_SCC_APB_SCC_ROSC_CTRL, [0x64730108] */
#define BIT_SCC_APB_SCC_RPT_READ_NXT                        ( BIT(31) )
#define BIT_SCC_APB_SCC_ROSC_GR_ENABLE                      ( BIT(1) )
#define BIT_SCC_APB_SCC_ROSC_RUN                            ( BIT(0) )

/* bits definitions for REG_SCC_APB_SCC_ROSC_RPT, [0x6473010C] */
#define BIT_SCC_APB_SCC_INIT_PAT_FAIL                       ( BIT(31) )
#define BIT_SCC_APB_SCC_ROSC_RPT_VALID                      ( BIT(30) )
#define BIT_SCC_APB_SCC_ROSC_SETTING(x)                     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_SCC_APB_SCC_ROSC_CNT(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_SCC_APB_SCC_ROSC_SW_RST, [0x64730110] */
#define BIT_SCC_APB_SCC_ROSC_SW_RST(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* vars definitions for controller CTL_SCC_APB */


#endif /* __SCC_APB_H____ */
