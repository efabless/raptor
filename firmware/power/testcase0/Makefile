ARMGNU := arm-none-eabi

GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O1 -c

SRC_PREFIX := ../../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c) ../../raptor.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
ASMBYS = $(patsubst %.c,%.s,$(SOURCES))
ORIG = $(patsubst %.c,%.s.orig,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

LINKSCRIPT := $(SRC_PREFIX)/sections.ld

PATTERN = testcase0

all:  hex

hex:  ${PATTERN:=.hex}

.PHONY: clean flash hex all bin

$(ASMBYS) : %.s : %.c ../../raptor.h 
	@echo ">> Compiling assembly $<"
	$(COMPILE) -S -fverbose-asm -o $@ $<
	python3 ../../../util/code_workaround.py $@

$(OBJECTS): %.o : %.s ../../raptor.h
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

%.hex : $(OBJECTS) %.c ../../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
	$(COMPILE) -S -fverbose-asm -o testcase0.s testcase0.c
	python3 ../../../util/code_workaround.py testcase0.s
	$(COMPILE) -o testcase0.o testcase0.s
#	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../../sw/gpio_drv.o testcase0.o -o testcase0.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) $(OBJECTS) testcase0.o -o testcase0.elf
	$(ARMGNU)-objdump -D testcase0.elf > testcase0.lst
	$(ARMGNU)-objcopy testcase0.elf -O verilog testcase0.hex
	python3 ../../../util/check_bug.py testcase0.lst

clean :
	rm -rf Dumps
	rm -f $(OBJECTS)
	rm -f *.bin
	rm -f *.elf
	rm -f *.lst
	rm -f *.hex
	rm -f *.vvp
	rm -f *.vcd
	rm -f *.out

flash: testcase0.hex
	python3 ../../../util/raptor_flash.py testcase0.hex
	

