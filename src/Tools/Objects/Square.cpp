//
// Created by rdher on 15/07/2021.
//

#include "Square.h"

bool Square::intersect(const Ray &ray, Point &impact) {
    Ray lr = globalToLocal(ray).normalized();
    if (lr.Direction()[2] < 0.0001 && lr.Direction()[2] > -0.0001)return false;
    if (lr.Direction()[2] * lr.Origin()[2] > 0)return false;
    float t = -lr.Origin()[2] / lr.Direction()[2];
    Point p = lr.Origin() + (lr.Direction() * t);
    if (p[0] < -1 || p[0] > 1 || p[1] < -1 || p[1] > 1)return false;
    impact = localToGlobal(p);
    return true;
}
