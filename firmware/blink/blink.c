//#include "../raptor.h"
#include "../sw/gpio_drv.h"

//#define     GPIO_DATA_REG           0x00000000
//#define     GPIO_DIR_REG            0x00000004
//#define     GPIO_BASE_ADDR          0x80000000
//
//unsigned int volatile * const GPIO_DATA =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);
//
//unsigned int volatile * const GPIO_DIR =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);


void led(int x) {
    gpio_write(x);
//    *GPIO_DATA = x;

    for (int j = 0; j < 70000; j++);
}

void main()
{
	// Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
//    *GPIO_DIR = 0;

    led(0x000f);

    while (1) {
        led(0x0000);
        led(0x0001);
        led(0x0002);
        led(0x0004);
        led(0x0008);
        led(0x0004);
        led(0x0002);
        led(0x0001);
    }

}

