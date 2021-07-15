//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    bool intersect(const Ray &ray, Point &impact) const override;
};


#endif //RAYTRACING_SPHERE_H
