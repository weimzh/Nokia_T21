//20220531,Added by zhu_jun for Set ZeroFlag related property begin
#include <common.h>
#include <command.h>
#include <linux/types.h>
#include <mpflag_def.h>
#include <miscdata_def.h>
#include <chipram_env.h>
#include <boot_mode.h>

//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
int download_mode_flag = -1;
int s_efused = -1;
extern char *get_product_sn(void);
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end

//added by dongming, AGT-685, 20221011
int s_edl_repair_signature_flag = -1;
//end added by dongming, AGT-685

extern int get_lcs(uint32_t *p_lcs);

/*
*   mp flags
*   1.Efused
*   2.WT_FINAL_RELEASE
*   3.ZeroFlag != 0x55
*/

int check_efused(void)
{
	boot_mode_t bmode;
	int ret = -1;
    unsigned int t_lcs __attribute__((aligned(4096)));
    unsigned int lcs = 0;
	
	if ( s_efused != -1 ) 
	{
		printf("%s: s_efused=%d\n", __func__, s_efused);
	    return s_efused;
	}

    bmode = get_boot_role();

    if (BOOTLOADER_MODE_DOWNLOAD == bmode) {
            if (sprd_get_lcs(&lcs) || (5 != lcs)) {
                    debugf("secboot was disabled(lcs: %d)\n", lcs);
					s_efused = 0;
                    return 0;
            }
            debugf("secboot was enabled\n");
			s_efused = 1;
            return 1;
    } else if (BOOTLOADER_MODE_LOAD == bmode) {
            if (get_lcs(&t_lcs) || (5 != t_lcs)) {
                    debugf("secboot was disabled(t_lcs: %d)\n", t_lcs);
					s_efused = 0;
                    return 0;
            }
            debugf("secboot was enabled\n");
			s_efused = 1;
            return 1;
    }
	s_efused = 0;
	return 0;
}

int get_download_auth_flag(void)
{
//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication begin
#ifndef WT_COMPILE_FACTORY_VERSION
	char product_sn_token_str[64] __attribute__ ((aligned(4096)));
	unsigned char download_auth_buf[512] = {0};
	int ret = -1;
	int efused = -1;
	
	if ( download_mode_flag != -1 )
	{
	    printf("%s: download_mode_flag=%d\n", __func__, download_mode_flag);
	    return download_mode_flag;
	}
	
	efused = check_efused();
	
	download_mode_flag = 0;
	
	if (efused) {
		printf("%s:The device is efuse, need download auth\n", __FUNCTION__);
		if (oem_repair_read_mmc_ex("download", download_auth_buf, HMD_DOWNLOAD_MODE_SIGNATURE_LEN) < 0) {
			printf("%s:read the download data failed, pls need flash it first\n", __FUNCTION__);
			//dl_send_ack(BSL_CHECK_DATA_ERROR);
			//printf("%s:The device is reset to normal ...\n", __FUNCTION__);
			//reset_to_normal(CMD_NORMAL_MODE);
			return download_mode_flag;
		}

		memset(product_sn_token_str, 0, sizeof(product_sn_token_str));
		strcpy(product_sn_token_str, get_product_sn());
		ret = rsa_decrypt_data("download", download_auth_buf, product_sn_token_str);
		if(ret == 0){
			printf("%s:download decrypt failed,get_product_sn=%s\n", __FUNCTION__,get_product_sn());
			//dl_send_ack(BSL_CHECK_DATA_ERROR);
			//printf("%s:The device is reset to normal ...\n", __FUNCTION__);
			//reset_to_normal(CMD_NORMAL_MODE);
			return download_mode_flag;
		} else {
			download_mode_flag = 1;
			printf("%s:download decrypt sucessfully\n", __FUNCTION__);
		}
	}
	//20220915, Add zhu_jun for VSI-681 SoC Download Mode Authentication end
	return download_mode_flag;
#else
	download_mode_flag = 0;
	return download_mode_flag;
#endif
}

// added by dongming, AGT-685, 20221011
int check_edl_with_repair_signature(void)
{
#ifndef WT_COMPILE_FACTORY_VERSION
#ifdef WT_FINAL_RELEASE
	char product_sn_token_str[64] __attribute__ ((aligned(4096)));
	unsigned char repair_signature_auth_buf[512] = {0};
	int ret = -1;
	int efused = -1;
	
	if ( s_edl_repair_signature_flag != -1 )
	{
	    printf("%s: s_edl_repair_signature_flag=%d\n", __func__, s_edl_repair_signature_flag);
	    return s_edl_repair_signature_flag;
	}
	
	s_edl_repair_signature_flag = 0;
	
	efused = check_efused();
	
	if (efused) {
		printf("%s:The device is efuse, need check edl repair auth\n", __FUNCTION__);
		if (oem_repair_read_mmc_ex(HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE, repair_signature_auth_buf, HMD_EDL_MODE_SIGNATURE_LEN) < 0) {
			printf("%s:read the repair signature data failed, pls need flash it first\n", __FUNCTION__);
			return 0;
		}

		memset(product_sn_token_str, 0, sizeof(product_sn_token_str));
		strcpy(product_sn_token_str, get_product_sn());
		ret = rsa_decrypt_data(HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE, repair_signature_auth_buf, product_sn_token_str);
		if(ret == 0){
			printf("%s:%s decrypt failed,get_product_sn=%s\n", __FUNCTION__,HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE, get_product_sn());
			return 0;
		} else {
			s_edl_repair_signature_flag = 1;
			printf("%s:%s decrypt sucessfully\n", __FUNCTION__, HMD_EDL_MODE_REPAIR_SIGNATURE_TYPE);
			return 1;
		}
	}
	s_edl_repair_signature_flag = 1;
	return 1;
#else
	s_edl_repair_signature_flag = 1;
	return 1;
#endif
#else
	s_edl_repair_signature_flag = 1;
	return 1;
#endif
}
//end added by dongming, AGT-685

int get_zeroflag(unsigned char* zeroflag)
{
    int ret = oem_repair_read_mmc_ex("zeroflag", zeroflag, 1);
    return ret;
}

int set_zeroflag(unsigned char zeroflag)
{
    unsigned char buf[2];
    buf[0] = zeroflag;
    buf[1] = 0;
    int ret = oem_repair_write_mmc_ex("zeroflag", buf);
    return ret;
}

#ifdef WT_FINAL_RELEASE
int wt_check_mp_flags(void)
{
    u8 zeroflag;
    int efused = check_efused();
    int zeroflag_ret = get_zeroflag(&zeroflag);
    debugf("efused=%d zeroflag=0x%x\n", efused, zeroflag);

    if((efused >= 0) && (zeroflag_ret >= 0)) {
        if(efused && (zeroflag != 0x55)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        debug("check_efused fail\n");
        return 1;
    }
}
#else
int wt_check_mp_flags(void)
{
    return 0;
}
#endif

int wt_check_download_flag(void)
{
    u8 zeroflag;
    int efused = check_efused();
	int download_flag = get_download_auth_flag();
    //int zeroflag_ret = get_zeroflag(&zeroflag);
	
    printf("%s: efused=%d, download_flag=%d\n", __func__, efused, download_flag);

    if( efused > 0 ) {
        return download_flag > 0 ? 1 : 0;
    } else {
        debug("no efused\n");
        return 1;
    }
}

int wt_check_fastboot_edl(void)
{
    int efused = check_efused();
    int edl = check_fastboot_edl();

    printf("%s: efused=%d, edl=%d\n", __func__, efused, edl);
    if (efused > 0) {
	    return edl > 0 ? 1 : 0;
    }

    return 1;
}

void wt_clear_edl()
{
#ifndef WT_FINAL_RELEASE
	printf("%s: not WT_FINAL_RELEASE!!!\n", __func__);
	return;
#endif

    int efused = check_efused();
    printf("%s: efused=%d\n", __func__, efused);
    if ( efused > 0 ) {
      	if ( check_fastboot_edl() ) {
            printf("%s: to clear_fastboot_edl\n", __func__);
            clear_fastboot_edl();
			//added by dongming, AGT-658, 20221011
			if (common_raw_erase("miscdata", HMD_EDL_MODE_SIGNATURE_LEN, HMD_EDL_MODE_SIGNATURE_OFFSET)) {
				errorf("erase the repair auth data fail\n");
			}
			//end added by dongming, AGT-658
        }
    }
}

int wt_check_download_permission(void)
{
#ifdef WT_COMPILE_FACTORY_VERSION
    printf("%s: Allow download, ATO version\n", __func__);
    return 1;
#endif
#ifndef WT_FINAL_RELEASE
	printf("%s: not WT_FINAL_RELEASE!!!\n", __func__);
	return 1;
#endif
    int idownload = 0, iedl = 0, icheck_repair_signature = 0;
    int hardware_level = sprd_get_hardwareid_info();
    
    idownload = wt_check_download_flag();
    iedl = wt_check_fastboot_edl();
	icheck_repair_signature = check_edl_with_repair_signature();

    printf("%s: hardware_level=%d, idownload=%d, iedl=%d, icheck_repair_signature=%d\n", __func__, hardware_level, idownload, iedl, icheck_repair_signature);
 
	return ( idownload > 0 || (iedl > 0 && icheck_repair_signature > 0) ) ? 1 : 0;
}
//20220531,Added by zhu_jun for Set ZeroFlag related property end
