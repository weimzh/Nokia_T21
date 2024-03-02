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
#define CTL_AON_SEC_APB_BASE            SCI_IOMAP(0x40460000)
#endif

#define CTL_BASE_AON_SEC_APB    CTL_AON_SEC_APB_BASE

/* registers definitions for CTL_AON_SEC_APB, 0x40460000 */
#define REG_AON_SEC_APB_SEC_EB                              SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0000)
#define REG_AON_SEC_APB_SEC_SOFT_RST                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0004)
#define REG_AON_SEC_APB_FUNC_DMA_EN                         SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0008)
#define REG_AON_SEC_APB_CA53_CFG_CTRL                       SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x000C)
#define REG_AON_SEC_APB_CA53_SOFT_RST                       SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0010)
#define REG_AON_SEC_APB_CCI_CFG0                            SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x001C)
#define REG_AON_SEC_APB_CCI_CFG1                            SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0020)
#define REG_AON_SEC_APB_RVBARADDR0_LIT                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0024)
#define REG_AON_SEC_APB_RVBARADDR1_LIT                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0028)
#define REG_AON_SEC_APB_RVBARADDR2_LIT                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x002C)
#define REG_AON_SEC_APB_RVBARADDR3_LIT                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0030)
#define REG_AON_SEC_APB_RVBARADDR0_BIG                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0034)
#define REG_AON_SEC_APB_RVBARADDR1_BIG                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0038)
#define REG_AON_SEC_APB_RVBARADDR2_BIG                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x003C)
#define REG_AON_SEC_APB_RVBARADDR3_BIG                      SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0040)
#define REG_AON_SEC_APB_SEC_EFUSE_BOUNDARY                  SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0050)
#define REG_AON_SEC_APB_GIC_ACC_EN                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0054)
#define REG_AON_SEC_APB_DBG_RECOVERY_EN                     SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0058)

/* bits definitions for REG_AON_SEC_APB_SEC_EB, [0x40460000] */
#define BIT_AON_SEC_APB_DMA_SEC_EB                          ( BIT(12) )
#define BIT_AON_SEC_APB_EFUSE_SEC_EB                        ( BIT(11) )
#define BIT_AON_SEC_APB_SEC_EIC_RTCDV5_EB                   ( BIT(10) )
#define BIT_AON_SEC_APB_SEC_EIC_RTC_EB                      ( BIT(9) )
#define BIT_AON_SEC_APB_SEC_EIC_EB                          ( BIT(8) )
#define BIT_AON_SEC_APB_SEC_GPIO_EB                         ( BIT(7) )
#define BIT_AON_SEC_APB_SEC_RTC_CLK_GATE_EB                 ( BIT(6) )
#define BIT_AON_SEC_APB_SEC_WDG_EB                          ( BIT(5) )
#define BIT_AON_SEC_APB_SEC_WDG_RTC_EB                      ( BIT(4) )
#define BIT_AON_SEC_APB_SEC_RTC_EB                          ( BIT(3) )
#define BIT_AON_SEC_APB_SEC_TMR_EB                          ( BIT(2) )
#define BIT_AON_SEC_APB_SEC_TMR_RTC_EB                      ( BIT(1) )
#define BIT_AON_SEC_APB_SEC_TZPC_EB                         ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_SEC_SOFT_RST, [0x40460004] */
#define BIT_AON_SEC_APB_SEC_EIC_SOFT_RST                    ( BIT(5) )
#define BIT_AON_SEC_APB_SEC_GPIO_RST                        ( BIT(4) )
#define BIT_AON_SEC_APB_SEC_WDG_SOFT_RST                    ( BIT(3) )
#define BIT_AON_SEC_APB_SEC_RTC_SOFT_RST                    ( BIT(2) )
#define BIT_AON_SEC_APB_SEC_TMR_SOFT_RST                    ( BIT(1) )
#define BIT_AON_SEC_APB_SEC_TZPC_SOFT_RST                   ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_FUNC_DMA_EN, [0x40460008] */
#define BIT_AON_SEC_APB_FUNC_DMA_EN                         ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_CA53_CFG_CTRL, [0x4046000C] */
#define BIT_AON_SEC_APB_CA53_GIC_CFGSDISABLE                ( BIT(8) )
#define BIT_AON_SEC_APB_CA53_BIG_CP15SDISABLE(x)            ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_SEC_APB_CA53_LIT_CP15SDISABLE(x)            ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_SEC_APB_CA53_SOFT_RST, [0x40460010] */
#define BIT_AON_SEC_APB_CA53_BIG_DBG_SOFT_RST               ( BIT(25) )
#define BIT_AON_SEC_APB_CA53_BIG_L2_SOFT_RST                ( BIT(24) )
#define BIT_AON_SEC_APB_CA53_BIG_ATB_SOFT_RST(x)            ( (x) << 20 & (BIT(20)|BIT(21)) )
#define BIT_AON_SEC_APB_CA53_BIG_CORE_SOFT_RST(x)           ( (x) << 16 & (BIT(16)|BIT(17)) )
#define BIT_AON_SEC_APB_CA53_LIT_DBG_SOFT_RST               ( BIT(9) )
#define BIT_AON_SEC_APB_CA53_LIT_L2_SOFT_RST                ( BIT(8) )
#define BIT_AON_SEC_APB_CA53_LIT_ATB_SOFT_RST(x)            ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_AON_SEC_APB_CA53_LIT_CORE_SOFT_RST(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_AON_SEC_APB_CCI_CFG0, [0x4046001C] */
#define BIT_AON_SEC_APB_CCI_PERIPHBASE_H25(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )

/* bits definitions for REG_AON_SEC_APB_CCI_CFG1, [0x40460020] */
#define BIT_AON_SEC_APB_CCI_AWQOS_BIG(x)                    ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_AON_SEC_APB_CCI_ARQOS_BIG(x)                    ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_AON_SEC_APB_CCI_AWQOS_LIT(x)                    ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_AON_SEC_APB_CCI_ARQOS_LIT(x)                    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_SEC_APB_CCI_QOSOVERRIDE(x)                  ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_AON_SEC_APB_CCI_BUFFERABLEOVERRIDE(x)           ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR0_LIT, [0x40460024] */
#define BIT_AON_SEC_APB_RVBARADDR0_LIT(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR1_LIT, [0x40460028] */
#define BIT_AON_SEC_APB_RVBARADDR1_LIT(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR2_LIT, [0x4046002C] */
#define BIT_AON_SEC_APB_RVBARADDR2_LIT(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR3_LIT, [0x40460030] */
#define BIT_AON_SEC_APB_RVBARADDR3_LIT(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR0_BIG, [0x40460034] */
#define BIT_AON_SEC_APB_RVBARADDR0_BIG(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR1_BIG, [0x40460038] */
#define BIT_AON_SEC_APB_RVBARADDR1_BIG(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR2_BIG, [0x4046003C] */
#define BIT_AON_SEC_APB_RVBARADDR2_BIG(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_RVBARADDR3_BIG, [0x40460040] */
#define BIT_AON_SEC_APB_RVBARADDR3_BIG(x)                   ( (x) )

/* bits definitions for REG_AON_SEC_APB_SEC_EFUSE_BOUNDARY, [0x40460050] */
#define BIT_AON_SEC_APB_SEC_EFUSE_BOUNDARY(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SEC_APB_GIC_ACC_EN, [0x40460054] */
#define BIT_AON_SEC_APB_GICP_ALLOW_NS                       ( BIT(1) )
#define BIT_AON_SEC_APB_GICT_ALLOW_NS                       ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_DBG_RECOVERY_EN, [0x40460058] */
#define BIT_AON_SEC_APB_DBGRCV_TRIG_OUT_EN                  ( BIT(2) )
#define BIT_AON_SEC_APB_AUTO_SAVE_TRIG_OUT_EN               ( BIT(1) )
#define BIT_AON_SEC_APB_AUTO_SAVE_GATED_OUT_EN              ( BIT(0) )

/* vars definitions for controller CTL_AON_SEC_APB */


#endif /* __AON_SEC_APB_H____ */
