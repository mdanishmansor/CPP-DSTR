cmake_minimum_required(VERSION 3.22)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        main.cpp
        mainmenu.h
        userLogin.h
        Order.h)
