.syntax unified
.cpu cortex-m4
.thumb

@ -----------------------------------------------------------------------------

.section .vector_table, "a"

vector_table:
    .word   __stack_end
    .word   isr_reset
    .space  0x3f8

@ -----------------------------------------------------------------------------

.text

.type isr_reset, "function"
isr_reset:
    bl main
    b .
