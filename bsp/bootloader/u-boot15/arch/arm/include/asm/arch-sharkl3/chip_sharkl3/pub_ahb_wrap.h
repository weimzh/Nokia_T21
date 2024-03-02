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

#ifndef __PUB_AHB_WRAP_H____
#define __PUB_AHB_WRAP_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_PUB_AHB_WRAP_BASE
#define CTL_PUB_AHB_WRAP_BASE           SCI_IOMAP(0x300F0000)
#endif

/* registers definitions for CTL_PUB_AHB_WRAP, 0x300F0000 */
#define REG_PUB_AHB_WRAP_PUB_AXI_QOS_REG_BK                 SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0000)
#define REG_PUB_AHB_WRAP_DFS_STATUS                         SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0004)
#define REG_PUB_AHB_WRAP_DFS_SW_CTRL                        SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0008)
#define REG_PUB_AHB_WRAP_RESERVED1                          SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x000C)
#define REG_PUB_AHB_WRAP_PUB_LP_GEN_CTRL                    SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0010)
#define REG_PUB_AHB_WRAP_RESERVED3                          SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0014)
#define REG_PUB_AHB_WRAP_DFS_PURE_SW_CTRL                   SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0018)
#define REG_PUB_AHB_WRAP_MEM_FW_INT                         SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x001C)
#define REG_PUB_AHB_WRAP_AXI_LPC_CTRL_0                     SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0020)
#define REG_PUB_AHB_WRAP_AXI_LPC_CTRL_1                     SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0024)
#define REG_PUB_AHB_WRAP_FENCING_CTRL                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0028)
#define REG_PUB_AHB_WRAP_WIFI_DFS_CTRL                      SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x002C)
#define REG_PUB_AHB_WRAP_DFS_SW_CTRL1                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0030)
#define REG_PUB_AHB_WRAP_DFS_SW_CTRL2                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0034)
#define REG_PUB_AHB_WRAP_DFS_SW_CTRL3                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0038)
#define REG_PUB_AHB_WRAP_PUB_DMC_MPU_INT                    SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0040)
#define REG_PUB_AHB_WRAP_DFS_INT_CTRL                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0044)
#define REG_PUB_AHB_WRAP_BASE_ADDR                          SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0048)
#define REG_PUB_AHB_WRAP_BIST_CTRL                          SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x004C)
#define REG_PUB_AHB_WRAP_BIST_CTRL_STATUS                   SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0050)
#define REG_PUB_AHB_WRAP_BUSMON_CLK_EN                      SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0054)
#define REG_PUB_AHB_WRAP_PUB_PERI_CLK_EN                    SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0058)
#define REG_PUB_AHB_WRAP_PUB_AXI_QOS_REG_1                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x005C)
#define REG_PUB_AHB_WRAP_RESERVED4                          SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0060)
#define REG_PUB_AHB_WRAP_DFS_HW_CTRL                        SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0100)
#define REG_PUB_AHB_WRAP_DFS_HW_CTRL1                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0104)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET0                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0108)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET1                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x010C)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET2                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0110)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET3                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0114)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET4                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0118)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET5                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x011C)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET6                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0120)
#define REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET7                  SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0124)
#define REG_PUB_AHB_WRAP_DFS_HW_CTRL2                       SCI_ADDR(CTL_PUB_AHB_WRAP_BASE, 0x0130)

/* bits definitions for REG_PUB_AHB_WRAP_PUB_AXI_QOS_REG_BK, [0x300F0000] */

/* bits definitions for REG_PUB_AHB_WRAP_DFS_STATUS, [0x300F0004] */
#define BIT_PUB_AHB_WRAP_DFS_HW_MIN_FREQ_UP_FORCE_TRIG_ACK  ( BIT(30) )
#define BIT_PUB_AHB_WRAP_DFS_USED_PLL(x)                    ( (x) << 27 & (BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_AHB_WRAP_DFS_FC_SEL(x)                      ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_AHB_WRAP_SRC_AVAIL_PLL(x)                   ( (x) << 21 & (BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_AHB_WRAP_DFS_URGENT_WAIT_TIMEOUT_FLAG       ( BIT(20) )
#define BIT_PUB_AHB_WRAP_DFS_GIVEUP_INT_RAW                 ( BIT(19) )
#define BIT_PUB_AHB_WRAP_INT_DFS_GIVEUP                     ( BIT(18) )
#define BIT_PUB_AHB_WRAP_DFS_DENY_INT_RAW                   ( BIT(17) )
#define BIT_PUB_AHB_WRAP_INT_DFS_DENY                       ( BIT(16) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_LOCK                       ( BIT(15) )
#define BIT_PUB_AHB_WRAP_DFS_LOCK_ACK                       ( BIT(14) )
#define BIT_PUB_AHB_WRAP_HW_DFS_FSM_STATE(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_PUB_AHB_WRAP_HW_DFS_FSM_IDLE                    ( BIT(6) )
#define BIT_PUB_AHB_WRAP_DFS_ERROR_INT_RAW                  ( BIT(5) )
#define BIT_PUB_AHB_WRAP_INT_DFS_ERROR                      ( BIT(4) )
#define BIT_PUB_AHB_WRAP_DFS_COMPLETE_INT_RAW               ( BIT(3) )
#define BIT_PUB_AHB_WRAP_INT_DFS_COMPLETE                   ( BIT(2) )
#define BIT_PUB_AHB_WRAP_HW_DFS_EXIT_INT_RAW                ( BIT(1) )
#define BIT_PUB_AHB_WRAP_INT_HW_DFS_EXIT                    ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_SW_CTRL, [0x300F0008] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_SWITCH_TYPE                ( BIT(31) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_SWITCH_PERIOD(x)        ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_RATIO_DEFAULT(x)        ( (x) << 15 & (BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_RATIO(x)                ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_DENY                    ( BIT(7) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_FRQ_SEL(x)              ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_RESP                    ( BIT(3) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_ACK                     ( BIT(2) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_REQ                     ( BIT(1) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_ENABLE                  ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_RESERVED1, [0x300F000C] */

/* bits definitions for REG_PUB_AHB_WRAP_PUB_LP_GEN_CTRL, [0x300F0010] */
#define BIT_PUB_AHB_WRAP_HW_DFS_STOP_ENABLE                 ( BIT(5) )
#define BIT_PUB_AHB_WRAP_HW_DFS_RESTART_ENABLE              ( BIT(4) )

/* bits definitions for REG_PUB_AHB_WRAP_RESERVED3, [0x300F0014] */

/* bits definitions for REG_PUB_AHB_WRAP_DFS_PURE_SW_CTRL, [0x300F0018] */
#define BIT_PUB_AHB_WRAP_EMC_CKG_MODE_PURE_SW(x)            ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_PUB_AHB_WRAP_EMC_CKG_D2_SEL_PURE_SW(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_CLK_MODE(x)            ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_DENY                   ( BIT(16) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_ACK                    ( BIT(15) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_RESP                   ( BIT(14) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_FC_REQ                 ( BIT(13) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_REQ                    ( BIT(12) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_FC_ACK                 ( BIT(11) )
#define BIT_PUB_AHB_WRAP_PURE_SW_DFS_FRQ_SEL(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_AHB_WRAP_EMC_CKG_SEL_PURE_SW(x)             ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_AHB_WRAP_DFS_SW_DFS_MODE                    ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_MEM_FW_INT, [0x300F001C] */
#define BIT_PUB_AHB_WRAP_MEM_FW_INT_RAW                     ( BIT(3) )
#define BIT_PUB_AHB_WRAP_INT_MEM_FW                         ( BIT(2) )
#define BIT_PUB_AHB_WRAP_MEM_FW_INT_CLR                     ( BIT(1) )
#define BIT_PUB_AHB_WRAP_MEM_FW_INT_EN                      ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_AXI_LPC_CTRL_0, [0x300F0020] */
#define BIT_PUB_AHB_WRAP_LP_FORCE_AON_WCN_ETR_S0            ( BIT(13) )
#define BIT_PUB_AHB_WRAP_LP_EB_AON_WCN_ETR_S0               ( BIT(12) )
#define BIT_PUB_AHB_WRAP_LP_FORCE_AON_WCN_ETR_M2            ( BIT(11) )
#define BIT_PUB_AHB_WRAP_LP_EB_AON_WCN_ETR_M2               ( BIT(10) )
#define BIT_PUB_AHB_WRAP_LP_FORCE_AON_WCN_ETR_M1            ( BIT(9) )
#define BIT_PUB_AHB_WRAP_LP_EB_AON_WCN_ETR_M1               ( BIT(8) )
#define BIT_PUB_AHB_WRAP_LP_FORCE_AON_WCN_ETR_M0            ( BIT(7) )
#define BIT_PUB_AHB_WRAP_LP_EB_AON_WCN_ETR_M0               ( BIT(6) )
#define BIT_PUB_AHB_WRAP_LP_FORCE_CP_S0                     ( BIT(5) )
#define BIT_PUB_AHB_WRAP_LP_EB_CP_S0                        ( BIT(4) )
#define BIT_PUB_AHB_WRAP_LP_FORCE_CP_M1                     ( BIT(3) )
#define BIT_PUB_AHB_WRAP_LP_EB_CP_M1                        ( BIT(2) )
#define BIT_PUB_AHB_WRAP_LP_FORCE_CP_M0                     ( BIT(1) )
#define BIT_PUB_AHB_WRAP_LP_EB_CP_M0                        ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_AXI_LPC_CTRL_1, [0x300F0024] */
#define BIT_PUB_AHB_WRAP_LP_NUM(x)                          ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_AHB_WRAP_FENCING_CTRL, [0x300F0028] */
#define BIT_PUB_AHB_WRAP_DDR_FENCING_EN                     ( BIT(30) )
#define BIT_PUB_AHB_WRAP_FENCING_CHNL_IDLE_CNT(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_PUB_AHB_WRAP_WIFI_DFS_CTRL, [0x300F002C] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_LOCK_REQ                ( BIT(29) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_LOCK_MODE               ( BIT(28) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_TIMEOUT_FLAG              ( BIT(25) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_ACK                       ( BIT(24) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_URGENCY_CTRL_EN(x)        ( (x) << 22 & (BIT(22)|BIT(23)) )
#define BIT_PUB_AHB_WRAP_WIFI_FIFO_URGENCY_CTRL_EN(x)       ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_SW_REQ                    ( BIT(19) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_MODE                      ( BIT(18) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_TIMEOUT_EN                ( BIT(17) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_TIMEOUT_PERIOD(x)         ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_PUB_AHB_WRAP_WIFI_DFS_HW_BYPASS                 ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_SW_CTRL1, [0x300F0030] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_CLK_MODE_DEFAULT(x)     ( (x) << 18 & (BIT(18)|BIT(19)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_CLK_MODE(x)             ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_RATIO_D2_DEFAULT(x)     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_RATIO_D2(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_SW_CTRL2, [0x300F0034] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_DDL_ADJS_DEFAULT(x)     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_DDL_ADJS(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_SW_CTRL3, [0x300F0038] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_URGENT_WAIT_TIMEOUT_PERIOD(x) ( (x) << 18 & (BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_URGENT_WAIT_TIMEOUT_EN     ( BIT(17) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_URGENT_WAIT_EN          ( BIT(16) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_SW_URGENT_DENY_EN(x)       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_AHB_WRAP_PUB_DMC_MPU_INT, [0x300F0040] */
#define BIT_PUB_AHB_WRAP_INT_DMC_MPU_VIO                    ( BIT(3) )
#define BIT_PUB_AHB_WRAP_DMC_MPU_VIO_INT_RAW                ( BIT(2) )
#define BIT_PUB_AHB_WRAP_DMC_MPU_VIO_INT_CLR                ( BIT(1) )
#define BIT_PUB_AHB_WRAP_DMC_MPU_VIO_INT_EN                 ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_INT_CTRL, [0x300F0044] */
#define BIT_PUB_AHB_WRAP_DFS_GIVEUP_INT_CLR                 ( BIT(9) )
#define BIT_PUB_AHB_WRAP_DFS_GIVEUP_INT_EN                  ( BIT(8) )
#define BIT_PUB_AHB_WRAP_DFS_DENY_INT_CLR                   ( BIT(7) )
#define BIT_PUB_AHB_WRAP_DFS_DENY_INT_EN                    ( BIT(6) )
#define BIT_PUB_AHB_WRAP_DFS_ERROR_INT_CLR                  ( BIT(5) )
#define BIT_PUB_AHB_WRAP_DFS_ERROR_INT_EN                   ( BIT(4) )
#define BIT_PUB_AHB_WRAP_DFS_COMPLETE_INT_CLR               ( BIT(3) )
#define BIT_PUB_AHB_WRAP_DFS_COMPLETE_INT_EN                ( BIT(2) )
#define BIT_PUB_AHB_WRAP_HW_DFS_EXIT_INT_CLR                ( BIT(1) )
#define BIT_PUB_AHB_WRAP_HW_DFS_EXIT_INT_EN                 ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_BASE_ADDR, [0x300F0048] */
#define BIT_PUB_AHB_WRAP_PUB_CP_BASE_ADDR(x)                ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)) )
#define BIT_PUB_AHB_WRAP_WTL_CP_BASE_ADDR(x)                ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )
#define BIT_PUB_AHB_WRAP_WCN_BASE_ADDR(x)                   ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_PUB_AHB_WRAP_AON_BASE_ADDR(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)) )

/* bits definitions for REG_PUB_AHB_WRAP_BIST_CTRL, [0x300F004C] */
#define BIT_PUB_AHB_WRAP_PUB_BIST_EB_AXI                    ( BIT(17) )
#define BIT_PUB_AHB_WRAP_PUB_BIST_EB_REG                    ( BIT(16) )
#define BIT_PUB_AHB_WRAP_BIST_VSP_EN                        ( BIT(11) )
#define BIT_PUB_AHB_WRAP_BIST_WCN_AON_EN                    ( BIT(10) )
#define BIT_PUB_AHB_WRAP_BIST_WTL_PUBCP_EN                  ( BIT(9) )
#define BIT_PUB_AHB_WRAP_BIST_AP_EN                         ( BIT(8) )
#define BIT_PUB_AHB_WRAP_BIST_CPU_EN                        ( BIT(7) )
#define BIT_PUB_AHB_WRAP_BIST_DPU_EN                        ( BIT(6) )
#define BIT_PUB_AHB_WRAP_BIST_GPU_EN                        ( BIT(5) )
#define BIT_PUB_AHB_WRAP_BIST_MM_EN                         ( BIT(4) )
#define BIT_PUB_AHB_WRAP_BIST_MUX_1(x)                      ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_AHB_WRAP_BIST_MUX_0(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_AHB_WRAP_BIST_CTRL_STATUS, [0x300F0050] */
#define BIT_PUB_AHB_WRAP_DSKPLL_BIST_CNT(x)                 ( (x) << 16 & (0xFFFF0000) )
#define BIT_PUB_AHB_WRAP_BIST_FAIL_3                        ( BIT(3) )
#define BIT_PUB_AHB_WRAP_BIST_FAIL_2                        ( BIT(2) )
#define BIT_PUB_AHB_WRAP_BIST_FAIL_1                        ( BIT(1) )
#define BIT_PUB_AHB_WRAP_BIST_FAIL_0                        ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_BUSMON_CLK_EN, [0x300F0054] */
#define BIT_PUB_AHB_WRAP_BUSMON_EB_ATCLK                    ( BIT(4) )
#define BIT_PUB_AHB_WRAP_BUSMON_CH_SOFT_RST                 ( BIT(3) )
#define BIT_PUB_AHB_WRAP_BUSMON_RF_SOFT_RST                 ( BIT(2) )
#define BIT_PUB_AHB_WRAP_BUSMON_EB_AXI                      ( BIT(1) )
#define BIT_PUB_AHB_WRAP_BUSMON_EB_REG                      ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_PUB_PERI_CLK_EN, [0x300F0058] */
#define BIT_PUB_AHB_WRAP_RESERVE_CLK_EB(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_AHB_WRAP_QOS_SLV_CLK_EB                     ( BIT(3) )
#define BIT_PUB_AHB_WRAP_AXI_DEBUG_TCK_EB                   ( BIT(2) )
#define BIT_PUB_AHB_WRAP_OT_CLK_EB                          ( BIT(1) )
#define BIT_PUB_AHB_WRAP_FW_EB_APB                          ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_PUB_AXI_QOS_REG_1, [0x300F005C] */
#define BIT_PUB_AHB_WRAP_AWQOS_THRESHOLD_PUBCP(x)           ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_AHB_WRAP_ARQOS_THRESHOLD_PUBCP(x)           ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )

/* bits definitions for REG_PUB_AHB_WRAP_RESERVED4, [0x300F0060] */

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_CTRL, [0x300F0100] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_DDL_ADJS_DEFAULT(x)     ( (x) << 22 & (BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_CLK_MODE_DEFAULT(x)     ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_RATIO_D2_DEFAULT(x)     ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_RATIO_DEFAULT(x)        ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_INITIAL_FREQ(x)         ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_STOP                    ( BIT(2) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_START                   ( BIT(1) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_ENABLE                  ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_CTRL1, [0x300F0104] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_MIN_FREQ_UP_FORCE_TRIG  ( BIT(28) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_BWMON_MIN_EN            ( BIT(27) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_BWMON_MIN_FREQ(x)       ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_AVAIL_FREQ_EN(x)        ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_CHECK_PLL_EN            ( BIT(12) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_MIN_FREQ_UP(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_MIN_FREQ_DN(x)          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_MIN_EN_UP               ( BIT(3) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_MIN_EN_DN               ( BIT(2) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_MIN_LOAD                ( BIT(1) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_LP_PROT_EN                 ( BIT(0) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET0, [0x300F0108] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F3_RATIO(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F2_RATIO(x)             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F1_RATIO(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F0_RATIO(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET1, [0x300F010C] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F7_RATIO(x)             ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F6_RATIO(x)             ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F5_RATIO(x)             ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F4_RATIO(x)             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET2, [0x300F0110] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F7_RATIO_D2(x)          ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F6_RATIO_D2(x)          ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F5_RATIO_D2(x)          ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F4_RATIO_D2(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F3_RATIO_D2(x)          ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F2_RATIO_D2(x)          ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F1_RATIO_D2(x)          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F0_RATIO_D2(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET3, [0x300F0114] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F7_CLK_MODE(x)          ( (x) << 14 & (BIT(14)|BIT(15)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F6_CLK_MODE(x)          ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F5_CLK_MODE(x)          ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F4_CLK_MODE(x)          ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F3_CLK_MODE(x)          ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F2_CLK_MODE(x)          ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F1_CLK_MODE(x)          ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F0_CLK_MODE(x)          ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET4, [0x300F0118] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F1_DDL_ADJS(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F0_DDL_ADJS(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET5, [0x300F011C] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F3_DDL_ADJS(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F2_DDL_ADJS(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET6, [0x300F0120] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F5_DDL_ADJS(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F4_DDL_ADJS(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_RATIO_SET7, [0x300F0124] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F7_DDL_ADJS(x)          ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_F6_DDL_ADJS(x)          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_WRAP_DFS_HW_CTRL2, [0x300F0130] */
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_URGENT_WAIT_EN          ( BIT(16) )
#define BIT_PUB_AHB_WRAP_PUB_DFS_HW_URGENT_DENY_EN(x)       ( (x) << 0  & (0x0000FFFF) )

/* vars definitions for controller CTL_PUB_AHB_WRAP */


#endif /* __PUB_AHB_WRAP_H____ */
