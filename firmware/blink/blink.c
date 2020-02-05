#include "../raptor.h"
#include "../sw/gpio_regs.h"

// --------------------------------------------------------
// Firmware routines
// --------------------------------------------------------

// Copy the flash worker function to SRAM so that the SPI can be
// managed without having to read program instructions from it.

//void flashio(uint32_t *data, int len, uint8_t wrencmd)
//{
//	uint32_t func[&flashio_worker_end - &flashio_worker_begin];
//
//	uint32_t *src_ptr = &flashio_worker_begin;
//	uint32_t *dst_ptr = func;
//
//	while (src_ptr != &flashio_worker_end)
//		*(dst_ptr++) = *(src_ptr++);
//
//	((void(*)(uint32_t*, uint32_t, uint32_t))func)(data, len, wrencmd);
//}

//--------------------------------------------------------------
// NOTE: Volatile write *only* works with command 01, making the
// above routing non-functional.  Must write all four registers
// status, config1, config2, and config3 at once.
//--------------------------------------------------------------
// (NOTE: Forces quad/ddr modes off, since function runs in single data pin mode)
// (NOTE: Also sets quad mode flag, so run this before entering quad mode)
//--------------------------------------------------------------

//void set_flash_latency(uint8_t value)
//{
//	reg_spictrl = (reg_spictrl & ~0x007f0000) | ((value & 15) << 16);
//
//	uint32_t buffer_wr[2] = {0x01000260, ((0x70 | value) << 24)};
//	flashio(buffer_wr, 5, 0x50);
//}

//--------------------------------------------------------------

void main()
{
//	CLKCTRL_CLKCR_REG =
//	CLKCTRL_PLLCR_REG =
//	CLKCTRL_PLLTR_REG =

GPIO_DIR_REG = 0x0000
GPIO_DATA_REG = 0x000f

	uint32_t i, j, m, r, mode;

	// Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);

    for (j = 0; j < 170000; j++);

	while (1) {
        gpio_write(0x0000);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0001);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0002);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0004);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0008);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0004);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0002);
        for (j = 0; j < 70000; j++);
        gpio_write(0x0001);
        for (j = 0; j < 70000; j++);
	}

}

