cmake_minimum_required(VERSION 3.22)
project(LiveOrderIT_Management_System)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(LiveOrderIT_Management_System main.cpp)