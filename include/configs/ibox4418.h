/*
 * Charleye, wangkart@gmail.com
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_SYS_TEXT_BASE        0x42C00000
#define CONFIG_SYS_INIT_SP_ADDR     CONFIG_SYS_TEXT_BASE

#define CONFIG_NR_DRAM_BANKS        4

#define CONFIG_SYS_LOAD_ADDR        0x48000000  /* kernel load address */

#define CONFIG_SYS_L2_PL310
#define CONFIG_SYS_PL310_BASE       0xCF000000

/* Configuration of ENV Blocks on mmc */
#define CONFIG_ENV_SIZE     (16 << 10)  /* 16 KB */

/* Miscellaneous configurable options */
#define CONFIG_SYS_MAXARGS      16

#endif
