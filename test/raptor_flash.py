from pyftdi.ftdi import Ftdi
import time
from pyftdi.spi import SpiController
from array import array as Array

spi = SpiController(cs_count=1, turbo=True)
# spi.configure(vendor=0x0403, product=0x6014, interface=1)
spi.configure('ftdi://::/1')
slave = spi.get_port(cs=0, freq=12E6, mode=0)  # Chip select is 0 -- corresponds to D3

# acbus_direction = 0x01 # Bit C0 is output for reset
# ctrl._ftdi.write_data(Array('B', [Ftdi.SET_BITS_HIGH, 0x00, acbus_direction]))
# time.sleep(1.0)
# ctrl._ftdi.write_data(Array('B', [Ftdi.SET_BITS_HIGH, 0x01, acbus_direction]))
# time.sleep(1.0)
