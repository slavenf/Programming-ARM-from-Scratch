.syntax unified     @ Unified instruction set syntax.
                    @ See GNU as manual, section 9.4.2.1, page 123.

.cpu cortex-m4      @ Target processor is Cortex-M4.

.thumb              @ Thumb instruction set.
                    @ See PM0214, section 1.3, page 14/262.
                    @ See GNU as manual, section 9.4.4, page 129.

@ Vector table begin.
@ See PM0214, section 2.3.4, page 40/262.

.word 0x20020000    @ Initial SP value (top-of-stack) is set to end od RAM.

.word start + 1     @ Reset handler. +1 to indicate Thumb mode.
                    @ See PM0214, section 2.3.4, page 40/262.

.space 0x3f8        @ Fill the rest with zeros.

@ Vector table end.

start:
    nop                 @ Do Nothing.
    ldr r0, =0x1111     @ Write 0x1111 to register r0.
    ldr r1, =0x2222     @ Write 0x2222 to register r1.
    mov r2, r0          @ Copy content of register r0 to register r2.
    mov r3, r1          @ Copy content of register r1 to register r3.
    b .                 @ Endless loop.
