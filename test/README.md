##To program the SPI flash chip:

  1. Install the pyftdi python library if needed
  
    pip3 install pyftdi
  
  2. Configure the board for flash programming.

    Install jumpers on across pins 2 & 3 on the four 3-pin headers 
    next to the USB connector.
    
    Ensure the jumper for usb to Raptor uart are not installed 
    (two 2-pin headers next to USB)

  3. Change to the directory for the target firmware

    make clean hex flash

  4. Configure the board for processor operation

    Move jumpers on across pins 1 & 2 on the four 3-pin headers 
    next to the USB connector.




