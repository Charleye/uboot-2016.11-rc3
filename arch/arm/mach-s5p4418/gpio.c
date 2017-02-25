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

#define S5P4418_GPIO_GET_PIN(x) (x % GPIO_PER_BANK)

#define CFG_MASK(val)           (0x3 << ((val) << 1))
#define CFG_SFR(gpio, cfg)      ((cfg) << ((gpio) << 1))
#define CFG_SFR_UNSHIFT(val, gpio)  ((val) >> ((gpio) << 1))

#define DAT_MASK(gpio)          (0x1 << (gpio))
#define DAT_SET(gpio)           (0x1 << (gpio))

#define DIRECTION_MASK(gpio)    (0x1 << (gpio))
#define DIRECTION_SET(gpio)     (0x1 << (gpio))

#define PULL_MASK(gpio)         (0x1 << (gpio))
#define PULL_SET(gpio)          (0x1 << (gpio))

int s5p4418_gpio_get_pin(unsigned int gpio)
{
    return S5P4418_GPIO_GET_PIN(gpio);
}

static struct s5p4418_gpio_bank *s5p4418_gpio_get_bank(unsigned int gpio)
{
    const struct gpio_info *data;
    unsigned int upto;
    int count, i;

    data = get_gpio_data();
    count = get_bank_num();
    upto = 0;

    for (i = 0; i < count; i++) {
        debug("i=%d, upto=%d\n", i, upto);
        if (gpio < data->max_gpio) {
            struct s5p4418_gpio_bank *bank;
            bank = (struct s5p4418_gpio_bank *)data->reg_addr;
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

static unsigned int s5p4418_gpio_get_cfg_pin(struct s5p4418_gpio_bank *bank, int gpio)
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
    value |= (!!en) << gpio;
    writel(value, &bank->out);
}

static unsigned int s5p4418_gpio_get_value(struct s5p4418_gpio_bank *bank, int gpio)
{
    unsigned int value;

    value = readl(&bank->pad);
    return !!(value & DAT_MASK(gpio));
}

static void s5p4418_gpio_set_direction(struct s5p4418_gpio_bank *bank, int gpio, int dir)
{
    unsigned int value;

    switch (dir) {
    case S5P4418_GPIO_INPUT:
        value = readl(&bank->outenb);
        value &= ~DIRECTION_MASK(gpio);
        writel(value, &bank->outenb);
        break;
    case S5P4418_GPIO_OUTPUT:
        value = readl(&bank->outenb);
        value |= DIRECTION_SET(gpio);
        writel(value, &bank->outenb);
        break;
    default:
        break;
    }
}

static void s5p4418_gpio_set_pull(struct s5p4418_gpio_bank *bank, int gpio, int mode)
{
    unsigned int value;

    switch (mode) {
    case S5P4418_GPIO_PULL_DOWN:
        value = readl(&bank->pullsel);
        value &= ~PULL_MASK(gpio);
        writel(value, &bank->pullsel);
        value = readl(&bank->pullenb);
        value |= PULL_SET(gpio);
        writel(value, &bank->pullenb);
        break;
    case S5P4418_GPIO_PULL_UP:
        value = readl(&bank->pullsel);
        value &= PULL_MASK(gpio);
        writel(value, &bank->pullsel);
        value = readl(&bank->pullenb);
        value |= PULL_SET(gpio);
        writel(value, &bank->pullenb);
        break;
    case S5P4418_GPIO_PULL_NONE:
        value = readl(&bank->pullenb);
        value &= ~PULL_MASK(gpio);
        writel(value, &bank->pullenb);
        break;
    default:
        break;
    }

    value = readl(&bank->pullsel_disa);
    value |= PULL_SET(gpio);
    writel(value, &bank->pullsel_disa);
    value = readl(&bank->pullenb_disa);
    value |= PULL_SET(gpio);
    writel(value, &bank->pullenb_disa);
}

void gpio_set_pull(int gpio, int mode)
{
    s5p4418_gpio_set_pull(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio), mode);
}

void gpio_set_drv(int gpio, int mode)
{
}

int gpio_set_value(unsigned gpio, int value)
{
    s5p4418_gpio_set_value(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio), value);

    return 0;
}

int gpio_get_value(unsigned gpio)
{
    return s5p4418_gpio_get_value(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio));
}

void gpio_cfg_pin(int gpio, int cfg)
{
    s5p4418_gpio_cfg_pin(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio), cfg);
}

unsigned int gpio_get_cfg_pin(int gpio)
{
    return s5p4418_gpio_get_cfg_pin(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio));
}

int gpio_direction_input(unsigned gpio)
{
    s5p4418_gpio_set_direction(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio), S5P4418_GPIO_INPUT);

    return 0;
}

int gpio_direction_output(unsigned gpio, int value)
{
    s5p4418_gpio_set_direction(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio), S5P4418_GPIO_OUTPUT);

    s5p4418_gpio_set_value(s5p4418_gpio_get_bank(gpio),
            s5p4418_gpio_get_pin(gpio), value);

    return 0;
}

int gpio_test(void)
{
    gpio_set_pull(S5P4418_GPIO_C07, S5P4418_GPIO_PULL_DOWN);
    gpio_direction_output(S5P4418_GPIO_C07, 0x0);

    gpio_set_pull(S5P4418_GPIO_C12, S5P4418_GPIO_PULL_DOWN);
    gpio_direction_output(S5P4418_GPIO_C12, 0x0);

    return 0;
}
