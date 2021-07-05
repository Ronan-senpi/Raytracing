//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_POINT_H
#define RAYTRACING_POINT_H

#include <iostream>

class Point {
protected:
    float m_x,m_y,m_z;

public:

    Point(float x, float y, float z): m_x(x), m_y(y), m_z(z){}
    Point(const Point& p);

    virtual float dot(const Point& p) const;

    virtual float operator[](int i) const;
    Point operator+(const Point& p) const;
    Point operator-(Point& p);
    Point operator-() const;
    Point operator*(float factor) const;
    Point operator/(float divide) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif //RAYTRACING_POINT_H
