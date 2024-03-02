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

#ifndef AES_LOCL_H
#define AES_LOCL_H

#define GETU32(p) (((u32)(p)[3]) ^ ((u32)(p)[2] << 8) ^ ((u32)(p)[1] << 16) ^ ((u32)(p)[0] << 24))

#define PUTU32(c, s) { (c)[3] = (u8)(s); (c)[2] = (u8)((s)>>8); (c)[1] = (u8)((s)>>16); (c)[0] = (u8)((s)>>24); }

//typedef unsigned long u32;
//typedef unsigned short u16;
//typedef unsigned char u8;

#define MAXKC   (256/32)
#define MAXKB   (256/8)
#define MAXNR   14

#define STRICT_ALIGNMENT 1

static inline size_t load_word_le(const void *in) {
   size_t v;
   sprd_pal_memcpy(&v, in, sizeof(v));
   return v;
}

static inline void store_word_le(void *out, size_t v) {
   sprd_pal_memcpy(out, &v, sizeof(v));
}

typedef void (*block128_f)(const uint8_t in[16], uint8_t out[16], const void *key);

typedef void (*ctr128_f)(const uint8_t *in, uint8_t *out, size_t blocks,
                                 const void *key, const uint8_t ivec[16]);

void CRYPTO_cbc128_encrypt(const uint8_t *in, uint8_t *out, size_t len, const void *key, uint8_t ivec[16], block128_f block);

#undef FULL_UNROLL

#endif
