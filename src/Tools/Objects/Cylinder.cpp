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

Ray Cylinder::getNormal(const Point &p, const Point &o) {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    if (Vector((lo - Point(0, lo[1], 0))).norm() > 1)
        return localToGlobal(Ray(lp, Vector(lp[0], 0, lp[2]))).normalized();
    return localToGlobal(Ray(lp, Vector(-lp[0], 0, -lp[2]))).normalized();

}
