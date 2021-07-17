//
// Created by rdher on 05/07/2021.
//

#include "Entity.h"

void Entity::translate(const Vector transVec) {
    Matrix m;
    m(0, 3) = transVec.X();
    m(1, 3) = transVec.Y();
    m(2, 3) = transVec.Z();
    _position = transVec;
    _trans = m * _trans;
    _transInv = _trans.inverse();
}

void Entity::rotateX(const float deg) {
    Matrix m;
    float c = cos(deg);
    float s = sin(deg);
    m(1, 1) = c;
    m(1, 2) = -s;
    m(2, 1) = s;
    m(2, 2) = c;
    _rotation.X(deg);
    _trans = m * _trans;
    _transInv = _trans.inverse();
}

void Entity::rotateY(const float deg) {
    Matrix m;
    float c = cos(deg);
    float s = sin(deg);
    m(0, 0) = c;
    m(0, 2) = s;
    m(2, 0) = -s;
    m(2, 2) = c;
    _rotation.Y(deg);
    _trans = m * _trans;
    _transInv = _trans.inverse();
}

void Entity::rotateZ(const float deg) {
    Matrix m;
    float c = cos(deg);
    float s = sin(deg);
    m(0, 0) = c;
    m(0, 1) = -s;
    m(1, 0) = s;
    m(1, 1) = c;
    _rotation.Z(deg);
    _trans = m * _trans;
    _transInv = _trans.inverse();
}

void Entity::scale(const Vector factor) {
    Matrix m;
    m(0, 0) = factor.X();
    m(1, 1) = factor.Y();
    m(2, 2) = factor.Z();
    _scale = factor;
    _trans = m * _trans;
    _transInv = _trans.inverse();
}

void Entity::rotate(const Vector deg) {
    rotateX(deg.X());
    rotateY(deg.Y());
    rotateZ(deg.Z());
}

Ray Entity::localToGlobal(const Ray &r) {
    return {localToGlobal(r.Origin()), localToGlobal(r.Direction())};
}

Ray Entity::globalToLocal(const Ray &r) {
    return {globalToLocal(r.Origin()), globalToLocal(r.Direction())};
}

Point Entity::localToGlobal(const Point &p) {
    return _transInv * p;
}

Vector Entity::localToGlobal(const Vector &v) {
    return _transInv * v;
}

Point Entity::globalToLocal(const Point &p) {
    return _trans * p;
}

Vector Entity::globalToLocal(const Vector &v) {
    return _trans * v;
}

std::ostream &operator<<(std::ostream &os, const Entity &e) {
    return os << "position : " << e.position() << " | Rotation : " << e.rotation() << " | Scale : " << e.scale();
}