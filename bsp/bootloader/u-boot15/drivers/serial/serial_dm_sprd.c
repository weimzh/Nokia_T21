/*
 * (C) Copyright 2004
 */
#include <config.h>
#include <common.h>
#include <linux/compiler.h>
#include <dl_channel.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <serial.h>
#include "serial_sprd.h"
#include <clk.h>


typedef struct sprd_serial_platdata
{
	struct sprd_uart_regs *reg;
	void *apbbase;
	unsigned  int eb;
	int id;
	int clk;
	unsigned long int baudRate;
}sprd_serial_platdata;

#define CONSOLE_PORT CONFIG_CONS_INDEX
#define NUM_PORTS (sizeof(port)/sizeof(port[0]))
#define ARM_APB_CLK    26000000UL

/*
 *config serial baudrate
 */
int sprd_serial_setbrg(struct udevice *dev, int baudrate)
{
	struct sprd_serial_platdata *plat = dev->platdata;
	volatile struct sprd_uart_regs *regs = plat->reg;

	u32 divider = ARM_APB_CLK / baudrate;
	regs->uart_ckd0 = divider;

	return	0;
}

/*
 *initial serial,open clk
 */
static int sprd_serial_probe(struct udevice *dev)
{
	struct sprd_serial_platdata *plat = dev->platdata;
	volatile struct sprd_uart_regs *regs = plat->reg;

	/* Enable UART*/
	//sprd_apb_eb(CONSOLE_PORT);
	u32 divider = ARM_APB_CLK / CONFIG_BAUDRATE;
	regs->uart_ckd0 = divider;

	return 0;
}

/*
 *get serial one byte from fifo
 */
static int sprd_serial_getc(struct udevice *dev)
{
	struct sprd_serial_platdata *plat = dev->platdata;
	volatile struct sprd_uart_regs *regs = plat->reg;

	while(!((regs->uart_sts1)&0xff)){}

	return regs->uart_rxd;
}

/*
 *put one byte to serial fifo
 */
static int sprd_serial_putc(struct udevice *dev, const char ch)
{
	struct sprd_serial_platdata *plat = dev->platdata;
	volatile struct sprd_uart_regs *regs = plat->reg;

	while (((regs->uart_sts1)>>8)&0x1ff);

	regs->uart_txd  = ch;

	while(((regs->uart_sts1)>>8)&0x1ff);

	return 0;
}

/*
 * get serial fifo cnt
 */
static int sprd_serial_pending(struct udevice *dev, bool input)
{
	struct sprd_serial_platdata *plat = dev->platdata;
	struct sprd_uart_regs *const regs = plat->reg;
	uint32_t ufstat = regs->uart_sts1;

	if (input)
		return (ufstat & 0xff);
	else
		return (ufstat & 0x1ff) >> 8;
}

/*
 * get platdata from dts
 */
static int sprd_serial_ofdata_to_platdata(struct udevice *dev)
{
	struct sprd_serial_platdata *plat = dev->platdata;

	void __iomem *addr;
	struct clk clk;
	unsigned int val = 0xff;
	int ret;

	addr = dev_read_addr_ptr(dev);
	plat->reg = (struct sprd_uart_regs *)addr;

	/*get clock*/
	/*enable apb clock*/
	ret = clk_get_by_index(dev, 0, &clk);
	if (ret)
		return ret;
	ret = clk_enable(&clk);
	if (ret)
		return ret;
	dev_read_u32u(dev,"id",&val);
	plat->id = val;

	return 0;
}

static const struct dm_serial_ops sprd_serial_ops = {
        .putc = sprd_serial_putc,
        .pending = sprd_serial_pending,
        .getc = sprd_serial_getc,
        .setbrg = sprd_serial_setbrg,
};

static const struct udevice_id sprd_serial_ids[] = {
        { .compatible = "sprd,sc9863-uart" },
        { }
};


void serial_dm_init(void)
{
	int ret = 0;
	struct dm_serial_ops *ops;
	struct udevice *demo_dev;

	ret = uclass_get_device(UCLASS_SERIAL, 1, &demo_dev);
	if(ret) {
		errorf("Can not get serial!\n");
		return ;
	}

	ops = serial_get_ops(demo_dev);
	if (ops->setbrg)
		ops->setbrg(demo_dev, 115200);
	if (ops->getc)
		ops->getc(demo_dev);

}

U_BOOT_DRIVER(sprd_serial) = {
	.name = "sprd-serial",
	.id = UCLASS_SERIAL,
	.of_match = sprd_serial_ids,
	.ofdata_to_platdata = sprd_serial_ofdata_to_platdata,
        .platdata_auto_alloc_size = sizeof(struct sprd_serial_platdata),
	.probe = sprd_serial_probe,
	.ops = &sprd_serial_ops,
	.flags = DM_FLAG_PRE_RELOC,
};

