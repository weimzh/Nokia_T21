#include <common.h>
#include <asm/u-boot-arm.h>
#include <asm/io.h>

typedef void (*tHandler) (void *int_num);

void gic_interrupt_enable (unsigned int interrupt, unsigned int enable)
{
	if (enable) {
		uint32_t n = interrupt >> 5;
		uint32_t bit = interrupt & ((1 << 5) - 1);
		if(interrupt < 32){
			writel(1 << interrupt,GICR_BASE+0x100+0x10000);
			return;
		}
		writel(1 << bit, GICD_BASE + 0x100 + (n << 2));
	}else{
		uint32_t n = interrupt >> 5;
		uint32_t bit = interrupt & ((1 << 5) - 1);
		if(interrupt < 32){
			writel(1 << interrupt,GICR_BASE+0x180+0x10000);
			return;
		}
		writel(1 << bit,GICD_BASE+0x180);
	}
}

uint32_t gic_interrupt_acknowledge (void)
{
	uint32_t v;
	asm ("mrc p15,0,%0,c12,c12,0" : "=r" (v));//icc_iar1
	return v;
}

void gic_interrupt_endofinterrupt (uint32_t v)
{
	asm ("mcr p15,0,%0,c12,c12,1" : : "r" (v));
}

#ifdef CONFIG_USE_IRQ 

static tHandler handlers[256];

void default_handler (void *int_num)
{
	int num = (int)int_num;
	printf("---irq %d trigger---\n",num);
	gic_interrupt_enable(num, 0);
}

void do_irq (struct pt_regs *pt_regswq)
{
	unsigned int irq = gic_interrupt_acknowledge();

	if(handlers[irq]) {
		handlers[irq]((void *)irq);
	}else{
		default_handler((void *)irq);
	}

	gic_interrupt_endofinterrupt(irq);
}


void do_fiq (struct pt_regs *pt_regswq)
{
	unsigned int irq = gic_interrupt_acknowledge();

	if(handlers[irq]) {
		handlers[irq]((void *)irq);
	}else{
		default_handler((void *)irq);
	}

	gic_interrupt_endofinterrupt(irq);
}

void irq_handler_register(int irq_num,tHandler func);

int arch_interrupt_init (void)
{
	uint32_t cpsr;
	memset(handlers,0,sizeof(handlers));

	__asm__ __volatile__("mrs %0, cpsr\n"
			     : "=r" (cpsr)
			     :
			     : "memory");
	//hyp mode or svc
	if((cpsr&0xf) == 0xa || (cpsr&0xf) == 0x3) {
		gic_init_secure(GICD_BASE);
		gic_init_secure_percpu(GICR_BASE);
	}
	return 0;
}

void irq_handler_register(int irq_num,tHandler func)
{
	handlers[irq_num] = func;
}

#endif
