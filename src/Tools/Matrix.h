//
// Created by rdher on 05/07/2021.
//

#ifndef RAYTRACING_MATRIX_H
#define RAYTRACING_MATRIX_H

#include <array>
#include <vector>

//Matrix 4x4
class Matrix {
private:
    std::array<float, 16> m{};

//    static float invf(int i, int j, const std::array<float, 4 * 4> *mat);

    std::array<float, 16> emptyMatrix();

public:

    Matrix();

    Matrix(const Matrix &mat);

    ~Matrix() = default;
    float determinant();
    Matrix adjugate();
    Matrix inverse() const;

    float operator()(int i, int j)const;
    float& operator()(int i, int j);

};


#endif //RAYTRACING_MATRIX_H
