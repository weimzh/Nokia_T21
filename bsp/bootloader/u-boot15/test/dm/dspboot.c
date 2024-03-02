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

#include <common.h>
#include <dm.h>
#include <dm/test.h>
#include <test/ut.h>

/* Basic test of the pwm uclass */
static int dm_test_dspboot_base(struct unit_test_state *uts)
{
	struct udevice *dev;

	ut_assertok(uclass_get_device(UCLASS_DSPBOOT, 0, &dev));
	ut_assertnonnull(dev);
	ut_assertok(sprd_dspboot_doboot(0));

	return 0;
}
DM_TEST(dm_test_dspboot_base, DM_TESTF_SCAN_PDATA | DM_TESTF_SCAN_FDT);
