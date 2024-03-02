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

#ifndef __MM_VSP_AHB_H____
#define __MM_VSP_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_MM_VSP_AHB_BASE
#define CTL_MM_VSP_AHB_BASE             SCI_IOMAP(0x62000000)
#endif

/* registers definitions for CTL_MM_VSP_AHB, 0x62000000 */
#define REG_MM_VSP_AHB_AHB_EB                               SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0000)
#define REG_MM_VSP_AHB_AHB_RST                              SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0004)
#define REG_MM_VSP_AHB_CGM_VSP_FDIV                         SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0008)
#define REG_MM_VSP_AHB_CGM_CPP_FDIV                         SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x000C)
#define REG_MM_VSP_AHB_CGM_JPG_FDIV                         SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0010)
#define REG_MM_VSP_AHB_LP_CTRL_VSP                          SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0014)
#define REG_MM_VSP_AHB_LP_CTRL_JPG                          SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0018)
#define REG_MM_VSP_AHB_LP_CTRL_CPP                          SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x001C)
#define REG_MM_VSP_AHB_LP_CTRL_MM_VSP_0                     SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0020)
#define REG_MM_VSP_AHB_LP_CTRL_MM_VSP_1                     SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0024)
#define REG_MM_VSP_AHB_MTX_MOD_CTRL                         SCI_ADDR(CTL_MM_VSP_AHB_BASE, 0x0028)

/* bits definitions for REG_MM_VSP_AHB_AHB_EB, [0x62000000] */
#define BIT_MM_VSP_AHB_CPP_EB                               ( BIT(3) )
#define BIT_MM_VSP_AHB_JPG_EB                               ( BIT(2) )
#define BIT_MM_VSP_AHB_VSP_EB                               ( BIT(1) )
#define BIT_MM_VSP_AHB_CKG_EB                               ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_AHB_RST, [0x62000004] */
#define BIT_MM_VSP_AHB_CPP_DMA_SOFT_RST                     ( BIT(9) )
#define BIT_MM_VSP_AHB_CPP_PATH1_SOFT_RST                   ( BIT(8) )
#define BIT_MM_VSP_AHB_CPP_PATH0_SOFT_RST                   ( BIT(7) )
#define BIT_MM_VSP_AHB_CPP_SOFT_RST                         ( BIT(6) )
#define BIT_MM_VSP_AHB_JPG_SOFT_RST                         ( BIT(5) )
#define BIT_MM_VSP_AHB_VPP_SOFT_RST                         ( BIT(4) )
#define BIT_MM_VSP_AHB_VSP_SOFT_RST                         ( BIT(3) )
#define BIT_MM_VSP_AHB_VSP_GLB_SOFT_RST                     ( BIT(2) )
#define BIT_MM_VSP_AHB_AXI_MM_VSP_EMC_SOFT_RST              ( BIT(1) )
#define BIT_MM_VSP_AHB_CKG_SOFT_RST                         ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_CGM_VSP_FDIV, [0x62000008] */
#define BIT_MM_VSP_AHB_CGM_VSP_FDIV_NUM(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_VSP_AHB_CGM_VSP_FDIV_DENOM(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_VSP_AHB_CGM_CPP_FDIV, [0x6200000C] */
#define BIT_MM_VSP_AHB_CGM_CPP_FDIV_NUM(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_VSP_AHB_CGM_CPP_FDIV_DENOM(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_VSP_AHB_CGM_JPG_FDIV, [0x62000010] */
#define BIT_MM_VSP_AHB_CGM_JPG_FDIV_NUM(x)                  ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_VSP_AHB_CGM_JPG_FDIV_DENOM(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_MM_VSP_AHB_LP_CTRL_VSP, [0x62000014] */
#define BIT_MM_VSP_AHB_LP_NUM_VSP(x)                        ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_VSP_AHB_LP_EB_VSP                            ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_LP_CTRL_JPG, [0x62000018] */
#define BIT_MM_VSP_AHB_LP_NUM_JPG(x)                        ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_VSP_AHB_LP_EB_JPG                            ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_LP_CTRL_CPP, [0x6200001C] */
#define BIT_MM_VSP_AHB_LP_NUM_CPP(x)                        ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_VSP_AHB_LP_EB_CPP                            ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_LP_CTRL_MM_VSP_0, [0x62000020] */
#define BIT_MM_VSP_AHB_LP_NUM_MM_VSP(x)                     ( (x) << 16 & (0xFFFF0000) )
#define BIT_MM_VSP_AHB_LP_EB_MM_VSP                         ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_LP_CTRL_MM_VSP_1, [0x62000024] */
#define BIT_MM_VSP_AHB_ARQOS_THRESHOLD_MM_VSP(x)            ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_MM_VSP_AHB_AWQOS_THRESHOLD_MM_VSP(x)            ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_MM_VSP_AHB_QACTIVE_EB_CPP                       ( BIT(4) )
#define BIT_MM_VSP_AHB_QACTIVE_EB_JPG                       ( BIT(3) )
#define BIT_MM_VSP_AHB_QACTIVE_EB_VSP                       ( BIT(2) )
#define BIT_MM_VSP_AHB_CGM_MM_VSP_MTX_S0_AUTO_GATE_EN       ( BIT(1) )
#define BIT_MM_VSP_AHB_MM_VSP_LPC_DISABLE                   ( BIT(0) )

/* bits definitions for REG_MM_VSP_AHB_MTX_MOD_CTRL, [0x62000028] */
#define BIT_MM_VSP_AHB_MOD_CTRL_CPP_AR(x)                   ( (x) << 10 & (BIT(10)|BIT(11)) )
#define BIT_MM_VSP_AHB_MOD_CTRL_CPP_AW(x)                   ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_MM_VSP_AHB_MOD_CTRL_JPG_AR(x)                   ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_MM_VSP_AHB_MOD_CTRL_JPG_AW(x)                   ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_MM_VSP_AHB_MOD_CTRL_VSP_AR(x)                   ( (x) << 2  & (BIT(2)|BIT(3)) )
#define BIT_MM_VSP_AHB_MOD_CTRL_VSP_AW(x)                   ( (x) << 0  & (BIT(0)|BIT(1)) )

/* vars definitions for controller CTL_MM_VSP_AHB */


#endif /* __MM_VSP_AHB_H____ */
