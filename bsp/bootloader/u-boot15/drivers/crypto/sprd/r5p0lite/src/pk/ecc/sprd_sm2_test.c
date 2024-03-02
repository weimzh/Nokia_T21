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

#include "sprd_sm2.h"
#include "sprd_crypto.h"
#include <lib/console.h>
#include <platform.h>

struct ecc_test_st {
	uint32_t  ecc_px    [SPRD_ECC_CURVE_MAX_WORD_LENGTH];
	uint32_t  ecc_py    [SPRD_ECC_CURVE_MAX_WORD_LENGTH];
	uint32_t  ecc_d     [SPRD_ECC_CURVE_MAX_WORD_LENGTH];
	uint32_t  ecc_r     [SPRD_ECC_CURVE_MAX_WORD_LENGTH];
	uint32_t  ecc_s     [SPRD_ECC_CURVE_MAX_WORD_LENGTH];
	uint32_t  ecc_mhash [SPRD_ECC_CURVE_MAX_WORD_LENGTH];
	uint8_t   pxy_bytelen;
	uint8_t   d_bytelen;
	uint8_t   r_bytelen;
	uint8_t   s_bytelen;
	uint8_t   mhash_bytelen;
	uint8_t   p_bytelen;
	uint8_t   n_bytelen;
	sprd_ecc_curveid_t  ecc_curve;
};

static struct ecc_test_st ecc_test_vector = {
	//px
	//0AE4C779 8AA0F119 471BEE11 825BE462 02BB79E2 A5844495 E97C04FF 4DF2548A
	{0x79c7e40a, 0x19f1a08a, 0x11ee1b47, 0x62e45b82, 0xe279bb02, 0x954484a5, 0xff047ce9, 0x8a54f24d,},
	//py
	//7C0240F8 8F1CD4E1 6352A73C 17B7F16F 07353E53 A176D684 A9FE0C6B B798E857
	{0xf840027c, 0xe1d41c8f, 0x3ca75263, 0x6ff1b717, 0x533e3507, 0x84d676a1, 0x6b0cfea9, 0x57e898b7,},
	//da
	//128B2FA8 BD433C6C 068C8D80 3DFF7979 2A519A55 171B1B65 0C23661D 15897263
	{0xa82f8b12, 0x6c3c43bd, 0x808d8c06, 0x7979ff3d, 0x559a512a, 0x651b1b17, 0x1d66230c, 0x63728915,},
	//r
	//40F1EC59 F793D9F4 9E09DCEF 49130D41 94F79FB1 EED2CAA5 5BACDB49 C4E755D1
	{0x59ecf140, 0xf4d993f7, 0xefdc099e, 0x410d1349, 0xb19ff794, 0xa5cad2ee, 0x49dbac5b, 0xd155e7c4,},
	//s
	//6FC6DAC3 2C5D5CF1 0C77DFB2 0F7C2EB6 67A45787 2FB09EC5 6327A67E C7DEEBE7
	{0xc3dac66f, 0xf15c5d2c, 0xb2df770c, 0xb62e7c0f, 0x8757a467, 0xc59eb02f, 0x7ea62763, 0xe7ebdec7,},
	//e
	//B524F552 CD82B8B0 28476E00 5C377FB1 9A87E6FC 682D48BB 5D42E3D9 B9EFFE76
	{0x52f524b5, 0xb0b882cd, 0x006e4728, 0xb17f375c, 0xfce6879a, 0xbb482d68, 0xd9e3425d, 0x76feefb9,},
	0x20,
	0x20,
	0x20,
	0x20,
	0x20,
	0x20,
	0x20,
	SPRD_ECC_CurveID_secp160k1,
};

static int sm2_verify_test(void)
{
	struct ecc_test_st *test_data = &ecc_test_vector;
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint32_t temp;
	int ret = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_signature_t rs;

	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_x, test_data->ecc_px, test_data->pxy_bytelen);
	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_y, test_data->ecc_py, test_data->pxy_bytelen);
	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memcpy(rs.ecc_r, test_data->ecc_r, test_data->r_bytelen);
	sprd_pal_memset(rs.ecc_s, 0, n_len);
	sprd_pal_memcpy(rs.ecc_s, test_data->ecc_s, test_data->s_bytelen);

	ret = sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_erify_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_verify_test pass 1\n");
	}

	temp = rs.ecc_s[0];
	rs.ecc_s[0] = 0;
	ret = sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_verify_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_verify_test fail 2\n");
		return -3;
	}

	rs.ecc_s[0] = temp;
	ecc_public_key.pubkey_y[0] = 0;
	sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_verify_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_verify_test fail 3\n");
		return -4;
	}

	return 0;
}

static int sm2_sign_test(void)
{
	struct ecc_test_st *test_data = &ecc_test_vector;
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint32_t temp;
	int ret = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	sprd_ecc_signature_t rs;

	sprd_pal_memset(ecc_private_key.prikey, 0, n_len);
	sprd_pal_memcpy(ecc_private_key.prikey, test_data->ecc_d, n_len);

	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_x, test_data->ecc_px, n_len);

	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_y, test_data->ecc_py, n_len);

	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memset(rs.ecc_s, 0, n_len);

	ret |= sprd_sm2_sign(0, &ecc_private_key, (uint8_t*)test_data->ecc_mhash,test_data->mhash_bytelen, &rs);

	ret |= sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test pass 1\n");
	}

	temp = rs.ecc_s[0];
	rs.ecc_s[0] = (temp^0xffffffff)+1;
	ret = sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test fail 2\n");
		return -3;
	}

	rs.ecc_s[0] = temp;
	ecc_public_key.pubkey_y[0] = (ecc_public_key.pubkey_y[0]^0xffffffff)+1;
	ret = sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test fail 3\n");
		return -4;
	}

	return 0;
}

static int sm2_keygen_test(void)
{
	struct ecc_test_st *test_data = &ecc_test_vector;
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint32_t temp;
	int ret = 0;
	int i;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	sprd_ecc_signature_t rs;

	for (i = 0; i < 10; i++) {
		sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
		sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
		sprd_pal_memset(ecc_private_key.prikey, 0, n_len);
		sprd_pal_memset(rs.ecc_r, 0, n_len);
		sprd_pal_memset(rs.ecc_s, 0, n_len);

		ret |= sprd_sm2_genkey(0, &ecc_private_key, &ecc_public_key);
		ret |= sprd_sm2_sign(0, &ecc_private_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
		ret |= sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
		if (ret) {
			SPRD_CRYPTO_LOG_ERR("sm2_keygen_test fail 1(the %dst time)\n", i);
			return -2;
		} else {
			SPRD_CRYPTO_LOG_ERR("sm2_keygen_test pass 1(the %dst time)\n", i);
		}
	}

	temp = rs.ecc_s[0];
	rs.ecc_s[0] = (temp^0xffffffff)+1;
	ret = sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_keygen_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_keygen_test fail 2\n");
		return -3;
	}

	rs.ecc_s[0] = temp;
	ecc_public_key.pubkey_y[0] = (ecc_public_key.pubkey_y[0]^0xffffffff)+1;
	ret = sprd_sm2_verify(0, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_keygen_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_keygen_test fail 3\n");
		return -4;
	}

	return 0;
}

static int sm2_kap_prepare_test(void)
{
	int ret = 0;
	sprd_ecc_prikey_t rA = {
		{0xc8c9a283, 0xf75a6eb9, 0xb480d40b, 0x9a9a4072, 0xf1577232, 0x5b3fb7eb, 0xb2543307, 0x63856648,},
		0,
	};
	sprd_ecc_pubkey_t RA = {
		{0x3863b56c, 0x56ddf416, 0x45ec1d0b, 0xcccb1083, 0x95c05668, 0x6d4a3205, 0x400c1523, 0xf02b168f,},
		{0x62cf6f0d, 0x0a6c03f1, 0xcfac6d1b, 0x23923957, 0x7b7d5fa6, 0x7e63d9f2, 0x85ebbb5b, 0x1abf6179,},
		0,
	};
	sprd_ecc_pubkey_t temp;

	sprd_pal_memset(&temp, 0x0, sizeof (sprd_ecc_pubkey_t));

	ret = sprd_sm2_kap_prepare(0, &rA, &temp);

	SPRD_CRYPTO_LOG_TRACE("0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
			temp.pubkey_x[0], temp.pubkey_x[1], temp.pubkey_x[2], temp.pubkey_x[3],
			temp.pubkey_x[4], temp.pubkey_x[5], temp.pubkey_x[6], temp.pubkey_x[7]);
	if ((!ret) && (sprd_pal_memcmp(&temp, &RA, sizeof(sprd_ecc_pubkey_t)) == 0)) {
		SPRD_CRYPTO_LOG_ERR("sm2_kap_prepare_test pass\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_kap_prepare_test fail\n");
		return -2;
	}

	return 0;
}

static int sm2_key_dh_test(void)
{
	int ret = 0;
	sprd_ecc_prikey_t rA = {
		{0xc8c9a283, 0xf75a6eb9, 0xb480d40b, 0x9a9a4072, 0xf1577232, 0x5b3fb7eb, 0xb2543307, 0x63856648,},
		0,
	};
	sprd_ecc_prikey_t dA = {
		{0xefa2cb6f, 0x90abe09a, 0xe3bdc32b, 0x445d91ff, 0x8fc74cba, 0xe7f8e288, 0x3b6d99f8, 0xeeedce8c,},
		0,
	};
	sprd_ecc_pubkey_t RA = {
		{0x3863b56c, 0x56ddf416, 0x45ec1d0b, 0xcccb1083, 0x95c05668, 0x6d4a3205, 0x400c1523, 0xf02b168f,},
		{0x62cf6f0d, 0x0a6c03f1, 0xcfac6d1b, 0x23923957, 0x7b7d5fa6, 0x7e63d9f2, 0x85ebbb5b, 0x1abf6179,},
		0,
	};
	sprd_ecc_pubkey_t PB = {
		{0xd4935424, 0x8c8dc346, 0x3718f1c0, 0xdfe79046, 0x4b8a3a63, 0xb52933fb, 0xb204e6ec, 0x437ff3b4,},
		{0x9f86c053, 0x77179e4b, 0xec8fe63d, 0x0449e145, 0x5ba4dee0, 0x99cfcef6, 0xa05ec818, 0x4c0ac647,},
		0,
	};
	sprd_ecc_pubkey_t RB = {
		{0xa2b29917, 0x532978c7, 0x32a2d900, 0x2961685c, 0x33b5f2b8, 0x45cf3d7b, 0xc1bbe814, 0xe50e909d},
		{0x8c28c954, 0xfd3e7382, 0xe78a80f7, 0x730e7df2, 0xa7737c2f, 0xb798acd9, 0x910a74d8, 0xf43cdbd0,},
		0,
	};
	sprd_ecc_pubkey_t UA = {
		{0x5326c847, 0xf1f6c24d, 0x2887f2fb, 0x218f65dd, 0x81f474e1, 0x29efac79, 0xf5b7f800, 0x0509e466,},
		{0xfe6ef82a, 0x2af12c73, 0x1f9ae0d0, 0x65cc5625, 0xe3cc9c0d, 0x6b8649e2, 0x46685cbb, 0x95a2c4a4,},
		0,
	};
	sprd_ecc_pubkey_t temp;

	sprd_pal_memset(&temp, 0x0, sizeof (sprd_ecc_pubkey_t));

	ret = sprd_sm2_key_dh(0, &rA, &dA, &RA, &PB, &RB, &temp);

	if ((!ret) && (sprd_pal_memcmp(&temp, &UA, sizeof(sprd_ecc_pubkey_t)) == 0)) {
		SPRD_CRYPTO_LOG_ERR("sm2_key_dh_test pass\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_key_dh_test fail\n");
		return -2;
	}

	return 0;
}

static int sm2_encrypt_decrypt_test(void)
{
	int ret = 0;

	static struct {
		sprd_ecc_pubkey_t PB;
		sprd_ecc_prikey_t dB;
		uint32_t pt_len;
		uint32_t ct_len;
		uint8_t pt[64] __attribute__ ((aligned (8)));
		uint8_t ct[192] __attribute__ ((aligned (8)));
	} tests[] = {
		{
			{
				{0xcc395b43, 0x08b5f3a8, 0xfc8a48c1, 0x1a49be67, 0x7ea07b0f, 0x480e1a58, 0x70cfa549, 0x0a7e8a62,},
				{0x78badd75, 0xcbee5ff1, 0xe295784c, 0xfef5cdc1, 0x2cbbde01, 0x53f4addb, 0x7bf7cc99, 0x426a07ba,},
				0,
			},
			{
				{0x77ab4916, 0xbd3706a0, 0x28fe2e5e, 0x3535bf3f, 0x7c7faa34, 0xf26394b8, 0x29bcdd08, 0xa00dbb20,},
				0,
			},
			19,
			116,
			{
				0x65, 0x6E, 0x63, 0x72, 0x79, 0x70, 0x74, 0x69, 0x6F, 0x6E, 0x20,
				0x73, 0x74, 0x61, 0x6E, 0x64, 0x61, 0x72, 0x64,
			},
			{
				0x04, 0x24, 0x5c, 0x26, 0xfb, 0x68, 0xb1, 0xdd, 0xdd, 0xb1, 0x2c, 0x4b, 0x6b, 0xf9, 0xf2, 0xb6,
				0xd5, 0xfe, 0x60, 0xa3, 0x83, 0xb0, 0xd1, 0x8d, 0x1c, 0x41, 0x44, 0xab, 0xf1, 0x7f, 0x62, 0x52,
				0xe7, 0x76, 0xcb, 0x92, 0x64, 0xc2, 0xa7, 0xe8, 0x8e, 0x52, 0xb1, 0x99, 0x03, 0xfd, 0xc4, 0x73,
				0x78, 0xf6, 0x05, 0xe3, 0x68, 0x11, 0xf5, 0xc0, 0x74, 0x23, 0xa2, 0x4b, 0x84, 0x40, 0x0f, 0x01,
				0xb8, 0x65, 0x00, 0x53, 0xa8, 0x9b, 0x41, 0xc4, 0x18, 0xb0, 0xc3, 0xaa, 0xd0, 0x0d, 0x88, 0x6c,
				0x00, 0x28, 0x64, 0x67, 0x9c, 0x3d, 0x73, 0x60, 0xc3, 0x01, 0x56, 0xfa, 0xb7, 0xc8, 0x0a, 0x02,
				0x76, 0x71, 0x2d, 0xa9, 0xd8, 0x09, 0x4a, 0x63, 0x4b, 0x76, 0x6d, 0x3a, 0x28, 0x5e, 0x07, 0x48,
				0x06, 0x53, 0x42, 0x6d,
			},
		},
	};

	int i;
	uint8_t tmp[200] = {0};
	uint8_t tmp1[200] = {0};
	uint32_t tmp_size;

	for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++) {
		ret |= sprd_sm2_public_encrypt(0, &tests[i].PB, tests[i].pt, tests[i].pt_len, tmp, &tmp_size);
		ret |= sprd_sm2_private_decrypt(0, &tests[i].dB, tmp, tests[i].ct_len, tmp1, &tmp_size);

		if ((!ret) && (tmp_size == tests[i].pt_len) &&(sprd_pal_memcmp(&tmp1, tests[i].pt, tmp_size) == 0)) {
			SPRD_CRYPTO_LOG_ERR("sm2_encrypt_decrypt_test pass\n");
		} else {
			SPRD_CRYPTO_LOG_ERR("sm2_encrypt_decrypt_test fail\n");
			return -2;
		}
	}

	return 0;
}

#ifdef CE_PERFORMANCE_TEST
static int sm2_verify_speed_test(void)
{
	struct ecc_test_st *test_data = &ecc_test_vector;
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	int ret = 0, n = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_signature_t rs;
	lk_bigtime_t start, elapsed = 0;

	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_x, test_data->ecc_px, test_data->pxy_bytelen);
	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_y, test_data->ecc_py, test_data->pxy_bytelen);
	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memcpy(rs.ecc_r, test_data->ecc_r, test_data->r_bytelen);
	sprd_pal_memset(rs.ecc_s, 0, n_len);
	sprd_pal_memcpy(rs.ecc_s, test_data->ecc_s, test_data->s_bytelen);

	for (n = 0; n < 1000; n++) {
	start = current_time_hires();
	ret = sprd_sm2_verify(0, &ecc_public_key,
			(uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	elapsed += current_time_hires() - start;
	}

	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_erify_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_verify_test pass 1\n");
		SPRD_CRYPTO_LOG_ERR("%d sm2_verify test time is [%lld] \n", p_len, elapsed/1000);
	}
	elapsed = 0;

	return 0;
}

static int sm2_sign_speed_test(void)
{
	struct ecc_test_st *test_data = &ecc_test_vector;
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	int ret = 0, n = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	sprd_ecc_signature_t rs;
	lk_bigtime_t start, elapsed = 0;

	sprd_pal_memset(ecc_private_key.prikey, 0, n_len);
	sprd_pal_memcpy(ecc_private_key.prikey, test_data->ecc_d, n_len);

	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_x, test_data->ecc_px, n_len);

	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_y, test_data->ecc_py, n_len);

	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memset(rs.ecc_s, 0, n_len);

	for (n = 0; n < 1000; n++) {
	start = current_time_hires();
	ret |= sprd_sm2_sign(0, &ecc_private_key,
			(uint8_t*)test_data->ecc_mhash,
			test_data->mhash_bytelen, &rs);
	elapsed += current_time_hires() - start;
	}

	ret |= sprd_sm2_verify(0, &ecc_public_key,
			(uint8_t*)test_data->ecc_mhash,
			test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_sign_test pass 1\n");
		SPRD_CRYPTO_LOG_ERR("%d sm2_sign test time is [%lld] \n",
				p_len, elapsed/1000);
	}
	elapsed = 0;
	return 0;
}

static int sm2_keygen_speed_test(void)
{
	struct ecc_test_st *test_data = &ecc_test_vector;
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	int ret = 0, n = 0;
	int i;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	sprd_ecc_signature_t rs;
	lk_bigtime_t start, elapsed = 0;

	for (i = 0; i < 1; i++) {
		sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
		sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
		sprd_pal_memset(ecc_private_key.prikey, 0, n_len);
		sprd_pal_memset(rs.ecc_r, 0, n_len);
		sprd_pal_memset(rs.ecc_s, 0, n_len);

		for (n = 0; n < 1000; n++) {
		start = current_time_hires();
		ret |= sprd_sm2_genkey(0, &ecc_private_key, &ecc_public_key);
		elapsed += current_time_hires() - start;
		}
		ret |= sprd_sm2_sign(0, &ecc_private_key,
				(uint8_t*)test_data->ecc_mhash,
				test_data->mhash_bytelen, &rs);
		ret |= sprd_sm2_verify(0, &ecc_public_key,
				(uint8_t*)test_data->ecc_mhash,
				test_data->mhash_bytelen, &rs);
		if (ret) {
			SPRD_CRYPTO_LOG_ERR("sm2_keygen_test fail 1(the %dst time)\n", i);
			return -2;
		} else {
			SPRD_CRYPTO_LOG_ERR("sm2_keygen_test pass 1(the %dst time)\n", i);
			SPRD_CRYPTO_LOG_ERR("%d sm2_keygen test time is [%lld] \n",
					p_len, elapsed/1000);
		}
		elapsed = 0;
	}

	return 0;
}
#if 0

static int sm2_kap_prepare_speed_test(void)
{
	int ret = 0;
	sprd_ecc_prikey_t rA = {
		{0xc8c9a283, 0xf75a6eb9, 0xb480d40b, 0x9a9a4072, 0xf1577232, 0x5b3fb7eb, 0xb2543307, 0x63856648,},
		0,
	};
	sprd_ecc_pubkey_t RA = {
		{0x3863b56c, 0x56ddf416, 0x45ec1d0b, 0xcccb1083, 0x95c05668, 0x6d4a3205, 0x400c1523, 0xf02b168f,},
		{0x62cf6f0d, 0x0a6c03f1, 0xcfac6d1b, 0x23923957, 0x7b7d5fa6, 0x7e63d9f2, 0x85ebbb5b, 0x1abf6179,},
		0,
	};
	sprd_ecc_pubkey_t temp;

	sprd_pal_memset(&temp, 0x0, sizeof (sprd_ecc_pubkey_t));

	ret = sprd_sm2_kap_prepare(0, &rA, &temp);

	SPRD_CRYPTO_LOG_TRACE("0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
			temp.pubkey_x[0], temp.pubkey_x[1], temp.pubkey_x[2], temp.pubkey_x[3],
			temp.pubkey_x[4], temp.pubkey_x[5], temp.pubkey_x[6], temp.pubkey_x[7]);
	if ((!ret) && (sprd_pal_memcmp(&temp, &RA, sizeof(sprd_ecc_pubkey_t)) == 0)) {
		SPRD_CRYPTO_LOG_ERR("sm2_kap_prepare_test pass\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_kap_prepare_test fail\n");
		return -2;
	}

	return 0;
}

static int sm2_key_dh_speed_test(void)
{
	int ret = 0;
	sprd_ecc_prikey_t rA = {
		{0xc8c9a283, 0xf75a6eb9, 0xb480d40b, 0x9a9a4072, 0xf1577232, 0x5b3fb7eb, 0xb2543307, 0x63856648,},
		0,
	};
	sprd_ecc_prikey_t dA = {
		{0xefa2cb6f, 0x90abe09a, 0xe3bdc32b, 0x445d91ff, 0x8fc74cba, 0xe7f8e288, 0x3b6d99f8, 0xeeedce8c,},
		0,
	};
	sprd_ecc_pubkey_t RA = {
		{0x3863b56c, 0x56ddf416, 0x45ec1d0b, 0xcccb1083, 0x95c05668, 0x6d4a3205, 0x400c1523, 0xf02b168f,},
		{0x62cf6f0d, 0x0a6c03f1, 0xcfac6d1b, 0x23923957, 0x7b7d5fa6, 0x7e63d9f2, 0x85ebbb5b, 0x1abf6179,},
		0,
	};
	sprd_ecc_pubkey_t PB = {
		{0xd4935424, 0x8c8dc346, 0x3718f1c0, 0xdfe79046, 0x4b8a3a63, 0xb52933fb, 0xb204e6ec, 0x437ff3b4,},
		{0x9f86c053, 0x77179e4b, 0xec8fe63d, 0x0449e145, 0x5ba4dee0, 0x99cfcef6, 0xa05ec818, 0x4c0ac647,},
		0,
	};
	sprd_ecc_pubkey_t RB = {
		{0xa2b29917, 0x532978c7, 0x32a2d900, 0x2961685c, 0x33b5f2b8, 0x45cf3d7b, 0xc1bbe814, 0xe50e909d},
		{0x8c28c954, 0xfd3e7382, 0xe78a80f7, 0x730e7df2, 0xa7737c2f, 0xb798acd9, 0x910a74d8, 0xf43cdbd0,},
		0,
	};
	sprd_ecc_pubkey_t UA = {
		{0x5326c847, 0xf1f6c24d, 0x2887f2fb, 0x218f65dd, 0x81f474e1, 0x29efac79, 0xf5b7f800, 0x0509e466,},
		{0xfe6ef82a, 0x2af12c73, 0x1f9ae0d0, 0x65cc5625, 0xe3cc9c0d, 0x6b8649e2, 0x46685cbb, 0x95a2c4a4,},
		0,
	};
	sprd_ecc_pubkey_t temp;

	sprd_pal_memset(&temp, 0x0, sizeof (sprd_ecc_pubkey_t));

	ret = sprd_sm2_key_dh(0, &rA, &dA, &RA, &PB, &RB, &temp);

	if ((!ret) && (sprd_pal_memcmp(&temp, &UA, sizeof(sprd_ecc_pubkey_t)) == 0)) {
		SPRD_CRYPTO_LOG_ERR("sm2_key_dh_test pass\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("sm2_key_dh_test fail\n");
		return -2;
	}

	return 0;
}
#endif
static int sm2_encrypt_decrypt_speed_test(void)
{
	int ret = 0;

	static struct {
		sprd_ecc_pubkey_t PB;
		sprd_ecc_prikey_t dB;
		uint32_t pt_len;
		uint32_t ct_len;
		uint8_t pt[64] __attribute__ ((aligned (8)));
		uint8_t ct[192] __attribute__ ((aligned (8)));
	} tests[] = {
		{
			{
				{	0xcc395b43, 0x08b5f3a8, 0xfc8a48c1, 0x1a49be67,
					0x7ea07b0f, 0x480e1a58, 0x70cfa549, 0x0a7e8a62,},
				{	0x78badd75, 0xcbee5ff1, 0xe295784c, 0xfef5cdc1,
					0x2cbbde01, 0x53f4addb, 0x7bf7cc99, 0x426a07ba,},
				0,
			},
			{
				{	0x77ab4916, 0xbd3706a0, 0x28fe2e5e, 0x3535bf3f,
					0x7c7faa34, 0xf26394b8, 0x29bcdd08, 0xa00dbb20,},
				0,
			},
			19,
			116,
			{
				0x65, 0x6E, 0x63, 0x72, 0x79, 0x70, 0x74, 0x69,
				0x6F, 0x6E, 0x20, 0x73, 0x74, 0x61, 0x6E, 0x64,
				0x61, 0x72, 0x64,
			},
			{
				0x04, 0x24, 0x5c, 0x26, 0xfb, 0x68, 0xb1, 0xdd,
				0xdd, 0xb1, 0x2c, 0x4b, 0x6b, 0xf9, 0xf2, 0xb6,
				0xd5, 0xfe, 0x60, 0xa3, 0x83, 0xb0, 0xd1, 0x8d,
				0x1c, 0x41, 0x44, 0xab, 0xf1, 0x7f, 0x62, 0x52,
				0xe7, 0x76, 0xcb, 0x92, 0x64, 0xc2, 0xa7, 0xe8,
				0x8e, 0x52, 0xb1, 0x99, 0x03, 0xfd, 0xc4, 0x73,
				0x78, 0xf6, 0x05, 0xe3, 0x68, 0x11, 0xf5, 0xc0,
				0x74, 0x23, 0xa2, 0x4b, 0x84, 0x40, 0x0f, 0x01,
				0xb8, 0x65, 0x00, 0x53, 0xa8, 0x9b, 0x41, 0xc4,
				0x18, 0xb0, 0xc3, 0xaa, 0xd0, 0x0d, 0x88, 0x6c,
				0x00, 0x28, 0x64, 0x67, 0x9c, 0x3d, 0x73, 0x60,
				0xc3, 0x01, 0x56, 0xfa, 0xb7, 0xc8, 0x0a, 0x02,
				0x76, 0x71, 0x2d, 0xa9, 0xd8, 0x09, 0x4a, 0x63,
				0x4b, 0x76, 0x6d, 0x3a, 0x28, 0x5e, 0x07, 0x48,
				0x06, 0x53, 0x42, 0x6d,
			},
		},
	};

	int i, n = 0;
	uint8_t tmp[200] = {0};
	uint8_t tmp1[200] = {0};
	uint32_t tmp_size;
	lk_bigtime_t start, elapsed = 0, elapsed2 = 0;

	for (i = 0; i < (int)(sizeof(tests)/sizeof(tests[0])); i++) {
		for (n = 0; n < 1000; n++) {
			start = current_time_hires();
			ret |= sprd_sm2_public_encrypt(0, &tests[i].PB, tests[i].pt,
					tests[i].pt_len, tmp, &tmp_size);
			elapsed += current_time_hires() - start;
			start = current_time_hires();
			ret |= sprd_sm2_private_decrypt(0, &tests[i].dB, tmp,
					tests[i].ct_len, tmp1, &tmp_size);
			elapsed2 += current_time_hires() - start;
		}
		if ((!ret) && (tmp_size == tests[i].pt_len)
				&&(sprd_pal_memcmp(&tmp1, tests[i].pt, tmp_size) == 0)) {
			SPRD_CRYPTO_LOG_ERR("sm2_encrypt_decrypt_test pass\n");
			SPRD_CRYPTO_LOG_ERR("%d sm2_enc test time is [%lld] \n",
					tests[i].pt_len, elapsed/1000);
			SPRD_CRYPTO_LOG_ERR("%d sm2_dec test time is [%lld] \n",
					tests[i].pt_len, elapsed2/1000);
		} else {
			SPRD_CRYPTO_LOG_ERR("sm2_encrypt_decrypt_test fail\n");
			return -2;
		}
		elapsed = 0;
		elapsed2 = 0;
	}

	return 0;
}

int32_t sprd_sm2_speed_test(void)
{
	sprd_crypto_err_t err = SPRD_CRYPTO_SUCCESS;
	int32_t  sm2_keygen = 0, sm2_sign = 0, sm2_verify = 0, sm2_dh = 0;
	int32_t  sm2_kap_prepare = 0, sm2_enc_dec = 0;

	err = sm2_keygen_speed_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_keygen_speed_test FAILED!****\n");
		goto failed;
	} else {
		sm2_keygen = 1;
	}

	err = sm2_sign_speed_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_sign_speed_test FAILED!****\n");
		goto failed;
	} else {
		sm2_sign = 1;
	}

	err = sm2_verify_speed_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_verify_speed_test FAILED!****\n");
		goto failed;
	} else {
		sm2_verify = 1;
	}

#if 0
	err = sm2_kap_prepare_speed_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_kap_prepare_speed_test FAILED!****\n");
		goto failed;
	} else {
		sm2_kap_prepare = 1;
	}

	err = sm2_key_dh_speed_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_key_dh_speed_test FAILED!****\n");
		goto failed;
	} else {
		sm2_dh = 1;
	}
#endif

	err = sm2_encrypt_decrypt_speed_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_encrypt_decrypt_speed_test FAILED!****\n");
		goto failed;
	} else {
		sm2_enc_dec = 1;
	}

failed:
	if (sm2_keygen == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_keygen_speed_test pass!\n");
	}
	if (sm2_sign == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_sign_speed_test pass!\n");
	}
	if (sm2_verify == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_verify_speed_test pass!\n");
	}
	if (sm2_dh == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_dh_speed_test pass!\n");
	}
#if 0
	if (sm2_getZ == 1) {
		SPRD_CRYPTO_LOG_WARN("SM2_GetZ_test pass!\n");
	}
#endif
	if (sm2_kap_prepare == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_kap_prepare_test pass!\n");
	}
	if (sm2_enc_dec == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_encrypt_decrypt_test pass!\n");
	}

	return err;
}
#endif

int32_t sprd_sm2_test(void)
{
	sprd_crypto_err_t err = SPRD_CRYPTO_SUCCESS;
	int32_t  sm2_keygen = 0, sm2_sign = 0, sm2_verify = 0, sm2_dh = 0;
	int32_t  sm2_kap_prepare = 0, sm2_enc_dec = 0;

	err = sm2_keygen_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_keygen_test FAILED!****\n");
		goto failed;
	} else {
		sm2_keygen = 1;
	}

	err = sm2_sign_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_sign_test FAILED!****\n");
		goto failed;
	} else {
		sm2_sign = 1;
	}

	err = sm2_verify_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_verify_test FAILED!****\n");
		goto failed;
	} else {
		sm2_verify = 1;
	}

	err = sm2_kap_prepare_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_kap_prepare_test FAILED!****\n");
		goto failed;
	} else {
		sm2_kap_prepare = 1;
	}

	err = sm2_key_dh_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_key_dh_test FAILED!****\n");
		goto failed;
	} else {
		sm2_dh = 1;
	}

	err = sm2_encrypt_decrypt_test();
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("****sm2_encrypt_decrypt_test FAILED!****\n");
		goto failed;
	} else {
		sm2_enc_dec = 1;
	}

failed:
	if (sm2_keygen == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_keygen_test pass!\n");
	}
	if (sm2_sign == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_sign_test pass!\n");
	}
	if (sm2_verify == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_verify_test pass!\n");
	}
	if (sm2_dh == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_dh_test pass!\n");
	}
#if 0
	if (sm2_getZ == 1) {
		SPRD_CRYPTO_LOG_WARN("SM2_GetZ_test pass!\n");
	}
#endif
	if (sm2_kap_prepare == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_kap_prepare_test pass!\n");
	}
	if (sm2_enc_dec == 1) {
		SPRD_CRYPTO_LOG_WARN("sm2_encrypt_decrypt_test pass!\n");
	}

	return err;
}

STATIC_COMMAND_START
STATIC_COMMAND("sprd_sm2_test", "ce algorithm hmac test", (console_cmd)&sprd_sm2_test)
#ifdef CE_PERFORMANCE_TEST
STATIC_COMMAND("sprd_sm2_speed_test", "ce algorithm hmac test", (console_cmd)&sprd_sm2_speed_test)
#endif
STATIC_COMMAND_END(sprd_sm2_test);
