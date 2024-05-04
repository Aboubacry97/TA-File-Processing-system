cmake_minimum_required(VERSION 3.26)
project(Filtering_TA_Files)

set(CMAKE_CXX_STANDARD 20)

add_executable(Filtering_TA_Files main.cpp
        modifyFile.h
        modifyFile.cpp)
