AS       = arm-none-eabi-as
LD       = arm-none-eabi-ld
OBJ-COPY = arm-none-eabi-objcopy
GDB      = arm-none-eabi-gdb
ST-FLASH = st-flash
ST-UTIL  = st-util

.PHONY: all
all: example.elf

example.elf: example.o
	$(LD) example.o -o example.elf -Ttext=0x08000000

example.o: example.S
	$(AS) example.S -o example.o -g

example.bin: example.elf
	$(OBJ-COPY) -O binary example.elf example.bin

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.elf
	rm -rf *.bin

.PHONY: flash
flash: example.bin
	$(ST-FLASH) write example.bin 0x08000000

.PHONY: gdb-server
gdb-server:
	$(ST-UTIL) -m

.PHONY: gdb
gdb: example.elf
	$(GDB) example.elf -ex "target remote :4242" -ex "load"
