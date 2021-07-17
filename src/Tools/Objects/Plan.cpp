//
// Created by rdher on 15/07/2021.
//

#include "Plan.h"

bool Plan::intersect(const Ray &ray, Point &impact) {
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

Ray Plan::getNormal(const Point &p, const Point &o)  {
    Vector dir(0, 0, 0);
    Point oo = globalToLocal(o);
    Point i = globalToLocal(p);
    if (oo.Y() < 1) {
        dir.Y(-1);
    } else {
        dir.Y(1);
    }
    Ray r(i, dir);
    return localToGlobal(r);
}
