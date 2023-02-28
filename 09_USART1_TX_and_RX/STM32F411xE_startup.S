.syntax unified
.cpu cortex-m4
.thumb

@ -----------------------------------------------------------------------------

.macro HANDLER name
    .global     \name
    .weak       \name
    .thumb_set  \name, Default_Handler
    .word       \name
.endm

.section .vector_table, "a"

vector_table:
    .word       __stack_end                 @ Offset: 0x000
    .word       Reset_Handler               @ Offset: 0x004
    HANDLER     NMI_Handler                 @ Offset: 0x008
    HANDLER     HardFault_Handler           @ Offset: 0x00C
    HANDLER     MemManage_Handler           @ Offset: 0x010
    HANDLER     BusFault_Handler            @ Offset: 0x014
    HANDLER     UsageFault_Handler          @ Offset: 0x018
    .word       0                           @ Offset: 0x01C
    .word       0                           @ Offset: 0x020
    .word       0                           @ Offset: 0x024
    .word       0                           @ Offset: 0x028
    HANDLER     SVCall_Handler              @ Offset: 0x02C
    HANDLER     DebugMonitor_Handler        @ Offset: 0x030
    .word       0                           @ Offset: 0x034
    HANDLER     PendSV_Handler              @ Offset: 0x038
    HANDLER     SysTick_Handler             @ Offset: 0x03C
    HANDLER     WWDG_Handler                @ Offset: 0x040
    HANDLER     EXTI16_PVD_Handler          @ Offset: 0x044
    HANDLER     EXTI21_TAMP_STAMP_Handler   @ Offset: 0x048
    HANDLER     EXTI22_RTC_WKUP_Handler     @ Offset: 0x04C
    HANDLER     Flash_Handler               @ Offset: 0x050
    HANDLER     RCC_Handler                 @ Offset: 0x054
    HANDLER     EXTI0_Handler               @ Offset: 0x058
    HANDLER     EXTI1_Handler               @ Offset: 0x05C
    HANDLER     EXTI2_Handler               @ Offset: 0x060
    HANDLER     EXTI3_Handler               @ Offset: 0x064
    HANDLER     EXTI4_Handler               @ Offset: 0x068
    HANDLER     DMA1_Stream0_Handler        @ Offset: 0x06C
    HANDLER     DMA1_Stream1_Handler        @ Offset: 0x070
    HANDLER     DMA1_Stream2_Handler        @ Offset: 0x074
    HANDLER     DMA1_Stream3_Handler        @ Offset: 0x078
    HANDLER     DMA1_Stream4_Handler        @ Offset: 0x07C
    HANDLER     DMA1_Stream5_Handler        @ Offset: 0x080
    HANDLER     DMA1_Stream6_Handler        @ Offset: 0x084
    HANDLER     ADC_Handler                 @ Offset: 0x088
    .word       0                           @ Offset: 0x08C
    .word       0                           @ Offset: 0x090
    .word       0                           @ Offset: 0x094
    .word       0                           @ Offset: 0x098
    HANDLER     EXTI9_5_Handler             @ Offset: 0x09C
    HANDLER     TIM1_BRK_TIM9_Handler       @ Offset: 0x0A0
    HANDLER     TIM1_UP_TIM10_Handler       @ Offset: 0x0A4
    HANDLER     TIM1_TRG_COM_TIM11_Handler  @ Offset: 0x0A8
    HANDLER     TIM1_CC_Handler             @ Offset: 0x0AC
    HANDLER     TIM2_Handler                @ Offset: 0x0B0
    HANDLER     TIM3_Handler                @ Offset: 0x0B4
    HANDLER     TIM4_Handler                @ Offset: 0x0B8
    HANDLER     I2C1_EV_Handler             @ Offset: 0x0BC
    HANDLER     I2C1_ER_Handler             @ Offset: 0x0C0
    HANDLER     I2C2_EV_Handler             @ Offset: 0x0C4
    HANDLER     I2C2_ER_Handler             @ Offset: 0x0C8
    HANDLER     SPI1_Handler                @ Offset: 0x0CC
    HANDLER     SPI2_Handler                @ Offset: 0x0D0
    HANDLER     USART1_Handler              @ Offset: 0x0D4
    HANDLER     USART2_Handler              @ Offset: 0x0D8
    .word       0                           @ Offset: 0x0DC
    HANDLER     EXTI15_10_Handler           @ Offset: 0x0E0
    HANDLER     EXTI17_RTC_Alarm_Handler    @ Offset: 0x0E4
    HANDLER     EXTI18_OTG_FS_WKUP_Handler  @ Offset: 0x0E8
    .word       0                           @ Offset: 0x0EC
    .word       0                           @ Offset: 0x0F0
    .word       0                           @ Offset: 0x0F4
    .word       0                           @ Offset: 0x0F8
    HANDLER     DMA1_Stream7_Handler        @ Offset: 0x0FC
    .word       0                           @ Offset: 0x100
    HANDLER     SDIO_Handler                @ Offset: 0x104
    HANDLER     TIM5_Handler                @ Offset: 0x108
    HANDLER     SPI3_Handler                @ Offset: 0x10C
    .word       0                           @ Offset: 0x110
    .word       0                           @ Offset: 0x114
    .word       0                           @ Offset: 0x118
    .word       0                           @ Offset: 0x11C
    HANDLER     DMA2_Stream0_Handler        @ Offset: 0x120
    HANDLER     DMA2_Stream1_Handler        @ Offset: 0x124
    HANDLER     DMA2_Stream2_Handler        @ Offset: 0x128
    HANDLER     DMA2_Stream3_Handler        @ Offset: 0x12C
    HANDLER     DMA2_Stream4_Handler        @ Offset: 0x130
    .word       0                           @ Offset: 0x134
    .word       0                           @ Offset: 0x138
    .word       0                           @ Offset: 0x13C
    .word       0                           @ Offset: 0x140
    .word       0                           @ Offset: 0x144
    .word       0                           @ Offset: 0x148
    HANDLER     OTG_FS_Handler              @ Offset: 0x14C
    HANDLER     DMA2_Stream5_Handler        @ Offset: 0x150
    HANDLER     DMA2_Stream6_Handler        @ Offset: 0x154
    HANDLER     DMA2_Stream7_Handler        @ Offset: 0x158
    HANDLER     USART6_Handler              @ Offset: 0x15C
    HANDLER     I2C3_EV_Handler             @ Offset: 0x160
    HANDLER     I2C3_ER_Handler             @ Offset: 0x164
    .word       0                           @ Offset: 0x168
    .word       0                           @ Offset: 0x16C
    .word       0                           @ Offset: 0x170
    .word       0                           @ Offset: 0x174
    .word       0                           @ Offset: 0x178
    .word       0                           @ Offset: 0x17C
    .word       0                           @ Offset: 0x180
    HANDLER     FPU_Handler                 @ Offset: 0x184
    .word       0                           @ Offset: 0x188
    .word       0                           @ Offset: 0x18C
    HANDLER     SPI4_Handler                @ Offset: 0x190
    HANDLER     SPI5_Handler                @ Offset: 0x194

@ -----------------------------------------------------------------------------

.text

.type Reset_Handler, "function"
Reset_Handler:
    bl main
    b .

.type Default_Handler, "function"
Default_Handler:
    bkpt
    b .
