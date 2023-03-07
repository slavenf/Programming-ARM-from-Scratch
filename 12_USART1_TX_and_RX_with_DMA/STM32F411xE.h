#ifndef FILE_GUARD_STM32F411XE_H
#define FILE_GUARD_STM32F411XE_H

#include "Cortex-M4.h"

// Interrupt numbers
#define DMA1_Stream0_IRQn   11
#define DMA1_Stream1_IRQn   12
#define DMA1_Stream2_IRQn   13
#define DMA1_Stream3_IRQn   14
#define DMA1_Stream4_IRQn   15
#define DMA1_Stream5_IRQn   16
#define DMA1_Stream6_IRQn   17
#define TIM2_IRQn           28
#define USART1_IRQn         37
#define USART2_IRQn         38
#define DMA2_Stream0_IRQn   56
#define DMA2_Stream1_IRQn   57
#define DMA2_Stream2_IRQn   58
#define DMA2_Stream3_IRQn   59
#define DMA2_Stream4_IRQn   60
#define DMA2_Stream5_IRQn   68
#define DMA2_Stream6_IRQn   69
#define DMA2_Stream7_IRQn   70
#define USART6_IRQn         71

// DMA peripheral registers structure
struct DMA_t
{
    volatile uint32_t LISR;     // DMA low interrupt status register.           Address offset: 0x00
    volatile uint32_t HISR;     // DMA high interrupt status register.          Address offset: 0x04
    volatile uint32_t LIFCR;    // DMA low interrupt flag clear register.       Address offset: 0x08
    volatile uint32_t HIFCR;    // DMA high interrupt flag clear register.      Address offset: 0x0C
    volatile uint32_t S0CR;     // DMA stream 0 configuration register.         Address offset: 0x10
    volatile uint32_t S0NDTR;   // DMA stream 0 number of data register.        Address offset: 0x14
    volatile uint32_t S0PAR;    // DMA stream 0 peripheral address register.    Address offset: 0x18
    volatile uint32_t S0M0AR;   // DMA stream 0 memory 0 address register.      Address offset: 0x1C
    volatile uint32_t S0M1AR;   // DMA stream 0 memory 1 address register.      Address offset: 0x20
    volatile uint32_t S0FCR;    // DMA stream 0 FIFO control register.          Address offset: 0x24
    volatile uint32_t S1CR;     // DMA stream 1 configuration register.         Address offset: 0x28
    volatile uint32_t S1NDTR;   // DMA stream 1 number of data register.        Address offset: 0x2C
    volatile uint32_t S1PAR;    // DMA stream 1 peripheral address register.    Address offset: 0x30
    volatile uint32_t S1M0AR;   // DMA stream 1 memory 0 address register.      Address offset: 0x34
    volatile uint32_t S1M1AR;   // DMA stream 1 memory 1 address register.      Address offset: 0x38
    volatile uint32_t S1FCR;    // DMA stream 1 FIFO control register.          Address offset: 0x3C
    volatile uint32_t S2CR;     // DMA stream 2 configuration register.         Address offset: 0x40
    volatile uint32_t S2NDTR;   // DMA stream 2 number of data register.        Address offset: 0x44
    volatile uint32_t S2PAR;    // DMA stream 2 peripheral address register.    Address offset: 0x48
    volatile uint32_t S2M0AR;   // DMA stream 2 memory 0 address register.      Address offset: 0x4C
    volatile uint32_t S2M1AR;   // DMA stream 2 memory 1 address register.      Address offset: 0x50
    volatile uint32_t S2FCR;    // DMA stream 2 FIFO control register.          Address offset: 0x54
    volatile uint32_t S3CR;     // DMA stream 3 configuration register.         Address offset: 0x58
    volatile uint32_t S3NDTR;   // DMA stream 3 number of data register.        Address offset: 0x5C
    volatile uint32_t S3PAR;    // DMA stream 3 peripheral address register.    Address offset: 0x60
    volatile uint32_t S3M0AR;   // DMA stream 3 memory 0 address register.      Address offset: 0x64
    volatile uint32_t S3M1AR;   // DMA stream 3 memory 1 address register.      Address offset: 0x68
    volatile uint32_t S3FCR;    // DMA stream 3 FIFO control register.          Address offset: 0x6C
    volatile uint32_t S4CR;     // DMA stream 4 configuration register.         Address offset: 0x70
    volatile uint32_t S4NDTR;   // DMA stream 4 number of data register.        Address offset: 0x74
    volatile uint32_t S4PAR;    // DMA stream 4 peripheral address register.    Address offset: 0x78
    volatile uint32_t S4M0AR;   // DMA stream 4 memory 0 address register.      Address offset: 0x7C
    volatile uint32_t S4M1AR;   // DMA stream 4 memory 1 address register.      Address offset: 0x80
    volatile uint32_t S4FCR;    // DMA stream 4 FIFO control register.          Address offset: 0x84
    volatile uint32_t S5CR;     // DMA stream 5 configuration register.         Address offset: 0x88
    volatile uint32_t S5NDTR;   // DMA stream 5 number of data register.        Address offset: 0x8C
    volatile uint32_t S5PAR;    // DMA stream 5 peripheral address register.    Address offset: 0x90
    volatile uint32_t S5M0AR;   // DMA stream 5 memory 0 address register.      Address offset: 0x94
    volatile uint32_t S5M1AR;   // DMA stream 5 memory 1 address register.      Address offset: 0x98
    volatile uint32_t S5FCR;    // DMA stream 5 FIFO control register.          Address offset: 0x9C
    volatile uint32_t S6CR;     // DMA stream 6 configuration register.         Address offset: 0xA0
    volatile uint32_t S6NDTR;   // DMA stream 6 number of data register.        Address offset: 0xA4
    volatile uint32_t S6PAR;    // DMA stream 6 peripheral address register.    Address offset: 0xA8
    volatile uint32_t S6M0AR;   // DMA stream 6 memory 0 address register.      Address offset: 0xAC
    volatile uint32_t S6M1AR;   // DMA stream 6 memory 1 address register.      Address offset: 0xB0
    volatile uint32_t S6FCR;    // DMA stream 6 FIFO control register.          Address offset: 0xB4
    volatile uint32_t S7CR;     // DMA stream 7 configuration register.         Address offset: 0xB8
    volatile uint32_t S7NDTR;   // DMA stream 7 number of data register.        Address offset: 0xBC
    volatile uint32_t S7PAR;    // DMA stream 7 peripheral address register.    Address offset: 0xC0
    volatile uint32_t S7M0AR;   // DMA stream 7 memory 0 address register.      Address offset: 0xC4
    volatile uint32_t S7M1AR;   // DMA stream 7 memory 1 address register.      Address offset: 0xC8
    volatile uint32_t S7FCR;    // DMA stream 7 FIFO control register.          Address offset: 0xCC
};

// GPIO peripheral registers structure
struct GPIO_t
{
    volatile uint32_t MODER;    // GPIO port mode register.                 Address offset: 0x00
    volatile uint32_t OTYPER;   // GPIO port output type register.          Address offset: 0x04
    volatile uint32_t OSPEEDR;  // GPIO port output speed register.         Address offset: 0x08
    volatile uint32_t PUPDR;    // GPIO port pull-up/pull-down register.    Address offset: 0x0C
    volatile uint32_t IDR;      // GPIO port input data register.           Address offset: 0x10
    volatile uint32_t ODR;      // GPIO port output data register.          Address offset: 0x14
    volatile uint32_t BSSR;     // GPIO port bit set/reset register.        Address offset: 0x18
    volatile uint32_t LCKR;     // GPIO port configuration lock register.   Address offset: 0x1C
    volatile uint32_t AFRL;     // GPIO alternate function low register.    Address offset: 0x20
    volatile uint32_t AFRH;     // GPIO alternate function high register.   Address offset: 0x24
};

// RCC peripheral registers structure
struct RCC_t
{
    volatile uint32_t CR;           // RCC clock control register.                                  Address offset: 0x00
    volatile uint32_t PLLCFGR;      // RCC PLL configuration register.                              Address offset: 0x04
    volatile uint32_t CFGR;         // RCC clock configuration register.                            Address offset: 0x08
    volatile uint32_t CIR;          // RCC clock interrupt register.                                Address offset: 0x0C
    volatile uint32_t AHB1RSTR;     // RCC AHB1 peripheral reset register.                          Address offset: 0x10
    volatile uint32_t AHB2RSTR;     // RCC AHB2 peripheral reset register.                          Address offset: 0x14
    volatile uint32_t RESERVED0;    // Reserved.                                                    Address offset: 0x18
    volatile uint32_t RESERVED1;    // Reserved.                                                    Address offset: 0x1C
    volatile uint32_t APB1RSTR;     // RCC APB1 peripheral reset register.                          Address offset: 0x20
    volatile uint32_t APB2RSTR;     // RCC APB2 peripheral reset register.                          Address offset: 0x24
    volatile uint32_t RESERVED2;    // Reserved.                                                    Address offset: 0x28
    volatile uint32_t RESERVED3;    // Reserved.                                                    Address offset: 0x2C
    volatile uint32_t AHB1ENR;      // RCC AHB1 peripheral clock enable register.                   Address offset: 0x30
    volatile uint32_t AHB2ENR;      // RCC AHB2 peripheral clock enable register.                   Address offset: 0x34
    volatile uint32_t RESERVED4;    // Reserved.                                                    Address offset: 0x38
    volatile uint32_t RESERVED5;    // Reserved.                                                    Address offset: 0x3C
    volatile uint32_t APB1ENR;      // RCC APB1 peripheral clock enable register.                   Address offset: 0x40
    volatile uint32_t APB2ENR;      // RCC APB2 peripheral clock enable register.                   Address offset: 0x44
    volatile uint32_t RESERVED6;    // Reserved.                                                    Address offset: 0x48
    volatile uint32_t RESERVED7;    // Reserved.                                                    Address offset: 0x4C
    volatile uint32_t AHB1LPENR;    // RCC AHB1 peripheral clock enable in low power mode register. Address offset: 0x50
    volatile uint32_t AHB2LPENR;    // RCC AHB2 peripheral clock enable in low power mode register. Address offset: 0x54
    volatile uint32_t RESERVED8;    // Reserved.                                                    Address offset: 0x58
    volatile uint32_t RESERVED9;    // Reserved.                                                    Address offset: 0x5C
    volatile uint32_t APB1LPENR;    // RCC APB1 peripheral clock enable in low power mode register. Address offset: 0x60
    volatile uint32_t APB2LPENR;    // RCC APB2 peripheral clock enable in low power mode register. Address offset: 0x64
    volatile uint32_t RESERVED10;   // Reserved.                                                    Address offset: 0x68
    volatile uint32_t RESERVED11;   // Reserved.                                                    Address offset: 0x6C
    volatile uint32_t BDCR;         // RCC Backup domain control register.                          Address offset: 0x70
    volatile uint32_t CSR;          // RCC clock control & status register.                         Address offset: 0x74
    volatile uint32_t RESERVED12;   // Reserved.                                                    Address offset: 0x78
    volatile uint32_t RESERVED13;   // Reserved.                                                    Address offset: 0x7C
    volatile uint32_t SSCGR;        // RCC spread spectrum clock generation register.               Address offset: 0x80
    volatile uint32_t PLLI2SCFGR;   // RCC PLLI2S configuration register.                           Address offset: 0x84
    volatile uint32_t RESERVED14;   // Reserved.                                                    Address offset: 0x88
    volatile uint32_t DCKCFGR;      // RCC Dedicated Clocks Configuration Register.                 Address offset: 0x8C
};

// TIM peripheral registers structure
struct TIM_t
{
    volatile uint32_t CR1;          // TIM control register 1.              Address offset: 0x00
    volatile uint32_t CR2;          // TIM control register 2.              Address offset: 0x04
    volatile uint32_t SMCR;         // TIM slave mode control register.     Address offset: 0x08
    volatile uint32_t DIER;         // TIM DMA/Interrupt enable register.   Address offset: 0x0C
    volatile uint32_t SR;           // TIM status register.                 Address offset: 0x10
    volatile uint32_t EGR;          // TIM event generation register.       Address offset: 0x14
    volatile uint32_t CCMR1;        // TIM capture/compare mode register 1. Address offset: 0x18
    volatile uint32_t CCMR2;        // TIM capture/compare mode register 2. Address offset: 0x1C
    volatile uint32_t CCER;         // TIM capture/compare enable register. Address offset: 0x20
    volatile uint32_t CNT;          // TIM counter.                         Address offset: 0x24
    volatile uint32_t PSC;          // TIM prescaler.                       Address offset: 0x28
    volatile uint32_t ARR;          // TIM auto-reload register.            Address offset: 0x2C
    volatile uint32_t RESERVED0;    // Reserved.                            Address offset: 0x30
    volatile uint32_t CCR1;         // TIM capture/compare register 1.      Address offset: 0x34
    volatile uint32_t CCR2;         // TIM capture/compare register 2.      Address offset: 0x38
    volatile uint32_t CCR3;         // TIM capture/compare register 3.      Address offset: 0x3C
    volatile uint32_t CCR4;         // TIM capture/compare register 4.      Address offset: 0x40
    volatile uint32_t RESERVED1;    // Reserved.                            Address offset: 0x44
    volatile uint32_t DCR;          // TIM DMA control register.            Address offset: 0x48
    volatile uint32_t DMAR;         // TIM DMA address for full transfer.   Address offset: 0x4C
    volatile uint32_t OR;           // TIM option register.                 Address offset: 0x50
};

// USART peripheral registers structure
struct USART_t
{
    volatile uint32_t SR;   // Status register.                     Address offset: 0x00
    volatile uint32_t DR;   // Data register.                       Address offset: 0x04
    volatile uint32_t BRR;  // Baud rate register.                  Address offset: 0x08
    volatile uint32_t CR1;  // Control register 1.                  Address offset: 0x0C
    volatile uint32_t CR2;  // Control register 2.                  Address offset: 0x10
    volatile uint32_t CR3;  // Control register 3.                  Address offset: 0x14
    volatile uint32_t GTPR; // Guard time and prescaler register.   Address offset: 0x18
};

// Peripheral base addresses
#define DMA1_BASE   0x40026000
#define DMA2_BASE   0x40026400
#define GPIOA_BASE  0x40020000
#define GPIOB_BASE  0x40020400
#define GPIOC_BASE  0x40020800
#define GPIOD_BASE  0x40020C00
#define GPIOE_BASE  0x40021000
#define GPIOH_BASE  0x40021C00
#define RCC_BASE    0x40023800
#define TIM2_BASE   0x40000000
#define USART1_BASE 0x40011000
#define USART2_BASE 0x40004400
#define USART6_BASE 0x40011400

// Peripheral declarations
#define DMA1    ((struct DMA_t*)DMA1_BASE)
#define DMA2    ((struct DMA_t*)DMA2_BASE)
#define GPIOA   ((struct GPIO_t*)GPIOA_BASE)
#define GPIOB   ((struct GPIO_t*)GPIOB_BASE)
#define GPIOC   ((struct GPIO_t*)GPIOC_BASE)
#define GPIOD   ((struct GPIO_t*)GPIOD_BASE)
#define GPIOE   ((struct GPIO_t*)GPIOE_BASE)
#define GPIOH   ((struct GPIO_t*)GPIOH_BASE)
#define RCC     ((struct RCC_t*)RCC_BASE)
#define TIM2    ((struct TIM_t*)TIM2_BASE)
#define USART1  ((struct USART_t*)USART1_BASE)
#define USART2  ((struct USART_t*)USART2_BASE)
#define USART6  ((struct USART_t*)USART6_BASE)

// Bit definitions for DMA_LISR register
#define DMA_LISR_TCIF3              (1UL << 27) // Stream 3 transfer complete interrupt flag
#define DMA_LISR_HTIF3              (1UL << 26) // Stream 3 half transfer interrupt flag
#define DMA_LISR_TEIF3              (1UL << 25) // Stream 3 transfer error interrupt flag
#define DMA_LISR_DMEIF3             (1UL << 24) // Stream 3 direct mode error interrupt flag
#define DMA_LISR_FEIF3              (1UL << 22) // Stream 3 FIFO error interrupt flag
#define DMA_LISR_TCIF2              (1UL << 21) // Stream 2 transfer complete interrupt flag
#define DMA_LISR_HTIF2              (1UL << 20) // Stream 2 half transfer interrupt flag
#define DMA_LISR_TEIF2              (1UL << 19) // Stream 2 transfer error interrupt flag
#define DMA_LISR_DMEIF2             (1UL << 18) // Stream 2 direct mode error interrupt flag
#define DMA_LISR_FEIF2              (1UL << 16) // Stream 2 FIFO error interrupt flag
#define DMA_LISR_TCIF1              (1UL << 11) // Stream 1 transfer complete interrupt flag
#define DMA_LISR_HTIF1              (1UL << 10) // Stream 1 half transfer interrupt flag
#define DMA_LISR_TEIF1              (1UL << 9)  // Stream 1 transfer error interrupt flag
#define DMA_LISR_DMEIF1             (1UL << 8)  // Stream 1 direct mode error interrupt flag
#define DMA_LISR_FEIF1              (1UL << 6)  // Stream 1 FIFO error interrupt flag
#define DMA_LISR_TCIF0              (1UL << 5)  // Stream 0 transfer complete interrupt flag
#define DMA_LISR_HTIF0              (1UL << 4)  // Stream 0 half transfer interrupt flag
#define DMA_LISR_TEIF0              (1UL << 3)  // Stream 0 transfer error interrupt flag
#define DMA_LISR_DMEIF0             (1UL << 2)  // Stream 0 direct mode error interrupt flag
#define DMA_LISR_FEIF0              (1UL << 0)  // Stream 0 FIFO error interrupt flag

// Bit definitions for DMA_HISR register
#define DMA_HISR_TCIF7              (1UL << 27) // Stream 7 transfer complete interrupt flag
#define DMA_HISR_HTIF7              (1UL << 26) // Stream 7 half transfer interrupt flag
#define DMA_HISR_TEIF7              (1UL << 25) // Stream 7 transfer error interrupt flag
#define DMA_HISR_DMEIF7             (1UL << 24) // Stream 7 direct mode error interrupt flag
#define DMA_HISR_FEIF7              (1UL << 22) // Stream 7 FIFO error interrupt flag
#define DMA_HISR_TCIF6              (1UL << 21) // Stream 6 transfer complete interrupt flag
#define DMA_HISR_HTIF6              (1UL << 20) // Stream 6 half transfer interrupt flag
#define DMA_HISR_TEIF6              (1UL << 19) // Stream 6 transfer error interrupt flag
#define DMA_HISR_DMEIF6             (1UL << 18) // Stream 6 direct mode error interrupt flag
#define DMA_HISR_FEIF6              (1UL << 16) // Stream 6 FIFO error interrupt flag
#define DMA_HISR_TCIF5              (1UL << 11) // Stream 5 transfer complete interrupt flag
#define DMA_HISR_HTIF5              (1UL << 10) // Stream 5 half transfer interrupt flag
#define DMA_HISR_TEIF5              (1UL << 9)  // Stream 5 transfer error interrupt flag
#define DMA_HISR_DMEIF5             (1UL << 8)  // Stream 5 direct mode error interrupt flag
#define DMA_HISR_FEIF5              (1UL << 6)  // Stream 5 FIFO error interrupt flag
#define DMA_HISR_TCIF4              (1UL << 5)  // Stream 4 transfer complete interrupt flag
#define DMA_HISR_HTIF4              (1UL << 4)  // Stream 4 half transfer interrupt flag
#define DMA_HISR_TEIF4              (1UL << 3)  // Stream 4 transfer error interrupt flag
#define DMA_HISR_DMEIF4             (1UL << 2)  // Stream 4 direct mode error interrupt flag
#define DMA_HISR_FEIF4              (1UL << 0)  // Stream 4 FIFO error interrupt flag

// Bit definitions for DMA_LIFCR register
#define DMA_LIFCR_CTCIF3            (1UL << 27) // Stream 3 clear transfer complete interrupt flag
#define DMA_LIFCR_CHTIF3            (1UL << 26) // Stream 3 clear half transfer interrupt flag
#define DMA_LIFCR_CTEIF3            (1UL << 25) // Stream 3 clear transfer error interrupt flag
#define DMA_LIFCR_CDMEIF3           (1UL << 24) // Stream 3 clear direct mode error interrupt flag
#define DMA_LIFCR_CFEIF3            (1UL << 22) // Stream 3 clear FIFO error interrupt flag
#define DMA_LIFCR_CTCIF2            (1UL << 21) // Stream 2 clear transfer complete interrupt flag
#define DMA_LIFCR_CHTIF2            (1UL << 20) // Stream 2 clear half transfer interrupt flag
#define DMA_LIFCR_CTEIF2            (1UL << 19) // Stream 2 clear transfer error interrupt flag
#define DMA_LIFCR_CDMEIF2           (1UL << 18) // Stream 2 clear direct mode error interrupt flag
#define DMA_LIFCR_CFEIF2            (1UL << 16) // Stream 2 clear FIFO error interrupt flag
#define DMA_LIFCR_CTCIF1            (1UL << 11) // Stream 1 clear transfer complete interrupt flag
#define DMA_LIFCR_CHTIF1            (1UL << 10) // Stream 1 clear half transfer interrupt flag
#define DMA_LIFCR_CTEIF1            (1UL << 9)  // Stream 1 clear transfer error interrupt flag
#define DMA_LIFCR_CDMEIF1           (1UL << 8)  // Stream 1 clear direct mode error interrupt flag
#define DMA_LIFCR_CFEIF1            (1UL << 6)  // Stream 1 clear FIFO error interrupt flag
#define DMA_LIFCR_CTCIF0            (1UL << 5)  // Stream 0 clear transfer complete interrupt flag
#define DMA_LIFCR_CHTIF0            (1UL << 4)  // Stream 0 clear half transfer interrupt flag
#define DMA_LIFCR_CTEIF0            (1UL << 3)  // Stream 0 clear transfer error interrupt flag
#define DMA_LIFCR_CDMEIF0           (1UL << 2)  // Stream 0 clear direct mode error interrupt flag
#define DMA_LIFCR_CFEIF0            (1UL << 0)  // Stream 0 clear FIFO error interrupt flag

// Bit definitions for DMA_HIFCR register
#define DMA_HIFCR_CTCIF7            (1UL << 27) // Stream 7 clear transfer complete interrupt flag
#define DMA_HIFCR_CHTIF7            (1UL << 26) // Stream 7 clear half transfer interrupt flag
#define DMA_HIFCR_CTEIF7            (1UL << 25) // Stream 7 clear transfer error interrupt flag
#define DMA_HIFCR_CDMEIF7           (1UL << 24) // Stream 7 clear direct mode error interrupt flag
#define DMA_HIFCR_CFEIF7            (1UL << 22) // Stream 7 clear FIFO error interrupt flag
#define DMA_HIFCR_CTCIF6            (1UL << 21) // Stream 6 clear transfer complete interrupt flag
#define DMA_HIFCR_CHTIF6            (1UL << 20) // Stream 6 clear half transfer interrupt flag
#define DMA_HIFCR_CTEIF6            (1UL << 19) // Stream 6 clear transfer error interrupt flag
#define DMA_HIFCR_CDMEIF6           (1UL << 18) // Stream 6 clear direct mode error interrupt flag
#define DMA_HIFCR_CFEIF6            (1UL << 16) // Stream 6 clear FIFO error interrupt flag
#define DMA_HIFCR_CTCIF5            (1UL << 11) // Stream 5 clear transfer complete interrupt flag
#define DMA_HIFCR_CHTIF5            (1UL << 10) // Stream 5 clear half transfer interrupt flag
#define DMA_HIFCR_CTEIF5            (1UL << 9)  // Stream 5 clear transfer error interrupt flag
#define DMA_HIFCR_CDMEIF5           (1UL << 8)  // Stream 5 clear direct mode error interrupt flag
#define DMA_HIFCR_CFEIF5            (1UL << 6)  // Stream 5 clear FIFO error interrupt flag
#define DMA_HIFCR_CTCIF4            (1UL << 5)  // Stream 4 clear transfer complete interrupt flag
#define DMA_HIFCR_CHTIF4            (1UL << 4)  // Stream 4 clear half transfer interrupt flag
#define DMA_HIFCR_CTEIF4            (1UL << 3)  // Stream 4 clear transfer error interrupt flag
#define DMA_HIFCR_CDMEIF4           (1UL << 2)  // Stream 4 clear direct mode error interrupt flag
#define DMA_HIFCR_CFEIF4            (1UL << 0)  // Stream 4 clear FIFO error interrupt flag

// Bit definitions for DMA_SxCR register
#define DMA_SxCR_CHSEL_MASK         (7UL << 25) // Channel selection mask
#define DMA_SxCR_CHSEL_CH0          (0UL << 25) // Channel 0 selection
#define DMA_SxCR_CHSEL_CH1          (1UL << 25) // Channel 1 selection
#define DMA_SxCR_CHSEL_CH2          (2UL << 25) // Channel 2 selection
#define DMA_SxCR_CHSEL_CH3          (3UL << 25) // Channel 3 selection
#define DMA_SxCR_CHSEL_CH4          (4UL << 25) // Channel 4 selection
#define DMA_SxCR_CHSEL_CH5          (5UL << 25) // Channel 5 selection
#define DMA_SxCR_CHSEL_CH6          (6UL << 25) // Channel 6 selection
#define DMA_SxCR_CHSEL_CH7          (7UL << 25) // Channel 7 selection
#define DMA_SxCR_MINC               (1UL << 10) // Memory increment mode
#define DMA_SxCR_PFCTRL             (1UL << 5)  // Peripheral flow controller
#define DMA_SxCR_TCIE               (1UL << 4)  // Transfer complete interrupt enable
#define DMA_SxCR_DIR_MASK           (3UL << 6)  // Data transfer direction mask
#define DMA_SxCR_DIR_PERIPH_TO_MEM  (0UL << 6)  // Peripheral-to-memory data transfer direction
#define DMA_SxCR_DIR_MEM_TO_PERIPH  (1UL << 6)  // Memory-to-peripheral data transfer direction
#define DMA_SxCR_DIR_MEM_TO_MEM     (2UL << 6)  // Memory-to-memory data transfer direction
#define DMA_SxCR_EN                 (1UL << 0)  // Stream enable / flag stream ready when read low

// Bit definitions for GPIOC_MODER register
#define GPIO_MODER_MODER13_MASK     (3UL << 26)
#define GPIO_MODER_MODER13_OUTPUT   (1UL << 26)
#define GPIO_MODER_MODER10_MASK     (3UL << 20)
#define GPIO_MODER_MODER10_ALT_FUNC (2UL << 20)
#define GPIO_MODER_MODER9_MASK      (3UL << 18)
#define GPIO_MODER_MODER9_ALT_FUNC  (2UL << 18)

// Bit definitions for GPIOC_ODR register
#define GPIO_ODR_ODR13_MASK         (1UL << 13)
#define GPIO_ODR_ODR13              (1UL << 13)

// Bit definitions for GPIO_AFRH register
#define GPIO_AFRH_AFRH9_MASK        0x000000F0
#define GPIO_AFRH_AFRH9_AF7         0x00000070
#define GPIO_AFRH_AFRH10_MASK       0x00000F00
#define GPIO_AFRH_AFRH10_AF7        0x00000700

// Bit definitions for RCC_CR register
#define RCC_CR_HSEON                (1UL << 16) // HSE clock enable
#define RCC_CR_HSERDY               (1UL << 17) // HSE clock ready

// Bit definitions for RCC_CFGR register
#define RCC_CFGR_SW_MASK            (3UL << 0)  // System clock switch mask
#define RCC_CFGR_SW_HSI             (0UL << 0)  // HSI oscillator selected as system clock
#define RCC_CFGR_SW_HSE             (1UL << 0)  // HSE oscillator selected as system clock
#define RCC_CFGR_SW_PLL             (2UL << 0)  // PLL selected as system clock

#define RCC_CFGR_SWS_MASK           (3UL << 2)  // System clock switch status mask
#define RCC_CFGR_SWS_HSI            (0UL << 2)  // HSI oscillator used as the system clock
#define RCC_CFGR_SWS_HSE            (1UL << 2)  // HSE oscillator used as the system clock
#define RCC_CFGR_SWS_PLL            (2UL << 2)  // PLL used as the system clock

// Bit definitions for RCC_AHB1ENR register
#define RCC_AHB1ENR_DMA2EN          (1UL << 22) // DMA2 clock enable
#define RCC_AHB1ENR_DMA1EN          (1UL << 21) // DMA1 clock enable
#define RCC_AHB1ENR_CRCEN           (1UL << 12) // CRC clock enable
#define RCC_AHB1ENR_GPIOHEN         (1UL << 7)  // IO port H clock enable
#define RCC_AHB1ENR_GPIOEEN         (1UL << 4)  // IO port E clock enable
#define RCC_AHB1ENR_GPIODEN         (1UL << 3)  // IO port D clock enable
#define RCC_AHB1ENR_GPIOCEN         (1UL << 2)  // IO port C clock enable
#define RCC_AHB1ENR_GPIOBEN         (1UL << 1)  // IO port B clock enable
#define RCC_AHB1ENR_GPIOAEN         (1UL << 0)  // IO port A clock enable

// Bit definitions for RCC_APB1ENR register
#define RCC_APB1ENR_TIM2EN          (1UL << 0)  // TIM2 clock enable

// Bit definitions for RCC_APB2ENR register
#define RCC_APB2ENR_SPI5EN          (1UL << 20) // SPI5 clock enable
#define RCC_APB2ENR_TIM11EN         (1UL << 18) // TIM11 clock enable
#define RCC_APB2ENR_TIM10EN         (1UL << 17) // TIM10 clock enable
#define RCC_APB2ENR_TIM9EN          (1UL << 16) // TIM9 clock enable
#define RCC_APB2ENR_SYSCFGEN        (1UL << 14) // System configuration controller clock enable
#define RCC_APB2ENR_SPI4EN          (1UL << 13) // SPI4 clock enable
#define RCC_APB2ENR_SPI1EN          (1UL << 12) // SPI1 clock enable
#define RCC_APB2ENR_SDIOEN          (1UL << 11) // SDIO clock enable
#define RCC_APB2ENR_ADC1EN          (1UL << 8)  // ADC1 clock enable
#define RCC_APB2ENR_USART6EN        (1UL << 5)  // USART6 clock enable
#define RCC_APB2ENR_USART1EN        (1UL << 4)  // USART1 clock enable
#define RCC_APB2ENR_TIM1EN          (1UL << 0)  // TIM1 clock enable

// Bit definitions for TIM_CR1 register
#define TIM_CR1_CEN                 (1UL << 0)  // Counter enable

// Bit definitions for TIM_DIER register
#define TIM_DIER_UIE                (1UL << 0)  // Update interrupt enable

// Bit definitions for TIM_SR register
#define TIM_SR_UIF                  (1UL << 0)  // Update interrupt flag

// Bit definitions for TIM_EGR register
#define TIM_EGR_UG                  (1UL << 0)  // Update generation

// Bit definitions for USART_SR register
#define USART_SR_CTS                (1UL << 9)  // CTS flag
#define USART_SR_LBD                (1UL << 8)  // LIN break detection flag
#define USART_SR_TXE                (1UL << 7)  // Transmit data register empty
#define USART_SR_TC                 (1UL << 6)  // Transmission complete
#define USART_SR_RXNE               (1UL << 5)  // Read data register not empty
#define USART_SR_IDLE               (1UL << 4)  // IDLE line detected
#define USART_SR_ORE                (1UL << 3)  // Overrun error
#define USART_SR_NF                 (1UL << 2)  // Noise detected flag
#define USART_SR_FE                 (1UL << 1)  // Framing error
#define USART_SR_PE                 (1UL << 0)  // Parity error

// Bit definitions for USART_CR1 register
#define USART_CR1_OVER8             (1UL << 15) // Oversampling mode
#define USART_CR1_UE                (1UL << 13) // USART enable
#define USART_CR1_M                 (1UL << 12) // Word length
#define USART_CR1_WAKE              (1UL << 11) // Wakeup method
#define USART_CR1_PCE               (1UL << 10) // Parity control enable
#define USART_CR1_PS                (1UL << 9)  // Parity selection
#define USART_CR1_PEIE              (1UL << 8)  // PE interrupt enable
#define USART_CR1_TXEIE             (1UL << 7)  // TXE interrupt enable
#define USART_CR1_TCIE              (1UL << 6)  // Transmission complete interrupt enable
#define USART_CR1_RXNEIE            (1UL << 5)  // RXNE interrupt enable
#define USART_CR1_IDLEIE            (1UL << 4)  // IDLE interrupt enable
#define USART_CR1_TE                (1UL << 3)  // Transmitter enable
#define USART_CR1_RE                (1UL << 2)  // Receiver enable
#define USART_CR1_RWU               (1UL << 1)  // Receiver wakeup

// Bit definitions for USART_CR3 register
#define USART_CR3_ONEBIT            (1UL << 11) // One sample bit method enable
#define USART_CR3_CTSIE             (1UL << 10) // CTS interrupt enable
#define USART_CR3_CTSE              (1UL << 9)  // CTS enable
#define USART_CR3_RTSE              (1UL << 8)  // RTS enable
#define USART_CR3_DMAT              (1UL << 7)  // DMA enable transmitter
#define USART_CR3_DMAR              (1UL << 6)  // DMA enable receiver
#define USART_CR3_SCEN              (1UL << 5)  // Smartcard mode enable
#define USART_CR3_NACK              (1UL << 4)  // Smartcard NACK enable
#define USART_CR3_HDSEL             (1UL << 3)  // Half-duplex selection
#define USART_CR3_IRLP              (1UL << 2)  // IrDA low-power
#define USART_CR3_IREN              (1UL << 1)  // IrDA mode enable
#define USART_CR3_EIE               (1UL << 0)  // Error interrupt enable

// Bit manipulation macros
#define BIT_SET(register, mask)     ((register) |= (mask))
#define BIT_CLEAR(register, mask)   ((register) &= ~(mask))
#define BIT_TOGGLE(register, mask)  ((register) ^= (mask))
#define BIT_CHECK(register, mask)   ((register) & (mask))

#endif // FILE_GUARD_STM32F411XE_H
