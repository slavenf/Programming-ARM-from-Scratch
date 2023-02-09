.syntax unified
.cpu cortex-m4
.thumb

@ -----------------------------------------------------------------------------

RCC_BASE = 0x40023800
GPIOC_BASE = 0x40020800

RCC_AHB1ENR = RCC_BASE + 0x30
RCC_AHB1ENR_GPIOCEN = 1 << 2

GPIOC_MODER = GPIOC_BASE + 0x0
GPIOC_MODER13_MASK = 0b11 << 26
GPIOC_MODER13_OUTPUT_MODE = 0b01 << 26

GPIOC_BSSR = GPIOC_BASE + 0x18
GPIOC_BSSR_BR13 = 1 << 29
GPIOC_BSSR_BS13 = 1 << 13

LED_BLINK_DELAY = 1000000

@ -----------------------------------------------------------------------------

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
    ldr r1, =GPIOC_MODER13_MASK
    bic r2, r1
    ldr r1, =GPIOC_MODER13_OUTPUT_MODE
    orr r2, r1
    str r2, [r0]

    @ Reset state: GPIOC pin 13 type is set to push-pull
    @ Reset state: GPIOC pin 13 output speed is set to slow
    @ Reset state: GPIOC pin 13 no pull-up nor pull-down

led_off:
    ldr r0, =GPIOC_BSSR
    ldr r1, =GPIOC_BSSR_BS13
    str r1, [r0]

    ldr r0, =LED_BLINK_DELAY
delay1:
    subs r0, #1
    bne delay1

led_on:
    ldr r0, =GPIOC_BSSR
    ldr r1, =GPIOC_BSSR_BR13
    str r1, [r0]

    ldr r0, =LED_BLINK_DELAY
delay2:
    subs r0, #1
    bne delay2

    b led_off
