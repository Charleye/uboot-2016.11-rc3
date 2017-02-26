/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/gpio.h>
#include <asm/arch/pinmux.h>

static void s5p4418_uart_config(int peripheral)
{
    switch (peripheral) {
    case PERIPH_ID_UART0:
        gpio_cfg_pin(S5P4418_GPIO_D14, S5P4418_GPIO_FUNC(0x1));
        gpio_cfg_pin(S5P4418_GPIO_D18, S5P4418_GPIO_FUNC(0x1));
        gpio_set_direction(S5P4418_GPIO_D14, S5P4418_GPIO_INPUT);
        gpio_set_direction(S5P4418_GPIO_D18, S5P4418_GPIO_OUTPUT);
        break;

    case PERIPH_ID_UART1:
        gpio_cfg_pin(S5P4418_GPIO_D15, S5P4418_GPIO_FUNC(0x1));
        gpio_cfg_pin(S5P4418_GPIO_D19, S5P4418_GPIO_FUNC(0x1));
        gpio_set_direction(S5P4418_GPIO_D15, S5P4418_GPIO_INPUT);
        gpio_set_direction(S5P4418_GPIO_D19, S5P4418_GPIO_OUTPUT);
        break;

    case PERIPH_ID_UART2:
        gpio_cfg_pin(S5P4418_GPIO_D16, S5P4418_GPIO_FUNC(0x1));
        gpio_cfg_pin(S5P4418_GPIO_D20, S5P4418_GPIO_FUNC(0x1));
        gpio_set_direction(S5P4418_GPIO_D16, S5P4418_GPIO_INPUT);
        gpio_set_direction(S5P4418_GPIO_D20, S5P4418_GPIO_OUTPUT);
        break;

    case PERIPH_ID_UART3:
        gpio_cfg_pin(S5P4418_GPIO_D17, S5P4418_GPIO_FUNC(0x1));
        gpio_cfg_pin(S5P4418_GPIO_D21, S5P4418_GPIO_FUNC(0x1));
        gpio_set_direction(S5P4418_GPIO_D17, S5P4418_GPIO_INPUT);
        gpio_set_direction(S5P4418_GPIO_D21, S5P4418_GPIO_OUTPUT);
        break;

    default:
        break;
    }
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
