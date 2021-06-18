cmake_minimum_required(VERSION 3.19)
project(c__)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(c__ demo1.cpp  demo1_fun.cpp demo1_fun.h demo1/study_01.cpp
        demo1/study_01.h project01/pro01.cpp project01/pro01.h project01/utils.cpp project01/utils.h)
add_executable(zxf main.cpp)

add_library(test SHARED main.cpp)

add_executable(demo2_01 demo2/01.cpp)
add_executable(demo2_02 demo2/02.cpp)
add_executable(demo2_03 demo2/03.cpp)
add_executable(demo2_04 demo2/04.cpp)
add_executable(demo2_05 demo2/05.cpp)
add_executable(demo2_06 demo2/06.cpp)
add_executable(demo3_01 demo3/01.cpp)
add_executable(demo3_02 demo3/02.cpp)
add_executable(demo3_04 demo3/04.cpp)
add_executable(demo4_01 demo4/01.cpp)
add_executable(demo4_02 demo4/02.cpp)
add_executable(demo4_03 demo4/03.cpp)
add_executable(demo4_04 demo4/04.cpp)
add_executable(demo4_05 demo4/05.cpp)