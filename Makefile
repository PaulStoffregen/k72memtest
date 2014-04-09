# path location for the arm-none-eabi compiler
COMPILERPATH = /home/paul/teensy/arduino-1.0.5/hardware/tools/arm-none-eabi/bin

CFLAGS = -Wall -g -Os -mcpu=cortex-m4 -mthumb -nostdlib
CC = $(abspath $(COMPILERPATH))/arm-none-eabi-gcc
OBJDUMP = $(abspath $(COMPILERPATH))/arm-none-eabi-objdump
OBJCOPY = $(abspath $(COMPILERPATH))/arm-none-eabi-objcopy

k72memtest.hex k72memtest.elf k72memtest.lst: k72memtest.c
	$(CC) $(CFLAGS) -Tmk20dx256.ld -o k72memtest.elf k72memtest.c
	$(OBJDUMP) -d k72memtest.elf > k72memtest.lst
	$(OBJCOPY) -O ihex -R .eeprom k72memtest.elf k72memtest.hex

clean:
	rm -f *.o *.elf *.lst *.hex



