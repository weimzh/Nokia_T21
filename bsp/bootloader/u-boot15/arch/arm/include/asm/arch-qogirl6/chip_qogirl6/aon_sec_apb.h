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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/AON_SYS/SharkL6 AON SEC APB Control Register.xls;AON_SEC_APB_REG
 *     Revision : 236542
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AON_SEC_APB_H____
#define __AON_SEC_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_SEC_APB_BASE
#define CTL_AON_SEC_APB_BASE            SCI_IOMAP(0x64880000)
#endif

/* registers definitions for CTL_AON_SEC_APB, 0x64880000 */
#define REG_AON_SEC_APB_CHIP_KPRTL_0                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0000)
#define REG_AON_SEC_APB_CHIP_KPRTL_1                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0004)
#define REG_AON_SEC_APB_CHIP_KPRTL_2                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0008)
#define REG_AON_SEC_APB_CHIP_KPRTL_3                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x000C)
#define REG_AON_SEC_APB_SEC_EB                              SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0010)
#define REG_AON_SEC_APB_SEC_SOFT_RST                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0014)
#define REG_AON_SEC_APB_FUNC_DMA_EN                         SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0018)
#define REG_AON_SEC_APB_AON_SEC_EB                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x001C)
#define REG_AON_SEC_APB_SECURE_EFUSE_BOUNDRY                SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0020)
#define REG_AON_SEC_APB_APCPU_APB_EB                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0024)
#define REG_AON_SEC_APB_APCPU_SOFT_RST                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0028)
#define REG_AON_SEC_APB_APCPU_CORE0_3_CLK_CFG               SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x002C)
#define REG_AON_SEC_APB_APCPU_CORE4_7_CLK_CFG               SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0030)
#define REG_AON_SEC_APB_APCPU_BUS_CLK_CFG                   SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0038)
#define REG_AON_SEC_APB_APCPU_TOP_MISC_CLK_CFG              SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x003C)
#define REG_AON_SEC_APB_RVBARADDR0                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0040)
#define REG_AON_SEC_APB_RVBARADDR1                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0044)
#define REG_AON_SEC_APB_RVBARADDR2                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0048)
#define REG_AON_SEC_APB_RVBARADDR3                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x004C)
#define REG_AON_SEC_APB_RVBARADDR4                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0050)
#define REG_AON_SEC_APB_RVBARADDR5                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0054)
#define REG_AON_SEC_APB_RVBARADDR6                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0058)
#define REG_AON_SEC_APB_RVBARADDR7                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x005C)
#define REG_AON_SEC_APB_APCPU_CFG_CTRL                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0060)
#define REG_AON_SEC_APB_RTC_VALID_FLAG                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0068)
#define REG_AON_SEC_APB_AON_SEC_APB_RSV_0                   SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0070)
#define REG_AON_SEC_APB_AON_SEC_APB_RSV_1                   SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0074)

/* bits definitions for REG_AON_SEC_APB_CHIP_KPRTL_0, [0x64880000] */
#define BIT_AON_SEC_APB_KPRTL_0(x)                          ( (x) )

/* bits definitions for REG_AON_SEC_APB_CHIP_KPRTL_1, [0x64880004] */
#define BIT_AON_SEC_APB_KPRTL_1(x)                          ( (x) )

/* bits definitions for REG_AON_SEC_APB_CHIP_KPRTL_2, [0x64880008] */
#define BIT_AON_SEC_APB_KPRTL_2(x)                          ( (x) )

/* bits definitions for REG_AON_SEC_APB_CHIP_KPRTL_3, [0x6488000C] */
#define BIT_AON_SEC_APB_KPRTL_3(x)                          ( (x) )

/* bits definitions for REG_AON_SEC_APB_SEC_EB, [0x64880010] */
#define BIT_AON_SEC_APB_SEC_32K_DET_EB                      ( BIT(11) )
#define BIT_AON_SEC_APB_SEC_EIC_RTCDV5_EB                   ( BIT(10) )
#define BIT_AON_SEC_APB_SEC_EIC_RTC_EB                      ( BIT(9) )
#define BIT_AON_SEC_APB_SEC_EIC_EB                          ( BIT(8) )
#define BIT_AON_SEC_APB_SEC_RTC_CLK_GATE_EB                 ( BIT(7) )
#define BIT_AON_SEC_APB_SEC_GPIO_EB                         ( BIT(6) )
#define BIT_AON_SEC_APB_SEC_WDG_EB                          ( BIT(5) )
#define BIT_AON_SEC_APB_SEC_WDG_RTC_EB                      ( BIT(4) )
#define BIT_AON_SEC_APB_SEC_RTC_EB                          ( BIT(3) )
#define BIT_AON_SEC_APB_SEC_TMR0_EB                         ( BIT(2) )
#define BIT_AON_SEC_APB_SEC_TMR0_RTC_EB                     ( BIT(1) )
#define BIT_AON_SEC_APB_SEC_TZPC_EB                         ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_SEC_SOFT_RST, [0x64880014] */
#define BIT_AON_SEC_APB_SEC_32K_DET_SOFT_RST                ( BIT(6) )
#define BIT_AON_SEC_APB_SEC_EIC_SOFT_RST                    ( BIT(5) )
#define BIT_AON_SEC_APB_SEC_GPIO_SOFT_RST                   ( BIT(4) )
#define BIT_AON_SEC_APB_SEC_WDG_SOFT_RST                    ( BIT(3) )
#define BIT_AON_SEC_APB_SEC_RTC_SOFT_RST                    ( BIT(2) )
#define BIT_AON_SEC_APB_SEC_TMR0_SOFT_RST                   ( BIT(1) )
#define BIT_AON_SEC_APB_SEC_TZPC_SOFT_RST                   ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_FUNC_DMA_EN, [0x64880018] */
#define BIT_AON_SEC_APB_FUNC_DMA_EN                         ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_AON_SEC_EB, [0x6488001C] */
#define BIT_AON_SEC_APB_I2C_SEC_EB                          ( BIT(1) )
#define BIT_AON_SEC_APB_EFUSE_SEC_EB                        ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_SECURE_EFUSE_BOUNDRY, [0x64880020] */
#define BIT_AON_SEC_APB_SEC_EFUSE_BOUNDRY(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SEC_APB_APCPU_APB_EB, [0x64880024] */
#define BIT_AON_SEC_APB_APCPU_CSSYS_EB                      ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_APCPU_SOFT_RST, [0x64880028] */
#define BIT_AON_SEC_APB_APCPU_CSSYS_APB_SOFT_RST            ( BIT(14) )
#define BIT_AON_SEC_APB_APCPU_CSSYS_SOFT_RST                ( BIT(13) )
#define BIT_AON_SEC_APB_APCPU_SCU_SOFT_RST                  ( BIT(12) )
#define BIT_AON_SEC_APB_APCPU_DEBUG_APB_SOFT_RST            ( BIT(11) )
#define BIT_AON_SEC_APB_APCPU_PERIPH_SOFT_RST               ( BIT(10) )
#define BIT_AON_SEC_APB_APCPU_GIC_SOFT_RST                  ( BIT(9) )
#define BIT_AON_SEC_APB_APCPU_ATB_SOFT_RST                  ( BIT(8) )
#define BIT_AON_SEC_APB_APCPU_CORE_SOFT_RST(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SEC_APB_APCPU_CORE0_3_CLK_CFG, [0x6488002C] */
#define BIT_AON_SEC_APB_CGM_CORE3_DIV(x)                    ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_SEC_APB_CGM_CORE3_SEL(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AON_SEC_APB_CGM_CORE2_DIV(x)                    ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_SEC_APB_CGM_CORE2_SEL(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_AON_SEC_APB_CGM_CORE1_DIV(x)                    ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_SEC_APB_CGM_CORE1_SEL(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_SEC_APB_CGM_CORE0_DIV(x)                    ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_SEC_APB_CGM_CORE0_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_SEC_APB_APCPU_CORE4_7_CLK_CFG, [0x64880030] */
#define BIT_AON_SEC_APB_CGM_CORE7_DIV(x)                    ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_SEC_APB_CGM_CORE7_SEL(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)) )
#define BIT_AON_SEC_APB_CGM_CORE6_DIV(x)                    ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_SEC_APB_CGM_CORE6_SEL(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)) )
#define BIT_AON_SEC_APB_CGM_CORE5_DIV(x)                    ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_SEC_APB_CGM_CORE5_SEL(x)                    ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_AON_SEC_APB_CGM_CORE4_DIV(x)                    ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_SEC_APB_CGM_CORE4_SEL(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_SEC_APB_APCPU_BUS_CLK_CFG, [0x64880038] */
#define BIT_AON_SEC_APB_CGM_AXI_ACP_DIV(x)                  ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_SEC_APB_CGM_AXI_PERIPH_DIV(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_SEC_APB_CGM_ACE_DIV(x)                      ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)) )
#define BIT_AON_SEC_APB_CGM_SCU_DIV(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_SEC_APB_CGM_SCU_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_SEC_APB_APCPU_TOP_MISC_CLK_CFG, [0x6488003C] */
#define BIT_AON_SEC_APB_CGM_PERIPH_DIV(x)                   ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)) )
#define BIT_AON_SEC_APB_CGM_PERIPH_SEL(x)                   ( (x) << 24 & (BIT(24)|BIT(25)) )
#define BIT_AON_SEC_APB_CGM_GIC_DIV(x)                      ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)) )
#define BIT_AON_SEC_APB_CGM_GIC_SEL(x)                      ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AON_SEC_APB_CGM_DEBUG_APB_DIV(x)                ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_AON_SEC_APB_CGM_ATB_DIV(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_AON_SEC_APB_CGM_ATB_SEL(x)                      ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR0, [0x64880040] */
#define BIT_AON_SEC_APB_RVBARADDR0(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR1, [0x64880044] */
#define BIT_AON_SEC_APB_RVBARADDR1(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR2, [0x64880048] */
#define BIT_AON_SEC_APB_RVBARADDR2(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR3, [0x6488004C] */
#define BIT_AON_SEC_APB_RVBARADDR3(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR4, [0x64880050] */
#define BIT_AON_SEC_APB_RVBARADDR4(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR5, [0x64880054] */
#define BIT_AON_SEC_APB_RVBARADDR5(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR6, [0x64880058] */
#define BIT_AON_SEC_APB_RVBARADDR6(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR7, [0x6488005C] */
#define BIT_AON_SEC_APB_RVBARADDR7(x)                       ( (x) )

/* bits definitions for REG_AON_SEC_APB_APCPU_CFG_CTRL, [0x64880060] */
#define BIT_AON_SEC_APB_APCPU_PWAKEUPDBG_FORCE_ON           ( BIT(4) )
#define BIT_AON_SEC_APB_APCPU_GICP_ALLOW_NS                 ( BIT(3) )
#define BIT_AON_SEC_APB_APCPU_GICT_ALLOW_NS                 ( BIT(2) )
#define BIT_AON_SEC_APB_APCPU_GICCDISABLE                   ( BIT(1) )
#define BIT_AON_SEC_APB_APCPU_CRYPTODISABLE                 ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_RTC_VALID_FLAG, [0x64880068] */
#define BIT_AON_SEC_APB_RTC_VALID_FLAG                      ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_AON_SEC_APB_RSV_0, [0x64880070] */
#define BIT_AON_SEC_APB_AON_SEC_APB_RSV_0(x)                ( (x) )

/* bits definitions for REG_AON_SEC_APB_AON_SEC_APB_RSV_1, [0x64880074] */
#define BIT_AON_SEC_APB_AON_SEC_APB_RSV_1(x)                ( (x) )

/* vars definitions for controller CTL_AON_SEC_APB */


#endif /* __AON_SEC_APB_H____ */
