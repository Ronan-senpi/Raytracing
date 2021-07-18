//
// Created by rdher on 15/07/2021.
//

#include "Cylinder.h"

bool Cylinder::intersect(const Ray &ray, Point &impact) {
    Ray r = globalToLocal(ray).normalized();

    float a = r.Direction()[0] * r.Direction()[0] + r.Direction()[2] * r.Direction()[2];
    float b = 2 * (r.Direction()[0] * r.Origin()[0] + r.Direction()[2] * r.Origin()[2]);
    float c = r.Origin()[0] * r.Origin()[0] + r.Origin()[2] * r.Origin()[2] - 1.0;
    float delta = b * b - 4 * a * c;

    if (delta < 0)return false;

    float t;
    if (delta < 0.0001) {
        t = -b / (2 * a);
    } else {
        t = (-b - sqrt(delta)) / (2 * a);
        if (t < 0)t = (-b + sqrt(delta)) / (2 * a);
    }
    if (t < 0)return false;

    Point p = r.Origin() + (r.Direction() * t);
    impact = localToGlobal(p);
    return true;
}
