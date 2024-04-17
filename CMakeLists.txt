cmake_minimum_required(VERSION 3.28)
project(GPU_t1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(GPUT1_SRC
        "${PROJECT_SOURCE_DIR}/src/main.cpp"
        "${PROJECT_SOURCE_DIR}/src/Matrix.cpp"
        "${PROJECT_SOURCE_DIR}/src/Matrix.h"
)

add_library(${PROJECT_NAME} INTERFACE ${GPUT1_SRC})
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/src)

include(CTest)
add_subdirectory(extern)
add_subdirectory(test)


#include_directories(.)
#
#add_executable(GPU_t1
#        src/main.cpp
#        src/Matrix.cpp
#        src/Matrix.h)