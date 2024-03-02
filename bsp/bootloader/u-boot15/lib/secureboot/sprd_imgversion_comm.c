/*
 * Copyright (C) 2017 spreadtrum.com
 */
#include <linux/compiler.h>
#include <linux/types.h>

#include <sprd_imgversion.h>

int __weak sprd_get_imgversion(int imgType, unsigned int* swVersion)
{
    return -1;
}

int __weak sprd_init_all_imgversion(uint8_t *rpmb_key)
{
    return -1;
}

