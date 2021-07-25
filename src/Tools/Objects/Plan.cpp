//
// Created by rdher on 15/07/2021.
//

#include "Plan.h"

bool Plan::intersect(const Ray &ray, Point &impact) const {
    Ray lr = globalToLocal(ray);
    float vz = lr.Direction().Z();
    float oz = lr.Origin().Z();
    float t = -oz / vz;
    if (t > 0) {
        impact.X(lr.Origin().X() + lr.Direction().X() + t);
        impact.Y(lr.Origin().Y() + lr.Direction().Y() + t);
        impact.Z(lr.Origin().Z() + lr.Direction().Z() + t);

        impact = localToGlobal(impact);
        return true;
    } else {
        return false;
    }
}

Ray Plan::getNormal(const Point &p, const Point &o) const {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    float z = 1;
    if (lo[2] < 0)z = -1;
    return localToGlobal(Ray(lp, Vector(0, 0, z))).normalized();
}

Point Plan::getTextureCoordinates(const Point &p) const {
    Point lp = globalToLocal(p);
    float x = lp.X() - (int) lp.X();
    float y = lp.Y() - (int) lp.Y();

    if (x < 0)
        x += 1;
    if (y < 0)
        y += 1;

    return Point(x, y, 0);
}
