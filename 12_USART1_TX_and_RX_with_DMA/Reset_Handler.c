#include <stdint.h>

extern uint32_t __data_begin;
extern uint32_t __data_end;
extern uint32_t __data_load;
extern uint32_t __bss_begin;
extern uint32_t __bss_end;

int main();

__attribute__((noreturn))
void Reset_Handler()
{
    // Initialize .data section
    {
        uint32_t* ptr = &__data_begin;
        uint32_t* end = &__data_end;
        uint32_t* load = &__data_load;

        while (ptr != end)
        {
            *ptr = *load;
            ++ptr;
            ++load;
        }
    }

    // Initialize .bss section
    {
        uint32_t* ptr = &__bss_begin;
        uint32_t* end = &__bss_end;

        while (ptr != end)
        {
            *ptr = 0;
            ++ptr;
        }
    }

    // Call main function
    main();

    // Infinite loop just in case something goes wrong
    while (1)
    {
        __asm__("bkpt");
    }
}
