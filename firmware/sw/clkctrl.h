#ifndef _CLKCTRL_REGS_H_
#define _CLKCTRL_REGS_H_

#include "base_addr.h"
#include "macros.h"

#define     CLKCTRL_PLLCR_REG       0x50000000
#define     CLKCTRL_PLLTR_REG       0x50000004
#define     CLKCTRL_CLKCR_REG       0x50000008

unsigned int volatile * const CLKCTRL_PLLCR;
unsigned int volatile * const CLKCTRL_PLLTR;
unsigned int volatile * const CLKCTRL_CLKCR;

void set_clock(bool hse, bool pll, int div);

#endif