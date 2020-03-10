ARMGNU := arm-none-eabi

GCCOPS := -Wall  -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
# GCCOPS := -Wall  -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m0 -Wno-unused-value
AOPS := --warn #--fatal-warnings

COMPILE := $(ARMGNU)-gcc $(GCCOPS) -O0 -c

SRC_PREFIX := ../sw

SOURCES = $(shell find $(SRC_PREFIX) | grep _drv.c)
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

STARTUP := $(SRC_PREFIX)/cm0_startup.s
STARTUP_OBJECT := $(SRC_PREFIX)/start.o

# LINKSCRIPT := $(SRC_PREFIX)/memmap_qspi.ld
LINKSCRIPT := memmap_qspi.ld
# LINKSCRIPT := sections.lds

PATTERN = uart

all:  hex client

hex:  ${PATTERN:=.hex}

.PHONY: clean flash hex all bin

$(OBJECTS): %.o : %.c
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS)
	$(ARMGNU)-as $(AOPS) -mcpu=cortex-m0 -o ../sw/start.o ../sw/cm0_startup.s
	$(COMPILE) $(GCCOPS) -o uart.o uart.c
# 	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) ../sw/start.o blink.o $(OBJECTS) -o blink.elf
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) ../sw/start.o uart.o -o uart.elf
	$(ARMGNU)-objdump -D uart.elf > uart.lst
	$(ARMGNU)-objcopy uart.elf -O verilog uart.hex

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

client: client.c
	gcc client.c -o client

flash: uart.hex
	python3 ../../test/raptor_flash.py uart.hex
