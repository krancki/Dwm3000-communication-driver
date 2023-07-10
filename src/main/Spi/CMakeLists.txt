
set(SPI_LIB_SOURCES SpiConnector.hpp)

if(USE_RASPBERRY_PI)
    message(STATUS "Używanie biblioteki WiringPi")
    list(APPEND SPI_LIB_SOURCES RaspberryPiWiringPi.cpp)
endif()


add_library(${SPI_LIB_NAME} ${SPI_LIB_SOURCES})
set_target_properties(${SPI_LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

if(USE_RASPBERRY_PI)
    target_link_libraries(${SPI_LIB_NAME} wiringPi)
endif()