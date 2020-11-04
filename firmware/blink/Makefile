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

PATTERN = blink

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
%.hex : $(OBJECTS) blink.c ../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
	$(COMPILE) -S -fverbose-asm -o blink.s blink.c
	python3 ../../util/code_workaround.py blink.s
	$(COMPILE) -o blink.o blink.s

#	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) $(OBJECTS) ../raptor.o blink.o -o blink.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) $(OBJECTS) blink.o -o blink.elf
# 	$(ARMGNU)-objdump -d -S blink.elf > blink.lst
	$(ARMGNU)-objdump -D blink.elf > blink.lst
	$(ARMGNU)-objcopy blink.elf -O verilog blink.hex
	python3 ../../util/check_bug.py blink.lst


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

flash: blink.hex
	python3 ../../util/raptor_flash.py blink.hex
