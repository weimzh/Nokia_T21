/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 */

#include <linux/err.h>
#include <asm-generic/errno.h>
#include <asm/types.h>
#include <asm/arch/sprd_reg.h>
#include <common.h>
#include <dm/device.h>
#include <dm/read.h>
#include <dm/uclass.h>
#include <dm/uclass-id.h>
#include <command.h>
#include <sprd_adc.h>
#define ADC_MESURE_NUMBER			15
#define ADC_CHANNEL_FOR_NV			3
#if defined(CONFIG_ADIE_UMP9620)
	#define BIG_SCALE_CH				11
#else
	#define BIG_SCALE_CH				5
#endif
#define BIG_SCALE_VOL_RATIO			3
#define SMALL_SCALE_CH				1
#define SMALL_SCALE_VOL_RATIO		0
#define ISEN						2000
#define BOARD_ISEN_SCALE_RATIO		0

static int adc_sprd_get_board_id_vol_test(int argc, char *const argv[])
{
	int board_adc_value=0;
	int board_id_vol= 0;

	board_adc_value = pmic_adc_get_value_by_isen(ADC_CHANNEL_FOR_NV,BOARD_ISEN_SCALE_RATIO,ADC_MESURE_NUMBER,ISEN);
	board_id_vol = sprd_chan_small_adc_to_vol(ADC_CHANNEL_FOR_NV, 0 , 0 ,board_adc_value);
	if (board_id_vol > 0 && board_id_vol < 1200) {
		debugf("pass! current mode board id vol: %dmv\n", board_id_vol);
	}else{
		errorf("fail! current mode board id vol(%dmv) is out of ranger [0~1200]mv.\n", board_id_vol);
		return -1;
	}
	return 0;
}

static int adc_sprd_small_scale_adc_to_vol_test(int argc, char *const argv[])
{
	int small_scale_vol = 0;
	int mux = 0;

	small_scale_vol = sprd_chan_adc_to_vol(SMALL_SCALE_CH, SMALL_SCALE_VOL_RATIO, mux, ADC_SMALL_SCALE);
	if (small_scale_vol > 0 && small_scale_vol < 1200){
		debugf("pass! small scale vol: %dmv\n", small_scale_vol);
	}else{
		errorf("fail! small scale vol(%dmv) is out of ranger [0~1200]mv.\n", small_scale_vol);
		return -1;
	}
	return 0;
}

static int adc_sprd_big_scale_adc_to_vol_test(int argc, char *const argv[])
{
	int big_scale_vol = 0;
	int mux = 0;

	big_scale_vol = sprd_chan_adc_to_vol(BIG_SCALE_CH, BIG_SCALE_VOL_RATIO, mux, ADC_BIG_SCALE);
	if (big_scale_vol > 3000 && big_scale_vol < 4500){
		debugf("pass! big scale vol: %dmv\n", big_scale_vol);
	}else{
		errorf("fail! big scale vol(%dmv) is out of ranger [3000~4500]mv.\n", big_scale_vol);
		return -1;
	}
	return 0;
}

U_BOOT_IT_TEST_REGISTER(adc_tc1000_sprd_get_board_id_vol_test, adc_sprd_get_board_id_vol_test, "this function is current mode board id vol test");
U_BOOT_IT_TEST_REGISTER(adc_tc1001_sprd_small_scale_adc_to_vol_test, adc_sprd_small_scale_adc_to_vol_test, "this function is sprd small scale adc to vol test");
U_BOOT_IT_TEST_REGISTER(adc_tc1002_sprd_big_scale_adc_to_vol_test, adc_sprd_big_scale_adc_to_vol_test, "this function is sprd big scale adc to vol test");
