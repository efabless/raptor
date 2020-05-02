#ifndef I2C_REGS_H
#define I2C_REGS_H

#include "base_addr.h"

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
#define     I2C_CMD_ACK         0x08
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

#endif