#include <common.h>
#include <asm/u-boot-arm.h>

#define SPURIOUS_INTERRUPT                     1023
#define NO_OF_INTERRUPTS_IMPLEMENTED           (192 + 32)
#define GIC_NUM_REGISTERS                      32
#define GIC_PRIORITY_REGISTERS                 256
#define GIC_TARGET_REGISTERS                   256
#define GIC_CONFIG_REGISTERS                   64
#define GIC_PERIPHERAL_ID                      4
#define GIC_PRIMECELL_ID                       4
#define GIC_RESERVED_BEFORE_IDENTIFICATION     44
#define GIC_RESERVED_BEFORE_IGROUPN	       29
#define GIC_RESERVED_BEFORE_NSACR_INT          64
#define GIC_NSACR_REGISTERS		       64
#define GIC_RESERVED_BEFORE_CLRPENDING	       3
#define GIC_SGI_REGISTERS		       4
#define GIC_RESERVED_BEFORE_ACTIVE_PRIORITY    41
#define IPI_MASK                               0x0000000F
#define INTERRUPT_MASK                         0x000003FF
#define CPUID_MASK                             0x00000C00
#define BINARY_POINT_MASK                      0x00000007
#define PRIORITY_MASK_MASK                     0x000000F0
#define CPUID_SHIFT                            10
#define PRIORITY_SHIFT                         4
#define IPI_TARGET_SHIFT                       16
#define IPI_TARGET_FILTER_SHIFT                24
#define USE_TARGET_LIST                        0x0
#define ALL_BUT_SELF                           0x1
#define SELF                                   0x2
#define COMPARE_ALL                            0x3
#define COMPARE_7_6_5                          0x4
#define COMPARE_7_6                            0x5
#define COMPARE_7                              0x6
#define NO_PREEMPTION                          0x7
#define UARTINT0_CHAIN_ID                      (2  + 32)
#define UARTINT1_CHAIN_ID                      (3 + 32)
#define GIC1_CHAIN_ID                          (256 + 32)
#define GIC3_CHAIN_ID                          (256 + 32)
#define GIC2_CHAIN_ID                          (256 + 32)
#define GIC4_CHAIN_ID                          (256 + 32)
#define VECTOR_BASE                            0x0
#define SCHEDULER_IPI                          IPI_0
#define HIGHEST_PRIORITY                       0x0
#define LOWEST_PRIORITY                        0xE
#define DEFAULT_PRIORITY                       0xF
#define RESCHEDULE_PRIORITY                    LOWEST_PRIORITY
#define ENABLE                                 1
#define DISABLE                                0
#define SET                                    1
#define UNSET                                  0
#define GIC_OK                                 0
#define GIC_INVAL                              1
#define GIC_ERROR                              2
#define GIC_SEC_GROUP                          0
#define GIC_NON_SEC_GROUP                      1

#define GIC_IPI_0                              0
#define GIC_IPI_1                              1
#define GIC_IPI_2                              2
#define GIC_IPI_3                              3
#define GIC_IPI_4                              4
#define GIC_IPI_5                              5
#define GIC_IPI_6                              6
#define GIC_IPI_7                              7
#define GIC_IPI_8                              8
#define GIC_IPI_9                              9
#define GIC_IPI_10                             10
#define GIC_IPI_11                             11
#define GIC_IPI_12                             12
#define GIC_IPI_13                             13
#define GIC_IPI_14                             14
#define GIC_IPI_15                             15

typedef void (*tHandler) (void *int_num);

struct set_and_clear_regs
{
    volatile unsigned int set[GIC_NUM_REGISTERS], clear[GIC_NUM_REGISTERS];
};

typedef struct
{
    /* 0x000 */  unsigned int control; /* Interrupt Distributor Control Register (R/W) */
    /* 0x004 */  volatile unsigned int const controller_type; /* Interrupt Controller Type Register (RO) */
    /* 0x008 */  volatile const unsigned int iidr; /* distributor implimenter identification register */
    /* 0x00C */  const unsigned int reserved1[GIC_RESERVED_BEFORE_IGROUPN]; /* Reserved */
    /* 0x080 */  volatile unsigned int igroup[GIC_NUM_REGISTERS]; /* group registers, 32 */
    /* 0x100 */  struct set_and_clear_regs enable; /* Interrupt Set/Clear Enable Registers (R/W) */
	/* 0x200 */  struct set_and_clear_regs pending; /* Interrupt Set/Clear Pending Registers (R/W) */
    /* 0x300 */  struct set_and_clear_regs active; /* Interrupt Active Bit Registers (R/W) */
    /* 0x400 */  volatile unsigned int priority[GIC_PRIORITY_REGISTERS]; /* Interrupt Priority Registers (R/W) */
    /* 0x800 */  volatile unsigned int target[GIC_TARGET_REGISTERS]; /* Interrupt CPU Target Registers (R/W) */
    /* 0xC00 */  volatile unsigned int configuration[GIC_CONFIG_REGISTERS]; /* Interrupt Configuration Registers (R/W) */
    /* 0xD00 */  const unsigned int reserved3[GIC_RESERVED_BEFORE_NSACR_INT]; /* Reserved */
    /* 0xE00 */  volatile unsigned int nsacr[GIC_NSACR_REGISTERS]; /* non secure access control reigsters */
    /* 0xF00 */  volatile unsigned int software_interrupt; /* Software Interrupt Register (RO) */
    /* 0xF04 */  const unsigned int reserved4[GIC_RESERVED_BEFORE_CLRPENDING]; /* Reserved */
    /* 0xF10 */  volatile unsigned int sgi_clrpending[GIC_SGI_REGISTERS]; /* sgi clear pending registers */
    /* 0xF20 */  volatile unsigned int sgi_setpending[GIC_SGI_REGISTERS]; /* sgi clear pending registers */
    /* 0xF30 */  const unsigned int reserved5[GIC_RESERVED_BEFORE_IDENTIFICATION]; /* Reserved */
    /* 0xFE0 */  volatile unsigned int const peripheral_id[GIC_PERIPHERAL_ID]; /* Peripheral Identification Registers (RO) */
    /* 0xFF0 */  volatile unsigned int const primecell_id[GIC_PRIMECELL_ID]; /* PrimeCell Identification Registers (RO) */
} gic_distributor;

typedef struct
{
    /* 0x00 */  volatile unsigned int control; /* Control Register (R/W) */
    /* 0x04 */  volatile unsigned int priority_mask; /* Priority Mask Register (R/W) */
    /* 0x08 */  volatile unsigned int binary_point; /* Binary Point Register (R/W) */
    /* 0x0C */  volatile unsigned int const interrupt_ack; /* Interrupt Acknowledge Register (R) */
    /* 0x10 */  volatile unsigned int end_of_interrupt; /* End of Interrupt Register (W) */
    /* 0x14 */  volatile unsigned int const running_priority; /* Running Priority Register (R) */
    /* 0x18 */  volatile unsigned int const highest_pending; /* Highest Pending Interrupt Register (R) */
    /* 0x1c */  volatile unsigned int alias_binary_point; /* aliased Binary Point Register (R/W) */
    /* 0x20 */  volatile unsigned int alias_interrupt_ack; /* aliased Interrupt Acknowledge Register (R/W) */
    /* 0x24 */  volatile unsigned int alias_end_of_interrupt; /* aliased End of Interrupt Register (W) */
    /* 0x28 */  volatile unsigned int const alias_highest_pending; /* aliased Highest Pending Interrupt Register (R) */
    /* 0x2C */  unsigned int const reserved1[GIC_RESERVED_BEFORE_ACTIVE_PRIORITY]; /* reserved */
    /* 0xD0 */  volatile unsigned int active_priority[4]; /* active priority registers */
    /* 0xE0 */  volatile unsigned int ns_active_priority[4]; /* non-secure active priority registers */
} gic_cpu_interface;

static gic_distributor * const id = (gic_distributor *)(GICD_BASE);
static gic_cpu_interface * const ci = (gic_cpu_interface *)(GICC_BASE);

void gic_distributor_init (void)
{
	unsigned int i;

	id->control = 0x00000000;
	for (i = 0; i < NO_OF_INTERRUPTS_IMPLEMENTED / 32; i++) {
		id->enable.clear[i] = 0xFFFFFFFF;
	}
	for (i = 1; i < NO_OF_INTERRUPTS_IMPLEMENTED / 32; i++) {
		id->pending.clear[i] = 0xFFFFFFFF;
	}
	for (i = 0; i < NO_OF_INTERRUPTS_IMPLEMENTED / 32; i++) {
		id->igroup[i] = 0x00000000;
	}
	for (i = 8; i < NO_OF_INTERRUPTS_IMPLEMENTED / 4; i++) {
		id->priority[i] = 0xC0C0C0C0;
	}
	for (i = 0; i < NO_OF_INTERRUPTS_IMPLEMENTED / 4; i++) {
		id->target[i] = 0xffffffff;
	}
	for (i = 2; i < NO_OF_INTERRUPTS_IMPLEMENTED / 16; i++) {
		id->configuration[i] = 0x55555555;
	}
	id->control = 0x00000003;
}


void gic_cpu_interface_init (void)
{
	unsigned int i;

	id->pending.clear[0] = 0xFFFFFFFF;
	for (i = 0; i < 8; i++) {
		id->priority[i] = 0x00000000;
	}
	id->configuration[0] = 0xAAAAAAAA; // (SGIs)
	id->configuration[1] = 0xAAAAAAAA; // (PPIs)

	ci->control = 0x00000000;
	ci->priority_mask = 0x000000F0;
	ci->binary_point = 0x00000003;

	do {
		unsigned int temp;

		temp = ci->interrupt_ack;

		if ((temp & INTERRUPT_MASK) == SPURIOUS_INTERRUPT)
			break;

		ci->end_of_interrupt = temp;
	} while (1);

	ci->control = 0x00000003;
}

void gic_interrupt_enable (unsigned int interrupt, unsigned int enable)
{
	unsigned int word;

	word = interrupt / 32;
	interrupt %= 32;
	interrupt = 1 << interrupt;

	if (enable) {
	       id->enable.set[word]  =	interrupt;
	} else {
	       id->enable.clear[word]   = interrupt;
	}
}

unsigned int gic_interrupt_acknowledge (void)
{
	return ci->interrupt_ack;
}

void gic_interrupt_endofinterrupt (unsigned int raw_interrupt)
{
	ci->end_of_interrupt = raw_interrupt;
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
	memset(handlers,0,sizeof(handlers));

	if(id->control & 0x3)
		return 0;

	gic_distributor_init();
	gic_cpu_interface_init();

	return 0;
}

void irq_handler_register(int irq_num,tHandler func)
{
	handlers[irq_num] = func;
}

#endif
