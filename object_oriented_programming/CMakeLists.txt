cmake_minimum_required(VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 17
    CMAKE_CXX_STANDARD_REQUIRED ON)

project(oops VERSION 1.0.0 LANGUAGES CXX)

add_executable(oops src/main.cpp
                    src/Accounts.cpp
                    src/Templates.cpp
                    src/lambdas.cpp)

target_include_directories(oops PRIVATE include)