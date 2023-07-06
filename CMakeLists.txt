cmake_minimum_required (VERSION 3.18.4)

project(KRANCKI)

add_subdirectory(src/main)

# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)


# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)

