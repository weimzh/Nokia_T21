/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002
 * Gary Jennejohn, DENX Software Engineering, <gj@denx.de>
 *
 * (C) Copyright 2009
 * Ilya Yanok, Emcraft Systems Ltd, <yanok@emcraft.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/io.h>
#include <sprd_regulator.h>
#include <asm/arch/sprd_reg.h>
#include "sprd_wdt.h"
#include "notifier.h"
#include "sprd_reset.h"

/*
 * Reset the cpu by setting up the watchdog timer and let it time out
 */

int (*arch_poweroff)(void) = NULL;
static struct notifier_block *notify_head_poweroff;

/**
 * notifier_reset_register - register notifiers about reset.
 *	@n:		notifier call back
 *	@type:		register poweroff or reboot
 */
int notifier_reset_register(struct notifier_block *n, notify_reset_type type)
{
	int ret = -1;

	if (type == NOTIFY_RESET_TYPE_POWEROFF) {
		ret = notifier_chain_register(&notify_head_poweroff, n);
		notifier_dump_chain(&notify_head_poweroff);
	}

	return ret;
}
int notifier_reset_unregister(struct notifier_block *n, notify_reset_type type)
{
	int ret = -1;

	if (type == NOTIFY_RESET_TYPE_POWEROFF)
		ret = notifier_chain_unregister(&notify_head_poweroff, n);

	return ret;
}

void reset_cpu (ulong ignored)
{
	start_watchdog(5);
	printf("reset cpu\n");
	while (1) ;
}

void rtc_clean_all_int(void);
void power_down_cpu(ulong ignored)
{
	int v = 0;
	v = ANA_REG_GET(ANA_REG_GLB_POR_SRC_FLAG);
	printf("power on src = 0x%.8x\n", v);
	notifier_call_chain(&notify_head_poweroff, NOTIFY_RESET_ACTION_POWEROFF, NULL);

	while(1);
}
