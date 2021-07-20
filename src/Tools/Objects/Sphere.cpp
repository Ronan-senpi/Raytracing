//
// Created by rdher on 15/07/2021.
//

#include "Sphere.h"
#include "../Vector.h"

bool Sphere::intersect(const Ray &ray, Point &impact) {
    Ray r = globalToLocal(ray).normalized();
    float a = r.Direction().dot(r.Direction());
    float b = 2 * r.Direction().dot(r.Origin());
    float c = r.Origin().dot(r.Origin()) - 1.0;
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

    Point p = r.Origin() + r.Direction() * t;
    impact = localToGlobal(p);
    return true;
}

Ray Sphere::getNormal(const Point &p, const Point &o) {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    if ((lo - Point(0, 0, 0)).norm() < 1)return localToGlobal(Ray(lp, -lp)).normalized();
    return localToGlobal(Ray(lp, lp)).normalized();
}
