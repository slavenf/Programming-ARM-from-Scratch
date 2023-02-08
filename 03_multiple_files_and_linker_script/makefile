AS       = arm-none-eabi-as
LD       = arm-none-eabi-ld
OBJ-COPY = arm-none-eabi-objcopy
GDB      = arm-none-eabi-gdb
ST-FLASH = st-flash
ST-UTIL  = st-util

.PHONY: all
all: program.elf program.bin

vector_table.o: vector_table.S
	$(AS) vector_table.S -o vector_table.o -g

reset_handler.o: reset_handler.S
	$(AS) reset_handler.S -o reset_handler.o -g

main.o: main.S
	$(AS) main.S -o main.o -g

program.elf: vector_table.o reset_handler.o main.o STM32F411xE.ld
	$(LD) vector_table.o reset_handler.o main.o -o program.elf -T STM32F411xE.ld

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
