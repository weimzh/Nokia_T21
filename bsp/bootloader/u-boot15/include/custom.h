#ifndef _CUSTOM_H_
#define _CUSTOM_H_

#define TYPE_MISCDATA      0
#define TYPE_PROTECT_DATA  1

#define PROTECTDATA_SN_OFFSET	(0)
#define PROTECTDATA_SN_SZ		(32)
#define PROTECTDATA_SKUID_OFFSET	(32)
#define PROTECTDATA_SKUID_SZ		(12)
#define PROTECTDATA_WALLPP_OFFSET	(44)
#define PROTECTDATA_WALLPP_SZ		(1)
#define PROTECTDATA_TACODE_OFFSET	(45)
#define PROTECTDATA_TACODE_SZ		(12)
#define PROTECTDATA_HEF_OFFSET      (825)
#define PROTECTDATA_HEF_SZ		    (1)

#define PROTECTDATA_IMEI1_OFFSET   (827)
#define PROTECTDATA_IMEI_SZ        (16)
#define PROTECTDATA_IMEI2_OFFSET   (843)

#define MISCDATA_PRODUCT_INFOS_OFFSET	(774 * 1024 + 323)//Customer customization.

#define MISCDATA_POWP_KEY_OFFSET   (770*1024)
#define MISCDATA_POWP_KEY_SZ       (256)



#define MISCDATA_DIAG_FLAG_ENABLE_OFFSET  (774 * 1024 + 660)
#define MISCDATA_DIAG_FLAG_SZ   4

extern int repair_set_key(int type, uint64_t offset, char *buf, int length);

#endif
