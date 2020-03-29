cmake_minimum_required(VERSION 3.15)
project(RelayData)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(examples)
include_directories(examples/RelayData)

add_executable(RelayData
        examples/RelayData/RelayData.ino
        RelayData.cpp
        RelayData.h)
