/*
 * Charleye <wangkartx@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#include <common.h>
#include <asm/arch/cpu.h>

int board_init(void)
{
    return 0;
}

static void board_clock_init(void)
{
    struct clkgen *clkgen =
        (struct clkgen*)s5p4418_get_uart0_base();


}
