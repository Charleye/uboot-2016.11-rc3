#ifndef _S5P4418_PINMUX_H
#define _S5P4418_PINMUX_H

#include "periph.h"

enum {
    PINMUX_FLAG_NONE    = 0x00000000,

    /* Flags for I2C */
    PINMUX_FLAG_HS_MODE = 1 << 1,   /* I2C High Speed Mode */
};

int s5p4418_pinmux_config(int peripheral, int flags);
#endif
