#include <common.h>
#include <command.h>
#include <linux/types.h>
#include <boot_mode.h>
#include <asm/arch/check_reboot.h>
#include <sprd_battery.h>


int uboot_driver_test(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{

	int repatable = 0;

	if(argc > 10)
		return CMD_RET_USAGE;

	if(argv[1] == NULL || argv[2] == NULL)
		return 0;


	if(strncmp(argv[2], "all", 3) == 0)
		test_all_case(0, argc, argv, &repatable, NULL);
	else if(strncmp(argv[2], "help", 4) == 0)
		list_all_case(0, argc, argv, &repatable, NULL);
	else
		cmd_process_driver(0, argc, argv, &repatable, NULL);

	return 0;
}


U_BOOT_CMD(
	drivertest, 10, 1, uboot_driver_test,
	"choose module driver to it test",
	"module include: \ni2c, spi, regulator, charge, clock, vibrator, uart and so on\n"
	"command format:\n"
	"drivertest xxx(module) xxx(casename)\n"
	);
