/*
* Copyright (c) 2016, Spreadtrum Communications.
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
*
*/

#include "sprd_ecc_test.h"
#include <sprd_ecc.h>

#ifndef TEST_LOOP_TIMES
#define TEST_LOOP_TIMES  1
#endif

#if SPRD_ECC_TEST
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

struct ecc_test_st ecc_test_vector[] = {
	{
		{0xB8CA93D3, 0x49ED098A, 0x3A8C62C4, 0x49EE70E3, 0x1161706E,},
		{0xF9C29244, 0x644B55A4, 0x5FCA463C, 0xE3F9D37A, 0xE6205A1A,},
		{0x1343ABE2, 0x8D8288A1, 0xCB9BF564, 0x1ABE6B5B, 0x20215874,},
		{0x3C234D0C, 0x62C1AB27, 0x324F7FF1, 0x0A6FEC9E, 0xF311960D,},
		{0xED15F9A7, 0x7B70E553, 0x9E2C9FD9, 0x3A08C252, 0xF24F420D,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		20,
		20,
		20,
		20,
		20,
		20,
		24,
		SPRD_ECC_CurveID_secp160k1,
	},
	{
		{0x66C38390, 0xAF12C0A5, 0xAFBDF8EF, 0x051B7B6A, 0x78BB18FE,},
		{0xB97356B4, 0x8EAD1534, 0xA715F19B, 0x21485E40, 0x469EA0D8,},
		{0x1343ABE2, 0x8D8288A1, 0xCB9BF564, 0x1ABE6B5B, 0x20215874,},
		{0x4EAE3A24, 0xF7A27D0B, 0xFAC93E83, 0x4D1E32D2, 0x236DC0F0,},
		{0x6E90759D, 0xE8F901E8, 0xD15E520E, 0xE201AF3A, 0x3869D858,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		20,
		20,
		20,
		20,
		20,
		20,
		24,
		SPRD_ECC_CurveID_secp160r1,
	},
	{
		{0x7E8CA2A9, 0xD1B55CB4, 0xB74649DF, 0xE675F9B9, 0x7B851F2E,},
		{0x28CC9270, 0x088077A4, 0xD2203407, 0x28871176, 0x3B6D4750,},
		{0x1343ABE2, 0x8D8288A1, 0xCB9BF564, 0x1ABE6B5B, 0x20215874,},
		{0x9DF47FF4, 0x532ADD20, 0x5F9C179C, 0x2745F841, 0xDB362640,},
		{0x57B5AB67, 0x849E5B0F, 0xA22B4BBC, 0x6BACB58A, 0x34BF4B19,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		20,
		20,
		20,
		20,
		20,
		20,
		24,
		SPRD_ECC_CurveID_secp160r2,
	},
	{
		{0x5F95A66A, 0xB5326512, 0x755DAFD1, 0xA0AD17D2, 0x8FBEFE33, 0xFDA8AC00,},
		{0xAD78B03F, 0xA707E4A1, 0x9FBE6127, 0x66AF68F0, 0x5CFC177C, 0xBB7B0657,},
		{0x1343ABE2, 0xE5318D5E, 0x8D8288A1, 0xCB9BF564, 0x1ABE6B5B, 0x20215874,},
		{0x83C36B6A, 0x32918AB0, 0x371D11DA, 0x9F7CDFBB, 0x0AB8A3AF, 0x9D0F46AD,},
		{0x061D22DC, 0x9D9E4C13, 0x36479FFE, 0x25CECA9A, 0x25C728A3, 0xE943FFD1,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		24,
		24,
		24,
		24,
		20,
		24,
		24,
		SPRD_ECC_CurveID_secp192k1,
	},
	{
		{0x749873E8, 0x85BFBF0A, 0xBBA426D9, 0xA2C646B0, 0x15B8C4B7, 0xF302235F,},
		{0xD950D4EC, 0x0A6E791E, 0xA7102B46, 0xDAC1FB4C, 0x6FFE80F1, 0x971B5A67,},
		{0x1343ABE2, 0xE5318D5E, 0x8D8288A1, 0xCB9BF564, 0x1ABE6B5B, 0x20215874,},
		{0x61176DC7, 0x4B3DBFC4, 0x78360A95, 0x506A4A30, 0x03400840, 0xBB124CA2,},
		{0x929EAA53, 0x1ECCC05B, 0xFF201319, 0x4747AE55, 0xC442B49D, 0xDF63F69C,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		24,
		24,
		24,
		24,
		20,
		24,
		24,
		SPRD_ECC_CurveID_secp192r1,
	},
	{
		{0x75529487, 0xF31374CC, 0x44746F10, 0x2983C7BB, 0x29D207CA, 0xB176B6F8, 0x440BBFFD,},
		{0x25B21253, 0xD875AF4D, 0x527C69EE, 0x83B54082, 0xFF387E49, 0x865BB285, 0xABE68E35,},
		{0x0b33e3de, 0x7f65b971, 0x4384e8ae, 0xa879ba9e, 0xbbb7dc30, 0x1766bb40, 0x5d49b3d2,},
		{0x6865F5C2, 0xFAC199EF, 0x4BB3BDA3, 0xE902CD0A, 0x2B0D9958, 0xCD984C94, 0xF2A29C3A,},
		{0xC9BD8E58, 0x0FAB692D, 0x15D41D70, 0xFD581280, 0x22519836, 0x1E13950F, 0x5C409E0D,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		28,
		28,
		28,
		28,
		20,
		28,
		32,
		SPRD_ECC_CurveID_secp224k1,
	},
	{
		{0x8be83c53, 0x48c1b5e5, 0xd6c4329a, 0x356c948e, 0xee8d114a, 0xbe3874d5, 0xe001c6b5,},
		{0x4e852ef1, 0x85190b36, 0xe892b1f1, 0x7bd91701, 0x2ea94c75, 0x35de593e, 0xc47e3dee,},
		{0x0b33e3de, 0x7f65b971, 0x4384e8ae, 0xa879ba9e, 0xbbb7dc30, 0x1766bb40, 0x5d49b3d2,},
		{0xd4c195b6, 0x3329fa00, 0x95c8f9a6, 0xbeb5d6e6, 0xaf38cf2a, 0x6b6dceec, 0xa529b778,},
		{0x8108631c, 0x439603d9, 0x4900835c, 0x54d7272f, 0x4f45d603, 0x1a6039a9, 0xe9def556,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		28,
		28,
		28,
		28,
		20,
		28,
		28,
		SPRD_ECC_CurveID_secp224r1,
	},
	{
		{0x8901E949, 0xEB26740A, 0x75B7E854, 0xE5018943, 0xA3522450, 0xAB5F1528, 0x0227E45F, 0x23D23D2F,},
		{0x89806413, 0xF2178C64, 0x5E7B1008, 0x4F3940D0, 0xCD2F3D09, 0xFD0F293A, 0xB5C234E3, 0xB81BB726,},
		{0xf4d4bf0f, 0x426d4aa7, 0xf1324537, 0xad005675, 0x8574cf5e, 0xf7d5e26e, 0xbc7e1e67, 0x3449ff64,},
		{0x75EC986E, 0x9B06A5C8, 0x261D669A, 0x5AD219CE, 0xE6C0B52E, 0xA061F7A8, 0x0B017E64, 0x3B126355,},
		{0x5A582C19, 0x1646DAAA, 0x8D1E17E4, 0x9D37BCAC, 0x1A994608, 0xE7396B91, 0xD1E4144B, 0x4D1DF341,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		32,
		32,
		32,
		32,
		20,
		32,
		32,
		SPRD_ECC_CurveID_secp256k1,
	},
	{
		{0x61748b4f, 0xaa36cb76, 0x2cefd775, 0xbdb14ba9, 0x879752c9, 0xd429369d, 0x4649a187, 0xbab4b407,},
		{0x2b3865e6, 0x220acb1f, 0x73b2f1a4, 0xe3064947, 0x652058c6, 0x20f02d46, 0x01c8954e, 0x03a35ef9,},
		{0x9b318663, 0x723528c1, 0x44573760, 0x5fc1446b, 0xf29b3cf0, 0x945f3845, 0xb284b6ad, 0x595b41dd,},
		{0xd60de8bd, 0xc0ea0610, 0x86392b2f, 0x960eec5b, 0x59e9420a, 0x1e321b09, 0x8db90c07, 0x5b066e01,},
		{0x7611e896, 0x7a43d260, 0xc78063b0, 0x7bcf0c73, 0x9c21f6cc, 0xbb71bf7d, 0x77999b64, 0x45e6f16b,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		32,
		32,
		32,
		32,
		20,
		32,
		32,
		SPRD_ECC_CurveID_secp256r1,
	},
	{
		{0xec03da28, 0x63b751d4, 0xf1825c60, 0x6a8d1607, 0xf5f63651, 0x980f109d, 0x947c3c9c, 0x03d1a419, 0x054bd01e, 0x5c28259e, 0xc45b95a7, 0x65b44a89,},
		{0x4c30798f, 0x84706785, 0xc0a32dc4, 0x252be82a, 0x97ff4af3, 0xbbd231f3, 0x68f30103, 0x8f3e6889, 0xaa239bcc, 0x3b6e6b11, 0x362b9fb1, 0xbe862583,},
		{0x50359cf7, 0xf845b40f, 0x03c70e25, 0xcff67647, 0x263efc3f, 0xda036975, 0xe82faf71, 0x2ce33f18, 0xfd57f567, 0x0eb1e427, 0x5ddde509, 0x1644afdb,},
		{0x4efacd73, 0x98506938, 0xaf6c0d60, 0x728afbd1, 0xd53deec5, 0xf94b853c, 0xb37941a0, 0x24cb6122, 0x07ad3247, 0x9eee0516, 0x0efaa1dd, 0x4e585368,},
		{0x71b2f36c, 0x05574645, 0x6d4fd3c7, 0xd463bc9a, 0xb9e332b4, 0x9b9ed908, 0x887e0a15, 0x74e22e25, 0x7e419d23, 0x8bd05d35, 0x080419bc, 0xe7c1646f,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
		48,
		48,
		48,
		48,
		20,
		48,
		48,
		SPRD_ECC_CurveID_secp384r1,
	},{
		   {0xa01b4935, 0x0a050048, 0x7d8d5385, 0x4bbbd922, 0x189943ac, 0x25505633, 0xf3eace0f, 0x3068717d, 0x1f831140, 0x621a046c, 0xf9469078, 0x6f11d0cc, 0xb1df1ebf, 0x486be9cc, 0x2661893d, 0x9d94a9fe, 0x0000002a,},
		   {0xf116cce7, 0x1087c683, 0x20c0f57b, 0xc80fc8c9, 0x9ae7e662, 0xf58ea4a6, 0x8f9c270c, 0xa7c72977, 0x284c7be3, 0xd4a3074c, 0xd44866de, 0xc5af6979, 0xdeb04394, 0x873eb8fc, 0x8ff65c0e, 0x1e7334c7, 0x0000003f,},
		   {0xfbd854a7, 0xae66f518, 0x31918a30, 0x6787e478, 0x766f6a2e, 0x1de0b844, 0x6bea4d41, 0xed86969b, 0x3ec6ed3c, 0x98b93704, 0x78b5af77, 0x76643f50, 0xfb2aba84, 0x9f0653e5, 0xa308751c, 0x964a8683, 0x000001c1,},
		   {0x0d1bd38a, 0x507d37bd, 0xfcd8d07e, 0xfca8bbba, 0x971887b9, 0xc7c39b0a, 0x74a52d87, 0x1aa702b2, 0x9b0cb0cf, 0x0602b0fa, 0x1d52e6f5, 0x7cd05fc2, 0xd27cdad4, 0xf70a4ee5, 0x2fb7e3ee, 0x700dfcd6, 0x00000142,},
		   {0xe2874203, 0x68ac3381, 0xb8652a5c, 0xd54b9a1f, 0xb216f19e, 0x6275a447, 0x0d30132f, 0x91621b81, 0x8a932444, 0xf5df4cb2, 0xcf6c59ba, 0x93bd7c2d, 0xd2fd5ee2, 0xadaab2e6, 0xb30dce0e, 0x42328c10, 0x000001be,},
		/*{0x9cd0d89d, 0x7850c26c, 0xba3e2571, 0x4706816a, 0xa9993e36,},*/
		{0x363e99a9, 0x6a810647, 0x71253eba, 0x6cc25078, 0x9dd8d09c,},
        68,
        68,
        68,
        68,
		20,
		68,
		68,
		SPRD_ECC_CurveID_secp521r1,
	   },
};

static int ecc_verify_test(sprd_ecc_curveid_t curve_id)
{
	struct ecc_test_st *test_data = &ecc_test_vector[curve_id];
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint32_t temp;
	int ret = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_signature_t rs;

	if (ecc_test_vector[curve_id].ecc_curve != curve_id) {
		SPRD_CRYPTO_LOG_ERR("ecc_verify_test no match curve!\n");
		return -1;
	}

	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_x, test_data->ecc_px, test_data->pxy_bytelen);
	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_y, test_data->ecc_py, test_data->pxy_bytelen);
	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memcpy(rs.ecc_r, test_data->ecc_r, test_data->r_bytelen);
	sprd_pal_memset(rs.ecc_s, 0, n_len);
	sprd_pal_memcpy(rs.ecc_s, test_data->ecc_s, test_data->s_bytelen);

	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("ecc_verify_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_WARN("ecc_verify_test pass 1\n");
	}

	temp = rs.ecc_s[0];
	rs.ecc_s[0] = 0;
	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_WARN("ecc_verify_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_verify_test fail 2\n");
		return -3;
	}


	rs.ecc_s[0] = temp;
	ecc_public_key.pubkey_y[0] = 0;
	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_WARN("ecc_verify_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_verify_test fail 3\n");
		return -4;
	}

	return 0;
}

static int ecc_sign_test(sprd_ecc_curveid_t curve_id)
{
	struct ecc_test_st *test_data = &ecc_test_vector[curve_id];
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint32_t temp;
	int ret = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	sprd_ecc_signature_t rs;

	if (ecc_test_vector[curve_id].ecc_curve != curve_id) {
		SPRD_CRYPTO_LOG_ERR("\r\necc_sign_test no match curve!\r\n");
		return -1;
	}

	sprd_pal_memset(ecc_private_key.prikey, 0, n_len);
	sprd_pal_memcpy(ecc_private_key.prikey, test_data->ecc_d, test_data->d_bytelen);
	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_x, test_data->ecc_px, test_data->pxy_bytelen);
	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memcpy(ecc_public_key.pubkey_y, test_data->ecc_py, test_data->pxy_bytelen);
	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memset(rs.ecc_s, 0, n_len);
	ret |= sprd_ecc_sign(curve_id, &ecc_private_key, (uint8_t*)test_data->ecc_mhash,test_data->mhash_bytelen, &rs);
	ret |= sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("ecc_sign_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_WARN("ecc_sign_test pass 2\n");
	}

	temp = rs.ecc_s[0];
	rs.ecc_s[0] = (temp^0xffffffff)+1;
	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_WARN("ecc_sign_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_sign_test fail2\n");
		return -3;
	}

	rs.ecc_s[0] = temp;
	ecc_public_key.pubkey_y[0] = (ecc_public_key.pubkey_y[0]^0xffffffff)+1;
	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_WARN("ecc_sign_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_sign_test fail 3\n");
		return -4;
	}

	return 0;
}

static int ecc_keygen_test(sprd_ecc_curveid_t curve_id)
{
	struct ecc_test_st *test_data = &ecc_test_vector[curve_id];
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint32_t temp;
	int ret = 0;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	sprd_ecc_signature_t rs;

	if (ecc_test_vector[curve_id].ecc_curve != curve_id) {
		SPRD_CRYPTO_LOG_ERR("ecc_keygen_test no match curve!\n");
		return -1;
	}

	sprd_pal_memset(ecc_public_key.pubkey_x, 0, p_len);
	sprd_pal_memset(ecc_public_key.pubkey_y, 0, p_len);
	sprd_pal_memset(ecc_private_key.prikey, 0, n_len);
	sprd_pal_memset(rs.ecc_r, 0, n_len);
	sprd_pal_memset(rs.ecc_s, 0, n_len);

	ret |= sprd_ecc_genkey(curve_id, &ecc_private_key, &ecc_public_key);
	ret |= sprd_ecc_sign(curve_id, &ecc_private_key, (uint8_t*)test_data->ecc_mhash,test_data->mhash_bytelen, &rs);
	ret |= sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_ERR("ecc_sign_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_WARN("ecc_sign_test pass 1\n");
	}

	temp = rs.ecc_s[0];
	rs.ecc_s[0] = (temp^0xffffffff)+1;
	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_WARN("ecc_sign_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_sign_test fail 2\n");
		return -3;
	}

	rs.ecc_s[0] = temp;
	ecc_public_key.pubkey_y[0] = (ecc_public_key.pubkey_y[0]^0xffffffff)+1;
	ret = sprd_ecc_verify(curve_id, &ecc_public_key, (uint8_t*)test_data->ecc_mhash, test_data->mhash_bytelen, &rs);
	if (ret) {
		SPRD_CRYPTO_LOG_WARN("ecc_sign_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_sign_test fail 3\n");
		return -4;
	}
	return 0;
}

static int ecc_dh_test(sprd_ecc_curveid_t curve_id)
{
	int ret = 0;
	struct ecc_test_st *test_data = &ecc_test_vector[curve_id];
	uint32_t n_len = test_data->n_bytelen;
	uint32_t p_len = test_data->p_bytelen;
	uint8_t sharekeyA[100];
	uint8_t sharekeyB[100];
	uint32_t keylenA = 100;
	uint32_t keylenB = 100;
	sprd_ecc_pubkey_t ecc_public_keyA;
	sprd_ecc_prikey_t ecc_private_keyA;
	sprd_ecc_pubkey_t ecc_public_keyB;
	sprd_ecc_prikey_t ecc_private_keyB;

	if (ecc_test_vector[curve_id].ecc_curve != curve_id) {
		SPRD_CRYPTO_LOG_ERR("ecc_dh_test no match curve!\n");
		return -1;
	}

	sprd_pal_memset(ecc_public_keyA.pubkey_x, 0, p_len);
	sprd_pal_memset(ecc_public_keyA.pubkey_y, 0, p_len);
	sprd_pal_memset(ecc_private_keyA.prikey, 0, n_len);

	sprd_pal_memset(ecc_public_keyB.pubkey_x, 0, p_len);
	sprd_pal_memset(ecc_public_keyB.pubkey_y, 0, p_len);
	sprd_pal_memset(ecc_private_keyB.prikey, 0, n_len);

	sprd_pal_memset(sharekeyA, 0, n_len);
	sprd_pal_memset(sharekeyB, 0, n_len);

	ret |= sprd_ecc_genkey(curve_id, &ecc_private_keyA, &ecc_public_keyA);
	ret |= sprd_ecc_genkey(curve_id, &ecc_private_keyB, &ecc_public_keyB);

	ret |= sprd_ecc_dh(curve_id, &ecc_private_keyA, &ecc_public_keyB, sharekeyA, &keylenA);
	ret |= sprd_ecc_dh(curve_id, &ecc_private_keyB, &ecc_public_keyA, sharekeyB, &keylenB);

	if ((!ret) && (keylenA==keylenB) && (!sprd_pal_memcmp(sharekeyA, sharekeyB, keylenA))) {
		SPRD_CRYPTO_LOG_WARN("ecc_dh_test pass\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_dh_test fail\n");
		return -2;
	}

	return 0;
}

static int ecc_enc_dec_test(sprd_ecc_curveid_t curve_id)
{
	struct ecc_test_st *test_data = &ecc_test_vector[curve_id];
	uint32_t p_len = test_data->pxy_bytelen;
	sprd_ecc_pubkey_t ecc_public_key;
	sprd_ecc_prikey_t ecc_private_key;
	int ret = 0;
	uint8_t message[p_len * 2];
	uint32_t message_size = 0;
	uint8_t cipher[p_len * 4];
	uint32_t cipher_size = 0;
	uint8_t plain[p_len * 2];
	uint32_t plain_size = 0;

	if (ecc_test_vector[curve_id].ecc_curve != curve_id) {
		SPRD_CRYPTO_LOG_ERR("ecc_keygen_test no match curve!\n");
		return -1;
	}

	sprd_pal_memset(&ecc_public_key, 0, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memset(&ecc_private_key, 0, sizeof(sprd_ecc_prikey_t));
	sprd_pal_memset(message, 0, p_len*2);
	sprd_pal_memset(cipher, 0, p_len*4);
	sprd_pal_memset(plain, 0, p_len*2);

	//ret |= sprd_ecc_genkey(curve_id, &ecc_private_key, &ecc_public_key);
	sprd_pal_memcpy((uint8_t *)ecc_public_key.pubkey_x, (uint8_t *)test_data->ecc_px, p_len);
	sprd_pal_memcpy((uint8_t *)ecc_public_key.pubkey_y, (uint8_t *)test_data->ecc_py, p_len);
	sprd_pal_memcpy((uint8_t *)ecc_private_key.prikey, (uint8_t *)test_data->ecc_d, test_data->d_bytelen);

	sprd_pal_memcpy(message, (uint8_t *)ecc_public_key.pubkey_x, p_len);
	sprd_pal_memcpy(message + p_len, (uint8_t *)ecc_public_key.pubkey_y, p_len);
	message_size = 2 * p_len;

	ret |= sprd_ecc_public_encrypt(curve_id, &ecc_public_key,
			message, message_size, cipher, &cipher_size);
	ret |= sprd_ecc_private_decrypt(curve_id, &ecc_private_key,
			cipher, cipher_size, plain,  &plain_size);
	if (ret || (sprd_pal_memcmp(plain, message, message_size) != 0)) {
		SPRD_CRYPTO_LOG_ERR("ecc_enc_dec_test fail 1\n");
		return -2;
	} else {
		SPRD_CRYPTO_LOG_WARN("ecc_enc_dec_test pass 1\n");
	}

	ret |= sprd_ecc_public_encrypt(curve_id, &ecc_public_key,
			message, message_size, cipher, &cipher_size);
	message[0] += 1;
	ret |= sprd_ecc_private_decrypt(curve_id, &ecc_private_key,
			cipher, cipher_size, plain,  &plain_size);
	if (ret || (sprd_pal_memcmp(plain, message, message_size) != 0)) {
		SPRD_CRYPTO_LOG_WARN("ecc_enc_dec_test pass 2\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_enc_dec_test fail 2\n");
		return -2;
	}

	message[0] -= 1;
	ret |= sprd_ecc_public_encrypt(curve_id, &ecc_public_key,
			message, message_size, cipher, &cipher_size);
	cipher[0] += 1;
	ret |= sprd_ecc_private_decrypt(curve_id, &ecc_private_key,
			cipher, cipher_size, plain,  &plain_size);
	if (ret || (sprd_pal_memcmp(plain, message, message_size) != 0)) {
		SPRD_CRYPTO_LOG_WARN("ecc_enc_dec_test pass 3\n");
	} else {
		SPRD_CRYPTO_LOG_ERR("ecc_enc_dec_test fail 3\n");
		return -3;
	}

	return 0;
}

static int ecc_curve_test(sprd_ecc_curveid_t curve_id, int counter)
{
	int i;
	int ret = 0;

	SPRD_CRYPTO_LOG_WARN("----------verify test--------------\n");
	ret = ecc_verify_test(curve_id);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------sign test--------------\n");
	for (i = 0; i < counter; i++) {
		ret = ecc_sign_test(curve_id);
		if (ret) {
			return ret;
		}
	}

	SPRD_CRYPTO_LOG_WARN("----------keygen test--------------\n");
	for (i = 0; i < counter; i++) {
		ret = ecc_keygen_test(curve_id);
		if (ret) {
			return ret;
		}
	}

	SPRD_CRYPTO_LOG_WARN("----------dh test--------------\n");
	for (i = 0; i < counter; i++) {
		ret = ecc_dh_test(curve_id);
		if (ret) {
			return ret;
		}
	}

	SPRD_CRYPTO_LOG_WARN("----------enc and dec test------------\n");
	for (i = 0; i < counter; i++) {
		ret = ecc_enc_dec_test(curve_id);
		if (ret) {
			return ret;
		}
	}
	return ret;
}
#endif

int32_t sprd_ecc_test(void)
{
#ifdef SPRD_ECC_TEST
	int ret = 0;
	SPRD_CRYPTO_LOG_WARN("----------ecc test start-----------\n");
	SPRD_CRYPTO_LOG_WARN("----------secp160k1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp160k1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp160r1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp160r1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp160r2 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp160r2, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp192k1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp192k1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp192r1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp192r1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp224k1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp224k1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp224r1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp224r1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp256k1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp256k1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp256r1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp256r1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp384r1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp384r1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------secp521r1 start-----------\n");
	ret = ecc_curve_test(SPRD_ECC_CurveID_secp521r1, TEST_LOOP_TIMES);
	if (ret) {
		return ret;
	}

	SPRD_CRYPTO_LOG_WARN("----------ecc test over-------------\n");
#else
	SPRD_CRYPTO_LOG_WARN("sprd ecc test disabled\n");
#endif
	return 0;
}
