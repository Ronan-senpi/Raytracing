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
    Vector(const Point &p) : Point(p.X(), p.Y(), p.Z()) {}

    float norm() const;
    Vector normalized() const;
};

std::ostream &operator<<(std::ostream &os, const Vector &v);

#endif //RAYTRACING_VECTOR_H
