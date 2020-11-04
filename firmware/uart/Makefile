ARMGNU := arm-none-eabi

# GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0 #--fatal-warnings

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O1 -c

SRC_PREFIX := ../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c) ../raptor.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
ASMBYS = $(patsubst %.c,%.s,$(SOURCES))
ORIG = $(patsubst %.c,%.s.orig,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

LINKSCRIPT := $(SRC_PREFIX)/sections.ld

PATTERN = uart

all:  hex

hex:  ${PATTERN:=.hex}

.PHONY: clean flash hex all bin

$(ASMBYS): %.s : %.c ../raptor.h
	@echo ">> Compiling assembly $<"
	$(COMPILE) -S -fverbose-asm -o $@ $<
	python3 ../../util/code_workaround.py $@

$(OBJECTS): %.o : %.s ../raptor.h
	@echo ">> Compiling objects $<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS) %.c ../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
	$(COMPILE) -S -fverbose-asm -o uart.s uart.c
	python3 ../../util/code_workaround.py uart.s
	$(COMPILE) -o uart.o uart.s

# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) $(OBJECTS) uart.o -o uart.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../sw/gpio_drv.o ../raptor.o uart.o -o uart.elf
	$(ARMGNU)-objdump -D uart.elf > uart.lst
	$(ARMGNU)-objcopy uart.elf -O verilog uart.hex
	python3 ../../util/check_bug.py uart.lst


clean :
	rm -rf Dumps
	rm -f $(OBJECTS)
	rm -f $(ASMBYS)
	rm -f $(ORIG)
	rm -f *.bin
	rm -f *.elf
	rm -f *.lst
	rm -f *.hex
	rm -f *.vvp
	rm -f *.vcd
	rm -f *.out

flash: uart.hex
	python3 ../../util/raptor_flash.py uart.hex


