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

#ifndef __PUB_APB_H____
#define __PUB_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_PUB_APB_BASE
#define CTL_PUB_APB_BASE                SCI_IOMAP(0x300E0000)
#endif

/* registers definitions for CTL_PUB_APB, 0x300E0000 */
#define REG_PUB_APB_BUSMON_CNT_START                        SCI_ADDR(CTL_PUB_APB_BASE, 0x0000)
#define REG_PUB_APB_BUSMON_CFG                              SCI_ADDR(CTL_PUB_APB_BASE, 0x0004)
#define REG_PUB_APB_DDR_EB                                  SCI_ADDR(CTL_PUB_APB_BASE, 0x0008)
#define REG_PUB_APB_DDR_SOFT_RST                            SCI_ADDR(CTL_PUB_APB_BASE, 0x000C)
#define REG_PUB_APB_DMC_PORT_REMAP_EN                       SCI_ADDR(CTL_PUB_APB_BASE, 0x3000)
#define REG_PUB_APB_DMC_PORTS_MPU_EN                        SCI_ADDR(CTL_PUB_APB_BASE, 0x3004)
#define REG_PUB_APB_DMC_PORT0_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3008)
#define REG_PUB_APB_DMC_PORT1_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x300C)
#define REG_PUB_APB_DMC_PORT2_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3010)
#define REG_PUB_APB_DMC_PORT3_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3014)
#define REG_PUB_APB_DMC_PORT4_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3018)
#define REG_PUB_APB_DMC_PORT5_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x301C)
#define REG_PUB_APB_DMC_PORT6_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3020)
#define REG_PUB_APB_DMC_PORT7_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3024)
#define REG_PUB_APB_DMC_PORT8_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x3028)
#define REG_PUB_APB_DMC_PORT9_ADDR_REMAP_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x302C)
#define REG_PUB_APB_DMC_PORT0_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3030)
#define REG_PUB_APB_DMC_PORT1_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3034)
#define REG_PUB_APB_DMC_PORT2_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3038)
#define REG_PUB_APB_DMC_PORT3_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x303C)
#define REG_PUB_APB_DMC_PORT4_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3040)
#define REG_PUB_APB_DMC_PORT5_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3044)
#define REG_PUB_APB_DMC_PORT6_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3048)
#define REG_PUB_APB_DMC_PORT7_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3050)
#define REG_PUB_APB_DMC_PORT8_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3054)
#define REG_PUB_APB_DMC_PORT9_MPU_RANGE                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3058)
#define REG_PUB_APB_DMC_PORT0_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x305C)
#define REG_PUB_APB_DMC_PORT1_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3060)
#define REG_PUB_APB_DMC_PORT2_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3064)
#define REG_PUB_APB_DMC_PORT3_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3068)
#define REG_PUB_APB_DMC_PORT4_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x306C)
#define REG_PUB_APB_DMC_PORT5_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3070)
#define REG_PUB_APB_DMC_PORT6_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3074)
#define REG_PUB_APB_DMC_PORT7_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3078)
#define REG_PUB_APB_DMC_PORT8_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x307C)
#define REG_PUB_APB_DMC_PORT9_DUMP_ADDR                     SCI_ADDR(CTL_PUB_APB_BASE, 0x3080)
#define REG_PUB_APB_SYS_ENDIAN_CTRL                         SCI_ADDR(CTL_PUB_APB_BASE, 0x3090)
#define REG_PUB_APB_DMC_DUMMY_REG0                          SCI_ADDR(CTL_PUB_APB_BASE, 0x30A0)
#define REG_PUB_APB_DMC_DUMMY_REG1                          SCI_ADDR(CTL_PUB_APB_BASE, 0x30A4)
#define REG_PUB_APB_DMC_DUMMY_REG2                          SCI_ADDR(CTL_PUB_APB_BASE, 0x30A8)
#define REG_PUB_APB_DMC_DUMMY_REG3                          SCI_ADDR(CTL_PUB_APB_BASE, 0x30AC)
#define REG_PUB_APB_DMC_QOS_SEL                             SCI_ADDR(CTL_PUB_APB_BASE, 0x3100)
#define REG_PUB_APB_DMC_ARQOS_0_7                           SCI_ADDR(CTL_PUB_APB_BASE, 0x3110)
#define REG_PUB_APB_DMC_ARQOS_8                             SCI_ADDR(CTL_PUB_APB_BASE, 0x3114)
#define REG_PUB_APB_DMC_AWQOS_0_7                           SCI_ADDR(CTL_PUB_APB_BASE, 0x3118)
#define REG_PUB_APB_DMC_AWQOS_8                             SCI_ADDR(CTL_PUB_APB_BASE, 0x311C)
#define REG_PUB_APB_DMC_ARQOS_0_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3120)
#define REG_PUB_APB_DMC_ARQOS_1_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3124)
#define REG_PUB_APB_DMC_ARQOS_2_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3128)
#define REG_PUB_APB_DMC_ARQOS_3_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x312C)
#define REG_PUB_APB_DMC_ARQOS_4_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3130)
#define REG_PUB_APB_DMC_ARQOS_5_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3134)
#define REG_PUB_APB_DMC_ARQOS_6_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3138)
#define REG_PUB_APB_DMC_ARQOS_7_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x313C)
#define REG_PUB_APB_DMC_ARQOS_8_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3140)
#define REG_PUB_APB_DMC_AWQOS_0_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3150)
#define REG_PUB_APB_DMC_AWQOS_1_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3154)
#define REG_PUB_APB_DMC_AWQOS_2_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3158)
#define REG_PUB_APB_DMC_AWQOS_3_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x315C)
#define REG_PUB_APB_DMC_AWQOS_4_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3160)
#define REG_PUB_APB_DMC_AWQOS_5_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3164)
#define REG_PUB_APB_DMC_AWQOS_6_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3168)
#define REG_PUB_APB_DMC_AWQOS_7_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x316C)
#define REG_PUB_APB_DMC_AWQOS_8_ID                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3170)
#define REG_PUB_APB_DMC_EXT_LPCTRL_CFG                      SCI_ADDR(CTL_PUB_APB_BASE, 0x31A0)
#define REG_PUB_APB_DMC_EXT_LPCTRL_SEQL                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31A4)
#define REG_PUB_APB_DMC_EXT_LPCTRL_SEQH                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31A8)
#define REG_PUB_APB_DMC_EXT_LPCTRL_STEP                     SCI_ADDR(CTL_PUB_APB_BASE, 0x31AC)
#define REG_PUB_APB_QOS_SELECT                              SCI_ADDR(CTL_PUB_APB_BASE, 0x31B0)
#define REG_PUB_APB_DMC_PORTS_MPU_SEL                       SCI_ADDR(CTL_PUB_APB_BASE, 0x31B4)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_SEL                SCI_ADDR(CTL_PUB_APB_BASE, 0x31B8)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_RID_MASK           SCI_ADDR(CTL_PUB_APB_BASE, 0x31BC)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_WID_MASK           SCI_ADDR(CTL_PUB_APB_BASE, 0x31C0)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_RID_VAL            SCI_ADDR(CTL_PUB_APB_BASE, 0x31C4)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_WID_VAL            SCI_ADDR(CTL_PUB_APB_BASE, 0x31C8)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_RHIGH_RANGE        SCI_ADDR(CTL_PUB_APB_BASE, 0x31CC)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_RLOW_RANGE         SCI_ADDR(CTL_PUB_APB_BASE, 0x31D0)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_WHIGH_RANGE        SCI_ADDR(CTL_PUB_APB_BASE, 0x31D4)
#define REG_PUB_APB_DMC_PORTS_MPU_SHARED_WLOW_RANGE         SCI_ADDR(CTL_PUB_APB_BASE, 0x31D8)
#define REG_PUB_APB_DMC_PORTS_MPU_CH0_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31DC)
#define REG_PUB_APB_DMC_PORTS_MPU_CH0_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31E0)
#define REG_PUB_APB_DMC_PORTS_MPU_CH1_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31E4)
#define REG_PUB_APB_DMC_PORTS_MPU_CH1_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31E8)
#define REG_PUB_APB_DMC_PORTS_MPU_CH2_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31EC)
#define REG_PUB_APB_DMC_PORTS_MPU_CH2_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31F0)
#define REG_PUB_APB_DMC_PORTS_MPU_CH3_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31F4)
#define REG_PUB_APB_DMC_PORTS_MPU_CH3_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31F8)
#define REG_PUB_APB_DMC_PORTS_MPU_CH4_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x31FC)
#define REG_PUB_APB_DMC_PORTS_MPU_CH4_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x3200)
#define REG_PUB_APB_DMC_PORTS_MPU_CH5_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x3204)
#define REG_PUB_APB_DMC_PORTS_MPU_CH5_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x3208)
#define REG_PUB_APB_DMC_PORTS_MPU_CH6_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x320C)
#define REG_PUB_APB_DMC_PORTS_MPU_CH6_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x3210)
#define REG_PUB_APB_DMC_PORTS_MPU_CH7_RID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x3214)
#define REG_PUB_APB_DMC_PORTS_MPU_CH7_WID_MASK_VAL          SCI_ADDR(CTL_PUB_APB_BASE, 0x3218)
#define REG_PUB_APB_DMC_PORT_MPU_CH0_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x321C)
#define REG_PUB_APB_DMC_PORT_MPU_CH0_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3220)
#define REG_PUB_APB_DMC_PORT_MPU_CH1_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3224)
#define REG_PUB_APB_DMC_PORT_MPU_CH1_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3228)
#define REG_PUB_APB_DMC_PORT_MPU_CH2_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x322C)
#define REG_PUB_APB_DMC_PORT_MPU_CH2_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3230)
#define REG_PUB_APB_DMC_PORT_MPU_CH3_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3234)
#define REG_PUB_APB_DMC_PORT_MPU_CH3_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3238)
#define REG_PUB_APB_DMC_PORT_MPU_CH4_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x323C)
#define REG_PUB_APB_DMC_PORT_MPU_CH4_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3240)
#define REG_PUB_APB_DMC_PORT_MPU_CH5_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3244)
#define REG_PUB_APB_DMC_PORT_MPU_CH5_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3248)
#define REG_PUB_APB_DMC_PORT_MPU_CH6_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x324C)
#define REG_PUB_APB_DMC_PORT_MPU_CH6_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3250)
#define REG_PUB_APB_DMC_PORT_MPU_CH7_RLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3254)
#define REG_PUB_APB_DMC_PORT_MPU_CH7_WLOW_RANGE             SCI_ADDR(CTL_PUB_APB_BASE, 0x3258)
#define REG_PUB_APB_DMC_PORT_MPU_CH0_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x325C)
#define REG_PUB_APB_DMC_PORT_MPU_CH0_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3260)
#define REG_PUB_APB_DMC_PORT_MPU_CH1_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3264)
#define REG_PUB_APB_DMC_PORT_MPU_CH1_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3268)
#define REG_PUB_APB_DMC_PORT_MPU_CH2_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x326C)
#define REG_PUB_APB_DMC_PORT_MPU_CH2_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3270)
#define REG_PUB_APB_DMC_PORT_MPU_CH3_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3274)
#define REG_PUB_APB_DMC_PORT_MPU_CH3_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3278)
#define REG_PUB_APB_DMC_PORT_MPU_CH4_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x327C)
#define REG_PUB_APB_DMC_PORT_MPU_CH4_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3280)
#define REG_PUB_APB_DMC_PORT_MPU_CH5_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3284)
#define REG_PUB_APB_DMC_PORT_MPU_CH5_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3288)
#define REG_PUB_APB_DMC_PORT_MPU_CH6_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x328C)
#define REG_PUB_APB_DMC_PORT_MPU_CH6_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3290)
#define REG_PUB_APB_DMC_PORT_MPU_CH7_RHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3294)
#define REG_PUB_APB_DMC_PORT_MPU_CH7_WHIGH_RANGE            SCI_ADDR(CTL_PUB_APB_BASE, 0x3298)
#define REG_PUB_APB_DMC_MPU_VIO_ADDR                        SCI_ADDR(CTL_PUB_APB_BASE, 0x329C)
#define REG_PUB_APB_DMC_MPU_VIO_CMD                         SCI_ADDR(CTL_PUB_APB_BASE, 0x32A0)
#define REG_PUB_APB_DMC_MPU_VIO_USERID                      SCI_ADDR(CTL_PUB_APB_BASE, 0x32A4)
#define REG_PUB_APB_DMC_REMAP_EN                            SCI_ADDR(CTL_PUB_APB_BASE, 0x32A8)
#define REG_PUB_APB_DMC_PORT0_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32AC)
#define REG_PUB_APB_DMC_PORT0_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32B0)
#define REG_PUB_APB_DMC_PORT1_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32B4)
#define REG_PUB_APB_DMC_PORT1_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32B8)
#define REG_PUB_APB_DMC_PORT2_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32BC)
#define REG_PUB_APB_DMC_PORT2_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32C0)
#define REG_PUB_APB_DMC_PORT3_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32C4)
#define REG_PUB_APB_DMC_PORT3_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32C8)
#define REG_PUB_APB_DMC_PORT4_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32CC)
#define REG_PUB_APB_DMC_PORT4_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32D0)
#define REG_PUB_APB_DMC_PORT5_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32D4)
#define REG_PUB_APB_DMC_PORT5_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32D8)
#define REG_PUB_APB_DMC_PORT6_REMAP_ADDR_0                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32DC)
#define REG_PUB_APB_DMC_PORT6_REMAP_ADDR_1                  SCI_ADDR(CTL_PUB_APB_BASE, 0x32E0)
#define REG_PUB_APB_DMC_MPU_DUMP_ADDR                       SCI_ADDR(CTL_PUB_APB_BASE, 0x32E4)
#define REG_PUB_APB_PUB_DMC_MPU_INT                         SCI_ADDR(CTL_PUB_APB_BASE, 0x32E8)
#define REG_PUB_APB_PUB_AXI_QOS_REG                         SCI_ADDR(CTL_PUB_APB_BASE, 0x32EC)
#define REG_PUB_APB_DFS_INT_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x32F0)
#define REG_PUB_APB_DFS_STATUS                              SCI_ADDR(CTL_PUB_APB_BASE, 0x32F4)
#define REG_PUB_APB_DFS_SW_CTRL                             SCI_ADDR(CTL_PUB_APB_BASE, 0x32F8)
#define REG_PUB_APB_DFS_FC_REQ_DELAY                        SCI_ADDR(CTL_PUB_APB_BASE, 0x32FC)
#define REG_PUB_APB_DFS_HW_CTRL                             SCI_ADDR(CTL_PUB_APB_BASE, 0x3300)
#define REG_PUB_APB_DFS_HW_FRQ_RATIO                        SCI_ADDR(CTL_PUB_APB_BASE, 0x3334)
#define REG_PUB_APB_DFS_PURE_SW_CTRL                        SCI_ADDR(CTL_PUB_APB_BASE, 0x3338)
#define REG_PUB_APB_MEM_FW_INT                              SCI_ADDR(CTL_PUB_APB_BASE, 0x333C)
#define REG_PUB_APB_AXI_LPC_CTRL_0                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3340)
#define REG_PUB_APB_AXI_LPC_CTRL_1                          SCI_ADDR(CTL_PUB_APB_BASE, 0x3344)
#define REG_PUB_APB_FENCING_CTRL                            SCI_ADDR(CTL_PUB_APB_BASE, 0x3348)
#define REG_PUB_APB_BASE_ADDR                               SCI_ADDR(CTL_PUB_APB_BASE, 0x334C)
#define REG_PUB_APB_WIFI_DFS_CTRL                           SCI_ADDR(CTL_PUB_APB_BASE, 0x3350)
#define REG_PUB_APB_DFS_SW_GFREE_CFG                        SCI_ADDR(CTL_PUB_APB_BASE, 0x3354)

/* bits definitions for REG_PUB_APB_BUSMON_CNT_START, [0x300E0000] */

/* bits definitions for REG_PUB_APB_BUSMON_CFG, [0x300E0004] */
#define BIT_PUB_APB_BUSMON_EB                               ( BIT(23) )
#define BIT_PUB_APB_PUB_BUSMON6_EB                          ( BIT(22) )
#define BIT_PUB_APB_PUB_BUSMON5_EB                          ( BIT(21) )
#define BIT_PUB_APB_PUB_BUSMON4_EB                          ( BIT(20) )
#define BIT_PUB_APB_PUB_BUSMON3_EB                          ( BIT(19) )
#define BIT_PUB_APB_PUB_BUSMON2_EB                          ( BIT(18) )
#define BIT_PUB_APB_PUB_BUSMON1_EB                          ( BIT(17) )
#define BIT_PUB_APB_PUB_BUSMON0_EB                          ( BIT(16) )
#define BIT_PUB_APB_BUSMON_SOFT_RST                         ( BIT(7) )
#define BIT_PUB_APB_PUB_BUSMON6_SOFT_RST                    ( BIT(6) )
#define BIT_PUB_APB_PUB_BUSMON5_SOFT_RST                    ( BIT(5) )
#define BIT_PUB_APB_PUB_BUSMON4_SOFT_RST                    ( BIT(4) )
#define BIT_PUB_APB_PUB_BUSMON3_SOFT_RST                    ( BIT(3) )
#define BIT_PUB_APB_PUB_BUSMON2_SOFT_RST                    ( BIT(2) )
#define BIT_PUB_APB_PUB_BUSMON1_SOFT_RST                    ( BIT(1) )
#define BIT_PUB_APB_PUB_BUSMON0_SOFT_RST                    ( BIT(0) )

/* bits definitions for REG_PUB_APB_DDR_EB, [0x300E0008] */

/* bits definitions for REG_PUB_APB_DDR_SOFT_RST, [0x300E000C] */

/* bits definitions for REG_PUB_APB_DMC_PORT_REMAP_EN, [0x300E3000] */

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_EN, [0x300E3004] */

/* bits definitions for REG_PUB_APB_DMC_PORT0_ADDR_REMAP_0, [0x300E3008] */

/* bits definitions for REG_PUB_APB_DMC_PORT1_ADDR_REMAP_0, [0x300E300C] */

/* bits definitions for REG_PUB_APB_DMC_PORT2_ADDR_REMAP_0, [0x300E3010] */

/* bits definitions for REG_PUB_APB_DMC_PORT3_ADDR_REMAP_0, [0x300E3014] */

/* bits definitions for REG_PUB_APB_DMC_PORT4_ADDR_REMAP_0, [0x300E3018] */

/* bits definitions for REG_PUB_APB_DMC_PORT5_ADDR_REMAP_0, [0x300E301C] */

/* bits definitions for REG_PUB_APB_DMC_PORT6_ADDR_REMAP_0, [0x300E3020] */

/* bits definitions for REG_PUB_APB_DMC_PORT7_ADDR_REMAP_0, [0x300E3024] */

/* bits definitions for REG_PUB_APB_DMC_PORT8_ADDR_REMAP_0, [0x300E3028] */

/* bits definitions for REG_PUB_APB_DMC_PORT9_ADDR_REMAP_0, [0x300E302C] */

/* bits definitions for REG_PUB_APB_DMC_PORT0_MPU_RANGE, [0x300E3030] */

/* bits definitions for REG_PUB_APB_DMC_PORT1_MPU_RANGE, [0x300E3034] */

/* bits definitions for REG_PUB_APB_DMC_PORT2_MPU_RANGE, [0x300E3038] */

/* bits definitions for REG_PUB_APB_DMC_PORT3_MPU_RANGE, [0x300E303C] */

/* bits definitions for REG_PUB_APB_DMC_PORT4_MPU_RANGE, [0x300E3040] */

/* bits definitions for REG_PUB_APB_DMC_PORT5_MPU_RANGE, [0x300E3044] */

/* bits definitions for REG_PUB_APB_DMC_PORT6_MPU_RANGE, [0x300E3048] */

/* bits definitions for REG_PUB_APB_DMC_PORT7_MPU_RANGE, [0x300E3050] */

/* bits definitions for REG_PUB_APB_DMC_PORT8_MPU_RANGE, [0x300E3054] */

/* bits definitions for REG_PUB_APB_DMC_PORT9_MPU_RANGE, [0x300E3058] */

/* bits definitions for REG_PUB_APB_DMC_PORT0_DUMP_ADDR, [0x300E305C] */

/* bits definitions for REG_PUB_APB_DMC_PORT1_DUMP_ADDR, [0x300E3060] */

/* bits definitions for REG_PUB_APB_DMC_PORT2_DUMP_ADDR, [0x300E3064] */

/* bits definitions for REG_PUB_APB_DMC_PORT3_DUMP_ADDR, [0x300E3068] */

/* bits definitions for REG_PUB_APB_DMC_PORT4_DUMP_ADDR, [0x300E306C] */

/* bits definitions for REG_PUB_APB_DMC_PORT5_DUMP_ADDR, [0x300E3070] */

/* bits definitions for REG_PUB_APB_DMC_PORT6_DUMP_ADDR, [0x300E3074] */

/* bits definitions for REG_PUB_APB_DMC_PORT7_DUMP_ADDR, [0x300E3078] */

/* bits definitions for REG_PUB_APB_DMC_PORT8_DUMP_ADDR, [0x300E307C] */

/* bits definitions for REG_PUB_APB_DMC_PORT9_DUMP_ADDR, [0x300E3080] */

/* bits definitions for REG_PUB_APB_SYS_ENDIAN_CTRL, [0x300E3090] */

/* bits definitions for REG_PUB_APB_DMC_DUMMY_REG0, [0x300E30A0] */
#define BIT_PUB_APB_DMC_DUMMY_REG0(x)                       ( (x) )

/* bits definitions for REG_PUB_APB_DMC_DUMMY_REG1, [0x300E30A4] */
#define BIT_PUB_APB_DMC_DUMMY_REG1(x)                       ( (x) )

/* bits definitions for REG_PUB_APB_DMC_DUMMY_REG2, [0x300E30A8] */
#define BIT_PUB_APB_DMC_DUMMY_REG2(x)                       ( (x) )

/* bits definitions for REG_PUB_APB_DMC_DUMMY_REG3, [0x300E30AC] */
#define BIT_PUB_APB_DMC_DUMMY_REG3(x)                       ( (x) )

/* bits definitions for REG_PUB_APB_DMC_QOS_SEL, [0x300E3100] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_0_7, [0x300E3110] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_8, [0x300E3114] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_0_7, [0x300E3118] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_8, [0x300E311C] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_0_ID, [0x300E3120] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_1_ID, [0x300E3124] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_2_ID, [0x300E3128] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_3_ID, [0x300E312C] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_4_ID, [0x300E3130] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_5_ID, [0x300E3134] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_6_ID, [0x300E3138] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_7_ID, [0x300E313C] */

/* bits definitions for REG_PUB_APB_DMC_ARQOS_8_ID, [0x300E3140] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_0_ID, [0x300E3150] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_1_ID, [0x300E3154] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_2_ID, [0x300E3158] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_3_ID, [0x300E315C] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_4_ID, [0x300E3160] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_5_ID, [0x300E3164] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_6_ID, [0x300E3168] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_7_ID, [0x300E316C] */

/* bits definitions for REG_PUB_APB_DMC_AWQOS_8_ID, [0x300E3170] */

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_CFG, [0x300E31A0] */
#define BIT_PUB_APB_SOFT_CMD_NUM(x)                         ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_SOFT_CMD_FC_SEL(x)                      ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_SOFT_CMD_RESP                           ( BIT(3) )
#define BIT_PUB_APB_SOFT_CMD_DONE                           ( BIT(2) )
#define BIT_PUB_APB_SOFT_CMD_START                          ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_SEQL, [0x300E31A4] */
#define BIT_PUB_APB_SOFT_CMD_SEQL(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_SEQH, [0x300E31A8] */
#define BIT_PUB_APB_SOFT_CMD_SEQH(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_DMC_EXT_LPCTRL_STEP, [0x300E31AC] */
#define BIT_PUB_APB_SOFT_CMD_STEP(x)                        ( (x) )

/* bits definitions for REG_PUB_APB_QOS_SELECT, [0x300E31B0] */

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SEL, [0x300E31B4] */
#define BIT_PUB_APB_USRID_SEL(x)                            ( (x) << 17 & (BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_PUB_APB_MPU_SEL(x)                              ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_PUB_APB_MPU_PORT_EN(x)                          ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)) )
#define BIT_PUB_APB_MPU_EN                                  ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_SEL, [0x300E31B8] */
#define BIT_PUB_APB_MPU_SHARED_PORT(x)                      ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_PUB_APB_MPU_SHARED_USRID_SEL                    ( BIT(2) )
#define BIT_PUB_APB_MPU_SHARED_SEL                          ( BIT(1) )
#define BIT_PUB_APB_MPU_SHARED_EN                           ( BIT(0) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_RID_MASK, [0x300E31BC] */
#define BIT_PUB_APB_MPU_SHARED_RID_MASK(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_WID_MASK, [0x300E31C0] */
#define BIT_PUB_APB_MPU_SHARED_WID_MASK(x)                  ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_RID_VAL, [0x300E31C4] */
#define BIT_PUB_APB_MPU_SHARED_RID_VAL(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_WID_VAL, [0x300E31C8] */
#define BIT_PUB_APB_MPU_SHARED_WID_VAL(x)                   ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_RHIGH_RANGE, [0x300E31CC] */
#define BIT_PUB_APB_MPU_SHARED_RHIGH_RANGE(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_RLOW_RANGE, [0x300E31D0] */
#define BIT_PUB_APB_MPU_SHARED_RLOW_RANGE(x)                ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_WHIGH_RANGE, [0x300E31D4] */
#define BIT_PUB_APB_MPU_SHARED_WHIGH_RANGE(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_SHARED_WLOW_RANGE, [0x300E31D8] */
#define BIT_PUB_APB_MPU_SHARED_WLOW_RANGE(x)                ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH0_RID_MASK_VAL, [0x300E31DC] */
#define BIT_PUB_APB_MPU_CH0_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH0_WID_MASK_VAL, [0x300E31E0] */
#define BIT_PUB_APB_MPU_CH0_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH1_RID_MASK_VAL, [0x300E31E4] */
#define BIT_PUB_APB_MPU_CH1_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH1_WID_MASK_VAL, [0x300E31E8] */
#define BIT_PUB_APB_MPU_CH1_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH2_RID_MASK_VAL, [0x300E31EC] */
#define BIT_PUB_APB_MPU_CH2_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH2_WID_MASK_VAL, [0x300E31F0] */
#define BIT_PUB_APB_MPU_CH2_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH3_RID_MASK_VAL, [0x300E31F4] */
#define BIT_PUB_APB_MPU_CH3_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH3_WID_MASK_VAL, [0x300E31F8] */
#define BIT_PUB_APB_MPU_CH3_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH4_RID_MASK_VAL, [0x300E31FC] */
#define BIT_PUB_APB_MPU_CH4_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH4_WID_MASK_VAL, [0x300E3200] */
#define BIT_PUB_APB_MPU_CH4_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH5_RID_MASK_VAL, [0x300E3204] */
#define BIT_PUB_APB_MPU_CH5_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH5_WID_MASK_VAL, [0x300E3208] */
#define BIT_PUB_APB_MPU_CH5_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH6_RID_MASK_VAL, [0x300E320C] */
#define BIT_PUB_APB_MPU_CH6_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH6_WID_MASK_VAL, [0x300E3210] */
#define BIT_PUB_APB_MPU_CH6_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH7_RID_MASK_VAL, [0x300E3214] */
#define BIT_PUB_APB_MPU_CH7_RID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORTS_MPU_CH7_WID_MASK_VAL, [0x300E3218] */
#define BIT_PUB_APB_MPU_CH7_WID_MASK_VAL(x)                 ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH0_RLOW_RANGE, [0x300E321C] */
#define BIT_PUB_APB_MPU_CH0_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH0_WLOW_RANGE, [0x300E3220] */
#define BIT_PUB_APB_MPU_CH0_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH1_RLOW_RANGE, [0x300E3224] */
#define BIT_PUB_APB_MPU_CH1_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH1_WLOW_RANGE, [0x300E3228] */
#define BIT_PUB_APB_MPU_CH1_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH2_RLOW_RANGE, [0x300E322C] */
#define BIT_PUB_APB_MPU_CH2_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH2_WLOW_RANGE, [0x300E3230] */
#define BIT_PUB_APB_MPU_CH2_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH3_RLOW_RANGE, [0x300E3234] */
#define BIT_PUB_APB_MPU_CH3_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH3_WLOW_RANGE, [0x300E3238] */
#define BIT_PUB_APB_MPU_CH3_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH4_RLOW_RANGE, [0x300E323C] */
#define BIT_PUB_APB_MPU_CH4_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH4_WLOW_RANGE, [0x300E3240] */
#define BIT_PUB_APB_MPU_CH4_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH5_RLOW_RANGE, [0x300E3244] */
#define BIT_PUB_APB_MPU_CH5_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH5_WLOW_RANGE, [0x300E3248] */
#define BIT_PUB_APB_MPU_CH5_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH6_RLOW_RANGE, [0x300E324C] */
#define BIT_PUB_APB_MPU_CH6_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH6_WLOW_RANGE, [0x300E3250] */
#define BIT_PUB_APB_MPU_CH6_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH7_RLOW_RANGE, [0x300E3254] */
#define BIT_PUB_APB_MPU_CH7_RLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH7_WLOW_RANGE, [0x300E3258] */
#define BIT_PUB_APB_MPU_CH7_WLOW_RANGE(x)                   ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH0_RHIGH_RANGE, [0x300E325C] */
#define BIT_PUB_APB_MPU_CH0_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH0_WHIGH_RANGE, [0x300E3260] */
#define BIT_PUB_APB_MPU_CH0_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH1_RHIGH_RANGE, [0x300E3264] */
#define BIT_PUB_APB_MPU_CH1_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH1_WHIGH_RANGE, [0x300E3268] */
#define BIT_PUB_APB_MPU_CH1_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH2_RHIGH_RANGE, [0x300E326C] */
#define BIT_PUB_APB_MPU_CH2_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH2_WHIGH_RANGE, [0x300E3270] */
#define BIT_PUB_APB_MPU_CH2_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH3_RHIGH_RANGE, [0x300E3274] */
#define BIT_PUB_APB_MPU_CH3_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH3_WHIGH_RANGE, [0x300E3278] */
#define BIT_PUB_APB_MPU_CH3_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH4_RHIGH_RANGE, [0x300E327C] */
#define BIT_PUB_APB_MPU_CH4_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH4_WHIGH_RANGE, [0x300E3280] */
#define BIT_PUB_APB_MPU_CH4_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH5_RHIGH_RANGE, [0x300E3284] */
#define BIT_PUB_APB_MPU_CH5_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH5_WHIGH_RANGE, [0x300E3288] */
#define BIT_PUB_APB_MPU_CH5_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH6_RHIGH_RANGE, [0x300E328C] */
#define BIT_PUB_APB_MPU_CH6_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH6_WHIGH_RANGE, [0x300E3290] */
#define BIT_PUB_APB_MPU_CH6_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH7_RHIGH_RANGE, [0x300E3294] */
#define BIT_PUB_APB_MPU_CH7_RHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT_MPU_CH7_WHIGH_RANGE, [0x300E3298] */
#define BIT_PUB_APB_MPU_CH7_WHIGH_RANGE(x)                  ( (x) )

/* bits definitions for REG_PUB_APB_DMC_MPU_VIO_ADDR, [0x300E329C] */
#define BIT_PUB_APB_DMC_MPU_VIO_ADDR(x)                     ( (x) )

/* bits definitions for REG_PUB_APB_DMC_MPU_VIO_CMD, [0x300E32A0] */
#define BIT_PUB_APB_DMC_MPU_VIO_CMD(x)                      ( (x) )

/* bits definitions for REG_PUB_APB_DMC_MPU_VIO_USERID, [0x300E32A4] */
#define BIT_PUB_APB_DMC_MPU_VIO_USERID(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_PUB_APB_DMC_REMAP_EN, [0x300E32A8] */
#define BIT_PUB_APB_DMC_REMAP_EN(x)                         ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)) )

/* bits definitions for REG_PUB_APB_DMC_PORT0_REMAP_ADDR_0, [0x300E32AC] */
#define BIT_PUB_APB_DMC_PORT0_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT0_REMAP_ADDR_1, [0x300E32B0] */
#define BIT_PUB_APB_DMC_PORT0_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT1_REMAP_ADDR_0, [0x300E32B4] */
#define BIT_PUB_APB_DMC_PORT1_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT1_REMAP_ADDR_1, [0x300E32B8] */
#define BIT_PUB_APB_DMC_PORT1_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT2_REMAP_ADDR_0, [0x300E32BC] */
#define BIT_PUB_APB_DMC_PORT2_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT2_REMAP_ADDR_1, [0x300E32C0] */
#define BIT_PUB_APB_DMC_PORT2_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT3_REMAP_ADDR_0, [0x300E32C4] */
#define BIT_PUB_APB_DMC_PORT3_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT3_REMAP_ADDR_1, [0x300E32C8] */
#define BIT_PUB_APB_DMC_PORT3_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT4_REMAP_ADDR_0, [0x300E32CC] */
#define BIT_PUB_APB_DMC_PORT4_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT4_REMAP_ADDR_1, [0x300E32D0] */
#define BIT_PUB_APB_DMC_PORT4_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT5_REMAP_ADDR_0, [0x300E32D4] */
#define BIT_PUB_APB_DMC_PORT5_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT5_REMAP_ADDR_1, [0x300E32D8] */
#define BIT_PUB_APB_DMC_PORT5_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT6_REMAP_ADDR_0, [0x300E32DC] */
#define BIT_PUB_APB_DMC_PORT6_REMAP_ADDR_0(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_PORT6_REMAP_ADDR_1, [0x300E32E0] */
#define BIT_PUB_APB_DMC_PORT6_REMAP_ADDR_1(x)               ( (x) )

/* bits definitions for REG_PUB_APB_DMC_MPU_DUMP_ADDR, [0x300E32E4] */
#define BIT_PUB_APB_DMC_MPU_DUMP_ADDR(x)                    ( (x) )

/* bits definitions for REG_PUB_APB_PUB_DMC_MPU_INT, [0x300E32E8] */
#define BIT_PUB_APB_INT_DMC_MPU_VIO                         ( BIT(3) )
#define BIT_PUB_APB_DMC_MPU_VIO_INT_RAW                     ( BIT(2) )
#define BIT_PUB_APB_DMC_MPU_VIO_INT_CLR                     ( BIT(1) )
#define BIT_PUB_APB_DMC_MPU_VIO_INT_EN                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_PUB_AXI_QOS_REG, [0x300E32EC] */
#define BIT_PUB_APB_AWQOS_THRESHOLD_CP(x)                   ( (x) << 28 & (BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_CP(x)                   ( (x) << 24 & (BIT(24)|BIT(25)|BIT(26)|BIT(27)) )
#define BIT_PUB_APB_AWQOS_THRESHOLD_AON_WCN(x)              ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_ARQOS_THRESHOLD_AON_WCN(x)              ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_AWQOS_WCN(x)                            ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_ARQOS_WCN(x)                            ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_AWQOS_AON(x)                            ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_ARQOS_AON(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_DFS_INT_CTRL, [0x300E32F0] */
#define BIT_PUB_APB_DFS_ERROR_INT_CLR                       ( BIT(5) )
#define BIT_PUB_APB_DFS_ERROR_INT_EN                        ( BIT(4) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_CLR                    ( BIT(3) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_EN                     ( BIT(2) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_CLR                     ( BIT(1) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_EN                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_STATUS, [0x300E32F4] */
#define BIT_PUB_APB_HW_DFS_FSM_STATE(x)                     ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_PUB_APB_HW_DFS_FSM_IDLE                         ( BIT(6) )
#define BIT_PUB_APB_DFS_ERROR_INT_RAW                       ( BIT(5) )
#define BIT_PUB_APB_INT_DFS_ERROR                           ( BIT(4) )
#define BIT_PUB_APB_DFS_COMPLETE_INT_RAW                    ( BIT(3) )
#define BIT_PUB_APB_INT_DFS_COMPLETE                        ( BIT(2) )
#define BIT_PUB_APB_HW_DFS_EXIT_INT_RAW                     ( BIT(1) )
#define BIT_PUB_APB_INT_HW_DFS_EXIT                         ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_SW_CTRL, [0x300E32F8] */
#define BIT_PUB_APB_PUB_DFS_SW_SWITCH_PERIOD(x)             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)|BIT(30)|BIT(31)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO_DEFAULT(x)             ( (x) << 13 & (BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_PUB_APB_PUB_DFS_SW_RATIO(x)                     ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)) )
#define BIT_PUB_APB_PUB_DFS_SW_FRQ_SEL(x)                   ( (x) << 4  & (BIT(4)|BIT(5)) )
#define BIT_PUB_APB_PUB_DFS_SW_RESP                         ( BIT(3) )
#define BIT_PUB_APB_PUB_DFS_SW_ACK                          ( BIT(2) )
#define BIT_PUB_APB_PUB_DFS_SW_REQ                          ( BIT(1) )
#define BIT_PUB_APB_PUB_DFS_SW_ENABLE                       ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_FC_REQ_DELAY, [0x300E32FC] */
#define BIT_PUB_APB_DFS_FC_REQ_DELAY(x)                     ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_PUB_APB_DFS_HW_CTRL, [0x300E3300] */

/* bits definitions for REG_PUB_APB_DFS_HW_FRQ_RATIO, [0x300E3334] */

/* bits definitions for REG_PUB_APB_DFS_PURE_SW_CTRL, [0x300E3338] */
#define BIT_PUB_APB_PURE_SW_DFS_ACK                         ( BIT(14) )
#define BIT_PUB_APB_PURE_SW_DFS_RESP                        ( BIT(13) )
#define BIT_PUB_APB_PURE_SW_DFS_FC_REQ                      ( BIT(12) )
#define BIT_PUB_APB_PURE_SW_DFS_REQ                         ( BIT(11) )
#define BIT_PUB_APB_PURE_SW_DFS_FC_ACK                      ( BIT(10) )
#define BIT_PUB_APB_PURE_SW_DFS_FRQ_SEL(x)                  ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_PUB_APB_EMC_CKG_SEL_PURE_SW(x)                  ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_DFS_SW_DFS_MODE                         ( BIT(0) )

/* bits definitions for REG_PUB_APB_MEM_FW_INT, [0x300E333C] */
#define BIT_PUB_APB_MEM_FW_INT_RAW                          ( BIT(3) )
#define BIT_PUB_APB_INT_MEM_FW                              ( BIT(2) )
#define BIT_PUB_APB_MEM_FW_INT_CLR                          ( BIT(1) )
#define BIT_PUB_APB_MEM_FW_INT_EN                           ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_0, [0x300E3340] */
#define BIT_PUB_APB_LP_FORCE_AON_WCN_S0                     ( BIT(11) )
#define BIT_PUB_APB_LP_EB_AON_WCN_S0                        ( BIT(10) )
#define BIT_PUB_APB_LP_FORCE_AON_WCN_M1                     ( BIT(9) )
#define BIT_PUB_APB_LP_EB_AON_WCN_M1                        ( BIT(8) )
#define BIT_PUB_APB_LP_FORCE_AON_WCN_M0                     ( BIT(7) )
#define BIT_PUB_APB_LP_EB_AON_WCN_M0                        ( BIT(6) )
#define BIT_PUB_APB_LP_FORCE_CP_S0                          ( BIT(5) )
#define BIT_PUB_APB_LP_EB_CP_S0                             ( BIT(4) )
#define BIT_PUB_APB_LP_FORCE_CP_M1                          ( BIT(3) )
#define BIT_PUB_APB_LP_EB_CP_M1                             ( BIT(2) )
#define BIT_PUB_APB_LP_FORCE_CP_M0                          ( BIT(1) )
#define BIT_PUB_APB_LP_EB_CP_M0                             ( BIT(0) )

/* bits definitions for REG_PUB_APB_AXI_LPC_CTRL_1, [0x300E3344] */
#define BIT_PUB_APB_LP_NUM(x)                               ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_PUB_APB_FENCING_CTRL, [0x300E3348] */
#define BIT_PUB_APB_DDR_FENCING_EN                          ( BIT(30) )
#define BIT_PUB_APB_FENCING_CHNL_IDLE_CNT(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_PUB_APB_BASE_ADDR, [0x300E334C] */
#define BIT_PUB_APB_PUB_CP_BASE_ADDR(x)                     ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_PUB_APB_WTL_CP_BASE_ADDR(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_PUB_APB_WCN_BASE_ADDR(x)                        ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_PUB_APB_AON_BASE_ADDR(x)                        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)) )

/* bits definitions for REG_PUB_APB_WIFI_DFS_CTRL, [0x300E3350] */
#define BIT_PUB_APB_WIFI_DFS_TIMEOUT_FLAG                   ( BIT(23) )
#define BIT_PUB_APB_WIFI_DFS_ACK                            ( BIT(22) )
#define BIT_PUB_APB_WIFI_DFS_URGENCY_CTRL_EN                ( BIT(21) )
#define BIT_PUB_APB_WIFI_FIFO_URGENCY_CTRL_EN               ( BIT(20) )
#define BIT_PUB_APB_WIFI_DFS_SW_REQ                         ( BIT(19) )
#define BIT_PUB_APB_WIFI_DFS_MODE                           ( BIT(18) )
#define BIT_PUB_APB_WIFI_DFS_TIMEOUT_EN                     ( BIT(17) )
#define BIT_PUB_APB_WIFI_DFS_TIMEOUT_PERIOD(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_PUB_APB_WIFI_DFS_HW_BYPASS                      ( BIT(0) )

/* bits definitions for REG_PUB_APB_DFS_SW_GFREE_CFG, [0x300E3354] */
#define BIT_PUB_APB_CGM_DFS_GFREE_SWITCH_SW_EN              ( BIT(24) )
#define BIT_PUB_APB_CGM_DFS_GFREE_SWITCH_DIV(x)             ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_PUB_APB_CGM_DFS_GFREE_SWITCH_SEL                ( BIT(19) )
#define BIT_PUB_APB_GFREE_SW_OPEN_DELAY(x)                  ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_PUB_APB_GFREE_SW_CLOSE_DELAY(x)                 ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )
#define BIT_PUB_APB_GFREE_SW_CTRL_BYPASS                    ( BIT(0) )

/* vars definitions for controller CTL_PUB_APB */


#endif /* __PUB_APB_H____ */

