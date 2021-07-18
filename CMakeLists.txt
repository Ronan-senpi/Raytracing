cmake_minimum_required(VERSION 3.17)
project(Raytracing)

set(CMAKE_CXX_STANDARD 17)

add_executable(Raytracing main.cpp
        src/Tools/Vector.h
        src/Tools/Vector.cpp
        src/Tools/Point.cpp
        src/Tools/Point.h
        src/Tools/Matrix.cpp
        src/Tools/Matrix.h
        src/Tools/Entity.cpp
        src/Tools/Entity.h
        src/Tools/Objects/Object.cpp
        src/Tools/Objects/Object.h
        src/Tools/Objects/Plan.cpp
        src/Tools/Objects/Plan.h
        src/Tools/Objects/Sphere.cpp
        src/Tools/Objects/Sphere.h
        src/Tools/Objects/Cube.cpp
        src/Tools/Objects/Cube.h
        src/Tools/Objects/Square.cpp
        src/Tools/Objects/Square.h
        src/Tools/Objects/Cylinder.cpp
        src/Tools/Objects/Cylinder.h
        src/Tools/Ray.cpp
        src/Tools/Ray.h
        src/Tools/Scene.cpp
        src/Tools/Scene.h
        src/Tools/Color.cpp
        src/Tools/Color.h
        src/Tools/Light.cpp
        src/Tools/Light.h
        src/Tools/Material.cpp
        src/Tools/Material.h
        src/Tools/Images/Image.cpp
        src/Tools/Images/Image.h
        src/Tools/Images/ImageType.h
        src/Tools/Helpers/Debug.cpp
        src/Tools/Helpers/Debug.h
        src/Tools/Helpers/FileHelper.cpp
        src/Tools/Helpers/FileHelper.h
        src/Tools/Helpers/StringHelpers.cpp
        src/Tools/Helpers/StringHelpers.h
        src/Tools/Camera.cpp
        src/Tools/Camera.h)

target_include_directories(Raytracing PRIVATE
        "Libraries/opencv/build/include"
        "Libraries/stb")