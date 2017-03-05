/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 * Refer to arch/arm/cpu/armv7/s5p-common/pwm.c
 *
 */

#include <common.h>
#include <pwm.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/pwm.h>
#include <asm/arch/clk.h>

int pwm_enable(int pwm_id)
{
    const struct s5p4418_timer *pwm =
            (struct s5p4418_timer *)s5p4418_get_base_timer();
    unsigned long tcon;

    tcon = readl(&pwm->tcon);
    tcon |= TCON_START(pwm_id);

    writel(tcon, &pwm->tcon);

    return 0;
}

void pwm_disable(int pwm_id)
{
    const struct s5p4418_timer *pwm =
        (struct s5p4418_timer *)s5p4418_get_base_timer();
    unsigned long tcon;

    tcon = readl(&pwm->tcon);
    tcon &= ~TCON_START(pwm_id);

    writel(tcon, &pwm->tcon);
}

static unsigned long pwm_calc_tin(int pwd_id, unsigned long freq)
{
    unsigned long tin_parent_rate;
    unsigned int div;

    tin_parent_rate = get_pwm_clk();

    for (div = 2; div <= 16; div *= 2) {
        if ((tin_parent_rate / (div << 16)) < freq)
            return tin_parent_rate / div;
    }

    return tin_parent_rate / 16;
}

#define NS_IN_SEC   1000000000UL

int pwm_config(int pwm_id, int duty_ns, int period_ns)
{
    return 0;
}

int pwm_init(int pwm_id, int div, int invert)
{
    return 0;
}

