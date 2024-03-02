#
# Copyright (c) 2011 The Chromium OS Authors.
#
# SPDX-License-Identifier:	GPL-2.0+
#

# This Makefile builds the internal U-Boot fdt if CONFIG_OF_CONTROL is
# enabled. See doc/README.fdt-control for more details.

DEVICE_TREE ?= $(CONFIG_DEFAULT_DEVICE_TREE:"%"=%)
ifeq ($(DEVICE_TREE),)
DEVICE_TREE := unset
endif

ARCH_PATH := arch/$(ARCH)/dts
dtb_depends := arch-dtbs

ifneq ($(EXT_DTB),)
DTB := $(EXT_DTB)
else
DTB_S := $(patsubst %.dts,%.dtb, $(wildcard $(srctree)/$(ARCH_PATH)/$(DEVICE_TREE).dts)) $(patsubst %.dts,%.dtb, $(wildcard $(srctree)/$(ARCH_PATH)/$(DEVICE_TREE)_bid_*.dts))
DTB := $(DTB_S:$(srctree)/%=%)
dtb_depends += $(DTB:.dtb=.dts)
endif

$(obj)/dt.dtb: $(DTB) FORCE
	$(Q)rm -f $@
	$(Q)for i in $(filter-out FORCE,$^); do \
		dd if=$$i ibs=16 obs=16 conv=sync >> $@; \
	done
#	$(call if_changed,shipped)

targets += dt.dtb

$(DTB): $(dtb_depends)
ifeq ($(EXT_DTB),)
	$(Q)$(MAKE) $(build)=$(ARCH_PATH) $@
endif
	$(Q)test -e $@ || (						\
	echo >&2;							\
	echo >&2 "Device Tree Source is not correctly specified.";	\
	echo >&2 "Please define 'CONFIG_DEFAULT_DEVICE_TREE'";		\
	echo >&2 "or build with 'DEVICE_TREE=<device_tree>' argument";	\
	echo >&2;							\
	/bin/false)

arch-dtbs:
	$(Q)$(MAKE) $(build)=$(ARCH_PATH) dtbs

.SECONDARY: $(obj)/dt.dtb.S

obj-$(CONFIG_OF_EMBED) := dt.dtb.o

dtbs: $(obj)/dt.dtb
	@:

clean-files := dt.dtb.S

# Let clean descend into dts directories
subdir- += ../arch/arm/dts ../arch/microblaze/dts ../arch/mips/dts ../arch/sandbox/dts ../arch/x86/dts
