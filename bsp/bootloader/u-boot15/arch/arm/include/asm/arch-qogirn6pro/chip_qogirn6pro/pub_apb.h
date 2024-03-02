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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/pub/SharkL6Pro_PUB_CTL_APB_Control_Register.xls;PUB APB Reg
 *     Revision : 231409
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
#define CTL_PUB_APB_BASE                SCI_IOMAP(0x60050000)
#endif

/* registers definitions for CTL_PUB_APB, 0x60050000 */
#define REG_PUB_APB_DDR_EB                                  SCI_ADDR(CTL_PUB_APB_BASE, 0x0000)
#define REG_PUB_APB_DDR_SOFT_RST                            SCI_ADDR(CTL_PUB_APB_BASE, 0x0004)
#define REG_PUB_APB_DDL_MASK_CTRL                           SCI_ADDR(CTL_PUB_APB_BASE, 0x1000)
#define REG_PUB_APB_LP_COMPITABLE_WITH_L3                   SCI_ADDR(CTL_PUB_APB_BASE, 0x3100)
#define REG_PUB_APB_PUB_DDR_CHN_LP_CTRL                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3104)
#define REG_PUB_APB_AXI_LPC_CTRL_PUNUM_CFG_0                SCI_ADDR(CTL_PUB_APB_BASE, 0x3108)
#define REG_PUB_APB_AXI_LPC_CTRL_PUNUM_DBG                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3120)
#define REG_PUB_APB_MTX_BUS_MON_EN                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3140)
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
#define REG_PUB_APB_AXI_LPC_CTRL_1                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3354)
#define REG_PUB_APB_FENCING_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x3358)
#define REG_PUB_APB_PHYCP_BASE_ADDR                         SCI_ADDR(CTL_PUB_APB_BASE, 0x3360)
#define REG_PUB_APB_PSCP_BASE_ADDR                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3364)
#define REG_PUB_APB_AGCP_ISE_BASE_ADDR                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3368)
#define REG_PUB_APB_CLK_PUB_DFS_CTRL                        SCI_ADDR(CTL_PUB_APB_BASE, 0x336C)
#define REG_PUB_APB_FENCING_CTRL_FSP_0                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3370)
#define REG_PUB_APB_FENCING_CTRL_FSP_1                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3374)
#define REG_PUB_APB_FENCING_CTRL_FSP_2                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3378)
#define REG_PUB_APB_FENCING_CTRL_FSP_3                      SCI_ADDR(CTL_PUB_APB_BASE, 0x337C)
#define REG_PUB_APB_FENCING_CTRL_FSP_4                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3380)
#define REG_PUB_APB_FENCING_CTRL_FSP_5                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3384)
#define REG_PUB_APB_FENCING_CTRL_FSP_6                      SCI_ADDR(CTL_PUB_APB_BASE, 0x3388)
#define REG_PUB_APB_FENCING_CTRL_FSP_7                      SCI_ADDR(CTL_PUB_APB_BASE, 0x338C)
#define REG_PUB_APB_BIST_CTRL                               SCI_ADDR(CTL_PUB_APB_BASE, 0x3400)
#define REG_PUB_APB_PUB_SOFT_RST_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x3404)
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
#define REG_PUB_APB_CGM_EN_LEGACY_STYLE_EN                  SCI_ADDR(CTL_PUB_APB_BASE, 0x4030)
#define REG_PUB_APB_CGM_EN_LP_STAT_STYLE_EN                 SCI_ADDR(CTL_PUB_APB_BASE, 0x4034)
#define REG_PUB_APB_AXI_MST_CGM_EN_SW_CTRL                  SCI_ADDR(CTL_PUB_APB_BASE, 0x4038)
#define REG_PUB_APB_DMC_AXI_CH_CGM_EN_SW_CTRL               SCI_ADDR(CTL_PUB_APB_BASE, 0x403C)
#define REG_PUB_APB_DDR_CLK_ROOT_BACKPRES_EN                SCI_ADDR(CTL_PUB_APB_BASE, 0x4040)
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
#define REG_PUB_APB_HW_DESKEWPLL_PD_CTRL0                   SCI_ADDR(CTL_PUB_APB_BASE, 0x4144)
#define REG_PUB_APB_HW_DESKEWPLL_PD_CTRL1                   SCI_ADDR(CTL_PUB_APB_BASE, 0x4148)
#define REG_PUB_APB_VOTE_MASTER_EN                          SCI_ADDR(CTL_PUB_APB_BASE, 0x4310)
#define REG_PUB_APB_VOTE_FSM_CNT                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4314)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_0                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4318)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_1                    SCI_ADDR(CTL_PUB_APB_BASE, 0x431C)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_2                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4320)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_3                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4324)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_4                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4328)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_5                    SCI_ADDR(CTL_PUB_APB_BASE, 0x432C)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_6                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4330)
#define REG_PUB_APB_THRESHOLD_INC_FREQ_7                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4334)
#define REG_PUB_APB_TEST_DSKPLL_BIST_CNT                    SCI_ADDR(CTL_PUB_APB_BASE, 0x4340)
#define REG_PUB_APB_PUB_MON_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4700)
#define REG_PUB_APB_PUB_MON_MODE                            SCI_ADDR(CTL_PUB_APB_BASE, 0x4704)
#define REG_PUB_APB_PUB_MON_OUT_SEL                         SCI_ADDR(CTL_PUB_APB_BASE, 0x4708)
#define REG_PUB_APB_PUB_DFS_TIMEOUT_TH                      SCI_ADDR(CTL_PUB_APB_BASE, 0x470C)
#define REG_PUB_APB_PUB_MON_TRANS_BASE_ADDR                 SCI_ADDR(CTL_PUB_APB_BASE, 0x4710)
#define REG_PUB_APB_PUB_MON_TRANS_CTRL                      SCI_ADDR(CTL_PUB_APB_BASE, 0x4714)
#define REG_PUB_APB_PUB_MON_F0_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4718)
#define REG_PUB_APB_PUB_MON_F1_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x471C)
#define REG_PUB_APB_PUB_MON_F2_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4720)
#define REG_PUB_APB_PUB_MON_F3_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4724)
#define REG_PUB_APB_PUB_MON_F4_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4728)
#define REG_PUB_APB_PUB_MON_F5_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x472C)
#define REG_PUB_APB_PUB_MON_F6_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4730)
#define REG_PUB_APB_PUB_MON_F7_EN                           SCI_ADDR(CTL_PUB_APB_BASE, 0x4734)
#define REG_PUB_APB_PUB_MON_USER_QOS                        SCI_ADDR(CTL_PUB_APB_BASE, 0x4738)
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
#define REG_PUB_APB_VOTE_CTRL_DPU_0                         SCI_ADDR(CTL_PUB_APB_BASE, 0x6400)
#define REG_PUB_APB_VOTE_CTRL_DCAM_0                        SCI_ADDR(CTL_PUB_APB_BASE, 0x6404)
#define REG_PUB_APB_VOTE_CTRL_PUBCP_0                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6408)
#define REG_PUB_APB_VOTE_CTRL_WTLCP_0                       SCI_ADDR(CTL_PUB_APB_BASE, 0x640C)
#define REG_PUB_APB_VOTE_CTRL_WTLCP1_0                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6410)
#define REG_PUB_APB_VOTE_CTRL_AGCP_0                        SCI_ADDR(CTL_PUB_APB_BASE, 0x6414)
#define REG_PUB_APB_VOTE_CTRL_SW_0                          SCI_ADDR(CTL_PUB_APB_BASE, 0x6418)
#define REG_PUB_APB_VOTE_CTRL_DPU_1                         SCI_ADDR(CTL_PUB_APB_BASE, 0x6420)
#define REG_PUB_APB_VOTE_CTRL_DCAM_1                        SCI_ADDR(CTL_PUB_APB_BASE, 0x6424)
#define REG_PUB_APB_VOTE_CTRL_PUBCP_1                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6428)
#define REG_PUB_APB_VOTE_CTRL_WTLCP_1                       SCI_ADDR(CTL_PUB_APB_BASE, 0x642C)
#define REG_PUB_APB_VOTE_CTRL_WTLCP1_1                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6430)
#define REG_PUB_APB_VOTE_CTRL_AGCP_1                        SCI_ADDR(CTL_PUB_APB_BASE, 0x6434)
#define REG_PUB_APB_VOTE_CTRL_SW_1                          SCI_ADDR(CTL_PUB_APB_BASE, 0x6438)
#define REG_PUB_APB_DFS_GFREE_CTRL                          SCI_ADDR(CTL_PUB_APB_BASE, 0x6500)
#define REG_PUB_APB_DFS_SW_CTRL_APPEND                      SCI_ADDR(CTL_PUB_APB_BASE, 0x6600)
#define REG_PUB_APB_AWURGENT_DBG_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6800)
#define REG_PUB_APB_ARURGENT_DBG_CTRL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x6804)
#define REG_PUB_APB_LSLP_SRE_SIM                            SCI_ADDR(CTL_PUB_APB_BASE, 0x6808)
#define REG_PUB_APB_PUB_TOP_DBG_1                           SCI_ADDR(CTL_PUB_APB_BASE, 0x680C)
#define REG_PUB_APB_PUB_TOP_DBG_2                           SCI_ADDR(CTL_PUB_APB_BASE, 0x6810)
#define REG_PUB_APB_PUB0_DUMMY_REG0                         SCI_ADDR(CTL_PUB_APB_BASE, 0x8000)
#define REG_PUB_APB_PUB0_DUMMY_REG1                         SCI_ADDR(CTL_PUB_APB_BASE, 0x8004)

/* bits definitions for REG_PUB_APB_DDR_EB, [0x60050000] */

/* bits definitions for REG_PUB_APB_DDR_SOFT_RST, [0x60050004] */

/* bits definitions for REG_PUB_APB_DDL_MASK_CTRL, [0x60051000] */
#define BIT_PUB_APB_DDL_MASK_CTRL(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_LP_COMPITABLE_WITH_L3, [0x60053100] */
#define BIT_PUB_APB_LP_CTRL_DMC_SLEEP_EN                    ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_DDR_CHN_LP_CTRL, [0x60053104] */
#define BIT_PUB_APB_DDR_CHN7_AXI_LP_EN                      ( BIT(15) )
#define BIT_PUB_APB_DDR_CHN6_AXI_LP_EN                      ( BIT(14) )
#define BIT_PUB_APB_DDR_CHN5_AXI_LP_EN                      ( BIT(13) )
#define BIT_PUB_APB_DDR_CHN4_AXI_LP_EN                      ( BIT(12) )
#define BIT_PUB_APB_DDR_CHN3_AXI_LP_EN                      ( BIT(11) )
#define BIT_PUB_APB_DDR_CHN2_AXI_LP_EN                      ( BIT(10) )
#define BIT_PUB_APB_DDR_CHN1_AXI_LP_EN                      ( BIT(9) )
#define BIT_PUB_APB_DDR_CHN0_AXI_LP_EN                      ( BIT(8) )
#define BIT_PUB_APB_DDR_CH7_AXI_STOP_SEL                    ( BIT(7) )
#define BIT_PUB_APB_DDR_CH6_AXI_STOP_SEL                    ( BIT(6) )
#define BIT_PUB_APB_DDR_CH5_AXI_STOP_SEL                    ( BIT(5) )
#define BIT_PUB_APB_DDR_CH4_AXI_STOP_SEL                    ( BIT(4) )
#define BIT_PUB_APB_DDR_CH3_AXI_STOP_SEL                    ( BIT(3) )
#define BIT_PUB_APB_DDR_CH2_AXI_STOP_SEL                    ( BIT(2) )
#define BIT_PUB_APB_DDR_CH1_AXI_STOP_SEL                    ( BIT(1) )
#define BIT_PUB_APB_DDR_CH0_AXI_STOP_SEL                    ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_PUNUM_CFG_0, [0x60053108] */
#define BIT_PUB_APB_PU_NUM_PUB_CFG_S2(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PU_NUM_PUB_CFG_S1(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PU_NUM_PUB_CFG_S0(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PU_NUM_PUB_CFG_M0(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_PUNUM_DBG, [0x60053120] */
#define BIT_PUB_APB_PU_NUM_DBG_ASYNCB_W(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_MTX_BUS_MON_EN, [0x60053140] */
#define BIT_PUB_APB_MATRIX_BUSMON_CFG_EN                    ( BIT(6) )
#define BIT_PUB_APB_MATRIX_BUSMON_CROSS_EN                  ( BIT(5) )
#define BIT_PUB_APB_MATRIX_BUSMON_CPACC_EN                  ( BIT(4) )
#define BIT_PUB_APB_MATRIX_BUSMON_CPCPU_EN                  ( BIT(3) )
#define BIT_PUB_APB_MATRIX_BUSMON_AP_AON_EN                 ( BIT(2) )
#define BIT_PUB_APB_MATRIX_BUSMON_DCAM_EN                   ( BIT(1) )
#define BIT_PUB_APB_MATRIX_BUSMON_MM_EN                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_CFG, [0x600531A0] */
#define BIT_PUB_APB_SOFT_CMD_NUM(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_SOFT_CMD_FC_SEL(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_SOFT_CMD_RESP                           ( BIT(3) )
#define BIT_PUB_APB_SOFT_CMD_DONE                           ( BIT(2) )
#define BIT_PUB_APB_SOFT_CMD_START                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_SEQL, [0x600531A4] */
#define BIT_PUB_APB_SOFT_CMD_SEQL(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_SEQH, [0x600531A8] */
#define BIT_PUB_APB_SOFT_CMD_SEQH(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_STEP, [0x600531AC] */
#define BIT_PUB_APB_SOFT_CMD_STEP(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_QOS_SELECT, [0x600531B0] */

/* bits definitions for REG_PUB_APB_DPLL_PRE_DIV_STATUS, [0x600531C0] */
#define BIT_PUB_APB_DPLL_PRE_DIV_MONITOR_GATE_AUTO_EN_STATUS(x) ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_DPLL_PRE_DIV_MONITOR_WAIT_EN_STATUS(x)  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_DFI_BWMON_TIMER, [0x600531C4] */
#define BIT_PUB_APB_DFI_MON_IDLE_CNT(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DFI_MON_TIMER_DELAY(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_QOS_SWITCH, [0x600531C8] */
#define BIT_PUB_APB_URGENT_CHN_SEL                          ( BIT(1) )
#define BIT_PUB_APB_QOS_URGENT_SEL                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_BUS_CK_EB, [0x600531CC] */
#define BIT_PUB_APB_PUB_CLK_CORE_REG_EB                     ( BIT(23) )
#define BIT_PUB_APB_DPLL_PRE_DIV_REG_EB                     ( BIT(22) )
#define BIT_PUB_APB_CGM_PTM_26M_EN                          ( BIT(21) )
#define BIT_PUB_APB_PUB_APB_DVFS_REG_EB                     ( BIT(20) )
#define BIT_PUB_APB_PUB_APB_CROSS_MTX_REG_EB                ( BIT(19) )
#define BIT_PUB_APB_PUB_APB_CPCPU_MTX_REG_EB                ( BIT(18) )
#define BIT_PUB_APB_PUB_APB_CP_ACC_MTX_REG_EB               ( BIT(17) )
#define BIT_PUB_APB_PUB_APB_AP_AON_ISE_IPA_MTX_REG_EB       ( BIT(16) )
#define BIT_PUB_APB_PUB_APB_MM_MTX_REG_EB                   ( BIT(15) )
#define BIT_PUB_APB_PUB_APB_DCAM_DPU_MTX_REG_EB             ( BIT(14) )
#define BIT_PUB_APB_PUB_DFIMON_REG_EB                       ( BIT(13) )
#define BIT_PUB_APB_PUB_DMC_REG_EB                          ( BIT(12) )
#define BIT_PUB_APB_LP_STAT_MTX_CG_EN                       ( BIT(11) )
#define BIT_PUB_APB_CHN_DMC_STOP_CG_EN                      ( BIT(10) )
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

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_3, [0x600531D0] */
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_DBG_ASYNCB_W           ( BIT(7) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_DBG_ASYNCB_W           ( BIT(6) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_S1             ( BIT(5) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_S1             ( BIT(4) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_S0             ( BIT(3) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_S0             ( BIT(2) )
#define BIT_PUB_APB_CSYSACK_SYNC_SEL_PUB_CFG_M0             ( BIT(1) )
#define BIT_PUB_APB_CACTIVE_SYNC_SEL_PUB_CFG_M0             ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_INT_CG_EN, [0x600531D4] */
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

/* bits definitions for REG_PUB_APB_TIMER_ENABLE, [0x600531D8] */
#define BIT_PUB_APB_PTM_TIMER_EN                            ( BIT(3) )
#define BIT_PUB_APB_LATMON_TIMER_EN                         ( BIT(2) )
#define BIT_PUB_APB_BWMON_TIMER_EN                          ( BIT(1) )
#define BIT_PUB_APB_DBM_TIMER_EN                            ( BIT(0) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL, [0x600531E0] */
#define BIT_PUB_APB_BWVOTE_SUB_BWMON_EN                     ( BIT(30) )
#define BIT_PUB_APB_BV_FV_EQUAL_INC_EN                      ( BIT(29) )
#define BIT_PUB_APB_DBM_PERCENT_SEL(x)                      ( (x) << 26 & (BIT(26)|BIT(27)|BIT(28)) )
#define BIT_PUB_APB_DFS_VOTE_DMC_REF_AG_EN                  ( BIT(25) )
#define BIT_PUB_APB_DFS_APB_ACCESS_CLK_AUTO_EN              ( BIT(24) )
#define BIT_PUB_APB_VOTE_CK_OPEN_CNT(x)                     ( (x) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_PUB_APB_TIMING_WINDOW_SEL(x)                    ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)) )
#define BIT_PUB_APB_VOTE_UNIT_TRANS_EN                      ( BIT(9) )
#define BIT_PUB_APB_SW_FORCE_VOTE_MASK_EN                   ( BIT(8) )
#define BIT_PUB_APB_SW_FORCE_VOTE_MASK(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_VOTE_STATUS, [0x600531E4] */
#define BIT_PUB_APB_VOTE_TAR_FRQ(x)                         ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_VOTE_NEXT_STATE(x)                      ( (x) << 5  & (BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_PUB_APB_VOTE_CUR_STATE(x)                       ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_PUB_APB_VOTE_BW_OVERFLOW                        ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL3, [0x600531F0] */
#define BIT_PUB_APB_DFS_LOCK_DELAY_EN                       ( BIT(31) )
#define BIT_PUB_APB_REG_DFS_LOCK_DELAY_CNT(x)               ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_DFI_MASK_WAIT_LSLP_EN                   ( BIT(24) )
#define BIT_PUB_APB_DFI_MASK_WAIT_TIME_LSLP(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DFI_MASK_WAIT_EN                        ( BIT(8) )
#define BIT_PUB_APB_DFI_MASK_WAIT_TIME(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_QOS_FIXED_CTRL0, [0x600531F4] */
#define BIT_PUB_APB_DMC_FIXED_QOS_EN(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_QOS_FIXED_CTRL1, [0x600531F8] */
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH3(x)                  ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH3(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH2(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH2(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH1(x)                  ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH1(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH0(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH0(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_QOS_FIXED_CTRL2, [0x600531FC] */
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH7(x)                  ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH7(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH6(x)                  ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH6(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH5(x)                  ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH5(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_DMC_FIXED_ARQOS_CH4(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DMC_FIXED_AWQOS_CH4(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_AXI_QOS_URGENT_REG_0, [0x60053200] */
#define BIT_PUB_APB_ARQOS_URGENT_CH3(x)                     ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH3(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH2(x)                     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH2(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH1(x)                     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH1(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH0(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH0(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_AXI_QOS_URGENT_REG_1, [0x60053204] */
#define BIT_PUB_APB_ARQOS_URGENT_CH7(x)                     ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH7(x)                     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH6(x)                     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH6(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH5(x)                     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH5(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_ARQOS_URGENT_CH4(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AWQOS_URGENT_CH4(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_INT_CTRL, [0x600532F0] */
#define BIT_PUB_APB_DFS_TIMEOUT_INT_CLR                     ( BIT(17) )
#define BIT_PUB_APB_DFS_TIMEOUT_INT_EN                      ( BIT(16) )
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

/* bits definitions for REG_PUB_APB_DFS_STATUS, [0x600532F4] */
#define BIT_PUB_APB_DFS_TIMEOUT_INT_RAW                     ( BIT(31) )
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

/* bits definitions for REG_PUB_APB_DFS_STATUS1, [0x600532F8] */
#define BIT_PUB_APB_DFS_SW_FSM_STATE(x)                     ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_DFS_VOTE_DONE_INT_RAW                   ( BIT(1) )
#define BIT_PUB_APB_INT_DFS_VOTE_DONE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_FC_REQ_DELAY, [0x600532FC] */
#define BIT_PUB_APB_DFS_FC_REQ_DELAY(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_PUB_LP_GEN_CTRL, [0x6005333C] */
#define BIT_PUB_APB_DFS_SW_MODE                             ( BIT(6) )
#define BIT_PUB_APB_HW_DFS_STOP_ENABLE                      ( BIT(5) )
#define BIT_PUB_APB_HW_DFS_RESTART_ENABLE                   ( BIT(4) )
#define BIT_PUB_APB_AUTO_STOP_NOC_ENABLE                    ( BIT(3) )
#define BIT_PUB_APB_AUTO_STOP_DFS_ENABLE                    ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_EN                              ( BIT(1) )
#define BIT_PUB_APB_PUB_LP_EN                               ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_0, [0x6005334C] */
#define BIT_PUB_APB_LP_FORCE_DBG_ASYNCB_W                   ( BIT(11) )
#define BIT_PUB_APB_LP_EB_DBG_ASYNCB_W                      ( BIT(10) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S3                     ( BIT(9) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S3                        ( BIT(8) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S2                     ( BIT(7) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S2                        ( BIT(6) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S1                     ( BIT(5) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S1                        ( BIT(4) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_S0                     ( BIT(3) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_S0                        ( BIT(2) )
#define BIT_PUB_APB_LP_FORCE_PUB_CFG_M0                     ( BIT(1) )
#define BIT_PUB_APB_LP_EB_PUB_CFG_M0                        ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_1, [0x60053354] */
#define BIT_PUB_APB_LP_NUM_PUB_CFG(x)                       ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_LP_NUM(x)                               ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL, [0x60053358] */
#define BIT_PUB_APB_DDR_FENCING_EN_PER_FSP_EN               ( BIT(31) )
#define BIT_PUB_APB_DDR_FENCING_EN                          ( BIT(30) )
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PHYCP_BASE_ADDR, [0x60053360] */
#define BIT_PUB_APB_PHYCP_ACC_BASE_ADDR(x)                  ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_PHYCP_CPU_BASE_ADDR(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_PUB_APB_PSCP_BASE_ADDR, [0x60053364] */
#define BIT_PUB_APB_PSCP_ACC_BASE_ADDR(x)                   ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_PSCP_CPU_BASE_ADDR(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_PUB_APB_AGCP_ISE_BASE_ADDR, [0x60053368] */
#define BIT_PUB_APB_ISE_BASE_ADDR(x)                        ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AGCP_BASE_ADDR(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_PUB_APB_CLK_PUB_DFS_CTRL, [0x6005336C] */
#define BIT_PUB_APB_DMC_PHY_X1_D2_BYPASS_MODE_AUTO_GATE_EN(x) ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_DMC_PHY_D2_BYPASS_MODE_AUTO_GATE_EN(x)  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_PHY_X2_BYPASS_MODE_AUTO_GATE_EN(x)  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_CGM_PUB_MON_32M_DIV(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_CGM_PUB_MON_32M_EN                      ( BIT(3) )
#define BIT_PUB_APB_LP_WAIT_CGM_BUSY_SEL                    ( BIT(2) )
#define BIT_PUB_APB_CGM_PUB_DFS_SEL                         ( BIT(1) )
#define BIT_PUB_APB_CGM_PUB_DFS_EN                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_0, [0x60053370] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F0(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_1, [0x60053374] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F1(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_2, [0x60053378] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F2(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_3, [0x6005337C] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F3(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_4, [0x60053380] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F4(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_5, [0x60053384] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F5(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_6, [0x60053388] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F6(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL_FSP_7, [0x6005338C] */
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT_F7(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_BIST_CTRL, [0x60053400] */
#define BIT_PUB_APB_BIST_PORT7_ADDR_MUX                     ( BIT(23) )
#define BIT_PUB_APB_BIST_PORT6_ADDR_MUX                     ( BIT(22) )
#define BIT_PUB_APB_BIST_PORT5_ADDR_MUX                     ( BIT(21) )
#define BIT_PUB_APB_BIST_PORT4_ADDR_MUX                     ( BIT(20) )
#define BIT_PUB_APB_BIST_PORT3_ADDR_MUX                     ( BIT(19) )
#define BIT_PUB_APB_BIST_PORT2_ADDR_MUX                     ( BIT(18) )
#define BIT_PUB_APB_BIST_PORT1_ADDR_MUX                     ( BIT(17) )
#define BIT_PUB_APB_BIST_PORT0_ADDR_MUX                     ( BIT(16) )
#define BIT_PUB_APB_BIST_FAIL_FLAG_CH3                      ( BIT(11) )
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

/* bits definitions for REG_PUB_APB_PUB_SOFT_RST_CTRL, [0x60053404] */
#define BIT_PUB_APB_ASYNCB_AGCP_SOFT_RST                    ( BIT(22) )
#define BIT_PUB_APB_ASYNCB_PHYCP_SOFT_RST                   ( BIT(21) )
#define BIT_PUB_APB_ASYNCB_PSCP_SOFT_RST                    ( BIT(20) )
#define BIT_PUB_APB_ASYNCB_AI_SOFT_RST                      ( BIT(19) )
#define BIT_PUB_APB_ASYNCB_AON_SOFT_RST                     ( BIT(18) )
#define BIT_PUB_APB_ASYNCB_AP_SOFT_RST                      ( BIT(17) )
#define BIT_PUB_APB_ASYNCB_CPU_SOFT_RST                     ( BIT(16) )
#define BIT_PUB_APB_ASYNCB_DCAM_SOFT_RST                    ( BIT(15) )
#define BIT_PUB_APB_ASYNCB_DPU0_SOFT_RST                    ( BIT(14) )
#define BIT_PUB_APB_ASYNCB_DPU1_SOFT_RST                    ( BIT(13) )
#define BIT_PUB_APB_ASYNCB_GPU_SOFT_RST                     ( BIT(12) )
#define BIT_PUB_APB_ASYNCB_IPA_SOFT_RST                     ( BIT(11) )
#define BIT_PUB_APB_ASYNCB_ISE_SOFT_RST                     ( BIT(10) )
#define BIT_PUB_APB_ASYNCB_ISP_VDSP_SOFT_RST                ( BIT(9) )
#define BIT_PUB_APB_ASYNCB_PCIE_SOFT_RST                    ( BIT(8) )
#define BIT_PUB_APB_ASYNCB_PHYCP_ACC_SOFT_RST               ( BIT(7) )
#define BIT_PUB_APB_ASYNCB_PSCP_ACC_SOFT_RST                ( BIT(6) )
#define BIT_PUB_APB_ASYNCB_VSP_GSP_SOFT_RST                 ( BIT(5) )
#define BIT_PUB_APB_ASYNCB_APB_SOFT_RST                     ( BIT(4) )
#define BIT_PUB_APB_ASYNCB_DMC_SOFT_RST                     ( BIT(3) )
#define BIT_PUB_APB_DMC_SOFT_RST                            ( BIT(2) )
#define BIT_PUB_APB_APB_FW_SOFT_RST                         ( BIT(1) )
#define BIT_PUB_APB_DDRPHY_SOFT_RST                         ( BIT(0) )

/* bits definitions for REG_PUB_APB_MC_IDLE_WAIT_CTRL, [0x60053414] */
#define BIT_PUB_APB_MC_IDLE_WAIT_CTRL(x)                    ( (x) )

/* bits definitions for REG_PUB_APB_QOS_THRESHOLD_0, [0x60053418] */
#define BIT_PUB_APB_AWQOS_THRESHOLD_WTL_AG(x)               ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_WTL_AG(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_AWQOS_THRESHOLD_DPU_ISP(x)              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_DPU_ISP(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_AWQOS_THRESHOLD_AP_AON(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_AP_AON(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_AON_AWQOS(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AON_ARQOS(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_QOS_THRESHOLD_1, [0x6005341C] */
#define BIT_PUB_APB_AWQOS_THRESHOLD_ISP_VDSP(x)             ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_ISP_VDSP(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DMC_DDR_CLK_CTRL, [0x60054000] */
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
#define BIT_PUB_APB_PUB_CLK_DMC_D2_DFIMON_EB                ( BIT(16) )
#define BIT_PUB_APB_PUB_CLK_DFS_EB                          ( BIT(15) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_PTM_EB                   ( BIT(14) )
#define BIT_PUB_APB_PUB_CLK_PHY_D2_EB                       ( BIT(13) )
#define BIT_PUB_APB_PUB_CLK_DMC_D2_EB                       ( BIT(12) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_EB                       ( BIT(11) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_EB                       ( BIT(10) )
#define BIT_PUB_APB_PUB_CLK_PHY_X1_D2_EB                    ( BIT(9) )
#define BIT_PUB_APB_PUB_DDR_CLK_EB                          ( BIT(8) )
#define BIT_PUB_APB_TIMER_CLK_AON_APB_OPEN_EN               ( BIT(7) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_PTM_AUTO_GATE_EN         ( BIT(6) )
#define BIT_PUB_APB_PUB_CLK_PHY_D2_CGM_SEL                  ( BIT(5) )
#define BIT_PUB_APB_PUB_CLK_DMC_D2_CGM_SEL                  ( BIT(4) )
#define BIT_PUB_APB_PUB_CLK_DMC_X1_CGM_SEL                  ( BIT(3) )
#define BIT_PUB_APB_PUB_CLK_PHY_X2_CGM_SEL                  ( BIT(2) )
#define BIT_PUB_APB_PUB_CLK_PHY_X1_D2_CGM_SEL               ( BIT(1) )
#define BIT_PUB_APB_PUB_DDR_CLK_CGM_SEL                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_CLK_INIT_SW_START, [0x60054004] */
#define BIT_PUB_APB_DMC_CLK_INIT_SW_START                   ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_CLK_STATE, [0x60054008] */
#define BIT_PUB_APB_DFS_LP_CTRL_CUR_STATE(x)                ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_DMC_CLK_HW_CUR_STATE(x)                 ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DMC_CUR_CLK_MODE(x)                     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_DMC_CLK_INIT_SW_DONE                    ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_CLK_INIT_CFG, [0x6005400C] */
#define BIT_PUB_APB_PTM_LSLP_CLK_KEEP_ON_EN                 ( BIT(25) )
#define BIT_PUB_APB_DMC_DFI_MON_LSLP_AG_EN                  ( BIT(24) )
#define BIT_PUB_APB_DMC_STOP_WAIT_CNT(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_DMC_SLEEP_FORCE_FINISH_MODE             ( BIT(8) )
#define BIT_PUB_APB_DESKEW_PLL_PD_DEFAULT_SW                ( BIT(5) )
#define BIT_PUB_APB_DESKEW_PLL_PD_DEFAULT_SEL               ( BIT(4) )
#define BIT_PUB_APB_DMC_SLEEP_CLK_AUTO_MODE                 ( BIT(1) )
#define BIT_PUB_APB_DFS_CLK_AUTO_MODE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CFG, [0x60054010] */
#define BIT_PUB_APB_DSKDLL_DCC_FINE_WAIT_SRC_SW             ( BIT(10) )
#define BIT_PUB_APB_DSKDLL_DCC_COARSE_WAIT_SRC_SW           ( BIT(9) )
#define BIT_PUB_APB_DSKPLL_LOCK_WAIT_SRC_SW                 ( BIT(8) )
#define BIT_PUB_APB_DDL_ADJS_V_WAIT_EN                      ( BIT(3) )
#define BIT_PUB_APB_DSKDLL_DCC_FINE_WAIT_EN                 ( BIT(2) )
#define BIT_PUB_APB_DSKDLL_DCC_COARSE_WAIT_EN               ( BIT(1) )
#define BIT_PUB_APB_DSKPLL_LOCK_WAIT_EN                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT0, [0x60054014] */
#define BIT_PUB_APB_WAIT_CNT_DSKPLL_PWRON_TIME(x)           ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_WAIT_CNT_DSKPLL_LOCK_TIME(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT1, [0x60054018] */
#define BIT_PUB_APB_WAIT_CNT_DSKDLL_DCC_FINE_TIME(x)        ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_WAIT_CNT_DSKDLL_DCC_COARSE_TIME(x)      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT2, [0x6005401C] */
#define BIT_PUB_APB_WAIT_CNT_DFS_RESET_OFF_TIME(x)          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_WAIT_CNT_DFS_RESET_ON_TIME(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_WAIT_CNT_DFS_CLK_OFF_TIME(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DMC_DESKEW_WAIT_CNT3, [0x60054020] */
#define BIT_PUB_APB_WAIT_CNT_DDL_ADJS_V_HIGH_TIME(x)        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_WAIT_CNT_DDL_ADJS_V_LOW_TIME(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DMC_DDL_CTRL, [0x6005402C] */
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

/* bits definitions for REG_PUB_APB_CGM_EN_LEGACY_STYLE_EN, [0x60054030] */
#define BIT_PUB_APB_CGM_EN_LEGACY_STYLE_AXI_DDRC(x)         ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_CGM_EN_LEGACY_STYLE_AXI_MST(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )

/* bits definitions for REG_PUB_APB_CGM_EN_LP_STAT_STYLE_EN, [0x60054034] */
#define BIT_PUB_APB_CGM_EN_LP_STAT_STYLE_AXI_DDRC(x)        ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_CGM_EN_LP_STAT_STYLE_AXI_MST(x)         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )

/* bits definitions for REG_PUB_APB_AXI_MST_CGM_EN_SW_CTRL, [0x60054038] */
#define BIT_PUB_APB_AXI_MST_DVFS_LAT_MON_EN(x)              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_AXI_MST_CLK_EB(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)) )

/* bits definitions for REG_PUB_APB_DMC_AXI_CH_CGM_EN_SW_CTRL, [0x6005403C] */
#define BIT_PUB_APB_DMC_AXI_CH_CLK_EB(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DDR_CLK_ROOT_BACKPRES_EN, [0x60054040] */
#define BIT_PUB_APB_LP_STAT_BACK_PRESS_DDR_EN               ( BIT(20) )
#define BIT_PUB_APB_PWR_HANDSHAKE_CLK_REQ_FORCE_EN(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_DFS_PURE_SW_CTRL, [0x60054100] */
#define BIT_PUB_APB_EMC_CKG_MDLL_SEL_PURE_SW(x)             ( (x) << 30 & (BIT(30)|BIT(31)) )
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

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL, [0x60054104] */
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

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL1, [0x60054108] */
#define BIT_PUB_APB_PUB_DFS_SW_UG_DENY_EN                   ( BIT(22) )
#define BIT_PUB_APB_PUB_DFS_SW_LP_DENY_EN                   ( BIT(21) )
#define BIT_PUB_APB_PUB_DFS_SW_UG_CHK_EN                    ( BIT(20) )
#define BIT_PUB_APB_PUB_DFS_SW_CLK_MODE_DEFAULT(x)          ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_SW_CLK_MODE(x)                  ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_MDLL_DEFAULT(x)        ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_D2_DEFAULT(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_MDLL(x)                ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_D2(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL2, [0x6005410C] */
#define BIT_PUB_APB_PUB_DFS_SW_DDL_ADJS_DEFAULT(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_SW_DDL_ADJS(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL3, [0x60054110] */
#define BIT_PUB_APB_PUB_DFS_URGENT_WAIT_TIMEOUT_PERIOD(x)   ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_PUB_DFS_URGENT_WAIT_TIMEOUT_EN          ( BIT(17) )
#define BIT_PUB_APB_PUB_DFS_SW_URGENT_WAIT_EN               ( BIT(16) )
#define BIT_PUB_APB_PUB_DFS_SW_URGENT_DENY_EN(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL, [0x60054114] */
#define BIT_PUB_APB_PUB_DFS_HW_DDL_ADJS_DEFAULT(x)          ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_PUB_DFS_HW_CLK_MODE_DEFAULT(x)          ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_PUB_DFS_HW_RATIO_D2_DEFAULT(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_HW_RATIO_DEFAULT(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_INITIAL_FREQ(x)              ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_PUB_DFS_HW_STOP                         ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_HW_START                        ( BIT(1) )
#define BIT_PUB_APB_PUB_DFS_HW_ENABLE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL1, [0x60054118] */
#define BIT_PUB_APB_SW_FORCE_EXIT_SW_LP_WAIT_ACK            ( BIT(31) )
#define BIT_PUB_APB_SW_FORCE_EXIT_HW_LP_WAIT_ACK            ( BIT(30) )
#define BIT_PUB_APB_SW_FORCE_EXIT_LP_WAIT_REQ               ( BIT(29) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_FREQ_UP_FORCE_TRIG       ( BIT(28) )
#define BIT_PUB_APB_PUB_DFS_HW_BWMON_MIN_EN                 ( BIT(27) )
#define BIT_PUB_APB_PUB_DFS_HW_BWMON_MIN_FREQ(x)            ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_APB_PUB_DFS_HW_AVAIL_FREQ_EN(x)             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PUB_DFS_HW_RATIO_MDLL_DEFAULT(x)        ( (x) << 13 & (BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_CHECK_PLL_EN                 ( BIT(12) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_FREQ_UP(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_FREQ_DN(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_EN_UP                    ( BIT(3) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_EN_DN                    ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_HW_MIN_LOAD                     ( BIT(1) )
#define BIT_PUB_APB_PUB_DFS_LP_PROT_EN                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL2, [0x6005411C] */
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

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET0, [0x60054120] */
#define BIT_PUB_APB_PUB_DFS_HW_F3_RATIO(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_RATIO(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_RATIO(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_RATIO(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET1, [0x60054124] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_RATIO(x)                  ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_RATIO(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_RATIO(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_RATIO(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET2, [0x60054128] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_RATIO_D2(x)               ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_RATIO_D2(x)               ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_RATIO_D2(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_RATIO_D2(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_HW_F3_RATIO_D2(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_RATIO_D2(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_RATIO_D2(x)               ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_RATIO_D2(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET3, [0x6005412C] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_RATIO_MDLL(x)             ( (x) << 30 & (BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_RATIO_MDLL(x)             ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_RATIO_MDLL(x)             ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_RATIO_MDLL(x)             ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_PUB_APB_PUB_DFS_HW_F3_RATIO_MDLL(x)             ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_RATIO_MDLL(x)             ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_RATIO_MDLL(x)             ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_RATIO_MDLL(x)             ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_PUB_DFS_HW_F7_CLK_MODE(x)               ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_CLK_MODE(x)               ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_PUB_DFS_HW_F5_CLK_MODE(x)               ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_CLK_MODE(x)               ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_PUB_DFS_HW_F3_CLK_MODE(x)               ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_CLK_MODE(x)               ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_PUB_DFS_HW_F1_CLK_MODE(x)               ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_CLK_MODE(x)               ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET4, [0x60054130] */
#define BIT_PUB_APB_PUB_DFS_HW_F1_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F0_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET5, [0x60054134] */
#define BIT_PUB_APB_PUB_DFS_HW_F3_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F2_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET6, [0x60054138] */
#define BIT_PUB_APB_PUB_DFS_HW_F5_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F4_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_DFS_HW_RATIO_SET7, [0x6005413C] */
#define BIT_PUB_APB_PUB_DFS_HW_F7_DDL_ADJS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_PUB_DFS_HW_F6_DDL_ADJS(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_APB_HW_DESKEWPLL_PD_CTRL0, [0x60054144] */
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_DEEP_SLEEP_MODE(x)     ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_AUTO_LIGHT_SLEEP_MODE(x) ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_SMART_LIGHT_SLEEP_MODE(x) ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_DEFAULT_BYP_MODE(x)    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_HW_DESKEWPLL_PD_CTRL1, [0x60054148] */
#define BIT_PUB_APB_DFS_FC_ACK_ASSERT_WAIT_CNT(x)           ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_DFS_HW_FRQ_SEL_SW(x)                    ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_DFS_HW_FRQ_SEL_SET                      ( BIT(3) )
#define BIT_PUB_APB_DFS_CUR_CLK_MODE_TOGGLE                 ( BIT(2) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PD_DEFAULT_HIGH           ( BIT(1) )
#define BIT_PUB_APB_HW_DESKEW_PLL_PO_AHEAD_EN               ( BIT(0) )

/* bits definitions for REG_PUB_APB_VOTE_MASTER_EN, [0x60054310] */
#define BIT_PUB_APB_DFS_VOTE_DEC_EN                         ( BIT(31) )
#define BIT_PUB_APB_VOTE_HW_DFS_DEC_MASK_EN                 ( BIT(30) )
#define BIT_PUB_APB_VOTE_HW_DFS_INC_MASK_EN                 ( BIT(29) )

/* bits definitions for REG_PUB_APB_VOTE_FSM_CNT, [0x60054314] */
#define BIT_PUB_APB_DFS_INTERVAL_CNT(x)                     ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_APB_VOTE_INTERVAL_CNT(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_0, [0x60054318] */
#define BIT_PUB_APB_THRD_INC_F0(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_1, [0x6005431C] */
#define BIT_PUB_APB_THRD_INC_F1(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_2, [0x60054320] */
#define BIT_PUB_APB_THRD_INC_F2(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_3, [0x60054324] */
#define BIT_PUB_APB_THRD_INC_F3(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_4, [0x60054328] */
#define BIT_PUB_APB_THRD_INC_F4(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_5, [0x6005432C] */
#define BIT_PUB_APB_THRD_INC_F5(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_6, [0x60054330] */
#define BIT_PUB_APB_THRD_INC_F6(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_THRESHOLD_INC_FREQ_7, [0x60054334] */
#define BIT_PUB_APB_THRD_INC_F7(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_TEST_DSKPLL_BIST_CNT, [0x60054340] */
#define BIT_PUB_APB_TEST_DSKPLL_BIST_CNT(x)                 ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_PUB_MON_CTRL, [0x60054700] */
#define BIT_PUB_APB_MON_TRANS_EN                            ( BIT(3) )
#define BIT_PUB_APB_PUB_MON_DONE                            ( BIT(2) )
#define BIT_PUB_APB_PUB_MON_EN                              ( BIT(1) )
#define BIT_PUB_APB_PUB_MON_SOFT_RST                        ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_MON_MODE, [0x60054704] */
#define BIT_PUB_APB_MON_TRANS_MODE                          ( BIT(6) )
#define BIT_PUB_APB_DFS_TIME_MODE(x)                        ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_MON_NUM(x)                              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_PUB_MON_OUT_SEL, [0x60054708] */
#define BIT_PUB_APB_BW_BYTE_SEL(x)                          ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_PUB_APB_DFS_BYTE_SEL(x)                         ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)) )
#define BIT_PUB_APB_ST_CYCLE_SEL(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_PUB_DFS_TIMEOUT_TH, [0x6005470C] */
#define BIT_PUB_APB_DFS_TIMEOUT_TH(x)                       ( (x) )

/* bits definitions for REG_PUB_APB_PUB_MON_TRANS_BASE_ADDR, [0x60054710] */
#define BIT_PUB_APB_MON_BASE_ADDR(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_PUB_MON_TRANS_CTRL, [0x60054714] */
#define BIT_PUB_APB_MON_TRANS_NUM(x)                        ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_MON_START_REG(x)                        ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_PUB_MON_F0_EN, [0x60054718] */
#define BIT_PUB_APB_F0_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F0_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F1_EN, [0x6005471C] */
#define BIT_PUB_APB_F1_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F1_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F2_EN, [0x60054720] */
#define BIT_PUB_APB_F2_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F2_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F3_EN, [0x60054724] */
#define BIT_PUB_APB_F3_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F3_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F4_EN, [0x60054728] */
#define BIT_PUB_APB_F4_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F4_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F5_EN, [0x6005472C] */
#define BIT_PUB_APB_F5_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F5_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F6_EN, [0x60054730] */
#define BIT_PUB_APB_F6_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F6_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_F7_EN, [0x60054734] */
#define BIT_PUB_APB_F7_TRANS_NUM(x)                         ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_F7_TRANS_EN(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )

/* bits definitions for REG_PUB_APB_PUB_MON_USER_QOS, [0x60054738] */
#define BIT_PUB_APB_ARQOS_PUB_MON(x)                        ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_PUB_APB_AWQOS_PUB_MON(x)                        ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)) )
#define BIT_PUB_APB_ARUSER_PUB_MON(x)                       ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_PUB_APB_AWUSER_PUB_MON(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_APB_PUB_STATUS_MON_CTRL, [0x60056200] */
#define BIT_PUB_APB_DFS_COUNT_EN                            ( BIT(9) )
#define BIT_PUB_APB_PUB_DFS_STA_EN                          ( BIT(8) )
#define BIT_PUB_APB_DMC_ST_MON_SEL(x)                       ( (x) << 1  & (BIT(1)|BIT(2)) )
#define BIT_PUB_APB_PUB_TOP_MON_EN                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_ST_IDLE_CYC_CNT, [0x60056204] */
#define BIT_PUB_APB_DMC_ST_IDLE_CYCLE_CNT(x)                ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_WR_CYC_CNT, [0x60056208] */
#define BIT_PUB_APB_DMC_ST_WRITE_CYCLE_CNT(x)               ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_RD_CYC_CNT, [0x6005620C] */
#define BIT_PUB_APB_DMC_ST_READ_CYCLE_CNT(x)                ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_SR_CYC_CNT, [0x60056210] */
#define BIT_PUB_APB_DMC_ST_SREF_CYCLE_CNT(x)                ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_LS_CYC_CNT, [0x60056214] */
#define BIT_PUB_APB_DMC_ST_LIGHT_CYCLE_CNT(x)               ( (x) )

/* bits definitions for REG_PUB_APB_PUB_ST_LS_TIME_CNT, [0x60056218] */
#define BIT_PUB_APB_DMC_ST_SREF_CNT(x)                      ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_APB_DMC_ST_LIGHT_CNT(x)                     ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F0_CYC_CNT, [0x6005621C] */
#define BIT_PUB_APB_DFS_F0_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F1_CYC_CNT, [0x60056220] */
#define BIT_PUB_APB_DFS_F1_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F2_CYC_CNT, [0x60056224] */
#define BIT_PUB_APB_DFS_F2_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F3_CYC_CNT, [0x60056228] */
#define BIT_PUB_APB_DFS_F3_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F4_CYC_CNT, [0x6005622C] */
#define BIT_PUB_APB_DFS_F4_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F5_CYC_CNT, [0x60056230] */
#define BIT_PUB_APB_DFS_F5_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F6_CYC_CNT, [0x60056234] */
#define BIT_PUB_APB_DFS_F6_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_F7_CYC_CNT, [0x60056238] */
#define BIT_PUB_APB_DFS_F7_CYCLE_CNT(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DFS_CNT, [0x6005623C] */
#define BIT_PUB_APB_DFS_COUNT(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_DPU_0, [0x60056400] */
#define BIT_PUB_APB_DPU_BV_EN                               ( BIT(31) )
#define BIT_PUB_APB_DPU_FV_EN                               ( BIT(30) )
#define BIT_PUB_APB_HW_VOTE_DPU_FLAG_EN                     ( BIT(29) )
#define BIT_PUB_APB_BFV_VOTE_DPU_SW                         ( BIT(25) )
#define BIT_PUB_APB_VOTE_DPU_ACK                            ( BIT(23) )
#define BIT_PUB_APB_VOTE_DPU_HW_ACK                         ( BIT(22) )
#define BIT_PUB_APB_FREQ_VOTE_DPU(x)                        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_DCAM_0, [0x60056404] */
#define BIT_PUB_APB_DCAM_BV_EN                              ( BIT(31) )
#define BIT_PUB_APB_DCAM_FV_EN                              ( BIT(30) )
#define BIT_PUB_APB_HW_VOTE_DCAM_FLAG_EN                    ( BIT(29) )
#define BIT_PUB_APB_BFV_VOTE_DCAM_SW                        ( BIT(25) )
#define BIT_PUB_APB_VOTE_DCAM_ACK                           ( BIT(23) )
#define BIT_PUB_APB_VOTE_DCAM_HW_ACK                        ( BIT(22) )
#define BIT_PUB_APB_FREQ_VOTE_DCAM(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_PUBCP_0, [0x60056408] */
#define BIT_PUB_APB_PUBCP_BV_EN                             ( BIT(31) )
#define BIT_PUB_APB_PUBCP_FV_EN                             ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_PUBCP_FLAG                      ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_PUBCP_FLAG                    ( BIT(24) )
#define BIT_PUB_APB_VOTE_PUBCP_ACK                          ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_PUBCP(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WTLCP_0, [0x6005640C] */
#define BIT_PUB_APB_WTLCP_BV_EN                             ( BIT(31) )
#define BIT_PUB_APB_WTLCP_FV_EN                             ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_WTLCP_FLAG                      ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP_FLAG                    ( BIT(24) )
#define BIT_PUB_APB_VOTE_WTLCP_ACK                          ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP(x)                      ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WTLCP1_0, [0x60056410] */
#define BIT_PUB_APB_WTLCP1_BV_EN                            ( BIT(31) )
#define BIT_PUB_APB_WTLCP1_FV_EN                            ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_WTLCP1_FLAG                     ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP1_FLAG                   ( BIT(24) )
#define BIT_PUB_APB_VOTE_WTLCP1_ACK                         ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_WTLCP1(x)                     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_AGCP_0, [0x60056414] */
#define BIT_PUB_APB_AGCP_BV_EN                              ( BIT(31) )
#define BIT_PUB_APB_AGCP_FV_EN                              ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_AGCP_FLAG                       ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_AGCP_FLAG                     ( BIT(24) )
#define BIT_PUB_APB_VOTE_AGCP_ACK                           ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_AGCP(x)                       ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_SW_0, [0x60056418] */
#define BIT_PUB_APB_SW_BV_EN                                ( BIT(31) )
#define BIT_PUB_APB_SW_FV_EN                                ( BIT(30) )
#define BIT_PUB_APB_BW_VOTE_SW_FLAG                         ( BIT(25) )
#define BIT_PUB_APB_FREQ_VOTE_SW_FLAG                       ( BIT(24) )
#define BIT_PUB_APB_VOTE_SW_ACK                             ( BIT(23) )
#define BIT_PUB_APB_FREQ_VOTE_SW(x)                         ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_DPU_1, [0x60056420] */
#define BIT_PUB_APB_BW_VOTE_DPU(x)                          ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_DCAM_1, [0x60056424] */
#define BIT_PUB_APB_BW_VOTE_DCAM(x)                         ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_PUBCP_1, [0x60056428] */
#define BIT_PUB_APB_BW_VOTE_PUBCP(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WTLCP_1, [0x6005642C] */
#define BIT_PUB_APB_BW_VOTE_WTLCP(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_WTLCP1_1, [0x60056430] */
#define BIT_PUB_APB_BW_VOTE_WTLCP1(x)                       ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_AGCP_1, [0x60056434] */
#define BIT_PUB_APB_BW_VOTE_AGCP(x)                         ( (x) )

/* bits definitions for REG_PUB_APB_VOTE_CTRL_SW_1, [0x60056438] */
#define BIT_PUB_APB_BW_VOTE_SW(x)                           ( (x) )

/* bits definitions for REG_PUB_APB_DFS_GFREE_CTRL, [0x60056500] */
#define BIT_PUB_APB_DFS_GFREE_HW_BYPASS_EN                  ( BIT(24) )
#define BIT_PUB_APB_DFS_GFREE_SW_OPEN_DELAY(x)              ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_DFS_GFREE_SW_CLOSE_DELAY(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_PUB_APB_DFS_GFREE_SW_BYPASS                     ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL_APPEND, [0x60056600] */
#define BIT_PUB_APB_PUB_DFS_SW_SWITCH_PERIOD_APPEND(x)      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_AWURGENT_DBG_CTRL, [0x60056800] */
#define BIT_PUB_APB_AWURGENT_DBG_AI(x)                      ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_PUB_APB_AWURGENT_DBG_IPA2(x)                    ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_APB_AWURGENT_DBG_AGCP(x)                    ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_PUB_APB_AWURGENT_DBG_PUBCP(x)                   ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PUB_APB_AWURGENT_DBG_WTLCP(x)                   ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_AWURGENT_DBG_IPA1(x)                    ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_AWURGENT_DBG_ESE(x)                     ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_AWURGENT_DBG_AON(x)                     ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_APB_AWURGENT_DBG_AP(x)                      ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_AWURGENT_DBG_VDSP(x)                    ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_APB_AWURGENT_DBG_MM_ISP(x)                  ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_AWURGENT_DBG_ISP_RAW(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AWURGENT_DBG_DPU(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_AWURGENT_DBG_GPU(x)                     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_AWURGENT_DBG_CPU(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_ARURGENT_DBG_CTRL, [0x60056804] */
#define BIT_PUB_APB_ARURGENT_DBG_AI(x)                      ( (x) << 28 & (BIT(28)|BIT(29)) )
#define BIT_PUB_APB_ARURGENT_DBG_IPA2(x)                    ( (x) << 26 & (BIT(26)|BIT(27)) )
#define BIT_PUB_APB_ARURGENT_DBG_AGCP(x)                    ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_PUB_APB_ARURGENT_DBG_PUBCP(x)                   ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PUB_APB_ARURGENT_DBG_WTLCP(x)                   ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_APB_ARURGENT_DBG_IPA1(x)                    ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_APB_ARURGENT_DBG_ESE(x)                     ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_APB_ARURGENT_DBG_AON(x)                     ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_APB_ARURGENT_DBG_AP(x)                      ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_APB_ARURGENT_DBG_VDSP(x)                    ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_APB_ARURGENT_DBG_MM_ISP(x)                  ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_ARURGENT_DBG_ISP_RAW(x)                 ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_APB_ARURGENT_DBG_DPU(x)                     ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_ARURGENT_DBG_GPU(x)                     ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_APB_ARURGENT_DBG_CPU(x)                     ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_APB_LSLP_SRE_SIM, [0x60056808] */
#define BIT_PUB_APB_SRE_FLAG_DBG                            ( BIT(1) )
#define BIT_PUB_APB_SRE_REQ_DBG                             ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_TOP_DBG_1, [0x6005680C] */
#define BIT_PUB_APB_PUB_APB_DBG_EB                          ( BIT(16) )
#define BIT_PUB_APB_PUB_APB_DBG_MOD_SEL(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_PUB_APB_DBG_SIG_SEL(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_PUB_TOP_DBG_2, [0x60056810] */
#define BIT_PUB_APB_PUB_APB_DBG_SUBSYS_BUS(x)               ( (x) )

/* bits definitions for REG_PUB_APB_PUB0_DUMMY_REG0, [0x60058000] */
#define BIT_PUB_APB_PUB0_DUMMY_REG0(x)                      ( (x) )

/* bits definitions for REG_PUB_APB_PUB0_DUMMY_REG1, [0x60058004] */
#define BIT_PUB_APB_PUB0_DUMMY_REG1(x)                      ( (x) )

/* vars definitions for controller CTL_PUB_APB */


#endif /* __PUB_APB_H____ */
