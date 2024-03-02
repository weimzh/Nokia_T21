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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/Analog/Analog_G2 Control Register.xls;Analog_G2
 *     Revision : 217905
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __ANLG_PHY_G2_H____
#define __ANLG_PHY_G2_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_G2_BASE
#define CTL_ANLG_PHY_G2_BASE            SCI_IOMAP(0x64570000)
#endif

/* registers definitions for CTL_ANLG_PHY_G2, 0x64570000 */
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_TEST_PIN         SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0000)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_UTMI_CTL1        SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0004)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_BATTER_PLL       SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0008)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_UTMI_CTL2        SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x000C)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_TRIMMING         SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0010)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_PHY_TUNE_CTL     SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0014)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_PHY_BIST_TEST    SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0018)
#define REG_ANLG_PHY_G2_ANALOG_USB20_USB20_ISO_SW           SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x001C)
#define REG_ANLG_PHY_G2_ANALOG_USB20_REG_SEL_CFG_0          SCI_ADDR(CTL_ANLG_PHY_G2_BASE, 0x0020)

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_TEST_PIN, [0x64570000] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TESTCLK          ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TESTDATAIN(x)    ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TESTADDR(x)      ( (x) << 12 & (BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TESTDATAOUTSEL   ( BIT(11) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TESTDATAOUT(x)   ( (x) << 7  & (BIT(7)|BIT(8)|BIT(9)|BIT(10)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BIST_MODE(x)     ( (x) << 2  & (BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_T2RCOMP          ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_LPBK_END         ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_UTMI_CTL1, [0x64570004] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_DATABUS16_8      ( BIT(28) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_SUSPENDM         ( BIT(27) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PORN             ( BIT(26) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_RESET            ( BIT(25) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_RXERROR          ( BIT(24) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_DRV_DP    ( BIT(23) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_DRV_DM    ( BIT(22) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_FS        ( BIT(21) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_IN_DP     ( BIT(20) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_IN_DM     ( BIT(19) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_OUT_DP    ( BIT(18) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BYPASS_OUT_DM    ( BIT(17) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_VBUSVLDEXT       ( BIT(16) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_RESERVED(x)      ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_BATTER_PLL, [0x64570008] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PS_PD_S          ( BIT(4) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PS_PD_L          ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_REXTENABLE       ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_DMPULLUP         ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_SAMPLER_SEL      ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_UTMI_CTL2, [0x6457000C] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_DPPULLDOWN       ( BIT(4) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_DMPULLDOWN       ( BIT(3) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TXBITSTUFFENABLE ( BIT(2) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TXBITSTUFFENABLEH ( BIT(1) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_SLEEPM           ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_TRIMMING, [0x64570010] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNEHSAMP(x)     ( (x) << 25 & (BIT(25)|BIT(26)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TFREGRES(x)      ( (x) << 19 & (BIT(19)|BIT(20)|BIT(21)|BIT(22)|BIT(23)|BIT(24)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TFHSRES(x)       ( (x) << 14 & (BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNERISE(x)      ( (x) << 12 & (BIT(12)|BIT(13)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNEOTG(x)       ( (x) << 9  & (BIT(9)|BIT(10)|BIT(11)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNEDSC(x)       ( (x) << 7  & (BIT(7)|BIT(8)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNESQ(x)        ( (x) << 3  & (BIT(3)|BIT(4)|BIT(5)|BIT(6)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNEEQ(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_PHY_TUNE_CTL, [0x64570014] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_TUNEPLLS(x)      ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PLL_PFD_DEADZONE(x) ( (x) << 8  & (BIT(8)|BIT(9)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PLL_PFD_DELAY(x) ( (x) << 6  & (BIT(6)|BIT(7)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PLL_CP_IOFFSET_EN ( BIT(5) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PLL_CP_IOFFSET(x) ( (x) << 1  & (BIT(1)|BIT(2)|BIT(3)|BIT(4)) )
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_PLL_REF_DOUBLER_EN ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_PHY_BIST_TEST, [0x64570018] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_BIST_MODE_EN     ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_USB20_ISO_SW, [0x6457001C] */
#define BIT_ANLG_PHY_G2_ANALOG_USB20_USB20_ISO_SW_EN        ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G2_ANALOG_USB20_REG_SEL_CFG_0, [0x64570020] */
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_SUSPENDM ( BIT(8) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_PORN     ( BIT(7) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_RESET    ( BIT(6) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_BYPASS_FS ( BIT(5) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_BYPASS_IN_DM ( BIT(4) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_SAMPLER_SEL ( BIT(3) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_DPPULLDOWN ( BIT(2) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_DMPULLDOWN ( BIT(1) )
#define BIT_ANLG_PHY_G2_DBG_SEL_ANALOG_USB20_USB20_SLEEPM   ( BIT(0) )

/* vars definitions for controller CTL_ANLG_PHY_G2 */


#endif /* __ANLG_PHY_G2_H____ */