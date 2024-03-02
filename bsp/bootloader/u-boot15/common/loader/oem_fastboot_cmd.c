#include "oem_fastboot_cmd.h"
#include <common.h>
#include <malloc.h>
#include <android_bootimg.h>
#include <boot_mode.h>
#include <dl_common.h>
#include "sparse_format.h"
#include <linux/usb/usb_uboot.h>
#include <sprd_common_rw.h>
#include <secureboot/sec_common.h>
#include "miscdata_def.h"
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
#include "protect_data_def.h"
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo begin
#include "sprd_cpcmdline.h"
//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo end

//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
#include <crypto/authentication.h>
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end

typedef void (*fastboot_cmd_fn)(const char *, void *, unsigned);
struct fastboot_cmd_desc {
	char * name;
	fastboot_cmd_fn cb;
};

#define EXPAND(NAME) #NAME
#define TARGET(NAME) EXPAND(NAME)


#define MAX_RSP_SIZE            128

//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo begin
extern int POWP_flag;
extern int hardware_level;
extern int sprd_get_imgversion(int imgType, unsigned int* swVersion);
extern int check_efused(void);
extern int get_lock_status(void);
extern char *get_product_imei1(void);
extern char *get_product_imei2(void);
//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo end
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
extern unsigned char auth_data[AUTH_DATA_LEN + 1];
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
extern void fb_cmd_oem_permission(const char *arg, void *data, uint64_t sz);
extern int rsa_encrypt_data(unsigned char *send_data);
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN begin
extern void fastboot_enter_cali_mode(u8 cail_mode, u8 cail_freq);
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN end
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
enum rsa_encrypt_mode{
	RSA_ENCRYPT_HMD = 0,
	RSA_ENCRYPT_FACTORY,
	RSA_ENCRYPT_DOWNLOAD,
	RSA_ENCRYPT_ALL,
};

int rsa_encrypt_data_flag = RSA_ENCRYPT_HMD;
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin

//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
extern char upload_buf[UPLOADE_SIZE];
extern unsigned int upload_len;


//20220610,Added by zhu_jun for update the official sw public key begin
	char sw_pub_key[SW_PUB_KEY_LEN+1] =
"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAqGNTJb7acu/UxERUNbZX\
rQFx0sKC67CHYk/w7pdVdidao05DI76VZ3nrCfdayFqXWTEjGZRRsXRua7GhVWw1\
vfy/IAFHNhrA9ODVSgOcaNeGPZOCjJGpZJ5uwO8Yh/N7yRQnJ6wKiqRX1AePnhuT\
URB7BfTGzrUxHE2KJFKyI0XyErHPf0mGTsebFT0uh8EVMQ+kFB+dhSOuJCZsQ9vQ\
Q/XmVt3Am7X/241pxhW034AUWrDzPZtPYRF6SBJ28MrLkogzqQA8uyc3BNgqMgvw\
PgtfqdOmvnemCXdEbijgK/xZDPWJqBf082xRQG/frfq7Tad5fBA9fG8wj8GWDdDM\
MQIDAQAB";
//20220610,Added by zhu_jun for update the official sw public key end

//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end

struct mode_key_table {
	char *mode;
	unsigned char *key;
	int key_len;
	int mode_flag;
};

int fastboot_mode_flag = MODE_FASTBOOT_BASIC;
char text_verify[48];
extern char sn_buf[];
int mode_flag = 0;


char * strtok_r(char *s, const char *delim, char **last)
{
    char *spanp;
    int c, sc;
    char *tok;
    if (s == NULL && (s = *last) == NULL)
        return (NULL);
        /*
        * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
        */
cont:
    c = *s++;
    for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
        if (c == sc)
            goto cont;
    }
    if (c == 0) { /* no non-delimiter characters */
        *last = NULL;
        return (NULL);
    }
    tok = s - 1;
    /*
    * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
    * Note that delim must have one NUL; we stop if we see that, too.
    */
    for (;;) {
        c = *s++;
        spanp = (char *)delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                   s[-1] = 0;
                *last = s;
                return (tok);
             }
        } while (sc != 0);
    }
}

void cmd_oem_getsecurityversion(const char *arg, void *data, unsigned size) {
        //now it is 101-version for adapting HMD flash tool
        wt_fastboot_info("113");
        fastboot_okay("");
}

void cmd_oem_getdllname(const char *arg, void *data, unsigned size) {
	/*the value of return refer to our tool lib*/
        wt_fastboot_info("dllname=HmdLibrary_AGT:oem enter_calibration");
	fastboot_okay("");
}

//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
void cmd_oem_auth_start(const char *arg, void *data, unsigned size) {
	int ret = -1;

	rsa_encrypt_data_flag = RSA_ENCRYPT_HMD;
	//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
	memset(upload_buf,0,sizeof(upload_buf));
	ret = rsa_encrypt_data(upload_buf);
	if(ret == 0){
		upload_len = AUTH_DATA_LEN;
	//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end
		fastboot_okay("");
	}else
		fastboot_fail("rsa encrypt failed");

	return;
}

void cmd_oem_factory_auth_start(const char *arg, void *data, unsigned size) {

	int ret = -1;

	rsa_encrypt_data_flag = RSA_ENCRYPT_FACTORY;
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
	memset(upload_buf,0,sizeof(upload_buf));
	ret = rsa_encrypt_data(upload_buf);
	if(ret == 0){
		upload_len = AUTH_DATA_LEN;
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end
		fastboot_okay("");
	}
	else
		fastboot_fail("factory rsa encrypt failed");

	return;
}
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN begin
static void cmd_oem_enter_calibration(const char *arg, void *data, unsigned size)
{
	/*calibration default para is: 1,0,146*/
	unsigned char cail_mode = 1;
	unsigned char cail_freq = 0;
	char *tok;
	const char *delim = " ";

	tok = strtok(NULL, delim);
	if (tok) {
		cail_mode = (unsigned char)simple_strtoul(tok, NULL, 10);
	}

	tok = strtok(NULL, delim);
	if (tok) {
		cail_freq = (unsigned char)simple_strtoul(tok, NULL, 10);
	}

	debugf("cail_mode=%d, cail_freq=%d\n", cail_mode, cail_freq);

	fastboot_enter_cali_mode(cail_mode, cail_freq);

	fastboot_okay("");

	lcd_clear();
	lcd_splash("logo");

	calibration_mode();
}
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN end

//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo begin
void cmd_oem_get_devinfo(const char *arg, void *data, uint64_t sz)
{
	int ret, status;
	char info[256] = "";
	int str_len;
	char tembuf[128] = {0};
	char simslot_buf[16] = {0};
	unsigned int simslot_buf_len=0;
	int hardware_level = sprd_get_hardwareid_info();

	wt_fastboot_info("");
	wt_fastboot_info("{");

	memset(info, 0x0,sizeof(info));
	memset(tembuf, 0x0,sizeof(tembuf));

	if(hardware_level < 1){
		ret = common_raw_read("miscdata", (uint64_t )MISCDATA_SKUID_LEN, (uint64_t)MISCDATA_SKUID_ADDR, tembuf);
	}
	else {
		ret = common_raw_read("protect_data", (uint64_t )SKUID_LEN, (uint64_t)SKUID_OFFSET, tembuf);
	}

	if(0 != ret)
		debugf("%s:%d common raw read return%d\r\n",__func__, __LINE__, ret);
	sprintf(info, "\"SKUID\"\: \"%s\",", tembuf);

	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"Project\"\: \"%s\",", "AGT");
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"Product\"\: \"%s\",", DEVINFO_PRODUCT);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"Version\"\: \"%s\",", DEVINFO_VERSION);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	memset(tembuf, 0x0,sizeof(tembuf));
	ret = common_raw_read("protect_data", (uint64_t )TA_Code_LEN, (uint64_t)TA_Code_OFFSET, tembuf);
	if(0 != ret)
		debugf("%s:%d common raw read return%d\r\n",__func__, __LINE__, ret);
	sprintf(info, "\"ProductTAcode\"\: \"%s\",", tembuf);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"ProductModel\"\: \"%s\",", DEVINFO_MODEL);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"AntiRollback_HW\"\: \"%s\",", ANTIROLLBACK_HW);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"AntiRollback_vbmeta\"\: \"%s\",", ANTIROLLBACK_VBMETA);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"AntiRollback_vbmeta_system\"\: \"%s\",", ANTIROLLBACK_VBMETA_SYSTEM);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

	memset(simslot_buf, 0x0, sizeof(simslot_buf));
	get_status_simslot(simslot_buf,&simslot_buf_len);
	if (!strncmp(simslot_buf,"single", sizeof("single"))){
		memset(info, 0x0, sizeof(info));
		memset(tembuf, 0x0, sizeof(tembuf));
		ret = common_raw_read("protect_data", (uint64_t )WT_IMEI1_LEN, (uint64_t )WT_IMEI1_OFFSET, tembuf);

		if(0 != ret)
			debugf("%s:%d common raw read return%d\r\n",__func__, __LINE__, ret);
		sprintf(info, "\"IMEI0\"\: \"%s\",", get_product_imei1());
		str_len = strlen(info);
		info[str_len] = '\0';
		wt_fastboot_info(info);
	}
	else if (!strncmp(simslot_buf,"dual", sizeof("dual"))){
		memset(info, 0x0,sizeof(info));
		memset(tembuf, 0x0, sizeof(tembuf));
		ret = common_raw_read("protect_data", (uint64_t )WT_IMEI1_LEN, (uint64_t )WT_IMEI1_OFFSET, tembuf);

		if(0 != ret)
			debugf("%s:%d common raw read return%d\r\n",__func__, __LINE__, ret);
		sprintf(info, "\"IMEI0\"\: \"%s\",", get_product_imei1());
		str_len = strlen(info);
		info[str_len] = '\0';
		wt_fastboot_info(info);

		memset(info, 0x0,sizeof(info));
		memset(tembuf, 0x0, sizeof(tembuf));
		ret = common_raw_read("protect_data", (uint64_t )WT_IMEI2_LEN, (uint64_t )WT_IMEI2_OFFSET, tembuf);

		if(0 != ret)
			debugf("%s:%d common raw read return%d\r\n",__func__, __LINE__, ret);
		sprintf(info, "\"IMEI1\"\: \"%s\",", get_product_imei2());
		str_len = strlen(info);
		info[str_len] = '\0';
		wt_fastboot_info(info);
	}

	memset(info, 0x0,sizeof(info));
	sprintf(info, "\"POWP\"\: \"%d\",", POWP_flag);
	str_len = strlen(info);
	info[str_len] = '\0';
	wt_fastboot_info(info);

#if defined(DEBUG) || defined(USER_BUILD)
    memset(info, 0x0,sizeof(info));
    sprintf(info, "\"SU\"\: \"%s\",", "0");
    str_len = strlen(info);
    info[str_len] = '\0';
    wt_fastboot_info(info);
#else
    memset(info, 0x0,sizeof(info));
    sprintf(info, "\"SU\"\: \"%s\",", "1");
    str_len = strlen(info);
    info[str_len] = '\0';
    wt_fastboot_info(info);
#endif

    memset(info, 0x0,sizeof(info));
    sprintf(info, "\"Locked\"\: \"%d\",",  (get_lock_status() == VBOOT_STATUS_UNLOCK ? 0 : 1));
    str_len = strlen(info);
    info[str_len] = '\0';
    wt_fastboot_info(info);

    memset(info, 0x0,sizeof(info));
    sprintf(info, "\"Secure\"\: \"%d\",", check_efused());
    str_len = strlen(info);
    info[str_len] = '\0';
    wt_fastboot_info(info);

    wt_fastboot_info("}");
    fastboot_okay("");
}
//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo end

void show_oem_repair_usage() {
    wt_fastboot_info("Usages:fastboot oem repair [psn|imei1|imei2|meid|meid2|wallpapered|skuid|wifiaddr|btaddr] [set|get]");
    wt_fastboot_info("Example:fastboot oem repair wallpapered set 0x1");
    wt_fastboot_info("Example:fastboot oem repair wallpapered get");
    fastboot_fail("error command");
}

void show_oem_repair_response(const char *type,unsigned char *value)
{
	char response[MAX_RSP_SIZE] = {};
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
	if(!strcmp(type, "hef")){
		snprintf(response, sizeof(response), "%s=%d", type, value[0]);
	}else{
        snprintf(response, sizeof(response), "%s=%s", type, value);
	}
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
        wt_fastboot_info(response);
}

//20220601,Added by zhu_jun for suport fastboot command:fastboot oem repair skuid get begin
int oem_repair_handle(const char *op,const char *type,unsigned char *value)
{
	int ret = -1;
	int hardware_level = sprd_get_hardwareid_info();

	if(!strcmp(op, "set")){
		if(!strcmp(type, "skuid") || !strcmp(type, "sku") ||
		!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
			if(hardware_level < 1){
				ret = oem_repair_write_mmc_ex(type,value);
			}else{
				ret = write_protect_data_ex(type,value);
			}
		}else{
			ret = write_protect_data_ex(type,value);
		}
	}else if(!strcmp(op, "get")){
		if(!strcmp(type, "skuid") || !strcmp(type, "sku") ||
		!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
			if(hardware_level < 1){
				ret = oem_repair_read_mmc_ex(type,value,READ_MMC_LEN_AUTO);
			}else{
				ret = read_protect_data_ex(type,value,READ_Protect_data_LEN_AUTO);
			}
		}else{
			ret = read_protect_data_ex(type,value,READ_Protect_data_LEN_AUTO);
		}
	}
	return ret;
}
//20220601,Added by zhu_jun for suport fastboot command:fastboot oem repair skuid get end

void cmd_oem_repair(const char *arg, void *data, unsigned size) {
    debugf("oem reapir [%s]\n", arg);
    if(!arg) {
        show_oem_repair_usage();
        return;
    }
    int len = strlen(arg);
    char args[len + 1];
    char *delim = " ";
    char *sp = NULL;
    char *type = NULL;
    char *op = NULL;
    char value_buf[64] = {};
    char *value = value_buf;
    strncpy(args, arg, len);
    args[len] = '\0';  // don't remove this or will case error
    debugf("args [%s]\n", args);
    type = strtok_r(args, delim, &sp);
    if (!type){
        show_oem_repair_usage();
        return;
    }
    debugf("oem repair type is %s\n", type);
    op = strtok_r(NULL, delim, &sp);
    if (!op){
        show_oem_repair_usage();
        return;
    }
    debugf("oem repair operation is %s\n", op);
    if(!strcmp(op, "set")){
        value = strtok_r(NULL, delim, &sp);
        if (value == NULL) {
            show_oem_repair_usage();
            return;
        }
        debugf("oem repair set value is [%s]\n", value);
        show_oem_repair_response(type, value);

        if(!oem_repair_handle(op,type,value)) {
            fastboot_okay("");
        }else{
            fastboot_fail("oem repair set failed");
        }
    }else if(!strcmp(op, "get")){

        if(!oem_repair_handle(op,type,value)) {
            show_oem_repair_response(type,value);
            fastboot_okay("");
        }else{
            fastboot_fail("oem repair get failed");
        }
    } else {
        debugf("oem repair unsupport command");
        fastboot_fail("unsupport command");
    }
}

//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
void cmd_oem_hef(const char *arg, void *data, unsigned size) {
    int len = strlen(arg);
    char args[len + 1];
    char *delim = " ";
    char *sp = NULL;
    char *op = NULL;
	char read_buf[64];
	int str_len;
	char info[256] = "";
	memset(read_buf, 0, 64);
    strncpy(args, arg, len);
    args[len] = '\0';  // don't remove this or will case error
    op = strtok_r(args, delim, &sp);
	
    if(MODE_FASTBOOT_REPAIR != fastboot_mode_flag && strcmp("get",op)) {
	    fastboot_fail("permission denied, repair needed.");
	    return;
    }

    if(!strcmp(op, "0")){
        if (0 == write_protect_data_ex("hef", op)) {
		    wt_fastboot_info("set 0 success to hef");
		    fastboot_okay("");
		} else {
		    wt_fastboot_info("set 0 fail to hef");
		    fastboot_fail("Write protect data fail!");
		}
    } else if(!strcmp(op, "1")){
		if ( 0 == write_protect_data_ex("hef", op)) {
		    wt_fastboot_info("set 1 success to hef");
		    fastboot_okay("");
		} else {
		    wt_fastboot_info("set 1 fail to hef");
		    fastboot_fail("Write protect data fail!");
		}
    } else if(!strcmp(op, "get")){
		read_protect_data_ex("hef", read_buf, HEF_LEN);
		sprintf(info, "get hef: %d", read_buf[0]);
		str_len = strlen(info);
		info[str_len] = '\0';
		wt_fastboot_info(info);
		fastboot_okay("");
    } else {
        debugf("oem off_mode_charge unsupport command");
        fastboot_fail("unsupport command");
    }
}
//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin

static int equalsymbols(char *s, int len)
{
    int cnt = 0;

    while (s[--len] == '=' && len > 0)
        cnt++;

    return cnt;
}


static void cmd_oem_permission(const char *arg, void *data, unsigned size)
{

	fb_cmd_oem_permission(arg,data,size);

	fastboot_okay("");
}

//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
void cmd_oem_zeroflag(const char *arg, void *data, unsigned size) {
	char subcmd[64];
	const char *delim = " ";
	int ret = -1;

	memset(subcmd, 0, sizeof(subcmd));
	strcpy(subcmd, strtok(arg, delim));

	if(!strcmp(subcmd, "set")){
		ret = set_zeroflag(0x55);
		wt_fastboot_info("set success");
	}else if(!strcmp(subcmd, "clr")){
		ret = set_zeroflag(0x22);
		wt_fastboot_info("clr success");
	}

	fastboot_okay("");
}

#if 0
void cmd_get_zeroflag(const char *arg, void *data, unsigned size) {
	unsigned char zeroflag = 0;
	char test[10] = {};
	int ret;

	ret = get_zeroflag(&zeroflag);

	sprintf(test,"0x%x",zeroflag);
	wt_fastboot_info(test);
	fastboot_okay("");
}
#endif
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end

//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
void cmd_oem_sw_pub_key(const char *arg, void *data, unsigned size)
{
	int i;

	upload_len = SW_PUB_KEY_LEN;
	memset(upload_buf,0,sizeof(upload_buf));

	for(i = 0; i < upload_len; i++)
	      upload_buf[i] = sw_pub_key[i];

	fastboot_okay("");
}
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end

void cmd_oem_getpermissions(const char *arg, void *data, unsigned size) {
	switch (fastboot_mode_flag) {
		case MODE_FASTBOOT_BASIC:
			wt_fastboot_info("permission=None");
			break;
		case MODE_FASTBOOT_FLASH:
			wt_fastboot_info("permission=flash");
			break;
		case MODE_FASTBOOT_REPAIR:
			wt_fastboot_info("permission=flash | repair");
			break;
		case MODE_FASTBOOT_SIMLOCK:
			wt_fastboot_info("permission=flash | simlock");
			break;
        //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
		case MODE_FASTBOOT_FACTORY:
			wt_fastboot_info("permission=factory");
			break;
       //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
		//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
		case MODE_FASTBOOT_DOWNLOAD:
			wt_fastboot_info("permission=download");
			break;
		//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end
		default:
			fastboot_fail("mode error!!!");
			return;
	}
	fastboot_okay("");
}

//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
void cmd_oem_powp_wt_enable(const char *arg, void *data, unsigned size)
{
	int ret = -1;
	char powp_enable[WT_POWP_LEN] = {0};

	ret = oem_repair_write_mmc_ex("powp",powp_enable);
	if(ret){
		fastboot_fail("clear powp bin fail");
	}

	fastboot_okay("");
}
void cmd_oem_powp_enable(const char *arg, void *data, unsigned size)
{
	int ret = -1;
	char powp_enable[WT_POWP_LEN] = {0};

	ret = oem_repair_write_mmc_ex("powp",powp_enable);
	if(ret){
		fastboot_fail("clear powp bin fail");
	}

	fastboot_okay("");

	usb_driver_exit();
	reboot_devices(CMD_FASTBOOT_MODE);
}
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end

//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
#ifdef WT_OEM_TEST
void cmd_oem_test(const char *arg, void *data, unsigned size)
{
	//Get reapir permission.
	//This command only can be use before MP stage.

	fastboot_mode_flag = MODE_FASTBOOT_REPAIR;
	wt_fastboot_info("permission=flash | repair");

	fastboot_okay("");
}
#endif
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

//20220704,Added by zhu_jun for VSI-679 suport fastboot command:fastboot oem cali_disable begin
void cmd_oem_cali_disable(const char *arg, void *data, unsigned size)
{
	if (common_raw_erase("miscdata", HMD_CALI_MODE_SIGNATURE_LEN + WT_FACTORY_SN_DATA_LEN, HMD_CALI_MODE_SIGNATURE_OFFSET)) {
		fastboot_fail("cali_disable failed");
	} else {
		mdelay(500);
		fastboot_okay("");
		/* the last time to write log before reboot */
		reboot_devices(CMD_FASTBOOT_MODE);
	}
}
//20220704,Added by zhu_jun for VSI-679 suport fastboot command:fastboot oem cali_disable end

//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin

int is_need_hmd_download_auth(void)
{
	int efused = -1;
	u8 zeroflag;
	efused = check_efused();
	get_zeroflag(&zeroflag);
	if( 1 == efused && 0x22 == zeroflag )
		return 1;
	return 0;
}

void cmd_oem_download_auth_start(const char *arg, void *data, unsigned size)
{
	int ret = -1;
	if(!is_need_hmd_download_auth()){
		fastboot_fail("The phone is not efuse machine and not in factory, don not download auth");
		return;
	}

	rsa_encrypt_data_flag = RSA_ENCRYPT_DOWNLOAD;
	memset(upload_buf,0,sizeof(upload_buf));
	ret = rsa_encrypt_data(upload_buf);
	if( 0 == ret ){
		upload_len = AUTH_DATA_LEN;
		fastboot_okay("download auth sucessfully.");
	} else {

		fastboot_fail("download auth failed, ret:%d", ret);
	}

	return;
}

//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end

void oem_fastboot_register_commands(void) {
	int i;
	struct fastboot_cmd_desc cmd_list[] = {

		{ "oem getsecurityversion", cmd_oem_getsecurityversion },
		{ "oem getdllname", cmd_oem_getdllname },
		{ "oem auth_start", cmd_oem_auth_start },
		{ "oem permission",cmd_oem_permission },
		{ "oem getpermissions",cmd_oem_getpermissions },
		{ "oem repair", cmd_oem_repair },
		//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
		{ "oem hef", cmd_oem_hef },
		//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end
		//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo begin
		{ "oem get_devinfo", cmd_oem_get_devinfo },
		//20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo end
		//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
		{ "oem sw_pub_key", cmd_oem_sw_pub_key },
		//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end
		//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
		{ "oem powp_enable", cmd_oem_powp_enable },
		{ "oem powp_wt_enable", cmd_oem_powp_wt_enable },
		//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end

        //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
		{ "oem factory_auth_start", cmd_oem_factory_auth_start },
		{ "oem zeroflag", cmd_oem_zeroflag },
        //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN begin
		{ "oem enter_calibration", cmd_oem_enter_calibration },
//20220525 Added by zhu_jun for [HMD Flash Tool]devicekit editphone info to read SN end
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
#ifdef WT_OEM_TEST
		{ "oem test", cmd_oem_test },
#endif
//20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

		//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
		{ "oem download_auth_start", cmd_oem_download_auth_start },
		//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end
		//20220704,Added by zhu_jun for VSI-679 suport fastboot command:fastboot oem cali_disable begin
		{ "oem cali_disable", cmd_oem_cali_disable },
		//20220704,Added by zhu_jun for VSI-679 suport fastboot command:fastboot oem cali_disable end
	};

	int cmds_cnt = sizeof(cmd_list) / sizeof(cmd_list[0]);
	for (i = 0; i < cmds_cnt; i++) {
		fastboot_register(cmd_list[i].name, cmd_list[i].cb);
	}
}






