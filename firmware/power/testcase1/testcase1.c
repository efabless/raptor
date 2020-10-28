#include "../../raptor.h"

void main()
{
	int j;
	gpio_set_dir(0x0000);
	while(1)
	{
		gpio_write(0x0001);
    		for (j = 0; j < 70000; j++);
		gpio_write(0x0002);
		for (j = 0; j < 70000; j++);
		gpio_write(0x0004);
		for (j = 0; j < 70000; j++);
		gpio_write(0x0008);
		for (j = 0; j < 70000; j++);
	}
} 
