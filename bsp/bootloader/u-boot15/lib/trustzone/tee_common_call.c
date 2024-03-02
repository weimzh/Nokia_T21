#include "uboot_sec_drv.h"

static smc_param param;


/**
start_addr must be 32 bits addr
there are two ways if you want to use 64 bits addr:
1. put 64 bits addr to your own structure, then pass structure's addr here
2. seperate 64 bits addr to two 4 bytes and then put them into param, then call tee_smc_call
*/
smc_param *tee_common_call(uint32_t funcid, uint32_t start_addr, uint32_t lenth)
{
	memset(&param, 0x00, sizeof(smc_param));
	param.a0 = TEESMC_SIPCALL_WITH_ARG;
	param.a1 = funcid;
	param.a2 = start_addr;
	param.a3 = lenth;
	tee_smc_call(&param);
	return &param;
}


int tee_smc_sip_call(uint32_t sip_call_id, uint32_t *a1, uint32_t *a2, uint32_t *a3)
{
	smc_param params;

	memset(&params, 0x00, sizeof(smc_param));
	params.a0 = TEESMC_SIP_CALL_ID(sip_call_id);
	params.a1 = *a1;
	params.a2 = *a2;
	params.a3 = *a3;
	tee_smc_call(&params);

	if(0 == params.a0) {
		*a1 = params.a1;
		*a2 = params.a2;
		*a3 = params.a3;
	} else {
		*a1 = 0;
		*a2 = 0;
		*a3 = 0;
	}

	return params.a0;
}

int tee_smc_fast_call(uint32_t fast_call_id, uint32_t paddr_l, uint32_t paddr_h, uint32_t size)
{
	smc_param params;

	memset(&param, 0x00, sizeof(smc_param));
	params.a0 = TEESMC_FAST_CALL_ID(fast_call_id);
	params.a1 = paddr_l;
	params.a2 = paddr_h;
	params.a3 = size;
	tee_smc_call(&params);

	return params.a0;
}
