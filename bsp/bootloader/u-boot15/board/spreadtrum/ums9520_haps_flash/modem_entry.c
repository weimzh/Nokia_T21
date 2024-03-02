#include <common.h>
#include <asm/arch/common.h>
#include <asm/arch/sprd_reg.h>

#include "cp_boot.h"

/* audio cp aon iram, and ddr memory for communication */
#define AUDCP_AON_IRAM_START 0x65006400
/* size 4k */
#define AUDCP_AON_IRAM_SIZE 0x1000
#define AUDCP_DDR_COMMU_START 0x87780000
/* size 3.5k + 16 bytes */
#define AUDCP_DDR_COMMU_SIZE 0xe10

/*bug:533275  memset tg/l/agdsp share memory
root cause: In agdsp share IRAM memory ,this area exits command for agdsp,when interunpt happens
from ap or cp,the agdsp will use this area. While the area exit the dirty binary data ,ap or cp
do not clean up this area when interrupt happens at the right time,so error command will cause
unexcepted problems.*/

void memset_dsp_share_memory()
{
	/* audio cp aon iram 4k */
	memset((void *)AUDCP_AON_IRAM_START,0x0,AUDCP_AON_IRAM_SIZE);
	/* audio cp ddr 3.5k+16 bytes */
	memset((void *)AUDCP_DDR_COMMU_START,0x0,AUDCP_DDR_COMMU_SIZE);
}

void audcp_boot_header(u32 boot_vector)
{
	if (!memcmp(boot_vector, AUDCP_HEADER_STR, strlen(AUDCP_HEADER_STR)))
	{
		audcp_boot(((boot_vector+0x80)/2));
		debugf("audio cp boot ok!\n");
	}
	else
	{
		debugf("audio cp boot fail, can't find AUDCP section header!\n");
	}
}

void modem_entry()
{
	memset_dsp_share_memory();
	audcp_boot_header(LTE_AGDSP_ADDR);

	pubcp_boot_prepare();
#ifndef CONFIG_KERNEL_BOOT_CP
	sp_boot();
	ch_boot();
	pubcp_boot();
	debugf("boot CP1 OK\n");
#else
	extern unsigned int g_charger_mode;
	if(g_charger_mode) {
	#ifndef PROJECT_SEC_CM4
		sp_boot();
	#endif
		debugf("boot sp  OK\n");
	}
#endif
}

