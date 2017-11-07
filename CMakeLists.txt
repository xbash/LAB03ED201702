cmake_minimum_required(VERSION 3.8)
project(Colas)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Colas.h Ruleta.h)
add_executable(Colas ${SOURCE_FILES})