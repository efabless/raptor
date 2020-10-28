ARMGNU := arm-none-eabi

GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O1 -c

SRC_PREFIX := ../../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

LINKSCRIPT := $(SRC_PREFIX)/sections.ld

PATTERN = testcase3

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
	$(COMPILE) -S -fverbose-asm -o testcase3.s testcase3.c
	python3 ../../../util/code_workaround.py testcase3.s
	$(COMPILE) -o testcase3.o testcase3.s
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../../sw/gpio_drv.o testcase3.o -o testcase3.elf
	$(ARMGNU)-objdump -D testcase3.elf > testcase3.lst
	$(ARMGNU)-objcopy testcase3.elf -O verilog testcase3.hex
	python3 ../../../util/check_bug.py testcase3.lst

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

flash: testcase3.hex
	python3 ../../../util/raptor_flash.py testcase3.hex
	

