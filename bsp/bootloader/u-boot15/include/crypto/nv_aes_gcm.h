#ifndef _NV_AES_GCM_H
#define _NV_AES_GCM_H

#define GET_UID_FAILED -1
#define CRYPT_SUCCESSED 0
#define CRYPT_FAILED -2

/* GET UID */
int sprd_get_chip_hex_uid (char *buf);

/* HASH256 */
void sha256_csum_wd_sw (const unsigned char *input,unsigned int ilen,unsigned char *output,unsigned int chunk_sz);

/*
 * [IN]input : data to encrypt(decrypt)
 * [IN]input_bytelen : byte length of input
 * [OUT]output : data after encrypt(encrypt)
 * [OUT]output_bytelen : byte length of output
 */
int nv_aes_gcm(unsigned char *input, int input_bytelen, unsigned char *output, int *output_bytelen);
#endif
