/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <trusty/smc.h>

#ifndef __asmeq
#define __asmeq(x, y) ".ifnc " x "," y " ; .err ; .endif\n\t"
#endif

//#ifdef NS_ARCH_ARM64
#if CONFIG_ARM64
#define SMC_ARG0 "x0"
#define SMC_ARG1 "x1"
#define SMC_ARG2 "x2"
#define SMC_ARG3 "x3"
#define SMC_ARCH_EXTENSION ""
#define SMC_REGISTERS_TRASHED                                              \
    "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", \
            "x15", "x16", "x17"
#else
#define SMC_ARG0 "r0"
#define SMC_ARG1 "r1"
#define SMC_ARG2 "r2"
#define SMC_ARG3 "r3"
#define SMC_ARCH_EXTENSION ".arch_extension sec\n"
#define SMC_REGISTERS_TRASHED "ip"
#endif

/*
 * Execute SMC call into trusty
 */
unsigned long smc(unsigned long r0,
                  unsigned long r1,
                  unsigned long r2,
                  unsigned long r3) {
    register unsigned long _r0 __asm__(SMC_ARG0) = r0;
    register unsigned long _r1 __asm__(SMC_ARG1) = r1;
    register unsigned long _r2 __asm__(SMC_ARG2) = r2;
    register unsigned long _r3 __asm__(SMC_ARG3) = r3;

    /* clang-format off */
    __asm__ volatile(
        __asmeq("%0", SMC_ARG0)
        __asmeq("%1", SMC_ARG1)
        __asmeq("%2", SMC_ARG2)
        __asmeq("%3", SMC_ARG3)
        __asmeq("%4", SMC_ARG0)
        __asmeq("%5", SMC_ARG1)
        __asmeq("%6", SMC_ARG2)
        __asmeq("%7", SMC_ARG3)
        SMC_ARCH_EXTENSION
        "smc    #0" /* switch to secure world */
        : "=r" (_r0), "=r" (_r1), "=r" (_r2), "=r" (_r3)
        : "r" (_r0), "r" (_r1), "r" (_r2), "r" (_r3)
        : SMC_REGISTERS_TRASHED);
    /* clang-format on */
    return _r0;
}
