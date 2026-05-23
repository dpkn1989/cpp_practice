cmake_minimum_required(VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 17)

project(design_patterns VERSION 1.0.0)

add_executable(design_patterns src/main.cpp
                            src/singleton_example.cpp
                            src/factory_example.cpp
                            src/abstract_factory_example.cpp
                            src/strategy_example.cpp
                            src/state_example.cpp
                            src/observer_example.cpp
                            src/adapter_example.cpp
                            src/decorator_example.cpp
                            src/command_example.cpp      
                )                

target_include_directories(design_patterns PRIVATE include)
