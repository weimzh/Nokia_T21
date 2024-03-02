/*
 *  log_mechanism_ITcase.c - For IT testing
 *
 *  Copyright (C) 2020 Unisoc Communications Inc.
 *  History:
 *      2020/7/9 zhe.wang1
 *      Description
 */
#include <rtc.h>
#include <boot_mode.h>
#include <common.h>
#include <linux/input.h>
#include <linux/mtd/mtd.h>
#include <linux/sizes.h>
#include <asm/arch/check_reboot.h>
#include <mmc.h>
#include <fat.h>
#include <exfat.h>
#include <chipram_env.h>
#include <sprd_common_rw.h>

#if defined(CONFIG_LOG_2_EMMC) || defined(CONFIG_LOG_2_UFS)
extern LOG_STRUCT log_st;
#endif

static uint32_t log_partition_flag_clear(uint64_t log_p_offset_t)
{
	uchar hdr_buf[LOG_HEADER_SIZE];
	LOG_PARTITION_HEADER *p_hdr = hdr_buf;
	memset(hdr_buf, 0, sizeof(hdr_buf));

	if (0 != common_raw_read(UBOOT_LOG_PARTITION, (uint64_t)LOG_HEADER_SIZE, log_p_offset_t, hdr_buf)) {
		errorf("read error\n");
		return -1;
	}

	/*clear log init sucess status*/
	log_st.flag = FAILED;

	return p_hdr->next_body;
}

static int uboot_log_mechanism_test(int argc, char *const argv[])
{
#if defined(CONFIG_LOG_2_EMMC) || defined(CONFIG_LOG_2_UFS)
	int i = 0;
	int ret = 0;
	int log_type;
	uint32_t current_body;
	uint32_t next_body;
	uint64_t log_p_offset = 0;

#ifdef CONFIG_ZEBU
	boot_mode_t boot_role = BOOTLOADER_MODE_LOAD;
#else
	boot_mode_t boot_role = get_boot_role();
#endif

	switch(boot_role) {
		case BOOTLOADER_MODE_DOWNLOAD:
			log_type = DOWNLD_LOG_TYPE;
			log_p_offset = DOWNLD_LOG_PARTITION_OFFSET;
			break;
		case BOOTLOADER_MODE_LOAD:
			log_type = START_LOG_TYPE;
			log_p_offset = START_LOG_PARTITON_OFFSET;
			break;
		default :
			errorf("unkown uboot role ,nothing to do in preboot\n");
			return -1;
	}

	for (i; i < LOG_BODY_NUM; i++) {
		current_body = log_partition_flag_clear(log_p_offset);
		if (-1 == next_body)
			return -1;
		if (-1 == init_log_partition_hdr())
			return -1;
		flush_log_buffer();
		next_body = log_partition_flag_clear(log_p_offset);
		if (-1 == next_body)
			return -1;
		if (next_body == 0 && log_type == DOWNLD_LOG_TYPE) {
			next_body = LOG_BODY_NUM;
		} else if (next_body == 0 && log_type == START_LOG_TYPE) {
			next_body = LOG_BODY_NUM - 1;
		}
		if (current_body == next_body - 1) {
			if (log_type == DOWNLD_LOG_TYPE)
				debugf("DOWNLOAD mode current log body: %d next log body %d, PASS\n", current_body, next_body);
			else if (log_type == START_LOG_TYPE)
				debugf("LOAD mode current log body: %d next log body %d, PASS\n", current_body, next_body);
		} else {
			if (log_type == DOWNLD_LOG_TYPE)
				errorf("DOWNLOAD mode current log body: %d next log body %d, FAILED\n", current_body, next_body);
			else if (log_type == START_LOG_TYPE)
				errorf("LOAD mode current log body: %d next log body %d, FAILED\n", current_body, next_body);
			return -1;
		}
	}

	return 0;
#else
	errorf("macro CONFIG_LOG_2_EMMC\CONFIG_LOG_2_UFS were not defined\n");
#endif
}

U_BOOT_IT_TEST_REGISTER(uboot_tc1002_log_mechanism_test, uboot_log_mechanism_test,
		"This tc function detects that the download\load mode log mechanism is correct");
