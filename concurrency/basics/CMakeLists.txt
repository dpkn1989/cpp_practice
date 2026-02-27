cmake_minimum_required(VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 17)

project(concurrency_basics VERSION 1.0.0)

add_executable(concurrency_basics src/main.cpp
                                  src/basics.cpp)

target_include_directories(concurrency_basics PRIVATE include)