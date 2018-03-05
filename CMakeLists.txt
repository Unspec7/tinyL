cmake_minimum_required(VERSION 3.9)
project(tinyL C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -ggdb -Wall")

add_executable(tinyL Interpreter.c Compiler.c Optimizer.c)