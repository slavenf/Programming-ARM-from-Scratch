AS  = arm-none-eabi-as
LD  = arm-none-eabi-ld
GDB = arm-none-eabi-gdb

.PHONY: all
all: example.elf

example.elf: example.o
	$(LD) example.o -o example.elf -Ttext=0x08000000

example.o: example.S
	$(AS) example.S -o example.o -g

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.elf

.PHONY: gdb-server
gdb-server:
	st-util -m

.PHONY: gdb
gdb: example.elf
	$(GDB) example.elf -ex "target remote :4242" -ex "load"
