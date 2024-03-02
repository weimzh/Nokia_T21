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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/RFTI_SYS/SharkL6 RFTI APB Control Register.xls;AP_APB_REG
 *     Revision : 233474
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __RFTI_APB_REG_H____
#define __RFTI_APB_REG_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

/* registers definitions for CTL_RFTI_APB_REG, 0x00000000 */
#define REG_RFTI_APB_REG_CFG_RFSPI_EN                       SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x002C)
#define REG_RFTI_APB_REG_RFTI_SPI_CTRL                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0030)
#define REG_RFTI_APB_REG_LVDSRF_PHY_RX_SET                  SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0034)
#define REG_RFTI_APB_REG_LVDSRF_PHY_TX_SET                  SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0038)
#define REG_RFTI_APB_REG_LVDSRF_CLK_EN                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x003C)
#define REG_RFTI_APB_REG_LVDSRF_RFTI_SOFT_RST               SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0040)
#define REG_RFTI_APB_REG_LVDSRF_FS_BIST                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0050)
#define REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_0                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0054)
#define REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_1                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0058)
#define REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_2                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x005C)
#define REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_3                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0060)
#define REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_4                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0064)
#define REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_5                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0068)
#define REG_RFTI_APB_REG_LVDSRF_PHASE_BIST_EN               SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x006C)
#define REG_RFTI_APB_REG_PHASE_CFG_VALUE                    SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0070)
#define REG_RFTI_APB_REG_PHASE0_BIST_CTRL                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0074)
#define REG_RFTI_APB_REG_PHASE1_BIST_CTRL                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0078)
#define REG_RFTI_APB_REG_BIST_FAIL_CNT0                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x007C)
#define REG_RFTI_APB_REG_BIST_FAIL_CNT1                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0080)
#define REG_RFTI_APB_REG_PRBS_CTRL                          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0084)
#define REG_RFTI_APB_REG_CLKSEL_OVR                         SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0088)
#define REG_RFTI_APB_REG_LVDSRF_TEST_CTRL                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x008C)
#define REG_RFTI_APB_REG_BIST2_CNTR                         SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0090)
#define REG_RFTI_APB_REG_DL_AFIFO_INFO0                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0094)
#define REG_RFTI_APB_REG_DL_AFIFO_INFO1                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0098)
#define REG_RFTI_APB_REG_TEST_BUS                           SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x009C)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FS_BIST               SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00A0)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_0          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00A4)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_1          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00A8)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_2          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00AC)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_3          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00B0)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_4          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00B4)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_5          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00B8)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_RFTI2_PHASE_BIST_EN   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00BC)
#define REG_RFTI_APB_REG_RFTI2_PHASE_CFG_VALUE              SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00C0)
#define REG_RFTI_APB_REG_RFTI2_PHASE0_BIST_CTRL             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00C4)
#define REG_RFTI_APB_REG_RFTI2_PHASE1_BIST_CTRL             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00C8)
#define REG_RFTI_APB_REG_RFTI2_BIST_FAIL0                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00CC)
#define REG_RFTI_APB_REG_RFTI2_BIST_FAIL1                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00D0)
#define REG_RFTI_APB_REG_RFTI2_PRBS_CTRL                    SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00D4)
#define REG_RFTI_APB_REG_RFTI2_CLKSEL_OVR                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00D8)
#define REG_RFTI_APB_REG_RFTI2_LVDSRF_TEST_CTRL             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00DC)
#define REG_RFTI_APB_REG_RFTI2_BIST2_CNTR                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00E0)
#define REG_RFTI_APB_REG_RFTI2_DL_AFIFO_INFO0               SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00E4)
#define REG_RFTI_APB_REG_RFTI2_DL_AFIFO_INFO1               SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00E8)
#define REG_RFTI_APB_REG_RFTI2_TEST_BUS                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00EC)
#define REG_RFTI_APB_REG_PAD_RFTI_SPI_SEL                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00F0)
#define REG_RFTI_APB_REG_RFTI_SYS_MODE_SEL                  SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00F4)
#define REG_RFTI_APB_REG_RFTI_SYS_MODES                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00F8)
#define REG_RFTI_APB_REG_RFSPI_CTRL_RSVD                    SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x00FC)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG0             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0200)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG1             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0204)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG2             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0208)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG0             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x020C)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG1             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0210)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG2             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0214)
#define REG_RFTI_APB_REG_RFTI_GSSI_1BIT_SLICE_RD_CFG1       SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0218)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG0             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0220)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG1             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0224)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG2             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0228)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG0             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x022C)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG1             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0230)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG2             SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0234)
#define REG_RFTI_APB_REG_RFTI_GSSI_4BIT_SLICE_RD_CFG1       SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0238)
#define REG_RFTI_APB_REG_RFTI_SBI_CMD0                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0240)
#define REG_RFTI_APB_REG_RFTI_SBI_CMD1                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0244)
#define REG_RFTI_APB_REG_RFTI_SBI_RDATA                     SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0248)
#define REG_RFTI_APB_REG_RFTI_SPI_SLV_STATUS                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0250)
#define REG_RFTI_APB_REG_RX_PD_CNT                          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0260)
#define REG_RFTI_APB_REG_RX_RST_CNT                         SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0264)
#define REG_RFTI_APB_REG_RX_CLKSEL_CNT                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0268)
#define REG_RFTI_APB_REG_RX_CLKEN_CNT                       SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x026C)
#define REG_RFTI_APB_REG_TX_PD_CNT                          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0270)
#define REG_RFTI_APB_REG_TX_RST_CNT                         SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0274)
#define REG_RFTI_APB_REG_TX_CLKSEL_CNT                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0278)
#define REG_RFTI_APB_REG_TX_CLKEN_CNT                       SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x027C)
#define REG_RFTI_APB_REG_LVDSPLL_PD_RST_CTRL                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0280)
#define REG_RFTI_APB_REG_RPLL_PD_RST_CTRL                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0284)
#define REG_RFTI_APB_REG_RX_SEQ_CTRL                        SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0290)
#define REG_RFTI_APB_REG_RX_SEQ_CTRL_CNT                    SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0294)
#define REG_RFTI_APB_REG_RFTI_HSDL_TIMESTAMP                SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0300)
#define REG_RFTI_APB_REG_RFTI_SYS_HSDL_CFG                  SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0304)
#define REG_RFTI_APB_REG_RFTI_SYS_EXT_DBG_MODE_SEL          SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0308)
#define REG_RFTI_APB_REG_RFTI_FILLER_SEND_CTRL              SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0310)
#define REG_RFTI_APB_REG_RFTI_CRC_CTRL                      SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0314)
#define REG_RFTI_APB_REG_RFTI_UL_TRANS_CTRL                 SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x031C)
#define REG_RFTI_APB_REG_INT_REQ_RFTI_EN                    SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0320)
#define REG_RFTI_APB_REG_INT_REQ_RFTI_CLR                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0324)
#define REG_RFTI_APB_REG_INT_REQ_RFTI_MASK                  SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x0328)
#define REG_RFTI_APB_REG_INT_REQ_RFTI_SRC                   SCI_ADDR(CTL_RFTI_APB_REG_BASE, 0x032C)

/* bits definitions for REG_RFTI_APB_REG_CFG_RFSPI_EN, [0x0000002C] */
#define BIT_RFTI_APB_REG_CFG_RFSPI_EN                       ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SPI_CTRL, [0x00000030] */
#define BIT_RFTI_APB_REG_RFTI_SBI_RST_SOFT                  ( BIT(6) )
#define BIT_RFTI_APB_REG_RFTI_PRI_SPI_RESETB_SOFT           ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI_SPI1_RESETB_SOFT              ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI_SPI0_RESETB_SOFT              ( BIT(3) )
#define BIT_RFTI_APB_REG_RFTI_PRI_SPI_EN                    ( BIT(2) )
#define BIT_RFTI_APB_REG_RFTI_SPI_MODE                      ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI_SPI_ARB_ROTATE_EN             ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_PHY_RX_SET, [0x00000034] */

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_PHY_TX_SET, [0x00000038] */

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_CLK_EN, [0x0000003C] */
#define BIT_RFTI_APB_REG_RFTI_CLK_LTH_EN                    ( BIT(1) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_RFTI_SOFT_RST, [0x00000040] */
#define BIT_RFTI_APB_REG_RST_RFTI_LTH_SOFT                  ( BIT(2) )
#define BIT_RFTI_APB_REG_RFTI2_RESETB_SOFT                  ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI1_RESETB_SOFT                  ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FS_BIST, [0x00000050] */
#define BIT_RFTI_APB_REG_RFTI1_FSBIST_TX_FORCE_EN           ( BIT(7) )
#define BIT_RFTI_APB_REG_RFTI1_LVDSPATTERN_FIX_EN           ( BIT(6) )
#define BIT_RFTI_APB_REG_RFTI1_BIST_FAIL1                   ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI1_BIST_DO1                     ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI1_FSBIST_EN1                   ( BIT(3) )
#define BIT_RFTI_APB_REG_RFTI1_BIST_FAIL0                   ( BIT(2) )
#define BIT_RFTI_APB_REG_RFTI1_BIST_DO0                     ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI1_FSBIST_EN0                   ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_0, [0x00000054] */
#define BIT_RFTI_APB_REG_RFTI1_LVDS_PATTERN_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_1, [0x00000058] */
#define BIT_RFTI_APB_REG_RFTI1_LVDS_PATTERN_1(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_2, [0x0000005C] */
#define BIT_RFTI_APB_REG_RFTI1_LVDS_PATTERN_2(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_3, [0x00000060] */
#define BIT_RFTI_APB_REG_RFTI1_LVDS_PATTERN_3(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_4, [0x00000064] */
#define BIT_RFTI_APB_REG_RFTI1_LVDS_PATTERN_4(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_FIXPATTERN_5, [0x00000068] */
#define BIT_RFTI_APB_REG_RFTI1_LVDS_PATTERN_5(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_PHASE_BIST_EN, [0x0000006C] */

/* bits definitions for REG_RFTI_APB_REG_PHASE_CFG_VALUE, [0x00000070] */

/* bits definitions for REG_RFTI_APB_REG_PHASE0_BIST_CTRL, [0x00000074] */
#define BIT_RFTI_APB_REG_RFTI1_DLHSSBREADY0                 ( BIT(22) )
#define BIT_RFTI_APB_REG_RFTI1_DLHSSBDATPHFOUND0            ( BIT(21) )

/* bits definitions for REG_RFTI_APB_REG_PHASE1_BIST_CTRL, [0x00000078] */
#define BIT_RFTI_APB_REG_RFTI1_DLHSSBREADY1                 ( BIT(22) )
#define BIT_RFTI_APB_REG_RFTI1_DLHSSBDATPHFOUND1            ( BIT(21) )

/* bits definitions for REG_RFTI_APB_REG_BIST_FAIL_CNT0, [0x0000007C] */
#define BIT_RFTI_APB_REG_RFTI1_BIST_FAIL_CNT0(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_BIST_FAIL_CNT1, [0x00000080] */
#define BIT_RFTI_APB_REG_RFTI1_BIST_FAIL_CNT1(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_PRBS_CTRL, [0x00000084] */
#define BIT_RFTI_APB_REG_RFTI1_PRBS_CLIP_EN                 ( BIT(31) )
#define BIT_RFTI_APB_REG_RFTI1_PRBS_LENGTH(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_RFTI_APB_REG_CLKSEL_OVR, [0x00000088] */
#define BIT_RFTI_APB_REG_RFTI1_TX_CLK_FORCE_ON_LV2          ( BIT(7) )
#define BIT_RFTI_APB_REG_RFTI1_RX_CLK_FORCE_ON_LV2          ( BIT(6) )
#define BIT_RFTI_APB_REG_RFTI1_TX_CLK_FORCE_ON_LV1          ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI1_RX_CLK_FORCE_ON_LV1          ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI1_TX_CLKSEL_OVR                ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI1_RX_CLKSEL_OVR                ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_LVDSRF_TEST_CTRL, [0x0000008C] */
#define BIT_RFTI_APB_REG_RFTI1_EXTERNAL_CDR_RX_VALUE(x)     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_FLAGDEST_ERR(x)        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_FLAG_NOT_RDY           ( BIT(11) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_FLAG_RATE_ERR          ( BIT(10) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_ACTIVE                 ( BIT(9) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_LENGTH(x)              ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_EN                     ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI1_STANDALONE_TEST_EN           ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI1_DLRCB_TEST_LANE_SEL          ( BIT(3) )
#define BIT_RFTI_APB_REG_RFTI1_EXTERNAL_CDR_TEST_EN         ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_BIST2_CNTR, [0x00000090] */
#define BIT_RFTI_APB_REG_RFTI1_BIST2_SYM_CNTR(x)            ( (x) << 16 & (0xFFFF0000) )
#define BIT_RFTI_APB_REG_RFTI1_BIST2_ERR_CNTR(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RFTI_APB_REG_DL_AFIFO_INFO0, [0x00000094] */
#define BIT_RFTI_APB_REG_RFTI1_DL_AFIFO_INFO0(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_DL_AFIFO_INFO1, [0x00000098] */
#define BIT_RFTI_APB_REG_RFTI1_DL_AFIFO_INFO1(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_TEST_BUS, [0x0000009C] */
#define BIT_RFTI_APB_REG_RFTI1_TESTBUS16(x)                 ( (x) << 16 & (0xFFFF0000) )
#define BIT_RFTI_APB_REG_RFTI1_TBUS_MODE                    ( BIT(8) )
#define BIT_RFTI_APB_REG_RFTI1_TBUS_ADDR(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FS_BIST, [0x000000A0] */
#define BIT_RFTI_APB_REG_RFTI2_FSBIST_TX_FORCE_EN           ( BIT(7) )
#define BIT_RFTI_APB_REG_RFTI2_LVDSPATTERN_FIX_EN           ( BIT(6) )
#define BIT_RFTI_APB_REG_RFTI2_BIST_FAIL1                   ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI2_BIST_DO1                     ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI2_FSBIST_EN1                   ( BIT(3) )
#define BIT_RFTI_APB_REG_RFTI2_BIST_FAIL0                   ( BIT(2) )
#define BIT_RFTI_APB_REG_RFTI2_BIST_DO0                     ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI2_FSBIST_EN0                   ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_0, [0x000000A4] */
#define BIT_RFTI_APB_REG_RFTI2_LVDS_PATTERN_0(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_1, [0x000000A8] */
#define BIT_RFTI_APB_REG_RFTI2_LVDS_PATTERN_1(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_2, [0x000000AC] */
#define BIT_RFTI_APB_REG_RFTI2_LVDS_PATTERN_2(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_3, [0x000000B0] */
#define BIT_RFTI_APB_REG_RFTI2_LVDS_PATTERN_3(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_4, [0x000000B4] */
#define BIT_RFTI_APB_REG_RFTI2_LVDS_PATTERN_4(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_FIXPATTERN_5, [0x000000B8] */
#define BIT_RFTI_APB_REG_RFTI2_LVDS_PATTERN_5(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_RFTI2_PHASE_BIST_EN, [0x000000BC] */

/* bits definitions for REG_RFTI_APB_REG_RFTI2_PHASE_CFG_VALUE, [0x000000C0] */

/* bits definitions for REG_RFTI_APB_REG_RFTI2_PHASE0_BIST_CTRL, [0x000000C4] */
#define BIT_RFTI_APB_REG_RFTI2_DLHSSBREADY0                 ( BIT(22) )
#define BIT_RFTI_APB_REG_RFTI2_DLHSSBDATPHFOUND0            ( BIT(21) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_PHASE1_BIST_CTRL, [0x000000C8] */
#define BIT_RFTI_APB_REG_RFTI2_DLHSSBREADY1                 ( BIT(22) )
#define BIT_RFTI_APB_REG_RFTI2_DLHSSBDATPHFOUND1            ( BIT(21) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_BIST_FAIL0, [0x000000CC] */
#define BIT_RFTI_APB_REG_RFTI2_BIST_FAIL_CNT0(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_BIST_FAIL1, [0x000000D0] */
#define BIT_RFTI_APB_REG_RFTI2_BIST_FAIL_CNT1(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_PRBS_CTRL, [0x000000D4] */
#define BIT_RFTI_APB_REG_RFTI2_PRBS_CLIP_EN                 ( BIT(31) )
#define BIT_RFTI_APB_REG_RFTI2_PRBS_LENGTH(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_CLKSEL_OVR, [0x000000D8] */
#define BIT_RFTI_APB_REG_RFTI2_TX_CLK_FORCE_ON_LV2          ( BIT(7) )
#define BIT_RFTI_APB_REG_RFTI2_RX_CLK_FORCE_ON_LV2          ( BIT(6) )
#define BIT_RFTI_APB_REG_RFTI2_TX_CLK_FORCE_ON_LV1          ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI2_RX_CLK_FORCE_ON_LV1          ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI2_TX_CLKSEL_OVR                ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI2_RX_CLKSEL_OVR                ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_LVDSRF_TEST_CTRL, [0x000000DC] */
#define BIT_RFTI_APB_REG_RFTI2_EXTERNAL_CDR_RX_VALUE(x)     ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)|BIT(25)|BIT(26)|BIT(27)|BIT(28)|BIT(29)) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_FLAGDEST_ERR(x)        ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_FLAG_NOT_RDY           ( BIT(11) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_FLAG_RATE_ERR          ( BIT(10) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_ACTIVE                 ( BIT(9) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_LENGTH(x)              ( (x) << 6  & (BIT(6)|BIT(7)|BIT(8)) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_EN                     ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI2_STANDALONE_TEST_EN           ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI2_DLRCB_TEST_LANE_SEL          ( BIT(3) )
#define BIT_RFTI_APB_REG_RFTI2_EXTERNAL_CDR_TEST_EN         ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_BIST2_CNTR, [0x000000E0] */
#define BIT_RFTI_APB_REG_RFTI2_BIST2_SYM_CNTR(x)            ( (x) << 16 & (0xFFFF0000) )
#define BIT_RFTI_APB_REG_RFTI2_BIST2_ERR_CNTR(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_DL_AFIFO_INFO0, [0x000000E4] */
#define BIT_RFTI_APB_REG_RFTI2_DL_AFIFO_INFO0(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_DL_AFIFO_INFO1, [0x000000E8] */
#define BIT_RFTI_APB_REG_RFTI2_DL_AFIFO_INFO1(x)            ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI2_TEST_BUS, [0x000000EC] */
#define BIT_RFTI_APB_REG_RFTI2_TESTBUS16(x)                 ( (x) << 16 & (0xFFFF0000) )
#define BIT_RFTI_APB_REG_RFTI2_TBUS_MODE                    ( BIT(8) )
#define BIT_RFTI_APB_REG_RFTI2_TBUS_ADDR(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_PAD_RFTI_SPI_SEL, [0x000000F0] */
#define BIT_RFTI_APB_REG_PAD_RFTI_SPI_SEL(x)                ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SYS_MODE_SEL, [0x000000F4] */
#define BIT_RFTI_APB_REG_RFTI_SYS_DBG_MODE_SEL(x)           ( (x) << 0  & (BIT(0)|BIT(1)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SYS_MODES, [0x000000F8] */
#define BIT_RFTI_APB_REG_RFTI_SYS_DBG_BUS_TVALUE(x)         ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFSPI_CTRL_RSVD, [0x000000FC] */
#define BIT_RFTI_APB_REG_RFSPI_CTL_RESERVED(x)              ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_RFTI_APB_REG_RFSPI_SLICE_EN                     ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG0, [0x00000200] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG0(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG1, [0x00000204] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG1(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG2, [0x00000208] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_WR_CFG2(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG0, [0x0000020C] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG0(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG1, [0x00000210] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG1(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG2, [0x00000214] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_RD_CFG2(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_1BIT_SLICE_RD_CFG1, [0x00000218] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_1BIT_SLICE_RD_CFG1(x)    ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG0, [0x00000220] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG0(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG1, [0x00000224] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG1(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG2, [0x00000228] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_WR_CFG2(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG0, [0x0000022C] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG0(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG1, [0x00000230] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG1(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG2, [0x00000234] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_RD_CFG2(x)          ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_GSSI_4BIT_SLICE_RD_CFG1, [0x00000238] */
#define BIT_RFTI_APB_REG_RFTI_GSSI_4BIT_SLICE_RD_CFG1(x)    ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SBI_CMD0, [0x00000240] */
#define BIT_RFTI_APB_REG_RFTI_SBI_CMD_DATA(x)               ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SBI_CMD1, [0x00000244] */
#define BIT_RFTI_APB_REG_RFTI_SBI_STATE(x)                  ( (x) << 4  & (BIT(4)|BIT(5)|BIT(6)|BIT(7)) )
#define BIT_RFTI_APB_REG_RFTI_SBI_CMD_VLD                   ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SBI_RDATA, [0x00000248] */
#define BIT_RFTI_APB_REG_RFTI_SBI_RDATA(x)                  ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SPI_SLV_STATUS, [0x00000250] */
#define BIT_RFTI_APB_REG_SPI_SLV2_FIFO_EMPTY                ( BIT(5) )
#define BIT_RFTI_APB_REG_SPI_SLV2_FIFO_FULL                 ( BIT(4) )
#define BIT_RFTI_APB_REG_SPI_SLV1_FIFO_EMPTY                ( BIT(3) )
#define BIT_RFTI_APB_REG_SPI_SLV1_FIFO_FULL                 ( BIT(2) )
#define BIT_RFTI_APB_REG_SPI_SLV0_FIFO_EMPTY                ( BIT(1) )
#define BIT_RFTI_APB_REG_SPI_SLV0_FIFO_FULL                 ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RX_PD_CNT, [0x00000260] */
#define BIT_RFTI_APB_REG_RX_PD_CNT(x)                       ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RX_RST_CNT, [0x00000264] */
#define BIT_RFTI_APB_REG_RX_RST_CNT(x)                      ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RX_CLKSEL_CNT, [0x00000268] */
#define BIT_RFTI_APB_REG_RX_CLKSEL_CNT(x)                   ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RX_CLKEN_CNT, [0x0000026C] */
#define BIT_RFTI_APB_REG_RX_CLKEN_CNT(x)                    ( (x) )

/* bits definitions for REG_RFTI_APB_REG_TX_PD_CNT, [0x00000270] */
#define BIT_RFTI_APB_REG_TX_PD_CNT(x)                       ( (x) )

/* bits definitions for REG_RFTI_APB_REG_TX_RST_CNT, [0x00000274] */
#define BIT_RFTI_APB_REG_TX_RST_CNT(x)                      ( (x) )

/* bits definitions for REG_RFTI_APB_REG_TX_CLKSEL_CNT, [0x00000278] */
#define BIT_RFTI_APB_REG_TX_CLKSEL_CNT(x)                   ( (x) )

/* bits definitions for REG_RFTI_APB_REG_TX_CLKEN_CNT, [0x0000027C] */
#define BIT_RFTI_APB_REG_TX_CLKEN_CNT(x)                    ( (x) )

/* bits definitions for REG_RFTI_APB_REG_LVDSPLL_PD_RST_CTRL, [0x00000280] */
#define BIT_RFTI_APB_REG_LVDSPLL_PD_CNT(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_RFTI_APB_REG_LVDSPLL_RST_CNT(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_RPLL_PD_RST_CTRL, [0x00000284] */
#define BIT_RFTI_APB_REG_RPLL_PD_CNT(x)                     ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_RFTI_APB_REG_RPLL_RST_CNT(x)                    ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_RX_SEQ_CTRL, [0x00000290] */
#define BIT_RFTI_APB_REG_SYNC_FOUND_CTRL_EN                 ( BIT(1) )
#define BIT_RFTI_APB_REG_PHASE_FOUND_CTRL_EN                ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RX_SEQ_CTRL_CNT, [0x00000294] */
#define BIT_RFTI_APB_REG_SYNC_FOUND_CTRL_CNT(x)             ( (x) << 16 & (0xFFFF0000) )
#define BIT_RFTI_APB_REG_PHASE_FOUND_CTRL_CNT(x)            ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_HSDL_TIMESTAMP, [0x00000300] */
#define BIT_RFTI_APB_REG_RFTI_HSDL_TIMESTAMP(x)             ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SYS_HSDL_CFG, [0x00000304] */
#define BIT_RFTI_APB_REG_RFTI_SYS_HSDL_CFG(x)               ( (x) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_SYS_EXT_DBG_MODE_SEL, [0x00000308] */
#define BIT_RFTI_APB_REG_RFTI_SYS_EXT_DBG_MODE_SEL(x)       ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_FILLER_SEND_CTRL, [0x00000310] */
#define BIT_RFTI_APB_REG_RFTI_FILLER_SEND_EN                ( BIT(8) )
#define BIT_RFTI_APB_REG_RFTI_FILLER_SEND_NUM(x)            ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_CRC_CTRL, [0x00000314] */
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_CNT3(x)               ( (x) << 20 & (BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_CNT2(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_CNT1(x)               ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_CNT0(x)               ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_FLAG3                 ( BIT(7) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_FLAG2                 ( BIT(6) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_FLAG1                 ( BIT(5) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_FLAG0                 ( BIT(4) )
#define BIT_RFTI_APB_REG_RFTI_CRC_ERR_CLR                   ( BIT(1) )
#define BIT_RFTI_APB_REG_RFTI_CRC_EN                        ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_RFTI_UL_TRANS_CTRL, [0x0000031C] */
#define BIT_RFTI_APB_REG_RFTI_UL_INCESSANT_EN               ( BIT(0) )

/* bits definitions for REG_RFTI_APB_REG_INT_REQ_RFTI_EN, [0x00000320] */
#define BIT_RFTI_APB_REG_INT_REQ_RFTI_EN(x)                 ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_INT_REQ_RFTI_CLR, [0x00000324] */
#define BIT_RFTI_APB_REG_INT_REQ_RFTI_CLR(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_INT_REQ_RFTI_MASK, [0x00000328] */
#define BIT_RFTI_APB_REG_INT_REQ_RFTI_MASK(x)               ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_RFTI_APB_REG_INT_REQ_RFTI_SRC, [0x0000032C] */
#define BIT_RFTI_APB_REG_INT_REQ_RFTI_SRC(x)                ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* vars definitions for controller CTL_RFTI_APB_REG */


#endif /* __RFTI_APB_REG_H____ */
