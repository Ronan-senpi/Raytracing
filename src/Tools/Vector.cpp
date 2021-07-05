//
// Created by Aedrinios on 05/07/2021.
//

#include "Vector.h"
#include <cmath>

Vector::Vector(const Vector &v) {
    this->m_x = v.m_x;
    this->m_y = v.m_y;
    this->m_z = v.m_z;
}

float Vector::norm() const {
    return sqrtf(pow(this->m_x, 2) + pow(this->m_y, 2) + pow(this->m_z, 2));
}

Vector Vector::normalized() const {
    float magnitude = this->norm();
    return {this->m_x / magnitude, this->m_x / magnitude, this->m_x / magnitude};
}

float Vector::dot(const Vector &v) const {
    return this->m_x * v.m_x + this->m_y * v.m_y + this->m_z * v.m_z;
}

float Vector::operator[](const int i) const {
    if (i == 0)
        return this->m_x;

    if (i == 1)
        return this->m_y;

    if (i == 2)
        return this->m_z;
    else
        throw "out of range";
}

Vector Vector::operator+(const Vector &v) const {
    return {this->m_x + v.m_x, this->m_y + v.m_y, this->m_z + v.m_z};
}

Vector Vector::operator-(Vector &v) {
    return (*this) + (-v);
}

Vector Vector::operator-() const {
    return {-this->m_x, -this->m_y, -this->m_z};
}

Vector Vector::operator*(const float factor) const {
    return {this->m_x * factor, this->m_y * factor, this->m_z * factor};
}

Vector Vector::operator/(float divide) const {
    return {this->m_x / divide, this->m_y / divide, this->m_z / divide};
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    return os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
}