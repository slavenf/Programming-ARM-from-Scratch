#include "STM32F411xE.h"

// HSE clock frequency
#define HSECLK_FREQ 25000000

// System clock frequency is equal to HSE clock frequency
#define SYSCLK_FREQ HSECLK_FREQ

// SysTick frequency
#define SYSTICK_FREQ (SYSCLK_FREQ / 1000)

// USART1 baud rate
#define USART1_BAUD_RATE 115200

// Size of USART1 RX buffer
#define USART1_RX_BUFFER_SIZE 1000

// USART1 RX buffer
uint8_t usart1_rx_buffer[USART1_RX_BUFFER_SIZE];

// Number of elements in USART1 RX buffer
uint32_t usart1_rx_count;

// SysTick counter. Incremented by 1 when SysTick interrupt triggered.
volatile uint32_t systick_counter;

void delay_milliseconds(uint32_t t)
{
    const uint32_t start = systick_counter;

    while (systick_counter - start < t)
    {
        // Do nothing
    }
}

int main()
{
    systick_counter = 0;



    // Enable HSE clock
    BIT_SET(RCC->CR, RCC_CR_HSEON);

    // Wait until HSE clock becomes ready
    while (!BIT_CHECK(RCC->CR, RCC_CR_HSERDY))
    {
        // Do nothing.
    }

    // Select HSE clock as system clock
    BIT_CLEAR(RCC->CFGR, RCC_CFGR_SW_MASK);
    BIT_SET(RCC->CFGR, RCC_CFGR_SW_HSE);

    // Make sure that HSE clock is selected as system clock
    while (BIT_CHECK(RCC->CFGR, RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS_HSE)
    {
        // Do nothing.
    }



    // Set SysTick reload value
    BIT_CLEAR(STK->LOAD, STK_LOAD_RELOAD_MASK);
    BIT_SET(STK->LOAD, SYSTICK_FREQ);

    // Set processor clock as SysTick clock source
    BIT_SET(STK->CTRL, STK_CTRL_CLKSOURCE);

    // Enable SysTick exception request
    BIT_SET(STK->CTRL, STK_CTRL_TICKINT);

    // Enable SysTick counter
    BIT_SET(STK->CTRL, STK_CTRL_ENABLE);



    // Enable GPIOC
    BIT_SET(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);

    // Set GPIOC pin 13 mode to output
    BIT_CLEAR(GPIOC->MODER, GPIO_MODER_MODER13_MASK);
    BIT_SET(GPIOC->MODER, GPIO_MODER_MODER13_OUTPUT);

    // Enable TIM2 clock
    BIT_SET(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);

    // Set TIM2 prescaler
    TIM2->PSC = 1000;

    // Set TIM2 auto-reload register
    TIM2->ARR = 12500;

    // Enable TIM2 update interrupt
    BIT_SET(TIM2->DIER, TIM_DIER_UIE);

    // Generate TIM2 update
    BIT_SET(TIM2->EGR, TIM_EGR_UG);

    // Enable TIM2 counter
    BIT_SET(TIM2->CR1, TIM_CR1_CEN);

    // Enable TIM2 interrupt
    irq_enable(TIM2_IRQn);



    // Enable GPIOA
    BIT_SET(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);

    // Set GPIOA pin 9 mode to alternate function mode
    BIT_CLEAR(GPIOA->MODER, GPIO_MODER_MODER9_MASK);
    BIT_SET(GPIOA->MODER, GPIO_MODER_MODER9_ALT_FUNC);

    // Set GPIOA pin 9 alternate function to AF7
    BIT_CLEAR(GPIOA->AFRH, GPIO_AFRH_AFRH9_MASK);
    BIT_SET(GPIOA->AFRH, GPIO_AFRH_AFRH9_AF7);

    // Set GPIOA pin 10 mode to alternate function mode
    BIT_CLEAR(GPIOA->MODER, GPIO_MODER_MODER10_MASK);
    BIT_SET(GPIOA->MODER, GPIO_MODER_MODER10_ALT_FUNC);

    // Set GPIOA pin 10 alternate function to AF7
    BIT_CLEAR(GPIOA->AFRH, GPIO_AFRH_AFRH10_MASK);
    BIT_SET(GPIOA->AFRH, GPIO_AFRH_AFRH10_AF7);

    // Enable USART1 clock
    BIT_SET(RCC->APB2ENR, RCC_APB2ENR_USART1EN);

    // Enable USART1
    BIT_SET(USART1->CR1, USART_CR1_UE);

    // Enable USART1 transmitter
    BIT_SET(USART1->CR1, USART_CR1_TE);

    // Enable USART1 receiver
    BIT_SET(USART1->CR1, USART_CR1_RE);

    // Set USART1 baud rate
    USART1->BRR = SYSCLK_FREQ / USART1_BAUD_RATE;

    while (1)
    {
        const char* str = "Send something and I will echo it.\n";

        while (*str)
        {
            // Write character to USART data register
            USART1->DR = *str;

            // Wait until transmit data register empty
            while (!BIT_CHECK(USART1->SR, USART_SR_TXE))
            {
                // Do nothing
            }

            ++str;
        }

        // Reset RX counter
        usart1_rx_count = 0;

        // Wait until read data register not empty
        while (!BIT_CHECK(USART1->SR, USART_SR_RXNE))
        {
            // Do nothing
        }

        while (1)
        {
            // If read data register not empty
            if (BIT_CHECK(USART1->SR, USART_SR_RXNE))
            {
                // Read data register
                usart1_rx_buffer[usart1_rx_count] = (uint8_t)USART1->DR;
                ++usart1_rx_count;
            }

            // If IDLE line detected
            if (BIT_CHECK(USART1->SR, USART_SR_IDLE))
            {
                break;
            }
        }

        // Send echo
        for (uint32_t i = 0; i < usart1_rx_count; ++i)
        {
            // Write character to USART data register
            USART1->DR = usart1_rx_buffer[i];

            // Wait until transmit data register empty
            while (!BIT_CHECK(USART1->SR, USART_SR_TXE))
            {
                // Do nothing
            }
        }

        delay_milliseconds(500);
    }
}

void SysTick_Handler()
{
    ++systick_counter;
}

void TIM2_Handler()
{
    // Clear TIM2 update interrupt flag
    BIT_CLEAR(TIM2->SR, TIM_SR_UIF);

    // Toggle GPIOC pin 13
    BIT_TOGGLE(GPIOC->ODR, GPIO_ODR_ODR13);
}
