#ifndef _S5P4418_CPU_H
#define _S5P4418_CPU_H

#define S5P4418_CPU_NAME    "S5P4418"

#define S5P4418_CLOCK_BASE  0xC0010000
#define S5P4418_GPIOA_BASE  0xC001A000
#define S5P4418_GPIOB_BASE  0xC001B000
#define S5P4418_GPIOC_BASE  0xC001C000
#define S5P4418_GPIOD_BASE  0xC001D000
#define S5P4418_GPIOE_BASE  0xC001E000
#define S5P4418_UART0_BASE  0xC00A9000
#define S5P4418_UART1_BASE  0xC00A8000
#define S5P4418_UART2_BASE  0xC00AA000
#define S5P4418_UART3_BASE  0xC00AB000
#define S5P4418_UART4_BASE  0xC006E000
#define S5P4418_UART5_BASE  0xC0084000
#define S5P4418_TIMER_BASE  0xC0017000

#define S5P4418_BASE(device,base)       \
static inline unsigned long __attribute__((no_instrument_function)) \
    s5p4418_get_base_##device(void)     \
{                                       \
    return S5P4418_##base;              \
}

S5P4418_BASE(clock, CLOCK_BASE)
S5P4418_BASE(uart0, UART0_BASE)
S5P4418_BASE(uart1, UART1_BASE)
S5P4418_BASE(uart2, UART2_BASE)
S5P4418_BASE(uart3, UART3_BASE)
S5P4418_BASE(timer, TIMER_BASE)

#endif
