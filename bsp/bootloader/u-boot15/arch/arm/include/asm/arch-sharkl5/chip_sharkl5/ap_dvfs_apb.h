/*
 * Copyright (C) 2019 Spreadtrum Communications Inc.
 *
 * This file is dual-licensed: you can use it either under the terms
 * of the GPL or the X11 license, at your option. Note that this dual
 * licensing only applies to this file, and not this project as a
 * whole.
 *
 * updated at 2019-03-19 14:05:48
 *
 */


#ifndef AP_DVFS_APB_H
#define AP_DVFS_APB_H

#define CTL_BASE_AP_DVFS_APB 0x71700000


#define REG_AP_DVFS_APB_AP_DVFS_HOLD_CTRL              ( CTL_BASE_AP_DVFS_APB + 0x0000 )
#define REG_AP_DVFS_APB_AP_DVFS_WAIT_WINDOW_CFG        ( CTL_BASE_AP_DVFS_APB + 0x0004 )
#define REG_AP_DVFS_APB_AP_DFS_EN_CTRL                 ( CTL_BASE_AP_DVFS_APB + 0x0008 )
#define REG_AP_DVFS_APB_AP_SW_TRIG_CTRL                ( CTL_BASE_AP_DVFS_APB + 0x000C )
#define REG_AP_DVFS_APB_AP_MIN_VOLTAGE_CFG             ( CTL_BASE_AP_DVFS_APB + 0x0010 )
#define REG_AP_DVFS_APB_AP_SW_DVFS_CTRL                ( CTL_BASE_AP_DVFS_APB + 0x0034 )
#define REG_AP_DVFS_APB_AP_FREQ_UPDATE_BYPASS          ( CTL_BASE_AP_DVFS_APB + 0x0038 )
#define REG_AP_DVFS_APB_CGM_AP_DVFS_CLK_GATE_CTRL      ( CTL_BASE_AP_DVFS_APB + 0x003C )
#define REG_AP_DVFS_APB_AP_DVFS_VOLTAGE_DBG            ( CTL_BASE_AP_DVFS_APB + 0x0040 )
#define REG_AP_DVFS_APB_AP_DVFS_CGM_CFG_DBG            ( CTL_BASE_AP_DVFS_APB + 0x004C )
#define REG_AP_DVFS_APB_AP_DVFS_STATE_DBG              ( CTL_BASE_AP_DVFS_APB + 0x0050 )
#define REG_AP_DVFS_APB_VSP_INDEX0_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x0074 )
#define REG_AP_DVFS_APB_VSP_INDEX1_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x0078 )
#define REG_AP_DVFS_APB_VSP_INDEX2_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x007C )
#define REG_AP_DVFS_APB_VSP_INDEX3_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x0080 )
#define REG_AP_DVFS_APB_VSP_INDEX4_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x0084 )
#define REG_AP_DVFS_APB_VSP_INDEX5_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x0088 )
#define REG_AP_DVFS_APB_VSP_INDEX6_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x008C )
#define REG_AP_DVFS_APB_VSP_INDEX7_MAP                 ( CTL_BASE_AP_DVFS_APB + 0x0090 )
#define REG_AP_DVFS_APB_DISPC_INDEX0_MAP               ( CTL_BASE_AP_DVFS_APB + 0x0094 )
#define REG_AP_DVFS_APB_DISPC_INDEX1_MAP               ( CTL_BASE_AP_DVFS_APB + 0x0098 )
#define REG_AP_DVFS_APB_DISPC_INDEX2_MAP               ( CTL_BASE_AP_DVFS_APB + 0x009C )
#define REG_AP_DVFS_APB_DISPC_INDEX3_MAP               ( CTL_BASE_AP_DVFS_APB + 0x0100 )
#define REG_AP_DVFS_APB_DISPC_INDEX4_MAP               ( CTL_BASE_AP_DVFS_APB + 0x0104 )
#define REG_AP_DVFS_APB_DISPC_INDEX5_MAP               ( CTL_BASE_AP_DVFS_APB + 0x0108 )
#define REG_AP_DVFS_APB_DISPC_INDEX6_MAP               ( CTL_BASE_AP_DVFS_APB + 0x010C )
#define REG_AP_DVFS_APB_DISPC_INDEX7_MAP               ( CTL_BASE_AP_DVFS_APB + 0x0110 )
#define REG_AP_DVFS_APB_VSP_DVFS_INDEX_CFG             ( CTL_BASE_AP_DVFS_APB + 0x011C )
#define REG_AP_DVFS_APB_VSP_DVFS_INDEX_IDLE_CFG        ( CTL_BASE_AP_DVFS_APB + 0x0120 )
#define REG_AP_DVFS_APB_DISPC_DVFS_INDEX_CFG           ( CTL_BASE_AP_DVFS_APB + 0x0124 )
#define REG_AP_DVFS_APB_DISPC_DVFS_INDEX_IDLE_CFG      ( CTL_BASE_AP_DVFS_APB + 0x0128 )
#define REG_AP_DVFS_APB_AP_FREQ_UPD_STATE              ( CTL_BASE_AP_DVFS_APB + 0x012C )
#define REG_AP_DVFS_APB_AP_GFREE_WAIT_DELAY_CFG        ( CTL_BASE_AP_DVFS_APB + 0x0130 )
#define REG_AP_DVFS_APB_AP_FREQ_UPD_TYPE_CFG           ( CTL_BASE_AP_DVFS_APB + 0x0134 )
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG0      ( CTL_BASE_AP_DVFS_APB + 0x0138 )
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG1      ( CTL_BASE_AP_DVFS_APB + 0x013C )
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG2      ( CTL_BASE_AP_DVFS_APB + 0x0140 )
#define REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG3      ( CTL_BASE_AP_DVFS_APB + 0x0144 )

/* REG_AP_DVFS_APB_AP_DVFS_HOLD_CTRL */

#define BIT_AP_DVFS_APB_AP_DVFS_HOLD                  BIT(0)

/* REG_AP_DVFS_APB_AP_DVFS_WAIT_WINDOW_CFG */

#define BIT_AP_DVFS_APB_AP_DVFS_UP_WINDOW(x)          (((x) & 0x3FF) << 10)
#define BIT_AP_DVFS_APB_AP_DVFS_DOWN_WINDOW(x)        (((x) & 0x3FF))

/* REG_AP_DVFS_APB_AP_DFS_EN_CTRL */

#define BIT_AP_DVFS_APB_VSP_DFS_EN                    BIT(1)
#define BIT_AP_DVFS_APB_DISPC_DFS_EN                  BIT(0)

/* REG_AP_DVFS_APB_AP_SW_TRIG_CTRL */

#define BIT_AP_DVFS_APB_VSP_DFS_SW_TRIG               BIT(1)
#define BIT_AP_DVFS_APB_DISPC_DFS_SW_TRIG             BIT(0)

/* REG_AP_DVFS_APB_AP_MIN_VOLTAGE_CFG */

#define BIT_AP_DVFS_APB_AP_SYS_MIN_VOLTAGE(x)         (((x) & 0x7))

/* REG_AP_DVFS_APB_AP_SW_DVFS_CTRL */

#define BIT_AP_DVFS_APB_AP_DVFS_ACK                   BIT(8)
#define BIT_AP_DVFS_APB_AP_DVFS_VOLTAGE_SW(x)         (((x) & 0x7) << 4)
#define BIT_AP_DVFS_APB_AP_CURRENT_VOLTAGE_SW(x)      (((x) & 0x7) << 1)
#define BIT_AP_DVFS_APB_AP_DVFS_REQ_SW                BIT(0)

/* REG_AP_DVFS_APB_AP_FREQ_UPDATE_BYPASS */

#define BIT_AP_DVFS_APB_REG_VSP_FREQ_UPD_EN_BYP       BIT(1)
#define BIT_AP_DVFS_APB_REG_DISPC_FREQ_UPD_EN_BYP     BIT(0)

/* REG_AP_DVFS_APB_CGM_AP_DVFS_CLK_GATE_CTRL */

#define BIT_AP_DVFS_APB_CGM_AP_DVFS_FORCE_EN          BIT(1)
#define BIT_AP_DVFS_APB_CGM_AP_DVFS_AUTO_GATE_SEL     BIT(0)

/* REG_AP_DVFS_APB_AP_DVFS_VOLTAGE_DBG */

#define BIT_AP_DVFS_APB_AP_CURRENT_VOLTAGE(x)         (((x) & 0x7) << 12)
#define BIT_AP_DVFS_APB_VSP_VOLTAGE(x)                (((x) & 0x7) << 6)
#define BIT_AP_DVFS_APB_DISPC_VOLTAGE(x)              (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_AP_INTERNAL_VOTE_VOLTAGE(x)   (((x) & 0x7))

/* REG_AP_DVFS_APB_AP_DVFS_CGM_CFG_DBG */

#define BIT_AP_DVFS_APB_CGM_VSP_SEL_DVFS(x)           (((x) & 0x3) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_DVFS(x)         (((x) & 0x7))

/* REG_AP_DVFS_APB_AP_DVFS_STATE_DBG */

#define BIT_AP_DVFS_APB_AP_SYS_DVFS_BUSY              BIT(13)
#define BIT_AP_DVFS_APB_AP_DVFS_WINDOW_CNT(x)         (((x) & 0x3FF) << 3)
#define BIT_AP_DVFS_APB_AP_DVFS_STATE(x)              (((x) & 0x7))

/* REG_AP_DVFS_APB_VSP_INDEX0_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX0(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX0(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX1_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX1(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX1(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX2_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX2(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX2(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX3_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX3(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX3(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX4_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX4(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX4(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX5_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX5(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX5(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX6_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX6(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX6(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_VSP_INDEX7_MAP */

#define BIT_AP_DVFS_APB_VSP_VOL_INDEX7(x)             (((x) & 0x7) << 2)
#define BIT_AP_DVFS_APB_CGM_VSP_SEL_INDEX7(x)         (((x) & 0x3))

/* REG_AP_DVFS_APB_DISPC_INDEX0_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX0(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX0(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX1_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX1(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX1(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX2_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX2(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX2(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX3_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX3(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX3(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX4_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX4(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX4(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX5_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX5(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX5(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX6_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX6(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX6(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_INDEX7_MAP */

#define BIT_AP_DVFS_APB_DISPC_VOL_INDEX7(x)           (((x) & 0x7) << 3)
#define BIT_AP_DVFS_APB_CGM_DISPC_SEL_INDEX7(x)       (((x) & 0x7))

/* REG_AP_DVFS_APB_VSP_DVFS_INDEX_CFG */

#define BIT_AP_DVFS_APB_VSP_DVFS_INDEX(x)             (((x) & 0x7))

/* REG_AP_DVFS_APB_VSP_DVFS_INDEX_IDLE_CFG */

#define BIT_AP_DVFS_APB_VSP_DVFS_INDEX_IDLE(x)        (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_DVFS_INDEX_CFG */

#define BIT_AP_DVFS_APB_DISPC_DVFS_INDEX(x)           (((x) & 0x7))

/* REG_AP_DVFS_APB_DISPC_DVFS_INDEX_IDLE_CFG */

#define BIT_AP_DVFS_APB_DISPC_DVFS_INDEX_IDLE(x)      (((x) & 0x7))

/* REG_AP_DVFS_APB_AP_FREQ_UPD_STATE */

#define BIT_AP_DVFS_APB_DISPC_DVFS_FREQ_UPD_STATE(x)  (((x) & 0xF) << 8)
#define BIT_AP_DVFS_APB_VSP_DVFS_FREQ_UPD_STATE(x)    (((x) & 0xF) << 4)

/* REG_AP_DVFS_APB_AP_GFREE_WAIT_DELAY_CFG */

#define BIT_AP_DVFS_APB_DISPC_GFREE_WAIT_DELAY(x)     (((x) & 0x3FF) << 10)
#define BIT_AP_DVFS_APB_VSP_GFREE_WAIT_DELAY(x)       (((x) & 0x3FF))

/* REG_AP_DVFS_APB_AP_FREQ_UPD_TYPE_CFG */

#define BIT_AP_DVFS_APB_DISPC_FREQ_UPD_DELAY_EN       BIT(5)
#define BIT_AP_DVFS_APB_DISPC_FREQ_UPD_HDSK_EN        BIT(4)
#define BIT_AP_DVFS_APB_VSP_FREQ_UPD_DELAY_EN         BIT(3)
#define BIT_AP_DVFS_APB_VSP_FREQ_UPD_HDSK_EN          BIT(2)

/* REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG0 */

#define BIT_AP_DVFS_APB_DVFS_RES_REG0(x)              (((x) & 0xFFFFFFFF))

/* REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG1 */

#define BIT_AP_DVFS_APB_DVFS_RES_REG1(x)              (((x) & 0xFFFFFFFF))

/* REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG2 */

#define BIT_AP_DVFS_APB_DVFS_RES_REG2(x)              (((x) & 0xFFFFFFFF))

/* REG_AP_DVFS_APB_AP_DVFS_RESERVED_REG_CFG3 */

#define BIT_AP_DVFS_APB_DVFS_RES_REG3(x)              (((x) & 0xFFFFFFFF))


#endif /* AP_DVFS_APB_H */


