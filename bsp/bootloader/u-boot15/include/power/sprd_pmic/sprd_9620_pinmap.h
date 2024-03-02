/*
*  sprd_9620.h  - 9620 pmic pinmap config
*
*  Copyright (C) 2020 Unisoc Communications Inc.
*  History:
*      2020-08-17 linhua.xu@unisoc.com
*      Add 9620 pinmap configuration
*/

#ifndef _SPRD_9620_H_
#define _SPRD_9620_H_


#include "adi.h"
#include <asm/arch/sprd_reg.h>

/* here is the pinmap info of adie such as 9620 */
#define CTL_ANA_PIN_BASE			(ANA_PIN_BASE)

/* registers definitions for controller CTL_PIN */
#define REG_PIN_ANA_ADI_SCLK			( 0x00 )
#define REG_PIN_ANA_ADI_D			( 0x04 )
#define REG_PIN_ANA_PTESTO			( 0x08 )
#define REG_PIN_ANA_EXT_RST_B			( 0x0c )
#define REG_PIN_ANA_ANA_INT			( 0x10 )
#define REG_PIN_ANA_CHIP_SLEEP			( 0x14 )
#define REG_PIN_ANA_DCDC_CPU1_EN		( 0x18 )
#define REG_PIN_ANA_DCDC_CPU2_EN		( 0x1C )
#define REG_PIN_ANA_CLK_32K			( 0x20 )
#define REG_PIN_ANA_EXT_XTL_EN0			( 0x24 )
#define REG_PIN_ANA_EXT_XTL_EN1			( 0x28 )
#define REG_PIN_ANA_EXT_XTL_EN2			( 0x2c )
#define REG_PIN_ANA_EXT_XTL_EN3			( 0x30 )
#define REG_PIN_ANA_EXT_XTL_EN4			( 0x34 )
#define REG_PIN_ANA_EXT_XTL_EN5			( 0x38 )
#define REG_PIN_ANA_EXT_XTL_EN6			( 0x3c )
#define REG_PIN_ANA_RSTN_O			( 0x40 )
#define REG_PIN_ANA_OTP_1			( 0x44 )
#define REG_PIN_ANA_USB_FLAG			( 0x48 )
#define REG_PIN_ANA_BATDET_OK			( 0x4C )
#define REG_PIN_ANA_DNS_D0			( 0x50 )
#define REG_PIN_ANA_DNS_D1			( 0x54 )
#define REG_PIN_ANA_AUD_ADD0			( 0x58 )
#define REG_PIN_ANA_AUD_ADD1			( 0x5C )
#define REG_PIN_ANA_AUD_ADSYNC			( 0x60 )
#define REG_PIN_ANA_AUD_DAD0			( 0x64 )
#define REG_PIN_ANA_AUD_DAD1			( 0x68 )
#define REG_PIN_ANA_AUD_DASYNC			( 0x6C )
#define REG_PIN_ANA_AUD_SCLK			( 0x70 )
#define REG_PIN_ANA_EXT_RSTN_A			( 0x74 )
#define REG_PIN_ANA_XTL_EN0_O			( 0x78 )
#define REG_PIN_ANA_XTL_EN1_O			( 0x7C )
#define REG_PIN_ANA_CHIP_SLEEP_O		( 0x80 )

/* bits definitions for register REG_PIN_XXX */
#define BITS_ANA_PIN_DS(_x_)                ( ((_x_) << 8) & (BIT_8|BIT_9) )
#define BIT_ANA_PIN_WPU                     ( BIT_7 )
#define BIT_ANA_PIN_WPD                     ( BIT_6 )
#define BITS_ANA_PIN_AF(_x_)                ( ((_x_) << 4) & (BIT_4|BIT_5) )
#define BIT_ANA_PIN_SLP_WPU                 ( BIT_3 )
#define BIT_ANA_PIN_SLP_WPD                 ( BIT_2 )
#define BIT_ANA_PIN_SLP_IE                  ( BIT_1 )
#define BIT_ANA_PIN_SLP_OE                  ( BIT_0 )

#define BIT_ANA_PIN_SLP_Z			( 0 )
#define	BIT_ANA_PIN_NUL				( 0 )
#define BIT_ANA_PIN_SLP_NUL			( 0 )

#endif //_SPRD_9620_H_
