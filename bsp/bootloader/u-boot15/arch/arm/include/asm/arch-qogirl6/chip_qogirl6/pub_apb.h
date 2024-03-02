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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/PUB_SYS/SharkL6 PUB CTL APB Control Register.xls;PUB APB Reg
 *     Revision : 222727
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __PUB_APB_H____
#define __PUB_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_PUB_APB_BASE
#define CTL_PUB_APB_BASE                SCI_IOMAP(0x60000000)
#endif

/* registers definitions for CTL_PUB_APB, 0x60000000 */
#define REG_PUB_APB_DDR_EB                                  SCI_ADDR(CTL_PUB_APB_BASE, 0x0000)
#define REG_PUB_APB_DDR_SOFT_RST                            SCI_ADDR(CTL_PUB_APB_BASE, 0x0004)
#define REG_PUB_APB_DDR_CHN_SLEEP_CTRL0                     SCI_ADDR(CTL_PUB_APB_BASE, 0x0008)
#define REG_PUB_APB_PUB_AXI_REGU_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x000C)
#define REG_PUB_APB_DMC_EXT_LPCTRL_CFG                      SCI_ADDR(CTL_PUB_APB_BASE, 0x31A0)
#define REG_PUB_APB_DMC_EXT_LPCTRL_SEQL                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31A4)
#define REG_PUB_APB_DMC_EXT_LPCTRL_SEQH                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31A8)
#define REG_PUB_APB_DMC_EXT_LPCTRL_STEP                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31AC)
#define REG_PUB_APB_QOS_SELECT                              SCI_ADDR(CTL_PUB_APB_BASE, 0x31B0)
#define REG_PUB_APB_DPLL_PRE_DIV_STATUS                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31C0)
#define REG_PUB_APB_DFI_BWMON_TIMER                         SCI_ADDR(CTL_PUB_APB_BASE, 0x31C4)
#define REG_PUB_APB_QOS_SWITCH                              SCI_ADDR(CTL_PUB_APB_BASE, 0x31C8)
#define REG_PUB_APB_PUB_BUS_CK_EB                           SCI_ADDR(CTL_PUB_APB_BASE, 0x31CC)
#define REG_PUB_APB_AXI_LPC_CTRL_3                          SCI_ADDR(CTL_PUB_APB_BASE, 0x31D0)
#define REG_PUB_APB_PUB_INT_CG_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x31D4)
#define REG_PUB_APB_TIMER_ENABLE                            SCI_ADDR(CTL_PUB_APB_BASE, 0x31D8)
#define REG_PUB_APB_VOTE_CTRL                               SCI_ADDR(CTL_PUB_APB_BASE, 0x31E0)
#define REG_PUB_APB_VOTE_STATUS                             SCI_ADDR(CTL_PUB_APB_BASE, 0x31E4)
#define REG_PUB_APB_DFS_HW_CTRL3                            SCI_ADDR(CTL_PUB_APB_BASE, 0x31F0)
#define REG_PUB_APB_QOS_FIXED_CTRL0                         SCI_ADDR(CTL_PUB_APB_BASE, 0x31F4)
#define REG_PUB_APB_QOS_FIXED_CTRL1                         SCI_ADDR(CTL_PUB_APB_BASE, 0x31F8)
#define REG_PUB_APB_QOS_FIXED_CTRL2                         SCI_ADDR(CTL_PUB_APB_BASE, 0x31FC)
#define REG_PUB_APB_PUB_AXI_QOS_URGENT_REG_0                SCI_ADDR(CTL_PUB_APB_BASE, 0x3200)
#define REG_PUB_APB_PUB_AXI_QOS_URGENT_REG_1                SCI_ADDR(CTL_PUB_APB_BASE, 0x3204)
#define REG_PUB_APB_PUB_INT_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x32F0)
#define REG_PUB_APB_DFS_STATUS                              SCI_ADDR(CTL_PUB_APB_BASE, 0x32F4)
#define REG_PUB_APB_DFS_STATUS1                             SCI_ADDR(CTL_PUB_APB_BASE, 0x32F8)
#define REG_PUB_APB_DFS_FC_REQ_DELAY                        SCI_ADDR(CTL_PUB_APB_BASE, 0x32FC)
#define REG_PUB_APB_PUB_LP_GEN_CTRL                         SCI_ADDR(CTL_PUB_APB_BASE, 0x333C)
#define REG_PUB_APB_AXI_LPC_CTRL_0                          SCI_ADDR(CTL_PUB_APB_BASE, 0x334C)
#define REG_PUB_APB_AXI_LPC_CTRL_1                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3350)
#define REG_PUB_APB_AXI_LPC_CTRL_2                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3354)
#define REG_PUB_APB_FENCING_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x3358)
#define REG_PUB_APB_CP_BASE_ADDR                            SCI_ADDR(CTL_PUB_APB_BASE, 0x3360)
#define REG_PUB_APB_CLK_PUB_DFS_CTRL                        SCI_ADDR(CTL_PUB_APB_BASE, 0x3364)
#define REG_PUB_APB_BIST_CTRL                               SCI_ADDR(CTL_PUB_APB_BASE, 0x3400)
#define REG_PUB_APB_DMC_SOFT_RST_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x3404)
#define REG_PUB_APB_MC_IDLE_WAIT_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x3414)
#define REG_PUB_APB_QOS_THRESHOLD_0                         SCI_ADDR(CTL_PUB_APB_BASE, 0x3418)
#define REG_PUB_APB_QOS_THRESHOLD_1                         SCI_ADDR(CTL_PUB_APB_BASE, 0x341C)
#define REG_PUB_APB_DMC_DDR_CLK_CTRL                        SCI_ADDR(CTL_PUB_APB_BASE, 0x4000)
#define REG_PUB_APB_DMC_CLK_INIT_SW_START                   SCI_ADDR(CTL_PUB_APB_BASE, 0x4004)
#define REG_PUB_APB_DMC_CLK_STATE                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4008)
#define REG_PUB_APB_DMC_CLK_INIT_CFG                        SCI_ADDR(CTL_PUB_APB_BASE, 0x400C)
#define REG_PUB_APB_DMC_DESKEW_WAIT_CFG                     SCI_ADDR(CTL_PUB_APB_BASE, 0x4010)
#define REG_PUB_APB_DMC_DESKEW_WAIT_CNT0                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4014)
#define REG_PUB_APB_DMC_DESKEW_WAIT_CNT1                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4018)
#define REG_PUB_APB_DMC_DESKEW_WAIT_CNT2                    SCI_ADDR(CTL_PUB_APB_BASE, 0x401C)
#define REG_PUB_APB_DMC_DESKEW_WAIT_CNT3                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4020)
#define REG_PUB_APB_DMC_DDL_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x402C)
#define REG_PUB_APB_DFS_PURE_SW_CTRL                        SCI_ADDR(CTL_PUB_APB_BASE, 0x4100)
#define REG_PUB_APB_DFS_SW_CTRL                             SCI_ADDR(CTL_PUB_APB_BASE, 0x4104)
#define REG_PUB_APB_DFS_SW_CTRL1                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4108)
#define REG_PUB_APB_DFS_SW_CTRL2                            SCI_ADDR(CTL_PUB_APB_BASE, 0x410C)
#define REG_PUB_APB_DFS_SW_CTRL3                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4110)
#define REG_PUB_APB_DFS_HW_CTRL                             SCI_ADDR(CTL_PUB_APB_BASE, 0x4114)
#define REG_PUB_APB_DFS_HW_CTRL1                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4118)
#define REG_PUB_APB_DFS_HW_CTRL2                            SCI_ADDR(CTL_PUB_APB_BASE, 0x411C)
#define REG_PUB_APB_DFS_HW_RATIO_SET0                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4120)
#define REG_PUB_APB_DFS_HW_RATIO_SET1                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4124)
#define REG_PUB_APB_DFS_HW_RATIO_SET2                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4128)
#define REG_PUB_APB_DFS_HW_RATIO_SET3                       SCI_ADDR(CTL_PUB_APB_BASE, 0x412C)
#define REG_PUB_APB_DFS_HW_RATIO_SET4                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4130)
#define REG_PUB_APB_DFS_HW_RATIO_SET5                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4134)
#define REG_PUB_APB_DFS_HW_RATIO_SET6                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4138)
#define REG_PUB_APB_DFS_HW_RATIO_SET7                       SCI_ADDR(CTL_PUB_APB_BASE, 0x413C)
#define REG_PUB_APB_DFS_HW_RATIO_SET8                       SCI_ADDR(CTL_PUB_APB_BASE, 0x4140)
#define REG_PUB_APB_HW_DESKEWPLL_PD_CTRL0                   SCI_ADDR(CTL_PUB_APB_BASE, 0x4144)
#define REG_PUB_APB_HW_DESKEWPLL_PD_CTRL1                   SCI_ADDR(CTL_PUB_APB_BASE, 0x4148)
#define REG_PUB_APB_DVS_CTRL_0                              SCI_ADDR(CTL_PUB_APB_BASE, 0x4150)
#define REG_PUB_APB_DVS_CTRL_1                              SCI_ADDR(CTL_PUB_APB_BASE, 0x4154)
#define REG_PUB_APB_DVS_CTRL_2                              SCI_ADDR(CTL_PUB_APB_BASE, 0x4158)
#define REG_PUB_APB_DVS_DEC_BLOCK_TIME                      SCI_ADDR(CTL_PUB_APB_BASE, 0x415C)
#define REG_PUB_APB_VOTE_MASTER_EN                          SCI_ADDR(CTL_PUB_APB_BASE, 0x4310)
#define REG_PUB_APB_VOTE_FSM_CNT                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4314)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_0                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4318)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_1                    SCI_ADDR(CTL_PUB_APB_BASE, 0x431C)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_2                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4320)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_3                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4324)
#define REG_PUB_APB_TEST_DSKPLL_BIST_CNT                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4328)
#define REG_PUB_APB_PUB_STATUS_MON_CTRL                     SCI_ADDR(CTL_PUB_APB_BASE, 0x6200)
#define REG_PUB_APB_PUB_ST_IDLE_CYC_CNT                     SCI_ADDR(CTL_PUB_APB_BASE, 0x6204)
#define REG_PUB_APB_PUB_ST_WR_CYC_CNT                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6208)
#define REG_PUB_APB_PUB_ST_RD_CYC_CNT                       SCI_ADDR(CTL_PUB_APB_BASE, 0x620C)
#define REG_PUB_APB_PUB_ST_SR_CYC_CNT                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6210)
#define REG_PUB_APB_PUB_ST_LS_CYC_CNT                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6214)
#define REG_PUB_APB_PUB_ST_LS_TIME_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6218)
#define REG_PUB_APB_PUB_DFS_F0_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x621C)
#define REG_PUB_APB_PUB_DFS_F1_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6220)
#define REG_PUB_APB_PUB_DFS_F2_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6224)
#define REG_PUB_APB_PUB_DFS_F3_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6228)
#define REG_PUB_APB_PUB_DFS_F4_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x622C)
#define REG_PUB_APB_PUB_DFS_F5_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6230)
#define REG_PUB_APB_PUB_DFS_F6_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6234)
#define REG_PUB_APB_PUB_DFS_F7_CYC_CNT                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6238)
#define REG_PUB_APB_PUB_DFS_CNT                             SCI_ADDR(CTL_PUB_APB_BASE, 0x623C)
#define REG_PUB_APB_VOTE_CTRL_DPU                           SCI_ADDR(CTL_PUB_APB_BASE, 0x6400)
#define REG_PUB_APB_VOTE_CTRL_DCAM                          SCI_ADDR(CTL_PUB_APB_BASE, 0x6404)
#define REG_PUB_APB_VOTE_CTRL_PUBCP                         SCI_ADDR(CTL_PUB_APB_BASE, 0x6408)
#define REG_PUB_APB_VOTE_CTRL_WTLCP                         SCI_ADDR(CTL_PUB_APB_BASE, 0x640C)
#define REG_PUB_APB_VOTE_CTRL_WTLCP1                        SCI_ADDR(CTL_PUB_APB_BASE, 0x6410)
#define REG_PUB_APB_VOTE_CTRL_AGCP                          SCI_ADDR(CTL_PUB_APB_BASE, 0x6414)
#define REG_PUB_APB_VOTE_CTRL_SW                            SCI_ADDR(CTL_PUB_APB_BASE, 0x6418)
#define REG_PUB_APB_VOTE_CTRL_VDSP                          SCI_ADDR(CTL_PUB_APB_BASE, 0x641C)
#define REG_PUB_APB_VOTE_CTRL_WCN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x6420)
#define REG_PUB_APB_DFS_GFREE_CTRL                          SCI_ADDR(CTL_PUB_APB_BASE, 0x6500)
#define REG_PUB_APB_DFS_SW_CTRL_APPEND                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6600)
#define REG_PUB_APB_AWURGENT_DBG_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6800)
#define REG_PUB_APB_ARURGENT_DBG_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6804)
#define REG_PUB_APB_LSLP_SRE_SIM                            SCI_ADDR(CTL_PUB_APB_BASE, 0x6808)
#define REG_PUB_APB_PUB0_DUMMY_REG0                         SCI_ADDR(CTL_PUB_APB_BASE, 0x8000)
#define REG_PUB_APB_PUB0_DUMMY_REG1                         SCI_ADDR(CTL_PUB_APB_BASE, 0x8004)
#define REG_PUB_APB_CLOCK_FORCE_ON0                         SCI_ADDR(CTL_PUB_APB_BASE, 0x8008)
#define REG_PUB_APB_CLOCK_FORCE_ON1                         SCI_ADDR(CTL_PUB_APB_BASE, 0x800C)
#define REG_PUB_APB_CLOCK_FORCE_OFF0                        SCI_ADDR(CTL_PUB_APB_BASE, 0x8010)
#define REG_PUB_APB_CLOCK_FORCE_OFF1                        SCI_ADDR(CTL_PUB_APB_BASE, 0x8014)
#define REG_PUB_APB_WCN_ADDR_REMAP                          SCI_ADDR(CTL_PUB_APB_BASE, 0x8018)

/* bits definitions for REG_PUB_APB_DDR_EB, [0x60000000] */

/* bits definitions for REG_PUB_APB_DDR_SOFT_RST, [0x60000004] */

/* bits definitions for REG_PUB_APB_DDR_CHN_SLEEP_CTRL0, [0x60000008] */
#define BIT_PUB_APB_DDR_CHN9_AXI_LP_EN                      ( BIT(25) )
#define BIT_PUB_APB_DDR_CHN8_AXI_LP_EN                      ( BIT(24) )
#define BIT_PUB_APB_DDR_CHN7_AXI_LP_EN                      ( BIT(23) )
#define BIT_PUB_APB_DDR_CHN6_AXI_LP_EN                      ( BIT(22) )
#define BIT_PUB_APB_DDR_CHN5_AXI_LP_EN                      ( BIT(21) )
#define BIT_PUB_APB_DDR_CHN4_AXI_LP_EN                      ( BIT(20) )
#define BIT_PUB_APB_DDR_CHN3_AXI_LP_EN                      ( BIT(19) )
#define BIT_PUB_APB_DDR_CHN2_AXI_LP_EN                      ( BIT(18) )
#define BIT_PUB_APB_DDR_CHN1_AXI_LP_EN                      ( BIT(17) )
#define BIT_PUB_APB_DDR_CHN0_AXI_LP_EN                      ( BIT(16) )
#define BIT_PUB_APB_DDR_CHN9_AXI_STOP_SEL                   ( BIT(9) )
#define BIT_PUB_APB_DDR_CHN8_AXI_STOP_SEL                   ( BIT(8) )
#define BIT_PUB_APB_DDR_CHN7_AXI_STOP_SEL                   ( BIT(7) )
#define BIT_PUB_APB_DDR_CHN6_AXI_STOP_SEL                   ( BIT(6) )
#define BIT_PUB_APB_DDR_CHN5_AXI_STOP_SEL                   ( BIT(5) )
#define BIT_PUB_APB_DDR_CHN4_AXI_STOP_SEL                   ( BIT(4) )
#define BIT_PUB_APB_DDR_CHN3_AXI_STOP_SEL                   ( BIT(3) )
#define BIT_PUB_APB_DDR_CHN2_AXI_STOP_SEL                   ( BIT(2) )
#define BIT_PUB_APB_DDR_CHN1_AXI_STOP_SEL                   ( BIT(1) )
#define BIT_PUB_APB_DDR_CHN0_AXI_STOP_SEL                   ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_AXI_REGU_CTRL, [0x6000000C] */
#define BIT_PUB_APB_MTX_BUSMON_ENABLE                       ( BIT(16) )
#define BIT_PUB_APB_AXI_REGU_AON_AP_EB                      ( BIT(5) )
#define BIT_PUB_APB_AXI_REGU_PUBCP_AG_EB                    ( BIT(4) )
#define BIT_PUB_APB_AXI_REGU_DPU_DCAM_EB                    ( BIT(3) )
#define BIT_PUB_APB_AXI_REGU_PUB_CROSS_EB                   ( BIT(2) )
#define BIT_PUB_APB_AXI_REGU_PUB_CROSS_SOFT_RST             ( BIT(1) )
#define BIT_PUB_APB_AXI_REGU_APB_SOFT_RST                   ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_CFG, [0x600031A0] */
#define BIT_PUB_APB_SOFT_CMD_NUM(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_SOFT_CMD_FC_SEL(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_SOFT_CMD_RESP                           ( BIT(3) )
#define BIT_PUB_APB_SOFT_CMD_DONE                           ( BIT(2) )
#define BIT_PUB_APB_SOFT_CMD_START                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_SEQL, [0x600031A4] */
#define BIT_PUB_APB_SOFT_CMD_SEQL(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_SEQH, [0x600031A8] */
#define BIT_PUB_APB_SOFT_CMD_SEQH(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_STEP, [0x600031AC] */
#define BIT_PUB_APB_SOFT_CMD_STEP(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_QOS_SELECT, [0x600031B0] */

/* bits definitions for REG_PUB_APB_DPLL_PRE_DIV_STATUS, [0x600031C0] */
#define BIT_PUB_APB_DPLL_PRE_DIV_MONITOR_GATE_AUTO_EN_STATUS(x) ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_DPLL_PRE_DIV_MONITOR_WAIT_EN_STATUS(x)  ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_DFI_BWMON_TIMER, [0x600031C4] */
#define BIT_PUB_APB_DFI_MON_IDLE_CNT(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DFI_MON_TIMER_DELAY(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_QOS_SWITCH, [0x600031C8] */
#define BIT_PUB_APB_URGENT_CHN_SEL                          ( BIT(1) )
#define BIT_PUB_APB_QOS_URGENT_SEL                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_BUS_CK_EB, [0x600031CC] */
#define BIT_PUB_APB_CH7_DMC_STOP_CG_EN                      ( BIT(31) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_WCN         ( BIT(30) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_AGCP        ( BIT(29) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_PUBCP       ( BIT(28) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_WTLCP       ( BIT(27) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_AON         ( BIT(26) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_AP          ( BIT(25) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_VDSP        ( BIT(24) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_ISP         ( BIT(23) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_ISP_RAW     ( BIT(22) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_DPU         ( BIT(21) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_GPU         ( BIT(20) )
#define BIT_PUB_APB_HANDSHK_FORCE_OPEN_CLOCK_EN_APCPU       ( BIT(19) )
#define BIT_PUB_APB_CH6_DMC_STOP_CG_EN                      ( BIT(18) )
#define BIT_PUB_APB_CH5_DMC_STOP_CG_EN                      ( BIT(17) )
#define BIT_PUB_APB_CH4_DMC_STOP_CG_EN                      ( BIT(16) )
#define BIT_PUB_APB_CH3_DMC_STOP_CG_EN                      ( BIT(15) )
#define BIT_PUB_APB_CH2_DMC_STOP_CG_EN                      ( BIT(14) )
#define BIT_PUB_APB_CH1_DMC_STOP_CG_EN                      ( BIT(13) )
#define BIT_PUB_APB_CH0_DMC_STOP_CG_EN                      ( BIT(12) )
#define BIT_PUB_APB_LP_STAT_MTX_CG_EN                       ( BIT(11) )
#define BIT_PUB_APB_PUB_PTM_26M_EN                          ( BIT(10) )
#define BIT_PUB_APB_OT_DETECT_CLK_EB                        ( BIT(9) )
#define BIT_PUB_APB_PUB_CLK_CSSYS_PTM_EB                    ( BIT(8) )
#define BIT_PUB_APB_PUB_APB_PTM_REG_EB                      ( BIT(7) )
#define BIT_PUB_APB_PUB_CLK_DMC_PTM_EB                      ( BIT(6) )
#define BIT_PUB_APB_PUB_APB_INT_EB                          ( BIT(5) )
#define BIT_PUB_APB_PUB_APB_BIST_REG_EB                     ( BIT(4) )
#define BIT_PUB_APB_PUB_AHB_QOSC_REG_EB                     ( BIT(3) )
#define BIT_PUB_APB_PUB_AHB_REG_EB                          ( BIT(2) )
#define BIT_PUB_APB_PUB_AHB_BUS_EB                          ( BIT(1) )
#define BIT_PUB_APB_PUB_PHY_REG_EB                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_3, [0x600031D0] */
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_AP_AON_S0              ( BIT(27) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_AP_AON_S0              ( BIT(26) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_AP_AON_M1              ( BIT(25) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_AP_AON_M1              ( BIT(24) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_AP_AON_M0              ( BIT(23) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_AP_AON_M0              ( BIT(22) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_ISP_VDSP_S0            ( BIT(21) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_ISP_VDSP_S0            ( BIT(20) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_ISP_VDSP_M1            ( BIT(19) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_ISP_VDSP_M1            ( BIT(18) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_ISP_VDSP_M0            ( BIT(17) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_ISP_VDSP_M0            ( BIT(16) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_DPU_ISP_S0             ( BIT(15) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_DPU_ISP_S0             ( BIT(14) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_DPU_ISP_M1             ( BIT(13) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_DPU_ISP_M1             ( BIT(12) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_DPU_ISP_M0             ( BIT(11) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_DPU_ISP_M0             ( BIT(10) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_S3             ( BIT(9) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_S3             ( BIT(8) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_S2             ( BIT(7) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_S2             ( BIT(6) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_S1             ( BIT(5) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_S1             ( BIT(4) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_S0             ( BIT(3) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_S0             ( BIT(2) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_M0             ( BIT(1) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_M0             ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_INT_CG_EN, [0x600031D4] */
#define BIT_PUB_APB_INT_DFS_VOTE_DONE_CG_EN                 ( BIT(10) )
#define BIT_PUB_APB_MEM_FW_PUB_CACTIVE_CG_EN                ( BIT(9) )
#define BIT_PUB_APB_INT_DMC_MPU_VIO_CG_EN                   ( BIT(8) )
#define BIT_PUB_APB_INT_MEM_FW_CG_EN                        ( BIT(7) )
#define BIT_PUB_APB_INT_DFS_GIVEUP_CG_EN                    ( BIT(6) )
#define BIT_PUB_APB_INT_DFS_DENY_CG_EN                      ( BIT(5) )
#define BIT_PUB_APB_INT_DFS_ERROR_CG_EN                     ( BIT(4) )
#define BIT_PUB_APB_INT_HARDWARE_DFS_EXIT_CG_EN             ( BIT(3) )
#define BIT_PUB_APB_INT_DFS_COMPLETE_CG_EN                  ( BIT(2) )
#define BIT_PUB_APB_INT_DFI_BUS_MONITOR_CG_EN               ( BIT(1) )
#define BIT_PUB_APB_INT_REQ_PUB_PTM_CG_EN                   ( BIT(0) )

/* bits definitions for REG_PUB_APB_TIMER_ENABLE, [0x600031D8] */
#define BIT_PUB_APB_PTM_TIMER_TRIGGER_WAIT_CNT(x)           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PTM_TIMER_EN                            ( BIT(3) )
#define BIT_PUB_APB_LATMON_TIMER_EN                         ( BIT(2) )
#define BIT_PUB_APB_BWMON_TIMER_EN                          ( BIT(1) )
#define BIT_PUB_APB_DBM_TIMER_EN                            ( BIT(0) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL, [0x600031E0] */
#define BIT_PUB_APB_BV_FV_EQUAL_INC_EN                      ( BIT(29) )
#define BIT_PUB_APB_DBM_PERCENT_SEL(x)                      ( (x) << 26 & (BIT(26)|BIT(27)|BIT(28)) )
#define BIT_PUB_APB_DFS_VOTE_DMC_REF_AG_EN                  ( BIT(25) )
#define BIT_PUB_APB_DFS_APB_ACCESS_CLK_AUTO_EN              ( BIT(24) )
#define BIT_PUB_APB_VOTE_CK_OPEN_CNT(x)                     ( (x) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_PUB_APB_TIMING_WINDOW_SEL(x)                    ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)) )
#define BIT_PUB_APB_VOTE_UNIT_TRANS_EN                      ( BIT(9) )
#define BIT_PUB_APB_SW_FORCE_VOTE_MASK_EN                   ( BIT(8) )
#define BIT_PUB_APB_SW_FORCE_VOTE_MASK(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_VOTE_STATUS, [0x600031E4] */
#define BIT_PUB_APB_VOTE_TAR_FRQ(x)                         ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_VOTE_NEXT_STATE(x)                      ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_PUB_APB_VOTE_CUR_STATE(x)                       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_PUB_APB_VOTE_BW_OVERFLOW                        ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL3, [0x600031F0] */
#define BIT_PUB_APB_DFS_LOCK_DELAY_EN                       ( BIT(31) )
#define BIT_PUB_APB_REG_DFS_LOCK_DELAY_CNT(x)               ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_DFI_MASK_WAIT_LSLP_EN                   ( BIT(24) )
#define BIT_PUB_APB_DFI_MASK_WAIT_TIME_LSLP(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DFI_MASK_WAIT_EN                        ( BIT(8) )
#define BIT_PUB_APB_DFI_MASK_WAIT_TIME(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_QOS_FIXED_CTRL0, [0x600031F4] */
#define BIT_PUB_APB_DMC_FIXED_QOS_EN(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_QOS_FIXED_CTRL1, [0x600031F8] */
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH3(x)                  ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH3(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH2(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH2(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH1(x)                  ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH1(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH0(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH0(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_QOS_FIXED_CTRL2, [0x600031FC] */
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH7(x)                  ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH7(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH6(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH6(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH5(x)                  ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH5(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH4(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH4(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_AXI_QOS_URGENT_REG_0, [0x60003200] */
#define BIT_PUB_APB_ARQOS_URGENT_CH3(x)                     ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH3(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH2(x)                     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH2(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH1(x)                     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH1(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH0(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH0(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_AXI_QOS_URGENT_REG_1, [0x60003204] */
#define BIT_PUB_APB_ARQOS_URGENT_CH7(x)                     ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH7(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH6(x)                     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH6(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH5(x)                     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH5(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH4(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH4(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_INT_CTRL, [0x600032F0] */
#define BIT_PUB_APB_DFS_VOTE_DONE_INT_BYPASS                ( BIT(23) )
#define BIT_PUB_APB_DFS_GIVEUP_INT_BYPASS                   ( BIT(22) )
#define BIT_PUB_APB_DFS_DENY_INT_BYPASS                     ( BIT(21) )
#define BIT_PUB_APB_DMC_MPU_VIO_INT_BYPASS                  ( BIT(20) )
#define BIT_PUB_APB_MEM_FW_INT_BYPASS                       ( BIT(19) )
#define BIT_PUB_APB_DFS_ERROR_INT_BYPASS                    ( BIT(18) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_BYPASS                 ( BIT(17) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_BYPASS                  ( BIT(16) )
#define BIT_PUB_APB_DFS_VOTE_DONE_INT_CLR                   ( BIT(15) )
#define BIT_PUB_APB_DFS_VOTE_DONE_INT_EN                    ( BIT(14) )
#define BIT_PUB_APB_DFS_GIVEUP_INT_CLR                      ( BIT(13) )
#define BIT_PUB_APB_DFS_GIVEUP_INT_EN                       ( BIT(12) )
#define BIT_PUB_APB_DFS_DENY_INT_CLR                        ( BIT(11) )
#define BIT_PUB_APB_DFS_DENY_INT_EN                         ( BIT(10) )
#define BIT_PUB_APB_DMC_MPU_VIO_INT_CLR                     ( BIT(9) )
#define BIT_PUB_APB_DMC_MPU_VIO_INT_EN                      ( BIT(8) )
#define BIT_PUB_APB_MEM_FW_INT_CLR                          ( BIT(7) )
#define BIT_PUB_APB_MEM_FW_INT_EN                           ( BIT(6) )
#define BIT_PUB_APB_DFS_ERROR_INT_CLR                       ( BIT(5) )
#define BIT_PUB_APB_DFS_ERROR_INT_EN                        ( BIT(4) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_CLR                    ( BIT(3) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_EN                     ( BIT(2) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_CLR                     ( BIT(1) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_EN                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_STATUS, [0x600032F4] */
#define BIT_PUB_APB_DFS_HW_MIN_FREQ_UP_FORCE_TRIG_ACK       ( BIT(30) )
#define BIT_PUB_APB_DFS_USED_PLL(x)                         ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_DFS_FC_SEL(x)                           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_APB_SRC_AVAIL_PLL(x)                        ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DFS_URGENT_WAIT_TIMEOUT_FLAG            ( BIT(20) )
#define BIT_PUB_APB_DFS_GIVEUP_INT_RAW                      ( BIT(19) )
#define BIT_PUB_APB_INT_DFS_GIVEUP                          ( BIT(18) )
#define BIT_PUB_APB_DFS_DENY_INT_RAW                        ( BIT(17) )
#define BIT_PUB_APB_INT_DFS_DENY                            ( BIT(16) )
#define BIT_PUB_APB_HW_DFS_FSM_STATE(x)                     ( (x) << 11 & (BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_HW_DFS_FSM_IDLE                         ( BIT(10) )
#define BIT_PUB_APB_INT_DMC_MPU_VIO_RAW                     ( BIT(9) )
#define BIT_PUB_APB_INT_DMC_MPU_VIO                         ( BIT(8) )
#define BIT_PUB_APB_INT_MEM_FW_RAW                          ( BIT(7) )
#define BIT_PUB_APB_INT_MEM_FW                              ( BIT(6) )
#define BIT_PUB_APB_DFS_ERROR_INT_RAW                       ( BIT(5) )
#define BIT_PUB_APB_INT_DFS_ERROR                           ( BIT(4) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_RAW                    ( BIT(3) )
#define BIT_PUB_APB_INT_DFS_COMPLETE                        ( BIT(2) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_RAW                     ( BIT(1) )
#define BIT_PUB_APB_INT_HW_DFS_EXIT                         ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_STATUS1, [0x600032F8] */
#define BIT_PUB_APB_DFS_SW_FSM_STATE(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_DFS_VOTE_DONE_INT_RAW                   ( BIT(1) )
#define BIT_PUB_APB_INT_DFS_VOTE_DONE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_FC_REQ_DELAY, [0x600032FC] */
#define BIT_PUB_APB_DFS_FC_REQ_DELAY(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_PUB_LP_GEN_CTRL, [0x6000333C] */
#define BIT_PUB_APB_DFS_SW_MODE                             ( BIT(6) )
#define BIT_PUB_APB_HW_DFS_STOP_ENABLE                      ( BIT(5) )
#define BIT_PUB_APB_HW_DFS_RESTART_ENABLE                   ( BIT(4) )
#define BIT_PUB_APB_AUTO_STOP_NOC_ENABLE                    ( BIT(3) )
#define BIT_PUB_APB_AUTO_STOP_DFS_ENABLE                    ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_EN                              ( BIT(1) )
#define BIT_PUB_APB_PUB_LP_EN                               ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_0, [0x6000334C] */
#define BIT_PUB_APB_PU_NUM(x)                               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PU_NUM_PUB_CFG(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUBCP_AG_S0            ( BIT(15) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUBCP_AG_S0            ( BIT(14) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUBCP_AG_M1            ( BIT(13) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUBCP_AG_M1            ( BIT(12) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUBCP_AG_M0            ( BIT(11) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUBCP_AG_M0            ( BIT(10) )
#define BIT_PUB_APB_LP_FORCE_ISP_VDSP_S0                    ( BIT(5) )
#define BIT_PUB_APB_LP_EB_ISP_VDSP_S0                       ( BIT(4) )
#define BIT_PUB_APB_LP_FORCE_ISP_VDSP_M1                    ( BIT(3) )
#define BIT_PUB_APB_LP_EB_ISP_VDSP_M1                       ( BIT(2) )
#define BIT_PUB_APB_LP_FORCE_ISP_VDSP_M0                    ( BIT(1) )
#define BIT_PUB_APB_LP_EB_ISP_VDSP_M0                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_1, [0x60003350] */
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S3                     ( BIT(27) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S3                        ( BIT(26) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S2                     ( BIT(25) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S2                        ( BIT(24) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S1                     ( BIT(23) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S1                        ( BIT(22) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S0                     ( BIT(21) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S0                        ( BIT(20) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_M0                     ( BIT(19) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_M0                        ( BIT(18) )
#define BIT_PUB_APB_LP_FORCE_PUBCP_AG_S0                    ( BIT(17) )
#define BIT_PUB_APB_LP_EB_PUBCP_AG_S0                       ( BIT(16) )
#define BIT_PUB_APB_LP_FORCE_PUBCP_AG_M1                    ( BIT(15) )
#define BIT_PUB_APB_LP_EB_PUBCP_AG_M1                       ( BIT(14) )
#define BIT_PUB_APB_LP_FORCE_PUBCP_AG_M0                    ( BIT(13) )
#define BIT_PUB_APB_LP_EB_PUBCP_AG_M0                       ( BIT(12) )
#define BIT_PUB_APB_LP_FORCE_AP_AON_S0                      ( BIT(11) )
#define BIT_PUB_APB_LP_EB_AP_AON_S0                         ( BIT(10) )
#define BIT_PUB_APB_LP_FORCE_AP_AON_M1                      ( BIT(9) )
#define BIT_PUB_APB_LP_EB_AP_AON_M1                         ( BIT(8) )
#define BIT_PUB_APB_LP_FORCE_AP_AON_M0                      ( BIT(7) )
#define BIT_PUB_APB_LP_EB_AP_AON_M0                         ( BIT(6) )
#define BIT_PUB_APB_LP_FORCE_DPU_ISP_S0                     ( BIT(5) )
#define BIT_PUB_APB_LP_EB_DPU_ISP_S0                        ( BIT(4) )
#define BIT_PUB_APB_LP_FORCE_DPU_ISP_M1                     ( BIT(3) )
#define BIT_PUB_APB_LP_EB_DPU_ISP_M1                        ( BIT(2) )
#define BIT_PUB_APB_LP_FORCE_DPU_ISP_M0                     ( BIT(1) )
#define BIT_PUB_APB_LP_EB_DPU_ISP_M0                        ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_2, [0x60003354] */
#define BIT_PUB_APB_LP_NUM_PUB_CFG(x)                       ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_LP_NUM(x)                               ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL, [0x60003358] */
#define BIT_PUB_APB_PUB_CLK_DDR_EN_BY_FENCING_RELEASE       ( BIT(31) )
#define BIT_PUB_APB_DDR_FENCING_EN                          ( BIT(30) )
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_PUB_APB_CP_BASE_ADDR, [0x60003360] */
#define BIT_PUB_APB_AON_BASE_ADDR(x)                        ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_AG_CP_BASE_ADDR(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_CLK_PUB_DFS_CTRL, [0x60003364] */
#define BIT_PUB_APB_PUB_CP_BASE_ADDR(x)                     ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_WTL_CP_BASE_ADDR(x)                     ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_PUB_APB_LP_WAIT_CGM_BUSY_SEL                    ( BIT(2) )
#define BIT_PUB_APB_CGM_PUB_DFS_SEL                         ( BIT(1) )
#define BIT_PUB_APB_CGM_PUB_DFS_EN                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_BIST_CTRL, [0x60003400] */
#define BIT_PUB_APB_BIST_PORT3_ADDR_MUX(x)                  ( (x) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_BIST_PORT2_ADDR_MUX(x)                  ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_BIST_PORT1_ADDR_MUX(x)                  ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_PUB_APB_BIST_PORT0_ADDR_MUX(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BIST_FAIL_FLAG_CH2                      ( BIT(10) )
#define BIT_PUB_APB_BIST_FAIL_FLAG_CH1                      ( BIT(9) )
#define BIT_PUB_APB_BIST_FAIL_FLAG_CH0                      ( BIT(8) )
#define BIT_PUB_APB_BIST_PORT7_EN                           ( BIT(7) )
#define BIT_PUB_APB_BIST_PORT6_EN                           ( BIT(6) )
#define BIT_PUB_APB_BIST_PORT5_EN                           ( BIT(5) )
#define BIT_PUB_APB_BIST_PORT4_EN                           ( BIT(4) )
#define BIT_PUB_APB_BIST_PORT3_EN                           ( BIT(3) )
#define BIT_PUB_APB_BIST_PORT2_EN                           ( BIT(2) )
#define BIT_PUB_APB_BIST_PORT1_EN                           ( BIT(1) )
#define BIT_PUB_APB_BIST_PORT0_EN                           ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_SOFT_RST_CTRL, [0x60003404] */
#define BIT_PUB_APB_BIST_PORT7_ADDR_MUX(x)                  ( (x) << 25 & (BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_BIST_PORT6_ADDR_MUX(x)                  ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_BIST_PORT5_ADDR_MUX(x)                  ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)) )
#define BIT_PUB_APB_BIST_PORT4_ADDR_MUX(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_DMC_SOFT_RST                            ( BIT(2) )
#define BIT_PUB_APB_DCC_SOFT_RST                            ( BIT(1) )
#define BIT_PUB_APB_DDRPHY_SOFT_RST                         ( BIT(0) )

/* bits definitions for REG_PUB_APB_MC_IDLE_WAIT_CTRL, [0x60003414] */
#define BIT_PUB_APB_MC_IDLE_WAIT_CTRL(x)                    ( (x) )

/* bits definitions for REG_PUB_APB_QOS_THRESHOLD_0, [0x60003418] */
#define BIT_PUB_APB_AWQOS_THRESHOLD_PUBCP_AG(x)             ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_PUBCP_AG(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_AWQOS_THRESHOLD_DPU_ISP(x)              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_DPU_ISP(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_AWQOS_THRESHOLD_AP_AON(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_AP_AON(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_AON_AWQOS(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AON_ARQOS(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_QOS_THRESHOLD_1, [0x6000341C] */
#define BIT_PUB_APB_AWQOS_THRESHOLD_ISP_VDSP(x)             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_ISP_VDSP(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DMC_DDR_CLK_CTRL, [0x60004000] */
#define BIT_PUB_APB_PUB_CLK_DFS_SLEEP_AUTO_GATE_EN          ( BIT(31) )
#define BIT_PUB_APB_CLK_AON_APB_AUTO_GATE_EN                ( BIT(30) )
#define BIT_PUB_APB_CLK_DMC_REF_AUTO_GATE_EN                ( BIT(29) )
#define BIT_PUB_APB_PUB_CLK_DFS_AUTO_GATE_EN                ( BIT(28) )
#define BIT_PUB_APB_DMC_DFI_MON_AUTO_GATE_EN                ( BIT(27) )
#define BIT_PUB_APB_DMC_SREF_AUTO_GATE_EN                   ( BIT(26) )
#define BIT_PUB_APB_DDR_PHY_AUTO_GATE_EN                    ( BIT(25) )
#define BIT_PUB_APB_DDR_UMCTL_AUTO_GATE_EN                  ( BIT(24) )
#define BIT_PUB_APB_PUB_CLK_DMC_BIST_EB                     ( BIT(23) )
#define BIT_PUB_APB_PUB_CLK_DMC_REF_EB                      ( BIT(22) )
#define BIT_PUB_APB_PUB_CLK_CSSYS_EB                        ( BIT(21) )
#define BIT_PUB_APB_PUB_CLK_AON_APB_EB                      ( BIT(20) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_FORCE_PHASE(x)           ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_FORCE_PHASE_SEL          ( BIT(17) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_FORCE_BYP                ( BIT(16) )
#define BIT_PUB_APB_PUB_CLK_DFS_EB                          ( BIT(15) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_PTM_EB                   ( BIT(14) )
#define BIT_PUB_APB_PUB_CLK_MLB_D2_EB                       ( BIT(13) )
#define BIT_PUB_APB_PUB_CLK_DMC_D2_EB                       ( BIT(12) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_EB                       ( BIT(11) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_EB                       ( BIT(10) )
#define BIT_PUB_APB_PUB_CLK_DCC_EB                          ( BIT(9) )
#define BIT_PUB_APB_PUB_DDR_CLK_EB                          ( BIT(8) )
#define BIT_PUB_APB_TIMER_CLK_AON_APB_OPEN_EN               ( BIT(7) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_PTM_AUTO_GATE_EN         ( BIT(6) )
#define BIT_PUB_APB_PUB_CLK_MLB_D2_CGM_SEL                  ( BIT(5) )
#define BIT_PUB_APB_PUB_CLK_DMC_D2_CGM_SEL                  ( BIT(4) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_CGM_SEL                  ( BIT(3) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_CGM_SEL                  ( BIT(2) )
#define BIT_PUB_APB_PUB_CLK_DCC_CGM_SEL                     ( BIT(1) )
#define BIT_PUB_APB_PUB_DDR_CLK_CGM_SEL                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_CLK_INIT_SW_START, [0x60004004] */
#define BIT_PUB_APB_DMC_CLK_INIT_SW_START                   ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_CLK_STATE, [0x60004008] */
#define BIT_PUB_APB_DFS_LP_CTRL_CUR_STATE(x)                ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_DMC_CLK_HW_CUR_STATE(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DMC_CUR_CLK_MODE(x)                     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_DMC_CLK_INIT_SW_DONE                    ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_CLK_INIT_CFG, [0x6000400C] */
#define BIT_PUB_APB_PTM_LSLP_CLK_KEEP_ON_EN                 ( BIT(24) )
#define BIT_PUB_APB_DMC_STOP_WAIT_CNT(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_SLEEP_FORCE_FINISH_MODE             ( BIT(8) )
#define BIT_PUB_APB_DESKEW_PLL_PD_DEFAULT_SW                ( BIT(5) )
#define BIT_PUB_APB_DESKEW_PLL_PD_DEFAULT_SEL               ( BIT(4) )
#define BIT_PUB_APB_DMC_SLEEP_CLK_AUTO_MODE                 ( BIT(1) )
#define BIT_PUB_APB_DFS_CLK_AUTO_MODE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CFG, [0x60004010] */
#define BIT_PUB_APB_DSKDLL_DCC_FINE_WAIT_SRC_SW             ( BIT(10) )
#define BIT_PUB_APB_DSKDLL_DCC_COARSE_WAIT_SRC_SW           ( BIT(9) )
#define BIT_PUB_APB_DSKPLL_LOCK_WAIT_SRC_SW                 ( BIT(8) )
#define BIT_PUB_APB_DDL_ADJS_V_WAIT_EN                      ( BIT(3) )
#define BIT_PUB_APB_DSKDLL_DCC_FINE_WAIT_EN                 ( BIT(2) )
#define BIT_PUB_APB_DSKDLL_DCC_COARSE_WAIT_EN               ( BIT(1) )
#define BIT_PUB_APB_DSKPLL_LOCK_WAIT_EN                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT0, [0x60004014] */
#define BIT_PUB_APB_WAIT_CNT_DSKPLL_PWRON_TIME(x)           ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_WAIT_CNT_DSKPLL_LOCK_TIME(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT1, [0x60004018] */
#define BIT_PUB_APB_WAIT_CNT_DSKDLL_DCC_FINE_TIME(x)        ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_WAIT_CNT_DSKDLL_DCC_COARSE_TIME(x)      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT2, [0x6000401C] */
#define BIT_PUB_APB_WAIT_CNT_DFS_RESET_OFF_TIME(x)          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_WAIT_CNT_DFS_RESET_ON_TIME(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_WAIT_CNT_DFS_CLK_OFF_TIME(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT3, [0x60004020] */
#define BIT_PUB_APB_WAIT_CNT_DDL_ADJS_V_HIGH_TIME(x)        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_WAIT_CNT_DDL_ADJS_V_LOW_TIME(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DMC_DDL_CTRL, [0x6000402C] */
#define BIT_PUB_APB_PTEST_DDL_SCOUT                         ( BIT(26) )
#define BIT_PUB_APB_PTEST_DDL_SCIN                          ( BIT(25) )
#define BIT_PUB_APB_PTEST_DDL_SE                            ( BIT(24) )
#define BIT_PUB_APB_DMC_DDL_SW_ADJS(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_PUB_APB_DMC_DDL_SW_UPDATE                       ( BIT(7) )
#define BIT_PUB_APB_DMC_DDL_SW_BYPASS                       ( BIT(6) )
#define BIT_PUB_APB_DMC_DDL_SW_RESET                        ( BIT(5) )
#define BIT_PUB_APB_DMC_DDL_SW_ADJS_VALID                   ( BIT(4) )
#define BIT_PUB_APB_DMC_DDL_CFG_SRC_PURE_SW                 ( BIT(1) )
#define BIT_PUB_APB_DMC_DDL_CFG_SRC_SW                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_PURE_SW_CTRL, [0x60004100] */
#define BIT_PUB_APB_PUB_DFS_SW_LOCK_REQ                     ( BIT(27) )
#define BIT_PUB_APB_PUB_DFS_SW_LOCK_MODE                    ( BIT(26) )
#define BIT_PUB_APB_EMC_CKG_MODE_PURE_SW(x)                 ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_PUB_APB_EMC_CKG_D2_SEL_PURE_SW(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PURE_SW_DFS_CLK_MODE(x)                 ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PURE_SW_DFS_DENY                        ( BIT(16) )
#define BIT_PUB_APB_PURE_SW_DFS_ACK                         ( BIT(15) )
#define BIT_PUB_APB_PURE_SW_DFS_RESP                        ( BIT(14) )
#define BIT_PUB_APB_PURE_SW_DFS_FC_REQ                      ( BIT(13) )
#define BIT_PUB_APB_PURE_SW_DFS_REQ                         ( BIT(12) )
#define BIT_PUB_APB_PURE_SW_DFS_FC_ACK                      ( BIT(11) )
#define BIT_PUB_APB_PURE_SW_DFS_FRQ_SEL(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_EMC_CKG_SEL_PURE_SW(x)                  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DFS_SW_DFS_MODE                         ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL, [0x60004104] */
#define BIT_PUB_APB_PUB_DFS_SWITCH_TYPE                     ( BIT(31) )
#define BIT_PUB_APB_PUB_DFS_SW_SWITCH_PERIOD(x)             ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_DEFAULT(x)             ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_SW_DENY                         ( BIT(7) )
#define BIT_PUB_APB_PUB_DFS_SW_FRQ_SEL(x)                   ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_PUB_DFS_SW_RESP                         ( BIT(3) )
#define BIT_PUB_APB_PUB_DFS_SW_ACK                          ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_SW_REQ                          ( BIT(1) )
#define BIT_PUB_APB_PUB_DFS_SW_ENABLE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL1, [0x60004108] */
#define BIT_PUB_APB_PUB_DFS_SW_UG_DENY_EN                   ( BIT(22) )
#define BIT_PUB_APB_PUB_DFS_SW_LP_DENY_EN                   ( BIT(21) )
#define BIT_PUB_APB_PUB_DFS_SW_UG_CHK_EN                    ( BIT(20) )
#define BIT_PUB_APB_PUB_DFS_SW_CLK_MODE_DEFAULT(x)          ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_SW_CLK_MODE(x)                  ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_D2_DEFAULT(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_D2(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL2, [0x6000410C] */
#define BIT_PUB_APB_PUB_DFS_SW_DDL_ADJS_DEFAULT(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_SW_DDL_ADJS(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL3, [0x60004110] */
#define BIT_PUB_APB_PUB_DFS_URGENT_WAIT_TIMEOUT_PERIOD(x)   ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_PUB_DFS_URGENT_WAIT_TIMEOUT_EN          ( BIT(17) )
#define BIT_PUB_APB_PUB_DFS_SW_URGENT_WAIT_EN               ( BIT(16) )
#define BIT_PUB_APB_PUB_DFS_SW_URGENT_DENY_EN(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL, [0x60004114] */
#define BIT_PUB_APB_PUB_DFS_HW_DDL_ADJS_DEFAULT(x)          ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_PUB_DFS_HW_CLK_MODE_DEFAULT(x)          ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_PUB_DFS_HW_RATIO_D2_DEFAULT(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_HW_RATIO_DEFAULT(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_INITIAL_FREQ(x)              ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_PUB_DFS_HW_STOP                         ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_HW_START                        ( BIT(1) )
#define BIT_PUB_APB_PUB_DFS_HW_ENABLE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL1, [0x60004118] */
#define BIT_PUB_APB_SW_FORCE_EXIT_SW_LP_WAIT_ACK            ( BIT(31) )
#define BIT_PUB_APB_SW_FORCE_EXIT_HW_LP_WAIT_ACK            ( BIT(30) )
#define BIT_PUB_APB_SW_FORCE_EXIT_LP_WAIT_REQ               ( BIT(29) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_FREQ_UP_FORCE_TRIG       ( BIT(28) )
#define BIT_PUB_APB_PUB_DFS_HW_BWMON_MAX_EN                 ( BIT(27) )
#define BIT_PUB_APB_PUB_DFS_HW_BWMON_MAX_FREQ(x)            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_APB_PUB_DFS_HW_AVAIL_FREQ_EN(x)             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PUB_DFS_HW_CHECK_PLL_EN                 ( BIT(12) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_FREQ_UP(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_FREQ_DN(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_EN_UP                    ( BIT(3) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_EN_DN                    ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_LOAD                     ( BIT(1) )
#define BIT_PUB_APB_PUB_DFS_LP_PROT_EN                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL2, [0x6000411C] */
#define BIT_PUB_APB_DFS_INC_REQ_HOLD_EN                     ( BIT(31) )
#define BIT_PUB_APB_DFS_DEC_TO_INC_EN                       ( BIT(30) )
#define BIT_PUB_APB_PUB_DFS_HW_DEC_UG_DENY_EN               ( BIT(29) )
#define BIT_PUB_APB_PUB_DFS_HW_INC_UG_DENY_EN               ( BIT(28) )
#define BIT_PUB_APB_PUB_DFS_HW_DEC_LP_DENY_EN               ( BIT(27) )
#define BIT_PUB_APB_PUB_DFS_HW_INC_LP_DENY_EN               ( BIT(26) )
#define BIT_PUB_APB_PUB_DFS_HW_DEC_UG_CHK_EN                ( BIT(25) )
#define BIT_PUB_APB_PUB_DFS_HW_INC_UG_CHK_EN                ( BIT(24) )
#define BIT_PUB_APB_PUB_DFS_HW_URGENT_WAIT_EN               ( BIT(16) )
#define BIT_PUB_APB_PUB_DFS_HW_URGENT_DENY_EN(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET0, [0x60004120] */
#define BIT_PUB_APB_PUB_DFS_HW_F3_RATIO(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_RATIO(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_RATIO(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_RATIO(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET1, [0x60004124] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_RATIO(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_RATIO(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_RATIO(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_RATIO(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET2, [0x60004128] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_RATIO_D2(x)               ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_RATIO_D2(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_RATIO_D2(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_RATIO_D2(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_HW_F3_RATIO_D2(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_RATIO_D2(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_RATIO_D2(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_RATIO_D2(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET3, [0x6000412C] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_CLK_MODE(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_CLK_MODE(x)               ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_CLK_MODE(x)               ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_CLK_MODE(x)               ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_PUB_DFS_HW_F3_CLK_MODE(x)               ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_CLK_MODE(x)               ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_CLK_MODE(x)               ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_CLK_MODE(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET4, [0x60004130] */
#define BIT_PUB_APB_PUB_DFS_HW_F1_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET5, [0x60004134] */
#define BIT_PUB_APB_PUB_DFS_HW_F3_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET6, [0x60004138] */
#define BIT_PUB_APB_PUB_DFS_HW_F5_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET7, [0x6000413C] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET8, [0x60004140] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_REQ_DURATION(x)           ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_REQ_DURATION(x)           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_REQ_DURATION(x)           ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_REQ_DURATION(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_HW_F3_REQ_DURATION(x)           ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_REQ_DURATION(x)           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_REQ_DURATION(x)           ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_REQ_DURATION(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_HW_DESKEWPLL_PD_CTRL0, [0x60004144] */
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_DEEP_SLEEP_MODE(x)     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_AUTO_LIGHT_SLEEP_MODE(x) ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_SMART_LIGHT_SLEEP_MODE(x) ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_DEFAULT_BYP_MODE(x)    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_HW_DESKEWPLL_PD_CTRL1, [0x60004148] */
#define BIT_PUB_APB_DFS_FC_ACK_ASSERT_WAIT_CNT(x)           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DFS_HW_FRQ_SEL_SW(x)                    ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_DFS_HW_FRQ_SEL_SET                      ( BIT(3) )
#define BIT_PUB_APB_DFS_CUR_CLK_MODE_TOGGLE                 ( BIT(2) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_DEFAULT_HIGH           ( BIT(1) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PO_AHEAD_EN               ( BIT(0) )

/* bits definitions for REG_PUB_APB_DVS_CTRL_0, [0x60004150] */
#define BIT_PUB_APB_VDDCORE_VOL_F7(x)                       ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_VDDCORE_VOL_F6(x)                       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_APB_VDDCORE_VOL_F5(x)                       ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_APB_VDDCORE_VOL_F4(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_VDDCORE_VOL_F3(x)                       ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_VDDCORE_VOL_F2(x)                       ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_VDDCORE_VOL_F1(x)                       ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_VDDCORE_VOL_F0(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_DVS_CTRL_1, [0x60004154] */
#define BIT_PUB_APB_VDDCORE_VOL_CUR(x)                      ( (x) << 26 & (BIT(26)|BIT(27)|BIT(28)) )
#define BIT_PUB_APB_VDDCORE_VOL_DFLT(x)                     ( (x) << 23 & (BIT(23)|BIT(24)|BIT(25)) )
#define BIT_PUB_APB_VDDCORE_VOL_SET                         ( BIT(22) )
#define BIT_PUB_APB_VDDCORE_DVS_ACK                         ( BIT(21) )
#define BIT_PUB_APB_VDDCORE_DVS_REQ_SW                      ( BIT(20) )
#define BIT_PUB_APB_VDDCORE_DVS_VOL_SW(x)                   ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_VDDCORE_DVS_DEC_EN(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_VDDCORE_DVS_INC_EN(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DVS_CTRL_2, [0x60004158] */
#define BIT_PUB_APB_VDDCORE_DVS_VOL(x)                      ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_VDDCORE_DVS_REQ                         ( BIT(20) )
#define BIT_PUB_APB_HW_DFS_AUTO_DIS                         ( BIT(19) )
#define BIT_PUB_APB_HW_DFS_TARGET_FSP(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_VDDCORE_DVS_DN_SW_EN(x)                 ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_VDDCORE_DVS_UP_SW_EN(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DVS_DEC_BLOCK_TIME, [0x6000415C] */
#define BIT_PUB_APB_DVS_DEC_BLOCK_TIME(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_MASTER_EN, [0x60004310] */
#define BIT_PUB_APB_DFS_VOTE_DEC_EN                         ( BIT(31) )
#define BIT_PUB_APB_VOTE_HW_DFS_DEC_MASK_EN                 ( BIT(30) )
#define BIT_PUB_APB_VOTE_HW_DFS_INC_MASK_EN                 ( BIT(29) )

/* bits definitions for REG_PUB_APB_VOTE_FSM_CNT, [0x60004314] */
#define BIT_PUB_APB_DFS_INTERVAL_CNT(x)                     ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_VOTE_INTERVAL_CNT(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_0, [0x60004318] */
#define BIT_PUB_APB_THRD_INC_F1(x)                          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_THRD_INC_F0(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_1, [0x6000431C] */
#define BIT_PUB_APB_THRD_INC_F3(x)                          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_THRD_INC_F2(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_2, [0x60004320] */
#define BIT_PUB_APB_THRD_INC_F5(x)                          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_THRD_INC_F4(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_3, [0x60004324] */
#define BIT_PUB_APB_THRD_INC_F7(x)                          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_THRD_INC_F6(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_TEST_DSKPLL_BIST_CNT, [0x60004328] */
#define BIT_PUB_APB_TEST_DSKPLL_BIST_CNT(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_PUB_STATUS_MON_CTRL, [0x60006200] */
#define BIT_PUB_APB_DFS_COUNT_EN                            ( BIT(9) )
#define BIT_PUB_APB_PUB_DFS_STA_EN                          ( BIT(8) )
#define BIT_PUB_APB_DMC_ST_MON_SEL(x)                       ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_PUB_APB_PUB_TOP_MON_EN                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_ST_IDLE_CYC_CNT, [0x60006204] */
#define BIT_PUB_APB_DMC_ST_IDLE_CYCLE_CNT(x)                ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_WR_CYC_CNT, [0x60006208] */
#define BIT_PUB_APB_DMC_ST_WRITE_CYCLE_CNT(x)               ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_RD_CYC_CNT, [0x6000620C] */
#define BIT_PUB_APB_DMC_ST_READ_CYCLE_CNT(x)                ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_SR_CYC_CNT, [0x60006210] */
#define BIT_PUB_APB_DMC_ST_SREF_CYCLE_CNT(x)                ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_LS_CYC_CNT, [0x60006214] */
#define BIT_PUB_APB_DMC_ST_LIGHT_CYCLE_CNT(x)               ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_LS_TIME_CNT, [0x60006218] */
#define BIT_PUB_APB_DMC_ST_SREF_CNT(x)                      ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_DMC_ST_LIGHT_CNT(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F0_CYC_CNT, [0x6000621C] */
#define BIT_PUB_APB_DFS_F0_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F1_CYC_CNT, [0x60006220] */
#define BIT_PUB_APB_DFS_F1_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F2_CYC_CNT, [0x60006224] */
#define BIT_PUB_APB_DFS_F2_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F3_CYC_CNT, [0x60006228] */
#define BIT_PUB_APB_DFS_F3_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F4_CYC_CNT, [0x6000622C] */
#define BIT_PUB_APB_DFS_F4_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F5_CYC_CNT, [0x60006230] */
#define BIT_PUB_APB_DFS_F5_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F6_CYC_CNT, [0x60006234] */
#define BIT_PUB_APB_DFS_F6_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F7_CYC_CNT, [0x60006238] */
#define BIT_PUB_APB_DFS_F7_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_CNT, [0x6000623C] */
#define BIT_PUB_APB_PUB_DFS_DBM_BW_VALID_BYPASS_PERIOD(x)   ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_PUB_APB_DFS_COUNT(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_DPU, [0x60006400] */
#define BIT_PUB_APB_DPU_BV_EN                               ( BIT(31) )
#define BIT_PUB_APB_DPU_FV_EN                               ( BIT(30) )
#define BIT_PUB_APB_HW_VOTE_DPU_FLAG_EN                     ( BIT(29) )
#define BIT_PUB_APB_BFV_VOTE_DPU_SW                         ( BIT(25) )
#define BIT_PUB_APB_VOTE_DPU_ACK                            ( BIT(23) )
#define BIT_PUB_APB_VOTE_DPU_HW_ACK                         ( BIT(22) )
#define BIT_PUB_APB_FREQ_VOTE_DPU(x)                        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_DPU(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_DCAM, [0x60006404] */
#define BIT_PUB_APB_DCAM_BV_EN                              ( BIT(31) )
#define BIT_PUB_APB_DCAM_FV_EN                              ( BIT(30) )
#define BIT_PUB_APB_HW_VOTE_DCAM_FLAG_EN                    ( BIT(29) )
#define BIT_PUB_APB_BFV_VOTE_DCAM_SW                        ( BIT(25) )
#define BIT_PUB_APB_VOTE_DCAM_ACK                           ( BIT(23) )
#define BIT_PUB_APB_VOTE_DCAM_HW_ACK                        ( BIT(22) )
#define BIT_PUB_APB_FREQ_VOTE_DCAM(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_DCAM(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_PUBCP, [0x60006408] */
#define BIT_PUB_APB_PUBCP_BV_EN                             ( BIT(31) )
#define BIT_PUB_APB_PUBCP_FV_EN                             ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_PUBCP_FLAG                      ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_PUBCP_FLAG                    ( BIT(24) )
#define BIT_PUB_APB_VOTE_PUBCP_ACK                          ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_PUBCP(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_PUBCP(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WTLCP, [0x6000640C] */
#define BIT_PUB_APB_WTLCP_BV_EN                             ( BIT(31) )
#define BIT_PUB_APB_WTLCP_FV_EN                             ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_WTLCP_FLAG                      ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP_FLAG                    ( BIT(24) )
#define BIT_PUB_APB_VOTE_WTLCP_ACK                          ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_WTLCP(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WTLCP1, [0x60006410] */
#define BIT_PUB_APB_WTLCP1_BV_EN                            ( BIT(31) )
#define BIT_PUB_APB_WTLCP1_FV_EN                            ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_WTLCP1_FLAG                     ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP1_FLAG                   ( BIT(24) )
#define BIT_PUB_APB_VOTE_WTLCP1_ACK                         ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP1(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_WTLCP1(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_AGCP, [0x60006414] */
#define BIT_PUB_APB_AGCP_BV_EN                              ( BIT(31) )
#define BIT_PUB_APB_AGCP_FV_EN                              ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_AGCP_FLAG                       ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_AGCP_FLAG                     ( BIT(24) )
#define BIT_PUB_APB_VOTE_AGCP_ACK                           ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_AGCP(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_AGCP(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_SW, [0x60006418] */
#define BIT_PUB_APB_SW_BV_EN                                ( BIT(31) )
#define BIT_PUB_APB_SW_FV_EN                                ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_SW_FLAG                         ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_SW_FLAG                       ( BIT(24) )
#define BIT_PUB_APB_VOTE_SW_ACK                             ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_SW(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_SW(x)                           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_VDSP, [0x6000641C] */
#define BIT_PUB_APB_VDSP_BV_EN                              ( BIT(31) )
#define BIT_PUB_APB_VDSP_FV_EN                              ( BIT(30) )
#define BIT_PUB_APB_HW_VOTE_VDSP_FLAG_EN                    ( BIT(29) )
#define BIT_PUB_APB_BFV_VOTE_VDSP_SW                        ( BIT(25) )
#define BIT_PUB_APB_VOTE_VDSP_ACK                           ( BIT(23) )
#define BIT_PUB_APB_VOTE_VDSP_HW_ACK                        ( BIT(22) )
#define BIT_PUB_APB_FREQ_VOTE_VDSP(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_VDSP(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WCN, [0x60006420] */
#define BIT_PUB_APB_WCN_BV_EN                               ( BIT(31) )
#define BIT_PUB_APB_WCN_FV_EN                               ( BIT(30) )
#define BIT_PUB_APB_HW_VOTE_WCN_FLAG_EN                     ( BIT(29) )
#define BIT_PUB_APB_BFV_VOTE_WCN_SW                         ( BIT(25) )
#define BIT_PUB_APB_VOTE_WCN_ACK                            ( BIT(23) )
#define BIT_PUB_APB_VOTE_WCN_HW_ACK                         ( BIT(22) )
#define BIT_PUB_APB_FREQ_VOTE_WCN(x)                        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_BW_VOTE_WCN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_DFS_GFREE_CTRL, [0x60006500] */
#define BIT_PUB_APB_DFS_GFREE_HW_BYPASS_EN                  ( BIT(24) )
#define BIT_PUB_APB_DFS_GFREE_SW_OPEN_DELAY(x)              ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_DFS_GFREE_SW_CLOSE_DELAY(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_PUB_APB_DFS_GFREE_SW_BYPASS                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL_APPEND, [0x60006600] */
#define BIT_PUB_APB_PUB_DFS_SW_SWITCH_PERIOD_APPEND(x)      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_AWURGENT_DBG_CTRL, [0x60006800] */
#define BIT_PUB_APB_AWURGENT_DBG_WCN(x)                     ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AWURGENT_DBG_AGCP(x)                    ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_AWURGENT_DBG_WTLCP(x)                   ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_AWURGENT_DBG_PUBCP(x)                   ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_AWURGENT_DBG_AON(x)                     ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_APB_AWURGENT_DBG_AP(x)                      ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_AWURGENT_DBG_VDSP(x)                    ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_APB_AWURGENT_DBG_MM_ISP(x)                  ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_AWURGENT_DBG_ISP_RAW(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AWURGENT_DBG_DPU(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_AWURGENT_DBG_GPU(x)                     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_AWURGENT_DBG_CPU(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_ARURGENT_DBG_CTRL, [0x60006804] */
#define BIT_PUB_APB_ARURGENT_DBG_WCN(x)                     ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PUB_APB_ARURGENT_DBG_AGCP(x)                    ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_ARURGENT_DBG_WTLCP(x)                   ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_ARURGENT_DBG_PUBCP(x)                   ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_ARURGENT_DBG_AON(x)                     ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_APB_ARURGENT_DBG_AP(x)                      ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_ARURGENT_DBG_VDSP(x)                    ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_APB_ARURGENT_DBG_MM_ISP(x)                  ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_ARURGENT_DBG_ISP_RAW(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_APB_ARURGENT_DBG_DPU(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_ARURGENT_DBG_GPU(x)                     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_ARURGENT_DBG_CPU(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_LSLP_SRE_SIM, [0x60006808] */
#define BIT_PUB_APB_SRE_FLAG_DBG                            ( BIT(1) )
#define BIT_PUB_APB_SRE_REQ_DBG                             ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB0_DUMMY_REG0, [0x60008000] */
#define BIT_PUB_APB_PUB0_DUMMY_REG0(x)                      ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_DPLL0_CLKOUT_DIV32_EN                   ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB0_DUMMY_REG1, [0x60008004] */
#define BIT_PUB_APB_PUB0_DUMMY_REG1(x)                      ( (x) )

/* bits definitions for REG_PUB_APB_CLOCK_FORCE_ON0, [0x60008008] */
#define BIT_PUB_APB_CLOCK_FORCE_ON0(x)                      ( (x) )

/* bits definitions for REG_PUB_APB_CLOCK_FORCE_ON1, [0x6000800C] */
#define BIT_PUB_APB_CLOCK_FORCE_ON1(x)                      ( (x) )

/* bits definitions for REG_PUB_APB_CLOCK_FORCE_OFF0, [0x60008010] */
#define BIT_PUB_APB_CLOCK_FORCE_OFF0(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_CLOCK_FORCE_OFF1, [0x60008014] */
#define BIT_PUB_APB_CLOCK_FORCE_OFF1(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_WCN_ADDR_REMAP, [0x60008018] */
#define BIT_PUB_APB_WCN_REMAP_SIZE_SEL(x)                   ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_WCN_BASE_ADDR(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* vars definitions for controller CTL_PUB_APB */


#endif /* __PUB_APB_H____ */