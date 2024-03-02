/*
 * Copyright (C) 2019 unisoc.com
 *
 * Support notifier train.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include "notifier.h"

int notifier_chain_register(struct notifier_block **nl,
				   struct notifier_block *n)
{
	struct notifier_block *pre = NULL;
	struct notifier_block *next;

	if (!nl || !n || !n->name || !n->notifier_call)
		return -1;

	next = *nl;
	while (next != NULL) {
		if (n->priority > next->priority)
			break;
		pre = next;
		next = next->next;
	}

	n->next = next;
	if (pre)
		pre->next = n;
	else
		*nl = n;

	debugf("%s\n", n->name);

	return 0;
}

/**
 * notifier_chain_unregister - unregister *n, *n's memory not be release here.
 *	@nl:	Pointer to head of the blocking notifier chain
 *	@n:	Pointer to notifier
 */
int notifier_chain_unregister(struct notifier_block **nl,
				     struct notifier_block *n)
{
	struct notifier_block *pre = NULL;
	struct notifier_block *next;

	if (!nl || !n)
		return -1;

	next = *nl;
	while (next != NULL) {
		if (next == n) {
			if (pre)
				pre->next = n->next;
			else
				*nl = n->next;
			return 0;
		}
		pre = next;
		next = next->next;
	}

	return -1;
}

/**
 * notifier_call_chain - Informs the registered notifiers about an event.
 *	@nl:		Pointer to head of the blocking notifier chain
 *	@val:		Value passed unmodified to notifier function
 *	@v:		Pointer passed unmodified to notifier function
 */
int notifier_call_chain(struct notifier_block **nl,
			       unsigned long val, void *v)
{
	struct notifier_block *next;
	int ret = NOTIFY_DONE;

	if (!nl)
		return -1;

	next = *nl;
	while (next != NULL) {
		ret = next->notifier_call(next, val, v);
		if (ret & NOTIFY_STOP_MASK) {
			printf("%s returns NOTIFY_STOP", next->name);
			break;
		}
		debugf("%s is called\n", next->name);
		next = next->next;
	}

	return ret;
}

int notifier_dump_chain(struct notifier_block **nl)
{
	struct notifier_block *next;

	if (!nl)
		return -1;

	next = *nl;
	while (next != NULL) {
		debugf("%s, priority %d\n", next->name, next->priority);
		next = next->next;
	}

	return 0;
}
