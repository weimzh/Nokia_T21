//20220525,Added by zhu_jun for serial number related properties begin
#include <common.h>
#include <boot_mode.h>
#include <part_efi.h>
#include "loader_common.h"
#include <sprd_common_rw.h>
#include "protect_data_def.h"
#include "sprd_cpcmdline.h"
#include <linux/ctype.h>

extern int POWP_flag;

int atoi(const char *src)
{
      int s = 0;
      bool isMinus = 0;

      while(*src == ' ')
      {
          src++;
      }

      if(*src == '+' || *src == '-')
      {
          if(*src == '-')
          {
              isMinus = 1;
          }
          src++;
      }
      else if(*src < '0' || *src > '9')
      {
          s = 2147483647;
          return s;
      }

      while(*src != '\0' && *src >= '0' && *src <= '9')
      {
          s = s * 10 + *src - '0';
          src++;
      }
      return s * (isMinus ? -1 : 1);
 }

int read_protect_data_ex(const char *type,unsigned char *buf,int len) {
	uint32_t ret = -1;
	uint64_t protect_address;
	uint64_t protect_len;
	char t_ch;

	char protect_buf[1024] = {0};

	debugf("read protect_data get type %s\n", type);

	if((len > sizeof(protect_buf)) && ( len != READ_Protect_data_LEN_AUTO)) {
		errorf("read_protect_data_ex read len error\n");
		return -1;
	}
	else if(!strcmp(type, "skuid") || !strcmp(type, "sku")) {
		protect_address = SKUID_OFFSET;
		protect_len = SKUID_LEN;
	}
	else if (!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
		protect_address = Color_ID_OFFSET;
		protect_len = Color_ID_LEN;
	}
	else if (!strcmp(type, "serial") || !strcmp(type, "sn")) {
		protect_address = PHONE_SN_OFFSET;
		protect_len = PHONE_SN_LEN;
	}
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
	else if(!strcmp(type, "hef")) {
		protect_address = HEF_OFFSET;
		protect_len = HEF_LEN;
	}
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end
	//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
	else if (!strcmp(type, "IMEI1")) {
		protect_address = WT_IMEI1_OFFSET;
		protect_len = WT_IMEI1_LEN;
	}
	else if (!strcmp(type, "IMEI2")) {
		protect_address = WT_IMEI2_OFFSET;
		protect_len = WT_IMEI2_LEN;
	}
	//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
	else if (!strcmp(type, "simslot")) {
		protect_len = TA_Code_LEN;
		memset(protect_buf, 0, sizeof(protect_buf));
		get_status_simslot(protect_buf, (unsigned int *)&protect_len);
		ret = 0;
		goto OUT;
	}
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
	else {
		errorf("ERROR: unsupport repair type\n");
		return -1;
	}

	ret = common_raw_read(PROTECT_DATA, protect_len, protect_address, protect_buf);
	if (ret) {
		errorf("partition <protect> read data error\n");
		return ret;
        }
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions begin
	if (!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
		t_ch = protect_buf[0];
		memset(protect_buf, 0, sizeof(protect_buf));
		sprintf(protect_buf ,"0x%x",t_ch);
		protect_len = strlen(protect_buf)+1;
	}
	//20220531,Added by zhu_jun for Devicekit write configuration to protect partitions end
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
	if(!strcmp(type, "hef")) {		//read
		if('1' == protect_buf[0]){
			write_protect_data_ex("hef", "1");
			protect_buf[0] = 1;
		}
		if('0' == protect_buf[0]){
			write_protect_data_ex("hef", "0");
			protect_buf[0] = 0;
		}
	}
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end

OUT:
	//debugf("protect_buf %s\n", protect_buf);
	memcpy(buf, protect_buf, (len > 0) ? len : protect_len);

	return ret;
}

int write_protect_data_ex(const char *type,unsigned char *buf) {
	int t_val=0;
	uint32_t ret = -1;
	uint64_t protect_address;
	uint64_t protect_len;
	char t_buf[8] = {0} ;
	char protect_buf[1024] = {0};
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
	int hef_val = 0;
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end

	debugf("oem repair write mmc get type %s\n", type);
	//20220607,Added by zhu_jun for disable write protect_data when powp is enable begin
	if (POWP_flag) {
		errorf("protect partition status is enabled\n");
		return ret;
    }
	//20220607,Added by zhu_jun for disable write protect_data when powp is enable end

	memcpy(protect_buf, buf, strlen(buf));

	if(!strcmp(type, "skuid") || !strcmp(type, "sku")) {
		protect_address = SKUID_OFFSET;
		protect_len = SKUID_LEN;
	}else if (!strcmp(type, "colorid") || !strcmp(type, "wallpapered")) {
		protect_address = Color_ID_OFFSET;
		protect_len = Color_ID_LEN;

		if (!strncmp(protect_buf,"0x",2)) {
           		memcpy(t_buf,protect_buf+2,2);
			t_val =  htoi(t_buf);
		}else{
			memcpy(t_buf,protect_buf,2);
			t_val =  atoi(t_buf);
		}
		memset(protect_buf, 0, sizeof(protect_buf));
		//t_val =  mystrtoint(t_buf);
		if(-1 == t_val){
			errorf("ERROR: write colorid or wallpapered error\n");
			return -1;
		}else{
			protect_buf[0] = (char)t_val;
		}
	}
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
	else if(!strcmp(type, "hef")) { //write
		protect_address = HEF_OFFSET;
		protect_len = HEF_LEN;

		if('0' == protect_buf[0]){
			hef_val = 0;
		}else{
			hef_val = 1;
		}
		protect_buf[0] = (char)hef_val;
	}
	//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end
	//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
	#if 1 // use test
	else if (!strcmp(type, "IMEI1")) {
		protect_address = WT_IMEI1_OFFSET;
		protect_len = WT_IMEI1_LEN;
	}
	else if (!strcmp(type, "IMEI2")) {
		protect_address = WT_IMEI2_OFFSET;
		protect_len = WT_IMEI2_LEN;
	}
	#endif
	//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end
	else {
		errorf("ERROR: unsupport repair type\n");
		return -1;
	}
	//debugf("protect_buf[0] is == %d,protect_len = %d\n", protect_buf[0],protect_len);
	ret = common_raw_write(PROTECT_DATA, protect_len, (u64)0, protect_address, protect_buf);
	if (ret) {
		errorf("partition <protect> write NV data error\n");
		return ret;
        }

	debugf("buf %s\n", buf);

EXIT:
	return ret;
}
//20220525,Added by zhu_jun for serial number related properties end

