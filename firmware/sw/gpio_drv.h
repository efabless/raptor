#ifndef GPIO_DRV_H
#define GPIO_DRV_H

void gpio_set_dir(unsigned int dir);
unsigned int gpio_read();
void gpio_write(unsigned int data);

#endif