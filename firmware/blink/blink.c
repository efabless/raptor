//#include "../raptor.h"
#include "../sw/gpio_drv.h"

//#define     GPIO_BASE_ADDR      		0x80000000
//#define     GPIO_DATA_REG           	0x00000000
//#define     GPIO_DIR_REG            	0x00000004
//
//unsigned int volatile * const GPIO_DATA =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);
//
//unsigned int volatile * const GPIO_DIR =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);

//extern unsigned int volatile * const GPIO_DATA;
//extern unsigned int volatile * const GPIO_DIR;


void main()
{

//	uint32_t j;
	int j;


	// Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);
//    *GPIO_DIR = 0;
//    *GPIO_DATA = 0x000f;

    for (j = 0; j < 70000; j++);

    while (1) {
        gpio_write(0x0000);
//        *GPIO_DATA = 0x0000;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0001);
//        *GPIO_DATA = 0x0001;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0002);
//        *GPIO_DATA = 0x0002;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0004);
//        *GPIO_DATA = 0x0004;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0008);
//        *GPIO_DATA = 0x0008;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0004);
//        *GPIO_DATA = 0x0004;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0002);
//        *GPIO_DATA = 0x0002;
        for (j = 0; j < 70000; j++);
        gpio_write(0x0001);
//        *GPIO_DATA = 0x0001;
        for (j = 0; j < 70000; j++);
    }

}

