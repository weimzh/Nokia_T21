/*
 *  nand_ITcase.c - For IT testing
 *
 *  Copyright (C) 2020 Unisoc Communications Inc.
 *  History:
 *      2020/11/30 zhenxiong.lai
 *      Description
 */
#include <common.h>
#include <sprd_common_rw.h>

#ifdef CONFIG_NAND_BOOT
static int uboot_nand_write_test(int argc, char *const argv[])
{
	unsigned int test = 0x5a5a1234;
	int ret;

	ret = common_raw_write("misc", sizeof(test), 0, 0, (char *)&test);
	if (ret) {
		debugf("test fail %d\n", ret);
	else
		debugf("test success\n");
	return 0;
}

static int uboot_nand_read_test(int argc, char *const argv[])
{
	unsigned int test;
	int ret;

	ret = common_raw_read("misc", sizeof(test), 0, (char *)&test);
	if (ret || test != 0x5a5a1234) {
		debugf("test fail %d\n", ret);
	else
		debugf("test success\n");
	
	return 0;
}

static int uboot_nand_erase_test(int argc, char *const argv[])
{
	return 0;
}

U_BOOT_IT_TEST_REGISTER(uboot_nand_tc1000_write_test, uboot_nand_write_test,
			"Test write data to nand flash");
U_BOOT_IT_TEST_REGISTER(uboot_nand_tc1001_read_test, uboot_nand_read_test,
			"Test read data from nand flash");
U_BOOT_IT_TEST_REGISTER(uboot_nand_tc1002_erase_test, uboot_nand_erase_test,
			"Test erase nand flash");
#endif

