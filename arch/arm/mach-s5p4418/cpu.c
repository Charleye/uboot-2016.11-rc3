/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/alive.h>
#include <asm/arch/rtc.h>
#include <asm/arch/tieoff.h>

int arch_cpu_init (void)
{
    u32 val;
    flush_dcache_all();

    /* Alive Power Gate must enble for RTC register access. */
    writel(1, &S5P4418_ALIVE->PWRGATE);
    writel(0xFFFFFFFF, &S5P4418_RTC->SCRATCH);

    /* Control for ACP register access. */
    val = readl(&S5P4418_TIEOFF->REG[28]);
    val &= ~((3 << 30) | (3 << 10));
    writel(val, &S5P4418_TIEOFF->REG[28]);

    val = readl(&S5P4418_TIEOFF->REG[32]);
    val &= ~(3 << 3);
    writel(val, &S5P4418_TIEOFF->REG[32]);

    return 0;
}

void reset_cpu(ulong addr)
{

}

int dram_init(void)
{
    return 0;
}

#ifdef CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
    return 0;
}
#endif
