//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_VECTOR_H
#define RAYTRACING_VECTOR_H

#include <iostream>
#include "Point.h"

class Vector {

class Vector : public Point {
public:
    Vector(float x, float y, float z) : Point(x, y, z) {}
    Vector(const Vector &v) : Point(v.m_x, v.m_y, v.m_z) {}

    float norm() const;

    Vector normalized() const;


    Vector operator=(const Point& p)
  
    float X() const {
        return m_x;
    }

    void X(float val) {
        m_x = val;
    }

    float Y() const {
        return m_y;
    }

    void Y(float val) {
        m_y = val;
    }

    float Z() const {
        return m_z;
    }

    void Z(float val) {
        m_z = val;
    }
};

std::ostream &operator<<(std::ostream &os, const Vector &v);

#endif //RAYTRACING_VECTOR_H
