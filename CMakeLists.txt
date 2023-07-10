cmake_minimum_required (VERSION 3.18.4)

option(USE_RASPBERRY_PI "Use WiringPi on RaspberryPi" OFF)
option(USE_SPI_STUB "Use SPI stub" ON)

project(dwm3000-communication-driver)

add_subdirectory(src/main)



# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)


# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)

