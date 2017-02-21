/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>

int board_init(void)
{
    return 0;
}

static int board_uart_init(void)
{
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
