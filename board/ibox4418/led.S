/*
 * LED1:    GPIOC7
 * LED2:    GPIOC12
 *
 */

#include <linux/linkage.h>

ENTRY(led_on)
    ldr r0, =0xC001C004
    ldr r1, [r0]
    orr r1, r1, #(1 << 7)
    str r1, [r0]

    ldr r0, =0xC001C000
    mov r1, #0x00
    str r1, [r0]

1:
    b 1b
    mov pc, lr
ENDPROC(led_on)
