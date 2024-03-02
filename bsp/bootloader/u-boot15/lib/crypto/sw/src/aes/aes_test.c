/*
 * Unit test for HW AES encryption.
 */

#include "aes.h"
#include <sprd_crypto_sw.h>
#include <common.h>
//#include <platform.h>

/*
 * These sample values come from publication "FIPS-197", Appendix C.1
 * "AES-128" See
 * http://csrc.nist.gov/publications/fips/fips197/fips-197.pdf
 */
static const uint8_t plaintext[32] = {
	0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a,
	0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a, 0x5a};

static const uint8_t aes_iv[16] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
	0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};

static const uint8_t key[16] = {
	0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
	0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
};

static const uint8_t key32[32] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
                                0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
static const uint8_t key_test[32] = {
	0x39, 0xFB, 0x4B, 0xF8, 0xD1, 0x07, 0x49, 0x67,
    0x9F, 0xD9, 0xB2, 0x51, 0x24, 0x77, 0xFF, 0xB2,
    0xD2, 0x8F, 0x95, 0x69, 0x55, 0x0F, 0x0B, 0x99,
    0xFC, 0x01, 0xB4, 0x2D, 0xC7, 0x28, 0xD1, 0x49,
};

static const uint8_t iv_test[16] = {
    0x74, 0x95, 0xE2, 0xEE, 0xD8, 0xC1, 0x06, 0xA3,
    0xF3, 0x28, 0x4A, 0x2D, 0xF5, 0x89, 0x97, 0xAC,
};

static const uint8_t expected_ciphertext[64] = {
    0x87, 0x2d, 0x98, 0xc2, 0xcc, 0x31, 0x5b, 0x41, 0xe0, 0xfa, 0x7b,
    0x0a, 0x71, 0xc0, 0x42, 0xbf, 0x4f, 0x61, 0xd0, 0x0d, 0x58, 0x8c,
    0xf7, 0x05, 0xfb, 0x94, 0x89, 0xd3, 0xbc, 0xaa, 0x1a, 0x50, 0x45,
    0x1f, 0xc3, 0x8c, 0xb8, 0x98, 0x86, 0xa3, 0xe3, 0x6c, 0xfc, 0xad,
    0x3a, 0xb5, 0x59, 0x27, 0x7d, 0x21, 0x07, 0xca, 0x4c, 0x1d, 0x55,
    0x34, 0xdd, 0x5a, 0x2d, 0xc4, 0xb4, 0xf5, 0xa8, 0x35};

#if 0
void crypto_hexdump(const char *title, uint8_t * data, int len)
{
    int i, j;
    int N = len / 16 + 1;
    printf("%s\n", title);
    printf("crypto: %d bytes", len);
    for (i = 0; i < N; i++) {
        printf("\n");
        for (j = 0; j < 16; j++) {
            if (i * 16 + j >= len)
                goto end;
            printf("%02x", data[i * 16 + j]);
        }
    }

end:
    printf("\n");
}
#else
void crypto_hexdump(const char *title, uint8_t * data, int len)
{
    return;
}
#endif

int aes_cbc_sw_test(void)
{
	AES_KEY aes_key;
	uint8_t iv[16];
	uint8_t ciphertext[256];
	uint8_t plaintext_temp[256];
	uint8_t i;

	SPRD_CRYPTO_LOG_TRACE("Testing AES encryption.\n");
	sprd_pal_memset(&aes_key, 0, sizeof(AES_KEY));
	sprd_pal_memset(ciphertext, 0, sizeof(ciphertext));
	sprd_pal_memcpy(iv, aes_iv, sizeof(aes_iv));
	SPRD_CRYPTO_LOG_TRACE("Testing AES encryption.\n");
	if (0 != AES_set_encrypt_key(key, 128, &aes_key))
	{
		SPRD_CRYPTO_LOG_TRACE("aes set enc key  failed. \r\n");
	}
	AES_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &aes_key, iv, AES_ENC);
	SPRD_CRYPTO_LOG_TRACE("Testing AES decryption.\n");
//	sprd_pal_memset(ciphertext, 0, sizeof(ciphertext));
	sprd_pal_memcpy(iv, aes_iv, sizeof(aes_iv));
	if (0 != AES_set_decrypt_key(key, 128, &aes_key))
	{
		SPRD_CRYPTO_LOG_TRACE("aes set dec key  failed. \r\n");
	}
	AES_cbc_encrypt(ciphertext, plaintext_temp, sizeof(plaintext), &aes_key, iv, AES_DEC);
	//AES_encrypt(plaintext, ciphertext, &aes_key);
	//lk_bigtime_t end = current_time_hires();
	//int elapsed = end - start;
	//SPRD_CRYPTO_LOG_TRACE("Elapsed time: %d us for 16 bytes (%d.%03d us per byte)\n",
	//       elapsed, elapsed / AES_BLOCK_SIZE,
	//       ((elapsed * 1000) / AES_BLOCK_SIZE) % 1000);
	int not_equal = sprd_pal_memcmp(plaintext_temp, plaintext, 2*AES_BLOCK_SIZE);
	if (not_equal) {
		SPRD_CRYPTO_LOG_TRACE("decryption failed.\n");
		//SPRD_CRYPTO_LOG_TRACE("Actual:\n");
		//hexdump8(ciphertext, sizeof(ciphertext));
		debugf("FAILED AES decryption\n");
	} else {
		debugf("PASSED AES decryption\n");
	}

	return 0;
}

int aes_cbc_sw_encrypt(const uint8_t *raw_data, uint8_t *encrypt_data)
{
        AES_KEY aes_key;
        uint8_t decrypt_data[32] = {0};
        uint8_t encrypt_data_temp[32] = {0};
        uint8_t iv[16] = {0};
        uint8_t i = 0;

        printf("%s\n", __func__);

        sprd_pal_memset(&aes_key, 0, sizeof(AES_KEY));
        if(0 != AES_set_encrypt_key(key32, 256, &aes_key))
        {
                printf("aes set dec key failed\n");
        }


        memcpy(iv, aes_iv, sizeof(aes_iv));
        AES_cbc_encrypt(raw_data, encrypt_data_temp, 32, &aes_key, iv, AES_ENC);

        if(0 != AES_set_decrypt_key(key32, 256, &aes_key))
        {
                printf("aes set dec key failed\n");
        }


#if 0
        printf("the random data: ");
        for(i = 0; i < 32; i++)
                printf("%x, ", raw_data[i]);
        printf("\n");

        printf("the encrypt temp data: ");
        for(i = 0; i < 32; i++)
                printf("%x, ", encrypt_data_temp[i]);
        printf("\n");
#endif

        memcpy(iv, aes_iv, sizeof(aes_iv));
        AES_cbc_encrypt(encrypt_data_temp, decrypt_data, 32, &aes_key, iv, AES_DEC);

        if(!memcmp(raw_data, decrypt_data, 32))
        {
                memcpy(encrypt_data, encrypt_data_temp, 32);
                printf("AES encrypt data success\n");
                return 0;
        }

        return 0;
}

#if 0
int aes256_cbc_pkcs7_test(void)
{
    int ret = 20;
    uint8_t iv[16] = {0};
    uint8_t output[48] = {0};
    uint8_t temp[32] = {0};

    sprd_pal_memcpy(iv, iv_test, 16);
    crypto_hexdump("iv_test:", iv_test, 16);
    ret = aes256_cbc_encrypt_pkcs7(key_test, iv_test, plaintext, 32, output);
    SPRD_CRYPTO_LOG_TRACE("ret = %d\n", ret);
    crypto_hexdump("output:", output, 48);
    sprd_pal_memcpy(iv, iv_test, 16);
    crypto_hexdump("iv_test:", iv_test, 16);
    ret = aes256_cbc_decrypt_pkcs7(key_test, iv_test, output, 48, temp);
    SPRD_CRYPTO_LOG_TRACE("ret = %d\n", ret);
    crypto_hexdump("temp:", temp, 32);
    return 0;
}
#endif

