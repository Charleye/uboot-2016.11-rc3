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

static unsigned long get_pll_clk(int pllreg)
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

int clock_cpu_init(void)
{
    printf("PLL0: %ldHz\n", get_pll_clk(PLL0));
    printf("PLL1: %ldHz\n", get_pll_clk(PLL1));

    return 0;
}
