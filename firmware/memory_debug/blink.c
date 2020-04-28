//#include "../raptor.h"
#include "../sw/gpio_drv.h"
//#include "../sw/clkctrl_regs.h"

//#define   HSE_ON      *CLKCTRL_CLKCR |= 0x10
//#define   PLL_ON      *CLKCTRL_PLLCR |= 0x1
//#define   PLL_DIV(d)  *CLKCTRL_PLLCR &= 0x3; *CLKCTRL_PLLCR |= (d<<2); *CLKCTRL_CLKCR |= 2

extern unsigned long _sidata;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;


//#define     GPIO_DATA_REG           0x00000000
//#define     GPIO_DIR_REG            0x00000004
//#define     GPIO_BASE_ADDR          0x80000000
//
//unsigned int volatile * const GPIO_DATA =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DATA_REG);
//
//unsigned int volatile * const GPIO_DIR =
//    (unsigned int *) (GPIO_BASE_ADDR + GPIO_DIR_REG);


//void led() {
void led(int x) {
//int j,x;
int j;
////    gpio_write(x);
//    reg_gpio_data = x;
////    *GPIO_DATA = x;
    reg_gpio_data = 0x0a;
    for (int j = 0; j < 70000; j++);
    reg_gpio_data = 0x01;
    for (int j = 0; j < 70000; j++);
    __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1;  for (j = 0; j < 70000; j++);
    __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x >> 4; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
    __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x >> 8; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
    __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x >> 12; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
    #define m2 ((volatile uint32_t*) (0x20000fe0))
    reg_gpio_data = *m2;for (j = 0; j < 70000; j++); reg_gpio_data = 0x2;  for (j = 0; j < 70000; j++);
    reg_gpio_data = *m2 >> 4;for (j = 0; j < 70000; j++); reg_gpio_data = 0x2;  for (j = 0; j < 70000; j++);
    reg_gpio_data = *m2 >> 8;for (j = 0; j < 70000; j++); reg_gpio_data = 0x2;  for (j = 0; j < 70000; j++);

}

//int A[] = {5,7,2,3,1};

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
    reg_gpio_data = 0x000f;

    for (j = 0; j < 70000; j++);

//	HSE_ON;
//    for (int j = 0; j < 70000; j++);
//    // configure the clock muxes
//    *CLKCTRL_CLKCR |= 0x5;

	// Enable GPIO (all output, ena = 0)
//	gpio_set_dir(0x0000);

//	reg_gpio_data = 0x0004;
//    *GPIO_DIR = 0;
//    for (int j = 0; j < 70000; j++);
    #define m1 ((volatile uint32_t*) (0x20003ff0))
//    #define m1 ((volatile unsigned char*) (0x20000000))
//    #define m1 (*(volatile uint32_t*) (0x20000000))
//    unsigned char volatile * const m1 = (unsigned char *) 0x20000000;
//    int x;
//    *m1 = 0x0008;
//    x = *m1;
//    reg_gpio_data = x;

//    for (i = 0; i<100; i++) {
////        reg_gpio_data = A[i];
//        *(m1) = 0x0b;

//        __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1;  for (j = 0; j < 70000; j++);
//        __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x >> 4; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
//        __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x >> 8; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
//        __asm("mov %[result],lr":[result] "=r" (x)); reg_gpio_data = x >> 12; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
//        __asm("mov %[result],sp":[result] "=r" (x)); reg_gpio_data = x >> 16; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);
//        __asm("mov %[result],sp":[result] "=r" (x)); reg_gpio_data = x >> 28; for (j = 0; j < 70000; j++); reg_gpio_data = 0x1; for (j = 0; j < 70000; j++);

////        reg_gpio_data = i % 16;
////        reg_gpio_data = 0x0001;
////        for (j = 0; j < 70000; j++);
////        reg_gpio_data = 0x0003;
//        for (j = 0; j < 70000; j++);
//    }

//    reg_gpio_data = 0x000e;


//    for (j = 0; j < 70000; j++);

    led(0);

    reg_gpio_data = 0x0006;

    while (1) {
//        led(0x0000);
//        led(0x0001);
//        led(0x0002);
//        led(0x0004);
//        led(0x0008);
//        led(0x0004);
//        led(0x0002);
//        led(0x0001);
    }

}

