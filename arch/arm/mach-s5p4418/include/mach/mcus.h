#ifndef _S5P4418_MCUS_H
#define _S5P4418_MCUS_H

struct s5p4418_mcus {
    u32 MEMBW;              /* Memory Bus Width Register */
    u32 MEMTIMEACS[2];      /* Memory Timing for TACS Register */
    u32 MEMTIMECOS[2];      /* Memory Timing for TCOS Register */
    u32 MEMTIMEACC[4];      /* Memory Timing for TACC Register */
    u32 MEMTIMESACC[4];     /* Memory Timing for TSACC Register */
    u32 __rsvd[4];          /* Reserved */
    u32 MEMTIMECOH[2];      /* Memory Timing for TCOH Register */
    u32 MEMTIMECAH[2];      /* Memory Timing for TCAH Register */
    u32 MEMBURSTL;          /* Memory Burst Control Low Register */
    u32 __rsvd1;
    u32 MEMWAIT;            /* Memory Wait Control Register */
    u32 __rsvd2[7];
};

#define MCUS_BASE   0xC0051000
#define S5P4418_MCUS    ((struct s5p4418_mcus *)MCUS_BASE)

#define MCUS0_MASK  (0x0F)
#define MCUS1_MASK  (0xF0)
#define MCUS_MASK   (0xFF)
#define MCUSBW_MASK (0x01)
#endif
