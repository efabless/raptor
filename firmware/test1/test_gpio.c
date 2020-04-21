#include "test_gpio.h"

//#define     GPIO_BASE_ADDR      		0x80000000
//#define     GPIO_DATA_REG           	0x00000000
//#define     GPIO_DIR_REG            	0x00000004
//
//unsigned int volatile * const GPIO_DATA =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);
//
//unsigned int volatile * const GPIO_DIR =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);

unsigned int volatile * const GPIO_DATA =
    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);

unsigned int volatile * const GPIO_DIR =
    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);

void test_gpio() {
	int count;
	*GPIO_DIR = 0;
	for(count=0;;count++)
		*GPIO_DATA = (count >>16);
}