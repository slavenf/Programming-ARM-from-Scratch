AS       = arm-none-eabi-as
LD       = arm-none-eabi-ld
OBJ-COPY = arm-none-eabi-objcopy
GDB      = arm-none-eabi-gdb
ST-FLASH = st-flash
ST-UTIL  = st-util

.PHONY: all
all: program.elf program.bin

STM32F411xE_startup.o: STM32F411xE_startup.S
	$(AS) STM32F411xE_startup.S -o STM32F411xE_startup.o -g

program.elf: STM32F411xE_startup.o main.o STM32F411xE.ld
	$(LD) STM32F411xE_startup.o main.o -o program.elf -T STM32F411xE.ld

program.bin: program.elf
	$(OBJ-COPY) -O binary program.elf program.bin

main.o: main.S
	$(AS) main.S -o main.o -g

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
