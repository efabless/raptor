#include "../raptor.h"
#include "../raptor_io.h"

void main()
{
//	uint32_t i, j;
	int i, j;
	int x, v;
    unsigned char data[2];

//    set_clock(true, true, 0);

    // Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);

    for (j = 0; j < 70000; j++);

//    print("Starting...");
    spi_configure(0,0,20);

//    while (1) {
//        i2c_send(0xa2, 0x02);
//        gpio_write(0x000a);
//        if (i2c_read(0xa2, 0x02, &data, 3)){
    data[0] = i2c_read_byte(0xa2, 0x02);
    print_hex(data[0], 2); print(":");
    gpio_write(data[0] >> 4);
//        print_hex(data[1], 2); print(":");
//        print_hex(data[2], 2);
//        } else {
//            gpio_write(0x09);
//        }
//        for (j = 0; j < 34000; j++) {} // 2 sec
//        gpio_write(0x0005);
    for (j = 0; j < 34000; j++) {} // 2 sec
//    }

}

