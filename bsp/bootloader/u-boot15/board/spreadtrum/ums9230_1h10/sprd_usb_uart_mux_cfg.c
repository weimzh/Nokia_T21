#include <asm/arch/sprd_reg.h>
#include <asm/arch/pinmap.h>
#include <common.h>

/* set uart inf9 as ap_uart1 and inf1 as auddsp_uart0  */
#define PIN_UART_MATRIX_MTX_CFG_VALUE	(0x5BA90C84)
#define PIN_UART_MATRIX_MTX_CFG1_VALUE	(0x000002E2)
#define PIN_UART_SEL	BIT(2)

static void sprd_uart_inf_sel(void)
{
	CHIP_REG_SET(CTL_PIN_BASE + REG_PIN_UART_MATRIX_MTX_CFG, PIN_UART_MATRIX_MTX_CFG_VALUE);
	CHIP_REG_SET(CTL_PIN_BASE + REG_PIN_UART_MATRIX_MTX_CFG1, PIN_UART_MATRIX_MTX_CFG1_VALUE);
}

int read_mux_cfg_flag(void)
{
	if(CHIP_REG_GET(REG_AON_APB_USB_UART_JTAG_MUX))
		return 1;
	else
		return 0;
}

void usb_uart_mux_config(void)
{
	if (CHIP_REG_GET(REG_AON_APB_USB_UART_JTAG_MUX) == PIN_UART_SEL)
		sprd_uart_inf_sel();
}
