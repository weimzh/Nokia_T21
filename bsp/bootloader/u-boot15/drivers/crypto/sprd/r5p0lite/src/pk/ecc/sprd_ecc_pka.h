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
* created by : vee.zhang xinle.yang
*
*/


#ifndef DRV_PKA_H_
#define DRV_PKA_H_

#include <sprd_ce.h>

/* PKA Opration Code*/
#define    CE_PKA_OPCODE_RAN              0x01
#define    CE_PKA_OPCODE_SMULF            0x02
#define    CE_PKA_OPCODE_PADD             0x03
#define    CE_PKA_OPCODE_PDBL             0x04
#define    CE_PKA_OPCODE_JMP              0x05
#define    CE_PKA_OPCODE_MMUL             0x06
#define    CE_PKA_OPCODE_MTMUL            0x07
#define    CE_PKA_OPCODE_MADD             0x08
#define    CE_PKA_OPCODE_MSUB             0x09
#define    CE_PKA_OPCODE_MINV             0x0A
#define    CE_PKA_OPCODE_MEXP             0x0B
#define    CE_PKA_OPCODE_ADD              0x0C
#define    CE_PKA_OPCODE_SUB              0x0D
#define    CE_PKA_OPCODE_MUL              0x0E
#define    CE_PKA_OPCODE_DIV              0x0F
#define    CE_PKA_OPCODE_SHL              0x10
#define    CE_PKA_OPCODE_SHR              0x11
#define    CE_PKA_OPCODE_AND              0x12
#define    CE_PKA_OPCODE_OR               0x13
#define    CE_PKA_OPCODE_INV              0x14
#define    CE_PKA_OPCODE_XOR              0x15
#define    CE_PKA_OPCODE_LD               0x16
#define    CE_PKA_OPCODE_ST               0x17
#define    CE_PKA_OPCODE_GTM              0x18
#define    CE_PKA_OPCODE_MTG              0x19
#define    CE_PKA_OPCODE_PADDP            0x1A
#define    CE_PKA_OPCODE_PDBLP            0x1B
#define    CE_PKA_OPCODE_MOV              0x1C
#define    CE_PKA_OPCODE_KPP              0x1D
#define    CE_PKA_OPCODE_PRIME_GEN        0x1E
#define    CE_PKA_OPCODE_RSAKEY_GEN       0x1F

/* PKA bit shift of command*/
#define DRV_PKA_CMD_OPCODE_BIT_SHIFT		27
#define DRV_PKA_CMD_LENID_BIT_SHIFT			23
#define DRV_PKA_CMD_DST_BIT_SHIFT			18
#define DRV_PKA_CMD_OP_A_CONST_BIT_SHIFT	17
#define DRV_PKA_CMD_OP_A_BIT_SHIFT			12
#define DRV_PKA_CMD_OP_B_CONST_BIT_SHIFT	11
#define DRV_PKA_CMD_OP_B_BIT_SHIFT			6
#define DRV_PKA_CMD_TAG_BIT_SHIFT			0
#define DRV_PKA_CMD_ENDIAN_BIT_SHIFT		17
#define DRV_PKA_CMD_LOAD_STORE_BIT_SHIFT	0

#define DRV_PKA_CMD_OPCODE_BIT_SIZE			5
#define DRV_PKA_CMD_LENID_BIT_SIZE			4
#define DRV_PKA_CMD_DST_BIT_SIZE			5
#define DRV_PKA_CMD_OP_A_CONST_BIT_SIZE		1
#define DRV_PKA_CMD_OP_A_BIT_SIZE			5
#define DRV_PKA_CMD_OP_B_CONST_BIT_SIZE		1
#define DRV_PKA_CMD_OP_B_BIT_SIZE			5
#define DRV_PKA_CMD_TAG_BIT_SIZE			6
#define DRV_PKA_CMD_ENDIAN_BIT_SIZE			1
#define DRV_PKA_CMD_LOAD_STORE_BIT_SIZE		17


/* defination of PKA regitster*/
#define REG_NULL       0x00
#define REG_IN_RAM0_00 0x00
#define REG_IN_RAM1_01 0x01
#define REG_IN_RAM2_02 0x02
#define REG_IN_RAM3_03 0x03
#define REG_IN_RAM4_04 0x04
#define REG_IN_RAM5_05 0x05
#define REG_IN_RAM6_06 0x06
#define REG_IN_RAM7_07 0x07
#define REG_IN_RAM0_08 0x08
#define REG_IN_RAM1_09 0x09
#define REG_IN_RAM2_0a 0x0a
#define REG_IN_RAM3_0b 0x0b
#define REG_IN_RAM4_0c 0x0c
#define REG_IN_RAM5_0d 0x0d
#define REG_IN_RAM6_0e 0x0e
#define REG_IN_RAM7_0f 0x0f
#define REG_IN_RAM0_10 0x10
#define REG_IN_RAM1_11 0x11
#define REG_IN_RAM2_12 0x12
#define REG_IN_RAM3_13 0x13
#define REG_IN_RAM4_14 0x14
#define REG_IN_RAM5_15 0x15
#define REG_IN_RAM6_16 0x16
#define REG_IN_RAM7_17 0x17
#define REG_IN_RAM0_18 0x18
#define REG_IN_RAM1_19 0x19
#define REG_IN_RAM2_1a 0x1a
#define REG_IN_RAM3_1b 0x1b
#define REG_IN_RAM4_1c 0x1c
#define REG_IN_RAM5_1d 0x1d
#define REG_IN_RAM6_1e 0x1e
#define REG_IN_RAM7_1f 0x1f

/*definations of length ID*/
#define LEN_ID_00     0x00
#define LEN_ID_01     0x01
#define LEN_ID_02     0x02
#define LEN_ID_03     0x03


/* commands of PKA*/
#define DRV_PKA_COMMAND(op_code,len_id,op_r,is_a_const,op_a,is_b_const,op_b,tag) \
   ( (uint32_t)(op_code)      << DRV_PKA_CMD_OPCODE_BIT_SHIFT            | \
     (uint32_t)(len_id)       << DRV_PKA_CMD_LENID_BIT_SHIFT             | \
     (uint32_t)(op_r)         << DRV_PKA_CMD_DST_BIT_SHIFT               | \
     (uint32_t)(is_a_const)   << DRV_PKA_CMD_OP_A_CONST_BIT_SHIFT        | \
     (uint32_t)(op_a)         << DRV_PKA_CMD_OP_A_BIT_SHIFT              | \
     (uint32_t)(is_b_const)   << DRV_PKA_CMD_OP_B_CONST_BIT_SHIFT        | \
     (uint32_t)(op_b)         << DRV_PKA_CMD_OP_B_BIT_SHIFT              | \
     (uint32_t)(tag)          << DRV_PKA_CMD_TAG_BIT_SHIFT )


#define DRV_PKA_COMMAND2(op_code,len_id,reg_id,addr) \
   ( (uint32_t)(op_code)      << DRV_PKA_CMD_OPCODE_BIT_SHIFT            | \
     (uint32_t)(len_id)       << DRV_PKA_CMD_LENID_BIT_SHIFT             | \
     (uint32_t)(reg_id)       << DRV_PKA_CMD_DST_BIT_SHIFT               | \
     (uint32_t)(0x0)          << DRV_PKA_CMD_ENDIAN_BIT_SHIFT            | \
     (uint32_t)(addr)         << DRV_PKA_CMD_LOAD_STORE_BIT_SHIFT)

#define DRV_PKA_COMMAND_BE(op_code,len_id,reg_id,addr) \
   ( (uint32_t)(op_code)      << DRV_PKA_CMD_OPCODE_BIT_SHIFT            | \
     (uint32_t)(len_id)       << DRV_PKA_CMD_LENID_BIT_SHIFT             | \
     (uint32_t)(reg_id)       << DRV_PKA_CMD_DST_BIT_SHIFT               | \
     (uint32_t)(0x1)          << DRV_PKA_CMD_ENDIAN_BIT_SHIFT            | \
     (uint32_t)(addr)         << DRV_PKA_CMD_LOAD_STORE_BIT_SHIFT)

/**   PKA instruction  **/
#define   JMP_COND_CO       0x10
#define   JMP_COND_INF_P    0x11
#define   JMP_COND_NONE     0X1F

#define   PADDP_P0P1_type_affine  0x00
#define   PADDP_P0P1_type_project 0x01
#define   PADDP_P2_type_affine    0x00
#define   PADDP_P2_type_project   0x01

#define   PKA_MOV_SRC_TYPE_REG 0x00
#define   PKA_MOV_SRC_TYPE_VAL 0x03

#define SPRD_CE_PKA_INST_LEN                            CE_PKA_CMD_FLAG_LEN
#define SPRD_CE_PKA_INST_ADDR_OFFSET                    CE_PKA_INSTR_ADDR
#define SPRD_CE_PKA_STORE_H_ADDR_OFFSET                 CE_PKA_STORE_ADDR_HI
#define SPRD_CE_PKA_LOAD_H_ADDR_OFFSET                  CE_PKA_LOAD_ADDR_HI
#define SPRD_CE_PKA_REG_LENGTH01_OFFSET                 CE_PKA_REG_LEN01
#define SPRD_CE_PKA_REG_LENGTH23_OFFSET                 CE_PKA_REG_LEN23

#define SPRD_WRITEREG(regOffset, val) do { uint32_t __i; __i = val; sprd_ce_write_pka_cmd_cfg(regOffset, 1, &__i);} while(0)

/*  01 RAN */
#define   DRV_PKA_RAN_ins(op_r, len_id)      \
            drv_pka_set_operation(CE_PKA_OPCODE_RAN,(len_id), (op_r), 0, REG_NULL, 0, REG_NULL, 0)

/*  PADDP:        */
#define   DRV_PKA_PADDP_ins(op_x1, op_y1, op_z1, op_x2, op_z2, p0p1_type, p2_type)   \
            drv_pka_set_operation(CE_PKA_OPCODE_PADDP,(op_z2>>1), (op_x2), (op_z2&0x01), (op_x1), (p0p1_type), (op_y1), ((op_z1<<1)|p2_type))
/*  PADD:        */
#define   DRV_PKA_PADD_ins(op_y2, op_x0, op_y0, op_z0, mont, len_id)   \
            drv_pka_set_operation(CE_PKA_OPCODE_PADD,(len_id), (op_y2), 0, (op_x0), 0, (op_y0), ((op_z0<<1)|mont))

/*  PDBLP:        */
#define   DRV_PKA_PDBLP_ins(op_x2, op_z2, op_a, p1_type, p2_type, a_type)   \
            drv_pka_set_operation(CE_PKA_OPCODE_PDBLP,(op_z2>>1), (op_x2), (op_z2&0x01), (op_a), (p1_type), 0, ((a_type<<1)|p2_type))

/*  PDBL:        */
#define   DRV_PKA_PDBL_ins(op_y2, op_x1, op_y1, op_z1, mont, len_id)   \
            drv_pka_set_operation(CE_PKA_OPCODE_PDBL,(len_id), (op_y2), 0, (op_x1), 0, (op_y1), ((op_z1<<1)|mont))

/*  KPP:        */
#define   DRV_PKA_KPP_ins(op_a, op_k, op_gx, len_id, a_type)   \
				drv_pka_set_operation(CE_PKA_OPCODE_KPP,(len_id), (op_gx), (0), (op_a), (0), (op_k), (a_type<<1))

	/*  SMULF:        */
#define   DRV_PKA_SMULF_ins(op_gy, op_px, op_py, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_SMULF,(len_id), (op_gy), 0, (op_px), 0, (op_py), 0)

	/*  GTM:        */
#define   DRV_PKA_GTM_ins(op_a, op_ma, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_GTM,(len_id), (op_ma), 0,(op_a), 0, 0, 0)

	/*  MTG:        */
#define   DRV_PKA_MTG_ins(op_ma, op_a, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MTG,(len_id), (op_a), 0,(op_ma), 0, 0, 0)

	/*  JMP: JMP dst_addr*/
#define   DRV_PKA_JMP_ins(condition, dst_addr)      \
				drv_pka_set_operation2(CE_PKA_OPCODE_JMP, 0, (condition), (dst_addr))

	/* MMUL:  c = a * b mod n, n in reg0*/
#define   DRV_PKA_MMUL_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MMUL,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/* MTMUL:  c = a * b *R - 1 mod n, n in reg0*/
#define   DRV_PKA_MTMUL_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MTMUL,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/* MADD:  c = a + b mod n, n in reg0*/
#define   DRV_PKA_MADD_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MADD,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/* MSUB:  c = a - b mod n, n in reg0*/
#define   DRV_PKA_MSUB_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MSUB,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/* MINV:  c = a ^ -1 mod n, n in reg0*/
#define   DRV_PKA_MINV_ins(op_r, op_a, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MINV,(len_id), (op_r), 0, (op_a), 0, 0, 0)

	/* MEXP:  c = a ^ b mod n, n in reg0*/
#define   DRV_PKA_MEXP_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_MEXP,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/*  LD:  [src_addr] -> reg_id */
#define   DRV_PKA_LD_ins(src_addr, reg_id, len_id)       \
				drv_pka_set_operation2(CE_PKA_OPCODE_LD, (len_id), (reg_id), (src_addr))

	/*  ST: [reg_id] -> dst_addr */
#define   DRV_PKA_ST_ins(reg_id, dst_addr, len_id)      \
				drv_pka_set_operation2(CE_PKA_OPCODE_ST, (len_id), (reg_id), (dst_addr))

    /*  LD:  [src_addr] -> reg_id */
#define   DRV_PKA_LD_BE_ins(src_addr, reg_id, len_id)       \
                drv_pka_set_operation_be(CE_PKA_OPCODE_LD, (len_id), (reg_id), (src_addr))

    /*  ST: [reg_id] -> dst_addr */
#define   DRV_PKA_ST_BE_ins(reg_id, dst_addr, len_id)      \
                drv_pka_set_operation_be(CE_PKA_OPCODE_ST, (len_id), (reg_id), (dst_addr))

	/*  MOV: [src_id]/con_data -> [dst_id]  */
#define   DRV_PKA_MOV_ins(src, dst_id, len_id, tag)      \
				drv_pka_set_operation(CE_PKA_OPCODE_MOV,(len_id), (dst_id), 0, (src), 0, 0, tag)

	/*  ADD: op_r =  op_a + op_b  */
#define   DRV_PKA_ADD_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_ADD,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/*  SUB:   op_r =  op_a - op_b */
#define   DRV_PKA_SUB_ins(op_r, con_a, op_a, con_b, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_SUB,(len_id), (op_r), (con_a), (op_a), (con_b), (op_b), 0)

	/*  DIV:   op_q =  op_a / op_b , op_r =  op_a % op_b*/
#define   DRV_PKA_DIV_ins(op_q, op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_DIV,(len_id), (op_r), 0, (op_a), 0, (op_b), (0x20|op_q))

	/*  MOD:   op_r =  op_a % op_b  */
#define   DRV_PKA_MOD_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_DIV,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/*  SHL:   op_r = op_a << 1  */
#define   DRV_PKA_SHL_ins(op_r, op_a, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_SHL,(len_id), (op_r), 0, (op_a), 0, 0, 0)

	/*  SHR:   op_r = op_a >> 1  */
#define   DRV_PKA_SHR_ins(op_r, op_a, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_SHR,(len_id), (op_r), 0, (op_a), 0, 0, 0)

	/*  AND:   op_r =  op_a & op_b  */
#define   DRV_PKA_AND_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_AND,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/*  OR:   op_r =  op_a | op_b  */
#define   DRV_PKA_OR_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_OR,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

	/* INV:   op_r =  ~op_a */
#define   DRV_PKA_INV_ins(op_r, op_a, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_INV,(len_id), (op_r), 0, (op_a), 0, 0, 0)

	/* XOR:   op_r =  op_a ** op_b  */
#define   DRV_PKA_XOR_ins(op_r, op_a, op_b, len_id)   \
				drv_pka_set_operation(CE_PKA_OPCODE_XOR,(len_id), (op_r), 0, (op_a), 0, (op_b), 0)

#define   DRV_PKA_END_ins  0xFFFFFFFF

extern uint32_t *g_pka_inst_buf;

uint32_t drv_pka_set_operation( uint8_t op_code, uint8_t len_id, uint8_t op_r,
		uint8_t is_a_const, uint8_t op_a, uint8_t is_b_const, uint8_t op_b, uint8_t tag);

uint32_t drv_pka_set_operation2( uint8_t op_code, uint8_t len_id,
		uint8_t reg_id, uintptr_t addr);

sprd_crypto_err_t  drv_pka_set_len(uint32_t len, uint32_t len_id);

uint32_t drv_pka_set(uint8_t value, uint8_t reg_id, uint32_t len, uint8_t len_id);

uint32_t drv_pka_load(uint32_t *src_addr, uint8_t reg_id, uint32_t len, uint8_t len_id);

uint32_t drv_pka_store(uint8_t reg_id, uint32_t *dst_addr, uint32_t len, uint8_t len_id);

uint32_t drv_pka_load_be(uint32_t *src_addr, uint8_t reg_id, uint32_t len, uint8_t len_id);

uint32_t drv_pka_store_be(uint8_t reg_id, uint32_t *dst_addr, uint32_t len, uint8_t len_id);


sprd_crypto_err_t drv_pka_set_instruction(void* command_base, uint32_t num);

sprd_crypto_err_t drv_pka_set_high_addr(void* load_high, void* store_high);

#endif
