/******************************************************************************
 ** File Name:      cp_mode.c                                                 *
 ** Author:         Andrew.Yang                                               *
 ** DATE:           31/03/2014                                                *
 ** Copyright:      2014 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:    This file defines the logic interfaces called during boot,*
 **                 including reset mode setting, initialization etc.
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 31/03/2014     Andrew           Create.                                   *
 ******************************************************************************/

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifndef _CP_BOOT_H_
#define  _CP_BOOT_H__


/**---------------------------------------------------------------------------*
 **                         Global variables                                  *
 **---------------------------------------------------------------------------*/

#define msleep(cnt) udelay(cnt*1000)
/**---------------------------------------------------------------------------*
 **                         Local variables                                   *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                     Local Function Prototypes                             *
 **---------------------------------------------------------------------------*/

/**---------------------------------------------------------------------------*
 **                         Function Prototypes                               *
 **---------------------------------------------------------------------------*/
/*****************************************************************************/
//  Description:    Sets the different kinds of reset modes, used in normal p-
//                  ower up mode, watchdog reset mode and calibration mode etc.
//  Author:         Andrew.Yang
//  Note:
/*****************************************************************************/

static u32 ps_loader[] = {
	0xe3a01000, 0xee061f12, 0xf57ff06f, 0xe3a01102,
	0xee061f11, 0xe3a01039, 0xee061f51, 0xe300110f,
	0xee061f91, 0xe3a01001, 0xee061f12, 0xf57ff06f,
	0xe3a01000, 0xee061f11, 0xe3a0103d, 0xee061f51,
	0xe3011101, 0xee061f91, 0xe3a01002, 0xee061f12,
	0xf57ff06f, 0xe3a01000, 0xee061f11, 0xe3a01017,
	0xee061f51, 0xe3a01f43, 0xee061f91, 0xee110f10,
	0xe3800001, 0xf57ff04f, 0xee010f10, 0xf57ff06f,
	0xe51ff004, 0x96000600
};

static u32 phy_loader[] = {
	0xe3a01000, 0xee061f12, 0xf57ff06f, 0xe3a01102,
	0xee061f11, 0xe3a0103B, 0xee061f51, 0xe300110f,
	0xee061f91, 0xe3a01001, 0xee061f12, 0xf57ff06f,
	0xe3a01000, 0xee061f11, 0xe3a0103d, 0xee061f51,
	0xe3011101, 0xee061f91, 0xe3a01002, 0xee061f12,
	0xf57ff06f, 0xe3a01000, 0xee061f11, 0xe3a01017,
	0xee061f51, 0xe3a01f43, 0xee061f91, 0xe3a01003,
	0xee061f12, 0xf57ff06f, 0xe3a01441, 0xee061f11,
	0xe3a01027, 0xee061f51, 0xe3a01f43, 0xee061f91,
	0xee110f10, 0xe3800001, 0xf57ff04f, 0xee010f10,
	0xf57ff06f, 0xe51ff004, 0x9a400600
};

#ifdef CONFIG_SP_DDR_BOOT
/* sp ddr bootcode*/
static u32 sp_loader[] = {
	0x00003800, 0x00000009,	0xf44f4818, 0xf44f2380,
	0xf04f06c0, 0x1d026800,	0x1440f44f, 0x5a0f44f,
	0x7e0f44f,  0x900f44f, 	0xc10f44f,  0x8024f8c0,
	0x12f8e882, 0xf8df6c02,	0xea42a038, 0x6402020a,
	0x527cea4f, 0x490b6582,	0xe04f101,  0x8024f8c1,
	0x12f8e88e, 0xea436c0b,	0x640b030a, 0xf240658a,
	0x60022202, 0x4804600a,	0x4687,     0x60600000,
	0x20000002, 0x60400000,	0x10040000
};
#endif

#ifdef CONFIG_CH_DDR_BOOT
/* ch ddr bootcode*/
static u32 ch_loader[] = {
	0x0002a000, 0x00000009,	0xf2404802, 0x600121e6,
	0x46874801, 0x62110060, 0x80040000
};
#endif

#ifdef CONFIG_MEM_LAYOUT_DECOUPLING
extern int load_cp_boot_code(void *loader);
#else
inline int load_cp_boot_code(void *loader)
{
	return -1;
}
#endif

#ifdef CONFIG_SP_DDR_BOOT
extern int load_sp_boot_code(void);
inline int get_sp_bootcode_size(void)
{
	return sizeof(sp_loader)/sizeof(u32);
}

inline void *get_sp_bootcode_buf(void)
{
	return &sp_loader[0];
}
#endif

#ifdef CONFIG_CH_DDR_BOOT
int load_ch_boot_code(void)
{
	memcpy(CH_IRAM_ADDR, &ch_loader[0], sizeof(ch_loader));
	return 0;
}
#endif

static inline void pscp_boot(void)
{
#ifndef CONFIG_MEM_LAYOUT_DECOUPLING
	u32 count = sizeof(ps_loader);
	memcpy((void*)PSCP_IRAM_ADDRESS, ps_loader, count);
#endif

	/*hold*/
	//*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_0)|= BIT_PMU_APB_PS_CP_SOFT_RST;   /*hold sys soft reset*/
	*((volatile u32*)REG_AON_APB_PSCP_SOFT_RST) |= BIT_AON_APB_PSCP_CR8_PS_CORE_SW_RST(3); /*hold core soft reset*/
	/*power on*/
	*((volatile u32*)REG_PMU_APB_PD_PS_CP_CFG_0) &= ~BIT_PMU_APB_PD_PS_CP_FORCE_SHUTDOWN;/* clear force shutdown */
	*((volatile u32*)REG_PMU_APB_PD_PS_CP_CFG_0) &= ~BIT_PMU_APB_PD_PS_CP_AUTO_SHUTDOWN_EN;/* clear auto shutdown */
	//*((volatile u32*)REG_PMU_APB_PD_PUB_CFG_0) &= ~BIT_PMU_APB_PD_PUB_FORCE_SHUTDOWN;/* clear pub force shutdown */
	//*((volatile u32*)REG_PMU_APB_PD_PUB_CFG_0) &= ~BIT_PMU_APB_PD_PUB_AUTO_SHUTDOWN_EN;/* clear pub auto shutdown */
	*((volatile u32*)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_PS_CP_FORCE_DEEP_SLEEP_REG;   /*clear force sleep */

	msleep(50);
	/*reset*/
	//*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_0) &= ~BIT_PMU_APB_PS_CP_SOFT_RST; /*clear sys soft reset*/
	*((volatile u32*)REG_AON_APB_PSCP_SOFT_RST) &= ~(BIT_AON_APB_PSCP_CR8_PS_CORE_SW_RST(3)); /*clear core soft reset*/
}

static inline void phycp_boot(void)
{
#ifndef CONFIG_MEM_LAYOUT_DECOUPLING
	u32 count = sizeof(phy_loader);
	memcpy((void*)PHYCP_IRAM_ADDRESS, phy_loader, count);
#endif

	/*hold*/
	//*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_0)|= BIT_PMU_APB_PHY_CP_SOFT_RST;   /*hold sys soft reset*/
	*((volatile u32*)REG_AON_APB_PHY_CR8_REG) |= BIT_AON_APB_PHY_CR8_CORE_SW_RST(3); /*hold core soft reset*/
	/*power on*/
	*((volatile u32*)REG_PMU_APB_PD_PHY_CP_CFG_0) &= ~BIT_PMU_APB_PD_PHY_CP_FORCE_SHUTDOWN;/* clear force shutdown */
	*((volatile u32*)REG_PMU_APB_PD_PHY_CP_CFG_0) &= ~BIT_PMU_APB_PD_PHY_CP_AUTO_SHUTDOWN_EN;/* clear auto shutdown */
	//*((volatile u32*)REG_PMU_APB_PD_CR8_PHY_TOP_CFG_0) &= ~BIT_PMU_APB_PD_CR8_PHY_TOP_FORCE_SHUTDOWN;/* clear top force shutdown */
	//*((volatile u32*)REG_PMU_APB_PD_CR8_PHY_TOP_CFG_0) &= ~BIT_PMU_APB_PD_CR8_PHY_TOP_AUTO_SHUTDOWN_EN;/* clear top auto shutdown */
	//*((volatile u32*)REG_PMU_APB_PD_PUB_CFG_0) &= ~BIT_PMU_APB_PD_PUB_FORCE_SHUTDOWN;/* clear pub force shutdown */
	//*((volatile u32*)REG_PMU_APB_PD_PUB_CFG_0) &= ~BIT_PMU_APB_PD_PUB_AUTO_SHUTDOWN_EN;/* clear pub auto shutdown */
	*((volatile u32*)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_PHY_CP_FORCE_DEEP_SLEEP_REG;   /*clear force sleep */

	msleep(50);
	/*reset*/
	//*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_0) &= ~BIT_PMU_APB_PHY_CP_SOFT_RST; /*clear sys soft reset*/
	*((volatile u32*)REG_AON_APB_PHY_CR8_REG) &= ~(BIT_AON_APB_PHY_CR8_CORE_SW_RST(3)); /*clear core soft reset*/
}

static inline void pubcp_boot_prepare(void)
{
	/*PHYCP boot prepare*/
	*((volatile u32*)REG_PMU_APB_PD_CR8_PHY_TOP_CFG_0) &= ~BIT_PMU_APB_PD_CR8_PHY_TOP_FORCE_SHUTDOWN;/* clear top force shutdown */
	*((volatile u32*)REG_PMU_APB_PD_CR8_PHY_TOP_CFG_0) &= ~BIT_PMU_APB_PD_CR8_PHY_TOP_AUTO_SHUTDOWN_EN;/* clear top auto shutdown */
}

static inline void pubcp_boot(void)
{
	pscp_boot();
	phycp_boot();
}

/*****************************************************************************/
//  Description:    Gets the current reset mode.
//  Author:         Andrew.Yang
//  Note:
/*****************************************************************************/
void pmic_arm7_RAM_active(void)
{
	*((volatile u32*)REG_AON_APB_SP_SYS_SOFT_RST) |= BIT_AON_APB_SP_CORE_SOFT_RST;
	*((volatile u32*)REG_AON_APB_CH_SYS_SOFT_RST) |= BIT_AON_APB_CH_CORE_SOFT_RST;
	msleep(50);
	*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_1) &= ~BIT_PMU_APB_SP_SOFT_RST;
	*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_1) &= ~BIT_PMU_APB_CH_SOFT_RST;
	*((volatile u32*)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_SP_FORCE_DEEP_SLEEP_REG;   /*clear sp force sleep */
	*((volatile u32*)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_CH_FORCE_DEEP_SLEEP_REG;   /*clear ch force sleep */
	msleep(50);
}


/*****************************************************************************/
//  Description:    Gets the current reset mode.
//  Author:         Andrew.Yang
//  Note:
/*****************************************************************************/
static inline void sp_boot(void)
{
	*((volatile u32*)REG_AON_APB_SP_SYS_SOFT_RST) &= ~(BIT_AON_APB_SP_CORE_SOFT_RST);   /* core release */
}

static inline void ch_boot(void)
{
#ifdef CONFIG_CH_DDR_BOOT
	load_ch_boot_code();
#endif
	*((volatile u32*)REG_AON_APB_CH_SYS_SOFT_RST) &= ~(BIT_AON_APB_CH_CORE_SOFT_RST);   /* core release */
}

static inline void audcp_boot(u32 boot_vector)
{
	*((volatile u32 *)REG_PMU_APB_SYS_SOFT_RST_0) |= BIT_PMU_APB_AUDIO_SOFT_RST;
	*((volatile u32 *)REG_PMU_APB_DM_SOFT_RST) |= BIT_PMU_APB_AUD_CEVA_SOFT_RST;
	*((volatile u32 *)REG_PMU_APB_SOFT_RST_SEL) |= BIT_PMU_APB_SOFT_RST_SEL(BIT(22));

	*((volatile u32 *)REG_PMU_APB_PD_AUDIO_CFG_0) &= ~BIT_PMU_APB_PD_AUDIO_AUTO_SHUTDOWN_EN;
	*((volatile u32 *)REG_PMU_APB_PD_AUDIO_CFG_0) &= ~BIT_PMU_APB_PD_AUDIO_FORCE_SHUTDOWN;
	*((volatile u32 *)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_AUDIO_FORCE_DEEP_SLEEP_REG;
	*((volatile u32 *)REG_PMU_APB_PD_AUD_CEVA_CFG_0) &= ~BIT_PMU_APB_PD_AUD_CEVA_AUTO_SHUTDOWN_EN;
	*((volatile u32 *)REG_PMU_APB_PD_AUD_CEVA_CFG_0) &= ~BIT_PMU_APB_PD_AUD_CEVA_FORCE_SHUTDOWN;

	*((volatile u32 *)REG_AON_APB_AUDCP_BOOT_PROT) &= ~BIT_AON_APB_AUDCP_REG_PROT_VAL(~0);
	*((volatile u32 *)REG_AON_APB_AUDCP_BOOT_PROT) |= BIT_AON_APB_AUDCP_REG_PROT_VAL(0x9620);
	*((volatile u32 *)REG_AON_APB_AUDCP_DSP_CTRL0) = BIT_AON_APB_AUDCP_DSP_BOOT_VECTOR(boot_vector);
	*((volatile u32 *)REG_AON_APB_AUDCP_DSP_CTRL1) |= BIT_AON_APB_AUDCP_DSP_BOOT;

	*((volatile u32 *)REG_PMU_APB_SYS_SOFT_RST_0) &= ~BIT_PMU_APB_AUDIO_SOFT_RST;
	*((volatile u32 *)REG_PMU_APB_DM_SOFT_RST) &= ~BIT_PMU_APB_AUD_CEVA_SOFT_RST;
	*((volatile u32 *)REG_PMU_APB_SOFT_RST_SEL) &= ~BIT_PMU_APB_SOFT_RST_SEL(BIT(22));
}

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#endif
