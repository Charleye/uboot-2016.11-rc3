/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/arch/pinmux.h>

static void s5p4418_uart_config(int peripheral)
{
}

static void s5p4418_i2c_config(int peripheral, int flags)
{
}

int s5p4418_pinmux_config(int peripheral, int flags)
{
    switch (peripheral) {
    case PERIPH_ID_UART0:
    case PERIPH_ID_UART1:
    case PERIPH_ID_UART2:
    case PERIPH_ID_UART3:
        s5p4418_uart_config(peripheral);
        break;
    case PERIPH_ID_I2C0:
    case PERIPH_ID_I2C1:
    case PERIPH_ID_I2C2:
        s5p4418_i2c_config(peripheral, flags);
    default:
        debug("%s: invalid peripheral %d", __func__, peripheral);
        return -1;
    }

    return 0;
}
