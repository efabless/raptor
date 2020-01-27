from pyftdi.ftdi import Ftdi

Ftdi().open_mpsee_from_url('ftdi://ftdi:232h:2:6/1')
print(Ftdi().ic_name())
print(Ftdi().device_version())
print(Ftdi().has_mpsse())
print(Ftdi().is_mpsse())

Ftdi().close()