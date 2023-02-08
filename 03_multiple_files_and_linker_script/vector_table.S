.syntax unified
.cpu cortex-m4
.thumb

.section .vector_table, "a"

.word __stack_end
.word Reset_Handler
.space 0x3f8
