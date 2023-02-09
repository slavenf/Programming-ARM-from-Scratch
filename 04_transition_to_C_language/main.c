// Peripheral base addresses
#define RCC_BASE    0x40023800
#define GPIOC_BASE  0x40020800

// RCC_AHB1ENR register
#define RCC_AHB1ENR                 (RCC_BASE + 0x30)
#define RCC_AHB1ENR_GPIOCEN         (1 << 2)

// GPIOC_MODER register
#define GPIOC_MODER                 (GPIOC_BASE + 0x0)
#define GPIOC_MODER_MODER13_MASK    (3 << 26)
#define GPIOC_MODER_MODER13_OUTPUT  (1 << 26)

// GPIOC_ODR register
#define GPIOC_ODR                   (GPIOC_BASE + 0x14)
#define GPIOC_ODR_ODR13             (1 << 13)

// Bit manipulation macros
#define BIT_SET(register, mask)     ((register) |= (mask))
#define BIT_CLEAR(register, mask)   ((register) &= ~(mask))
#define BIT_TOGGLE(register, mask)  ((register) ^= (mask))

// Register access macro
#define REG(address) (*(volatile unsigned int*)address)

void delay(unsigned int i)
{
    while (i > 0)
    {
        --i;
    }
}

int main()
{
    // Enable GPIOC
    BIT_SET( REG(RCC_AHB1ENR), RCC_AHB1ENR_GPIOCEN );

    // Set GPIOC pin 13 mode to output
    BIT_CLEAR( REG(GPIOC_MODER), GPIOC_MODER_MODER13_MASK );
    BIT_SET( REG(GPIOC_MODER), GPIOC_MODER_MODER13_OUTPUT );

    while (1)
    {
        // Toggle GPIOC pin 13
        BIT_TOGGLE( REG(GPIOC_ODR), GPIOC_ODR_ODR13 );
        delay(500000);
    }
}
