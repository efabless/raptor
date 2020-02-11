#include "../raptor.h"

void main()
{

	uint32_t j;

//	CLKCTRL_CLKCR =
//	CLKCTRL_PLLCR =
//	CLKCTRL_PLLTR =

//    *(0x80000004) = (unsigned int) 0x0000;
//    *(0x80000000) = (unsigned int) 0x000f;

	// Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);

//    for (j = 0; j < 170000; j++);

    while (1) {
        gpio_write(0x0000);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0001);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0002);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0004);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0008);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0004);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0002);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0001);
        for (j = 0; j < 70000; j++);
    }

}

