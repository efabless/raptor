ARMGNU := arm-none-eabi

# GCCOPS := -Wall  -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value
GCCOPS := -Wall  -nostdlib -nostartfiles -ffreestanding -mthumb -mcpu=cortex-m0 -Wno-unused-value
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

PATTERN = blink

all:  ${PATTERN:=.vcd}

hex:  ${PATTERN:=.hex}

bin:  ${PATTERN:=.bin}

.PHONY: clean

$(OBJECTS): %.o : %.c
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:
%.hex : $(OBJECTS)
	$(ARMGNU)-as $(AOPS) -mcpu=cortex-m0 -o ../sw/start.o ../sw/cm0_startup.s
	$(COMPILE) $(GCCOPS) -o blink.o blink.c
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) ../sw/start.o blink.o $(OBJECTS) -o blink.elf
	$(ARMGNU)-objdump -D blink.elf > blink.lst
	$(ARMGNU)-objcopy blink.elf -O verilog blink.hex

%.bin : $(OBJECTS)
	$(ARMGNU)-as $(AOPS) -mcpu=cortex-m0 -o ../sw/start.o ../sw/cm0_startup.s
	$(COMPILE) $(GCCOPS) -o blink.o blink.c
	$(ARMGNU)-ld $(LDOPS) -T $(LINKSCRIPT) ../sw/start.o blink.o $(OBJECTS) -o blink.elf
	$(ARMGNU)-objdump -D blink.elf > blink.lst
	$(ARMGNU)-objcopy blink.elf -O binary blink.bin

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
