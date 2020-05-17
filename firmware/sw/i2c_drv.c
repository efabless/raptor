#include "base_addr.h"
#include "i2c_drv.h"
#include "i2c_regs.h"


// added for debug
#define     GPIO_DATA_REG           0x00000000
#define     GPIO_DIR_REG            0x00000004
#define     GPIO_BASE_ADDR          AHB_GPIO_BASE_ADDR_0
#define reg_gpio_data (*(volatile unsigned int*) (GPIO_BASE_ADDR + GPIO_DATA_REG))

void i2c_init(unsigned int pre){
    //unsigned int sysCLK, unsigned int i2cCLK)
    //unsigned int pre = sysCLK/i2cCLK/5;
    *(I2C_PRE_LO) = pre & 0xff;
    *(I2C_PRE_HI) = pre & 0xff00;
//    *(I2C_CTRL) = I2C_CTRL_EN | I2C_CTRL_IEN;
    *(I2C_CTRL) = I2C_CTRL_EN;
}

int i2c_send_byte(unsigned char saddr, unsigned char sdata){
    int volatile y;
    *(I2C_TX) = saddr;
    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 );
    //(*I2C_STAT) & I2C_STAT_TIP ;

    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }
    *(I2C_TX) = sdata;
    *(I2C_CMD) = I2C_CMD_WR;
    while( (*I2C_STAT) & I2C_STAT_TIP );
    *(I2C_CMD) = I2C_CMD_STO;
    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
        return 0;
    else
        return 1;
}

inline int i2c_read_bytes(unsigned char saddr, unsigned char waddr, unsigned char *data, int len) {
//inline int i2c_read_bytes(unsigned char saddr, unsigned char waddr, unsigned char *data) {
//inline unsigned char i2c_read_bytes(unsigned char saddr, unsigned char waddr) {
    int volatile y;

    // debug code
//    int len = 1;

    // write slave address
    *(I2C_TX) = saddr;
    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 ) {
        reg_gpio_data = 0x01;
//        reg_gpio_data = (*I2C_STAT) >> 4;
    };
//    reg_gpio_data = 0x02;
    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }

    // write word / memory address
    *(I2C_TX) = waddr;
    *(I2C_CMD) = I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 ) {
//        reg_gpio_data = 0x03;
    };
    reg_gpio_data = 0x04;
    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }

    // restart and send slave address _ read bit
    *(I2C_TX) = saddr | 0x0001;
    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 ) {
//        reg_gpio_data = 0x05;
    };
    reg_gpio_data = 0x06;
    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }

    // read data
    for (int i = 0; i < len; i++) {
//        if (i == len-1)
//            *(I2C_CMD) = I2C_CMD_RD;
//        else
//            *(I2C_CMD) = I2C_CMD_RD|I2C_CMD_ACK;

        if (i < len-1) {
            *(I2C_CMD) = I2C_CMD_RD;
        } else {
            *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_STO;
//            *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_NACK | I2C_CMD_STO;
//            *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_NACK;
//            *(I2C_CMD) = I2C_CMD_RD;
        }

        while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 ) {
//            reg_gpio_data = 0x08 | i;
//            reg_gpio_data = 0x08;
    //        reg_gpio_data = (*I2C_STAT) >> 4;
//            reg_gpio_data = (*I2C_STAT);
        };

//        reg_gpio_data = 0x0e;

        if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1){
            *(I2C_CMD) = I2C_CMD_STO;
            return 0;
        }

        data[i] = *(I2C_RX);
//        data = *(I2C_RX);

    }
    reg_gpio_data = 0x0e;

//    return *(I2C_RX);
    return 1;
}

inline unsigned char i2c_read_byte(unsigned char saddr, unsigned char waddr) {
    int volatile y;

    // write slave address
    *(I2C_TX) = saddr;
    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 );
    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }

    // write word / memory address
    *(I2C_TX) = waddr;
    *(I2C_CMD) = I2C_CMD_WR;
    while( (*I2C_STAT) & I2C_STAT_TIP );
    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }

    // restart and send slave address _ read bit
    *(I2C_TX) = saddr | 0x0001;
    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 );
    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
        *(I2C_CMD) = I2C_CMD_STO;
        return 0;
    }

    // read data
//    *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_NACK | I2C_CMD_STO;
    *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_STO;

    while( (*I2C_STAT) & I2C_STAT_TIP );

    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
        return 0;
    else
        return *(I2C_RX);
}

//int i2c_read_byte_1(unsigned char saddr, unsigned char waddr, unsigned char data[4]) {
//    int y;
//
//    unsigned char d0, d1, d2;
//
//    // write slave address
//    *(I2C_TX) = saddr;
//    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
//    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 );
//    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
//        *(I2C_CMD) = I2C_CMD_STO;
//        return 0;
//    }
//
//    // write word / memory address
//    *(I2C_TX) = waddr;
//    *(I2C_CMD) = I2C_CMD_WR;
//    while( (*I2C_STAT) & I2C_STAT_TIP );
//    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
//        *(I2C_CMD) = I2C_CMD_STO;
//        return 0;
//    }
//
//    // restart and send slave address _ read bit
//    *(I2C_TX) = saddr | 0x0001;
//    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
//    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 );
//    if( ((*I2C_STAT) & I2C_STAT_RXACK)  == 1) {
//        *(I2C_CMD) = I2C_CMD_STO;
//        return 0;
//    }
//
//    // read data
////    *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_NACK | I2C_CMD_STO;
//    *(I2C_CMD) = I2C_CMD_RD;
//
//    while( (*I2C_STAT) & I2C_STAT_TIP );
//
//    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
//        return 0;
//    else
//        data[0] =  *(I2C_RX);
//
//    *(I2C_CMD) = I2C_CMD_RD;
//
//    while( (*I2C_STAT) & I2C_STAT_TIP );
//
//    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
//        return 0;
//    else
//        data[1] =  *(I2C_RX);
//
//    *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_STO;
//
//    while( (*I2C_STAT) & I2C_STAT_TIP );
//
//    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
//        return 0;
//    else
//        data[2] =  *(I2C_RX);
//
//    reg_gpio_data = 0x01;
//
////    y = d0 + d1*256 + ((int) d2<<16);
//
//    return 1;
//
//}