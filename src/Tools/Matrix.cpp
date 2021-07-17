//
// Created by rdher on 05/07/2021.
//

#include <iostream>
#include "Matrix.h"

//Matrix de 4x4
Matrix::Matrix() {
    m = Matrix::emptyMatrix();
}

Matrix::Matrix(const Matrix &mat) {
    m = mat.m;
}

Matrix::Matrix(std::array<float, 16> tab) {
    m = tab;
}

float Matrix::operator()(const int i, const int j) const {
    return m[i * 4 + j];
}

float &Matrix::operator()(const int i, const int j) {
    return m[i * 4 + j];
}

std::array<float, 16> Matrix::emptyMatrix() const {
    std::array<float, 4 * 4> a{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[i = 4 + j] = 0;
        }
    }
    return a;
}

Matrix Matrix::inverse() const {
    std::array<float, 16> tmp{}, inv{};
    float det;
    int i;

    tmp[0] = m[5] * m[10] * m[15] -
             m[5] * m[11] * m[14] -
             m[9] * m[6] * m[15] +
             m[9] * m[7] * m[14] +
             m[13] * m[6] * m[11] -
             m[13] * m[7] * m[10];

    tmp[4] = -m[4] * m[10] * m[15] +
             m[4] * m[11] * m[14] +
             m[8] * m[6] * m[15] -
             m[8] * m[7] * m[14] -
             m[12] * m[6] * m[11] +
             m[12] * m[7] * m[10];

    tmp[8] = m[4] * m[9] * m[15] -
             m[4] * m[11] * m[13] -
             m[8] * m[5] * m[15] +
             m[8] * m[7] * m[13] +
             m[12] * m[5] * m[11] -
             m[12] * m[7] * m[9];

    tmp[12] = -m[4] * m[9] * m[14] +
              m[4] * m[10] * m[13] +
              m[8] * m[5] * m[14] -
              m[8] * m[6] * m[13] -
              m[12] * m[5] * m[10] +
              m[12] * m[6] * m[9];

    tmp[1] = -m[1] * m[10] * m[15] +
             m[1] * m[11] * m[14] +
             m[9] * m[2] * m[15] -
             m[9] * m[3] * m[14] -
             m[13] * m[2] * m[11] +
             m[13] * m[3] * m[10];

    tmp[5] = m[0] * m[10] * m[15] -
             m[0] * m[11] * m[14] -
             m[8] * m[2] * m[15] +
             m[8] * m[3] * m[14] +
             m[12] * m[2] * m[11] -
             m[12] * m[3] * m[10];

    tmp[9] = -m[0] * m[9] * m[15] +
             m[0] * m[11] * m[13] +
             m[8] * m[1] * m[15] -
             m[8] * m[3] * m[13] -
             m[12] * m[1] * m[11] +
             m[12] * m[3] * m[9];

    tmp[13] = m[0] * m[9] * m[14] -
              m[0] * m[10] * m[13] -
              m[8] * m[1] * m[14] +
              m[8] * m[2] * m[13] +
              m[12] * m[1] * m[10] -
              m[12] * m[2] * m[9];

    tmp[2] = m[1] * m[6] * m[15] -
             m[1] * m[7] * m[14] -
             m[5] * m[2] * m[15] +
             m[5] * m[3] * m[14] +
             m[13] * m[2] * m[7] -
             m[13] * m[3] * m[6];

    tmp[6] = -m[0] * m[6] * m[15] +
             m[0] * m[7] * m[14] +
             m[4] * m[2] * m[15] -
             m[4] * m[3] * m[14] -
             m[12] * m[2] * m[7] +
             m[12] * m[3] * m[6];

    tmp[10] = m[0] * m[5] * m[15] -
              m[0] * m[7] * m[13] -
              m[4] * m[1] * m[15] +
              m[4] * m[3] * m[13] +
              m[12] * m[1] * m[7] -
              m[12] * m[3] * m[5];

    tmp[14] = -m[0] * m[5] * m[14] +
              m[0] * m[6] * m[13] +
              m[4] * m[1] * m[14] -
              m[4] * m[2] * m[13] -
              m[12] * m[1] * m[6] +
              m[12] * m[2] * m[5];

    tmp[3] = -m[1] * m[6] * m[11] +
             m[1] * m[7] * m[10] +
             m[5] * m[2] * m[11] -
             m[5] * m[3] * m[10] -
             m[9] * m[2] * m[7] +
             m[9] * m[3] * m[6];

    tmp[7] = m[0] * m[6] * m[11] -
             m[0] * m[7] * m[10] -
             m[4] * m[2] * m[11] +
             m[4] * m[3] * m[10] +
             m[8] * m[2] * m[7] -
             m[8] * m[3] * m[6];

    tmp[11] = -m[0] * m[5] * m[11] +
              m[0] * m[7] * m[9] +
              m[4] * m[1] * m[11] -
              m[4] * m[3] * m[9] -
              m[8] * m[1] * m[7] +
              m[8] * m[3] * m[5];

    tmp[15] = m[0] * m[5] * m[10] -
              m[0] * m[6] * m[9] -
              m[4] * m[1] * m[10] +
              m[4] * m[2] * m[9] +
              m[8] * m[1] * m[6] -
              m[8] * m[2] * m[5];

    det = m[0] * tmp[0] + m[1] * tmp[4] + m[2] * tmp[8] + m[3] * tmp[12];
    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        inv[i] = tmp[i] * det;

    return Matrix(inv);
}

std::array<float, 16> Matrix::getMatrix() const {
    return m;
}

Matrix Matrix::operator*(Matrix mult) {
    std::array<float, 16> arr{};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i * 4 + j] = m[i * 4] * mult.getMatrix()[j] + m[i * 4 + 1] * mult.getMatrix()[1 * 4 + j] +
                             m[i * 4 + 2] * mult.getMatrix()[2 * 4 + j] + m[i * 4 + 3] * mult.getMatrix()[3 * 4 + j];
        }
    }
    return Matrix(arr);
}

Matrix Matrix::operator*(float f) {
    std::array<float, 16> arr{};
    for (int i = 0; i < 4; i++) {
        arr[i] = m[i] * f;
    }
    return Matrix(arr);
}

Point Matrix::operator*(Point p) {
    Point res;
    float w;
    res.X((*this)(0, 0) * p.X() + (*this)(1, 0) * p.Y() + (*this)(2, 0) * p.Z() + (*this)(3, 0));
    res.Y((*this)(0, 1) * p.X() + (*this)(1, 1) * p.Y() + (*this)(2, 1) * p.Z() + (*this)(3, 1));
    res.Z((*this)(0, 2) * p.X() + (*this)(1, 2) * p.Y() + (*this)(2, 2) * p.Z() + (*this)(3, 2));
    w = (*this)(0, 3) * p.X() + (*this)(1, 3) * p.Y() + (*this)(2, 3) * p.Z() + (*this)(3, 3);

    w = 1.0f / w;
    res.X(res.X() * w);
    res.Y(res.Y() * w);
    res.Z(res.Z() * w);
    return res;
}


Vector Matrix::operator*(Vector p) {
    Vector res;
    res.X((*this)(0, 0) * p.X() + (*this)(1, 0) * p.Y() + (*this)(2, 0) * p.Z());
    res.Y((*this)(0, 1) * p.X() + (*this)(1, 1) * p.Y() + (*this)(2, 1) * p.Z());
    res.Z((*this)(0, 2) * p.X() + (*this)(1, 2) * p.Y() + (*this)(2, 2) * p.Z());
    return res;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    std::array<float, 16> arr = matrix.getMatrix();
    for (float i : arr) {
        os << "(" << i << ")";
    }
    return os << std::endl;
}



