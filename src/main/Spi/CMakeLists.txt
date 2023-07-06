add_library(${SPI_LIB_NAME} ./SpiConnector.hpp ./RaspberryPiWiringPi.cpp)

target_link_libraries(${SPI_LIB_NAME} wiringPi)