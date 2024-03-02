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

#define PUBCP_IRAM_ADDRESS 0x65003400

static u32 g_loader[] = {
	0xee110f10, 0xe3c00005, 0xe3c00a01, 0xf57ff04f,
	0xee010f10, 0xf57ff06f, 0xee110f30, 0xe3800802,
	0xe3800801, 0xe3c00902, 0xee010f30, 0xf57ff04f,
	0xe3a00000, 0xee070f15, 0xee0f0f15, 0xee060f12,
	0xf57ff06f, 0xe3a01102, 0xee061f11, 0xe3a0103d,
	0xee061f51, 0xe3a01fc2, 0xee061f91, 0xe3a01001,
	0xee061f12, 0xf57ff06f, 0xee060f11, 0xe3a0103d,
	0xee061f51, 0xe3a01e31, 0xee061f91, 0xe3a01002,
	0xee061f12, 0xf57ff06f, 0xee060f11, 0xe3a01017,
	0xee061f51, 0xe3a01fc2, 0xee061f91, 0xee110f30,
	0xe3c0090e, 0xee010f30, 0xee110f10, 0xe3800001,
	0xf57ff04f, 0xee010f10, 0xf57ff06f, 0xe51ff004,
	0x8b000600
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
	0x60022202, 0x4804600a,	0x4687,     0x61600000,
	0x20000002, 0x61400000,	0x10040000
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

static inline void pubcp_boot(void)
{
	u32 count = sizeof(g_loader);

	if(load_cp_boot_code((void*)PUBCP_IRAM_ADDRESS))
		memcpy((void*)PUBCP_IRAM_ADDRESS, g_loader, count);

	/*boot cr5 */
	*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_0)|= BIT_PMU_APB_PUBCP_SOFT_RST;   /* reset R5 */
	*((volatile u32*)REG_AON_APB_PCP_SOFT_RST) |= BIT_AON_APB_PUBCP_CR5_CORE_SOFT_RST; /*cr5 core soft reset*/
	/*power on*/
	*((volatile u32*)REG_PMU_APB_PD_PUBCP_CFG_0) &= ~BIT_PMU_APB_PD_PUBCP_FORCE_SHUTDOWN;/* clear R5 force shutdown */
	*((volatile u32*)REG_PMU_APB_PD_PUBCP_CFG_0) &= ~BIT_PMU_APB_PD_PUBCP_AUTO_SHUTDOWN_EN;/* clear R5 auto shutdown */
	*((volatile u32*)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_PUBCP_FORCE_DEEP_SLEEP_REG;   /*clear R5 force sleep */

	msleep(50);
	/*reset*/
	*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_0) &= ~BIT_PMU_APB_PUBCP_SOFT_RST; /* pubcp soft reset */
	*((volatile u32*)REG_AON_APB_PCP_SOFT_RST) &= ~BIT_AON_APB_PUBCP_CR5_CORE_SOFT_RST; /*cr5 core soft reset*/

}

/*****************************************************************************/
//  Description:    Gets the current reset mode.
//  Author:         Andrew.Yang
//  Note:
/*****************************************************************************/
void pmic_arm7_RAM_active(void)
{
	*((volatile u32*)REG_AON_APB_CM4_SYS_SOFT_RST) |= BIT_AON_APB_CM4_CORE_SOFT_RST;
	msleep(50);
	*((volatile u32*)REG_PMU_APB_SYS_SOFT_RST_1) &= ~BIT_PMU_APB_SP_SOFT_RST;
	*((volatile u32*)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &= ~BIT_PMU_APB_SP_FORCE_DEEP_SLEEP_REG;   /*clear sp force sleep */
	*((volatile u32*)REG_AON_APB_CM4_SYS_SOFT_RST) &= ~BIT_AON_APB_CM4_SYS_SOFT_RST;
	msleep(50);
}

/*****************************************************************************/
//  Description:    Gets the current reset mode.
//  Author:         Andrew.Yang
//  Note:
/*****************************************************************************/
static inline void sp_boot(void)
{
	#ifdef CONFIG_SP_DDR_BOOT
	load_sp_boot_code();
	#endif
	*((volatile u32*)REG_AON_APB_CM4_SYS_SOFT_RST) &= ~BIT_AON_APB_CM4_CORE_SOFT_RST;   /* core release */
}

static inline void audcp_boot(u32 boot_vector)
{
	/* 6402_0000 PMU reset */
	/* 0x0B98 bit[22]=1 */
	*((volatile u32 *)REG_PMU_APB_SYS_SOFT_RST_0) |=
                BIT_PMU_APB_AUDCP_SOFT_RST;

	/* 0x0B88 bit[0]=1 */
	*((volatile u32 *)REG_PMU_APB_DM_SOFT_RST) |=
                BIT_PMU_APB_AUDCP_AUDDSP_SOFT_RST;

	/* 0x0BA8 bit[22]=0 */
	*((volatile u32 *)REG_PMU_APB_SOFT_RST_SEL_0) &=
               ~BIT_PMU_APB_SOFT_RST_SEL(BIT(22));


	/* 6402_0000 PMU */
	/* 0x03D0 bit[24,25]=0 */
	*((volatile u32 *)REG_PMU_APB_PD_AUDCP_CFG_0) &=
               ~(BIT_PMU_APB_PD_AUDCP_FORCE_SHUTDOWN|BIT_PMU_APB_PD_AUDCP_AUTO_SHUTDOWN_EN);

	/* 0x0818 bit[3]=0 */
	*((volatile u32 *)REG_PMU_APB_FORCE_DEEP_SLEEP_CFG_0) &=
                ~BIT_PMU_APB_AUDCP_FORCE_DEEP_SLEEP_REG;

	/* 0x03D4 bit[24,25]=0 */
	*((volatile u32 *)REG_PMU_APB_PD_AUDCP_AUDDSP_CFG_0) &=
                ~(BIT_PMU_APB_PD_AUDCP_AUDDSP_FORCE_SHUTDOWN|BIT_PMU_APB_PD_AUDCP_AUDDSP_AUTO_SHUTDOWN_EN);


	/* 6400_0000 AON */
	/* 0x0078 0x9620 */
	*((volatile u32 *)REG_AON_APB_AUDCP_BOOT_PROT) &=
                ~BIT_AON_APB_AUDCP_REG_PROT_VAL(~0);
        *((volatile u32 *)REG_AON_APB_AUDCP_BOOT_PROT) |=
                BIT_AON_APB_AUDCP_REG_PROT_VAL(0x9620);

	/* 0x0140 boot_vector */
	*((volatile u32 *)REG_AON_APB_AUDCP_DSP_CTRL0) =
                BIT_AON_APB_AUDCP_DSP_BOOT_VECTOR(boot_vector);

	/* 0x0144 bit[0]=1 */
	*((volatile u32 *)REG_AON_APB_AUDCP_DSP_CTRL1) |=
                BIT_AON_APB_AUDCP_DSP_BOOT;


	/* 6402_0000 PMU */
	/* 0x0B98 bit[22]=0 */
	*((volatile u32 *)REG_PMU_APB_SYS_SOFT_RST_0) &=
                ~BIT_PMU_APB_AUDCP_SOFT_RST;

	/* 0x0B88 bit[0]=0 */
	*((volatile u32 *)REG_PMU_APB_DM_SOFT_RST) &=
                ~BIT_PMU_APB_AUDCP_AUDDSP_SOFT_RST;

	/* 0x0BA8 bit[22]=0 */
	*((volatile u32 *)REG_PMU_APB_SOFT_RST_SEL_0) &=
                ~BIT_PMU_APB_SOFT_RST_SEL(BIT(22));
}
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#endif
