#include <secureboot/sec_efuse_test.h>
#include <secureboot/sec_efuse_api.h>
#include <secureboot/sec_efuse.h>
#include <sprd_crypto.h>
#include <secureboot/sec_efuse_sharkl6pro.h>

#if defined(CONFIG_SOC_QOGIRN6PRO)
#define SIZE_LOCK_BIT_BLOCK 8
#elif defined(CONFIG_SOC_ROC1)
#define SIZE_LOCK_BIT_BLOCK 6
#else
#define SIZE_LOCK_BIT_BLOCK 4
#endif

#define EFUSE_HUK_SECCUSS               (0x0)
#define EFUSE_HUK_ERR_BASE              (0x100)
#define EFUSE_HUK_ERR_BLOCK             (EFUSE_HUK_ERR_BASE + 0x01)
#define EFUSE_HUK_ERR_LOCK_BIT          (EFUSE_HUK_ERR_BASE + 0x02)
#define EFUSE_HUK_ERR_WRITE_BLOCK       (EFUSE_HUK_ERR_BASE + 0x03)
#define EFUSE_HUK_ERR_WRITE_LOCK_BIT    (EFUSE_HUK_ERR_BASE + 0x04)
#define EFUSE_HUK_ERR_NOT_WRITE         (EFUSE_HUK_ERR_BASE + 0x05)

uint8_t key[32] = {0};
uint8_t iv[64] __attribute((aligned(64))) = {0};

uint8_t in[16] = {0x00,0x11,0x22,0x33,0x44,0x55, \
	0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
uint8_t out0[16] = {0};
uint8_t out[16] = {0};
uint8_t out_tmp[16] = {0};

//key256=00000...,AES_CBC
uint8_t out0_right[16] = {0x1c,0x06,0x0f,0x4c,0x9e,0x7e,0xa8,0xd6, \
	0xca,0x96,0x1a,0x2d,0x64,0xc0,0x5c,0x18};
//key256=FFFFF...,AES_CBC
uint8_t outf_right[16] = {0xd9,0xb8,0x84,0x17,0x02,0xb5,0x0e,0x9b, \
	0x5e,0xd5,0x0a,0x14,0x94,0xdf,0xf0,0xe2};

static uint8_t huk_context[4096] __attribute((aligned(4))) = {0};
static bool is_huk_need_write = false;

sprd_crypto_context_t *context = NULL;



//0 : is lock, -1 : not lock
int sprd_huk_is_locked(void)
{
#if defined(CONFIG_SOC_QOGIRN6PRO)
	if (sec_huk_is_locked())
	{
		return 0;
	} else {
		return -1;
	}
#else
	return -1;
#endif
}

static void sec_ce_aes_huk(sprd_crypto_context_t *context)
{
	int i = 0;

	efuse_enable();
	sprd_ce_init();
	sprd_ce_open();

	sprd_ce_write_cmd(context);
	sprd_ce_polling();

	printf("aes test out data : \n");
	for (i = 0; i < 16; i++)
	{
		printf("0x%x ", context->out[i]);
	}
	printf("\n");
	efuse_disable();
}

void sec_efuse_check(void)
{
	unsigned int i = 0;
	unsigned int pLcs = 0;
	unsigned int rebuf1[ROTPK0_BLOCK_END - ROTPK0_BLOCK_START + 1] = {0};
	unsigned int rebuf2[ROTPK1_BLOCK_END - ROTPK1_BLOCK_START + 1] = {0};
	unsigned int rebuf3[8] = {0};
	unsigned int rebuf4[8] = {0};
	unsigned int r_data = 0;
	unsigned int lock_buf[SIZE_LOCK_BIT_BLOCK] = {0};

	printf("[sec_efuse_check]sec efuse check start!\n");
	sprd_get_lcs(&pLcs);
	printf("pLcs is %x\n", pLcs);

	sec_efuse_read_lock_bits_map(lock_buf);
	printf("LOCK_BIT_BLOCK.................\n");
	for(i = 0; i < SIZE_LOCK_BIT_BLOCK; i++)
	{
		printf("0x%X ",lock_buf[i]);
	}
	printf("\n");

	sprd_sec_efuse_rotpk0_read(rebuf1);
	printf("ROTPK0_BLOCK.........\n");
	for(i = 0; i < ROTPK0_BLOCK_END - ROTPK0_BLOCK_START + 1; i++)
	{
		printf("0x%X ",rebuf1[i]);
	}
	printf("\n");

	sprd_sec_efuse_rotpk1_read(rebuf2);
	printf("ROTPK1_BLOCK.........\n");
	for(i = 0; i < ROTPK1_BLOCK_END - ROTPK1_BLOCK_START + 1; i++)
	{
		printf("0x%X ",rebuf2[i]);
	}
	printf("\n");

#if defined(CONFIG_SOC_QOGIRN6PRO)
	sprd_sec_efuse_blocks_read(SEC_VERSION1_BLOCK, SEC_VERSION_BLOCK, rebuf3);
	printf("SEC_VERSION_BLOCK.........\n");
	for(i = 0; i < SEC_VERSION_BLOCK - SEC_VERSION1_BLOCK +1; i++)
	{
		printf("0x%X ",rebuf3[i]);
	}
	printf("\n");
#else
	sprd_sec_efuse_blocks_read(SEC_VERSION_BLOCK, SEC_VERSION_BLOCK, rebuf3);
	printf("SEC_VERSION_BLOCK.........\n");
	printf("0x%X\n ",rebuf3[0]);
#endif

	sprd_sec_efuse_blocks_read(CYCLE_STATE_BLOCK, CYCLE_STATE_BLOCK, rebuf4);
	printf("CYCLE_STATE_BLOCK.........\n");
	printf("0x%X\n",rebuf4[0]);

	efuse_read_drv(PUBLIC_EFUSE_BLOCK2, PUBLIC_EFUSE_BLOCK2, &r_data, 1);//sharkl3/sharkl6 public efuse block 92/93 bit0
	printf("public efuse secboot bit block is %x\n", r_data);

	printf("[sec_efuse_check]sec efuse check end!\n");
}

int sec_efuse_huk_test(void)
{
	int i = 0;
	int lock = 0;
	int ret = 0;
	int tret0 = 0;
	int tretf = 0;
	int tret = 0;
	int32_t in_len = 16;
	int32_t out_len = 16;

	printf("[sec_efuse_huk_test]sec efuse huk test start!\n");
	context = (sprd_crypto_context_t *)huk_context;
	memset(context, 0, sizeof(sprd_crypto_context_t));
	context->algo = SPRD_CRYPTO_AES_CBC_HUK; //SPRD_CRYPTO_AES_ECB,SPRD_CRYPTO_AES_CBC
	context->in = in;
	context->in_len = in_len;
	context->out = out;
	context->out_len = out_len;
	context->continued = 0;
	context->end = 1;
	context->info.aes.decrypt = 0;
	memcpy(context->info.aes.key1, key, 32);
	context->info.aes.key1_len = 32;
	//context->info.aes.key2 = (void *)NULL;
	context->info.aes.key2_len = 0;
	memcpy(context->info.aes.iv, iv, 16);
	context->info.aes.iv_len = 16;

	for (i = 0; i < 32; i++)
	{
		context->info.aes.key1[i] = 0;
	}

	//1. check huk lock
	printf("get huk lock bit...\n");
	lock = sprd_huk_is_locked();

	//1. calculate CT value and compare with all 1/0
	printf("call sec_ce_aes_huk to compare\n");
	sec_ce_aes_huk(context);
	sec_memcpy(out_tmp, out, out_len);
	tret0 = sec_memcmp(out, out0_right, out_len);
	tretf = sec_memcmp(out, outf_right, out_len);
	tret  = sec_memcmp(out, out0, out_len);
	printf("tret0 is %d, tretf is %d, tret is %d\n", tret0, tretf, tret);

	if (lock == 0) {
		printf("huk is locked !\n");
		if (tretf == 0 || tret0 == 0 || tret == 0)//huk is all 1/0/error
		{
			printf("huk block error: block=0/F, but lockbit=F!\n");
			ret = EFUSE_HUK_ERR_BLOCK;
			goto failed;
		} else {
			printf("huk has been written seccuss !\n");
			ret = EFUSE_HUK_SECCUSS;
		}
	} else {
		printf("huk is not locked !\n");
		if (tretf == 0)
		{
			printf("huk block error: block=F, but lockbit=0!\n");
			ret = EFUSE_HUK_ERR_BLOCK;
			goto failed;
		} else {
			printf("huk block not write\n");
			if (tret0 != 0)
			{
				printf("huk block error: block!=0, but lockbit=0!\n");
			}
			ret = EFUSE_HUK_ERR_NOT_WRITE;
			//. huk write
			if (is_huk_need_write) //need to write huk
			{
				printf("need to write huk\n");
				sprd_huk_program();
				printf("call sec_ce_aes_huk to compare after write\n");
				sec_ce_aes_huk(context);
				sec_memcpy(out_tmp, out, out_len);
				tret0 = sec_memcmp(out,out0_right,out_len);
				tretf = sec_memcmp(out,outf_right,out_len);
				tret  = sec_memcmp(out, out0, out_len);
				printf("tret0 is %d, tretf is %d, tret is %d\n", tret0, tretf, tret);

				if (tretf == 0 || tret0 == 0 || tret == 0 ) {//huk is all 1/0/error
					printf("write huk error: block=0/F !\n");
					ret = EFUSE_HUK_ERR_WRITE_BLOCK;
					goto failed;
				} else {
					printf("write huk sucessfull !\n");
					ret = EFUSE_HUK_SECCUSS;
					printf("get huk lock bit...\n");
					lock = sprd_huk_is_locked();
				}
			}
			else
			{
				printf("no need to write huk\n");
				goto failed;
			}
		}
	}

	//3. if huk success, rewrite huk and check whether rewrite success
	if(lock == 0) //only for EFUSE_HUK_SECCUSS
	{
		printf("huk is locked !\n");
		sprd_huk_program();
		printf("call sec_ce_aes_huk to check value whether same as last !\n");
		sec_ce_aes_huk(context);
		tret0 = sec_memcmp(out, out_tmp, out_len);
		if (tret0 == 0)	{
			printf("cannot rewrite huk, lock bit valid !\n");
			ret = EFUSE_HUK_SECCUSS;
		} else {
			printf("can rewrite huk, lock bit not valid !\n");
			ret = EFUSE_HUK_ERR_WRITE_LOCK_BIT;
		}
	}
	else
	{
		printf("huk is not locked, return error !\n");
		ret = EFUSE_HUK_ERR_WRITE_LOCK_BIT;
	}

	//4. finally test
failed:
	printf("[sec_efuse_huk_test]sec efuse huk test end!\n");
	return ret;
}


int sprd_sec_efuse_test(void)
{
	int ret = 0;

	printf("[sprd_sec_efuse_test]sprd_sec_efuse_test start, will call sec_efuse_check\n");
	sec_efuse_check();

	printf("[sprd_sec_efuse_test]will sec_efuse_huk_test\n");
	ret = sec_efuse_huk_test();
	printf("[sprd_sec_efuse_test]sprd_sec_efuse_test end, ret %d\n",ret);

	return ret;
}

