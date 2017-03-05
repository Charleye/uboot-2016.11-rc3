#ifndef _S5P4418_CLK_H
#define _S5P4418_CLK_H

#define PLL0    0
#define PLL1    1
#define PLL2    2
#define PLL3    3

#define FCLK    0
#define HCLK    1
#define BCLK    2
#define PCLK    3
#define MDCLK   4
#define MCLK    5
#define MBCLK   6
#define MPCLK   7
#define GR3DBCLK    8
#define MPEGBCLK    9
#define MPEGPCLK    10

#define CLKGEN          (1 << 2)
#define CLKDIV0(x)      (((x) & 0xff) << 5)
#define CLKSRCSEL0(x)   (((x) & 0x07) << 2)
#define OUTCLKINV0(x)   (((x) & 0x01) << 1)

unsigned long get_uart_clk(int dev_index);
unsigned long get_pll_clk(int pllreg);
unsigned long get_pwm_clk(void);
#endif
