////
//// Created by rdher on 05/07/2021.
////
//
#ifndef RAYTRACING_MATRIX_H
#define RAYTRACING_MATRIX_H

//
#include <array>
#include "Point.h"
#include "Vector.h"
//
////Matrix 4x4
class Matrix {
private:

    std::array<float, 16> m = {};
    std::array<float, 16> identiy() const;

public:

    Matrix();
    Matrix(const Matrix &mat);
    Matrix(std::array<float, 16> tab);
    ~Matrix() = default;

    std::array<float, 16> getMatrix() const;

    Matrix inverse() const;

    float operator()(const int& i, const int& j) const;
    float &operator()(int i, int j);

    Matrix operator*(Matrix mult);
    Point operator*(Point p);
    Vector operator*(Vector p);
    Matrix operator*(float f);
};

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);



#endif //RAYTRACING_MATRIX_H
