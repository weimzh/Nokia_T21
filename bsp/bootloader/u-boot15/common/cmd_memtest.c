#include <common.h>
#include <command.h>
#include <loader_common.h>
#include <boot_mode.h>

static int do_memtest(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	static int once = 1;
	debugf("enter memtest\n");
	if(once)
	{
		once = 0;
#ifdef CONFIG_SPLASH_SCREEN
		extern int drv_lcd_init (void);
#ifndef DEBUG
		stop_watchdog();
#endif
		drv_lcd_init();
		lcd_splash(LOGO_PART);
		lcd_enable();
		vibrator_hw_init();
		set_vibrator(1);

		extern void set_backlight(uint32_t value);
		set_backlight(BACKLIGHT_ON);
		mdelay(400);
		set_vibrator(0);
#endif
	}
	extern ddr_memtester(ulong test_len);
	extern ddr_region_printf();
	extern ddr_manual_memtester(ulong start_ads, ulong test_len);
	ulong start_ads;
	ulong test_len;

	set_vibrator(1);
	mdelay(400);
	set_vibrator(0);

	if(argc == 1){
		ddr_memtester(0);
	}else if(argc == 2){
		ddr_region_printf();
	}else if(argc == 3){
		if(strict_strtoul(argv[1], 16, &start_ads) < 0)
			return CMD_RET_USAGE;

		if(strict_strtoul(argv[2], 16, &test_len) < 0)
			return CMD_RET_USAGE;

		ddr_manual_memtester(start_ads, test_len);
	}
}

U_BOOT_CMD(
	memtest, 5, 0, do_memtest,
	"RAM read/write test",
	"memtest <start_address> <len>"
);
