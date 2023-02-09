#include "STM32F411xE.h"

void delay(volatile unsigned int i)
{
    while (i > 0)
    {
        --i;
    }
}

int main()
{
    // Enable GPIOC
    BIT_SET(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);

    // Set GPIOC pin 13 mode to output
    BIT_CLEAR(GPIOC->MODER, GPIO_MODER_MODER13_MASK);
    BIT_SET(GPIOC->MODER, GPIO_MODER_MODER13_OUTPUT);

    while (1)
    {
        // Toggle GPIOC pin 13
        BIT_TOGGLE(GPIOC->ODR, GPIO_ODR_ODR13);
        delay(500000);
    }
}
