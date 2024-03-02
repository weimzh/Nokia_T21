/*
*  sprd_9620.h  - 9620 pmic pinmap config
*
*  Copyright (C) 2020 Unisoc Communications Inc.
*  History:
*      2020-08-17 linhua.xu@unisoc.com
*      Add 9620 pinmap configuration
*/

#ifndef _SPRD_9622_H_
#define _SPRD_9622_H_


#include "adi.h"
#include <asm/arch/sprd_reg.h>

/* here is the pinmap info of adie such as 9620 */
#define CTL_ANA_PIN_BASE_9622			(ANA_UMP9622_PIN_BASE)

/* registers definitions for controller CTL_PIN */
#define REG_PIN_ANA_ADI_SCLK_9622			( 0x00 )
#define REG_PIN_ANA_ADI_D_9622			( 0x04 )
#define REG_PIN_ANA_TDIG_9622			( 0x08 )
#define REG_PIN_ANA_TSEN_SEL_9622			( 0x0C )
#define REG_PIN_ANA_CHIP_SLEEP_IN_9622		( 0x10 )
#define REG_PIN_ANA_XTL_EN1_9622			( 0x14 )

#endif //_SPRD_9622_H_
