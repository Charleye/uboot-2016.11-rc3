/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>

static void clock_uart_init(void)
{
    register volatile u32 val;

    /* Disable to generate clock for UART0 */
    val = readl(UART0CLKENB);
    val &= ~0x04;
    writel(val, UART0CLKENB);

    /* Configure UART0 Clock */
    val = 0x160;    /* 50MHz PLL0 */
    writel(val, UART0CLKGEN);

    /* Enable to generate clock for UART0 */
    val = readl(UART0CLKENB);
    val &= ~0x04;
    val |= 0x04;
    writel(val, UART0CLKENB);
}

int mach_cpu_init(void)
{
    clock_uart_init();

    return 0;
}
