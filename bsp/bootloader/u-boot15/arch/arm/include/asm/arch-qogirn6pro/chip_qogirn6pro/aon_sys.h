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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/aon/nic400_aon_main_mtx_m9_qos_control_register.xls;qos_regs
 *     Revision : 231409
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AON_SYS_H____
#define __AON_SYS_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_SYS_BASE
#define CTL_AON_SYS_BASE                SCI_IOMAP(0x645A0000)
#endif

/* registers definitions for CTL_AON_SYS, 0x645A0000 */
#define REG_AON_SYS_REGU_OT_CTRL_EN                         SCI_ADDR(CTL_AON_SYS_BASE, 0x0000)
#define REG_AON_SYS_REGU_OT_CTRL_AW_CFG                     SCI_ADDR(CTL_AON_SYS_BASE, 0x0004)
#define REG_AON_SYS_REGU_OT_CTRL_AR_CFG                     SCI_ADDR(CTL_AON_SYS_BASE, 0x0008)
#define REG_AON_SYS_REGU_OT_CTRL_AX_CFG                     SCI_ADDR(CTL_AON_SYS_BASE, 0x000C)
#define REG_AON_SYS_REGU_LAT_EN                             SCI_ADDR(CTL_AON_SYS_BASE, 0x0010)
#define REG_AON_SYS_REGU_LAT_W_CFG                          SCI_ADDR(CTL_AON_SYS_BASE, 0x0014)
#define REG_AON_SYS_REGU_LAT_R_CFG                          SCI_ADDR(CTL_AON_SYS_BASE, 0x0018)
#define REG_AON_SYS_REGU_LAT_STATUS                         SCI_ADDR(CTL_AON_SYS_BASE, 0x001C)
#define REG_AON_SYS_REGU_AXQOS_GEN_EN                       SCI_ADDR(CTL_AON_SYS_BASE, 0x0060)
#define REG_AON_SYS_REGU_AXQOS_GEN_CFG                      SCI_ADDR(CTL_AON_SYS_BASE, 0x0064)
#define REG_AON_SYS_REGU_URG_CNT_CFG                        SCI_ADDR(CTL_AON_SYS_BASE, 0x0068)
#define REG_AON_SYS_REGU_URG_CNT_VALUE                      SCI_ADDR(CTL_AON_SYS_BASE, 0x006C)

/* bits definitions for REG_AON_SYS_REGU_OT_CTRL_EN, [0x645A0000] */
#define BIT_AON_SYS_OT_CTRL_EN                              ( BIT(0) )

/* bits definitions for REG_AON_SYS_REGU_OT_CTRL_AW_CFG, [0x645A0004] */
#define BIT_AON_SYS_URG_13_AW_INTVL_MODE(x)                 ( (x) << 30 & (BIT(30)|BIT(31)) )
#define BIT_AON_SYS_URG_13_MAX_AW_OT(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_SYS_URG_00_AW_INTVL_MODE(x)                 ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_AON_SYS_URG_00_MAX_AW_OT(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_AON_SYS_URG_01_AW_INTVL_MODE(x)                 ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AON_SYS_URG_01_MAX_AW_OT(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AON_SYS_URG_03_AW_INTVL_MODE(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AON_SYS_URG_03_MAX_AW_OT(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_SYS_REGU_OT_CTRL_AR_CFG, [0x645A0008] */
#define BIT_AON_SYS_URG_13_MAX_AR_OT(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_SYS_URG_00_MAX_AR_OT(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_AON_SYS_URG_01_MAX_AR_OT(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AON_SYS_URG_03_MAX_AR_OT(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_SYS_REGU_OT_CTRL_AX_CFG, [0x645A000C] */
#define BIT_AON_SYS_URG_3X_MAX_AR_OT(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_AON_SYS_URG_1X_MAX_AR_OT(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_AON_SYS_URG_3X_AW_INTVL_MODE(x)                 ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_AON_SYS_URG_3X_MAX_AW_OT(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_AON_SYS_URG_1X_AW_INTVL_MODE(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_AON_SYS_URG_1X_MAX_AW_OT(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_AON_SYS_REGU_LAT_EN, [0x645A0010] */
#define BIT_AON_SYS_REGU_EN_R                               ( BIT(1) )
#define BIT_AON_SYS_REGU_EN_W                               ( BIT(0) )

/* bits definitions for REG_AON_SYS_REGU_LAT_W_CFG, [0x645A0014] */
#define BIT_AON_SYS_WINDOW_LENGTH_W(x)                      ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_SYS_BLK_REQ_LAT_W(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_SYS_CMD_NOT_CYCLE_W                         ( BIT(11) )
#define BIT_AON_SYS_INCR_OT_DISABLE_W                       ( BIT(10) )
#define BIT_AON_SYS_BW_LIKE_MODE_W                          ( BIT(9) )
#define BIT_AON_SYS_ULTRA_DISABLE_W                         ( BIT(8) )
#define BIT_AON_SYS_AVG_LAT_EXP_W(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SYS_REGU_LAT_R_CFG, [0x645A0018] */
#define BIT_AON_SYS_WINDOW_LENGTH_R(x)                      ( (x) << 16 & (0xFFFF0000) )
#define BIT_AON_SYS_BLK_REQ_LAT_R(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_SYS_CMD_NOT_CYCLE_R                         ( BIT(11) )
#define BIT_AON_SYS_INCR_OT_DISABLE_R                       ( BIT(10) )
#define BIT_AON_SYS_BW_LIKE_MODE_R                          ( BIT(9) )
#define BIT_AON_SYS_ULTRA_DISABLE_R                         ( BIT(8) )
#define BIT_AON_SYS_AVG_LAT_EXP_R(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SYS_REGU_LAT_STATUS, [0x645A001C] */
#define BIT_AON_SYS_WIN_LAT_ACT_OVF_W                       ( BIT(17) )
#define BIT_AON_SYS_WIN_LAT_EXP_OVF_W                       ( BIT(16) )
#define BIT_AON_SYS_WIN_LAT_ACT_OVF_R                       ( BIT(1) )
#define BIT_AON_SYS_WIN_LAT_EXP_OVF_R                       ( BIT(0) )

/* bits definitions for REG_AON_SYS_REGU_AXQOS_GEN_EN, [0x645A0060] */
#define BIT_AON_SYS_URGENCY_FEEDTHR                         ( BIT(31) )
#define BIT_AON_SYS_GEN_EN_R                                ( BIT(1) )
#define BIT_AON_SYS_GEN_EN_W                                ( BIT(0) )

/* bits definitions for REG_AON_SYS_REGU_AXQOS_GEN_CFG, [0x645A0064] */
#define BIT_AON_SYS_AWURGENCY(x)                            ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_AON_SYS_AWQOS_ULTRA(x)                          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_SYS_AWQOS_HIGH(x)                           ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_SYS_AWQOS_NORM(x)                           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_SYS_ARURGENCY(x)                            ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_SYS_ARQOS_ULTRA(x)                          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_AON_SYS_ARQOS_HIGH(x)                           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_SYS_ARQOS_NORM(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_SYS_REGU_URG_CNT_CFG, [0x645A0068] */
#define BIT_AON_SYS_CNT_SEL(x)                              ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_SYS_CNT_EN                                  ( BIT(0) )

/* bits definitions for REG_AON_SYS_REGU_URG_CNT_VALUE, [0x645A006C] */
#define BIT_AON_SYS_AX_CNT(x)                               ( (x) )

/* vars definitions for controller CTL_AON_SYS */


#endif /* __AON_SYS_H____ */
