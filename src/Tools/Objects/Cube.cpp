//
// Created by rdher on 15/07/2021.
//

#include "Cube.h"

bool Cube::intersect(const Ray &ray, Point &impact) const {
    return Object::intersect(ray, impact);
}
