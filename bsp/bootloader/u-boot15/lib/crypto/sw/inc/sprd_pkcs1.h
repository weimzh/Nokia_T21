/*
 * Copyright (c) 2019, Spreadtrum Communications.
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

#ifndef SPRD_PKCS1_H
#define SPRD_PKCS1_H

#include <sprd_crypto_sw.h>

enum sprd_pkcs_1_v1_5_padding_type
{
	SPRD_PKCS_1_EMSA   = 1,        /* Block type 1 (PKCS #1 v1.5 signature padding) */
	SPRD_PKCS_1_EME    = 2         /* Block type 2 (PKCS #1 v1.5 encryption padding) */
};

uint32_t sprd_pkcs1_v1_5_decode_sw(const uint8_t *msg,
		uint32_t msglen,
		int32_t block_type,
		uint32_t modulus_len,
		uint8_t *out,
		uint32_t *outlen,
		int32_t *is_valid);

uint32_t sprd_pkcs1_pss_encode_sw(const uint8_t *msghash, uint32_t msghashlen,
                             int saltlen, sprd_crypto_algo_t hash_type, sprd_crypto_algo_t mgf1_hash_type,
                             uint32_t modulus_bitlen,
                             uint8_t *out, uint32_t *outlen);

uint32_t sprd_pkcs1_pss_decode_sw(const uint8_t *msghash, uint32_t msghashlen,
		const uint8_t *sig, uint32_t siglen,
		int saltlen, sprd_crypto_algo_t hash_type, sprd_crypto_algo_t mgf1_hash_type,
		uint32_t modulus_bitlen, int *res);
uint32_t sprd_pkcs1_oaep_encode_sw(const unsigned char *msg, unsigned long msglen,
                             const unsigned char *lparam, unsigned long lparamlen,
                             unsigned long modulus_bitlen, sprd_crypto_algo_t hash_type, sprd_crypto_algo_t mgf1_hash_type,
                             unsigned char *out, unsigned long *outlen);

uint32_t sprd_pkcs1_oaep_decode_sw(const unsigned char *msg, unsigned long msglen,
                             const unsigned char *lparam, unsigned long lparamlen,
                             unsigned long modulus_bitlen, sprd_crypto_algo_t hash_type, sprd_crypto_algo_t mgf1_hash_type,
                             unsigned char *out, unsigned long *outlen, int *res);

#endif /* SPRD_PKCS1_H*/
