//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_VECTOR_H
#define RAYTRACING_VECTOR_H
#include <iostream>

class Vector {
private:
    float m_x,m_y,m_z;

public:

    Vector(float x, float y, float z): m_x(x), m_y(y), m_z(z){}
    Vector(const Vector& v);

    float norm() const;
    Vector normalized() const;
    float dot(const Vector& v) const;

    float operator[](int i) const;
    Vector operator+(const Vector& v) const;
    Vector operator-(Vector& v);
    Vector operator-() const;
    Vector operator*(float factor) const;
    Vector operator/(float divide) const;
};

std::ostream& operator<<(std::ostream& os, const Vector& v);

#endif //RAYTRACING_VECTOR_H
