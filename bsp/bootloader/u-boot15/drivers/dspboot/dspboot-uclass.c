/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#undef DEBUG

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <dm/lists.h>
#include <dm/util.h>
#include "dspboot.h"
#include "fdtdec.h"
#include <regmap.h>
#include <syscon.h>

int dspboot_read_list(struct udevice *dev, char *name[], int max_count, struct dspboot_desc *desc_out)
{
	int ret, index, i;
	struct ofnode_phandle_args args;
	struct udevice *syscon_dev;
	struct regmap *map;

	debug("%s entry\n", __func__);

	for (i = 0; i < max_count; i++) {
		debug("[%d]: string=%s\n", i, name[i]);

		index = dev_read_stringlist_search(dev, "syscon-names", name[i]);
		debug("index=%d\n", index);

		if (FDT_ADDR_T_NONE != index) {
			ret = dev_read_phandle_with_args(dev, "syscons", NULL, 2, index, &args);
			if (ret) {
				errorf("of_parse_phandle_with_args fail, ret=0x%x", ret);
				break;
			}

			if (uclass_get_device_by_ofnode(UCLASS_SYSCON, args.node, &syscon_dev)) {
				break;
			}

			map = syscon_get_regmap(syscon_dev);

			desc_out[i].reg_addr = map->ranges[0].start;
			desc_out[i].offset = args.args[0];
			desc_out[i].mask = args.args[1];
		} else
			debug("[%s] not find\n", name[i]);
	}

	return 0;
}

int dspboot_bind_driver(int busnum,
		       const char *drv_name, const char *dev_name,
		       struct udevice **busp)
{
	struct udevice *bus, *dev;
	int ret;

	debug("%s entry\n", __func__);

	ret = uclass_first_device_err(UCLASS_DSPBOOT, &bus);
	if (ret) {
		errorf("Invalid bus %d (err=%d)\n", busnum, ret);
		return ret;
	}

	*busp = bus;

	return 0;
}


UCLASS_DRIVER(dspboot) = {
	.id		= UCLASS_DSPBOOT,
	.name		= "dspboot",
	.flags		= DM_UC_FLAG_SEQ_ALIAS,

#if !CONFIG_IS_ENABLED(OF_PLATDATA)
	.post_bind	= dm_scan_fdt_dev,
#endif
};

UCLASS_DRIVER(dspboot_generic) = {
	.id		= UCLASS_DSPBOOT_GENERIC,
	.name		= "dspboot_generic",
};

U_BOOT_DRIVER(dspboot_generic_drv) = {
	.name		= "dspboot_generic_drv",
	.id		= UCLASS_DSPBOOT_GENERIC,
};
