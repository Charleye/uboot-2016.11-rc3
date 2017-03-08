/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 * Refer to arch/arm/cpu/armv7/s5p-common/timer.c
 *
 */

#include <common.h>
#include <div64.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/pwm.h>
#include <asm/arch/clk.h>
#include <asm/arch/rstcon.h>

/* Use the old PWM interface for now */
#undef CONFIG_DM_PWM
#include <pwm.h>

DECLARE_GLOBAL_DATA_PTR;

static inline struct s5p4418_timer *get_base_timer(void)
{
    return (struct s5p4418_timer *)s5p4418_get_base_timer();
}

static unsigned long timer_get_us_dowm(void)
{
    struct s5p4418_timer *const timer = get_base_timer();

    return readl(&timer->tcnto4);
}

int timer_init(void)
{
    s5p4418_ip_reset(IP_RESET_PWMTIMER_1);

    pwm_init(4, MUX_DIV_4, 0);
    pwm_config(4, 100000, 100000);
    pwm_enable(4);

    gd->arch.timer_reset_value = 0;

    gd->arch.lastinc = timer_get_us_dowm();
    reset_timer_masked();

    return 0;
}

unsigned long __attribute__((no_instrument_function)) timer_get_us(void)
{
    static unsigned long base_time_us;

    struct s5p4418_timer *const timer =
        (struct s5p4418_timer *)get_base_timer();
    unsigned long now_downward_us = readl(&timer->tcnto4);

    if (!base_time_us)
        base_time_us = now_downward_us;

    return base_time_us - now_downward_us;
}

/* timer without interrupts */
void __udelay(unsigned long usec)
{
    unsigned long count_value;

    count_value = timer_get_us_dowm();
    while ((int)(count_value - timer_get_us_dowm()) < (int)usec)
        ;
}

ulong get_timer(ulong base)
{
    unsigned long long time_ms;

    ulong now = timer_get_us_dowm();

    gd->arch.timer_reset_value += gd->arch.lastinc - now;
    gd->arch.lastinc = now;

    time_ms = gd->arch.timer_reset_value;
    do_div(time_ms, 1000);

    return time_ms - base;
}

void reset_timer_masked(void)
{
    struct s5p4418_timer *const timer = get_base_timer();

    gd->arch.lastinc = readl(&timer->tcnto4);
    gd->arch.tbl = 0;
}

unsigned long long get_ticks(void)
{
    return get_timer(0);
}

/*
 * This function is derived from PowerPC code (timebase clock frequency)
 * on ARM it returns the number of timer ticks per second
 */
unsigned long get_tbclk(void)
{
    return CONFIG_SYS_HZ;
}
