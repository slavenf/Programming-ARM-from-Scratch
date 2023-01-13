.syntax unified
.cpu cortex-m4
.thumb

.word 0x20020000    @ Top of stack (end od RAM)
.word start         @ Reset handler
.space 0x3f8        @ Fill with zeros

start:
nop                 @ Do Nothing
ldr r0, =0x1111     @ Write 0x1111 to register r0
ldr r1, =0x2222     @ Write 0x2222 to register r1
mov r2, r0          @ Copy content of register r0 to register r2
mov r3, r1          @ Copy content of register r1 to register r3
b .                 @ Endless loop
