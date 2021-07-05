cmake_minimum_required(VERSION 3.17)
project(Raytracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracing main.cpp
        src/Tools/Vector.h
        src/Tools/Vector.cpp)