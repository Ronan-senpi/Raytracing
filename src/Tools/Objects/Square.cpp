//
// Created by rdher on 15/07/2021.
//

#include "Square.h"

bool Square::intersect(const Ray &ray, Point &impact) const {
    return Plan::intersect(ray, impact);
}
