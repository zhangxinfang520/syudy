cmake_minimum_required(VERSION 3.19)
project(study)

set(CMAKE_CXX_STANDARD 14)

include_directories(study)

add_executable(study
        study/01.cpp
        study/02.cpp
        study/swap.cpp
        study/swap.h)
