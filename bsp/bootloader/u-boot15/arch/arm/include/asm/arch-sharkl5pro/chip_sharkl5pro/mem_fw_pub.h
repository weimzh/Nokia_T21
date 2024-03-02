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

#ifndef __MEM_FW_PUB_H____
#define __MEM_FW_PUB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_MEM_FW_PUB_BASE
#define CTL_MEM_FW_PUB_BASE             SCI_IOMAP(0x3280B000)
#endif

/* registers definitions for CTL_MEM_FW_PUB, 0x3280B000 */
#define REG_MEM_FW_PUB_PORT0_DEFAULT_R_ADDR_0               SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0000)
#define REG_MEM_FW_PUB_PORT0_DEFAULT_W_ADDR_0               SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0004)
#define REG_MEM_FW_PUB_PORT1_DEFAULT_R_ADDR_0               SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0008)
#define REG_MEM_FW_PUB_PORT1_DEFAULT_W_ADDR_0               SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x000C)
#define REG_MEM_FW_PUB_CLK_GATE_BYPASS                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0100)
#define REG_MEM_FW_PUB_PORT_INT_W_EN                        SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0200)
#define REG_MEM_FW_PUB_PORT_INT_W_CLR                       SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0204)
#define REG_MEM_FW_PUB_PORT_INT_W_RAW                       SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0208)
#define REG_MEM_FW_PUB_PORT_INT_W_FIN                       SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x020C)
#define REG_MEM_FW_PUB_PORT_INT_R_EN                        SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0210)
#define REG_MEM_FW_PUB_PORT_INT_R_CLR                       SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0214)
#define REG_MEM_FW_PUB_PORT_INT_R_RAW                       SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0218)
#define REG_MEM_FW_PUB_PORT_INT_R_FIN                       SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x021C)
#define REG_MEM_FW_PUB_PORT_0_W_DEBUG_ADDR                  SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0400)
#define REG_MEM_FW_PUB_PORT_0_W_DEBUG_ID                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0404)
#define REG_MEM_FW_PUB_PORT_0_R_DEBUG_ADDR                  SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0408)
#define REG_MEM_FW_PUB_PORT_0_R_DEBUG_ID                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x040C)
#define REG_MEM_FW_PUB_PORT_1_W_DEBUG_ADDR                  SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0410)
#define REG_MEM_FW_PUB_PORT_1_W_DEBUG_ID                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0414)
#define REG_MEM_FW_PUB_PORT_1_R_DEBUG_ADDR                  SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0418)
#define REG_MEM_FW_PUB_PORT_1_R_DEBUG_ID                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x041C)
#define REG_MEM_FW_PUB_SEG_DEFAULT_FIRST_ADDR               SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0800)
#define REG_MEM_FW_PUB_SEG_DEFAULT_LAST_ADDR                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0804)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID0                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0808)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID1                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x080C)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID2                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0810)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID3                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0814)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID4                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0818)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID5                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x081C)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID6                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0820)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID7                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0824)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID0                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0828)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID1                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x082C)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID2                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0830)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID3                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0834)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID4                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0838)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID5                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x083C)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID6                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0840)
#define REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID7                SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0844)
#define REG_MEM_FW_PUB_SEG_0_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1000)
#define REG_MEM_FW_PUB_SEG_0_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1004)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1008)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x100C)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1010)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1014)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1018)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x101C)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1020)
#define REG_MEM_FW_PUB_SEG_0_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1024)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1028)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x102C)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1030)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1034)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1038)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x103C)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1040)
#define REG_MEM_FW_PUB_SEG_0_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1044)
#define REG_MEM_FW_PUB_SEG_1_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1080)
#define REG_MEM_FW_PUB_SEG_1_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1084)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1088)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x108C)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1090)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1094)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1098)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x109C)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10A0)
#define REG_MEM_FW_PUB_SEG_1_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10A4)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10A8)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10AC)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10B0)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10B4)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10B8)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10BC)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10C0)
#define REG_MEM_FW_PUB_SEG_1_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x10C4)
#define REG_MEM_FW_PUB_SEG_2_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1100)
#define REG_MEM_FW_PUB_SEG_2_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1104)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1108)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x110C)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1110)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1114)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1118)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x111C)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1120)
#define REG_MEM_FW_PUB_SEG_2_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1124)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1128)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x112C)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1130)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1134)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1138)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x113C)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1140)
#define REG_MEM_FW_PUB_SEG_2_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1144)
#define REG_MEM_FW_PUB_SEG_3_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1180)
#define REG_MEM_FW_PUB_SEG_3_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1184)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1188)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x118C)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1190)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1194)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1198)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x119C)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11A0)
#define REG_MEM_FW_PUB_SEG_3_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11A4)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11A8)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11AC)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11B0)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11B4)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11B8)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11BC)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11C0)
#define REG_MEM_FW_PUB_SEG_3_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x11C4)
#define REG_MEM_FW_PUB_SEG_4_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1200)
#define REG_MEM_FW_PUB_SEG_4_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1204)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1208)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x120C)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1210)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1214)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1218)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x121C)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1220)
#define REG_MEM_FW_PUB_SEG_4_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1224)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1228)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x122C)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1230)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1234)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1238)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x123C)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1240)
#define REG_MEM_FW_PUB_SEG_4_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1244)
#define REG_MEM_FW_PUB_SEG_5_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1280)
#define REG_MEM_FW_PUB_SEG_5_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1284)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1288)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x128C)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1290)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1294)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1298)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x129C)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12A0)
#define REG_MEM_FW_PUB_SEG_5_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12A4)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12A8)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12AC)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12B0)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12B4)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12B8)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12BC)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12C0)
#define REG_MEM_FW_PUB_SEG_5_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x12C4)
#define REG_MEM_FW_PUB_SEG_6_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1300)
#define REG_MEM_FW_PUB_SEG_6_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1304)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1308)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x130C)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1310)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1314)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1318)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x131C)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1320)
#define REG_MEM_FW_PUB_SEG_6_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1324)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1328)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x132C)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1330)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1334)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1338)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x133C)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1340)
#define REG_MEM_FW_PUB_SEG_6_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1344)
#define REG_MEM_FW_PUB_SEG_7_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1380)
#define REG_MEM_FW_PUB_SEG_7_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1384)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1388)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x138C)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1390)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1394)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1398)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x139C)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13A0)
#define REG_MEM_FW_PUB_SEG_7_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13A4)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13A8)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13AC)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13B0)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13B4)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13B8)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13BC)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13C0)
#define REG_MEM_FW_PUB_SEG_7_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x13C4)

/* bits definitions for REG_MEM_FW_PUB_PORT0_DEFAULT_R_ADDR_0, [0x3280B000] */
#define BIT_MEM_FW_PUB_PORT0_DEFAULT_R_ADDR_0_PORT0_DEFAULT_R_ADDR_0(x)  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT0_DEFAULT_W_ADDR_0, [0x3280B004] */
#define BIT_MEM_FW_PUB_PORT0_DEFAULT_W_ADDR_0_PORT0_DEFAULT_W_ADDR_0(x)  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT1_DEFAULT_R_ADDR_0, [0x3280B008] */
#define BIT_MEM_FW_PUB_PORT1_DEFAULT_R_ADDR_0_PORT1_DEFAULT_R_ADDR_0(x)  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT1_DEFAULT_W_ADDR_0, [0x3280B00C] */
#define BIT_MEM_FW_PUB_PORT1_DEFAULT_W_ADDR_0_PORT1_DEFAULT_W_ADDR_0(x)  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_CLK_GATE_BYPASS, [0x3280B100] */
#define BIT_MEM_FW_PUB_CLK_GATE_BYPASS_CLK_GATE_BYPASS                   ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_EN, [0x3280B200] */
#define BIT_MEM_FW_PUB_PORT_INT_W_EN_PORT_1_W_EN                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_W_EN_PORT_0_W_EN                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_CLR, [0x3280B204] */
#define BIT_MEM_FW_PUB_PORT_INT_W_CLR_PORT_1_W_CLR                       ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_W_CLR_PORT_0_W_CLR                       ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_RAW, [0x3280B208] */
#define BIT_MEM_FW_PUB_PORT_INT_W_RAW_PORT_1_W_RAW                       ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_W_RAW_PORT_0_W_RAW                       ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_FIN, [0x3280B20C] */
#define BIT_MEM_FW_PUB_PORT_INT_W_FIN_PORT_1_W_FIN                       ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_W_FIN_PORT_0_W_FIN                       ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_EN, [0x3280B210] */
#define BIT_MEM_FW_PUB_PORT_INT_R_EN_PORT_1_R_EN                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_R_EN_PORT_0_R_EN                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_CLR, [0x3280B214] */
#define BIT_MEM_FW_PUB_PORT_INT_R_CLR_PORT_1_R_CLR                       ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_R_CLR_PORT_0_R_CLR                       ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_RAW, [0x3280B218] */
#define BIT_MEM_FW_PUB_PORT_INT_R_RAW_PORT_1_R_RAW                       ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_R_RAW_PORT_0_R_RAW                       ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_FIN, [0x3280B21C] */
#define BIT_MEM_FW_PUB_PORT_INT_R_FIN_PORT_1_R_FIN                       ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_INT_R_FIN_PORT_0_R_FIN                       ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_W_DEBUG_ADDR, [0x3280B400] */
#define BIT_MEM_FW_PUB_PORT_0_W_DEBUG_ADDR_W_ADDR_0(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_W_DEBUG_ID, [0x3280B404] */
#define BIT_MEM_FW_PUB_PORT_0_W_DEBUG_ID_W_ID_0(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_R_DEBUG_ADDR, [0x3280B408] */
#define BIT_MEM_FW_PUB_PORT_0_R_DEBUG_ADDR_R_ADDR_0(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_R_DEBUG_ID, [0x3280B40C] */
#define BIT_MEM_FW_PUB_PORT_0_R_DEBUG_ID_R_ID_0(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_W_DEBUG_ADDR, [0x3280B410] */
#define BIT_MEM_FW_PUB_PORT_1_W_DEBUG_ADDR_W_ADDR_1(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_W_DEBUG_ID, [0x3280B414] */
#define BIT_MEM_FW_PUB_PORT_1_W_DEBUG_ID_W_ID_1(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_R_DEBUG_ADDR, [0x3280B418] */
#define BIT_MEM_FW_PUB_PORT_1_R_DEBUG_ADDR_R_ADDR_1(x)                   ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_R_DEBUG_ID, [0x3280B41C] */
#define BIT_MEM_FW_PUB_PORT_1_R_DEBUG_ID_R_ID_1(x)                       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_FIRST_ADDR, [0x3280B800] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_FIRST_ADDR_FIRST_ADDR(x)              ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_LAST_ADDR, [0x3280B804] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_LAST_ADDR_LAST_ADDR(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID0, [0x3280B808] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID0_MST_R_ID0(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID1, [0x3280B80C] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID1_MST_R_ID1(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID2, [0x3280B810] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID2_MST_R_ID2(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID3, [0x3280B814] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID3_MST_R_ID3(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID4, [0x3280B818] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID4_MST_R_ID4(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID5, [0x3280B81C] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID5_MST_R_ID5(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID6, [0x3280B820] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID6_MST_R_ID6(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID7, [0x3280B824] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID7_MST_R_ID7(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID0, [0x3280B828] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID0_MST_W_ID0(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID1, [0x3280B82C] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID1_MST_W_ID1(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID2, [0x3280B830] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID2_MST_W_ID2(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID3, [0x3280B834] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID3_MST_W_ID3(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID4, [0x3280B838] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID4_MST_W_ID4(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID5, [0x3280B83C] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID5_MST_W_ID5(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID6, [0x3280B840] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID6_MST_W_ID6(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID7, [0x3280B844] */
#define BIT_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID7_MST_W_ID7(x)                ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_FIRST_ADDR, [0x3280C000] */
#define BIT_MEM_FW_PUB_SEG_0_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_LAST_ADDR, [0x3280C004] */
#define BIT_MEM_FW_PUB_SEG_0_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID0, [0x3280C008] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID1, [0x3280C00C] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID2, [0x3280C010] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID3, [0x3280C014] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID4, [0x3280C018] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID5, [0x3280C01C] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID6, [0x3280C020] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID7, [0x3280C024] */
#define BIT_MEM_FW_PUB_SEG_0_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID0, [0x3280C028] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID1, [0x3280C02C] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID2, [0x3280C030] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID3, [0x3280C034] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID4, [0x3280C038] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID5, [0x3280C03C] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID6, [0x3280C040] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID7, [0x3280C044] */
#define BIT_MEM_FW_PUB_SEG_0_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_FIRST_ADDR, [0x3280C080] */
#define BIT_MEM_FW_PUB_SEG_1_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_LAST_ADDR, [0x3280C084] */
#define BIT_MEM_FW_PUB_SEG_1_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID0, [0x3280C088] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID1, [0x3280C08C] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID2, [0x3280C090] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID3, [0x3280C094] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID4, [0x3280C098] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID5, [0x3280C09C] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID6, [0x3280C0A0] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID7, [0x3280C0A4] */
#define BIT_MEM_FW_PUB_SEG_1_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID0, [0x3280C0A8] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID1, [0x3280C0AC] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID2, [0x3280C0B0] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID3, [0x3280C0B4] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID4, [0x3280C0B8] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID5, [0x3280C0BC] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID6, [0x3280C0C0] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID7, [0x3280C0C4] */
#define BIT_MEM_FW_PUB_SEG_1_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_FIRST_ADDR, [0x3280C100] */
#define BIT_MEM_FW_PUB_SEG_2_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_LAST_ADDR, [0x3280C104] */
#define BIT_MEM_FW_PUB_SEG_2_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID0, [0x3280C108] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID1, [0x3280C10C] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID2, [0x3280C110] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID3, [0x3280C114] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID4, [0x3280C118] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID5, [0x3280C11C] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID6, [0x3280C120] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID7, [0x3280C124] */
#define BIT_MEM_FW_PUB_SEG_2_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID0, [0x3280C128] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID1, [0x3280C12C] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID2, [0x3280C130] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID3, [0x3280C134] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID4, [0x3280C138] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID5, [0x3280C13C] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID6, [0x3280C140] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID7, [0x3280C144] */
#define BIT_MEM_FW_PUB_SEG_2_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_FIRST_ADDR, [0x3280C180] */
#define BIT_MEM_FW_PUB_SEG_3_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_LAST_ADDR, [0x3280C184] */
#define BIT_MEM_FW_PUB_SEG_3_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID0, [0x3280C188] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID1, [0x3280C18C] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID2, [0x3280C190] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID3, [0x3280C194] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID4, [0x3280C198] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID5, [0x3280C19C] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID6, [0x3280C1A0] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID7, [0x3280C1A4] */
#define BIT_MEM_FW_PUB_SEG_3_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID0, [0x3280C1A8] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID1, [0x3280C1AC] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID2, [0x3280C1B0] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID3, [0x3280C1B4] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID4, [0x3280C1B8] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID5, [0x3280C1BC] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID6, [0x3280C1C0] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID7, [0x3280C1C4] */
#define BIT_MEM_FW_PUB_SEG_3_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_FIRST_ADDR, [0x3280C200] */
#define BIT_MEM_FW_PUB_SEG_4_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_LAST_ADDR, [0x3280C204] */
#define BIT_MEM_FW_PUB_SEG_4_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID0, [0x3280C208] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID1, [0x3280C20C] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID2, [0x3280C210] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID3, [0x3280C214] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID4, [0x3280C218] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID5, [0x3280C21C] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID6, [0x3280C220] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID7, [0x3280C224] */
#define BIT_MEM_FW_PUB_SEG_4_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID0, [0x3280C228] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID1, [0x3280C22C] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID2, [0x3280C230] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID3, [0x3280C234] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID4, [0x3280C238] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID5, [0x3280C23C] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID6, [0x3280C240] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID7, [0x3280C244] */
#define BIT_MEM_FW_PUB_SEG_4_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_FIRST_ADDR, [0x3280C280] */
#define BIT_MEM_FW_PUB_SEG_5_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_LAST_ADDR, [0x3280C284] */
#define BIT_MEM_FW_PUB_SEG_5_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID0, [0x3280C288] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID1, [0x3280C28C] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID2, [0x3280C290] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID3, [0x3280C294] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID4, [0x3280C298] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID5, [0x3280C29C] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID6, [0x3280C2A0] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID7, [0x3280C2A4] */
#define BIT_MEM_FW_PUB_SEG_5_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID0, [0x3280C2A8] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID1, [0x3280C2AC] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID2, [0x3280C2B0] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID3, [0x3280C2B4] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID4, [0x3280C2B8] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID5, [0x3280C2BC] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID6, [0x3280C2C0] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID7, [0x3280C2C4] */
#define BIT_MEM_FW_PUB_SEG_5_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_FIRST_ADDR, [0x3280C300] */
#define BIT_MEM_FW_PUB_SEG_6_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_LAST_ADDR, [0x3280C304] */
#define BIT_MEM_FW_PUB_SEG_6_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID0, [0x3280C308] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID1, [0x3280C30C] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID2, [0x3280C310] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID3, [0x3280C314] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID4, [0x3280C318] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID5, [0x3280C31C] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID6, [0x3280C320] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID7, [0x3280C324] */
#define BIT_MEM_FW_PUB_SEG_6_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID0, [0x3280C328] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID1, [0x3280C32C] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID2, [0x3280C330] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID3, [0x3280C334] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID4, [0x3280C338] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID5, [0x3280C33C] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID6, [0x3280C340] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID7, [0x3280C344] */
#define BIT_MEM_FW_PUB_SEG_6_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_FIRST_ADDR, [0x3280C380] */
#define BIT_MEM_FW_PUB_SEG_7_FIRST_ADDR_FIRST_ADDR(x)                    ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_LAST_ADDR, [0x3280C384] */
#define BIT_MEM_FW_PUB_SEG_7_LAST_ADDR_LAST_ADDR(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID0, [0x3280C388] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID0_MST_R_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID1, [0x3280C38C] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID1_MST_R_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID2, [0x3280C390] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID2_MST_R_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID3, [0x3280C394] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID3_MST_R_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID4, [0x3280C398] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID4_MST_R_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID5, [0x3280C39C] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID5_MST_R_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID6, [0x3280C3A0] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID6_MST_R_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID7, [0x3280C3A4] */
#define BIT_MEM_FW_PUB_SEG_7_MST_R_ID7_MST_R_ID7(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID0, [0x3280C3A8] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID0_MST_W_ID0(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID1, [0x3280C3AC] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID1_MST_W_ID1(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID2, [0x3280C3B0] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID2_MST_W_ID2(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID3, [0x3280C3B4] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID3_MST_W_ID3(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID4, [0x3280C3B8] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID4_MST_W_ID4(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID5, [0x3280C3BC] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID5_MST_W_ID5(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID6, [0x3280C3C0] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID6_MST_W_ID6(x)                      ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID7, [0x3280C3C4] */
#define BIT_MEM_FW_PUB_SEG_7_MST_W_ID7_MST_W_ID7(x)                      ( (x) )

/* vars definitions for controller CTL_MEM_FW_PUB */


#endif /* __MEM_FW_PUB_H____ */


