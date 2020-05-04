#ifndef I2C_DRV_H
#define I2C_DRV_H

#include "base_addr.h"

void i2c_init(unsigned int);//unsigned int sysCLK, unsigned int i2cCLK);
int i2c_send_byte(unsigned char saddr, unsigned char sdata);
int i2c_read_bytes(unsigned char saddr, unsigned char waddr, unsigned char *data);
//int i2c_read_bytes(unsigned char saddr, unsigned char waddr, unsigned char *data, int len);
unsigned char i2c_read_byte(unsigned char saddr, unsigned char waddr);


#endif