/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef AES_H
#define AES_H

//#include <stdint.h>
#include <sprd_crypto_sw.h>
#include <malloc.h>

enum AES_KEYSIZE {
    AES_KEYSIZE_128 = 0,
    AES_KEYSIZE_192,
    AES_KEYSIZE_256
};

#if HW_AES_IMPL

// XXX get from a better source?
typedef struct {
    enum AES_KEYSIZE size;
    uint8_t key[256/8];
} AES_KEY;

#else // software implementation

struct aes_key_struct_sw {
    unsigned long rd_key[60];
    int rounds;
};

typedef struct aes_key_struct_sw AES_KEY;

#endif

#define AES_BLOCK_SIZE 16

#define AES_ENC 1
#define AES_DEC 0

int AES_set_encrypt_key(const unsigned char *userKey, const int bits,
                            AES_KEY *key);

int AES_set_decrypt_key(const unsigned char *userKey, const int bits,
                             AES_KEY *key);

void AES_decrypt(const unsigned char *in, unsigned char *out,
                         const AES_KEY *key);

void AES_encrypt(const unsigned char *in, unsigned char *out,
                         const AES_KEY *key);

void AES_cbc_encrypt(const uint8_t *in, uint8_t *out, size_t len, const AES_KEY *key, uint8_t *ivec, const int enc);

int aes256_cbc_encrypt_pkcs7(const uint8_t *key, const uint8_t *iv, const uint8_t *plaintext, uint32_t plaintext_size, uint8_t *ciphertext);

int aes256_cbc_decrypt_pkcs7(const uint8_t *key, const uint8_t *iv, const uint8_t *ciphertext, uint32_t ciphertext_size, uint8_t *plaintext);

#endif
