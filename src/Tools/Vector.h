//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_VECTOR_H
#define RAYTRACING_VECTOR_H

#include <iostream>
#include "Point.h"

class Vector : public Point {
public:

    Vector() : Point(0, 0, 0) {};

    Vector(const float &x, const float &y, const float &z) : Point(x, y, z) {}

    Vector(const Vector &v) : Point(v) {}

    Vector(const Point &p) : Point(p) {}

    float norm() const;

    Vector normalized() const;

    Vector operator*(const float factor) const {
        return {this->m_x * factor, this->m_y * factor, this->m_z * factor};
    }
};

std::ostream &operator<<(std::ostream &os, const Vector &v);

#endif //RAYTRACING_VECTOR_H
