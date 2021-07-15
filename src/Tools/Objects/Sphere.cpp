//
// Created by rdher on 15/07/2021.
//

#include "Sphere.h"

bool Sphere::intersect(const Ray &ray, Point &impact) const {
    return Object::intersect(ray, impact);
}
