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
public:
    Matrix();

    Matrix(const Matrix &mat);

    Matrix(std::array<float, 16> tab);

    ~Matrix() = default;

    std::array<float, 16> getMatrix() const;

    static std::array<float, 16> identiy();


    Matrix inverse() const;

    float operator()(const int &i, const int &j) const;

    float &operator()(int i, int j);

    Matrix operator*(const Matrix &mult) const;

    Point operator*(const Point &p) const;

    Vector operator*(const Vector &p) const;

    Matrix operator*(const float &f) const;
};

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);


#endif //RAYTRACING_MATRIX_H
