/*
 * Copyright (c) 2009, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <common.h>
#include <malloc.h>
#include <android_bootimg.h>
#include <boot_mode.h>
#include <dl_common.h>
#include "sparse_format.h"
#include <linux/usb/usb_uboot.h>
#include <sprd_common_rw.h>
#include <asm/errno.h>
#include "dl_operate.h"
#include <asm/arch/chip_releted_def.h>
#include <linux/input.h>
#include <secureboot/sec_common.h>
#include "../../fs/f2fs-tools/include/f2fs_fs.h"
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#include <chipram_env.h>
#endif
#include <bootloader_message.h>
#include <miscdata_def.h>

//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
#include <sprd_kp.h>
//20220606, Added by zhu_jun for bootloader unlock by devicekit end

//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
#include "oem_fastboot_cmd.h"
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
#include "sprd_cpcmdline.h"
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end

//20220614, Added by zhu_jun for disable enter recovery via fastboot reboot recovery on MP&User build begin
#include <mpflag_def.h>
//20220614, Added by zhu_jun for disable enter recovery via fastboot reboot recovery on MP&User build end
#include "others.h"
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
#include <crypto/authentication.h>
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end
int is_gsimode = 0;
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
char upload_buf[UPLOADE_SIZE] = {0};
unsigned int upload_len = 0;
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end
extern SPECIAL_PARTITION_CFG const s_special_partition_cfg[];
extern uchar *_get_backup_partition_name(uchar * partition_name);
extern void lcd_printf(const char *fmt, ...);
extern char *block_dev_get_name(void);

//20220615, Added by zhu_jun for disable bootloader unlock  on user MP device begin
extern bool is_MP_Device();
//20220615, Added by zhu_jun for disable bootloader unlock  on user MP device end

unsigned int g_download_part_count = 0;
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
unsigned char auth_data[AUTH_DATA_LEN+1]= {0};
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
char powp_buf[WT_POWP_LEN] = {0};
int powp_size = 0;
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end

//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
#ifdef CONFIG_PCTOOL_AUTHORIZE_HMD
char hmd_cali_buf[HMD_CALI_MODE_SIGNATURE_LEN] = {0};
int hmd_cali_size = 0;
#endif
//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end

//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
char hmd_download_buf[HMD_DOWNLOAD_MODE_SIGNATURE_LEN] = {0};
int hmd_download_size = 0;
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
/* edl download flag offset */
#define MISCDATA_EDL_OFFSET		(9 * 1024 + 832)

#define MISCDATA_PSN_OFFSET		0//(9 * 1024 + 64)
#define MISCDATA_PSN_SZ			64//(64 + 2)
/* format: 7E+7E+.... */
#define MISCDATA_SKUID_OFFSET	(9 * 1024 + 832 + 64)
#define MISCDATA_SKUID_SZ		(16 + 2)
#define MISCDATA_WALLPP_OFFSET	(MISCDATA_SKUID_OFFSET + MISCDATA_SKUID_SZ)
#define MISCDATA_WALLPP_SZ		(2 + 2)

#define TYPE_PERMISSION_FLASH   (0)
#define TYPE_PERMISSION_REPAIR  (2)
#define TYPE_PERMISSION_SIMLOCK (1)
#endif

#define ALL_VERSION_OFFSET	(768 * 1024)//Customer customization.
#define PRODUCT_NAME_OFFSET	(768 * 1024 + 128)//Customer customization.

#define OEM_UPLOAD_FLASH_BUF	0x80000 //0x200000

//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
#define PW_KEY_PRESSED        0
#define PW_KEY_NOT_PRESSED    1
//20220606, Added by zhu_jun for bootloader unlock by devicekit end
//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked begin
#define MISCDATA_BLOCK_OFFSET		(768 * 1024 + 766)
#define MAGIC_BLOCK_FLAG				{1}
#define FLAG_BLOCKED					(1)
#define FLAG_UNBLOCKED					(0)
//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked end
enum ALL_VER{
	MODLE = 0,
	SUB_MD,
	SW_VR,
	SW_MD,
	BD_NU,
	HW_VR,
	RF_ID,
	ALL_VER_MAX,
};

#ifdef CONFIG_SECURE_BOOT
#include "secure_verify.h"
#endif
#define FLASHING_LOCK_PARA_LEN (8)

#ifdef CONFIG_NAND_BOOT
#include <nand.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/nand.h>
#include <jffs2/load_kernel.h>


typedef struct {
	char *vol;
	char *bakvol;
} FB_NV_VOL_INFO;

static FB_NV_VOL_INFO s_nv_vol_info[] = {
	{"fixnv1", "fixnv2"},
	{"wfixnv1", "wfixnv2"},
	{"tdfixnv1", "tdfixnv2"},
	{NULL, NULL}
};

#endif

struct dl_image_inf {
	uint8_t *base_address;
	uint64_t max_size;
	uint64_t data_size;
#ifdef CONFIG_WR_SPARSE
	uint64_t max_size_raw;
	char part_name[PARTNAME_SZ];
	int first_pkt;
#endif
};

#define ROUND_TO_PAGE(x,y) (((x) + (y)) & (~(y)))

struct fastboot_cmd {
	struct fastboot_cmd *next;
	const char *prefix;
	unsigned prefix_len;
	void (*handle) (const char *arg, void *data, uint64_t sz);
};

struct fastboot_var {
	struct fastboot_var *next;
	const char *name;
	const char *value;
};

static struct fastboot_cmd *cmdlist;
struct dl_image_inf ImageInfo;
unsigned int fastboot_image_size = 0;
static unsigned char buffer[4096] __attribute__((aligned(64)));

typedef enum {
	STATE_OFFLINE = 0,
	STATE_COMMAND,
	STATE_COMPLETE,
	STATE_ERROR
} FB_USB_STATE;

extern int rsa_encrypt_data(unsigned char *send_data);
extern int rsa_decrypt_data(unsigned char *data_type, unsigned char *revice_data, unsigned char *sn_data);
extern int usb_fastboot_exit(void);
static unsigned fastboot_state = STATE_OFFLINE;
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
extern int rsa_encrypt_data(unsigned char *send_data);
extern int rsa_decrypt_data(unsigned char *data_type, unsigned char *revice_data, unsigned char *sn_data);
unsigned char encrypt_data[344] = {0};
static unsigned int open_permission = 0;
#endif
extern int usb_fastboot_init(void);
extern int fb_usb_write(void *buf, unsigned len);
extern int fb_usb_read(void *_buf, unsigned len);
extern int fb_usb_read_triger(void *_buf, unsigned len);
extern int fb_read_usb_query_finish(void);

extern void power_down_devices(unsigned pd_cmd);
extern void reboot_devices(unsigned reboot_mode);
extern void splFillCheckData(uchar * splBuf);

/*for fastboot getlcs, getsocid, setrma cmd*/
#ifdef CONFIG_SECBOOT
extern int get_lcs(uint32_t *p_lcs);
extern int get_socid(uint64_t start_addr, uint64_t lenth);
extern int set_rma(void);
extern unsigned int get_lock_status(void);
extern int set_lock_status(unsigned int flag);
#endif
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
extern char *get_product_imei1(void);
extern char *get_product_imei2(void);
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
extern char *get_product_sn();

//20220602,Added by zhu_jun for suport fastboot command:fastboot getvar boardid begin
extern char *target_get_boardname(void);
//20220602,Added by zhu_jun for suport fastboot command:fastboot getvar boardid end

//added by dongming, for AGT-685, 20221011
char s_repair_signature[HMD_EDL_MODE_SIGNATURE_LEN] = {0};
int  s_repair_signature_realsize = 0;
//end added by dongming, for AGT-685

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#ifdef CONFIG_ERASE_SPL_AUTO_DOWNLOAD
extern int erase_spl_enter_download_mode(void);
#endif
extern int set_product_sn(char *psn, int len);
#endif
# ifndef CONFIG_DTS_MEM_LAYOUT
unsigned char *g_FbBuf = (unsigned char *)0x82000000;
# else
unsigned char *g_FbBuf = NULL;
uint64_t g_FbBuf_size = 0;
# endif
/* for sysdump fastboot command start*/
#ifdef CONFIG_SPRD_SYSDUMP
extern int sysdump_setdump_command(const char *cmd);
extern int sysdump_getdump_command(const char *cmd, int *fulldump_enable_status, int *minidump_enable_status);
#else
#define sysdump_setdump_command(cmd) -1
#define sysdump_getdump_command(cmd, fulldump_enable_status, minidump_enable_status) -1
#endif
/* for sysdump fastboot command end*/

#ifdef CONFIG_DTS_MEM_LAYOUT
#define SET_FASTBOOT_BUFFER_BASE_SIZE(basep, sizep)		get_buffer_base_size_from_dt("heap@4", basep, sizep)

//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
extern int fastboot_mode_flag;
extern int rsa_decrypt_data(unsigned char *data_type, unsigned char *revice_data, unsigned char *sn_data);

struct mode_key_table {
	char *mode;
	int mode_flag;
};
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end

//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
struct mode_cmd_check_table {
	char **cmd_disallow;
	int  cmd_disallows;
};
//20220704,Added by zhu_jun for VSI-679 suport fastboot command:fastboot oem cali_disable begin
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN begin
char *basic_cmd_disallow[] = { "reboot-emergency", "oem repair", "oem enter_calibration", "oem zeroflag","oem powp_enable","oem powp_wt_enable", "oem hef" };
char *flash_cmd_disallow[] = { "reboot-emergency", "oem repair", "oem enter_calibration", "oem zeroflag","oem powp_enable" ,"oem powp_wt_enable" };
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN end
//20220704,Added by zhu_jun for VSI-679 suport fastboot command:fastboot oem cali_disable end
char *repair_cmd_disallow[] = { };
char *simlock_cmd_disallow[] = { "reboot-emergency", "oem repair", };

char *factory_cmd_disallow[] = { "reboot-emergency"};
char *factory_allow_erase_arg[] = { "userdata", "cache", "metadata", "powp_wt"};
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end

char *flash_basic_allow_arg[] = { "unlock", "cali"};
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
char *flash_disallow_arg[] = { "frp" };

struct mode_cmd_check_table check_tbl[MODE_FASTBOOT_NUM] = {
	{ basic_cmd_disallow, sizeof(basic_cmd_disallow) / sizeof(basic_cmd_disallow[0]) },
	{ flash_cmd_disallow, sizeof(flash_cmd_disallow) / sizeof(flash_cmd_disallow[0]) },
	{ repair_cmd_disallow, sizeof(repair_cmd_disallow) / sizeof(repair_cmd_disallow[0]) },
	{ simlock_cmd_disallow, sizeof(simlock_cmd_disallow) / sizeof(simlock_cmd_disallow[0]) },
    //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
	{ factory_cmd_disallow, sizeof(factory_cmd_disallow)/ sizeof(factory_cmd_disallow[0])},
	//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
};

const unsigned char *next_arg(char *next/*out param*/, const unsigned char *buff)
{
	int i, idx_start, idx_end;

	i = 0;
	while (buff[i] == ' ')
		i++;
	idx_start = i;

	while (buff[i] != ' ' && buff[i] != '\0')
		i++;
	idx_end = i;

	for (i = 0; i < idx_end - idx_start; i++)
		next[i] = buff[idx_start + i];
	next[i] = '\0';
        return buff + idx_start + i;
}

static int fastboot_mode_cmd_filter(struct fastboot_cmd *cmd, const unsigned char *buff)
{
	int i, cnt;
	char next[64];
	int is_flash_erase = 0;
	int cmd_disallow = 0;
        /* every mode disallow several cmds; so simply disallow in respective mode */
	if (check_tbl[fastboot_mode_flag].cmd_disallow != NULL) {
		for (i = 0; i < check_tbl[fastboot_mode_flag].cmd_disallows; i++) {
			if (!strcmp(cmd->prefix, check_tbl[fastboot_mode_flag].cmd_disallow[i])) {
				cmd_disallow = 1;
				break;
			}
		}
	}

        /*
	 * if command is flash or erase, get in trouble here. due to HMD's requirements,
	 * in basic mode, we should allow flash/erase userdata and cache parition
	 * and forbid any other paritions.
	 * in flash/simlock mode, we should allow flash/erase all partition except
	 * config parition(FRP flag) and unlock.
	 */
	if (!strcmp(cmd->prefix, "flash:") || !strcmp(cmd->prefix, "erase:"))
		is_flash_erase = 1;

	if(is_flash_erase){
		next_arg(next, buff + cmd->prefix_len);

		cnt = sizeof(flash_basic_allow_arg) / sizeof(flash_basic_allow_arg[0]);
		if (fastboot_mode_flag == MODE_FASTBOOT_BASIC) {
			cmd_disallow = 1;
			for (i = 0; i < cnt; i++) {
				if (!strcmp(next, flash_basic_allow_arg[i])) {
					cmd_disallow = 0;
					break;
				}
			}
		}

		cnt = sizeof(flash_disallow_arg) / sizeof(flash_disallow_arg[0]);
		if ((fastboot_mode_flag == MODE_FASTBOOT_FLASH || fastboot_mode_flag == MODE_FASTBOOT_SIMLOCK)) {
			for (i = 0; i < cnt; i++) {
				if (!strcmp(next, flash_disallow_arg[i])) {
					cmd_disallow = 1;
				break;
				}
			}
		}
       //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
		if(fastboot_mode_flag == MODE_FASTBOOT_FACTORY){
			cmd_disallow = 1;
			cnt = sizeof(factory_allow_erase_arg) / sizeof(factory_allow_erase_arg[0]);

			for (i = 0; i < cnt; i++) {
				if (!strcmp(next, factory_allow_erase_arg[i])) {
					cmd_disallow = 0;
					break;
				}
			}
		}
       //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
       }
	if (cmd_disallow) {
		return -1;
	} else {
		return 0;
	}
}
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

int set_fastboot_buf_base_size()
{
	unsigned long buf_base, buf_size;
	if (SET_FASTBOOT_BUFFER_BASE_SIZE(&buf_base, &buf_size) < 0) {
		errorf("set fastboot buffer error\n");
		return -1;
	}

	g_FbBuf = (unsigned char *)ALIGN(buf_base , 8);
	g_FbBuf_size = buf_size;

	debugf("fastboot buffer base %p, size %llx\n", g_FbBuf, g_FbBuf_size);

	return 0;
}
#endif

void fastboot_register(const char *prefix, void (*handle) (const char *arg, void *data, uint64_t sz))
{
	struct fastboot_cmd *cmd;
	cmd = malloc(sizeof(*cmd));
	if (cmd) {
		cmd->prefix = prefix;
		cmd->prefix_len = strlen(prefix);
		cmd->handle = handle;
		cmd->next = cmdlist;
		cmdlist = cmd;
	}
}

static struct fastboot_var *varlist;

void fastboot_publish(const char *name, const char *value)
{
	struct fastboot_var *var;
	var = malloc(sizeof(*var));
	if (var) {
		var->name = name;
		var->value = value;
		var->next = varlist;
		varlist = var;
	}
}
static char response[64] __attribute__((aligned(64)));
void fastboot_ack(const char *code, const char *reason)
{

	if (fastboot_state != STATE_COMMAND)
		return;
	if (reason == 0)
		reason = "";

	//snprintf(response, 64, "%s%s", code, reason);
	if (strlen(code) + strlen(reason) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "%s%s", code, reason);
	fastboot_state = STATE_COMPLETE;

	fb_usb_write(response, strlen(response));

}

void fastboot_fail(const char *reason)
{
	fastboot_ack("FAIL", reason);
}

void fastboot_okay(const char *info)
{
	fastboot_ack("OKAY", info);
}

//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
void wt_fastboot_info(const char *info)
  {
	if (info == 0)
		info = "";
	if (strlen("INFO") + strlen(info) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "INFO%s", info);
	fb_usb_write(response, strlen(response));
  }
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
void fastboot_info(const char *format, ...)
{
	char tmp[sizeof(response) + 1];
	va_list args;

	strcpy(tmp, "INFO");
	if (format) {
		va_start(args, format);
		vsnprintf(tmp + strlen(tmp), sizeof(tmp) - strlen(tmp) - 1,
			format, args);
		va_end(args);
	}

	strlcpy(response, tmp, sizeof(response));
	fb_usb_write(response, strlen(response));

	strcpy(response, "OKAY");
	fb_usb_write(response, strlen(response));
	fastboot_state = STATE_COMPLETE;
}

static int fb_check_permission(int perm_type)
{
	return get_permission() & (1 << perm_type);
}
#endif

char product_sn_token[PRODUCT_SN_TOKEN_MAX_SIZE] __attribute__ ((aligned(4096)));
char product_sn_signature[PRODUCT_SN_SIGNATURE_SIZE] __attribute__((aligned(4096)));

#ifdef CONFIG_SECBOOT
char product_sn_token[PRODUCT_SN_TOKEN_MAX_SIZE] __attribute__ ((aligned(4096)));
char product_sn_signature[PRODUCT_SN_SIGNATURE_SIZE] __attribute__((aligned(4096)));
#ifdef PRODUCT_USE_DYNAMIC_PARTITIONS
void fastboot_response_socid(const char *info)
{
	if (info == 0)
		info = "";
	if (strlen("INFO") + strlen(info) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "INFO%s", info);
	fb_usb_write(response, strlen(response));
}

void fastboot_response_sn(const char *info)
{
	if (info == 0)
		info = "";
	if (strlen("INFO") + strlen(info) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "INFO%s", info);
	fb_usb_write(response, strlen(response));
}
#else
void fastboot_response_socid(const char *info)
{
	if (info == 0)
		info = "";
	if (strlen("SOCID") + strlen(info) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "%s%s", "SOCID", info);
	fb_usb_write(response, strlen(response));
}

void fastboot_response_sn(const char *info)
{
	if (info == 0)
		info = "";
	if (strlen("SN") + strlen(info) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "%s%s", "SN", info);
	fb_usb_write(response, strlen(response));
}
#endif //PRODUCT_USE_DYNAMIC_PARTITIONS
//#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD  //20220606, Added by zhu_jun for bootloader unlock by devicekit

/*
 * * Function: fb_verify_unlockkey
 * * Description: verify unlock digital signature unlock.key by decode it and compare with serial number
 * * Calls: RSA_Verify
 * * Called By:fb_cmd_flash fb_cmd_oem
 * * Return: 1- signature is valid
 * *   0- signature is invalid
 *              */
int fb_verify_unlockkey(unsigned char *encrypt_data, unsigned char *serialno)
{
    int ret = -1;
    int32_t length = -1;
            unsigned char revice_raw_data[32] = {0};

            unsigned char pub_E[4] = {0x00, 0x01, 0x00, 0x01};
//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
            unsigned char mod_N[256] =
                    { 0x81, 0x7f, 0x24, 0xe4, 0xa9, 0x98, 0xbb, 0xbc, 0x74, 0xbc, 0xaf, 0x21, 0xb0, 0xf3,
                      0xfc, 0x57, 0x49, 0x2d, 0xa2, 0x9d, 0xf2, 0x9f, 0x38, 0x5a, 0x56, 0xfc, 0x71, 0x7a, 0xb5,
                      0xff, 0xfc, 0xad, 0x35, 0x04, 0x92, 0x93, 0x35, 0x64, 0xa6, 0x1d, 0x1d, 0x95, 0x07, 0xe2,
                      0x24, 0x3d, 0xa0, 0xe1, 0xe4, 0x4c, 0x90, 0x21, 0xc1, 0xf9, 0x62, 0x0e, 0x7a, 0xad, 0x90,
                      0x4a, 0xfe, 0xe9, 0xdf, 0x59, 0xa9, 0x99, 0x3a, 0x8d, 0x70, 0xe6, 0x6d, 0xce, 0x4e, 0x0a,
                      0x7a, 0xb9, 0xe8, 0xdc, 0x86, 0x5b, 0x24, 0xe1, 0xb0, 0x16, 0xed, 0xef, 0x16, 0xe6, 0xf5,
                      0x65, 0x03, 0x65, 0xba, 0xb5, 0x9b, 0x49, 0x4a, 0xb8, 0xa7, 0x69, 0x2a, 0xf7, 0x18, 0xb7,
                      0x57, 0xce, 0x04, 0x7d, 0x33, 0xc9, 0x21, 0x1e, 0x02, 0x75, 0x2a, 0x88, 0x3d, 0x24, 0x36,
                      0x3b, 0xc1, 0x18, 0x10, 0x3b, 0x5b, 0x62, 0x7a, 0x4d, 0x03, 0xcb, 0xfe, 0xc7, 0x00, 0x09,
                      0x89, 0x1e, 0x06, 0x4b, 0x11, 0xb4, 0x0f, 0x7f, 0x04, 0x80, 0x39, 0x5b, 0x21, 0xc4, 0x43,
                      0x8a, 0xcb, 0x47, 0x9d, 0x72, 0x53, 0x2c, 0x66, 0x03, 0x0b, 0x21, 0xea, 0x88, 0xc5, 0xe0,
                      0x55, 0x99, 0xde, 0xef, 0x21, 0xec, 0x16, 0x28, 0x98, 0xe1, 0x8d, 0xe1, 0x38, 0x07, 0x69,
                      0x83, 0x23, 0x21, 0x4b, 0xb0, 0xaf, 0x34, 0xc7, 0x7e, 0x88, 0xc5, 0xc1, 0xa8, 0xe7, 0xbd,
                      0x72, 0xe4, 0xdd, 0xa7, 0x20, 0x15, 0xad, 0x98, 0x25, 0x2e, 0x2e, 0x76, 0x82, 0x5a, 0x4c,
                      0x29, 0x07, 0x43, 0x3f, 0xc8, 0xf0, 0x95, 0x8b, 0x14, 0x50, 0x78, 0xa6, 0x83, 0x8d, 0x18,
                      0x34, 0x1c, 0x44, 0x61, 0x6f, 0x6d, 0xc3, 0x36, 0x8c, 0xe5, 0x15, 0x08, 0x55, 0x90, 0x64,
                      0x00, 0x24, 0x48, 0x71, 0x6b, 0xeb, 0x42, 0x25, 0x8f, 0xa9, 0x28, 0x07, 0x4e, 0x61, 0x94,
                      0x2f, 0x2f };

//20220606, Added by zhu_jun for bootloader unlock by devicekit end

            length = RSA_Verify(pub_E, mod_N, 2048, encrypt_data, revice_raw_data);

            if (0 > length)
            {
                printf("rsa verify dec failed err:%d\n", length);
                ret = -1;
                return ret;
            }

            dumpHex("revice_raw_data", revice_raw_data, 32);
            dumpHex("plaintext", serialno, 32);

            if(!strncmp(revice_raw_data, serialno, length))
            {
                printf("veriy serial number data sucess\n");
                ret = 1;
            } else {
                printf("veriy serial number data failed\n");
                ret = 0;
            }

            return ret;
}
//#endif  //20220606, Added by zhu_jun for bootloader unlock by devicekit
#endif

static void fb_cmd_getvar(const char *arg, void *data, uint64_t sz)
{
	struct fastboot_var *var;

	for (var = varlist; var; var = var->next) {
		if (!strcmp(var->name, arg)) {
			fastboot_okay(var->value);
			return;
		}
	}

#ifdef CONFIG_SECBOOT
        if(!strcmp("serialno", arg)) {
            strcpy(product_sn_token, get_product_sn());
            fastboot_okay(product_sn_token);
            return;
        }
#endif

#ifdef CONFIG_SECBOOT
#ifdef PRODUCT_USE_DYNAMIC_PARTITIONS

	if (!strcmp("socid", arg)) {
		fb_cmd_getsocid(arg, data, sz);
		return;
	}else if (!strcmp("lcs", arg)) {
		fb_cmd_getlcs(arg, data, sz);
		return;
        }

#endif //PRODUCT_USE_DYNAMIC_PARTITIONS
#endif

	if (!strcmp("product", arg)) {
/*	
		char product_name[65];

		memset(product_name, 0, sizeof(product_name));

		if (0 != common_raw_read("miscdata", (uint64_t)(sizeof(product_name) - 1),
				(uint64_t)PRODUCT_NAME_OFFSET, product_name)) {
			errorf("<miscdata> read error\n");
			fastboot_fail("read miscdata fail!");
			return;
		}

		debugf("product_name: %s\n", product_name);
*/
		fastboot_okay("AGT");

		return;
	}

	if (!strncmp("partition-size:", arg, strlen("partition-size:"))) {
		disk_partition_t part_info = {0};
		char response[64];
		uint64_t size;
		int ret;

		ret = get_img_partition_info(arg + strlen("partition-size:"), &part_info);
		if (ret) {
			errorf("get partition info fail, %d\n", ret);
			fastboot_fail("get partition info fail");
			return;
		}
		size = part_info.size * part_info.blksz;
		debugf("partition-size:0x%llx \n", size);
		sprintf(response, "0x%llx", size);
		fastboot_okay(response);
		return;
	}

	if (!strncmp("partition-type:", arg, strlen("partition-type:"))) {
		disk_partition_t part_info = {0};
		char response[64];
		int ret;

		ret = get_img_partition_info(arg + strlen("partition-type:"), &part_info);
		if (ret) {
			errorf("get partition info fail, %d\n", ret);
			fastboot_fail("get partition info fail");
			return;
		}
		debugf("partition-type:%s \n", part_info.type);
		sprintf(response, "%s", part_info.type);
		fastboot_okay(response);
		return;
	}

	if (!strcmp("slot-count", arg)) {
		struct bootloader_control abc = {0};
		ulong abc_offset, abc_size;
		int ret;
		char response[64];

		abc_offset = offsetof(struct bootloader_message_ab, slot_suffix);
		abc_size = sizeof(struct bootloader_control);

		ret = common_raw_read("misc", (u64)abc_size, (u64)abc_offset, (char *)&abc);
		if (ret < 0) {
			errorf("ANDROID: Could not read from boot ctrl partition\n");
			fastboot_fail("Could not read from boot ctrl partition");
			return;
		}

		debugf("nb_slot:%d \n", abc.nb_slot);

		sprintf(response, "%d", abc.nb_slot);

		fastboot_okay(response);
		return;
	}

	if (!strcmp("current-slot", arg)) {
		struct bootloader_control abc = {0};
		ulong abc_offset, abc_size;
		int ret;
		char response[64];

		abc_offset = offsetof(struct bootloader_message_ab, slot_suffix);
		abc_size = sizeof(struct bootloader_control);

		ret = common_raw_read("misc", (u64)abc_size, (u64)abc_offset, (char *)&abc);
		if (ret < 0) {
			errorf("ANDROID: Could not read from boot ctrl partition\n");
			fastboot_fail("Could not read from boot ctrl partition");
			return;
		}
		debugf("current-slot:%c \n", abc.slot_suffix[1]);

		sprintf(response, "%c", abc.slot_suffix[1]);

		fastboot_okay(response);
		return;
	}
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
	if (!strcmp("off-mode-charge", arg)) {
		unsigned short flag;
		char flag2[1] = {0};
		char response[64];

		if (common_raw_read("miscdata",OFF_MODE_CHARGE_FLAG_LEN, OFF_MODE_CHARGE_FLAG_OFFSET, &flag)) {
			errorf("read off-mode-charge flag error!\n");
		}
		if (common_raw_read("miscdata",HMD_OFF_MODE_CHARGE_FLAG_LEN, HMD_OFF_MODE_CHARGE_FLAG_OFFSET, flag2)) {
			errorf("read hmd_off_mode_charge flag2 error!\n");
		}
		debugf("off-mode-charge flag is:%d  hmd_off_mode_charge :%s\n", flag, flag2);
		sprintf(response, "fastboot:%d app:%s", flag, flag2);
		fastboot_okay(response);
	}
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 end
	fastboot_okay("");
}

static void fb_cmd_download(const char *arg, void *data, uint64_t sz)
{
	char response[64];
	uint64_t len = simple_strtoul(arg, NULL, 16);
	int total_rcv;
#ifdef CONFIG_WR_SPARSE
	char *pname = ImageInfo.part_name;
	sparse_header_t sparse_hdr;
	const uint64_t frag_len = SZ_2M;
	uint64_t i, j, k, t;
	int sparse_start = 0;
	uint64_t last_pos, unsave_sz;
	int retval;
	uint32_t ticks_usb_one_frag = 0, ticks_flash_wr = 0, ticks_total = 0;
	uint32_t ticks_cur1, ticks_cur2;
	uint64_t last_unsave_len;
	uint64_t total_size = 0;
#endif

	debugf("Start fastboot download, image len=0x%llx \n", len);
	debugf("buffer base %p, buffer size 0x%llx \n", ImageInfo.base_address, ImageInfo.max_size);
	if (len > ImageInfo.max_size) {
		debugf("Image size over the max buffer size,can not accept \n");
		fastboot_fail("data too large");
		return;
	}

	sprintf(response, "DATA%16llx", len);
	if (fb_usb_write(response, strlen(response)) < 0) {
		fastboot_state = STATE_ERROR;
		return;
	}

#ifdef CONFIG_WR_SPARSE
	if (!strlen(ImageInfo.part_name)) {
		total_rcv = fb_usb_read(ImageInfo.base_address, len);
		if (total_rcv != len) {
			fastboot_state = STATE_ERROR;
			return;
		}

		ImageInfo.data_size = len;
		fastboot_image_size = ImageInfo.data_size;
		fastboot_okay("");
		return;
	}

	if (!strcmp(ImageInfo.part_name, "userdata") && g_download_part_count == 0) {
		debugf("userdata, erase...\n");
		get_img_partition_size(ImageInfo.part_name, &total_size);
		common_raw_erase(ImageInfo.part_name, total_size / 100, (uint64_t)0LL);
		g_download_part_count += 1;
	}

	wr_dbg("Wr rest ImageInfo.part_name:%s\n", ImageInfo.part_name);
	wr_sparse_rest(ImageInfo.part_name);

	ImageInfo.first_pkt = 1;
	last_unsave_len = 0;

	i = len;
	last_pos = total_rcv = 0;
	unsave_sz = 0;
	t = 0;
	while (i) {
		ticks_cur1 = SCI_GetTickCount();

		j = i > frag_len ? frag_len : i;

		if (fb_usb_read_triger(ImageInfo.base_address + total_rcv, j)) {
			fastboot_state = STATE_ERROR;
			goto out;
		}

		if (ImageInfo.first_pkt) {
			k = fb_read_usb_query_finish();
			if (k != j) {
				fastboot_state = STATE_ERROR;
				goto out;
			}

			if (!ticks_usb_one_frag)
				ticks_usb_one_frag = SCI_GetTickCount() - ticks_cur1;

			if (ImageInfo.first_pkt) {
				ImageInfo.first_pkt = 0;
				memcpy(&sparse_hdr, ImageInfo.base_address, sizeof(sparse_hdr));

				if ((sparse_hdr.magic == SPARSE_HEADER_MAGIC)
					&& (sparse_hdr.major_version == SPARSE_HEADER_MAJOR_VER)
					&& strlen(ImageInfo.part_name)) {
					wr_dbg("First packet is sparse\n");
					sparse_start = 1;
				}
			}

			total_rcv += j;
			i -= j;
			unsave_sz += j;
			t++;

			ticks_total += SCI_GetTickCount() - ticks_cur1;
			continue;
		}

		t = 0;
		if (sparse_start) {
			ticks_cur2 = SCI_GetTickCount();

#define DCACHE_BYTE_ALIGN 0x3F
			invalidate_dcache_range(((unsigned int)ImageInfo.base_address + last_pos) & (~DCACHE_BYTE_ALIGN),
				(((unsigned int)ImageInfo.base_address + last_pos) + unsave_sz + DCACHE_BYTE_ALIGN) & (~DCACHE_BYTE_ALIGN));

			//debugf("%s fb download saving image buf %p, size %llx\n",
			//	pname, ImageInfo.base_address + last_pos - last_unsave_len, unsave_sz + last_unsave_len);
			retval = write_sparse_img(pname, ImageInfo.base_address + last_pos - last_unsave_len, unsave_sz + last_unsave_len);
			if (-1 == retval) {
				errorf("%s write packet fail, buf %p, size %lx\n", pname,
					ImageInfo.base_address + last_pos, unsave_sz);
				fastboot_state = STATE_ERROR;
				goto out;
			} else if ((retval > 0) && (retval < unsave_sz + last_unsave_len)) {
				last_unsave_len = unsave_sz + last_unsave_len - retval;
				wr_dbg("unsave_sz %llx retval %x (%llx)\n",
					unsave_sz + last_unsave_len, retval, last_unsave_len);
			} else
				last_unsave_len = 0;
			//debugf("return value=%d\n", retval);
			last_pos = total_rcv;
			unsave_sz = 0;

			ticks_flash_wr += SCI_GetTickCount() - ticks_cur2;
		}

		if (!ImageInfo.first_pkt) {
			k = fb_read_usb_query_finish();
			if (k != j) {
				fastboot_state = STATE_ERROR;
				goto out;
			}
		}

		total_rcv += j;
		i -= j;
		unsave_sz = j;

		ticks_total += SCI_GetTickCount() - ticks_cur1;
	}

	if (sparse_start && (unsave_sz + last_unsave_len)) {
		wr_dbg("%s saving last packet, buf %p, size %llx\n",
			pname, ImageInfo.base_address + last_pos - last_unsave_len, unsave_sz + last_unsave_len);

		ticks_cur2 = SCI_GetTickCount();
		invalidate_dcache_range(((unsigned int)ImageInfo.base_address + last_pos) & (~DCACHE_BYTE_ALIGN),
			(((unsigned int)ImageInfo.base_address + last_pos) + unsave_sz + DCACHE_BYTE_ALIGN) & (~DCACHE_BYTE_ALIGN));

		retval = write_sparse_img(pname, ImageInfo.base_address + last_pos - last_unsave_len, unsave_sz + last_unsave_len);
		if (-1 == retval) {
			errorf("%s write last packet fail, buf %p, size %lx\n", pname,
				ImageInfo.base_address + last_pos, unsave_sz);
			fastboot_state = STATE_ERROR;
			goto out;
		} else if ((retval > 0) && (retval < unsave_sz + last_unsave_len)) {
			last_unsave_len = unsave_sz + last_unsave_len - retval;
			errorf("unsave_sz %llx retval %x (%d)\n",
				unsave_sz + last_unsave_len, retval, last_unsave_len);
			fastboot_state = STATE_ERROR;
			goto out;
		} else
			last_unsave_len = 0;
		//debugf("return value=%d\n", retval);

		ticks_flash_wr += SCI_GetTickCount() - ticks_cur2;
		ticks_total += SCI_GetTickCount() - ticks_cur2;

#ifdef CONFIG_WRBG_SPARSE
		(void)wrbg_sparse_flush(pname); /* !!!flush backstage write */
#endif
	}

out:
	if (fastboot_state == STATE_ERROR) {
#ifdef CONFIG_WRBG_SPARSE
		(void)wrbg_sparse_flush(pname); /* !!!flush backstage write */
#endif
		errorf("%s err out\n", pname);
		return;
	}

	//report
	printf("got %lld bytes\n", len);
	printf("elapsed time total: %d ms\n", ticks_total);
	printf("%d ms per receive\n", ticks_usb_one_frag);
	printf("%d ms flash\n", ticks_flash_wr);
	printf("%d ms usb\n", ticks_total - ticks_flash_wr);

	ImageInfo.data_size = len;
	fastboot_image_size = ImageInfo.data_size;
	fastboot_okay("");
	return;
#else
	total_rcv = fb_usb_read(ImageInfo.base_address, len);
	if (total_rcv != len) {
		fastboot_state = STATE_ERROR;
		return;
	}

	ImageInfo.data_size = len;
	fastboot_image_size = ImageInfo.data_size;
	fastboot_okay("");
#endif
}

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
static int fb_check_permission_part_flash(char *part_name)
{
	/*
	 * userdata could be flash on base permission,
	 *   and persist was not allow alway
	 */
	if (!strcmp(part_name, "persist"))
		return 0;

	if (!strcmp(part_name, "userdata"))
		return 1;
	if (!strcmp(part_name, "elabel"))
		return 1;

	return fb_check_permission(TYPE_PERMISSION_FLASH);
}

static int fb_check_permission_part_erase(char *part_name)
{
	/* userdata could be flash on base permission */
	if (!strcmp(part_name, "userdata"))
		return 1;

	if (!strcmp(part_name, "cache"))
		return 1;
	return fb_check_permission(TYPE_PERMISSION_REPAIR);
}
#endif
//20220614, Added by zhu_jun for Enable backup nv machanism by default begin
static volatile unsigned int s_backupnv_flag = 1;
//20220614, Added by zhu_jun for Enable backup nv machanism by default end
int fb_nvmerge(char *partition_name, unsigned char *buf, uint32_t size) {
	uint8_t header_buf[NV_HEAD_LEN], old_header_buf[NV_HEAD_LEN];
	nv_header_t	*old_nv_header_p = NULL;
	uint32_t old_nv_size = 0;
	char *old_nv_buf = NULL;
	char *temp_nv_buf = NULL;
	char *backup_partition_name = _get_backup_partition_name(partition_name);

	memset(old_header_buf, 0x00, NV_HEAD_LEN);
	if (common_raw_read(partition_name, NV_HEAD_LEN, (uint64_t)0, old_header_buf)) {
		errorf("fail to read nv header!\n");
		return -1;
	}
	old_nv_header_p = old_header_buf;
	if( old_nv_header_p->magic == NV_HEAD_MAGIC && old_nv_header_p->version == NV_VERSION) {
		old_nv_size = old_nv_header_p->len;
		old_nv_buf = malloc(old_nv_size);
		if (NULL == old_nv_buf) {
			errorf("no enough space for old nv buffer\n");
			return -2;
		}
		memset(old_nv_buf, 0x0, old_nv_size);
		debugf("old_nv_size 0x%x\n", old_nv_size);
		common_raw_read(partition_name, (uint64_t)(old_nv_size), NV_HEAD_LEN, old_nv_buf);
		if(TRUE != fdl_check_crc(old_nv_buf, old_nv_size, old_nv_header_p->checksum)) {
			debugf("main nv partition %s is damaged!\n", partition_name);
			memset(old_header_buf, 0x00, NV_HEAD_LEN);
			if (common_raw_read(backup_partition_name, NV_HEAD_LEN, (uint64_t)0, old_header_buf)) {
				errorf("fail to write nv header!\n");
				free(old_nv_buf);
				return -3;
			}
			old_nv_header_p = old_header_buf;
			if( old_nv_header_p->magic == NV_HEAD_MAGIC && old_nv_header_p->version == NV_VERSION) {
				free(old_nv_buf);
				old_nv_size = old_nv_header_p->len;
				old_nv_buf = malloc(old_nv_size);
				if (NULL == old_nv_buf) {
					errorf("no enough space for old nv buffer\n");
					return -4;
				}
				if (common_raw_read(backup_partition_name, (uint64_t)(old_nv_size), NV_HEAD_LEN, old_nv_buf)) {
					errorf("fail to write nv header!\n");
					free(old_nv_buf);
					return -5;
				}
				if(TRUE != fdl_check_crc(old_nv_buf, old_nv_size, old_nv_header_p->checksum)) {
					free(old_nv_buf);
					errorf("main nv partition and bakup nv partition is damaged!\n");
					return -6;
				}
			} else {
				free(old_nv_buf);
				errorf("back up nv partition header error!magic = %#x,version = %d\n",
					old_nv_header_p->magic, old_nv_header_p->version);
				return -7;
			}
		}
		temp_nv_buf = malloc(size);
		if (NULL == temp_nv_buf) {
			free(old_nv_buf);
			errorf("no enough space for temp nv buffer\n");
			return -8;
		}
		memcpy(temp_nv_buf, buf, size);
		debugf("start to mergeitem, old_nv_size 0x%x, new_nv_size 0x%x\n", old_nv_size, size);
		if( mergeItem(old_nv_buf, old_nv_size, temp_nv_buf, size) == TRUE) {
			memcpy(buf, temp_nv_buf, size);
		} else {
			free(temp_nv_buf);
			free(old_nv_buf);
			errorf("nv merge fail!\n");
			return -9;
		}
		free(old_nv_buf);
		free(temp_nv_buf);
	} else {
		debugf("The current nv partition is empty, Nv cannot be backed up!\n");
	}
	return 0;

}
#ifndef CONFIG_NAND_BOOT
static PARTITION_IMG_TYPE fb_get_partition_image_type(char *part_name,
	unsigned char *buf, ulong sechdr_offset)
{
	PARTITION_IMG_TYPE img_format = IMG_RAW;
	sparse_header_t *sparse_header;

	sparse_header = (sparse_header_t *)(buf + sechdr_offset);
	if ((sparse_header->magic == SPARSE_HEADER_MAGIC)
			&& (sparse_header->major_version == SPARSE_HEADER_MAJOR_VER)) {
		img_format = IMG_WITH_SPARSE;
		debugf("img_format = IMG_WITH_SPARSE\n");
	}

	return img_format;
}

static int _fb_repartition(uint8_t *pgpt, uint64_t size)
{
	block_dev_desc_t *dev_desc;
	int dev_id = 0;
	char *ifname;

	ifname = block_dev_get_name();
	dev_id = get_devnum_hwpart(ifname, 0);
	if (dev_id < 0) {
		errorf("%s: get dev_id %d fail\n", __func__, dev_id);
		return -1;
	}

	dev_desc = get_dev_hwpart(ifname, dev_id, 0);
	if (!dev_desc) {
		errorf("%s: get dev_desc fail\n", __func__);
		return -2;
	}

	debugf("%s: updating MBR, Primary and Backup GPT(s)\n",__func__);
	if (write_mbr_and_gpt_partitions(dev_desc, pgpt)) {
		errorf("Write pgpt fail(0)\n");
		return -3;
	}
	debugf("Write pgpt successfully\n");
	return 0;
}

/* clear g_status.unsave_recv_size before return if necessary */
int fb_write_nv_img(char *part_name, unsigned char *buf, uint32_t size, unsigned int backup_flag)
{
	unsigned char *part_name_bak = NULL;
	uint8_t header_buf[NV_HEADER_SIZE];
	nv_header_t *nv_header_p = NULL;
	int retval = 0;

	debugf("fb_write_nv_img enter, size 0x%x\n", size);
#ifdef NV_ENCRYPTION
	encryptFixnvPartition(buf);
#endif

	debugf("fb_write_nv_img backup_flag %d\n", backup_flag);
	if (backup_flag) {
		retval = fb_nvmerge(part_name, buf, size);
		debugf("fb_nvmerge return %d\n", retval);
	}

	memset(header_buf, 0x00, NV_HEADER_SIZE);
	nv_header_p = header_buf;
	nv_header_p->magic = NV_HEAD_MAGIC;
	nv_header_p->len = size;
	nv_header_p->checksum = (uint32_t)fdl_calc_checksum(buf, size);
	nv_header_p->version = NV_VERSION;

	debugf("Start to write first block of NV partition(%s)\n", part_name);
	if (0 != common_raw_write(part_name, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf))
		return -1;

	debugf("Start to write remain blocks of NV partition\n");
	if (0 != common_raw_write(part_name, (uint64_t)size, (uint64_t)0, NV_HEADER_SIZE, buf))
		return -1;

	/*write the backup partition */
	part_name_bak = _get_backup_partition_name((unsigned char*)part_name);
	if (NULL == part_name_bak) {
		errorf(" get backup partition name fail\n");
		return -1;
	}
	if (0 != common_raw_write(part_name_bak, NV_HEADER_SIZE, (uint64_t)0, (uint64_t)0, header_buf))
		return -1;

	if (0 != common_raw_write(part_name_bak, (uint64_t)size, (uint64_t)0, NV_HEADER_SIZE, buf))
		return -1;

	return 0;
}

//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked begin
static int check_miscdata_blocked_flag()
{
	debugf("check miscdata is blocked or unblocked.\n");
	char tmp[] = MAGIC_BLOCK_FLAG, buf[1] = {0};
	uint64_t offset = MISCDATA_BLOCK_OFFSET;
	int length = 1;
	if (common_raw_read("miscdata", (uint64_t)length, offset, buf)) {
		errorf("read miscdata %d fail on offset %lld.\n", length, offset);
		return;
	}
	debugf("msicdata offset:%lld blocked flag:%x.\n", offset, *(int *)buf);
	if (!memcmp(tmp, buf, sizeof(buf))) {
		return FLAG_BLOCKED;
	}
	return FLAG_UNBLOCKED;
}
//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked end

void fb_cmd_flash(const char *arg, void *data, uint64_t sz)
{
	PARTITION_IMG_TYPE img_format = IMG_RAW;
	OPERATE_STATUS status = OPERATE_SUCCESS;
	char part_name[PARTNAME_SZ];
	PARTITION_PURPOSE part_purpose;
	ulong strip_header = 0;
	ulong sec_offset = 0x200;
	static sys_img_header *bakup_header;
	uint32_t write_size = 0;
	uchar * write_start = NULL;
	int32_t retval = 0, i;
	uint64_t total_size = 0;
//#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD  //20220606, Added by zhu_jun for bootloader unlock by devicekit
        char subcmd[64];
        const char *delim = " ";
        int ret = -1;
//#endif  //20220606, Added by zhu_jun for bootloader unlock by devicekit begin

	debugf("data = %p,ImageInfo[0].base_address = %p\n", data, ImageInfo.base_address);

//#if defined(CONFIG_FASTBOOT_SECURITY_DOWNLOAD) && defined(CONFIG_SECBOOT) //20220606, Added by zhu_jun for bootloader unlock by devicekit
    memset(subcmd, 0, sizeof(subcmd));
    strcpy(subcmd, strtok(arg, delim));

//20220601,Added by zhu_jun for Devicekit write configuration to protect partitions begin
    if (!strcmp(subcmd, "powp_wt")){
		if(WT_POWP_LEN < ImageInfo.data_size){
			fastboot_fail("flash powp.bin  failed\n");
			return ;
		}
		powp_size = ImageInfo.data_size;
		memcpy(powp_buf,ImageInfo.base_address,powp_size);
		ret = oem_repair_write_mmc_ex("powp",powp_buf);
		if(!ret) {
		    fastboot_okay("flash powp.bin success\n");
		} else {
		    fastboot_fail("flash powp.bin  failed\n");
		}

		return;
	}else if (!strcmp(subcmd, "powp")){
		if(WT_POWP_LEN < ImageInfo.data_size){
			fastboot_fail("flash powp.bin  failed\n");
			return ;
		}
		powp_size = ImageInfo.data_size;
		memcpy(powp_buf,ImageInfo.base_address,powp_size);
		ret = oem_repair_write_mmc_ex("powp",powp_buf);
		if(!ret) {
		    fastboot_okay("");
		    usb_driver_exit();
		    reboot_devices(CMD_FASTBOOT_MODE);
		} else {
		    fastboot_fail("flash powp.bin  failed\n");
		}

		return;
	} else if (!strcmp(subcmd, "unlock")){
	//20220601,Added by zhu_jun for Devicekit write configuration to protect partitions end
        strcpy(product_sn_token, get_product_sn());
        debugf("Product SerialNo: %s\n", product_sn_token);
        memset(product_sn_signature, 0, sizeof(product_sn_signature));
        memcpy(product_sn_signature, data, PRODUCT_SN_SIGNATURE_SIZE);

        ret = fb_verify_unlockkey(product_sn_signature, product_sn_token);
        if(ret == 1) {
            fastboot_okay("flash unlock success\n");
        } else {
            fastboot_fail("flash unlock failed\n");
        }

        return;
    }
//#endif  //20220606, Added by zhu_jun for bootloader unlock by devicekit

//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
#ifdef CONFIG_PCTOOL_AUTHORIZE_HMD
    if (!strcmp(subcmd, "cali")){
        debugf("hmd cali start");
        memset(product_sn_signature, 0, sizeof(product_sn_signature));
        memcpy(product_sn_signature, data, PRODUCT_SN_SIGNATURE_SIZE);
        char sn_cali[64] = {0};
        int cali_ret = -1;
        const char *salt="DIAG_ENABLE";
        sprintf(sn_cali,"%s%s",get_product_sn(),salt);
        cali_ret = hmd_cali_authentication(product_sn_signature,sn_cali,strlen(sn_cali));
        if(AUTH_SUCCESS == cali_ret) {
            fastboot_okay("cali auth sucessfully, start flash cali.bin");
            if(HMD_CALI_MODE_SIGNATURE_LEN < ImageInfo.data_size){
                fastboot_fail("flash cali.bin  failed\n");
                return ;
            }
        hmd_cali_size = ImageInfo.data_size;
        memcpy(hmd_cali_buf,ImageInfo.base_address,hmd_cali_size);
        ret = oem_repair_write_mmc_ex("cali",hmd_cali_buf);
        if(!ret) {
            fastboot_okay("flash cali.bin sucessfully\n");
        } else {
            fastboot_fail("flash cali.bin failed\n");
	    }
    } else {
        fastboot_fail("cali auth failed");
    }
        return;
    }
#endif
//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end

//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
#if 0
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#if defined (CONFIG_SECBOOT)
	if (!fb_check_permission_part_flash(arg)
			&& (get_lock_status() == VBOOT_STATUS_LOCK)) {
		fastboot_fail("flash Not allow! Please unlock or get permission first!");
		return;
	}
#else
	if (!fb_check_permission_part_flash(arg)) {
		fastboot_fail("Not allow!");
		return;
	}
#endif
//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
/*#else
#if defined (CONFIG_SECBOOT) && !defined (DEBUG)
	if(get_lock_status() == VBOOT_STATUS_LOCK) {
		fastboot_fail("Flashing Lock Flag is locked. Please unlock it first!");
		return;
	}
#endif
*/
//20220606, Added by zhu_jun for bootloader unlock by devicekit end
#endif
#endif
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end

	for (i = 0; i < PARTNAME_SZ; i++) {
		part_name[i] = arg[i];
		if (0 == arg[i])
			break;
	}

#if defined (CONFIG_SECURE_BOOT) ||defined (CONFIG_SECBOOT)
	/* secboot verify */
	status = dl_secboot_verify(&strip_header,
				part_name,
				0, 0, data);
	if (OPERATE_SUCCESS != status) {
		fastboot_fail("Secboot verify fail!");
		return;
	}
#endif

	bakup_header = (sys_img_header *)(ImageInfo.base_address);
	debugf("bakup_header->mMagicNum=0x%x\n", bakup_header->mMagicNum);
	if (bakup_header->mMagicNum != IMG_BAK_HEADER) {
		sec_offset = 0;
	}

	/* Write partition table */
	if (!strcmp(part_name, "partition") || !strcmp(part_name, "gpt")) {
		retval = _fb_repartition(ImageInfo.base_address, ImageInfo.data_size);
		if (retval) {
			errorf("Write pgpt fail(%d)\n", retval);
			fastboot_fail("Write gpt image fail!");
			return;
		} else {
			fastboot_okay("");
			return;
		}
	}

	img_format = fb_get_partition_image_type(part_name, ImageInfo.base_address,
					sec_offset);

	write_size = ImageInfo.data_size;
	write_start = ImageInfo.base_address;
	//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked begin
	if (!strcmp(part_name, "userdata") || !strcmp(part_name, "metadata")) {
		if (FLAG_BLOCKED == check_miscdata_blocked_flag()) {
			fastboot_fail("operate fail, miscdata_blocked_flag set true");
			return;
		}
	}
	//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked end

	if (!strcmp(part_name, "userdata") && g_download_part_count == 0) {
		debugf("userdata image format is %d\n", img_format);
		get_img_partition_size(part_name, &total_size);
		if (0 != common_raw_erase(part_name, total_size/100, (uint64_t)0LL)) {
			errorf("erase partition %s fail!\n", part_name);
			return -1;
		}
		f2fs_init_resize_configuration();
		g_resize_config.resize_flag = RESIZE_FROM_EMMC;
		g_download_part_count += 1;
	}

	/* image write */
	part_purpose = dl_get_partition_purpose(part_name);

	debugf("fb_cmd_flash notnandboot: part_purpose %d\n", part_purpose);
	if (PARTITION_PURPOSE_NV == part_purpose) {
		debugf("fb_cmd_flash notnandboot: part_purpose PARTITION_PURPOSE_NV, s_backupnv_flag %d\n", s_backupnv_flag);
		if (0 != fb_write_nv_img(part_name, write_start, FIXNV_SIZE, s_backupnv_flag)) {
			errorf("Write nv img fail\n");
			retval = -1;
		}
	} else {
		retval = dl_image_write(part_name, write_size, 0, ImageInfo.max_size,
				write_start, img_format, part_purpose);
	}

	if (retval < 0) {
		errorf("Write img fail, code(%d)\n", retval);
		fastboot_fail("Write img fail!");
		return;
	} else if (retval > 0) {
		errorf("Error: after simg , unsave_recv_size=%d, saved value=%d\n",
			write_size - retval, retval);
		fastboot_fail("Write simg fail!");
		return;
	} else { /* write success */
	/* backup */
		status = dl_backup(part_name, ImageInfo.data_size, ImageInfo.base_address);
		if (OPERATE_WRITE_ERROR == status) {
			fastboot_fail("Backup fail!");
			return;
		}
	}
	if (is_f2fs_filesystem(part_name)) {
		total_size = 0;
		debugf("write %s size 0x%x ok\n", part_name, write_size);
		get_img_partition_size(part_name, &total_size);
#ifdef CONFIG_WR_SPARSE
		if (ImageInfo.max_size_raw < (total_size / 128)) {
#else
		if (ImageInfo.max_size < (total_size / 128)) {
#endif
			errorf("resize skip! small buffer, config dts!\n");
		} else {
			retval = f2fs_resize_main(total_size,
					512,
					f2fs_write_callback,
					f2fs_read_callback,
					(void*)part_name,
					ImageInfo.base_address,
#ifdef CONFIG_WR_SPARSE
					ImageInfo.max_size_raw,
#else
					ImageInfo.max_size,
#endif
					write_size);
			if (retval==0) {
				debugf("resize userdata ok\n");
			} else {
				debugf("resize usedata error\n");
			}
		}
	}

	fastboot_okay("");
}

void fb_cmd_erase(const char *arg, void *data, uint64_t size)
{
	char partition_name[PARTNAME_SZ];
	int i;
	size = 0;
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
#if 0
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#if defined (CONFIG_SECBOOT)
	if (!fb_check_permission_part_erase(arg)
			&& (get_lock_status() == VBOOT_STATUS_LOCK)) {
		fastboot_fail("flash Not allow! Please unlock or get permission first!");
		return;
	}
#else
	if (!fb_check_permission_part_erase(arg)) {
		fastboot_fail("Not allow!");
		return;
	}
#endif
//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
/*#else
#if defined (CONFIG_SECBOOT) && !defined (DEBUG)
	if(get_lock_status() == VBOOT_STATUS_LOCK) {
		fastboot_fail("Flashing Lock Flag is locked. Please unlock it first!");
		return;
	}
#endif
*/
//20220606, Added by zhu_jun for bootloader unlock by devicekit end
#endif
#endif
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end

	for (i = 0; i < PARTNAME_SZ; i++) {
		partition_name[i] = arg[i];
		if (0 == arg[i])
			break;
	}

	if (!strcmp(partition_name, "persist")) {
		fastboot_fail("not support");
		return;
	} else if (!strcmp(partition_name, "config")) {
		strcpy(partition_name, "persist");
	}
	//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked begin
	if (!strcmp(partition_name, "userdata") || !strcmp(partition_name, "metadata")) {
		if (FLAG_BLOCKED == check_miscdata_blocked_flag()) {
			fastboot_fail("operate fail, miscdata_blocked_flag set true");
			return;
		}
	}
	//20220608, Added by zhu_jun for [HMDEnterpriseAPI] forbit erase userdata and metadate when miscdata set blocked begin end
	if (OPERATE_SUCCESS != dl_erase(partition_name, size)) {
		fastboot_fail("operate fail");
		return;
	}

	debugf("Cmd Erase OK\n");
	fastboot_okay("");
	return;
}
#endif
/*for nand this can not work,TODO*/
#ifdef CONFIG_NAND_BOOT
void fb_cmd_flash(const char *arg, void *data, u32 sz)
{

	int ret = -1;
	int i;
	uint64_t *code_addr;

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
        char subcmd[64];
        const char *delim = " ";

        memset(subcmd, 0, sizeof(subcmd));
        strcpy(subcmd, strtok(arg, delim));

        if (!strcmp(subcmd, "unlock")){
            strcpy(product_sn_token, get_product_sn());
            debugf("Product SerialNo: %s.", product_sn_token);
            memset(product_sn_signature, 0, sizeof(product_sn_signature));
            memcpy(product_sn_signature, data, PRODUCT_SN_SIGNATURE_SIZE);

            ret = fb_verify_unlockkey(product_sn_signature, product_sn_token);
            if(ret == 1) {
                fastboot_okay("flash unlock success\n");
            } else {
                fastboot_fail("flash unlock failed\n");
            }
            return;
        }
#endif


	debugf("arg:%x date: 0x%x, sz 0x%x\n", arg, data, sz);

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#if defined (CONFIG_SECBOOT)
	if (!fb_check_permission_part_flash(arg)
			&& (get_lock_status() == VBOOT_STATUS_LOCK)) {
		fastboot_fail("flash Not allow! Please unlock or get permission first!");
		return;
	}
#else
	if (!fb_check_permission_part_flash(arg)) {
		fastboot_fail("Not allow!");
		return;
	}
#endif
#endif

	//ImageInfo.data_size =0x10000;
	if (!strcmp(arg, "boot") || !strcmp(arg, "recovery")) {
#ifdef CONFIG_SECURE_BOOT
		code_addr = (uint64_t *) get_code_addr(NULL, data);
		if (memcmp((void *)code_addr, BOOT_MAGIC, BOOT_MAGIC_SIZE)) {
			fastboot_fail("image is not a boot image");
			return;
		}
		secure_verify("uboot", data, 0);
#else
		if (memcmp((void *)data, BOOT_MAGIC, BOOT_MAGIC_SIZE)) {
			fastboot_fail("image is not a boot image");
			return;
		}
#endif
	}
#ifdef CONFIG_SECURE_BOOT
	if (strcmp(arg, "splloader") == 0) {
		secure_verify("splloader0", data, 0);
	} else if (strcmp(arg, "uboot") == 0) {
		secure_verify("splloader", data, 0);
	}
#endif

	/**
	 *	FIX ME!
	 *	assume first image buffer is big enough for nv
	 */
	for (i = 0; s_nv_vol_info[i].vol != NULL; i++) {
		if (!strcmp(arg, s_nv_vol_info[i].vol)) {
			debugf("fb_cmd_flash nandboot: s_backupnv_flag = %d\n", s_backupnv_flag);
			if (s_backupnv_flag) {
				char 		*partition_name = arg;
				uint8_t 	header_buf[NV_HEAD_LEN];
				nv_header_t *nv_header_p = NULL;
				int 		retval = 0;
				void 		*buf = data;

				retval = fb_nvmerge(partition_name, (unsigned char *)buf, FIXNV_SIZE);
				debugf("fb_nvmerge return %d\n", retval);

				memset(header_buf, 0x00, NV_HEAD_LEN);
				nv_header_p = header_buf;
				nv_header_p->magic = NV_HEAD_MAGIC;
				nv_header_p->len = FIXNV_SIZE;
				nv_header_p->checksum = (uint32_t) calc_checksum((unsigned char *)buf, FIXNV_SIZE);
				nv_header_p->version = NV_VERSION;
				/*write org nv */
				ret = do_raw_data_write(arg, FIXNV_SIZE + NV_HEAD_LEN, NV_HEAD_LEN, 0, header_buf);
				if (ret)
					goto end;
				ret = do_raw_data_write(arg, 0, FIXNV_SIZE, NV_HEAD_LEN, buf);
				if (ret)
					goto end;
				/*write bak nv */
				ret = do_raw_data_write(s_nv_vol_info[i].bakvol, FIXNV_SIZE + NV_HEAD_LEN, NV_HEAD_LEN, 0, header_buf);
				if (ret)
					goto end;
				ret = do_raw_data_write(s_nv_vol_info[i].bakvol, 0, FIXNV_SIZE, NV_HEAD_LEN, buf);
				goto end;
			} else {
				nv_header_t *header = NULL;
				uint8_t tmp[NV_HEAD_LEN];

				memset(tmp, 0x00, NV_HEAD_LEN);
				header = tmp;
				header->magic = NV_HEAD_MAGIC;
				header->len = FIXNV_SIZE;
				header->checksum = (uint32_t) calc_checksum((unsigned char *)data, FIXNV_SIZE);
				header->version = NV_VERSION;

				/*write org nv */
				ret = do_raw_data_write(arg, FIXNV_SIZE + NV_HEAD_LEN, NV_HEAD_LEN, 0, tmp);
				if (ret)
					goto end;
				ret = do_raw_data_write(arg, 0, FIXNV_SIZE, NV_HEAD_LEN, data);
				if (ret)
					goto end;
				/*write bak nv */
				ret = do_raw_data_write(s_nv_vol_info[i].bakvol, FIXNV_SIZE + NV_HEAD_LEN, NV_HEAD_LEN, 0, tmp);
				if (ret)
					goto end;
				ret = do_raw_data_write(s_nv_vol_info[i].bakvol, 0, FIXNV_SIZE, NV_HEAD_LEN, data);
				goto end;
			}

		}
	}

		ret = do_raw_data_write(arg, ImageInfo.data_size, ImageInfo.data_size, 0, ImageInfo.base_address);


end:
	if (!ret)
		fastboot_okay("");
	else
		fastboot_fail("flash error");
	return;

}

void fb_cmd_erase(const char *arg, void *data, uint64_t sz)
{
	struct mtd_info *nand;
	struct mtd_device *dev;
	struct part_info *part;
	nand_erase_options_t opts;
	u8 pnum;
	int ret;
	char buf[1024];

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	if (!fb_check_permission_part_erase(arg)) {
		fastboot_fail("Not allow!");
		return;
	}
#endif
	debugf("\n");

	if (!strcmp(arg, "persist")) {
		fastboot_fail("not support");
		return;
	} else if (!strcmp(arg, "config")) {
		arg = "persist";
	}

	ret = find_dev_and_part(arg, &dev, &pnum, &part);
	if (!ret) {
		nand = &nand_info[dev->id->num];
		memset(&opts, 0, sizeof(opts));
		opts.offset = (loff_t) (part->offset);
		opts.length = (loff_t) (part->size);
		opts.jffs2 = 0;
		opts.quiet = 1;
		ret = nand_erase_opts(nand, &opts);
		if (ret)
			goto end;
	}

	/*just erase 1k now */
	memset(buf, 0x0, 1024);
	ret = do_raw_data_write(arg, 1024, 1024, 0, buf);

end:
	if (ret)
		fastboot_fail("nand erase error");
	else
		fastboot_okay("");
	return;
}
#endif

void boot_linux(unsigned kaddr, unsigned taddr)
{
	void (*theKernel) (void *dtb_addr, int zero, int arch, int reserved) = (void*)kaddr;

	invalidate_dcache_all();

	theKernel(DT_ADR, 0, 0, 0);
}

void fb_cmd_setdump(const char *arg, void *data, uint64_t sz)
{
	int ret = 0;
	char subcmd[64];
	const char *delim = " ";

	memset(subcmd, 0, sizeof(subcmd));
	strcpy(subcmd, strtok(arg, delim));

	ret = sysdump_setdump_command(subcmd);
	if (ret < 0)
		fastboot_fail("setdump fail");
	else
		fastboot_okay("");

	write_log();
}

void fb_cmd_getdump(const char *arg, void *data, uint64_t sz)
{
	int ret = 0;
	char subcmd[64];
	char status_info[60];
	const char *delim = " ";
	int fulldump_enable_status;
	int minidump_enable_status;

	memset(subcmd, 0, sizeof(subcmd));
	strcpy(subcmd, strtok(arg, delim));

	ret = sysdump_getdump_command(subcmd, &fulldump_enable_status, &minidump_enable_status);
	if (ret < 0) {
		fastboot_fail("getdump command fail");
	} else {
#ifdef CONFIG_SPLASH_SCREEN
		lcd_printf("\nfulldump_enable_status:%d\nminidump_enable_status:%d\n", fulldump_enable_status, minidump_enable_status);
#endif
		sprintf(status_info, "INFO\nfulldump_enable_status:%d\nminidump_enable_status:%d\n",fulldump_enable_status, minidump_enable_status);
		fb_usb_write(status_info, strlen(status_info));
		fastboot_okay("");
	}
	write_log();
}


#ifdef CONFIG_SECBOOT
char product_sn_token[PRODUCT_SN_TOKEN_MAX_SIZE] __attribute__ ((aligned(4096)));
char product_sn_signature[PRODUCT_SN_SIGNATURE_SIZE] __attribute__((aligned(4096)));

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
static int repair_set_key(uint64_t offset, char *buf, int length)
{
	if (common_raw_write("miscdata", (uint64_t)length, (uint64_t)0, offset,
			buf)) {
		errorf("write miscdata data %d fail on offset %lld.\n", length, offset);
		return -1;
	}

	return 0;
}

static int repair_get_key(uint64_t offset, char *buf, int length)
{
	if (common_raw_read("miscdata", (uint64_t)length, offset, buf)) {
		errorf("read miscdata data %d fail on offset %lld.\n", length, offset);
		return -1;
	}

	return 0;
}

static int repair_clr_key(uint64_t offset)
{
	const char buf[2] = {0};

	if (common_raw_write("miscdata", (uint64_t)2, (uint64_t)0, offset, buf)) {
		errorf("clr miscdata data %d fail on offset %lld.\n", 2, offset);
		return -1;
	}

	return 0;
}

int fb_oem_repair_get_booargs(char *buf, int len)
{
	char wallpp[MISCDATA_WALLPP_SZ + 1] = {0};
	char skuid[MISCDATA_SKUID_SZ + 1] = {0};
	int c = 0;

	if (!repair_get_key(MISCDATA_SKUID_OFFSET, skuid, MISCDATA_SKUID_SZ)
			&& skuid[0] == 0x7E && skuid[1] == 0x7E) {
		c += snprintf(buf, len - c - 1, " androidboot.skuid=%s ", skuid + 2);
	}

	if (!repair_get_key(MISCDATA_WALLPP_OFFSET, wallpp, MISCDATA_WALLPP_SZ)
			&& wallpp[0] == 0x7E && wallpp[1] == 0x7E) {
		c += snprintf(buf + c, len - c - 1, "androidboot.wallpapered=%s ",
			wallpp + 2);
	}

	return c;
}

static void getrepair_psn(char *key)
{
	char psn[PRODUCT_SN_TOKEN_MAX_SIZE + 1] = {0};

	strcpy(psn, get_product_sn());
	if (strlen(psn))
		fastboot_info("%s=%s", key, psn);
	else
		fastboot_okay("");
}

static void getrepair_skuid(char *key)
{
	char skuid[MISCDATA_SKUID_SZ + 1] = {0};

	if (!repair_get_key(MISCDATA_SKUID_OFFSET, skuid, MISCDATA_SKUID_SZ)
			&& skuid[0] == 0x7E && skuid[1] == 0x7E)
		fastboot_info("%s=%s", key, skuid + 2);
	else
		fastboot_okay("");
}

static void getrepair_wallpapered(char *key)
{
	char wallpp[MISCDATA_WALLPP_SZ + 1] = {0};

	if (!repair_get_key(MISCDATA_WALLPP_OFFSET, wallpp, MISCDATA_WALLPP_SZ)
			&& wallpp[0] == 0x7E && wallpp[1] == 0x7E)
		fastboot_info("%s=%s", key, wallpp + 2);
	else
		fastboot_okay("");
}

static const struct getrepair {
	const char *key;
	void (*get)(char *key);
} fb_getrepair[] = {
	{
		.key = "psn",
		.get = getrepair_psn,
	}, {
		.key = "SKUID",
		.get = getrepair_skuid,
	}, {
		.key = "wallpapered",
		.get = getrepair_wallpapered,
	},
};

static void setrepair_psn(char *key, char *value)
{
	if (!set_product_sn(value, !value ? 0 : strlen(value)))
		fastboot_info("%s=%s", key, get_product_sn());
	else
		fastboot_fail("");
}

static void setrepair_skuid(char *key, char *value)
{
	int sz;

	if (!value) {
		repair_clr_key(MISCDATA_SKUID_OFFSET);
		fastboot_info("%s=", key);
		return;
	} else
		sz = strlen(value) > MISCDATA_SKUID_SZ ? MISCDATA_SKUID_SZ
				: strlen(value);

	if (!repair_set_key(MISCDATA_SKUID_OFFSET, "\x7E\x7E", 2)
			&& !repair_set_key(MISCDATA_SKUID_OFFSET + 2, value, sz)) {
		fastboot_info("%s=%s", key, value);
	}
}

static void setrepair_wallpapered(char *key, char *value)
{
	int sz;

	if (!value) {
		repair_clr_key(MISCDATA_WALLPP_OFFSET);
		fastboot_info("%s=", key);
		return;
	} else
		sz = strlen(value) > MISCDATA_WALLPP_SZ ? MISCDATA_WALLPP_SZ
				: strlen(value);

	if (!repair_set_key(MISCDATA_WALLPP_OFFSET, "\x7E\x7E", 2)
			&& !repair_set_key(MISCDATA_WALLPP_OFFSET + 2, value, sz)) {
		fastboot_info("%s=%s", key, value);
	}
}

static const struct setrepair {
	const char *key;
	void (*set)(char *key, char *value);
} fb_setrepair[] = {
	{
		.key = "psn",
		.set = setrepair_psn,
	}, {
		.key = "SKUID",
		.set = setrepair_skuid,
	}, {
		.key = "wallpapered",
		.set = setrepair_wallpapered,
	},
};

/* fastboot oem repair */
void fb_cmd_oem_repair(const char *arg, void *data, uint64_t sz)
{
	char *key, *opt, *value, *end = &arg[strlen(arg) - 1];
	const char *delim = " ";
	int i;

	if (!fb_check_permission(TYPE_PERMISSION_REPAIR)) {
		fastboot_fail("Not allow!");
		return;
	}

	while (*arg == *delim)
		arg++;

	/* trim trailing space */
	while ((*end == *delim) && (end != arg))
		*end-- = '\0';

	key = strtok(arg + strlen("repair"), delim);
	if (!key) {
		return;
	}

	opt = strtok(NULL, delim);
	if (!opt) {
		return;
	}

	if (!strcmp(opt, "get")) {
		for (i = 0; i < ARRAY_SIZE(fb_getrepair); i++)
			if (!strcmp(key, fb_getrepair[i].key))
				fb_getrepair[i].get(key);
	} else if (!strcmp(opt, "set")) {
		value = strtok(NULL, delim);
		for (i = 0; i < ARRAY_SIZE(fb_setrepair); i++)
			if (!strcmp(key, fb_setrepair[i].key))
				fb_setrepair[i].set(key, value);
	}
	return;
}

void fb_cmd_upload(const char *arg, void *data, uint64_t sz)
{
	int i;

	printf("%s\n", __func__);

	fastboot_ack("DATA", "0x158");

        for(i = 0; i < 344; i++)
                encrypt_data[i] = (unsigned char)encrypt_data[i];

	fb_usb_write(encrypt_data, 344);

	fastboot_state = STATE_COMMAND;
	fastboot_okay("");
	fastboot_state = STATE_COMPLETE;
}

int get_permission(void)
{
	return open_permission;
}
#endif
#endif

#ifndef CONFIG_SECBOOT
void fb_cmd_oem(const char *arg, void *data, uint64_t sz)
{
	const char *delim = " ";
	char subcmd[64];

	debugf("arg#%s#, data: %p, sz: 0x%llx\n", arg, data, sz);
	if (!strncmp(arg + 1, "backupnv", strlen("backupnv"))) {
		debugf("execute backupnv!\n");
		s_backupnv_flag = 1;
		fastboot_okay("");
		return;
	}
	if (!strncmp(arg + 1, "gsimode", strlen("gsimode"))) {
		debugf("enable gsi mode!\n");
		is_gsimode = 1;
		fastboot_okay("");
		return;
	}
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	if (!strncmp(arg + 1, "repair", strlen("repair"))) {
		fb_cmd_oem_repair(arg + 1, data, sz);
		return;
	}
#endif
}

#else

static int fb_cmd_oem_upload_ddr(char *range)
{
	uint64_t addr, size = 0;
	uint64_t offset = 0, send;
	char ulen[64];
	int ret;
	char *ptr;

	addr = simple_strtoull(range, &ptr, 16);
	if (ptr && ('+' == *ptr) && ('+' == *(ptr + 1))) {
		ptr += 2;
		size = simple_strtoull(ptr, NULL, 16);
		size += 1;
	}

	if (size) {
		printf("get addr %llx size %llx\n", addr, size);

		debugf("upload %llx bytes\n", size);
		sprintf(ulen, "0x%llx", size);
		fastboot_ack("DATA", ulen);

		while (size) {
			send = size > 512 ? 512 : size;
			ret = fb_usb_write(addr + offset, send);
			if (ret < 0)
				break;
			size -= send;
			offset += send;
		}

		debugf("write remain: %llxbytes\n", size);
	}

	fastboot_state = STATE_COMMAND;
	if (!size)
		fastboot_okay("");
	fastboot_state = STATE_COMPLETE;
	return size;
}

static int fb_cmd_oem_upload_gpt(void)
{
	char *ptr = NULL;
	int ret;
	int dev_id;
	char *ifname;
	block_dev_desc_t *desc;
	uint64_t size = -1;
	uint64_t offset = 0, send;
	char ulen[64];

	ifname = block_dev_get_name();
	dev_id = get_devnum_hwpart(ifname, 0/*USER_PART*/);
	if (dev_id < 0) {
		errorf("get user part dev num fail!\n");
		goto out;
	}

	desc = get_dev_hwpart(ifname, dev_id, 0/*USER_PART*/);
	if (!desc) {
		errorf("get user part dev fail!\n");
		goto out;
	}

	/* read size */
	size = desc->blksz * 2 + GPT_ENTRY_NUMBERS * GPT_ENTRY_SIZE;
	ptr = (char *)calloc(1, size);
	if (!ptr) {
		errorf("malloc fail\n");
		goto out;
	}

	if (desc->block_read(desc->dev, (lbaint_t)0,
			BLOCK_CNT(size, desc), ptr) != BLOCK_CNT(size, desc)) {
		errorf("Can't read GPT\n");
		goto out;
	}

	debugf("upload %llx bytes\n", size);
	sprintf(ulen, "0x%llx", size);
	fastboot_ack("DATA", ulen);

	offset = 0;
	while (size) {
		send = size > 512 ? 512 : size;
		ret = fb_usb_write(ptr + offset, send);
		if (ret < 0)
			break;
		size -= send;
		offset += send;
	}

	debugf("write remain: %llxbytes\n", size);

	fastboot_state = STATE_COMMAND;
	if (!size)
		fastboot_okay("");
	fastboot_state = STATE_COMPLETE;

out:
	if (ptr)
		free(ptr);
	return size;
}

static int fb_cmd_oem_upload_flash(char *part)
{
	uint64_t offset_s, offset_r, send, read;
	uint64_t addr = 0;
	uint64_t size = 0, part_size = 0;
	char ulen[64];
	int ret;
	char *ptr = NULL;
	char *range = part;
	char delim[] = ",";

	/* read gpt */
	if (!strcmp(part, "partition")) {
		return fb_cmd_oem_upload_gpt();
	}

	ptr = strsep(&range, delim);
	debugf("ptr: %s\n", ptr);
	if (*range) {
		debugf("range: %s\n", range);

		addr = simple_strtoull(range, &ptr, 16);
		if (ptr && ('+' == *ptr) && ('+' == *(ptr + 1))) {
			ptr += 2;
			size = simple_strtoull(ptr, NULL, 16);
			size += 1;
		}

		debugf("addr: %llx, size %llx\n", addr, size);
	}

	if ((get_img_partition_size(part, &part_size) < 0)
			|| part_size <= 0) {
		return -1;
	}

	if (addr >= part_size) {
		errorf("beyond the upper limit of the boundar,"
			" offset %llx part size %llx", addr, part_size);
		return -2;
	} else if (!addr && !size)
		size = part_size;
	  else if ((addr + size) > part_size)
		size = part_size - addr;

	printf("get partition part_size %llx\n", part_size);

	ptr = (char *)malloc(OEM_UPLOAD_FLASH_BUF);
	if (!ptr) {
		errorf("malloc fail\n");
		return -3;
	}

	sprintf(ulen, "0x%llx", size);
	fastboot_ack("DATA", ulen);

	if (addr)
		offset_r = addr;
	else
		offset_r = 0;

	debugf("upload %llx bytes, from offset %llx\n", size, offset_r);
	while (size) {
		read = size > OEM_UPLOAD_FLASH_BUF ? OEM_UPLOAD_FLASH_BUF : size;
		ret = common_raw_read(part, read, offset_r, ptr);
		if (ret) {
			errorf("read fail offset %llx\n", offset_r);
			goto out;
		}
		size -= read;
		offset_r += read;

		offset_s = 0;
		while (read) {
			send = read > 512 ? 512 : read;

			ret = fb_usb_write(ptr + offset_s, send);
			if (ret < 0)
				goto out;
			read -= send;
			offset_s += send;
		}
	}

out:
	debugf("write remain: %llxbytes\n", size);

	fastboot_state = STATE_COMMAND;
	if (!size)
		fastboot_okay("");
	fastboot_state = STATE_COMPLETE;

	if (ptr)
		free(ptr);
	return size;
}

char product_sn_token[PRODUCT_SN_TOKEN_MAX_SIZE] __attribute__ ((aligned(4096)));
char product_sn_signature[PRODUCT_SN_SIGNATURE_SIZE] __attribute__((aligned(4096)));


void fastboot_response_info(const char *info)
{
	if (info == 0)
		info = "";
	if (strlen("INFO") + strlen(info) >= 64) {
		debugf("too long string\r\n");
	}
	sprintf(response, "INFO%s", info);
	fb_usb_write(response, strlen(response));
}

void fb_cmd_startup_corex(char *core)
{
	const unsigned char magic = 0x5A;
	unsigned short val = 0;
	unsigned long core_num;
	char *ptr;

	if (strcmp(core, "default")) {
		core_num = simple_strtoul(core, &ptr, 10);
		printf("got core num %lu\n", core_num);

		val = (0x5A << 8) | ((unsigned char)core_num);
	}

	if (0 != common_raw_write("miscdata", CORE_STARTUP_FLAG_LEN, (uint64_t)0,
			(uint64_t)(CORE_STARTUP_FLAG_OFFSET), (char *)&val)) {
		errorf("write partition <miscdata> fail, val %x\n", val);
		fastboot_fail("Save fail");
		return;
	}

	fastboot_okay("please reboot for continue");
}

void fb_cmd_oem(const char *arg, void *data, uint64_t sz)
{
	char subcmd[64];
	char s[34];
	int pwd_verify_ret = 0;
	int i, j;
    int key_code;
    //20220606, Added by zhu_jun for bootloader unlock by devicekit begin
    int flag_unlock = 0;
    //20220606, Added by zhu_jun for bootloader unlock by devicekit end
    bool butt_check = false;
    unsigned int all_zero_flag = 1;
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	unsigned char permission[64] = {0};
	unsigned char *cmd_p = NULL;
	unsigned char *data_buf = ImageInfo.base_address;
	int ret = -1;
#endif
	const char *delim = " ";

	debugf("arg#%s#, data: %p, sz: 0x%llx\n", arg, data, sz);
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	if (!strncmp(arg + 1, "repair", strlen("repair"))) {
		fb_cmd_oem_repair(arg + 1, data, sz);
		return;
	}

	cmd_p = (const char*)arg + 12;
#endif

	if (!strncmp(arg + 1, "gsimode", strlen("gsimode"))) {
		debugf("enable gsi mode!\n");
		is_gsimode = 1;
		fastboot_okay("");
		return;
	}
	memset(subcmd, 0, sizeof(subcmd));
	memset(s, 0, sizeof(s));
	memset(product_sn_token, 0, sizeof(product_sn_token));

	strcpy(subcmd, strtok(arg, delim));
	if (strlen(subcmd)) {
		debugf("subcmd +%s+\n", subcmd);
	} else {
		debugf("subcmd is null.\n");
		fastboot_fail("subcmd is null.");
		return;
	}

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	if(!strcmp(subcmd, "auth_start"))
	{
		ret = rsa_encrypt_data(encrypt_data);
		if(ret == 0)
			fastboot_okay("");
		else
			fastboot_fail("rsa encrypt failed");
		return;
	}else if (!strcmp(subcmd, "permission")){
		strcpy(product_sn_token, get_product_sn());
		if(!strcmp(cmd_p, "flash")){
			printf("the cmd is flash\n");
			ret = rsa_decrypt_data("flash", data_buf, product_sn_token);
			if(ret == 0)
				fastboot_fail("flash decrypt failed");
			else
				fastboot_okay("");
		}else if(!strcmp(cmd_p, "simlock")){
			printf("the cmd is simlock\n");
			ret = rsa_decrypt_data("simlock", data_buf, product_sn_token);
			if(ret == 0)
				fastboot_fail("simlock decrypt failed");
			else
				fastboot_okay("");
		}else if(!strcmp(cmd_p, "repair")){
			printf("the cmd is repair\n");
			ret = rsa_decrypt_data("repair", data_buf, product_sn_token);
			if(ret == 0)
				fastboot_fail("repair decrypt failed");
			else
				fastboot_okay("");
		}
			open_permission = open_permission | ret;
			return;
	}else if (!strcmp(subcmd, "getpermissions")){
		printf("the cmd is getpermissions\n");
		if(open_permission == 0x0)
		{
			fastboot_response_info("permissions=None");
			fastboot_okay("");
		}
		if(open_permission == 0x1)
		{
			fastboot_response_info("permissions=flash");
			fastboot_okay("");
		}
		if(open_permission == 0x2)
		{
			fastboot_response_info("permissions=simlock");
			fastboot_okay("");
		}
		if(open_permission == 0x3)
		{
			fastboot_response_info("permissions=flash|simlock");
			fastboot_okay("");
		}
		if(open_permission == 0x4)
		{
			fastboot_response_info("permissions=repair");
			fastboot_okay("");
		}
		if(open_permission == 0x5)
		{
			fastboot_response_info("permissions=flash|repair");
			fastboot_okay("");
		}
		if(open_permission == 0x6)
		{
			fastboot_response_info("permissions=simlock|repair");
			fastboot_okay("");
		}
		if(open_permission == 0x7)
		{
			fastboot_response_info("permissions=flash|simlock|repair");
			fastboot_okay("");
		}
			return;
	} else
#endif

	if (!strcmp(subcmd, "pull")) {
		char *param = strtok(NULL, delim);

		if (param && strlen(param)) {
			printf("param %s\n", param);
			if (!strncmp(param, "0x", 2)) {
				if (fb_cmd_oem_upload_ddr(param)) {
					fastboot_fail("upload range fail.");
				}
			} else {
				if (fb_cmd_oem_upload_flash(param)) {
					fastboot_fail("upload partition fail.");
				}
			}
		} else
			fastboot_fail("unknown format.");
		return;
	} else if (!strcmp(subcmd, "get_identifier_token")) {
		strcpy(product_sn_token, get_product_sn());
		debugf("Identifier token: %s.\n", product_sn_token);
		fastboot_response_sn("Identifier token:\n");

		for (j = 0; j < 4; j++){

			for (i = 0; i < 16; i++){
				if (product_sn_token[16*j+i] == '\0') {
					strcat(s,"\n");
					break;
				}
				if (i < 15) {
					sprintf(s+i*2, "%02x", product_sn_token[16*j+i]);
				} else {
					sprintf(s+i*2, "%02x\n", product_sn_token[16*j+i]);
				}
			}

			fastboot_response_sn(s);

			if (product_sn_token[16*j+i] == '\0') {
				break;
			}
		}

		fastboot_okay("");
	} else if (!strcmp(subcmd, "startup_core")) {
		char *core = strtok(NULL, delim);

		if (core && strlen(core))
			fb_cmd_startup_corex(core);
		else
			fastboot_fail("unknown format.");
		return;
	} else if (!strcmp(subcmd, "unlock")) {
		int op = -1, curow = 0;
    	if (get_lock_status() == VBOOT_STATUS_UNLOCK) {
    	debugf("bootloader has been unlocked\n");
        fastboot_fail("Bootloader can not been unlocked repeatly.");
       	return;
       	}

//20220615, Added by zhu_jun for disable bootloader unlock  on user MP device begin
#ifdef USER_BUILD
        if (is_MP_Device()) {
            fastboot_fail("Unlock is not allow on user MP device.");
            return;
        }

#endif
//20220615, Added by zhu_jun for disable bootloader unlock  on user MP device end
      	strcpy(product_sn_token, get_product_sn());
       	debugf("Identifier token: %s.\n", product_sn_token);

//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
//#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#ifndef WT_COMPILE_FACTORY_VERSION
        if (1 != fb_verify_unlockkey(product_sn_signature, product_sn_token)) {
        	debugf("execute <fastboot oem unlock> command fail.\n");
        	fastboot_fail("Unlock bootloader fail. fb_verify_unlockkey");
        	return;
        }
#endif
/*#else
        if (verify_product_sn_signature()) {
          	debugf("execute <fastboot oem unlock> command fail.\n");
         	fastboot_fail("Unlock bootloader fail.");
           	return;
       	}
#endif
*/
#ifndef WT_COMPILE_FACTORY_VERSION
        op = display_unlock_infos_and_wait_op(true);
		if ( op == OP_TIMEOUT ) {
			debugf("timeout\n");
           	fastboot_fail("Unlock bootloader fail.");
           	return;
		} else if ( op == OP_CANCEL ) {
			fastboot_okay("Info:user cancel unlock bootloader! ");
            return;
		} 
#endif			
		curow = lcd_get_screen_rows();
		lcd_position_cursor(0, curow - ROW_LOG_START); 
	
       	lcd_printf("Begin to erase user data...\n");
        if (0 != common_raw_erase("userdata", 0, 0)) {
        	debugf("erase userdata failed\n");
           	fastboot_fail("Erase userdata fail.");
           	return;
     	}

        lcd_printf("   Begin to erase metadata ...\n");
		if (0 != common_raw_erase("metadata", 0, 0)) {
			debugf("erase metadata failed\n");
			fastboot_fail("Erase metadata fail.");
			return;
		} 

      	if (set_lock_status(VBOOT_STATUS_UNLOCK)) {
           	debugf("set_lock_status failed\n");
           	fastboot_fail("Unlock bootloader fail.");
           	return;
      	}

      	debugf("execute <fastboot oem unlock> successfully.\n");
      	lcd_printf("   Incfo:Unlock bootloader success!\n");
      	fastboot_okay("Info:Unlock bootloader success! ");
	// after unlock bootloader, devices will reboot normal mode
	reboot_devices(CMD_NORMAL_MODE);
	//20220606, Added by zhu_jun for bootloader unlock by devicekit end
	} else if(!strcmp(subcmd, "lock")){
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
            if (get_lock_status() == VBOOT_STATUS_LOCK) {
                fastboot_fail("Bootloader can not been locked repeatly.");
                return;
            }

            if (set_lock_status(VBOOT_STATUS_LOCK)) {
                debugf("execute <fastboot_response_snt flashing lock_bootloader> command fail.\n");
                fastboot_fail("Lock butt_checkootloader fail.");
                return;
            }

            debugf("execute <fastboot flashing lock_bootloader> command successfully.\n");
            lcd_printf("Info:Lock bootloader success!\n");
            fastboot_okay("Lock bootloader successfully!");
#endif
    } else if(!strcmp(subcmd, "getsecurityversion")) {
		debugf("execute getsecurityversion!\n");

		const char securityversion[] = "1";//Customer-defined, defaults to 1

		fastboot_response_info(securityversion);

		fastboot_okay("");
	} else if(!strcmp(subcmd, "getversions")) {
		debugf("execute getversions!\n");

		char temp[128];
		char model[64] = "model=";
		char sub_model[64] = "sub_model=";
		char sw_vr[64] = "software version=";
		char sw_model[64] = "SW model=";
		char build_number[64] = "build number=";
		char hw_vr[64] = "hardware version=";
		char rf_id[64] = "RF band id=";
		char temp_config[7][32] = {0};

		const char none[] = "none";

		if (0 != common_raw_read("miscdata", (uint64_t)sizeof(temp),
				(uint64_t)ALL_VERSION_OFFSET, temp)) {
			errorf("<miscdata> read error\n");
			fastboot_fail("read miscdata fail!");
			return;
		}

		char *token = strtok(temp, ";");
		i = 0;
		while (token != NULL) {
			debugf("%s\n", token);

			strlcpy(temp_config[i], token, sizeof(temp_config[0]));

			token = strtok(NULL, ";");
			i++;
		}

		debugf("get parameter: %d\n", i);

		/* 0 (bootloader) model=$(ro.product.model) */
		sprintf(model + strlen(model), "%s", temp_config[MODLE]);
		fastboot_response_info(model);

		/* 1 (bootloader) sub_model=none */
		sprintf(sub_model + strlen(sub_model), "%s", temp_config[SUB_MD]);
		fastboot_response_info(sub_model);

		/* 2 (bootloader) software version=$(ro.build.display.id) */
		sprintf(sw_vr + strlen(sw_vr), "%s", temp_config[SW_VR]);
		fastboot_response_info(sw_vr);

		/* 3 (bootloader) SW model=$(ro.product.model.num) */
		sprintf(sw_model + strlen(sw_model), "%s", temp_config[SW_MD]);
		fastboot_response_info(sw_model);

		/* 4 (bootloader) build number=A01 or B01 */
		sprintf(build_number + strlen(build_number), "%s", temp_config[BD_NU]);
		fastboot_response_info(build_number);

		/* 5 (bootloader) hardware version=$(Defined by ODM) */
		sprintf(hw_vr + strlen(hw_vr), "%s", temp_config[HW_VR]);
		fastboot_response_info(hw_vr);

		/* 6 (bootloader) RF band id=$(Defined by ODM) */
		sprintf(rf_id + strlen(rf_id), "%s", temp_config[RF_ID]);
		fastboot_response_info(rf_id);

		fastboot_okay("");

	} else if (!strncmp(subcmd, "backupnv", strlen("backupnv"))) {
			debugf("oem SECBOOT:execute backupnv!\n");
			s_backupnv_flag = 1;
			fastboot_okay("");
	//added by dongming, support fastboot oem erase_metadata, 20220903
	} else if (!strncmp(subcmd, "erase_metadata", strlen("erase_metadata"))) {
                if (get_lock_status() == VBOOT_STATUS_LOCK) {
			debugf("Info:Bootloader has been locked!! no permission to erase_metadata!!\n");
                        fastboot_fail("Bootloader has been locked!!no permission to erase_metadata!!\n");
                        return;
                }

                debugf("Begin to erase user data...\n");
                if (0 != common_raw_erase("userdata", 0, 0)) {
                        debugf("erase userdata failed\n");
                        fastboot_fail("Erase userdata fail.");
                        return;
                }

                debugf("   Begin to erase metadata ...\n");
                if (0 != common_raw_erase("metadata", 0, 0)) {
                        debugf("erase metadata failed\n");
                        fastboot_fail("Erase metadata fail.");
                        return;
                }
		fastboot_okay("");
                return;
	// end added
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
	} else if (!strcmp(subcmd, "off-mode-charge")) {
		debugf("oem off-mode-charge setting\n");
		if (!strncmp(arg+17,"0",strlen("0"))) {
			debugf("into set 0 mode!\n");
			unsigned short flag = 1;
			if (common_raw_write("miscdata", OFF_MODE_CHARGE_FLAG_LEN, (uint64_t)0, (uint64_t)OFF_MODE_CHARGE_FLAG_OFFSET, (char *)&flag)) {
				errorf("write miscdata off-mode-charge flag fail!\n");
			} else {
				debugf("off-mode-charge off now\n");
			}
		} else if(!strncmp(arg+17,"1",strlen("1"))) {
			debugf("into set 1 mode!\n");
			unsigned short flag = 0;
			if (common_raw_write("miscdata", OFF_MODE_CHARGE_FLAG_LEN, (uint64_t)0, (uint64_t)OFF_MODE_CHARGE_FLAG_OFFSET, (char *)&flag)) {
				errorf("write miscdata off-mode-charge flag fail!\n");
			} else {
				debugf("off-mode-charge on now\n");
			}
		} else if(!strncmp(arg+17,"2",strlen("2"))) {
			debugf("into set 2 mode!\n");
			unsigned short flag = 2;
			if (common_raw_write("miscdata", OFF_MODE_CHARGE_FLAG_LEN, (uint64_t)0, (uint64_t)OFF_MODE_CHARGE_FLAG_OFFSET, (char *)&flag)) {
				errorf("write miscdata off-mode-charge flag fail!\n");
			} else {
				debugf("off-mode-charge on now\n");
			}
		}
		debugf("end of off-mode-charge setting!\n");
		fastboot_okay("");
	//20220602, Added by zhu_jun for VSI-687 support fastboot command:fastboot oem off-mode-charge 0|1|2 begin
	} else {
		fastboot_fail("unknown cmd.");
	}
}

void fb_cmd_flashing(const char *arg, void *data, uint64_t sz)
{
	char subcmd[64];
	const char *delim = " ";
	int i = 0;
	unsigned int all_zero_flag = 1;
	bool butt_check = false;
	int key_code;
	//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
	int flag_lock = 0;
	//20220606, Added by zhu_jun for bootloader unlock by devicekit end

	debugf("arg#%s#, data: %p, sz: 0x%llx\n", arg, data, sz);

	memset(subcmd, 0, sizeof(subcmd));

	strcpy(subcmd, strtok(arg, delim));
	if (strlen(subcmd)) {
		debugf("subcmd +%s+\n", subcmd);
	} else {
		debugf("submd is null.\n");
		fastboot_fail("subcmd is null.");
		return;
	}

	//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
	if (!strcmp(subcmd, "lock")) {
	    int op = -1, curow = 0;
		if (get_lock_status() == VBOOT_STATUS_LOCK) {
			debugf("Bootloader has been locked! Flashing lock is not allowed!\n");
			fastboot_fail("Flashing lock is not allowed!");
			return;
		}

		if (fastboot_mode_flag != MODE_FASTBOOT_REPAIR) {
			lcd_printf("\n\n   Flashing lock is not allowed! fastboot_mode_flag=%d!\n", fastboot_mode_flag);
			debugf("Flashing lock is not allowed! fastboot_mode_flag=%d!\n", fastboot_mode_flag);
			fastboot_fail("Flashing lock is not allowed!");
			return;
		}
#ifndef WT_COMPILE_FACTORY_VERSION
		op = display_unlock_infos_and_wait_op(false);
        if ( op == OP_TIMEOUT ) {
            debugf("timeout\n");
            fastboot_fail("lock bootloader fail.");
            return;
        } else if ( op == OP_CANCEL ) {
            fastboot_okay("Info:user cancel lock bootloader! ");
            return;
        }
#endif
        curow = lcd_get_screen_rows();
        lcd_position_cursor(0, curow - ROW_LOG_START);
	//20220606, Added by zhu_jun for bootloader unlock by devicekit end

		lcd_printf("   Begin to erase user data...\n");
		if (0 != common_raw_erase("userdata", 0, 0)) {
			debugf("erase userdata failed\n");
			fastboot_fail("Erase userdata fail.");
			return;
		}

		lcd_printf("   Begin to erase metadata ...\n");
		if (0 != common_raw_erase("metadata", 0, 0)) {
			debugf("erase metadata failed\n");
			fastboot_fail("Erase metadata fail.");
			return;
		}

		if (set_lock_status(VBOOT_STATUS_LOCK)) {
			debugf("execute <fastboot flashing lock_bootloader> command fail.\n");
			fastboot_fail("Lock bootloader fail.");
			return;
		}

		debugf("execute <fastboot flashing lock_bootloader> command successfully.\n");
		lcd_printf("   Info:Lock bootloader success!\n");
		fastboot_okay("Lock bootloader successfully!   ");
		//20220606, Added by zhu_jun for bootloader unlock by devicekit begin
		// after lock bootloader, devices will reboot normal mode
		reboot_devices(CMD_NORMAL_MODE);
		//20220606, Added by zhu_jun for bootloader unlock by devicekit end

	} else if (!strcmp(subcmd, "unlock_critical")) {
		fastboot_fail("Not implement.");
	} else if (!strcmp(subcmd, "lock_critical")) {
		fastboot_fail("Not implement.");
	} else if (!strcmp(subcmd, "get_unlock_ability")) {
		fastboot_fail("Not implement.");
	} else if (!strcmp(subcmd, "get_unlock_bootloader_nonce")) {
		fastboot_fail("Not implement.");
	} else if (!strcmp(subcmd, "lock_bootloader")) {
		if (get_lock_status() == VBOOT_STATUS_LOCK) {
		        lcd_printf("   Info:Bootloader has been locked!\n");
			fastboot_okay("Bootloader has been locked!\n");
			return;
		}

		lcd_printf("\n   Warning: lock device may erase user data.\n");
		lcd_printf("   Press volume down button to confirm that.\n");
		lcd_printf("   Press volume up button to cancel.\n");
		while(!butt_check) {
			/* continue check till button pressed */
			key_code = wait_for_keypress(TIMEOUT_TEN_SEC, false);
			if (key_code == KEY_VOLUMEDOWN) {
				butt_check = true;
			} else if (key_code == KEY_VOLUMEUP) {
				lcd_printf("   Info:user cancelled!\n");
				fastboot_okay("Info:user cancel lock bootloader!   ");
				return;
			}
		}
		lcd_printf("   Begin to erase user data...\n");
		if (0 != common_raw_erase("userdata", 0, 0)) {
			debugf("erase userdata failed\n");
			fastboot_fail("Erase userdata fail.");
			return;
		}

		lcd_printf("   Begin to erase metadata ...\n");
		if (0 != common_raw_erase("metadata", 0, 0)) {
			debugf("erase metadata failed\n");
			fastboot_fail("Erase metadata fail.");
			return;
		}

		if (set_lock_status(VBOOT_STATUS_LOCK)) {
			debugf("execute <fastboot flashing lock_bootloader> command fail.\n");
			fastboot_fail("Lock bootloader fail.");
			return;
		}

		debugf("execute <fastboot flashing lock_bootloader> command successfully.\n");
		lcd_printf("   Info:Lock bootloader success!\n");
		fastboot_okay("Lock bootloader successfully!   ");
	} else if (!strcmp(subcmd, "unlock_bootloader")) {
		if (get_lock_status() == VBOOT_STATUS_UNLOCK) {
			debugf("bootloader has been unlocked\n");
			fastboot_fail("Bootloader can not been unlocked repeatly.");
			return ;
		}

		for (i = 0; i < 64; i++) {
			if (product_sn_token[i]) {
				all_zero_flag = 0;
			}
		}
		if (all_zero_flag){
			fastboot_fail("Please firstly execute <fastboot oem get_identifier_token>");
			return;
		}

        memset(product_sn_signature, 0, sizeof(product_sn_signature));
        memcpy(product_sn_signature, data, PRODUCT_SN_SIGNATURE_SIZE);

		//dumpHex("flashing unlock_bootloader", data, PRODUCT_SN_SIGNATURE_SIZE);

		if (verify_product_sn_signature()) {
			debugf("execute <fastboot flashing unlock_bootloader> command fail.\n");
			fastboot_fail("Unlock bootloader fail.");
			return;
		}

        memset(product_sn_signature, 0, sizeof(product_sn_signature));

		lcd_printf("\n   Warning: Unlock device may erase user data.\n");
		lcd_printf("   Press volume down button to confirm that.\n");
		lcd_printf("   Press volume up button to cancel.\n");
		while(!butt_check) {
			/* continue check till button pressed */
			key_code = wait_for_keypress(TIMEOUT_TEN_SEC, false);
			if (key_code == KEY_VOLUMEDOWN) {
				butt_check = true;
			} else if (key_code == KEY_VOLUMEUP) {
				lcd_printf("   Info:user cancelled!\n");
				fastboot_okay("Info:user cancel unlock bootloader!   ");
				return;
			}
		}
		lcd_printf("   Begin to erase user data...\n");
		if (0 != common_raw_erase("userdata", 0, 0)) {
			debugf("erase userdata failed\n");
			fastboot_fail("Erase userdata fail.");
			return;
		}

		lcd_printf("   Begin to erase metadata ...\n");
		if (0 != common_raw_erase("metadata", 0, 0)) {
			debugf("erase metadata failed\n");
			fastboot_fail("Erase metadata fail.");
			return;
		}

		if (set_lock_status(VBOOT_STATUS_UNLOCK)) {
			debugf("set_lock_status failed\n");
			fastboot_fail("Unlock bootloader fail.");
			return;
		}

		debugf("execute <fastboot flashing unlock_bootloader> successfully.\n");
		lcd_printf("   Info:Unlock bootloader success!\n");
		fastboot_okay("Info:Unlock bootloader success!   ");
	} else {
		fastboot_fail("unknown cmd.");
	}
}

static void fastboot_lcs_init(void)
{
    int ret = -1;
    char lcs[8] = {0};
    int p = 0, i = 0;

    unsigned int t_lcs __attribute__((aligned(4096))) = 0;
    ret = get_lcs(&t_lcs);
    if(ret == 0){
        sprintf(lcs, "%d", t_lcs);
        fastboot_publish("lcs", strdup(lcs));
    }else{
        debugf("get lcs fail\n");
    }
}

static void fastboot_token_init(void)
{
    int ret = -1;
    char token_value[64] = {0};
    char tokenname[16] = {0};
    int p = 0, i = 0;

    strcpy(product_sn_token, get_product_sn());
    for(p=0;p<4;p++){
        if('\0' == product_sn_token[p*16])
            break;
        memset(token_value, 0, 64);
        memset(tokenname, 0, 16);
        for(i=p*16;i<((p+1)*16);i++){
            if('\0' == product_sn_token[p*16])
                break;
            sprintf(token_value+(i%16)*2, "%02x", product_sn_token[i]);
        }
        sprintf(tokenname, "tokenp%d", p+1);
        fastboot_publish(strdup(tokenname), strdup(token_value));
    }
}


static void fastboot_socid_init(void)
{
    int ret = -1;
    uint8_t socIdBuff[32] __attribute__((aligned(4096)));
    char socid_buf[64] = {0};
    char socid_name[16] = {0};
    int p = 0, i = 0;

    ret = get_socid(socIdBuff, sizeof(socIdBuff));
    if(ret == 0){
        for(p=0; p<2; p++){
            memset(socid_buf, 0, 64);
            memset(socid_name, 0, 16);
            for(i=p*16;i<((p+1)*16);i++){
                sprintf(socid_buf+(i%16)*2, "%02x", socIdBuff[i]);
            }
            sprintf(socid_name, "socidp%d", p+1);
            fastboot_publish(strdup(socid_name), strdup(socid_buf));
        }
    }else{
        debugf("get socid fail\n");
    }
}
#endif //CONFIG_SECBOOT

extern unsigned char raw_header[8192];
void fb_cmd_boot(const char *arg, void *data, uint64_t sz)
{
	boot_img_hdr *hdr = (boot_img_hdr *)raw_header;
	unsigned kernel_actual;
	unsigned ramdisk_actual;

	if (memcmp(hdr->magic, BOOT_MAGIC, BOOT_MAGIC_SIZE)) {
		debugf("boot image headr: %s\n", hdr->magic);
		fastboot_fail("bad boot image header");
		return;
	}
	kernel_actual = ROUND_TO_PAGE(hdr->kernel_size, (KERNL_PAGE_SIZE - 1));
	if (kernel_actual <= 0) {
		fastboot_fail("kernel image should not be zero");
		return;
	}
	ramdisk_actual = ROUND_TO_PAGE(hdr->ramdisk_size, (KERNL_PAGE_SIZE - 1));
	if (0 == ramdisk_actual) {
		fastboot_fail("ramdisk size error");
		return;
	}

	memcpy((void *)hdr->kernel_addr, (void *)data + KERNL_PAGE_SIZE, kernel_actual);
	memcpy((void *)hdr->ramdisk_addr, (void *)data + KERNL_PAGE_SIZE + kernel_actual, ramdisk_actual);

	debugf("kernel @0x%08x (0x%08x bytes)\n", hdr->kernel_addr, kernel_actual);
	debugf("ramdisk @0x%08x (0x%08x bytes)\n", hdr->ramdisk_addr, ramdisk_actual);

	fastboot_okay("");
	usb_driver_exit();
	boot_linux(hdr->kernel_addr, hdr->tags_addr);
}

void fb_cmd_continue(const char *arg, void *data, uint64_t sz)
{
	fastboot_okay("");
	usb_driver_exit();
	normal_mode();
}

void fb_cmd_reboot(const char *arg, void *data, uint64_t sz)
{
	fastboot_okay("");
	/* the last time to write log before reboot */
	write_log_last();
	reboot_devices(CMD_NORMAL_MODE);
}

/**
 * enter userpace fastboot mode
 * 1. clear flags on misc
 * 2. reboot into recovery mode
 */
void fb_cmd_reboot_recovery(const char *arg, void *data, uint64_t sz)
{
	if (0 != clear_recovery_not_run_fastbootd()) {
		errorf("write flags fail\n");
		fastboot_fail("write misc fail\n");
		goto err;
	}

	fastboot_okay("");
	usb_driver_exit();
	/* the last time to write log before reboot */
	write_log_last();
	reboot_devices(CMD_RECOVERY_MODE);
	return;

err:
	usb_driver_exit();
	reboot_devices(CMD_FASTBOOT_MODE);
}

/**
 * enter userpace fastboot mode
 * 1. set flags on misc
 * 2. reboot into recovery mode
 */
void fb_cmd_reboot_userspace_fastboot(const char *arg, void *data, uint64_t sz)
{
	//20220615, Added by zhu_jun for disallow to enter fastbootd mode on locked device begin
	// If the device is lock, donot allow to enter fastbootd mode
	if (get_lock_status() != VBOOT_STATUS_UNLOCK) {
		fastboot_fail("No permission to enter fastbootd mode for locked device \n");
		goto err;
	}
	//20220615, Added by zhu_jun for disallow to enter fastbootd mode on locked device end

	if (0 != set_recovery_run_fastbootd()) {
		errorf("write flags fail\n");
		fastboot_fail("write misc fail\n");
		goto err;
	}

	fastboot_okay("");
	usb_driver_exit();
	/* the last time to write log before reboot */
	write_log_last();
	reboot_devices(CMD_RECOVERY_MODE);
	return;

err:
	usb_driver_exit();
	reboot_devices(CMD_FASTBOOT_MODE);
}

void fb_cmd_reboot_bootloader(const char *arg, void *data, uint64_t sz)
{
	fastboot_okay("");
	usb_driver_exit();
	/* the last time to write log before reboot */
	write_log_last();
	reboot_devices(CMD_FASTBOOT_MODE);
}

#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
#define MAGIC_ENTER_EDL		{0x5a, 0x5a, 0x12, 0x34}
/* set edl download flag on miscdata */
int fb_require_reboot_edl(int on)
{
	uint64_t offset = MISCDATA_EDL_OFFSET;
	int length = 4;
	char set[] = MAGIC_ENTER_EDL, clr[4] = {0};

	if (common_raw_write("miscdata", (uint64_t)length, (uint64_t)0, offset,
			on ? (char *)set : (char *)clr)) {
		errorf("write data %d fail on offset %lld.\n", length,
			offset);
		return -1;
	}

	debugf("%srequire reboot edl\n", on ? " " : "no ");
	return 0;
}

int fb_check_secboot_enable(void)
{

#ifdef CONFIG_SECBOOT 
	unsigned int t_lcs __attribute__((aligned(4096)));
	unsigned int lcs = 0;
	boot_mode_t bmode;

	bmode = get_boot_role();
	if (BOOTLOADER_MODE_DOWNLOAD == bmode) {
		if (sprd_get_lcs(&lcs) || (5 != lcs)) {
			debugf("secboot was disabled(lcs: %d)\n", lcs);
			return -1;
		}
		debugf("secboot was enabled\n");
	} else if (BOOTLOADER_MODE_LOAD == bmode) {
		if (get_lcs(&t_lcs) || (5 != t_lcs)) {
			debugf("secboot was disabled(t_lcs: %d)\n", t_lcs);
			return -2;
		}
		debugf("secboot was enabled\n");
	}
#else
	if (0) {
	}
#endif
	else {
		debugf("unknown state\n");
		return -3;
	}

	return 0;
}

/* if it was required to reboot edl */
int fb_check_reboot_edl(void *ptr)
{
	char tmp[] = MAGIC_ENTER_EDL, buf[4] = {0};
	uint64_t offset = MISCDATA_EDL_OFFSET;
	int length = 4;

	/* if secboot was not enabled, then go ahead */
	if (fb_check_secboot_enable())
		return 0;

	if (common_raw_read("miscdata", (uint64_t)length, offset, buf)) {
		errorf("read data %d fail on offset %lld.\n", length, offset);
		return -1;
	}

	if (memcmp(tmp, buf, sizeof(buf))) {
		debugf("(%x) operation was not required by reboot-edl\n", *(int *)buf);
		return -2;
	}

	return 0;
}

void fb_cmd_reboot_edl(const char *arg, void *data, uint64_t sz)
{
	if (!fb_check_permission(TYPE_PERMISSION_REPAIR)) {
		fastboot_fail("Not allow!");
		return;
	}

	if (fb_require_reboot_edl(1)) {
		fastboot_fail("reboot edl fail\n");
		return;
	}

	fastboot_okay("");
	usb_driver_exit();
	reboot_devices(CMD_AUTODLOADER_REBOOT);
}
#endif

void fb_cmd_powerdown(const char *arg, void *data, uint64_t sz)
{
	fastboot_okay("");
	/* the last time to write log before reboot */
	write_log_last();
	power_down_devices(0);

}

/*add fastboot cmd for sharkl2*/
#ifdef CONFIG_SECBOOT
#define  SOCID_SIZE_IN_WORDS 8
void fb_cmd_getlcs(const char *arg, void *data, uint64_t sz){
	int ret = 0;
	unsigned int t_lcs __attribute__((aligned(4096))) = 0;
	ret = get_lcs(&t_lcs);
	char s[20]={0};
	if(ret!=0){
		sprintf(s, " ret is %04x", ret);
		fastboot_fail(s);
	}else{
		sprintf(s, "lcs is %d\n", t_lcs);
		fastboot_okay(s);
	}
}

void fb_cmd_setrma(const char *arg, void *data, uint64_t sz){
	int ret = 0;
	lcd_printf(
		"\n\n------------------------------------------------------------------------\n"
		"   Warning:RMA will change hardware status and unrecoverable, also will make some secure data unaccessible!\n"
		"   Do you confirm that you are developer and need this operation really?\n"
		"   Press button 'Volumn-Down' for 'No'.\n"
		"   Press button 'Volumn-Up' for 'Yes'.\n"
		"   The operation will be cancelled automatically after 20 seconds.\n"
		"------------------------------------------------------------------------\n");
	int key_code = wait_for_keypress(TIMEOUT_TEN_SEC, false);
	if (key_code == KEY_VOLUMEDOWN) {
		fastboot_fail("user cancelled");
	} else if (key_code == KEY_VOLUMEUP) {
		ret = set_rma();
		char s[20]={0};
		if(ret!=0){
			sprintf(s, " ret is %04x", ret);
			fastboot_fail(s);
		}else{
			fastboot_okay("");
		}
	} else if (key_code == -1) {
		fastboot_fail("time out");
	}
	lcd_clear();
	//lcd_splash("logo");
    if ( s_boot_mode == CMD_FASTBOOT_MODE ) {
	    lcd_position_cursor(0, 0);
        lcd_printf("\n   fastboot mode");
    }
}

void fb_cmd_getsocid(const char *arg, void *data, uint64_t sz){
	int ret = 0;
	uint8_t socIdBuff[32] __attribute__((aligned(4096)));
	ret = get_socid(socIdBuff, sizeof(socIdBuff));
	char s[33] = {0};
	if(ret!=0){
		sprintf(s, " ret is %04x", ret);
		fastboot_fail(s);
	}else{
		fastboot_response_socid("socid is:\n");
		int i;
		for(i=0;i<16;i++){
			if(i<15){
				sprintf(s+i*2, "%02x", socIdBuff[i]);
			}else{
				sprintf(s+i*2, "%02x\n", socIdBuff[i]);
			}
		}
		fastboot_response_socid(s);
		int j;
		for(j=16;j<32;j++){
			if(j<31){
				sprintf(s+(j-16)*2, "%02x", socIdBuff[j]);
			}else{
				sprintf(s+(j-16)*2, "%02x\n", socIdBuff[j]);
			}
		}
		fastboot_response_socid(s);
		fastboot_okay("");
	}
}
#endif

void fb_cmd_set_active(const char *arg)
{
	struct bootloader_control abc = {0};
	disk_partition_t part_info = {0};
	block_dev_desc_t *dev;
	ulong abc_offset, abc_size;
	int ret, slot;

	abc_offset = offsetof(struct bootloader_message_ab, slot_suffix);
	abc_size = sizeof(struct bootloader_control);

	ret = common_raw_read("misc", (u64)abc_size, (u64)abc_offset, (char *)&abc);
	if (ret < 0) {
		errorf("ANDROID: Could not read from boot ctrl partition\n");
		fastboot_fail("Could not read from boot ctrl partition");
		return;
	}

	if (abc.slot_suffix[1] != *arg) {
		slot = abc.slot_suffix[1] - 'a';
		abc.slot_info[slot].priority = 14;
		abc.slot_info[slot].tries_remaining = 0;
		abc.slot_suffix[1] = *arg;
		slot = *arg - 'a';
		abc.slot_info[slot].priority = 15;
		abc.slot_info[slot].tries_remaining = 6;

		abc.crc32_le = crc32(0, (void *)&abc, offsetof(typeof(abc), crc32_le));
		ret = common_raw_write("misc", (u64)abc_size, 0, (u64)abc_offset, (char *)&abc);
		if(ret) {
			errorf("ANDROID: Could not write to boot ctrl partition\n");
			fastboot_fail("Could not write from boot ctrl partition");
			return;
		}
	}

	fastboot_okay("");
	//20220607, Added by zhu_jun for fix the issue that cannot erase userdata after switch slot by devicekit begin
	//usb_driver_exit();
	//20220607, Added by zhu_jun for fix the issue that cannot erase userdata after switch slot by devicekit end
	write_log_last();
	//20220607, Added by zhu_jun for donot reboot to normal mode by devicekit begin
	//reboot_devices(CMD_NORMAL_MODE);
	//20220607, Added by zhu_jun for donot reboot to normal mode by devicekit end
	return;
}


//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
void fb_cmd_upload(const char *arg, void *data, uint64_t sz)
{
	int i;
	char upload_ack[10] = {0};

	sprintf(upload_ack,"0x%x",upload_len);

	fastboot_ack("DATA", upload_ack);


	/*for(i = 0; i < upload_len; i++)
	      printf("%x",upload_buf[i]);
	debugf("\n");*/

	fb_usb_write(upload_buf, upload_len);

	fastboot_state = STATE_COMMAND;
	fastboot_okay("");
	fastboot_state = STATE_COMPLETE;
}
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end

//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
void fb_get_permission_download(const char *arg) {
	unsigned char msg[256] = {0};
	int ret = -1;
	char response[64] = {0};
	memcpy(msg,arg,256);
	ret = hmd_download_authentication(msg, DECRYPT);
	if (ret == AUTH_SUCCESS) {
		fastboot_okay("");
		mdelay(500);
		usb_driver_exit();
		mdelay(500);
		reboot_devices(CMD_AUTODLOADER_REBOOT);
		while(1);
	} else {
		sprintf(response,"download permission auth failed, ret:%d.",ret);
		wt_fastboot_info(response);
		fastboot_fail("failed to download permission auth");
	}
}
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end

void fb_cmd_oem_permission(const char *arg, void *data, uint64_t sz)
{
	int i,cnt;
	int ret = 0;
	char flag = 0;
	char subcmd[64];
	const char *delim = " ";
	char response[64] = {0};
	unsigned char *data_buf = ImageInfo.base_address;
	struct mode_key_table table[] = {
		{ (char *)"flash", MODE_FASTBOOT_FLASH   },
		{ (char *)"repair", MODE_FASTBOOT_REPAIR  },
		{ (char *)"simlock", MODE_FASTBOOT_SIMLOCK },
        //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
		{ (char *)"factory", MODE_FASTBOOT_FACTORY },
		//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
		//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
		{ (char *)"download", MODE_FASTBOOT_DOWNLOAD },
		//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end
	};

	memset(subcmd, 0, sizeof(subcmd));
	strcpy(subcmd, strtok(arg, delim));

	//20220723, Added by zhu_jun for skip SoC Download Mode Auth for ATO version begin
	#ifdef WT_COMPILE_FACTORY_VERSION
	if(!strcmp("download", (char *)subcmd)){
	    //20220923, Add zhu_jun for VSI-681 store the download auth data for ATO version begin
		memset(hmd_download_buf, 0x0, sizeof(hmd_download_buf));
		hmd_download_size = ImageInfo.data_size;
		memcpy(hmd_download_buf,ImageInfo.base_address,hmd_download_size);
		ret = oem_repair_write_mmc_ex("download",hmd_download_buf);
		if(!ret) {
			fastboot_okay("flash download.bin sucessfully\n");
		} else {
			fastboot_fail("flash download.bin failed\n");
		}
		//20220923, Add zhu_jun for VSI-681 store the download auth data for ATO version end
		
		strcpy(response,"switch to download mode successful.");
	    wt_fastboot_info(response);
		
		mdelay(500);
		usb_driver_exit();
		mdelay(500);
		
		reboot_devices(CMD_AUTODLOADER_REBOOT);
	}
	#endif
	//20220723, Added by zhu_jun for skip SoC Download Mode Auth for ATO version end
	
	//added by dongming, AGT-685, store repair signature data in memory, 20221011
	if(!strcmp("repair", (char *)subcmd)){
		memset(s_repair_signature, 0x0, sizeof(s_repair_signature));
		s_repair_signature_realsize = ImageInfo.data_size;
		memcpy(s_repair_signature,ImageInfo.base_address,s_repair_signature_realsize);
	}
	//end added, AGT-685

	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
	if((!check_efused()) && (!strcmp("download", (char *)subcmd))){
		mdelay(500);
		usb_driver_exit();
		mdelay(500);
		reboot_devices(CMD_AUTODLOADER_REBOOT);
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end

	cnt = sizeof(table) / sizeof(table[0]);
	for(i = 0; i < cnt ; i++)
	{
		strcpy(product_sn_token, get_product_sn());
		if(!strcmp((char *)subcmd, table[i].mode)){
			ret = rsa_decrypt_data(table[i].mode, data_buf, product_sn_token);
			if(ret == 0){
				sprintf(response,"%s decrypt failed",table[i].mode);
				fastboot_fail(response);
				return;
			}else{
				flag = 1;
				break;
			}
		}
	}
	if(flag == 0)
	{
		fastboot_fail("");
		return;
	}
	if (i >= cnt) {
	  return;
	}

	sprintf(response,"switch to %s mode successful.",table[i].mode);
	wt_fastboot_info(response);

	fastboot_mode_flag = table[i].mode_flag;
	fastboot_okay("");
	if(MODE_FASTBOOT_DOWNLOAD == fastboot_mode_flag) {
		//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
		memset(hmd_download_buf, 0x0, sizeof(hmd_download_buf));
		hmd_download_size = ImageInfo.data_size;
		memcpy(hmd_download_buf,ImageInfo.base_address,hmd_download_size);
		ret = oem_repair_write_mmc_ex("download",hmd_download_buf);
		if(!ret) {
			fastboot_okay("flash download.bin sucessfully\n");
		} else {
			fastboot_fail("flash download.bin failed\n");
		}
		//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end
		mdelay(500);
		usb_driver_exit();
		mdelay(500);
		reboot_devices(CMD_AUTODLOADER_REBOOT);
	}

}
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
static void imei_fastboot_publish_commands(void)
{
    char simslot_buf[16] = {0};
    unsigned int simslot_buf_len=0;

    memset(simslot_buf, 0x0, sizeof(simslot_buf));
    get_status_simslot(simslot_buf, &simslot_buf_len);

    //debugf("simslot_buf = %s .\r\n",simslot_buf);

    //if (!strcmp(simslot_buf, "single"))
    if (!strncmp(simslot_buf, "single", sizeof("single"))) {
        fastboot_publish("IMEI0", strdup(get_product_imei1()));
    } else if (!strncmp(simslot_buf, "dual", sizeof("dual"))) {
        fastboot_publish("IMEI0", strdup(get_product_imei1()));
        fastboot_publish("IMEI1", strdup(get_product_imei2()));
    }

}
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end

//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
void fb_cmd_reboot_edl(const char *arg, void *data, uint64_t sz)
{
#ifdef WT_FINAL_RELEASE
	unsigned char fastboot_reboot_edl[2] = {0};
	fastboot_reboot_edl[0] = 1;

	oem_repair_write_mmc_ex("fastboot_reboot_edl", fastboot_reboot_edl);
	
	//added by dongming, AGT-685, 20221011
	if ( check_efused() ) {
	    oem_repair_write_mmc_ex(HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE, s_repair_signature);
	}
	//end added by dongming, AGT-685
#endif

	fastboot_okay("");
	udelay(500);
	usb_driver_exit();

	reboot_devices(CMD_AUTODLOADER_REBOOT);
}
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end

static void fastboot_command_loop(void)
{
	struct fastboot_cmd *cmd;
	int r;
	char *ptr = NULL;
	debugf("fastboot: processing commands\n");

again:
	while (fastboot_state != STATE_ERROR) {
		memset(buffer, 0, 64);
		r = fb_usb_read(buffer, 64);
		if (r < 0) {
			if (-ESHUTDOWN ==  r) {
				/* disconnect usb  */
				debugf("fastboot exit\r\n");
				usb_fastboot_exit();
			}
			break;
		}
		buffer[r] = 0;
		debugf("fastboot: %s, r:%d\n", buffer, r);

		for (cmd = cmdlist; cmd; cmd = cmd->next) {
			write_log();
			debugf("cmd->prefix: %s, cmd->prefix_len:%d\n", cmd->prefix, cmd->prefix_len);
			if (memcmp(buffer, cmd->prefix, cmd->prefix_len))
				continue;
			debugf("Receive cmd from host :%s \n", cmd->prefix);

#ifdef CONFIG_WR_SPARSE
#define PART_NAME	"is-logical"
#define PART_NAME_LEN strlen(PART_NAME)
#define PART_TYPE	"partition-type"
#define PART_TYPE_LEN	strlen(PART_TYPE)
			ptr = strstr(buffer, PART_NAME);
			if (ptr && (ptr[PART_NAME_LEN] == ':')) {
				ptr += PART_NAME_LEN + 1;
				if (ptr[0] != '\0') {
					strncpy(ImageInfo.part_name, ptr, PARTNAME_SZ - 1);
					printf("====== get is-logical [%s] ==== \n", ImageInfo.part_name);
				}
			} else if ((ptr = strstr(buffer, PART_TYPE)) != NULL) {
				/* try partition-type */
				if (ptr[PART_TYPE_LEN] == ':') {
					ptr += PART_TYPE_LEN + 1;
					if (ptr[0] != '\0') {
						strncpy(ImageInfo.part_name, ptr, PARTNAME_SZ - 1);
						printf("====== get partition-type [%s] ==== \n", ImageInfo.part_name);
					}
				}
			}
#endif
			fastboot_state = STATE_COMMAND;
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
			if( !fastboot_mode_cmd_filter(cmd, buffer) ) {
				cmd->handle((const char *)buffer + cmd->prefix_len, ImageInfo.base_address, ImageInfo.data_size);
            } else{
				fastboot_fail("permission denied, auth needed.");
            }
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end
			if (fastboot_state == STATE_COMMAND)
				fastboot_fail("unknown reason");
			goto again;
		}

		fastboot_fail("unknown command");

	}
	fastboot_state = STATE_OFFLINE;
	debugf("fastboot: oops!\n");
	debugf("wait usb cable connect\n");
	/* wait usb connected  */
	while (fastboot_state == STATE_OFFLINE) {
		if (fastboot_charger_connected()) {
			debugf("fastboot re-init\r\n");
			r = usb_fastboot_init();
			if (r < 0) {
				debugf("usb re-init err\r\n");
				usb_fastboot_exit();
			}
			goto again;
		}
	}
	write_log();
}

static int fastboot_handler(void *arg)
{
	for (;;) {
		fastboot_command_loop();
	}
	return 0;
}

int do_fastboot(void)
{
	char max_download_size[64];
	int ret = 0;
	debugf("start fastboot\n");

#ifdef CONFIG_SECBOOT
	/*Initialize product_sn_token to 0 */
	memset(product_sn_token, 0, PRODUCT_SN_TOKEN_MAX_SIZE);
#endif

	ret = usb_fastboot_init();
	if (ret < 0)
		return ret;

#ifdef CONFIG_DTS_MEM_LAYOUT
	ret = set_fastboot_buf_base_size();
	if (ret < 0)
		return ret;
#endif

	ImageInfo.base_address = g_FbBuf;

#ifdef CONFIG_DTS_MEM_LAYOUT
	ImageInfo.max_size = g_FbBuf_size;
#else
	/*except the u-boot occupied area , all RAM can be used as fastboot buffer */
	ImageInfo.max_size = (uint64_t) (CONFIG_SYS_TEXT_BASE - (uint64_t)g_FbBuf);
#endif
#ifdef CONFIG_DTS_MEM_LAYOUT
	ImageInfo.max_size = g_FbBuf_size;
#endif
	sprintf(max_download_size, "0x%llx", ImageInfo.max_size);
	ImageInfo.data_size = 0;

#ifdef CONFIG_WR_SPARSE
	ImageInfo.max_size_raw = ImageInfo.max_size;
	wr_sparse_prepare(ImageInfo.base_address, &ImageInfo.max_size);
	sprintf(max_download_size, "0x%llx", ImageInfo.max_size);
#endif

	fastboot_register("getvar:", fb_cmd_getvar);
	/*when you input cmd"flash" in host, we will rcv cmd"download" first,then the "flash",
	   so even if we can't see cmd"download" in host fastboot cmd list,it is also used */
	fastboot_register("download:", fb_cmd_download);
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
        fastboot_register("upload", fb_cmd_upload);
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
	fastboot_publish("version", "1.0");
	/* Add new command for AndroidQ */
	fastboot_publish("is-userspace", "no");
	fastboot_publish("max-download-size", max_download_size);
	fastboot_register("flash:", fb_cmd_flash);
	fastboot_register("erase:", fb_cmd_erase);
	fastboot_register("boot", fb_cmd_continue);
	fastboot_register("reboot", fb_cmd_reboot);
	fastboot_register("powerdown", fb_cmd_powerdown);
	fastboot_register("continue", fb_cmd_continue);
	fastboot_register("reboot-bootloader", fb_cmd_reboot_bootloader);
	fastboot_register("reboot-fastboot", fb_cmd_reboot_userspace_fastboot);
	//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
	//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
	fastboot_register("reboot-emergency", fb_cmd_reboot_edl);
	//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end
	fastboot_publish("product", "AGT");
	fastboot_publish("unlocked", get_lock_status() ? "yes":"no");
	//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end
	//20220602,Added by zhu_jun for suport fastboot command:fastboot getvar boardid begin
	fastboot_publish("boardid", target_get_boardname());
	//20220602,Added by zhu_jun for suport fastboot command:fastboot getvar boardid end

	//20220614, Added by zhu_jun for disable enter recovery via fastboot reboot recovery on MP&User build begin
	#ifdef USER_BUILD
		if(wt_check_mp_flags()){
			fastboot_register("reboot-recovery", fb_cmd_reboot);
		}else{
			fastboot_register("reboot-recovery", fb_cmd_reboot_recovery);
		}
	#else
		fastboot_register("reboot-recovery", fb_cmd_reboot_recovery);
	#endif
	//20220614, Added by zhu_jun for disable enter recovery via fastboot reboot recovery on MP&User build begin
	fastboot_register("set_active:", fb_cmd_set_active);

	//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
	imei_fastboot_publish_commands();
	//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
	/* Add new command for Unisoc Sysdump */
#ifdef CONFIG_FASTBOOT_SECURITY_DOWNLOAD
	fastboot_register("reboot-emergency", fb_cmd_reboot_edl);
	fastboot_register("upload", fb_cmd_upload);
#endif
	/* Add new command for Unisoc Sysdump */
	fastboot_register("setdump", fb_cmd_setdump);
	fastboot_register("getdump", fb_cmd_getdump);
#ifndef CONFIG_SECBOOT
	fastboot_register("oem", fb_cmd_oem);
#else
	fastboot_register("flashing", fb_cmd_flashing);
	fastboot_register("oem", fb_cmd_oem);
	/*add fastboot cmd for sharkl2*/
	fastboot_register("getlcs", fb_cmd_getlcs);
	fastboot_register("setrma", fb_cmd_setrma);
	fastboot_register("getsocid", fb_cmd_getsocid);
    fastboot_lcs_init();
    fastboot_token_init();
    fastboot_socid_init();
#endif

//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
	oem_fastboot_register_commands();
//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
	fastboot_handler(0);

	return 0;

}


