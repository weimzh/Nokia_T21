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
 * SVN URL      : http://shsvn06/svn/CHIP/Interface/SharkL6/Autoreg/AON_SYS/SharkL6 AON DEBUG APB Control Register.xls;AON_DBG_APB_REG
 *     Revision : 235358
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AON_DBG_APB_H____
#define __AON_DBG_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_DBG_APB_BASE
#define CTL_AON_DBG_APB_BASE            SCI_IOMAP(0x64890000)
#endif

/* registers definitions for CTL_AON_DBG_APB, 0x64890000 */
#define REG_AON_DBG_APB_APCPU_COMM_CTRL                     SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x0000)
#define REG_AON_DBG_APB_APCPU_PROT_CTRL                     SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x0004)
#define REG_AON_DBG_APB_CSSYS_CFG                           SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x0008)
#define REG_AON_DBG_APB_CR5_PROT_CTRL                       SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x000C)
#define REG_AON_DBG_APB_APCPU_PROT_CTRL_NON_SEC             SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x0010)
#define REG_AON_DBG_APB_CSSYS_CFG_NON_SEC                   SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x0014)
#define REG_AON_DBG_APB_CR5_PROT_CTRL_NON_SEC               SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x0018)
#define REG_AON_DBG_APB_DEBUG_BOND_OPTION                   SCI_ADDR(CTL_AON_DBG_APB_BASE, 0x001C)

/* bits definitions for REG_AON_DBG_APB_APCPU_COMM_CTRL, [0x64890000] */
#define BIT_AON_DBG_APB_APCPU_AWSTASHLPIDENS                ( BIT(20) )
#define BIT_AON_DBG_APB_APCPU_AWSTASHLPIDS(x)               ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_DBG_APB_APCPU_CFGTE(x)                      ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_DBG_APB_APCPU_AA64NAA32(x)                  ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_DBG_APB_APCPU_PROT_CTRL, [0x64890004] */
#define BIT_AON_DBG_APB_APCPU_SPNIDEN                       ( BIT(3) )
#define BIT_AON_DBG_APB_APCPU_SPIDEN                        ( BIT(2) )
#define BIT_AON_DBG_APB_APCPU_NIDEN                         ( BIT(1) )
#define BIT_AON_DBG_APB_APCPU_DBGEN                         ( BIT(0) )

/* bits definitions for REG_AON_DBG_APB_CSSYS_CFG, [0x64890008] */
#define BIT_AON_DBG_APB_DAP_DEVICEEN                        ( BIT(31) )
#define BIT_AON_DBG_APB_DAP_DBGEN                           ( BIT(30) )
#define BIT_AON_DBG_APB_DAP_SPIDBGEN                        ( BIT(29) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_DBGEN                   ( BIT(28) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_SINV_DBGEN              ( BIT(27) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_NINV_DBGEN              ( BIT(26) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_NSINV_DBGEN             ( BIT(25) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_DBGEN                   ( BIT(24) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_SINV_DBGEN              ( BIT(23) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_NINV_DBGEN              ( BIT(22) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_NSINV_DBGEN             ( BIT(21) )
#define BIT_AON_DBG_APB_AON_CMSTAR_SINV_DBGEN               ( BIT(15) )
#define BIT_AON_DBG_APB_AON_CMSTAR_NINV_DBGEN               ( BIT(14) )
#define BIT_AON_DBG_APB_AON_CMSTAR_NSINV_DBGEN              ( BIT(13) )
#define BIT_AON_DBG_APB_CDMA2K_DBGEN                        ( BIT(12) )
#define BIT_AON_DBG_APB_VDSP_DBGEN                          ( BIT(11) )
#define BIT_AON_DBG_APB_GPU_DBGEN                           ( BIT(10) )
#define BIT_AON_DBG_APB_TG_JTAG_EN                          ( BIT(9) )
#define BIT_AON_DBG_APB_LTE_JTAG_EN                         ( BIT(8) )
#define BIT_AON_DBG_APB_AON_CM4_DBGEN                       ( BIT(7) )
#define BIT_AON_DBG_APB_DJTAG_EN                            ( BIT(6) )
#define BIT_AON_DBG_APB_AG_JTAG_EN                          ( BIT(5) )
#define BIT_AON_DBG_APB_MJTAG_EN                            ( BIT(4) )
#define BIT_AON_DBG_APB_CSSYS_NIDEN                         ( BIT(3) )
#define BIT_AON_DBG_APB_CSSYS_SPNIDEN                       ( BIT(2) )
#define BIT_AON_DBG_APB_CSSYS_SPIDEN                        ( BIT(1) )
#define BIT_AON_DBG_APB_CSSYS_DBGEN                         ( BIT(0) )

/* bits definitions for REG_AON_DBG_APB_CR5_PROT_CTRL, [0x6489000C] */
#define BIT_AON_DBG_APB_CR5_NIDEN                           ( BIT(1) )
#define BIT_AON_DBG_APB_CR5_DBGEN                           ( BIT(0) )

/* bits definitions for REG_AON_DBG_APB_APCPU_PROT_CTRL_NON_SEC, [0x64890010] */
#define BIT_AON_DBG_APB_APCPU_SPNIDEN_NON_SEC               ( BIT(3) )
#define BIT_AON_DBG_APB_APCPU_SPIDEN_NON_SEC                ( BIT(2) )
#define BIT_AON_DBG_APB_APCPU_NIDEN_NON_SEC                 ( BIT(1) )
#define BIT_AON_DBG_APB_APCPU_DBGEN_NON_SEC                 ( BIT(0) )

/* bits definitions for REG_AON_DBG_APB_CSSYS_CFG_NON_SEC, [0x64890014] */
#define BIT_AON_DBG_APB_DAP_DEVICEEN_NON_SEC                ( BIT(31) )
#define BIT_AON_DBG_APB_DAP_DBGEN_NON_SEC                   ( BIT(30) )
#define BIT_AON_DBG_APB_DAP_SPIDBGEN_NON_SEC                ( BIT(29) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_DBGEN_NON_SEC           ( BIT(28) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_SINV_DBGEN_NON_SEC      ( BIT(27) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_NINV_DBGEN_NON_SEC      ( BIT(26) )
#define BIT_AON_DBG_APB_GNSS_CMSTAR_NSINV_DBGEN_NON_SEC     ( BIT(25) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_DBGEN_NON_SEC           ( BIT(24) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_SINV_DBGEN_NON_SEC      ( BIT(23) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_NINV_DBGEN_NON_SEC      ( BIT(22) )
#define BIT_AON_DBG_APB_BTWF_CMSTAR_NSINV_DBGEN_NON_SEC     ( BIT(21) )
#define BIT_AON_DBG_APB_AON_CMSTAR_SINV_DBGEN_NON_SEC       ( BIT(15) )
#define BIT_AON_DBG_APB_AON_CMSTAR_NINV_DBGEN_NON_SEC       ( BIT(14) )
#define BIT_AON_DBG_APB_AON_CMSTAR_NSINV_DBGEN_NON_SEC      ( BIT(13) )
#define BIT_AON_DBG_APB_CDMA2K_DBGEN_NON_SEC                ( BIT(12) )
#define BIT_AON_DBG_APB_VDSP_DBGEN_NON_SEC                  ( BIT(11) )
#define BIT_AON_DBG_APB_GPU_DBGEN_NON_SEC                   ( BIT(10) )
#define BIT_AON_DBG_APB_TG_JTAG_EN_NON_SEC                  ( BIT(9) )
#define BIT_AON_DBG_APB_LTE_JTAG_EN_NON_SEC                 ( BIT(8) )
#define BIT_AON_DBG_APB_AON_CM4_DBGEN_NON_SEC               ( BIT(7) )
#define BIT_AON_DBG_APB_DJTAG_EN_NON_SEC                    ( BIT(6) )
#define BIT_AON_DBG_APB_AG_JTAG_EN_NON_SEC                  ( BIT(5) )
#define BIT_AON_DBG_APB_MJTAG_EN_NON_SEC                    ( BIT(4) )
#define BIT_AON_DBG_APB_CSSYS_NIDEN_NON_SEC                 ( BIT(3) )
#define BIT_AON_DBG_APB_CSSYS_SPNIDEN_NON_SEC               ( BIT(2) )
#define BIT_AON_DBG_APB_CSSYS_SPIDEN_NON_SEC                ( BIT(1) )
#define BIT_AON_DBG_APB_CSSYS_DBGEN_NON_SEC                 ( BIT(0) )

/* bits definitions for REG_AON_DBG_APB_CR5_PROT_CTRL_NON_SEC, [0x64890018] */
#define BIT_AON_DBG_APB_CR5_NIDEN_NON_SEC                   ( BIT(1) )
#define BIT_AON_DBG_APB_CR5_DBGEN_NON_SEC                   ( BIT(0) )

/* bits definitions for REG_AON_DBG_APB_DEBUG_BOND_OPTION, [0x6489001C] */
#define BIT_AON_DBG_APB_EFUSE_DEBUG_BOND_OFF                ( BIT(31) )
#define BIT_AON_DBG_APB_EFUSE_SECURE_DEBUG                  ( BIT(30) )

/* vars definitions for controller CTL_AON_DBG_APB */


#endif /* __AON_DBG_APB_H____ */
