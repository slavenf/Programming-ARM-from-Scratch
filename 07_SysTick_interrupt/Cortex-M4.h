#include <stdint.h>

// SysTick peripheral registers structure
struct STK_t
{
    volatile uint32_t CTRL;     // SysTick control and status register. Address offset: 0x00
    volatile uint32_t LOAD;     // SysTick reload value register.       Address offset: 0x04
    volatile uint32_t VAL;      // SysTick current value register.      Address offset: 0x08
    volatile uint32_t CALIB;    // SysTick calibration value register.  Address offset: 0x0C
};

// Peripheral base addresses
#define STK_BASE    0xE000E010

// Peripheral declarations
#define STK     ((struct STK_t*)STK_BASE)

// Bit definitions for STK_CTRL register
#define STK_CTRL_COUNTFLAG      (1UL << 16)
#define STK_CTRL_CLKSOURCE      (1UL << 2)
#define STK_CTRL_TICKINT        (1UL << 1)
#define STK_CTRL_ENABLE         (1UL << 0)

// Bit definitions for STK_LOAD register
#define STK_LOAD_RELOAD_MASK    0x00FFFFFF

// Bit definitions for STK_VAL register
#define STK_LOAD_VAL_MASK       0x00FFFFFF
