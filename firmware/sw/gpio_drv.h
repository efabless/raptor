#ifndef GPIO_DRV_H
#define GPIO_DRV_H

#include "gpio_regs.h"

void gpio_set_dir(unsigned int dir);
unsigned int gpio_read();
void gpio_write(unsigned int data);

#endif