MEMORY {
    FLASH   : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM    : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS {
    .vector_table : {
        *(.vector_table)
    } > FLASH

    .text : {
        *(.text)
        . = ALIGN(4);
    } > FLASH

    .stack (NOLOAD) : {
        . = . + 0x400;
        __stack_end = .;
    } > SRAM

    .data : {
        __data_begin = .;
        *(.data)
        . = ALIGN(4);
        __data_end = .;
    } > SRAM AT > FLASH

    __data_load = LOADADDR(.data);

    .bss (NOLOAD) : {
        __bss_begin = .;
        *(.bss)
        . = ALIGN(4);
        __bss_end = .;
    } > SRAM
}
