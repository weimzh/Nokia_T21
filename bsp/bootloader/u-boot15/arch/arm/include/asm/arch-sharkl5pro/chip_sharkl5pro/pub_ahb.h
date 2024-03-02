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

#ifndef __PUB_AHB_H____
#define __PUB_AHB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_PUB_AHB_BASE
#define CTL_PUB_AHB_BASE                SCI_IOMAP(0x31030000)
#endif

/* registers definitions for CTL_PUB_AHB, 0x31030000 */
#define REG_PUB_AHB_DMC_EXT_LPCTRL_CFG                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3000)
#define REG_PUB_AHB_DMC_EXT_LPCTRL_SEQL                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x3004)
#define REG_PUB_AHB_DMC_EXT_LPCTRL_SEQH                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x3008)
#define REG_PUB_AHB_DMC_EXT_LPCTRL_STEP                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x300C)
#define REG_PUB_AHB_MPU_DUMP_ADDR                           SCI_ADDR(CTL_PUB_AHB_BASE, 0x3010)
#define REG_PUB_AHB_DMC_MPU_VIO_ADDR                        SCI_ADDR(CTL_PUB_AHB_BASE, 0x3014)
#define REG_PUB_AHB_DMC_MPU_VIO_CMD                         SCI_ADDR(CTL_PUB_AHB_BASE, 0x3018)
#define REG_PUB_AHB_DMC_MPU_BASE_CFG                        SCI_ADDR(CTL_PUB_AHB_BASE, 0x301C)
#define REG_PUB_AHB_MPU_CFG0                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3020)
#define REG_PUB_AHB_MPU_CFG0_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3024)
#define REG_PUB_AHB_MPU_CFG0_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3028)
#define REG_PUB_AHB_MPU_CFG0_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x302C)
#define REG_PUB_AHB_MPU_CFG1                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3030)
#define REG_PUB_AHB_MPU_CFG1_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3034)
#define REG_PUB_AHB_MPU_CFG1_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3038)
#define REG_PUB_AHB_MPU_CFG1_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x303C)
#define REG_PUB_AHB_MPU_CFG2                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3040)
#define REG_PUB_AHB_MPU_CFG2_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3044)
#define REG_PUB_AHB_MPU_CFG2_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3048)
#define REG_PUB_AHB_MPU_CFG2_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x304C)
#define REG_PUB_AHB_MPU_CFG3                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3050)
#define REG_PUB_AHB_MPU_CFG3_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3054)
#define REG_PUB_AHB_MPU_CFG3_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3058)
#define REG_PUB_AHB_MPU_CFG3_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x305C)
#define REG_PUB_AHB_MPU_CFG4                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3060)
#define REG_PUB_AHB_MPU_CFG4_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3064)
#define REG_PUB_AHB_MPU_CFG4_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3068)
#define REG_PUB_AHB_MPU_CFG4_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x306C)
#define REG_PUB_AHB_MPU_CFG5                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3070)
#define REG_PUB_AHB_MPU_CFG5_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3074)
#define REG_PUB_AHB_MPU_CFG5_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3078)
#define REG_PUB_AHB_MPU_CFG5_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x307C)
#define REG_PUB_AHB_MPU_CFG6                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3080)
#define REG_PUB_AHB_MPU_CFG6_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3084)
#define REG_PUB_AHB_MPU_CFG6_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3088)
#define REG_PUB_AHB_MPU_CFG6_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x308C)
#define REG_PUB_AHB_MPU_CFG7                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x3090)
#define REG_PUB_AHB_MPU_CFG7_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x3094)
#define REG_PUB_AHB_MPU_CFG7_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x3098)
#define REG_PUB_AHB_MPU_CFG7_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x309C)
#define REG_PUB_AHB_MPU_CFG8                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x30A0)
#define REG_PUB_AHB_MPU_CFG8_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x30A4)
#define REG_PUB_AHB_MPU_CFG8_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x30A8)
#define REG_PUB_AHB_MPU_CFG8_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x30AC)
#define REG_PUB_AHB_MPU_CFG9                                SCI_ADDR(CTL_PUB_AHB_BASE, 0x30B0)
#define REG_PUB_AHB_MPU_CFG9_ID_MASK_VAL                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x30B4)
#define REG_PUB_AHB_MPU_CFG9_LOW_RANGE                      SCI_ADDR(CTL_PUB_AHB_BASE, 0x30B8)
#define REG_PUB_AHB_MPU_CFG9_HIGH_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x30BC)
#define REG_PUB_AHB_MPU_CFG10                               SCI_ADDR(CTL_PUB_AHB_BASE, 0x30C0)
#define REG_PUB_AHB_MPU_CFG10_ID_MASK_VAL                   SCI_ADDR(CTL_PUB_AHB_BASE, 0x30C4)
#define REG_PUB_AHB_MPU_CFG10_LOW_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x30C8)
#define REG_PUB_AHB_MPU_CFG10_HIGH_RANGE                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x30CC)
#define REG_PUB_AHB_MPU_CFG11                               SCI_ADDR(CTL_PUB_AHB_BASE, 0x30D0)
#define REG_PUB_AHB_MPU_CFG11_ID_MASK_VAL                   SCI_ADDR(CTL_PUB_AHB_BASE, 0x30D4)
#define REG_PUB_AHB_MPU_CFG11_LOW_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x30D8)
#define REG_PUB_AHB_MPU_CFG11_HIGH_RANGE                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x30DC)
#define REG_PUB_AHB_MPU_CFG12                               SCI_ADDR(CTL_PUB_AHB_BASE, 0x30E0)
#define REG_PUB_AHB_MPU_CFG12_ID_MASK_VAL                   SCI_ADDR(CTL_PUB_AHB_BASE, 0x30E4)
#define REG_PUB_AHB_MPU_CFG12_LOW_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x30E8)
#define REG_PUB_AHB_MPU_CFG12_HIGH_RANGE                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x30EC)
#define REG_PUB_AHB_MPU_CFG13                               SCI_ADDR(CTL_PUB_AHB_BASE, 0x30F0)
#define REG_PUB_AHB_MPU_CFG13_ID_MASK_VAL                   SCI_ADDR(CTL_PUB_AHB_BASE, 0x30F4)
#define REG_PUB_AHB_MPU_CFG13_LOW_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x30F8)
#define REG_PUB_AHB_MPU_CFG13_HIGH_RANGE                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x30FC)
#define REG_PUB_AHB_MPU_CFG14                               SCI_ADDR(CTL_PUB_AHB_BASE, 0x3100)
#define REG_PUB_AHB_MPU_CFG14_ID_MASK_VAL                   SCI_ADDR(CTL_PUB_AHB_BASE, 0x3104)
#define REG_PUB_AHB_MPU_CFG14_LOW_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x3108)
#define REG_PUB_AHB_MPU_CFG14_HIGH_RANGE                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x310C)
#define REG_PUB_AHB_MPU_CFG15                               SCI_ADDR(CTL_PUB_AHB_BASE, 0x3110)
#define REG_PUB_AHB_MPU_CFG15_ID_MASK_VAL                   SCI_ADDR(CTL_PUB_AHB_BASE, 0x3114)
#define REG_PUB_AHB_MPU_CFG15_LOW_RANGE                     SCI_ADDR(CTL_PUB_AHB_BASE, 0x3118)
#define REG_PUB_AHB_MPU_CFG15_HIGH_RANGE                    SCI_ADDR(CTL_PUB_AHB_BASE, 0x311C)

/* bits definitions for REG_PUB_AHB_DMC_EXT_LPCTRL_CFG, [0x31033000] */
#define BIT_PUB_AHB_SOFT_CMD_NUM(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_AHB_SOFT_CMD_FC_SEL(x)                      ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_AHB_SOFT_CMD_RESP                           ( BIT(3) )
#define BIT_PUB_AHB_SOFT_CMD_DONE                           ( BIT(2) )
#define BIT_PUB_AHB_SOFT_CMD_START                          ( BIT(0) )

/* bits definitions for REG_PUB_AHB_DMC_EXT_LPCTRL_SEQL, [0x31033004] */
#define BIT_PUB_AHB_SOFT_CMD_SEQL(x)                        ( (x) )

/* bits definitions for REG_PUB_AHB_DMC_EXT_LPCTRL_SEQH, [0x31033008] */
#define BIT_PUB_AHB_SOFT_CMD_SEQH(x)                        ( (x) )

/* bits definitions for REG_PUB_AHB_DMC_EXT_LPCTRL_STEP, [0x3103300C] */
#define BIT_PUB_AHB_SOFT_CMD_STEP(x)                        ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_DUMP_ADDR, [0x31033010] */
#define BIT_PUB_AHB_MPU_DUMP_ADDR(x)                        ( (x) )

/* bits definitions for REG_PUB_AHB_DMC_MPU_VIO_ADDR, [0x31033014] */
#define BIT_PUB_AHB_DMC_MPU_VIO_ADDR(x)                     ( (x) )

/* bits definitions for REG_PUB_AHB_DMC_MPU_VIO_CMD, [0x31033018] */
#define BIT_PUB_AHB_DMC_MPU_VIO_CMD(x)                      ( (x) )

/* bits definitions for REG_PUB_AHB_DMC_MPU_BASE_CFG, [0x3103301C] */
#define BIT_PUB_AHB_DMC_MPU_VIO_INT_REQ                     ( BIT(1) )
#define BIT_PUB_AHB_MPU_EN                                  ( BIT(0) )

/* bits definitions for REG_PUB_AHB_MPU_CFG0, [0x31033020] */
#define BIT_PUB_AHB_MPU_CFG0(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG0_ID_MASK_VAL, [0x31033024] */
#define BIT_PUB_AHB_MPU_CFG0_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG0_LOW_RANGE, [0x31033028] */
#define BIT_PUB_AHB_MPU_CFG0_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG0_HIGH_RANGE, [0x3103302C] */
#define BIT_PUB_AHB_MPU_CFG0_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG1, [0x31033030] */
#define BIT_PUB_AHB_MPU_CFG1(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG1_ID_MASK_VAL, [0x31033034] */
#define BIT_PUB_AHB_MPU_CFG1_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG1_LOW_RANGE, [0x31033038] */
#define BIT_PUB_AHB_MPU_CFG1_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG1_HIGH_RANGE, [0x3103303C] */
#define BIT_PUB_AHB_MPU_CFG1_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG2, [0x31033040] */
#define BIT_PUB_AHB_MPU_CFG2(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG2_ID_MASK_VAL, [0x31033044] */
#define BIT_PUB_AHB_MPU_CFG2_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG2_LOW_RANGE, [0x31033048] */
#define BIT_PUB_AHB_MPU_CFG2_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG2_HIGH_RANGE, [0x3103304C] */
#define BIT_PUB_AHB_MPU_CFG2_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG3, [0x31033050] */
#define BIT_PUB_AHB_MPU_CFG3(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG3_ID_MASK_VAL, [0x31033054] */
#define BIT_PUB_AHB_MPU_CFG3_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG3_LOW_RANGE, [0x31033058] */
#define BIT_PUB_AHB_MPU_CFG3_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG3_HIGH_RANGE, [0x3103305C] */
#define BIT_PUB_AHB_MPU_CFG3_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG4, [0x31033060] */
#define BIT_PUB_AHB_MPU_CFG4(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG4_ID_MASK_VAL, [0x31033064] */
#define BIT_PUB_AHB_MPU_CFG4_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG4_LOW_RANGE, [0x31033068] */
#define BIT_PUB_AHB_MPU_CFG4_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG4_HIGH_RANGE, [0x3103306C] */
#define BIT_PUB_AHB_MPU_CFG4_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG5, [0x31033070] */
#define BIT_PUB_AHB_MPU_CFG5(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG5_ID_MASK_VAL, [0x31033074] */
#define BIT_PUB_AHB_MPU_CFG5_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG5_LOW_RANGE, [0x31033078] */
#define BIT_PUB_AHB_MPU_CFG5_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG5_HIGH_RANGE, [0x3103307C] */
#define BIT_PUB_AHB_MPU_CFG5_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG6, [0x31033080] */
#define BIT_PUB_AHB_MPU_CFG6(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG6_ID_MASK_VAL, [0x31033084] */
#define BIT_PUB_AHB_MPU_CFG6_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG6_LOW_RANGE, [0x31033088] */
#define BIT_PUB_AHB_MPU_CFG6_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG6_HIGH_RANGE, [0x3103308C] */
#define BIT_PUB_AHB_MPU_CFG6_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG7, [0x31033090] */
#define BIT_PUB_AHB_MPU_CFG7(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG7_ID_MASK_VAL, [0x31033094] */
#define BIT_PUB_AHB_MPU_CFG7_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG7_LOW_RANGE, [0x31033098] */
#define BIT_PUB_AHB_MPU_CFG7_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG7_HIGH_RANGE, [0x3103309C] */
#define BIT_PUB_AHB_MPU_CFG7_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG8, [0x310330A0] */
#define BIT_PUB_AHB_MPU_CFG8(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG8_ID_MASK_VAL, [0x310330A4] */
#define BIT_PUB_AHB_MPU_CFG8_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG8_LOW_RANGE, [0x310330A8] */
#define BIT_PUB_AHB_MPU_CFG8_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG8_HIGH_RANGE, [0x310330AC] */
#define BIT_PUB_AHB_MPU_CFG8_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG9, [0x310330B0] */
#define BIT_PUB_AHB_MPU_CFG9(x)                             ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG9_ID_MASK_VAL, [0x310330B4] */
#define BIT_PUB_AHB_MPU_CFG9_ID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG9_LOW_RANGE, [0x310330B8] */
#define BIT_PUB_AHB_MPU_CFG9_LOW_RANGE(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG9_HIGH_RANGE, [0x310330BC] */
#define BIT_PUB_AHB_MPU_CFG9_HIGH_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG10, [0x310330C0] */
#define BIT_PUB_AHB_MPU_CFG10(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG10_ID_MASK_VAL, [0x310330C4] */
#define BIT_PUB_AHB_MPU_CFG10_ID_MASK_VAL(x)                ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG10_LOW_RANGE, [0x310330C8] */
#define BIT_PUB_AHB_MPU_CFG10_LOW_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG10_HIGH_RANGE, [0x310330CC] */
#define BIT_PUB_AHB_MPU_CFG10_HIGH_RANGE(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG11, [0x310330D0] */
#define BIT_PUB_AHB_MPU_CFG11(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG11_ID_MASK_VAL, [0x310330D4] */
#define BIT_PUB_AHB_MPU_CFG11_ID_MASK_VAL(x)                ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG11_LOW_RANGE, [0x310330D8] */
#define BIT_PUB_AHB_MPU_CFG11_LOW_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG11_HIGH_RANGE, [0x310330DC] */
#define BIT_PUB_AHB_MPU_CFG11_HIGH_RANGE(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG12, [0x310330E0] */
#define BIT_PUB_AHB_MPU_CFG12(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG12_ID_MASK_VAL, [0x310330E4] */
#define BIT_PUB_AHB_MPU_CFG12_ID_MASK_VAL(x)                ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG12_LOW_RANGE, [0x310330E8] */
#define BIT_PUB_AHB_MPU_CFG12_LOW_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG12_HIGH_RANGE, [0x310330EC] */
#define BIT_PUB_AHB_MPU_CFG12_HIGH_RANGE(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG13, [0x310330F0] */
#define BIT_PUB_AHB_MPU_CFG13(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG13_ID_MASK_VAL, [0x310330F4] */
#define BIT_PUB_AHB_MPU_CFG13_ID_MASK_VAL(x)                ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG13_LOW_RANGE, [0x310330F8] */
#define BIT_PUB_AHB_MPU_CFG13_LOW_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG13_HIGH_RANGE, [0x310330FC] */
#define BIT_PUB_AHB_MPU_CFG13_HIGH_RANGE(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG14, [0x31033100] */
#define BIT_PUB_AHB_MPU_CFG14(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG14_ID_MASK_VAL, [0x31033104] */
#define BIT_PUB_AHB_MPU_CFG14_ID_MASK_VAL(x)                ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG14_LOW_RANGE, [0x31033108] */
#define BIT_PUB_AHB_MPU_CFG14_LOW_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG14_HIGH_RANGE, [0x3103310C] */
#define BIT_PUB_AHB_MPU_CFG14_HIGH_RANGE(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG15, [0x31033110] */
#define BIT_PUB_AHB_MPU_CFG15(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG15_ID_MASK_VAL, [0x31033114] */
#define BIT_PUB_AHB_MPU_CFG15_ID_MASK_VAL(x)                ( (x) )

/* bits definitions for REG_PUB_AHB_MPU_CFG15_LOW_RANGE, [0x31033118] */
#define BIT_PUB_AHB_MPU_CFG15_LOW_RANGE(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* bits definitions for REG_PUB_AHB_MPU_CFG15_HIGH_RANGE, [0x3103311C] */
#define BIT_PUB_AHB_MPU_CFG15_HIGH_RANGE(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)) )

/* vars definitions for controller CTL_PUB_AHB */


#endif /* __PUB_AHB_H____ */
