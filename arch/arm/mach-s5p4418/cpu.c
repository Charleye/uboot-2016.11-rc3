/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/alive.h>

int arch_cpu_init (void)
{
    flush_dcache_all();

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
