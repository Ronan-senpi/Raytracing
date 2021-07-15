//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CYLINDER_H
#define RAYTRACING_CYLINDER_H

#include "Object.h"

class Cylinder : public Object {
public:
    bool intersect(const Ray &ray, Point &impact) const override;
};


#endif //RAYTRACING_CYLINDER_H
