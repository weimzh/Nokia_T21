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

#ifndef __GPU_APB_H____
#define __GPU_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_GPU_APB_BASE
#define CTL_GPU_APB_BASE                SCI_IOMAP(0x60100000)
#endif

/* registers definitions for CTL_GPU_APB, 0x60100000 */
#define REG_GPU_APB_APB_RST                                 SCI_ADDR(CTL_GPU_APB_BASE, 0x0000)
#define REG_GPU_APB_APB_CLK_CTRL                            SCI_ADDR(CTL_GPU_APB_BASE, 0x0004)
#define REG_GPU_APB_APB_BARRIER_CTRL                        SCI_ADDR(CTL_GPU_APB_BASE, 0x0008)
#define REG_GPU_APB_GPU_NIC400_GPU2PUB_SLV_LP_CFG           SCI_ADDR(CTL_GPU_APB_BASE, 0x000C)
#define REG_GPU_APB_GPU_LPC_NUM_CFG                         SCI_ADDR(CTL_GPU_APB_BASE, 0x0010)
#define REG_GPU_APB_GPU_NIC400_QOS                          SCI_ADDR(CTL_GPU_APB_BASE, 0x0014)
#define REG_GPU_APB_GPU_CGM_FDIV_NUM                        SCI_ADDR(CTL_GPU_APB_BASE, 0x0018)
#define REG_GPU_APB_GPU_CGM_FDIV_DENOM                      SCI_ADDR(CTL_GPU_APB_BASE, 0x001C)

/* bits definitions for REG_GPU_APB_APB_RST, [0x60100000] */
#define BIT_GPU_APB_GPU_SOFT_RST                            ( BIT(0) )

/* bits definitions for REG_GPU_APB_APB_CLK_CTRL, [0x60100004] */
#define BIT_GPU_APB_CLK_GPU_DIV(x)                          ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_GPU_APB_CLK_GPU_SEL(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_GPU_APB_APB_BARRIER_CTRL, [0x60100008] */
#define BIT_GPU_APB_GPU_BARRIER_DISABLE_EN                  ( BIT(0) )

/* bits definitions for REG_GPU_APB_GPU_NIC400_GPU2PUB_SLV_LP_CFG, [0x6010000C] */
#define BIT_GPU_APB_NIC400_GPU2PUB_SLV_LP_EB                ( BIT(1) )
#define BIT_GPU_APB_NIC400_GPU2PUB_SLV_LP_FORCE             ( BIT(0) )

/* bits definitions for REG_GPU_APB_GPU_LPC_NUM_CFG, [0x60100010] */
#define BIT_GPU_APB_GPU_SYS_LP_NUM(x)                       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_GPU_APB_GPU_NIC400_QOS, [0x60100014] */
#define BIT_GPU_APB_GPU_QOS_SEL                             ( BIT(16) )
#define BIT_GPU_APB_AWQOS_THRESHOLD_GPU(x)                  ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_GPU_APB_ARQOS_THRESHOLD_GPU(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_GPU_APB_AWQOS_GPU(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_GPU_APB_ARQOS_GPU(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_APB_GPU_CGM_FDIV_NUM, [0x60100018] */
#define BIT_GPU_APB_CGM_GPU_FDIV_NUM(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_GPU_APB_GPU_CGM_FDIV_DENOM, [0x6010001C] */
#define BIT_GPU_APB_CGM_GPU_FDIV_DENOM(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* vars definitions for controller CTL_GPU_APB */


#endif /* __GPU_APB_H____ */
