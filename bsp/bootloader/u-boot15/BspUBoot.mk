BSP_OBJ :=`cat /proc/cpuinfo | grep processor | wc -l`

ifneq ($(strip $(BSP_UBOOT_TOOLCHAIN)),)
UBOOT_TOOLCHAIN := $(BSP_UBOOT_TOOLCHAIN)
else
#use default
ifeq ($(BSP_BOARD_ARCH) , arm64)
UBOOT_TOOLCHAIN := $(shell pwd)/../prebuilts/gcc/linaro-x86/aarch64/gcc-linaro-4.8/gcc-linaro-4.8-2015.06-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-
else ifeq ($(BSP_BOARD_ARCH), arm)
UBOOT_TOOLCHAIN := $(shell pwd)/../prebuilts/gcc/linux-x86/arm/arm-eabi-4.8/bin/arm-eabi-
else ifeq ($(BSP_BOARD_ARCH), x86)
UBOOT_TOOLCHAIN := $(shell pwd)/../prebuilts/gcc/linux-x86/x86/x86_64-linux-android-4.9/bin/x86_64-linux-android-
endif
endif

ifeq ($(BSP_BOARD_ARCH) , arm64)
SRCARCH := arm
else ifeq ($(BSP_BOARD_ARCH), arm)
SRCARCH := arm
else ifeq ($(BSP_BOARD_ARCH), x86)
SRCARCH := x86
endif

export UBOOT_MODEM_FLAG
ifeq ($(strip $(BSP_BOARD_REMOVE_SPRD_MODEM)),true)
UBOOT_MODEM_FLAG := -DCONFIG_REMOVE_MODEM
endif

BSP_UBOOT_CONFIG := $(BSP_UBOOT_OUT)/include/config.h
BSP_UBOOT_DTB_BUILT_BIN := $(BSP_UBOOT_OUT)/u-boot-dtb.bin
BSP_UBOOT_BUILT_BIN := $(BSP_UBOOT_OUT)/u-boot.bin
BSP_FDL2_BUILT_BIN := $(BSP_UBOOT_OUT)/fdl2.bin
BSP_UBOOT_DTB_BUILT := $(BSP_UBOOT_OUT)/u-boot
BSP_UBOOT_DTB_SYSTEM_MAP := $(BSP_UBOOT_OUT)/System.map
BSP_UBOOT_DTB_CFG := $(BSP_UBOOT_OUT)/u-boot.cfg


ifeq ($(BSP_BUILD_VARIANT),userdebug)
#ifneq ($(WT_COMPILE_FACTORY_VERSION),yes)
UBOOT_DEBUG_FLAG := -DDEBUG
#endif
endif

#20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device begin
#ifeq ($(BSP_BUILD_VARIANT),user)
#UBOOT_DEBUG_FLAG := -DUSER_BUILD
#endif
#20220608, Added by zhu_jun for VSI-492 flash userdebug package enter fastboot on efuse locked device end
export UBOOT_CONFIG_PRODUCT UBOOT_DEBUG_FLAG

ifeq ($(strip $(BSP_PRODUCT_SECURE_BOOT)),SPRD)
UBOOT_SECURE_BOOT_FLAG := -DCONFIG_SECBOOT
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_SPRD_SECBOOT

#20220606, Added by zhu_jun for bootloader unlock by devicekit begin
#ifeq ($(strip $(CONFIG_FASTBOOT_SECURITY_DOWNLOAD)),true)
#UBOOT_SECURE_BOOT_FLAG += -DCONFIG_FASTBOOT_SECURITY_DOWNLOAD
#endif
#20220606, Added by zhu_jun for bootloader unlock by devicekit end

ifeq ($(strip $(BSP_PRODUCT_USE_DYNAMIC_PARTITIONS)),true)
UBOOT_SECURE_BOOT_FLAG += -DPRODUCT_USE_DYNAMIC_PARTITIONS
endif

ifeq ($(strip $(BSP_PKCS1_PSS_FLAG)),true)
UBOOT_SECURE_BOOT_FLAG += -DPKCS1_PSS_FLAG
endif

ifeq ($(strip $(BSP_KERNEL_VERSION)),kernel5.4)
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_K54_FLAG
endif

ifeq ($(strip $(BSP_SHARKL5_CDSP_FLAG)),true)
UBOOT_SECURE_BOOT_FLAG += -DSHARKL5_CDSP
endif

ifeq ($(strip $(BSP_PROJECT_SEC_CM4_FLAG)),true)
UBOOT_SECURE_BOOT_FLAG += -DPROJECT_SEC_CM4
endif
ifeq ($(strip $(BSP_SPRD_WCN_GNSS_FLAG)),true)
UBOOT_SECURE_BOOT_FLAG += -DVERIFY_WCN_GNSS
endif
ifeq ($(strip $(BSP_PRODUCT_VBOOT)),V2)
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_VBOOT_V2
ifeq (9,$(filter 9,$(PLATFORM_VERSION)))
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_VBOOT_SYSTEMASROOT
endif
endif

ifneq ($(strip $(BOARD_PRODUCTIMAGE_PARTITION_SIZE)),)
UBOOT_SECURE_BOOT_FLAG += -DBOARD_PRODUCTIMAGE_PARTITION_SIZE
endif
endif #BSP_PRODUCT_SECURE_BOOT

ifneq ($(strip $(BSP_HWFEATURE)),)
UBOOT_HWFEATURE_FLAG += -DCONFIG_UBOOT_HWFEATURE='"$(strip $(BSP_HWFEATURE))"'
export UBOOT_HWFEATURE_FLAG
endif

ifeq ($(strip $(PRODUCT_DMVERITY_DISABLE)),true)
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_DMVERITY_DISABLE
endif

ifeq ($(strip $(BSP_PRODUCT_DISABLE_VAB)),true)
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_DISABLE_VAB
endif

#20220613, Added by zhu_jun for BSP disable enter recovery mode via keys on MP&User version begin
ifeq ($(strip $(WT_FINAL_RELEASE)),yes)
UBOOT_SECURE_BOOT_FLAG += -DWT_FINAL_RELEASE
endif
#20220613, Added by zhu_jun for BSP disable enter recovery mode via keys on MP&User version end
include $(shell pwd)/../../../vendor/hmd/$(TARGET_PRODUCT)/version.mk
DEVINFO_PROJECT := $(DEVINFO_PROJECT)
export DEVINFO_PROJECT
DEVINFO_PRODUCT := $(DEVINFO_PRODUCT)
export DEVINFO_PRODUCT
DEVINFO_MODEL := $(DEVINFO_MODEL)
export DEVINFO_MODEL
DEVINFO_VERSION := $(DEVINFO_VERSION)
export DEVINFO_VERSION
include $(shell pwd)/../../tools/secureboot_key/config/version.cfg
ANTIROLLBACK_HW := $(trusted_version)
export ANTIROLLBACK_HW
ANTIROLLBACK_VBMETA := $(avb_version_vbmeta)
export ANTIROLLBACK_VBMETA
ANTIROLLBACK_VBMETA_SYSTEM := $(avb_version_system)
export ANTIROLLBACK_VBMETA_SYSTEM
#20220606, Added by zhu_jun for support fastboot command fastboot oem get_devinfo end
#20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication begin
ifneq ($(strip $(WT_FINAL_RELEASE)),yes)
UBOOT_SECURE_BOOT_FLAG += -DWT_OEM_TEST
endif
#20220525, Added by zhu_jun for [HMD Flash Tool] fastboot command authentication end

#20220615, Added by zhu_jun for disable UART for shipment begin
ifeq ($(strip $(BUILD_PRODUCTION_SHIPMENT)),true)
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_DISABLE_UART
endif
#20220615, Added by zhu_jun for disable UART for shipment version end

export UBOOT_SECURE_BOOT_FLAG

ifeq ($(strip $(ROC1_CACHE_WORKAROUND)), true)
UBOOT_ROC1_CACHE_WA_FLAG := -DROC1_CACHE_MODIFICATION
endif

export UBOOT_ROC1_CACHE_WA_FLAG

ifeq ($(strip $(BSP_BOARD_TEE_CONFIG)),trusty)
UBOOT_TOS_TRUSTY_FLAG := -DTOS_TRUSTY
UBOOT_TOS_TRUSTY_FLAG += -DCONFIG_TRUSTY_QL_TIPC
endif

export UBOOT_TOS_TRUSTY_FLAG

ifeq ($(strip $(BSP_BOARD_TEECFG_CUSTOM)),true)
UBOOT_TEECFG_CUSTOM_FLAG := -DCONFIG_TEECFG_CUSTOM
endif

export UBOOT_TEECFG_CUSTOM_FLAG

ifeq ($(strip $(BSP_CONFIG_CHIP_UID)),true)
UBOOT_CHIP_UID_FLAG += -DCONFIG_CHIP_UID
endif

export UBOOT_CHIP_UID_FLAG

ifeq ($(strip $(BSP_CONFIG_TEE_FIREWALL)),true)
UBOOT_FIREWALL_FLAG := -DCONFIG_TEE_FIREWALL
endif

export UBOOT_FIREWALL_FLAG

ifeq ($(BSP_BOARD_ARCH), arm)
ifeq ($(strip $(BSP_BOARD_ATF_CONFIG)),true)
UBOOT_ARMV7_LPAE_FLAG := -DCONFIG_ARMV7_LPAE
endif
endif
export UBOOT_ARMV7_LPAE_FLAG

ifeq ($(strip $(CONFIG_BOARD_KERNEL_CMDLINE)),true)
UBOOT_KERNEL_CMDLINE_FLAG := -DCONFIG_BOARD_KERNEL_CMDLINE
endif
export UBOOT_KERNEL_CMDLINE_FLAG

ifeq ($(strip $(CONFIG_PCTOOL_CHECK_MULTI_FIXNV)),true)
UBOOT_PCTOOL_CHECK_MULTI_FIXNV_FLAG := -DCONFIG_PCTOOL_CHECK_MULTI_FIXNV
endif
export UBOOT_PCTOOL_CHECK_MULTI_FIXNV_FLAG

ifeq ($(strip $(CONFIG_PCTOOL_CHECK_WRITE_PROTECT)),true)
UBOOT_PCTOOL_CHECK_WRITE_PROTECT_FLAG := -DCONFIG_PCTOOL_CHECK_WRITE_PROTECT
endif
export UBOOT_PCTOOL_CHECK_WRITE_PROTECT_FLAG

ifeq ($(strip $(BSP_CALIMODE_USE_BOOTIMG)),true)
UBOOT_CALIMODE_USE_BOOTIMG_FLAG := -DCONFIG_CALIMODE_USE_BOOTIMG
endif
export UBOOT_CALIMODE_USE_BOOTIMG_FLAG

ifeq ($(strip $(CONFIG_NV_ENCRYPTION)),true)
	UBOOT_NV_ENCRYPTION_FLAG := -DNV_ENCRYPTION
endif
export UBOOT_NV_ENCRYPTION_FLAG

ifeq ($(strip $(WT_COMPILE_FACTORY_VERSION)),yes)
UBOOT_SECURE_BOOT_FLAG += -DWT_COMPILE_FACTORY_VERSION
UBOOT_SECURE_BOOT_FLAG += -DCONFIG_WT_COMPILE_FACTORY_VERSION
endif

NV_CFG_TO_H_INFO = $(shell $(BSP_ROOT_DIR)/bootloader/u-boot15/common/cfg_to_h.sh $(BSP_ROOT_DIR)/../device/sprd/mpool/module/modem/msoc/$(BSP_SYSTEM_VERSION)/nvmerge.cfg $(BSP_ROOT_DIR)/bootloader/u-boot15/common/nvmerge.h)
$(info $(strip $(findstring error:,$(NV_CFG_TO_H_INFO))))
ifneq ($(strip $(findstring error:,$(NV_CFG_TO_H_INFO))),error:)
$(info $(NV_CFG_TO_H_INFO))
else
$(error $(NV_CFG_TO_H_INFO))
endif


all: $(BSP_UBOOT_CONFIG)
	@mkdir -p $(BSP_UBOOT_DIST)
	$(MAKE) ARCH=$(SRCARCH) DEVICE_TREE=$(BSP_UBOOT_TARGET_DTB) CROSS_COMPILE=$(UBOOT_TOOLCHAIN) AUTOBOOT_FLAG=true O=$(BSP_UBOOT_OUT) -j$(BSP_OBJ)
	-cp $(BSP_UBOOT_DTB_BUILT_BIN) $(BSP_UBOOT_BUILT_BIN)
	@mkdir -p $(BSP_UBOOT_OUT)/.out
	@cp $(BSP_UBOOT_BUILT_BIN) $(BSP_UBOOT_OUT)/.out/u-boot_autopoweron.bin
	@cp $(BSP_UBOOT_DTB_BUILT) $(BSP_UBOOT_OUT)/.out/u-boot_autopoweron
	@cp $(BSP_UBOOT_DTB_SYSTEM_MAP) $(BSP_UBOOT_OUT)/.out/System_autopoweron.map
	@cp $(BSP_UBOOT_DTB_CFG) $(BSP_UBOOT_OUT)/.out/u-boot_autopoweron.cfg
	$(MAKE) ARCH=$(SRCARCH) DEVICE_TREE=$(BSP_UBOOT_TARGET_DTB) CROSS_COMPILE=$(UBOOT_TOOLCHAIN) O=$(BSP_UBOOT_OUT) clean
	$(MAKE) ARCH=$(SRCARCH) DEVICE_TREE=$(BSP_UBOOT_TARGET_DTB) CROSS_COMPILE=$(UBOOT_TOOLCHAIN) O=$(BSP_UBOOT_OUT)
	-cp $(BSP_UBOOT_DTB_BUILT_BIN) $(BSP_UBOOT_BUILT_BIN)
	@cp $(BSP_UBOOT_BUILT_BIN) $(BSP_FDL2_BUILT_BIN)
	@mv $(BSP_UBOOT_OUT)/.out/* $(BSP_UBOOT_OUT)/
	@rm -rf $(BSP_UBOOT_OUT)/.out
	@echo "Install U-Boot target done"

$(BSP_UBOOT_OUT):
	@echo "Start U-Boot build board $(BSP_UBOOT_DEFCONFIG)"

$(BSP_UBOOT_CONFIG): configs/$(addsuffix _defconfig,$(BSP_UBOOT_DEFCONFIG)) $(BSP_UBOOT_OUT)
	@mkdir -p $(BSP_UBOOT_OUT)
	$(MAKE) ARCH=$(SRCARCH) CROSS_COMPILE=$(UBOOT_TOOLCHAIN) O=$(BSP_UBOOT_OUT) distclean
	$(MAKE) ARCH=$(SRCARCH) CROSS_COMPILE=$(UBOOT_TOOLCHAIN) O=$(BSP_UBOOT_OUT) $(BSP_UBOOT_DEFCONFIG)_defconfig

ifeq ($(strip $(NORMAL_UART_MODE)),true)
	@echo "#define NORMAL_UART_MODE" >> $(BSP_UBOOT_CONFIG)
endif
