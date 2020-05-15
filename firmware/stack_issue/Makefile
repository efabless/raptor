ARMGNU := arm-none-eabi

# GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value -finline-functions
# GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0 #--fatal-warnings

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O1  -c

SRC_PREFIX := ../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c) ../raptor_io.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

STARTUP := ./cm0_startup.s
STARTUP_OBJECT := ./start.o

LINKSCRIPT := ./sections.ld

PATTERN = test

all:  hex

hex:  ${PATTERN:=.hex}

.PHONY: clean flash hex all bin

$(OBJECTS): %.o : %.c ../raptor.h ../raptor_io.h
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS) %.c ../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
	$(COMPILE) -o test.o test.c
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) test.o -o test.elf
# 	$(ARMGNU)-objdump -d -S test.elf > test.lst
	$(ARMGNU)-objdump -D test.elf > test.lst
	$(ARMGNU)-objcopy test.elf -O verilog test.hex
	grep 'push' test.lst
	grep 'pop' test.lst

sim:
	iverilog -D RTL -D DBG -D JTAG -D CREATE_DUMPS -Wall -Wno-timescale -c files_gl.list -s SoC_tb -o SoC.tb.vvp 2>&1 | grep -v "warning"
# 	iverilog -D RTL -D DBG -D JTAG -D CREATE_DUMPS -Wall -Wno-timescale -c files.list -s SoC_tb -o SoC.tb.vvp 2>&1 | grep -v "warning"
# 	iverilog -D RTL -D DBG -D JTAG -D CREATE_DUMPS -Wall -Wno-timescale -c files.list -s SoC_tb -o SoC.tb.vvp 2>&1 | grep -v "warning"
	vvp SoC.tb.vvp | grep -v "Standard inconsistency," | grep -v "VCD" | tee -a results.out

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
	rm -f *.o

flash:
	python3 ../../test/raptor_flash.py test.hex


