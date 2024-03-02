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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/gpu/gpu_dvfs_reg.xlsx;L6PRO DVFS APB Control Register
 *     Revision : 231409
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
#define REG_GPU_DVFS_APB_GPU_DVFS_WAIT_WINDOW_CFG0          SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0004)
#define REG_GPU_DVFS_APB_GPU_MIN_VOLTAGE_CFG                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0024)
#define REG_GPU_DVFS_APB_GPU_SW_DVFS_CTRL                   SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0038)
#define REG_GPU_DVFS_APB_GPU_DVFS_FREQ_UPDATE_BYPASS0       SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0048)
#define REG_GPU_DVFS_APB_CGM_GPU_DVFS_CLK_GATE_CTRL         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0050)
#define REG_GPU_DVFS_APB_GPU_DVFS_VOLTAE_DBG0               SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0054)
#define REG_GPU_DVFS_APB_GPU_GPU_DVFS_CGM_CFG_DBG           SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0068)
#define REG_GPU_DVFS_APB_GPU_DVFS_STATE_DBG                 SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0130)
#define REG_GPU_DVFS_APB_GPU_INDEX0_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0154)
#define REG_GPU_DVFS_APB_GPU_INDEX1_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0158)
#define REG_GPU_DVFS_APB_GPU_INDEX2_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x015C)
#define REG_GPU_DVFS_APB_GPU_INDEX3_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0160)
#define REG_GPU_DVFS_APB_GPU_INDEX4_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0164)
#define REG_GPU_DVFS_APB_GPU_INDEX5_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0168)
#define REG_GPU_DVFS_APB_GPU_INDEX6_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x016C)
#define REG_GPU_DVFS_APB_GPU_INDEX7_MAP                     SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0170)
#define REG_GPU_DVFS_APB_GPU_DVFS_INDEX_CFG                 SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0794)
#define REG_GPU_DVFS_APB_GPU_DVFS_INDEX_IDLE_CFG            SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0798)
#define REG_GPU_DVFS_APB_GPU_FREQ_UPD_STATE0                SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0924)
#define REG_GPU_DVFS_APB_GPU_GFREE_WAIT_DELAY_CFG0          SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0944)
#define REG_GPU_DVFS_APB_GPU_FREQ_UPD_TYPE_CFG0             SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x09AC)
#define REG_GPU_DVFS_APB_GPU_DFS_IDLE_DISABLE_CFG0          SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x09B4)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG0         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0A58)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG1         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0A5C)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG2         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0A60)
#define REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG3         SCI_ADDR(CTL_GPU_DVFS_APB_BASE, 0x0A64)

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_HOLD_CTRL, [0x23014000] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_HOLD                      ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_WAIT_WINDOW_CFG0, [0x23014004] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_UP_WINDOW(x)              ( (x) << 16 & (0xFFFF0000) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_DOWN_WINDOW(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_MIN_VOLTAGE_CFG, [0x23014024] */
#define BIT_GPU_DVFS_APB_GPU_SYS_MIN_VOLTAGE(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_SW_DVFS_CTRL, [0x23014038] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_ACK                       ( BIT(8) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_VOLTAGE_SW(x)             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_REQ_SW                    ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_FREQ_UPDATE_BYPASS0, [0x23014048] */
#define BIT_GPU_DVFS_APB_REG_GPU_FREQ_UPD_EN_BYP            ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_CGM_GPU_DVFS_CLK_GATE_CTRL, [0x23014050] */
#define BIT_GPU_DVFS_APB_CGM_GPU_DVFS_FORCE_EN              ( BIT(1) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DVFS_AUTO_GATE_SEL         ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_VOLTAE_DBG0, [0x23014054] */
#define BIT_GPU_DVFS_APB_GPU_VOLTAGE(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_DVFS_APB_GPU_INTERNAL_VOTE_VOLTAGE(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_GPU_DVFS_CGM_CFG_DBG, [0x23014068] */
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_DVFS(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_DVFS(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_STATE_DBG, [0x23014130] */
#define BIT_GPU_DVFS_APB_GPU_SYS_DVFS_BUSY                  ( BIT(28) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_WINDOW_CNT(x)             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_GPU_DVFS_APB_GPU_CURRENT_VOLTAGE(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_GPU_DVFS_APB_GPU_DVFS_STATE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX0_MAP, [0x23014154] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX0(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX0(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX0(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX1_MAP, [0x23014158] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX1(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX1(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX1(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX2_MAP, [0x2301415C] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX2(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX2(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX2(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX3_MAP, [0x23014160] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX3(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX3(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX3(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX4_MAP, [0x23014164] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX4(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX4(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX4(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX5_MAP, [0x23014168] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX5(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX5(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX5(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX6_MAP, [0x2301416C] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX6(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX6(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX6(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_INDEX7_MAP, [0x23014170] */
#define BIT_GPU_DVFS_APB_GPU_VOL_INDEX7(x)                  ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_DIV_INDEX7(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_GPU_DVFS_APB_CGM_GPU_SEL_INDEX7(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_INDEX_CFG, [0x23014794] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_INDEX(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_INDEX_IDLE_CFG, [0x23014798] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_INDEX_IDLE(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_FREQ_UPD_STATE0, [0x23014924] */
#define BIT_GPU_DVFS_APB_GPU_DVFS_FREQ_UPD_STATE(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_GFREE_WAIT_DELAY_CFG0, [0x23014944] */
#define BIT_GPU_DVFS_APB_GPU_GFREE_WAIT_DELAY(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_FREQ_UPD_TYPE_CFG0, [0x230149AC] */
#define BIT_GPU_DVFS_APB_GPU_FREQ_UPD_DELAY_EN              ( BIT(1) )
#define BIT_GPU_DVFS_APB_GPU_FREQ_UPD_HDSK_EN               ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DFS_IDLE_DISABLE_CFG0, [0x230149B4] */
#define BIT_GPU_DVFS_APB_GPU_GPU_DFS_IDLE_DISABLE           ( BIT(0) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG0, [0x23014A58] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG0(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG1, [0x23014A5C] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG1(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG2, [0x23014A60] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG2(x)                   ( (x) )

/* bits definitions for REG_GPU_DVFS_APB_GPU_DVFS_RESERVED_REG_CFG3, [0x23014A64] */
#define BIT_GPU_DVFS_APB_DVFS_RES_REG3(x)                   ( (x) )

/* vars definitions for controller CTL_GPU_DVFS_APB */


#endif /* __GPU_DVFS_APB_H____ */
