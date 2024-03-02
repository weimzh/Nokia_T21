/*
 * Copyright (C) 2017 spreadtrum.com
 */
#ifndef _SPRDIMGVERSION_H
#define _SPRDIMGVERSION_H

#define IMGVER_DEBUG 1

typedef enum enAntiRBImageType {
	IMAGE_VBMETA = 0,
	IMAGE_BOOT,
	IMAGE_RECOVERY,
	IMAGE_SYSTEM,
	IMAGE_VENDOR,
	IMAGE_L_MODEM,
	IMAGE_L_LDSP,
	IMAGE_L_LGDSP,
	IMAGE_PM_SYS,
	IMAGE_AGDSP,
	IMAGE_WCN,
	IMAGE_GPS,
	IMAGE_GPU,
	IMAGE_SOCKO,
	IMAGE_ODMKO,
	IMAGE_SPARE,
	IMAGE_SPARES,
	IMAGE_TYPE_END
} antirb_image_type;

/*
*@imgType   The image which need to get the version
*@swVersion return image version
*Return value: zero is ok
*
*/
int sprd_get_imgversion(int imgType, unsigned int* swVersion);

int sprd_init_all_imgversion(uint8_t *rpmb_key);

#endif //_SPRDIMGVERSION_H
