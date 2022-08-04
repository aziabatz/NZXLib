cmake_minimum_required(VERSION 3.1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(NZXLib CXX ASM-ATT)

set(CMAKE_VERBOSE_MAKEFILE ON)
ENABLE_LANGUAGE(ASM-ATT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "/home/aziabatz/opt/cross/bin/i686-elf-g++")
set(CMAKE_ASM-ATT_COMPILER "/home/aziabatz/opt/cross/bin/i686-elf-as")
set(CMAKE_CXX_FLAGS "-c -g -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-leading-underscore -ffreestanding -Wall -Wextra -fno-exceptions -fno-rtti -fpermissive")
set(CMAKE_ASM-ATT_FLAGS "--32 -g")
set(CMAKE_CXX_LINK_EXECUTABLE "/home/aziabatz/opt/cross/bin/i686-elf-gcc -T linker.ld -o <TARGET> -ffreestanding -O2 -nostdlib <OBJECTS> -lgcc")


add_library(NZXLib Memory.cpp streams/OutputStream.cpp streams/Stream.cpp)
set_target_properties(NZXLib PROPERTIES PREFIX static)
set_target_properties(NZXLib PROPERTIES OUTPUT_NAME NZX)
set_target_properties(NZXLib PROPERTIES SUFFIX .library)
target_include_directories(NZXLib PRIVATE ../include)
