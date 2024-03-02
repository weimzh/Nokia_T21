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

#include <sprd_ce.h>
#include <sprd_crypto.h>
#include <sprd_pka.h>

//#define SPRD_CE_ARGCHK(x)   if (!(x)) return SPRD_CE_ERR_ARG;

static void* s_ahb_vaddr;
static void* s_ce_vaddr;

#define REG_SET_VAL(__base, __offset,__v)	((*(volatile uint32_t *)((__base) + (__offset))) = (uint32_t)(__v))
#define REG_GET_VAL(__base, __offset)		 (*(volatile uint32_t *)((__base) + (__offset)))

static uint32_t get_paddr_hi (void *vaddr){
	void *paddr = sprd_pal_vaddr_to_paddr(vaddr);
	return (uint32_t)(((uintptr_t)paddr & 0xF00000000ULL) >> 32);
};

static uint32_t get_paddr_lo (void *vaddr){
	void *paddr = sprd_pal_vaddr_to_paddr(vaddr);
	return (uint32_t)((uintptr_t)paddr & 0xFFFFFFFFULL);
};

static uint32_t get_pka_paddr_hi (uint8_t *vaddr){
	void *paddr = sprd_pal_vaddr_to_paddr(vaddr);
	return (uint32_t)(((uintptr_t)paddr & 0xFFFFE0000ULL) >> 17);
};

static uint32_t get_pka_paddr_lo (uint8_t *vaddr){
	void *paddr = sprd_pal_vaddr_to_paddr(vaddr);
	return (uint32_t)(((uintptr_t)paddr & 0x1FFFFULL));
};

void sprd_crypto_init_ce_cfg(sprd_ce_cfg_t* ce_cfg) {
	*(uint32_t*)(ce_cfg) = 0x0;
	ce_cfg->src_outstanding_num = 0x7;
	ce_cfg->dst_outstanding_num = 0x7;
	ce_cfg->src_word_switch = 0x0;
	ce_cfg->dst_word_switch = 0x0;
	ce_cfg->src_byte_switch = 0x1;
	ce_cfg->dst_byte_switch = 0x1;
	ce_cfg->do_wait_bdone = 0x1;
	ce_cfg->key_in_iram = 0x0;
	ce_cfg->key_in_session = 0x0;
	ce_cfg->key_in_efuse = 0x0;
	ce_cfg->key_in_ddr = 0x0;
	ce_cfg->dma_bypass = 0x0;
	ce_cfg->std_aad = 0x0;
	ce_cfg->std_aad_end = 0x0;
	ce_cfg->std_end = 0;
	ce_cfg->cmd_ioc = 0x1;
	ce_cfg->dont_dump_ddr = 0;
	ce_cfg->dont_rcv_ddr = 0;
	ce_cfg->link_mode = SPRD_CE_STD;
}

void sprd_ce_write_cmd_cfg(uint32_t reg, uint32_t reg_num, uint32_t* reg_val) {
	uint32_t i;
	uint32_t cfg_reg_op = ((0x1 & 0xF) << 28)
		| ((reg_num & 0x1F) << 16)
		| (reg & 0xFFFF);

	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, cfg_reg_op);
	REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, cfg_reg_op);

	for(i = 0; i< reg_num; i++) {
		SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, *(reg_val+i));
		REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, *(reg_val+i));
	}
}

void sprd_ce_write_cmd_start(sprd_ce_start_param_t *param) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
	uint32_t start_op = (((uint32_t)0x2 & 0xF) << 28)
		| ((param->algo & 0x7000000) >> 4)
		| (*((uint32_t*)(&param->rcv_dump_addr_hi)) & 0xFF) << 8;

	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, start_op);
	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, *(uint32_t*)(&param->algo_cfg));
	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, *(uint32_t*)(&param->ce_cfg));
	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, param->rcv_addr_lo);
	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_CMD_FIFO_ENTRY, param->dump_addr_lo);

	REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, start_op);
	REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, *(uint32_t*)(&param->algo_cfg));
	REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, *(uint32_t*)(&param->ce_cfg));
	REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, param->rcv_addr_lo);
	REG_SET_VAL(s_ce_vaddr, CE_CMD_FIFO_ENTRY, param->dump_addr_lo);
#pragma GCC diagnostic pop
}

#ifdef R5P0LITE
void sprd_ce_write_pka_cmd_cfg(uint32_t reg, uint32_t reg_num, uint32_t* reg_val) {
	uint32_t i;
	uint32_t cfg_reg_op = ((0x1 & 0xF) << 28)
		| ((reg_num & 0x1F) << 16)
		| (reg & 0xFFFF);

	SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, cfg_reg_op);
	REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, cfg_reg_op);

	for(i = 0; i< reg_num; i++) {
		SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, *(reg_val+i));
		REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, *(reg_val+i));
	}
}

void sprd_ce_write_cmd_start_pka(sprd_ce_start_param_t *param, uint32_t pka_addr) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
    uint32_t start_op = (((uint32_t)0x2 & 0xF) << 28)
        | ((param->algo & 0x7000000) >> 4);
        // leave blank after
        //| (*((uint32_t*)(&param->rcv_dump_addr_hi)) & 0xFF) << 8;

    SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, start_op);
    SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, *(uint32_t*)(&param->algo_cfg));
    SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, *(uint32_t*)(&param->ce_cfg));
    /*SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, param->rcv_addr_lo);*/
    /*SPRD_CRYPTO_LOG_TRACE("[0x%x] = 0x%x\n", CE_PKA_CMD_FIFO_ENTRY, param->dump_addr_lo);*/

    REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, start_op);
    REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, *(uint32_t*)(&(param->algo_cfg.pka)));
    REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, pka_addr);
    /*REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, param->rcv_addr_lo);*/
    /*REG_SET_VAL(s_ce_vaddr, CE_PKA_CMD_FIFO_ENTRY, param->dump_addr_lo);*/
#pragma GCC diagnostic pop
}
#endif

void sprd_ce_write_cmd_hash(sprd_crypto_context_t* context) {
	sprd_ce_data_t data;
	sprd_ce_start_param_t start_param;

	sprd_pal_memset(&data, 0, sizeof(sprd_ce_data_t));
	data.src_addr_hi = get_paddr_hi(context->in);
	data.src_addr_lo = get_paddr_lo(context->in);
	data.src_frag_len = context->in_len & 0xFFFFFF;
	data.dst_addr_hi = get_paddr_hi(context->out);
	data.dst_addr_lo = get_paddr_lo(context->out);
	data.dst_frag_len = context->out_len & 0xFFFFFF;
	sprd_ce_write_cmd_cfg(CE_SRC_FLAG_LEN, 4, (uint32_t*)(&data));

	//start
	sprd_pal_memset(&start_param, 0, sizeof(sprd_ce_start_param_t));
	start_param.algo = context->algo;
	//set ce config
	sprd_crypto_init_ce_cfg(&start_param.ce_cfg);
	start_param.ce_cfg.std_end = context->end;
	start_param.ce_cfg.dont_dump_ddr = (context->end == 0 ? 0 : 1);
	start_param.ce_cfg.dont_rcv_ddr = (context->continued == 0 ? 1 : 0);
	//set algo config
	start_param.algo_cfg.hash.mode = context->algo & SPRD_CRYPTO_SUB_MODE_MASK;
	start_param.algo_cfg.hash.en = 0x1;
	//set dump addr
	start_param.rcv_dump_addr_hi.rcv_addr_hi = get_paddr_hi(context->info.hash.dump);
	start_param.rcv_dump_addr_hi.dump_addr_hi = get_paddr_hi(context->info.hash.dump);
	start_param.rcv_addr_lo = get_paddr_lo(context->info.hash.dump);
	start_param.dump_addr_lo = get_paddr_lo(context->info.hash.dump);
	sprd_ce_write_cmd_start(&start_param);
}

#ifndef R5P0LITE
void sprd_ce_write_cmd_rsa(sprd_crypto_context_t* context) {
	sprd_ce_pka_data_t data;
	uint32_t pka_reg_len01;
	sprd_ce_start_param_t start_param;

	pka_reg_len01 = context->info.rsa.key_len;
	sprd_ce_write_cmd_cfg(CE_PKA_REG_LEN01, 1, &pka_reg_len01);
	sprd_pal_memset(&data, 0, sizeof(sprd_ce_pka_data_t));
	data.pka_store_addr_hi = get_pka_paddr_hi(context->out);
	data.pka_instr_addr_hi = get_paddr_hi((void*)(context->info.rsa.pka_cmd));
	data.pka_instr_addr_lo = get_paddr_lo((void*)(context->info.rsa.pka_cmd));
	data.pka_instr_len = 16 & 0xFFFFFF;
	sprd_ce_write_cmd_cfg(CE_PKA_CMD_FLAG_LEN, 4, (uint32_t*)(&data));

	//start
	sprd_pal_memset(&start_param, 0, sizeof(sprd_ce_start_param_t));
	start_param.algo = context->algo;
	//set ce config
	sprd_crypto_init_ce_cfg(&start_param.ce_cfg);
	start_param.ce_cfg.src_word_switch = 0x1;
	start_param.ce_cfg.dst_word_switch = 0x0;
	start_param.ce_cfg.key_in_ddr = 0x1;
	start_param.ce_cfg.std_end = 1;
	start_param.ce_cfg.dont_dump_ddr = 1;
	start_param.ce_cfg.dont_rcv_ddr = 1;
	//set algo config
	start_param.algo_cfg.pka.find_prime_num = 0xff;
	start_param.algo_cfg.pka.reg_num_sel = 0x1;
	start_param.algo_cfg.pka.en = 0x1;

	//load n
	data.pka_load_addr_hi = get_pka_paddr_hi(context->info.rsa.key_n);
	sprd_ce_write_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	context->info.rsa.pka_cmd[0] =
		sprd_pka_load(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_0, 1, get_pka_paddr_lo(context->info.rsa.key_n));
	context->info.rsa.pka_cmd[1] =
			sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rsa.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);
	sprd_ce_write_cmd_start(&start_param);
	sprd_ce_polling();

	//load e
	data.pka_load_addr_hi = get_pka_paddr_hi(context->info.rsa.key_eod);
	sprd_ce_write_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	context->info.rsa.pka_cmd[0] =
			sprd_pka_load(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_2, 1, get_pka_paddr_lo(context->info.rsa.key_eod));
	context->info.rsa.pka_cmd[1] =
			sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rsa.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);
	sprd_ce_write_cmd_start(&start_param);
	sprd_ce_polling();

	//load in and cal
	data.pka_load_addr_hi = get_pka_paddr_hi(context->in);
	sprd_ce_write_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	context->info.rsa.pka_cmd[0] =
		sprd_pka_load(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_1, 1, get_pka_paddr_lo(context->in));
	context->info.rsa.pka_cmd[1] =
		sprd_pka_mod_exp(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_3, SPRD_CE_PKA_REG_1, SPRD_CE_PKA_REG_2);;
	context->info.rsa.pka_cmd[2] =
		sprd_pka_store(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_3, 1, get_pka_paddr_lo(context->out));
	context->info.rsa.pka_cmd[3] =
		sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rsa.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);
	sprd_ce_write_cmd_start(&start_param);
}

#else

void sprd_ce_write_cmd_rsa(sprd_crypto_context_t* context) {
	sprd_ce_pka_data_t data;
	uint32_t pka_reg_len01;
	sprd_ce_start_param_t start_param;

	pka_reg_len01 = context->info.rsa.key_len;
	sprd_ce_write_pka_cmd_cfg(CE_PKA_REG_LEN01, 1, &pka_reg_len01);
	sprd_pal_memset(&data, 0, sizeof(sprd_ce_pka_data_t));
	data.pka_store_addr_hi = get_pka_paddr_hi(context->out);
	/*data.pka_instr_addr_hi = get_paddr_hi((void*)(context->info.rsa.pka_cmd));*/
	/*data.pka_instr_addr_lo = get_paddr_lo((void*)(context->info.rsa.pka_cmd));*/
	/*data.pka_instr_len = 16 & 0xFFFFFF;*/
	/*sprd_ce_write_pka_cmd_cfg(CE_PKA_CMD_FLAG_LEN, 4, (uint32_t*)(&data));*/
	sprd_ce_write_pka_cmd_cfg(CE_PKA_STORE_ADDR_HI, 1, (uint32_t*)(&data.pka_store_addr_hi));

	//start
	sprd_pal_memset(&start_param, 0, sizeof(sprd_ce_start_param_t));
	start_param.algo = context->algo;
	//set ce config
	/*sprd_crypto_init_ce_cfg(&start_param.ce_cfg);*/
	/*start_param.ce_cfg.src_word_switch = 0x1;*/
	/*start_param.ce_cfg.dst_word_switch = 0x0;*/
	/*start_param.ce_cfg.key_in_ddr = 0x1;*/
	/*start_param.ce_cfg.std_end = 1;*/
	/*start_param.ce_cfg.dont_dump_ddr = 1;*/
	/*start_param.ce_cfg.dont_rcv_ddr = 1;*/
	//set algo config
	start_param.algo_cfg.pka.find_prime_num = 0xff;
	start_param.algo_cfg.pka.reg_num_sel = 0x1;
	start_param.algo_cfg.pka.en = 0x1;
	//set r5p0lite param
	start_param.algo_cfg.pka.src_word_switch = 0x0;
	start_param.algo_cfg.pka.dst_word_switch = 0x0;
	start_param.algo_cfg.pka.src_byte_switch = 0x1;
	start_param.algo_cfg.pka.dst_byte_switch = 0x1;
	start_param.algo_cfg.pka.pka_hi_addr = get_paddr_hi(context->info.rsa.pka_cmd);

	//load n
	data.pka_load_addr_hi = get_pka_paddr_hi(context->info.rsa.key_n);
	sprd_ce_write_pka_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	context->info.rsa.pka_cmd[0] =
		sprd_pka_load(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_0, 1, get_pka_paddr_lo(context->info.rsa.key_n));
	context->info.rsa.pka_cmd[1] =
			sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rsa.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);
	sprd_ce_write_cmd_start_pka(&start_param, get_paddr_lo(context->info.rsa.pka_cmd));
	sprd_ce_pka_polling();

	//load e
	data.pka_load_addr_hi = get_pka_paddr_hi(context->info.rsa.key_eod);
	sprd_ce_write_pka_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	context->info.rsa.pka_cmd[0] =
			sprd_pka_load(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_2, 1, get_pka_paddr_lo(context->info.rsa.key_eod));
	context->info.rsa.pka_cmd[1] =
			sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rsa.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);
	sprd_ce_write_cmd_start_pka(&start_param, get_paddr_lo(context->info.rsa.pka_cmd));
	sprd_ce_pka_polling();

	//load in and cal
	data.pka_load_addr_hi = get_pka_paddr_hi(context->in);
	sprd_ce_write_pka_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	context->info.rsa.pka_cmd[0] =
		sprd_pka_load(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_1, 1, get_pka_paddr_lo(context->in));
	context->info.rsa.pka_cmd[1] =
		sprd_pka_mod_exp(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_3, SPRD_CE_PKA_REG_1, SPRD_CE_PKA_REG_2);;
	context->info.rsa.pka_cmd[2] =
		sprd_pka_store(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_3, 1, get_pka_paddr_lo(context->out));
	context->info.rsa.pka_cmd[3] =
		sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rsa.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);
	sprd_ce_write_cmd_start_pka(&start_param, get_paddr_lo(context->info.rsa.pka_cmd));
}
#endif

void sprd_ce_write_cmd_aes(sprd_crypto_context_t* context) {
	uint32_t key[8];
	sprd_ce_iv_t iv;
	sprd_ce_data_t data;
	sprd_ce_aes_tag_t aes_tag;
	sprd_ce_secure_key_t huk;
	sprd_ce_secure_key_t kce;
	sprd_ce_start_param_t start_param;
	uint8_t *temp_iv, *temp_key;
	uint32_t i;
#ifdef HDCP_TEST
	struct {
		uint32_t ce_iram_key0;
		uint32_t ce_iram_key1;
		uint32_t ce_iram_key2;
		uint32_t ce_iram_key3;
		uint32_t ce_iram_key4;
		uint32_t ce_iram_key5;
		uint32_t ce_iram_key6;
		uint32_t ce_iram_key7;
	} iramkey = {
		0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111,0x11111111
	};
#endif

	SPRD_CRYPTO_LOG_TRACE("start sprd_ce_write_cmd_aes\n");

	/* set key */
	switch(context->algo) {
	case SPRD_CRYPTO_AES_XTS:
		if (context->info.aes.key2 != NULL &&  context->info.aes.key2_len > 0) {
			temp_key = context->info.aes.key2;
			for (i = 0; i < context->info.aes.key2_len; i += 4){
				key[i/4] =  (temp_key[i] << 24)
					| (temp_key[i+1] << 16)
					| (temp_key[i+2] << 8)
					| (temp_key[i+3]);
			}
			sprd_ce_write_cmd_cfg(CE_AES_DES_KEY20, context->info.aes.key2_len/4, key);
		}

	case SPRD_CRYPTO_AES_ECB:
	case SPRD_CRYPTO_AES_CBC:
	case SPRD_CRYPTO_AES_CTR:
	case SPRD_CRYPTO_AES_CMAC:
	case SPRD_CRYPTO_AES_GCM:
	case SPRD_CRYPTO_AES_CTR_HDCP:
		if (context->info.aes.key1 != NULL && context->info.aes.key1_len > 0) {
			temp_key = context->info.aes.key1;
			for (i = 0; i < context->info.aes.key1_len; i += 4){
				key[i/4] =  (temp_key[i] << 24)
					| (temp_key[i+1] << 16)
					| (temp_key[i+2] << 8)
					| (temp_key[i+3]);
			}
			sprd_ce_write_cmd_cfg(CE_AES_DES_KEY10, context->info.aes.key1_len/4, key);
		}
#ifdef HDCP_TEST
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY0, iramkey.ce_iram_key0);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY1, iramkey.ce_iram_key1);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY2, iramkey.ce_iram_key2);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY3, iramkey.ce_iram_key3);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY4, iramkey.ce_iram_key4);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY5, iramkey.ce_iram_key5);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY6, iramkey.ce_iram_key6);
		REG_SET_VAL(s_ce_vaddr, CE_IRAM_KEY7, iramkey.ce_iram_key7);
#endif
		break;

	case SPRD_CRYPTO_AES_CBC_HUK:
	case SPRD_CRYPTO_AES_CMAC_HUK:
		sprd_pal_memset(&huk, 0, sizeof(sprd_ce_secure_key_t));
		huk.key1_start_addr = EFUSE_HUK_OFFSET;
		huk.key_len = context->info.aes.key1_len;
		sprd_ce_write_cmd_cfg(CE_SEC_KEY_WORK_MODE, 1, (uint32_t*)(&huk));
		break;

	case SPRD_CRYPTO_AES_CBC_KCE:
		sprd_pal_memset(&kce, 0, sizeof(sprd_ce_secure_key_t));
		kce.key1_start_addr = EFUSE_KCE_OFFSET;
		kce.key_len = context->info.aes.key1_len;
		sprd_ce_write_cmd_cfg(CE_SEC_KEY_WORK_MODE, 1, (uint32_t*)(&kce));
		break;
	}

	/* set iv */
	if (context->continued == 0) {
		sprd_pal_memset(&iv, 0, sizeof(sprd_ce_iv_t));
		switch (context->algo) {
		case SPRD_CRYPTO_AES_ECB:
		case SPRD_CRYPTO_AES_CMAC:
		case SPRD_CRYPTO_AES_CMAC_HUK:
			break;
		case SPRD_CRYPTO_AES_CBC:
		case SPRD_CRYPTO_AES_CTR:
		case SPRD_CRYPTO_AES_XTS:
		case SPRD_CRYPTO_AES_GCM:
		case SPRD_CRYPTO_AES_CBC_HUK:
		case SPRD_CRYPTO_AES_CBC_KCE:
		case SPRD_CRYPTO_AES_CTR_HDCP:
			temp_iv = context->info.aes.iv;
			iv.iv_sec_cnt0 = (temp_iv[0] << 24) | (temp_iv[1] << 16) | (temp_iv[2] << 8) | temp_iv[3];
			iv.iv_sec_cnt1 = (temp_iv[4] << 24) | (temp_iv[5] << 16) | (temp_iv[6] << 8) | temp_iv[7];
			iv.iv_sec_cnt2 = (temp_iv[8] << 24) | (temp_iv[9] << 16) | (temp_iv[10] << 8) | temp_iv[11];
			iv.iv_sec_cnt3 = (temp_iv[12] << 24) | (temp_iv[13] << 16) | (temp_iv[14] << 8) | temp_iv[15];
			break;
		}
		sprd_ce_write_cmd_cfg(CE_IV_SEC_CNT0, 4, (uint32_t*)(&iv));
	}

	/* set data */
	sprd_pal_memset(&data, 0, sizeof(sprd_ce_data_t));
	data.src_addr_hi = get_paddr_hi(context->in);
	data.src_addr_lo = get_paddr_lo(context->in);
	data.src_frag_len = context->in_len & 0xFFFFFF;
	data.dst_addr_hi = get_paddr_hi(context->out);
	data.dst_addr_lo = get_paddr_lo(context->out);
	data.dst_frag_len = context->out_len & 0xFFFFFF;
	sprd_ce_write_cmd_cfg(CE_SRC_FLAG_LEN, 4, (uint32_t*)(&data));

	/* set tag */
	if((context->tag  != NULL)){
		sprd_pal_memset(&aes_tag, 0, sizeof(sprd_ce_aes_tag_t));
		aes_tag.aes_tag_addr_hi = get_paddr_hi(context->tag);
		aes_tag.aes_tag_addr_lo = get_paddr_lo(context->tag);
		aes_tag.aes_tag_len = context->tag_len & 0xFF;
		sprd_ce_write_cmd_cfg(CE_AES_TAG_LEN, 2, (uint32_t*)(&aes_tag));
	}

	/* to initialize start_param */
	sprd_pal_memset(&start_param, 0, sizeof(sprd_ce_start_param_t));
	start_param.algo = context->algo;
	/* set ce config */
	sprd_crypto_init_ce_cfg(&start_param.ce_cfg);
	if (start_param.algo == SPRD_CRYPTO_AES_CBC_HUK
		|| start_param.algo == SPRD_CRYPTO_AES_CMAC_HUK
		|| start_param.algo == SPRD_CRYPTO_AES_CBC_KCE) {
		start_param.ce_cfg.key_in_efuse = 0x1;
	} else if (start_param.algo == SPRD_CRYPTO_AES_CTR_HDCP) {
		start_param.ce_cfg.key_in_iram = 0x1;
		start_param.ce_cfg.key_hdcp_en = 0x1;
    } else {
		start_param.ce_cfg.key_in_ddr = 0x0;
	}
	start_param.ce_cfg.std_aad = context->info.aes.aad_flag;
	start_param.ce_cfg.std_aad_end = context->info.aes.add_end_flag;
	start_param.ce_cfg.std_end = context->end;
	start_param.ce_cfg.dont_dump_ddr = (context->end == 0 ? 0 : 1);
	if(context->algo == SPRD_CRYPTO_AES_GCM &&
	  context->info.aes.processed_len < 16) {
		start_param.ce_cfg.dont_rcv_ddr = 1;
	} else {
		start_param.ce_cfg.dont_rcv_ddr = (context->continued == 0 ? 1 : 0);
	}
	/* set algo config */
	start_param.algo_cfg.aes.xts_iv_rotate = 0;
	switch (context->info.aes.key1_len) {
	case 16:
		start_param.algo_cfg.aes.key_len_sel = 0;
		break;
	case 24:
		start_param.algo_cfg.aes.key_len_sel = 1;
		break;
	case 32:
		start_param.algo_cfg.aes.key_len_sel = 2;
		break;
	default:
		start_param.algo_cfg.aes.key_len_sel = 2;
		break;
	}

	/* set algo mode */
	switch (context->algo) {
	case SPRD_CRYPTO_AES_ECB:
	case SPRD_CRYPTO_AES_CBC:
	case SPRD_CRYPTO_AES_CTR:
	case SPRD_CRYPTO_AES_XTS:
	case SPRD_CRYPTO_AES_CMAC:
	case SPRD_CRYPTO_AES_GCM:
		start_param.algo_cfg.aes.mode = context->algo & SPRD_CRYPTO_SUB_MODE_MASK;
		break;
	case SPRD_CRYPTO_AES_CTR_HDCP:
		start_param.algo_cfg.aes.mode = SPRD_CRYPTO_AES_CTR & SPRD_CRYPTO_SUB_MODE_MASK;
		break;
	case SPRD_CRYPTO_AES_CBC_HUK:
	case SPRD_CRYPTO_AES_CBC_KCE:
		start_param.algo_cfg.aes.mode = SPRD_CRYPTO_AES_CBC & SPRD_CRYPTO_SUB_MODE_MASK;
		break;
	case SPRD_CRYPTO_AES_CMAC_HUK:
		start_param.algo_cfg.aes.mode = SPRD_CRYPTO_AES_CMAC & SPRD_CRYPTO_SUB_MODE_MASK;
		break;
	}

	start_param.algo_cfg.aes.enc_dec_sel = context->info.aes.decrypt;
	start_param.algo_cfg.aes.en = 0x1;

	/* set dump addr */
	start_param.rcv_dump_addr_hi.rcv_addr_hi = get_paddr_hi(context->info.aes.dump);
	if(context->algo == SPRD_CRYPTO_AES_GCM &&
	   context->info.aes.smaller_than_sixteen_times) {
		start_param.rcv_dump_addr_hi.dump_addr_hi = get_paddr_hi(context->info.aes.temp_dump);
	} else {
		start_param.rcv_dump_addr_hi.dump_addr_hi = get_paddr_hi(context->info.aes.dump);
	}

	start_param.rcv_addr_lo = get_paddr_lo(context->info.aes.dump);

	if(context->algo == SPRD_CRYPTO_AES_GCM &&
	   context->info.aes.smaller_than_sixteen_times) {
		start_param.dump_addr_lo= get_paddr_lo(context->info.aes.temp_dump);
	} else {
		start_param.dump_addr_lo = get_paddr_lo(context->info.aes.dump);
	}

	sprd_ce_write_cmd_start(&start_param);

	SPRD_CRYPTO_LOG_TRACE("finish sprd_ce_write_cmd_aes\n");
}

#ifndef R5P0LITE
void sprd_ce_write_cmd_rng(sprd_crypto_context_t* context) {
	sprd_ce_pka_data_t data;
	uint32_t pka_reg_len01;
	sprd_ce_start_param_t start_param;

	context->info.rng.pka_cmd[0] =
		sprd_pka_load_rng(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_0);
	context->info.rng.pka_cmd[1] =
		sprd_pka_store(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_0, 1, get_pka_paddr_lo(context->out));
	context->info.rng.pka_cmd[2] = sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rng.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);

	pka_reg_len01 = context->out_len;
	sprd_ce_write_cmd_cfg(CE_PKA_REG_LEN01, 1, &pka_reg_len01);
	sprd_pal_memset(&data, 0, sizeof(sprd_ce_pka_data_t));
	data.pka_load_addr_hi = 0;
	data.pka_store_addr_hi = get_pka_paddr_hi(context->out);
	data.pka_instr_addr_hi = get_paddr_hi((void*)(context->info.rng.pka_cmd));
	data.pka_instr_addr_lo = get_paddr_lo((void*)(context->info.rng.pka_cmd));
	data.pka_instr_len = (12) & 0xFFFFFF;
	sprd_ce_write_cmd_cfg(CE_PKA_CMD_FLAG_LEN, 4, (uint32_t*)(&data));

	//start
	sprd_pal_memset(&start_param, 0, sizeof(sprd_ce_start_param_t));
	start_param.algo = context->algo;
	//set ce config
	sprd_crypto_init_ce_cfg(&start_param.ce_cfg);
	start_param.ce_cfg.src_word_switch = 0x1;
	start_param.ce_cfg.dst_word_switch = 0x0;
	start_param.ce_cfg.std_end = 1;
	start_param.ce_cfg.dont_dump_ddr = 1;
	start_param.ce_cfg.dont_rcv_ddr = 1;
	//set algo config
	start_param.algo_cfg.pka.find_prime_num = 0xff;
	start_param.algo_cfg.pka.reg_num_sel = 0x1;
	start_param.algo_cfg.pka.en = 0x1;
	sprd_ce_write_cmd_start(&start_param);
}
#else
void sprd_ce_write_cmd_rng(sprd_crypto_context_t* context) {
	sprd_ce_pka_data_t data;
	uint32_t pka_reg_len01;
	sprd_ce_start_param_t start_param;

	context->info.rng.pka_cmd[0] =
		sprd_pka_load_rng(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_0);
	context->info.rng.pka_cmd[1] =
		sprd_pka_store(SPRD_CE_PKA_LEN_0, SPRD_CE_PKA_REG_0, 1, get_pka_paddr_lo(context->out));
	context->info.rng.pka_cmd[2] = sprd_pka_stop();
	sprd_pal_clean_by_vaddr(context->info.rng.pka_cmd, SPRD_CRYPTO_PKA_CMD_LEN*4);

	pka_reg_len01 = context->out_len;
	sprd_ce_write_pka_cmd_cfg(CE_PKA_REG_LEN01, 1, &pka_reg_len01);
	sprd_pal_memset(&data, 0, sizeof(sprd_ce_pka_data_t));
	data.pka_load_addr_hi = 0;
	data.pka_store_addr_hi = get_pka_paddr_hi(context->out);
	//data.pka_instr_addr_hi = get_paddr_hi((void*)(context->info.rng.pka_cmd));
	//data.pka_instr_addr_lo = get_paddr_lo((void*)(context->info.rng.pka_cmd));
	//data.pka_instr_len = (12) & 0xFFFFFF;
	//sprd_ce_write_cmd_cfg(CE_PKA_CMD_FLAG_LEN, 4, (uint32_t*)(&data));
	sprd_ce_write_pka_cmd_cfg(CE_PKA_LOAD_ADDR_HI, 1, (uint32_t*)(&data.pka_load_addr_hi));
	sprd_ce_write_pka_cmd_cfg(CE_PKA_STORE_ADDR_HI, 1, (uint32_t*)(&data.pka_store_addr_hi));

	//start
	sprd_pal_memset(&start_param, 0, sizeof(sprd_ce_start_param_t));
	start_param.algo = context->algo;
	//set ce config
	//sprd_crypto_init_ce_cfg(&start_param.ce_cfg);
	//start_param.ce_cfg.src_word_switch = 0x1;
	//start_param.ce_cfg.dst_word_switch = 0x0;
	//start_param.ce_cfg.std_end = 1;
	//start_param.ce_cfg.dont_dump_ddr = 1;
	//start_param.ce_cfg.dont_rcv_ddr = 1;
	//set algo config
	start_param.algo_cfg.pka.find_prime_num = 0xff;
	start_param.algo_cfg.pka.reg_num_sel = 0x1;
	start_param.algo_cfg.pka.en = 0x1;
	//set r5p0lite param
	start_param.algo_cfg.pka.src_word_switch = 0x0;
	start_param.algo_cfg.pka.dst_word_switch = 0x0;
	start_param.algo_cfg.pka.src_byte_switch = 0x1;
	start_param.algo_cfg.pka.dst_byte_switch = 0x1;
	start_param.algo_cfg.pka.pka_hi_addr = get_paddr_hi(context->info.rng.pka_cmd);
	sprd_ce_write_cmd_start_pka(&start_param, get_paddr_lo(context->info.rng.pka_cmd));
}
#endif

void sprd_ce_write_cmd_ecc(sprd_crypto_context_t* context) {
	sprd_ecc_data_t *data = context->info.ecc.data;
	sprd_ce_start_param_t start_param;

	sprd_ecc_core_handler(data);

	/* to initialize start_param */
	if (sec_memset(&start_param, 0, sizeof(sprd_ce_start_param_t)) == NULL) {
		SPRD_CRYPTO_LOG_ERR("sprd_memset failed!\n");
		return SPRD_ECC_ERROR_BASE;
	}
	start_param.algo = context->algo;
	sprd_crypto_init_ce_cfg(&start_param.ce_cfg);
	start_param.ce_cfg.src_word_switch = 0x1;
	start_param.ce_cfg.dst_word_switch = 0x0;
	start_param.ce_cfg.src_byte_switch = 0x0;
	start_param.ce_cfg.dst_byte_switch = 0x0;
	start_param.ce_cfg.key_in_ddr = 0x1;
	start_param.ce_cfg.std_end = 1;
	start_param.ce_cfg.dont_dump_ddr = 1;
	start_param.ce_cfg.dont_rcv_ddr = 1;
	start_param.algo_cfg.pka.en = 0x1;
#ifndef R3P0
	start_param.algo_cfg.pka.src_word_switch = 0x1;
	start_param.algo_cfg.pka.dst_word_switch = 0x0;
	start_param.algo_cfg.pka.src_byte_switch = 0x0;
	start_param.algo_cfg.pka.dst_byte_switch = 0x0;
	start_param.algo_cfg.pka.pka_hi_addr = get_paddr_hi(data->pka_data);
	sprd_ce_write_cmd_start_pka(&start_param, get_paddr_lo(data->pka_data));
#else
	sprd_ce_write_cmd_start(&start_param);
#endif
}

void
sprd_ce_write_cmd(sprd_crypto_context_t* context) {
	SPRD_CRYPTO_LOG_TRACE("context->algo = 0x%x, cmd_status = %d\n", context->algo, REG_GET_VAL(s_ce_vaddr, CE_CMD_FIFO_STATUS));
	switch (context->algo & SPRD_CRYPTO_MAIN_MODE_MASK) {
	case SPRD_CRYPTO_HASH:
		sprd_ce_write_cmd_hash(context);
		break;

	case SPRD_CRYPTO_RSA:
		sprd_ce_write_cmd_rsa(context);
		break;

	case SPRD_CRYPTO_AES:
		sprd_ce_write_cmd_aes(context);
		break;

	case SPRD_CRYPTO_RNG:
		sprd_ce_write_cmd_rng(context);
		break;

	case SPRD_CRYPTO_ECC:
		sprd_ce_write_cmd_ecc(context);
	break;

	default:
		break;
	}
}

uint32_t sprd_ce_get_finish_count(void) {
	return REG_GET_VAL(s_ce_vaddr, CE_FINISH_CMD_CNT);
}

uint32_t sprd_ce_polling(void) {
	while (1) {
		if (REG_GET_VAL(s_ce_vaddr, CE_INT_STATUS) & 0x01) {
			REG_SET_VAL(s_ce_vaddr, CE_INT_CLEAR, REG_GET_VAL(s_ce_vaddr, CE_INT_STATUS));
			break;
		}
	}
	return SPRD_CRYPTO_SUCCESS;
}

#ifdef R5P0LITE
uint32_t sprd_ce_pka_polling(void) {
	while (1) {
		if (REG_GET_VAL(s_ce_vaddr, CE_INT_STATUS) & 0x2000) {
			REG_SET_VAL(s_ce_vaddr, CE_INT_CLEAR, REG_GET_VAL(s_ce_vaddr, CE_INT_STATUS));
			break;
		}
	}
	return SPRD_CRYPTO_SUCCESS;
}
#endif


static inline void sprd_ce_all_int_enable(void) {
	sprd_ce_int_t int_en;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
	*(uint32_t*)(&int_en) = 0;
	int_en.cmd_done = 1;
	int_en.len_err = 1;
#ifndef R5P0LITE
	int_en.tdes_key_err = 1;
#endif
	int_en.rng = 0;
	int_en.pka_store_done = 0;
	int_en.pka_one_cmd_done = 0;
	int_en.use_efuse_err = 1;
	int_en.pka_div_zero_err = 1;
	int_en.pka_find_prime_err = 1;
#ifdef R5P0LITE
	int_en.pka_cmd_done = 1;
	int_en.pka_len_err = 1;
#endif
	REG_SET_VAL(s_ce_vaddr, CE_INT_EN, *(uint32_t*)(&int_en));
#pragma GCC diagnostic pop
}

static inline void sprd_ce_all_int_disable(void) {
	REG_SET_VAL(s_ce_vaddr, CE_INT_EN, 0x00);
}

static inline void sprd_ce_all_int_clear(void) {
	sprd_ce_int_t int_en;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
	*(uint32_t*)(&int_en) = 0;
	int_en.cmd_done = 1;
	int_en.len_err = 1;
#ifndef R5P0LITE
	int_en.tdes_key_err = 1;
#endif
	int_en.rng = 1;
	int_en.pka_store_done = 1;
	int_en.pka_one_cmd_done = 1;
	int_en.use_efuse_err = 1;
	int_en.pka_div_zero_err = 1;
	int_en.pka_find_prime_err = 1;
#ifdef R5P0LITE
	int_en.pka_cmd_done = 1;
	int_en.pka_len_err = 1;
#endif
	REG_SET_VAL(s_ce_vaddr, CE_INT_CLEAR, *(uint32_t*)(&int_en));
#pragma GCC diagnostic pop
}

#define SET_OFFSET  0x1000
#define CLR_OFFSET  0x2000
#define SPRD_REG_SET_BIT(__base, __offset, __v)   ((*(volatile u32 *)((__base) + __offset + SET_OFFSET)) = (uint32_t)(__v))
#define SPRD_REG_CLR_BIT(__base, __offset, __v)   ((*(volatile u32 *)((__base) + __offset + CLR_OFFSET)) = (uint32_t)(__v))

static inline void sprd_ce_enable(void) {
	//set ce freq : 256M
	unsigned int cgm_ce0_val = REG_GET_VAL(REG_AP_CLK_CORE_CGM_CE_CFG, 0);
	if ((cgm_ce0_val & BIT_CGM_CE0_SEL) != CGM_CE0_SEL_256M) {
		REG_SET_VAL(REG_AP_CLK_CORE_CGM_CE_CFG, 0, (cgm_ce0_val | CGM_CE0_SEL_256M));
	}

	SPRD_REG_SET_BIT(s_ahb_vaddr, REG_AP_AHB_CE_SEC_EB_OFFSET, BIT_AP_AHB_CE_SEC_EB);
}

static inline void sprd_ce_disable(void) {
	SPRD_REG_CLR_BIT(s_ahb_vaddr, REG_AP_AHB_CE_SEC_EB_OFFSET, BIT_AP_AHB_CE_SEC_EB);
}

void sprd_ce_open(void) {
	uint32_t count;
	(void)count;

	sprd_ce_enable();
	sprd_ce_reset();
	count = sprd_ce_get_finish_count();
	SPRD_CRYPTO_LOG_DEBUG("sprd_ce_open finish_count = %d\n", count);
	sprd_ce_all_int_clear();
	//sprd_ce_all_int_enable();
}

void sprd_ce_close(void){
	//sprd_ce_all_int_disable();
	sprd_ce_disable();
	SPRD_CRYPTO_LOG_TRACE("sprd_ce_close\n");
}

void sprd_ce_reset(void) {
	SPRD_REG_SET_BIT(s_ahb_vaddr, REG_AP_AHB_CE_SEC_SOFT_RST_OFFSET, BIT_AP_AHB_CE_SEC_SOFT_RST);
	SPRD_REG_CLR_BIT(s_ahb_vaddr, REG_AP_AHB_CE_SEC_SOFT_RST_OFFSET, BIT_AP_AHB_CE_SEC_SOFT_RST);
	REG_SET_VAL(s_ce_vaddr, CE_CLEAR, CE_CLEAR_EN);
}

void sprd_ce_init(void) {
#if defined(CONFIG_SOC_SHARKL5) || defined(CONFIG_SOC_ROC1) || defined(CONFIG_SOC_SHARKL5PRO) \
    || defined(CONFIG_SOC_QOGIRL6) || defined(CONFIG_SOC_QOGIRN6PRO)
	s_ahb_vaddr = sprd_pal_paddr_to_vaddr(CTL_BASE_AP_APB);
#else
	s_ahb_vaddr = sprd_pal_paddr_to_vaddr(SPRD_AHB_PHYS);
#endif
	s_ce_vaddr = sprd_pal_paddr_to_vaddr(SPRD_SECURE_CE_PHYS);
	SPRD_CRYPTO_LOG_DEBUG("success!  ahb = %p, ce = %p\n", s_ahb_vaddr, s_ce_vaddr);
}

void sprd_ce_terminal(void) {
}
