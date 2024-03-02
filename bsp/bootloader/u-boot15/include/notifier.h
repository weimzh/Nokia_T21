/*
 * Copyright (C) 2019 unisoc.com
 *
 * Support notifier chain.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef _LINUX_NOTIFIER_H_
#define _LINUX_NOTIFIER_H_

#include <linux/compat.h>

#define NOTIFY_DONE		0x0000		/* Don't care */
#define NOTIFY_OK		0x0001		/* Suits me */
#define NOTIFY_STOP_MASK	0x8000		/* Don't call further */
#define NOTIFY_BAD		(NOTIFY_STOP_MASK|0x0002)
						/* Bad/Veto action */
/*
 * Clean way to return from the notifier and stop further calls.
 */
#define NOTIFY_STOP		(NOTIFY_OK|NOTIFY_STOP_MASK)


extern int notifier_chain_register(struct notifier_block **nl,
				   struct notifier_block *n);
extern int notifier_chain_unregister(struct notifier_block **nl,
				     struct notifier_block *n);
extern int notifier_call_chain(struct notifier_block **nl,
			       unsigned long val, void *v);
extern int notifier_dump_chain(struct notifier_block **nl);
#endif
