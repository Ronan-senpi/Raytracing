//
// Created by rdher on 05/07/2021.
//

#include "Entity.h"

void Entity::translate(const Vector transVec) {
    Matrix m;
    m(0, 3) = transVec.X();
    m(1, 3) = transVec.Y();
    m(2, 3) = transVec.Z();
    translation = transVec;
    trans = m * trans;
    transInv = trans.inverse();
}

void Entity::rotateX(const float deg) {
    Matrix m;
    float c = cos(deg);
    float s = sin(deg);
    m(1, 1) = c;
    m(1, 2) = -s;
    m(2, 1) = s;
    m(2, 2) = c;
    trans = m * trans;
    transInv = trans.inverse();
}

void Entity::rotateY(const float deg) {
    Matrix m;
    float c = cos(deg);
    float s = sin(deg);
    m(0, 0) = c;
    m(0, 2) = s;
    m(2, 0) = -s;
    m(2, 2) = c;
    trans = m * trans;
    transInv = trans.inverse();
}

void Entity::rotateZ(const float deg) {
    Matrix m;
    float c = cos(deg);
    float s = sin(deg);
    m(0, 0) = c;
    m(0, 1) = -s;
    m(1, 0) = s;
    m(1, 1) = c;
    trans = m * trans;
    transInv = trans.inverse();
}

void Entity::scaling(Vector factor) {
    Matrix m;
    m(0, 0) = factor.X();
    m(1, 1) = factor.Y();
    m(2, 2) = factor.Z();
    scale = factor;
    trans = m * trans;
    transInv = trans.inverse();
}

void Entity::rotate(const Vector deg) {
    rotateX(deg.X());
    rotateY(deg.Y());
    rotateZ(deg.Z());
}

Ray Entity::localToGlobal(const Ray &r) const {
    Point origin = localToGlobal(r.Origin());
    Vector direction = localToGlobal(r.Direction());
    return Ray(origin, direction);
}

Ray Entity::globalToLocal(const Ray &r) const {
    Point origin = globalToLocal(r.Origin());
    Vector direction = globalToLocal(r.Direction());
    return Ray(origin, direction);
}

Point Entity::localToGlobal(const Point &p) const {
    return trans * p;
}

Vector Entity::localToGlobal(const Vector &v) const {
    return trans * v;
}

Point Entity::globalToLocal(const Point &p) const {
    return transInv * p;
}

Vector Entity::globalToLocal(const Vector &v) const {
    return transInv * v;
}

std::ostream &operator<<(std::ostream &os, const Entity &e) {
    return os << "Transformation matrix : " << e.getMatrix() << std::endl;
}