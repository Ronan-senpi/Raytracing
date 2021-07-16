//
// Created by rdher on 15/07/2021.
//

#include "Sphere.h"
#include "../Vector.h"

bool Sphere::intersect(const Ray &ray, Point &impact) const {
    Ray r = globalToLocal(ray);

    float a = (r.Direction().X() * r.Direction().X())
              + (r.Direction().Y() * r.Direction().Y())
              + (r.Direction().Z() * r.Direction().Z());

    float b = 2 * (r.Direction().X() * r.Origin().X()
                   + r.Direction().Y() * r.Origin().Y()
                   + r.Direction().Z() * r.Origin().Z());

    float c = (r.Origin().X() * r.Origin().X())
              + (r.Origin().Y() * r.Origin().Y())
              + (r.Origin().Z() * r.Origin().Z()) - 1;

    float delta = (b * b) - 4 * a * c;

    if (delta < 0) {
        return false;
    }
    if (delta == 0) {
        float t = -b / (2 * a);
        Point p;
        p.X(r.Origin().X() + r.Direction().X() * t);
        p.Y(r.Origin().Y() + r.Direction().Y() * t);
        p.Z(r.Origin().Z() + r.Direction().Z() * t);
        impact = localToGlobal(p);
        return true;
    }
    float t1 = (-b - sqrt(delta)) / (2 * a);
    float t2 = (-b + sqrt(delta)) / (2 * a);

    if (t1 > 0) {
        Point p;
        p.X(r.Origin().X() + r.Direction().X() * t1);
        p.Y(r.Origin().Y() + r.Direction().Y() * t1);
        p.Z(r.Origin().Z() + r.Direction().Z() * t1);
        impact = localToGlobal(p);
        return true;
    }

    if (t2 > 0) {
        Point p;
        p.X(r.Origin().X() + r.Direction().X() * t2);
        p.Y(r.Origin().Y() + r.Direction().Y() * t2);
        p.Z(r.Origin().Z() + r.Direction().Z() * t2);
        impact = localToGlobal(p);
        return true;
    }
    return false;
}

Ray Sphere::getNormal(const Point &p, const Point &o) const {
    Point oo = globalToLocal(o);
    Point i = globalToLocal(p);

    float d = sqrt(o.X() * o.X() + o.Y() * o.Y() + o.Z() * o.Z());

    Vector v;
    if (d < 1) {
        v = i * -1;
    } else {
        v = i;
    }
    Ray ray(p, v.normalized());
    return ray;
}
