@ Unified instruction set syntax.
@ See GNU as manual, section 9.4.2.1, page 123 and page 129.
.syntax unified

@ Target processor is Cortex-M4.
@ See GNU as manual, section 9.4.2.1, page 125.
.cpu cortex-m4

@ Thumb instruction set.
@ See PM0214, section 1.3, page 14/262.
@ See GNU as manual, section 9.4.4, page 129.
.thumb

@ -----------------------------------------------------------------------------
@ Vector table.
@ See PM0214, section 2.3.4, page 40/262.

@ Initial SP value (top-of-stack) is set to end od RAM.
.word 0x20020000

@ Reset handler. +1 to indicate that the exception handler is Thumb code.
@ See PM0214, section 2.3.4, page 40/262.
.word start + 1

@ Fill the rest with zeros.
.space 0x3f8

@ -----------------------------------------------------------------------------
@ Program start
start:
    nop                 @ Do Nothing.
    ldr r0, =0x1111     @ Write 0x1111 to register r0.
    ldr r1, =0x2222     @ Write 0x2222 to register r1.
    mov r2, r0          @ Copy content of register r0 to register r2.
    mov r3, r1          @ Copy content of register r1 to register r3.
    b .                 @ Endless loop.
