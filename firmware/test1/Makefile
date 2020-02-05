PATTERN = test1 test3

hex:  test1.hex test3.hex

bin:  ${PATTERN:=.bin}

.PHONY: clean flash hex all bin

$(OBJECTS): %.o : %.c
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:

test3.hex : test3.c
    arm-none-eabi-as -mcpu=cortex-m0 -o ../sw/start.o ../sw/cm0_startup.s
	arm-none-eabi-gcc -Wall  -nostdlib -nostartfiles -ffreestanding -mcpu=cortex-m0 -Wno-unused-value test3.c -o test3.o
	arm-none-eabi-ld -T memmap_qspi.ld ../sw/start.o test3.o -o test3.elf
    arm-none-eabi-objcopy  test3.elf -O verilog test3.hex

test1.hex : test1.s
	arm-none-eabi-as -mcpu=cortex-m0 test1.s -o test1.o
    arm-none-eabi-objcopy  test1.o -O verilog test1.hex

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

flash1: test1.hex
	python3 ../../test/raptor_flash.py test1.hex

flash3: test3.hex
	python3 ../../test/raptor_flash.py test3.hex
