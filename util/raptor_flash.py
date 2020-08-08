from pyftdi.ftdi import Ftdi
import time
import sys, os
from pyftdi.spi import SpiController
from array import array as Array
import binascii


SR_WIP = 0b00000001  # Busy/Work-in-progress bit
SR_WEL = 0b00000010  # Write enable bit
SR_BP0 = 0b00000100  # bit protect #0
SR_BP1 = 0b00001000  # bit protect #1
SR_BP2 = 0b00010000  # bit protect #2
SR_BP3 = 0b00100000  # bit protect #3
SR_TBP = SR_BP3      # top-bottom protect bit
SR_SP = 0b01000000
SR_BPL = 0b10000000
SR_PROTECT_NONE = 0  # BP[0..2] = 0
SR_PROTECT_ALL = 0b00011100  # BP[0..2] = 1
SR_LOCK_PROTECT = SR_BPL
SR_UNLOCK_PROTECT = 0
SR_BPL_SHIFT = 2

CMD_READ_STATUS = 0x05  # Read status register
CMD_WRITE_ENABLE = 0x06  # Write enable
CMD_WRITE_DISABLE = 0x04  # Write disable
CMD_PROGRAM_PAGE = 0x02  # Write page
CMD_EWSR = 0x50  # Enable write status register
CMD_WRSR = 0x01  # Write status register
CMD_ERASE_SUBSECTOR = 0x20
CMD_ERASE_HSECTOR = 0x52
CMD_ERASE_SECTOR = 0xD8
# CMD_ERASE_CHIP = 0xC7
CMD_ERASE_CHIP = 0x60
CMD_RESET_CHIP = 0x99
CMD_JEDEC_DATA = 0x9f

CMD_READ_LO_SPEED = 0x03  # Read @ low speed
CMD_READ_HI_SPEED = 0x0B  # Read @ high speed
ADDRESS_WIDTH = 3

JEDEC_ID = 0xEF
DEVICES = {0x30: 'W25X', 0x40: 'W25Q'}
SIZES = {0x11: 1 << 17, 0x12: 1 << 18, 0x13: 1 << 19, 0x14: 1 << 20,
         0x15: 2 << 20, 0x16: 4 << 20, 0x17: 8 << 20, 0x18: 16 << 20}
SPI_FREQ_MAX = 104  # MHz
CMD_READ_UID = 0x4B
UID_LEN = 0x8  # 64 bits
READ_UID_WIDTH = 4  # 4 dummy bytes
TIMINGS = {'page': (0.0015, 0.003),  # 1.5/3 ms
           'subsector': (0.200, 0.200),  # 200/200 ms
           'sector': (1.0, 1.0),  # 1/1 s
           'bulk': (32, 64),  # seconds
           'lock': (0.05, 0.1),  # 50/100 ms
           'chip': (4, 11)}
# FEATURES = (SerialFlash.FEAT_SECTERASE |
#             SerialFlash.FEAT_SUBSECTERASE |
#             SerialFlash.FEAT_CHIPERASE)


def get_status(device):
    return int.from_bytes(device.exchange([CMD_READ_STATUS],1), byteorder='big')


def report_status(jedec):
    if jedec[0] == int('bf', 16):
        print("changing cmd values...")
        print("status reg_1 = {}".format(hex(get_status(slave))))
    else:
        print("status reg_1 = {}".format(hex(get_status(slave))))
        status = slave.exchange([0x35], 1)
        print("status reg_2 = {}".format(hex(int.from_bytes(status, byteorder='big'))))
        # print("status = {}".format(hex(from_bytes(slave.exchange([CMD_READ_STATUS], 2)[1], byteorder='big'))))


def is_busy(device):
    return get_status(device) & SR_WIP


class Led:
    def __init__(self, gpio):
        self.gpio = gpio
        self.led = 1

    def toggle(self):
        self.led = (self.led+1) & 0x1
        output = 0b000100000000 | self.led << 11
        self.gpio.write(output)


if len(sys.argv) < 2:
    print("Usage: raptor_flash.py <file>")
    sys.exit()

file_path = sys.argv[1]

if not os.path.isfile(file_path):
    print("File not found.")
    sys.exit()

spi = SpiController(cs_count=1, turbo=True)
# spi.configure(vendor=0x0403, product=0x6014, interface=1)
spi.configure('ftdi://ftdi:232h:0/1')
slave = spi.get_port(cs=0, freq=12E6, mode=0)  # Chip select is 0 -- corresponds to D3

gpio = spi.get_gpio()
# gpio.set_direction(0x0100, 0x0100)  # (mask, dir)
gpio.set_direction(0b110100000000, 0b110100000000)  # (mask, dir)
gpio.write(0b000100000000)
led = Led(gpio)

time.sleep(1.0)

led.toggle()
# slave.write([CMD_RESET_CHIP])
# while (is_busy(slave)):
#     time.sleep(0.5)
#     led.toggle()
# led.toggle()

jedec = slave.exchange([CMD_JEDEC_DATA], 3)
print("JEDEC = {}".format(binascii.hexlify(jedec)))

if jedec[0] != int('ef', 16) and jedec[0] != int('01', 16) and jedec[0] != int('bf', 16):
    print("Winbond, Microchip or Cypress SRAM not found")
    sys.exit()

if jedec[0] == int('bf', 16):
    SR_WIP = 0b10000000
    CMD_ERASE_CHIP = 0xC7

report_status(jedec)

print("Erasing chip...")
led.toggle()
slave.write([CMD_WRITE_ENABLE])
slave.write([CMD_ERASE_CHIP])
led.toggle()

while (is_busy(slave)):
    time.sleep(0.5)
    led.toggle()

led.toggle()
print("done")
print("status = {}".format(hex(get_status(slave))))

buf = bytearray()
addr = 0
nbytes = 0
total_bytes = 0

with open(file_path, mode='r') as f:
    x = f.readline()
    while x != '':
        if x[0] == '@':
            addr = int(x[1:], 16)
            print('setting address to {}'.format(hex(addr)))
        else:
            # print(x)
            values = bytearray.fromhex(x[0:len(x)-1])
            buf[nbytes:nbytes] = values
            nbytes += len(values)
            # print(binascii.hexlify(values))

        x = f.readline()

        if nbytes >= 256:
            total_bytes += nbytes
            # print('\n----------------------\n')
            # print(binascii.hexlify(buf))
            # print("\ntotal_bytes = {}".format(total_bytes))

            slave.write([CMD_WRITE_ENABLE])
            wcmd = bytearray((CMD_PROGRAM_PAGE,(addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff))
            # print(binascii.hexlify(wcmd))
            # wcmd.extend(buf[0:255])
            wcmd.extend(buf)
            slave.exchange(wcmd)
            led.toggle()
            while (is_busy(slave)):
                time.sleep(0.1)
                led.toggle()

            led.toggle()
            print("addr {}: flash page write successful".format(hex(addr)))

            if nbytes > 256:
                buf = buf[255:]
                addr += 256
                nbytes -= 256
                print("*** over 256 hit")
            else:
                buf = bytearray()
                addr += 256
                nbytes =0

    if nbytes > 0:
        total_bytes += nbytes
        # print('\n----------------------\n')
        # print(binascii.hexlify(buf))
        # print("\nnbytes = {}".format(nbytes))

        slave.write([CMD_WRITE_ENABLE])
        wcmd = bytearray((CMD_PROGRAM_PAGE, (addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff))
        wcmd.extend(buf)
        slave.exchange(wcmd)
        led.toggle()
        while (is_busy(slave)):
            time.sleep(0.1)
            led.toggle()

        led.toggle()
        print("addr {}: flash page write successful".format(hex(addr)))

print("\ntotal_bytes = {}".format(total_bytes))

if jedec[0] != int('bf', 16):
    led.toggle()
    print("locking registers...")
    slave.write([0xaa])
    slave.write([0x55])
    slave.write([0x06])
    slave.write([0x31, 0x01])
    led.toggle()

report_status(jedec)

print("************************************")
print("verifying...")
print("************************************")

buf = bytearray()
addr = 0
nbytes = 0
total_bytes = 0

while (is_busy(slave)):
    time.sleep(0.5)
    led.toggle()

report_status(jedec)

with open(file_path, mode='r') as f:
    x = f.readline()
    while x != '':
        if x[0] == '@':
            addr = int(x[1:],16)
            print('setting address to {}'.format(hex(addr)))
        else:
            # print(x)
            values = bytearray.fromhex(x[0:len(x)-1])
            buf[nbytes:nbytes] = values
            nbytes += len(values)
            # print(binascii.hexlify(values))

        x = f.readline()

        if nbytes >= 256:
            total_bytes += nbytes
            # print('\n----------------------\n')
            # print(binascii.hexlify(buf))
            # print("\ntotal_bytes = {}".format(total_bytes))

            read_cmd = bytearray((CMD_READ_LO_SPEED,(addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff))
            # print(binascii.hexlify(read_cmd))
            buf2 = slave.exchange(read_cmd, nbytes)
            led.toggle()
            if buf == buf2:
                print("addr {}: read compare successful".format(hex(addr)))
            else:
                print("addr {}: *** read compare FAILED ***".format(hex(addr)))
                print(binascii.hexlify(buf))
                print("<----->")
                print(binascii.hexlify(buf2))

            if nbytes > 256:
                buf = buf[255:]
                addr += 256
                nbytes -= 256
                print("*** over 256 hit")
            else:
                buf = bytearray()
                addr += 256
                nbytes =0

    if nbytes > 0:
        total_bytes += nbytes
        # print('\n----------------------\n')
        # print(binascii.hexlify(buf))
        # print("\nnbytes = {}".format(nbytes))

        read_cmd = bytearray((CMD_READ_LO_SPEED, (addr >> 16) & 0xff, (addr >> 8) & 0xff, addr & 0xff))
        # print(binascii.hexlify(read_cmd))
        buf2 = slave.exchange(read_cmd, nbytes)
        led.toggle()
        if buf == buf2:
            print("addr {}: read compare successful".format(hex(addr)))
        else:
            print("addr {}: *** read compare FAILED ***".format(hex(addr)))
            print(binascii.hexlify(buf))
            print("<----->")
            print(binascii.hexlify(buf2))

print("\ntotal_bytes = {}".format(total_bytes))

spi.terminate()

