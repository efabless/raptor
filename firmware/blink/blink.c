//#include "../raptor.h"
#include "../sw/gpio_drv.h"
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

//#define   HSE_ON      *CLKCTRL_CLKCR |= 0x10
//#define   PLL_ON      *CLKCTRL_PLLCR |= 0x1
//#define   PLL_DIV(d)  *CLKCTRL_PLLCR &= 0x3; *CLKCTRL_PLLCR |= (d<<2); *CLKCTRL_CLKCR |= 2

extern unsigned long _sidata;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;

void led(int x) {
int j;
////    gpio_write(x);
    reg_gpio_data = x;
////    *GPIO_DATA = x;
    for (int j = 0; j < 70000; j++);
//    delay_us(100000000);

}

void main()
{
    unsigned long *src , *dst, *dstend;
    int x;

    // Copy data initializers
    src = &_sidata;
    dst = &_sdata;
    dstend = &_edata;
    while (dst < dstend)
        *(dst ++) = *(src ++);

    // Zero bss
    dst = &_sbss;
    while (dst < &_ebss)
        *(dst ++) = 0;

    int i,j;
    reg_gpio_dir = 0x0000;
//	gpio_set_dir(0x0000);
    reg_gpio_data = 0x000f;

    for (j = 0; j < 70000; j++);

//	HSE_ON;
//    for (int j = 0; j < 70000; j++);
//    // configure the clock muxes
//    *CLKCTRL_CLKCR |= 0x5;

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

