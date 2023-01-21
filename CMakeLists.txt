cmake_minimum_required(VERSION 3.22)
project(05_Try_it_Out_Linear_Probing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(05_Try_it_Out_Linear_Probing
        LinearHashtable.h
        LinearHashTester.cpp)
