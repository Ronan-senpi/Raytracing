//
// Created by rdher on 15/07/2021.
//

#include "Cube.h"

bool Cube::intersect(const Ray &ray, Point &impact) const {
    Ray r = globalToLocal(ray);
    float tmin = (-1 - r.Origin().X()) / r.Direction().X();
    float tmax = (1 - r.Origin().X()) / r.Direction().X();

    if (tmin > tmax) std::swap(tmin, tmax);

    float tymin = (-1 - r.Origin().Y() / r.Direction().Y());
    float tymax = (1 - r.Origin().Y() / r.Direction().Y());

    if (tymin > tymax) std::swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (-1 - r.Origin().Y() / r.Direction().Y());
    float tzmax = (1 - r.Origin().Y() / r.Direction().Y());

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    Point p;
    p.X(r.Origin().X() + r.Direction().X() * tmin);
    p.Y(r.Origin().Y() + r.Direction().Y() * tmin);
    p.Z(r.Origin().Z() + r.Direction().Z() * tmin);
    impact = localToGlobal(p);

    return true;
}

Ray Cube::getNormal(const Point &p, const Point &o) const {
    Vector dir(0, 0, 0);
    Point oo = globalToLocal(o);
    Point i = globalToLocal(p);

    if (abs(i.X() + 1) < 0.001)
        dir.X(-1);
    if (abs(i.X() - 1) < 0.001)
        dir.X(1);
    if (abs(i.Y() + 1) < 0.001)
        dir.Y(-1);
    if (abs(i.Y() - 1) < 0.001)
        dir.Y(1);
    if (abs(i.Z() + 1) < 0.001)
        dir.Z(-1);
    if (abs(i.Z() - 1) < 0.001)
        dir.Z(1);

    if (oo.X() < 1 && oo.X() > -1 &&
        oo.Y() < 1 && oo.Y() > -1 &&
        oo.Z() < 1 && oo.Z() > -1) {
        dir = -dir;
    }

    dir = localToGlobal(dir);
    dir = dir.normalized();
    Ray r(p, dir);
    return r;
}
