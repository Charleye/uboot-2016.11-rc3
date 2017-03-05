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
#include <asm/arch/pwm.h>
#include <asm/arch/cpu.h>

/* Use the old PWM interface for now */
#undef CONFIG_DM_PWM
#include <pwm.h>

DECLARE_GLOBAL_DATA_PTR;

/* macro to read the 32-bit timer */
static inline struct s5p4418_timer *s5p_get_base_timer(void)
{
    return (struct s5p4418_timer *)s5p4418_get_base_timer();
}

/* return current value of timer */
static unsigned long timer_get_us_down(void)
{
    struct s5p4418_timer *const timer =
            (struct s5p4418_timer *)s5p4418_get_base_timer();

    return readl(&timer->tcnto4);
}

int timer_init(void)
{
    /* PWM Timer 4 */
    pwm_init(4, MUX_DIV_4, 0);
    pwm_config(4, 100000, 100000);
    pwm_enable(4);

    /* Use this as the current monotonic time in us */
    gd->arch.timer_reset_value = 0;

    /* Use this as the last timer value we saw */
    gd->arch.lastinc = timer_get_us_down();
    reset_timer_masked();

    return 0;
}

/* timer without interrupts */
ulong get_timer(ulong base)
{
    unsigned long long time_ms;

    unsigned long now = timer_get_us_down();

    gd->arch.timer_reset_value += gd->arch.lastinc - now;
    gd->arch.lastinc = now;

    /* Divide by 1000 to convert from us to ms */
    time_ms = gd->arch.timer_reset_value;
    do_div(time_ms, 1000);
    return time_ms -base;
}

unsigned long __attribute__((no_instrument_function)) timer_get_us(void)
{
    static unsigned long base_time_us;

    struct s5p4418_timer *const timer =
        (struct s5p4418_timer *)s5p4418_get_base_timer();
    unsigned long now_downward_us = readl(&timer->tcnto4);

    if (!base_time_us)
        base_time_us = now_downward_us;

    /* Note that this timer counts downward */
    return base_time_us - now_downward_us;
}

/* delay x useconds */
void __udelay(unsigned long usec)
{
    unsigned long count_value;

    count_value = timer_get_us_down();
    while ((int)(count_value - timer_get_us_down()) < (int)usec)
        ;
}

void reset_timer_masked(void)
{
    struct s5p4418_timer *const timer =
            (struct s5p4418_timer *)s5p4418_get_base_timer();

    /* reset timer */
    gd->arch.lastinc = readl(&timer->tcnto4);
    gd->arch.tbl = 0;
}

unsigned long long get_ticks(void)
{
    return get_timer(0);
}

unsigned long get_tbclk(void)
{
    return CONFIG_SYS_HZ;
}
