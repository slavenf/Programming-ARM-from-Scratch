AS       = arm-none-eabi-as
CC		 = arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -std=c11 -g -Os -Wall -Wextra -Wpedantic -fno-builtin
LD       = arm-none-eabi-ld
OBJ-COPY = arm-none-eabi-objcopy
GDB      = arm-none-eabi-gdb
ST-FLASH = st-flash
ST-UTIL  = st-util

.PHONY: all
all: program.elf program.bin

STM32F411xE_startup.o: STM32F411xE_startup.S
	$(AS) STM32F411xE_startup.S -o STM32F411xE_startup.o -g

Reset_Handler.o: Reset_Handler.c
	$(CC) Reset_Handler.c -c -o Reset_Handler.o

main.o: main.c STM32F411xE.h Cortex-M4.h
	$(CC) main.c -c -o main.o

program.elf: STM32F411xE_startup.o Reset_Handler.o main.o STM32F411xE.ld
	$(LD) STM32F411xE_startup.o Reset_Handler.o main.o -o program.elf -T STM32F411xE.ld

program.bin: program.elf
	$(OBJ-COPY) -O binary program.elf program.bin

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.bin

.PHONY: flash
flash: program.bin
	$(ST-FLASH) write program.bin 0x08000000

.PHONY: gdb-server
gdb-server:
	$(ST-UTIL) -m

.PHONY: gdb
gdb: program.elf
	$(GDB) program.elf -ex "target remote :4242" -ex "load"
