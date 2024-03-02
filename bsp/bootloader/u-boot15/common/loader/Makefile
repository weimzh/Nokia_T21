obj-y += loader_common.o
#obj-y += loader_emmc.o
obj-y += loader_nvm.o
obj-y += boot_mode.o
obj-y += dev_tree.o
obj-y += sprd_fdt_support.o
obj-y += calibration_detect.o
obj-y += fastboot.o
obj-y += others.o
obj-y += recv_mode.o
obj-y += alarm_mode.o
obj-y += autodloader_mode.o
#obj-y += secure_verify.o
obj-y += vbat_check.o
obj-$(CONFIG_SPRD_SYSDUMP) += sysdump.o
obj-$(CONFIG_X86) += crashlog.o
obj-y += sd_operate.o
obj-y += sprd_cpcmdline.o
obj-y += sprdisk.o
obj-y += sprd_fdt_memory.o
obj-$(CONFIG_MEM_LAYOUT_DECOUPLING) += process_cp_coupling_info.o
obj-y += read_miscdata_boot_flag.o
obj-y += hwfeature.o
#20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start begin
obj-y += oem_fastboot_cmd.o
obj-y += read_miscdata_info.o
#20220524,Added by zhu_jun for suport fastboot command:fastboot oem auth_start end
#20220531,Added by zhu_jun for Set ZeroFlag related property begin
obj-y += mpflag_check.o
#20220531,Added by zhu_jun for Set ZeroFlag related property end
#20220525,Added by zhu_jun for serial number related properties begin
obj-y += read_protect_data_info.o
#20220525,Added by zhu_jun for serial number related properties end

ifeq ($(BSP_BUILD_VARIANT),user)
ccflags-y += -DUSER_BUILD
endif
