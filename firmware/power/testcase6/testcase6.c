#include "../../raptor.h"

void putchar(uint32_t c)
{
	reg_uart_data = c;
	reg_uart1_data = c;
}

void print(const char *p)
{
	while (*p)
		putchar(*(p++));
}

void print_dec(uint32_t v)
{
	if (v >= 2000) {
		print("OVER");
		return;
	}
	else if (v >= 1000) { putchar('1'); v -= 1000; }
	else putchar(' ');

	if 	(v >= 900) { putchar('9'); v -= 900; }
	else if	(v >= 800) { putchar('8'); v -= 800; }
	else if	(v >= 700) { putchar('7'); v -= 700; }
	else if	(v >= 600) { putchar('6'); v -= 600; }
	else if	(v >= 500) { putchar('5'); v -= 500; }
	else if	(v >= 400) { putchar('4'); v -= 400; }
	else if	(v >= 300) { putchar('3'); v -= 300; }
	else if	(v >= 200) { putchar('2'); v -= 200; }
	else if	(v >= 100) { putchar('1'); v -= 100; }
	else putchar('0');

	if 	(v >= 90) { putchar('9'); v -= 90; }
	else if	(v >= 80) { putchar('8'); v -= 80; }
	else if	(v >= 70) { putchar('7'); v -= 70; }
	else if	(v >= 60) { putchar('6'); v -= 60; }
	else if	(v >= 50) { putchar('5'); v -= 50; }
	else if	(v >= 40) { putchar('4'); v -= 40; }
	else if	(v >= 30) { putchar('3'); v -= 30; }
	else if	(v >= 20) { putchar('2'); v -= 20; }
	else if	(v >= 10) { putchar('1'); v -= 10; }
	else putchar('0');

	if 	(v >= 9) { putchar('9'); v -= 9; }
	else if	(v >= 8) { putchar('8'); v -= 8; }
	else if	(v >= 7) { putchar('7'); v -= 7; }
	else if	(v >= 6) { putchar('6'); v -= 6; }
	else if	(v >= 5) { putchar('5'); v -= 5; }
	else if	(v >= 4) { putchar('4'); v -= 4; }
	else if	(v >= 3) { putchar('3'); v -= 3; }
	else if	(v >= 2) { putchar('2'); v -= 2; }
	else if	(v >= 1) { putchar('1'); v -= 1; }
	else putchar('0');
}

void main()
{
	int j;
	int data, x, v;

	gpio_set_dir(0x0000);
   	gpio_write(0x000f);

	for (j = 0; j < 70000; j++);

	print("Starting...");
	adc_enable();
	adc_set_vrefh(0);
	adc_set_channel(0);
	adc_set_prescalar(9); 

    	while (1) 
    	{
        	data = adc_acquire();
        	print(":");
        	print_dec(data);

        	v = data;
        	x = 1;
        	while (1)
 		{
            		if (v > 256) 
			{
                		v = v - 256;
                		x = x << 1;
                		x = x | 1;
            		} 
			else
			{
                		break;
            		}
        	}
        	gpio_write(x);
        	for (j = 0; j < 34000; j++) {} // 2 sec
    	}
} 

