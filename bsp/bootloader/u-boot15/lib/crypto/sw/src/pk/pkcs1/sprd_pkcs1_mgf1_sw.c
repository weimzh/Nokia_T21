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

#include "sprd_pkcs1_mgf1.h"
#include <sprdsha.h>

#define MGF1_HASH_MIN SPRD_CRYPTO_HASH_SHA1
#define MGF1_HASH_MAX SPRD_CRYPTO_HASH_SHA256

#define MGF1_STORE32H(x, y) \
	do { (y)[0] = (unsigned char)(((x)>>24)&255); (y)[1] = (unsigned char)(((x)>>16)&255); \
		(y)[2] = (unsigned char)(((x)>>8)&255); (y)[3] = (unsigned char)((x)&255); } while(0)

static uint8_t buf[SPRD_CRYPTO_MAX_RSA_SIZE] __attribute__ ((aligned(8)));
static uint8_t tmp[SPRD_CRYPTO_MAX_RSA_SIZE+4] __attribute__ ((aligned(8)));
/**
  Perform PKCS #1 MGF1 (internal)
  @param hash_idx    The index of the hash desired
  @param seed        The seed for MGF1
  @param seedlen     The length of the seed
  @param mask        [out] The destination
  @param masklen     The length of the mask desired
  @return CRYPT_OK if successful
  */
uint32_t sprd_pkcs1_mgf1_sw(sprd_crypto_algo_t hash_type,
		const unsigned char *seed, unsigned long seedlen,
		unsigned char *mask, unsigned long masklen)
{
	unsigned long hLen, x;
	uint32_t counter;
	uint32_t err;

	if (seed == NULL || mask == NULL) {
		SPRD_CRYPTO_LOG_ERR("seed or mask invalid \n");
		return SPRD_CRYPTO_INVALID_ARG;
	}

	/* ensure valid hash */
	if(hash_type < MGF1_HASH_MIN || hash_type > MGF1_HASH_MAX) {
		SPRD_CRYPTO_LOG_ERR("hash_type invalid \n");
		return SPRD_CRYPTO_INVALID_ARG;
	}

	/* get hash output size */
	hLen = SPRD_HASH_SIZE(hash_type);

	sprd_pal_memset(buf, 0, SPRD_CRYPTO_MAX_RSA_SIZE);
	sprd_pal_memset(tmp, 0, SPRD_CRYPTO_MAX_RSA_SIZE+4);

	/*we asume seed is hash result*/
	if(seedlen > (SPRD_CRYPTO_MAX_RSA_SIZE)) {
		SPRD_CRYPTO_LOG_ERR("seedlen larger than max modulus size \n");
		return SPRD_CRYPTO_INVALID_ARG;
	}
	sprd_pal_memcpy(tmp, seed, seedlen);

	/* start counter */
	counter = 0;

	while (masklen > 0) {
		/* handle counter */
		MGF1_STORE32H(counter, tmp+seedlen);
		++counter;

        sprd_digest_sw((unsigned char*)tmp, seedlen+4, buf, hash_type);

		/* store it */
		for (x = 0; x < hLen && masklen > 0; x++, masklen--) {
			*mask++ = buf[x];
		}
	}

	err = SPRD_CRYPTO_SUCCESS;
LBL_ERR:

	return err;
}
