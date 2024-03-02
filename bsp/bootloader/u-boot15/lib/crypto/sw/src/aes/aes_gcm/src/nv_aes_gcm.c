#include "config_gcm_sw.h"
#include "gcm.h"
#include "nv_aes_gcm.h"

extern void crypto_hexdump(const char *title, uint8_t * data, int len);

/*
 * [IN]input : data to encrypt(decrypt)
 * [IN]input_bytelen : byte length of input
 * [OUT]output : data after encrypt(encrypt)
 * [OUT]output_bytelen : byte length of output
 */
int nv_aes_gcm(unsigned char *input, int input_bytelen, unsigned char *output, int *output_bytelen)
{
    int ret = -1;
    unsigned char key[16] = {0};
    unsigned char iv[16] = {0};
    unsigned char uid[17] = {0};
    unsigned char buf[48] = {0};
    unsigned char hash_ran_uid[32] = {0};
    unsigned char tag[16] = {0};
    const unsigned char additional[16] = {0};
    unsigned char rand_h[16] = {0xD1, 0xAA, 0xE8, 0x8C, 0x52, 0xAE, 0x98, 0xB9,
                                0x6B, 0xD6, 0x55, 0xE2, 0x8F, 0xA3, 0xCD, 0xD1};
    unsigned char rand_e[16] = {0xE7, 0xA1, 0x93, 0x0A, 0x4E, 0x40, 0xC6, 0x0C,
                                0x6A, 0xE7, 0x80, 0x7D, 0x5C, 0xC1, 0xAD, 0xA8};

    /* get uid */
    if ( 0 != sprd_get_chip_hex_uid (uid)) {
        return GET_UID_FAILED;
    }

    memcpy (buf, rand_h, sizeof(rand_h));

    memcpy (&buf[sizeof(rand_h)], uid, 16);

    memcpy (&buf[sizeof(rand_h) + 16], rand_e, sizeof(rand_e));
    crypto_hexdump("buf3:", buf, 48);

    /* calculate key amd iv */
    sha256_csum_wd_sw (buf, sizeof(buf), hash_ran_uid, NULL);
    crypto_hexdump("hash_ran_uid = ", hash_ran_uid, 32);
    memcpy (key, hash_ran_uid, sizeof(key));
    crypto_hexdump("key:", key, 16);
    memcpy (iv, &hash_ran_uid[sizeof(key)], sizeof(iv));
    crypto_hexdump("iv:", iv, 16);

    *output_bytelen = input_bytelen;
    mbedtls_gcm_context ctx;
    mbedtls_gcm_init (&ctx);
    mbedtls_cipher_id_t cipher = MBEDTLS_CIPHER_ID_AES;

    ret = mbedtls_gcm_setkey (&ctx, cipher, key, sizeof(key) << 3);
    if (ret != 0) {
        return ret;
    }

    ret = mbedtls_gcm_crypt_and_tag (&ctx, MBEDTLS_GCM_ENCRYPT, input_bytelen, iv, sizeof(iv), additional, sizeof(additional), input, output, sizeof(tag), tag);
    if ( 0 == ret ) {
        return CRYPT_SUCCESSED;
    } else {
        return CRYPT_FAILED;
    }
}

#if 0
int nv_crypt_test(){
    const unsigned char pt1[32] = {0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a,
        0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a,
        0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a,
        0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a};
    const unsigned char pt2[1] = {0x5a};
    int r = -1;
    unsigned char ct1[32] = {0};
    unsigned char ct2[1] = {0};
    int ct1_bytelen, ct2_bytelen;
    int out1_bytelen, out2_bytelen;
    printf("first test starts\n");

    crypto_hexdump("my_pt1:", pt1, 32);
    r = nv_aes_gcm(pt1, sizeof(pt1), ct1, &ct1_bytelen);
    if (r >= 0) {
        crypto_hexdump("my_ct1 = ", ct1, 32);
        printf("ct1_bytelen = %d\n", ct1_bytelen);
    }
    const unsigned char output[32] = {0};
    printf("decrypt:\n");
    r = nv_aes_gcm(ct1, sizeof(ct1), output, &out1_bytelen);
    if (r >= 0) {
        crypto_hexdump("my_output1 = ", output, 32);
    }
    printf("r = %d\n", r);

    printf("second test starts\n");
    crypto_hexdump("my_pt2:", pt2, 1);
    r = nv_aes_gcm(pt2, sizeof(pt2), ct2, &ct2_bytelen);
    if (r >= 0) {
        crypto_hexdump("my_ct2 = ", ct2, 1);
        printf("ct2_bytelen = %d\n", ct2_bytelen);
    }
    const unsigned char output2[1] = {0};
    printf("decrypt:\n");
    r = nv_aes_gcm(ct2, sizeof(ct2), output2, &out2_bytelen);
    if (r >= 0) {
        crypto_hexdump("my_output2 = ", output2, 1);
    }
    printf("r = %d\n", r);

    return 0;
}
#endif
