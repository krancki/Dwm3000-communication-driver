

set(SOURCES 
./RegistryReader.cpp
./RegistryReader.hpp
./RegistryLoader.cpp
./RegistryLoader.hpp
./Dwm3000.hpp
)

#Add spi library
set(SPI_LIB_NAME SPI_LIBRARY)
set(HEADER_FORMATING_LIB_NAME HEADER_FORMATING_LIB)
set(COMMAND_DEFINITION_LIB_NAME COMMAND_DEFINITION_LIB)
set(REGISTERS_DEFINITION_LIB_NAME REGISTERS_DEFINITION_LIB)

add_subdirectory(Spi)
add_subdirectory(HeaderFormatting)
add_subdirectory(Commands)
add_subdirectory(Registers)

add_executable(${PROJECT_NAME} ./Main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SPI_LIB_NAME})
target_link_libraries(${PROJECT_NAME} ${HEADER_FORMATING_LIB_NAME})
target_link_libraries(${PROJECT_NAME} ${COMMAND_DEFINITION_LIB_NAME})
target_link_libraries(${PROJECT_NAME} ${REGISTERS_DEFINITION_LIB_NAME})


