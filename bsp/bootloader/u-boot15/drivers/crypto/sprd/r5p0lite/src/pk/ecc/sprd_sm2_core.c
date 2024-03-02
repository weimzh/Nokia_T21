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

#include "sprd_sm2_core.h"
#include "sprd_ecc_pka.h"
#include "sprd_utils.h"

/* Enumerator for the EC point coordinates identificator */
typedef enum
{
	ECC_COORDINATE_Affine           = 0,   /* Affine coordinates */
	ECC_COORDINATE_Jacobian         = 1,   /* Jacobian projective coordinates */
	ECC_COORDINATE_ProjStandard     = 2,   /* Standard projective coordinates */
	ECC_COORDINATE_Chudnovsky       = 3,   /* Chudnovsky projective coordinates */
	ECC_COORDINATE_Last             = 0x7FFFFFFF,
} sprd_ecc_coordinate_t;

typedef struct {
	uint8_t  reg_p ;
	uint8_t  reg_a ;
	uint8_t  reg_b ;
	uint8_t  reg_gx;
	uint8_t  reg_gy;
	uint8_t  reg_gz;
	uint8_t  reg_n ;
	uint32_t  p_bytelen;
	uint32_t  n_bytelen;
	sprd_ecc_fieldid_t ecc_field;
} sprd_ecc_curve_reg_t;

typedef struct  {
	uint8_t   reg_x;
	uint8_t   reg_y;
	uint8_t   reg_z;
	sprd_ecc_coordinate_t coordinate_id;
} sprd_ecc_point_reg_t;

typedef struct {
	uint8_t reg_r;
	uint8_t reg_s;
} sprd_ecc_signature_reg_t;

#define SM2_OFFSET_BASE  100
#define SM2_DATA_MAX_LEN 10

static sprd_crypto_err_t sprd_sm2_core_keygen(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, sprd_ecc_prikey_t *prikey, sprd_ecc_pubkey_t *pubkey)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};
	sprd_ecc_point_reg_t rpa = {
		.reg_x = REG_IN_RAM4_04,
		.reg_y = REG_IN_RAM5_05,
		.coordinate_id = ECC_COORDINATE_Affine,
	};
	uint8_t rda = REG_IN_RAM1_01;
	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM2_02, REG_IN_RAM3_03, REG_IN_RAM6_06
	};
	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp = rtemp[1];
	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b Gx,Gy, n to related registers */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* Generate random k and Check whether it is valid or not */
	*tmp++ = DRV_PKA_RAN_ins(reg_temp, LEN_ID_01);
	*tmp++ = DRV_PKA_MOD_ins(rda, reg_temp, rcurve.reg_n, LEN_ID_01);
	*tmp++ = DRV_PKA_SUB_ins(reg_temp, 0, rda, 1, 0x01, LEN_ID_01);
	*tmp++ = DRV_PKA_JMP_ins(JMP_COND_CO, 0);

	/* Calculate Q(x1, y1)(Q(x1, y1) = kG(x, y)) and check whether it is infinite point or not*/
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, rda, rpa.reg_x, LEN_ID_01, 1);
	*tmp++ = DRV_PKA_SMULF_ins(rpa.reg_y, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01);
	*tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

	/* Save k and Q(x1, y1) as keypair */
	*tmp++ = drv_pka_store_be(rda, sprd_pal_vaddr_to_paddr((uint8_t *)prikey->prikey), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(rpa.reg_x, sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_x), rcurve.p_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(rpa.reg_y, sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_y), rcurve.p_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* clean & invalidate cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_invalidate_by_vaddr(prikey, sizeof(sprd_ecc_prikey_t));
	sprd_pal_invalidate_by_vaddr(pubkey, sizeof(sprd_ecc_pubkey_t));

	return ret;
}

static sprd_crypto_err_t sprd_sm2_core_sign(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, sprd_ecc_prikey_t *prikey, uint8_t *hash_data,
		uint8_t hash_bytelen, sprd_ecc_signature_t *rs)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};

	uint8_t rda = REG_IN_RAM3_0b;
	uint8_t rdata = REG_IN_RAM1_09;

	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
		REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06
	};

	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp01 = rtemp[1];
	uint8_t reg_temp02 = rtemp[2];
	uint8_t reg_temp03 = rtemp[3];
	uint8_t reg_temp04 = rtemp[4];
	uint8_t reg_temp05 = rtemp[5];
	uint8_t reg_temp06 = rtemp[6];
	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;
	sprd_pal_memset(tmp, 0, PKA_DATA_LEN*4);

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rda, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rdata, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b Gx,Gy, n to related registers */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* load private key and hash to registers */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(prikey->prikey), rda, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(hash_data), rdata, hash_bytelen, LEN_ID_01);

	/* Generate random k and Check whether it is valid or not */
	*tmp++ = DRV_PKA_RAN_ins(reg_temp03, LEN_ID_01);
	*tmp++ = DRV_PKA_MOD_ins(reg_temp01, reg_temp03, rcurve.reg_n, LEN_ID_01);
	*tmp++ = DRV_PKA_SUB_ins(reg_temp03, 0, reg_temp01, 1, 0x01, LEN_ID_01);
	*tmp++ = DRV_PKA_JMP_ins(JMP_COND_CO, 0);

	/* Calculate Q(x1, y1) = [k]G */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp03, LEN_ID_01, 1);     /* reg_temp03 ->x1 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp06, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01);  /* reg_temp06 ->y1 */

	/* calculate the r of signature( r = (e+x1) mod n, e is hash of message ) */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_n, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp05, reg_temp03, rdata, LEN_ID_01);
	*tmp++ = DRV_PKA_MOV_ins(0, reg_temp04, LEN_ID_01, PKA_MOV_SRC_TYPE_VAL);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp02, reg_temp05, reg_temp04, LEN_ID_01);

	/* Calculte the s of signature ( s = (1/(1 + dA)*(k - r*dA )) mod n ) */
	*tmp++ = DRV_PKA_MOV_ins(0x01, reg_temp06, LEN_ID_01, PKA_MOV_SRC_TYPE_VAL);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp04, reg_temp06, rda, LEN_ID_01);                /* reg_temp04 -> (1+da) mod n */
	*tmp++ = DRV_PKA_MOV_ins(0, reg_temp03, LEN_ID_01, PKA_MOV_SRC_TYPE_VAL);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp05, reg_temp03, reg_temp04, LEN_ID_01);

	*tmp++ = DRV_PKA_MINV_ins(reg_temp04, reg_temp05, LEN_ID_01);                     /* reg_temp04 -> 1/(da+1) */

	*tmp++ = DRV_PKA_MMUL_ins(reg_temp06, reg_temp02, rda, LEN_ID_01);                /* reg_temp06 -> r*da */
	*tmp++ = DRV_PKA_MSUB_ins(reg_temp05, reg_temp01, reg_temp06, LEN_ID_01);         /* reg_temp05 -> k-r*da */
	*tmp++ = DRV_PKA_MMUL_ins(reg_temp03, reg_temp04, reg_temp05, LEN_ID_01);         /* reg_temp03 -> (1/(1+da))(k-r*da) */

	*tmp++ = drv_pka_store_be(reg_temp02, sprd_pal_vaddr_to_paddr(rs->ecc_r), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(reg_temp03, sprd_pal_vaddr_to_paddr(rs->ecc_s), rcurve.n_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* invalidate and clean cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_clean_by_vaddr(prikey, sizeof(sprd_ecc_prikey_t));
	sprd_pal_clean_by_vaddr(hash_data, hash_bytelen);
	sprd_pal_invalidate_by_vaddr(rs, sizeof(sprd_ecc_signature_t));

	return ret;
}

static sprd_crypto_err_t sprd_sm2_core_verify(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, sprd_ecc_pubkey_t *pubkey, uint8_t *hash_data,
		uint8_t hash_bytelen, sprd_ecc_signature_t *rs, uint32_t *out)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};
	sprd_ecc_signature_reg_t rsignature = {
		.reg_r = REG_IN_RAM3_0b,
		.reg_s = REG_IN_RAM4_0c,
	};
	sprd_ecc_point_reg_t rpa = {
		.reg_x = REG_IN_RAM5_0d,
		.reg_y = REG_IN_RAM6_0e,
		.coordinate_id = ECC_COORDINATE_Affine,
	};
	uint8_t rdata = REG_IN_RAM2_0a;
	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
		REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06
	};
	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp01 = rtemp[1];
	uint8_t reg_temp02 = rtemp[2];
	uint8_t reg_temp03 = rtemp[3];
	uint8_t reg_temp04 = rtemp[4];
	uint8_t reg_temp05 = rtemp[5];
	uint8_t reg_temp06 = rtemp[6];

	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rpa.reg_x, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rpa.reg_y, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rdata, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b,Gx,Gy,n to related regitsters */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* load public key */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(pubkey->pubkey_x), rpa.reg_x, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(pubkey->pubkey_y), rpa.reg_y, rcurve.p_bytelen, LEN_ID_02);

	/* load signature */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(rs->ecc_r), rsignature.reg_r, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(rs->ecc_s), rsignature.reg_s, rcurve.n_bytelen, LEN_ID_01);

	/* load the hash of message*/
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(hash_data), rdata, hash_bytelen, LEN_ID_01);

	/* calculte t( t =(r+s) mod n ) */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_n, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp02, rsignature.reg_r, rsignature.reg_s, LEN_ID_01);        /* (r+s) mod n -> reg_temp02 */
	*tmp++ = DRV_PKA_MOV_ins(0, reg_temp03, LEN_ID_01, PKA_MOV_SRC_TYPE_VAL);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp01, reg_temp02, reg_temp03, LEN_ID_01);                    /* (r+s) mod n -> reg_temp01 */

	/* calculate (x1,y1)=[s]G */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, rsignature.reg_s, reg_temp02, LEN_ID_01, 1);          /* x1 -> reg_temp02 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp03, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01);             /* y1 -> reg_temp03 */

	/* calculate (x2,y2)=[t]P, p is public key */
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp04, LEN_ID_01, 1);                /* x2 -> reg_temp04 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp05, rpa.reg_x, rpa.reg_y, LEN_ID_01);                     /* y2 -> reg_temp05 */

	/* calculate (x3,y3)=[s]G+[t]P */
	*tmp++ = DRV_PKA_PADDP_ins(reg_temp02, reg_temp03, 0, reg_temp01, 0, 0, 0);                  /* x3 -> reg_temp01 */
	*tmp++ = DRV_PKA_PADD_ins(reg_temp06, reg_temp04, reg_temp05, 0, 0, LEN_ID_01);              /* y3 -> reg_temp06 */

	/* calculate R(R=(x3+e) mod n), e is the hash of message */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_n, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp04, reg_temp01, rdata, LEN_ID_01);                         /* (e+x3) mod n -> reg_temp4 */
	*tmp++ = DRV_PKA_MOV_ins(0, reg_temp02, LEN_ID_01, PKA_MOV_SRC_TYPE_VAL);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp03, reg_temp02, reg_temp04, LEN_ID_01);

	*tmp++ = drv_pka_store_be(reg_temp03, sprd_pal_vaddr_to_paddr(out), rcurve.n_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* Invalidate and clean cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_clean_by_vaddr(pubkey, sizeof(sprd_ecc_pubkey_t));
	sprd_pal_clean_by_vaddr(hash_data, hash_bytelen);
	sprd_pal_clean_by_vaddr(rs, sizeof(sprd_ecc_signature_t));
	sprd_pal_invalidate_by_vaddr(out, rcurve.n_bytelen);

	return ret;
}

static sprd_crypto_err_t sprd_sm2_core_prepare_dh(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, sprd_ecc_prikey_t *prikey, sprd_ecc_pubkey_t *pubkey)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};

	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
		REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06
	};

	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp01 = rtemp[1];
	uint8_t reg_temp03 = rtemp[3];
	uint8_t reg_temp06 = rtemp[6];
	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;
	sprd_pal_memset(tmp, 0, PKA_DATA_LEN*4);

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b,Gx,Gy,n to related register */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* load private key */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(prikey->prikey), reg_temp01,  rcurve.p_bytelen, LEN_ID_01);

	/* Calculate Q(x1, y1) = [k]G */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp03, LEN_ID_01, 1);              /* reg_temp03 ->x1 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp06, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01);           /* reg_temp06 ->y1 */

	/* Save Q(x1, y1) as to public key */
	*tmp++ = drv_pka_store_be(reg_temp03, sprd_pal_vaddr_to_paddr(pubkey->pubkey_x), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(reg_temp06, sprd_pal_vaddr_to_paddr(pubkey->pubkey_y), rcurve.n_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* Invalidate and clean cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_clean_by_vaddr(prikey, sizeof(sprd_ecc_prikey_t));
	sprd_pal_clean_by_vaddr(pubkey, sizeof(sprd_ecc_pubkey_t));

	return ret;
}

static sprd_crypto_err_t sprd_sm2_compute_key_dh(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, ecc_key_dh_t *key_dh)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};

	uint8_t reg5_loadx = REG_IN_RAM5_0d;
	uint8_t reg4_loady = REG_IN_RAM4_0c;
	uint8_t reg3_num   = REG_IN_RAM3_0b;

	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
		REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06
	};

	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp01 = rtemp[1];
	uint8_t reg_temp02 = rtemp[2];
	uint8_t reg_temp03 = rtemp[3];
	uint8_t reg_temp04 = rtemp[4];
	uint8_t reg_temp05 = rtemp[5];
	uint8_t reg_temp06 = rtemp[6];
	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;
	sprd_pal_memset(tmp, 0, PKA_DATA_LEN*4);

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b,Gx,Gy,n to related registers */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* load x1 of the public key */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->RA.pubkey_x), reg5_loadx,  rcurve.p_bytelen, LEN_ID_01);

	/* load 2^127 */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->param_num127), reg3_num,  rcurve.p_bytelen, LEN_ID_01);

	/* calculate  x1` = 2^127 + (x1&(2^127 - 1)) */
	*tmp++ = DRV_PKA_SUB_ins(reg_temp02, 0, reg3_num, 1, 0x01, LEN_ID_01);
	*tmp++ = DRV_PKA_AND_ins(reg_temp04, reg_temp02, reg5_loadx, LEN_ID_01);
	*tmp++ = DRV_PKA_ADD_ins(reg_temp05, reg_temp04, reg3_num, LEN_ID_01);        /* 2^127 + (x1 & (2^127 - 1)) -> reg_temp05 */

	/* calucate tA=(dA+x1`*rA) mod n */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->rA.prikey), reg_temp03,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_n, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_MMUL_ins(reg_temp02, reg_temp05, reg_temp03, LEN_ID_01);     /* x1` * rA -> reg_temp02 */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->dA.prikey), reg_temp03,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp04, reg_temp02, reg_temp03, LEN_ID_01);     /* (dA+x1` * rA) mod n -> reg_temp04 */

	*tmp++ = DRV_PKA_MOV_ins(0, reg_temp02, LEN_ID_01, PKA_MOV_SRC_TYPE_VAL);
	*tmp++ = DRV_PKA_MADD_ins(reg_temp06, reg_temp02, reg_temp04, LEN_ID_01);     /* (dA+x1` * rA) mod n -> reg_temp06 */

	/* calculate x2` = 2^127 + (x2&(2^127 - 1)) */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->RB.pubkey_x), reg5_loadx,  rcurve.p_bytelen, LEN_ID_01);
	*tmp++ = DRV_PKA_SUB_ins(reg_temp02, 0, reg3_num, 1, 0x01, LEN_ID_01);
	*tmp++ = DRV_PKA_AND_ins(reg_temp04, reg_temp02, reg5_loadx, LEN_ID_01);
	*tmp++ = DRV_PKA_ADD_ins(reg_temp05, reg_temp04, reg3_num, LEN_ID_01);        /* 2^127 + (x2 & (2^127 - 1)) -> reg_temp05*/

	/* calculate [x2`]RB =(xB0, yB0) */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->RB.pubkey_y), reg4_loady,  rcurve.p_bytelen, LEN_ID_01);
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp05, reg_temp04, LEN_ID_01, 1); /* xB0 -> reg_temp04 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp01, reg5_loadx, reg4_loady, LEN_ID_01);    /* yB0 -> reg_temp01 */

	/* calculte  PB +[x2`]RB =(xB1,yB1) */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->PB.pubkey_x), reg5_loadx,  rcurve.p_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(key_dh->PB.pubkey_y), reg4_loady,  rcurve.p_bytelen, LEN_ID_01);
	*tmp++ = DRV_PKA_PADDP_ins(reg_temp04, reg_temp01, 0, reg_temp02, 0, 0, 0);          /* xB1 -> reg_temp02  */
	*tmp++ = DRV_PKA_PADD_ins(reg_temp03, reg5_loadx, reg4_loady, 0, 0, LEN_ID_01);      /* yB1 -> reg_temp03  */

	/* calculate U=[h.tA](PB+[x2`]RB)=(xU,yU) */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp06, reg_temp04, LEN_ID_01, 1);        /* xU -> reg_temp04   */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp01, reg_temp02, reg_temp03, LEN_ID_01);           /* yU -> reg_temp01   */

	/* save U */
	*tmp++ = drv_pka_store_be(reg_temp04, sprd_pal_vaddr_to_paddr(key_dh->UA.pubkey_x), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(reg_temp01, sprd_pal_vaddr_to_paddr(key_dh->UA.pubkey_y), rcurve.n_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* invalidate and clean cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_clean_by_vaddr(key_dh, sizeof(ecc_key_dh_t));

	return ret;
}

static sprd_crypto_err_t sprd_sm2_core_pub_enc(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, ecc_enc_dec_t *enc_dec)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};

	uint8_t reg5_loadx = REG_IN_RAM5_0d;
	uint8_t reg4_loady = REG_IN_RAM4_0c;

	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
		REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06
	};

	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp01 = rtemp[1];
	uint8_t reg_temp03 = rtemp[3];
	uint8_t reg_temp06 = rtemp[6];
	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;
	sprd_pal_memset(tmp, 0, PKA_DATA_LEN*4);

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b,Gx,Gy,n to related register */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* calculte C1(C1(x1, y1) = [k]G), k is a random) */
	*tmp++ = DRV_PKA_RAN_ins(reg_temp01, LEN_ID_01);
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp03, LEN_ID_01, 1);        /* x1 -> reg_temp03 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp06, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01);     /* y1 -> reg_temp06 */

	*tmp++ = drv_pka_store_be(reg_temp03, sprd_pal_vaddr_to_paddr(enc_dec->C1.pubkey_x), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(reg_temp06, sprd_pal_vaddr_to_paddr(enc_dec->C1.pubkey_y), rcurve.n_bytelen, LEN_ID_01);

	/* calculate (x2, y2) = [k]PB, k is a random) */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(enc_dec->PB.pubkey_x), reg5_loadx,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(enc_dec->PB.pubkey_y), reg4_loady,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp03, LEN_ID_01, 1);        /* x2 -> reg_temp03 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp06, reg5_loadx, reg4_loady, LEN_ID_01);           /* y2 -> reg_temp06 */

	*tmp++ = drv_pka_store_be(reg_temp03, sprd_pal_vaddr_to_paddr(enc_dec->point.pubkey_x), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(reg_temp06, sprd_pal_vaddr_to_paddr(enc_dec->point.pubkey_y), rcurve.n_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* invalidate and clean cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_clean_by_vaddr(enc_dec, sizeof(ecc_enc_dec_t));

	return ret;
}


static sprd_crypto_err_t sprd_sm2_core_pri_dec(sprd_ecc_curve_t *curve,
		uint32_t *pka_data, ecc_enc_dec_t *enc_dec)
{
	sprd_ecc_curve_t *cur_curve;
	sprd_ecc_curve_reg_t rcurve = {
		.reg_p =  REG_IN_RAM1_11,
		.reg_a =  REG_IN_RAM2_12,
		.reg_b =  REG_IN_RAM3_13,
		.reg_gx = REG_IN_RAM4_14,
		.reg_gy = REG_IN_RAM5_15,
		.reg_n =  REG_IN_RAM6_16,
	};

	uint8_t reg5_loadx = REG_IN_RAM5_0d;
	uint8_t reg4_loady = REG_IN_RAM4_0c;

	uint8_t rtemp[] = {
		REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
		REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06
	};

	uint8_t reg_m = rtemp[0];
	uint8_t reg_temp01 = rtemp[1];
	uint8_t reg_temp03 = rtemp[3];
	uint8_t reg_temp06 = rtemp[6];
	sprd_crypto_err_t ret = SPRD_ECC_OK;

	cur_curve = curve;

	rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
	rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
	rcurve.ecc_field = cur_curve->ecc_field;

	/* The beginning address of PKA command */
	uint32_t *tmp = pka_data;
	sprd_pal_memset(tmp, 0, PKA_DATA_LEN*4);

	/* Set the length of n and p  to CE_PKA_REG_LENGH01 & CE_PKA_REG_LENGH23 registers */
	ret = drv_pka_set_len(rcurve.n_bytelen, LEN_ID_01);
	ret = drv_pka_set_len(rcurve.p_bytelen, LEN_ID_02);

	/* write upper 19bit address of pka_data to CE_PKA_STORE_ADDR_HI & CE_PKA_LOAD_ADDR_HI */
	drv_pka_set_high_addr(pka_data, pka_data);

	*tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

	/* load p,a,b,Gx,Gy,n */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

	/* load private key */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(enc_dec->dB.prikey), reg_temp01,  rcurve.n_bytelen, LEN_ID_01);

	/* load C1 */
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(enc_dec->C1.pubkey_x), reg5_loadx,  rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_load_be(sprd_pal_vaddr_to_paddr(enc_dec->C1.pubkey_y), reg4_loady,  rcurve.n_bytelen, LEN_ID_01);

	/* calculate (x2, y2)=[dB]C1 */
	*tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
	*tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp03, LEN_ID_01, 1);      /* x2 -> reg_temp03 */
	*tmp++ = DRV_PKA_SMULF_ins(reg_temp06, reg5_loadx, reg4_loady, LEN_ID_01);         /* y2 -> reg_temp06 */

	*tmp++ = drv_pka_store_be(reg_temp03, sprd_pal_vaddr_to_paddr(enc_dec->point.pubkey_x), rcurve.n_bytelen, LEN_ID_01);
	*tmp++ = drv_pka_store_be(reg_temp06, sprd_pal_vaddr_to_paddr(enc_dec->point.pubkey_y), rcurve.n_bytelen, LEN_ID_01);

	*tmp++ = DRV_PKA_END_ins;

	drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

	/* invalidate and clean cache */
	sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
	sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
	sprd_pal_clean_by_vaddr(enc_dec, sizeof(ecc_enc_dec_t));

	return ret;
}

sprd_crypto_err_t sprd_sm2_core_handler(sprd_ecc_data_t *data)
{
	switch(data->req_id) {
		case SPRD_ECC_REQUEST_VERIFY:
			sprd_sm2_core_verify(&(data->curve), data->pka_data, &(data->param.verify.pubkey),
					data->param.verify.hash_data, data->param.verify.hash_bytelen,
					&(data->param.verify.rs), data->param.verify.out_r);
			break;

		case SPRD_ECC_REQUEST_SIGN:
			sprd_sm2_core_sign(&(data->curve), data->pka_data, &(data->param.sign.prikey),
					data->param.sign.hash_data, data->param.sign.hash_bytelen, &(data->param.sign.rs));
			break;

		case SPRD_ECC_REQUEST_KEYGEN:
			sprd_sm2_core_keygen(&(data->curve), data->pka_data, &(data->param.keygen.prikey),
					&(data->param.keygen.pubkey));
			break;

		case SPRD_ECC_REQUEST_EC_POINT:
			sprd_sm2_core_prepare_dh(&(data->curve), data->pka_data, &(data->param.key_dh.rA),
					&(data->param.key_dh.RA));
			break;

		case SPRD_ECC_REQUEST_KEY_DH:
			sprd_sm2_compute_key_dh(&(data->curve), data->pka_data, &(data->param.key_dh));
			break;

		case SPRD_ECC_REQUEST_PUB_ENC:
			sprd_sm2_core_pub_enc(&(data->curve), data->pka_data, &(data->param.enc_dec));
			break;

		case SPRD_ECC_REQUEST_PRI_DEC:
			sprd_sm2_core_pri_dec(&(data->curve), data->pka_data, &(data->param.enc_dec));
			break;

		default:
			break;
	}

	return SPRD_ECC_OK;
}
