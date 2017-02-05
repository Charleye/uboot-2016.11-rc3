#ifndef _S5P4418_RTC_H
#define _S5P4418_RTC_H

struct s5p4418_rtc {
    u32 CNTWRITE;   /* RTC Time Count Write Register */
    u32 CNTREAD;    /* RTC Time Count Read Register */
    u32 ALARM;      /* Alarm Time Count Set Register */
    u32 CTRL;       /* RTC Control Register */
    u32 INTENB;     /* RTC Interrupt Enable Register */
    u32 INTPND;     /* RTC Interrupt Pending Register */
    u32 CORERSTIMESEL;  /* RTC Core Por Time Select Register */
    u32 SCRATCH;    /* RTC Scratch Register */
};

#define RTC_BASE    0xC0010C00
#define S5P4418_RTC ((struct s5p4418_rtc *)RTC_BASE)

#endif
