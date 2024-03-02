#ifndef _OEM_FASTBOOTCMD_H_
#define _OEM_FASTBOOTCMD_H_

enum MODE_FASTBOOT {
    MODE_FASTBOOT_BASIC = 0,
    MODE_FASTBOOT_FLASH,
    MODE_FASTBOOT_REPAIR,
    MODE_FASTBOOT_SIMLOCK,
    //20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
    MODE_FASTBOOT_FACTORY,
	//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
    //20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
    MODE_FASTBOOT_DOWNLOAD,
    //20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end
    MODE_FASTBOOT_NUM,
};

#define AUTH_DATA_LEN 344
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key begin
#define SW_PUB_KEY_LEN 392
#define UPLOADE_SIZE 512
//20220602,Added by zhu_jun for suport fastboot command:fastboot oem sw_pub_key end

void oem_fastboot_register_commands(void);
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
int is_need_hmd_download_auth(void);
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end

#endif /* !_OEM_FASTBOOTCMD_H_ */



