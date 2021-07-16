//
// Created by rdher on 15/07/2021.
//

#include "Square.h"

bool Square::intersect(const Ray &ray, Point &impact) const {
    Ray lr = globalToLocal(ray);
    float vz = lr.Direction().Z();
    float oz = lr.Origin().Z();
    float t = -1 * (-oz / vz);
    if (t > 0) {
        Point p;
        p.X(lr.Origin().X() + lr.Direction().X() + t);
        p.Y(lr.Origin().Y() + lr.Direction().Y() + t);
        p.Z(lr.Origin().Z() + lr.Direction().Z() + t);
        if (p.X() <= 1 && p.X() >= -1 && p.Y() <= 1 && p.Y() >= -1) {
            impact = localToGlobal(impact);
            return true;
        } else
            return false;
    } else {
        return false;
    }
}
