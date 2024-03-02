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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/Security/mem_fw_pub_memory_fw.xlsx;mem_fw_pub_rf
 *     Revision : 204186
 *     Author   : {author}
 *     Date     : {date}
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
#define CTL_MEM_FW_PUB_BASE             SCI_IOMAP(0x6480B000)
#endif

/* registers definitions for CTL_MEM_FW_PUB, 0x6480B000 */
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
#define REG_MEM_FW_PUB_SEG_8_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1400)
#define REG_MEM_FW_PUB_SEG_8_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1404)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1408)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x140C)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1410)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1414)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1418)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x141C)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1420)
#define REG_MEM_FW_PUB_SEG_8_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1424)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1428)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x142C)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1430)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1434)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1438)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x143C)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1440)
#define REG_MEM_FW_PUB_SEG_8_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1444)
#define REG_MEM_FW_PUB_SEG_9_FIRST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1480)
#define REG_MEM_FW_PUB_SEG_9_LAST_ADDR                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1484)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1488)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x148C)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1490)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1494)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1498)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x149C)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14A0)
#define REG_MEM_FW_PUB_SEG_9_MST_R_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14A4)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID0                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14A8)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID1                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14AC)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID2                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14B0)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID3                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14B4)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID4                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14B8)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID5                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14BC)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID6                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14C0)
#define REG_MEM_FW_PUB_SEG_9_MST_W_ID7                      SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x14C4)
#define REG_MEM_FW_PUB_SEG_10_FIRST_ADDR                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1500)
#define REG_MEM_FW_PUB_SEG_10_LAST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1504)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1508)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x150C)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1510)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1514)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1518)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x151C)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1520)
#define REG_MEM_FW_PUB_SEG_10_MST_R_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1524)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1528)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x152C)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1530)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1534)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1538)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x153C)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1540)
#define REG_MEM_FW_PUB_SEG_10_MST_W_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1544)
#define REG_MEM_FW_PUB_SEG_11_FIRST_ADDR                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1580)
#define REG_MEM_FW_PUB_SEG_11_LAST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1584)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1588)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x158C)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1590)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1594)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1598)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x159C)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15A0)
#define REG_MEM_FW_PUB_SEG_11_MST_R_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15A4)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15A8)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15AC)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15B0)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15B4)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15B8)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15BC)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15C0)
#define REG_MEM_FW_PUB_SEG_11_MST_W_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x15C4)

/* bits definitions for REG_MEM_FW_PUB_PORT0_DEFAULT_R_ADDR_0, [0x6480B000] */
#define BIT_MEM_FW_PUB_PORT0_DEFAULT_R_ADDR_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT0_DEFAULT_W_ADDR_0, [0x6480B004] */
#define BIT_MEM_FW_PUB_PORT0_DEFAULT_W_ADDR_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT1_DEFAULT_R_ADDR_0, [0x6480B008] */
#define BIT_MEM_FW_PUB_PORT1_DEFAULT_R_ADDR_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT1_DEFAULT_W_ADDR_0, [0x6480B00C] */
#define BIT_MEM_FW_PUB_PORT1_DEFAULT_W_ADDR_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_CLK_GATE_BYPASS, [0x6480B100] */
#define BIT_MEM_FW_PUB_CLK_GATE_BYPASS                      ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_EN, [0x6480B200] */
#define BIT_MEM_FW_PUB_PORT_1_W_EN                          ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_EN                          ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_CLR, [0x6480B204] */
#define BIT_MEM_FW_PUB_PORT_1_W_CLR                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_CLR                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_RAW, [0x6480B208] */
#define BIT_MEM_FW_PUB_PORT_1_W_RAW                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_RAW                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_FIN, [0x6480B20C] */
#define BIT_MEM_FW_PUB_PORT_1_W_FIN                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_FIN                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_EN, [0x6480B210] */
#define BIT_MEM_FW_PUB_PORT_1_R_EN                          ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_EN                          ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_CLR, [0x6480B214] */
#define BIT_MEM_FW_PUB_PORT_1_R_CLR                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_CLR                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_RAW, [0x6480B218] */
#define BIT_MEM_FW_PUB_PORT_1_R_RAW                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_RAW                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_FIN, [0x6480B21C] */
#define BIT_MEM_FW_PUB_PORT_1_R_FIN                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_FIN                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_W_DEBUG_ADDR, [0x6480B400] */
#define BIT_MEM_FW_PUB_W_ADDR_0(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_W_DEBUG_ID, [0x6480B404] */
#define BIT_MEM_FW_PUB_W_ID_0(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_R_DEBUG_ADDR, [0x6480B408] */
#define BIT_MEM_FW_PUB_R_ADDR_0(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_R_DEBUG_ID, [0x6480B40C] */
#define BIT_MEM_FW_PUB_R_ID_0(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_W_DEBUG_ADDR, [0x6480B410] */
#define BIT_MEM_FW_PUB_W_ADDR_1(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_W_DEBUG_ID, [0x6480B414] */
#define BIT_MEM_FW_PUB_W_ID_1(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_R_DEBUG_ADDR, [0x6480B418] */
#define BIT_MEM_FW_PUB_R_ADDR_1(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_R_DEBUG_ID, [0x6480B41C] */
#define BIT_MEM_FW_PUB_R_ID_1(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_FIRST_ADDR, [0x6480B800] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_LAST_ADDR, [0x6480B804] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID0, [0x6480B808] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID1, [0x6480B80C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID2, [0x6480B810] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID3, [0x6480B814] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID4, [0x6480B818] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID5, [0x6480B81C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID6, [0x6480B820] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID7, [0x6480B824] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID0, [0x6480B828] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID1, [0x6480B82C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID2, [0x6480B830] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID3, [0x6480B834] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID4, [0x6480B838] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID5, [0x6480B83C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID6, [0x6480B840] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID7, [0x6480B844] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_FIRST_ADDR, [0x6480C000] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_LAST_ADDR, [0x6480C004] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID0, [0x6480C008] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID1, [0x6480C00C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID2, [0x6480C010] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID3, [0x6480C014] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID4, [0x6480C018] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID5, [0x6480C01C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID6, [0x6480C020] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID7, [0x6480C024] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID0, [0x6480C028] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID1, [0x6480C02C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID2, [0x6480C030] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID3, [0x6480C034] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID4, [0x6480C038] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID5, [0x6480C03C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID6, [0x6480C040] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID7, [0x6480C044] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_FIRST_ADDR, [0x6480C080] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_LAST_ADDR, [0x6480C084] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID0, [0x6480C088] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID1, [0x6480C08C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID2, [0x6480C090] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID3, [0x6480C094] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID4, [0x6480C098] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID5, [0x6480C09C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID6, [0x6480C0A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID7, [0x6480C0A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID0, [0x6480C0A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID1, [0x6480C0AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID2, [0x6480C0B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID3, [0x6480C0B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID4, [0x6480C0B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID5, [0x6480C0BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID6, [0x6480C0C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID7, [0x6480C0C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_FIRST_ADDR, [0x6480C100] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_LAST_ADDR, [0x6480C104] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID0, [0x6480C108] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID1, [0x6480C10C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID2, [0x6480C110] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID3, [0x6480C114] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID4, [0x6480C118] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID5, [0x6480C11C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID6, [0x6480C120] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID7, [0x6480C124] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID0, [0x6480C128] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID1, [0x6480C12C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID2, [0x6480C130] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID3, [0x6480C134] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID4, [0x6480C138] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID5, [0x6480C13C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID6, [0x6480C140] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID7, [0x6480C144] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_FIRST_ADDR, [0x6480C180] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_LAST_ADDR, [0x6480C184] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID0, [0x6480C188] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID1, [0x6480C18C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID2, [0x6480C190] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID3, [0x6480C194] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID4, [0x6480C198] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID5, [0x6480C19C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID6, [0x6480C1A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID7, [0x6480C1A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID0, [0x6480C1A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID1, [0x6480C1AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID2, [0x6480C1B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID3, [0x6480C1B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID4, [0x6480C1B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID5, [0x6480C1BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID6, [0x6480C1C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID7, [0x6480C1C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_FIRST_ADDR, [0x6480C200] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_LAST_ADDR, [0x6480C204] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID0, [0x6480C208] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID1, [0x6480C20C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID2, [0x6480C210] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID3, [0x6480C214] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID4, [0x6480C218] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID5, [0x6480C21C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID6, [0x6480C220] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID7, [0x6480C224] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID0, [0x6480C228] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID1, [0x6480C22C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID2, [0x6480C230] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID3, [0x6480C234] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID4, [0x6480C238] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID5, [0x6480C23C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID6, [0x6480C240] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID7, [0x6480C244] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_FIRST_ADDR, [0x6480C280] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_LAST_ADDR, [0x6480C284] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID0, [0x6480C288] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID1, [0x6480C28C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID2, [0x6480C290] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID3, [0x6480C294] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID4, [0x6480C298] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID5, [0x6480C29C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID6, [0x6480C2A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID7, [0x6480C2A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID0, [0x6480C2A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID1, [0x6480C2AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID2, [0x6480C2B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID3, [0x6480C2B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID4, [0x6480C2B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID5, [0x6480C2BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID6, [0x6480C2C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID7, [0x6480C2C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_FIRST_ADDR, [0x6480C300] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_LAST_ADDR, [0x6480C304] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID0, [0x6480C308] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID1, [0x6480C30C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID2, [0x6480C310] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID3, [0x6480C314] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID4, [0x6480C318] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID5, [0x6480C31C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID6, [0x6480C320] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID7, [0x6480C324] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID0, [0x6480C328] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID1, [0x6480C32C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID2, [0x6480C330] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID3, [0x6480C334] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID4, [0x6480C338] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID5, [0x6480C33C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID6, [0x6480C340] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID7, [0x6480C344] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_FIRST_ADDR, [0x6480C380] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_LAST_ADDR, [0x6480C384] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID0, [0x6480C388] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID1, [0x6480C38C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID2, [0x6480C390] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID3, [0x6480C394] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID4, [0x6480C398] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID5, [0x6480C39C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID6, [0x6480C3A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID7, [0x6480C3A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID0, [0x6480C3A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID1, [0x6480C3AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID2, [0x6480C3B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID3, [0x6480C3B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID4, [0x6480C3B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID5, [0x6480C3BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID6, [0x6480C3C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID7, [0x6480C3C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_FIRST_ADDR, [0x6480C400] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_LAST_ADDR, [0x6480C404] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID0, [0x6480C408] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID1, [0x6480C40C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID2, [0x6480C410] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID3, [0x6480C414] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID4, [0x6480C418] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID5, [0x6480C41C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID6, [0x6480C420] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID7, [0x6480C424] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID0, [0x6480C428] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID1, [0x6480C42C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID2, [0x6480C430] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID3, [0x6480C434] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID4, [0x6480C438] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID5, [0x6480C43C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID6, [0x6480C440] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID7, [0x6480C444] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_FIRST_ADDR, [0x6480C480] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_LAST_ADDR, [0x6480C484] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID0, [0x6480C488] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID1, [0x6480C48C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID2, [0x6480C490] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID3, [0x6480C494] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID4, [0x6480C498] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID5, [0x6480C49C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID6, [0x6480C4A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID7, [0x6480C4A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID0, [0x6480C4A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID1, [0x6480C4AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID2, [0x6480C4B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID3, [0x6480C4B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID4, [0x6480C4B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID5, [0x6480C4BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID6, [0x6480C4C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID7, [0x6480C4C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_FIRST_ADDR, [0x6480C500] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_LAST_ADDR, [0x6480C504] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID0, [0x6480C508] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID1, [0x6480C50C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID2, [0x6480C510] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID3, [0x6480C514] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID4, [0x6480C518] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID5, [0x6480C51C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID6, [0x6480C520] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID7, [0x6480C524] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID0, [0x6480C528] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID1, [0x6480C52C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID2, [0x6480C530] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID3, [0x6480C534] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID4, [0x6480C538] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID5, [0x6480C53C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID6, [0x6480C540] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID7, [0x6480C544] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_FIRST_ADDR, [0x6480C580] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_LAST_ADDR, [0x6480C584] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID0, [0x6480C588] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID1, [0x6480C58C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID2, [0x6480C590] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID3, [0x6480C594] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID4, [0x6480C598] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID5, [0x6480C59C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID6, [0x6480C5A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID7, [0x6480C5A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID0, [0x6480C5A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID1, [0x6480C5AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID2, [0x6480C5B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID3, [0x6480C5B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID4, [0x6480C5B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID5, [0x6480C5BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID6, [0x6480C5C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID7, [0x6480C5C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* vars definitions for controller CTL_MEM_FW_PUB */


#endif /* __MEM_FW_PUB_H____ */
