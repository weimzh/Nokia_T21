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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/SHARKL6_RTL_0.5_DV_00/DVFS/SharkL6 GPU DVFS Control Register.xlsx;Sheet1
 *     Revision : 205295
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __GPU_DVFS_APB_H____
#define __GPU_DVFS_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_GPU_DVFS_APB_BASE
#define CTL_GPU_DVFS_APB_BASE           SCI_IOMAP(0x23014000)
#endif

/* registers definitions for CTL_GPU_DVFS_APB, 0x23014000 */
#define REG_GPU_DVFS_APB_GPU_DVFS_HOLD_CTRL                 SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0000)
#define REG_GPU_DVFS_APB_GPU_MIN_VOLTAGE_CFG                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0010)
#define REG_GPU_DVFS_APB_GPU_SW_DVFS_CTRL                   SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0020)
#define REG_GPU_DVFS_APB_GPU_FREQ_UPDATE_BYPASS             SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0024)
#define REG_GPU_DVFS_APB_CGM_GPU_DVFS_CLK_GATE_CTRL         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0028)
#define REG_GPU_DVFS_APB_GPU_DVFS_VOLTAGE_DBG               SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x002C)
#define REG_GPU_DVFS_APB_GPU_DVFS_CGM_CFG_DBG               SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0034)
#define REG_GPU_DVFS_APB_GPU_DVFS_STATE_DBG                 SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0038)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX0_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0048)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX1_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x004C)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX2_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0050)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX3_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0054)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX4_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0058)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX5_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x005C)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX6_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0060)
#define REG_GPU_DVFS_APB_GPU_CORE_INDEX7_MAP                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0064)
#define REG_GPU_DVFS_APB_GPU_DVFS_INDEX_CFG                 SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x008C)
#define REG_GPU_DVFS_APB_GPU_CORE_DVFS_INDEX_IDLE_CFG       SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0090)
#define REG_GPU_DVFS_APB_GPU_FREQ_UPD_STATE                 SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0098)
#define REG_GPU_DVFS_APB_GPU_GFREE_WAIT_DELAY_CFG           SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x009C)
#define REG_GPU_DVFS_APB_GPU_FREQ_UPD_TYPE_CFG              SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00A4)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG0         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00A8)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG1         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00AC)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG2         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00B0)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG3         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00B4)
#define REG_GPU_DVFS_APB_GPU_DVFS_WAIT_WINDOW_CFG2          SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00C0)
#define REG_GPU_DVFS_APB_GPU_DFS_IDLE_DISABLE_CFG           SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00D0)
#define REG_GPU_DVFS_APB_GPU_DVFS_VOL_CTRL                  SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x00D4)

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_HOLD_CTRL, [0x23014000] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_HOLD                      ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_MIN_VOLTAGE_CFG, [0x23014010] */
#define BIT_GPU_DVFS_APB_GPU_TOP_MIN_VOLTAGE(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_SW_DVFS_CTRL, [0x23014020] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_ACK                       ( BIT(8) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_VOLTAGE_SW(x)             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_GPU_DVFS_APB_GPU_CURRENT_VOLTAGE_SW(x)          ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_REQ_SW                    ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_FREQ_UPDATE_BYPASS, [0x23014024] */
#define BIT_GPU_DVFS_APB_REG_GPU_CORE_FREQ_UPD_EN_BYP       ( BIT(2) )

/* bits definitions for REG_GPU_DVFS_APB_CGM_GPU_DVFS_CLK_GATE_CTRL, [0x23014028] */
#define BIT_GPU_DVFS_APB_CGM_GPU_DVFS_FORCE_EN              ( BIT(1) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DVFS_AUTO_GATE_SEL         ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_VOLTAGE_DBG, [0x2301402C] */
#define BIT_GPU_DVFS_APB_GPU_CURRENT_VOLTAGE(x)             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_GPU_DVFS_APB_GPU_INTERNAL_VOTE_VOLTAGE(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_CGM_CFG_DBG, [0x23014034] */
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_DVFS(x)           ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_DVFS(x)           ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_DVFS(x)            ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_DVFS(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_STATE_DBG, [0x23014038] */
#define BIT_GPU_DVFS_APB_GPU_TOP_DVFS_BUSY                  ( BIT(19) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_WINDOW_CNT(x)             ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_STATE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX0_MAP, [0x23014048] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX0(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX0(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX0(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX0(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX0(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX1_MAP, [0x2301404C] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX1(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX1(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX1(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX1(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX1(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX2_MAP, [0x23014050] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX2(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX2(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX2(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX2(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX2(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX3_MAP, [0x23014054] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX3(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX3(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX3(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX3(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX3(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX4_MAP, [0x23014058] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX4(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX4(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX4(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX4(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX4(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX5_MAP, [0x2301405C] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX5(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX5(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX5(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX5(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX5(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX6_MAP, [0x23014060] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX6(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX6(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX6(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX6(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX6(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_INDEX7_MAP, [0x23014064] */
#define BIT_GPU_DVFS_APB_CGM_GPU_SYS_DIV_INDEX7(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_MEM_DIV_INDEX7(x)          ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_GPU_DVFS_APB_GPU_CORE_VOL_INDEX7(x)             ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_DIV_INDEX7(x)         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_CORE_SEL_INDEX7(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_INDEX_CFG, [0x2301408C] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_INDEX(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_CORE_DVFS_INDEX_IDLE_CFG, [0x23014090] */
#define BIT_GPU_DVFS_APB_GPU_CORE_DVFS_INDEX_IDLE(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_FREQ_UPD_STATE, [0x23014098] */
#define BIT_GPU_DVFS_APB_GPU_CORE_DVFS_FREQ_UPD_STATE(x)    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_GFREE_WAIT_DELAY_CFG, [0x2301409C] */
#define BIT_GPU_DVFS_APB_GPU_CORE_GFREE_WAIT_DELAY(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_FREQ_UPD_TYPE_CFG, [0x230140A4] */
#define BIT_GPU_DVFS_APB_GPU_CORE_FREQ_UPD_DELAY_EN         ( BIT(1) )
#define BIT_GPU_DVFS_APB_GPU_CORE_FREQ_UPD_HDSK_EN          ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG0, [0x230140A8] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG0(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG1, [0x230140AC] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG1(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG2, [0x230140B0] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG2(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG3, [0x230140B4] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG3(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_WAIT_WINDOW_CFG2, [0x230140C0] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_UP_WINDOW(x)              ( (x) << 16 & (0xFFFF0000) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_DOWN_WINDOW(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DFS_IDLE_DISABLE_CFG, [0x230140D0] */
#define BIT_GPU_DVFS_APB_GPU_CORE_DFS_IDLE_DISABLE          ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_VOL_CTRL, [0x230140D4] */
#define BIT_GPU_DVFS_APB_VOL_DOWN_EARLY_UPD_EN              ( BIT(0) )

/* vars definitions for controller CTL_GPU_DVFS_APB */


#endif /* __GPU_DVFS_APB_H____ */
