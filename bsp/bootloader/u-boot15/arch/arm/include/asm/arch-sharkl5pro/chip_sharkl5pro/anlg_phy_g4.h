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

#ifndef __ANLG_PHY_G4_H____
#define __ANLG_PHY_G4_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_ANLG_PHY_G4_BASE
#define CTL_ANLG_PHY_G4_BASE            SCI_IOMAP(0x323D0000)
#endif

/* registers definitions for CTL_ANLG_PHY_G4, 0x323D0000 */
#define REG_ANLG_PHY_G4_ANALOG_THM1_1_THM1_CTL              SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0000)
#define REG_ANLG_PHY_G4_ANALOG_THM1_1_THM1_RESERVED_CTL     SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0004)
#define REG_ANLG_PHY_G4_ANALOG_THM1_1_REG_SEL_CFG_0         SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0008)
#define REG_ANLG_PHY_G4_ANALOG_EFUSE4K_EFUSE_PIN_PW_CTL     SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x000C)
#define REG_ANLG_PHY_G4_ANALOG_EFUSE4K_REG_SEL_CFG_0        SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0010)
#define REG_ANLG_PHY_G4_ANALOG_EFUSE4K_CSI_PHY_POWER_CONTROL SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0014)

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_THM1_1_THM1_CTL, [0x323D0000] */
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_RSTN              ( BIT(27) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_RUN               ( BIT(26) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_PD                ( BIT(25) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_VALID             ( BIT(24) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_BG_RBIAS_MODE     ( BIT(23) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_TEST_SEL(x)       ( (x) << 21 & (BIT(21)|BIT(22)) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_BP_MODE           ( BIT(20) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_DATA(x)           ( (x) << 10 & (BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_BP_DATA(x)        ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9)) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_THM1_1_THM1_RESERVED_CTL, [0x323D0004] */
#define BIT_ANLG_PHY_G4_ANALOG_THM1_1_THM_RESERVED(x)       ( (x) << 0  & (0x0000FFFF) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_THM1_1_REG_SEL_CFG_0, [0x323D0008] */
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_THM1_1_THM_RSTN      ( BIT(3) )
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_THM1_1_THM_RUN       ( BIT(2) )
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_THM1_1_THM_PD        ( BIT(1) )
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_THM1_1_THM_RESERVED  ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_EFUSE4K_EFUSE_PIN_PW_CTL, [0x323D000C] */
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_ENK1             ( BIT(4) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_ENK2             ( BIT(3) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_TRCS             ( BIT(2) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_AT1              ( BIT(1) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_AT0              ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_EFUSE4K_REG_SEL_CFG_0, [0x323D0010] */
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_EFUSE4K_EFS_ENK1     ( BIT(1) )
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_EFUSE4K_EFS_ENK2     ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_EFUSE4K_CSI_PHY_POWER_CONTROL, [0x323D0014] */
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_CSI_PHY_POWER_CONTROL(x) ( (x) )

/* vars definitions for controller CTL_ANLG_PHY_G4 */


#endif /* __ANLG_PHY_G4_H____ */
