/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <asm/gpio.h>

int board_init(void)
{
    return 0;
}

static void board_gpio_init(void)
{
    /* I2C Pin */
}

static int board_uart_init(void)
{
    int err;

    err = s5p4418_pinmux_config(PERIPH_ID_UART0, PINMUX_FLAG_NONE);
    if (err) {
        debug("UART0 not configured\n");
        return err;
    }

    return 0;
}
#ifdef CONFIG_BOARD_EARLY_INIT_F
int board_early_init_f(void)
{
    int err;
    err = board_uart_init();
    if (err) {
        debug("UART init failed\n");
        return err;
    }

    return err;
}
#endif
