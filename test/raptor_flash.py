from pyftdi.ftdi import Ftdi
import time
from pyftdi.spi import SpiController
from array import array as Array
import binascii

spi = SpiController(cs_count=1, turbo=True)
# spi.configure(vendor=0x0403, product=0x6014, interface=1)
spi.configure('ftdi://::/1')
slave = spi.get_port(cs=0, freq=12E6, mode=0)  # Chip select is 0 -- corresponds to D3

jedec_id = slave.exchange([0x9f], 3)
print("JEDEC = {}".format(binascii.hexlify(jedec_id)))

slave.write([0x06])
slave.write([0x60])

spi.terminate()

