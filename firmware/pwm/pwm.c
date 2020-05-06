#include "../raptor.h"
#include "../raptor_io.h"


void main()
{
//	uint32_t i, j;
	int i, j;
	int x, v;

//    set_clock(true, true, 0);

    // Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);

    for (j = 0; j < 70000; j++);

    pwm_disable();

    // PWM period = (CMP1 + 1)/timer_clk = (CMP1 + 1)*(PRE + 1)/clk
    // PWM off cyle % = (CMP1 + 1)/(CMP2 + 1)
    pwm_init(199, 99, 9);   //  period = (199+1)/(clk/(9+1)) = 2000/clk,
                          //  OFF % = 50/200 * 100 = 25%

    pwm_enable();

    gpio_write(0x0005);
//    for (j = 0; j < 34000; j++) {} // 2 sec

    while (1);
}

