#include "../../raptor.h"

void main()
{
	int j;
	gpio_set_dir(0x0000);
	while(1)
	{
		gpio_write(0x0003);	//0000 0000 0000 0011
    		for (j = 0; j < 70000; j++);
		gpio_write(0x0005);	//0000 0000 0000 0101
		for (j = 0; j < 70000; j++);
		gpio_write(0x0009);	//0000 0000 0000 1001
		for (j = 0; j < 70000; j++);
		gpio_write(0x0006);	//0000 0000 0000 0110
		for (j = 0; j < 70000; j++);
		gpio_write(0x000a);	//0000 0000 0000 1010
    		for (j = 0; j < 70000; j++);
		gpio_write(0x000c);	//0000 0000 0000 1100
		for (j = 0; j < 70000; j++);
	}
} 
