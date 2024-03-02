//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically begin
#ifndef __POWP_DISABLE_H__
#define __POWP_DISABLE_H__

#define DECRYPT_DATA_OFFSET	19
#define HASH_SIZE		32
#define ENCRYPT_DATA_SIZE	2048
#define WT_SN_SIZE		19

#define VERIFY_OK		1
#define VERIFY_FAIL		0

int powp_verify(void);

#endif
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically end
