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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/Analog/Analog_G4 Control Register.xls;Analog_G4
 *     Revision : 217905
 *     Author   : {author}
 *     Date     : {date}
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
#define CTL_ANLG_PHY_G4_BASE            SCI_IOMAP(0x64590000)
#endif

/* registers definitions for CTL_ANLG_PHY_G4, 0x64590000 */
#define REG_ANLG_PHY_G4_ANALOG_EFUSE4K_EFUSE_PIN_PW_CTL     SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0000)
#define REG_ANLG_PHY_G4_ANALOG_EFUSE4K_CSI_PHY_POWER_CONTROL SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0004)
#define REG_ANLG_PHY_G4_ANALOG_EFUSE4K_REG_SEL_CFG_0        SCI_ADDR(CTL_ANLG_PHY_G4_BASE, 0x0008)

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_EFUSE4K_EFUSE_PIN_PW_CTL, [0x64590000] */
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_ENK1             ( BIT(4) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_ENK2             ( BIT(3) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_TRCS             ( BIT(2) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_AT1              ( BIT(1) )
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_EFS_AT0              ( BIT(0) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_EFUSE4K_CSI_PHY_POWER_CONTROL, [0x64590004] */
#define BIT_ANLG_PHY_G4_ANALOG_EFUSE4K_CSI_PHY_POWER_CONTROL(x) ( (x) )

/* bits definitions for REG_ANLG_PHY_G4_ANALOG_EFUSE4K_REG_SEL_CFG_0, [0x64590008] */
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_EFUSE4K_EFS_ENK1     ( BIT(1) )
#define BIT_ANLG_PHY_G4_DBG_SEL_ANALOG_EFUSE4K_EFS_ENK2     ( BIT(0) )

/* vars definitions for controller CTL_ANLG_PHY_G4 */


#endif /* __ANLG_PHY_G4_H____ */
