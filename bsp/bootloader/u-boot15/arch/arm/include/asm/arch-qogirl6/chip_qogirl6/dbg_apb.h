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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/DBG_SYS/SharkL6 DBG APB Control Register.xls;DBG_APB_REG
 *     Revision : 213220
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __DBG_APB_H____
#define __DBG_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_DBG_APB_BASE
#define CTL_DBG_APB_BASE                SCI_IOMAP(0x7C00A000)
#endif

/* registers definitions for CTL_DBG_APB, 0x7C00A000 */
#define REG_DBG_APB_SUB_SYS_DBG_BUSY_TIMER_FOR_BUSMON       SCI_ADDR(CTL_DBG_APB_BASE, 0x0000)
#define REG_DBG_APB_SUB_SYS_DBG_MISC_SIGNAL                 SCI_ADDR(CTL_DBG_APB_BASE, 0x0004)
#define REG_DBG_APB_SUB_SYS_DBG_PWR_CTRL                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0008)
#define REG_DBG_APB_SUB_SYS_DBG_DBG_CTRL                    SCI_ADDR(CTL_DBG_APB_BASE, 0x000C)
#define REG_DBG_APB_SUB_SYS_DBG_STM_SOFT_RST                SCI_ADDR(CTL_DBG_APB_BASE, 0x0010)
#define REG_DBG_APB_SUB_SYS_DBG_RCO_CLK_CTRL                SCI_ADDR(CTL_DBG_APB_BASE, 0x0014)
#define REG_DBG_APB_SUB_SYS_DBG_SEL_CFG0                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0018)
#define REG_DBG_APB_SUB_SYS_DBG_SEL_CFG1                    SCI_ADDR(CTL_DBG_APB_BASE, 0x001C)
#define REG_DBG_APB_SUB_SYS_DBG_SEL_CFG2                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0020)
#define REG_DBG_APB_SUB_SYS_DBG_SEL_CFG3                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0024)
#define REG_DBG_APB_SUB_SYS_DBG_SEL_CFG4                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0028)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG0                SCI_ADDR(CTL_DBG_APB_BASE, 0x002C)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG1                SCI_ADDR(CTL_DBG_APB_BASE, 0x0030)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG2                SCI_ADDR(CTL_DBG_APB_BASE, 0x0034)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG3                SCI_ADDR(CTL_DBG_APB_BASE, 0x0038)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG4                SCI_ADDR(CTL_DBG_APB_BASE, 0x003C)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG5                SCI_ADDR(CTL_DBG_APB_BASE, 0x0040)
#define REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG6                SCI_ADDR(CTL_DBG_APB_BASE, 0x0044)
#define REG_DBG_APB_PAD_DBG_BUS_DATA_A                      SCI_ADDR(CTL_DBG_APB_BASE, 0x0048)
#define REG_DBG_APB_PAD_DBG_BUS_DATA_B                      SCI_ADDR(CTL_DBG_APB_BASE, 0x004C)
#define REG_DBG_APB_PAD_DBG_BUS_DATA_OUT                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0050)
#define REG_DBG_APB_ETR_AXI_MON_INT_EN                      SCI_ADDR(CTL_DBG_APB_BASE, 0x0054)
#define REG_DBG_APB_ETR_AXI_MON_INT_CLR                     SCI_ADDR(CTL_DBG_APB_BASE, 0x0058)
#define REG_DBG_APB_ETR_AXI_MON_INT_RAW                     SCI_ADDR(CTL_DBG_APB_BASE, 0x005C)
#define REG_DBG_APB_ETR_AXI_MON_INT_STAT                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0060)
#define REG_DBG_APB_ETR_AXI_MON_AWADDR0                     SCI_ADDR(CTL_DBG_APB_BASE, 0x0064)
#define REG_DBG_APB_ETR_AXI_MON_AWADDR1                     SCI_ADDR(CTL_DBG_APB_BASE, 0x0068)
#define REG_DBG_APB_ETR_AXI_MON_AWADDR2                     SCI_ADDR(CTL_DBG_APB_BASE, 0x006C)
#define REG_DBG_APB_ETR_AXI_MON_AWADDR3                     SCI_ADDR(CTL_DBG_APB_BASE, 0x0070)
#define REG_DBG_APB_SUB_SYS_DBG_SEL_CFG5                    SCI_ADDR(CTL_DBG_APB_BASE, 0x0074)

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_BUSY_TIMER_FOR_BUSMON, [0x7C00A000] */
#define BIT_DBG_APB_BUS_BUSY_TIMER_EN                       ( BIT(8) )
#define BIT_DBG_APB_BUS_BUSY_TIMER_DIVIDER(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_MISC_SIGNAL, [0x7C00A004] */
#define BIT_DBG_APB_APCPU_CSSYS_EN                          ( BIT(3) )
#define BIT_DBG_APB_APCPU_APB_TRANS_CSYSREQ                 ( BIT(2) )
#define BIT_DBG_APB_CPWRUPREQ_CDBGPWRUP                     ( BIT(1) )
#define BIT_DBG_APB_DBGCONNECTED                            ( BIT(0) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PWR_CTRL, [0x7C00A008] */
#define BIT_DBG_APB_CSYSPWRUPREQ_WCN_EN                     ( BIT(4) )
#define BIT_DBG_APB_CSYSPWRUPREQ_RCO_EN                     ( BIT(3) )
#define BIT_DBG_APB_CSYSPWRUPREQ_CR5_EN                     ( BIT(2) )
#define BIT_DBG_APB_CSYSPWRUPREQ_AON_CM4_EN                 ( BIT(1) )
#define BIT_DBG_APB_CSYSPWRUPREQ_APCPU_EN                   ( BIT(0) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_DBG_CTRL, [0x7C00A00C] */
#define BIT_DBG_APB_TPIU2SERDES_CGM_EN                      ( BIT(17) )
#define BIT_DBG_APB_CSSYS_EN_REG                            ( BIT(16) )
#define BIT_DBG_APB_APCPU_DAP_EN_REG                        ( BIT(15) )
#define BIT_DBG_APB_CROSS_TRIGGER_EN                        ( BIT(14) )
#define BIT_DBG_APB_APCPU_MTX_SOFT_RST                      ( BIT(13) )
#define BIT_DBG_APB_APCPU_AB_SOFT_RST                       ( BIT(12) )
#define BIT_DBG_APB_APCPU_APB_TRANS_BLKR_BYPASS             ( BIT(11) )
#define BIT_DBG_APB_APCPU_CORINTH_DEBUG_EN_FOR_LP           ( BIT(10) )
#define BIT_DBG_APB_AUTO_REG_SAVE_SEL                       ( BIT(9) )
#define BIT_DBG_APB_AUTO_REG_SAVE_SOFT_TRIG                 ( BIT(8) )
#define BIT_DBG_APB_AUTO_REG_SAVE_EN                        ( BIT(7) )
#define BIT_DBG_APB_CSSYS_SOFT_RST_EN                       ( BIT(6) )
#define BIT_DBG_APB_AON_MTX_SOFT_RST_EN                     ( BIT(5) )
#define BIT_DBG_APB_DAP_SOFT_RST_EN                         ( BIT(4) )
#define BIT_DBG_APB_APCPU_CSSYS_EN_REG                      ( BIT(3) )
#define BIT_DBG_APB_APCPU_DBG_CONNECTED_SW                  ( BIT(2) )
#define BIT_DBG_APB_APCPU_DBG_CONNECTED_CTRL(x)             ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_STM_SOFT_RST, [0x7C00A010] */
#define BIT_DBG_APB_STM_SOFT_RESET                          ( BIT(0) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_RCO_CLK_CTRL, [0x7C00A014] */
#define BIT_DBG_APB_AON_APB_CLK_RCO_SEL(x)                  ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_CSSYS_CLK_RCO_SEL(x)                    ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_DBG_APB_DAP_CLK_RCO_SEL(x)                      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_DBG_APB_AON_APB_CLK_RCO_CTRL_EN                 ( BIT(2) )
#define BIT_DBG_APB_CSSYS_CLK_RCO_CTRL_EN                   ( BIT(1) )
#define BIT_DBG_APB_DAP_CLK_RCO_CTRL_EN                     ( BIT(0) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_SEL_CFG0, [0x7C00A018] */
#define BIT_DBG_APB_REG_DBG_SYS_SEL_B(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DBG_APB_REG_DBG_SYS_SEL_A(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_SEL_CFG1, [0x7C00A01C] */
#define BIT_DBG_APB_REG_DBG_BUS_SEL_GPU(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_MM(x)                   ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_AP(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_APCPU(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_SEL_CFG2, [0x7C00A020] */
#define BIT_DBG_APB_REG_DBG_BUS_SEL_AON(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_AON_LP(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_PUB(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_SEL_CFG3, [0x7C00A024] */
#define BIT_DBG_APB_REG_DBG_BUS_SEL_MDAR(x)                 ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_WTLCP(x)                ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_PUBCP(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_AUDCP(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_SEL_CFG4, [0x7C00A028] */
#define BIT_DBG_APB_REG_DBG_MOD_SEL_LP(x)                   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_DBG_APB_REG_DBG_MOD_SEL_APCPU(x)                ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_REG_DBG_MOD_SEL_WTLCP(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DBG_APB_REG_DBG_MOD_SEL_PUBCP(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG0, [0x7C00A02C] */
#define BIT_DBG_APB_DBG_BUS4_SEL(x)                         ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_DBG_APB_DBG_BUS3_SEL(x)                         ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_DBG_BUS2_SEL(x)                         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_DBG_APB_DBG_BUS1_SEL(x)                         ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS0_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG1, [0x7C00A030] */
#define BIT_DBG_APB_DBG_BUS9_SEL(x)                         ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_DBG_APB_DBG_BUS8_SEL(x)                         ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_DBG_BUS7_SEL(x)                         ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_DBG_APB_DBG_BUS6_SEL(x)                         ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS5_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG2, [0x7C00A034] */
#define BIT_DBG_APB_DBG_BUS14_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_DBG_APB_DBG_BUS13_SEL(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_DBG_BUS12_SEL(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_DBG_APB_DBG_BUS11_SEL(x)                        ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS10_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG3, [0x7C00A038] */
#define BIT_DBG_APB_DBG_BUS19_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_DBG_APB_DBG_BUS18_SEL(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_DBG_BUS17_SEL(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_DBG_APB_DBG_BUS16_SEL(x)                        ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS15_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG4, [0x7C00A03C] */
#define BIT_DBG_APB_DBG_BUS24_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_DBG_APB_DBG_BUS23_SEL(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_DBG_BUS22_SEL(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_DBG_APB_DBG_BUS21_SEL(x)                        ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS20_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG5, [0x7C00A040] */
#define BIT_DBG_APB_DBG_BUS29_SEL(x)                        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_DBG_APB_DBG_BUS28_SEL(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_DBG_APB_DBG_BUS27_SEL(x)                        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_DBG_APB_DBG_BUS26_SEL(x)                        ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS25_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_PAD_SEL_CFG6, [0x7C00A044] */
#define BIT_DBG_APB_DBG_BUS31_SEL(x)                        ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_DBG_APB_DBG_BUS30_SEL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)) )

/* bits definitions for REG_DBG_APB_PAD_DBG_BUS_DATA_A, [0x7C00A048] */
#define BIT_DBG_APB_PAD_DBG_BUS_DATA_A(x)                   ( (x) )

/* bits definitions for REG_DBG_APB_PAD_DBG_BUS_DATA_B, [0x7C00A04C] */
#define BIT_DBG_APB_PAD_DBG_BUS_DATA_B(x)                   ( (x) )

/* bits definitions for REG_DBG_APB_PAD_DBG_BUS_DATA_OUT, [0x7C00A050] */
#define BIT_DBG_APB_PAD_DBG_BUS_DATA_OUT(x)                 ( (x) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_INT_EN, [0x7C00A054] */
#define BIT_DBG_APB_AWADDR3_MATCH_INT_EN                    ( BIT(3) )
#define BIT_DBG_APB_AWADDR2_MATCH_INT_EN                    ( BIT(2) )
#define BIT_DBG_APB_AWADDR1_MATCH_INT_EN                    ( BIT(1) )
#define BIT_DBG_APB_AWADDR0_MATCH_INT_EN                    ( BIT(0) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_INT_CLR, [0x7C00A058] */
#define BIT_DBG_APB_AWADDR3_MATCH_INT_CLR                   ( BIT(3) )
#define BIT_DBG_APB_AWADDR2_MATCH_INT_CLR                   ( BIT(2) )
#define BIT_DBG_APB_AWADDR1_MATCH_INT_CLR                   ( BIT(1) )
#define BIT_DBG_APB_AWADDR0_MATCH_INT_CLR                   ( BIT(0) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_INT_RAW, [0x7C00A05C] */
#define BIT_DBG_APB_AWADDR3_MATCH_INT_RAW                   ( BIT(3) )
#define BIT_DBG_APB_AWADDR2_MATCH_INT_RAW                   ( BIT(2) )
#define BIT_DBG_APB_AWADDR1_MATCH_INT_RAW                   ( BIT(1) )
#define BIT_DBG_APB_AWADDR0_MATCH_INT_RAW                   ( BIT(0) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_INT_STAT, [0x7C00A060] */
#define BIT_DBG_APB_AWADDR3_MATCH_INT_STAT                  ( BIT(3) )
#define BIT_DBG_APB_AWADDR2_MATCH_INT_STAT                  ( BIT(2) )
#define BIT_DBG_APB_AWADDR1_MATCH_INT_STAT                  ( BIT(1) )
#define BIT_DBG_APB_AWADDR0_MATCH_INT_STAT                  ( BIT(0) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_AWADDR0, [0x7C00A064] */
#define BIT_DBG_APB_ETR_AXI_MON_AWADDR0(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_AWADDR1, [0x7C00A068] */
#define BIT_DBG_APB_ETR_AXI_MON_AWADDR1(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_AWADDR2, [0x7C00A06C] */
#define BIT_DBG_APB_ETR_AXI_MON_AWADDR2(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )

/* bits definitions for REG_DBG_APB_ETR_AXI_MON_AWADDR3, [0x7C00A070] */
#define BIT_DBG_APB_ETR_AXI_MON_AWADDR3(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )

/* bits definitions for REG_DBG_APB_SUB_SYS_DBG_SEL_CFG5, [0x7C00A074] */
#define BIT_DBG_APB_REG_DBG_MOD_SEL_WCN(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_DBG_APB_REG_DBG_BUS_SEL_WCN(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* vars definitions for controller CTL_DBG_APB */


#endif /* __DBG_APB_H____ */
