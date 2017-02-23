/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/gpio.h>

#define CFG_MASK(val)           (0x3 << ((val) << 1))
#define CFG_SFR(gpio, cfg)      ((cfg) << ((gpio) << 1))
#define CFG_SFR_UNSHIFT(val, gpio)  ((val) >> ((gpio) << 1))

#define DAT_MASK(gpio)          (0x1 << (gpio))
#define DAT_SET(gpio)           (0x1 << (gpio))

static struct s5p4418_gpio_bank *s5p4418_gpio_get_bank(unsigned int gpio)
{
    const struct gpio_info *data;
    unsigned int upto;
    int count, i;

    data = get_gpio_data();
    count = get_bank_num();
    upto = 0;

    for (i = 0; i < count; i ++) {
        debug("i=%d, upto=%d\n", i, upto);
        if (gpio < data->max_gpio) {
            struct s5p4418_gpio_bank *bank;
            bank = (struct s5p4418_gpio_bank *)data->reg_addr;
            bank += (gpio - upto) / GPIO_PER_BANK;
            debug("gpio=%d,bank=%p\n", gpio, bank);
            return bank;
        }

        upto = data->max_gpio;
        data++;
    }

    return NULL;
}

static void s5p4418_gpio_cfg_pin(struct s5p4418_gpio_bank *bank, int gpio, int cfg)
{
    unsigned int value;

    if (gpio >> 4) {
        value = readl(&bank->altfn1);
        value &= ~CFG_MASK(gpio % 16);
        value |= CFG_SFR(gpio % 16, cfg);
        writel(value, &bank->altfn1);
    } else {
        value = readl(&bank->altfn0);
        value &= ~CFG_MASK(gpio);
        value |= CFG_SFR(gpio, cfg);
        writel(value, &bank->altfn0);
    }
}

static unsigned int s5p4418_gpio_get_cfg(struct s5p4418_gpio_bank *bank, int gpio)
{
    unsigned int value;

    if (gpio >> 4) {
        value = readl(&bank->altfn1);
        value &= CFG_MASK(gpio % 16);
        value = CFG_SFR_UNSHIFT(value, gpio % 16);
    } else {
        value = readl(&bank->altfn0);
        value &= CFG_MASK(gpio);
        value = CFG_SFR_UNSHIFT(value, gpio);
    }

    return value;
}

static void s5p4418_gpio_set_value(struct s5p4418_gpio_bank *bank, int gpio, int en)
{
    unsigned int value;

    value = readl(&bank->out);
    value &= ~DAT_MASK(gpio);
    if (en)
        value |= DAT_SET(gpio);
    writel(value, &bank->out);
}

static unsigned int s5p4418_gpio_get_value(struct s5p4418_gpio_bank *bank, int gpio)
{
    unsigned int value;

    value = readl(&bank->out);
    return !!(value & DAT_MASK(gpio));
}

void gpio_set_pull(int gpio, int mode)
{
}

void gpio_set_drv(int gpio, int mode)
{
}

void gpio_cfg_pin(int gpio, int cfg)
{
}

int gpio_test(void)
{
    s5p4418_gpio_get_bank(S5P4418_GPIO_D01);

    return 0;
}
