#include "../../raptor.h"

void main()
{
	int j;
	gpio_set_dir(0x0000);
	while(1)
	{
		gpio_write(0x0007);	//0000 0000 0000 0111
    		for (j = 0; j < 70000; j++);
		gpio_write(0x000b);	//0000 0000 0000 1011
		for (j = 0; j < 70000; j++);
		gpio_write(0x000d);	//0000 0000 0000 1101
		for (j = 0; j < 70000; j++);
		gpio_write(0x000e);	//0000 0000 0000 1110
		for (j = 0; j < 70000; j++);
	}
} 
