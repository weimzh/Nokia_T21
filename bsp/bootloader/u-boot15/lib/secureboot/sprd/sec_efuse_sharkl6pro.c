#include <secureboot/sec_efuse_sharkl6pro.h>

const int map0_block_index[47] = {
	 4,5,6,				//RESERVED_BLOCK
	 7,				//LCS
	 8,				//RESERVED_BLOCK4
	16,15,14,13,12,11,10,9,		//ROTPK0
	24,23,22,21,20,19,18,17,	//KCE
	32,31,30,29,28,27,26,25,	//HUK
	36,35,34,33,			//HDCP KPF
	40,39,38,37,			//HDCP DUK
	41,				//SEC_VERSION1
	42,				//SEC_VERSION0
	43,44,45,46,47,48,49,50		//ROTPK1
};

const int *pmap = map0_block_index;

static Efuse_Result_Ret efuse_read_lock_bits_map(uint32 *pReadData)
{
    Efuse_Result_Ret ret = EFUSE_RESULT_SUCCESS;

    ret = efuse_read_drv(0, 7, pReadData, 0);

    return ret;
}

static inline uint32 is_bit_set(uint32 * pdata, uint32 bit_pos)
{
    uint32 ret;
    ret = pdata[bit_pos / 32] & (1 << (bit_pos % 32));
    if (ret == 0)
        return 0;
    else
        return 1;
}

/*
 * bit_pos is a multiple of 2, shadow bit is 1 more than bit_pos. 
 */
static inline uint32 is_shadow_bit_set(uint32 * pdata, uint32 bit_pos)
{
    uint32 ret;
    ret = pdata[bit_pos / 32] & (1 << ((bit_pos + 1) % 32));
    if (ret == 0)
        return 0;
    else
        return 1;
}

static int is_huk_write(void)
{
	uint32 bitmap[8] = {0};
	int ret = 1;
	int i, block_id;

	efuse_read_lock_bits_map(bitmap);

	for (i = HUK_BLOCK_START; i <= HUK_BLOCK_END; i++)
	{
		block_id = pmap[i];
		ret = ret & (is_bit_set(bitmap, (block_id << 1)));
		ret = ret & (is_shadow_bit_set(bitmap, (block_id << 1)));
	}

	return ret;
}

static int is_rotpk_write(void)
{
	uint32 bitmap[8] = {0};
	int ret = 1;
	int i, block_id;

	efuse_read_lock_bits_map(bitmap);

	for (i = ROTPK0_BLOCK_START; i <= ROTPK0_BLOCK_END; i++)
	{
		block_id = pmap[i];
		ret = ret & (is_bit_set(bitmap, (block_id << 1)));
	}

	return ret;
}

static int is_backup_rotpk_write(void)
{
	uint32 bitmap[8] = {0};
	int ret = 1;
	int i, block_id;

	efuse_read_lock_bits_map(bitmap);

	for (i = ROTPK1_BLOCK_START; i <= ROTPK1_BLOCK_END; i++)
	{
		block_id = pmap[i];
		ret = ret & (is_bit_set(bitmap, (block_id << 1)));
	}

	return ret;
}

static int is_zero_bitmap(void)
{
	uint32 bitmap[8] = {0};
	int ret = 0;

	efuse_read_lock_bits_map(bitmap);
	ret = !(bitmap[0] | bitmap[1] | bitmap[2] | bitmap[3] | bitmap[4] | bitmap[5] | bitmap[6] | bitmap[7]);

	return ret;
}

Efuse_Result_Ret sprd_ce_efuse_huk_program(void)
{
	return 	efuse_huk_program();
}

Efuse_Result_Ret sprd_get_lock_bits(unsigned int start_id, unsigned int end_id, unsigned int *bits_data, unsigned int *bits_data1)
{
	Efuse_Result_Ret ret = EFUSE_RESULT_SUCCESS;

	if (HUK_BLOCK_START == start_id)
		*bits_data = *bits_data1 = 0XF;
	else if (ROTPK0_BLOCK_START == start_id)
		*bits_data = *bits_data1 = 0XF00;
	else if (ROTPK1_BLOCK_START == start_id)
		*bits_data = *bits_data1 = 0XF0000;

	return ret;
}

Efuse_Result_Ret sprd_ce_efuse_read(unsigned int block_id, unsigned int *read_ptr)
{
	Efuse_Result_Ret ret = EFUSE_RESULT_SUCCESS;
	uint32 real_block;

	if (KCE_BLOCK_START <= block_id && KCE_BLOCK_END >= block_id )
	{
		return ret;
	}

	if (block_id >= NONE)
	{
		return EFUSE_PARAM_ERROR;
	}

	if (block_id == LOCK_BIT_BLOCK || block_id == (LOCK_BIT_BLOCK + 1))
	{
		if (is_zero_bitmap())
			*read_ptr = 0;
		if (is_huk_write())
			*read_ptr = 0XF;
		if (is_rotpk_write())
			*read_ptr |= (0XF << 8);
		if (is_backup_rotpk_write())
			*read_ptr |= (0XF << 16);
		return ret;
	}

	if (block_id >= NSEC_VER_BLOCK_START && block_id <= NSEC_VER_BLOCK_END)
	{
		return ret;
	}

	real_block = pmap[block_id];
	ret = efuse_read_drv(real_block, real_block, read_ptr, 1);

	return ret;
}

Efuse_Result_Ret sprd_ce_efuse_program(unsigned int block_id, unsigned int WriteData)
{
	Efuse_Result_Ret ret = EFUSE_RESULT_SUCCESS;
	uint32 real_block;
	if (block_id == LOCK_BIT_BLOCK || block_id == (LOCK_BIT_BLOCK + 1))
	{
		return ret;
	}

	if (block_id >= NONE)
	{
		return EFUSE_PARAM_ERROR;
	}

	if (block_id >= NSEC_VER_BLOCK_END)
	{
		return ret;
	}

	if (block_id == CYCLE_STATE_BLOCK || block_id == SEC_VERSION_BLOCK || block_id == SEC_VERSION1_BLOCK)
	{
		real_block = pmap[block_id];
		ret = efuse_rewrite_double_bit(real_block, WriteData);
		return ret;
	}

	real_block = pmap[block_id];
	ret = efuse_write_drv(real_block, real_block, &WriteData,1);

	return ret;
}

unsigned int sprd_get_secure_boot_enable(void)
{
	uint32 read_bit;
	read_bit = sprd_ap_efuse_read(PUBLIC_EFUSE_BLOCK2);
	read_bit &= 1;

	return read_bit;
}

Efuse_Result_Ret sec_efuse_read_lock_bits_map(uint32 *pReadData)
{
	return efuse_read_lock_bits_map(pReadData);
}

int sec_huk_is_locked(void)
{
	return is_huk_write();
}
