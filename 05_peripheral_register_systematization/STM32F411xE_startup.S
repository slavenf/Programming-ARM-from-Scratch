.syntax unified
.cpu cortex-m4
.thumb

@ -----------------------------------------------------------------------------

.section .vector_table, "a"

vector_table:
    .word   __stack_end
    .word   Reset_Handler
    .space  0x3f8

@ -----------------------------------------------------------------------------

.text

.type Reset_Handler, "function"
Reset_Handler:
    bl main
    b .
