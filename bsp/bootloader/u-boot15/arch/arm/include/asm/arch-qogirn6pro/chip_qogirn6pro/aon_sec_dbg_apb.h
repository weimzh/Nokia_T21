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
 * SVN URL      : http://shsvn03/svn/CHIP/Interface/SharkL6Pro/Autoreg/RTL0.9/SharkL6Pro_doc_DE_top_0541_cq_goodcode_202004300959/reg/aon/aon_sec_dbg_apb_rf.xls;AON_DBG_APB_REG
 *     Revision : 231409
 *     Author   : {author}
 *     Date     : {date}
 */

#ifndef __AON_SEC_DBG_APB_H____
#define __AON_SEC_DBG_APB_H____

/* Some defs, in case these are not defined elsewhere */
#ifndef SCI_IOMAP
#define SCI_IOMAP(_b_) ( (_b_) )
#endif

#ifndef SCI_ADDR
#define SCI_ADDR(_b_, _o_) ( (_b_) + (_o_) )
#endif

#ifndef CTL_AON_SEC_DBG_APB_BASE
#define CTL_AON_SEC_DBG_APB_BASE        SCI_IOMAP(0x64890000)
#endif

/* registers definitions for CTL_AON_SEC_DBG_APB, 0x64890000 */
#define REG_AON_SEC_DBG_APB_APCPU_COMM_CTRL                 SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0000)
#define REG_AON_SEC_DBG_APB_APCPU_PROT_CTRL                 SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0004)
#define REG_AON_SEC_DBG_APB_CSSYS_CFG                       SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0008)
#define REG_AON_SEC_DBG_APB_APCPU_PROT_CTRL_NON_SEC         SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0010)
#define REG_AON_SEC_DBG_APB_CSSYS_CFG_NON_SEC               SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0014)
#define REG_AON_SEC_DBG_APB_PSCP_CR8_PROT_CTRL              SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0020)
#define REG_AON_SEC_DBG_APB_PSCP_CR8_PROT_CTRL_NON_SEC      SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0024)
#define REG_AON_SEC_DBG_APB_PHYCP_CR8_PROT_CTRL             SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0028)
#define REG_AON_SEC_DBG_APB_PHYCP_CR8_PROT_CTRL_NON_SEC     SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x002C)
#define REG_AON_SEC_DBG_APB_POS_ONE_WRITE_FLAG              SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0030)
#define REG_AON_SEC_DBG_APB_POS_ONE_WRITE_FLAG_NON_SEC      SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0034)
#define REG_AON_SEC_DBG_APB_DEBUG_BOND_OPTION               SCI_ADDR(CTL_AON_SEC_DBG_APB_BASE, 0x0040)

/* bits definitions for REG_AON_SEC_DBG_APB_APCPU_COMM_CTRL, [0x64890000] */
#define BIT_AON_SEC_DBG_APB_APCPU_AWSTASHLPIDENS            ( BIT(20) )
#define BIT_AON_SEC_DBG_APB_APCPU_AWSTASHLPIDS(x)           ( (x) << 16 & (BIT(16)|BIT(17)|BIT(18)|BIT(19)) )
#define BIT_AON_SEC_DBG_APB_APCPU_CFGTE(x)                  ( (x) << 8  & (BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15)) )
#define BIT_AON_SEC_DBG_APB_APCPU_AA64NAA32(x)              ( (x) << 0  & (BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)) )

/* bits definitions for REG_AON_SEC_DBG_APB_APCPU_PROT_CTRL, [0x64890004] */
#define BIT_AON_SEC_DBG_APB_APCPU_SPNIDEN                   ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_APCPU_SPIDEN                    ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_APCPU_NIDEN                     ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_APCPU_DBGEN                     ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_CSSYS_CFG, [0x64890008] */
#define BIT_AON_SEC_DBG_APB_DAP_DEVICEEN                    ( BIT(31) )
#define BIT_AON_SEC_DBG_APB_DAP_DBGEN                       ( BIT(30) )
#define BIT_AON_SEC_DBG_APB_DAP_SPIDBGEN                    ( BIT(29) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_DAP_EN            ( BIT(27) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_NIDEN             ( BIT(26) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_SPNIDEN           ( BIT(25) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_SPIDEN            ( BIT(24) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_DAP_EN           ( BIT(23) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_NIDEN            ( BIT(22) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_SPNIDEN          ( BIT(21) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_SPIDEN           ( BIT(20) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_DAP_EN               ( BIT(19) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_NIDEN                ( BIT(18) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_SPNIDEN              ( BIT(17) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_SPIDEN               ( BIT(16) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_DBGEN                ( BIT(15) )
#define BIT_AON_SEC_DBG_APB_UFSPHY_DBGEN                    ( BIT(14) )
#define BIT_AON_SEC_DBG_APB_USBPHY_DBGEN                    ( BIT(13) )
#define BIT_AON_SEC_DBG_APB_GPU_DBGEN                       ( BIT(12) )
#define BIT_AON_SEC_DBG_APB_VDSP_DBGEN                      ( BIT(11) )
#define BIT_AON_SEC_DBG_APB_PCIEPHY_DBGEN                   ( BIT(10) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_DBGEN            ( BIT(9) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_DBGEN             ( BIT(8) )
#define BIT_AON_SEC_DBG_APB_C2K_DBGEN                       ( BIT(7) )
#define BIT_AON_SEC_DBG_APB_JTAG_PAD_EN                     ( BIT(6) )
#define BIT_AON_SEC_DBG_APB_AG_DBGEN                        ( BIT(5) )
#define BIT_AON_SEC_DBG_APB_MJTAG_EN                        ( BIT(4) )
#define BIT_AON_SEC_DBG_APB_CSSYS_NIDEN                     ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_CSSYS_SPNIDEN                   ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_CSSYS_SPIDEN                    ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_CSSYS_DBGEN                     ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_APCPU_PROT_CTRL_NON_SEC, [0x64890010] */
#define BIT_AON_SEC_DBG_APB_APCPU_SPNIDEN_NON_SEC           ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_APCPU_SPIDEN_NON_SEC            ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_APCPU_NIDEN_NON_SEC             ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_APCPU_DBGEN_NON_SEC             ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_CSSYS_CFG_NON_SEC, [0x64890014] */
#define BIT_AON_SEC_DBG_APB_DAP_DEVICEEN_NON_SEC            ( BIT(31) )
#define BIT_AON_SEC_DBG_APB_DAP_DBGEN_NON_SEC               ( BIT(30) )
#define BIT_AON_SEC_DBG_APB_DAP_SPIDBGEN_NON_SEC            ( BIT(29) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_DAP_EN_NON_SEC    ( BIT(27) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_NIDEN_NON_SEC     ( BIT(26) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_SPNIDEN_NON_SEC   ( BIT(25) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_SPIDEN_NON_SEC    ( BIT(24) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_DAP_EN_NON_SEC   ( BIT(23) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_NIDEN_NON_SEC    ( BIT(22) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_SPNIDEN_NON_SEC  ( BIT(21) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_SPIDEN_NON_SEC   ( BIT(20) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_DAP_EN_NON_SEC       ( BIT(19) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_NIDEN_NON_SEC        ( BIT(18) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_SPNIDEN_NON_SEC      ( BIT(17) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_SPIDEN_NON_SEC       ( BIT(16) )
#define BIT_AON_SEC_DBG_APB_ISE_CMSTAR_DBGEN_NON_SEC        ( BIT(15) )
#define BIT_AON_SEC_DBG_APB_UFSPHY_DBGEN_NON_SEC            ( BIT(14) )
#define BIT_AON_SEC_DBG_APB_USBPHY_DBGEN_NON_SEC            ( BIT(13) )
#define BIT_AON_SEC_DBG_APB_GPU_DBGEN_NON_SEC               ( BIT(12) )
#define BIT_AON_SEC_DBG_APB_VDSP_DBGEN_NON_SEC              ( BIT(11) )
#define BIT_AON_SEC_DBG_APB_PCIEPHY_DBGEN_NON_SEC           ( BIT(10) )
#define BIT_AON_SEC_DBG_APB_AON_HUB_CMSTAR_DBGEN_NON_SEC    ( BIT(9) )
#define BIT_AON_SEC_DBG_APB_AON_SP_CMSTAR_DBGEN_NON_SEC     ( BIT(8) )
#define BIT_AON_SEC_DBG_APB_C2K_DBGEN_NON_SEC               ( BIT(7) )
#define BIT_AON_SEC_DBG_APB_JTAG_PAD_EN_NON_SEC             ( BIT(6) )
#define BIT_AON_SEC_DBG_APB_AG_DBGEN_NON_SEC                ( BIT(5) )
#define BIT_AON_SEC_DBG_APB_MJTAG_EN_NON_SEC                ( BIT(4) )
#define BIT_AON_SEC_DBG_APB_CSSYS_NIDEN_NON_SEC             ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_CSSYS_SPNIDEN_NON_SEC           ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_CSSYS_SPIDEN_NON_SEC            ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_CSSYS_DBGEN_NON_SEC             ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_PSCP_CR8_PROT_CTRL, [0x64890020] */
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_1_NIDEN                ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_1_DBGEN                ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_0_NIDEN                ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_0_DBGEN                ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_PSCP_CR8_PROT_CTRL_NON_SEC, [0x64890024] */
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_1_NIDEN_NON_SEC        ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_1_DBGEN_NON_SEC        ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_0_NIDEN_NON_SEC        ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_PSCP_CR8_0_DBGEN_NON_SEC        ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_PHYCP_CR8_PROT_CTRL, [0x64890028] */
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_1_NIDEN               ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_1_DBGEN               ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_0_NIDEN               ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_0_DBGEN               ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_PHYCP_CR8_PROT_CTRL_NON_SEC, [0x6489002C] */
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_1_NIDEN_NON_SEC       ( BIT(3) )
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_1_DBGEN_NON_SEC       ( BIT(2) )
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_0_NIDEN_NON_SEC       ( BIT(1) )
#define BIT_AON_SEC_DBG_APB_PHYCP_CR8_0_DBGEN_NON_SEC       ( BIT(0) )

/* bits definitions for REG_AON_SEC_DBG_APB_POS_ONE_WRITE_FLAG, [0x64890030] */
#define BIT_AON_SEC_DBG_APB_POS_ONE_WRITE_FLAG(x)           ( (x) )

/* bits definitions for REG_AON_SEC_DBG_APB_POS_ONE_WRITE_FLAG_NON_SEC, [0x64890034] */
#define BIT_AON_SEC_DBG_APB_POS_ONE_WRITE_FLAG_NON_SEC(x)   ( (x) )

/* bits definitions for REG_AON_SEC_DBG_APB_DEBUG_BOND_OPTION, [0x64890040] */
#define BIT_AON_SEC_DBG_APB_EFUSE_DEBUG_BOND_OFF            ( BIT(31) )
#define BIT_AON_SEC_DBG_APB_EFUSE_SECURE_DEBUG              ( BIT(30) )

/* vars definitions for controller CTL_AON_SEC_DBG_APB */


#endif /* __AON_SEC_DBG_APB_H____ */
