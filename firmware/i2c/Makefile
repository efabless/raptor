ARMGNU := arm-none-eabi

# GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value -finline-functions
GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
# GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0 #--fatal-warnings

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O1 -c

SRC_PREFIX := ../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c) ../raptor_io.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
ASMBYS = $(patsubst %.c,%.s,$(SOURCES))
ORIG = $(patsubst %.c,%.s.orig,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

LINKSCRIPT := $(SRC_PREFIX)/sections.ld

PATTERN = i2c

all:  hex

hex:  ${PATTERN:=.hex}

.PHONY: clean flash hex all bin

$(ASMBYS): %.s : %.c ../raptor.h ../raptor_io.h
	@echo ">> Compiling assembly $<"
	$(COMPILE) -S -fverbose-asm -o $@ $<
	python3 ../../util/code_workaround.py $@

# $(OBJECTS): %.o : %.c ../raptor.h ../raptor_io.h
$(OBJECTS): %.o : %.s ../raptor.h ../raptor_io.h
	@echo ">> Compiling objects$<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS) %.c ../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
	$(COMPILE) -S -fverbose-asm -o i2c.s i2c.c
	python3 ../../util/code_workaround.py i2c.s
	$(COMPILE) -o i2c.o i2c.s
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) $(OBJECTS) i2c.o -o i2c.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../sw/gpio_drv.o ../sw/i2c_drv.o ../raptor_io.o i2c.o -o i2c.elf
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../raptor_io.o ../sw/clkctrl.o ../sw/gpio_drv.o ../sw/i2c_drv.o i2c.o -o i2c.elf
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../sw/gpio_drv.o ../sw/i2c_drv.o i2c.o -o i2c.elf
# 	$(ARMGNU)-objdump -d -S i2c.elf > i2c.lst
	$(ARMGNU)-objdump -D i2c.elf > i2c.lst
	$(ARMGNU)-objcopy i2c.elf -O verilog i2c.hex
	grep 'push' i2c.lst
	grep 'pop' i2c.lst
	python3 ../../util/check_bug.py i2c.lst

sim:
	iverilog -D RTL -D DBG -D JTAG -D CREATE_DUMPS -Wall -Wno-timescale -c files_gl.list -s SoC_tb -o SoC.tb.vvp 2>&1 | grep -v "warning"
# 	iverilog -D RTL -D DBG -D JTAG -D CREATE_DUMPS -Wall -Wno-timescale -c files.list -s SoC_tb -o SoC.tb.vvp 2>&1 | grep -v "warning"
# 	iverilog -D RTL -D DBG -D JTAG -D CREATE_DUMPS -Wall -Wno-timescale -c files.list -s SoC_tb -o SoC.tb.vvp 2>&1 | grep -v "warning"
	vvp SoC.tb.vvp | grep -v "Standard inconsistency," | grep -v "VCD" | tee -a results.out

clean :
	rm -rf Dumps
	rm -f $(OBJECTS)
	rm -f $(ASMBYS)
	rm -f $(ORIG)
	rm -f *.s
	rm -f *.bin
	rm -f *.elf
	rm -f *.lst
	rm -f *.hex
	rm -f *.vvp
	rm -f *.vcd
	rm -f *.out
	rm -f *.o

flash: i2c.hex
	python3 ../../util/raptor_flash.py i2c.hex


