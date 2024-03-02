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

#include "sprd_ecc_pka.h"
#include <sprd_ecc.h>

#define PKA_DEBUG

#define MASK(__n,__w)  					(((1 << (__w)) - 1) << (__n))
#define VALUE(__n,__v) 					((__v) << (__n))

uint32_t *g_pka_inst_buf = 0x00;

uint32_t drv_pka_set_operation(
		uint8_t op_code,
		uint8_t len_id,
		uint8_t op_r,
		uint8_t is_a_const,
		uint8_t op_a,
		uint8_t is_b_const,
		uint8_t op_b,
		uint8_t tag)
{
	uint32_t command;

#ifdef PKA_DEBUG
	if ((op_code    & ~MASK(0,DRV_PKA_CMD_OPCODE_BIT_SIZE))     ||
		(len_id     & ~MASK(0,DRV_PKA_CMD_LENID_BIT_SIZE))      ||
		(op_r       & ~MASK(0,DRV_PKA_CMD_DST_BIT_SIZE))        ||
		(is_a_const & ~MASK(0,DRV_PKA_CMD_OP_A_CONST_BIT_SIZE)) ||
		(op_a       & ~MASK(0,DRV_PKA_CMD_OP_A_BIT_SIZE))       ||
		(is_b_const & ~MASK(0,DRV_PKA_CMD_OP_B_CONST_BIT_SIZE)) ||
		(op_b       & ~MASK(0,DRV_PKA_CMD_OP_B_BIT_SIZE))       ||
		(tag        & ~MASK(0,DRV_PKA_CMD_TAG_BIT_SIZE))) {

		return -1;
	}
#endif

	command = DRV_PKA_COMMAND(op_code,len_id,op_r,is_a_const,op_a,is_b_const,op_b,tag);

	return command;
}

sprd_crypto_err_t drv_pka_set_high_addr(void* load, void* store) {
	uint32_t load_high = (uint32_t)((((uintptr_t)sprd_pal_vaddr_to_paddr(load))>>17) & MASK(0,19));
	uint32_t store_high = (uint32_t)((((uintptr_t)sprd_pal_vaddr_to_paddr(store))>>17) & MASK(0,19));
	SPRD_WRITEREG(SPRD_CE_PKA_LOAD_H_ADDR_OFFSET, load_high);
	SPRD_WRITEREG(SPRD_CE_PKA_STORE_H_ADDR_OFFSET, store_high);

	return SPRD_ECC_OK;
}

uint32_t drv_pka_set_operation2(
		uint8_t op_code,
		uint8_t len_id,
		uint8_t reg_id,
		uintptr_t addr)
{
	uint32_t command;
	uint32_t low_addr;

#ifdef PKA_DEBUG
	if ((op_code   &   ~MASK(0,DRV_PKA_CMD_OPCODE_BIT_SIZE))     ||
		(len_id    &   ~MASK(0,DRV_PKA_CMD_LENID_BIT_SIZE))      ||
		(reg_id    &   ~MASK(0,DRV_PKA_CMD_DST_BIT_SIZE))) {

		return -1;
	}
#endif

	low_addr  = (uint32_t)(addr & MASK(0,17));

	command = DRV_PKA_COMMAND2(op_code, len_id, reg_id, low_addr);

	return command;
}

uint32_t drv_pka_set_operation_be(
        uint8_t op_code,
        uint8_t len_id,
        uint8_t reg_id,
        uintptr_t addr)
{
	uint32_t command;
	uint32_t low_addr;

#ifdef PKA_DEBUG
	if ((op_code   &   ~MASK(0,DRV_PKA_CMD_OPCODE_BIT_SIZE))     ||
		(len_id    &   ~MASK(0,DRV_PKA_CMD_LENID_BIT_SIZE))	||
		(reg_id    &   ~MASK(0,DRV_PKA_CMD_DST_BIT_SIZE))) {

		return -1;
	}
#endif

	low_addr  = (uint32_t)(addr & MASK(0,17));
	command = DRV_PKA_COMMAND_BE(op_code, len_id, reg_id, low_addr);

	return command;
}


sprd_crypto_err_t  drv_pka_set_len(uint32_t len, uint32_t len_id)
{
	uint32_t offset = len_id/2;
	uint32_t shift  = len_id%2;
	uint32_t value = 0;

	if (len_id > 3) {
		return SPRD_ECC_LEN_ID_ERROR;
	}

	if (len & ~MASK(0,10)) {
		return SPRD_ECC_LEN_ID_ERROR;
	}

	value = VALUE(16*shift, len);
	SPRD_WRITEREG(SPRD_CE_PKA_REG_LENGTH01_OFFSET+offset*4, value);

	return SPRD_ECC_OK;
}

uint32_t drv_pka_set(uint8_t value, uint8_t reg_id, uint32_t len, uint8_t len_id)
{
	return DRV_PKA_MOV_ins(value, reg_id, len_id, PKA_MOV_SRC_TYPE_VAL);
}

uint32_t drv_pka_load(uint32_t *src_addr, uint8_t reg_id, uint32_t len, uint8_t len_id)
{
	return DRV_PKA_LD_ins((uintptr_t)src_addr, reg_id, len_id);
}

uint32_t drv_pka_store(uint8_t reg_id, uint32_t *dst_addr, uint32_t len, uint8_t len_id)
{
	return DRV_PKA_ST_ins(reg_id, (uintptr_t)dst_addr, len_id);
}

uint32_t drv_pka_load_be(uint32_t *src_addr, uint8_t reg_id, uint32_t len, uint8_t len_id)
{
	return DRV_PKA_LD_BE_ins((uintptr_t)src_addr, reg_id, len_id);
}

uint32_t drv_pka_store_be(uint8_t reg_id, uint32_t *dst_addr, uint32_t len, uint8_t len_id)
{
	return DRV_PKA_ST_BE_ins(reg_id, (uintptr_t)dst_addr, len_id);
}

sprd_crypto_err_t drv_pka_set_instruction(void* command_base, uint32_t num)
{
#ifdef R3P0
	uintptr_t command_vaddr = (uintptr_t)sprd_pal_vaddr_to_paddr(command_base);
	SPRD_WRITEREG(SPRD_CE_PKA_INST_ADDR_OFFSET, (uint32_t)(command_vaddr & 0xffffffffULL));
	SPRD_WRITEREG(SPRD_CE_PKA_INST_LEN, (uint32_t)((command_vaddr & 0xf00000000ULL) >> 8) | num);
#endif

	return SPRD_ECC_OK;
}
