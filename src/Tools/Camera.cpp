//
// Created by Aedrinios on 18/07/2021.
//

#include "Camera.h"
#include "Images/Image.h"
#include "Helpers/Serializer.h"

Ray Camera::getRay(const float x, const float y) {
    Vector direction(-1 + 2 * x, -1 + 2 * y, -focal);
    Ray r(Point(0, 0, 0), direction.normalized());
    return localToGlobal(r);
}

void Camera::screenshot(const std::vector<Object *> &objects, const std::string &filename,
                        const int w, const int h) {
    Image im(w, h, {0, 0.5, 0.5});
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            Ray r = getRay(Serializer::serialize(x, 0, w - 1), Serializer::serialize(y, 0, h - 1));
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
                Ray normal = nearestObj->getNormal(impact, r.Origin());
                Point p = nearestObj->globalToLocal(impact);
                Color pixel(normal.Direction().X(), normal.Direction().Y(), normal.Direction().Z());
//                Color pixel(normal.Direction()[0], normal.Direction()[1], normal.Direction()[2]);
                im(x, y, pixel);
            }
        }
    }
    im.write(filename);
}

bool Camera::CloserThan(const Point &oldPoint, const Point &newPoint) {
    return Vector(oldPoint - this->position()).norm() < Vector(newPoint - this->position()).norm();
}


