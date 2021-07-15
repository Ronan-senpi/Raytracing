//
// Created by rdher on 15/07/2021.
//

#include "Plan.h"

bool Plan::intersect(const Ray &ray, Point &impact) const {
    return Object::intersect(ray, impact);
}
