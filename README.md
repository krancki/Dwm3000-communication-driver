# Dwm3000-communication-driver
C++ communication driver for dwm3000

# How to run
1. Clone repo
2. cmake .build/
3. cd build/
4. make

## Description / target
Project aims to provide a tool that will allow easy communication with the dwm3000 device. 
Finally, a library will be created that can be used to create device control logic in simple way.

### Dwm3000 use SPI for communication. 
By default is used library for raspberrypi, but you can change it in src/main/spi/CMakeLists.txt with your own implementation.
Use SpiConnector.hpp


