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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/pub/mem_fw_pub_memory_fw.xlsx;mem_fw_pub_rf
 *     Revision : 231409
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
#define CTL_MEM_FW_PUB_BASE             SCI_IOMAP(0x64815000)
#endif

/* registers definitions for CTL_MEM_FW_PUB, 0x64815000 */
#define REG_MEM_FW_PUB_PORT0_DEFAULT_ADDR_0                 SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0000)
#define REG_MEM_FW_PUB_PORT1_DEFAULT_ADDR_0                 SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x0008)
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
#define REG_MEM_FW_PUB_SEG_12_FIRST_ADDR                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1600)
#define REG_MEM_FW_PUB_SEG_12_LAST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1604)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1608)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x160C)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1610)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1614)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1618)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x161C)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1620)
#define REG_MEM_FW_PUB_SEG_12_MST_R_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1624)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1628)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x162C)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1630)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1634)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1638)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x163C)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1640)
#define REG_MEM_FW_PUB_SEG_12_MST_W_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1644)
#define REG_MEM_FW_PUB_SEG_13_FIRST_ADDR                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1680)
#define REG_MEM_FW_PUB_SEG_13_LAST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1684)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1688)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x168C)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1690)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1694)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1698)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x169C)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16A0)
#define REG_MEM_FW_PUB_SEG_13_MST_R_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16A4)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16A8)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16AC)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16B0)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16B4)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16B8)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16BC)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16C0)
#define REG_MEM_FW_PUB_SEG_13_MST_W_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x16C4)
#define REG_MEM_FW_PUB_SEG_14_FIRST_ADDR                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1700)
#define REG_MEM_FW_PUB_SEG_14_LAST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1704)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1708)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x170C)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1710)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1714)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1718)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x171C)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1720)
#define REG_MEM_FW_PUB_SEG_14_MST_R_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1724)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1728)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x172C)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1730)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1734)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1738)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x173C)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1740)
#define REG_MEM_FW_PUB_SEG_14_MST_W_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1744)
#define REG_MEM_FW_PUB_SEG_15_FIRST_ADDR                    SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1780)
#define REG_MEM_FW_PUB_SEG_15_LAST_ADDR                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1784)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1788)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x178C)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1790)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1794)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x1798)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x179C)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17A0)
#define REG_MEM_FW_PUB_SEG_15_MST_R_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17A4)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID0                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17A8)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID1                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17AC)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID2                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17B0)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID3                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17B4)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID4                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17B8)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID5                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17BC)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID6                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17C0)
#define REG_MEM_FW_PUB_SEG_15_MST_W_ID7                     SCI_ADDR(CTL_MEM_FW_PUB_BASE, 0x17C4)

/* bits definitions for REG_MEM_FW_PUB_PORT0_DEFAULT_ADDR_0, [0x64815000] */
#define BIT_MEM_FW_PUB_PORT0_DEFAULT_R_ADDR_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_MEM_FW_PUB_PORT1_DEFAULT_ADDR_0, [0x64815008] */
#define BIT_MEM_FW_PUB_PORT1_DEFAULT_R_ADDR_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_MEM_FW_PUB_CLK_GATE_BYPASS, [0x64815100] */
#define BIT_MEM_FW_PUB_CLK_GATE_BYPASS                      ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_EN, [0x64815200] */
#define BIT_MEM_FW_PUB_PORT_1_W_EN                          ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_EN                          ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_CLR, [0x64815204] */
#define BIT_MEM_FW_PUB_PORT_1_W_CLR                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_CLR                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_RAW, [0x64815208] */
#define BIT_MEM_FW_PUB_PORT_1_W_RAW                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_RAW                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_W_FIN, [0x6481520C] */
#define BIT_MEM_FW_PUB_PORT_1_W_FIN                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_W_FIN                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_EN, [0x64815210] */
#define BIT_MEM_FW_PUB_PORT_1_R_EN                          ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_EN                          ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_CLR, [0x64815214] */
#define BIT_MEM_FW_PUB_PORT_1_R_CLR                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_CLR                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_RAW, [0x64815218] */
#define BIT_MEM_FW_PUB_PORT_1_R_RAW                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_RAW                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_INT_R_FIN, [0x6481521C] */
#define BIT_MEM_FW_PUB_PORT_1_R_FIN                         ( BIT(1) )
#define BIT_MEM_FW_PUB_PORT_0_R_FIN                         ( BIT(0) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_W_DEBUG_ADDR, [0x64815400] */
#define BIT_MEM_FW_PUB_W_ADDR_0(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_W_DEBUG_ID, [0x64815404] */
#define BIT_MEM_FW_PUB_W_ID_0(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_R_DEBUG_ADDR, [0x64815408] */
#define BIT_MEM_FW_PUB_R_ADDR_0(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_0_R_DEBUG_ID, [0x6481540C] */
#define BIT_MEM_FW_PUB_R_ID_0(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_W_DEBUG_ADDR, [0x64815410] */
#define BIT_MEM_FW_PUB_W_ADDR_1(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_W_DEBUG_ID, [0x64815414] */
#define BIT_MEM_FW_PUB_W_ID_1(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_R_DEBUG_ADDR, [0x64815418] */
#define BIT_MEM_FW_PUB_R_ADDR_1(x)                          ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)) )

/* bits definitions for REG_MEM_FW_PUB_PORT_1_R_DEBUG_ID, [0x6481541C] */
#define BIT_MEM_FW_PUB_R_ID_1(x)                            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_FIRST_ADDR, [0x64815800] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_LAST_ADDR, [0x64815804] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID0, [0x64815808] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID1, [0x6481580C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID2, [0x64815810] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID3, [0x64815814] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID4, [0x64815818] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID5, [0x6481581C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID6, [0x64815820] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_R_ID7, [0x64815824] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID0, [0x64815828] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID1, [0x6481582C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID2, [0x64815830] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID3, [0x64815834] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID4, [0x64815838] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID5, [0x6481583C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID6, [0x64815840] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_DEFAULT_MST_W_ID7, [0x64815844] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_FIRST_ADDR, [0x64816000] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_LAST_ADDR, [0x64816004] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID0, [0x64816008] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID1, [0x6481600C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID2, [0x64816010] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID3, [0x64816014] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID4, [0x64816018] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID5, [0x6481601C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID6, [0x64816020] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_R_ID7, [0x64816024] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID0, [0x64816028] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID1, [0x6481602C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID2, [0x64816030] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID3, [0x64816034] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID4, [0x64816038] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID5, [0x6481603C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID6, [0x64816040] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_0_MST_W_ID7, [0x64816044] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_FIRST_ADDR, [0x64816080] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_LAST_ADDR, [0x64816084] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID0, [0x64816088] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID1, [0x6481608C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID2, [0x64816090] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID3, [0x64816094] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID4, [0x64816098] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID5, [0x6481609C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID6, [0x648160A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_R_ID7, [0x648160A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID0, [0x648160A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID1, [0x648160AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID2, [0x648160B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID3, [0x648160B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID4, [0x648160B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID5, [0x648160BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID6, [0x648160C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_1_MST_W_ID7, [0x648160C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_FIRST_ADDR, [0x64816100] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_LAST_ADDR, [0x64816104] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID0, [0x64816108] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID1, [0x6481610C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID2, [0x64816110] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID3, [0x64816114] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID4, [0x64816118] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID5, [0x6481611C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID6, [0x64816120] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_R_ID7, [0x64816124] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID0, [0x64816128] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID1, [0x6481612C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID2, [0x64816130] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID3, [0x64816134] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID4, [0x64816138] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID5, [0x6481613C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID6, [0x64816140] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_2_MST_W_ID7, [0x64816144] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_FIRST_ADDR, [0x64816180] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_LAST_ADDR, [0x64816184] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID0, [0x64816188] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID1, [0x6481618C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID2, [0x64816190] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID3, [0x64816194] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID4, [0x64816198] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID5, [0x6481619C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID6, [0x648161A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_R_ID7, [0x648161A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID0, [0x648161A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID1, [0x648161AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID2, [0x648161B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID3, [0x648161B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID4, [0x648161B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID5, [0x648161BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID6, [0x648161C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_3_MST_W_ID7, [0x648161C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_FIRST_ADDR, [0x64816200] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_LAST_ADDR, [0x64816204] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID0, [0x64816208] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID1, [0x6481620C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID2, [0x64816210] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID3, [0x64816214] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID4, [0x64816218] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID5, [0x6481621C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID6, [0x64816220] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_R_ID7, [0x64816224] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID0, [0x64816228] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID1, [0x6481622C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID2, [0x64816230] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID3, [0x64816234] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID4, [0x64816238] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID5, [0x6481623C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID6, [0x64816240] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_4_MST_W_ID7, [0x64816244] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_FIRST_ADDR, [0x64816280] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_LAST_ADDR, [0x64816284] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID0, [0x64816288] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID1, [0x6481628C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID2, [0x64816290] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID3, [0x64816294] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID4, [0x64816298] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID5, [0x6481629C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID6, [0x648162A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_R_ID7, [0x648162A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID0, [0x648162A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID1, [0x648162AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID2, [0x648162B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID3, [0x648162B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID4, [0x648162B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID5, [0x648162BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID6, [0x648162C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_5_MST_W_ID7, [0x648162C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_FIRST_ADDR, [0x64816300] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_LAST_ADDR, [0x64816304] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID0, [0x64816308] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID1, [0x6481630C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID2, [0x64816310] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID3, [0x64816314] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID4, [0x64816318] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID5, [0x6481631C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID6, [0x64816320] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_R_ID7, [0x64816324] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID0, [0x64816328] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID1, [0x6481632C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID2, [0x64816330] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID3, [0x64816334] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID4, [0x64816338] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID5, [0x6481633C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID6, [0x64816340] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_6_MST_W_ID7, [0x64816344] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_FIRST_ADDR, [0x64816380] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_LAST_ADDR, [0x64816384] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID0, [0x64816388] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID1, [0x6481638C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID2, [0x64816390] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID3, [0x64816394] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID4, [0x64816398] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID5, [0x6481639C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID6, [0x648163A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_R_ID7, [0x648163A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID0, [0x648163A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID1, [0x648163AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID2, [0x648163B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID3, [0x648163B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID4, [0x648163B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID5, [0x648163BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID6, [0x648163C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_7_MST_W_ID7, [0x648163C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_FIRST_ADDR, [0x64816400] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_LAST_ADDR, [0x64816404] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID0, [0x64816408] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID1, [0x6481640C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID2, [0x64816410] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID3, [0x64816414] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID4, [0x64816418] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID5, [0x6481641C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID6, [0x64816420] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_R_ID7, [0x64816424] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID0, [0x64816428] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID1, [0x6481642C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID2, [0x64816430] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID3, [0x64816434] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID4, [0x64816438] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID5, [0x6481643C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID6, [0x64816440] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_8_MST_W_ID7, [0x64816444] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_FIRST_ADDR, [0x64816480] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_LAST_ADDR, [0x64816484] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID0, [0x64816488] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID1, [0x6481648C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID2, [0x64816490] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID3, [0x64816494] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID4, [0x64816498] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID5, [0x6481649C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID6, [0x648164A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_R_ID7, [0x648164A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID0, [0x648164A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID1, [0x648164AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID2, [0x648164B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID3, [0x648164B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID4, [0x648164B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID5, [0x648164BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID6, [0x648164C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_9_MST_W_ID7, [0x648164C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_FIRST_ADDR, [0x64816500] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_LAST_ADDR, [0x64816504] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID0, [0x64816508] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID1, [0x6481650C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID2, [0x64816510] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID3, [0x64816514] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID4, [0x64816518] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID5, [0x6481651C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID6, [0x64816520] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_R_ID7, [0x64816524] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID0, [0x64816528] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID1, [0x6481652C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID2, [0x64816530] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID3, [0x64816534] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID4, [0x64816538] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID5, [0x6481653C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID6, [0x64816540] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_10_MST_W_ID7, [0x64816544] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_FIRST_ADDR, [0x64816580] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_LAST_ADDR, [0x64816584] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID0, [0x64816588] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID1, [0x6481658C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID2, [0x64816590] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID3, [0x64816594] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID4, [0x64816598] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID5, [0x6481659C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID6, [0x648165A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_R_ID7, [0x648165A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID0, [0x648165A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID1, [0x648165AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID2, [0x648165B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID3, [0x648165B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID4, [0x648165B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID5, [0x648165BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID6, [0x648165C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_11_MST_W_ID7, [0x648165C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_FIRST_ADDR, [0x64816600] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_LAST_ADDR, [0x64816604] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID0, [0x64816608] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID1, [0x6481660C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID2, [0x64816610] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID3, [0x64816614] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID4, [0x64816618] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID5, [0x6481661C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID6, [0x64816620] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_R_ID7, [0x64816624] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID0, [0x64816628] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID1, [0x6481662C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID2, [0x64816630] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID3, [0x64816634] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID4, [0x64816638] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID5, [0x6481663C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID6, [0x64816640] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_12_MST_W_ID7, [0x64816644] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_FIRST_ADDR, [0x64816680] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_LAST_ADDR, [0x64816684] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID0, [0x64816688] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID1, [0x6481668C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID2, [0x64816690] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID3, [0x64816694] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID4, [0x64816698] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID5, [0x6481669C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID6, [0x648166A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_R_ID7, [0x648166A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID0, [0x648166A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID1, [0x648166AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID2, [0x648166B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID3, [0x648166B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID4, [0x648166B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID5, [0x648166BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID6, [0x648166C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_13_MST_W_ID7, [0x648166C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_FIRST_ADDR, [0x64816700] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_LAST_ADDR, [0x64816704] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID0, [0x64816708] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID1, [0x6481670C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID2, [0x64816710] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID3, [0x64816714] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID4, [0x64816718] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID5, [0x6481671C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID6, [0x64816720] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_R_ID7, [0x64816724] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID0, [0x64816728] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID1, [0x6481672C] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID2, [0x64816730] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID3, [0x64816734] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID4, [0x64816738] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID5, [0x6481673C] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID6, [0x64816740] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_14_MST_W_ID7, [0x64816744] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_FIRST_ADDR, [0x64816780] */
#define BIT_MEM_FW_PUB_FIRST_ADDR(x)                        ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_LAST_ADDR, [0x64816784] */
#define BIT_MEM_FW_PUB_LAST_ADDR(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID0, [0x64816788] */
#define BIT_MEM_FW_PUB_MST_R_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID1, [0x6481678C] */
#define BIT_MEM_FW_PUB_MST_R_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID2, [0x64816790] */
#define BIT_MEM_FW_PUB_MST_R_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID3, [0x64816794] */
#define BIT_MEM_FW_PUB_MST_R_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID4, [0x64816798] */
#define BIT_MEM_FW_PUB_MST_R_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID5, [0x6481679C] */
#define BIT_MEM_FW_PUB_MST_R_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID6, [0x648167A0] */
#define BIT_MEM_FW_PUB_MST_R_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_R_ID7, [0x648167A4] */
#define BIT_MEM_FW_PUB_MST_R_ID7(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID0, [0x648167A8] */
#define BIT_MEM_FW_PUB_MST_W_ID0(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID1, [0x648167AC] */
#define BIT_MEM_FW_PUB_MST_W_ID1(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID2, [0x648167B0] */
#define BIT_MEM_FW_PUB_MST_W_ID2(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID3, [0x648167B4] */
#define BIT_MEM_FW_PUB_MST_W_ID3(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID4, [0x648167B8] */
#define BIT_MEM_FW_PUB_MST_W_ID4(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID5, [0x648167BC] */
#define BIT_MEM_FW_PUB_MST_W_ID5(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID6, [0x648167C0] */
#define BIT_MEM_FW_PUB_MST_W_ID6(x)                         ( (x) )

/* bits definitions for REG_MEM_FW_PUB_SEG_15_MST_W_ID7, [0x648167C4] */
#define BIT_MEM_FW_PUB_MST_W_ID7(x)                         ( (x) )

/* vars definitions for controller CTL_MEM_FW_PUB */


#endif /* __MEM_FW_PUB_H____ */
