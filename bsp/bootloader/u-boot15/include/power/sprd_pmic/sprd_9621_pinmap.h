/*
*  sprd_9620.h  - 9620 pmic pinmap config
*
*  Copyright (C) 2020 Unisoc Communications Inc.
*  History:
*      2020-08-17 linhua.xu@unisoc.com
*      Add 9620 pinmap configuration
*/

#ifndef _SPRD_9621_H_
#define _SPRD_9621_H_


#include "adi.h"
#include <asm/arch/sprd_reg.h>

/* here is the pinmap info of adie such as 9620 */
#define CTL_ANA_PIN_BASE_9621			(ANA_UMP9621_PIN_BASE)

/* registers definitions for controller CTL_PIN */
#define REG_PIN_ANA_ADI_SCLK_9621			( 0x00 )
#define REG_PIN_ANA_ADI_D_9621			( 0x04 )
#define REG_PIN_ANA_CHIP_SLEEP_9621			( 0x08 )
#define REG_PIN_ANA_DCDC_CPU_EN_9621			( 0x0C )
#define REG_PIN_ANA_EXT_XTL_EN_9621			( 0x10 )
#define REG_PIN_ANA_RSTN_1_9621			( 0x14 )
#define REG_PIN_ANA_OTP_O_9621			( 0x18 )

#endif //_SPRD_9621_H_
