#include "STM32F411xE.h"

// HSE clock frequency
#define HSECLK_FREQ 25000000

// System clock frequency is equal to HSE clock frequency
#define SYSCLK_FREQ HSECLK_FREQ

// SysTick frequency
#define SYSTICK_FREQ (SYSCLK_FREQ / 1000)

// USART1 baud rate
#define USART1_BAUD_RATE 115200



// Size of USART1 TX buffer
#define USART1_TX_BUFFER_SIZE 1000

// USART1 TX buffer
uint8_t usart1_tx_buffer[USART1_TX_BUFFER_SIZE];

// Number of charactes in USART1 TX buffer
uint32_t usart1_tx_size;

// Current number of transmitted charactes.
// This variable is used by interrupt routine.
// The total number of transmitted charactes is stored in `usart1_tx_size`.
volatile uint32_t usart1_tx_count;

// Size of USART1 RX buffer
#define USART1_RX_BUFFER_SIZE 1000

// USART1 RX buffer
uint8_t usart1_rx_buffer[USART1_RX_BUFFER_SIZE];

// Number of charactes in USART1 RX buffer
uint32_t usart1_rx_size;

// Current number of received character.
// This variable is used by interrupt routine.
// The total number of received character is stored in `usart1_rx_size`.
volatile uint32_t usart1_rx_count;

#define USART_STATE_READY   1
#define USART_STATE_BUSY    2

// USART1 current state.
volatile uint32_t usart1_state;



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

// Returns length of string without null-character.
__attribute__((optimize("O0")))
uint32_t string_length(const char* str)
{
    uint32_t len = 0;

    while (*str)
    {
        ++len;
        ++str;
    }

    return len;
}

// Copies string from `src` to `dest`. Null-character is also copied.
__attribute__((optimize("O0")))
void string_copy(char* dest, const char* src)
{
    while (*src)
    {
        *dest = *src;
        ++dest;
        ++src;
    }

    *dest = 0;
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

    // Enable USART1 interrupt
    irq_enable(USART1_IRQn);

    // Set USART1 counters to zero.
    // These counters are used inside USART1 interrupt routine.
    usart1_tx_count = 0;
    usart1_rx_count = 0;

    while (1)
    {
        // --------------------------------------------------------------------
        // STEP 1: Send message
        // --------------------------------------------------------------------

        // Write message to USART1 TX buffer
        string_copy((char*)usart1_tx_buffer, "Send something and I will echo it.\n");

        // Number of characters in USART1 TX buffer
        usart1_tx_size = string_length((const char*)usart1_tx_buffer);

        // Set state to busy
        usart1_state = USART_STATE_BUSY;

        // Enable TXE interrupt
        BIT_SET(USART1->CR1, USART_CR1_TXEIE);

        // Wait until transmission complete
        while (usart1_state != USART_STATE_READY)
        {
            // Do nothing
        }

        // --------------------------------------------------------------------
        // STEP 2: Receive message
        // --------------------------------------------------------------------

        // Set state to busy
        usart1_state = USART_STATE_BUSY;

        // Enable RXNE interrupt
        BIT_SET(USART1->CR1, USART_CR1_RXNEIE);

        // Wait until transmission complete
        while (usart1_state != USART_STATE_READY)
        {
            // Do nothing
        }

        // --------------------------------------------------------------------
        // STEP 3: Send echo
        // --------------------------------------------------------------------

        // Copy message from RX to TX buffer
        string_copy((char*)usart1_tx_buffer, (const char*)usart1_rx_buffer);

        // Set number of character to transmit
        usart1_tx_size = usart1_rx_size;

        // Set state to busy
        usart1_state = USART_STATE_BUSY;

        // Enable TXE interrupt
        BIT_SET(USART1->CR1, USART_CR1_TXEIE);

        // Wait until transmission complete
        while (usart1_state != USART_STATE_READY)
        {
            // Do nothing
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

void USART1_Handler()
{
    // If transmit data register empty
    if
    (
        BIT_CHECK(USART1->CR1, USART_CR1_TXEIE) &&
        BIT_CHECK(USART1->SR, USART_SR_TXE)
    )
    {
        // Write character to USART data register
        USART1->DR = usart1_tx_buffer[usart1_tx_count++];

        if (usart1_tx_count == usart1_tx_size)
        {
            // Disable TXE interrupt
            BIT_CLEAR(USART1->CR1, USART_CR1_TXEIE);

            // Enable TC interrupt
            BIT_SET(USART1->CR1, USART_CR1_TCIE);
        }
    }
    // If transmission complete
    else if
    (
        BIT_CHECK(USART1->CR1, USART_CR1_TCIE) &&
        BIT_CHECK(USART1->SR, USART_SR_TC)
    )
    {
        // Reset TX counter for next transmission
        usart1_tx_count = 0;

        // Disable TC interrupt
        BIT_CLEAR(USART1->CR1, USART_CR1_TCIE);

        // Set USART state to READY
        usart1_state = USART_STATE_READY;
    }
    // If read data register not empty
    else if
    (
        BIT_CHECK(USART1->CR1, USART_CR1_RXNEIE) &&
        BIT_CHECK(USART1->SR, USART_SR_RXNE)
    )
    {
        // Read character from USART data register
        usart1_rx_buffer[usart1_rx_count++] = 0xFF & USART1->DR;

        // Enable IDLE interrupt
        BIT_SET(USART1->CR1, USART_CR1_IDLEIE);
    }
    // If IDLE line detected
    else if
    (
        BIT_CHECK(USART1->CR1, USART_CR1_IDLEIE) &&
        BIT_CHECK(USART1->SR, USART_SR_IDLE)
    )
    {
        usart1_rx_size = usart1_rx_count;

        // Reset RX counter for next transmission
        usart1_rx_count = 0;

        // Disable RXNE interrupt
        BIT_CLEAR(USART1->CR1, USART_CR1_RXNEIE);

        // Disable IDLE interrupt
        BIT_CLEAR(USART1->CR1, USART_CR1_IDLEIE);

        // Set USART state to READY
        usart1_state = USART_STATE_READY;
    }
}
