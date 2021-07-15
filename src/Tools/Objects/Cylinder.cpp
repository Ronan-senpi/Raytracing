//
// Created by rdher on 15/07/2021.
//

#include "Cylinder.h"

bool Cylinder::intersect(const Ray &ray, Point &impact) const {
    return Object::intersect(ray, impact);
}
