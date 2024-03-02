/*
 *MPFLAG_DEF_H - use field defined on partition of 'mp flag'
 *
 *  Copyright (C) 2021 Unisoc Communications Inc.
 *  History:
 *
 */
//20220531,Added by zhu_jun for Set ZeroFlag related property begin
#ifndef __MPFLAG_DEF_H__
#define __MPFLAG_DEF_H__

int check_efused(void);
int wt_check_mp_flags(void);
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start begin
int set_zeroflag(unsigned char zeroflag);
//20220531,Added by zhu_jun for suport fastboot command:fastboot oem factory_auth_start end
int wt_check_download_permission(void);
#endif /* __MPFLAG_DEF_H__ */
//20220531,Added by zhu_jun for Set ZeroFlag related property end

