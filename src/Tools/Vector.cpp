//
// Created by Aedrinios on 05/07/2021.
//

#include "Vector.h"
#include <cmath>

float Vector::norm() const {
    return sqrt(pow(this->m_x, 2) + pow(this->m_y, 2) + pow(this->m_z, 2));
}

Vector Vector::normalized() const {
    float magnitude = this->norm();
    return {this->m_x / magnitude, this->m_y / magnitude, this->m_z / magnitude};
}

std::ostream &operator<<(std::ostream &os, const Vector &v) {
    return os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
}