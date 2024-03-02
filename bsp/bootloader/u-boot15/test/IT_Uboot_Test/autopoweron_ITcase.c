/*
 *  autopoweron_ITcase.c - For IT testing
 *
 *  Copyright (C) 2020 Unisoc Communications Inc.
 *  History:
 *      2020/7/9 zhe.wang1
 *      Description
 */
#include <common.h>
#include <boot_mode.h>
#include <part_efi.h>
#include "loader_common.h"
#include <sprd_common_rw.h>
#include "packet.h"

#define AON_FIRSTMODE_FLAG  (0x17)

int IT_test_dl_set_first_mode(dl_packet_t *packet)
{
	u32 set_first_mode = 0;

	set_first_mode = *(packet->body.content);
	debugf("set_first_mode: 0x%x\n", set_first_mode);

	set_first_mode += SET_FIRST_MODE_MAGIC;

	if (0 != common_raw_write("miscdata", (uint64_t)(sizeof(set_first_mode)), (uint64_t)0,
				(uint64_t)SET_FIRST_MODE_OFFSET, (char *)&set_first_mode)){
		errorf("write partition <miscdata> fail\n");
		return -1;
	}

	return 0;
}

int uboot_autopoweron_dl_set_firstmode_test(int argc, char *const argv[])
{
	dl_packet_t *packet_temp;
	u32 get_first_mode = 0;
	u32 clear_first_mode = 0;
	int ret = 0;

	packet_temp = (dl_packet_t *)malloc(sizeof(dl_packet_t));
	if (NULL == packet_temp) {
		errorf("malloc packet_temp fail\n");
		return -1;
	}
	/*set autopoweron firstmode flag 0x17*/
	*(packet_temp->body.content) = AON_FIRSTMODE_FLAG;
	if (-1 == IT_test_dl_set_first_mode(packet_temp)) {
		ret = -1;
		goto end;
	}

	if (0 != common_raw_read("miscdata", SET_FIRST_MDOE_LEN,
			(uint64_t)(SET_FIRST_MODE_OFFSET), (char *)&get_first_mode)) {
		errorf("partition <miscdata> read error\n");
		ret = -1;
		goto end;
	}

	if (get_first_mode == (u32)(AON_FIRSTMODE_FLAG + SET_FIRST_MODE_MAGIC))
		debugf("the download mode was successfully written to FirstMode flag\n");
	else {
		errorf("the download mode was failed written to FirstMode flag\n");
		ret = -1;
		goto end;
	}

	if (0 != common_raw_write("miscdata", SET_FIRST_MDOE_LEN, (uint64_t)0,
			(uint64_t)(SET_FIRST_MODE_OFFSET), (char *)&clear_first_mode)) {
		errorf("clear partition <miscdata> firstmode flag fail\n");
		ret = -1;
	}
end:
	free(packet_temp);
	return ret;
}

int uboot_autopoweron_enter_normal_mode_test(int argc, char *const argv[])
{
	dl_packet_t *packet_temp;
	int ret = 0;

	packet_temp = (dl_packet_t *)malloc(sizeof(dl_packet_t));
	if (NULL == packet_temp) {
		errorf("malloc packet_temp fail\n");
		return -1;
	}
	/*set autopoweron firstmode flag 0x17*/
	*(packet_temp->body.content) = AON_FIRSTMODE_FLAG;
	if (-1 == IT_test_dl_set_first_mode(packet_temp)) {
		ret = -1;
		goto end;
	}

	if (CMD_NORMAL_MODE != read_boot_flag()) {
		errorf("autopoweron enter normal mode failed\n");
		ret = -1;
	} else
		debugf("autopoweron enter normal mode successfully\n");
end:
	free(packet_temp);
	return ret;
}

U_BOOT_IT_TEST_REGISTER(uboot_tc1000_autopoweron_dl_set_firstmode_test, uboot_autopoweron_dl_set_firstmode_test,
			"This tc function detects that the download mode was successfully written to FirstMode flag");
U_BOOT_IT_TEST_REGISTER(uboot_tc1001_autopoweron_enter_normal_mode_test, uboot_autopoweron_enter_normal_mode_test,
			"This tc function detects that the devices will enter normal mode after setting autopoweron firstmode flag");
