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
#include <asm/arch/mcus.h>

/* MCU-S: Static Memory Configuration */
static void cpu_bus_init (void)
{
    register volatile u32 val;

    /* Configure Static #0 */
    val = readl(&S5P4418_MCUS->MEMTIMEACS[0]);  /* set TACS to 0x00(1 cycle) */
    val &= ~MCUS0_MASK;
    writel(val, &S5P4418_MCUS->MEMTIMEACS[0]);

    val = readl(&S5P4418_MCUS->MEMTIMECAH[0]);  /* set TCAH to 0x00(1 cycle) */
    val &= ~MCUS0_MASK;
    writel(val, &S5P4418_MCUS->MEMTIMECAH[0]);

    val = readl(&S5P4418_MCUS->MEMTIMECOS[0]);  /* set TCOS to 0x05(6 cycle) */
    val &= ~MCUS0_MASK;
    val |= 0x05;
    writel(val, &S5P4418_MCUS->MEMTIMECOS[0]);

    val = readl(&S5P4418_MCUS->MEMTIMECOH[0]);  /* set TCOH to 0x05(6 cycle) */
    val &= ~MCUS0_MASK;
    val |= 0x05;
    writel(val, &S5P4418_MCUS->MEMTIMECOH[0]);

    val = readl(&S5P4418_MCUS->MEMTIMEACC[0]);  /* set TACC t0 0x00(1 cycle) */
    val &= ~MCUS_MASK;
    writel(val, &S5P4418_MCUS->MEMTIMEACC[0]);

    val = readl(&S5P4418_MCUS->MEMTIMESACC[0]); /* set TSACC to 0x00(1 cycle) */
    val &= ~MCUS_MASK;
    writel(val, &S5P4418_MCUS->MEMTIMESACC[0]);

    val = readl(&S5P4418_MCUS->MEMBW);  /* set bus width to 0x08 */
    val &= ~MCUSBW_MASK;
    writel(val, &S5P4418_MCUS->MEMBW);

    val = readl(&S5P4418_MCUS->MEMBURSTL);   /* Disable read & write in brust mode */
    val &= ~MCUS0_MASK;
    writel(val, &S5P4418_MCUS->MEMBURSTL);

    val = readl(&S5P4418_MCUS->MEMWAIT);    /* Low Active Wait Signal */
    val &= ~(0x03);
    val |= 0x01;
    writel(val, &S5P4418_MCUS->MEMWAIT);

    /* Configure Static #1 */
    val = readl(&S5P4418_MCUS->MEMTIMEACS[0]);  /* set TACS to 0x05(6 cycle) */
    val &= ~MCUS1_MASK;
    val |= 0x50;
    writel(val, &S5P4418_MCUS->MEMTIMEACS[0]);

    val = readl(&S5P4418_MCUS->MEMTIMECAH[0]);  /* set TCAH to 0x05(6 cycle) */
    val &= ~MCUS1_MASK;
    val |= 0x50;
    writel(val, &S5P4418_MCUS->MEMTIMECAH[0]);

    val = readl(&S5P4418_MCUS->MEMTIMECOS[0]);  /* set TCOS to 0x0F(0 cycle) */
    val &= ~MCUS1_MASK;
    val |= 0xF0;
    writel(val, &S5P4418_MCUS->MEMTIMECOS[0]);

    val = readl(&S5P4418_MCUS->MEMTIMECOH[0]);  /* set TCOH to 0x0F(0 cycle) */
    val &= ~MCUS1_MASK;
    val |= 0xF0;
    writel(val, &S5P4418_MCUS->MEMTIMECOH[0]);

    val = readl(&S5P4418_MCUS->MEMTIMEACC[0]);  /* set TACC t0 0x05(6 cycle) */
    val &= ~(MCUS_MASK << 8);
    val |= (0x05 << 8);
    writel(val, &S5P4418_MCUS->MEMTIMEACC[0]);

    val = readl(&S5P4418_MCUS->MEMTIMESACC[0]); /* set TSACC to 0x05(6 cycle) */
    val &= ~(MCUS_MASK << 8);
    val |= (0x05 << 8);
    writel(val, &S5P4418_MCUS->MEMTIMESACC[0]);

    val = readl(&S5P4418_MCUS->MEMBW);  /* set bus width to 0x08 */
    val &= ~(MCUSBW_MASK << 1);
    writel(val, &S5P4418_MCUS->MEMBW);

    val = readl(&S5P4418_MCUS->MEMBURSTL);   /* Disable read & write in brust mode */
    val &= ~MCUS1_MASK;
    writel(val, &S5P4418_MCUS->MEMBURSTL);

    val = readl(&S5P4418_MCUS->MEMWAIT);    /* Low Active Wait Signal */
    val &= ~(0x03 << 2);
    val |= (0x01 << 2);
    writel(val, &S5P4418_MCUS->MEMWAIT);
}

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

    cpu_bus_init();
    return 0;
}

void reset_cpu(ulong addr)
{

}

#ifdef CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
    return 0;
}
#endif
