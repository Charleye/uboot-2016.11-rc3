#ifndef _S5P4418_CLOCK_H
#define _S5P4418_CLOCK_H

#define UART0CLKENB     0xC00A9000
#define UART0CLKGEN     0xC00A9004

void clock_cpu_init(void);
#endif
