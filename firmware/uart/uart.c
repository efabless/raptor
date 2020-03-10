#include "../raptor.h"

#define     GPIO_BASE_ADDR      		0x80000000
#define     GPIO_DATA_REG           	0x00000000
#define     GPIO_DIR_REG            	0x00000004

unsigned int volatile * const GPIO_DATA =
    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);

unsigned int volatile * const GPIO_DIR =
    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);

void main()
{

	uint32_t i, j;
//	int i, j;

// Enable GPIO (all output, ena = 0)
//	gpio_set_dir(0x0000);
//    gpio_write(0x000f);

//    reg_gpio_ena = 0;
//    reg_gpio_data = 0x000f;
    *GPIO_DIR = 0;
    *GPIO_DATA = 0x000f;


    for (j = 0; j < 70000; j++);

    for (i = 0; i < 4; i++) {
//	    reg_gpio_data = i;
	    *GPIO_DATA = (0x0001 << i);
        for (j = 0; j < 34000; j++) {} // 2 sec
        *GPIO_DATA = 0x0008;
        for (j = 0; j < 34000; j++) {} // 2 sec
        *GPIO_DATA = 0x0001;
        for (j = 0; j < 34000; j++) {} // 2 sec
//	    reg_gpio_data = (0x0001 << i);
    }

//    reg_gpio_data = 0x000f;
    *GPIO_DATA = 0x0008;


//    for (j = 0; j < 70000; j++);

//    while (1) {
//        *GPIO_DATA = 0x0000;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0001;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0002;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0004;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0008;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0004;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0002;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0001;
//        for (j = 0; j < 70000; j++);
//    }
//
//    	uint32_t i,j;
//
//	uint32_t count;

	// NOTE: Crystal on testboard running at 8MHz
	// Internal clock is 8x crystal, or 64MHz
	// Divided by clkdiv is 9.6 kHz
	// So at this crystal rate, use clkdiv = 6667 for 9600 baud.

	// Set UART clock to 9600 baud
//	reg_uart_clkdiv = 6667;
//	reg_uart_clkdiv = 6600;

//	reg_gpio_enb = 0x0000;
//	reg_gpio_data = 0x0001;
//
//    for (i = 1; i < 5; i++) {
//        for (j = 0; j < 34000; j++); // 2 sec
//	    reg_gpio_data = (0x0001 << i);
//    }
//
//    reg_gpio_data = 0x000f;

	// This should appear on the LCD display 4x20 characters.
//    print("Starting...\n");

//    print("Press ENTER to continue..\n");
//    while (getchar() != '\r') {}

//    reg_gpio_data = 0x000a;
//    cmd_echo();
//    reg_gpio_data = 0x0000;

//    print("\n\n");

    while (1) {}

}

