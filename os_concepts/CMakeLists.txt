cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 20)

project(os_concepts VERSION 1.0.0 LANGUAGES CXX)

add_executable(os_concepts src/main.cpp)

target_include_directories(os_concepts PRIVATE include)