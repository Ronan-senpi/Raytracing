//
// Created by rdher on 15/07/2021.
//

#include "Sphere.h"
#include "../Vector.h"

bool Sphere::intersect(const Ray &ray, Point &impact) {
    Ray r = globalToLocal(ray).normalized();


    float a = r.Direction().dot(r.Direction());
    float b = 2 * r.Direction().dot(r.Origin());
    float c = r.Origin().dot(r.Origin()) - 1.f;
    float delta = b * b - 4.f * a * c;

    if (delta < 0)
        return false;

    float t;
    if (delta < 0.0001f) {
        t = -b / (2.f * a);
    } else {
        t = (-b - sqrt(delta)) / (2.f * a);
        if (t < 0)
            t = (-b + sqrt(delta)) / (2.f * a);
    }
    if (t < 0.f)
        return false;

    Point p = r.Origin() + (r.Direction() * t);
    impact = localToGlobal(p);
    return true;
}

Ray Sphere::getNormal(const Point &p, const Point &o) {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
//    if (Vector(lo - Point(0.f, 0.f, 0.f)).norm() < 1.f)
//        return localToGlobal(Ray(lp, -lp)).normalized();
//    return localToGlobal(Ray(lp, lp)).normalized();

//    const Point i = this->globalToLocal(impact);
//    const Point p = this->globalToLocal(observator);
    const float distance = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];

    return Ray(o, (Vector(lo[0], lo[1], lo[2]) * (distance < 1.f ? -1.f : 1.f)).normalized());
}
