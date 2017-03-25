/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/rstcon.h>

static void noinline  __udelay__(unsigned long loop)
{
    for(; loop > 0; loop--);
}

static void s5p4418_set_ip(int id, int mode)
{
    unsigned long val;
    unsigned long addr;

    if (id < 32)
        addr = S5P4418_IP_RESET_BASE;
    else if (id < 64)
        addr = S5P4418_IP_RESET_BASE + 0x4;
    else
        return;

    val = readl(addr);
    val &= ~(0x1 << (id & 0x1f));
    val |= (mode ? 1 : 0) << (id & 0x1f);
    writel(val, addr);
}

static unsigned int s5p4418_get_ip(int id)
{
    unsigned long val;
    unsigned long addr;

    if (id < 32)
        addr = S5P4418_IP_RESET_BASE;
    else if (id < 64)
        addr = S5P4418_IP_RESET_BASE + 0x4;
    else
        return 1;

    val = readl(addr);
    return (val >> (id & 0x1f)) & 0x1;
}

void s5p4418_ip_reset(int id)
{
    if (!s5p4418_get_ip(id))
    {
        s5p4418_set_ip(id, 0);
        __udelay__(10);
        s5p4418_set_ip(id, 1);
    }
}
