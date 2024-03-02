#include "aes.h"
#include "pkcs7_padding.h"
#include <sprd_crypto_sw.h>
#include <common.h>

int aes256_cbc_encrypt_pkcs7(const uint8_t *key, const uint8_t *iv, const uint8_t *plaintext, uint32_t plaintext_size, uint8_t *ciphertext)
{
    AES_KEY aes_key;
    int ret = -1;
    int ciphertext_size = 0;
    uint8_t *plaintext_padding = NULL;

    if (key == NULL || iv == NULL || plaintext == NULL || ciphertext == NULL || plaintext_size == 0) {
        SPRD_CRYPTO_LOG_TRACE("bad input!\n");
        goto err;
    }

    ciphertext_size = (plaintext_size + 16) / 16 * 16;
    SPRD_CRYPTO_LOG_TRACE("ciphertext_size = %d\n", ciphertext_size);
    plaintext_padding = (uint8_t *)malloc(ciphertext_size);
    if (NULL == plaintext_padding) {
        return ret;
    }
    sprd_pal_memset(&aes_key, 0, sizeof(AES_KEY));
    sprd_pal_memset(plaintext_padding, 0, ciphertext_size);
    sprd_pal_memcpy(plaintext_padding, plaintext, plaintext_size);
    crypto_hexdump("plaintext_padding:", plaintext_padding, ciphertext_size);

    SPRD_CRYPTO_LOG_TRACE("set key start!\n");
    ret = AES_set_encrypt_key(key, 256, &aes_key);
    if (0 != ret) {
        SPRD_CRYPTO_LOG_TRACE("set_encrypt_key_failed!\n");
        goto err;
    }

    SPRD_CRYPTO_LOG_TRACE("padding start!\n");
    ret = pkcs7_padding_pad_buffer(plaintext_padding, plaintext_size, ciphertext_size, 16);
    if (ret < 1 || ret > 16) {
        SPRD_CRYPTO_LOG_TRACE("bad padding!\n");
        ret = -1;
        goto err;
    }

    crypto_hexdump("plaintext_padding:", plaintext_padding, ciphertext_size);
    SPRD_CRYPTO_LOG_TRACE("cbc start!\n");
    crypto_hexdump("iv:", iv, 16);
    AES_cbc_encrypt(plaintext_padding, ciphertext, ciphertext_size, &aes_key, iv, AES_ENC);

    crypto_hexdump("ciphertext:", ciphertext,ciphertext_size);

    free(plaintext_padding);
    return 0;

err:

    free(plaintext_padding);

    return ret;
}

int aes256_cbc_decrypt_pkcs7(const uint8_t *key, const uint8_t *iv, const uint8_t *ciphertext, uint32_t ciphertext_size, uint8_t *plaintext)
{
    AES_KEY aes_key;
    int ret = -1;
    int plaintext_size = 0;
    uint8_t *buffer = NULL;

    if (key == NULL || iv == NULL || ciphertext == NULL || plaintext == NULL || ciphertext_size % 16 != 0) {
        SPRD_CRYPTO_LOG_TRACE("bad input!\n");
        goto err;
    }

    SPRD_CRYPTO_LOG_TRACE("ciphertext_size = %d\n", ciphertext_size);
    crypto_hexdump("ciphertext1:", ciphertext, ciphertext_size);
    buffer = (uint8_t *)malloc(ciphertext_size);
    if (NULL == buffer) {
        SPRD_CRYPTO_LOG_TRACE("malloc failed!\n");
        return ret;
    }
    sprd_pal_memset(&aes_key, 0, sizeof(AES_KEY));
    sprd_pal_memset(buffer, 0, ciphertext_size);

    SPRD_CRYPTO_LOG_TRACE("set key start!\n");
    ret = AES_set_decrypt_key(key, 256, &aes_key);
    if (0 != ret) {
        SPRD_CRYPTO_LOG_TRACE("set_decrypt_key_failed!\n");
        goto err;
    }

    crypto_hexdump("ciphertext2:", ciphertext, ciphertext_size);
    SPRD_CRYPTO_LOG_TRACE("cbc start!\n");
    crypto_hexdump("iv:", iv, 16);
    AES_cbc_encrypt(ciphertext, buffer, ciphertext_size, &aes_key, iv, AES_DEC);

    crypto_hexdump("buffer:", buffer, ciphertext_size);

    SPRD_CRYPTO_LOG_TRACE("get plintext_length!\n");
    plaintext_size = pkcs7_padding_data_length(buffer, ciphertext_size, 16);
    if (plaintext_size == 0 ) {
        SPRD_CRYPTO_LOG_TRACE("bad buffer!\n");
        ret = -1;
        goto err;
    }

    SPRD_CRYPTO_LOG_TRACE("plaintext_size = %d\n", plaintext_size);
    SPRD_CRYPTO_LOG_TRACE("check pad!\n");
    ret = pkcs7_padding_valid(buffer, plaintext_size, ciphertext_size, 16);
    if (ret == 0) {
        SPRD_CRYPTO_LOG_TRACE("bad pad!\n");
        ret = -1;
        goto err;
    }

    sprd_pal_memcpy(plaintext, buffer, plaintext_size);
    crypto_hexdump("plaintext:", plaintext, plaintext_size);
    free(buffer);
    return 0;

err:

    free(buffer);

    return ret;
}
