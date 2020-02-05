hex:  test1.hex

bin:  ${PATTERN:=.bin}

.PHONY: clean flash hex all bin

$(OBJECTS): %.o : %.c
	@echo ">> Compiling $<"
	$(COMPILE) -o $@ $<

#.SILENT:
test1.hex : test1.s
	arm-none-eabi-as test1.s -o test1.o
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

flash: test1.hex
	python3 ../../test/raptor_flash.py test1.hex
