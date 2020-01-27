from pyftdi.ftdi import Ftdi

dev = Ftdi.open_from_url('ftdi://ftdi:232h:2:5/1')
mdev = Ftdi.open_mpsse_from_url('ftdi://ftdi:232h:2:5/1')

print(mdev.ic_name())
print(mdev.device_version())
print(mdev.has_mpsse())
print(mdev.is_mpsse())

dev.close()
mdev.close()