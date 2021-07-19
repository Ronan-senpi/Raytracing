//
// Created by Aedrinios on 18/07/2021.
//

#include "Camera.h"
#include "Images/Image.h"

Ray Camera::getRay(const float x, const float y) {
    Ray r(-1 + 2 * x, -1 + 2 * y, 0, 0, 0, 0);
    Point foc(0, 0, focal);
    r.Direction((r.Origin() - foc));
    r = localToGlobal(r);
    return r.normalized();
}

void Camera::screenshot(const std::vector<Object *> &objects, const std::string &filename,
                        const int h, const int w) {
    Image im(h, w, {0, 0.5, 0.5});
    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            Ray r = getRay(x, y);
            Point impact;
            Object *nearestObj = nullptr;
            for (Object *o : objects) {
                if (o->intersect(r, impact)) {
                    if (!nearestObj) {
                        nearestObj = o;
                    } else if (this->CloserThan(nearestObj->position(), o->position())) {
                        nearestObj = o;
                    }
                }
            }
            if (nearestObj) {
                Material m = nearestObj->getMaterial(impact);
                im(x, y, m.Ka());
            }
        }
    }
    im.write(filename);
}

bool Camera::CloserThan(const Point &oldPoint, const Point &newPoint) {
    return Vector(oldPoint - this->position()).norm() < Vector(newPoint - this->position()).norm();
}


