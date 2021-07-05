//
// Created by Aedrinios on 05/07/2021.
//

#include "Vector.h"
#include <cmath>

float Vector::norm() const {
    return sqrtf(pow(this->m_x, 2) + pow(this->m_y, 2) + pow(this->m_z, 2));
}

Vector Vector::normalized() const {
    float magnitude = this->norm();
    return {this->m_x / magnitude, this->m_x / magnitude, this->m_x / magnitude};
}

Vector Vector::operator=(const Point &p) {
    return Vector(p.m_x, p.m_y, p.m_z);
}
