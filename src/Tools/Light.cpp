//
// Created by rdher on 06/07/2021.
//

#include "Light.h"

Ray Light::getRayToLight(const Point &p) const {
    return {p,getVectorToLight(p)};
}

Ray Light::getRayFromLight(const Point &p) const {
    return {translation, getVectorFromLight(p)};
}

Vector Light::getVectorToLight(const Point &p) const {
    return Vector(p - translation).normalized();
}

Vector Light::getVectorFromLight(const Point &p) const {
    return Vector(translation - p).normalized();
}
