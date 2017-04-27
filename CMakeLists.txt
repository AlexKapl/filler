cmake_minimum_required(VERSION 3.6)
project(filler)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c filler.h reader.c placer.c checker.c)
add_executable(filler ${SOURCE_FILES})
target_link_libraries(filler ${CMAKE_SOURCE_DIR}/libft/libft.a)