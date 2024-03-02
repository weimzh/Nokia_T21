//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically begin
#include "powp_disable.h"
#include <miscdata_def.h>
#include <common.h>

extern char *get_product_sn();

static const unsigned char pub_E[4] = {0x00, 0x01, 0x00, 0x01};

static const unsigned char POWP_pubKy[] = {
    0x88, 0x54, 0x0a, 0x95, 0xd1, 0xf2, 0x3e, 0xec, 0x59, 0x9e, 0xa4, 0x1d, 0xde, 0x1a,
			0x07, 0x1a, 0x0a, 0xd8, 0xa0, 0x7c, 0x98, 0x53, 0x66, 0x5e, 0xc4, 0x57, 0xd7, 0x80, 0x3d,
			0x14, 0x4f, 0x10, 0x1e, 0x4f, 0x36, 0x10, 0x08, 0x1c, 0x03, 0xf2, 0x24, 0x05, 0xa8, 0xf3,
			0x22, 0xa5, 0x5f, 0x72, 0x23, 0xc8, 0x41, 0x1c, 0x93, 0xd2, 0x29, 0x15, 0x63, 0x30, 0x86,
			0x9b, 0x6a, 0x38, 0xbf, 0x67, 0xdf, 0x6e, 0x24, 0xae, 0x39, 0xb0, 0x79, 0x77, 0xa2, 0xa3,
			0x8e, 0x06, 0xff, 0x27, 0x4b, 0x3e, 0x45, 0x78, 0x7a, 0xea, 0x1c, 0x31, 0xbd, 0x0f, 0x6d,
			0xa8, 0x53, 0x56, 0x0c, 0x52, 0xe6, 0x2d, 0x6a, 0x7c, 0x44, 0x79, 0x2f, 0x12, 0xf2, 0x78,
			0x83, 0xd5, 0xa3, 0x8d, 0xf5, 0x31, 0xf5, 0xcb, 0x8a, 0xe0, 0x78, 0x34, 0x9e, 0x75, 0x02,
			0x72, 0x06, 0x00, 0xca, 0x47, 0x2e, 0x2c, 0xa0, 0x32, 0x5f, 0x98, 0xaa, 0x39, 0x8d, 0xf4,
			0xb0, 0xfe, 0x88, 0x8a, 0x5e, 0xa4, 0xa1, 0x3b, 0xc5, 0xf8, 0x0f, 0x19, 0xba, 0x09, 0x32,
			0xed, 0xe9, 0x0c, 0x7a, 0x04, 0x89, 0xdf, 0xf5, 0x1a, 0xb2, 0x9a, 0xd2, 0xa6, 0xf1, 0xd5,
			0x57, 0x7f, 0xa5, 0xf6, 0x33, 0x48, 0x94, 0x38, 0x37, 0x52, 0x6c, 0x6b, 0x39, 0x76, 0x9a,
			0x80, 0x33, 0x78, 0x2d, 0x7b, 0x2a, 0x75, 0x13, 0xb7, 0xa0, 0x3c, 0xc1, 0xe2, 0xff, 0x50,
			0x7f, 0xcc, 0xc3, 0xbd, 0xd7, 0x3b, 0x4a, 0xc8, 0x43, 0xbd, 0x0a, 0xe5, 0x0e, 0x63, 0xc6,
			0xaa, 0xa8, 0x51, 0x65, 0xba, 0x16, 0x62, 0xb4, 0xec, 0x73, 0x52, 0xe3, 0x83, 0xe6, 0x9d,
			0x67, 0xff, 0x45, 0xef, 0x5e, 0xca, 0x0d, 0x75, 0x19, 0x36, 0x3e, 0xd5, 0xb9, 0xbb, 0x0c,
			0x39, 0x50, 0x53, 0xe6, 0x48, 0x65, 0x50, 0xc2, 0x8f, 0xc2, 0x8d, 0x37, 0xa8, 0x92, 0x0b,
			0xda, 0x8f
};


static void debugPrintf_Hex1(const unsigned char *inBuf, int inLen, const char *cInfo)
{
    int i=0;
    printf("\n============= %s =============\n",cInfo);
    printf("inLen = %d \n",inLen);
    for (i = 0; i < inLen; i++) {
        if((0 == (i%16)) && (0 != i)) printf("\n");
        printf("%02x,",*(inBuf+i));
    }
    printf("\n============= %s =============\n",cInfo);
}


static int powp_verify_data_sha256(unsigned char * encrypt_data, int encrypt_data_len, unsigned char * data, int data_len)
{
    unsigned char hash[HASH_SIZE];
    unsigned char revice_raw_data[64] = {0};
	unsigned char pwop_sn[80];
    int sn_len = 0;
    int length = -1;
    int ret = -1;
    memset(pwop_sn, 0, sizeof(pwop_sn));

    sn_len = strlen("POWP_DISABLE");
    if(sn_len + data_len > 64)
        return VERIFY_FAIL;
    memcpy(pwop_sn, "POWP_DISABLE", sn_len);
    memcpy(pwop_sn+sn_len, data, data_len);
    sn_len += data_len;
    
    sha256_csum_wd_sw(pwop_sn, sn_len, hash, 0);
    debugPrintf_Hex1(hash, HASH_SIZE, "powp_verify_data_sha256_Hash");
    memset(revice_raw_data, 0x0, sizeof(revice_raw_data));
    length = RSA_Verify(pub_E, POWP_pubKy, encrypt_data_len, encrypt_data, revice_raw_data);
    if (0 > length) {
        debugf("rsa verify dec failed err:%d\n", length);
        return VERIFY_FAIL;
    }
	
	length = length > strlen(pwop_sn) ? strlen(pwop_sn) : length;
	
    debugPrintf_Hex1(revice_raw_data, length, "Verify return  revice_raw_data");
    if(strncmp(revice_raw_data + DECRYPT_DATA_OFFSET, hash, HASH_SIZE) == 0)
        return VERIFY_OK;
    else
        return VERIFY_FAIL;
}

#ifdef WT_COMPILE_FACTORY_VERSION
int powp_verify(void)
{
    debugf("============= powp_verify WT_COMPILE_FACTORY_VERSION= =============\n");
    return VERIFY_OK;
}

#else
int powp_verify(void)
{
    unsigned char encrypt_data[WT_POWP_LEN];

    unsigned char *sn;
    
    if(oem_repair_read_mmc_ex("powp", encrypt_data, WT_POWP_LEN) < 0)
        return VERIFY_FAIL;

    debugPrintf_Hex1(encrypt_data, WT_POWP_LEN, "encrypt_data_read from miscdata");
    sn = get_product_sn();
    if(!sn)
        return VERIFY_FAIL;

    debugf("============= sn = %s =============\n",sn);
    
    return powp_verify_data_sha256(encrypt_data, ENCRYPT_DATA_SIZE, sn, strlen(sn));
}
#endif
//20220531,Add by zhu_jun for Verify the signature of POWP_Flag in Uboot to enable/disable the POWP function dynamically end

