from pyftdi.ftdi import Ftdi
import pyftdi.serialext

# Ftdi.show_devices()

# f1 = Ftdi.create_from_url('ftdi://:/1')

# print(f1.baudrate)

port = pyftdi.serialext.serial_for_url('ftdi://:/1', baudrate=4175)

while (1):
    data = port.read(1)
    print(data)