#include "../raptor.h"
#include "../raptor_io.h"

#define BCD_DIGIT0(x) (x & (uint32_t)0x000F)
#define BCD_DIGIT1(x) ((x >> 4) & (uint32_t)0x000F)

void main()
{
//	uint32_t i, j;
	int i, j;
	int x, v;
    unsigned char data[2];

//    set_clock(true, true, 16);

    // Enable GPIO (all output, ena = 0)
	gpio_set_dir(0x0000);
    gpio_write(0x000f);

    for (j = 0; j < 70000; j++);

//    print("Starting...");
    i2c_init(40);

    while (1) {
//        i2c_send_byte(0xa2, 0x02);
//        gpio_write(0x000a);
//        if (i2c_read_bytes(0xa2, 0x02, data, 3)){
//            i2c_read_bytes(0xa2, 0x02, data, 3);
//            i2c_read_bytes(0xa2, 0x02, data);
//        if (data[0] = i2c_read_byte(0xa2, 0x02)){
        data[0] = i2c_read_byte(0xa2, 0x02);
//            print_hex(data[0], 2);
//            data[0] &= (unsigned char) 0x007F;
//            data[1] &= (unsigned char) 0x007F;
//            data[2] &= (unsigned char) 0x003F;
//            print_digit(BCD_DIGIT1(data[0]));
//            print_digit(BCD_DIGIT0(data[0]));
//            print(":");
//            gpio_write(data[0]);

//        print_hex(data[1], 2); print(":");
//        print_hex(data[2], 2);
//        } else {
//            gpio_write(0x09);
//        }
        gpio_write(0x0a);
        for (j = 0; j < 70000; j++) {
            gpio_write(0x0b);
        } // 2 sec
//        gpio_write(0x05);
//        for (j = 0; j < 70000; j++) {} // 2 sec
    }

}

