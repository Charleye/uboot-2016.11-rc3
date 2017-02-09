/*
 * Charleye, wangkart@gmail.com
 *
 * SPDX-License-Identifier: GPL-2.0+
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define DEBUG
/* input clock of PLL */
#define CONFIG_SYS_CLK_FREQ         24000000

#define CONFIG_SYS_TEXT_BASE        0x42C00000
#define CONFIG_SYS_INIT_SP_ADDR     CONFIG_SYS_TEXT_BASE

#define CONFIG_NR_DRAM_BANKS        4

#define CONFIG_SYS_LOAD_ADDR        0x48000000  /* kernel load address */

#define CONFIG_SYS_L2_PL310
#define CONFIG_SYS_PL310_BASE       0xCF000000

/* SD/MMC configuration */
#define CONFIG_MMC_DEFAULT_DEV      0
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV      CONFIG_MMC_DEFAULT_DEV
#define CONFIG_GENERIC_MMC
#define CONFIG_DWMMC
#define CONFIG_MMC


/* Configuration of ENV Blocks on mmc */
#define CONFIG_ENV_SIZE     (16 << 10)  /* 16 KB */

/* Size of malloc() pool before and after relocation */
#define CONFIG_SYS_MALLOC_LEN   (CONFIG_ENV_SIZE + (80 << 20)) /* 80 MB */

/* Miscellaneous configurable options */
#define CONFIG_SYS_CBSIZE       1024    /* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE       1024    /* Print Buffer Size */
#define CONFIG_SYS_MAXARGS      16      /* max number of command args */

/* FLASH and enviroment organization */
#define CONFIG_SYS_NO_FLASH

/* serial console configuration */
#define CONFIG_PL011_SERIAL
#define CONFIG_CONS_INDEX       0
#define CONFIG_BAUDRATE         115200
#define CONFIG_SYS_BAUDRATE_TABLE   {9600, 19200, 38400, 57600, \
                                    115200, 230400}
#define CONFIG_SYS_SERIAL0      0xC00A1000
#define CONFIG_SYS_SERIAL1      0xC00A0000
#define CONFIG_PL011_CLOCK      50000000    /* 50 MHZ */
#define CONFIG_PL01x_PORTS      { (void*)CONFIG_SYS_SERIAL0, \
                                  (void*)CONFIG_SYS_SERIAL1 }
#endif
