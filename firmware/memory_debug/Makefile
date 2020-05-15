ARMGNU := arm-none-eabi

# GCCOPS := -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
# GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
GCCOPS := -g -Wall -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -mthumb -Wno-unused-value
# GCCOPS := -Wall  -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn -Wa -mcpu=cortex-m0 #--fatal-warnings

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O2 -c

SRC_PREFIX := ../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

# LINKSCRIPT := $(SRC_PREFIX)/memmap_qspi.ld
# LINKSCRIPT := memmap_qspi.ld
# LINKSCRIPT := link.ld
LINKSCRIPT := sections.lds

PATTERN = blink

all:  ${PATTERN:=.hex}

hex:  ${PATTERN:=.hex}

bin:  ${PATTERN:=.bin}

.PHONY: clean flash hex all bin

$(OBJECTS): %.o : %.c
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS) blink.c ../raptor.h
	$(ARMGNU)-as $(AOPS) -o $(STARTUP_OBJECT) $(STARTUP)
# 	$(COMPILE) $(GCCOPS) -o start.o start.c
	$(COMPILE) $(GCCOPS) -o blink.o blink.c
# 	arm-none-eabi-gcc $(LDOPS) -T $(LINKSCRIPT) start.o blink.o -o blink.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) blink.o -o blink.elf
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) blink.o $(OBJECTS) -o blink.elf
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) $(STARTUP_OBJECT) ../sw/gpio_drv.o blink.o -o blink.elf
	$(ARMGNU)-objdump -d -S blink.elf > blink.lst
	$(ARMGNU)-objcopy blink.elf -O verilog blink.hex
	$(ARMGNU)-objcopy blink.elf
    python3 ../../util/check_bug.py blink.lst


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

flash: blink.hex
	python3 ../../util/raptor_flash.py blink.hex
