#include <asm-generic/errno.h>
#include <asm/types.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass.h>
#include <dm/uclass-id.h>
#include <linux/types.h>
#include <linux/err.h>
#include <common.h>
#include <misc.h>
#include <asm/arch-sc9630/migrate.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <fdtdec.h>
#include "dspboot.h"
#include <asm/io.h>
#include <mapmem.h>
#include <dm/of_access.h>
#include <command.h>

/* The dsp boot test code without header */
__align(16) volatile static u32 s_dsp_code[0x400] = {
		0xd7ee1320, 0xd7e67300, 0x00000000, 0xd7e6db00,
		0xd7e67304, 0x00000000, 0xd7e67300, 0x00000000,
		0x6a286a28, 0x00000000, 0x6a286a28, 0x6a286a28,
		0x6a286a28, 0x6a286a28, 0x6a286a28, 0x6a286a28,
		0x6a286a28, 0x6a286a28, 0x6a286a28, 0x6a286a28,
		0x00000003, 0xd7e67300, (0x015D0020/2), 0xd7e6db00,
		0xAAAAAAAA, 0xD7E67300,
#ifdef CONFIG_SOC_SHARKL5PRO
		(0x30000000/2),/* Start_Address from audsp/2 */
#endif

#ifdef CONFIG_SOC_QOGIRL6
		(0x65004400/2),
#endif

#ifdef CONFIG_SOC_QOGIRN6PRO
		(0x65005400/2),
#endif
		0xD7E6DB00,
		0xFFFFFFFC, 0xd7ee1320, 0x00000000, 0x00000000,
		0x0000a700, 0x0002a700, 0x0004a700, 0x0006a700,
		0x0008a700, 0x000aa700, 0x000ca700, 0x000ea700,
};

/* The dsp boot test code including header */
__align(16) volatile static u32 s_header_dsp_code[0x80+0x400] = {
		0x72616853, 0x5f354c6b, 0x43445541, 0x00000050,   //header: SharkL5_AUDCP
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0xd7ee1320, 0xd7e67300, 0x00000000, 0xd7e6db00,
		0xd7e67304, 0x00000000, 0xd7e67300, 0x00000000,
		0x6a286a28, 0x00000000, 0x6a286a28, 0x6a286a28,
		0x6a286a28, 0x6a286a28, 0x6a286a28, 0x6a286a28,
		0x6a286a28, 0x6a286a28, 0x6a286a28, 0x6a286a28,
		0x00000003, 0xd7e67300, (0x015D0020/2), 0xd7e6db00,
		0xAAAAAAAA, 0xD7E67300,
#ifdef CONFIG_SOC_SHARKL5PRO
		(0x30000000/2),/* Start_Address from audsp/2 */
#endif

#ifdef CONFIG_SOC_QOGIRL6
		(0x65004400/2),
#endif

#ifdef CONFIG_SOC_QOGIRN6PRO
		(0x65005400/2),
#endif
		0xD7E6DB00,
		0xFFFFFFFC, 0xd7ee1320, 0x00000000, 0x00000000,
		0x0000a700, 0x0002a700, 0x0004a700, 0x0006a700,
		0x0008a700, 0x000aa700, 0x000ca700, 0x000ea700,
};

int dspboot_boot_ok_test(int argc, char *const argv[])
{
	int ret = 0;

#ifdef CONFIG_SOC_SHARKL5PRO   //ums512_1h10.h
   	volatile u32 *AP_Addr = (volatile u32 *)0x00005400;  //Start_Address from ap
#endif

#ifdef CONFIG_SOC_QOGIRL6     //ums9230_1h10.h
	volatile u32 *AP_Addr = (volatile u32 *)0x65004400;  //Start_Address from ap
#endif

#ifdef CONFIG_SOC_QOGIRN6PRO  ////ums9520_1h10.h
	volatile u32 *AP_Addr = (volatile u32 *)0x65005400;  //Start_Address from ap
#endif

	ret = sprd_dspboot_doboot((u32)s_header_dsp_code, AUDCP_HEADER_STR, strlen(AUDCP_HEADER_STR), HEADER_SIZE );
	if (ret) {
		debugf("sprd_dspboot_doboot fail=%d\n", ret);
		return ret;
	}

	mdelay(1);

/*  read magic num from AP addr */
	if (*AP_Addr==0xAAAAAAAA) {
		debugf("audcp_boot test ok!  magic num read from AP start_address = 0x%x\n", *AP_Addr);
	}
	else {
		debugf("audcp_boot test fail! Cann't read magic num from AP start_address!\n");
		return -1;
	}
	return 0;
}

int dspboot_header_detect(int argc, char *const argv[])
{
	int ret = 0;
	ret = sprd_dspboot_doboot((u32)s_dsp_code, AUDCP_HEADER_STR, strlen(AUDCP_HEADER_STR), HEADER_SIZE );
	if (ret){
		debugf("Can't find AUDCP section header!\n");  //if header is not detected, it means that this test is ok.
	}
	else
          	return -1;
	return 0;
}

U_BOOT_IT_TEST_REGISTER(dspboot_tc1000_doboot_test, dspboot_boot_ok_test, "This function is to test boot_ok");
U_BOOT_IT_TEST_REGISTER(dspboot_tc1001_doboot_test, dspboot_header_detect, "This function is to detect no_dspboot_header");

