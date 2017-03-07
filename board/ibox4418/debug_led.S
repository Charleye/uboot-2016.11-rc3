/*
 * LED1:    GPIOC7
 * LED2:    GPIOC12
 *
 */

#include <linux/linkage.h>

ENTRY(debug_led)
    ldr r0, =0xC001C004
    ldr r1, [r0]
    orr r1, r1, #(1 << 12)
    str r1, [r0]

    ldr r0, =0xC001C000
    ldr r1, [r0]
    bic r1, r1, #(1 << 12)
    str r1, [r0]
ENDPROC(debug_led)
