#ifndef _S5P4418_TIEOFF_H
#define _S5P4418_TIEOFF_H

struct s5p4418_tieoff {
    u32 REG[33];
};

#define TIEOFF_BASE 0xC0011000
#define S5P4418_TIEOFF  ((struct s5p4418_tieoff *)TIEOFF_BASE)

#endif
