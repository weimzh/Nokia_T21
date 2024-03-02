//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
#include <common.h>
#include <boot_mode.h>
#include <part_efi.h>
#include "loader_common.h"
#include <sprd_common_rw.h>
#include <miscdata_def.h>
//20220601,Added by zhu_jun for suport fastboot command:fastboot oem repair skuid get begin
extern int powp_size;
extern int atoi(const char *src);
//20220601,Added by zhu_jun for suport fastboot command:fastboot oem repair skuid get end

//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
#ifdef CONFIG_PCTOOL_AUTHORIZE_HMD
extern int hmd_cali_size;
#endif
//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end

//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
extern int hmd_download_size;
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end

//added by dongming, AGT-685, 20221011
extern int s_repair_signature_realsize;
//end added by dongming, AGT-685

int tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c + 'a' - 'A';
	}
	else
	{
		return c;
	}
}

int htoi(char s[])
{
	int i;
	int n = 0;

	for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z');++i)
	{
		if (tolower(s[i]) > '9')
		{
			n = 16 * n + (10 + tolower(s[i]) - 'a');
		}
		else
		{
			n = 16 * n + (tolower(s[i]) - '0');
		}
	}
	return n;
}

int oem_repair_read_mmc_ex(const char *type,unsigned char *buf,int len) {
	uint32_t ret = -1;
	uint64_t miscdata_address;
	uint64_t miscdata_len;
	char t_ch;

	char miscdata_buf[1024] = {0};

	debugf("oem repair read mmc get type %s\n", type);

	if((len > sizeof(miscdata_buf)) && ( len != READ_MMC_LEN_AUTO)) {
		errorf("oem_repair_read_mmc_ex read NV len error\n");
		return -1;

	}
    //20220531,Added by zhu_jun for Set ZeroFlag related property begin
	//20220607, Added by zhu_jun Block/unblock Device getting into fastboot and factory reset begin
	else if(!strcmp(type, "block_fastboot_mode") ) {
		miscdata_address = BLOCK_FASTBOOT_ADDR;
		miscdata_len = BLOCK_FASTBOOT_LEN;
	}
	else if(!strcmp(type, "block_factory_reset") ) {
		miscdata_address = BLOCK_FACTORY_RESET_ADDR;
		miscdata_len = BLOCK_FACTORY_RESET_LEN;
	}
	//20220607, Added by zhu_jun Block/unblock Device getting into fastboot and factory reset end
	else if(!strcmp(type, "zeroflag")) {
		miscdata_address = (CUSTOM_NV_BASE + WT_ZEROFLAG_OFFSET);
		miscdata_len = WT_ZEROFLAG_LEN;
	}
	//20220531,Added by zhu_jun for Set ZeroFlag related property end
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
	else if(!strcmp(type, "powp")) {
		miscdata_address = WT_POWP_OFFSET;
		miscdata_len = WT_POWP_LEN;
	}
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
	else if(!strcmp(type, "skuid") || !strcmp(type, "sku")) {
		miscdata_address = MISCDATA_SKUID_ADDR;
		miscdata_len = MISCDATA_SKUID_LEN;
	}
	else if (!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
		miscdata_address = MISCDATA_COLORID_ADDR;
		miscdata_len = MISCDATA_COLORID_LEN;
	}
	//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
	else if (!strcmp(type, "fastboot_reboot_edl")) {
		miscdata_address = MISCDATA_EDL_ADDR;
		miscdata_len = MISCDATA_EDL_LEN;
	}
	//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end
	else if(!strcmp(type, "cali")) {
		miscdata_address = HMD_CALI_MODE_SIGNATURE_OFFSET;
		miscdata_len = HMD_CALI_MODE_SIGNATURE_LEN;
	}
	else if (!strcmp(type, "factory_sn_data")) {
		miscdata_address = WT_FACTORY_SN_DATA_OFFSET;
		miscdata_len = WT_FACTORY_SN_DATA_LEN;
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
	else if(!strcmp(type, "download")) {
		miscdata_address = HMD_DOWNLOAD_MODE_SIGNATURE_OFFSET;
		miscdata_len = HMD_DOWNLOAD_MODE_SIGNATURE_LEN;
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end
	//added by dongming, AGT-685, 20221011
	else if (!strcmp(type, HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE)) {
		miscdata_address = HMD_EDL_MODE_SIGNATURE_OFFSET;
		miscdata_len = HMD_EDL_MODE_SIGNATURE_LEN;
	}
	//end added by dongming, AGT-685
	//added by dongming, for miscdata india flag, 20221018
	else if (!strcmp(type, MISCDATA_INDIA_FLAG_TYPE)) {
		miscdata_address = MISCDATA_INDIA_FLAG_ADDR;
		miscdata_len = MISCDATA_INDIA_FLAG_LEN;
	}
	//end added by dongming, for miscdata india flag, 20221018
	else {
		errorf("ERROR: unsupport repair type\n");
		return -1;
	}

	ret = common_raw_read("miscdata", miscdata_len, miscdata_address, miscdata_buf);
	if (ret) {
		errorf("partition <miscdata> read NV data error\n");
		return ret;
        }

	if (!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
		t_ch = miscdata_buf[0];
		memset(miscdata_buf, 0, sizeof(miscdata_buf));
		sprintf(miscdata_buf ,"0x%x",t_ch);
		miscdata_len = strlen(miscdata_buf)+1;
	}


OUT:
	debugf("miscdata_buf %s\n", miscdata_buf);
	memcpy(buf, miscdata_buf, (len > 0) ? len : miscdata_len);

	return ret;
}

int oem_repair_write_mmc_ex(const char *type,unsigned char *buf) {
	char t_ch;
	int t_val=0;
	uint32_t ret = -1;
	uint64_t miscdata_address;
	uint64_t miscdata_len;
	char t_buf[8] = {0} ;
	char miscdata_buf[1024] = {0};


	debugf("oem repair write mmc get type %s\n", type);

	//20220601,Added by zhu_jun for suport fastboot command:fastboot oem repair skuid get begin
	if(!strcmp(type, "powp")) {
		memcpy(miscdata_buf, buf, powp_size);
	}else{
		memcpy(miscdata_buf, buf, strlen(buf));
	}

	//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
	#ifdef CONFIG_PCTOOL_AUTHORIZE_HMD
	if(!strcmp(type, "cali")) {
		memset(miscdata_buf, 0, sizeof(miscdata_buf));
		memcpy(miscdata_buf, buf, hmd_cali_size);
	}
	#endif
	//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end

	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
	if(!strcmp(type, "download")) {
		memset(miscdata_buf, 0, sizeof(miscdata_buf));
		memcpy(miscdata_buf, buf, hmd_download_size);
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end
	
	//added by dongming, AGT-685, 20221011
	if(!strcmp(type, HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE)) {
		memset(miscdata_buf, 0, sizeof(miscdata_buf));
		memcpy(miscdata_buf, buf, s_repair_signature_realsize);
	}
	//end added by dongming, AGT-685

	//20220601,Added by zhu_jun for suport fastboot command:fastboot oem repair skuid get begin
//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
	if(!strcmp(type, "powp")) {
		miscdata_address = WT_POWP_OFFSET;
		miscdata_len = WT_POWP_LEN;
	}
	//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
	else if(!strcmp(type, "zeroflag")) {
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
		miscdata_address = (CUSTOM_NV_BASE + WT_ZEROFLAG_OFFSET);
		miscdata_len = WT_ZEROFLAG_LEN;
	}else if(!strcmp(type, "skuid") || !strcmp(type, "sku")) {
	//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
		miscdata_address = MISCDATA_SKUID_ADDR;
		miscdata_len = MISCDATA_SKUID_LEN;
	}else if (!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
		miscdata_address = MISCDATA_COLORID_ADDR;
		miscdata_len = MISCDATA_COLORID_LEN;

		if (!strncmp(miscdata_buf,"0x",2)) {
           		memcpy(t_buf,miscdata_buf+2,2);
			t_val =  htoi(t_buf);
		}else{
			memcpy(t_buf,miscdata_buf,2);
			t_val =  atoi(t_buf);
		}
		memset(miscdata_buf, 0, sizeof(miscdata_buf));
		//t_val =  mystrtoint(t_buf);
		if(-1 == t_val){
			errorf("ERROR: write colorid or wallpapered error\n");
			return -1;
		}else{
			miscdata_buf[0] = (char)t_val;
		}
	}
//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency begin
	else if (!strcmp(type, "fastboot_reboot_edl")) {
		miscdata_address = MISCDATA_EDL_ADDR;
		miscdata_len = MISCDATA_EDL_LEN;
	}
	//20220602,Added by zhu_jun for suport fastboot command:fastboot reboot-emergency end
	else if(!strcmp(type, "cali")) {
		miscdata_address = HMD_CALI_MODE_SIGNATURE_OFFSET;
		miscdata_len = HMD_CALI_MODE_SIGNATURE_LEN;
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
	else if(!strcmp(type, "download")) {
		miscdata_address = HMD_DOWNLOAD_MODE_SIGNATURE_OFFSET;
		miscdata_len = HMD_DOWNLOAD_MODE_SIGNATURE_LEN;
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end
	//added by dongming, AGT-685, 20221011
	else if (!strcmp(type, HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE)) {
		miscdata_address = HMD_EDL_MODE_SIGNATURE_OFFSET;
		miscdata_len = HMD_EDL_MODE_SIGNATURE_LEN;
	}
	//end added by dongming, AGT-685
	else {
		errorf("ERROR: unsupport repair type\n");
		return -1;
	}
	debugf("miscdata_buf[0] is == %d,miscdata_len = %d\n", miscdata_buf[0],miscdata_len);
	ret = common_raw_write("miscdata", miscdata_len, (u64)0, miscdata_address, miscdata_buf);
	if (ret) {
		errorf("partition <miscdata> write NV data error\n");
		return ret;
        }

	debugf("buf %s\n", buf);

EXIT:
	return ret;
}

//20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end

