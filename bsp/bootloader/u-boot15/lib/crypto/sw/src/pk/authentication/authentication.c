#include <config_gcm_sw.h>
#include <gcm.h>
#include <authentication.h>
#include <sprd_rsa.h>
#include <sprd_crypto_sw.h>
#include <sprdsha.h>

extern void crypto_hexdump(const char *title, uint8_t * data, int len);

//unsigned char socIdBuff [32] __attribute__((aligned(4096)));
unsigned char R1[256] = {0};
unsigned char pubExp_A[4] = { 0x00, 0x01, 0x00, 0x01, };
unsigned char mod_N[256] = {
0xd9, 0xde, 0x1e, 0x16, 0xe4, 0xe2, 0xbf, 0x98, 0xb2, 0x5a, 0xf1, 0x1a, 0xe5, 0x54, 0x1e, 0xf0,
0x43, 0x16, 0xbe, 0x6d, 0x01, 0x31, 0xa1, 0xc8, 0x6d, 0xc7, 0x60, 0x63, 0x40, 0xe2, 0x5e, 0xd9,
0x39, 0xf3, 0x2a, 0x12, 0x95, 0x23, 0xb8, 0x21, 0x49, 0x8e, 0x8c, 0x46, 0x1c, 0xee, 0x01, 0x81,
0x70, 0xfb, 0xb4, 0x41, 0x4f, 0x89, 0x70, 0xc4, 0x83, 0x3c, 0xd2, 0x03, 0xb5, 0xcc, 0x5c, 0x09,
0x9e, 0x48, 0xc2, 0xc1, 0x0e, 0xc3, 0xd3, 0x25, 0x57, 0xbe, 0xc5, 0x5f, 0xbb, 0x94, 0xab, 0xcc,
0xd3, 0x6e, 0x5b, 0x2e, 0xf1, 0x1a, 0x0d, 0xd5, 0xde, 0x77, 0xd3, 0x96, 0x30, 0xf4, 0xbf, 0x60,
0xfd, 0x95, 0xbb, 0xd6, 0x1a, 0xb9, 0x18, 0x9b, 0x85, 0xe3, 0x39, 0xf5, 0x30, 0x47, 0x80, 0x2c,
0x5a, 0x98, 0x7d, 0x1f, 0x9d, 0x48, 0x3e, 0x82, 0x15, 0x78, 0x3a, 0x76, 0x59, 0xe7, 0x28, 0x44,
0x6f, 0x4e, 0x6f, 0xff, 0x9e, 0x85, 0x2d, 0xd3, 0xf1, 0x1a, 0xc7, 0x8e, 0xca, 0xd2, 0xe1, 0x15,
0x4c, 0x77, 0x2e, 0xf9, 0x70, 0x55, 0x68, 0xf6, 0x45, 0xe7, 0xd5, 0xb0, 0xcf, 0x78, 0x9d, 0xb4,
0x43, 0x04, 0xb9, 0x22, 0x34, 0x21, 0x85, 0xb8, 0xdb, 0x78, 0xd3, 0x32, 0x76, 0x0b, 0x52, 0xc3,
0x16, 0xc5, 0x6e, 0x32, 0xba, 0xc8, 0x0d, 0x80, 0x35, 0x60, 0x67, 0xcc, 0x94, 0x07, 0xff, 0x6d,
0x2b, 0x48, 0x81, 0x7d, 0x66, 0xa3, 0x12, 0x9e, 0x27, 0x98, 0x00, 0x4c, 0xf4, 0x7d, 0x14, 0xff,
0x9b, 0x04, 0x79, 0x62, 0xf6, 0x95, 0x42, 0x56, 0x0d, 0xef, 0xd8, 0xdf, 0x2e, 0xce, 0x0a, 0x77,
0xdf, 0xee, 0xc5, 0x54, 0xf9, 0x5e, 0xa9, 0x86, 0x87, 0x4c, 0xe0, 0xae, 0x6b, 0x67, 0xe6, 0x82,
0x35, 0xee, 0xbf, 0x38, 0xf5, 0xa0, 0x12, 0xa7, 0x90, 0xfd, 0x49, 0x42, 0x80, 0xdb, 0x14, 0xa7,
};
int bitLen_N = 2048;
/*
 * flg = 1 : respond to authentication requests
 * Msg : encrypted rand||socid with A
 * flg = 0 for return authentication result
 * Msg : encrypted R2 with d
 */

int authentication (unsigned char *msg, int flg)
{
    int ret = -1;
    unsigned char R0[32]={0};
    int res = 0;
    unsigned char R3[256] = {0};
    unsigned char uid[32] = {0};
    unsigned char hash_uid[64] = {0};

    if (msg == NULL) {
        printf("authentication: bad input!\n");
        return ret;
    }

    switch (flg) {
    case DECRYPT:
        ret = RSA_Verify(pubExp_A, mod_N, bitLen_N, msg, R3);
        crypto_hexdump("R1:", R1, 64);
        crypto_hexdump("R3:", R3, 64);

        res = memcmp(R1, R3, 64);
        if (ret < 0 || 0 != res) {
            return AUTH_FAILED;
        } else {
            return AUTH_SUCCESS;
        }
        break;

    case ENCRYPT:
        if (0 != prand_gen(R0, 32)) {
            return SHA1_RNG_FAILED;
        }

        ret = sprd_get_chip_hex_uid (uid);
        crypto_hexdump("got uid:", uid, sizeof(uid));

        if(0 != ret) {
            return GET_UID_FAILED;
        }

        sha256_csum_wd_sw (uid, 32, hash_uid, NULL);
        crypto_hexdump("hash_uid:", hash_uid, 32);

        memcpy(R1, R0, 32);
        memcpy(R1+32, hash_uid, 32);
        crypto_hexdump("R1:", R1, 64);

        ret = RSA_PubEnc(pubExp_A, mod_N, bitLen_N, R1, 64, msg);
        if (0 != ret) {
            return ENCRYPT_FAILED;
        } else {
            return ENCRYPT_SUCCESSED;
        }
        break;

    default:
        printf("unsupported flg!\n");
    }

    return ret;
}
/* do not use this */
#if 0
 int authentication_test()
 {
 unsigned char msg[ENCRYPT_SUCCESSED] = {0};
 int ret = -1;
 ret = authentication (msg, 1);
 if (ret < 0 || ret == 0) {
 return ret;
 }
 ret = authentication (msg, 0);
 printf("ret = %d\n", ret);
 ret = authentication (msg, 2);
 printf("ret = %d\n", ret);
 return 0;
 }
#endif

//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication begin
unsigned long times = 0l;
unsigned char R1_download[256] = {0};
unsigned char download_mod_N[256] = {
    0xae,0xc7,0x6b,0xd0,0x3e,0x43,0x72,0xef,0x05,0x6e,0x8c,0x61,0xe9,0xe1,
    0x6a,0x40,0x12,0xf8,0x94,0x43,0x5a,0xf3,0x0d,0xbb,0xcc,0x29,0x2c,0x8c,0xbb,
    0x96,0x72,0x4a,0x87,0x8a,0x3c,0x88,0x84,0x73,0xeb,0xe5,0x77,0x60,0x2e,0xc7,
    0xe7,0x41,0xe8,0xe5,0x1f,0x59,0xe4,0x3b,0xda,0x7b,0x76,0x99,0x83,0x52,0xa3,
    0xf9,0x87,0x2c,0xf7,0x04,0x2e,0x4b,0xf6,0x09,0xd4,0x9c,0x04,0x2c,0xf3,0x05,
    0xbd,0xd6,0x55,0x12,0x90,0xef,0xb2,0x63,0x13,0x80,0x42,0x1a,0x8c,0x6b,0x1f,
    0x0e,0x77,0x39,0xa9,0xdf,0x94,0x8d,0x5e,0x1d,0x8d,0xd8,0x57,0x52,0x11,0xc3,
    0x06,0x6f,0x9f,0x81,0x5d,0x98,0xda,0x7e,0xcf,0x3d,0xd7,0x35,0x74,0x6f,0xd3,
    0x6d,0x3e,0xd0,0x03,0xc7,0x3e,0x62,0x36,0x4f,0x1b,0x59,0x12,0x9d,0x02,0x6a,
    0x5e,0x54,0x7f,0xc9,0x0b,0xb0,0x92,0xb7,0x8b,0x79,0xc2,0x0b,0x38,0x18,0x82,
    0x25,0xc6,0x45,0x81,0x77,0xe6,0x5b,0xee,0x5a,0xb7,0x86,0xb5,0x1c,0x6f,0x3f,
    0xef,0x31,0x01,0x0f,0xb6,0x32,0xc1,0xe9,0xef,0x5b,0xac,0x9e,0xf9,0xbf,0x72,
    0xe8,0x00,0x42,0x2e,0xa8,0x1c,0x14,0xb3,0x9a,0x74,0x3a,0x0a,0xc9,0x03,0x6d,
    0x26,0xcf,0x92,0x5f,0x11,0x7b,0x65,0x7c,0xcf,0x07,0xbd,0x85,0x59,0xfe,0x79,
    0xc8,0x99,0x69,0xef,0x6d,0x54,0xd6,0x5f,0x85,0xc2,0x94,0x67,0xcf,0x09,0xdf,
    0x7a,0xd5,0x4b,0xf8,0x37,0xdc,0xa9,0x48,0xca,0x03,0xe4,0xe5,0x47,0xd0,0x9c,
    0x93,0xc8,0x53,0xc8,0x15,0x67,0xa2,0xad,0x49,0x34,0x50,0x18,0xee,0x77,0x5d,
    0x81,0xbd,
};

int hmd_download_authentication (unsigned char *msg, int flg)
{
    int ret = -1;
    unsigned char R0[32]={0};
    int res = 0;
    unsigned char R3[256] = {0};
    unsigned char uid[32] = {0};
    unsigned char hash_uid[64] = {0};

    if (msg == NULL) {
        printf("authentication: bad input!\n");
        return ret;
    }

    switch (flg) {
    case DECRYPT:
        if(sprd_rtc_get_sec() - times > 600){
            times=0l;
            return AUTH_TIMEOUT;
        }
        ret = RSA_Verify(pubExp_A, download_mod_N, bitLen_N, msg, R3);
        debugf("hmd_download_authentication ret1 is %d \n",ret);
        res = memcmp(R1_download, R3, 64);
        if (ret < 0 || 0 != res) {
            return AUTH_FAILED;
        } else {
            return AUTH_SUCCESS;
        }
        break;

    case ENCRYPT:
        if (0 != prand_gen(R0, 32)) {
            return SHA1_RNG_FAILED;
        }

        ret = sprd_get_chip_hex_uid (uid);
        crypto_hexdump("got uid:", uid, sizeof(uid));

        if(0 != ret) {
            return GET_UID_FAILED;
        }

        sha256_csum_wd_sw (uid, 32, hash_uid, NULL);
        crypto_hexdump("hash_uid:", hash_uid, 32);

        memcpy(R1_download, R0, 32);
        memcpy(R1_download + 32, hash_uid, 32);
        crypto_hexdump("R1_download:", R1_download, 64);
        times=sprd_rtc_get_sec();
        ret = RSA_PubEnc(pubExp_A, download_mod_N, bitLen_N, R1_download, 64, msg);
        if (0 != ret) {
            return ENCRYPT_FAILED;
        } else {
            return ENCRYPT_SUCCESSED;
        }
        break;

    default:
        printf("unsupported flg!\n");
    }

    return ret;
}
//20220701, Added by zhu_jun for VSI-681 SoC Download Mode Authentication end

//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
#ifdef CONFIG_PCTOOL_AUTHORIZE_HMD
unsigned char cali_mod_N[256] = {
    0xcd, 0xb0, 0xea, 0x9a, 0x7c, 0xdc, 0xc3, 0x4e, 0x77, 0xd9, 0x02, 0x87, 0x19, 0x96, 
    0x1a, 0xbc, 0x5f, 0x63, 0x49, 0xc0, 0xa3, 0xc4, 0xc2, 0x86, 0xfd, 0xd5, 0x36, 0xfe, 0xc8,
    0x3b, 0x3b, 0x8f, 0x70, 0xf8, 0x2f, 0xf9, 0x60, 0x71, 0x00, 0x8f, 0x93, 0xee, 0xba, 0x35,
    0x1c, 0xea, 0xcb, 0x2e, 0x12, 0x6b, 0x37, 0x84, 0x41, 0x12, 0x7e, 0xca, 0xad, 0x7a, 0xcc,
    0x96, 0xee, 0xd9, 0x97, 0x17, 0x6b, 0x85, 0x4b, 0x75, 0x2c, 0x08, 0x1a, 0xe3, 0x2e, 0xdf,
    0xcc, 0x7b, 0x8c, 0xec, 0x22, 0x6e, 0x55, 0x29, 0xf9, 0xcd, 0x0d, 0x4b, 0x9e, 0x1a, 0xa0,
    0xbf, 0xac, 0xa3, 0xf3, 0xe2, 0x71, 0x20, 0x47, 0x1f, 0x80, 0x27, 0x19, 0x90, 0x1a, 0xe1,
    0x1c, 0x2e, 0x32, 0xab, 0x6b, 0xe5, 0x27, 0xc2, 0x4c, 0x03, 0xeb, 0x5b, 0x8d, 0x20, 0xad,
    0x77, 0xf9, 0xda, 0x48, 0xbd, 0x95, 0x6e, 0x5e, 0xaf, 0x1f, 0xd3, 0x37, 0x67, 0x80, 0xe0,
    0x93, 0x65, 0x08, 0xf1, 0x43, 0x72, 0x3b, 0x05, 0xb7, 0x0c, 0xa2, 0x5e, 0xcb, 0x08, 0x72,
    0x9a, 0x53, 0xa5, 0xb0, 0xbb, 0xc1, 0xf9, 0x1e, 0xd7, 0xb8, 0x9f, 0x0e, 0x58, 0x53, 0x9c,
    0xae, 0xe3, 0x27, 0x27, 0x33, 0x45, 0xd3, 0x31, 0x09, 0x23, 0x53, 0xd2, 0x91, 0x85, 0x05,
    0xf3, 0xd4, 0xf8, 0xba, 0xfd, 0x8b, 0xd3, 0x68, 0x6d, 0xe0, 0xee, 0xe0, 0xc3, 0x09, 0xa9,
    0x3c, 0xd3, 0x22, 0xdf, 0x23, 0x75, 0x5e, 0x9f, 0x13, 0x1b, 0x73, 0x47, 0xd5, 0x83, 0xef,
    0x95, 0x10, 0x45, 0x4e, 0xbb, 0x2a, 0x05, 0xf9, 0x2b, 0x02, 0x8b, 0x0a, 0x56, 0x5f, 0xe0,
    0x15, 0x12, 0x2f, 0x44, 0x07, 0xcf, 0x96, 0xa8, 0x08, 0x69, 0xab, 0x06, 0xa4, 0x9f, 0xf0,
    0x6f, 0x6f, 0x6b, 0xd8, 0x21, 0x0b, 0x46, 0x66, 0xb3, 0xfa, 0x3e, 0x54, 0x63, 0x80, 0xd0,
    0x97, 0x99
};
#define HEAD_RSA_SIZE 19
#define SHA_DATA_SIZE 32
#define REVICE_POWP_DATA_SIZE  HEAD_RSA_SIZE+SHA_DATA_SIZE
static unsigned char HEAD_RSA_SHA256[HEAD_RSA_SIZE] =
{   0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01,
    0x05, 0x00, 0x04, 0x20
};
typedef struct _RSA_VERIFY_DATA
{
    unsigned char head_rsa[HEAD_RSA_SIZE];
    unsigned char sha_data[SHA_DATA_SIZE];
} RSA_VERIFY_DATA;


int hmd_cali_authentication(unsigned char *encrypt_data,unsigned char *original_data,unsigned int ori_data_len){
    int32_t length = -1;
    unsigned char revice_powp_data[REVICE_POWP_DATA_SIZE] = {0};
    RSA_VERIFY_DATA rsa_verify_data;
    memset(&rsa_verify_data, 0, REVICE_POWP_DATA_SIZE);
    // unsigned char sha_data[SHA_DATA_SIZE]={0};
    length = RSA_Verify(pubExp_A, cali_mod_N, bitLen_N, encrypt_data, revice_powp_data);
    if (0 > length)
    {
        printf("rsa verify dec failed err:%d\n", length);
        return AUTH_FAILED;
    }
    // dumpHex("revice_powp_data", revice_powp_data, REVICE_POWP_DATA_SIZE);
    memcpy(rsa_verify_data.head_rsa, revice_powp_data, HEAD_RSA_SIZE);
    unsigned char *point = revice_powp_data;
    point += HEAD_RSA_SIZE;
    memcpy(rsa_verify_data.sha_data, point, SHA_DATA_SIZE);
    unsigned char original_sha256_data[SHA_DATA_SIZE] = {0};
    sha256_csum_wd_sw(original_data, ori_data_len, original_sha256_data, NULL);
    if(0 != memcmp(rsa_verify_data.head_rsa, HEAD_RSA_SHA256, HEAD_RSA_SIZE)){
         return AUTH_FAILED;
    }
    if(0 != memcmp(rsa_verify_data.sha_data, original_sha256_data, SHA_DATA_SIZE)){
         return AUTH_FAILED;
    }else{
         return AUTH_SUCCESS;
    }
    return AUTH_FAILED;
}
#endif
//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end