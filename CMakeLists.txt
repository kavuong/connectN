cmake_minimum_required(VERSION 3.8)
project(connectn)

set(CMAKE_C_STANDARD 11)
set (GCC_ENABLE_WARNINGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_ENABLE_WARNINGS}" )

set(SOURCE_FILES main.c board.c board.h move.c move.h inputValidation.c inputValidation.h win.c win.h)
add_executable(connectn ${SOURCE_FILES})