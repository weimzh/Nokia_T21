/*
* Copyright (c) 2017, Spreadtrum Communications.
*
* The above copyright notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <sprd_crypto_sw.h>
#include <sprdsha.h>
#include <sha1_rng.h>
#include "sprd_pkcs1_mgf1.h"

#define OAEP_HASH_MIN SPRD_CRYPTO_HASH_SHA1
#define OAEP_HASH_MAX SPRD_CRYPTO_HASH_SHA256

/**
  PKCS #1 v2.00 OAEP encode
  @param msg             The data to encode
  @param msglen          The length of the data to encode (octets)
  @param lparam          A session or system parameter (can be NULL)
  @param lparamlen       The length of the lparam data
  @param modulus_bitlen  The bit length of the RSA modulus
  @param hash_type       The index of the hash desired
  @param mgf1_hash_type  The index of the mgf1 hash desired
  @param out             [out] The destination for the encoded data
  @param outlen          [in/out] The max size and resulting size of the encoded data
  @return SPRD_CRYPTO_SUCCESS if successful
*/
uint32_t sprd_pkcs1_oaep_encode_sw(const unsigned char *msg, unsigned long msglen,
                       const unsigned char *lparam, unsigned long lparamlen,
                             unsigned long modulus_bitlen, sprd_crypto_algo_t hash_type, sprd_crypto_algo_t mgf1_hash_type,
                             unsigned char *out, unsigned long *outlen)
{
    unsigned char *DB, *seed, *mask;
    unsigned long hLen, x, y, modulus_len;
	hash_state md;
	uint32_t err;

    if (msg == NULL || out == NULL || outlen == NULL) {
        SPRD_CRYPTO_LOG_ERR("msghash or out or outlen invalid \n");
        return SPRD_CRYPTO_INVALID_ARG;
    }

    /* test valid hash */
    if(hash_type < OAEP_HASH_MIN || hash_type > OAEP_HASH_MAX) {
        SPRD_CRYPTO_LOG_ERR("hash_type invalid \n");
        return SPRD_CRYPTO_INVALID_ARG;
    }

    hLen        = SPRD_HASH_SIZE(hash_type);
    modulus_len = (modulus_bitlen >> 3) + (modulus_bitlen & 7 ? 1 : 0);
    /* test message size */
    if ((2*hLen >= (modulus_len - 2)) || (msglen > (modulus_len - 2*hLen - 2))) {
        SPRD_CRYPTO_LOG_ERR("pk length invalid \n");
        return SPRD_CRYPTO_INVALID_ARG;
    }

    /* allocate ram for DB/mask/salt of size modulus_len */
    DB   = sprd_pal_malloc(modulus_len);
    mask = sprd_pal_malloc(modulus_len);
    seed = sprd_pal_malloc(hLen);

    if (DB == NULL || mask == NULL || seed == NULL) {
        if (DB != NULL) {
            sprd_pal_free(DB);
        }
        if (mask != NULL) {
            sprd_pal_free(mask);
        }
        if (seed != NULL) {
            sprd_pal_free(seed);
        }
        return SPRD_CRYPTO_OUTOFMEM;
    }

    sprd_pal_memset(DB, 0, modulus_len);
    sprd_pal_memset(mask, 0, modulus_len);
    sprd_pal_memset(seed, 0, hLen);

    /* get lhash */
    /* DB == lhash || PS || 0x01 || M, PS == k - mlen - 2hlen - 2 zeroes */
    if ((err = sprd_digest_init(&md, hash_type)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }
    if (lparam != NULL) {
        if ((err = sprd_digest_process(&md, lparam, lparamlen, hash_type)) != SPRD_CRYPTO_SUCCESS) {
            goto LBL_ERR;
        }
    } else {
        /* can't pass hash_memory a NULL so use DB with zero length */
        if ((err = sprd_digest_process(&md, DB, 0, hash_type)) != SPRD_CRYPTO_SUCCESS) {
            goto LBL_ERR;
        }
    }
    if ((err = sprd_digest_done(&md, DB, hash_type)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }

    /* append PS then 0x01 (to lhash)  */
    x = hLen;
    y = modulus_len - msglen - 2 * hLen - 2;
    sprd_pal_memset(DB + x, 0, y);
    x += y;

    /* 0x01 byte */
    DB[x++] = 0x01;

    /* message (length = msglen) */
    sprd_pal_memcpy(DB + x, msg, msglen);

    /* now choose a random seed */
    err = prand_gen(seed, hLen);
    if (err != SPRD_CRYPTO_SUCCESS) {
        SPRD_CRYPTO_LOG_ERR("get rng failed\n");
        goto LBL_ERR;
    }

    /* compute MGF1 of seed (k - hlen - 1) */
    if ((err = sprd_pkcs1_mgf1_sw(mgf1_hash_type, seed, hLen, mask, modulus_len - hLen - 1)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }

    /* xor against DB */
    for (y = 0; y < (modulus_len - hLen - 1); y++) {
        DB[y] ^= mask[y];
    }

   /* compute MGF1 of maskedDB (hLen) */
    if ((err = sprd_pkcs1_mgf1_sw(mgf1_hash_type, DB, modulus_len - hLen - 1, mask, hLen)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }

   /* XOR against seed */
    for (y = 0; y < hLen; y++) {
        seed[y] ^= mask[y];
    }

    /* create string of length modulus_len */
    if (*outlen < modulus_len) {
        *outlen = modulus_len;
        err = SPRD_CRYPTO_SHORT_BUFFER;
        goto LBL_ERR;
    }

   /* start output which is 0x00 || maskedSeed || maskedDB */
    x = 0;
    out[x++] = 0x00;
    sprd_pal_memcpy(out+x, seed, hLen);
    x += hLen;
    sprd_pal_memcpy(out+x, DB, modulus_len - hLen - 1);
    x += modulus_len - hLen - 1;

    *outlen = x;

    err = SPRD_CRYPTO_SUCCESS;
LBL_ERR:

    sprd_pal_free(seed);
    sprd_pal_free(mask);
    sprd_pal_free(DB);

    return err;
}

/**
   PKCS #1 v2.00 OAEP decode
   @param msg              The encoded data to decode
   @param msglen           The length of the encoded data (octets)
   @param lparam           The session or system data (can be NULL)
   @param lparamlen        The length of the lparam
   @param modulus_bitlen   The bit length of the RSA modulus
   @param hash_type        The index of the hash desired
   @param mgf1_hash_type   The index of the mgf1 hash desired
   @param out              [out] Destination of decoding
   @param outlen           [in/out] The max size and resulting size of the decoding
   @param res              [out] Result of decoding, 1==valid, 0==invalid
   @return SPRD_CRYPTO_SUCCESS if successful
*/
uint32_t sprd_pkcs1_oaep_decode_sw(const unsigned char *msg, unsigned long msglen,
                       const unsigned char *lparam, unsigned long lparamlen,
                             unsigned long modulus_bitlen, sprd_crypto_algo_t hash_type, sprd_crypto_algo_t mgf1_hash_type,
                             unsigned char *out, unsigned long *outlen, int *res)
{
    unsigned char *DB, *seed, *mask;
    unsigned long hLen, x, y, modulus_len;
	hash_state md;
    uint32_t err, ret;

    if (msg == NULL || out == NULL || outlen == NULL || res == NULL) {
        SPRD_CRYPTO_LOG_ERR("msg or out or outlen or res invalid \n");
        return SPRD_CRYPTO_INVALID_ARG;
    }

    /* test valid hash */
    if(hash_type < OAEP_HASH_MIN || hash_type > OAEP_HASH_MAX) {
        SPRD_CRYPTO_LOG_ERR("hash_type invalid \n");
        return SPRD_CRYPTO_INVALID_ARG;
    }

    hLen        = SPRD_HASH_SIZE(hash_type);
    modulus_len = (modulus_bitlen >> 3) + (modulus_bitlen & 7 ? 1 : 0);

    /* test hash/message size */
    if ((2*hLen >= (modulus_len - 2)) || (msglen != modulus_len)) {
        SPRD_CRYPTO_LOG_ERR("pk length invalid \n");
        return SPRD_CRYPTO_INVALID_ARG;
    }

    /* allocate ram for DB/mask/salt of size modulus_len */
    DB   = sprd_pal_malloc(modulus_len);
    mask = sprd_pal_malloc(modulus_len);
    seed = sprd_pal_malloc(hLen);

    if (DB == NULL || mask == NULL || seed == NULL) {
        if (DB != NULL) {
            sprd_pal_free(DB);
        }
        if (mask != NULL) {
            sprd_pal_free(mask);
        }
        if (seed != NULL) {
            sprd_pal_free(seed);
        }
        return SPRD_CRYPTO_OUTOFMEM;
    }

    sprd_pal_memset(DB, 0, modulus_len);
    sprd_pal_memset(mask, 0, modulus_len);
    sprd_pal_memset(seed, 0, hLen);

    /* ok so it's now in the form

      0x00  || maskedseed || maskedDB

       1    ||   hLen     ||  modulus_len - hLen - 1

    */

    ret = SPRD_CRYPTO_SUCCESS;

    /* must have leading 0x00 byte */
    if (msg[0] != 0x00) {
        ret = SPRD_CRYPTO_INVALID_PACKET;
    }

    /* now read the masked seed */
    x = 1;
    sprd_pal_memcpy(seed, msg + x, hLen);
    x += hLen;

    /* now read the masked DB */
    sprd_pal_memcpy(DB, msg + x, modulus_len - hLen - 1);

    /* compute MGF1 of maskedDB (hLen) */
    if ((err = sprd_pkcs1_mgf1_sw(mgf1_hash_type, DB, modulus_len - hLen - 1, mask, hLen)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }

    /* XOR against seed */
    for (y = 0; y < hLen; y++) {
        seed[y] ^= mask[y];
    }

    /* compute MGF1 of seed (k - hlen - 1) */
    if ((err = sprd_pkcs1_mgf1_sw(mgf1_hash_type, seed, hLen, mask, modulus_len - hLen - 1)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }

    /* xor against DB */
    for (y = 0; y < (modulus_len - hLen - 1); y++) {
        DB[y] ^= mask[y];
    }

    /* now DB == lhash || PS || 0x01 || M, PS == k - mlen - 2hlen - 2 zeroes */

    /* compute lhash and store it in seed [reuse temps!] */
    if ((err = sprd_digest_init(&md, hash_type)) != SPRD_CRYPTO_SUCCESS) {
        goto LBL_ERR;
    }
    if (lparam != NULL) {
        if ((err = sprd_digest_process(&md, lparam, lparamlen, hash_type)) != SPRD_CRYPTO_SUCCESS) {
            goto LBL_ERR;
        }
        if ((err = sprd_digest_done(&md, seed, hash_type)) != SPRD_CRYPTO_SUCCESS) {
            goto LBL_ERR;
        }

    } else {
      /* can't pass hash_memory a NULL so use DB with zero length */
        if ((err = sprd_digest_process(&md, DB, 0, hash_type)) != SPRD_CRYPTO_SUCCESS) {
            goto LBL_ERR;
        }
        if ((err = sprd_digest_done(&md, seed, hash_type)) != SPRD_CRYPTO_SUCCESS) {
            goto LBL_ERR;
        }
    }

    /* compare the lhash'es */
    if (sprd_pal_memcmp(seed, DB, hLen) != 0) {
        ret = SPRD_CRYPTO_INVALID_PACKET;
    }

    /* now zeroes before a 0x01 */
    for (x = hLen; x < (modulus_len - hLen - 1) && DB[x] == 0x00; x++) {
        /* step... */
    }

    /* error if wasn't 0x01 */
    if (x == (modulus_len - hLen - 1) || DB[x] != 0x01) {
        ret = SPRD_CRYPTO_INVALID_PACKET;
    }

    /* rest is the message (and skip 0x01) */
    if ((modulus_len - hLen - 1 - ++x) > *outlen) {
        ret = SPRD_CRYPTO_INVALID_PACKET;
    }

    if (ret == SPRD_CRYPTO_SUCCESS) {
        /* copy message */
        *outlen = modulus_len - hLen - 1 - x;
        sprd_pal_memcpy(out, DB + x, modulus_len - hLen - 1 - x);

        /* valid packet */
        *res = 1;
    }
    err = ret;

LBL_ERR:
    sprd_pal_free(seed);
    sprd_pal_free(mask);
    sprd_pal_free(DB);

    return err;
}
