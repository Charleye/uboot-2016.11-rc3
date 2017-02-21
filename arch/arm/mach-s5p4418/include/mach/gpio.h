#ifndef _S5P4418_GPIO_H
#define _S5P4418_GPIO_H

struct s5p4418_gpio_bank {
    unsigned int out;
    unsigned int outenb;
    unsigned int detmode0;
    unsigned int detmode1;
    unsigned int intenb;
    unsigned int det;
    unsigned int pad;
    unsigned char res0[4];
    unsigned int altfn0;
    unsigned int altfn1;
    unsigned int detmodeex;
    unsigned int detenb;
    unsigned int slew;
    unsigned int slew_disable;
    unsigned int drv1;
    unsigned int drv1_disable;
    unsigned int drv0;
    unsigned int drv0_disable;
    unsigned int pullsel;
    unsigned int pullsel_disa;
    unsigned int pullenb;
    unsigned int pullenb_disa;
};

/* GPIO pins per bank */
#define GPIO_PER_BANK   32

enum s5p4418_gpio_pin {
    S5P4418_GPIO_A00,       /* 0 */
    S5P4418_GPIO_A01,
    S5P4418_GPIO_A02,
    S5P4418_GPIO_A03,
    S5P4418_GPIO_A04,
    S5P4418_GPIO_A05,
    S5P4418_GPIO_A06,
    S5P4418_GPIO_A07,
    S5P4418_GPIO_A08,
    S5P4418_GPIO_A09,
    S5P4418_GPIO_A10,
    S5P4418_GPIO_A11,
    S5P4418_GPIO_A12,
    S5P4418_GPIO_A13,
    S5P4418_GPIO_A14,
    S5P4418_GPIO_A15,
    S5P4418_GPIO_A16,
    S5P4418_GPIO_A17,
    S5P4418_GPIO_A18,
    S5P4418_GPIO_A19,
    S5P4418_GPIO_A20,
    S5P4418_GPIO_A21,
    S5P4418_GPIO_A22,
    S5P4418_GPIO_A23,
    S5P4418_GPIO_A24,
    S5P4418_GPIO_A25,
    S5P4418_GPIO_A26,
    S5P4418_GPIO_A27,
    S5P4418_GPIO_A28,
    S5P4418_GPIO_A29,
    S5P4418_GPIO_A30,
    S5P4418_GPIO_A31,

    S5P4418_GPIOA_MAX,  /* 32 0x20 */
    S5P4418_GPIO_B00 = S5P4418_GPIOA_MAX,
};

#endif
