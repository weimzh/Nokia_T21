/*
 * Copyright (C) 2021 UNISOC Technologies Co.,Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __PIN_H__
#define __PIN_H__

typedef struct {
        uint32_t gpio_id;
        uint32_t pin_offset;
} gpio_pin_t;

#define CTL_MISC_PIN_BASE          (CTL_PIN_BASE + 0x400)
#define PIN_FUNC_MASK              (BIT(4)|BIT(5))

#define BIT_PIN_IE_OE_MASK          (BIT_0|BIT_1)
typedef enum {
                PIN_Z = 0,
                PIN_OE,
                PIN_IE,
} PIN_IE_OE;

#define BIT_PIN_WPDUS_MASK     (BIT_12|BIT_7|BIT_6|BIT_3|BIT_2)
typedef enum {
                PIN_NULL = 0,
                PIN_DOWN,
                PIN_UP_4_7K,
                PIN_UP_20K,
                PIN_UP_1_8K,
} PIN_PULL_DOWN;

int gpio_pin_set(unsigned int gpio_id, unsigned int ie_oe, unsigned int pull_down);

#endif
