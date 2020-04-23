#include "gpio_drv.h"

unsigned int volatile * const GPIO_DATA =
    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);

unsigned int volatile * const GPIO_DIR =
    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);

void gpio_set_dir(unsigned int dir){
//    *GPIO_DIR = dir;
    reg_gpio_dir = dir;
}

unsigned int gpio_read(){
//    return *GPIO_DATA;
    return reg_gpio_data;
}

void gpio_write(unsigned int data){
//    *GPIO_DATA = data;
    reg_gpio_data = data;
}