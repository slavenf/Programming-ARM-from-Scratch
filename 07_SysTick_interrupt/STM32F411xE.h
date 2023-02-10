#include "Cortex-M4.h"

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

// Peripheral base addresses
#define GPIOC_BASE  0x40020800
#define RCC_BASE    0x40023800

// Peripheral declarations
#define GPIOC   ((struct GPIO_t*)GPIOC_BASE)
#define RCC     ((struct RCC_t*)RCC_BASE)

// Bit definitions for GPIOC_MODER register
#define GPIO_MODER_MODER13_MASK     (3UL << 26)
#define GPIO_MODER_MODER13_OUTPUT   (1UL << 26)

// Bit definitions for GPIOC_ODR register
#define GPIO_ODR_ODR13_MASK         (1UL << 13)
#define GPIO_ODR_ODR13              (1UL << 13)

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
#define RCC_AHB1ENR_GPIOCEN_MASK    (1UL << 2)
#define RCC_AHB1ENR_GPIOCEN         (1UL << 2)

// Bit manipulation macros
#define BIT_SET(register, mask)     ((register) |= (mask))
#define BIT_CLEAR(register, mask)   ((register) &= ~(mask))
#define BIT_TOGGLE(register, mask)  ((register) ^= (mask))
#define BIT_CHECK(register, mask)   ((register) & (mask))
