#include "clk_ctrl_regs.h"

unsigned int volatile * const CLKCTRL_PLLCR = (unsigned int *) (CLK_CTRL_BASE_ADDR_0 + CLKCTRL_PLLCR_REG);
unsigned int volatile * const CLKCTRL_PLLTR = (unsigned int *) (CLK_CTRL_BASE_ADDR_0 + CLKCTRL_PLLTR_REG);
unsigned int volatile * const CLKCTRL_CLKCR = (unsigned int *) (CLK_CTRL_BASE_ADDR_0 + CLKCTRL_CLKCR_REG);

void set_clock(bool hse, bool pll, int div) {

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
	if (div)
	    PLL_DIV(div);

    // configure the clock muxes
    //    *CLKCTRL_CLKCR |= 0x5;
    //    *CLKCTRL_CLKCR |= 0x6;
    //    *CLKCTRL_CLKCR = 0x1e;

}