cmake_minimum_required(VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 17)

project(beginning VERSION 1.0.0)

add_executable(beginning    src/main.cpp
                            src/basic_01.cpp     
                )                

target_include_directories(beginning PRIVATE include)
