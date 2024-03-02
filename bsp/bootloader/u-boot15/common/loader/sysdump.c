/*
 * Copyright (C) 2013 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <boot_mode.h>
#include <common.h>
#include <linux/input.h>
#include "sysdump.h"
#include "sysdumpdb.h"
#include <u-boot/zlib.h>
#include <linux/mtd/mtd.h>
#include <linux/sizes.h>
#include <asm/arch/check_reboot.h>
#include <mmc.h>
#include <fat.h>
#include <exfat.h>
#include "loader_common.h"

#include <vsprintf.h>
#include <libfdt.h>
#include <fdt.h>
#include <linux/ctype.h>
#include <fdtdec.h>
#include <u-boot/sha1.h>

#include <linux/usb/ch9.h>
#include <linux/usb/usb_uboot.h>
#ifdef CONFIG_X86
#include <asm/e820.h>
#include <chipram_env.h>
#include "crashlog.h"
#endif
#include <sprd_led.h>
#include <sprd_log.h>
#include "logo_bin.h"
#include <miscdata_def.h>

#include <ext4fs.h>

/*for fulldump2internal start*/
struct fulldump_to_internal_info fulldump_to_internal_status ={
	.save_status	= FULLDUMP_INTER_UNDO,
	.data_start	= 0,
	.data_cur	= 0,
	.data_cur_index	= 0,
	.comp_buf	= NULL,
};
#define TRANSFER_BUF_START 0x80000000
#define SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE 8
int is_fulldumpdb_exist = 0;
char *name_new[40] = {0}; //for judge append flag
char *name_old[40] = {0}; //for judge append flag
/*for fulldump2internal end	*/

/*for dump to pc start*/
char dumpbuf_pc[MAX_DUMP_PKT_SIZE] = {0};
smp_header_t pkt_header;
int usb_init_count = 0;
int usb_insert_count = 0;
uint8_t handshake_buf[10];
extern int usb_trans_status;
extern unsigned short calc_checksum(unsigned char *dat, unsigned long len);
extern int charger_connected(void);
extern int usb_serial_init(void);
extern int usb_is_port_open(void);
extern int usb_is_configured(void);
extern void usb_init(uint32_t autodl_mode);
extern int usb_send(unsigned char *pbuf, int len);
/*for dump to pc end*/
int linux_mem_num_g = 0, reserved_mem_num_g = 0, dump_rst_mode_g = -1;
static struct sysdump_memory linux_memory[5];
static struct sysdump_memory reserved_memory[25];

void reboot_devices(unsigned reboot_mode);
extern unsigned reboot_reg;
extern unsigned sysdump_flag;
extern int sprd_host_init(int sdio_type);
extern struct rtc_time get_time_by_sec(void);
extern int load_fixup_dt_img(uchar *partition, uchar **dt_start_addr);
extern uint64_t _get_kernel_ramdisk_dt_offset( boot_img_hdr * hdr, uchar *partition);
extern void merge_dtbo(uchar *dt_start_addr);
#ifdef CONFIG_OF_LIBFDT_OVERLAY
extern void load_and_merge_dtbo(uchar *partition, uchar *dt_start_addr);
#endif
extern unsigned char board_key_scan(void);
extern int fdt_get_addr_size(const void *fdt, int node, const char *propname,
		uint64_t *addrp, mem_size_t *sizep);
/*	sysdump2.0 start */
struct check_dump_status_result check_dump_status_result;
struct dt_info dt_info;
struct dump_input_contents_info dump_input_contents_info;
CHECK_FUNC apdump_check_func_list[CHECK_FUNC_MAX] = {
	check_dump_enable_status,
};

int is_partition_ok = 1;
struct dumpdb_header check_header_g;
struct dumpdb_header header_paddr_mini;
struct sysdump_info backup_info_g;
/*	sysdump2.0 end */
#ifdef CONFIG_X86
extern ddr_info_t* get_ddr_range(void);
#endif

#if defined (CONFIG_ARM7_RAM_ACTIVE) && !defined (CONFIG_SPRD_SP_UART)
extern void pmic_arm7_RAM_active(void);
#endif

/*	for uboot log in minidump	*/
char* mini_pre_logbuffer = NULL;

/*	for etb */
#define ETBDATA "etbdata_uboot.bin"
#define ETBDATA_EXTEND "extend_etb_data"
#ifdef CONFIG_ETB_DUMP
extern unsigned char etb_dump_mem[SZ_32K];
extern u32 etb_buf_size;
extern void sprd_etb_hw_dis(void);
extern void sprd_etb_dump (void);
#endif

/* vmcoreinfo stuff */
int extend_vmcoreinfo_buf(void);
int *vmcoreinfo_size;
unsigned char *vmcoreinfo_data;
/* mmu res stuff */
int nr_cpus;
#define MMU_REGS "mmu_regs"
#define ARM64_TYPE "1"
#define ARM32_TYPE "0"

#define min(a, b)   ((a) < (b) ? a : b)

#ifdef CONFIG_SPLASH_SCREEN
extern void set_backlight(uint32_t value);
extern void lcd_printf(const char *fmt, ...);
extern void lcd_enable(void);
#define sysdump_lcd_printf(fmt, args...)   lcd_printf(fmt, ##args)
#else
#define sysdump_lcd_printf(fmt, args...)
#define lcd_enable(void)
#endif
#define DUMP_LOG_TAG	"sprd_dump"

#ifdef DEBUG
#define dump_logd(fmt, args...)  do { printf("(%s): ", DUMP_LOG_TAG); debugf(fmt, ##args); } while (0)
#else
#define dump_logd(fmt, args...)
#endif
#define dump_loge(fmt, args...)  do { printf("(%s): ", DUMP_LOG_TAG); errorf(fmt, ##args); } while (0)
#define dump_loga(fmt, args...)  do { printf("(%s): ", DUMP_LOG_TAG); printf("(%s): ", __func__); printf(fmt, ##args); } while (0)
char *sd_fs[] = {
	"FAT32",
	"EXFAT",
	"INVALID",
};
/* NOTE: the array need be updated on the basis of 'boot_mode_enum_type' */
char *rstmode[CMD_MAX_MODE] = {
	"undefind mode",			//CMD_UNDEFINED_MODE=0,
	"power down",				//CMD_POWER_DOWN_DEVICE,
	"normal",				//CMD_NORMAL_MODE,
	"recovery",				//CMD_RECOVERY_MODE,
	"fastboot",				//CMD_FASTBOOT_MODE,
	"alarm",				//CMD_ALARM_MODE,
	"charge",				//CMD_CHARGE_MODE,
	"engtest",				//CMD_ENGTEST_MODE,
	"cm4_watchdog_timeout",			//CMD_WATCHDOG_REBOOT ,
	"ap_watchdog_timeout",			//CMD_AP_WATCHDOG_REBOOT ,
	"framework crash",			//CMD_SPECIAL_MODE,
	"manual_dump",				//CMD_UNKNOW_REBOOT_MODE,
	"kernel_crash",				//CMD_PANIC_REBOOT,
	"vmm_panic",				//CMD_VMM_PANIC_MODE
	"tos_panic",				//CMD_TOS_PANIC_MODE
	"ext rstn reboot",                      //CMD_EXT_RSTN_REBOOT_MODE,
	"calibration",				//CMD_CALIBRATION_MODE,
	"factory test",				//CMD_FACTORYTEST_MODE,
	"autodloader",				//CMD_AUTODLOADER_REBOOT,
	"autotest",				//CMD_AUTOTEST_MODE,
	"iq reboot",				//CMD_IQ_REBOOT_MODE,
	"sleep",				//CMD_SLEEP_MODE,
	"sprd disk",				//CMD_SPRDISK_MODE,
	"apk mmi",				//CMD_APKMMI_MODE,
	"upt",					//CMD_UPT_MODE,
	"apkmmi auto",                          //CMD_APKMMI_AUTO_MODE,
	"abnormal mode",                        //CMD_ABNORMAL_REBOOT_MODE,
	"dmeio",					//CMD_DMEIO_MODE, /* 20220614, Added by zhu_jun for red eio warning screen when dm-verity device corrupted */
};
/* boot modes that need enter sysdump, the new exception mode should be added here */
int dump_mode[] = {
	CMD_WATCHDOG_REBOOT,
	CMD_AP_WATCHDOG_REBOOT,
	CMD_UNKNOW_REBOOT_MODE,
	CMD_SPECIAL_MODE,
	CMD_PANIC_REBOOT,
	CMD_VMM_PANIC_MODE,
	CMD_TOS_PANIC_MODE,
	CMD_EXT_RSTN_REBOOT_MODE,
	CMD_ABNORMAL_REBOOT_MODE,
};



char *fastboot_subcmd[] = {
	"full-enable",			//CMD_FULL_ENABLE
	"full-disable",			//CMD_FULL_DISABLE
	"mini-enable",			//CMD_MINI_ENABLE
	"mini-disable",			//CMD_MINI_DISABLE
	"status",			//CMD_STATUS
	"autoreboot-enable",		//CMD_AUTOREBOOT_ENABLE
	"autoreboot-disable",		//CMD_AUTOREBOOT_ENABLE
	"dataoutput",			//CMD_DATAOUTPUT
};
typedef enum {
	CMD_FULL_ENABLE=0,
	CMD_FULL_DISABLE,
	CMD_MINI_ENABLE,
	CMD_MINI_DISABLE,
	CMD_STATUS,
	CMD_AUTOREBOOT_ENABLE,			//value = 6
	CMD_AUTOREBOOT_DISABLE,			//value =
	CMD_DATAOUTPUT,
	/*this is not a cmd ,beyond CMD_MAX_NUM means overflow*/
	CMD_MAX_NUM
}fastboot_subcmd_enum_type;
int fulldump_enable_status;
int minidump_enable_status;
#define GET_RST_MODE(x) rstmode[(x) < CMD_MAX_MODE ? (x) : CMD_UNDEFINED_MODE]
#define GET_FS(x) sd_fs[(x) < FS_INVALID ? (x) : FS_INVALID]

/* boot mode */
int is_sysdump_boot_mode(int rst_mode)
{
	int i;
	int len;

	len = sizeof(dump_mode) / sizeof(int);

#define TRUE 1
#define FALSE 0

	for(i = 0; i < len; i++) {
		if (rst_mode == dump_mode[i])
			return TRUE;
	}

	return FALSE;
}

/*	Function for sysdump operation with fastboot . start	*/
int convert_command(const char *command)
{
	int i = 0;

	/*	parse sub-command	*/
	for (i = 0;i < CMD_MAX_NUM; i++) {
		if(!strcmp(fastboot_subcmd[i], command))
			break;
	}

	return i;
}
int sysdump_setdump_command(const char *command)
{
	struct dumpdb_header header_g;
	int cmd;

	cmd = convert_command(command);
	if (cmd == CMD_MAX_NUM) {
		dump_loge("invalid cmd:%d \n",cmd);
		return -1;
	}
	dump_logd("in -------------cmd:%d \n",cmd);
	if (common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)(sizeof(header_g)), (uint64_t)0,(char *)&header_g)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, SYSDUMPDB_PARTITION_NAME);
		return -1;
	}

	dump_logd("orig dump_flag:  (0x%x)\n", header_g.dump_flag);
	switch (cmd) {
	case CMD_FULL_ENABLE:
		header_g.dump_flag |= AP_FULL_DUMP_ENABLE;
		header_g.dump_flag |= ORIG_STATUS;
		dump_logd("CMD_FULL_ENABLE: update dump_flag:  (0x%x)\n", header_g.dump_flag);
		break;
	case CMD_FULL_DISABLE:
		header_g.dump_flag &= (~AP_FULL_DUMP_ENABLE);
		header_g.dump_flag |= ORIG_STATUS;
		dump_logd("CMD_FULL_DISABLE: update dump_flag:  (0x%x)\n", header_g.dump_flag);
		break;
	case CMD_MINI_ENABLE:
		header_g.dump_flag |= AP_MINI_DUMP_ENABLE;
		header_g.dump_flag |= ORIG_STATUS;
		dump_logd("CMD_MINI_ENABLE: update dump_flag:  (0x%x)\n", header_g.dump_flag);
		break;
	case CMD_MINI_DISABLE:
		header_g.dump_flag &= (~AP_MINI_DUMP_ENABLE);
		header_g.dump_flag |= ORIG_STATUS;
		dump_logd("CMD_MINI_DISABLE: update dump_flag:  (0x%x)\n", header_g.dump_flag);
		break;
	case CMD_AUTOREBOOT_ENABLE:
		header_g.dump_flag |= DUMP_FINISH_AUTO_REBOOT;
		dump_logd("CMD_AUTOREBOOT_ENABLE: update dump_flag:  (0x%x)\n", header_g.dump_flag);
		break;
	case CMD_AUTOREBOOT_DISABLE:
		header_g.dump_flag &= (~DUMP_FINISH_AUTO_REBOOT);
		dump_logd("CMD_AUTOREBOOT_DISABLE: update dump_flag:  (0x%x)\n", header_g.dump_flag);
		break;
	default:
		dump_loge(" invalid command.\n");
		return -1;
	}

	/*	updadte dump flag data */
	if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, sizeof(struct dumpdb_header), sizeof(struct dumpdb_header), 0, (char*)&header_g)) {
		dump_loge(" update dump flag  %s error.\n", SYSDUMPDB_PARTITION_NAME);
		return -1;
	}
	dump_logd("update dump_flag:  (0x%x)\n", header_g.dump_flag);
	return 0 ;
}

int sysdump_getdump_command(const char *command, int *fulldump_enable_status, int *minidump_enable_status)
{
	struct dumpdb_header header_g;
	int cmd;

	cmd = convert_command(command);
	if(cmd == CMD_MAX_NUM) {
		dump_loge("invalid cmd:%d \n",cmd);
		return -1;
	}
	dump_logd("in -------------cmd:%d \n",cmd);
	if (common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)(sizeof(header_g)), (uint64_t)0,(char *)&header_g)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, SYSDUMPDB_PARTITION_NAME);
		return -1;
	}

	dump_logd("orig dump_flag:  (0x%x)\n", header_g.dump_flag);
	switch (cmd) {
	case CMD_STATUS:
		dump_logd("CMD_STATUS:\n");
		*fulldump_enable_status = !!(header_g.dump_flag & AP_FULL_DUMP_ENABLE);
		*minidump_enable_status = !!(header_g.dump_flag & AP_MINI_DUMP_ENABLE);
		break;
	case CMD_DATAOUTPUT:
		/*	TODO:	 */
		dump_loge(" invalid command.\n");
		return -1;
	default:
		dump_loge(" invalid command.\n");
		return -1;
	}

	return 0 ;
}
/*	Function for sysdump operation with fastboot . end	*/
#ifdef CONFIG_SYSDUMP_LED

void led_sysdump_start(void)
{
	sprd_led_init();
	sprd_led_pattern_set(Red, BRIGHTNESS_MAX);
}
void led_dump2pc_wait_usb(void)
{
	sprd_led_pattern_set(Blue, BRIGHTNESS_MAX);
}
void led_dump2pc_usb_insert_ok(void)
{
	sprd_led_pattern_clear(Blue);
	sprd_led_set_brightness(Blue, BRIGHTNESS_MAX);
}
void led_sysdump_complete(void)
{
	sprd_led_pattern_clear(Red);
	sprd_led_set_brightness(Red, BRIGHTNESS_MAX);

	sprd_led_set_brightness(Blue, 0);
}
void led_sysdump_reboot(void)
{
	sprd_led_set_brightness(Red, 0);
}

#else
void led_sysdump_start(void)		{};
void led_dump2pc_wait_usb(void)		{};
void led_dump2pc_usb_insert_ok(void)	{};
void led_sysdump_complete(void)		{};
void led_sysdump_reboot(void)		{};
#endif
void display_writing_sysdump(void)
{
	dump_logd("%s\n", __FUNCTION__);
#ifdef CONFIG_SPLASH_SCREEN
#ifdef CONFIG_VIBRATOR
	vibrator_hw_init();
	set_vibrator(1);
#endif
	sysdump_lcd_printf("   -------------------------------  \n"
			"   Sysdumpping now, keep power on.  \n"
			"   -------------------------------  \n");
	set_backlight(BACKLIGHT_ON);
#ifdef CONFIG_VIBRATOR
	set_vibrator(0);
#endif
#endif
}
void display_special_mode(void)
{
	dump_logd("%s\n", __FUNCTION__);
#ifdef CONFIG_SPLASH_SCREEN
#ifdef CONFIG_VIBRATOR
	vibrator_hw_init();
	set_vibrator(1);
#endif
	sysdump_lcd_printf("   -------------------------------  \n"
			"   Restart now, keep power on.  \n"
			"   -------------------------------  \n");
	set_backlight(BACKLIGHT_ON);
#ifdef CONFIG_VIBRATOR
	set_vibrator(0);
#endif
#endif
}
#if 0
/*display without character*/
void display_sysdump(void)
{
	dump_logd("%s\n", __FUNCTION__);
#ifdef CONFIG_SPLASH_SCREEN
	vibrator_hw_init();
	set_vibrator(1);
	set_backlight(BACKLIGHT_ON);
	set_vibrator(0);
#endif
}
#endif
void display_sysdump_header(void)
{
#ifdef CONFIG_VIDEO_SPRD
	logo_display(LOGO_NORMAL_POWER, BACKLIGHT_ON, LCD_ON);
#endif

	led_sysdump_start();
	/* display on screen */
	display_writing_sysdump();
#define CONSOLE_COLOR_RED (0x1f<<11)
#define CONSOLE_COLOR_GREEN 0x07e0
	sysdump_lcd_printf("\nReset mode: %s\n\n",GET_RST_MODE(check_dump_status_result.reset_mode));
}
unsigned long get_minidump_info_paddr(struct dumpdb_header *header_g, struct sysdump_info *info_g)
{
	struct minidump_info *minidump_infop;
	/* check header magic */
	if(memcmp(MINIDUMP_MAGIC, info_g->sprd_minidump_info.magic, strlen(MINIDUMP_MAGIC))){
		dump_loge("no minidump magic. do nothing\n");
		sysdump_lcd_printf("no valid address, no info display\n");
		return 0;
	} else {
		minidump_infop = info_g->sprd_minidump_info.minidump_info_paddr;
		dump_logd("%s: minidump_info paddr : 0x%llx\n", __FUNCTION__, info_g->sprd_minidump_info.minidump_info_paddr);
		dump_logd("%s: minidump_info size : 0x%x\n", __FUNCTION__, info_g->sprd_minidump_info.minidump_info_size);
		return minidump_infop;
	}
}
int get_minidump_info_size(struct dumpdb_header *header_g, struct sysdump_info *info_g)
{
	int size;

	/* check header magic */
	if(memcmp(MINIDUMP_MAGIC, info_g->sprd_minidump_info.magic, strlen(MINIDUMP_MAGIC))){
		dump_loge("no minidump magic. do nothing\n");
		return -1;
	} else {
		size = info_g->sprd_minidump_info.minidump_info_size;
		return size;
	}
}
int check_header_magic_kernel(struct minidump_info *minidump_infop)
{
	/*	check minidump info data kernel  magic ,make sure it is valid	*/
	if(memcmp(KERNEL_MAGIC, minidump_infop->kernel_magic, strlen(KERNEL_MAGIC))){
		/*	no magic means ddr data is corruption  ,do nothing	*/
		dump_loge("no  kerenl magic ,minidump indo is no valid .do nothing\n");
		sysdump_lcd_printf("no valid data, no info display\n");
		return -1;
	} else {
		return 0;
	}
}
static void wait_for_keypress(void)
{
	int key_code;

	do {
		udelay(50 * 1000);
		key_code = board_key_scan();
		if (key_code == KEY_VOLUMEDOWN || key_code == KEY_VOLUMEUP || key_code == KEY_HOME)
			break;
	} while (1);
	dump_logd("Pressed key: %d\n", key_code);
	sysdump_lcd_printf("Pressed key: %d\n", key_code);
}

int init_mmc_fat(int *fs_type)
{
	struct mmc *mmc;
	block_dev_desc_t *dev_desc = NULL;
	int ret;

	*fs_type = FS_INVALID;
	dump_logd("init_mmc_fat\n");
	mmc = board_sd_init();
	if(mmc == NULL){
		dump_logd("no mmc block device found\n");
		return -1;
	}
	dev_desc = &mmc->block_dev;
	if(dev_desc==NULL){
		dump_logd("no mmc block device found\n");
		return -1;
	}

	if (dev_desc ->part_type != PART_TYPE_DOS){
		dump_logd(" no part_type_dos!\n");
		return -1;
	}
	ret = fat_register_device(dev_desc, 1);
	if (ret == 0) {
		ret = file_fat_detectfs();
		if(ret) {
			dump_logd("detect fs fat failed\n");
			return -1;
		}
		*fs_type = FS_FAT32;
		return 0;
	}
	dump_logd("Fat register fail. Try exFat. \n");

	ret = exfat_register_device(dev_desc, 1);
	if(ret < 0) {
		dump_logd("exFat register fail %d.\n", ret);
		return -1;
	}

	ret = file_exfat_detectfs();
	if(ret) {
		dump_logd("Detect fs exfat failed\n");
		return -1;
	}
	*fs_type = FS_EXFAT;
	return 0;
}

void write_mem_to_mmc(char *path, char *filename, int fs_type,
		void *memaddr, unsigned long memsize)
{
	int ret = 0;
	loff_t actwrite = 0;
	if (path) {
		do {} while (0); /* TODO: jianjun.he */
	}

	dump_logd("writing "LLX" bytes to sd file %s\n",
			memsize, filename);

	sysdump_lcd_printf("writing "LLX" bytes to sd file %s\n",
			memsize, filename);

	if (fs_type==FS_FAT32){
		ret = file_fat_write(filename, memaddr, 0, memsize, &actwrite);
		dump_logd("have write "LLX" bytes to the file\n",actwrite);
		if(ret >= 0 && actwrite > 0){
			//actwrite = 0;// may cause sprd_dump_mem_num to be 0
			ret = fat_size(filename, &actwrite);
			dump_logd("fat_size is "LLX" bytes\n",actwrite);
			if(ret < 0 || actwrite == 0){
				dump_logd("fat_size is 0,so try write again");
				ret = file_fat_write(filename, memaddr, 0, memsize, &actwrite);
			}
		}
		else{
			dump_logd("file_fat_write fail,try write again,actwrite="LLX"\n",actwrite);
			ret = file_fat_write(filename, memaddr, 0, memsize, &actwrite);
		}
	}
	else if (fs_type==FS_EXFAT)
		ret = file_exfat_write(filename, memaddr, memsize);
	else
		ret = -1;

	if (ret < 0) {
		dump_logd("write file %s to SD Card error, and ret = %d !!!\n", filename, ret);
		sysdump_lcd_printf("write file %s to SD Card error, and ret = %d !!!\n", filename, ret);
		return;
	}

	return;
}
/* To copy struct sysdump_mem all items to another */
void copy_sysdump_mem_struct(struct sysdump_mem *dest, struct sysdump_mem *src)
{
	dest->paddr = src->paddr;
	dest->vaddr = src->vaddr;
	dest->size = src->size;
	dest->soff = src->soff;
	dest->type = src->type;
}
/* sort the mem list by paddr */
void sort_mem_list(struct sysdump_mem *mem_list, int mem_num)
{
	struct sysdump_mem temp;
	int i,j;
	for (i = 0; i < mem_num -1; i++) {
		for(j = 0; j < mem_num - 1 - i; j++){
			if (mem_list[j].paddr > mem_list[j + 1].paddr) {
				copy_sysdump_mem_struct(&temp, &mem_list[j]);
				copy_sysdump_mem_struct(&mem_list[j], &mem_list[j + 1]);
				copy_sysdump_mem_struct(&mem_list[j + 1], &temp);
			}
		}
	}
}
/* Get the memory block belong to kernel(linux_memory) in sysdump_mem	*/
void get_elfhdr_ptload_mem(void)
{
	int i,j;
	int k = 0;
	struct sysdump_mem *dump_mem = dump_input_contents_info.sprd_dump_mem;
	struct sysdump_mem *ptload_mem = dump_input_contents_info.sprd_ptload_mem;
	int dump_mem_num = dump_input_contents_info.sprd_dump_mem_num;
	for(i = 0; i < dump_mem_num; i++){
		dump_logd("sprd_dump_mem[%d].paddr is "LLX"\n", i, dump_mem[i].paddr);
		for(j = 0; j < linux_mem_num_g; j++ ){
			dump_logd("linux_memory[%d].paddr is "LLX" paddr+size is "LLX"\n", j, linux_memory[j].addr, linux_memory[j].addr + linux_memory[j].size);
			if((dump_mem[i].paddr >= linux_memory[j].addr) && (dump_mem[i].paddr <= linux_memory[j].addr + linux_memory[j].size)){
				/*	the dump_mem region is belong to linux memory ,mark as elfhdr ptload */
				ptload_mem[k].paddr = dump_mem[i].paddr;
				ptload_mem[k].vaddr = dump_mem[i].vaddr;
				ptload_mem[k].size = dump_mem[i].size;
				dump_logd("elfhdr pt_load memory[%d] addr = "LLX", size = "LLX" !!!\n", k, ptload_mem[k].paddr, ptload_mem[k].size);
				k++;
			}
		}
	}
	dump_input_contents_info.sprd_ptload_mem_num = k;
	return ;
}
size_t get_elfhdr_size(int nphdr)
{
	size_t elfhdr_len;

	elfhdr_len = sizeof(struct elfhdr) +
		(nphdr + 1) * sizeof(struct elf_phdr);
#if SETUP_NOTE
	elfhdr_len += ((sizeof(struct elf_note)) +
			roundup(sizeof(CORE_STR), 4)) * 3 +
		roundup(sizeof(struct elf_prstatus), 4) +
		roundup(sizeof(struct elf_prpsinfo), 4) +
		roundup(sizeof(struct task_struct), 4);
#endif
	elfhdr_len = PAGE_ALIGN(elfhdr_len);
	return elfhdr_len;
}

#if SETUP_NOTE
static int notesize(struct memelfnote *en)
{
	int sz;

	sz = sizeof(struct elf_note);
	sz += roundup((strlen(en->name) + 1), 4);
	sz += roundup(en->datasz, 4);

	return sz;
}

static char *storenote(struct memelfnote *men, char *bufp)
{
	struct elf_note en;

#define DUMP_WRITE(addr,nr) do { memcpy(bufp,addr,nr); bufp += nr; } while(0)

	en.n_namesz = strlen(men->name) + 1;
	en.n_descsz = men->datasz;
	en.n_type = men->type;

	DUMP_WRITE(&en, sizeof(en));
	DUMP_WRITE(men->name, en.n_namesz);

	/* XXX - cast from long long to long to avoid need for libgcc.a */
	bufp = (char*) roundup((unsigned long)bufp,4);
	DUMP_WRITE(men->data, men->datasz);
	bufp = (char*) roundup((unsigned long)bufp,4);

#undef DUMP_WRITE

	return bufp;
}

#endif
static void sysdump_fill_core_hdr(struct pt_regs *regs,
		struct sysdump_mem *sysmem, int mem_num,
		char *bufp, int dataoff)
{
	struct elf_phdr *nhdr, *phdr;
	struct elfhdr *elf;
	struct memelfnote notes[3];
	off_t offset = 0;
	Elf_Off f_offset = dataoff;
	int i;
	/* setup ELF header */
	elf = (struct elfhdr *) bufp;
	bufp += sizeof(struct elfhdr);
	offset += sizeof(struct elfhdr);
	memcpy(elf->e_ident, ELFMAG, SELFMAG);
	elf->e_ident[EI_CLASS]	= ELF_CLASS;
	elf->e_ident[EI_DATA]	= ELF_DATA;
	elf->e_ident[EI_VERSION]= EV_CURRENT;
	elf->e_ident[EI_OSABI] = ELF_OSABI;
	memset(elf->e_ident+EI_PAD, 0, EI_NIDENT-EI_PAD);
	elf->e_type	= ET_CORE;
	elf->e_machine	= ELF_ARCH;
	elf->e_version	= EV_CURRENT;
	elf->e_entry	= 0;
	elf->e_phoff	= sizeof(struct elfhdr);
	elf->e_shoff	= 0;
	elf->e_flags	= ELF_CORE_EFLAGS;
	elf->e_ehsize	= sizeof(struct elfhdr);
	elf->e_phentsize= sizeof(struct elf_phdr);
	elf->e_phnum	= mem_num + 1;
	elf->e_shentsize= 0;
	elf->e_shnum	= 0;
	elf->e_shstrndx	= 0;

	/* setup ELF PT_NOTE program header */
	nhdr = (struct elf_phdr *) bufp;
	bufp += sizeof(struct elf_phdr);
	offset += sizeof(struct elf_phdr);
	nhdr->p_type	= PT_NOTE;
	nhdr->p_offset	= 0;
	nhdr->p_vaddr	= 0;
	nhdr->p_paddr	= 0;
	nhdr->p_filesz	= 0;
	if (is_sysdump_boot_mode(dump_rst_mode_g))
		nhdr->p_memsz = 0;
	nhdr->p_flags	= 0;
	nhdr->p_align	= 0;

	/* setup ELF PT_LOAD program header for every area */
	for (i = 0; i < mem_num; i++) {
		phdr = (struct elf_phdr *) bufp;
		bufp += sizeof(struct elf_phdr);
		offset += sizeof(struct elf_phdr);

		phdr->p_type	= PT_LOAD;
		phdr->p_flags	= PF_R|PF_W|PF_X;
		phdr->p_offset	= f_offset;
		phdr->p_vaddr	= sysmem[i].vaddr;
		phdr->p_paddr	= sysmem[i].paddr;
		phdr->p_filesz	= phdr->p_memsz	= sysmem[i].size;
		phdr->p_align	= 0;//PAGE_SIZE;
		f_offset += sysmem[i].size;
	}
#if SETUP_NOTE
	/*
	 * Set up the notes in similar form to SVR4 core dumps made
	 * with info from their /proc.
	 */
	nhdr->p_offset	= offset;

	/* set up the process status */
	notes[0].name = CORE_STR;
	notes[0].type = NT_PRSTATUS;
	notes[0].datasz = sizeof(struct elf_prstatus);
	notes[0].data = &prstatus;

	memset(&prstatus, 0, sizeof(struct elf_prstatus));

	nhdr->p_filesz	= notesize(&notes[0]);
	bufp = storenote(&notes[0], bufp);

	/* set up the process info */
	notes[1].name	= CORE_STR;
	notes[1].type	= NT_PRPSINFO;
	notes[1].datasz	= sizeof(struct elf_prpsinfo);
	notes[1].data	= &prpsinfo;

	memset(&prpsinfo, 0, sizeof(struct elf_prpsinfo));

	strcpy(prpsinfo.pr_fname, "vmlinux");

	nhdr->p_filesz	+= notesize(&notes[1]);
	bufp = storenote(&notes[1], bufp);

	/* set up the task structure */
	notes[2].name	= CORE_STR;
	notes[2].type	= NT_TASKSTRUCT;
	notes[2].datasz	= sizeof(struct task_struct);
	notes[2].data	= current;

	printf("%s: data size is %d, data addr is %p",__func__,notes[2].datasz,notes[2].data);

	nhdr->p_filesz	+= notesize(&notes[2]);
	bufp = storenote(&notes[2], bufp);
#endif
	if (nhdr->p_memsz == 0)
		nhdr->p_offset  = 0;
	else
		nhdr->p_offset  = offset;

	return;
}


#ifdef CONFIG_NAND_BOOT
/*Copy the data saved in nand flash to ram*/
int read_nand_to_ram( struct mtd_info *mtd, loff_t paddr, unsigned int size, unsigned char *buf)
{
	int ret = 0;
	unsigned int retlen = 0;
	loff_t read_addr = 0;
	unsigned char *read_buf = NULL;
	unsigned int readsize = 0;

	dump_logd("%s, read 0x%.8x:0x%.8x buf: 0x%.8x\n", __func__, (unsigned int)paddr, size, buf);
	for(read_addr = paddr, read_buf = buf; read_addr < (paddr + size); read_addr += readsize, read_buf += readsize) {
		readsize = (paddr + size - read_addr) > mtd->erasesize ? mtd->erasesize : (paddr + size - read_addr);
		if(mtd->_block_isbad(mtd, read_addr) == 1) {//if met bad block, we just fill it with 0x5a
			memset(read_buf, 0x5a, readsize);
			continue;
		}

		ret = mtd->_read(mtd, read_addr, readsize, &retlen, read_buf);
		if(ret != 0 && retlen != readsize) {
			printf("%s, read addr: 0x%.8x len: 0x%.8x 's value error, ret: %d, retlen: 0x%.8x\n",\
					__func__, (unsigned int)read_addr, readsize, ret, retlen);
			sysdump_lcd_printf("\nRead nand flash 0x%.8x error, you can dump it use download tools again!\n", read_addr);
			break;
		}
	}
	return ret;
}

/*dump the data saved in nand flash to sdcard when needed*/
void mtd_dump(int fs_type)
{
	int ret = 0;
	unsigned int write_len = 0, write_addr = 0;
	char *buf = NULL;
	unsigned int part_len = 0x8000000;//The size of each ubipac-part file
	int loop = 0;
	char fname[72];
	struct mtd_info *mtd = NULL;

	buf = CONFIG_SYS_SDRAM_BASE;//After dump memory to sdcard, we suppose the whole memory except u-boot used are avaliable.
	mtd = get_mtd_device_nm(UBIPAC_PART);
	if(mtd == NULL) {
		printf("Can't get the mtd part: %s\n", UBIPAC_PART);
		return;
	}

	dump_logd("Begin to dump 0x%.8x ubipac to sdcard!\n", mtd->size);
	for(write_addr = 0; write_addr < mtd->size; write_addr += write_len, loop++)
	{
		write_len = (mtd->size - write_addr) > part_len ? part_len : (mtd->size - write_addr);
		dump_logd("begin to read 0x%.8x value to ubipac%d\n", write_len, loop);
		memset(buf, 0, write_len);
		ret = read_nand_to_ram(mtd, (loff_t)(write_addr), write_len, buf);
		if(ret != 0) {
			printf("%s, read ubipac%d error, the ret is %d\n", __func__, loop, ret);
			break;
		}
		dump_logd("read ubipac%d end\n", loop);

		memset(fname, 0, 72);
		sprintf(fname, "ubipac%d", loop);
		write_mem_to_mmc(NULL, fname, fs_type, buf, write_len);
		dump_logd("write ubipac%d end\n", loop);
	}
	put_mtd_device(mtd);
}
#endif

unsigned char *get_dt_addr(void)
{
	unsigned char *dt_addr = DT_ADR;
	boot_img_hdr *hdr = (void *)raw_header;
	if (1 == _get_kernel_ramdisk_dt_offset(hdr, "boot")) {
		if( !hdr->ramdisk_size )
			load_fixup_dt_img("dtb", &dt_addr);
		else
			load_fixup_dt_img("boot", &dt_addr);
#ifdef CONFIG_OF_LIBFDT_OVERLAY
		if (BOOT_HEADER_VERSION_ONE == hdr->header_version)
			merge_dtbo(dt_addr);
		else if (BOOT_HEADER_VERSION_TWO == hdr->header_version) {
			struct boot_img_hdr_v1 *hdr_v1 = (struct boot_img_hdr_v1 *)(hdr + 1);
			if (hdr_v1->recovery_dtbo_size)
				load_and_merge_dtbo("boot", dt_addr);
			else
				merge_dtbo(dt_addr);
		}
#endif
	}
	return dt_addr;
}
static int check_dts_reserved_mem_node(unsigned char *fdt_blob)
{
	int nodeoffset = fdt_path_offset(fdt_blob, "/reserved-memory");

	dump_logd("reserved-memory nodeoffset = %d\n", nodeoffset);

	return nodeoffset;
}

static int get_dts_version(unsigned char *fdt_blob, int nodeoffset)
{
	__be32 *list = NULL;
	int lenp, version;

	list = fdt_getprop(fdt_blob, nodeoffset, "version", &lenp);
	if (list == NULL) {
		dump_logd("no version property in sysdump node.\n");
		version = 0;
	} else {
		version = fdt_size_to_cpu(*list);
	}

	dump_logd("dts sysdump version is 0x%x.\n", version);
	return version;
}

static int check_dts_sysdump_node(unsigned char *fdt_blob)
{
	int nodeoffset = fdt_path_offset(fdt_blob, "/sprd-sysdump");

	dump_logd("sysdump nodeoffset = %d\n", nodeoffset);
	return nodeoffset;
}

int init_dt_info(void)
{
	dt_info.dt_addr = get_dt_addr();
	dt_info.nodeoffset = check_dts_sysdump_node(dt_info.dt_addr);
	if (dt_info.nodeoffset < 0) {
		dump_logd("ERROR: device tree must have /sprd-sysdump node %s !!!\n", fdt_strerror(dt_info.nodeoffset));
		dt_info.dt_fail = 1;
	}

	if(!dt_info.dt_fail)
		dt_info.dts_version = get_dts_version(dt_info.dt_addr, dt_info.nodeoffset);

	if (!dt_info.dt_fail) {
		dt_info.ofs_remem = check_dts_reserved_mem_node(dt_info.dt_addr);
		if (dt_info.ofs_remem < 0) {
			dump_logd("ERROR: device tree must have /reserved-memory node %s.\n", fdt_strerror(dt_info.ofs_remem));
			return ERROR_FNISH;
		}
	}
	return 0;
}
void get_sprd_dump_size_auto(void)
{
	int i;

	for(i=0; i<dump_input_contents_info.sprd_dump_mem_num; i++) {
		dump_input_contents_info.mem_total_size += dump_input_contents_info.sprd_dump_mem[i].size;
	}
	dump_input_contents_info.file_total_size = dump_input_contents_info.mem_total_size + dump_input_contents_info.elfhdr_size;
#ifdef CONFIG_X86
	dump_logd("sysdump mem total size is 0x%llx !!!\n", dump_input_contents_info.mem_total_size);
	dump_logd("sysdump file total size is 0x%llx !!!\n", dump_input_contents_info.file_total_size);
#else
	dump_logd("sysdump mem total size is "LLX" !!!\n", dump_input_contents_info.mem_total_size);
	dump_logd("sysdump file total size is "LLX" !!!\n", dump_input_contents_info.file_total_size);
#endif
	return ;
}

static int fill_mem_from_dts(unsigned char *fdt_blob, int nodeoffset, const char *name, struct sysdump_mem *sprd_dump_mem)
{
	int i = 0;
	int lenp, size, phandle, lookup;
	unsigned long *ptr = NULL, *ptr_end = NULL;

	dump_logd("Now read dts %s property in the sysdump node !!!\n", name);
	ptr = fdt_getprop(fdt_blob, nodeoffset, name, &lenp);
	__be32 *list = fdt_getprop(fdt_blob, nodeoffset, name, &size);
	if (list == NULL) {
		dump_logd("ERROR: no %s property !!!\n", name);
		return 0;
	}
	__be32 *list_end = list + size / sizeof(*list);

	while (list < list_end) {
		phandle = be32_to_cpup(list++);
		lookup = fdt_node_offset_by_phandle(fdt_blob, phandle);

		ptr = fdt_getprop(fdt_blob, lookup, "reg", &lenp);
		if (ptr == NULL) {
			dump_logd("ERROR: no reg in %s property !!!\n", name);
			return 0;
		}
		else {
			ptr_end = ptr + lenp / (sizeof(SYSDUMP_LONG));
			while (ptr < ptr_end) {
				sprd_dump_mem[i].paddr = fdt_addr_to_cpu (*ptr ++);
#ifdef CONFIG_X86
				sprd_dump_mem[i].paddr = (sprd_dump_mem[i].paddr<<32) | fdt_addr_to_cpu(*ptr ++);
#endif
				sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
				sprd_dump_mem[i].size  = fdt_size_to_cpu (*ptr ++);
#ifdef CONFIG_X86
				sprd_dump_mem[i].size  = (sprd_dump_mem[i].size<<32) | fdt_addr_to_cpu(*ptr ++);
#endif
				sprd_dump_mem[i].soff  = 0xffffffff;
				sprd_dump_mem[i].type  = SYSDUMP_RAM;
#ifdef CONFIG_X86
				dump_logd("sprd_dump_mem[%d].paddr is 0x%llx\n", i, sprd_dump_mem[i].paddr);
				dump_logd("sprd_dump_mem[%d].size  is 0x%llx\n", i, sprd_dump_mem[i].size);
#else
				dump_logd("sprd_dump_mem[%d].paddr is 0x%lx\n", i, sprd_dump_mem[i].paddr);
				dump_logd("sprd_dump_mem[%d].size  is 0x%lx\n", i, sprd_dump_mem[i].size);
#endif
				i++;
			}
		}
	}

	dump_logd(" the %s memory num is %d\n", name, i);
	return i;
}

/* this function only support FAT filesysdump Now*/
static int sysdump_cyclic_storage(int fs_type, unsigned long long dump_size)
{
	char path[72] = {0};
	char path_rename[72] = {0};
	int i, j, ret = 0;
	int mod = 0;
	unsigned char key_code = 0;
	bool delete_flag = false;
	bool nospace_flag = false;
	dir_entry *dentptr = NULL;
	int ex_ret = -1;

	/*setp 1. check available space: delete or format*/
	if (fs_type == FS_FAT32)
		mod = fat_checksys(dump_size);
	if (fs_type == FS_EXFAT){
		mod = exfat_checksys(dump_size);
	}
	if (mod & FSNOSPACE) {
		nospace_flag = true;
		for (i = 1; i <= SYSDUMP_FOLDER_NUM; i++) {
			sprintf(path, SYSDUMP_FOLDER_NAME"/%d", i);
			path[strlen(path)] = '\0';
			if (fs_type == FS_FAT32)
				dentptr = check_folder_flag(path);
			if (fs_type == FS_EXFAT)
				ex_ret = dir_exfat_check(path);
			if(dentptr == NULL && ex_ret < 0)
				break;
		}
		if (i != 1 ) {
			for(j = i; j != 1;) {
				sprintf(path, SYSDUMP_FOLDER_NAME"/%d", --j);
				path[strlen(path)] = '\0';
				printf("j=%d, path=%s\n", j, path);
				if (fs_type == FS_FAT32)
					ret = delete_folder(path);
				if (fs_type == FS_EXFAT)
					ret = dir_exfat_remove(path);
				if(ret != 0) {
					dump_logd("ERROR: delete files or folder failed !!!\n");
					return -1;
				}
				if (fs_type == FS_FAT32)
					mod = fat_checksys(dump_size);
				if (fs_type == FS_EXFAT)
					mod = exfat_checksys(dump_size);
				if (!(mod & FSNOSPACE)) {
					dump_logd(" fat_checksys return 0x%x !!!\n", mod);
					nospace_flag = false;
					break;
				}
			}
		}
		if (nospace_flag) {
			sysdump_lcd_printf("\nSD Card have not enough space !!!");
			sysdump_lcd_printf("\npress volumeup to format SD Card !!!\notherwise press volumedown to skip sysdump to sdcard!!!\n");
			dump_logd("\nSD Card have not enough space !!!\n");
			dump_logd("\npress volumeup to format SD Card !!!\notherwise press volumedown to skip sysdump to sdcard!!!\n");
			do {
				udelay(50 * 1000);
				key_code = board_key_scan();
				if (key_code == KEY_VOLUMEUP) {
					if (fs_type == FS_FAT32) {
						dump_logd("Key: KEY_VOLUMEUP , try to fat_format  !!!\n");
						fat_format();
						break;
					}else if (fs_type == FS_EXFAT){
						dump_logd("Key: KEY_VOLUMEUP , try to fat_format  !!!\n");
						exfat_format();
					}else{
						return -1;
					}
				} else if (key_code == KEY_VOLUMEDOWN) {
					dump_logd("Key: KEY_VOLUMEDOWN , try to skip sysdump to sdcard  !!!\n");
					check_dump_status_result.dump_to_sd_fail = 1;
					return -1;
				}
			} while (1);
		}
	}
	/*step 2. enter /ylog/sysdump*/
	if (fs_type == FS_FAT32) {
		if(do_new_folder(SYSDUMP_FOLDER_NAME)) {
			dump_logd("ERROR: creat %s folder failed !!!\n", SYSDUMP_FOLDER_NAME);
			return -1;
		}
	}
	if (fs_type == FS_EXFAT) {
		if(dir_exfat_create(SYSDUMP_FOLDER_NAME)) {
			dump_logd("ERROR: creat %s folder failed !!!\n", SYSDUMP_FOLDER_NAME);
			return -1;
		}
	}

	/*step 3. check existed folder*/
	for (i = 1; i <= SYSDUMP_FOLDER_NUM; ++i) {
		sprintf(path, SYSDUMP_FOLDER_NAME"/%d", i);
		path[strlen(path)] = '\0';
		if (fs_type == FS_FAT32)
			dentptr = check_folder_flag(path);
		if (fs_type == FS_EXFAT)
			ex_ret = dir_exfat_check(path);
		if(dentptr == NULL && ex_ret < 0)
			break;
	}
	printf("i=%d\n", i);
	/*setp 4. delete folder greater than set number*/
	if (i > SYSDUMP_FOLDER_NUM) {
		dump_logd("there existed %d history log !!!\n", SYSDUMP_FOLDER_NUM);
		i --;
		sprintf(path, SYSDUMP_FOLDER_NAME"/%d", i);
		path[strlen(path)] = '\0';
		if (fs_type == FS_FAT32)
			ret = delete_folder(path);
		if (fs_type == FS_EXFAT)
			ret = dir_exfat_remove(path);
		if(ret != 0)
			dump_logd("Error: delete files or folder\n");
	}

	/*setp 5. rename folder*/
	for(j = i - 1; j > 0 && i != 1; j = j - 2) {
		sprintf(path, SYSDUMP_FOLDER_NAME"/%d", j++);
		path[strlen(path)] = '\0';
		sprintf(path_rename, SYSDUMP_FOLDER_NAME"/%d", j);
		path_rename[strlen(path_rename)] ='\0';
		dump_logd("rename folder from %s to %s !!!\n", path, path_rename);
		if (fs_type == FS_FAT32)
			ret = rename_folder(path, path_rename);
		if (fs_type == FS_EXFAT)
			ret = dir_exfat_rename(path, path_rename);
		if (ret != 0) {
			dump_logd("ERROR: delete files or folder failed !!!\n");
			break;
		}
	}

	/*setp 6. create a new folder "1"*/
	sprintf(path, SYSDUMP_FOLDER_NAME"/%d", 1);
	path[strlen(path)] = '\0';
	dump_logd("create folder 1 !!!\n");
	if (fs_type == FS_FAT32)
		ret = do_new_folder(path);
	if (fs_type == FS_EXFAT)
		ret = dir_exfat_create(path);
	if (ret != 0) {
		dump_logd("ERROR: creat %s folder failed !!!\n", path);
		return -1;
	}

	return 0;
}

static void reorder_reserved_memory_by_addr(struct sysdump_memory *memArray, int size)
{
	int i, j, min;
	struct sysdump_memory temp;

	for (i=0; i<size; i++) {
		min = i;
		for (j=i+1; j<size; j++) {
			if (memArray[min].addr > memArray[j].addr) {
				min = j;
			}
		}

		if (min != i) {
			temp.addr = memArray[min].addr;
			temp.size = memArray[min].size;
			memArray[min].addr = memArray[i].addr;
			memArray[min].size = memArray[i].size;
			memArray[i].addr = temp.addr;
			memArray[i].size = temp.size;
		}
	}

	return;
}

#ifdef CONFIG_X86
static u32 e820_map_auto_detect(struct e820entry *entries)
{
	u32 e820_entries_detect = 0;
	int i = 0;
	ddr_info_t* ddr_info = get_ddr_range();
	e820_entries_detect = ddr_info->section_number;

	entries->addr = U32_T_U64(ddr_info->sec_info[0].start_address_high,ddr_info->sec_info[0].start_address_low)+VMM_RESERVE_SIZE;
	entries->size  = U32_T_U64(ddr_info->sec_info[0].end_address_high,ddr_info->sec_info[0].end_address_low)-entries->addr;
	entries->type  = E820_RAM;
	dump_logd("e820 entry addr = 0x%08llx, entry size = 0x%llx !!!\n", entries->addr, entries->size);
	entries++;

	for (i = 1; i < e820_entries_detect; i++) {
		entries->addr = U32_T_U64(ddr_info->sec_info[i].start_address_high,ddr_info->sec_info[i].start_address_low);
		entries->size  = U32_T_U64(ddr_info->sec_info[i].end_address_high,ddr_info->sec_info[i].end_address_low)-entries->addr;
		entries->type  = E820_RAM;
		dump_logd("e820 entry addr = 0x%08llx, entry size = 0x%llx !!!\n", entries->addr, entries->size);
		entries++;
	}

	dump_logd("e820 total num is %d !!!\n", e820_entries_detect);
	return e820_entries_detect;
}
#endif
/* TODO: Double channel should be attention */
static int get_total_dump_memory(void)
{
	int k, i = 0;
	struct sysdump_mem *sprd_dump_mem = dump_input_contents_info.sprd_dump_mem;

#ifdef CONFIG_X86
	struct e820entry x86_entries[5] = {0};
	linux_mem_num_g = e820_map_auto_detect(x86_entries);

	if (VMM_RESERVE_SIZE) {
		dump_logd("dump vmm memory region !!!\n");
		sprd_dump_mem[0].paddr = 0;
		sprd_dump_mem[0].vaddr = 0;
		sprd_dump_mem[0].size  = VMM_RESERVE_SIZE;
		sprd_dump_mem[0].soff  = 0xffffffff;
		sprd_dump_mem[0].type  = SYSDUMP_RAM;
		i ++;
	}

	for (k = 0; k < linux_mem_num_g; k++) {
		sprd_dump_mem[i].paddr = x86_entries[k].addr;
		sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
		sprd_dump_mem[i].size = x86_entries[k].size + 1;
		sprd_dump_mem[i].soff  = 0xffffffff;
		sprd_dump_mem[i].type  = SYSDUMP_RAM;
		i ++;
	}

	linux_mem_num_g = i;
	dump_logd("--	here, we dump all mem , so init linux_memory & sprd_ptload_mem as same data	--!!\n");
	for (k = 0; k < linux_mem_num_g; k++) {
		linux_memory[k].addr = sprd_dump_mem[k].paddr;
		linux_memory[k].size = sprd_dump_mem[k].size;
		dump_logd("linux memory addr = 0x%llx, size = 0x%llx !!!\n",linux_memory[k].addr, linux_memory[k].size);
	}
#else
	phys_addr_t ddr_base = CONFIG_SYS_SDRAM_BASE;
	phys_size_t ddr_size = get_real_ram_size();

	sprd_dump_mem[0].paddr = ddr_base;
	sprd_dump_mem[0].vaddr =  __va(sprd_dump_mem[i].paddr);
	sprd_dump_mem[0].size = ddr_size;
	sprd_dump_mem[0].soff  = 0xffffffff;
	sprd_dump_mem[0].type  = SYSDUMP_RAM;

	i ++;
	linux_mem_num_g = i;
	dump_logd("--	here, we dump all mem , so init linux_memory & sprd_ptload_mem as same data	--!!\n");
	for (k = 0; k < linux_mem_num_g; k++) {
		linux_memory[k].addr = sprd_dump_mem[k].paddr;
		linux_memory[k].size = sprd_dump_mem[k].size;
		dump_logd("linux memory addr = 0x%llx, size = 0x%llx !!!\n",linux_memory[k].addr, linux_memory[k].size);
	}
#endif

	return linux_mem_num_g;
}

static int recalculate_kernel_memory(unsigned char *fdt_blob, int nodeoffset, int ofs_remem, int dts_version, struct sysdump_mem *sprd_dump_mem)
{
	char *pStr=NULL;
	char nodename[256];
	struct sysdump_memory *entries = NULL;
	int j = 0, mem_used = 0, i = 0, k, offset, str_len;
	SYSDUMP_LONG maddr, msize, base_addr;
	SYSDUMP_LONG old_addr = 0, old_size=0;

	/* get linux memory region */
#ifdef CONFIG_X86
	struct e820entry x86_entries[5] = {0};

	if (dts_version == 0xa1)
		linux_mem_num_g = e820_map_auto_detect(x86_entries);
	for (k = 0; k < linux_mem_num_g; k++) {
		linux_memory[k].addr = x86_entries[k].addr;
		linux_memory[k].size = x86_entries[k].size;
		dump_logd("linux memory addr = 0x%llx, size = 0x%llx !!!\n", linux_memory[k].addr, linux_memory[k].size);
	}
#else
	struct sysdump_mem arm_entries[5] = {0};

	linux_mem_num_g = fill_mem_from_dts(fdt_blob, nodeoffset, "memory-region", arm_entries);
	for (k = 0; k < linux_mem_num_g; k++) {
		linux_memory[k].addr = arm_entries[k].paddr;
		linux_memory[k].size = arm_entries[k].size - 1;
		dump_logd("linux memory addr = "LLX", size = "LLX"!!!\n", linux_memory[k].addr, linux_memory[k].size);
	}
#endif

	/* get linux reserved-memory region */
	for (offset = fdt_first_subnode(fdt_blob, ofs_remem); offset >= 0; offset = fdt_next_subnode(fdt_blob, offset)) {

		sprintf(nodename, "%s", fdt_get_name(fdt_blob, offset, NULL));
		str_len = strlen(nodename);
		nodename[str_len] = '\0';
		pStr = strstr(nodename, "sysdump-uboot");
		if (pStr) {
			dump_logd("find sysdump-uboot reserved memory\n" );
			continue;
		}
		fdt_get_addr_size(fdt_blob, offset, "reg", &maddr, &msize);
		reserved_memory[reserved_mem_num_g].addr = maddr;
		reserved_memory[reserved_mem_num_g].size = msize;
#ifdef CONFIG_X86
		//	dump_logd("reserved-memory addr is %llx\n", reserved_memory[reserved_mem_num_g].addr);
		//	dump_logd("reserved-memory size is %llx\n", reserved_memory[reserved_mem_num_g].size);
#else
		//	dump_logd("reserved-memory addr is %lx\n", reserved_memory[reserved_mem_num_g].addr);
		//	dump_logd("reserved-memory size is %lx\n", reserved_memory[reserved_mem_num_g].size);
#endif
		reserved_mem_num_g++;
	}
	dump_logd("reserved-memory num is %d !!!\n", reserved_mem_num_g);

	/* reorder reserved-memory by addr */
	reorder_reserved_memory_by_addr(reserved_memory, reserved_mem_num_g);

	entries = linux_memory;
#ifdef CONFIG_X86
	base_addr = VMM_RESERVE_SIZE;
#else
	base_addr = linux_memory[0].addr;
#endif
	for (k = 0; k < reserved_mem_num_g; k++) {
		maddr = reserved_memory[k].addr;
		msize = reserved_memory[k].size;
#ifdef CONFIG_X86
		dump_logd("base_addr is 0x%llx\n", base_addr);
		dump_logd("fdt addr is 0x%llx\n", maddr);
		dump_logd("fdt size is 0x%llx\n", msize);
#else
		dump_logd("base_addr is 0x%lx\n", base_addr);
		dump_logd("fdt addr is 0x%lx\n", maddr);
		dump_logd("fdt size is 0x%lx\n", msize);
#endif

		if ((maddr + msize) > (entries->addr + entries->size +1)) {  //next entry
			base_addr = entries->addr + entries->size + 1;
			entries++;  mem_used++;

			if (base_addr == old_addr+old_size) {
				base_addr = entries->addr;
			} else if (base_addr > old_addr+old_size) {
				dump_logd("d1\n");
				sprd_dump_mem[i].paddr = old_addr + old_size;
				sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
				sprd_dump_mem[i].size  = base_addr - sprd_dump_mem[i].paddr;
				sprd_dump_mem[i].soff  = 0xffffffff;
				sprd_dump_mem[i].type  = SYSDUMP_RAM;
				base_addr = entries->addr;
				i++;
			}

			if(maddr == base_addr) {
				base_addr += msize;
			} else if (maddr > base_addr) {
				dump_logd("d2\n");
				if (maddr <= (entries->size + 1)) {
					sprd_dump_mem[i].paddr = base_addr;
					sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
					sprd_dump_mem[i].size  = maddr - base_addr;
					sprd_dump_mem[i].soff  = 0xffffffff;
					sprd_dump_mem[i].type  = SYSDUMP_RAM;
					base_addr = maddr + msize;
					i++;
				} else {
					sprd_dump_mem[i].paddr = base_addr;
					sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
					sprd_dump_mem[i].size  = entries->addr + entries->size - base_addr + 1;
					sprd_dump_mem[i].soff  = 0xffffffff;
					sprd_dump_mem[i].type  = SYSDUMP_RAM;
					i++;
					entries++;
					mem_used++;
					base_addr = entries->addr;
				}
			}
		} else {   //this entry
			if (maddr == base_addr) {
				base_addr += msize;
			} else if (maddr > base_addr) {
				dump_logd("d3\n");
				sprd_dump_mem[i].paddr = base_addr;
				sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
				sprd_dump_mem[i].size  = maddr - base_addr;
				sprd_dump_mem[i].soff  = 0xffffffff;
				sprd_dump_mem[i].type  = SYSDUMP_RAM;
				base_addr = maddr + msize;
				i++;
			} else {
				dump_logd("ERROR: maddr < base_addr !!!\n");
				return 0;
			}
		}

		old_addr = maddr;
		old_size = msize;
	}

	if (mem_used <= linux_mem_num_g - 1) {
		for (j=mem_used; j<= linux_mem_num_g - 1; j++) {
			if (j == mem_used) {
				if ((maddr+msize) < (entries->addr + entries->size + 1)) {
					dump_logd("d4\n");
					sprd_dump_mem[i].paddr = maddr+msize;
					sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
					sprd_dump_mem[i].size  = entries->addr + entries->size + 1 - sprd_dump_mem[i].paddr;
					sprd_dump_mem[i].soff  = 0xffffffff;
					sprd_dump_mem[i].type  = SYSDUMP_RAM;
					i++;
				}
				entries++;
			} else {
				dump_logd("d5\n");
				sprd_dump_mem[i].paddr = entries->addr;
				sprd_dump_mem[i].vaddr = __va(sprd_dump_mem[i].paddr);
				sprd_dump_mem[i].size  = entries->size + 1;
				sprd_dump_mem[i].soff  = 0xffffffff;
				sprd_dump_mem[i].type  = SYSDUMP_RAM;
				i++;
				entries++;
			}
		}
	}

	dump_logd(" linux memory need dump %d region !!!\n", i);
	return i;
}

#ifdef CONFIG_ARM
static int fill_dump_mem_auto_arm(void)
{
	unsigned char *fdt_blob = dt_info.dt_addr;
	int nodeoffset = dt_info.nodeoffset;
	int ofs_remem = dt_info.ofs_remem;
	int dts_version = 0;
	int ret = 0, i = 0;
	int arm_dump_mem_num = 0;
	struct sysdump_mem *temp_mem = dump_input_contents_info.sprd_dump_mem;
	/* calculate linux memory region */
	dump_logd("calculate linux memory region !!!\n");
	ret = recalculate_kernel_memory(fdt_blob, nodeoffset, ofs_remem, dts_version, dump_input_contents_info.sprd_dump_mem);
	if (ret == 0)
		dump_logd("ERROR: ARM: linux memory recalculation failed !!!\n");
	else {
		i += ret;
		temp_mem += ret;
	}

	/* calculate specific reserved-memory*/
	dump_logd("read reserved-memory region from sysdump node !!!\n");
	ret = fill_mem_from_dts(fdt_blob, nodeoffset, "memory-region-re", temp_mem);
	if (ret == 0)
		dump_logd("ERROR: ARM: memory-region-re dump failed !!!\n");
	else {
		i += ret;
		temp_mem += ret;
	}

	/* security memory region from kernel dts */
	if (dump_rst_mode_g == CMD_TOS_PANIC_MODE) {
		dump_logd("read security memory region from sysdump node !!!\n");
		ret = fill_mem_from_dts(fdt_blob, nodeoffset, "memory-region-se", temp_mem);
		if (ret == 0)
			dump_logd("ERROR: ARM: memory-region-se dump failed !!!\n");
		else {
			i += ret;
			temp_mem += ret;
		}
	}

	arm_dump_mem_num = i;
	dump_logd("auto arm_dump_mem_num is %d\n", arm_dump_mem_num);

	for (i = 0; i < arm_dump_mem_num; i++) {
		dump_logd("auto arm_dump_mem[%d].paddr is "LLX"\n", i, dump_input_contents_info.sprd_dump_mem[i].paddr);
		dump_logd("auto arm_dump_mem[%d].size  is "LLX"\n", i, dump_input_contents_info.sprd_dump_mem[i].size);
	}

	return arm_dump_mem_num;
}
#endif

/* i: memory region form dts */
static void write_to_mmc(char *path, char *filename, int fs_type,
		void *memaddr, struct sysdump_mem *mem, int i)
{
#ifdef CONFIG_RAMDUMP_NO_SPLIT
	sprintf(filename,
			SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_"LLX"-"LLX"_dump.lst",
			i + 1, mem[i].paddr, mem[i].paddr+mem[i].size -1);
	write_mem_to_mmc(path, filename, fs_type, memaddr, mem[i].size);
#else
	int j;
	if (mem[i].size <= SZ_8M) {
		sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_"LLX,
				i + 1,mem[i].paddr);
		write_mem_to_mmc(path, filename, fs_type, memaddr, mem[i].size);
	} else {
		for (j = 0; j < mem[i].size / SZ_8M; j++) {
			sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_%03d_"LLX,
					i + 1, j, mem[i].paddr+j*SZ_8M);
			write_mem_to_mmc(path, filename, fs_type, memaddr + j*SZ_8M, SZ_8M);
		}
		if (mem[i].size % SZ_8M) {
			sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_%03d_"LLX,
					i + 1, j, mem[i].paddr+j*SZ_8M);
			write_mem_to_mmc(path, filename, fs_type, memaddr + j*SZ_8M, (mem[i].size % SZ_8M));
		}
	}
#endif
}

#ifdef CONFIG_X86
/*
 * i: memory region form dts
 * k: number k block in i
 */
static void write_to_mmc_x86(char *path, char *filename, int fs_type,
		void *memaddr, struct sysdump_mem *mem,
		int i, int k, unsigned long size)
{
	unsigned long long vaddr = mem[i].paddr+k*SYSDUMP_256M;
#ifdef CONFIG_RAMDUMP_NO_SPLIT
	if(check_dump_status_result.dump_to_pc_flag != 1){
		sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_%03d_"LLX"-"LLX"_dump.lst",
				i + 1, k, vaddr, vaddr+size -1);
		write_mem_to_mmc(path, filename, fs_type, memaddr, size);
	} else {
		sprintf(filename, SYSDUMP_CORE_NAME_FMT"_%03d_"LLX"-"LLX"_dump.lst",
				i + 1, k, vaddr, vaddr+size -1);
		send_mem_to_pc(dumpbuf_pc, filename, &pkt_header, (char *)memaddr, (uint64_t)size);
	}
#else
	int j;
	if (mem[i].size <= SZ_8M) {
		if(check_dump_status_result.dump_to_pc_flag != 1){
			sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_"LLX, i + 1, vaddr);
			write_mem_to_mmc(path, filename, fs_type, memaddr, size);
		} else {
			sprintf(filename, SYSDUMP_CORE_NAME_FMT"_"LLX, i + 1, vaddr);
			send_mem_to_pc(dumpbuf_pc, filename, &pkt_header, (char *)memaddr, (uint64_t)size);
		}
	} else {
		for (j = 0; j < mem[i].size / SZ_8M; j++) {
			if(check_dump_status_result.dump_to_pc_flag != 1){
				sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_%03d_"LLX,
						i + 1, j, vaddr+j*SZ_8M);
				write_mem_to_mmc(path, filename, fs_type, memaddr + j*SZ_8M, SZ_8M);
			} else {
				sprintf(filename, SYSDUMP_CORE_NAME_FMT"_%03d_"LLX,
						i + 1, j, vaddr+j*SZ_8M);
				send_mem_to_pc(dumpbuf_pc, filename, &pkt_header, (char *)memaddr + j*SZ_8M, (uint64_t)SZ_8M);
			}
		}
		if (mem[i].size % SZ_8M) {
			if(check_dump_status_result.dump_to_pc_flag != 1){
				sprintf(filename, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT"_%03d_"LLX,
						i + 1, j, vaddr+j*SZ_8M);
				write_mem_to_mmc(path, filename, fs_type, memaddr + j*SZ_8M, (size % SZ_8M));
			} else {
				sprintf(filename, SYSDUMP_CORE_NAME_FMT"_%03d_"LLX,
						i + 1, j, vaddr+j*SZ_8M);
				send_mem_to_pc(dumpbuf_pc, filename, &pkt_header, (char *)memaddr + j*SZ_8M, (uint64_t)(size % SZ_8M));
			}
		}
	}
#endif
}

static int fill_dump_mem_auto_x86(void)
{
	unsigned char *fdt_blob = dt_info.dt_addr;
	int nodeoffset = dt_info.nodeoffset;
	int ofs_remem = dt_info.ofs_remem;
	int dts_version = dt_info.dts_version;
	unsigned long long temp_size = 0;
	int x86_dump_mem_num, ret, j= 0, i = 0;
	struct sysdump_mem *temp_mem = dump_input_contents_info.sprd_dump_mem;
	/* step1: vmm region */
	if (VMM_RESERVE_SIZE) {
		dump_logd("dump vmm memory region !!!\n");
		dump_input_contents_info.sprd_dump_mem[0].paddr = 0;
		dump_input_contents_info.sprd_dump_mem[0].vaddr = 0;
		dump_input_contents_info.sprd_dump_mem[0].size  = VMM_RESERVE_SIZE;
		dump_input_contents_info.sprd_dump_mem[0].soff  = 0xffffffff;
		dump_input_contents_info.sprd_dump_mem[0].type  = SYSDUMP_RAM;
		i++;
		temp_mem++;
	}

	dump_logd("dump reset mode is 0x%x\n", dump_rst_mode_g);

	/* step2: memory region from kernel dts */
	if (dump_rst_mode_g == CMD_TOS_PANIC_MODE) {
		dump_logd("read security memory region from sysdump node !!!\n");
		ret = fill_mem_from_dts(fdt_blob, nodeoffset, "memory-region-se", temp_mem);
		if (ret == 0)
			dump_logd("ERROR: X86: memory-region-se dump failed !!!\n");
		else {
			i += ret;
			temp_mem += ret;
		}
	}

	/* step3: auto calculate linux memory region */
	if (dump_rst_mode_g != CMD_TOS_PANIC_MODE) {

		/* calculate specific reserved-memory*/
		dump_logd("read reserved-memory region from sysdump node !!!\n");
		ret = fill_mem_from_dts(fdt_blob, nodeoffset, "memory-region-re", temp_mem);
		if (ret == 0)
			dump_logd("ERROR: x86: memory-region-re dump failed !!!\n");
		else {
			i += ret;
			temp_mem += ret;
		}

		/* calculate linux memory region */
		dump_logd("calculate linux memory region !!!\n");
		ret = recalculate_kernel_memory(fdt_blob, nodeoffset, ofs_remem, dts_version, temp_mem);
		if (ret == 0)
			dump_logd("ERROR: x86: linux memory recalculation failed !!!\n");
		else {
			i += ret;
			temp_mem += ret;
		}

	}

	/* step4: return */
	x86_dump_mem_num = i;
	dump_logd("auto x86_dump_mem_num is %d\n", x86_dump_mem_num);
	for (i = 0; i < x86_dump_mem_num; i++) {
		dump_logd("auto x86_dump_mem[%d].paddr is 0x%llx\n", i, dump_input_contents_info.sprd_dump_mem[i].paddr);
		dump_logd("auto x86_dump_mem[%d].size  is 0x%llx\n", i, dump_input_contents_info.sprd_dump_mem[i].size);
	}

	return x86_dump_mem_num;
}
#endif
/*TODO: need check dual ddr */
int is_paddr_linux_memory(unsigned long paddr)
{
	phys_addr_t ddr_base = CONFIG_SYS_SDRAM_BASE;
	phys_size_t ddr_size = get_real_ram_size();
	phys_addr_t ddr_end = ddr_base + ddr_size;
	if(paddr < ddr_base || paddr > ddr_end)
		return 0;
	else
		return 1;
}
#define UBOOT_SIZE 0x1000000 // 16MB 
#ifdef CONFIG_FULLDUMP_INTERNAL_ENABLE
#define DUMP_SPLIT_LIMIT SZ_512M
#else
#define DUMP_SPLIT_LIMIT SZ_1G
#endif
void check_split_dump_mem(void)
{
	struct sysdump_mem sprd_not_ptload_mem[MAX_NUM_DUMP_MEM];
	struct sysdump_mem sprd_ptload_mem[MAX_NUM_DUMP_MEM];
	int sprd_ptload_mem_num = 0;
	int sprd_ptload_mem_flag = 0;
	int sprd_not_ptload_mem_num = 0;
	int linux_mem_num = linux_mem_num_g;/* global variable mem_num is linux_memory number*/
	int sprd_dump_mem_num = dump_input_contents_info.sprd_dump_mem_num;
	struct sysdump_mem *sprd_dump_mem = dump_input_contents_info.sprd_dump_mem;
	int mem_num_tmp = 0;
	unsigned long size = 0;
	unsigned long paddr = 0;
	unsigned long vaddr = 0;
	unsigned long addr_tmp = 0;
	unsigned long j = 0, i = 0;/* Prevent integer overflow when DDR is greater than 2G, j must be unsigned long */


	dump_logd("------------- show all mem blocks before  ------------------ \n");
	for (i = 0; i < sprd_dump_mem_num; i++) {
		dump_logd("mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", i, sprd_dump_mem[i].paddr, sprd_dump_mem[i].vaddr, sprd_dump_mem[i].size);
		for(j = 0; j < linux_mem_num; j++ ){
			if ((sprd_dump_mem[i].paddr >= linux_memory[j].addr) && (sprd_dump_mem[i].paddr <= linux_memory[j].addr + linux_memory[j].size)){ 
				copy_sysdump_mem_struct(&sprd_ptload_mem[sprd_ptload_mem_num ++],&sprd_dump_mem[i]);
				sprd_ptload_mem_flag = 1;
				break;
			}
		}
		if(0 == sprd_ptload_mem_flag){
			copy_sysdump_mem_struct(&sprd_not_ptload_mem[sprd_not_ptload_mem_num ++],&sprd_dump_mem[i]);
		}
		sprd_ptload_mem_flag = 0;
	}
	dump_logd("------------- show ptload mem blocks before ------------------ \n");
	for (i = 0; i < sprd_ptload_mem_num; i++) {
		dump_logd("ptload mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
				i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
	}
	dump_logd("------------- show not ptload mem blocks before ------------------ \n");
	for (i = 0; i < sprd_not_ptload_mem_num; i++) {
		dump_logd("not ptload mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
				i, sprd_not_ptload_mem[i].paddr, sprd_not_ptload_mem[i].vaddr, sprd_not_ptload_mem[i].size);
	}
	dump_logd("------------- start split ptload  mem blocks before ------------------ \n");
	mem_num_tmp = sprd_ptload_mem_num;
	for (i = 0; i < sprd_ptload_mem_num; i++) {
		/* record current add,size  */
		size = sprd_ptload_mem[i].size;
		paddr = sprd_ptload_mem[i].paddr;
		vaddr = sprd_ptload_mem[i].vaddr;
		j = 0;

		/*      here, we suppose every mem block size should be larger than 128M, the least size of product ddr is 128M   */
		while (size > DUMP_SPLIT_LIMIT) {
			dump_logd("mem block  %d too big , need split it %d ...........\n", i, j);
			if (j == 0) {
				sprd_ptload_mem[i].paddr = paddr;
				sprd_ptload_mem[i].vaddr = vaddr;
				sprd_ptload_mem[i].size = DUMP_SPLIT_LIMIT;
				dump_logd("check split , the first mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n",\
						i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
			} else {
				sprd_ptload_mem[mem_num_tmp - 1 + j].paddr = paddr+j*DUMP_SPLIT_LIMIT;
				sprd_ptload_mem[mem_num_tmp - 1 + j].vaddr = vaddr+j*DUMP_SPLIT_LIMIT;
				sprd_ptload_mem[mem_num_tmp - 1 + j].size = DUMP_SPLIT_LIMIT;
				sprd_ptload_mem[mem_num_tmp - 1 + j].soff = 0xffffffff;
				sprd_ptload_mem[mem_num_tmp - 1 + j].type = SYSDUMP_RAM;
				dump_logd("check split in while ...mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
						mem_num_tmp - 1 + j, sprd_ptload_mem[mem_num_tmp - 1 + j].paddr, sprd_ptload_mem[mem_num_tmp - 1 + j].vaddr, sprd_ptload_mem[mem_num_tmp - 1 + j].size);
			}
			size -= DUMP_SPLIT_LIMIT;
			j++;
		}
		if (size != 0) {
			if (j == 0) {
				sprd_ptload_mem[i].paddr = paddr;
				sprd_ptload_mem[i].vaddr = vaddr;
				sprd_ptload_mem[i].size = size;
				dump_logd("Do not need split , mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n",\
						i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
			} else {
				sprd_ptload_mem[mem_num_tmp - 1 + j].paddr = paddr+j*DUMP_SPLIT_LIMIT;
				sprd_ptload_mem[mem_num_tmp - 1 + j].vaddr = vaddr+j*DUMP_SPLIT_LIMIT;
				sprd_ptload_mem[mem_num_tmp - 1 + j].size = size;
				sprd_ptload_mem[mem_num_tmp - 1 + j].soff = 0xffffffff;
				sprd_ptload_mem[mem_num_tmp - 1 + j].type = SYSDUMP_RAM;
				dump_logd("check split last...mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n",\
						mem_num_tmp - 1 + j, sprd_ptload_mem[mem_num_tmp - 1 + j].paddr, sprd_ptload_mem[mem_num_tmp - 1 + j].vaddr, sprd_ptload_mem[mem_num_tmp - 1 + j].size);
			}
		}
		mem_num_tmp += j;
	}
	dump_logd("mem block num : old(%d) ----> new(%d) \n", sprd_ptload_mem_num, mem_num_tmp);
	sprd_ptload_mem_num = mem_num_tmp;
	dump_logd("------------- show ptload mem blocks after split ------------------ \n");
	for (i = 0; i < sprd_ptload_mem_num; i++) {
		dump_logd("ptload mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
				i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
#ifdef CONFIG_FULLDUMPINTERNAL_COMPRESS
		/*      here, we suppose every mem block size larger than 128M   */
		if(sprd_ptload_mem[i].paddr < CONFIG_SYS_TEXT_BASE) {
			if((CONFIG_SYS_TEXT_BASE + UBOOT_SIZE) >= (sprd_ptload_mem[i].paddr + sprd_ptload_mem[i].size)) {
				dump_logd("Compress need delete uboot section , | -mem- | uboot | \n");
				/*  case like this :  (ddr size: 128M , 256M, 512M)
					 | -mem- | uboot |  
				 */
				sprd_ptload_mem[i].size -= UBOOT_SIZE;
				dump_logd("Delete Uboot :ptload mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
						i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
			} else {
				dump_logd("Compress need delete uboot section , | -mem- | uboot | -mem- | \n");
				/*  case like this : (DDR size larger than 1G)
					 | -mem-1 | uboot | -mem-2 |  
				 */
				/*	mem-2	*/
				sprd_ptload_mem[sprd_ptload_mem_num].paddr = CONFIG_SYS_TEXT_BASE + UBOOT_SIZE;
				sprd_ptload_mem[sprd_ptload_mem_num].size = sprd_ptload_mem[i].paddr + sprd_ptload_mem[i].size - (CONFIG_SYS_TEXT_BASE + UBOOT_SIZE);
				sprd_ptload_mem[sprd_ptload_mem_num].soff = 0xffffffff;
				sprd_ptload_mem[sprd_ptload_mem_num].vaddr = sprd_ptload_mem[i].vaddr +  sprd_ptload_mem[i].size + UBOOT_SIZE;
				dump_logd("Delete Uboot: ptload mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
						sprd_ptload_mem_num, sprd_ptload_mem[sprd_ptload_mem_num].paddr,\
						 sprd_ptload_mem[sprd_ptload_mem_num].vaddr, sprd_ptload_mem[sprd_ptload_mem_num].size);

				/*	mem-1	*/
				sprd_ptload_mem[i].size = CONFIG_SYS_TEXT_BASE - sprd_ptload_mem[i].paddr;
				dump_logd("Delete Uboot: ptload mem block %ld :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
						i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
				sprd_ptload_mem_num ++;
			}
		}
#endif
	}
	/*  sort ptload mem blocks */
	sort_mem_list(sprd_ptload_mem, sprd_ptload_mem_num);
	dump_logd("------------- show ptload mem blocks after split and sort ------------------ \n");
	for (i = 0; i < sprd_ptload_mem_num; i++) {
		dump_logd("ptload mem block %ld :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", \
				i, sprd_ptload_mem[i].paddr, sprd_ptload_mem[i].vaddr, sprd_ptload_mem[i].size);
	}

	/*  reload sprd_dump_mem from sprd_ptload_mem and sprd_not_ptload_mem */
	dump_logd("------------- reload sprd_dump_mem from sprd_ptload_mem and sprd_not_ptload_mem  ------------------ \n");
	memset(sprd_dump_mem, 0, sizeof(sprd_dump_mem));
	mem_num_tmp = 0;
	for (i = 0; i < sprd_ptload_mem_num; i++) {
		copy_sysdump_mem_struct(&sprd_dump_mem[mem_num_tmp ++], &sprd_ptload_mem[i]);
	}
	for (i = 0; i < sprd_not_ptload_mem_num; i++) {
		copy_sysdump_mem_struct(&sprd_dump_mem[mem_num_tmp ++], &sprd_not_ptload_mem[i]);
	}

	dump_logd("------------- show mem blocks after split ------------------ \n");
	for (i = 0; i < mem_num_tmp; i++) {
		dump_logd("New mem block %d :paddr "LLX" , vaddr: "LLX" size: "LLX"\n", i, sprd_dump_mem[i].paddr, sprd_dump_mem[i].vaddr, sprd_dump_mem[i].size);
	}
	dump_input_contents_info.sprd_dump_mem_num = mem_num_tmp;
	return ;
}

int sysdumpdb_write(char *part_name, uint32_t size, uint32_t updsize, uint32_t offset, char *buf)
{

#ifdef CONFIG_NAND_BOOT
	/*	int do_raw_data_write(char *part, u32 updsz, u32 size, u32 off, char *buf)	*/
	return do_raw_data_write(part_name, updsize,  size,  offset, buf);
#else
	/*	int common_raw_write(char *part_name, uint64_t size, uint64_t updsize, uint64_t offset, char *buf)	*/
	return common_raw_write(part_name, (uint64_t)size, (uint64_t)updsize, (uint64_t)offset, buf);
#endif


}

void update_exception_info(struct minidump_info *minidump_infop, int rst_mode)
{
	memcpy(minidump_infop->exception_info.exception_reboot_reason, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
	strcpy(minidump_infop->exception_info.exception_time, dump_input_contents_info.infop->time);
	sprintf(minidump_infop->exception_info.exception_serialno, "ro.boot.serialno=%s", get_product_sn());
	if(rst_mode == CMD_UNKNOW_REBOOT_MODE) {
		memcpy(minidump_infop->exception_info.exception_panic_reason, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
		memcpy(minidump_infop->exception_info.exception_kernel_version, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
		memcpy(minidump_infop->exception_info.exception_file_info, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
		memcpy(minidump_infop->exception_info.exception_task_id, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
		memcpy(minidump_infop->exception_info.exception_task_family, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
		memcpy(minidump_infop->exception_info.exception_pc_symbol, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
		memcpy(minidump_infop->exception_info.exception_stack_info, GET_RST_MODE(rst_mode), strlen(GET_RST_MODE(rst_mode)));
	}


}
int sysdump_save_extend_information(struct section_extend_info *section_extend_infop)
{
	int i, j, index;
	struct minidump_info *minidump_infop;
	unsigned int rst_mode;
	struct section_info *extend_section;
	char str_name[SECTION_NAME_MAX];
	uint64_t addr;
	uint32_t size;
	uint16_t type;
	char tmp;

	dump_logd("%s: %s in \n", SYSDUMPDB_LOG_TAG, __FUNCTION__);
	rst_mode = reboot_mode_check();
	if (is_sysdump_boot_mode(rst_mode)) {
		dump_loga("add %s extend information start.\n", section_extend_infop->name);
	} else {
		dump_loge("%s:  Not exception mode .do nothing \n", SYSDUMPDB_LOG_TAG);
		return -1;
	}

	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(&check_header_g, &backup_info_g));
	if(!is_paddr_linux_memory(minidump_infop)){
		dump_loge("minidump info address is invalid!!, do nothing\n");
		return -1;
	}
	memset(str_name, 0, SECTION_NAME_MAX);
	memcpy(str_name, section_extend_infop->name, strlen(section_extend_infop->name));
	dump_logd("the name is %s, the len is %d\n", str_name, strlen(str_name));
	/* check name valid first */
	if (strlen(str_name) > (SECTION_NAME_MAX - strlen(EXTEND_STRING) - 2)) {
		dump_loge("The length of name is too long!!, add extend section fail!!\n");
		return -1;
	}
	if (!strlen(str_name)) {
		dump_loge("The name is empty, invalid!!\n");
		return -1;
	}
	for (j = 0; j < strlen(str_name); j++) {
		tmp = str_name[j];
		if (tmp == '?' || tmp == '*' || tmp == '/' || tmp == '>' || tmp == '<'
				|| tmp == '"' || tmp == '|') {
			dump_loge("the name=%s include special character:%c that not supported!!\n",
					str_name, tmp);
			return -1;
		}
	}
	/* check insert repeatly and acquire total seciton num before insert new section */
	for (i = 0; i < SECTION_NUM_MAX; i++) {
		if (!memcmp(str_name,
					minidump_infop->section_info_total.section_info[i].section_name,
					strlen(str_name))) {
			dump_loge("please rename a new name!!\n ");
			return -1;
		}
		if (!strlen(minidump_infop->section_info_total.section_info[i].section_name))
			break;
	}

	minidump_infop->section_info_total.total_num = i;
	index = minidump_infop->section_info_total.total_num;

	if (index >= (SECTION_NUM_MAX - 1)) {
		dump_loge("No space for new section.\n");
		return -1;
	}
	/* add new section in the tail of section_info */
	addr = section_extend_infop->paddr;
	size = section_extend_infop->size;
	type = section_extend_infop->type;

	extend_section = &minidump_infop->section_info_total.section_info[index];
	if (!is_paddr_linux_memory(extend_section)){
		dump_loge("extend_section: 0x%p, is invalid, no add new extend section\n", extend_section);
		return -1;
	}
	sprintf(extend_section->section_name, "%s_%d_%s", MINI_STRING, type, str_name);
	extend_section->section_start_paddr = addr;
	extend_section->section_end_paddr = addr + size;
	extend_section->section_size = size;
	minidump_infop->section_info_total.total_size += extend_section->section_size;
	minidump_infop->minidump_data_size += extend_section->section_size;

	minidump_infop->section_info_total.total_num++;
	dump_loga("%s added successfully in minidump section:paddr_start=%lx,size=%d\n",
			str_name, addr, size);
	return 0;

}
#ifdef CONFIG_SPRD_MINI_SYSDUMP
void show_minidump_info(struct minidump_info *minidump_infop)
{
	int i, l, n;
	char *p = minidump_infop->exception_info.exception_stack_info;

	dump_logd("kernel_magic: %s  \n ", minidump_infop->kernel_magic);

	dump_logd("---     regs_info       ---  \n ");
	dump_logd("arch:              %d \n ", minidump_infop->regs_info.arch);
	dump_logd("num:               %d \n ", minidump_infop->regs_info.num);
	dump_logd("paddr:         "LLX" \n ", minidump_infop->regs_info.paddr);
	dump_logd("size:          %d \n ", minidump_infop->regs_info.size);

	dump_logd("---     regs_memory_info        ---  \n ");
	for(i=0;i<minidump_infop->regs_info.num;i++){
		dump_logd("reg[%d] paddr:          "LLX" \n ", i, minidump_infop->regs_memory_info.reg_paddr[i]);
	}
	dump_logd("per_reg_memory_size:    %d \n ", minidump_infop->regs_memory_info.per_reg_memory_size);
	dump_logd("valid_reg_num:          %d \n ", minidump_infop->regs_memory_info.valid_reg_num);
	dump_logd("reg_memory_all_size:    %d \n ", minidump_infop->regs_memory_info.size);

	dump_logd("---     section_info_total        ---  \n ");
	dump_logd("Here are %d sections, Total size : %d \n", minidump_infop->section_info_total.total_num, minidump_infop->section_info_total.total_size);
	dump_logd("total_num:        %d \n ", minidump_infop->section_info_total.total_num);
	dump_logd("total_size        %d \n ", minidump_infop->section_info_total.total_size);
	for(i=0;i<minidump_infop->section_info_total.total_num;i++){
		dump_logd("section_name:           %s \n ", minidump_infop->section_info_total.section_info[i].section_name);
		dump_logd("section_start_vaddr:   "LLX" \n ", minidump_infop->section_info_total.section_info[i].section_start_vaddr);
		dump_logd("section_end_vaddr:      "LLX" \n ", minidump_infop->section_info_total.section_info[i].section_end_vaddr);
		dump_logd("section_start_paddr:   "LLX" \n ", minidump_infop->section_info_total.section_info[i].section_start_paddr);
		dump_logd("section_end_paddr:      "LLX" \n ", minidump_infop->section_info_total.section_info[i].section_end_paddr);
		dump_logd("section_size:           %x \n ", minidump_infop->section_info_total.section_info[i].section_size);
	}

	dump_logd("minidump_data_size:     %x \n ", minidump_infop->minidump_data_size);

	debugf("\n-------------------------		exception_info	----------------------------- \n ");
	debugf(" struct minidump_info size : "LLX"  \n ", sizeof(struct minidump_info));
	debugf("kernel_magic:             %s  \n ", minidump_infop->exception_info.kernel_magic);
	debugf("exception_serialno:  %s  \n ", minidump_infop->exception_info.exception_serialno);
	debugf("exception_kernel_version: %s  \n ", minidump_infop->exception_info.exception_kernel_version);
	debugf("exception_reboot_reason:  %s  \n ", minidump_infop->exception_info.exception_reboot_reason);
	debugf("exception_panic_reason:   %s  \n ", minidump_infop->exception_info.exception_panic_reason);
	debugf("exception_time:           %s  \n ", minidump_infop->exception_info.exception_time);
	debugf("exception_file_info:      %s  \n ", minidump_infop->exception_info.exception_file_info);
	debugf("exception_task_id:        %d  \n ", minidump_infop->exception_info.exception_task_id);
	debugf("exception_task_family:      %s  \n ", minidump_infop->exception_info.exception_task_family);
	debugf("exception_pc_symbol:      %s  \n ", minidump_infop->exception_info.exception_pc_symbol);

	/*	debugf exception stack info	*/
	l = strlen(p);
	n = (l - (l % 1024)) / 1024;
	debugf("exception_stack_info:     \n");
	for(i = 0; i < n; i++)
	{
		printf("%1024.1024s", p + i*1024);
	}
	printf("%s", p + n * 1024);
	/*	debugf exception stack info end		*/

	return;
}
int compress_data(void *des, unsigned long *outlen, unsigned char  *src, unsigned long srclen)
{
	int ret = 0;
	dump_logd(" %s: before compress  des : %p outlen : "LLX" srclen : "LLX" \n", __func__, des, *outlen, srclen);
	memset(des, 0, *outlen);
	/* when gzip return 0 ,means compressed ok */
	ret = gzip(des, outlen, src, srclen);
	if(ret){
		dump_logd(" compress data  fail ..\n");
		return -1;
	}
	dump_logd(" %s: after compress outlen : "LLX" srclen : "LLX" \n", __func__, *outlen, srclen);
	return ret;

}

int handle_minidump(int rst_mode)
{

	struct minidump_info *minidump_infop;
	int minidump_info_offset = sizeof(struct dumpdb_header);
	int offset = 0;
	int size = 0;
	char *addr = NULL;
	char *vaddr = NULL;
	int i = 0;
	int minidump_mem_num = 0;
	struct sysdump_mem minidump_mem[MINIDUMP_MEM_MAX]; /* must large than 1 + regs_mem_num + section_num */
	char *minidump_elfhdr_addr = NULL;
	int minidump_elfhdr_size;
	void* compressed_buf = NULL;
	unsigned long malloc_limit = MALLOC_LIMIT;
	unsigned long fix_len = 0;
	unsigned long compressed_size = 0;
	unsigned long src_data_max = SRC_DATA_MAX; /*  12K  smaller than compress buf len */
	int compress_counter;
	int step_size = 0;


	dump_logd("%s: %s in \n", SYSDUMPDB_LOG_TAG, __FUNCTION__);
	/*	get minidump info data  */
	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(&header_paddr_mini, dump_input_contents_info.infop));
	if(!is_paddr_linux_memory(minidump_infop)){
		dump_loge("minidump info address is invalid!!, do nothing\n");
		return -1;
	}
	/*	check minidump info data kernel  magic ,make sure it is valid	*/
	if(memcmp(KERNEL_MAGIC, minidump_infop->kernel_magic, strlen(KERNEL_MAGIC))){
		/*	no magic means ddr data is corruption  ,do nothing	*/
		dump_loge("%s: no  kerenl magic ,minidump indo is no valid .do nothing \n",SYSDUMPDB_LOG_TAG);
		return -1;
	}
	update_exception_info(minidump_infop, rst_mode);
	show_minidump_info(minidump_infop);
	if(minidump_infop->compressed){
		compressed_buf = (void*)malloc(malloc_limit);
		if(NULL == compressed_buf){
			dump_logd("%s: %s malloc compress buf error , want size "LLX" \n", SYSDUMPDB_LOG_TAG, __FUNCTION__, malloc_limit);
			return -1;
		}
	}
	/*  struct pt_regs  */
	offset = minidump_info_offset + sizeof(struct minidump_info);
	size = minidump_infop->regs_info.size;
	addr = (char*)minidump_infop->regs_info.paddr;
	vaddr = (char*)minidump_infop->regs_info.vaddr;
	if(is_paddr_linux_memory(addr)){
		/*	save minidump_mem info for elfhdr	*/
		minidump_mem[minidump_mem_num].paddr = addr;
		//minidump_mem[minidump_mem_num].vaddr = __va(addr);
		minidump_mem[minidump_mem_num].vaddr = vaddr;
		minidump_mem[minidump_mem_num].size = size;
		minidump_mem_num += 1;
		dump_logd("%s: regs offset : 0x%x   \n", __FUNCTION__, offset);
		dump_logd("%s: malloc_limit : "LLX"   \n", __FUNCTION__, malloc_limit);
		if(minidump_infop->compressed){
			dump_logd("%s: need compress-----total  data size  : 0x%x  offset : 0x%x  \n", __FUNCTION__, size, offset);
			/*	if the data length more than malloc_limit ,we need compresse step by step 	*/
			compress_counter = step_size =0;  /* record circle num as src data index  */
			while(size > src_data_max){
				fix_len = malloc_limit; /*	we compress malloc_limit data every time , src data pointor need have a offset too .*/
				dump_logd("%s: need compress step by step -----step-%d  \n", __FUNCTION__, compress_counter);
				dump_logd("%s:  compress step-%d src addr : %p \n", __FUNCTION__, compress_counter, (char*)addr + compress_counter * src_data_max);
				if(compress_data(compressed_buf, &fix_len, (char*)addr + compress_counter * src_data_max, src_data_max)){
					goto error_handler;
				}
				/*	after compressed, we record circle number , rest data length, and compressed output length */
				compress_counter++; /*	circle number	*/
				size -= src_data_max; /*	rest data length	*/
				dump_logd("%s:  write step-%d data compressed len :"LLX"  offset : 0x%x \n", __FUNCTION__, compress_counter, fix_len, offset);
				if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, fix_len, fix_len, offset, (char*)compressed_buf)) {
					dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
					goto error_handler;
				}
				offset += fix_len;
				step_size += fix_len;
			}
			dump_logd("%s: need compress-----last compress data size  : 0x%x   offset : 0x%x data location : %p\n", __FUNCTION__, size, offset, (char*)addr + compress_counter * src_data_max);
			compressed_size = malloc_limit;
			if(compress_data(compressed_buf, &compressed_size, (void*)addr + compress_counter * src_data_max, size)){
				goto error_handler;
			}
			size = compressed_size;
			addr = (char*)compressed_buf;
		}
		if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, size, size, offset, (char*)addr)) {
			dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
			goto error_handler;
		}
		if(minidump_infop->compressed){
			dump_logd("%s: size : 0x%x step_size : 0x%x  \n", __FUNCTION__, size, step_size);
			minidump_infop->regs_info.size_comp = size + step_size;
			dump_logd("%s: regs info.size_comp : 0x%x   \n", __FUNCTION__, minidump_infop->regs_info.size_comp);
		}

		/*	update offset	*/
		offset += size;
	} else {
		minidump_infop->regs_info.size = 0;
		dump_loge("no valid address, skip save pt_regs\n");
	}

	/*  memory amount regs  */
	dump_logd("%s: memory amount regs offset : 0x%x   \n", __FUNCTION__, offset);
	for(i=0;i<minidump_infop->regs_info.num;i++){
		size = minidump_infop->regs_memory_info.per_reg_memory_size;
		addr = minidump_infop->regs_memory_info.reg_paddr[i];
		vaddr = minidump_infop->regs_memory_info.reg_vaddr[i];
		dump_logd("%s: memory amount regs : %d size : 0x%x addr : "LLX"  \n", __FUNCTION__, i, size, addr);
		if(addr == 0 || !is_paddr_linux_memory(addr) ) {
			dump_logd("%s: invalid addr skip it  . \n", __FUNCTION__);
			continue;
		}
		/*	save minidump_mem info for elfhdr	*/
		minidump_mem[minidump_mem_num].paddr = addr;
		//minidump_mem[minidump_mem_num].vaddr = __va(addr);
		minidump_mem[minidump_mem_num].vaddr = vaddr;
		minidump_mem[minidump_mem_num].size = size;
		minidump_mem_num += 1;


		if(minidump_infop->compressed){
			dump_logd("%s: need compress-----total  data size  : 0x%x  offset : 0x%x  \n", __FUNCTION__, size, offset);
			/*	if the data length more than malloc_limit ,we need compresse step by step 	*/
			compress_counter = step_size = 0;  /* record circle num as src data index  */
			while(size > src_data_max){
				fix_len = malloc_limit; /*	we compress malloc_limit data every time , src data pointor need have a offset too .*/
				dump_logd("%s: need compress step by step -----step-%d  \n", __FUNCTION__, compress_counter);
				dump_logd("%s:  compress step-%d src addr : %p \n", __FUNCTION__, compress_counter, (char*)addr + compress_counter * src_data_max);
				if(compress_data(compressed_buf, &fix_len, (char*)addr + compress_counter * src_data_max, src_data_max)){
					goto error_handler;
				}
				/*	after compressed, we record circle number , rest data length, and compressed output length */
				compress_counter++; /*	circle number	*/
				size -= src_data_max; /*	rest data length	*/
				dump_logd("%s:  write step-%d data compressed len :"LLX"  offset : 0x%x \n", __FUNCTION__, compress_counter, fix_len, offset);
				if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, fix_len, fix_len, offset, (char*)compressed_buf)){
					dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
					goto error_handler;
				}
				offset += fix_len;
				step_size += fix_len;
			}
			dump_logd("%s: need compress-----last compress data size  : 0x%x   offset : 0x%x data location : %p\n", __FUNCTION__, size, offset, (char*)addr + compress_counter * src_data_max);
			compressed_size = malloc_limit;
			if(compress_data(compressed_buf, &compressed_size, (void*)addr + compress_counter * src_data_max, size)){
				goto error_handler;
			}
			size = compressed_size;
			addr = (char*)compressed_buf;
		}
		if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, size, size, offset, (char*)addr)) {
			dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
			goto error_handler;
		}
		if(minidump_infop->compressed){
			dump_logd("%s: size : 0x%x step_size : 0x%x  \n", __FUNCTION__, size, step_size);
			minidump_infop->regs_memory_info.per_mem_size_comp[i] = size + step_size;
			dump_logd("%s: minidump_infop->regs_memory_info.per_mem_size_comp : 0x%x   \n", __FUNCTION__, minidump_infop->regs_memory_info.per_mem_size_comp[i]);
		}
		/*	update offset	*/
		offset += size;

	}
	/*  sections  */
	for(i=0;i<minidump_infop->section_info_total.total_num;i++){
		size = minidump_infop->section_info_total.section_info[i].section_size;
		addr = minidump_infop->section_info_total.section_info[i].section_start_paddr;
		vaddr = minidump_infop->section_info_total.section_info[i].section_start_vaddr;
		dump_logd("%s: sections : %d size : 0x%x addr : "LLX"  \n", __FUNCTION__, i, size, addr);
		if(!addr) {
			dump_loge("%s:%s: invalid addr skip it  . \n", __FUNCTION__, minidump_infop->section_info_total.section_info[i].section_name);
			continue;
		}
		/*	save minidump_mem  info for elfhdr	*/
		minidump_mem[minidump_mem_num].paddr = addr;
		//minidump_mem[minidump_mem_num].vaddr = __va(addr);
		minidump_mem[minidump_mem_num].vaddr = vaddr;
		minidump_mem[minidump_mem_num].size = size;
		minidump_mem_num += 1;
		if(minidump_infop->compressed){
			dump_logd("%s: need compress-----total  data size  : 0x%x  offset : 0x%x  \n", __FUNCTION__, size, offset);
			/*	if the data length more than malloc_limit ,we need compresse step by step 	*/
			compress_counter = step_size = 0;  /* record circle num as src data index  */
			while(size > src_data_max){
				fix_len = malloc_limit; /*	we compress malloc_limit data every time , src data pointor need have a offset too .*/
				dump_logd("%s: need compress step by step -----step-%d  \n", __FUNCTION__, compress_counter);
				dump_logd("%s:  compress step-%d src addr : %p \n", __FUNCTION__, compress_counter, (char*)addr + compress_counter * src_data_max);
				if(compress_data(compressed_buf, &fix_len, (char*)addr + compress_counter * src_data_max, src_data_max)){
					goto error_handler;
				}
				/*	after compressed, we record circle number , rest data length, and compressed output length */
				compress_counter++; /*	circle number	*/
				size -= src_data_max; /*	rest data length	*/
				dump_logd("%s:  write step-%d data compressed len :"LLX"  offset : 0x%x \n", __FUNCTION__, compress_counter, fix_len, offset);
				if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, fix_len, fix_len, offset, (char*)compressed_buf)) {
					dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
					goto error_handler;
				}
				offset += fix_len;
				step_size += fix_len;
			}
			dump_logd("%s: need compress-----last compress data size  : 0x%x   offset : 0x%x data location : %p\n", __FUNCTION__, size, offset, (char*)addr + compress_counter * src_data_max);
			compressed_size = malloc_limit;
			if(compress_data(compressed_buf, &compressed_size, (void*)addr + compress_counter * src_data_max, size)){
				goto error_handler;
			}
			size = compressed_size;
			addr = (char*)compressed_buf;
		}
		if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, size, size, offset, (char*)addr)) {
			dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
			goto error_handler;
		}
		if(minidump_infop->compressed){
			dump_logd("%s: size : 0x%x step_size : 0x%x  \n", __FUNCTION__, size, step_size);
			minidump_infop->section_info_total.section_info[i].section_size_comp = size + step_size;
			dump_logd("%s: minidump_infop->section_info_total.section_info[%d].section_size_comp : 0x%x   \n", __FUNCTION__, i, minidump_infop->section_info_total.section_info[i].section_size_comp);
		}
		dump_logd("%s: %s sections offset : 0x%x   \n", __FUNCTION__, minidump_infop->section_info_total.section_info[i].section_name, offset);
		/*	update offset	*/
		offset += size;

	}


	/*	minidump elfhdr */
	minidump_elfhdr_size = get_elfhdr_size(minidump_mem_num);
	minidump_elfhdr_addr = (char*)malloc(minidump_elfhdr_size);
	if(NULL == minidump_elfhdr_addr){
		dump_logd("%s:%s: malloc minidump_elfhdr_addr fail \n", SYSDUMPDB_LOG_TAG, __FUNCTION__);
		goto error_handler;
	}
	for(i=0;i<minidump_mem_num;i++){
		dump_logd("[%d]  ----  paddr:  "LLX",  vaddr:  "LLX" \n ", i, minidump_mem[i].paddr, minidump_mem[i].vaddr);
	}
	dump_logd("%s: minidump elfhdr offset : 0x%x   \n", __FUNCTION__, offset);
	sysdump_fill_core_hdr(NULL, minidump_mem, minidump_mem_num, minidump_elfhdr_addr, minidump_elfhdr_size);
	size = minidump_elfhdr_size;
	addr = minidump_elfhdr_addr;
	if(minidump_infop->compressed){
		dump_logd("%s: need compress-----total  data size  : 0x%x  offset : 0x%x  \n", __FUNCTION__, size, offset);
		/*	if the data length more than malloc_limit ,we need compresse step by step 	*/
		compress_counter = step_size = 0;  /* record circle num as src data index  */
		while(size > src_data_max){
			fix_len = malloc_limit; /*	we compress malloc_limit data every time , src data pointor need have a offset too .*/
			dump_logd("%s: need compress step by step -----step-%d  \n", __FUNCTION__, compress_counter);
			dump_logd("%s:  compress step-%d src addr : %p \n", __FUNCTION__, compress_counter, (char*)addr + compress_counter * src_data_max);
			if(compress_data(compressed_buf, &fix_len, (char*)addr + compress_counter * src_data_max, src_data_max)){
				goto error_handler;
			}
			/*	after compressed, we record circle number , rest data length, and compressed output length */
			compress_counter++; /*	circle number	*/
			size -= src_data_max; /*	rest data length	*/
			dump_logd("%s:  write step-%d data compressed len :"LLX"  offset : 0x%x \n", __FUNCTION__, compress_counter, fix_len, offset);
			if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, fix_len, fix_len, offset, (char*)compressed_buf)) {
				dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
				goto error_handler;
			}
			offset += fix_len;
			step_size += fix_len;
		}
		dump_logd("%s: need compress-----last compress data size  : 0x%x   offset : 0x%x data location : %p\n", __FUNCTION__, size, offset, (char*)addr + compress_counter * src_data_max);
		compressed_size = malloc_limit;
		if(compress_data(compressed_buf, &compressed_size, (void*)addr + compress_counter * src_data_max, size)){
			goto error_handler;
		}
		size = compressed_size;
		addr = (char*)compressed_buf;
	}
	if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, size, size, offset, addr)) {
		dump_loge(" write %s error.\n", SYSDUMPDB_PARTITION_NAME);
		goto error_handler;
	}
	if(minidump_infop->compressed){
		dump_logd("%s: size : 0x%x step_size : 0x%x  \n", __FUNCTION__, size, step_size);
		minidump_infop->minidump_elfhdr_size_comp = size + step_size;
		dump_logd("%s: minidump_infop->minidump_elfhdr_size_comp : 0x%x   \n", __FUNCTION__, minidump_infop->minidump_elfhdr_size_comp);
	}
	if(minidump_elfhdr_addr) {
		free(minidump_elfhdr_addr);
		minidump_elfhdr_addr = NULL;
	}
	offset += size; /* the end of all minidump data */

	/*	update  minidump_info	*/
	minidump_infop->minidump_elfhdr_size = minidump_elfhdr_size;
	size = get_minidump_info_size(&header_paddr_mini, dump_input_contents_info.infop);
	if (size < 0) {
		dump_loge("minidump_info size is %d, save minidump_info to sysdumpdb failed!!\n", size);
		goto error_handler;
	}
	addr = minidump_infop;
	if(!is_paddr_linux_memory(addr)){
		dump_loge("the addr of minidump_info struct is invalid:0x%p, return!!\n", addr);
		return -1;
	}
	if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, size, size, minidump_info_offset, (char*)addr)) {
		dump_loge(" update minidump_info  %s error.\n", SYSDUMPDB_PARTITION_NAME);
		goto error_handler;
	}
	if(minidump_infop->compressed)
		free(compressed_buf);
	if(mini_pre_logbuffer)
                free(mini_pre_logbuffer);
	dump_logd("%s: %s ok \n", SYSDUMPDB_LOG_TAG, __FUNCTION__);
	return 0;

error_handler:
	if(minidump_infop->compressed){
		free(compressed_buf);
	}
	if(mini_pre_logbuffer)
		free(mini_pre_logbuffer);
	if(minidump_elfhdr_addr) {
		free(minidump_elfhdr_addr);
	}

	return -1;
}
int update_header(struct dumpdb_header *header_g)
{

	memset(header_g->app_magic, 0 , strlen(APP_MAGIC));
	memset(dump_input_contents_info.infop->sprd_minidump_info.magic, 0, strlen(MINIDUMP_MAGIC));
	memcpy(header_g->uboot_magic, UBOOT_MAGIC, strlen(UBOOT_MAGIC));
	if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, sizeof(struct dumpdb_header), sizeof(struct dumpdb_header), 0, (char*)header_g)) {
		dump_loge(" update minidump_info  %s error.\n", SYSDUMPDB_PARTITION_NAME);
		return -1;
	}
	return 0;

}
int save_etb_dump_to_minidump(struct dumpdb_header *header_g)
{
	int i;
	struct minidump_info *minidump_infop;
	char etb_data[20] = "etb data is null";
	dump_logd("%s: %s in \n", SYSDUMPDB_LOG_TAG, __FUNCTION__);
	/*      get minidump info data  */
	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(header_g, dump_input_contents_info.infop));
	if(!is_paddr_linux_memory(minidump_infop)){
		dump_loge("minidump info address is invalid!!, do nothing\n");
		return -1;
	}

	for(i=0;i<minidump_infop->section_info_total.total_num;i++){
		if((!(memcmp(ETBDATA, minidump_infop->section_info_total.section_info[i].section_name, strlen(ETBDATA)))) ||
			(!(memcmp(ETBDATA_EXTEND, minidump_infop->section_info_total.section_info[i].section_name, strlen(ETBDATA_EXTEND))))){
#ifdef CONFIG_ETB_DUMP
			dump_logd ("\n Start to dump ETB trace data to minidump\n");
			sprd_etb_hw_dis();
			sprd_etb_dump();
			minidump_infop->section_info_total.section_info[i].section_start_paddr = &etb_dump_mem[0];
			minidump_infop->section_info_total.section_info[i].section_size = etb_buf_size * 4;
			dump_logd ("\n Dump ETB data to minidump finished\n");
#else
			dump_logd(" no etb data to save!!! \n");
			minidump_infop->section_info_total.section_info[i].section_start_paddr = &etb_data;
			minidump_infop->section_info_total.section_info[i].section_size = 20;
#endif
			return 0;
		}
	}

	dump_logd ("\n Dump ETB data to minidump failed!!!\n");
	return 0;
}
int save_sysdumpdb(int rst_mode)
{
	int ret = 0;

	if (is_sysdump_boot_mode(rst_mode)) {
		dump_loga(" save_sysdumpdb start ...... \n");
	} else {
		dump_loge("%s:  Not exception mode .do nothing \n", SYSDUMPDB_LOG_TAG);
		return -1;
	}

	if (common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)(sizeof(struct dumpdb_header)), (uint64_t)0,(char *)&header_paddr_mini)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, SYSDUMPDB_PARTITION_NAME);
		return -1;
	}
	/* check header and minidump magic */
	if(memcmp(MINIDUMP_MAGIC, dump_input_contents_info.infop->sprd_minidump_info.magic, strlen(MINIDUMP_MAGIC))){
		dump_loge("%s: no minidump magic.do nothing...\n",SYSDUMPDB_LOG_TAG);
		return -1;
	}
#if SPRD_SYSDUMP_MAGIC != RAMDISK_ADR
	/* update vmcoreinfo */
	extend_vmcoreinfo_buf();
#endif
	/* add here for minidump accsess iram */
#ifdef CONFIG_ARM7_RAM_ACTIVE
	pmic_arm7_RAM_active();
#endif

	/*      save etb dump   */
	save_etb_dump_to_minidump(&header_paddr_mini);

	/*	handle minidump	*/
	if (handle_minidump(rst_mode)){
		dump_loge("%s: handle minidump  fail . \n",SYSDUMPDB_LOG_TAG);
		return -1;
	}

	/*	handle minidump	*/
	if (update_header(&header_paddr_mini)){
		dump_loge("%s: update_header  fail . \n",SYSDUMPDB_LOG_TAG);
		return -1;
	}
	dump_loga("%s: %s ok \n", SYSDUMPDB_LOG_TAG, __FUNCTION__);
	return ret;
}
#endif
int fulldump_to_internal_init(void)
{
	/*
		Here , wo set malloc size is 513 * 1024, and wo use it src data size as 512 * 1024
		because src data size must be smaller 512B than out buffer size .
		we also set fix_len as 513 * 1024 when compressing
	*/
	unsigned long malloc_limit = MALLOC_LIMIT;
	void* compressed_buf = NULL;
	if(fulldump_to_internal_status.save_status != FULLDUMP_INTER_UNDO) {
		dump_logd("Already inited ... \n");
		return -1;
	}
       compressed_buf = (void*)malloc(malloc_limit);
       if(NULL == compressed_buf){
               dump_logd("%s: %s malloc compress buf error , want size 0x%lx \n", SYSDUMPDB_LOG_TAG, __FUNCTION__, malloc_limit);
               return -1;
       }
       fulldump_to_internal_status.comp_buf = compressed_buf;

	fulldump_to_internal_status.save_status = FULLDUMP_INTER_INITED;
#ifdef CONFIG_EXT4_WRITE
	sysdump_lcd_printf("format partition start ......\n");
	if( (format_fs_ext4(FULLDUMPDB_PARTITION_NAME)) == 0){
		dump_loga("\nmkfs success !!!\n");
		sysdump_lcd_printf("Done .\n");
	}
#endif
	dump_loga(" ok ...\n");
	return 0;
}
int sysdump_write_file_ext4(char *mpart, char *filenm, void *buf, int len)
{
	int ret = 0;
	int append_flag = 0; // 0: create ; 1 : append write
	sprintf((char*)name_new,"%s",filenm);

	if(!strcmp(name_new, name_old))
		append_flag = 1;
	sprintf((char*)name_old,"%s",name_new);
	dump_loga(" wxz Try write file %s  (size: 0x%x , append_flag : %d)  To %s...\n", filenm, len, append_flag, mpart);
#ifdef CONFIG_EXT4_WRITE
	ret = write_file_ext4(mpart, filenm, buf, len, append_flag);
#endif
	return ret;
}
int send_data_to_internal(char *filename, char *memaddr, uint64_t memsize) 
{
	char *file_name_fullpath[40] = {0};
	uint64_t size = 0;
	char *addr = NULL;
	void* compressed_buf = NULL;
	unsigned long src_data_max = SRC_DATA_MAX;
	unsigned long fix_len = 0;
	unsigned long offset = 0;
	unsigned long compressed_size = 0;
	int compress_counter;
	int step_size = 0;
	int index = 0;

	if(fulldump_to_internal_status.save_status == FULLDUMP_INTER_UNDO) {
		fulldump_to_internal_status.save_status = FULLDUMP_INTER_ABORT;
		dump_loga("Not inited , must be something wrong , drop the data \n ");
		return -1;
	}
	if(fulldump_to_internal_status.save_status == FULLDUMP_INTER_ABORT) {
		fulldump_to_internal_status.save_status = FULLDUMP_INTER_ABORT;
		dump_loga("Abort ever before , drop the data \n ");
		return -1;
	}
	fulldump_to_internal_status.save_status = FULLDUMP_INTER_DOING;

	sprintf((char*)file_name_fullpath,"/%s",filename);

#ifndef CONFIG_FULLDUMPINTERNAL_COMPRESS
	sysdump_lcd_printf("%s: %s start .\n", __func__, file_name_fullpath);
	if(sysdump_write_file_ext4(FULLDUMPDB_PARTITION_NAME, file_name_fullpath, (char*)memaddr,memsize)) {
		sysdump_lcd_printf("Failed .\n");
	} else {
		sysdump_lcd_printf("Done .\n");
	}
#else
	sysdump_lcd_printf("%s:  start compress %s ...\n", __func__, file_name_fullpath);
	compress_counter = step_size =0;  /* record circle num as src data index  */
	compressed_buf = fulldump_to_internal_status.comp_buf;
	memset(compressed_buf, 0 , src_data_max);
	size = memsize;
	addr = memaddr;
	dump_loga("name : %s ;org size : 0x%x  \n ", filename, memsize);
	while(size > src_data_max) {
		fix_len = MALLOC_LIMIT;
		dump_logd("need compress step by step -----step-%d  \n", compress_counter);
		dump_logd("compress step-%d src addr : %p \n", compress_counter, (char*)addr + compress_counter * src_data_max);
		if(compress_data(compressed_buf, &fix_len, (char*)addr + compress_counter * src_data_max, src_data_max)){
			dump_loge(" Compresse %s error.\n", SYSDUMPDB_PARTITION_NAME);
			fulldump_to_internal_status.save_status = FULLDUMP_INTER_ABORT;
			free(compressed_buf);
			return -1;
		}
		/*	after compressed, we record circle number , rest data length, and compressed output length */
		dump_logd(" write step-%d data compressed len :0x%x  offset= 0x%x\n", compress_counter, fix_len, offset);
		compress_counter++; /*	circle number	*/
		size -= src_data_max; /*	rest data length	*/
		memcpy(((char*)TRANSFER_BUF_START + offset), (char*)compressed_buf, fix_len);
		offset += fix_len;
		step_size += fix_len;
	}
	dump_logd("need compress-----last compress data size  : 0x%x   data location : %p\n",
			size, (char*)addr + compress_counter * src_data_max);
	compressed_size = src_data_max;
	if(compress_data(compressed_buf, &compressed_size, (void*)addr + compress_counter * src_data_max, size)){
		fulldump_to_internal_status.save_status = FULLDUMP_INTER_ABORT;
		free(compressed_buf);
		return -1;
	}
	size = compressed_size;
	addr = (char*)compressed_buf;
	memcpy(((char*)TRANSFER_BUF_START + offset), (char*)compressed_buf, size);

	dump_loga("File  %s save Compelte------compressed size : 0x%x\n ", filename, step_size + size );

	sysdump_lcd_printf("Done .\n");
	sprintf((char*)file_name_fullpath,"/%s%s",filename, ".gz");
	sysdump_lcd_printf("%s: write %s start ...\n", __func__, file_name_fullpath);
	if(sysdump_write_file_ext4(FULLDUMPDB_PARTITION_NAME, file_name_fullpath, (char*)(char*)TRANSFER_BUF_START, (step_size + size))) {
		sysdump_lcd_printf("Failed .\n");
	} else {
		sysdump_lcd_printf("Done .\n");
	}

#endif
	dump_loga("%s ok ...\n", __func__);
	return 0;
}
int fulldump_to_internal_finish(void)
{
	fulldump_to_internal_status.save_status = FULLDUMP_INTER_FINISH;
}
int sysdump_initusb(void)
{
	ulong now;
	int key_code;

	now = 0;
	while(!usb_is_configured()){
		mdelay(1);
		now++;
		if(now > DUMP_USB_ENUM_MS) {
			dump_loge("USB SERIAL CONFIGED failed \n");
			return -1;
		}
		if( !(now % 100)) {
			printf("now = %ld \n", now);
			key_code = board_key_scan();
			if (key_code == KEY_VOLUMEUP){
				dump_logd("Key pressed detect ,Do not wait usb cable,abort sysdump ...\n");
				return -1;
			}
		}
	}
	printf("now = %ld \n", now);
	dump_loga("USB SERIAL CONFIGED\n");

	now = 0;
	while(!usb_is_port_open()) {
		mdelay(1);
		now++;
		if(now > DUMP_USB_IO_MS) {
			dump_loge("USB SERIAL PORT OPEN failed \n");
			return -1;
		}
		if( !(now % 1000)) {
			printf("now = %d \n", now);
			key_code = board_key_scan();
			if (key_code == KEY_VOLUMEUP){
				dump_logd("Key pressed detect ,Do not wait usb cable,abort sysdump ...\n");
				return -1;
			}
		}
	}
	printf("now = %ld \n", now);

	gs_open();
	dump_loga("USB SERIAL PORT OPENED\n");
	return 0;
}

int get_handshake_value(uint8_t *buf, int len)
{
	int got = 0;
	int count = len;
	int ret = 0;

	while (got < len) {
		if (usb_is_trans_done(0)) {
			if (usb_trans_status)
				dump_loge("func: %s line %d usb trans with error %d\n", __func__, __LINE__, usb_trans_status);

			gs_read(buf, &count);

			if (usb_trans_status)
				dump_loge("func: %s line %d usb trans with error %d\n", __func__, __LINE__, usb_trans_status);

			got+=count;
		}

		if (got == len)
			break;
	}

	dump_loga("caliberate:what got from host total %d is \n", got);
	return 1;
}
static int usb_sysdump_handler(void)
{
	unsigned char value1 = 0;
	unsigned char value2 = 0;
	volatile unsigned char reg_rx;
	int key_code;
	static int usb_status_old = 0;
	static int usb_status_new = 0;
	static int first_enter_flag = 1;
	static int handshake_error_flag = 1;
	if(first_enter_flag){
		first_enter_flag = 0;
		usb_status_old = usb_status_new = charger_connected();
	}
	/*	only status is insert ,we handle it
		usb_status_old	usb_status_new	status
		0              0          invalid
		0              1          insert
		1              0          remove
		1              1          invalid
	 */
	if(usb_status_old == 0 && usb_status_new == 1) {
		dump_logd("sysdump: usb cable is inserted\n");
		usb_insert_count ++;
		if( handshake_error_flag && (usb_insert_count <= 1))
			sysdump_lcd_printf("usb cable is inserted...\n");
		led_dump2pc_usb_insert_ok();
		dcache_disable();

		if(sysdump_initusb()) {
			dcache_enable();
			dump_logd("ERROR: sysdump_initusb failed.\n");
			usb_init_count ++;
			if (usb_init_count <= 1)
				sysdump_lcd_printf(" pressed  up key to abort sysdump ...\n");

			key_code = board_key_scan();
			if (key_code == KEY_VOLUMEUP){
				dump_logd("Key pressed detect ,Do not wait usb cable,abort sysdump ...\n");
				return -1;
			} else {
				return 0;
			}
		}
		dcache_enable();

		dump_logd("sysdump: do handshake with pc tools!!\n");
		get_handshake_value(handshake_buf, 2 );

		if ((handshake_buf[0] == 0x74) && (handshake_buf[1] == 0x0A)) {
			gs_close();
			dump_logd(" handshake is ok from pc tools to sysdump\n");
			sysdump_lcd_printf("\nhandshake is ok from pc tools to sysdump!!!.\nNow start do memory dump\n");
			return 1;
		} else {
			gs_close();
			dump_logd(" handshakeis abnormal from pc tools to sysdump\n");
			if( handshake_error_flag) {
				handshake_error_flag = 0;
				sysdump_lcd_printf("\nhandshakeis abnormal from pc tools to sysdump!!!.\nplease check PC tools\n");
			}
			key_code = board_key_scan();
			if (key_code == KEY_VOLUMEUP){
				dump_logd("Key pressed detect, abort sysdump ...\n");
				sysdump_lcd_printf("PC tools maybe incorrect, abort sysdump ...\n");
				return -1;
			}
			return 0;
		}
	} else {
		/*	update usb cable status detection */
		usb_status_old = usb_status_new ;
		usb_status_new = charger_connected();
		/* no cable insert , press key to abort it */
		udelay(50 * 1000);
		key_code = board_key_scan();
		if (key_code == KEY_VOLUMEUP){
			dump_logd("Key pressed detect ,Do not wait usb cable,abort sysdump ...\n");
			sysdump_lcd_printf("Do not wait usb cable,abort sysdump ...\n");
			return -1;
		}
	}

	return 0;
}

void pkt_header_init(smp_header_t * header)
{
	header->header = 0x7E7E7E7E;
	header->lcn = 0x0;
	header->type = 0x0;
	header->reserved = 0x5A5A;
	header->diag_sn = 0x0;
	header->diag_type = 0xFF;
	header->diag_subtype = 0x08;
}

/*
 *send the filesize and filename to pc tool
 *filezise occupied 8 bytes,and filename occupied 128 bytes
 */
void send_to_pc_start(char *smp_string, char *filename, smp_header_t * header, uint64_t memsize)
{
	char filename_buf[FN_MAX_SIZE] = {0};

	header->sub_cmd_type = 0x0;
	header->smp_length = sizeof(*header) - sizeof(header->header) + sizeof(memsize) + FN_MAX_SIZE;
	header->diag_length = header->smp_length - sizeof(header->smp_length) - sizeof(header->lcn) - sizeof(header->type) - sizeof(header->reserved) - sizeof(header->check_sum);
	header->check_sum = calc_checksum(((unsigned char *)header + sizeof(header->header)), 6);

	memcpy(&smp_string[0], (char*)(header), sizeof(*header));
	memcpy(&smp_string[sizeof(*header)], &memsize, sizeof(memsize));

	memcpy(filename_buf, filename, 72);
	memcpy(&smp_string[sizeof(*header) + sizeof(memsize)], filename_buf,FN_MAX_SIZE);

	usb_send(smp_string, header->smp_length + sizeof(header->header));

	return;
}

/*send the real data*/
void send_to_pc_midst(char *smp_string, smp_header_t * header, char *memaddr, uint64_t memsize)
{
	unsigned short data_size;
	unsigned long long j;

	header->sub_cmd_type = 0x1;

	if (memsize <= PKT_SZ_40K) {
		data_size = (unsigned short)memsize;
		header->smp_length = sizeof(*header) - sizeof(header->header) + data_size;
		header->diag_length = header->smp_length - sizeof(header->smp_length) - sizeof(header->lcn) - sizeof(header->type) - sizeof(header->reserved) - sizeof(header->check_sum);
		header->check_sum = calc_checksum(((unsigned char *)header + sizeof(header->header)), 6);

		memcpy(&smp_string[0], (char*)(header), sizeof(*header));
		memcpy(&smp_string[sizeof(*header)], memaddr,data_size);

		usb_send(smp_string, header->smp_length + sizeof(header->header));
	} else {
		for (j = 0; j < memsize / PKT_SZ_40K; j++) {
			data_size = (unsigned short)PKT_SZ_40K;
			header->smp_length = sizeof(*header) - sizeof(header->header) + data_size;
			header->diag_length = header->smp_length - sizeof(header->smp_length) - sizeof(header->lcn) - sizeof(header->type) - sizeof(header->reserved) - sizeof(header->check_sum);
			header->check_sum = calc_checksum(((unsigned char *)header + sizeof(header->header)),6);

			memcpy(&smp_string[0], (char*)(header), sizeof(*header));
			memcpy(&smp_string[sizeof(*header)], memaddr + j*PKT_SZ_40K, data_size);

			usb_send(smp_string, header->smp_length + sizeof(header->header));
		}
		if (memsize % PKT_SZ_40K) {
			data_size = (unsigned short)(memsize % PKT_SZ_40K);
			header->smp_length = sizeof(*header) - sizeof(header->header) + data_size;
			header->diag_length = header->smp_length - sizeof(header->smp_length) - sizeof(header->lcn) - sizeof(header->type) - sizeof(header->reserved) - sizeof(header->check_sum);
			header->check_sum = calc_checksum(((unsigned char *)header + sizeof(header->header)),6);

			memcpy(&smp_string[0], (char*)(header), sizeof(*header));
			memcpy(&smp_string[sizeof(*header)], memaddr + memsize - memsize % PKT_SZ_40K, data_size);

			usb_send(smp_string, header->smp_length + sizeof(header->header));
		}
	}
	return;
}

void send_to_pc_end(char *smp_string, smp_header_t * header)
{
	header->sub_cmd_type = 0x2;

	header->smp_length = sizeof(*header) - sizeof(header->header);
	header->diag_length = header->smp_length - sizeof(header->smp_length) - sizeof(header->lcn) - sizeof(header->type) - sizeof(header->reserved) - sizeof(header->check_sum);
	header->check_sum = calc_checksum(((unsigned char *)header + sizeof(header->header)), 6);

	memcpy(&smp_string[0], (char*)(header), sizeof(*header));

	usb_send(smp_string, header->smp_length + sizeof(header->header));

	return;
}

void send_to_pc_finish(char *smp_string, smp_header_t * header)
{
	header->sub_cmd_type = 0x3;

	header->smp_length = sizeof(*header) - sizeof(header->header);
	header->diag_length = header->smp_length - sizeof(header->smp_length) - sizeof(header->lcn) - sizeof(header->type) - sizeof(header->reserved) - sizeof(header->check_sum);
	header->check_sum = calc_checksum(((unsigned char *)header + sizeof(header->header)), 6);

	memcpy(&smp_string[0], (char*)(header), sizeof(*header));

	usb_send(smp_string, header->smp_length + sizeof(header->header));

	return;
}

void send_mem_to_pc(char *smp_string, char *filename, smp_header_t * header, char *memaddr, uint64_t memsize)
{
	dump_logd("writing 0x%llx bytes to pc file %s\n", memsize, filename);
	sysdump_lcd_printf("writing 0x%llx bytes to pc file %s\n", memsize, filename);
	send_to_pc_start(smp_string, filename,header, memsize);
	send_to_pc_midst(smp_string, header,memaddr, memsize);
	send_to_pc_end(smp_string, header);
	return;
}
int enter_sysdump_flag = 0;
/*	maybe full and mini dump reset allow will be different .*/
int is_fulldump_reset_allow(void)
{
	int reset_allow = 0;
	int rst_mode = check_dump_status_result.reset_mode;
	if (is_sysdump_boot_mode(rst_mode)) {
		reset_allow = 1;
	}
	return reset_allow;
}
int is_minidump_reset_allow(void)
{
	int reset_allow = 0;
	int rst_mode = check_dump_status_result.reset_mode;
	if (is_sysdump_boot_mode(rst_mode)) {
		reset_allow = 1;
	}
	return reset_allow;
}
int check_path_valid(void)
{
	int ret = 0;
	int fs_type = 0;
	/*	path sdcard 	*/
	dump_logd("  path_sdcard start .\n");
	if (init_mmc_fat(&fs_type)) {
		check_dump_status_result.path_sdcard = 0;
		check_dump_status_result.fs_type = FS_INVALID;
	} else {
		check_dump_status_result.path_sdcard = 1;
		check_dump_status_result.fs_type = fs_type;
	}
	dump_logd("%s fs_type = %d  path_sdcard : %d .\n", __FUNCTION__, fs_type, check_dump_status_result.path_sdcard);
	/*	path pc 	*/
	dump_logd("  path_pc start .\n");
	pkt_header_init(&pkt_header);
	if(usb_driver_init(USB_SPEED_HIGH)) {
		check_dump_status_result.path_pc = 0;
		dump_logd("usb_driver_init fail  .\n");
		return 0;
	}
	if(usb_serial_init()) {
		check_dump_status_result.path_pc = 0;
		dump_logd("usb_serial_init fail .\n");
		return 0;
	}
	check_dump_status_result.path_pc = 1;
	/*	path internal 	*/
	#ifdef CONFIG_FULLDUMP_INTERNAL_ENABLE
	if(is_fulldumpdb_exist) {
		check_dump_status_result.fulldump_internal_enbale = 1;
	} else {
		check_dump_status_result.fulldump_internal_enbale = 0;
		dump_loga("wxz : is_fulldumpdb_exist = %d  .\n", is_fulldumpdb_exist);
	}
	dump_loga("wxz : check_dump_status_result.fulldump_internal_enbale = %d  .\n", check_dump_status_result.fulldump_internal_enbale);
	#endif
	return 0;
}
void record_dumpdb_header_status(struct dumpdb_header *header_g)
{
	/* record the data type */
	if(sizeof(unsigned long) == sizeof(uint64_t)){
		header_g->dump_flag |= SIZEOF_UNSIGNED_LONG;
	}
	/* record the status whether the struct is packeted */
	header_g->dump_flag |= IS_STRUCT_PACKET;
}
int check_dump_enable_status(void)
{
	int ret = 0;

	/* get time value for later use */
	get_current_time();
	dump_logd("%s in -------------\n", __FUNCTION__);
	if (common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)(sizeof(struct dumpdb_header)), (uint64_t)0,(char *)&check_header_g)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, SYSDUMPDB_PARTITION_NAME);
		is_partition_ok = 0;
		return -1;
	}
	if((IS_ORIG_STATUS(check_header_g.dump_flag)) || (check_dump_status_result.reset_mode == CMD_RECOVERY_MODE)) {
		check_header_g.dump_flag &= SYSDUMP_STATUS_MASK;
		dump_logd("dump status is orig:  (0x%x)\n", check_header_g.dump_flag);
#ifdef DEBUG
		check_header_g.dump_flag |= AP_FULL_DUMP_ENABLE;
		dump_logd("Debug mode , set ap full dump enable default . (0x%x) \n", check_header_g.dump_flag);
#else
		check_header_g.dump_flag &= (~AP_FULL_DUMP_ENABLE);
		dump_logd("user mode , set ap full dump disenable default .  (0x%x)\n", check_header_g.dump_flag);
#endif
		check_header_g.dump_flag |= AP_MINI_DUMP_ENABLE;
		dump_logd("Always set ap mini dump enable default .  (0x%x) \n", check_header_g.dump_flag);

		/* record the status of dumpdb_header struct */
		record_dumpdb_header_status(&check_header_g);
		/*	updadte dump flag data */
		if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, sizeof(struct dumpdb_header), sizeof(struct dumpdb_header), 0, (char*)&check_header_g)) {
			dump_loge(" update dump flag  %s error.\n", SYSDUMPDB_PARTITION_NAME);
			return -1;
		}

		check_dump_status_result.full_dump_enable = !!(check_header_g.dump_flag & AP_FULL_DUMP_ENABLE);
		check_dump_status_result.mini_dump_enable = !!(check_header_g.dump_flag & AP_MINI_DUMP_ENABLE);

	} else {
		dump_logd("...Status Changed... , read saved status (0x%x)\n", check_header_g.dump_flag);
		check_dump_status_result.full_dump_enable = !!(check_header_g.dump_flag & AP_FULL_DUMP_ENABLE);
		check_dump_status_result.mini_dump_enable = !!(check_header_g.dump_flag & AP_MINI_DUMP_ENABLE);

	}

	dump_logd("full_dump_enable  status: %d .\n", check_dump_status_result.full_dump_enable);
	dump_logd("mini_dump_enable  status: %d .\n", check_dump_status_result.mini_dump_enable);
	if(check_dump_status_result.full_dump_enable && is_fulldump_reset_allow())
		check_dump_status_result.full_dump_allow =1;
	if(check_dump_status_result.mini_dump_enable && is_minidump_reset_allow())
		check_dump_status_result.mini_dump_allow =1;
	dump_logd("full_dump_allow  status: %d .\n", check_dump_status_result.full_dump_allow);
	dump_logd("mini_dump_allow  status: %d .\n", check_dump_status_result.mini_dump_allow);

	check_dump_status_result.is_auto_reboot = IS_DUMPFINISH_AUTOREBOOT(check_header_g.dump_flag);
	dump_logd("wxz is_auto_reboot: %d .\n", check_dump_status_result.is_auto_reboot);
	return 0;
}
void show_check_enable_status_result(void)
{

	dump_loga("------------------	%s 	------------------ .\n", __FUNCTION__);
	dump_loga("full_dump_enable : %d .\n", check_dump_status_result.full_dump_enable);
	dump_loga("mini_dump_enable : %d .\n", check_dump_status_result.mini_dump_enable);
	dump_loga("full_dump_allow  : %d .\n", check_dump_status_result.full_dump_allow);
	dump_loga("mini_dump_allow  : %d .\n", check_dump_status_result.mini_dump_allow);
	dump_loga("reset_mode       : (%x)-(%s) .\n", check_dump_status_result.reset_mode,GET_RST_MODE(check_dump_status_result.reset_mode));
	return;
}
void show_check_path_status_result(void)
{

	dump_loga("------------------	%s 	------------------ .\n", __FUNCTION__);
	dump_loga("path_sdcard      : %d .\n", check_dump_status_result.path_sdcard);
	dump_loga("fs_type          : (%d) .\n", check_dump_status_result.fs_type);
	dump_loga("fs_type          : (%d)-(%s) .\n", check_dump_status_result.fs_type, GET_FS(check_dump_status_result.fs_type));
	dump_loga("path_pc          : %d .\n", check_dump_status_result.path_pc);
	return;
}
void prepare_dump_mem_info(void)
{
	struct sysdump_info *infop = dump_input_contents_info.infop;
	if (!dt_info.dt_fail) {
#ifdef CONFIG_X86
		dump_input_contents_info.sprd_dump_mem_num = fill_dump_mem_auto_x86();
		dump_input_contents_info.infop->dump_mem_paddr = (unsigned long long)dump_input_contents_info.sprd_dump_mem;
#else
		dump_input_contents_info.sprd_dump_mem_num = fill_dump_mem_auto_arm();
		dump_input_contents_info.infop->dump_mem_paddr = (unsigned long)dump_input_contents_info.sprd_dump_mem;
#endif
	} else {
		dump_input_contents_info.sprd_dump_mem_num = get_total_dump_memory();
		dump_input_contents_info.infop->dump_mem_paddr = (unsigned long)dump_input_contents_info.sprd_dump_mem;
	}

	return;
}
int prepare_sd_env(void)
{
	SYSDUMP_LONG max_size = dump_input_contents_info.file_total_size;
	int fs_type = check_dump_status_result.fs_type;
	int mod =0;
	int key_code = 0;
	int ret = 0 ;

	dump_logd("FAT32 max space size is "LLX"\n",max_size);
	if(check_dump_status_result.dump_to_pc_flag != 1){
		if (fs_type == FS_FAT32) {
			dump_logd("FileSystem is FAT32 !!!\n");
			mod = fat_checksys(max_size);
			if (mod & FSFATAL) {
				sysdump_lcd_printf("\n SD Card is demaged !!!");
				sysdump_lcd_printf("\npress volumeup to format SD Card !!!\notherwise press volumedown to skip sysdump to sdcard!!!\n");
				dump_logd("\n SD Card is demaged !!!i\n");
				dump_logd("\npress volumeup to format SD Card !!!\notherwise press volumedown to skip sysdump to sdcard!!!\n");
				do {
					udelay(50 * 1000);
					key_code = board_key_scan();
					if (key_code == KEY_VOLUMEUP) {
						dump_logd("Key: KEY_VOLUMEUP , try to fat_format  !!!\n");
						fat_format();
						break;
					} else if(key_code == KEY_VOLUMEDOWN) {
						dump_logd("Key: KEY_VOLUMEDOWN , try to skip sysdump to sdcard  !!!\n");
						check_dump_status_result.dump_to_sd_fail = 1;
						return ERROR_FNISH;
					}
				} while (1);
			}
			ret = sysdump_cyclic_storage(fs_type,max_size);
			if (ret < 0){
				check_dump_status_result.dump_to_sd_fail = 1;
				dump_logd("sysdump_cyclic_storage fail...\n");
				return ERROR_FNISH;
			}
			dump_logd("check sysdump_auto_test.txt start!!!\n");
			if(check_folder_flag(SYSDUMP_AUTO_TEST)) {
				dump_logd("Now has existed sysdump_auto_test.txt, so jump wait_for_keypress !!!\n");
			}
			dump_logd("check sysdump_auto_test.txt end!!!\n");

		} else if (fs_type == FS_EXFAT) {
			dump_logd("FileSystem is exFAT !!!\n");

			mod = exfat_checksys(max_size);
			if (mod & FSSMSIZE) {
				dump_logd("SD card volume size is smaller then dumped size. Skip sysdump to sdcard!!!\n");
				check_dump_status_result.dump_to_sd_fail = 1;
				return ERROR_FNISH;
			}
			if (mod &(FSFATAL | FSNOSPACE)) {
				if (mod & FSFATAL)
					sysdump_lcd_printf("\nHello Baby: SD Card is demaged !!!");
				else if (mod & FSNOSPACE)
					sysdump_lcd_printf("\nHello Baby: SD Card has not enough space !!!");

				sysdump_lcd_printf("\npress volumeup to format SD Card !!!\notherwise press volumedown to skip sysdump to sdcard!!!\n");
				do {
					udelay(50 * 1000);
					key_code = board_key_scan();
					if (key_code == KEY_VOLUMEUP) {
						sysdump_lcd_printf("\nNow volumeup key is pressed !!!\nSD Card format starts........\n");
						ret = exfat_format();
						if (ret != 0) {
							sysdump_lcd_printf("\nSD Card format failed !!! Skip sysdump to sdcard!!!\n");
							check_dump_status_result.dump_to_sd_fail = 1;
							return ERROR_FNISH;
						}
						dump_logd("SD Card formatting done !!!\n");
						break;
					} else if(key_code == KEY_VOLUMEDOWN) {
						sysdump_lcd_printf("\nvolumeddown key is pressed and don't format SD Card !!!\nsysdump to sdcard will be skipped !!!\n");
						check_dump_status_result.dump_to_sd_fail = 1;
						return ERROR_FNISH;
					}
				} while (1);
			}
			ret = sysdump_cyclic_storage(fs_type,max_size);
			if (ret < 0){
				check_dump_status_result.dump_to_sd_fail = 1;
				dump_logd("sysdump_cyclic_storage fail...\n");
				return ERROR_FNISH;
			}
			dump_logd("check sysdump_auto_test.txt start!!!\n");
			if(!(dir_exfat_check(SYSDUMP_AUTO_TEST))) {
				dump_logd("Now has existed sysdump_auto_test.txt, so jump wait_for_keypress !!!\n");
			}
			dump_logd("check sysdump_auto_test.txt end!!!\n");
		}
		else {
			sysdump_lcd_printf("Invalid file system... Sysdump to sdcard  will be skipped !!!\n");
			check_dump_status_result.dump_to_sd_fail = 1;
			return ERROR_FNISH;
		}
	}
	return 0;
}
#ifdef CONFIG_X86
void x86_dump_info_crash_data(void)
{
	int m = 0, n = 0, n_max = 1024;
	uint32_t crash_data[n_max];

	n = crash_data_receive(crash_data, n_max);
	char info_crash_data[9216] = {0};/* info_crash_data's size = n_max*sizeof("%08X\n") */
	if (n < 0) {
		dump_logd("error receiving crash log\n");
	}else{
		dump_logd("crash log size: %d words\n", n);
		for (m = 0; m < n; m += 1) {
			dump_logd("%08X\n", crash_data[m]);
			snprintf(info_crash_data+9*m,9216,"%08X\n",crash_data[m]);
		}
		if(check_dump_status_result.dump_to_pc_flag != 1){
			sprintf(fnbuf,SYSDUMP_FOLDER_NAME"/1/Crashlog_%s.txt",dump_input_contents_info.infop->time);
			write_mem_to_mmc(path, fnbuf, fs_type, (char *)(info_crash_data), strlen(info_crash_data));
		} else {
			sprintf(fnbuf,"Crashlog_%s.txt", dump_input_contents_info.infop->time);
			send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(info_crash_data), (uint64_t)strlen(info_crash_data));
		}
	}
	return;
}
#endif
int save_allmem_to_file(void)
{
	unsigned long mem_virt;
	struct sysdump_mem *mem;
	sha1_context ctx;
	unsigned char sha1sum[20];
	char fnbuf[72] = {0}, *waddr;
	char *path = NULL;
	int i,j,k;
	int fs_type = check_dump_status_result.fs_type;
	char *check_sum = dump_input_contents_info.sysdump_checksum;
	int chk_length = dump_input_contents_info.chk_length;

	mem = (struct sysdump_mem *)dump_input_contents_info.infop->dump_mem_paddr;
	for (i = 0; i < dump_input_contents_info.sprd_dump_mem_num; i++) {
		if (0xffffffff != mem[i].soff) {
			dump_logd("------ mem[%d].soff is "LLX" ------\n", i, mem[i].soff);
			dump_logd("mem[%d].paddr is "LLX"\n", i, mem[i].paddr);
			waddr = (char *)dump_input_contents_info.infop + sizeof(struct sysdump_info) +
				dump_input_contents_info.elfhdr_size + mem[i].soff;
			dump_logd("but here waddr is "LLX"\n", waddr);
		} else {
			dump_logd("mem[%d].paddr is "LLX"\n", i, mem[i].paddr);
			dump_logd("mem[%d].size  is "LLX"\n", i, mem[i].size);
#ifdef CONFIG_X86
			if (mem[i].paddr > SYSDUMP_4GB) {  //if mem[i].paddr > SYSDUMP_4GB, mem[i].size should <= 512M
				cpu_paging_disable();
				mem_virt = cpu_page_remap(SYSDUMP_MAPPING_ADDR, mem[i].size, mem[i].paddr);

				if (!SPLIT_MEM_REGION) {
					cpu_paging_enable();
					memmove((void *)SYSDUMP_COPY_PADDR, (void *)mem_virt, mem[i].size);
					cpu_paging_disable();
					waddr = SYSDUMP_COPY_PADDR;
				} else {
					for (k=0; k<mem[i].size/SYSDUMP_256M; k++) {
						cpu_paging_enable();
						memmove((void *)SYSDUMP_COPY_PADDR, (void *)mem_virt+SYSDUMP_256M*k, SYSDUMP_256M);
						cpu_paging_disable();
						write_to_mmc_x86(path, fnbuf, fs_type, SYSDUMP_COPY_PADDR+k*SYSDUMP_256M, mem, i, k, SYSDUMP_256M);
					}
					if (mem[i].size%SYSDUMP_256M) {
						cpu_paging_enable();
						memmove((void *)SYSDUMP_COPY_PADDR, (void *)mem_virt+SYSDUMP_256M*k, mem[i].size%SYSDUMP_256M);
						cpu_paging_disable();
						write_to_mmc_x86(path, fnbuf, fs_type, SYSDUMP_COPY_PADDR+k*SYSDUMP_256M, mem, i, k, mem[i].size%SYSDUMP_256M);
					}
					return 0;
				}
			} else
#endif
			{
				waddr = mem[i].paddr;
			}

		}
#ifdef  CONFIG_SYSDUMP_FILE_CHECKSUM
		/*dump memory checksum start*/
		if(((unsigned int)waddr < CONFIG_SYS_TEXT_BASE) && (((unsigned int)waddr + mem[i].size) > CONFIG_SYS_TEXT_BASE))
			dump_loga("this memory section include uboot image, don't verify memory !!!\n");
		else {
			dump_logd("calculate dump memory "LLX"-"LLX" sha1 checksum !!!\n",(SYSDUMP_LONG)waddr, (SYSDUMP_LONG)waddr + mem[i].size - 1);
			sha1_starts(&ctx);
			sha1_update(&ctx, waddr, mem[i].size);
			sha1_finish(&ctx,sha1sum);
			chk_length += sprintf(check_sum + chk_length, SYSDUMP_CORE_NAME_FMT"_"LLX"-"LLX"_dump.lst ",
					i + 1, mem[i].paddr, mem[i].paddr + mem[i].size -1);
			for(j = 0; j < 20; j++)
				chk_length += sprintf(check_sum + chk_length, "%02x", sha1sum[j]);
			chk_length += sprintf(check_sum + chk_length, "\n");
		}
		/*dump memory checksum end*/
#endif

		if(check_dump_status_result.dump_to_pc_flag == 1){
 			sprintf(fnbuf, SYSDUMP_CORE_NAME_FMT"_"LLX"-"LLX"_dump.lst", i + 1, mem[i].paddr, mem[i].paddr+mem[i].size -1);
 			send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)waddr, (uint64_t)mem[i].size);
		} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
			sprintf(fnbuf, SYSDUMP_CORE_NAME_FMT"_"LLX"-"LLX"_dump.lst", i + 1, mem[i].paddr, mem[i].paddr+mem[i].size -1);
			send_data_to_internal(fnbuf, (char *)waddr, (uint64_t)mem[i].size);
		} else {
			write_to_mmc(path, fnbuf, fs_type, waddr, mem, i);
 		}

	}

	/*	update	chk_length */
	dump_input_contents_info.chk_length = chk_length;
	return 0;
}

int save_checksum_to_file(void)
{
	int chk_length = dump_input_contents_info.chk_length;
	char *checksum = dump_input_contents_info.sysdump_checksum;
	int fs_type = check_dump_status_result.fs_type;
	char fnbuf[72] = {0};
	char *path = NULL;

	/* write dump memory checksum to sd card*/
	if(check_dump_status_result.dump_to_pc_flag == 1){
 		dump_logd(" writing dump memory checksum to PC !!!\n");
 		sprintf(fnbuf, "sysdump-checksum.txt");
 		dump_logd("sysdump_checksum is 0x%x and check_length is 0x%x\n", strlen(checksum), chk_length);
 		send_mem_to_pc(dumpbuf_pc, fnbuf,&pkt_header, (char *)(checksum), (uint64_t)chk_length);
	} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
		dump_logd(" writing dump memory checksum to PC !!!\n");
		sprintf(fnbuf, "sysdump-checksum.txt");
		dump_logd("sysdump_checksum is 0x%x and check_length is 0x%x\n", strlen(checksum), chk_length);
		send_data_to_internal(fnbuf,(char *)(checksum), (uint64_t)chk_length);
	} else {
		dump_logd(" writing dump memory checksum to sd card !!!\n");
		sprintf(fnbuf,SYSDUMP_FOLDER_NAME"/1/sysdump-checksum.txt");
		dump_logd("sysdump_checksum is 0x%x and check_length is 0x%x\n", strlen(checksum), chk_length);
		write_mem_to_mmc(path, fnbuf, fs_type, (char *)(checksum), chk_length);
	}
	return 0;
}
void get_current_time(void)
{
	struct rtc_time tm;

	tm = get_time_by_sec();
	sprintf(dump_input_contents_info.infop->time, "%04d-%02d-%02d_%02d-%02d-%02d",
			tm.tm_year, tm.tm_mon, tm.tm_mday, \
			tm.tm_hour,tm.tm_min, tm.tm_sec);
	dump_logd("time is %s\n",dump_input_contents_info.infop->time);
	return;
}

int save_dumpinfo_to_file(void)
{
	char *txt_info = NULL;
	int s_length =0;
	char *string;
	int fs_type = check_dump_status_result.fs_type;
	char fnbuf[72] = {0};
	char *path = NULL;
	int i;
	int re_len = 0;
	int total_len = DUMPINFO_FILE_SIZE;
	int log_flag = 0;
	struct minidump_info *minidump_infop;

	txt_info = malloc(DUMPINFO_FILE_SIZE);
	if(txt_info == NULL){
		dump_logd("malloc error , want size 0x%x \n", DUMPINFO_FILE_SIZE);
		return -1;
	}

	string = txt_info;
	s_length = scnprintf(txt_info, total_len, "-%s%s\n-%s%x\n-%s%x\n-%s%s\n-%s%d\n-%s%d\n-%s%d\n-%s"LLX"\n\n",
			"time is ",
			dump_input_contents_info.infop->time,
			"reboot reg is ",
			reboot_reg,
			"reset mode is ",
			dump_rst_mode_g,
			"reason is ",
			GET_RST_MODE(check_dump_status_result.reset_mode),
			"elfhdr_size is ",
			dump_input_contents_info.elfhdr_size,
			"mem_num is ",
			dump_input_contents_info.sprd_dump_mem_num,
			"crash_key is ",
			dump_input_contents_info.infop->crash_key,
			"dump_mem_paddr is ",
			dump_input_contents_info.infop->dump_mem_paddr);
#if SPRD_SYSDUMP_MAGIC != RAMDISK_ADR
#ifdef CONFIG_ARM64
	/* record kernel vmcore info to txt file when sysdump-mem is reserved to (0x80001000) */
	dump_logd("\n%s\n-%s%llx\n-%s%llx\n-%s%llx\n-%s%lld\n\n",
			"Vmcoreinfo:",
			"kimage_voffset = 0x",
			dump_input_contents_info.infop->sprd_vmcoreinfo.kimage_voffset,
			"phys_offset = 0x",
			dump_input_contents_info.infop->sprd_vmcoreinfo.phys_offset,
			"kaslr_offset = 0x",
			dump_input_contents_info.infop->sprd_vmcoreinfo.kaslr_offset,
			"vabits_actual = ",
			dump_input_contents_info.infop->sprd_vmcoreinfo.vabits_actual);

	re_len = total_len - s_length;
	if(re_len > 0) {
		s_length += scnprintf(string + s_length, re_len, "%s\n%s%llx\n%s%llx\n%s%llx\n%s%lld\n\n",
				"Vmcoreinfo:",
				"[kimage_voffset]: 0x",
				dump_input_contents_info.infop->sprd_vmcoreinfo.kimage_voffset,
				"[phys_offset]: 0x",
				dump_input_contents_info.infop->sprd_vmcoreinfo.phys_offset,
				"[kaslr_offset]: 0x",
				dump_input_contents_info.infop->sprd_vmcoreinfo.kaslr_offset,
				"[vabits_actual]: ",
				dump_input_contents_info.infop->sprd_vmcoreinfo.vabits_actual);
	} else if(log_flag == 0){
		dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
		log_flag = 1;
	}
#endif
#endif
	/* record linux memory & reserved memory & dump memory to txt file */
	for(i = 0; i < linux_mem_num_g; i++) {
		re_len = total_len - s_length;
		if(re_len > 0) {
			s_length += scnprintf(string + s_length, re_len, "linux memory %d: "LLX"-"LLX"\n", i + 1,
					linux_memory[i].addr, linux_memory[i].addr + linux_memory[i].size);
		} else if(log_flag == 0){
			dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
			log_flag = 1;
		}
	}

	for(i = 0; i < reserved_mem_num_g; i++) {
		re_len = total_len - s_length;
		if(re_len > 0) {
			s_length += snprintf(string + s_length, re_len, "reserved memory %d: "LLX"-"LLX"\n", i + 1,
					reserved_memory[i].addr, reserved_memory[i].addr + reserved_memory[i].size);
		} else if(log_flag == 0){
			dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
			log_flag = 1;
		}
	}

	for(i = 0; i < dump_input_contents_info.sprd_dump_mem_num; i++) {
		re_len = total_len - s_length;
		if(re_len > 0) {
			s_length += scnprintf(string + s_length, re_len, "sprd dump memory %d: "LLX"-"LLX"\n", i + 1,
					dump_input_contents_info.sprd_dump_mem[i].paddr, dump_input_contents_info.sprd_dump_mem[i].paddr + dump_input_contents_info.sprd_dump_mem[i].size -1);
		} else if(log_flag == 0){
			dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
			log_flag = 1;
		}
	}

	re_len = total_len - s_length;
	if(re_len > 0) {
		s_length += scnprintf(string + s_length, re_len, "\n===========	[exception_time: %s]	===========\n ",dump_input_contents_info.infop->time);
	} else if (log_flag == 0) {
		dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
		log_flag = 1;
	}
	/* get minidump info data */
	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(&check_header_g, &backup_info_g));
	if(!minidump_infop){
		re_len = total_len - s_length;
		if(re_len > 0) {
			s_length += scnprintf(string + s_length, re_len, "\nno valid address, no info display=========== [exception_time: %s]=========== \n ",dump_input_contents_info.infop->time);
		} else if (log_flag == 0) {
			dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
			log_flag = 1;
		}
	} else {
		/*	check minidump info data kernel  magic ,make sure it is valid	*/
		if(check_header_magic_kernel(minidump_infop)){
			re_len = total_len - s_length;
			if(re_len > 0) {
				s_length += scnprintf(string + s_length, re_len, "\nno valid data, no info display=========== [exception_time: %s]===========\n ",dump_input_contents_info.infop->time);
			} else if (log_flag == 0) {
				dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
				log_flag = 1;
			}
		} else {
			re_len = total_len - s_length;
			if(re_len > 0) {
				s_length += scnprintf(string + s_length, re_len, "%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%s\n%s%d\n%s%s\n%s%s\n%s%s\n\0",
						"[exception_serialno]: ", minidump_infop->exception_info.exception_serialno,
						"[exception_kernel_version]: ", minidump_infop->exception_info.exception_kernel_version,
						"[exception_reboot_reason]: ", minidump_infop->exception_info.exception_reboot_reason,
						"[exception_panic_reason]: ", minidump_infop->exception_info.exception_panic_reason,
						"[exception_time]: ", minidump_infop->exception_info.exception_time,
						"[exception_file_info]: ", minidump_infop->exception_info.exception_file_info,
						"[exception_task_id]: ", minidump_infop->exception_info.exception_task_id,
						"[exception_task_family]: ", minidump_infop->exception_info.exception_task_family,
						"[exception_pc_symbol]: ", minidump_infop->exception_info.exception_pc_symbol,
						"[exception_stack_info]: ", minidump_infop->exception_info.exception_stack_info);
			} else if (log_flag == 0) {
				dump_logd("dump info buffer is full -- txt_info is 0x%x and s_length is 0x%x\n", DUMPINFO_FILE_SIZE, s_length);
				log_flag = 1;
			}
		}
	}
	dump_logd("txt_info is 0x%x and s_length is 0x%x\n", strlen(txt_info),s_length);
	if(check_dump_status_result.dump_to_pc_flag == 1){
 		sprintf(fnbuf, "%s", SYSDUMP_DUMPINFO_NAME);
 		send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(txt_info), (uint64_t)s_length);
	} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
		sprintf(fnbuf, "%s", SYSDUMP_DUMPINFO_NAME);
		send_data_to_internal(fnbuf, (char *)(txt_info), s_length);
	} else {
		sprintf(fnbuf,SYSDUMP_FOLDER_NAME"/1/%s", SYSDUMP_DUMPINFO_NAME);
		write_mem_to_mmc(path, fnbuf, fs_type, (char *)(txt_info), s_length);
	}

	free(txt_info);
	return 0;
}
void vmcoreinfo_append_str(const char *fmt, ...)
{
	va_list args;
	char buf[0x50];
	size_t r;
	va_start(args, fmt);
	r = vsnprintf(buf, sizeof(buf), fmt, args);
	va_end(args);

	r = min(r, (size_t)VMCOREINFO_BYTES - *vmcoreinfo_size);
	memcpy(&vmcoreinfo_data[*vmcoreinfo_size], buf, r);
	*vmcoreinfo_size += r;
}
void get_mmu_regs_info(void)
{
	uint32_t id;
	uint32_t i;
	uint32_t offset_len;
	uint64_t cpu_paddr[nr_cpus];
	struct sprd_debug_mmu_reg_t *sprd_debug_mmu_reg;

	id = dump_input_contents_info.infop->sprd_mmuregs_info.cpu_id;
	offset_len = dump_input_contents_info.infop->sprd_mmuregs_info.sprd_pcpu_offset;
	cpu_paddr[id] = dump_input_contents_info.infop->sprd_mmuregs_info.paddr_mmu_regs_t;
	dump_logd("id=0x%x, offset_len=0x%x, cpu_paddr[%d]=0x%llx\n", id, offset_len, id, cpu_paddr[id]);
	if (!is_paddr_linux_memory((unsigned long)cpu_paddr[id])){
		dump_loge("Invalid paddr!, do nothing...\n");
		return;
	}
        vmcoreinfo_append_str("SYMBOL(%s)=%d\n", "processor_id", id);
        vmcoreinfo_append_str("SYMBOL(%s)=%d\n", "per_cpu_offset", offset_len);
        vmcoreinfo_append_str("SYMBOL(%s)=0x%llx\n", "paddr_mmu_regs_id", cpu_paddr[id]);
	for (i = 0; i < nr_cpus; i++) {
		cpu_paddr[i] = cpu_paddr[id] + ((i - id) * offset_len);
		sprd_debug_mmu_reg = (struct sprd_debug_mmu_reg_t *)cpu_paddr[i];
		dump_logd("cpu %d, the paddr is 0x%llx\n", i, cpu_paddr[i]);
		if (!is_paddr_linux_memory((unsigned long)sprd_debug_mmu_reg)){
			dump_loge("the sprd_debug_mmu_reg is invalid, cpu %d, do nothing...\n", i);
			return;
		}
#ifdef CONFIG_ARM64
                vmcoreinfo_append_str("<%s> <%s> <%d> [sctlr_el1]=0x%llx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->sctlr_el1);
                vmcoreinfo_append_str("<%s> <%s> <%d> [ttbr0_el1]=0x%llx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->ttbr0_el1);
                vmcoreinfo_append_str("<%s> <%s> <%d> [ttbr1_el1]=0x%llx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->ttbr1_el1);
                vmcoreinfo_append_str("<%s> <%s> <%d> [tcr_el1]=0x%llx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->tcr_el1);
                vmcoreinfo_append_str("<%s> <%s> <%d> [mair_el1]=0x%llx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->mair_el1);
                vmcoreinfo_append_str("<%s> <%s> <%d> [amair_el1]=0x%lx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->amair_el1);
                vmcoreinfo_append_str("<%s> <%s> <%d> [contextidr_el1]=0x%llx\n",
					ARM64_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->contextidr_el1);
#elif defined CONFIG_X86
		vmcoreinfo_append_str("--------------X86,None\n", i);
#else
		vmcoreinfo_append_str("<%s> <%s> <%d> [SCTLR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->SCTLR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [TTBR0]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->TTBR0);
		vmcoreinfo_append_str("<%s> <%s> <%d> [TTBR1]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->TTBR1);
		vmcoreinfo_append_str("<%s> <%s> <%d> [TTBCR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->TTBCR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [DACR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->DACR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [DFSR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->DFSR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [DFAR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->DFAR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [IFSR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->IFSR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [IFAR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->IFAR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [DAFSR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->DAFSR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [IAFSR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->IAFSR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [PMRRR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->PMRRR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [NMRRR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->NMRRR);
		vmcoreinfo_append_str("<%s> <%s> <%d> [FCSEPID]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->FCSEPID);
		vmcoreinfo_append_str("<%s> <%s> <%d> [CONTEXT]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->CONTEXT);
		vmcoreinfo_append_str("<%s> <%s> <%d> [URWTPID]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->URWTPID);
		vmcoreinfo_append_str("<%s> <%s> <%d> [UROTPID]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->UROTPID);
		vmcoreinfo_append_str("<%s> <%s> <%d> [POTPIDR]=0x%x\n",
					ARM32_TYPE, MMU_REGS, i, sprd_debug_mmu_reg->POTPIDR);
#endif
	}
}
int extend_vmcoreinfo_buf(void)
{
	int i;
	uint32_t *log_first_idx, *log_next_idx;
	struct minidump_info *minidump_infop;

	nr_cpus = dump_input_contents_info.infop->sprd_mmuregs_info.cpu_numbers;

	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(&check_header_g, &backup_info_g));

	/* init vmcoreinfo stuff */
	if (!is_paddr_linux_memory(minidump_infop)) {
		dump_loge("no valid address, no save extend vmcoreinfo\n");
		return -1;
	} else {
		if (check_header_magic_kernel(minidump_infop)) {
			dump_loge("no valid data, save extend vmcoreinfo\n");
			return -1;
		}
		for (i = 0;i < minidump_infop->section_info_total.total_num;i++){
			if (!strcmp(minidump_infop->section_info_total.section_info[i].section_name,"extend_vmcoreinfo")) {
				vmcoreinfo_data = minidump_infop->section_info_total.section_info[i].section_start_paddr;
				break;
			}
		}
		if (i == minidump_infop->section_info_total.total_num) {
			dump_loge("no extend_vmcoreinfo!!\n");
			return -1;
		}
	}

	if(!is_paddr_linux_memory(vmcoreinfo_data)) {
		dump_loge("no valid address, no save extend vmcoreinfo\n ");
		return -1;
	}
	vmcoreinfo_size = dump_input_contents_info.infop->sprd_logbuf_info.vmcoreinfo_size;
	/* add log buf info */
	log_first_idx = dump_input_contents_info.infop->sprd_logbuf_info.log_first_idx;
	log_next_idx = dump_input_contents_info.infop->sprd_logbuf_info.log_next_idx;

	vmcoreinfo_append_str("SYMBOL(%s)=0x%lx\n", "log_buf",
				(unsigned long)dump_input_contents_info.infop->sprd_logbuf_info.log_buf);
	vmcoreinfo_append_str("SYMBOL(%s)=%d\n", "log_buf_len",
				dump_input_contents_info.infop->sprd_logbuf_info.log_buf_len);
	vmcoreinfo_append_str("SYMBOL(%s)=%d\n", "log_first_idx", *log_first_idx);
	vmcoreinfo_append_str("SYMBOL(%s)=%d\n", "log_next_idx", *log_next_idx);
	
	/* add percpu info */
	vmcoreinfo_append_str("SYMBOL(%s)=0x%llx\n", "per_cpu_start",
			dump_input_contents_info.infop->sprd_coreregs_info.pcpu_start_paddr);
	vmcoreinfo_append_str("SYMBOL(%s)=0x%llx\n", "core_regs_id",
			dump_input_contents_info.infop->sprd_coreregs_info.paddr_core_regs_t);
	
	/* add mmu regs info */
	get_mmu_regs_info();

	return 0;
}

int save_extend_bufs(void)
{
	int fs_type = check_dump_status_result.fs_type;
	char fnbuf[72] = {0};
	int i;
	int size = 0;
	char *addr = NULL;
	char *path = NULL;
	struct minidump_info *minidump_infop;

	/* get minidump info data */
	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(&check_header_g, &backup_info_g));

	if (!minidump_infop) {
		dump_loge("no valid address, no save_extend_bufs \n ");
		return -1;
	} else {
		/*	check minidump info data kernel  magic ,make sure it is valid	*/
		if (check_header_magic_kernel(minidump_infop)) {
			dump_loge("no valid data, save_extend_bufs \n ");
			return -1;
		} else {
			for (i = 0;i < minidump_infop->section_info_total.total_num;i++){
				dump_logd("section_info[%d].section_name: %s \n", i, minidump_infop->section_info_total.section_info[i].section_name);
				if (!strcmp(minidump_infop->section_info_total.section_info[i].section_name,"ylog_buf")) {
					size = minidump_infop->section_info_total.section_info[i].section_size;
					addr = minidump_infop->section_info_total.section_info[i].section_start_paddr;
					if(check_dump_status_result.dump_to_pc_flag == 1){
 						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
 						send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(addr), (uint64_t)size);
					} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
						send_data_to_internal(fnbuf, (char *)(addr), (uint64_t)size);
					} else {
						sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/%s", minidump_infop->section_info_total.section_info[i].section_name);
						write_mem_to_mmc(path, fnbuf, fs_type, (char *)(addr), size);
					}
				}
				if (!strcmp(minidump_infop->section_info_total.section_info[i].section_name,"scproc")) {
					size = minidump_infop->section_info_total.section_info[i].section_size;
					addr = minidump_infop->section_info_total.section_info[i].section_start_paddr;
					if(check_dump_status_result.dump_to_pc_flag == 1){
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
 						send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(addr), (uint64_t)size);
					} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
						send_data_to_internal(fnbuf, (char *)(addr), (uint64_t)size);
					} else {
						sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/%s", minidump_infop->section_info_total.section_info[i].section_name);
						write_mem_to_mmc(path, fnbuf, fs_type, (char *)(addr), size);
					}
				}
				if (!strcmp(minidump_infop->section_info_total.section_info[i].section_name,"vmcoreinfo")) {
					size = minidump_infop->section_info_total.section_info[i].section_size;
					addr = minidump_infop->section_info_total.section_info[i].section_start_paddr;
					if(check_dump_status_result.dump_to_pc_flag == 1){
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
						send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(addr), (uint64_t)size);
					} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
						send_data_to_internal(fnbuf, (char *)(addr), (uint64_t)size);
					} else {
						sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/%s", minidump_infop->section_info_total.section_info[i].section_name);
						write_mem_to_mmc(path, fnbuf, fs_type, (char *)(addr), size);
					}
				}
				if (strstr(minidump_infop->section_info_total.section_info[i].section_name, EXTEND_STRING)) {
					size = minidump_infop->section_info_total.section_info[i].section_size;
					addr = minidump_infop->section_info_total.section_info[i].section_start_paddr;
					if(!addr){
						dump_logd("%s:%s: invalid addr skip it  . \n", __FUNCTION__, minidump_infop->section_info_total.section_info[i].section_name);
						continue;
					}
					if(check_dump_status_result.dump_to_pc_flag == 1){
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
						send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(addr), (uint64_t)size);
					} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
						sprintf(fnbuf, "%s", minidump_infop->section_info_total.section_info[i].section_name);
						send_data_to_internal(fnbuf, (char *)(addr), (uint64_t)size);
					} else {
						sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/%s", minidump_infop->section_info_total.section_info[i].section_name);
						write_mem_to_mmc(path, fnbuf, fs_type, (char *)(addr), size);
					}
				}
			}
			if(i == minidump_infop->section_info_total.total_num)
				dump_logd(" no extend section found \n");
		}
	}
	return 0;
}
int save_elfheader_to_file(void)
{
	int fs_type = check_dump_status_result.fs_type;
	char fnbuf[72] = {0};
	char *path = NULL;
	struct sysdump_info *infop = dump_input_contents_info.infop;

	if(check_dump_status_result.dump_to_pc_flag == 1){
		sprintf(fnbuf, SYSDUMP_CORE_NAME_FMT, 0);
		send_mem_to_pc(dumpbuf_pc, fnbuf,&pkt_header, (char *)infop + sizeof(*infop), (uint64_t)dump_input_contents_info.elfhdr_size);
	} else if(fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
		sprintf(fnbuf, SYSDUMP_CORE_NAME_FMT, 0);
		send_data_to_internal(fnbuf, (char *)infop + sizeof(*infop), (uint64_t)dump_input_contents_info.elfhdr_size);
	} else {
 		sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/"SYSDUMP_CORE_NAME_FMT, 0);
 		write_mem_to_mmc(path, fnbuf, fs_type,
 				(char *)infop + sizeof(*infop), dump_input_contents_info.elfhdr_size);
	}
	return 0;
}

int checksum_elfheader(void)
{
	sha1_context ctx;
	unsigned char sha1sum[20];
	int chk_length = dump_input_contents_info.chk_length;
	char *check_sum = dump_input_contents_info.sysdump_checksum;
	struct sysdump_info *infop = dump_input_contents_info.infop;
	int j = 0;

	sha1_starts(&ctx);
	sha1_update(&ctx, (char *)infop + sizeof(*infop), dump_input_contents_info.elfhdr_size);
	sha1_finish(&ctx,sha1sum);
	chk_length += sprintf(check_sum + chk_length, SYSDUMP_CORE_NAME_FMT" ", 0);
	for(j = 0; j < 20; j++)
		chk_length += sprintf(check_sum + chk_length, "%02x", sha1sum[j]);
	chk_length += sprintf(check_sum + chk_length, "\n");

	/*	update	chk_length */
	dump_input_contents_info.chk_length = chk_length;
	return 0;
}

#ifdef CONFIG_ETB_DUMP
int save_etb_to_file(void)
{
	int fs_type = check_dump_status_result.fs_type;
	char fnbuf[72] = {0};
	char *path = NULL;

	dump_loga("\n Start to dump ETB trace data\n");
	sprd_etb_hw_dis();
	sprd_etb_dump();
	if(check_dump_status_result.dump_to_pc_flag == 1){
 		sprintf(fnbuf, "etbdata_uboot.bin");
 		send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(&etb_dump_mem[0]), (uint64_t)SZ_32K);
	} else if(fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO) {
		sprintf(fnbuf, "etbdata_uboot.bin");
		send_data_to_internal(fnbuf, (char *)(&etb_dump_mem[0]), (uint64_t)SZ_32K);
	} else {
		sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/etbdata_uboot.bin");
		write_mem_to_mmc(0, fnbuf, fs_type, &etb_dump_mem[0], etb_buf_size * 4);
	}
	dump_loga ("\n Dump ETB data finished\n");

	return 0;
}
#endif
int add_uboot_log_to_section(void)
{
	uint32_t size;
	int fs_type = check_dump_status_result.fs_type;
	struct section_extend_info section_extend_p;
	int ret = 0;

	/* save bootloader last log */
	section_extend_p.paddr = get_uboot_log_addr();
	if (!section_extend_p.paddr) {
		dump_loge("the addr of bootloader log buffer is 0x%lx\n", section_extend_p.paddr);
		return -1;
	}
	section_extend_p.size = get_uboot_log_len();
	section_extend_p.type = UBOOT_INFO;
	memset(section_extend_p.name, 0, EXTEND_NAME_MAX);
	memcpy(section_extend_p.name, BOOTLOADER_LAST_LOG, strlen(BOOTLOADER_LAST_LOG));
	ret = sysdump_save_extend_information(&section_extend_p);
	if (ret < 0) {
		dump_loge("add section: %s failed!!\n",BOOTLOADER_LAST_LOG);
		return -1;
	}

	dump_logd ("\nadd bootloader last log to section ok!!!\n");

	/* save bootloader previous time log */
	mini_pre_logbuffer = (char *)malloc(LOG_BUFFER_SIZE);
	if(!mini_pre_logbuffer){
		dump_loge("%s: %s malloc compress buf error , want size 0x%lx \n", SYSDUMPDB_LOG_TAG, __FUNCTION__, LOG_BUFFER_SIZE);
		return -1;
	}

	if (common_raw_read(UBOOT_LOG_PARTITION, (uint64_t)(LOG_BUFFER_SIZE), (uint64_t)(LAST_LOG_PARTITION_OFFSET),(char *)mini_pre_logbuffer)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, UBOOT_LOG_PARTITION);
		goto error_handle;
	}
	section_extend_p.paddr = mini_pre_logbuffer;
	section_extend_p.size = LOG_BUFFER_SIZE;
	section_extend_p.type = UBOOT_INFO;
	memset(section_extend_p.name, 0, EXTEND_NAME_MAX);
	memcpy(section_extend_p.name, BOOTLOADER_PRE_LOG, strlen(BOOTLOADER_PRE_LOG));

	ret = sysdump_save_extend_information(&section_extend_p);
	if (ret < 0) {
		dump_loge("add section: %s failed!!\n", BOOTLOADER_PRE_LOG);
		goto error_handle;
	}

	dump_logd ("\nadd bootloader log to section successfully!!!\n");
	return 0;


error_handle:
	if(mini_pre_logbuffer){
		free(mini_pre_logbuffer);
		mini_pre_logbuffer = NULL;
	}
	return -1;
}
int update_reset_mode_from_dump(void)
{
	struct dumpdb_header header_g;
	dump_logd(" %s .\n", GET_RST_MODE(check_dump_status_result.reset_mode));
	if (common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)(sizeof(header_g)), (uint64_t)0,(char *)&header_g)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, SYSDUMPDB_PARTITION_NAME);
		is_partition_ok = 0;
		return -1;
	}

	if(IS_BOOT_FROM_DUMP(header_g.dump_flag)) {
		dump_logd(" ----   IS_BOOT_FROM_DUMP   TRUE-----  (0x%x)\n", header_g.dump_flag);
		/*	clear BOOT_FROM_DUMP_STATUS flag bit */
		header_g.dump_flag &= (~BOOT_FROM_DUMP_STATUS);
		/*	set env for bootmode */
		setenv("bootmode", GET_RST_MODE(header_g.reset_mode));

		/*      updadte dump flag data */
		if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, sizeof(struct dumpdb_header), sizeof(struct dumpdb_header), 0, (char*)&header_g)) {
			dump_loge("  %s error.\n", SYSDUMPDB_PARTITION_NAME);
			return -1;
		}

	} else {
		dump_logd(" ----   IS_BOOT_FROM_DUMP   FALSE-----  (0x%x)\n", header_g.dump_flag);
	}
	return 0;
}
int save_reset_mode_after_dump(void)
{
	struct dumpdb_header header_g;
	if (common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)(sizeof(header_g)), (uint64_t)0,(char *)&header_g)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, SYSDUMPDB_PARTITION_NAME);
		is_partition_ok = 0;
		return -1;
	}
	/*	set BOOT_FROM_DUMP_STATUS flag bit */
	header_g.dump_flag |= BOOT_FROM_DUMP_STATUS;
	dump_logd(" set BOOT_FROM_DUMP_STATUS flag bit \n");
	header_g.reset_mode = check_dump_status_result.reset_mode;
	dump_logd(" save reset mode for dump update -----  (%s)\n", GET_RST_MODE(check_dump_status_result.reset_mode));

	/*      updadte dump flag data */
	if (sysdumpdb_write(SYSDUMPDB_PARTITION_NAME, sizeof(struct dumpdb_header), sizeof(struct dumpdb_header), 0, (char*)&header_g)) {
		dump_loge("  %s error.\n", SYSDUMPDB_PARTITION_NAME);
		return -1;
	}

	return 0;
}

void display_sysdump_info(int rst_mode)
{
	int i, l, n;
	struct minidump_info *minidump_infop;

	/* get minidump info data */
	minidump_infop = (struct minidump_info *)(get_minidump_info_paddr(&check_header_g, &backup_info_g));
	if(!is_paddr_linux_memory(minidump_infop)){
		sysdump_lcd_printf("no valid address, no info display \n");
		return;
	} else {
		/* check minidump info data kernel  magic ,make sure it is valid */
		if(check_header_magic_kernel(minidump_infop)){
			sysdump_lcd_printf("no valid data, no info display \n");
			return;
		}
		update_exception_info(minidump_infop, rst_mode);
		sysdump_lcd_printf("exception_file_info:\n%s\n ", minidump_infop->exception_info.exception_file_info);
		sysdump_lcd_printf("exception_panic_reason:\n%s\n ", minidump_infop->exception_info.exception_panic_reason);

		/* printf exception stack info to lcd */
		char *p = minidump_infop->exception_info.exception_stack_info;
		l = strlen(p);
		n = (l - (l % 1024)) / 1024;
		sysdump_lcd_printf("exception_stack_info:\n");
		for(i = 0; i < n; i++)
		{
			sysdump_lcd_printf("%1024.1024s", p + i*1024);
		}
		sysdump_lcd_printf("%s\n", p + n * 1024);
		/* printf exception stack info to lcd end */

	}
}
void set_prestatus_recored_flag(void)
{
	int test = 0;
	int dump_flag = 0;
	if (common_raw_read("fulldumpdb", (uint64_t)sizeof(test), (uint64_t)0,(char *)&test)) {

		is_fulldumpdb_exist = 0;

		if (0 != common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)sizeof(dump_flag), (uint64_t)SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE, &dump_flag)) {
		}

		dump_flag &=(~(0xf << SYSDUMPDB_PARTITION_DUMP_FLAG_OFFSET));
		if (common_raw_write(SYSDUMPDB_PARTITION_NAME, (uint64_t)sizeof(dump_flag), (uint64_t)sizeof(dump_flag), (uint64_t)SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE, &dump_flag)) {
			printf("fulldumpdb partition is  not exsit ... mark flag fail \n");
		} else {
			printf("fulldumpdb partition is  not exsit ... mark flag ok \n");
		}


	} else {

		is_fulldumpdb_exist = 1;

		if (0 != common_raw_read(SYSDUMPDB_PARTITION_NAME, (uint64_t)sizeof(dump_flag), (uint64_t)SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE, &dump_flag)) {
		}

		dump_flag |= ('Y' << SYSDUMPDB_PARTITION_DUMP_FLAG_OFFSET);
		if (common_raw_write(SYSDUMPDB_PARTITION_NAME, (uint64_t)sizeof(dump_flag), (uint64_t)sizeof(dump_flag), (uint64_t)SYSDUMPDB_PARTITION_DUMP_FLAG_SIZE, &dump_flag)) {
			printf("fulldumpdb partition is  exsit ... mark flag fail \n");
		} else {
			printf("fulldumpdb partition is  exsit ... mark flag ok \n");
		}
	}
}
int save_bootloader_log(void)
{
	int fs_type = check_dump_status_result.fs_type;
	char fnbuf[72] = {0};
	int size = 0;
	char *addr = NULL;
	char* pre_log_buffer = NULL;
	char *path = NULL;

	/* save last log */
	addr = get_uboot_log_addr();
	size = get_uboot_log_len();

	if(check_dump_status_result.dump_to_pc_flag == 1){
		sprintf(fnbuf, "bootloader_last_log");
		send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(addr), (uint64_t)size);
	 } else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO){
                sprintf(fnbuf, "bootloader_last_log");
                send_data_to_internal(fnbuf, (char *)(addr), (uint64_t)size);
	} else {
		sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/%s", "bootloader_last_log");
		write_mem_to_mmc(path, fnbuf, fs_type, (char *)(addr), size);
	}
	dump_logd("save bootloader last log sucessfully.\n");

	/* save previous log */
	pre_log_buffer = (char *)malloc(LOG_BUFFER_SIZE);
	if(!pre_log_buffer){
		dump_loge("%s: %s malloc compress buf error, want size %d \n", SYSDUMPDB_LOG_TAG, __FUNCTION__, LOG_BUFFER_SIZE);
		return -1;
	}
	if (common_raw_read(UBOOT_LOG_PARTITION, (uint64_t)(LOG_BUFFER_SIZE), (uint64_t)(LAST_LOG_PARTITION_OFFSET),(char *)pre_log_buffer)){
		dump_loge("%s: read header from %s error.do nothing \n", SYSDUMPDB_LOG_TAG, UBOOT_LOG_PARTITION);
		free(pre_log_buffer);
		return -1;
	}

	addr = pre_log_buffer;
	size = LOG_BUFFER_SIZE;

	if(check_dump_status_result.dump_to_pc_flag == 1){
		sprintf(fnbuf, "bootloader_pre_log");
		send_mem_to_pc(dumpbuf_pc, fnbuf, &pkt_header, (char *)(addr), (uint64_t)size);
	} else if (fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO){
		sprintf(fnbuf, "bootloader_pre_log");
		send_data_to_internal(fnbuf, (char *)(addr), (uint64_t)size);
	} else {
		sprintf(fnbuf, SYSDUMP_FOLDER_NAME"/1/%s", "bootloader_pre_log");
		write_mem_to_mmc(path, fnbuf, fs_type, (char *)(addr), size);
	}
	dump_logd("save bootloader previous time log sucessfully.\n");

	free(pre_log_buffer);

	return 0;

}
void write_sysdump_before_boot(int rst_mode)
{
	struct sysdump_info *infop = NULL;
	unsigned long sprd_sysdump_magic = 0;
	int i, j, k, ret;

	char fnbuf[72] = {0}, *path, *waddr, *check_sum;

	dump_rst_mode_g = rst_mode;
	sprd_sysdump_magic = SPRD_SYSDUMP_MAGIC;

	memset(&check_dump_status_result , 0, sizeof(struct check_dump_status_result));
	memset(&dt_info, 0, sizeof(struct dt_info));
	memset(&dump_input_contents_info, 0, sizeof(struct dump_input_contents_info));
	dump_input_contents_info.infop = (struct sysdump_info *)sprd_sysdump_magic;
	memcpy(&backup_info_g, dump_input_contents_info.infop, sizeof(struct sysdump_info));

	/*	init check itmes and call all check func	*/
	check_dump_status_result.reset_mode = rst_mode;
	check_dump_status_result.sprd_sysdump_magic = SPRD_SYSDUMP_MAGIC;
	dump_loga("Check dump info ......\n");
	for (i = 0;  i < CHECK_FUNC_MAX; i++) {
		/*func pointer NULL will break */
		if (!apdump_check_func_list[i])
			break;
		if (apdump_check_func_list[i]()){
			dump_loge("check list func (%d) error  !!!\n", i);
			/* is_partition_ok is TRUE means partition exsit, otherwise, we do not goto finish here ,just continue. */
			if(is_partition_ok) {
				dump_loge(" is_partition_ok = %d  goto finish!!!\n", is_partition_ok);
				goto FINISH;
			} else {
				dump_loge(" is_partition_ok = %d  continue!!!\n", is_partition_ok);
				continue;
			}
		}
	}
	set_prestatus_recored_flag();
	show_check_enable_status_result();

	if(is_partition_ok) {
		/* To be compatible with no partition version, when partition exsit, update sysdump_flag ,use new status from partiton */
		/*when is_partition_ok true and boot mode not CMD_UNDEFINED_MODE , we need update  boot mode if boot from dump */
		add_uboot_log_to_section();
		update_reset_mode_from_dump();
		sysdump_flag = check_dump_status_result.full_dump_enable;
#ifdef CONFIG_SPRD_MINI_SYSDUMP
		/*	if partition_ok ,do minidump frist */
		if(!check_dump_status_result.mini_dump_allow) {
			dump_loga("is_partition_ok : %d , mini_dump_allow : %d .  !!!\n", is_partition_ok, check_dump_status_result.mini_dump_allow);
			dump_loga("NO need minidump !!!\n");
		} else {
			save_sysdumpdb(rst_mode);
		}
#endif
		if(!check_dump_status_result.full_dump_allow) {
			dump_loga("is_partition_ok : %d , full_dump_allow : %d .  !!!\n", is_partition_ok, check_dump_status_result.full_dump_allow);
			dump_loga("NO need full  dump memory !!!\n");
			return;
		}
	} else {
		if (!sysdump_flag)
			check_dump_status_result.reset_mode = CMD_NORMAL_MODE;

		if(!is_fulldump_reset_allow()) {
			dump_loga("sysdump_flag : %d  .  !!!\n", sysdump_flag);
			dump_loga("NO need full dump memory !!!\n");
			return;
		}
	}
	dump_loga("Now enter in sysdump!!!\n");

	enter_sysdump_flag = 1;
#ifndef DEBUG
	stop_watchdog();/* stop watch_dog on user version */
#endif
	display_sysdump_header();
	display_sysdump_info(rst_mode);
	if(ERROR_FNISH == init_dt_info())
		goto FINISH;

	check_path_valid();
	show_check_path_status_result();

retry_dump_to_pc:
	if(check_dump_status_result.dump_to_pc_flag != 1 && !(fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO)){
 		/*	sdcard invalid , goto finish ,if path_pc ok ,will try dump to pc */
 		if (!check_dump_status_result.path_sdcard) {
 			dump_loge("ERROR: init_mmc_fat,fs_type=%d.\n", check_dump_status_result.fs_type);
 			sysdump_lcd_printf("\ninit_mmc_fat failed, Please check SD Card!!!.\n");
 			check_dump_status_result.dump_to_sd_fail = 1;
			dump_loge("wxz : check_dump_status_result.dump_to_sd_fail =%d.\n", check_dump_status_result.dump_to_sd_fail);
 			goto FINISH;
 		}
 	} else {
		/*  Only fulldump2internal done , we try dump2pc  */
		if(check_dump_status_result.fulldump_internal_enbale && (fulldump_to_internal_status.save_status == FULLDUMP_INTER_INITED)) {
			dump_loga(" We do fulldump2internal first , then try to dump2pc  !!!\n");
		} else {
			if (!check_dump_status_result.path_pc) {
				dump_loge("ERROR: init usb driver or serial failed  .\n");
				sysdump_lcd_printf("\ninit usb driver or serial failed !! abort dump to pc.\n");
 				goto FINISH;
			}
			sysdump_lcd_printf("\nDump to PC start..\ncheck usb cable's status or check key volumn up pressed to abort\n");
			do {
				dump_loga("check usb cable's status  !!!\n");
				ret = usb_sysdump_handler();
				if (ret == -1) {
					goto FINISH;
				} else if (ret == 1)
					break;
			}while(1);
			usb_init(1); /*need the ops after handler to re-init usb driver */
		}
 	}
	/*	prepare dump mem info */
	prepare_dump_mem_info();
	/*	check split dump mem  */
	check_split_dump_mem();
	get_elfhdr_ptload_mem();
	dump_input_contents_info.elfhdr_size = get_elfhdr_size(dump_input_contents_info.sprd_ptload_mem_num);
	sysdump_fill_core_hdr(NULL,
			dump_input_contents_info.sprd_ptload_mem,
			dump_input_contents_info.sprd_ptload_mem_num,
			(char *)dump_input_contents_info.infop + sizeof(struct sysdump_info),
			dump_input_contents_info.elfhdr_size);

	if (rst_mode != CMD_PANIC_REBOOT)
		dump_input_contents_info.infop->crash_key = 0;

	get_sprd_dump_size_auto();
	if(check_dump_status_result.dump_to_pc_flag != 1 && !(fulldump_to_internal_status.save_status > FULLDUMP_INTER_UNDO)){
		if(ERROR_FNISH == prepare_sd_env())
 		goto FINISH;
	}
#ifdef CONFIG_X86
	x86_dump_info_crash_data();
#endif
	/* NOTE: RAM_active must be located before cm4-mem saved */
#ifdef CONFIG_ARM7_RAM_ACTIVE
	pmic_arm7_RAM_active();
#endif
	save_dumpinfo_to_file();
	save_elfheader_to_file();
#ifdef  CONFIG_SYSDUMP_FILE_CHECKSUM
	checksum_elfheader();
#endif

	save_allmem_to_file();
#ifdef  CONFIG_SYSDUMP_FILE_CHECKSUM
	save_checksum_to_file();
#endif
	save_bootloader_log();
	save_extend_bufs();
#ifdef CONFIG_ETB_DUMP
	save_etb_to_file();
#endif

#if 0
#ifdef CONFIG_NAND_BOOT
	sysdump_lcd_printf("\nBegin to dump nand flash:\n");
	mtd_dump(check_dump_status_result.fs_type);
#endif
#endif
	if((fulldump_to_internal_status.save_status == FULLDUMP_INTER_DOING) || 
	   (fulldump_to_internal_status.save_status == FULLDUMP_INTER_ABORT)) {
		/* fulldump2internal fail  */
		if(fulldump_to_internal_status.save_status  == FULLDUMP_INTER_ABORT) {
			dump_loga("\n fullfump_internal writing fail...\n");
		}
		/* fulldump2internal pass */
		if(fulldump_to_internal_status.save_status == FULLDUMP_INTER_DOING) {
			dump_loga("\n fullfump_internal writing finish...\n");
			fulldump_to_internal_finish();
		}
		/* whatever fulldump2internal pass or fail all jump to FINISH , try dump2pc  */
		sysdump_lcd_printf(" fulldump2internal finish !\n");
	}

	if(check_dump_status_result.dump_to_pc_flag == 1){
		send_to_pc_finish(dumpbuf_pc,&pkt_header);
	}
	dump_logd("\nwriting done.\nPress any key to continue...\n");
	sysdump_lcd_printf("\nWriting done.\nPress any key (Exp power key) to continue...");
	led_sysdump_complete();
	if(!check_dump_status_result.is_auto_reboot)
		wait_for_keypress();
FINISH:
	if(check_dump_status_result.dump_to_sd_fail == 1) {
 		check_dump_status_result.dump_to_sd_fail = 0;
		/* dump2sd fail , whne fulldump2internal enable, do it first ,then dump2pc */
	if(check_dump_status_result.fulldump_internal_enbale && !fulldump_to_internal_status.save_status) {
			/* fulldump_to_internal enable and UNDO  */
			dump_loge ("sysdump to sdcard fail , Do fulldump2internal first !!!\n");
			sysdump_lcd_printf("sysdump to sdcard fail ,Do fulldump2internal first !!!\n");
			/* In fact , this circle, we do fulldump2internal */
			fulldump_to_internal_init();
			goto retry_dump_to_pc;
		} else {
#ifndef CONFIG_DUMP2PC_DISENABLE
			sysdump_lcd_printf("Try to do dump to pc now  !!");
			check_dump_status_result.dump_to_pc_flag = 1;
			led_dump2pc_wait_usb();
			goto retry_dump_to_pc;
#endif
		}
	}
	led_sysdump_reboot();
	/* uninit sd crad */
	sprd_mmc_exit(1);
#if (defined CONFIG_X86) && (defined CONFIG_MOBILEVISOR)
	reset_to_normal(CMD_NORMAL_MODE);
#endif
	dump_loga ("sysdump  finish or happen abnormally!!!\n");
	if(is_partition_ok) {
		/* indicate sysdump process in partition and record reset mode */
		save_reset_mode_after_dump();
		dump_loga ("sysdump reboot (reset_cpu)!!!\n");
		write_log();
		reboot_devices(CMD_NORMAL_MODE);
	}
	return;
}
