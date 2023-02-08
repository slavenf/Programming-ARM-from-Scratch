.syntax unified
.cpu cortex-m4
.thumb

.text

.type Reset_Handler, %function
.global Reset_Handler
Reset_Handler:
    b main
