cmake_minimum_required(VERSION 3.28)
project(GPU_t1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

include_directories(.)

add_executable(GPU_t1
        main.cpp
        Matrix.cpp
        Matrix.h)
