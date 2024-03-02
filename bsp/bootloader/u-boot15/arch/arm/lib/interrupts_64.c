/*
 * (C) Copyright 2013
 * David Feng <fenghua@phytium.com.cn>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <linux/compiler.h>
#include <asm/u-boot-arm.h>
#include <asm/io.h>

#ifdef CONFIG_USE_IRQ
typedef void (*tHandler) (void *int_num);
static tHandler handlers[256];
#endif

struct pt_regs regs_sav;

int interrupt_init(void)
{
#ifdef CONFIG_USE_IRQ
	memset(handlers,0,sizeof(handlers));
#endif
	return 0;
}

void enable_interrupts(void)
{
	asm("msr daifclr,#0x3\n");
	return;
}

int disable_interrupts(void)
{
	asm("msr daifset,#0x3\n");
	return 0;
}

void show_regs(struct pt_regs *regs)
{
	int i;

	memcpy(&regs_sav, regs, sizeof(regs_sav));

	printf("ELR:     %lx\n", regs->elr);
	printf("LR:      %lx\n", regs->regs[30]);
	for (i = 0; i < 29; i += 2)
		printf("x%-2d: %016lx x%-2d: %016lx\n",
		       i, regs->regs[i], i+1, regs->regs[i+1]);
	printf("\n");
}

/*
 * do_bad_sync handles the impossible case in the Synchronous Abort vector.
 */
void do_bad_sync(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("Bad mode in \"Synchronous Abort\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}

/*
 * do_bad_irq handles the impossible case in the Irq vector.
 */
void do_bad_irq(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("Bad mode in \"Irq\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}

/*
 * do_bad_fiq handles the impossible case in the Fiq vector.
 */
void do_bad_fiq(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("Bad mode in \"Fiq\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}

/*
 * do_bad_error handles the impossible case in the Error vector.
 */
void do_bad_error(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("Bad mode in \"Error\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}

/*
 * do_sync handles the Synchronous Abort exception.
 */
void do_sync(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("\"Synchronous Abort\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}
#ifdef CONFIG_USE_IRQ
void gic_interrupt_enable (unsigned int interrupt, unsigned int enable)
{
#if defined(CONFIG_GICV3)
	if (enable) {
		uint32_t n = interrupt >> 5;
		uint32_t bit = interrupt & ((1 << 5) - 1);
		if(interrupt < 32){
			writel(1 << interrupt,GICR_BASE+0x100+0x10000);
			return;
		}
		writel(1 << bit, GICD_BASE + 0x100 + (n << 2));
	}else {
		uint32_t n = interrupt >> 5;
		uint32_t bit = interrupt & ((1 << 5) - 1);
		if(interrupt < 32){
			writel(1 << interrupt,GICR_BASE+0x180+0x10000);
			return;
		}
		writel(1 << bit,GICD_BASE+0x180);
	}
#endif
}


void default_handler (void *int_num)
{
	int num = (int)int_num;
	printf("---irq %d trigger---\n",num);
	gic_interrupt_enable(num, 0);
}

#if defined(CONFIG_GICV3)
static inline uint64_t read_icc_iar0_el1(void) {
	uint64_t v;
	asm ("mrs %0, S3_0_c12_c8_0" : "=r" (v));
	return v;
}

static inline uint64_t read_icc_iar1_el1(void) {
	uint64_t v;
	asm ("mrs %0, S3_0_c12_c12_0" : "=r" (v));
	return v;
}

static inline void write_icc_eoir0_el1(uint64_t v) {
	asm("msr S3_0_c12_c8_1, %0" : : "r" (v));
}

static inline void write_icc_eoir1_el1(uint64_t v) {
	asm ("msr S3_0_c12_c12_1, %0" : : "r" (v));
}

volatile uint32_t irqn;
void do_irq(struct pt_regs *pt_regs, unsigned int esr)
{
	irqn = read_icc_iar1_el1();
	if(irqn < 1020 || irqn >=8192)
	{
		if(handlers[irqn]) {
			handlers[irqn]((void *)irqn);
		}else{
			default_handler((void *)irqn);
		}
		write_icc_eoir1_el1(irqn);
	}
}

volatile uint32_t fiqn;
void do_fiq(struct pt_regs *pt_regs, unsigned int esr)
{
	fiqn = read_icc_iar1_el1();
	if(fiqn < 1020 || fiqn >=8192)
	{
		if(handlers[fiqn]) {
			handlers[fiqn]((void *)fiqn);
		}else{
			default_handler((void *)fiqn);
		}
		write_icc_eoir1_el1(fiqn);
	}
}
#endif
void irq_handler_register(int irq_num,tHandler func)
{
	handlers[irq_num] = func;
}

#else
/*
 * do_irq handles the Irq exception.
 */
void do_irq(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("\"Irq\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}

/*
 * do_fiq handles the Fiq exception.
 */
void do_fiq(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("\"Fiq\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}
#endif

/*
 * do_error handles the Error exception.
 * Errors are more likely to be processor specific,
 * it is defined with weak attribute and can be redefined
 * in processor specific code.
 */
void __weak do_error(struct pt_regs *pt_regs, unsigned int esr)
{
	printf("\"Error\" handler, esr 0x%08x\n", esr);
	show_regs(pt_regs);
	panic("Resetting CPU ...\n");
}
