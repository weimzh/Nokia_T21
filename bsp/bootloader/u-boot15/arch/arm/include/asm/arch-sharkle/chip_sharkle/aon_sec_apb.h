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
#define CTL_AON_SEC_APB_BASE            SCI_IOMAP(0x32050000)
#endif

/* registers definitions for CTL_AON_SEC_APB, 0x32050000 */
#define REG_AON_SEC_APB_SEC_EB                              SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0000)
#define REG_AON_SEC_APB_SEC_SOFT_RST                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0004)
#define REG_AON_SEC_APB_FUNCDMA_NORMAL_EB                   SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0008)
#define REG_AON_SEC_APB_CA53_CFG_CTRL                       SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x000C)
#define REG_AON_SEC_APB_SECURE_EFUSE_BOUNDRY                SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0010)
#define REG_AON_SEC_APB_DMA_SEC_EB                          SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0014)
#define REG_AON_SEC_APB_EFUSE_SEC_EB                        SCI_ADDR(CTL_AON_SEC_APB_BASE, 0x0018)

/* bits definitions for REG_AON_SEC_APB_SEC_EB, [0x32050000] */
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

/* bits definitions for REG_AON_SEC_APB_SEC_SOFT_RST, [0x32050004] */
#define BIT_AON_SEC_APB_SEC_EIC_SOFT_RST                    ( BIT(5) )
#define BIT_AON_SEC_APB_SEC_GPIO_RST                        ( BIT(4) )
#define BIT_AON_SEC_APB_SEC_WDG_SOFT_RST                    ( BIT(3) )
#define BIT_AON_SEC_APB_SEC_RTC_SOFT_RST                    ( BIT(2) )
#define BIT_AON_SEC_APB_SEC_TMR_SOFT_RST                    ( BIT(1) )
#define BIT_AON_SEC_APB_SEC_TZPC_SOFT_RST                   ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_FUNCDMA_NORMAL_EB, [0x32050008] */
#define BIT_AON_SEC_APB_FUNCDMA_NORMAL_EB                   ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_CA53_CFG_CTRL, [0x3205000C] */
#define BIT_AON_SEC_APB_CA53_GIC_CFGSDISABLE                ( BIT(8) )
#define BIT_AON_SEC_APB_CP15SDISABLE(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_AON_SEC_APB_SECURE_EFUSE_BOUNDRY, [0x32050010] */
#define BIT_AON_SEC_APB_SEC_EFUSE_BOUNDRY(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SEC_APB_DMA_SEC_EB, [0x32050014] */
#define BIT_AON_SEC_APB_AON_DMA_SEC_EB                      ( BIT(0) )

/* bits definitions for REG_AON_SEC_APB_EFUSE_SEC_EB, [0x32050018] */
#define BIT_AON_SEC_APB_EFUSE_SEC_EB                        ( BIT(0) )

/* vars definitions for controller CTL_AON_SEC_APB */


#endif /* __AON_SEC_APB_H____ */
