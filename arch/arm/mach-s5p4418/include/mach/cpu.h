#ifndef _S5P4418_CPU_H
#define _S5P4418_CPU_H

#define S5P4418_CPU_NAME    "S5P4418"

#define S5P4418_CLOCK_BASE  0xC0010000

#define S5P4418_BASE(device,base)       \
static inline unsigned long __attribute__((no_instrument_function)) \
    s5p4418_get_base_##device(void)     \
{                                       \
    return S5P4418_##base;              \
}

S5P4418_BASE(clock, CLOCK_BASE)

#endif
