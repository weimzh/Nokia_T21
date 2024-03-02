/*
 * Copyright (C) 2018 Spreadtrum Communications Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _UFS_CFG_H_
#define _UFS_CFG_H_
#include <sprd_ufs.h>

void init_global_reg(void);
static int ufshci_enable_bottom();
extern struct ufs_hba_variant_ops hba_vops;

#endif
