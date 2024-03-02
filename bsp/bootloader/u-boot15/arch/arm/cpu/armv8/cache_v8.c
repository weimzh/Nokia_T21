/*
 * (C) Copyright 2013
 * David Feng <fenghua@phytium.com.cn>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/system.h>
#include <asm/armv8/mmu.h>

DECLARE_GLOBAL_DATA_PTR;
extern phys_size_t real_ram_size;

#ifndef CONFIG_SYS_DCACHE_OFF
void set_pgtable_section(u64 *page_table, u64 index, u64 section,
			 u64 memory_type)
{
	u64 value;

	value = section | PMD_TYPE_SECT | PMD_SECT_AF;
	if (MT_DEVICE_NGNRNE == memory_type)
		value |= PMD_SECT_PXN | PMD_SECT_UXN;
	value |= PMD_ATTRINDX(memory_type);
	page_table[index] = value;
}

static void set_whole_ddr_pgtable_section(u64 *page_table, u64 index, u64 section)
{
	u64 value;

	value = section | PMD_TYPE_SECT | PMD_SECT_AF;
	value |= PMD_SECT_PXN | PMD_SECT_UXN;
	value |= PMD_ATTRINDX(MT_NORMAL);
	page_table[index] = value;
}

/* to activate the MMU we need to set up virtual memory */
static void mmu_setup(void)
{
	int i, j, el;
	ulong uboot_start = CONFIG_SYS_TEXT_BASE;
	ulong uboot_end = CONFIG_SYS_SDRAM_BASE + get_effective_memsize();
	ulong ddr_start = CONFIG_SYS_SDRAM_BASE;
	ulong ddr_end = CONFIG_SYS_SDRAM_BASE + real_ram_size;
	bd_t *bd = gd->bd;
	u64 *page_table = (u64 *)gd->arch.tlb_addr;
	u64 *page_table_sec = (u64 *) (gd->arch.tlb_addr + 0x1000);

	/* Setup an identity-mapping for all spaces */
	for (i = 0; i < (PGTABLE_SIZE >> 3); i++) {
		set_pgtable_section(page_table, i, (u64)i << SECTION_SHIFT,
				    MT_DEVICE_NGNRNE);
	}

	/* Setup an identity-mapping for all RAM space */
	if (ddr_end % (1 << SECTION_SHIFT))
	{
		ddr_end = ddr_end +(1 << SECTION_SHIFT);
	}

	for (j = ddr_start >> SECTION_SHIFT;
			j < ddr_end >> SECTION_SHIFT; j++) {
		if (j == ddr_start >> SECTION_SHIFT)
			set_whole_ddr_pgtable_section(page_table, j, (u64)(page_table_sec) | 0x2);
		else
			set_whole_ddr_pgtable_section(page_table, j, (u64)j << SECTION_SHIFT);
	}

	/* 2nd page setup */
	for (j = 0; j < 0x40000000 >> SECTION_SHIFT_2M; j++) {
		set_whole_ddr_pgtable_section(page_table_sec, j,
			((((u64)j) << SECTION_SHIFT_2M) + ddr_start));
	}

	/* Setup an identity-mapping for UBOOT space */
	if (uboot_end % (1 << SECTION_SHIFT_2M))
	{
		uboot_end = uboot_end + (1 << SECTION_SHIFT_2M);
	}

	for (j = (uboot_start - ddr_start) >> SECTION_SHIFT_2M;
			j < (uboot_end - ddr_start) >> SECTION_SHIFT_2M; j++) {
		set_pgtable_section(page_table_sec, j,
			((((u64)j) << SECTION_SHIFT_2M) + ddr_start), MT_NORMAL);
	}

	/* load TTBR0 */
	el = current_el();
	if (el == 1) {
		set_ttbr_tcr_mair(el, gd->arch.tlb_addr,
				  TCR_FLAGS | TCR_EL1_IPS_BITS,
				  MEMORY_ATTRIBUTES);
	} else if (el == 2) {
		set_ttbr_tcr_mair(el, gd->arch.tlb_addr,
				  TCR_FLAGS | TCR_EL2_IPS_BITS,
				  MEMORY_ATTRIBUTES);
	} else {
		set_ttbr_tcr_mair(el, gd->arch.tlb_addr,
				  TCR_FLAGS | TCR_EL3_IPS_BITS,
				  MEMORY_ATTRIBUTES);
	}
	/* enable the mmu */
	set_sctlr(get_sctlr() | CR_M);
}

/*
 * Performs a invalidation of the entire data cache at all levels
 */
void invalidate_dcache_all(void)
{
	__asm_invalidate_dcache_all();
}

/*
 * Performs a clean & invalidation of the entire data cache at all levels.
 * This function needs to be inline to avoid using stack.
 * __asm_flush_l3_cache return status of timeout
 */
inline void flush_dcache_all(void)
{
	int ret;

	__asm_flush_dcache_all();
	ret = __asm_flush_l3_cache();
	//if (ret)
	//	debug("flushing dcache returns 0x%x\n", ret);
	//else
	//	debug("flushing dcache successfully.\n");
}

/*
 * Invalidates range in all levels of D-cache/unified cache
 */
void invalidate_dcache_range(unsigned long start, unsigned long stop)
{
	__asm_invalidate_dcache_range(start, stop);
}

/*
 * Flush range(clean & invalidate) from all levels of D-cache/unified cache
 */
void flush_dcache_range(unsigned long start, unsigned long stop)
{
	__asm_flush_dcache_range(start, stop);
}

void dcache_enable(void)
{
	/* The data cache is not active unless the mmu is enabled */
	if (!(get_sctlr() & CR_M)) {
		invalidate_dcache_all();
		__asm_invalidate_tlb_all();
		mmu_setup();
	}

	set_sctlr(get_sctlr() | CR_C);
}

void dcache_disable(void)
{
	uint32_t sctlr;

	sctlr = get_sctlr();

	/* if cache isn't enabled no need to disable */
	if (!(sctlr & CR_C))
		return;

	set_sctlr(sctlr & ~(CR_C|CR_M));

	flush_dcache_all();
	__asm_invalidate_tlb_all();
}

int dcache_status(void)
{
	return (get_sctlr() & CR_C) != 0;
}

#else	/* CONFIG_SYS_DCACHE_OFF */

void invalidate_dcache_all(void)
{
}

void flush_dcache_all(void)
{
}

void invalidate_dcache_range(unsigned long start, unsigned long stop)
{
}

void flush_dcache_range(unsigned long start, unsigned long stop)
{
}

void dcache_enable(void)
{
}

void dcache_disable(void)
{
}

int dcache_status(void)
{
	return 0;
}

#endif	/* CONFIG_SYS_DCACHE_OFF */

#ifndef CONFIG_SYS_ICACHE_OFF

void icache_enable(void)
{
	__asm_invalidate_icache_all();
	set_sctlr(get_sctlr() | CR_I);
}

void icache_disable(void)
{
	set_sctlr(get_sctlr() & ~CR_I);
}

int icache_status(void)
{
	return (get_sctlr() & CR_I) != 0;
}

void invalidate_icache_all(void)
{
	__asm_invalidate_icache_all();
}

#else	/* CONFIG_SYS_ICACHE_OFF */

void icache_enable(void)
{
}

void icache_disable(void)
{
}

int icache_status(void)
{
	return 0;
}

void invalidate_icache_all(void)
{
}

#endif	/* CONFIG_SYS_ICACHE_OFF */

/*
 * Enable dCache & iCache, whether cache is actually enabled
 * depend on CONFIG_SYS_DCACHE_OFF and CONFIG_SYS_ICACHE_OFF
 */
void __weak enable_caches(void)
{
	icache_enable();
	dcache_enable();
}

/*
 * Flush range from all levels of d-cache/unified-cache
 */
void flush_cache(unsigned long start, unsigned long size)
{
	flush_dcache_range(start, start + size);
}
