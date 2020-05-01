#include "i2c_regs.h"

void i2c_init(unsigned int pre){
    //unsigned int sysCLK, unsigned int i2cCLK)
    //unsigned int pre = sysCLK/i2cCLK/5;
    *(I2C_PRE_LO) = pre & 0xff;
    *(I2C_PRE_HI) = pre & 0xff00;
//    *(I2C_CTRL) = I2C_CTRL_EN | I2C_CTRL_IEN;
    *(I2C_CTRL) = I2C_CTRL_EN;
}

int i2c_send(unsigned char saddr, unsigned char sdata){
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

int i2c_read(unsigned char saddr, unsigned char waddr, unsigned char *data, int len){
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
    for (int i = 0; i < len-1; i++) {
//        if (i == len-1)
//            *(I2C_CMD) = I2C_CMD_RD;
//        else
//            *(I2C_CMD) = I2C_CMD_RD|I2C_CMD_ACK;

        if (i < len-1)
            *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_ACK;
        else {
            *(I2C_CMD) &= ~(I2C_CMD_ACK);
            *(I2C_CMD) = I2C_CMD_RD | I2C_CMD_STO;
        }

        while( (*I2C_STAT) & I2C_STAT_TIP );
        data[i] = *(I2C_RX) & 0xff;

//        if( ((*I2C_STAT) & I2C_STAT_RXACK ) == 1)
//            return 0;
//        else
//            return 1;

        return 0;
    }
}