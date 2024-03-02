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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/SHARKL6_RTL_0.5_DV_00/DVFS/SharkL6 AP DVFS Control Register.xlsx;Sheet1
 *     Revision : 206109
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AP_DVFS_APB_H____
#define __AP_DVFS_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AP_DVFS_APB_BASE
#define CTL_AP_DVFS_APB_BASE            SCI_IOMAP(0x20014000)
#endif

/* registers definitions for CTL_AP_DVFS_APB, 0x20014000 */
#define REG_AP_DVFS_APB_AP_DVFS_HOLD_CTRL                   SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0000)
#define REG_AP_DVFS_APB_AP_DVFS_WAIT_WINDOW_CFG             SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0004)
#define REG_AP_DVFS_APB_AP_DFS_EN_CTRL                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0008)
#define REG_AP_DVFS_APB_AP_SW_TRIG_CTRL                     SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x000C)
#define REG_AP_DVFS_APB_AP_MIN_VOLTAGE_CFG                  SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0010)
#define REG_AP_DVFS_APB_AP_SW_DVFS_CTRL                     SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0034)
#define REG_AP_DVFS_APB_AP_FREQ_UPDATE_BYPASS               SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0038)
#define REG_AP_DVFS_APB_CGM_AP_DVFS_CLK_GATE_CTRL           SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x003C)
#define REG_AP_DVFS_APB_AP_DVFS_VOLTAGE_DBG                 SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0040)
#define REG_AP_DVFS_APB_AP_DVFS_CGM_CFG_DBG                 SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x004C)
#define REG_AP_DVFS_APB_AP_DVFS_STATE_DBG                   SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0050)
#define REG_AP_DVFS_APB_VSP_INDEX0_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0074)
#define REG_AP_DVFS_APB_VSP_INDEX1_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0078)
#define REG_AP_DVFS_APB_VSP_INDEX2_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x007C)
#define REG_AP_DVFS_APB_VSP_INDEX3_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0080)
#define REG_AP_DVFS_APB_VSP_INDEX4_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0084)
#define REG_AP_DVFS_APB_VSP_INDEX5_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0088)
#define REG_AP_DVFS_APB_VSP_INDEX6_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x008C)
#define REG_AP_DVFS_APB_VSP_INDEX7_MAP                      SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0090)
#define REG_AP_DVFS_APB_DISPC_INDEX0_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0094)
#define REG_AP_DVFS_APB_DISPC_INDEX1_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0098)
#define REG_AP_DVFS_APB_DISPC_INDEX2_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x009C)
#define REG_AP_DVFS_APB_DISPC_INDEX3_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0100)
#define REG_AP_DVFS_APB_DISPC_INDEX4_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0104)
#define REG_AP_DVFS_APB_DISPC_INDEX5_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0108)
#define REG_AP_DVFS_APB_DISPC_INDEX6_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x010C)
#define REG_AP_DVFS_APB_DISPC_INDEX7_MAP                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0110)
#define REG_AP_DVFS_APB_VSP_DVFS_INDEX_CFG                  SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x011C)
#define REG_AP_DVFS_APB_VSP_DVFS_INDEX_IDLE_CFG             SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0120)
#define REG_AP_DVFS_APB_DISPC_DVFS_INDEX_CFG                SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0124)
#define REG_AP_DVFS_APB_DISPC_DVFS_INDEX_IDLE_CFG           SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0128)
#define REG_AP_DVFS_APB_AP_FREQ_UPD_STATE                   SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x012C)
#define REG_AP_DVFS_APB_AP_GFREE_WAIT_DELAY_CFG             SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0130)
#define REG_AP_DVFS_APB_AP_FREQ_UPD_TYPE_CFG                SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0134)
#define REG_AP_DVFS_APB_AP_DFS_IDLE_DISABLE_CFG             SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0140)
#define REG_AP_DVFS_APB_AP_DVFS_VOL_CTRL                    SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0144)
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG0           SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0150)
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG1           SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0154)
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG2           SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x0158)
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG3           SCI_ADDR(CTL_AP_DVFS_APB_BASE, 0x015C)

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_HOLD_CTRL, [0x20014000] */
#define BIT_AP_DVFS_APB_AP_DVFS_HOLD                        ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_WAIT_WINDOW_CFG, [0x20014004] */
#define BIT_AP_DVFS_APB_AP_DVFS_UP_WINDOW(x)                ( (x) << 16 & (0xFFFF0000) )
#define BIT_AP_DVFS_APB_AP_DVFS_DOWN_WINDOW(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AP_DVFS_APB_AP_DFS_EN_CTRL, [0x20014008] */
#define BIT_AP_DVFS_APB_VSP_DFS_EN                          ( BIT(1) )
#define BIT_AP_DVFS_APB_DISPC_DFS_EN                        ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_AP_SW_TRIG_CTRL, [0x2001400C] */
#define BIT_AP_DVFS_APB_VSP_DFS_SW_TRIG                     ( BIT(1) )
#define BIT_AP_DVFS_APB_DISPC_DFS_SW_TRIG                   ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_AP_MIN_VOLTAGE_CFG, [0x20014010] */
#define BIT_AP_DVFS_APB_AP_SYS_MIN_VOLTAGE(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_AP_SW_DVFS_CTRL, [0x20014034] */
#define BIT_AP_DVFS_APB_AP_DVFS_ACK                         ( BIT(8) )
#define BIT_AP_DVFS_APB_AP_DVFS_VOLTAGE_SW(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AP_DVFS_APB_AP_CURRENT_VOLTAGE_SW(x)            ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_AP_DVFS_APB_AP_DVFS_REQ_SW                      ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_AP_FREQ_UPDATE_BYPASS, [0x20014038] */
#define BIT_AP_DVFS_APB_REG_VSP_FREQ_UPD_EN_BYP             ( BIT(1) )
#define BIT_AP_DVFS_APB_REG_DISPC_FREQ_UPD_EN_BYP           ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_CGM_AP_DVFS_CLK_GATE_CTRL, [0x2001403C] */
#define BIT_AP_DVFS_APB_CGM_AP_DVFS_FORCE_EN                ( BIT(1) )
#define BIT_AP_DVFS_APB_CGM_AP_DVFS_AUTO_GATE_SEL           ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_VOLTAGE_DBG, [0x20014040] */
#define BIT_AP_DVFS_APB_AP_CURRENT_VOLTAGE(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AP_DVFS_APB_VSP_VOLTAGE(x)                      ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AP_DVFS_APB_DISPC_VOLTAGE(x)                    ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_AP_INTERNAL_VOTE_VOLTAGE(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_CGM_CFG_DBG, [0x2001404C] */
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_DVFS(x)                 ( (x) << 3  & (BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_DVFS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_STATE_DBG, [0x20014050] */
#define BIT_AP_DVFS_APB_AP_SYS_DVFS_BUSY                    ( BIT(19) )
#define BIT_AP_DVFS_APB_AP_DVFS_WINDOW_CNT(x)               ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_AP_DVFS_APB_AP_DVFS_STATE(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX0_MAP, [0x20014074] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX0(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX0(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX1_MAP, [0x20014078] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX1(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX1(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX2_MAP, [0x2001407C] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX2(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX2(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX3_MAP, [0x20014080] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX3(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX3(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX4_MAP, [0x20014084] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX4(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX4(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX5_MAP, [0x20014088] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX5(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX5(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX6_MAP, [0x2001408C] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX6(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX6(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_INDEX7_MAP, [0x20014090] */
#define BIT_AP_DVFS_APB_VSP_VOL_INDEX7(x)                   ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX7(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX0_MAP, [0x20014094] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX0(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX0(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX1_MAP, [0x20014098] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX1(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX1(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX2_MAP, [0x2001409C] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX2(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX2(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX3_MAP, [0x20014100] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX3(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX3(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX4_MAP, [0x20014104] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX4(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX4(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX5_MAP, [0x20014108] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX5(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX5(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX6_MAP, [0x2001410C] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX6(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX6(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_INDEX7_MAP, [0x20014110] */
#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX7(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX7(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_DVFS_INDEX_CFG, [0x2001411C] */
#define BIT_AP_DVFS_APB_VSP_DVFS_INDEX(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_VSP_DVFS_INDEX_IDLE_CFG, [0x20014120] */
#define BIT_AP_DVFS_APB_VSP_DVFS_INDEX_IDLE(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_DVFS_INDEX_CFG, [0x20014124] */
#define BIT_AP_DVFS_APB_DISPC_DVFS_INDEX(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_DISPC_DVFS_INDEX_IDLE_CFG, [0x20014128] */
#define BIT_AP_DVFS_APB_DISPC_DVFS_INDEX_IDLE(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AP_DVFS_APB_AP_FREQ_UPD_STATE, [0x2001412C] */
#define BIT_AP_DVFS_APB_DISPC_DVFS_FREQ_UPD_STATE(x)        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AP_DVFS_APB_VSP_DVFS_FREQ_UPD_STATE(x)          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AP_DVFS_APB_AP_GFREE_WAIT_DELAY_CFG, [0x20014130] */
#define BIT_AP_DVFS_APB_DISPC_GFREE_WAIT_DELAY(x)           ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AP_DVFS_APB_VSP_GFREE_WAIT_DELAY(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_AP_DVFS_APB_AP_FREQ_UPD_TYPE_CFG, [0x20014134] */
#define BIT_AP_DVFS_APB_DISPC_FREQ_UPD_DELAY_EN             ( BIT(5) )
#define BIT_AP_DVFS_APB_DISPC_FREQ_UPD_HDSK_EN              ( BIT(4) )
#define BIT_AP_DVFS_APB_VSP_FREQ_UPD_DELAY_EN               ( BIT(3) )
#define BIT_AP_DVFS_APB_VSP_FREQ_UPD_HDSK_EN                ( BIT(2) )

/* bits definitions for REG_AP_DVFS_APB_AP_DFS_IDLE_DISABLE_CFG, [0x20014140] */
#define BIT_AP_DVFS_APB_AP_DISPC_DFS_IDLE_DISABLE           ( BIT(2) )
#define BIT_AP_DVFS_APB_AP_VSP_DFS_IDLE_DISABLE             ( BIT(1) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_VOL_CTRL, [0x20014144] */
#define BIT_AP_DVFS_APB_VOL_DOWN_EARLY_UPD_EN               ( BIT(0) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG0, [0x20014150] */
#define BIT_AP_DVFS_APB_DVFS_RES_REG0(x)                    ( (x) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG1, [0x20014154] */
#define BIT_AP_DVFS_APB_DVFS_RES_REG1(x)                    ( (x) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG2, [0x20014158] */
#define BIT_AP_DVFS_APB_DVFS_RES_REG2(x)                    ( (x) )

/* bits definitions for REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG3, [0x2001415C] */
#define BIT_AP_DVFS_APB_DVFS_RES_REG3(x)                    ( (x) )

/* vars definitions for controller CTL_AP_DVFS_APB */


#endif /* __AP_DVFS_APB_H____ */
