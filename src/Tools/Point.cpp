//
// Created by Aedrinios on 05/07/2021.
//

#include "Point.h"

float Point::dot(const Point &p) const {
    return this->m_x * p.m_x + this->m_y * p.m_y + this->m_z * p.m_z;
}

float Point::operator[](const int i) const {
    if (i == 0)
        return m_x;

    if (i == 1)
        return m_y;

    if (i == 2)
        return m_z;
    else
        throw std::out_of_range("0, 1 or 2");
}

float Point::norm() const {
    return sqrt(pow(this->m_x, 2) + pow(this->m_y, 2) + pow(this->m_z, 2));
}


float &Point::operator[](const int i) {
    if (i == 0)
        return m_x;

    if (i == 1)
        return m_y;

    if (i == 2)
        return m_z;
    else
        throw std::out_of_range("0, 1 or 2");
}

Point Point::operator+(const Point &p) const {
    return {this->m_x + p.m_x, this->m_y + p.m_y, this->m_z + p.m_z};
}

Point Point::operator*(const Point &p) const {
    return {this->m_x * p.m_x, this->m_y * p.m_y, this->m_z * p.m_z};
}

Point Point::operator-(const Point &p) const {
    return (*this) + (-p);
}

Point Point::operator-() const {
    return {-this->m_x, -this->m_y, -this->m_z};
}

Point Point::operator*(const float factor) const {
    return {this->m_x * factor, this->m_y * factor, this->m_z * factor};
}

Point Point::operator/(float divide) const {
    return {this->m_x / divide, this->m_y / divide, this->m_z / divide};
}


std::ostream &operator<<(std::ostream &os, const Point &p) {
    return os << "(" << p[0] << ", " << p[1] << ", " << p[2] << ")";
}