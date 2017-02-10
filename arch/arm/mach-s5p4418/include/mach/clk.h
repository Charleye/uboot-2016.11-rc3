#ifndef _S5P4418_CLK_H
#define _S5P4418_CLK_H

#define PLL0    0
#define PLL1    1
#define PLL2    2
#define PLL3    3

#define CLKGEN          (1 << 2)
#define CLKDIV0(x)      (((x) & 0xff) << 5)
#define CLKSRCSEL0(x)   (((x) & 0x07) << 2)
#define OUTCLKINV0(x)   (((x) & 0x01) << 1)
#endif
