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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/SHARKL6_RTL_0.5_DV_00/DVFS/SharkL6 MM DVFS Control Register.xlsx;Sheet1
 *     Revision : 205295
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __MM_DVFS_AHB_H____
#define __MM_DVFS_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_MM_DVFS_AHB_BASE
#define CTL_MM_DVFS_AHB_BASE            SCI_IOMAP(0x30014000)
#endif

/* registers definitions for CTL_MM_DVFS_AHB, 0x30014000 */
#define REG_MM_DVFS_AHB_MM_DVFS_HOLD_CTRL                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0000)
#define REG_MM_DVFS_AHB_MM_DVFS_WAIT_WINDOW_CFG             SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0004)
#define REG_MM_DVFS_AHB_MM_DFS_EN_CTRL                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0008)
#define REG_MM_DVFS_AHB_MM_DFS_SW_TRIG_CFG                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x000C)
#define REG_MM_DVFS_AHB_MM_MIN_VOLTAGE_CFG                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0010)
#define REG_MM_DVFS_AHB_MM_SW_DVFS_CTRL                     SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x002C)
#define REG_MM_DVFS_AHB_MM_FREQ_UPDATE_BYPASS               SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0030)
#define REG_MM_DVFS_AHB_CGM_MM_DVFS_CLK_GATE_CTRL           SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0034)
#define REG_MM_DVFS_AHB_MM_DVFS_VOLTAGE_DBG                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0038)
#define REG_MM_DVFS_AHB_MM_DVFS_CGM_CFG_DBG                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0048)
#define REG_MM_DVFS_AHB_MM_DVFS_STATE_DBG                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x004C)
#define REG_MM_DVFS_AHB_ISP_INDEX0_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0050)
#define REG_MM_DVFS_AHB_ISP_INDEX1_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0054)
#define REG_MM_DVFS_AHB_ISP_INDEX2_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0058)
#define REG_MM_DVFS_AHB_ISP_INDEX3_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x005C)
#define REG_MM_DVFS_AHB_ISP_INDEX4_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0060)
#define REG_MM_DVFS_AHB_ISP_INDEX5_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0064)
#define REG_MM_DVFS_AHB_ISP_INDEX6_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0068)
#define REG_MM_DVFS_AHB_ISP_INDEX7_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x006C)
#define REG_MM_DVFS_AHB_JPG_INDEX0_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0070)
#define REG_MM_DVFS_AHB_JPG_INDEX1_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0074)
#define REG_MM_DVFS_AHB_JPG_INDEX2_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0078)
#define REG_MM_DVFS_AHB_JPG_INDEX3_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x007C)
#define REG_MM_DVFS_AHB_JPG_INDEX4_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0080)
#define REG_MM_DVFS_AHB_JPG_INDEX5_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0084)
#define REG_MM_DVFS_AHB_JPG_INDEX6_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0088)
#define REG_MM_DVFS_AHB_JPG_INDEX7_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x008C)
#define REG_MM_DVFS_AHB_CPP_INDEX0_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0090)
#define REG_MM_DVFS_AHB_CPP_INDEX1_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0094)
#define REG_MM_DVFS_AHB_CPP_INDEX2_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0098)
#define REG_MM_DVFS_AHB_CPP_INDEX3_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x009C)
#define REG_MM_DVFS_AHB_CPP_INDEX4_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0100)
#define REG_MM_DVFS_AHB_CPP_INDEX5_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0104)
#define REG_MM_DVFS_AHB_CPP_INDEX6_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0108)
#define REG_MM_DVFS_AHB_CPP_INDEX7_MAP                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x010C)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX0_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0110)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX1_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0114)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX2_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0118)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX3_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x011C)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX4_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0120)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX5_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0124)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX6_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0128)
#define REG_MM_DVFS_AHB_DCAM_IF_INDEX7_MAP                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x012C)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX0_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0130)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX1_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0134)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX2_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0138)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX3_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x013C)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX4_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0140)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX5_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0144)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX6_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0148)
#define REG_MM_DVFS_AHB_DCAM_AXI_INDEX7_MAP                 SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x014C)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX0_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0150)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX1_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0154)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX2_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0158)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX3_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x015C)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX4_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0160)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX5_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0164)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX6_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0168)
#define REG_MM_DVFS_AHB_MM_MTX_INDEX7_MAP                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x016C)
#define REG_MM_DVFS_AHB_FD_INDEX0_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0170)
#define REG_MM_DVFS_AHB_FD_INDEX1_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0174)
#define REG_MM_DVFS_AHB_FD_INDEX2_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0178)
#define REG_MM_DVFS_AHB_FD_INDEX3_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x017C)
#define REG_MM_DVFS_AHB_FD_INDEX4_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0180)
#define REG_MM_DVFS_AHB_FD_INDEX5_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0184)
#define REG_MM_DVFS_AHB_FD_INDEX6_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0188)
#define REG_MM_DVFS_AHB_FD_INDEX7_MAP                       SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x018C)
#define REG_MM_DVFS_AHB_ISP_DVFS_INDEX_CFG                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01C0)
#define REG_MM_DVFS_AHB_ISP_DVFS_INDEX_IDLE_CFG             SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01C4)
#define REG_MM_DVFS_AHB_JPG_DVFS_INDEX_CFG                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01C8)
#define REG_MM_DVFS_AHB_JPG_DVFS_INDEX_IDLE_CFG             SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01CC)
#define REG_MM_DVFS_AHB_CPP_DVFS_INDEX_CFG                  SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01D0)
#define REG_MM_DVFS_AHB_CPP_DVFS_INDEX_IDLE_CFG             SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01D4)
#define REG_MM_DVFS_AHB_MM_MTX_DVFS_INDEX_CFG               SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01D8)
#define REG_MM_DVFS_AHB_MM_MTX_DVFS_INDEX_IDLE_CFG          SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01DC)
#define REG_MM_DVFS_AHB_DCAM_IF_DVFS_INDEX_CFG              SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01E0)
#define REG_MM_DVFS_AHB_DCAM_IF_DVFS_INDEX_IDLE_CFG         SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01E4)
#define REG_MM_DVFS_AHB_DCAM_AXI_DVFS_INDEX_CFG             SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01E8)
#define REG_MM_DVFS_AHB_DCAM_AXI_DVFS_INDEX_IDLE_CFG        SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01EC)
#define REG_MM_DVFS_AHB_FD_DVFS_INDEX_CFG                   SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01F0)
#define REG_MM_DVFS_AHB_FD_DVFS_INDEX_IDLE_CFG              SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x01F4)
#define REG_MM_DVFS_AHB_FREQ_UPD_STATE                      SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0210)
#define REG_MM_DVFS_AHB_MM_GFREE_WAIT_DELAY_CFG0            SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0214)
#define REG_MM_DVFS_AHB_MM_GFREE_WAIT_DELAY_CFG1            SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0218)
#define REG_MM_DVFS_AHB_MM_GFREE_WAIT_DELAY_CFG2            SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x021C)
#define REG_MM_DVFS_AHB_MM_FREQ_UPD_TYPE_CFG                SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0220)
#define REG_MM_DVFS_AHB_MM_DFS_IDLE_DISABLE_CFG             SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0224)
#define REG_MM_DVFS_AHB_MM_DVFS_VOL_CTRL                    SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0228)
#define REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG0           SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0230)
#define REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG1           SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0234)
#define REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG2           SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x0238)
#define REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG3           SCI_ADDR(CTL_MM_DVFS_AHB_BASE, 0x023C)

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_HOLD_CTRL, [0x30014000] */
#define BIT_MM_DVFS_AHB_MM_DVFS_HOLD                        ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_WAIT_WINDOW_CFG, [0x30014004] */
#define BIT_MM_DVFS_AHB_MM_DVFS_UP_WINDOW(x)                ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_DVFS_AHB_MM_DVFS_DOWN_WINDOW(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DFS_EN_CTRL, [0x30014008] */
#define BIT_MM_DVFS_AHB_MM_DCAM_AXI_AUTO_TUNE_EN            ( BIT(7) )
#define BIT_MM_DVFS_AHB_FD_DFS_EN                           ( BIT(6) )
#define BIT_MM_DVFS_AHB_DCAM_DFS_EN                         ( BIT(5) )
#define BIT_MM_DVFS_AHB_JPG_DFS_EN                          ( BIT(3) )
#define BIT_MM_DVFS_AHB_CPP_DFS_EN                          ( BIT(2) )
#define BIT_MM_DVFS_AHB_ISP_DFS_EN                          ( BIT(1) )
#define BIT_MM_DVFS_AHB_MM_MTX_AUTO_TUNE_EN                 ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DFS_SW_TRIG_CFG, [0x3001400C] */
#define BIT_MM_DVFS_AHB_FD_DFS_SW_TRIG                      ( BIT(6) )
#define BIT_MM_DVFS_AHB_DCAM_DFS_SW_TRIG                    ( BIT(5) )
#define BIT_MM_DVFS_AHB_JPG_DFS_SW_TRIG                     ( BIT(3) )
#define BIT_MM_DVFS_AHB_CPP_DFS_SW_TRIG                     ( BIT(2) )
#define BIT_MM_DVFS_AHB_ISP_DFS_SW_TRIG                     ( BIT(1) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MIN_VOLTAGE_CFG, [0x30014010] */
#define BIT_MM_DVFS_AHB_MM_SYS_MIN_VOLTAGE(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_SW_DVFS_CTRL, [0x3001402C] */
#define BIT_MM_DVFS_AHB_MM_DVFS_ACK                         ( BIT(8) )
#define BIT_MM_DVFS_AHB_MM_DVFS_VOLTAGE_SW(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_MM_CURRENT_VOLTAGE_SW(x)            ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)) )
#define BIT_MM_DVFS_AHB_MM_DVFS_REQ_SW                      ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_FREQ_UPDATE_BYPASS, [0x30014030] */
#define BIT_MM_DVFS_AHB_REG_FD_FREQ_UPD_EN_BYP              ( BIT(6) )
#define BIT_MM_DVFS_AHB_REG_DCAM_IF_FREQ_UPD_EN_BYP         ( BIT(5) )
#define BIT_MM_DVFS_AHB_REG_JPG_FREQ_UPD_EN_BYP             ( BIT(4) )
#define BIT_MM_DVFS_AHB_REG_CPP_FREQ_UPD_EN_BYP             ( BIT(3) )
#define BIT_MM_DVFS_AHB_REG_ISP_FREQ_UPD_EN_BYP             ( BIT(2) )
#define BIT_MM_DVFS_AHB_REG_MM_MTX_FREQ_UPD_EN_BYP          ( BIT(1) )
#define BIT_MM_DVFS_AHB_REG_DCAM_AXI_FREQ_UPD_EN_BYP        ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_CGM_MM_DVFS_CLK_GATE_CTRL, [0x30014034] */
#define BIT_MM_DVFS_AHB_CGM_MM_DVFS_FORCE_EN                ( BIT(1) )
#define BIT_MM_DVFS_AHB_CGM_MM_DVFS_AUTO_GATE_SEL           ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_VOLTAGE_DBG, [0x30014038] */
#define BIT_MM_DVFS_AHB_MM_CURRENT_VOLTAGE(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_MM_DVFS_AHB_FD_VOLTAGE(x)                       ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOLTAGE(x)                  ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)) )
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOLTAGE(x)                 ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)) )
#define BIT_MM_DVFS_AHB_JPG_VOLTAGE(x)                      ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_MM_DVFS_AHB_CPP_VOLTAGE(x)                      ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_MM_DVFS_AHB_ISP_VOLTAGE(x)                      ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_MM_MTX_VOLTAGE(x)                   ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_MM_INTERNAL_VOTE_VOLTAGE(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_CGM_CFG_DBG, [0x30014048] */
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_DVFS(x)                  ( (x) << 23 & (BIT(23)|BIT(24)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_DVFS(x)      ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_DVFS(x)        ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_DVFS(x)             ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_DVFS(x)            ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_DVFS(x)                 ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_DVFS(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_DVFS(x)                 ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_DVFS(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_STATE_DBG, [0x3001404C] */
#define BIT_MM_DVFS_AHB_MM_DVFS_BUSY                        ( BIT(19) )
#define BIT_MM_DVFS_AHB_MM_DVFS_WINDOW_CNT(x)               ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_MM_DVFS_AHB_MM_DVFS_STATE(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX0_MAP, [0x30014050] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX0(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX0(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX0(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX1_MAP, [0x30014054] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX1(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX1(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX1(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX2_MAP, [0x30014058] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX2(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX2(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX2(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX3_MAP, [0x3001405C] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX3(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX3(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX3(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX4_MAP, [0x30014060] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX4(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX4(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX4(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX5_MAP, [0x30014064] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX5(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX5(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX5(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX6_MAP, [0x30014068] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX6(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX6(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX6(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_INDEX7_MAP, [0x3001406C] */
#define BIT_MM_DVFS_AHB_ISP_VOL_INDEX7(x)                   ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_MM_DVFS_AHB_ISP_VOTE_MTX_INDEX7(x)              ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_ISP_SEL_INDEX7(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX0_MAP, [0x30014070] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX0(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX0(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX0(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX1_MAP, [0x30014074] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX1(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX1(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX1(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX2_MAP, [0x30014078] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX2(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX2(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX2(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX3_MAP, [0x3001407C] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX3(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX3(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX3(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX4_MAP, [0x30014080] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX4(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX4(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX4(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX5_MAP, [0x30014084] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX5(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX5(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX5(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX6_MAP, [0x30014088] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX6(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX6(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX6(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_INDEX7_MAP, [0x3001408C] */
#define BIT_MM_DVFS_AHB_JPG_VOL_INDEX7(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_JPG_VOTE_MTX_INDEX7(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_JPG_SEL_INDEX7(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX0_MAP, [0x30014090] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX0(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX0(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX0(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX1_MAP, [0x30014094] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX1(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX1(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX1(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX2_MAP, [0x30014098] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX2(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX2(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX2(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX3_MAP, [0x3001409C] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX3(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX3(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX3(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX4_MAP, [0x30014100] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX4(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX4(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX4(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX5_MAP, [0x30014104] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX5(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX5(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX5(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX6_MAP, [0x30014108] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX6(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX6(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX6(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_INDEX7_MAP, [0x3001410C] */
#define BIT_MM_DVFS_AHB_CPP_VOL_INDEX7(x)                   ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_CPP_VOTE_MTX_INDEX7(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_CPP_SEL_INDEX7(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX0_MAP, [0x30014110] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX0(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX0(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX0(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX0(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX0(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX1_MAP, [0x30014114] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX1(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX1(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX1(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX1(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX1(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX2_MAP, [0x30014118] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX2(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX2(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX2(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX2(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX2(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX3_MAP, [0x3001411C] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX3(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX3(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX3(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX3(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX3(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX4_MAP, [0x30014120] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX4(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX4(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX4(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX4(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX4(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX5_MAP, [0x30014124] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX5(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX5(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX5(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX5(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX5(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX6_MAP, [0x30014128] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX6(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX6(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX6(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX6(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX6(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_INDEX7_MAP, [0x3001412C] */
#define BIT_MM_DVFS_AHB_DCAM_IF_VOTE_AXI_INDEX7(x)          ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_VOL_INDEX7(x)               ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_DENOM_INDEX7(x)    ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_FDIV_NUM_INDEX7(x)      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_IF_SEL_INDEX7(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX0_MAP, [0x30014130] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX0(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX0(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX1_MAP, [0x30014134] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX1(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX1(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX2_MAP, [0x30014138] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX2(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX2(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX3_MAP, [0x3001413C] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX3(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX3(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX4_MAP, [0x30014140] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX4(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX4(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX5_MAP, [0x30014144] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX5(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX5(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX6_MAP, [0x30014148] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX6(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX6(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_INDEX7_MAP, [0x3001414C] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_VOL_INDEX7(x)              ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_DCAM_AXI_SEL_INDEX7(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX0_MAP, [0x30014150] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX0(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX1_MAP, [0x30014154] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX1(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX1(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX2_MAP, [0x30014158] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX2(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX2(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX3_MAP, [0x3001415C] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX3(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX3(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX4_MAP, [0x30014160] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX4(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX4(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX5_MAP, [0x30014164] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX5(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX5(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX6_MAP, [0x30014168] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX6(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX6(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_INDEX7_MAP, [0x3001416C] */
#define BIT_MM_DVFS_AHB_MM_MTX_VOL_INDEX7(x)                ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_MM_DVFS_AHB_CGM_MM_MTX_SEL_INDEX7(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX0_MAP, [0x30014170] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX0(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX0(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX0(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX1_MAP, [0x30014174] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX1(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX1(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX1(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX2_MAP, [0x30014178] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX2(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX2(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX2(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX3_MAP, [0x3001417C] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX3(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX3(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX3(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX4_MAP, [0x30014180] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX4(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX4(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX4(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX5_MAP, [0x30014184] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX5(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX5(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX5(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX6_MAP, [0x30014188] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX6(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX6(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX6(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_INDEX7_MAP, [0x3001418C] */
#define BIT_MM_DVFS_AHB_FD_VOL_INDEX7(x)                    ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_FD_VOTE_MTX_INDEX7(x)               ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)) )
#define BIT_MM_DVFS_AHB_CGM_FD_SEL_INDEX7(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_DVFS_INDEX_CFG, [0x300141C0] */
#define BIT_MM_DVFS_AHB_ISP_DVFS_INDEX(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_ISP_DVFS_INDEX_IDLE_CFG, [0x300141C4] */
#define BIT_MM_DVFS_AHB_ISP_DVFS_INDEX_IDLE(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_DVFS_INDEX_CFG, [0x300141C8] */
#define BIT_MM_DVFS_AHB_JPG_DVFS_INDEX(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_JPG_DVFS_INDEX_IDLE_CFG, [0x300141CC] */
#define BIT_MM_DVFS_AHB_JPG_DVFS_INDEX_IDLE(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_DVFS_INDEX_CFG, [0x300141D0] */
#define BIT_MM_DVFS_AHB_CPP_DVFS_INDEX(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_CPP_DVFS_INDEX_IDLE_CFG, [0x300141D4] */
#define BIT_MM_DVFS_AHB_CPP_DVFS_INDEX_IDLE(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_DVFS_INDEX_CFG, [0x300141D8] */
#define BIT_MM_DVFS_AHB_MM_MTX_DVFS_INDEX(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_MTX_DVFS_INDEX_IDLE_CFG, [0x300141DC] */
#define BIT_MM_DVFS_AHB_MM_MTX_DVFS_INDEX_IDLE(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_DVFS_INDEX_CFG, [0x300141E0] */
#define BIT_MM_DVFS_AHB_DCAM_IF_DVFS_INDEX(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_IF_DVFS_INDEX_IDLE_CFG, [0x300141E4] */
#define BIT_MM_DVFS_AHB_DCAM_IF_DVFS_INDEX_IDLE(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_DVFS_INDEX_CFG, [0x300141E8] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_DVFS_INDEX(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_DCAM_AXI_DVFS_INDEX_IDLE_CFG, [0x300141EC] */
#define BIT_MM_DVFS_AHB_DCAM_AXI_DVFS_INDEX_IDLE(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_DVFS_INDEX_CFG, [0x300141F0] */
#define BIT_MM_DVFS_AHB_FD_DVFS_INDEX(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_FD_DVFS_INDEX_IDLE_CFG, [0x300141F4] */
#define BIT_MM_DVFS_AHB_FD_DVFS_INDEX_IDLE(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_MM_DVFS_AHB_FREQ_UPD_STATE, [0x30014210] */
#define BIT_MM_DVFS_AHB_FD_DVFS_FREQ_UPD_STATE(x)           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_MM_DVFS_AHB_JPG_DVFS_FREQ_UPD_STATE(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_MM_DVFS_AHB_CPP_DVFS_FREQ_UPD_STATE(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_DVFS_AHB_ISP_DVFS_FREQ_UPD_STATE(x)          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_MM_DVFS_AHB_MM_MTX_DVFS_FREQ_UPD_STATE(x)       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_MM_DVFS_AHB_DCAM_AXI_DVFS_FREQ_UPD_STATE(x)     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_DVFS_FREQ_UPD_STATE(x)      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_GFREE_WAIT_DELAY_CFG0, [0x30014214] */
#define BIT_MM_DVFS_AHB_ISP_GFREE_WAIT_DELAY(x)             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_MM_DVFS_AHB_CPP_GFREE_WAIT_DELAY(x)             ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_DVFS_AHB_JPG_GFREE_WAIT_DELAY(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_GFREE_WAIT_DELAY_CFG1, [0x30014218] */
#define BIT_MM_DVFS_AHB_MM_MTX_GFREE_WAIT_DELAY(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_MM_DVFS_AHB_DCAM_AXI_GFREE_WAIT_DELAY(x)        ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_DVFS_AHB_DCAM_IF_GFREE_WAIT_DELAY(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_GFREE_WAIT_DELAY_CFG2, [0x3001421C] */
#define BIT_MM_DVFS_AHB_FD_GFREE_WAIT_DELAY(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_MM_DVFS_AHB_MM_FREQ_UPD_TYPE_CFG, [0x30014220] */
#define BIT_MM_DVFS_AHB_FD_FREQ_UPD_DELAY_EN                ( BIT(13) )
#define BIT_MM_DVFS_AHB_FD_FREQ_UPD_HDSK_EN                 ( BIT(12) )
#define BIT_MM_DVFS_AHB_ISP_FREQ_UPD_DELAY_EN               ( BIT(11) )
#define BIT_MM_DVFS_AHB_ISP_FREQ_UPD_HDSK_EN                ( BIT(10) )
#define BIT_MM_DVFS_AHB_CPP_FREQ_UPD_DELAY_EN               ( BIT(9) )
#define BIT_MM_DVFS_AHB_CPP_FREQ_UPD_HDSK_EN                ( BIT(8) )
#define BIT_MM_DVFS_AHB_JPG_FREQ_UPD_DELAY_EN               ( BIT(7) )
#define BIT_MM_DVFS_AHB_JPG_FREQ_UPD_HDSK_EN                ( BIT(6) )
#define BIT_MM_DVFS_AHB_MM_MTX_FREQ_UPD_DELAY_EN            ( BIT(5) )
#define BIT_MM_DVFS_AHB_MM_MTX_FREQ_UPD_HDSK_EN             ( BIT(4) )
#define BIT_MM_DVFS_AHB_DCAM_AXI_FREQ_UPD_DELAY_EN          ( BIT(3) )
#define BIT_MM_DVFS_AHB_DCAM_AXI_FREQ_UPD_HDSK_EN           ( BIT(2) )
#define BIT_MM_DVFS_AHB_DCAM_IF_FREQ_UPD_DELAY_EN           ( BIT(1) )
#define BIT_MM_DVFS_AHB_DCAM_IF_FREQ_UPD_HDSK_EN            ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DFS_IDLE_DISABLE_CFG, [0x30014224] */
#define BIT_MM_DVFS_AHB_MM_MTX_DFS_IDLE_DISABLE             ( BIT(6) )
#define BIT_MM_DVFS_AHB_MM_FD_DFS_IDLE_DISABLE              ( BIT(5) )
#define BIT_MM_DVFS_AHB_MM_ISP_DFS_IDLE_DISABLE             ( BIT(4) )
#define BIT_MM_DVFS_AHB_MM_CPP_DFS_IDLE_DISABLE             ( BIT(3) )
#define BIT_MM_DVFS_AHB_MM_JPG_DFS_IDLE_DISABLE             ( BIT(2) )
#define BIT_MM_DVFS_AHB_MM_DCAM_AXI_DFS_IDLE_DISABLE        ( BIT(1) )
#define BIT_MM_DVFS_AHB_MM_DCAM_IF_DFS_IDLE_DISABLE         ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_VOL_CTRL, [0x30014228] */
#define BIT_MM_DVFS_AHB_VOL_DOWN_EARLY_UPD_EN               ( BIT(0) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG0, [0x30014230] */
#define BIT_MM_DVFS_AHB_DVFS_RES_REG0(x)                    ( (x) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG1, [0x30014234] */
#define BIT_MM_DVFS_AHB_DVFS_RES_REG1(x)                    ( (x) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG2, [0x30014238] */
#define BIT_MM_DVFS_AHB_DVFS_RES_REG2(x)                    ( (x) )

/* bits definitions for REG_MM_DVFS_AHB_MM_DVFS_RESERVED_REG_CFG3, [0x3001423C] */
#define BIT_MM_DVFS_AHB_DVFS_RES_REG3(x)                    ( (x) )

/* vars definitions for controller CTL_MM_DVFS_AHB */


#endif /* __MM_DVFS_AHB_H____ */
