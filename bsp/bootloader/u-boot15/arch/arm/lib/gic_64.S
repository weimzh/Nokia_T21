/*
 * GIC Initialization Routines.
 *
 * (C) Copyright 2013
 * David Feng <fenghua@phytium.com.cn>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <asm-offsets.h>
#include <config.h>
#include <linux/linkage.h>
#include <asm/gic.h>
#include <asm/macro.h>


#if defined(CONFIG_USE_IRQ)
/*************************************************************************
 *
 * void gic_init_secure(DistributorBase);
 *
 * Initialize secure copy of GIC at EL3.
 *
 *************************************************************************/
ENTRY(gic_init_secure)
	/*
	 * Initialize Distributor
	 * x0: Distributor Base
	 */
	switch_el x9, 3f,2f,1f
3:
#if defined(CONFIG_GICV3)
	mov	w9, #0x37		/* EnableGrp0 | EnableGrp1NS */
					/* EnableGrp1S | ARE_S | ARE_NS */
	str	w9, [x0, GICD_CTLR]	/* Secure GICD_CTLR */
	ldr	w9, [x0, GICD_TYPER]
	and	w10, w9, #0x1f		/* ITLinesNumber */
	cbz	w10, 1f			/* No SPIs */
	add	x11, x0, (GICD_IGROUPRn + 4)
	add	x12, x0, (GICD_IGROUPMODRn + 4)
	mov	w9, #~0
0:	str	w9, [x11], #0x4
	str	wzr, [x12], #0x4	/* Config SPIs as Group1NS */
	sub	w10, w10, #0x1
	cbnz	w10, 0b
	b exit
2:
	mov w9,#0x37
	str     w9, [x0, GICD_CTLR]     /* Secure GICD_CTLR */
	ldr     w9, [x0, GICD_TYPER]
	and     w10, w9, #0x1f          /* ITLinesNumber */
	cbz     w10, 1f
	add     x11, x0, (GICD_IGROUPRn + 4)
	add     x12, x0, (GICD_IGROUPMODRn + 4)
	mov     w9, #~0
0:      str     w9, [x11], #0x4
	str     wzr, [x12], #0x4
	sub     w10, w10, #0x1
	cbnz    w10, 0b

#elif defined(CONFIG_GICV2)
	mov	w9, #0x3		/* EnableGrp0 | EnableGrp1 */
	str	w9, [x0, GICD_CTLR]	/* Secure GICD_CTLR */
	ldr	w9, [x0, GICD_TYPER]
	and	w10, w9, #0x1f		/* ITLinesNumber */
	cbz	w10, 1f			/* No SPIs */
	add	x11, x0, (GICD_IGROUPRn + 4)
	mov	w9, #~0			/* Config SPIs as Grp1 */
0:	str	w9, [x11], #0x4
	sub	w10, w10, #0x1
	cbnz	w10, 0b
	b exit
2:
#endif
1:
exit:
	ret
ENDPROC(gic_init_secure)
#endif


/*************************************************************************
 * For Gicv2:
 * void gic_init_secure_percpu(DistributorBase, CpuInterfaceBase);
 * For Gicv3:
 * void gic_init_secure_percpu(ReDistributorBase);
 *
 * Initialize secure copy of GIC at EL3.
 *
 *************************************************************************/
ENTRY(gic_init_secure_percpu)
	switch_el x9 ,0f,5f,4f
0:
#if defined(CONFIG_GICV3)
	/*
	 * Initialize ReDistributor
	 * x0: ReDistributor Base
	 */
	mrs	x10, mpidr_el1
	lsr	x9, x10, #32
	bfi	x10, x9, #24, #8	/* w10 is aff3:aff2:aff1:aff0 */
	mov	x9, x0
1:	ldr	x11, [x9, GICR_TYPER]
	lsr	x11, x11, #32		/* w11 is aff3:aff2:aff1:aff0 */
	cmp	w10, w11
	b.eq	2f
	add	x9, x9, #(2 << 16)
	b	1b

	/* x9: ReDistributor Base Address of Current CPU */
2:
	mov     w10, #2
	str     w11, [x9, #0x24]
	dsb     st
	isb

	mov	w10, #~0x2
	ldr	w11, [x9, GICR_WAKER]
	and	w11, w11, w10		/* Clear ProcessorSleep */
	str	w11, [x9, GICR_WAKER]
	dsb	st
	isb
3:	ldr	w10, [x9, GICR_WAKER]
	tbnz	w10, #2, 3b		/* Wait Children be Alive */

	add	x10, x9, #(1 << 16)	/* SGI_Base */
	mov	w11, #~0
	str	w11, [x10, GICR_IGROUPRn]
	str	wzr, [x10, GICR_IGROUPMODRn]	/* SGIs|PPIs Group1NS */
	mov	w11, #0x1		/* Enable SGI 0 */
	str	w11, [x10, GICR_ISENABLERn]

	/* Initialize Cpu Interface */
	mrs	x10, ICC_SRE_EL3
	orr	x10, x10, #0xf		/* SRE & Disable IRQ/FIQ Bypass & */
					/* Allow EL2 access to ICC_SRE_EL2 */
	msr	ICC_SRE_EL3, x10
	isb

	mrs	x10, ICC_SRE_EL2
	orr	x10, x10, #0xf		/* SRE & Disable IRQ/FIQ Bypass & */
					/* Allow EL1 access to ICC_SRE_EL1 */
	msr	ICC_SRE_EL2, x10
	isb

	mov	x10, #0x3		/* EnableGrp1NS | EnableGrp1S */
	msr	ICC_IGRPEN1_EL3, x10
	isb

	msr	ICC_CTLR_EL3, xzr
	isb

	msr	ICC_CTLR_EL1, xzr	/* NonSecure ICC_CTLR_EL1 */
	isb

	mov	x10, #0x1 << 7		/* Non-Secure access to ICC_PMR_EL1 */
	msr	ICC_PMR_EL1, x10
	isb
	b exit1
5://el2 config
	mrs	x10,hcr_el2
	orr	x10,x10,0x10
	msr	hcr_el2,x10
	mrs     x10, mpidr_el1
	lsr     x9, x10, #32
	bfi     x10, x9, #24, #8
	mov     x9, x0

1:      ldr     x11, [x9, GICR_TYPER]
        lsr     x11, x11, #32           /* w11 is aff3:aff2:aff1:aff0 */
	cmp     w10, w11
	b.eq    2f
	add     x9, x9, #(2 << 16)
	b       1b

        /* x9: ReDistributor Base Address of Current CPU */
2:
	mov     w10, #2
	str     w11, [x9, #0x24]
	dsb     st
	isb
	mov     w10, #~0x2
        ldr     w11, [x9, GICR_WAKER]
        and     w11, w11, w10           /* Clear ProcessorSleep */
        str     w11, [x9, GICR_WAKER]
        dsb     st
        isb

3:      ldr     w10, [x9, GICR_WAKER]
        tbnz    w10, #2, 3b             /* Wait Children be Alive */

	add     x10, x9, #(1 << 16)     /* SGI_Base */
	mov     w11, #~0
	str     w11, [x10, GICR_IGROUPRn]
	str     wzr, [x10, GICR_IGROUPMODRn]    /* SGIs|*/
	mov     w11, #0x1               /* Enable SGI 0
	str     w11, [x10, GICR_ISENABLERn]

	mrs	x10, ICC_SRE_EL2
        orr     x10, x10, #0xf          /* SRE & Disable*/
                                        /* Allow EL1 acc*/
	msr     ICC_SRE_EL2, x10
	isb

	mov     x10, #0x3               /* EnableGrp1NS */
	msr     ICC_IGRPEN1_EL1, x10
	isb

	msr     ICC_CTLR_EL1, xzr       /* NonSecure ICC*/
	isb

	mov     x10, #0x1 << 7
	msr     ICC_PMR_EL1, x10
	isb

#elif defined(CONFIG_GICV2)
	/*
	 * Initialize SGIs and PPIs
	 * x0: Distributor Base
	 * x1: Cpu Interface Base
	 */
	mov	w9, #~0			/* Config SGIs and PPIs as Grp1 */
	str	w9, [x0, GICD_IGROUPRn]	/* GICD_IGROUPR0 */
	mov	w9, #0x1		/* Enable SGI 0 */
	str	w9, [x0, GICD_ISENABLERn]

	/* Initialize Cpu Interface */
	mov	w9, #0x1e7		/* Disable IRQ/FIQ Bypass & */
					/* Enable Ack Group1 Interrupt & */
					/* EnableGrp0 & EnableGrp1 */
	str	w9, [x1, GICC_CTLR]	/* Secure GICC_CTLR */

	mov	w9, #0x1 << 7		/* Non-Secure access to GICC_PMR */
	str	w9, [x1, GICC_PMR]
5:
#endif
4:
exit1:
	ret
ENDPROC(gic_init_secure_percpu)


/*************************************************************************
 * For Gicv2:
 * void gic_kick_secondary_cpus(DistributorBase);
 * For Gicv3:
 * void gic_kick_secondary_cpus(void);
 *
 *************************************************************************/
ENTRY(gic_kick_secondary_cpus)
#if defined(CONFIG_GICV3)
	mov	x9, #(1 << 40)
	msr	ICC_ASGI1R_EL1, x9
	isb
#elif defined(CONFIG_GICV2)
	mov	w9, #0x8000
	movk	w9, #0x100, lsl #16
	str	w9, [x0, GICD_SGIR]
#endif
	ret
ENDPROC(gic_kick_secondary_cpus)


/*************************************************************************
 * For Gicv2:
 * void gic_wait_for_interrupt(CpuInterfaceBase);
 * For Gicv3:
 * void gic_wait_for_interrupt(void);
 *
 * Wait for SGI 0 from master.
 *
 *************************************************************************/
ENTRY(gic_wait_for_interrupt)
#if defined(CONFIG_GICV3)
	gic_wait_for_interrupt_m x9
#elif defined(CONFIG_GICV2)
	gic_wait_for_interrupt_m x0, w9
#endif
	ret
ENDPROC(gic_wait_for_interrupt)
