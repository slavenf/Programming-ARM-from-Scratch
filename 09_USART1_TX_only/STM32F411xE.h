#ifndef FILE_GUARD_STM32F411XE_H
#define FILE_GUARD_STM32F411XE_H

#include "Cortex-M4.h"

// Interrupt numbers
#define TIM2_IRQn       28
#define USART1_IRQn     37
#define USART2_IRQn     38
#define USART6_IRQn     71

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

// Bit manipulation macros
#define BIT_SET(register, mask)     ((register) |= (mask))
#define BIT_CLEAR(register, mask)   ((register) &= ~(mask))
#define BIT_TOGGLE(register, mask)  ((register) ^= (mask))
#define BIT_CHECK(register, mask)   ((register) & (mask))

#endif // FILE_GUARD_STM32F411XE_H
