/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 * Refer to arch/arm/cpu/armv7/s5p-common/timer.c
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/rstcon.h>

int timer_init(void)
{
    s5p4418_ip_reset(IP_RESET_PWMTIMER_1);

    return 0;
}

/* timer without interrupts */
void __udelay(unsigned long usec)
{
}

ulong get_timer(ulong base)
{
    return 0;
}
