//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include <iostream>
#include "Point.h"
#include "Vector.h"

class Ray {
private:
    Point origin;
    Vector direction;
public:
    Ray(float ox, float oy, float oz, float dx, float dy, float dz) : origin(ox, oy, oz), direction(dx, dy, dz) {}

    Ray(Point origin, Vector direction) : origin(origin), direction(direction) {}

    Point Origin() const {
        return origin;
    }

    void Origin(Point p) {
        origin = p;
    }

    Vector Direction() const {
        return direction;
    }

    void Direction(Vector v) {
        direction = v;
    }

    Ray normalized();
};

std::ostream &operator<<(std::ostream &os, const Ray &r);

#endif //RAYTRACING_RAY_H
