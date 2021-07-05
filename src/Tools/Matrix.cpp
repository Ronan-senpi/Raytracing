////
//// Created by rdher on 05/07/2021.
////
//
//#include <iostream>
//#include "Matrix.h"
//
////Matrix de 4x4
//
//Matrix::Matrix() {
//    m = Matrix::emptyMatrix();
//}
//
//Matrix::Matrix(const Matrix &mat) {
//}
//
//
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
//
//float Matrix::operator()(int i, int j) const {
//    return m[i * 4 + j];
//}
//
//std::array<float, 4 * 4> Matrix::emptyMatrix() {
//    std::array<float, 4 * 4> a{};
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            a[i = 4 + j] = 0;
//        }
//    }
//    return a;
//}
//
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
//
//
