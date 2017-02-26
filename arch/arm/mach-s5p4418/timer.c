/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/pwm.h>
#include <asm/arch/cpu.h>

/* Use the old PWM interface for now */
#undef CONFIG_DM_PWM
#include <pwm.h>

DECLARE_GLOBAL_DATA_PTR;

/* macro to read the 32-bit timer */
static inline struct s5p4418_timer *s5p_get_base_timer(void)
{
    return (s5p4418_timer *)s5p4418_get_base_timer();
}

ulong get_timer(ulong base)
{
    return 0;
}

void __udelay(unsigned long usec)
{
}
