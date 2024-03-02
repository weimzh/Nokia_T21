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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0635_cq_goodcode_202010131505/reg/ai/ai_dvfs_reg.xlsx;L6PRO DVFS APB Control Register
 *     Revision : 248562
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AI_DVFS_APB_H____
#define __AI_DVFS_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AI_DVFS_APB_BASE
#define CTL_AI_DVFS_APB_BASE            SCI_IOMAP(0x27008000)
#endif

/* registers definitions for CTL_AI_DVFS_APB, 0x27008000 */
#define REG_AI_DVFS_APB_AI_DVFS_HOLD_CTRL                   SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0000)
#define REG_AI_DVFS_APB_AI_DVFS_WAIT_WINDOW_CFG0            SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0004)
#define REG_AI_DVFS_APB_AI_MIN_VOLTAGE_CFG                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0024)
#define REG_AI_DVFS_APB_AI_SW_DVFS_CTRL                     SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0038)
#define REG_AI_DVFS_APB_AI_DVFS_FREQ_UPDATE_BYPASS0         SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0048)
#define REG_AI_DVFS_APB_CGM_AI_DVFS_CLK_GATE_CTRL           SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0050)
#define REG_AI_DVFS_APB_AI_DVFS_VOLTAE_DBG0                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0054)
#define REG_AI_DVFS_APB_AI_POWERVR_DVFS_CGM_CFG_DBG         SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0068)
#define REG_AI_DVFS_APB_AI_MAIN_MTX_DVFS_CGM_CFG_DBG        SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x006C)
#define REG_AI_DVFS_APB_AI_OCM_DVFS_CGM_CFG_DBG             SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0070)
#define REG_AI_DVFS_APB_AI_DVFS_STATE_DBG                   SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0130)
#define REG_AI_DVFS_APB_POWERVR_INDEX0_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0154)
#define REG_AI_DVFS_APB_POWERVR_INDEX1_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0158)
#define REG_AI_DVFS_APB_POWERVR_INDEX2_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x015C)
#define REG_AI_DVFS_APB_POWERVR_INDEX3_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0160)
#define REG_AI_DVFS_APB_POWERVR_INDEX4_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0164)
#define REG_AI_DVFS_APB_POWERVR_INDEX5_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0168)
#define REG_AI_DVFS_APB_POWERVR_INDEX6_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x016C)
#define REG_AI_DVFS_APB_POWERVR_INDEX7_MAP                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0170)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX0_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0174)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX1_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0178)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX2_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x017C)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX3_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0180)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX4_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0184)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX5_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0188)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX6_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x018C)
#define REG_AI_DVFS_APB_MAIN_MTX_INDEX7_MAP                 SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0190)
#define REG_AI_DVFS_APB_OCM_INDEX0_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0194)
#define REG_AI_DVFS_APB_OCM_INDEX1_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0198)
#define REG_AI_DVFS_APB_OCM_INDEX2_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x019C)
#define REG_AI_DVFS_APB_OCM_INDEX3_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x01A0)
#define REG_AI_DVFS_APB_OCM_INDEX4_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x01A4)
#define REG_AI_DVFS_APB_OCM_INDEX5_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x01A8)
#define REG_AI_DVFS_APB_OCM_INDEX6_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x01AC)
#define REG_AI_DVFS_APB_OCM_INDEX7_MAP                      SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x01B0)
#define REG_AI_DVFS_APB_POWERVR_DVFS_INDEX_CFG              SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0794)
#define REG_AI_DVFS_APB_POWERVR_DVFS_INDEX_IDLE_CFG         SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0798)
#define REG_AI_DVFS_APB_MAIN_MTX_DVFS_INDEX_CFG             SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x079C)
#define REG_AI_DVFS_APB_MAIN_MTX_DVFS_INDEX_IDLE_CFG        SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x07A0)
#define REG_AI_DVFS_APB_OCM_DVFS_INDEX_CFG                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x07A4)
#define REG_AI_DVFS_APB_OCM_DVFS_INDEX_IDLE_CFG             SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x07A8)
#define REG_AI_DVFS_APB_AI_FREQ_UPD_STATE0                  SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0924)
#define REG_AI_DVFS_APB_AI_GFREE_WAIT_DELAY_CFG0            SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0944)
#define REG_AI_DVFS_APB_AI_FREQ_UPD_TYPE_CFG0               SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x09AC)
#define REG_AI_DVFS_APB_AI_DFS_IDLE_DISABLE_CFG0            SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x09B4)
#define REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG0           SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0A58)
#define REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG1           SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0A5C)
#define REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG2           SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0A60)
#define REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG3           SCI_ADDR(CTL_AI_DVFS_APB_BASE, 0x0A64)

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_HOLD_CTRL, [0x27008000] */
#define BIT_AI_DVFS_APB_AI_DVFS_HOLD                        ( BIT(0) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_WAIT_WINDOW_CFG0, [0x27008004] */
#define BIT_AI_DVFS_APB_AI_DVFS_UP_WINDOW(x)                ( (x) << 16 & (0xFFFF0000) )
#define BIT_AI_DVFS_APB_AI_DVFS_DOWN_WINDOW(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_AI_DVFS_APB_AI_MIN_VOLTAGE_CFG, [0x27008024] */
#define BIT_AI_DVFS_APB_AI_SYS_MIN_VOLTAGE(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AI_DVFS_APB_AI_SW_DVFS_CTRL, [0x27008038] */
#define BIT_AI_DVFS_APB_AI_DVFS_ACK                         ( BIT(8) )
#define BIT_AI_DVFS_APB_AI_DVFS_VOLTAGE_SW(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AI_DVFS_APB_AI_DVFS_REQ_SW                      ( BIT(0) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_FREQ_UPDATE_BYPASS0, [0x27008048] */
#define BIT_AI_DVFS_APB_REG_OCM_FREQ_UPD_EN_BYP             ( BIT(2) )
#define BIT_AI_DVFS_APB_REG_MAIN_MTX_FREQ_UPD_EN_BYP        ( BIT(1) )
#define BIT_AI_DVFS_APB_REG_POWERVR_FREQ_UPD_EN_BYP         ( BIT(0) )

/* bits definitions for REG_AI_DVFS_APB_CGM_AI_DVFS_CLK_GATE_CTRL, [0x27008050] */
#define BIT_AI_DVFS_APB_CGM_AI_DVFS_FORCE_EN                ( BIT(1) )
#define BIT_AI_DVFS_APB_CGM_AI_DVFS_AUTO_GATE_SEL           ( BIT(0) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_VOLTAE_DBG0, [0x27008054] */
#define BIT_AI_DVFS_APB_OCM_VOLTAGE(x)                      ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AI_DVFS_APB_MAIN_MTX_VOLTAGE(x)                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AI_DVFS_APB_POWERVR_VOLTAGE(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AI_DVFS_APB_AI_INTERNAL_VOTE_VOLTAGE(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AI_DVFS_APB_AI_POWERVR_DVFS_CGM_CFG_DBG, [0x27008068] */
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_DVFS(x)             ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_DVFS(x)             ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_AI_MAIN_MTX_DVFS_CGM_CFG_DBG, [0x2700806C] */
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_DVFS(x)            ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_DVFS(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_AI_OCM_DVFS_CGM_CFG_DBG, [0x27008070] */
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_DVFS(x)                 ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_DVFS(x)                 ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_STATE_DBG, [0x27008130] */
#define BIT_AI_DVFS_APB_AI_SYS_DVFS_BUSY                    ( BIT(28) )
#define BIT_AI_DVFS_APB_AI_DVFS_WINDOW_CNT(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AI_DVFS_APB_AI_CURRENT_VOLTAGE(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AI_DVFS_APB_AI_DVFS_STATE(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX0_MAP, [0x27008154] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX0(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX0(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX0(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX1_MAP, [0x27008158] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX1(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX1(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX1(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX2_MAP, [0x2700815C] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX2(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX2(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX2(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX3_MAP, [0x27008160] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX3(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX3(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX3(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX4_MAP, [0x27008164] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX4(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX4(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX4(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX5_MAP, [0x27008168] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX5(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX5(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX5(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX6_MAP, [0x2700816C] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX6(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX6(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX6(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_INDEX7_MAP, [0x27008170] */
#define BIT_AI_DVFS_APB_POWERVR_VOL_INDEX7(x)               ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV_INDEX7(x)           ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL_INDEX7(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX0_MAP, [0x27008174] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX0(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX0(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX0(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX1_MAP, [0x27008178] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX1(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX1(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX1(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX2_MAP, [0x2700817C] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX2(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX2(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX2(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX3_MAP, [0x27008180] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX3(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX3(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX3(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX4_MAP, [0x27008184] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX4(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX4(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX4(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX5_MAP, [0x27008188] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX5(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX5(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX5(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX6_MAP, [0x2700818C] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX6(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX6(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX6(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_INDEX7_MAP, [0x27008190] */
#define BIT_AI_DVFS_APB_MAIN_MTX_VOL_INDEX7(x)              ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV_INDEX7(x)          ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL_INDEX7(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX0_MAP, [0x27008194] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX0(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX0(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX0(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX1_MAP, [0x27008198] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX1(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX1(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX1(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX2_MAP, [0x2700819C] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX2(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX2(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX2(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX3_MAP, [0x270081A0] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX3(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX3(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX3(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX4_MAP, [0x270081A4] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX4(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX4(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX4(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX5_MAP, [0x270081A8] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX5(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX5(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX5(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX6_MAP, [0x270081AC] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX6(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX6(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX6(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_INDEX7_MAP, [0x270081B0] */
#define BIT_AI_DVFS_APB_OCM_VOL_INDEX7(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_AI_DVFS_APB_CGM_OCM_DIV_INDEX7(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL_INDEX7(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_DVFS_INDEX_CFG, [0x27008794] */
#define BIT_AI_DVFS_APB_POWERVR_DVFS_INDEX(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_POWERVR_DVFS_INDEX_IDLE_CFG, [0x27008798] */
#define BIT_AI_DVFS_APB_POWERVR_DVFS_INDEX_IDLE(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_DVFS_INDEX_CFG, [0x2700879C] */
#define BIT_AI_DVFS_APB_MAIN_MTX_DVFS_INDEX(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_MAIN_MTX_DVFS_INDEX_IDLE_CFG, [0x270087A0] */
#define BIT_AI_DVFS_APB_MAIN_MTX_DVFS_INDEX_IDLE(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_DVFS_INDEX_CFG, [0x270087A4] */
#define BIT_AI_DVFS_APB_OCM_DVFS_INDEX(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_OCM_DVFS_INDEX_IDLE_CFG, [0x270087A8] */
#define BIT_AI_DVFS_APB_OCM_DVFS_INDEX_IDLE(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AI_DVFS_APB_AI_FREQ_UPD_STATE0, [0x27008924] */
#define BIT_AI_DVFS_APB_OCM_DVFS_FREQ_UPD_STATE(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AI_DVFS_APB_MAIN_MTX_DVFS_FREQ_UPD_STATE(x)     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AI_DVFS_APB_POWERVR_DVFS_FREQ_UPD_STATE(x)      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AI_DVFS_APB_AI_GFREE_WAIT_DELAY_CFG0, [0x27008944] */
#define BIT_AI_DVFS_APB_OCM_GFREE_WAIT_DELAY(x)             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AI_DVFS_APB_MAIN_MTX_GFREE_WAIT_DELAY(x)        ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AI_DVFS_APB_POWERVR_GFREE_WAIT_DELAY(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_AI_DVFS_APB_AI_FREQ_UPD_TYPE_CFG0, [0x270089AC] */
#define BIT_AI_DVFS_APB_OCM_FREQ_UPD_DELAY_EN               ( BIT(5) )
#define BIT_AI_DVFS_APB_OCM_FREQ_UPD_HDSK_EN                ( BIT(4) )
#define BIT_AI_DVFS_APB_MAIN_MTX_FREQ_UPD_DELAY_EN          ( BIT(3) )
#define BIT_AI_DVFS_APB_MAIN_MTX_FREQ_UPD_HDSK_EN           ( BIT(2) )
#define BIT_AI_DVFS_APB_POWERVR_FREQ_UPD_DELAY_EN           ( BIT(1) )
#define BIT_AI_DVFS_APB_POWERVR_FREQ_UPD_HDSK_EN            ( BIT(0) )

/* bits definitions for REG_AI_DVFS_APB_AI_DFS_IDLE_DISABLE_CFG0, [0x270089B4] */
#define BIT_AI_DVFS_APB_AI_OCM_DFS_IDLE_DISABLE             ( BIT(2) )
#define BIT_AI_DVFS_APB_AI_MAIN_MTX_DFS_IDLE_DISABLE        ( BIT(1) )
#define BIT_AI_DVFS_APB_AI_POWERVR_DFS_IDLE_DISABLE         ( BIT(0) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG0, [0x27008A58] */
#define BIT_AI_DVFS_APB_CGM_OCM_DIV(x)                      ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AI_DVFS_APB_CGM_OCM_SEL(x)                      ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_DIV(x)                 ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)) )
#define BIT_AI_DVFS_APB_CGM_MAIN_MTX_SEL(x)                 ( (x) << 5  & (BIT(5)|BIT(6)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_DIV(x)                  ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_AI_DVFS_APB_CGM_POWERVR_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG1, [0x27008A5C] */
#define BIT_AI_DVFS_APB_DVFS_RES_REG1(x)                    ( (x) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG2, [0x27008A60] */
#define BIT_AI_DVFS_APB_DVFS_RES_REG2(x)                    ( (x) )

/* bits definitions for REG_AI_DVFS_APB_AI_DVFS_RESERVED_REG_CFG3, [0x27008A64] */
#define BIT_AI_DVFS_APB_DVFS_RES_REG3(x)                    ( (x) )

/* vars definitions for controller CTL_AI_DVFS_APB */


#endif /* __AI_DVFS_APB_H____ */
