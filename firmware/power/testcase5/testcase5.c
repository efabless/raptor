
#include "../../raptor.h"

extern unsigned long _sidata;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;

void main()
{
	int x,j;
	unsigned long *src, *dst, *dstend;
	
	src = &_sidata;
	dst = &_sdata;
	dstend = &_edata;
	
	while(dst < dstend) {
		*(dst++) = *(src++);
	}

	dst = &_sbss;
	while(dst < &_ebss){
		*(dst++) = 0; 
	}

	gpio_set_dir(0x0000);
	gpio_write(0x000f);

	for(j = 0; j < 70000; j++);		
}

