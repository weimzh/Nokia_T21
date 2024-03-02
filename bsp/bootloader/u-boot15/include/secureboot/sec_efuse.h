#ifndef _SEC_EFUSE_H_
#define _SEC_EFUSE_H_

#ifdef CONFIG_SC9833
#include "sec_efuse_sharkl2.h"
#endif
#ifdef CONFIG_SOC_SHARKLJ1
#include "sec_efuse_sharklj1.h"
#endif
#ifdef CONFIG_SOC_PIKE2
#include "sec_efuse_pike2.h"
#endif
#ifdef CONFIG_SOC_SHARKLE
#include "sec_efuse_sharkle.h"
#endif
#ifdef CONFIG_SOC_SHARKL3
#include "sec_efuse_sharkl3.h"
#endif
#ifdef CONFIG_SOC_SHARKL5
#include "sec_efuse_sharkl5.h"
#endif
#ifdef CONFIG_SOC_QOGIRL6
#include "sec_efuse_sharkl6.h"
#endif
#ifdef CONFIG_SOC_ROC1
#include "sec_efuse_roc1.h"
#endif
#ifdef CONFIG_SOC_ORCA
#include "sec_efuse_orca.h"
#endif
#ifdef CONFIG_SOC_SHARKL5PRO
#include "sec_efuse_sharkl5pro.h"
#endif
#ifdef CONFIG_SOC_QOGIRN6PRO
#include "sec_efuse_sharkl6pro.h"
#endif
#endif
