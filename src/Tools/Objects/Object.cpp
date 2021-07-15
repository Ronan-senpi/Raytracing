//
// Created by rdher on 05/07/2021.
//

#include "Object.h"

Point Object::getTextureCoordinates(const Point &p) const {
    return Point(0, 0, 0);
}

Material Object::getMaterial(const Point &p) const {
    return Material();
}

Ray Object::getNormal(const Point &p, const Point &o) const {
    return Ray(0, 0, 0, 0, 0, 0);
}
