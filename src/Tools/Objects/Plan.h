//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_PLAN_H
#define RAYTRACING_PLAN_H

#include "Object.h"

class Plan : public Object {
public:
    bool intersect(const Ray &ray, Point &impact) const override
};


#endif //RAYTRACING_PLAN_H
