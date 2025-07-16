# general settings
cmake_minimum_required(VERSION 3.25)
project(command LANGUAGES CXX)

# building observer class as library
add_library(command STATIC command.cxx)
target_include_directories(command PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# exe
add_executable(test main.cxx)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test PRIVATE command)

