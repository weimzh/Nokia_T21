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
	stmfd   sp!, {r6-r12, lr}
	mov	r9, #0x37		/* EnableGrp0 | EnableGrp1NS */
	mov	r8, #0			/* EnableGrp1S | ARE_S | ARE_NS */
	str	r9, [r0, #0]	/* Secure GICD_CTLR */
	ldr	r9, [r0, #4]
	and	r10, r9, #0x1f		/* ITLinesNumber */
	cmp	r10,#0
	beq	1f
	add	r11, r0, #0x84
	mov	r6,#0xd
	lsl	r6,r6,#8
	add	r6,r6,#4
	add	r12, r0, r6
	mov	r9, #~0
	mrs r6, cpsr
	bic r6,r6,#(~0xf)
	cmp r6,#3 /*svc mode*/
	bne	0f
	mov	r8,#~0
	mov	r9,#0
0:	str	r9, [r11], #0x4
	str	r8, [r12], #0x4	/* Config SPIs as Group1NS */
	sub	r10, r10, #0x1
	cmp	r10,#0
	bne	0b
1:
	ldmfd sp!,{r6-r12,pc}
ENDPROC(gic_init_secure)

ENTRY(gic_init_secure_percpu)
	stmfd   sp!, {r5-r12, lr}
	mrs r5, cpsr
	bic r5,r5,#(~0xf)
	cmp r5,#3 /*svc mode*/
	beq 1f
	mrc p15,4,r6,c1,c1,0 //hcr
	orr r6,r6,#0x10  /*enable hcr irq*/
	mcr p15,4,r6,c1,c1,0

1:	mov r9,r0
	mov     r10, #2
	str     r11, [r9, #0x24]
	dsb     st
	isb

	mov     r10, #~0x2
	ldr     r11, [r9, #0x14]
	and     r11, r11, r10
	str     r11, [r9, #0x14]
	dsb     st
	isb

	add     r10, r9, #(1 << 16)     /* SGI_Base */
	mov     r11, #~0
	str     r11, [r10, #0x80]
	mov	r6, #0
	str     r6, [r10, #0xD00]    /* SGIs|*/
	mov     r11, #0x1
	str     r11, [r10, #0x100]

	cmp	r5,#3
	beq	3f
	mrc	p15,4,r10,c12,c9,5 //icc_hsre
	orr     r10, r10, #0xf
	mcr	p15,4,r10,c12,c9,5
	isb
3:
	mov     r10, #0x3
	mcr	p15,0,r10,c12,c12,7 //icc_igrpen1
	isb

	mcr	p15,0,r6,c12,c12,4 //icc_ctlr
	isb

	mov     r10, #(0x1 << 7)
	mcr	p15,0,r10,c4,c6,0
	isb
2:
	ldmfd   sp!, {r5-r12, pc}
ENDPROC(gic_init_secure_percpu)
