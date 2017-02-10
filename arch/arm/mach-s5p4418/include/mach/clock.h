#ifndef _S5P4418_CLOCK_H
#define _S5P4418_CLOCK_H

struct s5p4418_clock {
    unsigned int mode0;
    unsigned int mode1;
    unsigned int pllset[4];
    unsigned char res0[8];
    unsigned int div[5];
    unsigned char res1[20];
    unsigned int pllss[4];  /* PLL setting register for spread spectrum */
    unsigned int rise;      /* GPIO reset enable register */
    unsigned int fall;      /* GPIO wakeup enable */
    unsigned int gpiointenb;    /* GPIO interrupt enable */
    unsigned int gpiointpend;   /* GPIO interrupt pending */
    unsigned int rststat;   /* Reset status */
    unsigned int intenb;    /* Interrupt Enable */
    unsigned int intpend;   /* Interrupt pending */
    unsigned int pwrctrl;   /* Power management control */
    unsigned int pwrmode;   /* Power management mode */
    unsigned char res2[4];
    unsigned int padstrength[3];
    unsigned int rstconfig; /* System reset configuration */
    unsigned char res3[0x1C0];
};

struct clkgen {
    unsigned int clkenb;    /* Clock Enable/Disable */
    unsigned int clkgen0;
    unsigned int clkgen1;
};

int clock_cpu_init(void);
#endif
