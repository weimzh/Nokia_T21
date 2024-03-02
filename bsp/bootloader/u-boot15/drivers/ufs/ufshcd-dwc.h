/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * UFS Host driver for Synopsys Designware Core
 *
 * Copyright (C) 2015-2016 Synopsys, Inc. (www.synopsys.com)
 *
 * Authors: Joao Pinto <jpinto@synopsys.com>
 */

#ifndef _UFSHCD_DWC_H
#define _UFSHCD_DWC_H
#include <common.h>

struct ufshcd_dme_attr_val {
	uint32_t attr_sel;
	uint32_t mib_val;
	uint8_t peer;
};
#if 0
int ufshcd_dwc_link_startup_notify(struct ufs_hba *hba,
					enum ufs_notify_change_status status);
#endif
int ufshcd_dwc_dme_set_attrs(const struct ufshcd_dme_attr_val *v, int n);
#endif /* End of Header */
