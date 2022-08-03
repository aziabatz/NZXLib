cmake_minimum_required(VERSION 3.23)
project(NZXLib)

set(CMAKE_CXX_STANDARD 14)

add_library(NZXLib library.cpp
        Stream.cpp ../include/Library/Memory/Memory.hpp Memory.cpp ../include/Library/util.hpp ../include/Library/Streams/OutputStream.hpp OutputStream.cpp)

target_include_directories(NZXLib PRIVATE ../include/Library)
