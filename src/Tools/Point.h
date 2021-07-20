//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_POINT_H
#define RAYTRACING_POINT_H

#include <iostream>

class Point {
protected:
    float m_x, m_y, m_z;

public:
    Point() : m_x(0), m_y(0), m_z(0) {}

    Point(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}

    Point(const Point &p) : m_x(p.m_x), m_y(p.m_y), m_z(p.m_z) {}

    float dot(const Point &p) const;

    float operator[](int i) const;

    float &operator[](int i);

    Point operator+(const Point &p) const;

    Point operator-(const Point &p) const;

    Point operator*(const Point &p) const;

    Point operator-() const;

    Point operator*(float factor) const;

    // float operator*(Point factor) const;

    Point operator/(float divide) const;

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

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif //RAYTRACING_POINT_H
