cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 20)

project(general_concepts VERSION 1.0.0 LANGUAGES CXX)

add_executable(general_concepts src/main.cpp)

target_include_directories(general_concepts PRIVATE include)