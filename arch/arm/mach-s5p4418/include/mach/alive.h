#ifndef _S5P4418_ALIVE_H
#define _S5P4418_ALIVE_H

struct s5p4418_alive {
    u32 PWRGATE;
    u32 GPIOASYNCDETECTMODERST;     /* GPIO Async Detect Mode Reset */
};

#define ALIVE_BASE  0xC0010800
#define S5P4418_ALIVE   ((struct s5p4418_alive *)ALIVE_BASE)

#endif
