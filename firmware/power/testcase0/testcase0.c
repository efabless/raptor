#include "../../raptor.h"

void main()
{
	int j;

	//    set_clock_50MHz_ext();
	//    set_clock_40MHz_int();
    //    set_clock_80MHz_int();

    set_clock_int(1);  // set internal clk (10MHz) with PLL (x8) plus divider
                       // 0 = div 2, 1 = div 4, 2 = div 8, 3 = div 16,
                       // >3 = no div (80 MHz)

	while(1)
	{
		gpio_set_dir(0x0000);
		gpio_write(0x0000);
	}
} 

/*
0 LED	1 LED	2 LED	3 LED	4 LED	hex
--------------------------------------------
0000					0
	0001				1
	0010				2
		0011			3
	0100				4
		0101			5
		0110			6
			0111		7
	1000				8
		1001			9
		1010			a
			1011		b
		1100			c
			1101		d
			1110		e
				1111	f
*/
