/*
 * (C) Copyright 2021 UNISOC
 * linhua.xu <linhua.xu@unisoc.com>
 *
 */

#include <common.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/io.h>
#include <stdio_dev.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <asm/global_data.h>
#include <libfdt.h>
#include <fdt_support.h>

#include <dm/device-internal.h>
#include "sprd_pinctrl.h"

static u32 sprd_set_misc_atv_pd(int atv_pd)
{
	const u32 tbl[] = {0,
			BIT(6),
			BIT(7),
			BIT(12),
			BIT(7) | BIT(12)
	};

	if (atv_pd >= ARRAY_SIZE(tbl)) {
		return 0;
	}

	return tbl[atv_pd];
}

static u32 sprd_set_misc_slp_pd(int slp_pd)

{
	const u32 tbl[] = {0,
			BIT(2),
			BIT(3)
	};

	if (slp_pd >= ARRAY_SIZE(tbl)) {
		return 0;
	}

	return tbl[slp_pd];
}

static u32 sprd_set_misc_driver(int driver)
{
	const u32 tbl[] = {0,
			BIT(19),
			BIT(20),
			BIT(19) | BIT(20),
			BIT(21),
			BIT(21) | BIT(19),
			BIT(21) | BIT(20),
			BIT(19) | BIT(20) | BIT(21),
			BIT(22),
			BIT(22) | BIT(19),
			BIT(22) | BIT(20),
			BIT(22) | BIT(20) | BIT(19),
			BIT(22) | BIT(21),
			BIT(22) | BIT(21) | BIT(19),
			BIT(22) | BIT(21) | BIT(20),
			BIT(22) | BIT(21) | BIT(20) | BIT(19)
	};

	if (driver >= ARRAY_SIZE(tbl)) {
		return 0;
	}

	return tbl[driver];
}

static u32 sprd_set_misc_sleep_mode(int sl_mode)

{
	const u32 tbl[] = {0,
			BIT(13),
			BIT(14),
			BIT(13) | BIT(14),
			BIT(15),
			BIT(15) | BIT(13),
			BIT(15) | BIT(14),
			BIT(13) | BIT(14) | BIT(15),
			BIT(16),
			BIT(16) | BIT(13),
			BIT(16) | BIT(14),
			BIT(16) | BIT(14) | BIT(13),
			BIT(16) | BIT(15),
			BIT(16) | BIT(15) | BIT(13),
			BIT(16) | BIT(15) | BIT(14),
			BIT(16) | BIT(15) | BIT(14) | BIT(13),
			BIT(17),
			BIT(17) | BIT(13),
			BIT(17) | BIT(14),
			BIT(17) | BIT(14) | BIT(13),
			BIT(17) | BIT(15),
			BIT(17) | BIT(15) | BIT(13),
			BIT(17) | BIT(15) | BIT(14),
			BIT(17) | BIT(15) | BIT(14) | BIT(13),
			BIT(17) | BIT(16),
			BIT(17) | BIT(16) | BIT(13),
			BIT(17) | BIT(16) | BIT(14),
			BIT(17) | BIT(16) | BIT(15),
			BIT(17) | BIT(16) | BIT(15) | BIT(14) |BIT(13),
			BIT(18),
			BIT(18) | BIT(13),
			BIT(18) | BIT(14),
			BIT(18) | BIT(14) | BIT(13),
			BIT(18) | BIT(15),
			BIT(18) | BIT(15) | BIT(13),
			BIT(18) | BIT(15) | BIT(14),
			BIT(18) | BIT(15) | BIT(14) | BIT(13),
			BIT(18) | BIT(16),
			BIT(18) | BIT(16) | BIT(13),
			BIT(18) | BIT(16) | BIT(14),
			BIT(18) | BIT(16) | BIT(15),
			BIT(18) | BIT(16) | BIT(15) | BIT(14) |BIT(13),
			BIT(18) | BIT(17),
			BIT(18) | BIT(17) | BIT(13),
			BIT(18) | BIT(17) | BIT(14),
			BIT(18) | BIT(17) | BIT(15),
			BIT(18) | BIT(17) | BIT(16),
			BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(14) |BIT(13)
	};

	if (sl_mode >= ARRAY_SIZE(tbl)) {
			return 0;
	}

	return tbl[sl_mode];
}

static u32 sprd_set_misc_in_out(int in_out)
{
	const u32 tbl[] = {0,
			BIT(0),
			BIT(1)
	};

	if (in_out >= ARRAY_SIZE(tbl)) {
		return 0;
	}

	return tbl[in_out];
}

static int sprd_set_global(struct pinctrl_info *dev_info,
			   struct pin_info *pinctr_info, int pins_num, u32 base_addr)
{
	int i, ret = 0;

	for (i = 0; i < pins_num; i++) {
		ret = strcmp(pinctr_info[i].name, dev_info->pins);
		if (ret == 0)
			__raw_writel(dev_info->val, pinctr_info[i].offset + base_addr);
	}
	return 0;
}

static int sprd_set_global_matrix(struct pinctrl_info *dev_info,
			   struct pin_info *pinctr_info, int pins_num, u32 base_addr)
{
	int i, ret = 0;
	u32 val = 0;

	for (i = 0; i < pins_num; i++) {
		ret = strcmp(pinctr_info[i].name, dev_info->pins);
		if (ret == 0) {
			val = __raw_readl(pinctr_info[i].offset + base_addr);

			if ((dev_info->inf_mask >= 0) && (dev_info->inf_shift >= 0)
			    && (dev_info->inf_val >= 0)) {
				val &= ~((dev_info->inf_mask) << (dev_info->inf_shift));
				val |= ((dev_info->inf_val) << (dev_info->inf_shift));
			}

			__raw_writel(val, pinctr_info[i].offset + base_addr);
		}
	}
	return 0;
}

static int sprd_set_common(struct pinctrl_info *dev_info,
			   struct pin_info *pinctr_info, int pins_num, u32 base_addr)
{
	int i, ret = 0;

	for (i = 0; i < pins_num; i++) {
		ret = strcmp(pinctr_info[i].name, dev_info->pins);
		if (ret == 0)
			__raw_writel(dev_info->val, pinctr_info[i].offset + base_addr);
	}
	return 0;
}

static int sprd_set_misc(struct pinctrl_info *dev_info,
			 struct pin_info *pinctr_info, int pins_num, u32 base_addr)
{
	int i, ret = 0;
	u32 val = 0;
	u32 val_pull, val_down, val_driver, val_in_out, val_mode;

	for (i = 0; i < pins_num; i++) {
		ret = strcmp(pinctr_info[i].name, dev_info->pins);
		if (ret == 0) {
			val = __raw_readl(pinctr_info[i].offset + base_addr);

			//set active pull & down
			if (dev_info->atv_pd >= 0) {
				val_pull = sprd_set_misc_atv_pd(dev_info->atv_pd);
				val &= ~(ACTIVE_MASK << ACTIVE_SHIFT);
				val |= val_pull;
			}

			//set sleep pull & down
			if (dev_info->slp_pd >= 0) {
				val_down = sprd_set_misc_slp_pd(dev_info->slp_pd);
				val &= ~(SLEEP_MASK << SLEEP_SHIFT);
				val |= val_down;
			}

			//set driver
			if (dev_info->driver >= 0) {
				val_driver = sprd_set_misc_driver(dev_info->driver);
				val &= ~(DRIVER_MASK << DRIVER_SHIFT);
				val |= val_driver;
			}

			//set input/output
			if (dev_info->in_out >= 0) {
				val_in_out = sprd_set_misc_in_out(dev_info->in_out);
				val &= ~(IN_OUT_MASK << IN_OUT_SHIFT);
				val |= val_in_out;
			}

			//set sleep mode
			if (dev_info->sl_mode >= 0) {
				val_mode = sprd_set_misc_sleep_mode(dev_info->sl_mode);
				val &= ~(SL_MODE_MASK << SL_MODE_SHIFT);
				val |= val_mode;
			}

			__raw_writel(val, pinctr_info[i].offset + base_addr);
		}
	}
	return 0;
}

static int fdt_find_pinctrl_node(const void *fdt, int offset, char *pin_name,
				 struct pin_info *pinctr_info, int pins_num, u32 base_addr)
{
	int pin_nodeoffset;
	struct pinctrl_info pinctrl = {0};
	int ret;
	u32 val = 0;

	pin_nodeoffset = fdt_subnode_offset(fdt, offset, pin_name);
	if (pin_nodeoffset < 0)
		errorf("fdt_find_pinctrl_node: cann't find pinctrl\n");
	else {
		pinctrl.type = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,type", -1);
		if (pinctrl.type < 0) {
			errorf("fdt_find_pinctrl_node: cann't find sprd,type property\n");
			return 0;
		} else {
			//parsing global register
			if (pinctrl.type == 0) {
				pinctrl.pins = fdt_getprop(fdt, pin_nodeoffset, "sprd,pins", NULL);
				if (!pinctrl.pins) {
					errorf("fdt_find_pinctrl_node: cann't find sprd,pins property\n");
					return 0;
				}

				ret = fdt_getprop_u32(fdt, pin_nodeoffset, "sprd,config", &val);
				if (ret < 0) {

					pinctrl.inf_mask = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,inf_mask", -1);
					pinctrl.inf_shift = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,inf_shift", -1);
					pinctrl.inf_val = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,inf_val", -1);

					sprd_set_global_matrix(&pinctrl, pinctr_info, pins_num, base_addr);
				}
				else {
					pinctrl.val = val;
					sprd_set_global(&pinctrl, pinctr_info, pins_num, base_addr);
				}
			}

			//parsing common register
			else if (pinctrl.type == 1) {
				pinctrl.pins = fdt_getprop(fdt, pin_nodeoffset, "sprd,pins", NULL);
				if (!pinctrl.pins) {
					errorf("fdt_find_pinctrl_node: cann't find sprd,pins property\n");
					return 0;
				}

				ret = fdt_getprop_u32(fdt, pin_nodeoffset, "sprd,config", &val);
				if (ret < 0) {
					errorf("fdt_find_pinctrl_node: cann't find sprd,config property\n");
					return 0;
				}

				pinctrl.val = val;
				sprd_set_common(&pinctrl, pinctr_info, pins_num, base_addr);
			}

			//parsing MISC register
			else if (pinctrl.type == 2) {
				pinctrl.pins = fdt_getprop(fdt, pin_nodeoffset, "sprd,pins", NULL);
				if (!pinctrl.pins) {
					errorf("fdt_find_pinctrl_node: cann't find sprd,pins property\n");
					return 0;
				}

				pinctrl.atv_pd = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,active_pd", -1);
				pinctrl.slp_pd = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,sleep_pd", -1);
				pinctrl.driver = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,driver", -1);
				pinctrl.in_out = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,in_out", -1);
				pinctrl.sl_mode = fdtdec_get_int(fdt, pin_nodeoffset, "sprd,sl_mode", -1);

				sprd_set_misc(&pinctrl, pinctr_info, pins_num, base_addr);
			}
		}
	}
	return 0;
}

int sprd_pinctrl_core_probe(struct pin_info *pinctr_info, int pins_num, u32 base_addr)
{
	const void *fdt = gd->fdt_blob;
	int pin_offset1,pin_offset2;
	int node_num;
	int i;
	char pin_name[16];

	if (!fdt) {
		errorf("fdt is NULL, can't parse dts\n");
		return -1;
	}

	/* parsing dtsi node,barod id,dtsi node name must be "pinctrl-boardid"*/
	pin_offset1 = fdt_path_offset(fdt, "/pinctrl-boardid");
	if (pin_offset1 < 0)
		errorf("get pinctrl-boardid node error: %s\n", fdt_strerror(pin_offset1));
	else {
		node_num = fdtdec_get_child_count(fdt, pin_offset1);

		for (i = 0; i < node_num; i++) {
			sprintf(pin_name, "pinctrl_%d", i);
			fdt_find_pinctrl_node(fdt, pin_offset1, pin_name, pinctr_info, pins_num, base_addr);
		}
	}
	/* parsing dts node,barod id,dts node name must be "pinctrl-common"*/
	pin_offset2 = fdt_path_offset(fdt, "/pinctrl-common");
	if (pin_offset2 < 0)
		errorf("get pinctrl-common node error: %s\n", fdt_strerror(pin_offset2));
	else {
		node_num = fdtdec_get_child_count(fdt, pin_offset2);

		for (i = 0; i < node_num; i++) {
			sprintf(pin_name, "pinctrl_%d", i);
			fdt_find_pinctrl_node(fdt, pin_offset2, pin_name, pinctr_info, pins_num, base_addr);
		}
	}
	return 0;
}

