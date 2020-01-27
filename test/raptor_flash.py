from pyftdi.ftdi import Ftdi

Ftdi().open_mpsse_from_url('ftdi://ftdi:232h:2:6/1')
print(Ftdi().has_mpsse)
print(Ftdi().is_mpsse)

Ftdi().close()
