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

#include <sprd_crypto.h>
#include <sprd_ecc.h>

/*total  508*11 bytes*/
static sprd_ecc_curve_t g_ecc_curve[SPRD_ECC_CurveID_size] = {
	{
		/* Field modulus: P = FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC73*/
		{0xFFFFAC73,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		/* EC equation parameters: a =  0*/
		{0x00000000},
		/* EC equation parameters: b = 7 */
		{0x00000007},
		/* Generator coordinates in affine: X = 3B4C382CE37AA192A4019E763036F4F5DD4D7EBB*/
		{0xDD4D7EBB,0x3036F4F5,0xA4019E76,0xE37AA192,0x3B4C382C},
		/* Generator coordinates in affine: Y = 938CF935318FDCED6BC28286531733C3F03C4FEE*/
		{0xF03C4FEE,0x531733C3,0x6BC28286,0x318FDCED,0x938CF935},
		/* Order of generator: n = 100000000000000000001B8FA16DFAB9ACA16B6B3*/
		{0xCA16B6B3,0x16DFAB9A,0x0001B8FA,0x00000000,0x00000000,0x00000001},
		/* EC cofactor h */
		1,
		/* Size of field modulus in bits */
		160,
		/* Size of order in bits */
		161,
		/* size of field modulus in words*/
		5,
		/* size of order in words*/
		6,
		/* Curve ID*/
		SPRD_ECC_CurveID_secp160k1,
		/* Field ID*/
		SPRD_ECC_GFp,
	},
	{
		{0x7FFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0x7FFFFFFC,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xC565FA45,0x81D4D4AD,0x65ACF89F,0x54BD7A8B,0x1C97BEFC},
		{0x13CBFC82,0x68C38BB9,0x46646989,0x8EF57328,0x4A96B568},
		{0x7AC5FB32,0x04235137,0x59DCC912,0x3168947D,0x23A62855},
		{0xCA752257,0xF927AED3,0x0001F4C8,0x00000000,0x00000000,0x00000001},
		1,
		160,
		161,
		5,
		6,
		SPRD_ECC_CurveID_secp160r1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFAC73,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xFFFFAC70,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xF50388BA,0x04664D5A,0xAB572749,0xFB59EB8B,0xB4E134D3},
		{0x3144CE6D,0x30F7199D,0x1F4FF11B,0x293A117E,0x52DCB034},
		{0xA7D43F2E,0xF9982CFE,0xE071FA0D,0xE331F296,0xFEAFFEF2},
		{0xF3A1A16B,0xE786A818,0x0000351E,0x00000000,0x00000000,0x00000001},
		1,
		160,
		161,
		5,
		6,
		SPRD_ECC_CurveID_secp160r2,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFEE37,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0x0},
		{0x3},
		{0xEAE06C7D,0x1DA5D1B1,0x80B7F434,0x26B07D02,0xC057E9AE,0xDB4FF10E},
		{0xD95E2F9D,0x4082AA88,0x15BE8634,0x844163D0,0x9C5628A7,0x9B2F2F6D},
		{0x74DEFD8D,0x0F69466A,0x26F2FC17,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF},
		1,
		192,
		192,
		6,
		6,
		SPRD_ECC_CurveID_secp192k1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xFFFFFFFC,0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xC146B9B1,0xFEB8DEEC,0x72243049,0x0FA7E9AB,0xE59C80E7,0x64210519},
		{0x82FF1012,0xF4FF0AFD,0x43A18800,0x7CBF20EB,0xB03090F6,0x188DA80E},
		{0x1E794811,0x73F977A1,0x6B24CDD5,0x631011ED,0xFFC8DA78,0x07192B95},
		{0xB4D22831,0x146BC9B1,0x99DEF836,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		1,
		192,
		192,
		6,
		6,
		SPRD_ECC_CurveID_secp192r1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFE56D,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0},
		{5},
		{0xB6B7A45C,0x0F7E650E,0xE47075A9,0x69A467E9,0x30FC28A1,0x4DF099DF,0xA1455B33},
		{0x556D61A5,0xE2CA4BDB,0xC0B0BD59,0xF7E319F7,0x82CAFBD6,0x7FBA3442,0x7E089FED},
		{0x769FB1F7,0xCAF0A971,0xD2EC6184,0x0001DCE8,0x00000000,0x00000000,0x00000000,0x00000001},
		1,
		224,
		225,
		7,
		8,
		SPRD_ECC_CurveID_secp224k1,
		SPRD_ECC_GFp,
	},
	{
		{0x00000001,0x00000000,0x00000000,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0x2355FFB4,0x270B3943,0xD7BFD8BA,0x5044B0B7,0xF5413256,0x0C04B3AB,0xB4050A85},
		{0x115C1D21,0x343280D6,0x56C21122,0x4A03C1D3,0x321390B9,0x6BB4BF7F,0xB70E0CBD},
		{0x85007E34,0x44D58199,0x5A074764,0xCD4375A0,0x4C22DFE6,0xB5F723FB,0xBD376388},
		{0x5C5C2A3D,0x13DD2945,0xE0B8F03E,0xFFFF16A2,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		1,
		224,
		224,
		7,
		7,
		SPRD_ECC_CurveID_secp224r1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFFC2F,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0x00000000},
		{0x00000007},
		{0x16F81798,0x59F2815B,0x2DCE28D9,0x029BFCDB,0xCE870B07,0x55A06295,0xF9DCBBAC,0x79BE667E},
		{0xFB10D4B8,0x9C47D08F,0xA6855419,0xFD17B448,0x0E1108A8,0x5DA4FBFC,0x26A3C465,0x483ADA77},
		{0xD0364141,0xBFD25E8C,0xAF48A03B,0xBAAEDCE6,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		1,
		256,
		256,
		8,
		8,
		SPRD_ECC_CurveID_secp256k1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0x00000000,0x00000000,0x00000000,0x00000001,0xFFFFFFFF},
		{0xFFFFFFFC,0xFFFFFFFF,0xFFFFFFFF,0x00000000,0x00000000,0x00000000,0x00000001,0xFFFFFFFF},
		{0x27D2604B,0x3BCE3C3E,0xCC53B0F6,0x651D06B0,0x769886BC,0xB3EBBD55,0xAA3A93E7,0x5AC635D8},
		{0xD898C296,0xF4A13945,0x2DEB33A0,0x77037D81,0x63A440F2,0xF8BCE6E5,0xE12C4247,0x6B17D1F2},
		{0x37BF51F5,0xCBB64068,0x6B315ECE,0x2BCE3357,0x7C0F9E16,0x8EE7EB4A,0xFE1A7F9B,0x4FE342E2},
		{0xFC632551,0xF3B9CAC2,0xA7179E84,0xBCE6FAAD,0xFFFFFFFF,0xFFFFFFFF,0x00000000,0xFFFFFFFF},
		1,
		256,
		256,
		8,
		8,
		SPRD_ECC_CurveID_secp256r1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFFFFF,0x00000000,0x00000000,0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xFFFFFFFC,0x00000000,0x00000000,0xFFFFFFFF,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		{0xD3EC2AEF,0x2A85C8ED,0x8A2ED19D,0xC656398D,0x5013875A,0x0314088F,0xFE814112,0x181D9C6E,0xE3F82D19,0x988E056B,0xE23EE7E4,0xB3312FA7},
		{0x72760AB7,0x3A545E38,0xBF55296C,0x5502F25D,0x82542A38,0x59F741E0,0x8BA79B98,0x6E1D3B62,0xF320AD74,0x8EB1C71E,0xBE8B0537,0xAA87CA22},
		{0x90EA0E5F,0x7A431D7C,0x1D7E819D,0x0A60B1CE,0xB5F0B8C0,0xE9DA3113,0x289A147C,0xF8F41DBD,0x9292DC29,0x5D9E98BF,0x96262C6F,0x3617DE4A},
		{0xCCC52973,0xECEC196A,0x48B0A77A,0x581A0DB2,0xF4372DDF,0xC7634D81,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF},
		1,
		384,
		384,
		12,
		12,
		SPRD_ECC_CurveID_secp384r1,
		SPRD_ECC_GFp,
	},
	{
		{0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0x000001FF},
		{0xFFFFFFFC,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0x000001FF},
		{0x6B503F00,0xEF451FD4,0x3D2C34F1,0x3573DF88,0x3BB1BF07,0x1652C0BD,0xEC7E937B,0x56193951,0x8EF109E1,0xB8B48991,0x99B315F3,0xA2DA725B,0xB68540EE,0x929A21A0,0x8E1C9A1F,0x953EB961,0x00000051},
		{0xC2E5BD66,0xF97E7E31,0x856A429B,0x3348B3C1,0xA2FFA8DE,0xFE1DC127,0xEFE75928,0xA14B5E77,0x6B4D3DBA,0xF828AF60,0x053FB521,0x9C648139,0x2395B442,0x9E3ECB66,0x0404E9CD,0x858E06B7,0x000000C6},
		{0x9FD16650,0x88BE9476,0xA272C240,0x353C7086,0x3FAD0761,0xC550B901,0x5EF42640,0x97EE7299,0x273E662C,0x17AFBD17,0x579B4468,0x98F54449,0x2C7D1BD9,0x5C8A5FB4,0x9A3BC004,0x39296A78,0x00000118},
		{0x91386409,0xBB6FB71E,0x899C47AE,0x3BB5C9B8,0xF709A5D0,0x7FCC0148,0xBF2F966B,0x51868783,0xFFFFFFFA,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0x000001FF},
		1,
		521,
		521,
		17,
		17,
		SPRD_ECC_CurveID_secp521r1,
		SPRD_ECC_GFp,
	},
};

static sprd_crypto_err_t sprd_ecc_get_curve(sprd_ecc_curveid_t curve_id,
		sprd_ecc_curve_t *curve_data)
{
	sprd_pal_memcpy(curve_data, &g_ecc_curve[curve_id], sizeof(sprd_ecc_curve_t));
	return SPRD_ECC_OK;
}

sprd_crypto_err_t sprd_ecc_queue_and_wait(sprd_ecc_data_t* ecc_data)
{
	sprd_crypto_context_t context;
	int err = 0;

	sprd_pal_memset(&context, 0, sizeof(sprd_crypto_context_t));

	context.algo = SPRD_CRYPTO_ECC;
	context.info.ecc.data = ecc_data;

	err = sprd_crypto_open(&context);
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("FAILED!\n");
		goto failed;
	}

	err = sprd_crypto_process(&context);
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_TRACE("sprd_crypto_process return 0x%x\n", err);
		goto failed;
	}

#ifndef R5P0LITE
	sprd_crypto_polling();
#else
	sprd_crypto_pka_polling();
#endif

failed:
	sprd_crypto_close(&context);
	return err;
}

sprd_crypto_err_t sprd_ecc_genkey(sprd_ecc_curveid_t curve_id,
		sprd_ecc_prikey_t *prikey, sprd_ecc_pubkey_t *pubkey)
{
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_keygen start\n");
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_TRACE("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_KEYGEN;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_ecc_queue_and_wait(data);
	error = data->error_code;

	sprd_pal_memcpy(prikey, &(data->param.keygen.prikey), sizeof(sprd_ecc_prikey_t));
	prikey->ecc_curve = curve_id;
	sprd_pal_memcpy(pubkey, &(data->param.keygen.pubkey), sizeof(sprd_ecc_pubkey_t));
	pubkey->ecc_curve = curve_id;
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_keygen process result=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}
	return error;
}

sprd_crypto_err_t sprd_ecc_sign(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *prikey,
		uint8_t *hash_data, uint8_t hash_bytelen, sprd_ecc_signature_t *rs)
{
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_sign start\n");
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_TRACE("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;

	data->req_id = SPRD_ECC_REQUEST_SIGN;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.sign.prikey), prikey, sizeof(sprd_ecc_prikey_t));
	sprd_pal_memcpy(data->param.sign.hash_data, hash_data, hash_bytelen);
	data->param.sign.hash_bytelen = hash_bytelen;

	sprd_ecc_queue_and_wait(data);
	error = data->error_code;

	//hexdump_sprd("rng:", data->pka_data+64, 512*4);
	//hexdump_sprd("signature:", (uint8_t*)(&(data->param.sign.rs)), sizeof(sprd_ecc_signature_t));
	sprd_pal_memcpy(rs, &(data->param.sign.rs), sizeof(sprd_ecc_signature_t));
	rs->ecc_curve = curve_id;
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_sign process result=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t sprd_ecc_verify(sprd_ecc_curveid_t curve_id, sprd_ecc_pubkey_t *pubkey,
		uint8_t *hash_data, uint8_t hash_bytelen, sprd_ecc_signature_t *rs)
{
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_verify start\n");
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_TRACE("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_VERIFY;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	//hexdump_sprd("ecc_p origin:", data->curve.ecc_p, data->curve.ecc_p_wordlen*4);
	sprd_pal_memcpy(&(data->param.verify.pubkey), pubkey, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy(data->param.verify.hash_data, hash_data, hash_bytelen);
	data->param.verify.hash_bytelen = hash_bytelen;
	sprd_pal_memcpy(&(data->param.verify.rs), rs, sizeof(sprd_ecc_signature_t));
	sprd_ecc_queue_and_wait(data);
	error = data->error_code;

	//hexdump_sprd("ecc_r:", (uint8_t*)(data->param.verify.out_r), data->curve.ecc_n_wordlen*4);
	//hexdump_sprd("ecc_r:", data->param.verify.out_r, 2048);
	if(error == SPRD_ECC_OK) {
		int cmp_res = sprd_pal_memcmp(data->param.verify.out_r, data->param.verify.rs.ecc_r, data->curve.ecc_n_wordlen*4);
		// SPRD_CRYPTO_LOG_TRACE("sprd_ecc_verify cmp_res=%d\n", cmp_res);
		if(cmp_res) {
			error = SPRD_ECC_VERIFY_FAILED_ERROR;
		} else {
			error = SPRD_ECC_OK;
		}
	}

	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_verify process result=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}
	return error;
}

sprd_crypto_err_t sprd_ecc_dh(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *prikey,
		sprd_ecc_pubkey_t *pubkey, uint8_t *shared_key, uint32_t *shared_key_len)
{
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_dh start\n");
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;
	uint32_t p_real_bytelen = 0;

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_TRACE("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_DH;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.dh.pubkey), pubkey, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy(&(data->param.dh.prikeyA), prikey, sizeof(sprd_ecc_prikey_t));

	sprd_ecc_queue_and_wait(data);
	error = data->error_code;
	//hexdump_sprd("reg_temp:", data->pka_data+64, data->curve.ecc_n_wordlen*4);
	//hexdump_sprd("shared_key:", (uint8_t*)(data->param.dh.shared_key), data->curve.ecc_p_wordlen*4);
	p_real_bytelen = (data->curve.ecc_p_bitlen+7)/8;
	if(*shared_key_len < p_real_bytelen) {
		error = SPRD_ECC_LENGTH_ERROR;
		goto failed;
	}
	if (sec_memcpy_invert(shared_key, data->param.dh.shared_key, p_real_bytelen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	*shared_key_len = p_real_bytelen;

	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_dh process result=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}
	return error;
}

sprd_crypto_err_t sprd_ecc_public_encrypt(sprd_ecc_curveid_t curve_id,
		sprd_ecc_pubkey_t *pubkey, uint8_t *message, uint32_t message_size,
		uint8_t *cipher, uint32_t *cipher_size)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	uint32_t ecc_p_byte_len = 0;
	uint32_t out_len = 0;
	uint32_t offset = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_ecc_public_encrypt\n");

	if (pubkey == NULL || message == NULL || message_size == 0 ||
			cipher == NULL || cipher_size == NULL) {
		SPRD_CRYPTO_LOG_ERR("Parmamter error!\n");
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_TRACE("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *)buf;

	data->req_id = SPRD_ECC_REQUEST_PUB_ENC;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.enc_dec.PB), pubkey, sizeof(sprd_ecc_pubkey_t));

	ecc_p_byte_len = data->curve.ecc_p_wordlen*4;
	if (message_size != ecc_p_byte_len * 2) {
		SPRD_CRYPTO_LOG_ERR("message_size error!\n");
		return SPRD_ECC_LENGTH_ERROR;
	}
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.M.pubkey_x), message, ecc_p_byte_len);
	offset = ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.M.pubkey_y), message + offset, ecc_p_byte_len);

	sprd_ecc_queue_and_wait(data);
	error = data->error_code;

	hexdump_sprd("Cipher data(C1.1):", (uint8_t*)(data->param.enc_dec.C1.pubkey_x), ecc_p_byte_len);
	hexdump_sprd("Cipher data(C1.2):", (uint8_t*)(data->param.enc_dec.C1.pubkey_y), ecc_p_byte_len);
	hexdump_sprd("Cipher data(C2.1):", (uint8_t*)(data->param.enc_dec.C2.pubkey_x), ecc_p_byte_len);
	hexdump_sprd("Cipher data(C2.2):", (uint8_t*)(data->param.enc_dec.C2.pubkey_y), ecc_p_byte_len);

	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_public_encrypt process result: %d\n", error);

	sprd_pal_memcpy((uint8_t *)cipher, (uint8_t *)(data->param.enc_dec.C1.pubkey_x), ecc_p_byte_len);
	out_len += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)cipher + out_len, (uint8_t *)(data->param.enc_dec.C1.pubkey_y), ecc_p_byte_len);
	out_len += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)cipher + out_len, (uint8_t *)(data->param.enc_dec.C2.pubkey_x), ecc_p_byte_len);
	out_len += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)cipher + out_len, (uint8_t *)(data->param.enc_dec.C2.pubkey_y), ecc_p_byte_len);
	out_len += ecc_p_byte_len;
	*cipher_size = out_len;

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t sprd_ecc_private_decrypt(sprd_ecc_curveid_t curve_id,
		sprd_ecc_prikey_t *prikey, uint8_t *cipher, uint32_t cipher_size,
		uint8_t *message, uint32_t *message_size)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	uint32_t offset = 0;
	uint32_t out_len = 0;
	uint32_t ecc_p_byte_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_ecc_private_decrypt\n");
	if (prikey == NULL || cipher == NULL || cipher_size == 0 ||
			message == NULL || message_size == NULL) {
		SPRD_CRYPTO_LOG_TRACE("Parameter error!\n");
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_TRACE("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *)buf;

	data->req_id = SPRD_ECC_REQUEST_PRI_DEC;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	ecc_p_byte_len = data->curve.ecc_p_wordlen*4;
	if (cipher_size != ecc_p_byte_len * 4) {
		SPRD_CRYPTO_LOG_ERR("message_size error!\n");
		return SPRD_ECC_LENGTH_ERROR;
	}
	sprd_pal_memcpy(&(data->param.enc_dec.dB), prikey, sizeof(sprd_ecc_prikey_t));
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.C1.pubkey_x), (uint8_t *)cipher, ecc_p_byte_len);
	offset += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.C1.pubkey_y), (uint8_t *)cipher + offset, ecc_p_byte_len);
	offset += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.C2.pubkey_x), (uint8_t *)cipher + offset, ecc_p_byte_len);
	offset += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.C2.pubkey_y), (uint8_t *)cipher + offset, ecc_p_byte_len);

	sprd_ecc_queue_and_wait(data);
	error = data->error_code;

	hexdump_sprd("Plain data(M.1):", (uint8_t*)(data->param.enc_dec.M.pubkey_x), ecc_p_byte_len);
	hexdump_sprd("Plain data(M.2):", (uint8_t*)(data->param.enc_dec.M.pubkey_y), ecc_p_byte_len);

	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_private_decrypt process result: %d\n", error);

	sprd_pal_memcpy((uint8_t *)message, (uint8_t *)(data->param.enc_dec.M.pubkey_x), ecc_p_byte_len);
	out_len += ecc_p_byte_len;
	sprd_pal_memcpy((uint8_t *)message + out_len, (uint8_t *)(data->param.enc_dec.M.pubkey_y), ecc_p_byte_len);
	out_len += ecc_p_byte_len;
	*message_size = out_len;

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t sprd_set_ecc_privatekey(sprd_ecc_curveid_t curve_id,
		uint8_t *inkey, uint32_t inkeylen, sprd_ecc_prikey_t *prikey)
{
	sprd_ecc_curve_t curve;
	sprd_ecc_curve_t *cur_curve = &curve;
	uint32_t n_real_bytelen = 0;

	if ((inkey == NULL) || (prikey == NULL)) {
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	if (curve_id >= SPRD_ECC_CurveID_size) {
		return SPRD_ECC_CURVEID_ERROR;
	}

	sprd_ecc_get_curve(curve_id, cur_curve);
	n_real_bytelen = (cur_curve->ecc_n_bitlen+7)/8;

	if ((inkeylen == 0) || (inkeylen > n_real_bytelen)) {
		return SPRD_ECC_LENGTH_ERROR;
	}

	sprd_pal_memset((uint8_t *)prikey->prikey, 0, cur_curve->ecc_n_wordlen*4);
	if (sec_memcpy_invert((uint8_t *)prikey->prikey, inkey, inkeylen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	prikey->ecc_curve = curve_id;

	return SPRD_ECC_OK;
}

sprd_crypto_err_t sprd_get_ecc_privatekey(sprd_ecc_prikey_t *prikey,
		uint8_t *outkey, uint32_t *outkeylen)
{
	sprd_ecc_curve_t curve;
	sprd_ecc_curve_t *cur_curve = &curve;
	uint32_t n_real_bytelen = 0;

	if ((outkey == NULL) || (prikey == NULL) || (outkeylen == NULL)) {
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	sprd_ecc_get_curve(prikey->ecc_curve, cur_curve);
	n_real_bytelen = (cur_curve->ecc_n_bitlen+7)/8;

	if (*outkeylen < n_real_bytelen) {
		*outkeylen = n_real_bytelen;
		return SPRD_ECC_OVERFLOW_ERROR;
	}

	*outkeylen = n_real_bytelen;
	if (sec_memcpy_invert(outkey, (uint8_t *)prikey->prikey, *outkeylen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}

	return SPRD_ECC_OK;
}

sprd_crypto_err_t sprd_set_ecc_publickey(sprd_ecc_curveid_t curve_id, uint8_t *inkey,
		uint32_t inkeylen, sprd_ecc_pubkey_t *pubkey)
{
	sprd_ecc_curve_t curve;
	sprd_ecc_curve_t *cur_curve = &curve;
	uint32_t p_real_bytelen = 0;

	if ((inkey == NULL) || (pubkey == NULL)) {
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	sprd_ecc_get_curve(curve_id, cur_curve);
	p_real_bytelen = (cur_curve->ecc_p_bitlen+7)/8;

	if ((inkeylen == 0) || (inkeylen > p_real_bytelen*2)) {
		return SPRD_ECC_LENGTH_ERROR;
	}

	if (sprd_pal_memset((uint8_t *)pubkey->pubkey_x, 0, cur_curve->ecc_p_wordlen*4) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sprd_pal_memset failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	if (sprd_pal_memset((uint8_t *)pubkey->pubkey_y, 0, cur_curve->ecc_p_wordlen*4) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sprd_pal_memset failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	if (sec_memcpy_invert((uint8_t *)pubkey->pubkey_x, inkey, inkeylen/2) == NULL) {
        	SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
        	return SPRD_ECC_ERROR_BASE;
    	}
	if (sec_memcpy_invert((uint8_t *)pubkey->pubkey_y, inkey+inkeylen/2, inkeylen/2) == NULL) {
        	SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
        	return SPRD_ECC_ERROR_BASE;
    	}
	pubkey->ecc_curve = curve_id;

	return SPRD_ECC_OK;
}

sprd_crypto_err_t sprd_get_ecc_publickey(sprd_ecc_pubkey_t *pubkey,
		uint8_t *outkey, uint32_t *outkeylen)
{
	sprd_ecc_curve_t curve;
	sprd_ecc_curve_t *cur_curve = &curve;
	uint32_t p_real_bytelen = 0;

	if ((outkey == NULL) || (pubkey == NULL) || (outkeylen == NULL)) {
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	sprd_ecc_get_curve(pubkey->ecc_curve, cur_curve);
	p_real_bytelen = (cur_curve->ecc_p_bitlen+7)/8;

	if (*outkeylen < p_real_bytelen*2) {
		*outkeylen = p_real_bytelen*2;
		return SPRD_ECC_OVERFLOW_ERROR;
	}

	*outkeylen = p_real_bytelen*2;
	if (sec_memcpy_invert(outkey, (uint8_t *)pubkey->pubkey_x, p_real_bytelen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	if (sec_memcpy_invert(outkey+p_real_bytelen, (uint8_t *)pubkey->pubkey_y, p_real_bytelen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}

	return SPRD_ECC_OK;
}

sprd_crypto_err_t sprd_set_ecc_signature(sprd_ecc_curveid_t curve_id,
		uint8_t *signature, uint32_t rslen, sprd_ecc_signature_t *rs)
{
	sprd_ecc_curve_t curve;
	sprd_ecc_curve_t *cur_curve = &curve;
	uint32_t n_real_bytelen = 0;

	if ((signature== NULL) || (rs== NULL)) {
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	sprd_ecc_get_curve(curve_id, cur_curve);
	n_real_bytelen = (cur_curve->ecc_n_bitlen+7)/8;

	if ((rslen == 0) || (rslen > n_real_bytelen*2)) {
		return SPRD_ECC_LENGTH_ERROR;
	}

	if (sprd_pal_memset((uint8_t *)rs->ecc_r, 0, cur_curve->ecc_n_wordlen*4) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sprd_pal_memset failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	if (sprd_pal_memset((uint8_t *)rs->ecc_s, 0, cur_curve->ecc_n_wordlen*4) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sprd_pal_memset failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	if (sec_memcpy_invert((uint8_t *)rs->ecc_r, signature, rslen/2) == NULL) {
        	SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
        	return SPRD_ECC_ERROR_BASE;
    	}
	if (sec_memcpy_invert((uint8_t *)rs->ecc_s, signature+rslen/2, rslen/2) == NULL) {
        	SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
        	return SPRD_ECC_ERROR_BASE;
    	}
	rs->ecc_curve = curve_id;

	return SPRD_ECC_OK;
}

sprd_crypto_err_t sprd_get_ecc_signature(sprd_ecc_signature_t *rs,
		uint8_t *signature, uint32_t *rslen)
{
	sprd_ecc_curve_t curve;
	sprd_ecc_curve_t *cur_curve = &curve;
	uint32_t n_real_bytelen = 0;

	if ((signature== NULL) || (rs== NULL) || (rslen == NULL)) {
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	sprd_ecc_get_curve(rs->ecc_curve, cur_curve);
	n_real_bytelen = (cur_curve->ecc_n_bitlen+7)/8;

	if (*rslen < n_real_bytelen*2) {
		*rslen = n_real_bytelen*2;
		return SPRD_ECC_OVERFLOW_ERROR;
	}

	*rslen = n_real_bytelen*2;
	if (sec_memcpy_invert(signature, (uint8_t *)rs->ecc_r, n_real_bytelen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	if (sec_memcpy_invert(signature+n_real_bytelen, (uint8_t *)rs->ecc_s, n_real_bytelen) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sec_memcpy_invert failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}

	return SPRD_ECC_OK;
}

