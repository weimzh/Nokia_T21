#include <common.h>
#include <asm/io.h>
#include <android_bootimg.h>
#include "loader_common.h"
#include <malloc.h>
#include <ext_common.h>
#include <ext4fs.h>
#include <linux/sizes.h>
#include "dl_operate.h"
#include "sci_img.h"
#include "sprd_common_rw.h"
#include "cp_mem_decoupling.h"
#include <chipram_env.h>
#include <logo_bin.h>
#ifdef  CONFIG_SPRD_HW_I2C_V2
#include <sprd_i2c_hwchn.h>
#endif
#ifdef  CONFIG_SPRD_HW_I2C
#include <sprd_i2c_hwchn.h>
#endif

#include <secureboot/sprdsec_header.h>
#include <secureboot/sec_common.h>
#include <uboot_sec_drv.h>
#include <avb/uboot_avb_ops.h>
#include <otp_helper.h>
#include <stdio_dev.h>
#ifdef CONFIG_SECBOOT
#include <lcd_console.h>
#endif
#ifdef CONFIG_ARM7_RAM_ACTIVE
extern void pmic_arm7_RAM_active(void);
#endif

#ifdef CONFIG_MINI_TRUSTZONE
#include "trustzone_def.h"
#endif

#ifdef CONFIG_SECURE_BOOT
#include "secure_boot.h"
#include "secure_verify.h"
#include <linux/types.h>
#endif

#ifdef CONFIG_OF_LIBFDT
#include <libfdt.h>
#include "dev_tree.h"
#endif
#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
#include <linux/input.h>
extern unsigned char board_key_scan(void);
#endif

#if (defined CONFIG_SECBOOT) && (defined CONFIG_VBOOT_V2)
unsigned long os_version __attribute__((aligned(4096))); /*must be PAGE ALIGNED*/
unsigned char root_of_trust_str[ROOT_OF_TRUST_MAXSIZE] __attribute__((aligned(4096)));
#endif

#ifdef CONFIG_BOARD_KERNEL_CMDLINE
unsigned char vendorboot_cmdline[VENDOR_BOOT_ARGS_SIZE];
#endif

DECLARE_GLOBAL_DATA_PTR;

extern int s_efused;
extern int low_bat;
extern unsigned cmd_fastboot;
extern int lcd_low_bat;
extern int lcd_line_length;
extern enVerifiedState g_verifiedbootstate;

extern int fdt_fixup_memory_region(void *fdt, int *auto_mem_num_p);
extern int get_dt_end_addr(void *fdt, uchar **addr);
extern int lcd_get_size(int *line_length);
extern unsigned char _chkNVEcc(uint8_t *buf, uint64_t size, uint32_t checksum);
extern void wakeup_source_enable();
extern void ap_clk_doze_enable();

extern int s_boot_mode;

#define MODEM_MAGIC		"SCI1"
#define MODEM_HDR_SIZE		(12 * 512) //size of a block
#define SCI_TYPE_MODEM_BIN	1
#define SCI_TYPE_PARSING_LIB	2
#define SCI_LAST_HDR		0x100
#define MODEM_SHA1_HDR		0x400
#define MODEM_SHA1_SIZE		20

#define FREE_RAM_SPACE_ADDR		0x9d000000 /* 0x9d000000 ~9f000000  30M Bytes Free*/
/*secure lcs*/
#define SECURE_LCS               0x5

#define DT_TABLE_MAGIC 0xd7b7ab1e

struct dt_table_header {
	uint32_t magic;
	uint32_t total_size;
	uint32_t header_size;
	uint32_t dt_entry_size;
	uint32_t dt_entry_count;
	uint32_t dt_entries_offset;
	uint32_t page_size;
	uint32_t reserved[1];
};
struct dt_table_entry {
	uint32_t dt_size;
	uint32_t dt_offset;
	uint32_t id;
	uint32_t rev;
	uint32_t custom[4];
};

typedef struct {
	uint32_t type_flags;
	uint32_t offset;
	uint32_t length;
} data_block_header_t;

static char boot_v3[128] = "boot";
static char vendor_boot_v3[128] = "vendor_boot";

typedef struct {
	char *bootimg_part;            /* partition name of boot.img */
	char *vendor_boot_part;        /* partition name of vendor boot image */
	uint64_t page_size;		/* page_size */
	uint64_t hdr_offset;		/* boot_image_hdr offset on storage*/
	uint64_t kernel_offset;	/* kernel offset */
	uint64_t ramdisk_offset;	/* generic ramdisk offset on v3 */
	uint64_t dt_offset;		/* dtb offset */
	uint64_t recovery_dtbo_offset;	/* recovery dtbo/acpio */
	uint64_t vendor_hdr_offset;	/* vendor boot header offset on vendor_boot_part */
	uint64_t vendor_ramdisk_offset;/* vendor ramdisk offset */
	uint64_t vendor_bootconfig_offset;/* vendor bootconfig offset */
	uint64_t vendor_ramdisk_table_offset;/* vendor ramdisk table offset */
	char *dtb_part;		/* dtb partition name */
	char *dtbo_part;		/* dtbo partition name */
	uint64_t dt_size;		/* dtb size */
	uint64_t vendor_ramdisk_size;
	uint64_t vendor_bootconfig_size;
	uint64_t vendor_ramdisk_table_size;
} boot_img_info_t;
static boot_img_info_t s_bootimg_info;
unsigned int g_DeviceStatus = VBOOT_STATUS_LOCK;
unsigned int g_DtboIndex = 0;


#ifdef CONFIG_SUPPORT_TDLTE
static boot_image_required_t const s_boot_image_tl_table[] = {
#if !defined( CONFIG_KERNEL_BOOT_CP )
	{"tl_fixnv1", "tl_fixnv2", LTE_FIXNV_SIZE, LTE_FIXNV_ADDR},
	{"tl_runtimenv1", "tl_runtimenv2", LTE_RUNNV_SIZE, LTE_RUNNV_ADDR},
	{"tl_modem", NULL, LTE_MODEM_SIZE, LTE_MODEM_ADDR},
	{"tl_ldsp", NULL, LTE_LDSP_SIZE, LTE_LDSP_ADDR},	//ltedsp
	{"tl_tgdsp", NULL, LTE_GDSP_SIZE, LTE_GDSP_ADDR},
#endif
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_WLTE
static boot_image_required_t const s_boot_image_wl_table[] = {
#if !defined( CONFIG_KERNEL_BOOT_CP )
	{"wl_fixnv1", "wl_fixnv2", LTE_FIXNV_SIZE, LTE_FIXNV_ADDR},
	{"wl_runtimenv1", "wl_runtimenv2", LTE_RUNNV_SIZE, LTE_RUNNV_ADDR},
	{"wl_modem", NULL, LTE_MODEM_SIZE, LTE_MODEM_ADDR},
	{"wl_ldsp", NULL, LTE_LDSP_SIZE, LTE_LDSP_ADDR},
	{"wl_gdsp", NULL, LTE_GDSP_SIZE, LTE_GDSP_ADDR},
	{"wl_warm", NULL, WL_WARM_SIZE, WL_WARM_ADDR},
#endif
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_GSM
static boot_image_required_t const s_boot_image_gsm_table[] = {
#if !defined( CONFIG_KERNEL_BOOT_CP )
	{"g_fixnv1", "g_fixnv2", GSM_FIXNV_SIZE, GSM_FIXNV_ADDR},
	{"g_runtimenv1", "g_runtimenv2", GSM_RUNNV_SIZE, GSM_RUNNV_ADDR},
	{"g_modem", NULL, GSM_MODEM_SIZE, GSM_MODEM_ADDR},
	{"g_dsp", NULL, GSM_DSP_SIZE, GSM_DSP_ADDR},
#endif
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_LTE
static boot_image_required_t const s_boot_image_lte_table[] = {
#if (!defined( CONFIG_KERNEL_BOOT_CP )) && (!defined(CONFIG_MEM_LAYOUT_DECOUPLING))
#ifdef CONFIG_ADVANCED_LTE
	{"l_fixnv1","l_fixnv2",LTE_FIXNV_SIZE,LTE_FIXNV_ADDR},
	{"l_runtimenv1","l_runtimenv2",LTE_RUNNV_SIZE,LTE_RUNNV_ADDR},
	{"l_modem",NULL,LTE_MODEM_SIZE,LTE_MODEM_ADDR},
	{"l_tgdsp",NULL,LTE_TGDSP_SIZE ,LTE_TGDSP_ADDR}, //tddsp
	{"l_ldsp",NULL,LTE_LDSP_SIZE ,LTE_LDSP_ADDR},
#else
	{"l_fixnv1", "l_fixnv2", LTE_FIXNV_SIZE, LTE_FIXNV_ADDR},
	{"l_runtimenv1", "l_runtimenv2", LTE_RUNNV_SIZE, LTE_RUNNV_ADDR},
	{"l_modem", NULL, LTE_MODEM_SIZE, LTE_MODEM_ADDR},
	{"l_ldsp", NULL, LTE_LDSP_SIZE, LTE_LDSP_ADDR},
	{"l_gdsp", NULL, LTE_GDSP_SIZE, LTE_GDSP_ADDR},
	{"l_warm", NULL, WL_WARM_SIZE, WL_WARM_ADDR},
#endif
#endif
#ifdef  CONFIG_ADVANCED_LTE
#ifdef CONFIG_SUPPORT_AGDSP
	{"l_agdsp",NULL,LTE_AGDSP_SIZE ,LTE_AGDSP_ADDR}, //agdsp now is boot by uboot
#endif// end CONFIG_SUPPORT_AGDSP
#endif
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_NR
static boot_image_required_t const s_boot_image_nr_table[] = {
#if (!defined( CONFIG_KERNEL_BOOT_CP )) && (!defined(CONFIG_MEM_LAYOUT_DECOUPLING))
	{"nr_fixnv1","nr_fixnv2",NR_FIXNV_SIZE,NR_FIXNV_ADDR},
	{"nr_runtimenv1","nr_runtimenv2",NR_RUNNV_SIZE,NR_RUNNV_ADDR},
	{"nr_modem",NULL,NR_MODEM_SIZE,NR_MODEM_ADDR},
	{"nr_phy",NULL,NR_PHY_SIZE ,NR_PHY_ADDR},
#endif
#ifdef CONFIG_SUPPORT_AGDSP
	{"l_agdsp",NULL,LTE_AGDSP_SIZE ,LTE_AGDSP_ADDR}, //agdsp now is boot by uboot
#endif// end CONFIG_SUPPORT_AGDSP
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_TD
static boot_image_required_t const s_boot_image_TD_table[] = {
#if !defined( CONFIG_KERNEL_BOOT_CP )
	{"tdfixnv1", "tdfixnv2", FIXNV_SIZE, TDFIXNV_ADR},
	{"tdruntimenv1", "tdruntimenv2", RUNTIMENV_SIZE, TDRUNTIMENV_ADR},
	{"tdmodem", NULL, TDMODEM_SIZE, TDMODEM_ADR},
	{"tddsp", NULL, TDDSP_SIZE, TDDSP_ADR},
#endif
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_W
static boot_image_required_t const s_boot_image_W_table[] = {
#if (!defined( CONFIG_KERNEL_BOOT_CP )) && (!defined(CONFIG_MEM_LAYOUT_DECOUPLING))
	{"wfixnv1", "wfixnv2", FIXNV_SIZE, WFIXNV_ADR},
	{"wruntimenv1", "wruntimenv2", RUNTIMENV_SIZE, WRUNTIMENV_ADR},
	{"wmodem", NULL, WMODEM_SIZE, WMODEM_ADR},
	{"wdsp", NULL, WDSP_SIZE, WDSP_ADR},
#endif
	{NULL, NULL, 0, 0}
};
#endif

#ifdef CONFIG_SUPPORT_WIFI
static boot_image_required_t const s_boot_image_WIFI_table[] = {
	{"wcnfixnv1", "wcnfixnv2", FIXNV_SIZE, WCNFIXNV_ADR},
	{"wcnruntimenv1", "wcnruntimenv2", RUNTIMENV_SIZE, WCNRUNTIMENV_ADR},
	{"wcnmodem", NULL, WCNMODEM_SIZE, WCNMODEM_ADR},
	{NULL, NULL, 0, 0}
};
#endif

static boot_image_required_t const s_boot_image_COMMON_table[] = {
#ifdef CONFIG_SIMLOCK_ENABLE
	{"simlock", NULL, SIMLOCK_SIZE, SIMLOCK_ADR},
#endif
#ifdef CONFIG_DFS_ENABLE
#if !defined( CONFIG_KERNEL_BOOT_CP )
	{"pm_sys", NULL, DFS_SIZE, DFS_ADDR},
#endif
#endif
#ifdef CONFIG_CH_ENABLE
#if !defined( CONFIG_KERNEL_BOOT_CP )
/*
	For CH subsys, hardware cannot copy datas from emmc to
	ch iram by dma directly.
	when ch iram boot, software copy those datas from emmc
	to ch ddr by dma firstly, then copy those datas from ddr
	to ch iram.
	when ch ddr boot,software only copy those datas from emmc
	to ch ddr by dma.
*/
#if defined(CONFIG_CH_DDR_BOOT)
	{"ch_sys", NULL, CH_DDR_SIZE, CH_DDR_ADDR},
#else
	{"ch_sys", NULL, CH_IRAM_SIZE, CH_DDR_ADDR},
#endif
#endif
#endif
	{NULL, NULL, 0, 0}

};

#ifdef CONFIG_MINI_TRUSTZONE
static boot_image_required_t const s_boot_image_TZ_table[] = {
	{"sml", NULL, TRUSTRAM_SIZE, TRUSTRAM_ADR},
	{NULL, NULL, 0, 0}

};
#endif

static boot_image_required_t *const s_boot_image_table[] = {
#ifdef CONFIG_SUPPORT_TDLTE
	s_boot_image_tl_table,
#endif

#ifdef CONFIG_SUPPORT_WLTE
	s_boot_image_wl_table,
#endif

#ifdef CONFIG_SUPPORT_LTE
	s_boot_image_lte_table,
#endif

#ifdef CONFIG_SUPPORT_NR
	s_boot_image_nr_table,
#endif

#ifdef CONFIG_SUPPORT_GSM
	s_boot_image_gsm_table,
#endif

#ifdef CONFIG_SUPPORT_TD
	s_boot_image_TD_table,
#endif

#ifdef CONFIG_SUPPORT_W
	s_boot_image_W_table,
#endif

#ifdef CONFIG_SUPPORT_WIFI
	s_boot_image_WIFI_table,
#endif
#ifdef CONFIG_MINI_TRUSTZONE
	s_boot_image_TZ_table,
#endif
	s_boot_image_COMMON_table,

	0
};

#ifdef CONFIG_SECURE_BOOT
uint8_t header_buf[SEC_HEADER_MAX_SIZE];
#endif

typedef enum {
	DTB_TYPE = 0,
	DTBO_TYPE,
	UNDEFINED_TYPE
}dt_img_type;

static struct pre_load_operations _uboot_pre_load = {
	.power = power_cfg,
	.display   = logo_display,
#ifdef CONFIG_VIBRATOR
	.vibrator  = vibrator_load,
#else
	.vibrator  = NULL,
#endif
#ifdef CONFIG_SPRD_SECURE_BOOT
	.secboot_init = secboot_init
#else
	.secboot_init = NULL
#endif
};

static struct post_load_operations _uboot_post_load = {
#ifdef CONFIG_SPRD_SECURE_BOOT
	.secboot_terminal = secboot_terminal,
#else
	.secboot_terminal = NULL,
#endif
	.rpmb = rpmb_check
};

#define VERSION_R	11
static uint32_t img_os_version;
static void check_img_os_version(uint32_t os_version)
{
	img_os_version = (uint32_t) os_version >> 25;
	debugf("operate system is VERSION_%d\n", img_os_version);

	return;
}

/* Note: return NULL if kernel offset was not found */
struct boot_img_hdr *get_boot_img_hdr(void)
{
	return !s_bootimg_info.kernel_offset ? NULL : (boot_img_hdr *)raw_header;
}

struct boot_img_hdr_v1 *get_boot_img_hdr_v1(struct boot_img_hdr *hdr)
{
	return (struct boot_img_hdr_v1 *)(hdr + 1);
}

struct boot_img_hdr_v2 *get_boot_img_hdr_v2(struct boot_img_hdr *hdr)
{
	struct boot_img_hdr_v1 *hdr_v1 = get_boot_img_hdr_v1(hdr);

	return (struct boot_img_hdr_v2 *)(hdr_v1 + 1);
}

char *get_slot_ab(char * ab_part_name)
{
	static char part[128] = {0};
	char *slot;

	if (!ab_part_name)
		return -1;

	slot = getenv("slot");
	if (!slot) {
		printf("Warning: get slot fail!\n");
		return ab_part_name;
	} else {
		snprintf(part, ARRAY_SIZE(part), "%s%s", ab_part_name, slot);
		return part;
	}
}

#ifdef CONFIG_SECURE_BOOT

int get_spl_hash(void *hash_data)
{
	NBLHeader *header;
	unsigned int len;
	uint8_t *spl_data;
	int ret = 0;
	int size = CONFIG_SPL_HASH_LEN;
	spl_data = malloc(size);
	if (!spl_data) {
		return ret;
	}

	if (0 != common_raw_read("splloader", (uint64_t)size, (uint64_t)0, (char *) spl_data)) {
		errorf("PARTITION_BOOT1 read error \n");
		return ret;
	}

	header = (NBLHeader *) ((uint8_t *) spl_data + BOOTLOADER_HEADER_OFFSET);
	len = header->mHashLen;
	/*clear header */
	memset(header, 0, sizeof(NBLHeader));
	header->mHashLen = len;
	debugf("cal spl hash len=%d\n", header->mHashLen * 4);
	ret = cal_sha1(spl_data, (header->mHashLen) << 2, hash_data);

	if (spl_data)
		free(spl_data);

	return ret;
}
#endif
void _boot_secure_check(void)
{
#ifdef SECURE_BOOT_ENABLE
	secure_check(DSP_ADR, 0, DSP_ADR + DSP_SIZE - VLR_INFO_OFF, CONFIG_SYS_NAND_U_BOOT_DST + CONFIG_SYS_NAND_U_BOOT_SIZE - KEY_INFO_SIZ - VLR_INFO_OFF);
	secure_check(MODEM_ADR, 0, MODEM_ADR + MODEM_SIZE - VLR_INFO_OFF,
		     CONFIG_SYS_NAND_U_BOOT_DST + CONFIG_SYS_NAND_U_BOOT_SIZE - KEY_INFO_SIZ - VLR_INFO_OFF);
#ifdef CONFIG_SIMLOCK
	secure_check(SIMLOCK_ADR, 0, SIMLOCK_ADR + SIMLOCK_SIZE - VLR_INFO_OFF,
		     CONFIG_SYS_NAND_U_BOOT_DST + CONFIG_SYS_NAND_U_BOOT_SIZE - KEY_INFO_SIZ - VLR_INFO_OFF);
#endif
#endif
	return;
}

int splash_screen_prepare(uchar *logo_part_name, u8 *addr)
{
	size_t size ;
	u32 bmp_header_size = 8192;

	size = lcd_get_size(&lcd_line_length);
	size += bmp_header_size;
#ifndef CONFIG_ZEBU
	if (0 != common_raw_read(logo_part_name, (uint64_t)size, (uint64_t)0, addr)) {
		errorf("failed to read logo partition:%s\n", logo_part_name);
		return -1;
	}
#else
	memcpy(addr, 0xb0000000, (size_t)size);
#endif

	return 0;
}

int32_t _boot_read_partition_with_backup(boot_image_required_t info)
{
	uchar header_buf[NV_HEADER_SIZE];
	uchar backup_header_buf[NV_HEADER_SIZE];
	nv_header_t *header_p = header_buf;
	nv_header_t *backup_header_p = backup_header_buf;
	uchar * backup_nv_buf = NULL;
	int status = ORIGIN_BACKUP_NV_OK;
	int ret = 0;
	char *temp = info.partition;

#ifndef CONFIG_NOT_BACKUP_NV
	backup_nv_buf = malloc(info.size);
	if (NULL == backup_nv_buf) {
		errorf("no enough space for backup nv buffer\n");
		return 0;
	}
#endif
#ifdef CONFIG_ANDROID_AB
	if (!strstr(info.partition, "runtimenv")) {
		temp = get_slot_ab(info.partition);
		strncpy(info.partition, temp, MAX_NAME_LEN);
	}
#endif

	do {
		/*read origin image header */
		if (0 != common_raw_read(info.partition, NV_HEADER_SIZE, (uint64_t)0, header_buf)) {
			errorf("read origin <<<%s>>> image header failed\n", info.partition);
			status |= ORIGIN_NV_DAMAGED;
			break;
		}

		if (NV_HEAD_MAGIC != header_p->magic) {
			errorf("<<<%s>>> header magic error, wrong magic=0x%x\n", info.partition, header_p->magic);
			status |= ORIGIN_NV_DAMAGED;
			break;
		}

		/*read origin image */
		if (0 != common_raw_read(info.partition, (uint64_t)(info.size), NV_HEADER_SIZE, info.mem_addr)) {
			errorf("read origin <<<%s>>> image data failed\n", info.partition);
			status |= ORIGIN_NV_DAMAGED;
			break;
		}

		/*check crc */
		if (_chkNVEcc(info.mem_addr, info.size, header_p->checksum)) {
			debugf("read origin <<<%s>>> image success and crc correct\n", info.partition);
		} else {
			errorf("check origin <<<%s>>> image crc wrong\n", info.partition);
			status |= ORIGIN_NV_DAMAGED;
		}
	} while(0);

#ifndef CONFIG_NOT_BACKUP_NV
	do {
		/*read backup header */
		if (0 != common_raw_read(info.bak_partition, NV_HEADER_SIZE, (uint64_t)0, backup_header_buf)) {
			errorf("read backup <<<%s>>> image header failed\n", info.bak_partition);
			status |= BACKUP_NV_DAMAGED;
			break;
		}

		if (NV_HEAD_MAGIC != backup_header_p->magic) {
			errorf("backup <<<%s>>> header magic error, wrong magic=0x%x\n", info.bak_partition, backup_header_p->magic);
			status |= BACKUP_NV_DAMAGED;
			break;
		}

		/*read bakup image */
		if (0 != common_raw_read(info.bak_partition, (uint64_t)(info.size), NV_HEADER_SIZE, backup_nv_buf)) {
			errorf("read backup <<<%s>>> image failed\n", info.bak_partition);
			status |= BACKUP_NV_DAMAGED;
			break;
		}

		/*check crc */
		if (_chkNVEcc(backup_nv_buf, info.size, backup_header_p->checksum)) {
			debugf("read backup <<<%s>>> image success and crc correct\n", info.bak_partition);
		} else {
			errorf("check backup <<<%s>>> image crc wrong\n", info.bak_partition);
			status |= BACKUP_NV_DAMAGED;
		}
	} while(0);
#endif

	switch (status) {
	case ORIGIN_BACKUP_NV_OK :
		debugf("both org and bak nv partition are ok\n");
		ret = 1;
		break;

#ifndef CONFIG_NOT_BACKUP_NV
	case ORIGIN_NV_DAMAGED :
		memcpy(info.mem_addr, backup_nv_buf, info.size);
		if (0 != common_raw_write(info.partition, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, backup_header_buf)) {
			errorf("reapire origin <<<%s>>> image header fail\n", info.partition);
			ret = 0;
			break;
		}

		if (0 != common_raw_write(info.partition, (uint64_t)(info.size), (uint64_t)0, NV_HEADER_SIZE, backup_nv_buf)) {
			errorf("reapire origin <<<%s>>> image data fail\n", info.partition);
			ret = 0;
			break;
		}

		ret = 1;
		break;
	case BACKUP_NV_DAMAGED :
		if (0 != common_raw_write(info.bak_partition, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf)) {
			errorf("reapire backup <<<%s>>> image header fail\n", info.bak_partition);
			ret = 0;
			break;
		}

		if (0 != common_raw_write(info.bak_partition, (uint64_t)(info.size), (uint64_t)0, NV_HEADER_SIZE, info.mem_addr)) {
			errorf("reapire backup <<<%s>>> image data fail\n", info.bak_partition);
			ret = 0;
			break;
		}
		debugf("repair backup <<<%s>>> image OK\n", info.bak_partition);
		ret = 1;
		break;
	case ORIGIN_NV_DAMAGED | BACKUP_NV_DAMAGED :
		errorf("both org <<<%s>>> and bak <<<%s>>> partition are damaged!\n", info.partition, info.bak_partition);
		ret = 0;
		break;
#endif
	}

#ifndef CONFIG_NOT_BACKUP_NV
	free(backup_nv_buf);
#endif
	return ret;
}

unsigned get_modem_img_info(const boot_image_required_t* img_info,
			    unsigned secure_offset,
			    int* is_sci,
			    size_t* total_len,
			    size_t* modem_exe_size) {
	unsigned offset = 0;

	if(!strstr((const char*)img_info->partition, "modem")) {
		*is_sci = 0;
		*total_len = img_info->size;
		*modem_exe_size = img_info->size;
		return 0;
	}

	/* Only support 10 effective headers at most for now. */
	data_block_header_t hdr_buf[11] __attribute__ ((__packed__));
	size_t read_len = sizeof(hdr_buf);

	if (common_raw_read(img_info->partition,
			    read_len,
			    secure_offset,
			    (char*)hdr_buf)) {
		debugf("Read MODEM image header failed!\n");
		return 0;
	}

	/* Check whether it's SCI image. */
	if (memcmp(hdr_buf, MODEM_MAGIC, strlen(MODEM_MAGIC))) {
		/* Not SCI format. */
		*is_sci = 0;
		*total_len = img_info->size;
		*modem_exe_size = img_info->size;

		debugf("Not SCI image.\n");

		return 0;
	}

	/* SCI image. Parse the headers */
	*is_sci = 1;

	unsigned i;
	data_block_header_t* hdr_ptr;
	int modem_offset = -1;
	int image_len = -1;

	for (i = 1, hdr_ptr = hdr_buf + 1;
	     i < sizeof hdr_buf / sizeof hdr_buf[0];
	     ++i, ++hdr_ptr) {
		unsigned type = (hdr_ptr->type_flags & 0xff);
		if (SCI_TYPE_MODEM_BIN == type) {
			modem_offset = (int)hdr_ptr->offset;
			*modem_exe_size = hdr_ptr->length;
			if(hdr_ptr->type_flags & MODEM_SHA1_HDR) {
				modem_offset += MODEM_SHA1_SIZE;
				*modem_exe_size -= MODEM_SHA1_SIZE;
			}
		}
		if (hdr_ptr->type_flags & SCI_LAST_HDR) {
			image_len = (int)(hdr_ptr->offset + hdr_ptr->length);
			break;
		}
	}

	if (-1 == modem_offset) {
		debugf("No MODEM image found in SCI image!\n");
	} else if (-1 == image_len) {
		debugf("SCI header too long!\n");
	} else {
		*total_len = image_len;
		offset = modem_offset;
	}

	debugf("Modem SCI offset: 0x%x!\n", (unsigned)offset);

	return offset;
}

/**
	Function for reading image which is needed when power on.
*/
int _boot_load_required_image(boot_image_required_t img_info)
{
	uint32_t secure_boot_offset = 0;
	int is_sci;
	size_t total_len;
	size_t exe_size;
	unsigned exe_offset;
	char *temp = img_info.partition;
	boot_image_required_t i_info = {0};

	debugf("load %s to addr %p, size = 0x%llx\n", img_info.partition, img_info.mem_addr, img_info.size);

	if (NULL != img_info.bak_partition) {
		debugf("load %s with backup img %s\n", img_info.partition, img_info.bak_partition);
#ifdef CONFIG_ANDROID_AB
		if (!strstr(img_info.bak_partition, "runtimenv")) {
			temp = get_slot_ab(img_info.bak_partition);
			strncpy(img_info.bak_partition, temp, MAX_NAME_LEN);
			debugf("load backup %s to ddr\n", img_info.bak_partition);
		}
#endif
		_boot_read_partition_with_backup(img_info);
	} else {
#ifdef CONFIG_ANDROID_AB
		if (!strstr(img_info.partition, "runtimenv")) {
			temp = get_slot_ab(img_info.partition);
			debugf("load %s to ddr\n", img_info.partition);
		}
#endif

#if defined (CONFIG_SECURE_BOOT)
		if (common_raw_read(img_info.partition,
				    SEC_HEADER_MAX_SIZE,
				    0,
				    (char*)header_buf)) {
			debugf("%s:%s read error!\n", img_info.partition);
			return 0;
		}
		secure_boot_offset = get_code_offset(header_buf);
		exe_offset = get_modem_img_info(&img_info,
						secure_boot_offset * EMMC_SECTOR_SIZE,
						&is_sci,
						&total_len,
						&exe_size);

		common_raw_read(img_info.partition,
				exe_size,
				secure_boot_offset * EMMC_SECTOR_SIZE + exe_offset,
				(char*)FREE_RAM_SPACE_ADDR);

		secure_verify("uboot", header_buf, (u8 *)FREE_RAM_SPACE_ADDR);
		memcpy((void *)img_info.mem_addr,
		       (void*)FREE_RAM_SPACE_ADDR,
		       exe_size);
#elif defined (CONFIG_SECBOOT)
		if (0 == memcmp("pm_sys", img_info.partition, strlen("pm_sys")))
		{
		#ifndef PROJECT_SEC_CM4
			/***secboot 2nd step***/
			vboot_secure_process_flow(img_info.partition);
		#endif
		}
		else
		{
			/***secboot 2nd step***/
			vboot_secure_process_flow(img_info.partition);
		}

	#if defined (CONFIG_VBOOT_V2)
		memcpy(img_info.mem_addr,gd->verify_base,img_info.size);
	#else
		memcpy(img_info.mem_addr,(gd->verify_base + SYS_HEADER_SIZE),img_info.size);
	#endif
#else  // Secure boot is not turned on
		i_info.partition = temp;
		i_info.mem_addr = img_info.mem_addr;
		i_info.size = img_info.size;
		exe_offset = get_modem_img_info(&i_info, 0,
						&is_sci, &total_len,
						&exe_size);
		if (common_raw_read(temp,
				    exe_size,
				    exe_offset,
				    img_info.mem_addr)) {
			errorf("read %s partition fail\n", img_info.partition);
		}

#endif
	}

	return 1;
}

extern int enter_sysdump_flag;

static uint64_t boot_img_offset_v01(boot_img_hdr *hdr, uint64_t offset)
{
	uint64_t size;

	/*kernel image */
	s_bootimg_info.kernel_offset = offset + KERNL_PAGE_SIZE;
	size = PAD_SIZE(hdr->kernel_size, KERNL_PAGE_SIZE);
	if (0 == size) {
		errorf("kernel image should not be zero!\n");
		return 0;
	}

	debugf("s_bootimg_info.kernel_offset is 0x%llx\n", s_bootimg_info.kernel_offset );

	if( hdr->ramdisk_size) {
		/* ramdisk image */
		s_bootimg_info.ramdisk_offset = s_bootimg_info.kernel_offset + size;
		size = PAD_SIZE(hdr->ramdisk_size, KERNL_PAGE_SIZE);
		if (0 == size) {
			errorf("ramdisk image size should not be zero\n");
			return 0;
		}

		debugf("s_bootimg_info.ramdisk_offset is 0x%llx\n", s_bootimg_info.ramdisk_offset );

		/* dt image */
		s_bootimg_info.dt_offset = s_bootimg_info.ramdisk_offset + size;

		debugf("s_bootimg_info.dt_offset is 0x%llx\n", s_bootimg_info.dt_offset );
	}

	return 1;
}

static uint64_t boot_img_offset_v2(boot_img_hdr *hdr, uint64_t offset)
{
	struct boot_img_hdr_v1 *hdr_v1 = get_boot_img_hdr_v1(hdr);
	struct boot_img_hdr_v2 *hdr_v2 = get_boot_img_hdr_v2(hdr);
	uint64_t size;

	/* kernel image */
	s_bootimg_info.kernel_offset = offset + KERNL_PAGE_SIZE;
	size = PAD_SIZE(hdr->kernel_size, KERNL_PAGE_SIZE);
	if (0 == size) {
		errorf("kernel image should not be zero!\n");
		return 0;
	}

	debugf("s_bootimg_info.kernel_offset is 0x%llx\n", s_bootimg_info.kernel_offset );

	if( hdr->ramdisk_size) {
		/* ramdisk image */
		s_bootimg_info.ramdisk_offset = s_bootimg_info.kernel_offset + size;
		size = PAD_SIZE(hdr->ramdisk_size, KERNL_PAGE_SIZE);
		if (0 == size) {
			errorf("ramdisk image size should not be zero\n");
			return 0;
		}

		debugf("s_bootimg_info.ramdisk_offset is 0x%llx\n", s_bootimg_info.ramdisk_offset );
	}

	/* Fixme second stage */

	if (hdr_v1->recovery_dtbo_size) {
		/* recovery_dtbo_offset */
		s_bootimg_info.recovery_dtbo_offset = s_bootimg_info.ramdisk_offset + size;
		size = PAD_SIZE(hdr_v1->recovery_dtbo_size, KERNL_PAGE_SIZE);
		if (0 == size) {
			errorf("recover dtbo image size should not be zero\n");
			return 0;
		}

		debugf("s_bootimg_info.recovery_dtbo_offset is 0x%llx\n", s_bootimg_info.recovery_dtbo_offset);
	}

	/* dt image */
	if (hdr_v1->recovery_dtbo_size)
		s_bootimg_info.dt_offset = s_bootimg_info.recovery_dtbo_offset + size;
	else if (hdr->ramdisk_size)
		s_bootimg_info.dt_offset = s_bootimg_info.ramdisk_offset + size;

	debugf("s_bootimg_info.dt_offset is 0x%llx\n", s_bootimg_info.dt_offset );
	if (hdr_v2->dtb_addr != s_bootimg_info.dt_offset)
		debugf("Warning: dtb addr 0x%llx on boot img hdr\n", hdr_v2->dtb_addr);
	check_img_os_version(hdr->os_version);

	return 1;
}

static int parser_boot_image_header_v3(boot_img_hdr *hdr, uint64_t offset)
{
	uint64_t size;
	boot_img_hdr_v3 *hdr_v3 = (boot_img_hdr_v3 *)(hdr);

	/* judge generic kernel size */
	size = PAD_SIZE(hdr_v3->kernel_size, s_bootimg_info.page_size);
	if (size == 0) {
		errorf("bootimage: generic kernel size should not be zero!\n");
		return 0;
	}
	debugf("bootimage: generic kernel size is %d\n", hdr_v3->kernel_size);

	/* get generic kernel offset */
	s_bootimg_info.kernel_offset = offset + s_bootimg_info.page_size;
	debugf("bootimage: generic kernel offset is 0x%llx\n", s_bootimg_info.kernel_offset);

	/* judge generic ramdisk size */
	if (hdr_v3->ramdisk_size == 0) {
		errorf("bootimage: generic ramdisk size should not be zero!\n");
		return 0;
	}
	debugf("bootimage: generic ramdisk size is %d\n", hdr_v3->ramdisk_size);

	/* get generic ramdisk offset */
	s_bootimg_info.ramdisk_offset = s_bootimg_info.kernel_offset + size;
	debugf("bootimage: generic ramdisk offset is 0x%llx\n", s_bootimg_info.ramdisk_offset);
	check_img_os_version(hdr_v3->os_version);

	return 1;
}

static int parser_vendor_boot_image_header_v3(vendor_boot_img_hdr_v3 *vb_hdr_v3, uint64_t offset)
{
	int ret;
	uint64_t size = 0;
	char *partition = s_bootimg_info.vendor_boot_part;

	s_bootimg_info.vendor_hdr_offset = offset;

	/* check vendor boot image header */
	if (memcmp(vb_hdr_v3->magic, VENDOR_BOOT_MAGIC, VENDOR_BOOT_MAGIC_SIZE)) {
		errorf("bad vendor boot image header, give up boot!\n");
		return 0;
	}

	/* judge vendor ramdisk size */
	size = PAD_SIZE(vb_hdr_v3->vendor_ramdisk_size, s_bootimg_info.page_size);
	if (size == 0) {
		errorf("vendor ramdisk size should not be zero!\n");
		return 0;
	}

	/* get vendor ramdisk size */
	s_bootimg_info.vendor_ramdisk_size = vb_hdr_v3->vendor_ramdisk_size;
	debugf("vendorbootimage: vendor ramdisk size is %lld\n", s_bootimg_info.vendor_ramdisk_size);

	/* get vendor ramdisk offset */
	s_bootimg_info.vendor_ramdisk_offset = s_bootimg_info.vendor_hdr_offset + s_bootimg_info.page_size;
	debugf("vendorbootimage: vendor ramdisk offset is 0x%llx\n", s_bootimg_info.vendor_ramdisk_offset);

	/* judge vendor dtb size */
	if (vb_hdr_v3->dtb_size == 0) {
		errorf("vendor dtb size should not be zero\n");
		return 0;
	}

	/* get vendor dtb size */
	s_bootimg_info.dt_size = vb_hdr_v3->dtb_size;
	debugf("vendorbootimage: vendor dt size is %lld\n", s_bootimg_info.dt_size);

	/* get vendor dtb offset */
	s_bootimg_info.dt_offset = s_bootimg_info.vendor_ramdisk_offset + size;
	debugf("vendorbootimage: vendor dt offset is 0x%llx\n", s_bootimg_info.dt_offset);

#ifdef CONFIG_BOARD_KERNEL_CMDLINE
	memset(vendorboot_cmdline, 0, VENDOR_BOOT_ARGS_SIZE);
	memcpy(vendorboot_cmdline, vb_hdr_v3->cmdline, VENDOR_BOOT_ARGS_SIZE);
#endif

	return 1;
}

static uint64_t boot_img_offset_v3(boot_img_hdr *hdr, uint64_t offset)
{
	int ret;
	char *vndr_boot_img_hdr;

#ifdef CONFIG_ANDROID_AB
	char *ab_slot = getenv("slot");
	if (ab_slot && (strlen(ab_slot) + strlen(boot_v3) + 1) <= ARRAY_SIZE(boot_v3) &&
		(strlen(ab_slot)+ strlen(vendor_boot_v3) + 1) <= ARRAY_SIZE(vendor_boot_v3)) {
		strcat(boot_v3, ab_slot);
		strcat(vendor_boot_v3, ab_slot);
	}
#endif

	/* header v3 page size is 4096 Byte */
	s_bootimg_info.bootimg_part = boot_v3;
	s_bootimg_info.vendor_boot_part = vendor_boot_v3;
	s_bootimg_info.page_size = KERNEL_PAG_SIZE_V3;
	vndr_boot_img_hdr = (char *)(malloc(KERNEL_PAG_SIZE_V3));
	if (vndr_boot_img_hdr == NULL) {
		errorf("malloc vndr_boot_img_hdr fail");
		goto err;
	}

	ret = parser_boot_image_header_v3(hdr, offset);
	if (!ret) {
		errorf("parser boot image header_v3 fail!\n");
		goto err;
	}

	/* read vendor boot image header */
	ret = common_raw_read(s_bootimg_info.vendor_boot_part, KERNEL_PAG_SIZE_V3, offset, vndr_boot_img_hdr);
	if (ret) {
		errorf("read %s header error!\n", s_bootimg_info.vendor_boot_part);
		goto err;
	}

	ret = parser_vendor_boot_image_header_v3((vendor_boot_img_hdr_v3 *)(vndr_boot_img_hdr), offset);
	if (!ret) {
		errorf("parser vendor boot image header_v3 fail!\n");
		goto err;
	}
	free(vndr_boot_img_hdr);
	return 1;

err:
	if (NULL != vndr_boot_img_hdr)
		free(vndr_boot_img_hdr);
	return 0;
}

static int parser_boot_image_header_v4(boot_img_hdr *hdr, uint64_t offset)
{
	uint64_t size;
	boot_img_hdr_v4 *hdr_v4 = (boot_img_hdr_v4 *)(hdr);

	/* judge generic kernel size */
	size = PAD_SIZE(hdr_v4->kernel_size, s_bootimg_info.page_size);
	if (size == 0) {
		errorf("bootimage: generic kernel size should not be zero!\n");
		return 0;
	}
	debugf("bootimage: generic kernel size is %d\n", hdr_v4->kernel_size);

	/* get generic kernel offset */
	s_bootimg_info.kernel_offset = offset + s_bootimg_info.page_size;
	debugf("bootimage: generic kernel offset is 0x%llx\n", s_bootimg_info.kernel_offset);

	/* judge generic ramdisk size */
	if (hdr_v4->ramdisk_size == 0) {
		errorf("bootimage: generic ramdisk size should not be zero!\n");
		return 0;
	}
	debugf("bootimage: generic ramdisk size is %d\n", hdr_v4->ramdisk_size);

	/* get generic ramdisk offset */
	s_bootimg_info.ramdisk_offset = s_bootimg_info.kernel_offset + size;
	debugf("bootimage: generic ramdisk offset is 0x%llx\n", s_bootimg_info.ramdisk_offset);
	check_img_os_version(hdr_v4->os_version);

	return 1;
}

static int parser_vendor_boot_image_header_v4(vendor_boot_img_hdr_v4 *vb_hdr_v4, uint64_t offset)
{
	int ret;
	uint64_t size = 0;
	char *partition = s_bootimg_info.vendor_boot_part;

	s_bootimg_info.vendor_hdr_offset = offset;

	/* check vendor boot image header */
	if (memcmp(vb_hdr_v4->magic, VENDOR_BOOT_MAGIC, VENDOR_BOOT_MAGIC_SIZE)) {
		errorf("bad vendor boot image header, give up boot!\n");
		return 0;
	}

	/* judge vendor ramdisk size */
	size = PAD_SIZE(vb_hdr_v4->vendor_ramdisk_size, s_bootimg_info.page_size);
	if (size == 0) {
		errorf("vendor ramdisk size should not be zero!\n");
		return 0;
	}

	/* get vendor ramdisk size */
	s_bootimg_info.vendor_ramdisk_size = vb_hdr_v4->vendor_ramdisk_size;
	debugf("vendorbootimage: vendor ramdisk size is %lld\n", s_bootimg_info.vendor_ramdisk_size);

	/* get vendor ramdisk offset */
	s_bootimg_info.vendor_ramdisk_offset = s_bootimg_info.vendor_hdr_offset + s_bootimg_info.page_size;
	debugf("vendorbootimage: vendor ramdisk offset is 0x%llx\n", s_bootimg_info.vendor_ramdisk_offset);

	/* judge vendor dtb size */
	if (vb_hdr_v4->dtb_size == 0) {
		errorf("vendor dtb size should not be zero\n");
		return 0;
	}

	/* get vendor dtb size */
	s_bootimg_info.dt_size = vb_hdr_v4->dtb_size;
	debugf("vendorbootimage: vendor dt size is %lld\n", s_bootimg_info.dt_size);

	/* get vendor dtb offset */
	size = PAD_SIZE(s_bootimg_info.vendor_ramdisk_size, s_bootimg_info.page_size);
	s_bootimg_info.dt_offset = s_bootimg_info.vendor_ramdisk_offset + size;
	debugf("vendorbootimage: vendor dt offset is 0x%llx\n", s_bootimg_info.dt_offset);

	/* judge vendor ramdisk table size */
	if (vb_hdr_v4->vendor_ramdisk_table_size == 0) {
		errorf("vendor ramdisk table size should not be zero\n");
		return 0;
	}

	/* get vendor ramdisk table size */
	s_bootimg_info.vendor_ramdisk_table_size = vb_hdr_v4->vendor_ramdisk_table_size;
	debugf("vendorbootimage: vendor ramdisk table size is %lld\n", s_bootimg_info.vendor_ramdisk_table_size);

	/* get vendor ramdisk table offset */
	size = PAD_SIZE(s_bootimg_info.dt_size, s_bootimg_info.page_size);
	s_bootimg_info.vendor_ramdisk_table_offset = s_bootimg_info.dt_offset + size;
	debugf("vendorbootimage: vendor ramdisk table offset is 0x%llx\n", s_bootimg_info.vendor_ramdisk_table_offset);

	/* get vendor bootconfig size */
	s_bootimg_info.vendor_bootconfig_size = vb_hdr_v4->bootconfig_size;
	debugf("vendorbootimage: vendor bootconfig size is %lld\n", s_bootimg_info.vendor_bootconfig_size);

	/* get vendor bootconfig offset */
	size = PAD_SIZE(s_bootimg_info.vendor_ramdisk_table_size, s_bootimg_info.page_size);
	s_bootimg_info.vendor_bootconfig_offset = s_bootimg_info.vendor_ramdisk_table_offset + size;
	debugf("vendorbootimage: vendor bootconfig offset is 0x%llx\n", s_bootimg_info.vendor_bootconfig_offset);

#ifdef CONFIG_BOARD_KERNEL_CMDLINE
	memset(vendorboot_cmdline, 0, VENDOR_BOOT_ARGS_SIZE);
	memcpy(vendorboot_cmdline, vb_hdr_v4->cmdline, VENDOR_BOOT_ARGS_SIZE);
#endif

	return 1;
}

static uint64_t boot_img_offset_v4(boot_img_hdr *hdr, uint64_t offset)
{
	int ret;
	char *vndr_boot_img_hdr;

#ifdef CONFIG_ANDROID_AB
	char *ab_slot = getenv("slot");
	if (ab_slot && (strlen(ab_slot) + strlen(boot_v3) + 1) <= ARRAY_SIZE(boot_v3) &&
		(strlen(ab_slot)+ strlen(vendor_boot_v3) + 1) <= ARRAY_SIZE(vendor_boot_v3)) {
		strcat(boot_v3, ab_slot);
		strcat(vendor_boot_v3, ab_slot);
	}
#endif

	/* header v3 page size is 4096 Byte */
	s_bootimg_info.bootimg_part = boot_v3;
	s_bootimg_info.vendor_boot_part = vendor_boot_v3;
	s_bootimg_info.page_size = KERNEL_PAG_SIZE_V3;
	vndr_boot_img_hdr = (char *)(malloc(VENDOR_BOOT_HEADER_SIZE_V4));
	if (vndr_boot_img_hdr == NULL) {
		errorf("malloc vndr_boot_img_hdr fail");
		goto err;
	}

	ret = parser_boot_image_header_v4(hdr, offset);
	if (!ret) {
		errorf("parser boot image header_v4 fail!\n");
		goto err;
	}

	/* read vendor boot image header */
	ret = common_raw_read(s_bootimg_info.vendor_boot_part, VENDOR_BOOT_HEADER_SIZE_V4, offset, vndr_boot_img_hdr);
	if (ret) {
		errorf("read %s header error!\n", s_bootimg_info.vendor_boot_part);
		goto err;
	}

	ret = parser_vendor_boot_image_header_v4((vendor_boot_img_hdr_v4 *)(vndr_boot_img_hdr), offset);
	if (!ret) {
		errorf("parser vendor boot image header_v4 fail!\n");
		goto err;
	}
	free(vndr_boot_img_hdr);
	return 1;

err:
	if (NULL != vndr_boot_img_hdr)
		free(vndr_boot_img_hdr);
	return 0;
}

typedef uint64_t (*boot_img_offset_hdl)(boot_img_hdr *, uint64_t);
static boot_img_offset_hdl boot_img_offset_hdl_tbl[] = {
	boot_img_offset_v01,
	boot_img_offset_v01,
	boot_img_offset_v2,
	boot_img_offset_v3,
	boot_img_offset_v4,
};

uint64_t _get_kernel_ramdisk_dt_offset(boot_img_hdr * hdr, uchar *partition)
{
	uint64_t size;
	uint64_t offset = 0;
	uint32_t secure_boot_offset = 0;

#ifdef CONFIG_SECURE_BOOT
	if (0 != common_raw_read(partition, (uint64_t)512, (uint64_t)0,  (u8 *) hdr)) {
		errorf("%s read error!\n", partition);
		return 0;
	}
	secure_boot_offset = get_code_offset(hdr);
	offset += secure_boot_offset;
#endif

#if (defined CONFIG_SECBOOT) && (!(defined CONFIG_VBOOT_V2))
	offset = 512;/**header of image size is 512B**/
#endif

	s_bootimg_info.hdr_offset = offset;
	s_bootimg_info.page_size = KERNL_PAGE_SIZE;
	if (0 != common_raw_read(partition, KERNEL_PAG_SIZE_V3, (uint64_t)offset, (char *)hdr)) {
		errorf("read %s header error!\n", partition);
		return 0;
	}

	/* check bootimage header */
	if (0 != memcmp(hdr->magic, BOOT_MAGIC, BOOT_MAGIC_SIZE)) {
		errorf("bad boot image header, give up boot!!!!\n");
		return 0;
	}

	debug("boot_img_hdr header_version: %d\n", hdr->header_version);
	if (hdr->header_version >= ARRAY_SIZE(boot_img_offset_hdl_tbl)) {
		if (!strcmp(partition, RECOVERY_PART)) {
			debugf("recovery header version is 0");
			hdr->header_version = BOOT_HEADER_VERSION_0;
		} else
			hdr->header_version = BOOT_HEADER_VERSION_ONE;
	}

	if (!boot_img_offset_hdl_tbl[hdr->header_version](hdr, offset))
		return 0;

#if (defined CONFIG_SPRD_SYSDUMP)
	if(enter_sysdump_flag){
		debug("Now doing sysdump ,go back here .\n");
		return 1;
	}
#endif

	return 1;
}

/**
*	Function for load dtbo and merge into dtb
*
*	The 64-bit and 32-bit parameters "sprd,sc-id" are the same,
*	but they will not appear in the same DTB file.
*
*/
static int look_for_matching_device_from_dt(char *fdt_temp, dt_img_type dt_type)
{
	char *device_string = NULL;
	char *device_string_t = NULL;
	char delim[] = " ";
	char *dts_plat_token = NULL;
	char *board_plat_token = NULL;
	char *board_info = NULL;
	char *board_info_t = NULL;
	int nodeoffset = fdt_path_offset(fdt_temp, "/");
	int gd_nodeoffset = fdt_path_offset(gd->fdt_blob, "/");
	int ret = 0;

	if(dt_type == UNDEFINED_TYPE) {
		errorf("dtb_type has not been set\n");
		return -1;
	}
	if (nodeoffset == -FDT_ERR_NOTFOUND || gd_nodeoffset == -FDT_ERR_NOTFOUND)
		return -1;

	board_info = strdup(fdt_getprop(gd->fdt_blob, gd_nodeoffset, "sprd,sc-id", NULL));;
	board_info_t = board_info;
	if (!board_info) {
		debugf("Cannot find prop name \"sprd,sc-id\" in gd->fdt_blob\n");
		return -1;
	}

	device_string = strdup(fdt_getprop(fdt_temp, nodeoffset, "sprd,sc-id", NULL));
	device_string_t = device_string;
	if (!device_string) {
		debugf("Cannot find prop name \"sprd,sc-id\" in kernel dtb\n");
		free(board_info);
		return -1;
	}

	debugf("Find kernel dtb prop name sprd,sc-id=%s, gd->fdt_blob sprd,sc-id=%s\n", device_string, board_info);

	/*match dtbo*/
	if (DTBO_TYPE == dt_type) {
		if (!strcmp(device_string, board_info)) {
			debugf("Matches the corresponding dtbo in multiple DTBO\n");
			goto end;
		} else {
			debugf("This dtbo file is not match\n");
			ret = -1;
			goto end;
		}
	}

	/*match dtb*/
	if (DTB_TYPE == dt_type) {
		/*PLATFORM ID for dtb\dtbo*/
		dts_plat_token = strsep(&device_string_t, delim);
		board_plat_token = strsep(&board_info_t, delim);
		if (!dts_plat_token || !board_plat_token) {
			errorf("Property sprd,sc-id is not formatted correctly\n");
			ret = -1;
			goto end;
		}

		if (!strcmp(board_plat_token, dts_plat_token))
			debugf("Matches the corresponding dtb in multiple DTB\n");
		else {
			debugf("This dtb file is not match\n");
			ret = -1;
		}
	}
end:
	free(device_string);
	free(board_info);
	return ret;
}

#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
__weak int sprd_get_dtboinfo(void)
{
	return -4000;
}

/* Function for load dtbo by board id */
static int look_for_matching_by_boardid(struct dt_table_entry *entry, int *mt)
{
	static int board_vid = -1;
	static int board_id = -1;
	int ret = -1;
	int tmp;

	if (-1 == board_vid) {
		if (!common_raw_read("miscdata", SET_VIRTUAL_BOARD_ID_LEN,
							 SET_VIRTUAL_BOARD_ID_OFFSET, &tmp)) {
			if (SET_VIRTUAL_BOARD_ID_MAGIC == (tmp & 0xFFFF0000)) {
				board_vid = tmp & 0xFFFF;
				debugf("got virtual board id %d\n", board_vid);
			} else
				board_vid = -2;
		}
	}

	if (-1 == board_id) {
		board_id = sprd_get_dtboinfo();
		debugf("got board id %d\n", board_id);
	}

	/* comparison of choice */
	if (be32_to_cpu(entry->id) == board_vid) {
		*mt = 0;
		debugf("matches dtbo entry by virtual id!\n");
		return 0;
	} else if (be32_to_cpu(entry->id) == board_id) {
		*mt = 1;
		debugf("matches dtbo entry!\n");
		return 0;
	} else
		debugf("mismatching dtbo entry(id:%d)\n", be32_to_cpu(entry->id));

	return ret;
}
#endif

/**
	Function for load dtbo and merge into dtb
*/
void load_and_merge_dtbo(uchar *partition, uchar *dt_start_addr)
{
	int ret = 0;
	int offset = 0;
	int count,i;
	struct dt_table_header table_header;
	struct dt_table_entry *entry=NULL;
	struct fdt_header *dtbo_header = NULL;
	u8 *dtbo_start_addr = NULL;
	u8 *dtbo_addr = NULL;
	struct boot_img_hdr_v1 hdr;
	uint64_t hdr_offset = s_bootimg_info.hdr_offset + sizeof(boot_img_hdr);
#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
	struct dt_table_entry *sav_entry_v = NULL, *sav_entry = NULL;
	int hit_cnt = 0;
	int mt = -1;
#endif

	debugf("load dtbo from %s\n", partition);
	if (0 != common_raw_read(partition, sizeof(struct boot_img_hdr_v1), hdr_offset, (char *)&hdr)) {
		errorf("read %s header error!\n", partition);
		return 0;
	}

	debug("recovery_dtbo_size: 0x%x\n", hdr.recovery_dtbo_size);
	debug("recovery_dtbo_offset: 0x%llx\n", hdr.recovery_dtbo_offset);
	debug("header_size: 0x%x\n", hdr.header_size);

	/* read dtbo table header */
	if (0 != common_raw_read(partition, (uint64_t)sizeof(struct dt_table_header), hdr.recovery_dtbo_offset, &table_header)) {
		errorf("read dtbo fail\n");
		goto error;
	}

	/* dtbo image header check */
	if (be32_to_cpu(table_header.magic) != DT_TABLE_MAGIC) {
		errorf("invalid dtbo partition\n");
		goto error;
	}

	if (be32_to_cpu(table_header.total_size) == 0)
		goto error;

	/* dtbo alloc memory*/
	dtbo_start_addr = malloc(be32_to_cpu(table_header.total_size));
	if (NULL == dtbo_start_addr) {
		errorf("malloc size=%dfor dt entrys fail\n", be32_to_cpu(table_header.total_size));
		goto error;
	}

	/* load dtbo image */
	if (0 != common_raw_read(partition, (uint64_t)be32_to_cpu(table_header.total_size), hdr.recovery_dtbo_offset, dtbo_start_addr)) {
		errorf("read dtbo fail\n");
		goto error;
	}

	if (be32_to_cpu(table_header.dt_entry_count) == 0) {
		errorf("not found dtbo !\n");
		goto error;
	}

	count = be32_to_cpu(table_header.dt_entry_count);
	entry = (struct dt_table_entry *)(dtbo_start_addr +
				be32_to_cpu(table_header.dt_entries_offset));

	for (i = 0; i < count; i++) {
#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
		if (!look_for_matching_by_boardid(entry, &mt)) { /* hit */
			if (!sav_entry_v && (mt == 0)) { /* virtual board id hit */
				sav_entry_v = entry;
			} else if (!sav_entry && (mt == 1)) {
				sav_entry = entry;
			}
		}

		if (!sav_entry_v) {
			if ((i < count - 1) || !sav_entry) {
				entry++;
				continue;
			} else
				entry = sav_entry;
		} else
			entry = sav_entry_v;

		hit_cnt++;
#endif

		offset = be32_to_cpu(entry->dt_offset);
		debugf("offset = 0x%x size=0x%x\n", offset, be32_to_cpu(entry->dt_size));

		dtbo_addr = (u8 *)malloc(be32_to_cpu(entry->dt_size));
		if (NULL == dtbo_addr) {
			errorf("malloc size=%d for dt entrys fail\n", be32_to_cpu(entry->dt_size));
			goto error;
		}
		memcpy(dtbo_addr, dtbo_start_addr + offset, be32_to_cpu(entry->dt_size));
		dtbo_header = (struct fdt_header *)dtbo_addr;
		if (fdt_check_header(dtbo_header) != 0) {
			errorf("image is not a fdt\n");
			goto error;
		}

#ifndef CONFIG_MATCH_DTBO_BY_BOARDID
		if (img_os_version >= VERSION_R) {
			if (look_for_matching_device_from_dt((char *)dtbo_addr, DTBO_TYPE)) {
				free(dtbo_addr);
				dtbo_addr = NULL;
				entry++;
				continue;
			}
		}
#endif

		ret = fdt_overlay_apply(dt_start_addr, dtbo_addr);
		if (ret) {
			errorf("fdt_overlay_apply(): %s\n", fdt_strerror(ret));
			goto error;
		}
		free(dtbo_addr);
		dtbo_addr = NULL;
		/* Only need to overlay one dtbo */
		break;
	}
error:
	if (NULL != dtbo_start_addr) {
		free(dtbo_start_addr);
	}
	if (NULL != dtbo_addr) {
		free(dtbo_addr);
	}
}

/**
	Function for do memory defragment and load dtb
*/
void merge_dtbo(uchar *dt_start_addr)
{
#ifdef CONFIG_OF_LIBFDT_OVERLAY
	struct dt_table_header *table_header;
	struct dt_table_entry *entry=NULL;
	struct dt_table_entry *cur_entry=NULL;
	struct fdt_header dtbo_header;
	uint8_t data[64];
	u8 *dtbo_addr = NULL;
	int offset = 0;
	int ret = 0;
	int count,size,i;
#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
	struct dt_table_entry *sav_entry_v = NULL, *sav_entry = NULL;
	int hit_cnt = 0;
	int mt = -1;
#endif

	char *dtbo_ab = "dtbo";
#ifdef CONFIG_ANDROID_AB
	dtbo_ab = get_slot_ab("dtbo");
#endif

	if (0 != common_raw_read(dtbo_ab, sizeof(*table_header), 0, &data[0])) {
		errorf("read dtbo fail\n");
		goto error;
	}
	table_header = (struct dt_table_header *)data;
	if (be32_to_cpu(table_header->magic) != DT_TABLE_MAGIC) {
		errorf("invalid dtbo partition\n");
		goto error;
	}
	if (be32_to_cpu(table_header->dt_entry_count)==0)
		goto error;
	size =be32_to_cpu(table_header->dt_entry_size) *
		 be32_to_cpu(table_header->dt_entry_count);
	entry = malloc(size);
	if (NULL == entry) {
		errorf("malloc size=%dfor dt entrys fail\n",size);
		goto error;
	}
	offset = be32_to_cpu(table_header->dt_entries_offset);
	count = be32_to_cpu(table_header->dt_entry_count);

	if (0 != common_raw_read(dtbo_ab, size, offset, entry)) {
		errorf("read dt entries fail\n");
		goto error;
	}

	cur_entry = entry;
	for (i=0; i < count; i++) {
#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
		if (!look_for_matching_by_boardid(cur_entry, &mt)) { /* hit */
			if (!sav_entry_v && (mt == 0)) { /* virtual board id hit */
				sav_entry_v = cur_entry;
			} else if (!sav_entry && (mt == 1)) {
				sav_entry = cur_entry;
			}
		}

		if (!sav_entry_v) {
			if ((i < count - 1) || !sav_entry) {
				cur_entry++;
				continue;
			} else
				cur_entry = sav_entry;
		} else
			cur_entry = sav_entry_v;

		hit_cnt++;
#endif
		printf("%s : offset = 0x%x size=0x%x\n"
			,__func__, offset, be32_to_cpu(cur_entry->dt_size));

		offset = be32_to_cpu(cur_entry->dt_offset);
		size = sizeof(struct fdt_header);
		debugf("offset = 0x%x size=0x%x\n", offset, be32_to_cpu(cur_entry->dt_size));
		if (0 != common_raw_read(dtbo_ab, size, offset, &dtbo_header)) {
			errorf("read dtbo fail\n");
			goto error;
		}

		if (fdt_check_header(&dtbo_header) != 0) {
			errorf("image is not a fdt\n");
			goto error;
		}
		size = fdt_totalsize(&dtbo_header);
		dtbo_addr = malloc(size);
		if (NULL == dtbo_addr) {
			errorf("malloc size %d for dtbo fail\n", size);
			goto error;
		}
		if (0 != common_raw_read(dtbo_ab, size, offset, dtbo_addr)) {
			errorf("read dtbo fail\n");
			goto error;
		}

#ifndef CONFIG_MATCH_DTBO_BY_BOARDID
		if (img_os_version >= VERSION_R) {
			if (look_for_matching_device_from_dt((char *)dtbo_addr, DTBO_TYPE)) {
				free(dtbo_addr);
				dtbo_addr = NULL;
				cur_entry++;
				continue;
			}
		}
#endif

		ret = fdt_overlay_apply(dt_start_addr, dtbo_addr);
		if (ret) {
			errorf("fdt_overlay_apply(): %s\n", fdt_strerror(ret));
			goto error;
		}

		free(dtbo_addr);
		dtbo_addr = NULL;
		/* Only need to overlay one dtbo */
		g_DtboIndex = i;
		break;
	}
error:
	if (NULL != entry)
		free(entry);
	if (NULL != dtbo_addr)
		free(dtbo_addr);

#ifdef CONFIG_MATCH_DTBO_BY_BOARDID
	if (!hit_cnt) {
		int key_code;

		lcd_printf("Merge dtbo fail, press key to reboot into fastboot\n");
		do {
			udelay(50 * 1000);
			key_code = board_key_scan();
			if (key_code == KEY_VOLUMEDOWN || key_code == KEY_VOLUMEUP || key_code == KEY_HOME)
				break;
		} while (1);
		//reboot_devices(CMD_FASTBOOT_MODE);
		fastboot_mode();
	}
#endif
#endif
}

/**
 * merge_bootargs - Function for bootargs in DTB merge with bootargs_ext in DTBO
 * @fdt_blob: Base Device Tree blob
 *
 * This function is used to solve BUG 1458956, Make sure that the node contents
 * changed in the overlay are not allowed to change after the merge.
 *
 * returns:
 *      0 on success
 *      Negative error code on failure
 */
int merge_bootargs(u8 *fdt_blob)
{
	int nodeoffset;
	const char *path = NULL;
	char *path_copy = NULL;
	char *path_copy_t = NULL;
	char *prop = NULL;
	char *prop_name = NULL;
	char *prop_name_t = NULL;
	const char *path_ext = NULL;
	char *path_copy_ext = NULL;
	char *path_copy_ext_t = NULL;
	char *prop_ext = NULL;
	char *prop_ext_name = NULL;
	char *prop_ext_name_t =NULL;
	int ret = -1;
	char buf[12] = "\0";

	nodeoffset = fdt_path_offset(fdt_blob, "/chosen");
	if (nodeoffset < 0) {
		errorf("merge_bootargs: cann't find chosen");
		goto end;
	}

	path = fdt_getprop(fdt_blob, nodeoffset, "bootargs", NULL);
	if (path == NULL) {
		errorf("bootargs is null\n");
		goto end;
	}

	path_ext = fdt_getprop(fdt_blob, nodeoffset, "bootargs_ext", NULL);
	if (path_ext == NULL) {
		debugf("The Bootargs_ext node does not exist\n");
		ret = 0;
		goto end;
	}
	path_copy_ext = strdup(path_ext);
	if (path_copy_ext == NULL) {
		errorf("pathextcopy string copy failed!\n");
		goto end;
	}
	path_copy_ext_t = path_copy_ext;
	debugf("bootargs: %s\n", path);
	debugf("bootargs_ext: %s\n", path_copy_ext);

	while ((prop_ext = strsep(&path_copy_ext, " ")) != NULL) {
		path_copy = strdup(path);
		if (path_copy == NULL) {
			errorf("pathcopy string copy failed!\n");
			goto end;
		}
		path_copy_t = path_copy;
		prop_ext_name_t = strdup(prop_ext);
		if (prop_ext_name_t == NULL) {
			errorf("prop_ext string copy failed!\n");
			goto end;
		}
		prop_ext_name = strsep(&prop_ext, "=");
		while ((prop = strsep(&path_copy, " ")) != NULL) {
			prop_name_t = strdup(prop);
			if (prop_name_t == NULL) {
				errorf("prop string copy failed!\n");
				goto end;
			}
			prop_name = strsep(&prop, "=");

			if (!strcmp(prop_name, prop_ext_name)) {
				debugf("replace info : prop: %s, prop_ext: %s\n", prop_name_t, prop_ext_name_t);
				ret = fdt_chosen_bootargs_replace(fdt_blob, prop_name_t, prop_ext_name_t);
				if (ret) {
					errorf("bootargs_ext replace to bootargs failed\n");
					goto end;
				}
				free(prop_name_t);
				prop_name_t = NULL;
				break;
			}
			free(prop_name_t);
			prop_name_t = NULL;
		}

		if (NULL == prop) {
			debugf("append cmdline: %s\n", prop_ext_name_t);
			ret = fdt_chosen_bootargs_append(fdt_blob, prop_ext_name_t, 1);
			if (ret) {
				errorf("bootargs_ext apppend to bootargs failed\n");
				goto end;
			}
		}
		free(prop_ext_name_t);
		prop_ext_name_t = NULL;
		free(path_copy_t);
		path_copy_t = NULL;
	}

end:
	if (NULL != path_copy_t)
		free(path_copy_t);
	if (NULL != path_copy_ext_t)
		free(path_copy_ext_t);
	if (NULL != prop_name_t)
		free(prop_name_t);
	if (NULL != prop_ext_name_t)
		free(prop_ext_name_t);
	return ret;
}

int load_fixup_dt_img(uchar *partition, uchar **dt_start_addr) {
	u8 *fdt_blob = NULL;
	struct dt_table table;
	char * header = NULL;
	struct dt_entry *dt_entry_ptr;
	uint64_t size = 0;
	uint64_t fdt_size = 0;
	uint64_t fdt_offset = 0;
	int ret = -1;
	uchar *dt_end_addr;
	uchar *ramdisk_adr;
	uint32_t auto_mem_num = 0;
	struct boot_img_hdr *hdr;
	struct boot_img_hdr_v2 *hdr_v2 = NULL;
	struct dt_table_header *table_header;
	struct dt_table_entry *entry = NULL;
	struct dt_table_entry *cur_entry = NULL;
	struct fdt_header dtb_header;
	uint8_t data[64];
	uint64_t offset_temp = 0;
	int count,i;

	hdr = get_boot_img_hdr();
	if (hdr) {
		hdr_v2 = get_boot_img_hdr_v2(hdr);
	}
	if (BOOT_HEADER_VERSION_THREE == hdr->header_version ||
			BOOT_HEADER_VERSION_FOUR == hdr->header_version) {
		size = s_bootimg_info.dt_size;
		fdt_offset = s_bootimg_info.dt_offset;
	} else if (!hdr_v2 || !((BOOT_HEADER_VERSION_TWO == hdr->header_version)
			&& (hdr_v2->dtb_addr && hdr_v2->dtb_size))) {
		size = sizeof(struct dt_table);
		if (0 != common_raw_read(partition, size, (uint64_t)(s_bootimg_info.dt_offset), &table)) {
			errorf("read dt image table header fail\n");
			goto error;
		}


		/* Validate the device tree table header */
		if((table.magic != DEV_TREE_MAGIC) || (table.version != DEV_TREE_VERSION)) {
			errorf("Cannot validate Device Tree Table(magic%x,version%d) on %s\n",
				table.magic, table.version, partition);
			goto error;
		}

		size = sizeof(struct dt_table) + sizeof(struct dt_entry) * table.num_entries;
		header = (char *)malloc(size);
		if (NULL == header) {
			errorf("malloc size %lld for dt header fail\n", size);
			goto error;
		}
		if (0 != common_raw_read(partition, size,  (uint64_t)(s_bootimg_info.dt_offset), header)) {
			errorf("read dt image table and entries header fail\n");
			goto error;
		}

		/* Calculate the offset of device tree within device tree table */
		dt_entry_ptr = dev_tree_get_entry_ptr((struct dt_table *)header);
		if(NULL == dt_entry_ptr) {
			errorf("Getting device tree address failed\n");
			goto error;
		}

		size = dt_entry_ptr->size;
		fdt_offset = s_bootimg_info.dt_offset + dt_entry_ptr->offset;
	} else {
		fdt_offset = s_bootimg_info.dt_offset;
		size = hdr_v2->dtb_size;
		if (fdt_offset != hdr_v2->dtb_addr)
			debugf("Warning: dtb addr 0x%llx on boot img hdr\n", hdr_v2->dtb_addr);
		debugf("v2 header fdt_offset:0x%llx size:0x%llx\n", fdt_offset, size);
	}

	if (img_os_version >= VERSION_R) {
		if (0 != common_raw_read(partition, sizeof(*table_header), fdt_offset, data)) {
			errorf("read dtb table header fail\n");
			goto error;
		}
		table_header = (struct dt_table_header *)data;
		if (be32_to_cpu(table_header->magic) != DT_TABLE_MAGIC) {
			errorf("invalid dtb partition\n");
			goto error;
		}
		if (be32_to_cpu(table_header->dt_entry_count) == 0)
			goto error;
		size = (uint64_t) (be32_to_cpu(table_header->dt_entry_size) *
					be32_to_cpu(table_header->dt_entry_count));
		entry = malloc(size);
		if (NULL == entry) {
			errorf("malloc size=%lld for dt entrys fail\n",size);
			goto error;
		}
		offset_temp = be32_to_cpu(table_header->dt_entries_offset);
		count = be32_to_cpu(table_header->dt_entry_count);

		if (0 != common_raw_read(partition, (uint64_t)size, (uint64_t)(fdt_offset + offset_temp), (char *)entry)) {
			errorf("read dt entries fail\n");
			goto error;
		}

		for (i = 0, cur_entry = entry; i < count; i++, cur_entry++) {
			offset_temp = be32_to_cpu(cur_entry->dt_offset);
			size = sizeof(struct fdt_header);
			if (0 != common_raw_read(partition, (uint64_t)size, (uint64_t)(fdt_offset + offset_temp), &dtb_header)) {
				errorf("read dtb header fail\n");
				goto error;
			}

			if (fdt_check_header(&dtb_header) != 0) {
				errorf("image is not a fdt\n");
				continue;
			}
			size = fdt_totalsize(&dtb_header);
			debugf("offset = 0x%llx size=0x%llx\n", fdt_offset + offset_temp, size);
			/* malloc reserve FDT_ADD_SIZE for fdt fixup */
			fdt_blob = malloc(size + FDT_ADD_SIZE);
			if (NULL == fdt_blob) {
				errorf("malloc size %lld for fdt_blob fail\n", size + FDT_ADD_SIZE);
				goto error;
			}
			if (0 != common_raw_read(partition, (uint64_t)size, (uint64_t)(fdt_offset + offset_temp), (char *)fdt_blob)) {
				errorf("read dtb fail\n");
				goto error;
			}

			ret = look_for_matching_device_from_dt((char *)fdt_blob, DTB_TYPE);
			if (0 != ret) {
				free(fdt_blob);
				fdt_blob = NULL;
			} else
				break;
		}

		if (-1 == ret) {
			errorf("No matching DTB could be found\n");
			goto error;
		}
	} else {
		/* malloc reserve FDT_ADD_SIZE for fdt fixup */
		fdt_blob = (u8 *)malloc(size + FDT_ADD_SIZE);
		if (NULL == fdt_blob) {
			errorf("malloc size 0x%llx for fdt_blob fail\n", size + FDT_ADD_SIZE);
			goto error;
		} else
			debugf("malloc size for fdt: 0x%llx\n", size + FDT_ADD_SIZE);
		if (0 != common_raw_read(partition, (uint64_t)size, (uint64_t)fdt_offset, (char *)fdt_blob)) {
			errorf("dt entry size read error!\n");
			goto error;
		}

		if (fdt_check_header(fdt_blob) != 0) {
			errorf("image is not a fdt\n");
			goto error;
		}
	}
	fdt_size = fdt_totalsize(fdt_blob);
	ret = fdt_open_into(fdt_blob, fdt_blob, fdt_size + FDT_ADD_SIZE);
	if (0 != ret) {
		errorf("libfdt fdt_open_into(): %s\n", fdt_strerror(ret));
		goto error;
	}
	ret = fdt_fixup_memory_region(fdt_blob, &auto_mem_num);
	if(ret < 0)
		goto error;
	fdt_size = fdt_totalsize(fdt_blob);
	size = PAD_SIZE(fdt_size, s_bootimg_info.page_size);
	if (0 == ret && 0 != auto_mem_num) {
		if(0 != get_dt_end_addr(fdt_blob , &dt_end_addr))
			goto end;
		*dt_start_addr = dt_end_addr - size;
	}
end:
	memcpy(*dt_start_addr, fdt_blob, size);
	ret = 0;
error:
	if (NULL != header)
		free(header);
	if (NULL != fdt_blob)
		free(fdt_blob);
	if (NULL != entry)
		free(entry);
	return ret;
}

static int load_kernel_image(boot_img_hdr *hdr, uchar *partition)
{
	uint64_t size;
	uint64_t buf_base;
	uint64_t buf_size;
	uint64_t max_size;
	uint64_t kernel_size = hdr->kernel_size;
	char gzip_header[2];

	size = PAD_SIZE(hdr->kernel_size, s_bootimg_info.page_size);
	if (0 == size) {
		errorf("kernel image should not be zero!\n");
		return 0;
	}

	/* read kernel image head, determine if it is a GZIP header */
	if (0 != common_raw_read(partition, sizeof(gzip_header), s_bootimg_info.kernel_offset, (char *)gzip_header)) {
		errorf("%s kernel read error!\n", partition);
		return 0;
	}

	if ((gzip_header[0] == '\x1f') && (gzip_header[1] == '\x8b')) {
		debugf("The kernel is in GZIP format!\n");
		/* get buffer size */
		if (get_buffer_base_size_from_dt("heap@4", &buf_base, &buf_size)) {
			errorf("get buffer error\n");
			return 0;
		}

		if (size > buf_size) {
			errorf("kernel size > buffer size\n");
			return 0;
		}

		/* read compressed IMG into temporary buffer */
		if (0 != common_raw_read(partition, size, s_bootimg_info.kernel_offset, (char *)buf_base)) {
			errorf("%s kernel read error!\n", partition);
			return 0;
		}

		/* get partition max size */
		if (get_img_partition_size(partition, &max_size)) {
			errorf("get %s partition size error!\n", partition);
			return 0;
		}

		/* decompress the compressed kernel to the kernel address */
		if (gunzip((void *)KERNEL_ADR, (int)max_size, (uchar *)buf_base, &kernel_size)) {
			errorf("gunzip kernel img error!\n");
			return 0;
		}
	} else {
		debugf("The kernel is in raw format!\n");
		/* read kernel image */
		if (0 != common_raw_read(partition, size, s_bootimg_info.kernel_offset, (char *)KERNEL_ADR)) {
			errorf("%s kernel read error!\n", partition);
			return 0;
		}
	}
	debugf("%s kernel read OK, page size = 0x%llx, locate to 0x%lx \n", partition, size, (ulong)KERNEL_ADR);

	return 1;
}


/* Simple real checksum for bootconfig */
static int checksum(unsigned char *buf, int len)
{
        int i, sum = 0;

        for (i = 0; i < len; i++)
                sum += buf[i];

        return sum;
}

static int read_vendor_bootconfig(uchar *ramdisk_addr)
{
	int ret;

	if (s_bootimg_info.vendor_bootconfig_size != 0) {
		ret = common_raw_read(s_bootimg_info.vendor_boot_part, s_bootimg_info.vendor_bootconfig_size,
				s_bootimg_info.vendor_bootconfig_offset, ramdisk_addr);
		if (ret != 0) {
			errorf("%s bootconfig read error!\n", s_bootimg_info.vendor_boot_part);
			return 0;
		}
	}
	debugf("%s bootconfig read OK, size = %lld, locate to %p!\n",
		s_bootimg_info.vendor_boot_part, s_bootimg_info.vendor_bootconfig_size, ramdisk_addr);
	return 1;
}

int _boot_load_kernel_ramdisk_image(char *bootmode, boot_img_hdr * hdr, uchar **dt_addr )
{
	uchar *partition = NULL;
	uchar *dtb_partname = NULL;
	uint64_t size;
	uchar *dt_img_adr;
	char  *boot_mode_type_str;
	uchar *ramdisk_addr = RAMDISK_ADR;
	uint64_t fdt_size = 0;
	int ret;
	boot_img_hdr_v3 *hdr_v3 = (boot_img_hdr_v3 *)hdr;
	uint64_t ramdisk_size;
	char bootconfig_trailer[BOOTCONFIG_TRAILER_SIZE];
	uint32_t bootconfig_size_v4 = 0;
	uint32_t bootconfig_checksum_v4 = 0;
	uint8_t bootconfig_gap = 0;

	if (0 == memcmp(bootmode, RECOVERY_PART, strlen(RECOVERY_PART))) {
#ifdef CONFIG_ANDROID_AB
		partition = "boot";
#else
		partition = "recovery";
#endif
		debugf("enter recovery mode!\n");
	} else {
		partition = "boot";
		debugf("enter boot mode!\n");
	}

#ifdef CONFIG_ANDROID_AB
	char temp[128];
	strcpy(temp, get_slot_ab(partition));
	partition = temp;
#endif

	if(0 == _get_kernel_ramdisk_dt_offset(hdr, partition))
		return 0;

/*
 * load kernel
 */
	ret = load_kernel_image(hdr, partition);
	if (!ret) {
		errorf("load kernel image fail\n");
		return 0;
	}

/*
 * load dtb
 */
	if ((hdr->header_version == BOOT_HEADER_VERSION_THREE || hdr->header_version == BOOT_HEADER_VERSION_FOUR) &&
			(hdr_v3->ramdisk_size)) {
		size = PAD_SIZE(hdr_v3->ramdisk_size, s_bootimg_info.page_size);
		ramdisk_size = hdr_v3->ramdisk_size;
	} else if (hdr->ramdisk_size) {
		size = PAD_SIZE(hdr->ramdisk_size, s_bootimg_info.page_size);
		ramdisk_size = hdr->ramdisk_size;
	}

	/*read dt image*/
#if defined(CONFIG_SEPARATE_DT)
	if (!_boot_load_separate_dt())
		return 0;
	fdt_size = fdt_totalsize(DT_ADR);
	ret = fdt_open_into(DT_ADR, DT_ADR, fdt_size + FDT_ADD_SIZE);
	if (0 != ret)
		errorf("libfdt fdt_open_into(): %s\n", fdt_strerror(ret));
	fdt_fixup_all((uchar *)DT_ADR);
#else
	if (BOOT_HEADER_VERSION_ONE == hdr->header_version) {
		/* fixbug1007672 */
		struct boot_img_hdr_v2 *hdr_v2 = get_boot_img_hdr_v2(hdr);
		if (hdr_v2->dtb_size && hdr_v2->dtb_addr) {
			dtb_partname = partition;
			s_bootimg_info.dt_offset = hdr_v2->dtb_addr;
		} else if (0 == common_raw_read("dtb", 10, 0, (char *)DT_ADR)) {
			dtb_partname = "dtb";
			s_bootimg_info.dt_offset = 0;
		} else {
			dtb_partname = partition;
		}
	} else if (BOOT_HEADER_VERSION_THREE == hdr->header_version ||
			BOOT_HEADER_VERSION_FOUR == hdr->header_version) {
		dtb_partname = s_bootimg_info.vendor_boot_part;
	} else {
		dtb_partname = partition;
	}

	/* for memory defragment, dr_addr and ramdisk_adr is allocated dynamically*/
	if (0 == load_fixup_dt_img(dtb_partname, dt_addr)) {
		if (DT_ADR != *dt_addr) {
			debugf("allocate dt_addr:%p \n", *dt_addr);
			/*allocate  ramdisk addr */
			ramdisk_addr = *dt_addr - size;
		} else {
			debugf(" use default value : DT_ADDR & RAMDISK_ADR\n");
		}
	} else {
		errorf("load dt error!\n");
		return 0;
	}

/*
 * load dtbo
 */
#ifdef CONFIG_OF_LIBFDT_OVERLAY
	if (BOOT_HEADER_VERSION_ONE == hdr->header_version) {
		if (0 == memcmp(bootmode, RECOVERY_PART, strlen(RECOVERY_PART))) {
			load_and_merge_dtbo(partition, *dt_addr);
		} else {
			merge_dtbo(*dt_addr);
		}
	} else if (BOOT_HEADER_VERSION_TWO == hdr->header_version) {
		if (s_bootimg_info.recovery_dtbo_offset && getenv("bootmode") && (!strcmp("recovery", getenv("bootmode"))))
			load_and_merge_dtbo(partition, *dt_addr);
		else
			merge_dtbo(*dt_addr);
	} else if (BOOT_HEADER_VERSION_THREE == hdr_v3->header_version ||
                  BOOT_HEADER_VERSION_FOUR == hdr_v3->header_version) {
		merge_dtbo(*dt_addr);
	}

	if (img_os_version >= VERSION_R) {
		if (merge_bootargs(*dt_addr))
			errorf("bootargs and bootargs_ext merge faided\n");
	}
#endif
#endif
	fdt_fixup_all(*dt_addr);
/*
 * load ramdisk
 */
	if(ramdisk_size) {
		if (BOOT_HEADER_VERSION_THREE == hdr_v3->header_version) {
			fdt_initrd_norsvmem(*dt_addr, ramdisk_addr,
				ramdisk_addr + hdr_v3->ramdisk_size + s_bootimg_info.vendor_ramdisk_size, 1);

			/* read vendor ramdisk image */
			if (0 != common_raw_read(s_bootimg_info.vendor_boot_part, s_bootimg_info.vendor_ramdisk_size,
					s_bootimg_info.vendor_ramdisk_offset, ramdisk_addr)) {
				errorf("%s ramdisk read error!\n", s_bootimg_info.vendor_boot_part);
				return 0;
			}
			debugf("%s ramdisk read OK, size = %lld, locate to %p!\n",
				s_bootimg_info.vendor_boot_part, s_bootimg_info.vendor_ramdisk_size, ramdisk_addr);

			ramdisk_addr = ramdisk_addr + s_bootimg_info.vendor_ramdisk_size;

			/* read ramdisk image */
			if (0 != common_raw_read(s_bootimg_info.bootimg_part, hdr_v3->ramdisk_size,
					s_bootimg_info.ramdisk_offset, ramdisk_addr)) {
				errorf("%s ramdisk read error!\n", s_bootimg_info.bootimg_part);
				return 0;
			}
			debugf("%s ramdisk read OK, size = %d, locate to %p!\n",
				s_bootimg_info.bootimg_part, hdr_v3->ramdisk_size, ramdisk_addr);

		} else if(BOOT_HEADER_VERSION_FOUR == hdr_v3->header_version){
			bootconfig_gap =  s_bootimg_info.vendor_bootconfig_size % 4;
			if(bootconfig_gap!=0){
				bootconfig_gap = 4 - bootconfig_gap;
				bootconfig_size_v4 = s_bootimg_info.vendor_bootconfig_size + bootconfig_gap;
			}else
				bootconfig_size_v4 = s_bootimg_info.vendor_bootconfig_size;

			fdt_initrd_norsvmem(*dt_addr, ramdisk_addr,
				ramdisk_addr + hdr_v3->ramdisk_size + s_bootimg_info.vendor_ramdisk_size + bootconfig_size_v4 + BOOTCONFIG_TRAILER_SIZE, 1);

			/* read vendor ramdisk image */
			if (0 != common_raw_read(s_bootimg_info.vendor_boot_part, s_bootimg_info.vendor_ramdisk_size,
					s_bootimg_info.vendor_ramdisk_offset, ramdisk_addr)) {
				errorf("%s ramdisk read error!\n", s_bootimg_info.vendor_boot_part);
				return 0;
			}
			debugf("%s ramdisk read OK, size = %lld, locate to %p!\n",
				s_bootimg_info.vendor_boot_part, s_bootimg_info.vendor_ramdisk_size, ramdisk_addr);

			ramdisk_addr = ramdisk_addr + s_bootimg_info.vendor_ramdisk_size;

			/* read ramdisk image */
			if (0 != common_raw_read(s_bootimg_info.bootimg_part, hdr_v3->ramdisk_size,
					s_bootimg_info.ramdisk_offset, ramdisk_addr)) {
				errorf("%s ramdisk read error!\n", s_bootimg_info.bootimg_part);
				return 0;
			}
			debugf("%s ramdisk read OK, size = %d, locate to %p!\n",
				s_bootimg_info.bootimg_part, hdr_v3->ramdisk_size, ramdisk_addr);

			ramdisk_addr = ramdisk_addr + hdr_v3->ramdisk_size;

			/*read bootconfig (from vendor_boot) right after the generic ramdisk.*/
			read_vendor_bootconfig(ramdisk_addr); /* To reduce ccn */

			/*Add the bootconfig trailer to end of the parameters */
			if(bootconfig_gap!=0)
				memset((ramdisk_addr + s_bootimg_info.vendor_bootconfig_size),'\0',bootconfig_gap);
			bootconfig_checksum_v4 = checksum(ramdisk_addr, bootconfig_size_v4);
			ramdisk_addr = ramdisk_addr + bootconfig_size_v4;

			memset(bootconfig_trailer, 0, BOOTCONFIG_TRAILER_SIZE);
			setbits_le32(&bootconfig_trailer[0], bootconfig_size_v4);
			setbits_le32(&bootconfig_trailer[4], bootconfig_checksum_v4);
			memcpy(&bootconfig_trailer[8], "#BOOTCONFIG\n", 12);
			debugf("add bootconfig tailer:size = %08x, checksum: %d locate to %p!\n",
				bootconfig_size_v4, bootconfig_checksum_v4, ramdisk_addr);

			memcpy(ramdisk_addr, &bootconfig_trailer[0], BOOTCONFIG_TRAILER_SIZE);
		} else {
			fdt_initrd_norsvmem(*dt_addr, ramdisk_addr, ramdisk_addr + hdr->ramdisk_size, 1);
			if (0 == size) {
				errorf("ramdisk image size should not be zero\n");
				return 0;
			}
			/*read ramdisk image */
			if (0 != common_raw_read(partition, size, (uint64_t)(s_bootimg_info.ramdisk_offset), ramdisk_addr)) {
				errorf("%s ramdisk read error!\n", partition);
				return 0;
			}
			debugf("%s ramdisk read OK,size=0x%llx, locate to %p \n", partition, size, ramdisk_addr);

			boot_mode_type_str = getenv("bootmode");
			if (NULL != boot_mode_type_str)
			{
				if(!strncmp(boot_mode_type_str, "sprdisk", 7)) {
					int ramdisk_size;
					ramdisk_size = boot_sprdisk(0, ramdisk_addr);
					if (ramdisk_size > 0) {
						hdr->ramdisk_size = ramdisk_size;
						if (RAMDISK_ADR != ramdisk_addr) {
							/* get ramdisk size , calculate addr, so we can have enough room for sprdisk ramdisk */
							size = PAD_SIZE(hdr->ramdisk_size, KERNL_PAGE_SIZE);
							ramdisk_addr = *dt_addr - size;
							hdr->ramdisk_addr = ramdisk_addr;
						}
						fdt_initrd_norsvmem(*dt_addr, ramdisk_addr, ramdisk_addr+hdr->ramdisk_size , 1);
						boot_sprdisk(ramdisk_size, ramdisk_addr);
					} else {
						errorf("%s, sprdisk mode failure!\n", __FUNCTION__);
					}
					return 1;
				}
			}
		}

#ifdef CONFIG_SDRAMDISK
		{
			int sd_ramdisk_size = 0;
#ifdef WDSP_ADR
			size = WDSP_ADR - RAMDISK_ADR;
#else
			size = TDDSP_ADR - RAMDISK_ADR;
#endif
			if (size > 0)
				_sd_fat_mount();
				sd_ramdisk_size = load_sd_ramdisk((void *) RAMDISK_ADR, size);
			if (sd_ramdisk_size > 0)
				hdr->ramdisk_size = sd_ramdisk_size;
		}
#endif
	}

	return 1;
}

#ifdef CONFIG_SEPARATE_DT
int _boot_load_separate_dt(void)
{
	struct dt_table table;
	char * header = NULL;
	struct dt_entry *dt_entry_ptr;
	uint32_t secure_boot_offset = 0;
	uint64_t offset = 0;
	uint64_t size = 0;

#ifdef CONFIG_SECURE_BOOT
	if (0 != common_raw_read("dt", EMMC_SECTOR_SIZE, (uint64_t)0, &table)) {
		errorf("dt read error!\n");
		free(table);
		return 0;
	}
	secure_boot_offset = get_code_offset(table);
	offset += secure_boot_offset;
#endif
#ifdef CONFIG_SECBOOT
	offset = 512;/**header of image size is 512B**/
#endif

	size = sizeof(struct dt_table);
	if (0 != common_raw_read(DT_PART, size, offset, &table)) {
		errorf("read dt image table header fail\n");
		goto fail;
	}

	/* Validate the device tree table header */
	if((table.magic != DEV_TREE_MAGIC) || (table.version != DEV_TREE_VERSION)) {
		errorf("Cannot validate Device Tree Table \n");
		goto fail;
	}

	size = sizeof(struct dt_table) + sizeof(struct dt_entry) * table.num_entries;
	header = (char *)malloc(size);
	if (NULL == header) {
		errorf("malloc size %d for dt header fail\n", size);
		goto fail;
	}
	if (0 != common_raw_read(DT_PART, size, offset, header)) {
		errorf("read dt image table and entries header fail\n");
		goto fail;
	}

	/* Calculate the offset of device tree within device tree table */
	dt_entry_ptr = dev_tree_get_entry_ptr((struct dt_table *)header);
	if(NULL == dt_entry_ptr) {
		errorf("Getting device tree address failed\n");
		goto fail;
	}

	size = dt_entry_ptr->size;
	offset += dt_entry_ptr->offset;
	if (0 != common_raw_read(DT_PART, size, offset, (char *)DT_ADR)) {
		errorf("dt entry size 0x%x offset 0x%x read error!\n", size, offset);
		goto fail;
	}

	debugf("load separate DT OK,size=0x%llx, locate to 0x%lx \n", size, (ulong)DT_ADR);
	free(header);
	return 1;

fail:
	if (NULL != header)
		free(header);
	return 0;
}
#endif

/*TODO*/
#ifdef CONFIG_SECURE_BOOT
int secure_verify_partition(block_dev_desc_t * dev, uchar * partition_name, void *ram_addr)
{
	int ret = 0;
	int size;
	disk_partition_t info;

	if (get_partition_info_by_name(dev, partition_name, &info)) {
		errorf("verify get partition %s info failed!\n", partition_name);
		ret = 1;
	}
	size = info.size * EMMC_SECTOR_SIZE;
	debugf("%s=%x  =%x\n", partition_name, info.size, size);
	_boot_partition_read(dev, partition_name, 0, size, (uint8_t *) ram_addr);
	secure_verify("uboot", (uint8_t *) ram_addr, 0);
	return ret;
}
#endif

#ifdef CONFIG_VBOOT_V2
int secure_get_partition_size(uchar * partition_name, uint64_t * size)
{
	int ret = 0;
#ifdef CONFIG_ANDROID_AB
        char * partition = get_slot_ab(partition_name);
	ret = get_img_partition_size(partition, size);
#else
	ret = get_img_partition_size(partition_name, size);
#endif

	debugf("partition:%s,size:0x%llx\n", partition_name, *size);
	return ret;
}
#endif

#ifdef CONFIG_ZEBU
void vlx_nand_boot_zebu(char *kernel_pname, int backlight_set, int lcd_enable)
{
	int err;
	uint64_t fdt_size;
	uint32_t size = DT_SIZE;
	size = (size+(KERNL_PAGE_SIZE - 1)) & (~(KERNL_PAGE_SIZE - 1));
	uint64_t dt_img_adr = RAMDISK_ADR - size - KERNL_PAGE_SIZE;
	debugf("%s,dt_img_addr:%p\n",__func__,dt_img_adr);

	/* copy kernel/dt/ramdisk/sml from jointRAM to InterlaceRAM */
#ifdef CONFIG_INTERLACE_RAM_COPY
	memcpy(KERNEL_ADR,SRC_KERNEL_ADR,KERNEL_SIZE);
	memcpy(RAMDISK_ADR,SRC_RAMDISK_ADR,RAMDISK_SIZE);
	memcpy(dt_img_adr,SRC_DT_ADR,DT_SIZE);
	debugf("copy kernel to interlace RAM done\n");
#endif

	/*fixup dtb size*/
	fdt_size = fdt_totalsize(DT_ADR);
	err = fdt_open_into(DT_ADR, DT_ADR, fdt_size +
                                    FDT_ADD_SIZE);
	if (err != 0) {
		errorf("libfdt fdt_open_into(): %s\n", fdt_strerror(err));
	}

	fdt_fixup_ddrsize_range(DT_ADR);

#ifdef CONFIG_DDR_BOOT_DTBOIMAGE_A_ADR
        err = fdt_overlay_apply(DT_ADR,CONFIG_DDR_BOOT_DTBOIMAGE_A_ADR);
        if (err) {
		errorf("fdt_overlay_apply(): %s\n",fdt_strerror(err));
        }
#else
        debugf("there is no dtbo address\n");
#endif

	uint32_t r_size = RAMDISK_SIZE;
	r_size = (r_size+(KERNL_PAGE_SIZE - 1)) & (~(KERNL_PAGE_SIZE - 1));
	fdt_initrd_norsvmem((uchar *)DT_ADR, RAMDISK_ADR, RAMDISK_ADR+r_size, 1);

	vlx_entry(DT_ADR);
}
#endif

#ifdef CONFIG_SECBOOT
int loader_binding_data_set(void)
{
	if(lcd_low_bat == 1 ||((cmd_fastboot ==1)&&(low_bat==1)))  
	{
		debugf("lcd_low_bat is ture\n");
		//lcd_printf("Fastboot mode cannot be entered when power is below 30%!!!\n");
		lcd_printf("The battery capacity is less than 30%, forbit enter fastboot mode!!!\n");
	}		
	/*set device state*/
	get_lock_status();

	if(g_DeviceStatus == VBOOT_STATUS_LOCK){
		debugf("INFO: LOCK FLAG IS : LOCK!!!\n");
	}else if(g_DeviceStatus == VBOOT_STATUS_UNLOCK){
		debugf("INFO: LOCK FLAG IS : UNLOCK!!!\n");
		lcd_printf("INFO: LOCK FLAG IS : UNLOCK!!!\n");
	}

	return 0;
}

int loader_binding_state_get(void)
{
	if(g_DeviceStatus == 0xFFFFFFFF) {
		debugf("Warning: get device state error: state is not initiated!\n");
		return -1;
	}

	return g_DeviceStatus;
}

int sprd_sec_verify_lockstatus(unsigned char *lockstatus, unsigned int status_len)
{
#ifndef CONFIG_VBOOT_V2
	return -1; /*default status : locked*/
#else
	uint8_t data_buffer[128] __attribute__((aligned(4096)));
	uint8_t * v_lock_state_ret = (uint8_t *)data_buffer + PDT_INFO_LOCK_FLAG_MAX_SIZE;

	uint32_t ret;

	if(!lockstatus || !status_len || (status_len > PDT_INFO_LOCK_FLAG_MAX_SIZE))
	{
		debugf("para error. \n");
		return -1;
	}

	memset(data_buffer, 0, sizeof(data_buffer));
	memcpy(data_buffer, lockstatus, status_len);

#ifdef CONFIG_VBOOT_DUMP
	do_hex_dump(data_buffer, status_len);
#endif

	ret = uboot_verify_lockstatus(data_buffer, sizeof(data_buffer));

	if(*v_lock_state_ret == VBOOT_STATUS_LOCK)
	{
		//debugf("verify unlock status failed. \n");
		ret = -1;
	}

	return ret;
#endif
}
#endif

#if defined (CONFIG_SECBOOT)
int take_action_with_vbootret(void)
{
	int sec_time_count = 60;
	char buf[256];
        
	memset(buf, 0, 256);

	switch(g_verifiedbootstate) {
		case v_state_red:
			debugf("WARNNING: Oem Key & User Key Verify Failed!!!\n");
			display_state_verified_red();
/*
			while(sec_time_count) {
				mdelay(100);
				sec_time_count --;
			}
*/
			power_down_devices(0);
			break;

		case v_state_yellow:
			debugf("WARNNING: USER KEY VERIFY SUCCESS!!!\n");
            display_state_verified_yellow();
			break;

		case v_state_green:
			debugf("WARNNING: OEM KEY VERIFY SUCCESS!!! bootmode=%d\n", s_boot_mode);
			break;

		case v_state_orange:
			debugf("WARNNING: LOCK FLAG IS : UNLOCK, SKIP VERIFY!!!\n");
			//lcd_printf("WARNNING: LOCK FLAG IS : UNLOCK, SKIP VERIFY!!!\n");
            display_state_verified_orange();
			break;

		default:
			debugf("WARNNING: VERIFY RESULT UNKNOWN!!!\n");
			break;
	}

	return 0;
}
#endif
// add for SOTER start
#if defined (CONFIG_CHIP_UID)
static u32 blocks[2] __attribute__((aligned(4096)));

void pass_chip_uid_to_tos()
{
    //u32 blocks[2]/* = {0} */__attribute__((aligned(4096)));
    //u32 *blocks = gd->verify_base;
    smc_param *param;

    printf("pass_chip_uid_to_tos()... sizeof(blocks)=%ld\n", sizeof(blocks));
    memset(blocks, 0, sizeof(blocks));
#if defined (CONFIG_SPRD_UID)
    blocks[1] = sprd_efuse_double_read(UID_START, UID_DOUBLE);
    blocks[0] = sprd_efuse_double_read(UID_END, UID_DOUBLE);
    param = tee_common_call(FUNCTYPE_SET_CHIP_UID, (uint32_t)blocks, sizeof(u32)*2);
    printf("blks:0x%08x 0x%08x, result: 0x%x \n", blocks[0], blocks[1], param->a0);
#else
    blocks[0]= sprd_ap_efuse_read(0);
    blocks[1]= sprd_ap_efuse_read(1);
    param = tee_common_call(FUNCTYPE_SET_CHIP_UID, (uint32_t)blocks, sizeof(u32)*2);
    printf("blks:0x%08x 0x%08x, result: 0x%x \n", blocks[0], blocks[1], param->a0);
#endif
    return;
}
#endif
// add for SOTER end

uint32_t uboot_start_time;
extern unsigned int g_charger_mode;
void power_cfg(void)
{
	wakeup_source_enable();
	ap_clk_doze_enable();
	return ;
}

#ifdef CONFIG_VIBRATOR
void vibrator_load(int enable)
{
	set_vibrator(enable);
	return ;
}
#endif

int load_require_image(void)
{
	int row=0, colum=0;

	//do something.... befor loading required image
#ifdef CONFIG_ARM7_RAM_ACTIVE
	pmic_arm7_RAM_active();
#endif

	//begin loading required image ....
	while (s_boot_image_table[row]) {
		colum = 0;
		while (s_boot_image_table[row][colum].partition) {
			_boot_load_required_image(s_boot_image_table[row][colum]);
			#if defined(CONFIG_CH_ENABLE) && !defined(CONFIG_CH_DDR_BOOT)
			if (0 == memcmp("ch_sys", s_boot_image_table[row][colum].partition, strlen("ch_sys")))
				memcpy(CH_IRAM_ADDR, CH_DDR_ADDR, CH_IRAM_SIZE);
			#endif
			colum++;
		}
		row++;
	}

#if defined(CONFIG_KERNEL_BOOT_CP)
	if(g_charger_mode) {
		boot_image_required_t pm_image = {"pm_sys", NULL, DFS_SIZE, DFS_ADDR};
		_boot_load_required_image(pm_image);
	}
#endif

#if !defined(CONFIG_KERNEL_BOOT_CP) && defined(CONFIG_MEM_LAYOUT_DECOUPLING)
	extern boot_image_required_t *get_cp_load_table(void);
	do {
		boot_image_required_t *cp_load_table = NULL;
		cp_load_table = get_cp_load_table();
		printf("cp_load_table = 0x%p\n", cp_load_table);
		if (NULL != cp_load_table) {
			for(row = 0; cp_load_table[row].size > 0; row++) {
				_boot_load_required_image(cp_load_table[row]);
			}
		}
	} while(0);
#endif

	return 0;
}

int load_kernel_ramdisk(char *bootmode, boot_img_hdr *hdr, char *dt_adr, char *ramdisk_adr)
{
	int ret = 0;
	uchar *adr = dt_adr;

#ifdef OTA_BACKUP_MISC_RECOVERY
	ret = memcmp(bootmode, RECOVERY_PART, strlen(RECOVERY_PART));
	if ((ret != 0) || (boot_load_recovery_in_sd(hdr) != 0))
		if (!_boot_load_kernel_ramdisk_image(bootmode, hdr, &adr))
			ret = -1;
#else
	/*loader kernel and ramdisk*/
	if (!_boot_load_kernel_ramdisk_image(bootmode, hdr, &adr))
		ret = -1;
#endif

	return ret;
}


int _uboot_set_postload(void)
{
	struct post_load_operations *postload = &_uboot_post_load;

	// add for SOTER start
#if defined (CONFIG_CHIP_UID)
	pass_chip_uid_to_tos();
#endif
	 // add for SOTER end
	postload->rpmb();

	printf("uboot postload\n");
#ifdef CONFIG_TEE_FIREWALL
	//fdt_reserved_mem_multimedia_parse(dt_adr);
#endif
#ifdef  CONFIG_SPRD_HW_I2C
	i2c_dvfs_hwchn_init();
#endif
#ifdef  CONFIG_SPRD_HW_I2C_V2
	i2c_dvfs_hwchn_init();
#endif
	if (postload->secboot_terminal) {
		postload->secboot_terminal();
	}

	return 0;
}

int _uboot_set_preload(int lcd_enable, uint32_t brightness)
{
	struct pre_load_operations *preload = &_uboot_pre_load;

	//pmic & wakeup configure
	preload->power();

	//lcd/backlight/vibrator configure
	preload->display(LOGO_NORMAL_POWER, brightness, lcd_enable);
#ifdef CONFIG_VIBRATOR
	preload->vibrator(0);
#endif
	if (preload->secboot_init) {
		preload->secboot_init();
	}

	return 0;
}

void rpmb_check(void)
{
//#if defined(TOS_TRUSTY) && defined(CONFIG_EMMC_BOOT) && defined(CONFIG_SPRD_RPMB)

#if defined(CONFIG_SPRD_RPMB)

#if defined(CONFIG_SPRD_WRITE_RPMB_KEY)
	uint8_t key[32];
	int rc;

	rc = uboot_write_rpmb_key(key);
	if (0 == rc) {
		sprd_init_all_imgversion(key);
	}
	memset((void*)key,  0, sizeof(key));
#endif

	uboot_set_rpmb_size();
	uboot_is_wr_rpmb_key();
	uboot_check_rpmb_key();
	uboot_set_rpmb_device_type();
#endif
	return;
}
void vlx_nand_boot(char *kernel_pname, int backlight_set, int lcd_enable)
{
	boot_img_hdr *hdr = (void *)raw_header;
	uchar *partition = NULL;
	int ret = 0;
	uchar *dt_adr = DT_ADR;

	//1. uboot preload doing...
	_uboot_set_preload(lcd_enable, backlight_set);

#if defined(CONFIG_SECURE_BOOT)||defined(CONFIG_SECBOOT)
	debugf("SECUREBOOT_ENABLE\n");
	if (0 == memcmp(kernel_pname, RECOVERY_PART, strlen(RECOVERY_PART))) {
#ifdef CONFIG_ANDROID_AB
		partition = "boot";
#else
		partition = "recovery";
#endif
	} else {
		partition = "boot";
	}
#if defined (CONFIG_SECURE_BOOT)
	secure_verify_partition(dev, partition, KERNEL_ADR);
#endif

#if defined (CONFIG_SECBOOT)
	/***secboot only 3 steps***/
	/***secboot 1st step***/
	secboot_init(partition);

	/***secboot 2nd step***/
	/*set v-boot binding data eg:lock status*/
	loader_binding_data_set();

	vboot_secure_process_flow(partition);
#endif
#endif

	//2. uboot gsm/wcdma/td/lte/5g image loading....
	load_require_image();

#if defined (CONFIG_SECBOOT)
		secboot_secure_process_flow(partition,0,0,(char *)gd->verify_base);
		//things to do refer to verify ret
		take_action_with_vbootret();

		if(set_root_of_trust(root_of_trust_str, ROOT_OF_TRUST_MAXSIZE)) {
			printf("set_root_of_trust failed.\n");
		} else {
			printf("set_root_of_trust succeeded.\n");
		}
#endif

	//4. uboot kernel & ramdisk loading...
	ret = load_kernel_ramdisk(kernel_pname, hdr, dt_adr,NULL);
	if (-1 == ret)
		return;

#ifdef PROJECT_SEC_CM4
	if(g_charger_mode)
	{
        boot_image_required_t pm_image = {"pm_sys", NULL, DFS_SIZE, DFS_ADDR};

		/* load sp ddr boot */
#ifdef CONFIG_SP_DDR_BOOT
		load_sp_boot_code();
#endif

		/***secboot 2nd step***/
		vboot_secure_process_flow_cm4(pm_image.partition);
        }
#endif

	//last. uboot postload doing...
	_uboot_set_postload();

#if defined (CONFIG_SECBOOT)
	/***secboot 3rd step***/
	secboot_terminal();
#endif

	vlx_entry(dt_adr);
}
