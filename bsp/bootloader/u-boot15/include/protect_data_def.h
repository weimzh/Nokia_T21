//20220525,Added by zhu_jun for serial number related properties begin
/*
 *PROTECT_DATA_DEF_H - use field defined on partition of 'protect_data'
 *
 *  Copyright (C) 2021 Unisoc Communications Inc.
 *  History:
 *      Tue Feb 9 10:10:36 2021 zhenxiong.lai
 *      Description
 *        
 */

#ifndef __PROTECT_DATA_DEF_H__
#define __PROTECT_DATA_DEF_H__


/*---------------WT  Protect_data -----------------*/
#define READ_Protect_data_LEN_AUTO -1

/*0~31	PHONE SN     */
#define PHONE_SN_OFFSET	0
#define PHONE_SN_LEN	32

/*32~43	SKUID	NOKIA项目例如："600EEA", "600WW"*/
#define SKUID_OFFSET	32
#define SKUID_LEN		12

/*44~44	Color ID   */
#define Color_ID_OFFSET	44
#define Color_ID_LEN	1

/*45~56	TA Code   */
#define TA_Code_OFFSET	45
#define TA_Code_LEN		12

//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) begin
#define HEF_OFFSET	825
#define HEF_LEN		1
//20220602,Added by zhu_jun for VSI-680 HMD Exception Flag (HEF) end

//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 begin
#define    WT_IMEI1_OFFSET   (57+256*0)
#define    WT_IMEI1_LEN   256
#define    WT_IMEI2_OFFSET   (57+256*1)
#define    WT_IMEI2_LEN   256
//20220531,Added by zhu_jun for suport fastboot command: fastboot getvar IMEI0/IMEI1 end

int read_protect_data_ex(const char *type,unsigned char *buf,int len);
int write_protect_data_ex(const char *type,unsigned char *buf);

#endif /* __PROTECT_DATA_DEF_H__ */
//20220525,Added by zhu_jun for serial number related properties end
