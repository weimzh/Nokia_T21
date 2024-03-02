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


#include "sprd_ecc_core.h"
#include "sprd_ecc_pka.h"

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

static sprd_crypto_err_t sprd_ecc_core_keygen(sprd_ecc_curve_t *curve, uint32_t *pka_data,
        sprd_ecc_prikey_t *prikey, sprd_ecc_pubkey_t *pubkey) {
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
    uint8_t random = REG_IN_RAM1_01;
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

    *tmp++ = drv_pka_set(0, rcurve.reg_p, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_a, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_b, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

    /* load p,a,b Gx,Gy,n */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

    *tmp++ = drv_pka_set(0, random, rcurve.p_bytelen, LEN_ID_02);

    /* generate random k */
    *tmp++ = DRV_PKA_RAN_ins(reg_temp, LEN_ID_02);
    if (rcurve.n_bytelen > rcurve.p_bytelen)
        *tmp++ = DRV_PKA_MOV_ins(reg_temp, random, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);     /* random -> random */
    else
        *tmp++ = DRV_PKA_MOD_ins(random, reg_temp, rcurve.reg_n, LEN_ID_02);             /* random -> random */
    *tmp++ = DRV_PKA_SUB_ins(reg_temp, 0, random, 1, 0x01, LEN_ID_02);
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_CO, 0);

    /* calculate Q(x, y)=[k]G */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, random, rpa.reg_x, LEN_ID_02, 1);
    *tmp++ = DRV_PKA_SMULF_ins(rpa.reg_y, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_02);
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* save k as to private key and save Q(x, y) as to public key */
    *tmp++ = drv_pka_store(random, sprd_pal_vaddr_to_paddr((uint8_t *)prikey->prikey), rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_store(rpa.reg_x, sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_x), rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_store(rpa.reg_y, sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_y), rcurve.p_bytelen, LEN_ID_02);

    /* stop cmd */
    *tmp++ = DRV_PKA_END_ins;

    drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

    /* Invalidate and clean cache */
    sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
    sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
    sprd_pal_invalidate_by_vaddr(prikey, sizeof(sprd_ecc_prikey_t));
    sprd_pal_invalidate_by_vaddr(pubkey, sizeof(sprd_ecc_pubkey_t));

    return ret;
}

static sprd_crypto_err_t sprd_ecc_core_sign(sprd_ecc_curve_t *curve,
        uint32_t *pka_data, sprd_ecc_prikey_t *prikey, uint8_t *hash_data,
        uint8_t hash_bytelen, sprd_ecc_signature_t *rs) {
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
        .reg_r = REG_IN_RAM5_0d,
        .reg_s = REG_IN_RAM4_0c,
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

    uint8_t hash_result[SPRD_ECC_CURVE_MAX_WORD_LENGTH*4];
    int i;
    int shift;
    int n_real_bytelen = 0;

    cur_curve = curve;

    rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
    rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
    rcurve.ecc_field = cur_curve->ecc_field;

    n_real_bytelen = (cur_curve->ecc_n_bitlen+7)/8;
    sprd_pal_memset(hash_result, 0, cur_curve->ecc_n_wordlen*4);
    if (cur_curve->ecc_n_bitlen >= 8*hash_bytelen) {
        sprd_pal_memcpy(hash_result, hash_data, hash_bytelen);
    } else {
        sprd_pal_memcpy(hash_result, hash_data, n_real_bytelen);
        shift = (8 - (cur_curve->ecc_n_bitlen & 7UL)) & 7UL;
        if (shift) {
            for (i = 0; i < n_real_bytelen - 1; i++) {
                hash_result[i] = (hash_result[i] >> shift) |
                                (hash_result[i+1] << (8-shift));
            }
            hash_result[i] = hash_result[i] >> shift;
        }
        hash_bytelen = n_real_bytelen;
    }
    sprd_pal_memset(hash_data, 0, HASH_MAX_LEN);
    sprd_pal_memcpy(hash_data, hash_result, hash_bytelen);

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

    /* load p,a,b,Gx,Gy,n */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

    /* load private key d */
    *tmp++ = drv_pka_set(0, rda, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)prikey->prikey), rda, rcurve.n_bytelen, LEN_ID_01);

    /* load the hash of message */
    *tmp++ = drv_pka_set(0, rdata, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)hash_data), rdata, hash_bytelen, LEN_ID_01);
    *tmp++ = DRV_PKA_MOD_ins(reg_temp02, rdata, rcurve.reg_n, LEN_ID_01);

    /* Generate random k */
    *tmp++ = DRV_PKA_RAN_ins(reg_temp03, LEN_ID_01);
    *tmp++ = DRV_PKA_MOD_ins(reg_temp01, reg_temp03, rcurve.reg_n, LEN_ID_01);    /* k -> reg_temp01 */
    *tmp++ = DRV_PKA_SUB_ins(reg_temp03, 0, reg_temp01, 1, 0x01, LEN_ID_01);
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_CO, 0);

    /* calculate (x1,y1)=[k]G */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp01, reg_temp04, LEN_ID_01, 1);       /* x1 -> reg_temp04 */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp05, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01);    /* y1 -> reg_temp05 */
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* calculate r=x1 mod n */
    *tmp++ = DRV_PKA_MOD_ins(reg_temp03, reg_temp04, rcurve.reg_n, LEN_ID_01);          /* x1 mod n -> reg_temp03 */
    *tmp++ = DRV_PKA_SUB_ins(reg_temp06, 0, reg_temp03, 1, 0x01, LEN_ID_01);
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_CO, 0);

    /* calculate s=1/k(dr+e) mod n*/
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_n, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_MMUL_ins(reg_temp06, reg_temp03, rda, LEN_ID_01);                  /* dr mod n -> reg_temp06 */
    *tmp++ = DRV_PKA_MADD_ins(reg_temp04, reg_temp06, reg_temp02, LEN_ID_01);           /* (dr + e) mod n -> reg_temp04 */
    *tmp++ = DRV_PKA_MINV_ins(reg_temp05, reg_temp01, LEN_ID_01);                       /* 1/k -> reg_temp -> reg_temp05 */
    *tmp++ = DRV_PKA_MMUL_ins(reg_temp02, reg_temp05, reg_temp04, LEN_ID_01);           /* 1/k(dr+e) mod n -> reg_temp02 */

    /* save signature */
    *tmp++ = DRV_PKA_MOV_ins(reg_temp03, rsignature.reg_r, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_MOV_ins(reg_temp02, rsignature.reg_s, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);

    *tmp++ = drv_pka_store(rsignature.reg_r, sprd_pal_vaddr_to_paddr((uint8_t *)rs->ecc_r), rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_store(rsignature.reg_s, sprd_pal_vaddr_to_paddr((uint8_t *)rs->ecc_s), rcurve.n_bytelen, LEN_ID_01);
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

static sprd_crypto_err_t sprd_ecc_core_verify(sprd_ecc_curve_t *curve,
        uint32_t *pka_data, sprd_ecc_pubkey_t *pubkey, uint8_t *hash_data,
        uint8_t hash_bytelen, sprd_ecc_signature_t *rs, uint32_t *out) {
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

    uint8_t hash_result[SPRD_ECC_CURVE_MAX_WORD_LENGTH*4];
    int i;
    int shift;
    int n_real_bytelen = 0;

    cur_curve = curve;

    rcurve.n_bytelen = cur_curve->ecc_n_wordlen*4;
    rcurve.p_bytelen = cur_curve->ecc_p_wordlen*4;
    rcurve.ecc_field = cur_curve->ecc_field;

    n_real_bytelen = (cur_curve->ecc_n_bitlen+7)/8;
    sprd_pal_memset(hash_result, 0, cur_curve->ecc_n_wordlen*4);
    if (cur_curve->ecc_n_bitlen>= 8*hash_bytelen) {
        sprd_pal_memcpy(hash_result, hash_data, hash_bytelen);
    } else {
        sprd_pal_memcpy(hash_result, hash_data, n_real_bytelen);
        shift = (8 - (cur_curve->ecc_n_bitlen & 7UL)) & 7UL;
        if (shift) {
            for (i = 0; i < n_real_bytelen - 1; i++) {
                hash_result[i] = (hash_result[i] >> shift) |
                                (hash_result[i+1] << (8-shift));
            }
            hash_result[i] = hash_result[i] >> shift;
        }
        hash_bytelen = n_real_bytelen;
    }
    sprd_pal_memset(hash_data, 0, HASH_MAX_LEN);
    sprd_pal_memcpy(hash_data, hash_result, hash_bytelen);

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

    /* load p,a,b,Gx,Gy,n */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

    *tmp++ = drv_pka_set(0, rpa.reg_x, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_set(0, rpa.reg_y, rcurve.n_bytelen, LEN_ID_01);

    /* load public key Q(x,y) */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_x), rpa.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_y), rpa.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* load signature r`,s` */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)rs->ecc_r), rsignature.reg_r, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)rs->ecc_s), rsignature.reg_s, rcurve.n_bytelen, LEN_ID_01);

    *tmp++ = drv_pka_set(0, rdata, rcurve.n_bytelen, LEN_ID_01);

    /* load the hash of message e`*/
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)hash_data), rdata, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = DRV_PKA_MOD_ins(reg_temp01, rdata, rcurve.reg_n, LEN_ID_01);

    /* calculate c=1/s` mod n */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_n, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_MINV_ins(reg_temp02, rsignature.reg_s, LEN_ID_01);         /*1/s` mod n -> reg_temp02 */

    /* calculate u1=e`c */
    *tmp++ = DRV_PKA_MMUL_ins(reg_temp03, reg_temp01, reg_temp02, LEN_ID_01);   /*e`c -> reg_temp03 */

    /* calculate u2=r`c */
    *tmp++ = DRV_PKA_MMUL_ins(reg_temp04, rsignature.reg_r, reg_temp02, LEN_ID_01);  /* r`c -> reg_temp04 */

    /* calculate (xg,yg)=u1G */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp03, reg_temp05, LEN_ID_01, 1);    /* xg -> reg_temp05 */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp06, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_01); /* yg -> reg_temp06 */

    /* calculate (xq,yq)=u2Q,  Q is the public key */
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, reg_temp04, reg_temp01, LEN_ID_01, 1);   /* xq -> reg_temp01 */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp02, rpa.reg_x, rpa.reg_y, LEN_ID_01);        /* yq -> reg_temp02 */

    /* calculate (x1,y1)=u1G+u2Q */
    *tmp++ = DRV_PKA_PADDP_ins(reg_temp05, reg_temp06, 0, reg_temp04, 0, 0, 0);     /* x1 -> reg_temp04 */
    *tmp++ = DRV_PKA_PADD_ins(reg_temp03, reg_temp01, reg_temp02, 0, 0, LEN_ID_01); /* y1 -> reg_temp03 */

    /* v = x1 mod n */
    *tmp++ = DRV_PKA_MOD_ins(reg_temp02, reg_temp04, rcurve.reg_n, LEN_ID_01);     /* reg_temp04 -> reg_temp02 */

    /* if v equal r`, verify succeed */
    *tmp++ = drv_pka_store(reg_temp02, sprd_pal_vaddr_to_paddr((uint8_t *)out), rcurve.n_bytelen, LEN_ID_01);

    *tmp++ = DRV_PKA_END_ins;

    drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

    /* invalidate and clean cache */
    sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
    sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
    sprd_pal_clean_by_vaddr(pubkey, sizeof(sprd_ecc_pubkey_t));
    sprd_pal_clean_by_vaddr(hash_data, hash_bytelen);
    sprd_pal_clean_by_vaddr(rs, sizeof(sprd_ecc_signature_t));
    sprd_pal_invalidate_by_vaddr(out, rcurve.n_bytelen);

    return ret;
}

static sprd_crypto_err_t sprd_ecc_core_dh(sprd_ecc_curve_t *curve,
        uint32_t *pka_data, sprd_ecc_prikey_t *prikey,
        sprd_ecc_pubkey_t *pubkey, uint8_t *shared_key) {
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
        .reg_x = REG_IN_RAM5_0d,
        .reg_y = REG_IN_RAM6_0e,
        .coordinate_id = ECC_COORDINATE_Affine,
    };
    uint8_t rda = REG_IN_RAM4_04;
    uint8_t rout = REG_IN_RAM1_01;
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

    /* load p,a,b,Gx,Gy,n */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p ), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

    /* load private key r */
    *tmp++ = drv_pka_set(0, rda, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)prikey->prikey), rda, rcurve.n_bytelen, LEN_ID_01);

    /* load public key P */
    *tmp++ = drv_pka_set(0, rpa.reg_x, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_x), rpa.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rpa.reg_y, rcurve.n_bytelen, LEN_ID_01);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)pubkey->pubkey_y), rpa.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* calculate (x1,y1)=[r]P */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_m, LEN_ID_01, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, rda, rout, LEN_ID_01, 1);            /* x1 -> rout */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp, rpa.reg_x, rpa.reg_y, LEN_ID_01);      /* y1 -> reg_temp */

    /* save x1 as to shared_key */
    *tmp++ = drv_pka_store(rout, sprd_pal_vaddr_to_paddr((uint8_t *)shared_key), rcurve.p_bytelen, LEN_ID_02);

    *tmp++ = DRV_PKA_END_ins;

    drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

    /* invalidate and clean cache */
    sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
    sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
    sprd_pal_clean_by_vaddr(pubkey, sizeof(sprd_ecc_pubkey_t));
    sprd_pal_clean_by_vaddr(prikey, sizeof(sprd_ecc_prikey_t));
    sprd_pal_invalidate_by_vaddr(shared_key, SHARED_KEY_MAX_LEN);

    return ret;
}

static sprd_crypto_err_t sprd_ecc_core_public_encrypt(sprd_ecc_curve_t *curve,
        uint32_t *pka_data, ecc_enc_dec_t* enc_string) {
    sprd_ecc_curve_t *cur_curve;
    sprd_ecc_curve_reg_t rcurve = {
        .reg_p =  REG_IN_RAM1_11,
        .reg_a =  REG_IN_RAM2_12,
        .reg_b =  REG_IN_RAM3_13,
        .reg_gx = REG_IN_RAM4_14,
        .reg_gy = REG_IN_RAM5_15,
        .reg_n =  REG_IN_RAM6_16,
    };

    uint8_t random = REG_IN_RAM1_01;
    sprd_ecc_point_reg_t public_key = {
        .reg_x = REG_IN_RAM3_0b,
        .reg_y = REG_IN_RAM4_0c,
        .coordinate_id = ECC_COORDINATE_Affine,
    };
    sprd_ecc_point_reg_t message = {
        .reg_x = REG_IN_RAM5_0d,
        .reg_y = REG_IN_RAM6_0e,
        .coordinate_id = ECC_COORDINATE_Affine,
    };

    uint8_t reg_array_temp[] = {
        REG_IN_RAM0_00, REG_IN_RAM2_02, REG_IN_RAM3_03, REG_IN_RAM4_04,
        REG_IN_RAM5_05, REG_IN_RAM6_06, REG_IN_RAM7_07
    };
    uint8_t reg_base = reg_array_temp[0];
    uint8_t reg_temp_01 = reg_array_temp[1];
    uint8_t reg_temp_02 = reg_array_temp[2];
    uint8_t reg_temp_03 = reg_array_temp[3];
    uint8_t reg_temp_04 = reg_array_temp[4];
    uint8_t reg_temp_05 = reg_array_temp[5];

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

    *tmp++ = drv_pka_set(0, rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

    /* load p,a,b,Gx,Gy,n */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

    *tmp++ = drv_pka_set(0, public_key.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, public_key.reg_y, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, message.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, message.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* load public key Q(x,y) */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->PB.pubkey_x)), public_key.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->PB.pubkey_y)), public_key.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* load message */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->M.pubkey_x)), message.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->M.pubkey_y)), message.reg_y, rcurve.p_bytelen, LEN_ID_02);

    *tmp++ = drv_pka_set(0, random, rcurve.p_bytelen, LEN_ID_02);

    /* Generate random  */
    *tmp++ = DRV_PKA_RAN_ins(reg_temp_01, LEN_ID_02);

    if (rcurve.n_bytelen > rcurve.p_bytelen)
        *tmp++ = DRV_PKA_MOV_ins(reg_temp_01, random, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);     /* random -> random */
    else
        *tmp++ = DRV_PKA_MOD_ins(random, reg_temp_01, rcurve.reg_n, LEN_ID_02);             /* random -> random */

    *tmp++ = DRV_PKA_SUB_ins(reg_temp_02, 0, random, 1, 0x01, LEN_ID_02);
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_CO, 0);

    /* calculate (x, y)=[r]Q */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_base, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, random, reg_temp_04, LEN_ID_02, 1);                      /* x -> reg_temp_04 */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp_05, public_key.reg_x, public_key.reg_y, LEN_ID_02);         /* y -> reg_temp_05 */
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* calculate C1(x1, y1)=M+[r]Q */
    *tmp++ = DRV_PKA_PADDP_ins(message.reg_x, message.reg_y, 0, reg_temp_02, 0, 0, 0);      /* x1 -> reg_temp_02 */
    *tmp++ = DRV_PKA_PADD_ins(reg_temp_03, reg_temp_04, reg_temp_05, 0, 0, LEN_ID_02);      /* y1 -> reg_temp_03 */
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* calculate C2(x2,y2)=[r]G */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_base, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, random, reg_temp_04, LEN_ID_02, 1);           /* x2 -> reg_temp_03 */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp_05, rcurve.reg_gx, rcurve.reg_gy, LEN_ID_02);    /* y2 -> reg_temp_04 */
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* save C1 */
    *tmp++ = drv_pka_store(reg_temp_02, sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->C1.pubkey_x)), rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_store(reg_temp_03, sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->C1.pubkey_y)), rcurve.p_bytelen, LEN_ID_02);
    /* save C2 */
    *tmp++ = drv_pka_store(reg_temp_04, sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->C2.pubkey_x)), rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_store(reg_temp_05, sprd_pal_vaddr_to_paddr((uint8_t *)(enc_string->C2.pubkey_y)), rcurve.p_bytelen, LEN_ID_02);

    *tmp++ = DRV_PKA_END_ins;

    drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

    /* invalidate and clean cache */
    sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
    sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
    sprd_pal_invalidate_by_vaddr(enc_string, sizeof(ecc_enc_dec_t));

    return ret;
}

static sprd_crypto_err_t sprd_ecc_core_private_decrypt(sprd_ecc_curve_t *curve,
        uint32_t *pka_data, ecc_enc_dec_t* dec_string) {
    sprd_ecc_curve_t *cur_curve;
    sprd_ecc_curve_reg_t rcurve = {
        .reg_p =  REG_IN_RAM1_11,
        .reg_a =  REG_IN_RAM2_12,
        .reg_b =  REG_IN_RAM3_13,
        .reg_gx = REG_IN_RAM4_14,
        .reg_gy = REG_IN_RAM5_15,
        .reg_n =  REG_IN_RAM6_16,
    };

    uint8_t private_key = REG_IN_RAM2_0a;
    sprd_ecc_point_reg_t c1 = {
        .reg_x = REG_IN_RAM3_0b,
        .reg_y = REG_IN_RAM4_0c,
        .coordinate_id = ECC_COORDINATE_Affine,
    };
    sprd_ecc_point_reg_t c2 = {
        .reg_x = REG_IN_RAM5_0d,
        .reg_y = REG_IN_RAM6_0e,
        .coordinate_id = ECC_COORDINATE_Affine,
    };

    uint8_t reg_array_temp[] = {
        REG_IN_RAM0_00, REG_IN_RAM1_01, REG_IN_RAM2_02, REG_IN_RAM3_03,
        REG_IN_RAM4_04, REG_IN_RAM5_05, REG_IN_RAM6_06, REG_IN_RAM7_07
    };
    uint8_t reg_base = reg_array_temp[0];
    uint8_t reg_temp_01 = reg_array_temp[1];
    uint8_t reg_temp_02 = reg_array_temp[2];
    uint8_t reg_temp_03 = reg_array_temp[3];
    uint8_t reg_temp_04 = reg_array_temp[4];
    uint8_t reg_temp_05 = reg_array_temp[5];

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

    *tmp++ = drv_pka_set(0, rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, rcurve.reg_n, rcurve.n_bytelen, LEN_ID_01);

    /* load p,a,b,Gx,Gy,n */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_p), rcurve.reg_p,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_a ), rcurve.reg_a,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_b ), rcurve.reg_b,  rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gx), rcurve.reg_gx, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_gy), rcurve.reg_gy, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr(cur_curve->ecc_n ), rcurve.reg_n,  rcurve.n_bytelen, LEN_ID_01);

    *tmp++ = drv_pka_set(0, private_key, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, c1.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, c1.reg_y, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, c2.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_set(0, c2.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* load private key k */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->dB.prikey)), private_key, rcurve.p_bytelen, LEN_ID_02);

    /* load C1 */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->C1.pubkey_x)), c1.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->C1.pubkey_y)), c1.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* load C2 */
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->C2.pubkey_x)), c2.reg_x, rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_load(sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->C2.pubkey_y)), c2.reg_y, rcurve.p_bytelen, LEN_ID_02);

    /* calculate (x2,y2)=[k]C2 */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_base, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_KPP_ins(rcurve.reg_a, private_key, reg_temp_01, LEN_ID_02, 1);      /* x2 -> reg_temp_01 */
    *tmp++ = DRV_PKA_SMULF_ins(reg_temp_02, c2.reg_x, c2.reg_y, LEN_ID_02);              /* y2 -> reg_temp_02 */
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* calculate (x2,-y2)=-[k]C2. Elliptic curve equation y^2=x^3+ax+b J=(Xj,Yj) K=-J=(Xj, -Yj)=(Xj, P-Yj) */
    *tmp++ = DRV_PKA_MOV_ins(rcurve.reg_p, reg_temp_03, LEN_ID_02, PKA_MOV_SRC_TYPE_REG);
    *tmp++ = DRV_PKA_SUB_ins(reg_temp_04, 0, reg_temp_03, 0, reg_temp_02, LEN_ID_02);         /*-y2 -> reg_temp_04 */

    /* calculate M=C1-[k]C2 */
    *tmp++ = DRV_PKA_PADDP_ins(c1.reg_x, c1.reg_y, 0, reg_temp_03, 0, 0, 0);            /* x1 -> reg_temp_03 */
    *tmp++ = DRV_PKA_PADD_ins(reg_temp_05, reg_temp_01, reg_temp_04, 0, 0, LEN_ID_02);  /* y1 -> reg_temp_05 */
    *tmp++ = DRV_PKA_JMP_ins(JMP_COND_INF_P, 0);

    /* save M */
    *tmp++ = drv_pka_store(reg_temp_03, sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->M.pubkey_x)) , rcurve.p_bytelen, LEN_ID_02);
    *tmp++ = drv_pka_store(reg_temp_05, sprd_pal_vaddr_to_paddr((uint8_t *)(dec_string->M.pubkey_y)) , rcurve.p_bytelen, LEN_ID_02);

    *tmp++ = DRV_PKA_END_ins;

    drv_pka_set_instruction(pka_data, (tmp-pka_data)*4);

    /* invalidate and clean cache */
    sprd_pal_clean_by_vaddr(cur_curve, sizeof(sprd_ecc_curve_t));
    sprd_pal_clean_by_vaddr(pka_data, PKA_DATA_LEN*4);
    sprd_pal_invalidate_by_vaddr(dec_string, sizeof(ecc_enc_dec_t));

    return ret;
}

sprd_crypto_err_t sprd_ecc_core_handler(sprd_ecc_data_t *data) {
    switch(data->req_id) {
        case SPRD_ECC_REQUEST_VERIFY:
            sprd_ecc_core_verify(&(data->curve), data->pka_data,
                    &(data->param.verify.pubkey), data->param.verify.hash_data,
                    data->param.verify.hash_bytelen, &(data->param.verify.rs),
                    data->param.verify.out_r);
            break;

        case SPRD_ECC_REQUEST_SIGN:
            sprd_ecc_core_sign(&(data->curve), data->pka_data,
                    &(data->param.sign.prikey), data->param.sign.hash_data,
                    data->param.sign.hash_bytelen, &(data->param.sign.rs));
            break;

        case SPRD_ECC_REQUEST_KEYGEN:
            sprd_ecc_core_keygen(&(data->curve), data->pka_data,
                    &(data->param.keygen.prikey), &(data->param.keygen.pubkey));
            break;

        case SPRD_ECC_REQUEST_DH:
            sprd_ecc_core_dh(&(data->curve), data->pka_data,
                    &(data->param.dh.prikeyA), &(data->param.dh.pubkey),
                    data->param.dh.shared_key);
            break;

        case SPRD_ECC_REQUEST_PUB_ENC:
            sprd_ecc_core_public_encrypt(&(data->curve), data->pka_data,
                    &(data->param.enc_dec));
            break;

        case SPRD_ECC_REQUEST_PRI_DEC:
            sprd_ecc_core_private_decrypt(&(data->curve), data->pka_data,
                    &(data->param.enc_dec));
            break;

        default:
            break;
    }

    return SPRD_ECC_OK;
}
