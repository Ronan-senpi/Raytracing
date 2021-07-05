//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_VECTOR_H
#define RAYTRACING_VECTOR_H

#include <iostream>
#include "Point.h"

class Vector : public Point {
public:
    Vector(float x, float y, float z) : Point(x, y, z) {}
    Vector(const Vector &v) : Point(v.m_x, v.m_y, v.m_z) {}

    float norm() const;

    Vector normalized() const;

    Vector operator=(const Point& p)
//    float dot(const Vector &v) const;
//    float operator[](int i) const;
//    Vector operator+(const Vector &v) const;
//    Vector operator-(Vector &v);
//    Vector operator-() const;
//    Vector operator*(float factor) const;
//    Vector operator/(float divide) const;
};

std::ostream &operator<<(std::ostream &os, const Vector &v);

#endif //RAYTRACING_VECTOR_H
