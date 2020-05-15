#!/usr/bin/env python3

# from pyftdi.ftdi import Ftdi
import pyftdi.serialext

import os
import sys
import termios
import fcntl

def getch():
  fd = sys.stdin.fileno()

  oldterm = termios.tcgetattr(fd)
  newattr = termios.tcgetattr(fd)
  newattr[3] = newattr[3] & ~termios.ICANON & ~termios.ECHO
  termios.tcsetattr(fd, termios.TCSANOW, newattr)

  oldflags = fcntl.fcntl(fd, fcntl.F_GETFL)
  fcntl.fcntl(fd, fcntl.F_SETFL, oldflags | os.O_NONBLOCK)

  try:
    while 1:
      try:
        c = sys.stdin.read(1)
        break
      except IOError: pass
  finally:
    termios.tcsetattr(fd, termios.TCSAFLUSH, oldterm)
    fcntl.fcntl(fd, fcntl.F_SETFL, oldflags)
  return c

# pyftdi.ftdi.show_
# devices('ftdi://ftdi:232h:/1')
# Ftdi.show_devices()

# f1 = Ftdi.create_from_url('ftdi://ftdi:232h:/1')

# print(f1.baudrate)

port = pyftdi.serialext.serial_for_url('ftdi://ftdi:232h:/1', baudrate=4175)
port._timeout = True  # make reads non-blocking

c = ''
while (c != 'q'):
    data = port.read(1)
    if (data):
        print(data.decode(encoding="utf-8"))
    c = getch()
    if (c != ''):
        port.write(c)