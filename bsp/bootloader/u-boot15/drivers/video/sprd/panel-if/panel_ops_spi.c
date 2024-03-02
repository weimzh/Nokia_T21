/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "sprd_panel.h"

static int panel_init(void)
{
	return 0;
}

static int panel_readid(void)
{
	return 0;
}

static int panel_power(int on)
{
	return 0;
}

static struct panel_ops spi_ops = {
	.init = panel_init,
	.read_id = panel_readid,
	.power = panel_power,
};

struct panel_ops *spi_ops_attach(void)
{
	return &spi_ops;
}
