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
*/

#include <sprd_crypto.h>
#include <sprd_aes.h>
#include <sprd_ce.h>

sprd_crypto_err_t
sprd_aes_get_context_size (sprd_crypto_algo_t algo, uint32_t *size) {
	return sizeof(sprd_crypto_context_t);
}

sprd_crypto_err_t
sprd_aes_init (sprd_crypto_algo_t algo, uint32_t decrypt,
		sprd_crypto_context_t* context,
		const uint8_t *key1, const uint8_t *key2, uint32_t key_len,
		const uint8_t *iv, uint32_t iv_len) {

	SPRD_CRYPTO_LOG_TRACE("enter!\n");
	sprd_crypto_err_t err;

	if ((algo != SPRD_CRYPTO_AES_CBC_HUK && algo != SPRD_CRYPTO_AES_CMAC_HUK
	  && algo != SPRD_CRYPTO_AES_CBC_KCE)
	  && (key1 == NULL || !(key_len == 16 || key_len == 24 || key_len == 32))) {
		SPRD_CRYPTO_LOG_ERR("Bad AES key1!\n");
		return SPRD_CRYPTO_INVALID_ARG;
	}

	if (algo == SPRD_CRYPTO_AES_XTS && key2 == NULL) {
		SPRD_CRYPTO_LOG_ERR("Bad AES key2!\n");
		return SPRD_CRYPTO_INVALID_ARG;
	}

	if ((algo != SPRD_CRYPTO_AES_ECB && algo != SPRD_CRYPTO_AES_CMAC && algo != SPRD_CRYPTO_AES_CMAC_HUK)
		&& (iv == NULL || iv_len != 16)) {
		SPRD_CRYPTO_LOG_ERR("Bad AES iv!\n");
		return SPRD_CRYPTO_INVALID_ARG;
	}

	sprd_pal_memset(context, 0, sizeof(sprd_crypto_context_t));
	if (algo == SPRD_CRYPTO_AES_GCM) {
		context->info.aes.dump = sprd_pal_malloc(SPRD_CRYPTO_DUMP_SIZE);
		if (context->info.aes.dump == NULL) {
			return SPRD_CRYPTO_OUTOFMEM;
		}
		sprd_pal_flush_by_vaddr(context->info.aes.dump, SPRD_CRYPTO_DUMP_SIZE);

		context->info.aes.temp_dump = sprd_pal_malloc(SPRD_CRYPTO_DUMP_SIZE);
		if (context->info.aes.temp_dump == NULL) {
			if (context->info.aes.dump != NULL){
				sprd_pal_free(context->info.aes.dump);
				context->info.aes.dump = NULL;
			}

			return SPRD_CRYPTO_OUTOFMEM;
		}

		sprd_pal_flush_by_vaddr(context->info.aes.temp_dump, SPRD_CRYPTO_DUMP_SIZE);
	} else {
		context->info.aes.dump = sprd_pal_malloc(SPRD_CRYPTO_DUMP_SIZE);
		if (context->info.aes.dump == NULL) {
			SPRD_CRYPTO_LOG_ERR("context->info.aes.dump = NULL!\n");
			return SPRD_CRYPTO_OUTOFMEM;
		}
		sprd_pal_flush_by_vaddr(context->info.aes.dump, SPRD_CRYPTO_DUMP_SIZE);
	}

	context->algo = algo;
	context->info.aes.decrypt = decrypt;
	if (key1 != NULL) {
		sprd_pal_memcpy(context->info.aes.key1, key1, key_len);
	}
	context->info.aes.key1_len = key_len;

	if (key2 != NULL) {
		sprd_pal_memcpy(context->info.aes.key2, key2, key_len);
		context->info.aes.key2_len = key_len;
	}

	if (iv != NULL) {
		sprd_pal_memcpy(context->info.aes.iv, iv, iv_len);
		context->info.aes.iv_len = iv_len;
	}
	/*hdcp lc128 support*/
	if (algo == SPRD_CRYPTO_AES_CTR_HDCP) {
#if 0
		//1.read rpmb ic128
		uint8_t *ic128_cipher;
		//2.gen efuse key to ce_iram
		uint8_t seed[16] = "adcdef0123456789";
		uint32_t err;
		sprd_crypto_context_t aes;
		err = sprd_aes_init(SPRD_CRYPTO_AES_CBC_HUK_HDCP, SPRD_CRYPTO_DEC, &aes, NULL, NULL, 16, iv, ivlen);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("aes_cbc encrypt test init FAILED [%d]\n", err);
			err = SPRD_CRYPTO_ERR_RESULT;
			return err;
		}
		err = sprd_aes_process(&aes, seed, tmp, 16);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("aes_cbc encrypt test process FAILED [%d]\n", err);
			err = SPRD_CRYPTO_ERR_RESULT;
			return err;
		}
		err = sprd_aes_final();
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("aes_cbc encrypt test final FAILED [%d]\n", err);
			err = SPRD_CRYPTO_ERR_RESULT;
			return err;
		}
		//3.use efuse key dec ic128 to ce_iram
		err = sprd_aes_init(SPRD_CRYPTO_AES_CBC_HDCP, SPRD_CRYPTO_DEC, &aes, NULL, NULL, 16, iv, ivlen);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("aes_cbc encrypt test init FAILED [%d]\n", err);
			err = SPRD_CRYPTO_ERR_RESULT;
			return err;
		}
		err = sprd_aes_process(&aes, seed, tmp, 16);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("aes_cbc encrypt test process FAILED [%d]\n", err);
			err = SPRD_CRYPTO_ERR_RESULT;
			return err;
		}
		err = sprd_aes_final();
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("aes_cbc encrypt test final FAILED [%d]\n", err);
			err = SPRD_CRYPTO_ERR_RESULT;
			return err;
		}
#endif
	}

	err = sprd_crypto_open(context);
	if (err == SPRD_CRYPTO_SUCCESS) {
		return err;
	} else {
		SPRD_CRYPTO_LOG_ERR("FAILED!\n");
		return SPRD_CRYPTO_ERROR;
	}
}

sprd_crypto_err_t
sprd_aes_process_internal(sprd_crypto_context_t *context,
			uint8_t *in, uint32_t in_len,
			uint8_t *out, uint32_t out_len) {
	sprd_crypto_err_t err;
	uint8_t *in_temp, *out_temp;
	uint32_t len_temp;
	uint8_t end_temp;
	uint32_t count = 0;
	uint8_t *buf = NULL;
	uint32_t buf_len = 65536;

	SPRD_CRYPTO_LOG_TRACE("in = %p, in_len = %d, out = %p, out_len = %d, end = %d\n",
				in, in_len, out, out_len, context->end);

	end_temp = context->end;

	buf = sprd_pal_malloc(buf_len);
	if (buf == NULL) {
		SPRD_CRYPTO_LOG_ERR("buf = %p\n", buf);
		err = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}
	if (buf_len < SPRD_PAL_CACHE_LINE) {
		SPRD_CRYPTO_LOG_ERR("buf_len = %d!\n", buf_len);
		err = SPRD_CRYPTO_OUTOFMEM;
		goto failed;
	}

	count = (in_len + buf_len -1) /buf_len;

	in_temp = in;
	out_temp = out;
	while (count > 0) {
		len_temp = count > 1 ? buf_len : in_len - (in_temp - in);
		sprd_pal_memcpy(buf, in_temp, len_temp);

		context->end = count > 1 ? 0: end_temp;
		context->in = buf;
		context->in_len = len_temp;
		context->out = buf;
		context->out_len = len_temp;
		sprd_pal_flush_by_vaddr(buf, buf_len);

		err = sprd_crypto_process(context);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("sprd_crypto_process return 0x%x\n", err);
			goto failed;
		}

		sprd_crypto_polling();
		if (out_temp != NULL) {
			sprd_pal_invalidate_by_vaddr(buf, buf_len);
			sprd_pal_memcpy(out_temp, buf, len_temp);
			out_temp += len_temp;
		}
		in_temp += len_temp;

		count--;
	}

	if (buf != NULL) {
		sprd_pal_free(buf);
	}

	return SPRD_CRYPTO_SUCCESS;

failed:
	if (buf != NULL) {
		sprd_pal_free(buf);
	}

	if (err != SPRD_CRYPTO_SUCCESS) {
		if (context->info.aes.dump != NULL) {
			sprd_pal_free(context->info.aes.dump);
			context->info.aes.dump = NULL;
		}
		if (context->info.aes.temp_dump != NULL) {
			sprd_pal_free(context->info.aes.temp_dump);
			context->info.aes.temp_dump = NULL;
		}
	}
	sprd_crypto_close(context);
	return err;
}

sprd_crypto_err_t
sprd_aes_process (sprd_crypto_context_t* context,
		const uint8_t *in, uint8_t *out, uint32_t len) {
	SPRD_CRYPTO_LOG_TRACE("enter !\n");
	if (in == NULL || out == NULL || len == 0
			|| len % SPRD_CRYPTO_AES_BLOCK_SIZE != 0) {
		return SPRD_CRYPTO_INVALID_ARG;
	}
	context->end = 0;
	return sprd_aes_process_internal(context, (uint8_t*)in, len, out, len);
}

sprd_crypto_err_t
sprd_aes_final(sprd_crypto_context_t* context,
		const uint8_t *in, uint32_t in_len,
		uint8_t *out, uint32_t *out_len,
		sprd_sym_padding_t padding) {
	sprd_crypto_err_t err = SPRD_CRYPTO_SUCCESS;
	SPRD_CRYPTO_LOG_TRACE("enter !\n");

	if (in != NULL && (out == NULL || out_len == NULL || *out_len < in_len)) {
	    SPRD_CRYPTO_LOG_ERR("err = %d\n", err);
		err = SPRD_CRYPTO_INVALID_ARG;
		goto failed;
	}

	if (in_len % SPRD_CRYPTO_AES_BLOCK_SIZE != 0) {
		err = SPRD_CRYPTO_INVALID_ARG;
	    SPRD_CRYPTO_LOG_ERR("err = %d\n", err);
		goto failed;
	}

	switch (padding) {
	case SPRD_SYM_NOPAD:
		break;
	case SPRD_SYM_PKCS5_PAD:
		break;
	case SPRD_SYM_ZERO_PAD:
		break;
	default:
		return SPRD_CRYPTO_INVALID_ARG;
	}

	if (in != NULL && in_len != 0) {
		context->end = 1;
		err = sprd_aes_process_internal(context, (uint8_t*)in, in_len, out, in_len);
		if (err != SPRD_CRYPTO_SUCCESS) {
			SPRD_CRYPTO_LOG_ERR("sprd_aes_process_internal FAILED[0x%x]\n", err);
			goto failed;
		}

		if (out_len != NULL) {
			*out_len = in_len;
		}
	}

failed:
	if (context->info.aes.dump != NULL) {
		sprd_pal_free(context->info.aes.dump);
		context->info.aes.dump = NULL;
	}
	if (context->info.aes.temp_dump != NULL) {
		sprd_pal_free(context->info.aes.temp_dump);
		context->info.aes.temp_dump = NULL;
	}
	sprd_crypto_close(context);
	return err;
}
