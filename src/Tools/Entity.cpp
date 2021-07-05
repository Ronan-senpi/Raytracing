//
// Created by rdher on 05/07/2021.
//

#include "Entity.h"

void Entity::translate(const Vector transVec) {
    _position = _position + transVec;
}

void Entity::rotateX(const float deg) {
    _rotation.X(_rotation.X() + deg);
}

void Entity::rotateY(const float deg) {
    _rotation.Y(_rotation.Y() + deg);
}

void Entity::rotateZ(const float deg) {
    _rotation.Z(_rotation.Z() + deg);
}

void Entity::scale(const float factor) {
    _scale = _scale * factor;
}

void Entity::rotate(const Vector deg) {
    _rotation = _rotation + deg;
}

std::ostream &operator<<(std::ostream &os, const Entity &e) {
    return os << "position : " << e.position() << " | Rotation : " << e.rotation() << " | Scale : " << e.scale();
}