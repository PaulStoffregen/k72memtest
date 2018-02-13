# path location for the arm-none-eabi compiler
# EDIT ME with the proper path
COMPILERPATH = $(HOME)/arduino-1.8.5/hardware/tools/arm/bin/

CFLAGS = -Wall -g -Os -mcpu=cortex-m4 -mthumb -nostdlib
CC = $(abspath $(COMPILERPATH))/arm-none-eabi-gcc-5.4.1
OBJDUMP = $(abspath $(COMPILERPATH))/arm-none-eabi-objdump
OBJCOPY = $(abspath $(COMPILERPATH))/arm-none-eabi-objcopy

all: k72memtest-3.1.hex k72memtest-3.6.hex

k72memtest-3.6.hex k72memtest-3.6.elf k72memtest-3.6.lst: k72memtest.c
	$(CC) $(CFLAGS) -DTEENSY36 -Tmk66fx1m0.ld -o k72memtest-3.6.elf k72memtest.c
	$(OBJDUMP) -d k72memtest-3.6.elf > k72memtest-3.6.lst
	$(OBJCOPY) -O ihex -R .eeprom k72memtest-3.6.elf k72memtest-3.6.hex

k72memtest-3.1.hex k72memtest-3.1.elf k72memtest-3.1.lst: k72memtest.c
	$(CC) $(CFLAGS) -DTEENSY31 -Tmk20dx256.ld -o k72memtest-3.1.elf k72memtest.c
	$(OBJDUMP) -d k72memtest-3.1.elf > k72memtest-3.1.lst
	$(OBJCOPY) -O ihex -R .eeprom k72memtest-3.1.elf k72memtest-3.1.hex

clean:
	rm -f *.o *.elf *.lst *.hex
