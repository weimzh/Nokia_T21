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
#define CONFIG_MEM_LAYOUT_DECOUPLING

#define CONFIG_LCD_ROTATION

/*build aarch64 u-boot.elf*/
#define CONFIG_REMAKE_ELF
#define CONFIG_SPRD_UID
#define CONFIG_SYS_NO_FLASH
#define CONFIG_SPL_BAK
#define CONFIG_MISC_INIT_R                     /* call misc_init_r()	      */
#define CONFIG_BOARD_LATE_INIT         /* call board_late_init() */
/*the SPL is erased, the romcode will enter the download process.*/
#define CONFIG_ERASE_SPL_AUTO_DOWNLOAD

/* Cache Definitions */
/* #define CONFIG_SYS_DCACHE_OFF */
/* #define CONFIG_SYS_ICACHE_OFF */

/* support wifi mode for temp */
#define CONFIG_WIFI_MODE

#define CONFIG_IDENT_STRING		"QOGIRL6"

#define CONFIG_SYS_INIT_SP_ADDR     \
	(CONFIG_SYS_SDRAM_END - 0x10000 - GENERATED_GBL_DATA_SIZE)

/* SMP Spin Table Definitions */
#define CPU_RELEASE_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x7fff0)

/* get soc serial number */
#define CONFIG_GET_CPU_SERIAL_NUMBER_NO_WD

/* Generic Timer Definitions */
#define COUNTER_FREQUENCY		(0x1800000)	/* 24MHz */

/* Generic Interrupt Controller Definitions */
#define CONFIG_GICV3
#define GICD_BASE			(0x10000000)
#define GICR_BASE			(0x10004000)
#define CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ (1024)
#define CONFIG_STACKSIZE_FIQ (1024)

#define CONFIG_SYS_MEMTEST_START	PHYS_SDRAM_1
#define CONFIG_SYS_MEMTEST_END		(PHYS_SDRAM_1 + 0x0800000)

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 7 * 1024 * 1024)

/* eMMC and DDR check type*/
#define CONFIG_EMMC_DDR_CHECK_TYPE

/*timer*/
#define CONFIG_SYS_HZ			1000
#define CONFIG_SPRD_TIMER_CLK		1000 /*32768*/

#define CONFIG_ROUND_CORNER_SUPPORT
#define CONFIG_CORNER_RADIUS 30

/* SPREADTRUM BIGPHONE board - SoC Configuration */
/* Note: SOC macro should be named as CONFIG_SOC_ProjectName */
#define CONFIG_SOC_QOGIRL6
#define CONFIG_ADIE_SC2730

/*pmic chipid */
#define CONFIG_PMIC_CHIP_ID

// LPC Enable Macro
#define CONFIG_AON_LPC_EN
#define CONFIG_AP_LPC_EN
#define CONFIG_CLOCK_AUTO_GATE_EN

#define CONFIG_DTS_MEM_LAYOUT

#define CONFIG_PRE_CONSOLE_BUFFER
#define CONFIG_PRE_CON_BUF_SZ		0x2000
#define CONFIG_PRE_CON_BUF_ADDR		0x92300000
/* SPRD Serial Configuration */
#define CONFIG_SPRD_UART		1
#define CONFIG_SYS_SC8800X_UART1	1
#define CONFIG_CONS_INDEX	1	/* use UART0 for console */
#define CONFIG_SPRD_UART_PORTS	{ (void *) (CONFIG_SYS_SERIAL0), (void *) (CONFIG_SYS_SERIAL1) }
#define CONFIG_SYS_SERIAL0		0x200a0000
#define CONFIG_SYS_SERIAL1		0x200b0000

/* Default baud rate */
#define CONFIG_BAUDRATE		115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*
 * log config
 */
#define CONFIG_SPRD_LOG
#define CONFIG_LOG_2_EMMC
/* sprd watchdog */
#define CONFIG_HW_WATCHDOG
#define CONFIG_SPRD_WATCHDOG

/* sprd rtc */
#define CONFIG_RTC_SPRD

/* sprd normal efuse */
#define CONFIG_SPRD_AP_NORMAL_EFUSE

/* sprd adc */
#define CONFIG_SPRD_ADC

/* sprd adi */
#define CONFIG_SPRD_ADI
#define ADI_R3P0_VER

/* sprd gpio */
#define CONFIG_SPRD_GPIO
#define CONFIG_SPRD_EIC_EXT1
#define CONFIG_POWERKEY_DEFAULT_HIGH

/*sprd clk*/
#define CONFIG_COMMON_CLK
#define CONFIG_SPRD_CLK
#define CONFIG_SPRD_CLK_UMS9230

/* Command line configuration */
#define CONFIG_MENU
/* #define CONFIG_MENU_SHOW */
#define CONFIG_CMD_CACHE
#define CONFIG_CMD_BDI
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_PXE
#define CONFIG_CMD_ENV
#define CONFIG_CMD_FLASH
#define CONFIG_CMD_IMI
#define CONFIG_CMD_MEMORY
#define CONFIG_CMD_MII
/* #define CONFIG_CMD_NET */
#define CONFIG_CMD_PING
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_RUN
/* #define CONFIG_CMD_BOOTD */
#define CONFIG_CMD_ECHO
#define CONFIG_CMD_SOURCE
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#define CONFIG_ARMV8_MULTIENTRY
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
#define CONFIG_SYS_CBSIZE		4096	/* Console I/O Buffer Size */
#define CONFIG_SYS_PROMPT		"qogirl6# "
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

/* boot with modem */
#define BOOT_NATIVE_LINUX_MODEM  1

#define CONFIG_SUPPORT_LTE
#define CONFIG_ADVANCED_LTE

#define CONFIG_SUPPORT_AGDSP
#define CONFIG_AUDCP_BOOT_VECTOR 0x44800040

#define AUDCP_HEADER_STR "SharkL5_AUDCP"  //QogirL6_AUDCP_HEADER inherited from SharkL5
#define LTE_AGDSP_SIZE  0x00500000
#define LTE_AGDSP_ADDR  0x89000000

#define FIXNV_SIZE     0x100000

#define CONFIG_DFS_ENABLE
#ifdef CONFIG_SP_DDR_BOOT
#define DFS_ADDR    0x88040000
#define SP_IRAM_ADDR 0x62010000
/* pm_sys partion size max only 1MB */
#define DFS_SIZE    (1*1024*1024)
#else
#define DFS_ADDR    0x62010000
#define DFS_SIZE    (256*1024)
#endif

/*get flash type during uboot downloading*/
#define CONFIG_SEND_STORAGE_TYPE

/*ufs and emmc one software multi hardware,auto detect*/
#define CONFIG_BLK_DEV_BOOT

/* eMMC config */
#define CONFIG_MMC
#define CONFIG_MMC_SDMA
#define CONFIG_EMMC_VERSION_R11P0
/*sprdimageversion Dynamic acquisition rpmb's size*/
#define CONFIG_SPRD_RPMB

/* eMMC boot */
//#define CONFIG_EMMC_BOOT
#define CONFIG_GENERIC_MMC
#define CONFIG_EMMC_RST_N_FUNCTION
#define EMMC_SECTOR_SIZE 512

/* ufs config */
#define CONFIG_UFS

#if defined(CONFIG_UFS) && defined(CONFIG_MMC)
#define CONFIG_UFS_BOOTDEVICE "androidboot.boot_devices=soc/soc:ap-apb/20200000.ufs"
#define CONFIG_EMMC_BOOTDEVICE "androidboot.boot_devices=soc/soc:ap-apb/201d0000.sdio"
#define CONFIG_UFS_DTS_PATH "/soc/ap-apb/ufs"
#define CONFIG_EMMC_DTS_PATH "/soc/ap-apb/sdio@201d0000"
#endif

/* file system config */
#define CONFIG_FAT_WRITE
#define CONFIG_FS_EXT4
#define CONFIG_EXT4_WRITE

/*used in usb drv*/
#define CHIP_ENDIAN_LITTLE
#define _LITTLE_ENDIAN 1
#define CONFIG_MUSB_GADGET
#define CONFIG_USB_SPRD_DMA
#define CONFIG_USB_GADGET_MUSB_HDRC
#define TMSC_16NM_FFPLL 0x5533166e /* USB3.0_PHY_TSMC_16NM */
#define USB3_PHY_TUNE1 0x919e9dec
#define USB3_PHY_TUNE2 0x0f0560fe
#define CONFIG_USB_PHY_QOGIRL6
//#define CALIBRATION_FLAG_CP0           0x88AF0000
#define CALIBRATION_FLAG_CP1	0x8da20000
//#define CONFIG_DWC_OTG
#define CONFIG_MODEM_CALIBERATE
#define CALIBRATE_ENUM_MS 15000
#define CALIBRATE_IO_MS 2000
#define CONFIG_USB_GADGET_SC8800G
#define CONFIG_USB_DWC
#define CONFIG_USB_GADGET_DUALSPEED

/* use EFI partition */
#define CONFIG_EFI_PARTITION

/* for sysdump */
#define CONFIG_SPRD_SYSDUMP
//#define SPRD_SYSDUMP_MAGIC	RAMDISK_ADR
#define SPRD_SYSDUMP_MAGIC	(0x80001000)
#define CONFIG_RAMDUMP_NO_SPLIT /* Don't split sysdump file */
#define REAL_SDRAM_SIZE 0x40000000  /*dump 1G*/
#define CONFIG_SHA1
#define CONFIG_SPRD_MINI_SYSDUMP
#define CONFIG_GZIP_COMPRESSED
#define CONFIG_GZIP_COMPRESS_DEF_SZ     0x200
#define CONFIG_SYSDUMP_LED
#define CONFIG_SYS_VSNPRINTF
#define CONFIG_FULLDUMP_INTERNAL_ENABLE
#define CONFIG_FULLDUMPINTERNAL_COMPRESS

#define PWR_KEY_DETECT_CNT  2
#define ALARM_LEAD_SET_MS 0 /* time set for alarm boot in advancd */
#define LOW_BAT_VOL            3510 /*phone battery voltage low than this value will not boot up*/
#define LOW_BAT_VOL_CHG        3500    //3.3V charger connect
#define MISCDATA_ADDRESS_BASE		(10 * 1024 + 256)
#define MISCDATA_MAGIC_OFFSET		0
#define MISCDATA_MAGIC_SIZE		4
#define MISCDATA_RTC_TIME_OFFSET	4
#define MISCDATA_RTC_TIME_SIZE		8
#define MISCDATA_CHARGE_CYCLE_OFFSET	12
#define MISCDATA_CHARGE_CYCLE_SIZE	4
#define MISCDATA_BASP_OFFSET		16
#define MISCDATA_BASP_SIZE		4
#define MISCDATA_CAPACITY_OFFSET	20
#define MISCDATA_CAPACITY_SIZE		4
#define MISCDATA_CAPACITY_CHECK_OFFSET	24
#define MISCDATA_CAPACITY_CHECK_SIZE	4

/*for device tree*/
#define DT_PLATFROM_ID 9230
#define DT_HARDWARE_ID 1
#define DT_SOC_VER     0x20000

#define SIMLOCK_ADR      (0x891FE800+0x4)   //0x4 just for data header

#define KERNEL_ADR      0x80080000
#define DT_ADR          0x9df00000
#define RAMDISK_ADR     0xa0000000


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
#define CONFIG_DPU_R5P0
#define CONFIG_DSIH_SPRD_CTRL_RXP0
#define CONFIG_DPHY_SPRD_QOGIRL6
#define CONFIG_MIPI_DRIVE_CAPABILITY 5
#define CONFIG_LCD_MIPI_CLOCK   1104000
#define CONFIG_SYS_WHITE_ON_BLACK
#define LCD_BPP LCD_COLOR16
#define CONFIG_LCD_I2C_DM

/*rf board id */
//#define RF_BAND_INFO
#ifdef RF_BAND_INFO
#define LB_GPIO_NUM   175
#define MB_GPIO_NUM   174
#define HB_GPIO_NUM   166
#define ADC_CHANNEL_FOR_NV   1
#endif

#define CONFIG_ANDROIDBOOT_HARDWARE

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
#define CONFIG_7S_RST_2KEY_MODE		0	//0:1Key--Normal mode; 1:2KEY
#define CONFIG_7S_RST_THRESHOLD		10	//7S, hold key down for this time to trigger

/* SMPL config */
//#define CONFIG_SMPL_EN
#define CONFIG_SMPL_THRESHOLD 	0		//one step is 0.25S

/* Chip Driver Macro Definitions End */
/* active arm7 ram before access to it */
#define CONFIG_ARM7_RAM_ACTIVE
#define CONFIG_RTC_START_YEAR		1970

#define CONFIG_DM_SPRD_I2C
#define CONFIG_SPRDCHG_I2C_BUS 4

#define CONFIG_SPRD_HW_I2C_V2
//#define CONFIG_DM_BQ2560X
#define CONFIG_DM_SGM41513A

#define CONFIG_DVFS_ADDR		0x60
#define CINFIG_DVFS_TX_0_REG_ADDR	0x02
#define CINFIG_DVFS_TX_1_REG_ADDR	0x00
/*-----------------------------------------------------------------------
 * Cache Configuration
 */
#define CONFIG_SYS_CACHELINE_SIZE	64

/* coresight dump ETB data */
#define CONFIG_ETB_DUMP

/* usbpinmux config */
#define CONFIG_USBPINMUX

#ifdef CONFIG_ADIE_SC2730
#define ADI_15BIT_MODE
#endif

#ifndef CONFIG_CHIP_UID
#define CONFIG_CHIP_UID
#endif

#define CONFIG_ANDROID_AB

#define CONFIG_TIME_STATISTIC

/* direct access prot configuration  */
/* #define CONFIG_DIRECT_ACC_PROT */

//#define CONFIG_WR_SPARSE
#endif /* __CONFIG_H  */

#ifdef CONFIG_USE_IRQ
#define CONFIG_SPRD_GPIO_IRQ
#define CONFIG_SPRD_EIC_IRQ

#define CONFIG_EMMC_WP  //add for protect protect_data partition

//sensor
//#define CONFIG_SENSOR_HUB_UBOOT
#define CONFIG_SENSOR_I2C_MATRIX_BASE  0x64710018
#define CONFIG_SENSOR_I2C_MATRIX_VALUE  0x27543018

//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking begin
#define CONFIG_PCTOOL_AUTHORIZE_HMD
//20220704, Added by zhu_jun for VSI-679 SoC Diagnostics Locking end
#endif

