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

#ifndef __REG_FW0_AP_H____
#define __REG_FW0_AP_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_REG_FW0_AP_BASE
#define CTL_REG_FW0_AP_BASE             SCI_IOMAP(0x32809000)
#endif

/* registers definitions for CTL_REG_FW0_AP, 0x32809000 */
#define REG_REG_FW0_AP_REG_RD_CTRL_0                        SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0000)
#define REG_REG_FW0_AP_REG_WR_CTRL_0                        SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0004)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY0                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0008)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY1                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x000C)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY2                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0010)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY3                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0014)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY4                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0018)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY5                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x001C)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY6                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0020)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY7                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0024)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY8                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0028)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY9                 SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x002C)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY10                SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0030)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY11                SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0034)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY12                SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0038)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY13                SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x003C)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY14                SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0040)
#define REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY15                SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0044)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY0                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0048)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY1                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x004C)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY2                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0050)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY3                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0054)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY4                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0058)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY5                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x005C)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY6                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0060)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY7                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0064)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY8                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0068)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY9                      SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x006C)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY10                     SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0070)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY11                     SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0074)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY12                     SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0078)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY13                     SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x007C)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY14                     SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0080)
#define REG_REG_FW0_AP_BIT_CTRL_ARRAY15                     SCI_ADDR(CTL_REG_FW0_AP_BASE, 0x0084)

/* bits definitions for REG_REG_FW0_AP_REG_RD_CTRL_0, [0x32809000] */
#define BIT_REG_FW0_AP_APB_MISC_CTRL_RD_SEC                 ( BIT(2) )
#define BIT_REG_FW0_AP_APB_RST_RD_SEC                       ( BIT(1) )
#define BIT_REG_FW0_AP_APB_EB_RD_SEC                        ( BIT(0) )

/* bits definitions for REG_REG_FW0_AP_REG_WR_CTRL_0, [0x32809004] */
#define BIT_REG_FW0_AP_APB_MISC_CTRL_WR_SEC                 ( BIT(2) )
#define BIT_REG_FW0_AP_APB_RST_WR_SEC                       ( BIT(1) )
#define BIT_REG_FW0_AP_APB_EB_WR_SEC                        ( BIT(0) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY0, [0x32809008] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY0(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY1, [0x3280900C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY1(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY2, [0x32809010] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY2(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY3, [0x32809014] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY3(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY4, [0x32809018] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY4(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY5, [0x3280901C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY5(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY6, [0x32809020] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY6(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY7, [0x32809024] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY7(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY8, [0x32809028] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY8(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY9, [0x3280902C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY9(x)              ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY10, [0x32809030] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY10(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY11, [0x32809034] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY11(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY12, [0x32809038] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY12(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY13, [0x3280903C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY13(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY14, [0x32809040] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY14(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY15, [0x32809044] */
#define BIT_REG_FW0_AP_BIT_CTRL_ADDR_ARRAY15(x)             ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY0, [0x32809048] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY0(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY1, [0x3280904C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY1(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY2, [0x32809050] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY2(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY3, [0x32809054] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY3(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY4, [0x32809058] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY4(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY5, [0x3280905C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY5(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY6, [0x32809060] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY6(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY7, [0x32809064] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY7(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY8, [0x32809068] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY8(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY9, [0x3280906C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY9(x)                   ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY10, [0x32809070] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY10(x)                  ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY11, [0x32809074] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY11(x)                  ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY12, [0x32809078] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY12(x)                  ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY13, [0x3280907C] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY13(x)                  ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY14, [0x32809080] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY14(x)                  ( (x) )

/* bits definitions for REG_REG_FW0_AP_BIT_CTRL_ARRAY15, [0x32809084] */
#define BIT_REG_FW0_AP_BIT_CTRL_ARRAY15(x)                  ( (x) )

/* vars definitions for controller CTL_REG_FW0_AP */


#endif /* __REG_FW0_AP_H____ */
