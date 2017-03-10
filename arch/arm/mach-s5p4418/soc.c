/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clk.h>
#include <asm/arch/clock.h>

/* Set clock for uart0 --50MHz, PLL0--*/
static void clock_uart_init(void)
{
    unsigned int val;
    unsigned int set, clr;
    struct s5p4418_clkgen *clkgen =
        (struct s5p4418_clkgen*)s5p4418_get_base_uart0();

    val = readl(&clkgen->clkenb);
    val &= ~CLKGEN;
    writel(val, &clkgen->clkenb);

    clr = CLKSRCSEL0(7) | CLKDIV0(0xFF) | OUTCLKINV0(1);
    set = CLKSRCSEL0(0) | CLKDIV0(0x0B) | OUTCLKINV0(0);
    clrsetbits_le32(&clkgen->clkgen0, clr, set);

    val = readl(&clkgen->clkenb);
    val &= ~CLKGEN;
    val |= CLKGEN;
    writel(val, &clkgen->clkenb);
}

/*
static void clock_timer_init(void)
{
    unsigned int val;
    unsigned int set, clr;
    struct s5p4418_clkgen *clkgen =
        (struct s5p4418_clkgen*)0xC00B9000;

    val = readl(&clkgen->clkenb);
    val &= ~CLKGEN;
    writel(val, &clkgen->clkenb);

    clr = CLKSRCSEL0(7) | CLKDIV0(0xFF) | OUTCLKINV0(1);
    set = CLKSRCSEL0(0) | CLKDIV0(0x05) | OUTCLKINV0(0);
    clrsetbits_le32(&clkgen->clkgen0, clr, set);

    val = readl(&clkgen->clkenb);
    val &= ~CLKGEN;
    val |= CLKGEN;
    writel(val, &clkgen->clkenb);
}
*/

int mach_cpu_init(void)
{
    clock_uart_init();

    return 0;
}
