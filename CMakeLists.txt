cmake_minimum_required(VERSION 3.20)
project(lead_std C)

set(CMAKE_C_STANDARD 99)

add_executable(lead_std main.c option.c option.h io.c io.h leadstd.h array_list.c array_list.h primitives.h string.c string.h mem.c mem.h)
