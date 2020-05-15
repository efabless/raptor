#include <stdint.h>

#define     I2C_BASE_ADDR_0             0x40100000
#define     UART_BASE_ADDR_0            0x40200000
#define     UART_BASE_ADDR_1            0x40300000
#define     AHB_GPIO_BASE_ADDR_0        0x80000000

#define     GPIO_DATA_REG               0x00000000
#define     GPIO_DIR_REG                0x00000004
#define     GPIO_BASE_ADDR              0x80000000

#define reg_gpio_data (*(volatile uint32_t*) (GPIO_BASE_ADDR + GPIO_DATA_REG))
#define reg_gpio_dir (*(volatile uint32_t*) (GPIO_BASE_ADDR + GPIO_DIR_REG))


#define     I2C_PRE_LO_REG      0x0
#define     I2C_PRE_HI_REG      0x4
#define     I2C_CTRL_REG        0x8
#define     I2C_TX_REG          0xC
#define     I2C_RX_REG          0x10
#define     I2C_CMD_REG         0x14
#define     I2C_STAT_REG        0x18

#define     I2C_CMD_STA         0x80
#define     I2C_CMD_STO         0x40
#define     I2C_CMD_RD          0x20
#define     I2C_CMD_WR          0x10
#define     I2C_CMD_NACK        0x08
#define     I2C_CMD_IACK        0x01

#define     I2C_CTRL_EN         0x80
#define     I2C_CTRL_IEN        0x40

#define     I2C_STAT_RXACK      0x80
#define     I2C_STAT_BUSY       0x40
#define     I2C_STAT_AL         0x20
#define     I2C_STAT_TIP        0x02
#define     I2C_STAT_IF         0x01

unsigned char volatile * const I2C_PRE_LO = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_PRE_LO_REG);
unsigned char volatile * const I2C_PRE_HI = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_PRE_HI_REG);
unsigned char volatile * const I2C_CTRL = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_CTRL_REG);
unsigned char volatile * const I2C_TX = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_TX_REG);
unsigned char volatile * const I2C_RX = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_RX_REG);
unsigned char volatile * const I2C_CMD = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_CMD_REG);
unsigned char volatile * const I2C_STAT = (unsigned char *) (I2C_BASE_ADDR_0 + I2C_STAT_REG);

int _data;

void i2c_init(unsigned int pre){
    //unsigned int sysCLK, unsigned int i2cCLK)
    //unsigned int pre = sysCLK/i2cCLK/5;
    *(I2C_PRE_LO) = pre & 0xff;
    *(I2C_PRE_HI) = pre & 0xff00;
//    *(I2C_CTRL) = I2C_CTRL_EN | I2C_CTRL_IEN;
    *(I2C_CTRL) = I2C_CTRL_EN;
}

unsigned char i2c_read_byte(unsigned char saddr, unsigned char waddr) {
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

//int i2c_read_bytes(unsigned char saddr, unsigned char waddr, unsigned char *data, int len) {
//inline int i2c_read_bytes(unsigned char saddr, unsigned char waddr, unsigned char *data) {
inline unsigned char i2c_read_bytes(unsigned char saddr, unsigned char waddr) {
    int volatile y;

    // debug code
    int len = 1;
    y = 1;

    // write slave address
    *(I2C_TX) = saddr;
    *(I2C_CMD) = I2C_CMD_STA | I2C_CMD_WR;
    while( ((*I2C_STAT) & I2C_STAT_TIP) != 0 ) {
//    while( y < 100 ) {
//        y = 1;
        y = y + 1;
//        reg_gpio_data = 0x01;
        _data = 0x01;
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
//    reg_gpio_data = 0x04;
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
//    reg_gpio_data = 0x06;
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

        reg_gpio_data = 0x0e;

        if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1){
            *(I2C_CMD) = I2C_CMD_STO;
            return 0;
        }

//        data[i] = *(I2C_RX);
//        data = *(I2C_RX);
//    reg_gpio_data = 0x0e;

    }
    reg_gpio_data = 0x0e;

    // this functions stops here

    return *(I2C_RX);

}

int dummy2() {
    reg_gpio_data = 0x7;
    while (1);
    return 0;
}

int dummy(unsigned char saddr, unsigned char waddr, unsigned char data[4]) {
    int y;

    unsigned char d0, d1, d2;

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
    *(I2C_CMD) = I2C_CMD_RD;

    while( (*I2C_STAT) & I2C_STAT_TIP );

    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
        return 0;
    else
        data[0] =  *(I2C_RX);

    *(I2C_CMD) = I2C_CMD_RD;

    while( (*I2C_STAT) & I2C_STAT_TIP );

    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
        return 0;
    else
        data[1] =  *(I2C_RX);

    *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_STO;

    while( (*I2C_STAT) & I2C_STAT_TIP );

    if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
        return 0;
    else
        data[2] =  *(I2C_RX);

//    reg_gpio_data = 0x01;

//    y = d0 + d1*256 + ((int) d2<<16);

    return 1;

}

//unsigned char data[4];


void main()
{
	int i, j;
	int x, v, y;
    unsigned char data;

	reg_gpio_dir = 0x0000;
    reg_gpio_data = 0x000f;

    for (j = 0; j < 1000; j++);

    i2c_init(19);
    y = 0;

    while (1) {
        data = i2c_read_bytes(0xa2, 0x02);  // this function fails
//        data = i2c_read_byte(0xa2, 0x02);  // this function works

        reg_gpio_data = 0x0a;
//        for (j = 0; j < 700000; j++) {} // 2 sec
    }

}

