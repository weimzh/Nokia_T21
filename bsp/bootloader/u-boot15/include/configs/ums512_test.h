/*
 * Configuration for Versatile Express. Parts were derived from other ARM
 *   configurations.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define SPRD_DEBUG_LEVEL		2

#define CONFIG_KERNEL_BOOT_CP
#define CONFIG_SP_DDR_BOOT
#define CONFIG_AUDCP_BOOT_VECTOR 0x44800040
#define CONFIG_MEM_LAYOUT_DECOUPLING

/*sharklj1 fpga/zebu debug*/
#define BOOTIMG_ADR	0x8D000000

/*build aarch64 u-boot.elf*/
#define CONFIG_REMAKE_ELF
#define CONFIG_SPRD_UID
#define CONFIG_SYS_NO_FLASH
#define CONFIG_SPL_BAK
#define CONFIG_MISC_INIT_R                     /* call misc_init_r()	      */
#define CONFIG_BOARD_LATE_INIT         /* call board_late_init() */
//#define CONFIG_SUPPORT_RAW_INITRD

/*the SPL is erased, the romcode will enter the download process.*/
#define CONFIG_ERASE_SPL_AUTO_DOWNLOAD

/* Cache Definitions */
//#define CONFIG_SYS_DCACHE_OFF
//#define CONFIG_SYS_ICACHE_OFF

#define CONFIG_IDENT_STRING		"SHARKL5PRO"

#define CONFIG_SYS_INIT_SP_ADDR     \
	(CONFIG_SYS_SDRAM_END - 0x10000 - GENERATED_GBL_DATA_SIZE)

/* Flat Device Tree Definitions */


/* SMP Spin Table Definitions */
#define CPU_RELEASE_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x7fff0)

/* get soc serial number */
#define CONFIG_GET_CPU_SERIAL_NUMBER

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY		(0x1800000)	/* 24MHz */

/* Generic Interrupt Controller Definitions */
#define CONFIG_GICV2
#define GICD_BASE			(0x12001000)
#define GICC_BASE			(0x12002000)

#define CONFIG_SYS_MEMTEST_START	PHYS_SDRAM_1
#define CONFIG_SYS_MEMTEST_END		(PHYS_SDRAM_1 + 0x0800000)

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 7 * 1024 * 1024)

/* eMMC and DDR check type*/
#define CONFIG_EMMC_DDR_CHECK_TYPE

/*timer*/
#define CONFIG_SYS_HZ			1000
#define CONFIG_SPRD_TIMER_CLK		1000 /*32768*/



 /* SPREADTRUM BIGPHONE board - SoC Configuration */
/* Note: SOC macro should be named as CONFIG_SOC_ProjectName */
#define CONFIG_SOC_SHARKL5PRO
#define CONFIG_ADIE_SC2730

/* SharkL5Pro Lowpower feature support start */
#define CONFIG_SUPPORT_LOWPOWER

// LPC Enable Macro
#define CONFIG_AON_LPC_EN
#define CONFIG_AP_LPC_EN
#define CONFIG_CLOCK_AUTO_GATE_EN

// DCDC Drop Enable Macro
#define CONFIG_DCDCCORE_DEEP_DROP_EN	1
#define CONFIG_DCDCCORE_DEEP_DROP_VOL 	600 //mV

#define CONFIG_DCDCSRAM_DEEP_DROP_EN	1
#define CONFIG_DCDCSRAM_DEEP_DROP_VOL 	700 //mV

#define CONFIG_DCDCMODEM_DEEP_DROP_EN	1
#define CONFIG_DCDCMODEM_DEEP_DROP_VOL 	700 //mV

#define CONFIG_DCDCGPU_DEEP_DROP_EN	1
#define CONFIG_DCDCGPU_DEEP_DROP_VOL 	550 //mV

#define CONFIG_DEEP_DROP_EN		CONFIG_DCDCCORE_DEEP_DROP_EN || CONFIG_DCDCSRAM_DEEP_DROP_EN || CONFIG_DCDCMODEM_DEEP_DROP_EN || CONFIG_DCDCGPU_DEEP_DROP_EN
/* SharkL5Pro Lowpower feature support end */

#define CONFIG_DTS_MEM_LAYOUT

#define CONFIG_PRE_CONSOLE_BUFFER
#define CONFIG_PRE_CON_BUF_SZ		0x2000
#define CONFIG_PRE_CON_BUF_ADDR		0x92300000

/* SharkL5Pro cpuinfo_hwfeature enable */

#define CONFIG_CPUINFO_HWFEATURE_ENABLE

/* SPRD Serial Configuration */
#define CONFIG_SPRD_UART		1
#define CONFIG_SYS_SC8800X_UART1	1
#define CONFIG_CONS_INDEX	2	/* use UART0 for console */
#define CONFIG_SPRD_UART_PORTS	{ (void *) (CONFIG_SYS_SERIAL0), (void *) (CONFIG_SYS_SERIAL1) }
#define CONFIG_SYS_SERIAL0		0x70000000
#define CONFIG_SYS_SERIAL1		0x70100000

/* Default baud rate */
#define CONFIG_BAUDRATE		115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*
 * log config
 */
#define CONFIG_SPRD_LOG
#define CONFIG_LOG_2_EMMC

/*sprd watchdog*/
#define CONFIG_HW_WATCHDOG
#define CONFIG_SPRD_WATCHDOG

/*sprd rtc*/
#define CONFIG_RTC_SPRD

/*sprd normal efuse*/
#define CONFIG_SPRD_AP_NORMAL_EFUSE
/*sprd adc*/
#define CONFIG_SPRD_ADC

/*sprd adi*/
#define CONFIG_SPRD_ADI
#define ADI_R3P0_VER
/*sprd gpio*/
#define CONFIG_DM_GPIO
#define CONFIG_SPRD_GPIO
#define CONFIG_SPRD_EIC
#define CONFIG_SPRD_PMIC_EIC
#define CONFIG_SPRD_EIC_EXT1
#define CONFIG_POWERKEY_DEFAULT_HIGH

/*sprd clk*/
#define CONFIG_COMMON_CLK
#define CONFIG_SPRD_CLK
#define CONFIG_SPRD_CLK_SHARKL5PRO
/* Chip Driver Macro Definitions End*/

/* Command line configuration */
#define CONFIG_MENU
/*#define CONFIG_MENU_SHOW*/
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_BDI
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PXE
#define CONFIG_CMD_ENV
#define CONFIG_CMD_FLASH
#define CONFIG_CMD_IMI
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_MII
//#define CONFIG_CMD_NET
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_RUN
//#define CONFIG_CMD_BOOTD
#define CONFIG_CMD_ECHO
#define CONFIG_CMD_SOURCE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION


/* Miscellaneous configurable options */
#define CONFIG_SYS_LOAD_ADDR		(PHYS_SDRAM_1 + 0x10000000)

/* Physical Memory Map */
#define  CONFIG_DUAL_DDR

#define PHYS_SDRAM_1			0x80000000	/* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE		0x20000000	/* 512 MB */

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_SDRAM_SIZE     PHYS_SDRAM_1_SIZE
#define CONFIG_SYS_SDRAM_END (CONFIG_SYS_SDRAM_BASE + CONFIG_SYS_SDRAM_SIZE)
#define CONFIG_DDR_AUTO_DETECT

#ifndef CONFIG_DUAL_DDR
#define CONFIG_NR_DRAM_BANKS		1
#else
#define CONFIG_NR_DRAM_BANKS		2
#define PHYS_SDRAM_2			0x180000000	/* SDRAM Bank #1 */
#define PHYS_SDRAM_2_SIZE		0x20000000	/* 256 MB */
#define CONFIG_SYS_SDRAM_BASE2    PHYS_SDRAM_2
#define CONFIG_SYS_SDRAM_SIZE2     PHYS_SDRAM_2_SIZE
#define CONFIG_SYS_SDRAM_END2 (CONFIG_SYS_SDRAM_BASE2 + CONFIG_SYS_SDRAM_SIZE2)
#endif

#ifdef DEBUG
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_AUTOBOOT_KEYED 1
#define CONFIG_AUTOBOOT_PROMPT "Press q to abort autoboot in %d seconds"
#define CONFIG_AUTOBOOT_STOP_STR "q"
#endif

/* Initial environment variables */
#define CONFIG_BOOTCOMMAND			"cboot normal"
#define CONFIG_BOOTDELAY		0
#define	CONFIG_EXTRA_ENV_SETTINGS				"mtdparts=" MTDPARTS_DEFAULT "\0"


/* Do not preserve environment */
#define CONFIG_ENV_IS_NOWHERE		1
#define CONFIG_ENV_SIZE			0x1000

/* Monitor Command Prompt */
#define CONFIG_SYS_CBSIZE		1024	/* Console I/O Buffer Size */
#define CONFIG_SYS_PROMPT		"sharkl5pro# "
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + \
									sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING		1
#define CONFIG_SYS_MAXARGS		64	/* max command args */


#define	CONFIG_PREBOOT		"role"


#define MEM_INIT_PARA "mem=512M"
#define MTDIDS_DEFAULT "nand0=sprd-nand"
#define MTDPARTS_DEFAULT "mtdparts=sprd-nand:256k(spl),768k(2ndbl),512k(kpanic),-(ubipac)"
#define CONFIG_BOOTARGS MEM_INIT_PARA" loglevel=7 console=ttyS0,115200n8 init=/init " MTDPARTS_DEFAULT

/*auto boot with normal mode*/
//#define CONFIG_AUTOBOOT

/*boot with modem*/
#define BOOT_NATIVE_LINUX_MODEM  1

//#define CONFIG_MINI_TRUSTZONE

#define CONFIG_SUPPORT_LTE
#define CONFIG_ADVANCED_LTE

#define CONFIG_SUPPORT_AGDSP

//#define CONFIG_SUPPORT_WLTE
//#define CONFIG_SUPPORT_GSM

#define AUDCP_HEADER_STR "SharkL5_AUDCP"
#define LTE_AGDSP_SIZE  0x00600000
#define LTE_AGDSP_ADDR  0x89000000
#define HEADER_SIZE 0x00000080

#define FIXNV_SIZE     0x100000

#define CONFIG_DFS_ENABLE
#ifdef CONFIG_SP_DDR_BOOT
#define DFS_ADDR    0x88040000
#define SP_IRAM_ADDR 0x800000
/* pm_sys partion size max only 1MB */
#define DFS_SIZE    (1*1024*1024)
#else
#define DFS_ADDR    0x800000
#define DFS_SIZE    (256*1024)
#endif

/*eMMC config*/
#define CONFIG_MMC
#define CONFIG_MMC_SDMA
#define CONFIG_EMMC_VERSION_R11P0
/*sprdimageversion Dynamic acquisition rpmb's size*/
#define CONFIG_SPRD_RPMB


/*eMMC boot*/
#define CONFIG_EMMC_BOOT
#define CONFIG_GENERIC_MMC
#define CONFIG_EMMC_RST_N_FUNCTION
#define EMMC_SECTOR_SIZE 512
/*file system config*/
#define CONFIG_FAT_WRITE
#define CONFIG_FS_EXT4


/*used in usb drv*/
#define CHIP_ENDIAN_LITTLE
#define _LITTLE_ENDIAN 1
#define CONFIG_MUSB_GADGET
#define CONFIG_USB_SPRD_DMA
#define CONFIG_USB_GADGET_MUSB_HDRC
#define TMSC_16NM_FFPLL 0x5533166e /* USB3.0_PHY_TSMC_16NM */
#define USB3_PHY_TUNE1 0x919e9dec
#define USB3_PHY_TUNE2 0x0f0560fe
#define CONFIG_USB_PHY_SHARKL5PRO
//#define CALIBRATION_FLAG_CP0           0x88AF0000
#define CALIBRATION_FLAG_CP1	0x8da20000
//#define CONFIG_DWC_OTG
#define CONFIG_MODEM_CALIBERATE
#define CALIBRATE_ENUM_MS 15000
#define CALIBRATE_IO_MS 2000
#define CONFIG_USB_GADGET_SC8800G
#define CONFIG_USB_DWC
#define CONFIG_USB_GADGET_DUALSPEED

/*use EFI partition*/
#define CONFIG_EFI_PARTITION

/*for sysdump*/
#define CONFIG_SPRD_SYSDUMP
#define CONFIG_SYS_VSNPRINTF
#define SPRD_SYSDUMP_MAGIC        (0x80001000)
#define CONFIG_RAMDUMP_NO_SPLIT /* Don't split sysdump file */
#define REAL_SDRAM_SIZE 0x40000000  /*dump 1G*/
#define CONFIG_SHA1
#define CONFIG_SPRD_MINI_SYSDUMP
#define CONFIG_GZIP_COMPRESSED
#define CONFIG_GZIP_COMPRESS_DEF_SZ     0x200
#define CONFIG_SYSDUMP_LED


#define PWR_KEY_DETECT_CNT  2
#define ALARM_LEAD_SET_MS 0 /* time set for alarm boot in advancd */
#define LOW_BAT_VOL            3500 /*phone battery voltage low than this value will not boot up*/
#define LOW_BAT_VOL_CHG        3300    //3.3V charger connect


/*for device tree*/
#define DT_PLATFROM_ID 512
#define DT_HARDWARE_ID 1
#define DT_SOC_VER     0x20000


#define SIMLOCK_ADR      (0x891FE800+0x4)   //0x4 just for data header

#define KERNEL_ADR      0x80080000
#define DT_ADR          0x82000000
#define RAMDISK_ADR     0x82100000


/*for modem entry*/
#define COOPERATE_PROCESSOR_RESET_ADDR    0x402b00b0
#define COOPERATE_PMU_CTRL0_ADDR         0x402b0044
#define COOPERATE_PMU_CTRL2_ADDR         0x402b0068
#define CORE_CP0                          BIT_0
#define CORE_CP2                          BIT_2

/* display config */
#define CONFIG_LCD
#define CONFIG_CMD_BMP
#define CONFIG_SPLASH_SCREEN
#define CONFIG_VIDEO_SPRD
#define CONFIG_DPU_R4P0
#define CONFIG_DSIH_SPRD_CTRL_RXP0
#define CONFIG_DPHY_SPRD_SHARKL5PRO
#define CONFIG_MIPI_DRIVE_CAPABILITY 7
#define CONFIG_LCD_MIPI_CLOCK   1104000
#define CONFIG_SYS_WHITE_ON_BLACK
#define LCD_BPP LCD_COLOR32
/*pmic chipid */
#define CONFIG_PMIC_CHIP_ID

/*fastboot*/
#define SCRATCH_ADDR    (CONFIG_SYS_SDRAM_BASE + 0x100000)
#define FB_DOWNLOAD_BUF_SIZE           (CONFIG_SYS_TEXT_BASE - SCRATCH_ADDR-0x800000)
#define SCRATCH_ADDR_EXT1              (CONFIG_SYS_TEXT_BASE + 32*1024*1024)
#define FB_DOWNLOAD_BUF_EXT1_SIZE      (224*1024*1024)

/*uid blk config*/
#define UID_START 94
#define UID_END 95
#define UID_DOUBLE 0

/*7S reset config*/
#define CONFIG_7S_RST_MODULE_EN		1	//0:disable module; 1:enable module

#ifdef DEBUG
#define CONFIG_7S_RST_SW_MODE	1	//0:hw reset,1:arm reset,power keep on	//soft for debug version
#else
#define CONFIG_7S_RST_SW_MODE	0	//0:hw reset,1:arm reset,power keep on	//hard for user version
#endif

#define CONFIG_7S_RST_SHORT_MODE	1	//0:long press then release key to trigger;1:press key some time to trigger
#define CONFIG_7S_RST_2KEY_MODE		1	//0:1Key--Normal mode; 1:2KEY
#define CONFIG_7S_RST_THRESHOLD		7	//7S, hold key down for this time to trigger

 /*SMPL config*/
//#define CONFIG_SMPL_EN
#define CONFIG_SMPL_THRESHOLD 	0		//one step is 0.25S

/* Chip Driver Macro Definitions End*/
/*active arm7 ram before access to it*/
#define CONFIG_ARM7_RAM_ACTIVE
#define CONFIG_RTC_START_YEAR		1970

#define CONFIG_DM_SPRD_I2C
#define CONFIG_SPRD_HW_I2C

#define CONFIG_DM_FAN54015


#define CONFIG_DVFS_ADDR		0x60
#define CINFIG_DVFS_TX_5_REG_ADDR	0x02
#define CINFIG_DVFS_TX_7_REG_ADDR	0x00

/*-----------------------------------------------------------------------
 * Cache Configuration
 */
#define CONFIG_SYS_CACHELINE_SIZE	64

/* coresight dump ETB data */
#define CONFIG_ETB_DUMP

#ifdef CONFIG_ADIE_SC2730
#define ADI_15BIT_MODE
#endif

#define CONFIG_ANDROID_AB
/* direct access prot configuration  */
//#define CONFIG_DIRECT_ACC_PROT
/*sharkl5pro dcdc/ldo force on for bringup*/
//#define CONFIG_DEBUG_DCDCLDO_FORCE_ON
#endif /* __CONFIG_H  */
