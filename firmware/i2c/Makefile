ARMGNU := arm-none-eabi

# GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0 #--fatal-warnings

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O1 -c

SRC_PREFIX := ../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c) ../raptor_io.c
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

LINKSCRIPT := $(SRC_PREFIX)/sections.ld

PATTERN = i2c

all:  hex

hex:  ${PATTERN:=.hex}

.PHONY: clean flash hex all bin

$(OBJECTS): %.o : %.c ../raptor.h ../raptor_io.h
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS) %.c ../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
	$(COMPILE) -o i2c.o i2c.c
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) $(OBJECTS) i2c.o -o i2c.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../raptor_io.o ../sw/gpio_drv.o ../sw/i2c_drv.o i2c.o -o i2c.elf
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../raptor_io.o ../sw/clkctrl.o ../sw/gpio_drv.o ../sw/i2c_drv.o i2c.o -o i2c.elf
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../sw/gpio_drv.o ../sw/i2c_drv.o i2c.o -o i2c.elf
# 	$(ARMGNU)-objdump -d -S i2c.elf > i2c.lst
	$(ARMGNU)-objdump -D i2c.elf > i2c.lst
	$(ARMGNU)-objcopy i2c.elf -O verilog i2c.hex

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

flash: i2c.hex
	python3 ../../test/raptor_flash.py i2c.hex


