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

Vector& Vector::operator=(const Point &p) {
    this->m_x = p.X();
    this->m_y = p.Y();
    this->m_z = p.Z();
}
