cmake_minimum_required(VERSION 3.17)
project(Raytracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracing main.cpp
        src/Tools/Vector.h
        src/Tools/Vector.cpp
        src/Tools/Point.cpp
        src/Tools/Point.h
        src/Tools/Matrix.cpp
        src/Tools/Matrix.h
        src/Tools/Entity.cpp
        src/Tools/Entity.h
        src/Tools/Object.cpp
        src/Tools/Object.h
        src/Tools/Ray.cpp
        src/Tools/Ray.h
        src/Tools/Scene.cpp
        src/Tools/Scene.h
        src/Tools/Color.cpp
        src/Tools/Color.h 
        src/Tools/Light.cpp 
        src/Tools/Light.h)
