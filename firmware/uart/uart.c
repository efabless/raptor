#include "../raptor.h"

void set_clock(bool hse, bool pll, int div) {

#define   HSE_ON      *CLKCTRL_CLKCR |= 0x10
#define   PLL_ON      *CLKCTRL_PLLCR |= 0x1
#define   PLL_DIV(d)  *CLKCTRL_PLLCR &= 0x3; *CLKCTRL_PLLCR |= (d<<2); *CLKCTRL_CLKCR |= 2

//	if (hse){
//	    HSE_ON;
	    *((unsigned int *)(0x50000008)) = 0x10;  // HSE on
//	    *CLKCTRL_CLKCR = 0x10; // HSE
        for (int j = 0; j < 15000; j++); // wait for HSE to stabilize

        *((unsigned int *)(0x50000008)) |= 0x2;  // DIV bypass

	    *((unsigned int *)(0x50000000)) |= 0x2;  // PLL source = ext
	    *((unsigned int *)(0x50000000)) = 0x01;  // PLL on
        for (int j = 0; j < 15000; j++); // wait for PLL to lock

        *((unsigned int *)(0x50000008)) |= 0x4;  // set sysclk to ext

//	}
//	if (pll) {
//	    PLL_ON;
//        for (int j = 0; j < 70000; j++);
//	}
//	if (div)
//	    PLL_DIV(div);

    // configure the clock muxes
//    *CLKCTRL_PLLCR = 0x3;

//    *CLKCTRL_CLKCR |= 0x5;
//    *((unsigned int *)(0x50000008)) |= 0x5;  // external with PLL by-pass

//    for (int j = 0; j < 15000; j++);


//    *CLKCTRL_CLKCR = 0x16;
//    *CLKCTRL_CLKCR = 0x14;
//    PLL_DIV(2);

    //    *CLKCTRL_CLKCR |= 0x6;
    //    *CLKCTRL_CLKCR = 0x1e;

}

void putchar(uint32_t c)
{
//	if (c == '\n')
//		putchar('\r');
	reg_uart_data = c;
	reg_uart1_data = c;
}

void print(const char *p)
{
	while (*p)
		putchar(*(p++));
}

void print_hex(uint32_t v, int digits)
{
	for (int i = digits - 1; i >= 0; i--) {
		char c = "0123456789abcdef"[(v >> (4*i)) & 15];
		putchar(c);
	}
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

void print_digit(uint32_t v)
{
    v &= (uint32_t)0x000F;

    if (v == 9) { putchar('9'); }
    else if (v == 8) { putchar('8'); }
    else if (v == 7) { putchar('7'); }
    else if (v == 6) { putchar('6'); }
    else if (v == 5) { putchar('5'); }
    else if (v == 4) { putchar('4'); }
    else if (v == 3) { putchar('3'); }
    else if (v == 2) { putchar('2'); }
    else if (v == 1) { putchar('1'); }
    else if (v == 0) { putchar('0'); }
    else putchar('*');
}

//char getchar_prompt(char *prompt)
//{
//	int32_t c = -1;
//
//	uint32_t cycles_begin, cycles_now, cycles;
//	__asm__ volatile ("rdcycle %0" : "=r"(cycles_begin));
//
////	reg_leds = ~0;
//
//	if (prompt)
//		print(prompt);
//
//	while (c == -1) {
//		__asm__ volatile ("rdcycle %0" : "=r"(cycles_now));
//		cycles = cycles_now - cycles_begin;
//		if (cycles > 12000000) {
//			if (prompt)
//				print(prompt);
//			cycles_begin = cycles_now;
////			reg_leds = ~reg_leds;
//		}
//		c = reg_uart_data;
//	}
//
////	reg_leds = 0;
//	return c;
//}

uint32_t getchar()
{
	int32_t c = -1;
	while (c == -1) {
		c = reg_uart_data;
	}
	return c;
}

void cmd_echo()
{
	print("Return to menu by sending '!'\n\n");
	uint32_t c;
	while ((c = getchar()) != '!') {
		if (c == '\r')
		    putchar('\n');
        else {
		    putchar(c);
//		    reg_gpio_data = c >> 4;
		    reg_gpio_data = c;
        }
    }
}

void main()
{
//	uint32_t i, j;
	int i, j;


    for (j = 0; j < 70000; j++);

    // Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);

    set_clock(true, true, 0);

    gpio_write(0x000a);


//    reg_gpio_ena = 0;
//    reg_gpio_data = 0x000f;
//    *GPIO_DIR = 0;
//    *GPIO_DATA = 0x000f;

    for (j = 0; j < 70000; j++);

    for (i = 0; i < 4; i++) {
	    gpio_write(i);
//	    *GPIO_DATA = (0x0001 << i);
	    gpio_write(0x0001 << i);
//	    *GPIO_DATA = i+1;
	    gpio_write( i+1);
        for (j = 0; j < 34000; j++) {} // 2 sec
//        *GPIO_DATA = 0x0008;
        gpio_write(0x0008);
        for (j = 0; j < 34000; j++) {} // 2 sec
        gpio_write(0x0001);
        for (j = 0; j < 34000; j++) {} // 2 sec
	    gpio_write(0x0001 << i);
    }

//    reg_gpio_data = 0x000f;
    gpio_write(0x000f);


//    for (j = 0; j < 70000; j++);

//    while (1) {
//        *GPIO_DATA = 0x0000;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0001;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0002;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0004;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0008;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0004;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0002;
//        for (j = 0; j < 70000; j++);
//        *GPIO_DATA = 0x0001;
//        for (j = 0; j < 70000; j++);
//    }
//
//    	uint32_t i,j;
//
//	uint32_t count;

	// NOTE: Crystal on testboard running at 8MHz
	// Internal clock is 8x crystal, or 64MHz
	// Divided by clkdiv is 9.6 kHz
	// So at this crystal rate, use clkdiv = 6667 for 9600 baud.


//	reg_gpio_enb = 0x0000;
//	reg_gpio_data = 0x0001;
//
//    for (i = 1; i < 5; i++) {
//        for (j = 0; j < 34000; j++); // 2 sec
//	    reg_gpio_data = (0x0001 << i);
//    }
//
//    reg_gpio_data = 0x000f;

	// This should appear on the LCD display 4x20 characters.
//    print("Starting...\n");
//
//    print("Press ENTER to continue..\n");
//    while (getchar() != '\r') {}

    gpio_write(0x000a);
//    cmd_echo();
    gpio_write(0x0000);

//    print("\n\n");

    while (1) {
        gpio_write(0x0085);
        print("A");
        for (j = 0; j < 34000; j++) {} // 2 sec
        gpio_write(0x008a);
//        print("b");
        for (j = 0; j < 34000; j++) {} // 2 sec
    }

}

