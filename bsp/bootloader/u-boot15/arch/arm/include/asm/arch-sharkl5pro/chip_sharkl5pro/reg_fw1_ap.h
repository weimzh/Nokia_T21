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

#ifndef __REG_FW1_AP_H____
#define __REG_FW1_AP_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_REG_FW1_AP_BASE
#define CTL_REG_FW1_AP_BASE             SCI_IOMAP(0x3280A000)
#endif

/* registers definitions for CTL_REG_FW1_AP, 0x3280A000 */
#define REG_REG_FW1_AP_REG_RD_CTRL_0                        SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0000)
#define REG_REG_FW1_AP_REG_RD_CTRL_1                        SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0004)
#define REG_REG_FW1_AP_REG_WR_CTRL_0                        SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0008)
#define REG_REG_FW1_AP_REG_WR_CTRL_1                        SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x000C)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY0                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0010)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY1                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0014)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY2                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0018)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY3                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x001C)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY4                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0020)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY5                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0024)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY6                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0028)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY7                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x002C)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY8                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0030)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY9                 SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0034)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY10                SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0038)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY11                SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x003C)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY12                SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0040)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY13                SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0044)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY14                SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0048)
#define REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY15                SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x004C)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY0                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0050)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY1                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0054)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY2                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0058)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY3                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x005C)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY4                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0060)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY5                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0064)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY6                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0068)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY7                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x006C)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY8                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0070)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY9                      SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0074)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY10                     SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0078)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY11                     SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x007C)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY12                     SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0080)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY13                     SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0084)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY14                     SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x0088)
#define REG_REG_FW1_AP_BIT_CTRL_ARRAY15                     SCI_ADDR(CTL_REG_FW1_AP_BASE, 0x008C)

/* bits definitions for REG_REG_FW1_AP_REG_RD_CTRL_0, [0x3280A000] */
#define BIT_REG_FW1_AP_AP_QOS0_RD_SEC                       ( BIT(31) )
#define BIT_REG_FW1_AP_MERGE_S0_LPC_RD_SEC                  ( BIT(30) )
#define BIT_REG_FW1_AP_MERGE_M1_LPC_RD_SEC                  ( BIT(29) )
#define BIT_REG_FW1_AP_MERGE_M0_LPC_RD_SEC                  ( BIT(28) )
#define BIT_REG_FW1_AP_S4_LPC_RD_SEC                        ( BIT(27) )
#define BIT_REG_FW1_AP_S3_LPC_RD_SEC                        ( BIT(26) )
#define BIT_REG_FW1_AP_S2_LPC_RD_SEC                        ( BIT(25) )
#define BIT_REG_FW1_AP_S1_LPC_RD_SEC                        ( BIT(24) )
#define BIT_REG_FW1_AP_S0_LPC_RD_SEC                        ( BIT(23) )
#define BIT_REG_FW1_AP_MAIN_LPC_RD_SEC                      ( BIT(22) )
#define BIT_REG_FW1_AP_M6_LPC_RD_SEC                        ( BIT(21) )
#define BIT_REG_FW1_AP_M5_LPC_RD_SEC                        ( BIT(20) )
#define BIT_REG_FW1_AP_M4_LPC_RD_SEC                        ( BIT(19) )
#define BIT_REG_FW1_AP_M3_LPC_RD_SEC                        ( BIT(18) )
#define BIT_REG_FW1_AP_M2_LPC_RD_SEC                        ( BIT(17) )
#define BIT_REG_FW1_AP_M1_LPC_RD_SEC                        ( BIT(16) )
#define BIT_REG_FW1_AP_M0_LPC_RD_SEC                        ( BIT(15) )
#define BIT_REG_FW1_AP_AP_ASYNC_BRG_RD_SEC                  ( BIT(14) )
#define BIT_REG_FW1_AP_S5_LPC_RD_SEC                        ( BIT(13) )
#define BIT_REG_FW1_AP_S6_LPC_RD_SEC                        ( BIT(12) )
#define BIT_REG_FW1_AP_DISP_ASYNC_BRG_RD_SEC                ( BIT(11) )
#define BIT_REG_FW1_AP_MISC_CKG_EN_RD_SEC                   ( BIT(10) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_ON_1_RD_SEC        ( BIT(9) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_ON_0_RD_SEC        ( BIT(8) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_OFF_1_RD_SEC       ( BIT(7) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_OFF_0_RD_SEC       ( BIT(6) )
#define BIT_REG_FW1_AP_CLOCK_FREQUENCY_DOWN_RD_SEC          ( BIT(5) )
#define BIT_REG_FW1_AP_HOLDING_PEN_RD_SEC                   ( BIT(4) )
#define BIT_REG_FW1_AP_AP_SYS_AUTO_SLEEP_CFG_RD_SEC         ( BIT(3) )
#define BIT_REG_FW1_AP_AP_SYS_FORCE_SLEEP_CFG_RD_SEC        ( BIT(2) )
#define BIT_REG_FW1_AP_AHB_RST_RD_SEC                       ( BIT(1) )
#define BIT_REG_FW1_AP_AHB_EB_RD_SEC                        ( BIT(0) )

/* bits definitions for REG_REG_FW1_AP_REG_RD_CTRL_1, [0x3280A004] */
#define BIT_REG_FW1_AP_CHIP_ID_RD_SEC                       ( BIT(9) )
#define BIT_REG_FW1_AP_DSI_PHY_RD_SEC                       ( BIT(8) )
#define BIT_REG_FW1_AP_AP_QOS_CFG_RD_SEC                    ( BIT(7) )
#define BIT_REG_FW1_AP_CACHE_EMMC_SDIO_RD_SEC               ( BIT(6) )
#define BIT_REG_FW1_AP_SYS_RST_RD_SEC                       ( BIT(5) )
#define BIT_REG_FW1_AP_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP_RD_SEC ( BIT(4) )
#define BIT_REG_FW1_AP_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP_RD_SEC ( BIT(3) )
#define BIT_REG_FW1_AP_ASYNC_BRIDGE_IDLE_OVERFLOW_RD_SEC    ( BIT(2) )
#define BIT_REG_FW1_AP_AP_QOS2_RD_SEC                       ( BIT(1) )
#define BIT_REG_FW1_AP_AP_QOS1_RD_SEC                       ( BIT(0) )

/* bits definitions for REG_REG_FW1_AP_REG_WR_CTRL_0, [0x3280A008] */
#define BIT_REG_FW1_AP_AP_QOS0_WR_SEC                       ( BIT(31) )
#define BIT_REG_FW1_AP_MERGE_S0_LPC_WR_SEC                  ( BIT(30) )
#define BIT_REG_FW1_AP_MERGE_M1_LPC_WR_SEC                  ( BIT(29) )
#define BIT_REG_FW1_AP_MERGE_M0_LPC_WR_SEC                  ( BIT(28) )
#define BIT_REG_FW1_AP_S4_LPC_WR_SEC                        ( BIT(27) )
#define BIT_REG_FW1_AP_S3_LPC_WR_SEC                        ( BIT(26) )
#define BIT_REG_FW1_AP_S2_LPC_WR_SEC                        ( BIT(25) )
#define BIT_REG_FW1_AP_S1_LPC_WR_SEC                        ( BIT(24) )
#define BIT_REG_FW1_AP_S0_LPC_WR_SEC                        ( BIT(23) )
#define BIT_REG_FW1_AP_MAIN_LPC_WR_SEC                      ( BIT(22) )
#define BIT_REG_FW1_AP_M6_LPC_WR_SEC                        ( BIT(21) )
#define BIT_REG_FW1_AP_M5_LPC_WR_SEC                        ( BIT(20) )
#define BIT_REG_FW1_AP_M4_LPC_WR_SEC                        ( BIT(19) )
#define BIT_REG_FW1_AP_M3_LPC_WR_SEC                        ( BIT(18) )
#define BIT_REG_FW1_AP_M2_LPC_WR_SEC                        ( BIT(17) )
#define BIT_REG_FW1_AP_M1_LPC_WR_SEC                        ( BIT(16) )
#define BIT_REG_FW1_AP_M0_LPC_WR_SEC                        ( BIT(15) )
#define BIT_REG_FW1_AP_AP_ASYNC_BRG_WR_SEC                  ( BIT(14) )
#define BIT_REG_FW1_AP_S5_LPC_WR_SEC                        ( BIT(13) )
#define BIT_REG_FW1_AP_S6_LPC_WR_SEC                        ( BIT(12) )
#define BIT_REG_FW1_AP_DISP_ASYNC_BRG_WR_SEC                ( BIT(11) )
#define BIT_REG_FW1_AP_MISC_CKG_EN_WR_SEC                   ( BIT(10) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_ON_1_WR_SEC        ( BIT(9) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_ON_0_WR_SEC        ( BIT(8) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_OFF_1_WR_SEC       ( BIT(7) )
#define BIT_REG_FW1_AP_AP_SYS_CLK_EN_FRC_OFF_0_WR_SEC       ( BIT(6) )
#define BIT_REG_FW1_AP_CLOCK_FREQUENCY_DOWN_WR_SEC          ( BIT(5) )
#define BIT_REG_FW1_AP_HOLDING_PEN_WR_SEC                   ( BIT(4) )
#define BIT_REG_FW1_AP_AP_SYS_AUTO_SLEEP_CFG_WR_SEC         ( BIT(3) )
#define BIT_REG_FW1_AP_AP_SYS_FORCE_SLEEP_CFG_WR_SEC        ( BIT(2) )
#define BIT_REG_FW1_AP_AHB_RST_WR_SEC                       ( BIT(1) )
#define BIT_REG_FW1_AP_AHB_EB_WR_SEC                        ( BIT(0) )

/* bits definitions for REG_REG_FW1_AP_REG_WR_CTRL_1, [0x3280A00C] */
#define BIT_REG_FW1_AP_CHIP_ID_WR_SEC                       ( BIT(9) )
#define BIT_REG_FW1_AP_DSI_PHY_WR_SEC                       ( BIT(8) )
#define BIT_REG_FW1_AP_AP_QOS_CFG_WR_SEC                    ( BIT(7) )
#define BIT_REG_FW1_AP_CACHE_EMMC_SDIO_WR_SEC               ( BIT(6) )
#define BIT_REG_FW1_AP_SYS_RST_WR_SEC                       ( BIT(5) )
#define BIT_REG_FW1_AP_ASYNC_BRIDGE_DEBUG_SIGNAL_W_AP_WR_SEC ( BIT(4) )
#define BIT_REG_FW1_AP_ASYNC_BRIDGE_DEBUG_SIGNAL_W_DISP_WR_SEC ( BIT(3) )
#define BIT_REG_FW1_AP_ASYNC_BRIDGE_IDLE_OVERFLOW_WR_SEC    ( BIT(2) )
#define BIT_REG_FW1_AP_AP_QOS2_WR_SEC                       ( BIT(1) )
#define BIT_REG_FW1_AP_AP_QOS1_WR_SEC                       ( BIT(0) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY0, [0x3280A010] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY0(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY1, [0x3280A014] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY1(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY2, [0x3280A018] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY2(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY3, [0x3280A01C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY3(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY4, [0x3280A020] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY4(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY5, [0x3280A024] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY5(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY6, [0x3280A028] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY6(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY7, [0x3280A02C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY7(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY8, [0x3280A030] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY8(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY9, [0x3280A034] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY9(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY10, [0x3280A038] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY10(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY11, [0x3280A03C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY11(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY12, [0x3280A040] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY12(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY13, [0x3280A044] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY13(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY14, [0x3280A048] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY14(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY15, [0x3280A04C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ADDR_ARRAY15(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY0, [0x3280A050] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY0(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY1, [0x3280A054] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY1(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY2, [0x3280A058] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY2(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY3, [0x3280A05C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY3(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY4, [0x3280A060] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY4(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY5, [0x3280A064] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY5(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY6, [0x3280A068] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY6(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY7, [0x3280A06C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY7(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY8, [0x3280A070] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY8(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY9, [0x3280A074] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY9(x)                   ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY10, [0x3280A078] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY10(x)                  ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY11, [0x3280A07C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY11(x)                  ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY12, [0x3280A080] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY12(x)                  ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY13, [0x3280A084] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY13(x)                  ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY14, [0x3280A088] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY14(x)                  ( (x) )

/* bits definitions for REG_REG_FW1_AP_BIT_CTRL_ARRAY15, [0x3280A08C] */
#define BIT_REG_FW1_AP_BIT_CTRL_ARRAY15(x)                  ( (x) )

/* vars definitions for controller CTL_REG_FW1_AP */


#endif /* __REG_FW1_AP_H____ */
