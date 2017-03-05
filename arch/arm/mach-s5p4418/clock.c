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
#include <asm/arch/periph.h>
#include <asm/arch/pwm.h>

#define PLL_DIV_65536   65536

static int s5p4418_get_pll_clk(int pllreg, unsigned int r, unsigned int k)
{
    unsigned long m, p, s = 0, fout;
    unsigned int freq;

    freq = CONFIG_SYS_CLK_FREQ;

    m = (r >> 8) & 0x3ff;
    p = (r >> 18) & 0x3f;
    s = r & 0xff;

    if (pllreg == PLL0 || pllreg == PLL1)
    {
        fout = m * (freq / (p * (1 << s)));
    }
    else
        fout = (m + k / PLL_DIV_65536) * (freq / (p * (1 << s)));

    return fout;
}

static unsigned long s5p4418_get_uart_clk(int dev_index)
{
    struct s5p4418_clkgen *clkgen = NULL;
    unsigned long uclk, sclk;
    unsigned int sel;
    unsigned int ratio;

    switch (dev_index) {
    case PERIPH_ID_UART0:
        clkgen = (struct s5p4418_clkgen*)s5p4418_get_base_uart0();
        break;
    case PERIPH_ID_UART1:
        clkgen = (struct s5p4418_clkgen*)s5p4418_get_base_uart1();
        break;
    case PERIPH_ID_UART2:
        clkgen = (struct s5p4418_clkgen*)s5p4418_get_base_uart2();
        break;
    case PERIPH_ID_UART3:
        clkgen = (struct s5p4418_clkgen*)s5p4418_get_base_uart3();
        break;
    }

    sel = readl(&clkgen->clkgen0);
    sel = (sel >> 2) & 0x7;

    if (sel == 0x00)
        sclk = get_pll_clk(PLL0);
    else if (sel == 0x01)
        sclk = get_pll_clk(PLL1);
    else if (sel == 0x02)
        sclk = get_pll_clk(PLL2);
    else
        return 0;

    ratio = readl(&clkgen->clkgen0);
    ratio = (ratio >> 5) & 0xff;

    uclk = sclk / (ratio + 1);
    return uclk;
}

static unsigned long s5p4418_get_sys_bus_clk(int name)
{
    struct s5p4418_clock *clk =
        (struct s5p4418_clock *)s5p4418_get_base_clock();
    unsigned long sclk, uclk = 0;
    unsigned int sel;
    unsigned int ratio;

    sel = readl(&clk->div[1]) & 0x7;
    if (sel == 0x00)
        sclk = get_pll_clk(PLL0);
    else if (sel == 0x01)
        sclk = get_pll_clk(PLL1);
    else if (sel == 0x02)
        sclk = get_pll_clk(PLL2);
    else
        return 0;

    if (name == BCLK) {
        ratio = readl(&clk->div[1]);
        ratio = (ratio >> 3) & 0x3f;
        uclk = sclk / (ratio + 1);
    } else if (name == PCLK) {
        ratio = readl (&clk->div[1]);
        ratio = (ratio >> 3) & 0x3f;
        uclk = sclk / (ratio + 1);
        ratio = readl (&clk->div[1]);
        ratio = (ratio >> 9) & 0x3f;
        uclk = uclk / (ratio + 1);
    }

    return uclk;
}

unsigned long get_pll_clk(int pllreg)
{
    struct s5p4418_clock *clk =
        (struct s5p4418_clock *)s5p4418_get_base_clock();
    unsigned long r, k = 0;

    switch (pllreg) {
    case PLL0:
        r = readl(&clk->pllset[0]);
        break;
    case PLL1:
        r = readl(&clk->pllset[1]);
        break;
    case PLL2:
        r = readl(&clk->pllset[2]);
        k = readl(&clk->pllss[2]);
        break;
    case PLL3:
        r = readl(&clk->pllset[3]);
        k = readl(&clk->pllss[3]);
        break;
    default:
        printf("Unsupported PLL (%d)\n", pllreg);
        return 0;
    }

    return s5p4418_get_pll_clk(pllreg, r, k);
}

unsigned long get_uart_clk(int dev_index)
{
    enum periph_id id;

    switch (dev_index) {
    case 0:
        id = PERIPH_ID_UART0;
        break;
    case 1:
        id = PERIPH_ID_UART1;
        break;
    case 2:
        id = PERIPH_ID_UART2;
        break;
    case 3:
        id = PERIPH_ID_UART3;
    default:
        debug("%s: invalid UART index %d", __func__, dev_index);
        return -1;
    }
    return s5p4418_get_uart_clk(id);
}

unsigned long get_clock_rate(int name)
{
    switch (name) {
    case FCLK:
    case HCLK:
        break;
    case BCLK:
    case PCLK:
        return s5p4418_get_sys_bus_clk(name);

    default:
        debug("%s: invaild clock name %d", __func__, name);
        return -1;
    }
    return 0;
}

unsigned long get_pwm_clk(void)
{
    return get_clock_rate(PCLK);
}


int clock_cpu_init(void)
{
    printf("PLL0: %ldHz\n", get_pll_clk(PLL0));
    printf("PLL1: %ldHz\n", get_pll_clk(PLL1));
    printf("UART0: %ldHz\n", get_uart_clk(0));
    printf("UART1: %ldHz\n", get_uart_clk(1));
    printf("BCLK: %ldHz\n", s5p4418_get_sys_bus_clk(BCLK));
    printf("PCLK: %ldHZ\n", s5p4418_get_sys_bus_clk(PCLK));

    return 0;
}
