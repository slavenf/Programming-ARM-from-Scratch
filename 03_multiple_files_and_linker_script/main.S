.syntax unified
.cpu cortex-m4
.thumb

@ -----------------------------------------------------------------------------
@ Symbols

@ Peripheral base addresses
GPIOC_BASE = 0x40020800
RCC_BASE   = 0x40023800

@ GPIOC peripheral register addresses
GPIOC_MODER = GPIOC_BASE + 0x0
GPIOC_BSSR  = GPIOC_BASE + 0x18

@ RCC peripheral register addresses
RCC_AHB1ENR = RCC_BASE + 0x30

@ Bit definitions for GPIO_MODER register
GPIO_MODER_MODER13_MASK   = 3 << 26
GPIO_MODER_MODER13_OUTPUT = 1 << 26

@ Bit definitions for GPIO_BSSR register
GPIO_BSSR_BR13 = 1 << 29
GPIO_BSSR_BS13 = 1 << 13

@ Bit definitions for RCC_AHB1ENR register
RCC_AHB1ENR_GPIOCEN = 1 << 2

@ LED blink delay
LED_BLINK_DELAY = 1000000

@ -----------------------------------------------------------------------------
@ Main function

.type main, "function"
.global main
main:
    @ Enable GPIOC
    ldr r0, =RCC_AHB1ENR
    ldr r2, [r0]
    ldr r1, =RCC_AHB1ENR_GPIOCEN
    orr r2, r1
    str r2, [r0]

    @ Set GPIOC pin 13 mode to output
    ldr r0, =GPIOC_MODER
    ldr r2, [r0]
    ldr r1, =GPIO_MODER_MODER13_MASK
    bic r2, r1
    ldr r1, =GPIO_MODER_MODER13_OUTPUT
    orr r2, r1
    str r2, [r0]

    @ GPIOC pin 13 type is set to push-pull (this is default after reset)
    @ GPIOC pin 13 output speed is set to slow (this is default after reset)
    @ GPIOC pin 13 no pull-up nor pull-down (this is default after reset)

led_off:
    ldr r0, =GPIOC_BSSR
    ldr r1, =GPIO_BSSR_BS13
    str r1, [r0]

    ldr r0, =LED_BLINK_DELAY
delay1:
    subs r0, #1
    bne delay1

led_on:
    ldr r0, =GPIOC_BSSR
    ldr r1, =GPIO_BSSR_BR13
    str r1, [r0]

    ldr r0, =LED_BLINK_DELAY
delay2:
    subs r0, #1
    bne delay2

    b led_off
