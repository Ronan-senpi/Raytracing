////
//// Created by rdher on 05/07/2021.
////
//
#ifndef RAYTRACING_MATRIX_H
#define RAYTRACING_MATRIX_H
//
//#include <array>
//#include <vector>
//
////Matrix 4x4
class Matrix {
public:
    Matrix inverse() const{
        return  Matrix();
    }

};
//private:
//    std::array<float, 4 * 4> m{};
//
//    static float invf(int i, int j, const std::array<float, 4 * 4> *mat);
//
//    static std::array<float, 4 * 4> emptyMatrix();
//
//public:
//
//    Matrix();
//
//    Matrix(const Matrix &mat);
//
//    ~Matrix() = default;
//
//    Matrix inverse() const;
//
//    float operator()(int i, int j) const;
//};
//
//
#endif //RAYTRACING_MATRIX_H
