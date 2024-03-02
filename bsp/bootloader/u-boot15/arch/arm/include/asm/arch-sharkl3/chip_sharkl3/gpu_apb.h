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

/* bits definitions for REG_GPU_APB_APB_RST, [0x60100000] */
#define BIT_GPU_APB_GPU_SOFT_RST                            ( BIT(0) )

/* vars definitions for controller CTL_GPU_APB */


#endif /* __GPU_APB_H____ */
