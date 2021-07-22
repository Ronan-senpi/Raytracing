cmake_minimum_required(VERSION 3.17)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

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
        src/Tools/Camera.h
        src/Tools/Helpers/Serializer.h
        src/Tools/Objects/Include.h)

find_package(OpenMP)


target_include_directories(Raytracing PRIVATE
        "Libraries/opencv/build/include"
        "Libraries/stb")

if (OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif ()

add_custom_command(TARGET Raytracing PRE_BUILD
        COMMAND robocopy ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources /E /NS /NC /NFL /NDL /NP /NJH /NJS || cmd /c "exit /b 0")

