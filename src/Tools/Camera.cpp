//
// Created by Aedrinios on 18/07/2021.
//

#include "Camera.h"

Camera::Camera(float f) : focal(f) {}

Ray Camera::getRay(const float x, const float y) {
    Ray r(-1 + 2 * x, -1 + 2 * y, 0, 0, 0, 0);
    Point foc(0, 0, focal);
    r.Direction() = (r.Origin() - foc);
    r = localToGlobal(r);
    return r.normalized();
}


