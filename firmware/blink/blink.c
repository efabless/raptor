#include "../raptor.h"
//#include "../sw/gpio_drv.h"
//#include "../sw/clkctrl_regs.h"

//void delay_us(int cycles) {
//    // cycles = delay in usec * 100
//    unsigned int cyc_start, cyc, cyc_diff;
//    __asm__ volatile ("rdcycle %0" : "=r"(cyc_start));
//    do {
//        __asm__ volatile ("rdcycle %0" : "=r"(cyc));
//        cyc_diff = cyc - cyc_start;
//    } while(cyc_diff<cycles);
//}
void set_clock(bool hse, bool pll, int pll_div) {

#define   HSE_ON      *CLKCTRL_CLKCR |= 0x10
#define   PLL_ON      *CLKCTRL_PLLCR |= 0x1
#define   PLL_DIV(d)  *CLKCTRL_PLLCR &= 0x3; *CLKCTRL_PLLCR |= (d<<2); *CLKCTRL_CLKCR |= 2

	if (hse){
	    HSE_ON;
        for (int j = 0; j < 70000; j++);
	}
	if (pll) {
	    PLL_ON;
        for (int j = 0; j < 70000; j++);
	}
	if (pll_div)
	    PLL_DIV(pll_div);

    // configure the clock muxes
    //    *CLKCTRL_CLKCR |= 0x5;
    //    *CLKCTRL_CLKCR |= 0x6;
    //    *CLKCTRL_CLKCR = 0x1e;

}


void led(int x) {
int j;
    gpio_write(x);
//    reg_gpio_data = x;
////    *GPIO_DATA = x;
    for (int j = 0; j < 70000; j++);
//    delay_us(100000000);

}

void main()
{
    int i,j;

//    set_clock(true, true, 0);

    reg_gpio_dir = 0x0000;
//	gpio_set_dir(0x0000);
    reg_gpio_data = 0x000f;

    for (j = 0; j < 70000; j++);

    led(0);

    while (1) {
        led(0x0000);
        led(0x0001);
        led(0x0002);
        led(0x0004);
        led(0x0008);
        led(0x0004);
        led(0x0002);
        led(0x0001);
    }

}

