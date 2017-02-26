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
    unsigned char res1[16];
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

    S5P4418_GPIOA_MAX_PORT,  /* 32 0x20 */
    S5P4418_GPIO_B00 = S5P4418_GPIOA_MAX_PORT,
    S5P4418_GPIO_B01,
    S5P4418_GPIO_B02,
    S5P4418_GPIO_B03,
    S5P4418_GPIO_B04,
    S5P4418_GPIO_B05,
    S5P4418_GPIO_B06,
    S5P4418_GPIO_B07,
    S5P4418_GPIO_B08,
    S5P4418_GPIO_B09,
    S5P4418_GPIO_B10,
    S5P4418_GPIO_B11,
    S5P4418_GPIO_B12,
    S5P4418_GPIO_B13,
    S5P4418_GPIO_B14,
    S5P4418_GPIO_B15,
    S5P4418_GPIO_B16,
    S5P4418_GPIO_B17,
    S5P4418_GPIO_B18,
    S5P4418_GPIO_B19,
    S5P4418_GPIO_B20,
    S5P4418_GPIO_B21,
    S5P4418_GPIO_B22,
    S5P4418_GPIO_B23,
    S5P4418_GPIO_B24,
    S5P4418_GPIO_B25,
    S5P4418_GPIO_B26,
    S5P4418_GPIO_B27,
    S5P4418_GPIO_B28,
    S5P4418_GPIO_B29,
    S5P4418_GPIO_B30,
    S5P4418_GPIO_B31,

    S5P4418_GPIOB_MAX_PORT,    /* 64 0x40 */
    S5P4418_GPIO_C00 = S5P4418_GPIOB_MAX_PORT,
    S5P4418_GPIO_C01,
    S5P4418_GPIO_C02,
    S5P4418_GPIO_C03,
    S5P4418_GPIO_C04,
    S5P4418_GPIO_C05,
    S5P4418_GPIO_C06,
    S5P4418_GPIO_C07,
    S5P4418_GPIO_C08,
    S5P4418_GPIO_C09,
    S5P4418_GPIO_C10,
    S5P4418_GPIO_C11,
    S5P4418_GPIO_C12,
    S5P4418_GPIO_C13,
    S5P4418_GPIO_C14,
    S5P4418_GPIO_C15,
    S5P4418_GPIO_C16,
    S5P4418_GPIO_C17,
    S5P4418_GPIO_C18,
    S5P4418_GPIO_C19,
    S5P4418_GPIO_C20,
    S5P4418_GPIO_C21,
    S5P4418_GPIO_C22,
    S5P4418_GPIO_C23,
    S5P4418_GPIO_C24,
    S5P4418_GPIO_C25,
    S5P4418_GPIO_C26,
    S5P4418_GPIO_C27,
    S5P4418_GPIO_C28,
    S5P4418_GPIO_C29,
    S5P4418_GPIO_C30,
    S5P4418_GPIO_C31,

    S5P4418_GPIOC_MAX_PORT,     /* 96 0x60 */
    S5P4418_GPIO_D00 = S5P4418_GPIOC_MAX_PORT,
    S5P4418_GPIO_D01,
    S5P4418_GPIO_D02,
    S5P4418_GPIO_D03,
    S5P4418_GPIO_D04,
    S5P4418_GPIO_D05,
    S5P4418_GPIO_D06,
    S5P4418_GPIO_D07,
    S5P4418_GPIO_D08,
    S5P4418_GPIO_D09,
    S5P4418_GPIO_D10,
    S5P4418_GPIO_D11,
    S5P4418_GPIO_D12,
    S5P4418_GPIO_D13,
    S5P4418_GPIO_D14,
    S5P4418_GPIO_D15,
    S5P4418_GPIO_D16,
    S5P4418_GPIO_D17,
    S5P4418_GPIO_D18,
    S5P4418_GPIO_D19,
    S5P4418_GPIO_D20,
    S5P4418_GPIO_D21,
    S5P4418_GPIO_D22,
    S5P4418_GPIO_D23,
    S5P4418_GPIO_D24,
    S5P4418_GPIO_D25,
    S5P4418_GPIO_D26,
    S5P4418_GPIO_D27,
    S5P4418_GPIO_D28,
    S5P4418_GPIO_D29,
    S5P4418_GPIO_D30,
    S5P4418_GPIO_D31,

    S5P4418_GPIOD_MAX_PORT,     /* 128 0x80 */
    S5P4418_GPIO_E00 = S5P4418_GPIOD_MAX_PORT,
    S5P4418_GPIO_E01,
    S5P4418_GPIO_E02,
    S5P4418_GPIO_E03,
    S5P4418_GPIO_E04,
    S5P4418_GPIO_E05,
    S5P4418_GPIO_E06,
    S5P4418_GPIO_E07,
    S5P4418_GPIO_E08,
    S5P4418_GPIO_E09,
    S5P4418_GPIO_E10,
    S5P4418_GPIO_E11,
    S5P4418_GPIO_E12,
    S5P4418_GPIO_E13,
    S5P4418_GPIO_E14,
    S5P4418_GPIO_E15,
    S5P4418_GPIO_E16,
    S5P4418_GPIO_E17,
    S5P4418_GPIO_E18,
    S5P4418_GPIO_E19,
    S5P4418_GPIO_E20,
    S5P4418_GPIO_E21,
    S5P4418_GPIO_E22,
    S5P4418_GPIO_E23,
    S5P4418_GPIO_E24,
    S5P4418_GPIO_E25,
    S5P4418_GPIO_E26,
    S5P4418_GPIO_E27,
    S5P4418_GPIO_E28,
    S5P4418_GPIO_E29,
    S5P4418_GPIO_E30,
    S5P4418_GPIO_E31,

    S5P4418_GPIO_MAX_PORT,  /* 160 0xa0 */
};

struct gpio_info {
    unsigned int reg_addr;
    unsigned int max_gpio;
};

#define S5P4418_GPIO_NUM_BANKS  5
static struct gpio_info s5p4418_gpio_data[S5P4418_GPIO_NUM_BANKS] = {
    {S5P4418_GPIOA_BASE, S5P4418_GPIOA_MAX_PORT},
    {S5P4418_GPIOB_BASE, S5P4418_GPIOB_MAX_PORT},
    {S5P4418_GPIOC_BASE, S5P4418_GPIOC_MAX_PORT},
    {S5P4418_GPIOD_BASE, S5P4418_GPIOD_MAX_PORT},
    {S5P4418_GPIOE_BASE, S5P4418_GPIO_MAX_PORT},
};

static inline struct gpio_info *get_gpio_data(void)
{
    return s5p4418_gpio_data;
}

static inline unsigned int get_bank_num(void)
{
    return S5P4418_GPIO_NUM_BANKS;
}

void gpio_cfg_pin(int gpio, int cfg);
unsigned int gpio_get_cfg_pin(int gpio);
void gpio_set_pull(int gpio, int mode);
int gpio_get_pull(int gpio);
void gpio_set_drv(int gpio, int mode);
int gpio_get_drv(int gpio);
void gpio_set_direction(int gpio, int mode);


int gpio_test(void);

/* Pin Configuration */
#define S5P4418_GPIO_INPUT      0x0
#define S5P4418_GPIO_OUTPUT     0x1
#define S5P4418_GPIO_FUNC(x)    (x)

/* Pull mode */
#define S5P4418_GPIO_PULL_DOWN  0x0
#define S5P4418_GPIO_PULL_UP    0x1
#define S5P4418_GPIO_PULL_NONE  0x2

/* Driver Strength level */
#define S5P4418_GPIO_DRV_1X     0x0
#define S5P4418_GPIO_DRV_2X     0x1
#define S5P4418_GPIO_DRV_3X     0x2

#define S5P4418_GPIO_DRV_FAST   0x0
#define S5P4418_GPIO_DRV_SLOW   0x1

#endif
