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

#include "sprd_sm2.h"
#include "sprd_crypto.h"
#include "sprd_utils.h"
#include "sprd_ecc_types.h"
#include "sprd_hash.h"
#include "sprd_kdf.h"

static sprd_ecc_curve_t g_ecc_curve = {
	//p
	{0x9ed64285, 0x184f044c, 0x3524b9e8, 0xdef76fbf, 0x91837245, 0x7d51455c, 0x8bdb2e72, 0xc3dff108,},
	//a
	{0xb4687978, 0xfdc332fa, 0x2e841724, 0xfffebb73, 0x8b843c2f, 0xe0d73168, 0x8b2265ec, 0x98e43739,},
	//b
	{0xd3c6e463, 0x840c3bb2, 0x4142f89c, 0x48fe4b48, 0xa5591df6, 0x6ea06bb1, 0xdad1126e, 0x9a24c527,},
	//Gx
	{0xd6eb1d42, 0xb6ea621b, 0xeb346474, 0x5e31ccc3, 0x3b0b2232, 0xdc0bd5ad, 0x146c4e4c, 0x3dd4ed7f,},
	//Gy
	{0x2b518006, 0x072cb4cb, 0xd24973d4, 0xc4703b15, 0xfcfdd7e5, 0xa16ea3bf, 0xb94158a8, 0xa2096ee4,},
	//n
	{0x9ed64285, 0x184f044c, 0x3524b9e8, 0xddf76fbf, 0x63207729, 0x8d628504, 0xe74ee75a, 0xb7792ec3,},

	/* EC cofactor h */
	1,
	/* Size of field modulus in bits */
	256,
	/* Size of order in bits */
	256,
	/* size of field modulus in words*/
	8,
	/* size of order in words*/
	8,
	/* Curve ID*/
	SPRD_ECC_CurveID_secp160k1,
	/* Field ID*/
	SPRD_ECC_GFp,
};

static uint8_t sm2_param_num127[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,};

static sprd_crypto_err_t sprd_ecc_get_curve(sprd_ecc_curveid_t curve_id,
		sprd_ecc_curve_t *curve_data)
{
	sprd_pal_memcpy(curve_data, &g_ecc_curve, sizeof(sprd_ecc_curve_t));
	return SPRD_ECC_OK;
}

static sprd_crypto_err_t sprd_sm2_queue_and_wait(sprd_ecc_data_t* ecc_data)
{
	void* sem_process;
	sprd_crypto_context_t context;
	int err = 0;

	sprd_pal_memset(&context, 0, sizeof(sprd_crypto_context_t));

	sem_process = sprd_pal_sem_init(0);
	if (sem_process == NULL) {
		return SPRD_CRYPTO_OUTOFMEM;
	}

	context.sem = sem_process;
	context.algo = SPRD_CRYPTO_SM2;
	context.info.ecc.data = ecc_data;

	err = sprd_crypto_process(&context);
	if (err != SPRD_CRYPTO_SUCCESS) {
		SPRD_CRYPTO_LOG_ERR("sprd_crypto_process return 0x%x\n", err);
		goto FAILED;
	}

	sprd_pal_sem_wait(sem_process);
	SPRD_CRYPTO_LOG_TRACE("sprd_sm2_queue_and_wait process done\n");
FAILED:
	sprd_pal_sem_destroy(sem_process);

	return err;
}

sprd_crypto_err_t
sprd_sm2_genkey(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *prikey,
		sprd_ecc_pubkey_t *pubkey)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_ecc_keygen\n");

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_KEYGEN;
	sprd_ecc_get_curve(curve_id, &(data->curve));
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);
	error = data->error_code;
	sprd_pal_invalidate_by_vaddr(buf, buf_len);
	sprd_pal_memcpy(prikey, &(data->param.keygen.prikey), sizeof(sprd_ecc_prikey_t));
	prikey->ecc_curve = curve_id;
	sprd_pal_memcpy(pubkey, &(data->param.keygen.pubkey), sizeof(sprd_ecc_pubkey_t));
	pubkey->ecc_curve = curve_id;
	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_keygen process result: %d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t
sprd_sm2_sign(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *prikey,
		uint8_t *hash_data, uint8_t hash_bytelen, sprd_ecc_signature_t *rs)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_ecc_sign\n");

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
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
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);

	error = data->error_code;

	sprd_pal_invalidate_by_vaddr(buf, buf_len);
	sprd_pal_memcpy(rs, &(data->param.sign.rs), sizeof(sprd_ecc_signature_t));
	rs->ecc_curve = curve_id;
	sprd_pal_invalidate_by_vaddr(rs, sizeof(sprd_ecc_signature_t));
	SPRD_CRYPTO_LOG_ERR("sprd_ecc_sign process result1=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t
sprd_sm2_verify(sprd_ecc_curveid_t curve_id, sprd_ecc_pubkey_t *pubkey,
		uint8_t *hash_data, uint8_t hash_bytelen, sprd_ecc_signature_t *rs)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_ecc_verify\n");

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_VERIFY;
	sprd_ecc_get_curve(curve_id, &(data->curve));
	sprd_pal_memcpy(&(data->param.verify.pubkey), pubkey, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy(data->param.verify.hash_data, hash_data, hash_bytelen);
	data->param.verify.hash_bytelen = hash_bytelen;
	sprd_pal_memcpy(&(data->param.verify.rs), rs, sizeof(sprd_ecc_signature_t));
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);
	error = data->error_code;
	sprd_pal_invalidate_by_vaddr(buf, buf_len);

	if(error == SPRD_ECC_OK) {
		int cmp_res = sprd_pal_memcmp(data->param.verify.out_r, data->param.verify.rs.ecc_r, data->curve.ecc_n_wordlen*4);
		SPRD_CRYPTO_LOG_TRACE("sprd_ecc_verify cmp_res: %d\n", cmp_res);
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

sprd_crypto_err_t sprd_sm2_kap_prepare(sprd_ecc_curveid_t curve_id,
		sprd_ecc_prikey_t *rA, sprd_ecc_pubkey_t *RA)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_ecc_dh\n");

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_EC_POINT;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.key_dh.rA), rA, sizeof(sprd_ecc_prikey_t));
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);
	error = data->error_code;
	sprd_pal_invalidate_by_vaddr(buf, buf_len);
	sprd_pal_memcpy(RA, &(data->param.key_dh.RA), sizeof(sprd_ecc_pubkey_t));

	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_dh process result=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t sprd_sm2_key_dh(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *rA,
		sprd_ecc_prikey_t *dA, sprd_ecc_pubkey_t *RA, sprd_ecc_pubkey_t *PB,
		sprd_ecc_pubkey_t *RB, sprd_ecc_pubkey_t *UA)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_sm2_key_dh\n");

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_KEY_DH;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.key_dh.rA), rA, sizeof(sprd_ecc_prikey_t));
	sprd_pal_memcpy(&(data->param.key_dh.dA), dA, sizeof(sprd_ecc_prikey_t));
	sprd_pal_memcpy(&(data->param.key_dh.RA), RA, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy(&(data->param.key_dh.PB), PB, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy(&(data->param.key_dh.RB), RB, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy(&(data->param.key_dh.param_num127), sm2_param_num127, sizeof(sm2_param_num127));
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);
	error = data->error_code;
	sprd_pal_invalidate_by_vaddr(buf, buf_len);
	sprd_pal_memcpy(UA, &(data->param.key_dh.UA), sizeof(sprd_ecc_pubkey_t));

	SPRD_CRYPTO_LOG_TRACE("sprd_ecc_dh process result=%d\n", error);

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

static sprd_crypto_err_t sprd_sm2_encrypt(sprd_ecc_curveid_t curve_id, sprd_ecc_pubkey_t *pubkey,
		sprd_ecc_pubkey_t *C1, sprd_ecc_pubkey_t *point)
{
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;
	int error = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_sm2_public_encrypt\n");

	if (pubkey == NULL || C1 == NULL || point == NULL) {
		SPRD_CRYPTO_LOG_ERR("NULL point error!\n");
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_PUB_ENC;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.enc_dec.PB), pubkey, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);
	error = data->error_code;
	sprd_pal_invalidate_by_vaddr(buf, buf_len);

	sprd_pal_memcpy((uint8_t *)C1, (uint8_t *)&(data->param.enc_dec.C1), sizeof(sprd_ecc_pubkey_t));
	sprd_pal_memcpy((uint8_t *)point, (uint8_t *)&(data->param.enc_dec.point), sizeof(sprd_ecc_pubkey_t));

failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t sprd_sm2_public_encrypt(sprd_ecc_curveid_t curve_id, sprd_ecc_pubkey_t *pubkey,
		uint8_t *src, uint32_t src_size, uint8_t *dst, uint32_t *dst_size)
{
	int i;
	uint8_t kdf_buf[64];
	uint8_t *outptr = dst;
	uint32_t outlen = 0;
	sprd_ecc_pubkey_t C1;
	sprd_ecc_pubkey_t point;
	sprd_ecc_curve_t curve;

	SPRD_CRYPTO_LOG_TRACE("start sprd_sm2_public_encrypt\n");

	if (src == NULL || dst == NULL) {
		SPRD_CRYPTO_LOG_ERR("NULL point error!\n");
		return SPRD_ECC_NULL_POINTER_ERROR;
	}
	sprd_sm2_encrypt(curve_id, pubkey, &C1, &point);
	sprd_ecc_get_curve(curve_id, &curve);

	outptr[0] = 0x04;
	outlen += 1;
	outptr = dst + outlen;
	sprd_pal_memcpy((uint8_t *)outptr, (uint8_t *)C1.pubkey_x, curve.ecc_p_wordlen * 4);
	outlen += curve.ecc_p_wordlen * 4;
	outptr = dst + outlen;
	sprd_pal_memcpy((uint8_t *)outptr, (uint8_t *)C1.pubkey_y, curve.ecc_p_wordlen * 4);
	outlen += curve.ecc_p_wordlen * 4;
	outptr = dst + outlen;

	sprd_pal_memcpy((uint8_t *)kdf_buf, (uint8_t *)point.pubkey_x, curve.ecc_p_wordlen * 4);
	sprd_pal_memcpy((uint8_t *)(kdf_buf + curve.ecc_p_wordlen * 4),
			(uint8_t *)point.pubkey_y, curve.ecc_p_wordlen * 4);

	sprd_kdf_update(SPRD_CRYPTO_HASH_SM3, (uint8_t *)kdf_buf, curve.ecc_p_wordlen * 8, outptr, src_size);

	for (i = 0; i < (int)src_size; i++) {
		outptr[i] = outptr[i] ^ src[i];
	}

	outlen += src_size;
	outptr = dst + outlen;

	sprd_crypto_context_t sm3;
	sprd_hash_init(SPRD_CRYPTO_HASH_SM3, &sm3);
	sprd_hash_update(&sm3, (uint8_t *)point.pubkey_x, curve.ecc_p_wordlen * 4);
	sprd_hash_update(&sm3, (uint8_t *)src, src_size);
	sprd_hash_update(&sm3, (uint8_t *)point.pubkey_y, curve.ecc_p_wordlen * 4);
	sprd_hash_final(&sm3, outptr);

	outlen += 32;
	*dst_size = outlen;

	return 0;
}

static sprd_crypto_err_t sprd_sm2_decrypt(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *prikey,
		uint8_t *src_ptr, sprd_ecc_pubkey_t *point)
{
	int error = 0;
	uint8_t *buf = NULL;
	uint32_t buf_len = 0;

	SPRD_CRYPTO_LOG_TRACE("start sprd_sm2_public_encrypt\n");

	if (prikey == NULL || point == NULL || src_ptr == NULL) {
		SPRD_CRYPTO_LOG_ERR("NULL point error!\n");
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	buf = sprd_pal_malloc(4096);
	buf_len = 4096;
	if (buf == NULL || buf_len < 4096) {
		SPRD_CRYPTO_LOG_ERR("buf = %p, buf_len is %d!\n", buf, buf_len);
		error = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	sprd_pal_memset(buf, 0, buf_len);
	sprd_ecc_data_t *data = (sprd_ecc_data_t *) buf;
	data->req_id = SPRD_ECC_REQUEST_PRI_DEC;
	sprd_ecc_get_curve(curve_id, &(data->curve));

	sprd_pal_memcpy(&(data->param.enc_dec.dB), prikey, sizeof(sprd_ecc_prikey_t));

	src_ptr += 1;
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.C1.pubkey_x), src_ptr, data->curve.ecc_p_wordlen * 4);
	src_ptr += data->curve.ecc_p_wordlen * 4;
	sprd_pal_memcpy((uint8_t *)(data->param.enc_dec.C1.pubkey_y), src_ptr, data->curve.ecc_p_wordlen * 4);
	src_ptr += data->curve.ecc_p_wordlen * 4;
	sprd_pal_flush_by_vaddr(buf, buf_len);
	sprd_sm2_queue_and_wait(data);
	error = data->error_code;
	sprd_pal_invalidate_by_vaddr(buf, buf_len);

	sprd_pal_memcpy((uint8_t *)point->pubkey_x, (uint8_t *)&data->param.enc_dec.point.pubkey_x,
			data->curve.ecc_p_wordlen * 4);
	sprd_pal_memcpy((uint8_t *)point->pubkey_y, (uint8_t *)&data->param.enc_dec.point.pubkey_y,
			data->curve.ecc_p_wordlen * 4);
failed:
	if(buf != NULL){
		sprd_pal_free(buf);
	}

	return error;
}

sprd_crypto_err_t sprd_sm2_private_decrypt(sprd_ecc_curveid_t curve_id, sprd_ecc_prikey_t *prikey,
		uint8_t *src, uint32_t src_size, uint8_t *dst, uint32_t *dst_size)
{
	int error = 0;
	int i;
	uint8_t kdf_buf[64];
	uint8_t *outptr = dst;
	uint32_t c2_len;
	uint32_t tmp[32];
	uint8_t *src_ptr = src;
	sprd_ecc_curve_t curve;
	sprd_ecc_pubkey_t point;

	SPRD_CRYPTO_LOG_TRACE("start sprd_sm2_public_encrypt\n");

	if (src == NULL || dst == NULL || prikey == NULL) {
		SPRD_CRYPTO_LOG_ERR("NULL point error!\n");
		return SPRD_ECC_NULL_POINTER_ERROR;
	}

	sprd_sm2_decrypt(curve_id, prikey, src_ptr, &point);
	sprd_ecc_get_curve(curve_id, &curve);

	src_ptr += 1;
	src_ptr += curve.ecc_p_wordlen * 4;
	src_ptr += curve.ecc_p_wordlen * 4;
	sprd_pal_memcpy((uint8_t *)kdf_buf, (uint8_t *)point.pubkey_x,
			curve.ecc_p_wordlen * 4);
	sprd_pal_memcpy((uint8_t *)(kdf_buf + curve.ecc_p_wordlen * 4),
			(uint8_t *)point.pubkey_y, curve.ecc_p_wordlen * 4);

	c2_len = src_size - curve.ecc_p_wordlen * 4 * 2 - 32 -1;
	sprd_kdf_update(SPRD_CRYPTO_HASH_SM3, (uint8_t *)kdf_buf, curve.ecc_p_wordlen * 8, outptr, c2_len);

	for (i = 0; i < (int)c2_len; i++) {
		outptr[i] = outptr[i] ^ src_ptr[i];
	}

	sprd_crypto_context_t sm3;
	sprd_hash_init(SPRD_CRYPTO_HASH_SM3, &sm3);
	sprd_hash_update(&sm3, (uint8_t *)point.pubkey_x, curve.ecc_p_wordlen * 4);
	sprd_hash_update(&sm3, (uint8_t *)outptr, c2_len);
	sprd_hash_update(&sm3, (uint8_t *)point.pubkey_y, curve.ecc_p_wordlen * 4);
	sprd_hash_final(&sm3, (uint8_t *)tmp);

	src_ptr += c2_len;
	if (sprd_pal_memcmp(tmp, src_ptr, 32) != 0) {
		SPRD_CRYPTO_LOG_ERR("private decrypt failed!\n");
		return SPRD_ECC_PRI_DEC_ERROR;
	}

	*dst_size = c2_len;

	return error;
}

sprd_crypto_err_t sprd_sm2_getz(uint8_t *ID,  uint16_t IDByteLen, uint8_t *pubkey, uint8_t *Z)
{
	int ret = 0;
	uint8_t idlen[2];
	sprd_crypto_context_t sm3;
	sprd_ecc_curve_t  *ecc_curve = &g_ecc_curve;

	if (ID == NULL)
		return SPRD_CRYPTO_INVALID_ARG;
	ret |= sprd_hash_init(SPRD_CRYPTO_HASH_SM3, &sm3);
	sprd_u16_to_u8_invert(&IDByteLen, 1, idlen);
	ret |= sprd_hash_update(&sm3, (uint8_t *)idlen, 2);
	ret |= sprd_hash_update(&sm3, (uint8_t *)ID, IDByteLen / 8);
	ret |= sprd_hash_update(&sm3, (uint8_t *)ecc_curve->ecc_a, ecc_curve->ecc_p_wordlen * 4);
	ret |= sprd_hash_update(&sm3, (uint8_t *)ecc_curve->ecc_b, ecc_curve->ecc_p_wordlen * 4);
	ret |= sprd_hash_update(&sm3, (uint8_t *)ecc_curve->ecc_gx, ecc_curve->ecc_p_wordlen * 4);
	ret |= sprd_hash_update(&sm3, (uint8_t *)ecc_curve->ecc_gy, ecc_curve->ecc_p_wordlen * 4);
	ret |= sprd_hash_update(&sm3, (uint8_t *)pubkey, 64);
	ret |= sprd_hash_final(&sm3, Z);

	return ret;
}
