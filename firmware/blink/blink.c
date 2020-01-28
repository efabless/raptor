#include "../raptor.h"

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
	uint32_t i, j, m, r, mode;

    //	set_flash_latency(8)

	// Start in standard (1x speed) mode

	// Set m for speed multiplier:
	// 1 standard (1x), 2 for DSPI (2x)
	mode = 1;
	m = 1;

	// Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);

	gpio_write(0xFFFF);

//    while (1) {
//    	gpio_write(0x1);
//        for (j = 0; j < 350000 * m; j++);
//        gpio_write(0x2);
//        for (j = 0; j < 50000 * m; j++);
//        gpio_write(0x4);
//        for (j = 0; j < 50000 * m; j++);
//        gpio_write(0x8);
//        for (j = 0; j < 50000 * m; j++);
//    }
}

