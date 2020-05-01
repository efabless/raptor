#ifndef I2C_DRV_H
#define I2C_DRV_H

void i2c_init(unsigned int);//unsigned int sysCLK, unsigned int i2cCLK);
int i2c_send(unsigned char saddr, unsigned char sdata);
int i2c_read(unsigned char saddr, unsigned char waddr, unsigned char *data, int len);


#endif