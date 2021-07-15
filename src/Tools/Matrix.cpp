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

Matrix Matrix::inverse() const {
    return Matrix();
}

//Matrix Matrix::inverse() const {
//    Matrix out;
//    Matrix inv;
//
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++)
//            inv(i, j) = invf(i, j, m);
//
//    float D = 0;
//
//    for (int k = 0; k < 4; k++)
//        D += m[k] * inv[k * 4];
//
//    if (D == 0) throw "det = 0";
//
//    D = 1.f / D;
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            out(i, j) = inv(i, j) * D;
//        }
//    }
//
//    return out;
//}

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

float Matrix::determinant() {
    return (*this)(0, 0) *
           (((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
            ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2))
            - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) - ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) -
            ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2)))
           - (*this)(1, 0) *
             (((*this)(0, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(0, 2) * (*this)(2, 3) * (*this)(3, 1)) +
              ((*this)(0, 3) * (*this)(2, 1) * (*this)(3, 2))
              - ((*this)(0, 3) * (*this)(2, 2) * (*this)(3, 1)) - ((*this)(0, 2) * (*this)(2, 1) * (*this)(3, 3)) -
              ((*this)(0, 1) * (*this)(2, 3) * (*this)(3, 2)))
           + (*this)(2, 0) *
             (((*this)(0, 1) * (*this)(1, 2) * (*this)(3, 3)) + ((*this)(0, 2) * (*this)(1, 3) * (*this)(3, 1)) +
              ((*this)(0, 3) * (*this)(1, 1) * (*this)(3, 2))
              - ((*this)(0, 3) * (*this)(1, 2) * (*this)(3, 1)) - ((*this)(0, 2) * (*this)(1, 3) * (*this)(3, 3)) -
              ((*this)(0, 1) * (*this)(1, 3) * (*this)(3, 2)))
           - (*this)(3, 0) *
             (((*this)(0, 1) * (*this)(1, 2) * (*this)(2, 3)) + ((*this)(0, 2) * (*this)(1, 3) * (*this)(2, 1)) +
              ((*this)(0, 3) * (*this)(1, 1) * (*this)(2, 2))
              - ((*this)(0, 3) * (*this)(1, 2) * (*this)(2, 1)) - ((*this)(0, 2) * (*this)(1, 1) * (*this)(2, 3)) -
              ((*this)(0, 1) * (*this)(1, 3) * (*this)(2, 2)));
}

Matrix Matrix::adjugate() {
    Matrix adj;
    adj(0, 0) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(0, 1) = -((*this)(0, 1) * (*this)(2, 2) * (*this)(3, 3)) - ((*this)(0, 2) * (*this)(2, 3) * (*this)(3, 1)) -
                ((*this)(0, 3) * (*this)(2, 1) * (*this)(3, 2)) + ((*this)(0, 3) * (*this)(2, 2) * (*this)(3, 1)) +
                ((*this)(0, 2) * (*this)(2, 1) * (*this)(3, 3)) + ((*this)(0, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(0, 2) = ((*this)(0, 1) * (*this)(1, 2) * (*this)(3, 3)) + ((*this)(0, 2) * (*this)(1, 3) * (*this)(3, 1)) +
                ((*this)(0, 3) * (*this)(1, 1) * (*this)(3, 2)) - ((*this)(0, 3) * (*this)(1, 2) * (*this)(3, 1)) -
                ((*this)(0, 2) * (*this)(1, 1) * (*this)(3, 3)) - ((*this)(0, 1) * (*this)(1, 3) * (*this)(3, 2));

    adj(0, 3) = -((*this)(0, 1) * (*this)(1, 2) * (*this)(2, 3)) - ((*this)(0, 2) * (*this)(1, 3) * (*this)(2, 1)) -
                ((*this)(0, 3) * (*this)(1, 1) * (*this)(2, 2)) + ((*this)(0, 3) * (*this)(1, 2) * (*this)(2, 1)) +
                ((*this)(0, 2) * (*this)(1, 1) * (*this)(2, 3)) + ((*this)(0, 1) * (*this)(1, 3) * (*this)(2, 2));


    adj(1, 0) = ((*this)(0, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(0, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(0, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(0, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(0, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(1, 1) = ((*this)(0, 0) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(0, 2) * (*this)(2, 3) * (*this)(3, 0)) +
                ((*this)(0, 3) * (*this)(2, 0) * (*this)(3, 2)) - ((*this)(0, 3) * (*this)(2, 2) * (*this)(3, 0)) -
                ((*this)(0, 2) * (*this)(2, 0) * (*this)(3, 3)) - ((*this)(0, 0) * (*this)(2, 3) * (*this)(3, 2));







    adj(1, 2) = ((*this)(0, 0) * (*this)(2, 1) * (*this)(3, 3)) + ((*this)(0, 1) * (*this)(2, 3) * (*this)(3, 0)) +
                ((*this)(0, 3) * (*this)(2, 0) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(1, 3) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(2, 0) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(2, 1) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(2, 2) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(2, 3) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(3, 0) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(3, 1) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(3, 2) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));

    adj(3, 3) = ((*this)(1, 1) * (*this)(2, 2) * (*this)(3, 3)) + ((*this)(1, 2) * (*this)(2, 3) * (*this)(3, 1)) +
                ((*this)(1, 3) * (*this)(2, 1) * (*this)(3, 2)) - ((*this)(1, 3) * (*this)(2, 2) * (*this)(3, 1)) -
                ((*this)(1, 2) * (*this)(2, 1) * (*this)(3, 3)) - ((*this)(1, 1) * (*this)(2, 3) * (*this)(3, 2));


    return adj;
}


//float Matrix::invf(int i, int j, const std::array<float, 4 * 4> *mat) {
//    int o = 2 + (j - i);
//
//    i += 4 + o;
//    j += 4 - o;
//
//#define e(a, b) mat[ ((j+b)%4)*4 + ((i+a)%4) ]
//
//    float inv =
//    +e(+1, -1)*e(+0, +0)*e(-1, +1)
//    +e(+1, +1)*e(+0, -1)*e(-1, +0)
//    +e(-1, -1) * e(+1, +0)*e(+0, +1)
//    -e(-1, -1) * e(+0, +0)*e(+1, +1)
//    -e(-1, +1)*e(+0, -1)*e(+1, +0)
//    -e(+1, -1)*e(-1, +0)*e(+0, +1);
//
//    return (o % 2) ? inv : -inv;
//
//#undef e
//}


