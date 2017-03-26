/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <asm/gpio.h>

DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{
    gd->ram_size = get_ram_size((long *)PHYS_SDRAM_1, PHYS_SDRAM_1_SIZE)
            + get_ram_size((long *)PHYS_SDRAM_2, PHYS_SDRAM_2_SIZE)
            + get_ram_size((long *)PHYS_SDRAM_3, PHYS_SDRAM_3_SIZE)
            + get_ram_size((long *)PHYS_SDRAM_4, PHYS_SDRAM_4_SIZE);

    return 0;
}

void dram_init_banksize(void)
{
    gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
    gd->bd->bi_dram[0].size = get_ram_size((long *)PHYS_SDRAM_1,
                                PHYS_SDRAM_1_SIZE);
    gd->bd->bi_dram[1].start = PHYS_SDRAM_2;
    gd->bd->bi_dram[1].size = get_ram_size((long *)PHYS_SDRAM_2,
                                PHYS_SDRAM_2_SIZE);
    gd->bd->bi_dram[2].start = PHYS_SDRAM_3;
    gd->bd->bi_dram[2].size = get_ram_size((long *)PHYS_SDRAM_3,
                                PHYS_SDRAM_3_SIZE);
    gd->bd->bi_dram[3].start = PHYS_SDRAM_4;
    gd->bd->bi_dram[3].size = get_ram_size((long *)PHYS_SDRAM_4,
                                PHYS_SDRAM_4_SIZE);
}

int board_init(void)
{
    return 0;
}

void board_gpio_init(void)
{
    /* I2C Pin */
}

static int board_uart_init(void)
{
    int err;

    err = s5p4418_pinmux_config(PERIPH_ID_UART0, PINMUX_FLAG_NONE);
    if (err) {
        debug("UART0 not configured\n");
        return err;
    }

    return 0;
}
#ifdef CONFIG_BOARD_EARLY_INIT_F
int board_early_init_f(void)
{
    int err;
    err = board_uart_init();
    if (err) {
        debug("UART init failed\n");
        return err;
    }

    return err;
}
#endif
