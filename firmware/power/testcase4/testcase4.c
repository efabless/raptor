#include "../../raptor.h"

void main()
{
	gpio_set_dir(0x0000);
	while(1)
	{
		gpio_write(0x000f);
	}
} 

