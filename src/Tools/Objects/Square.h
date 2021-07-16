//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_SQUARE_H
#define RAYTRACING_SQUARE_H

#include "Plan.h"
#include "../Point.h"

class Square : public Plan {
    bool intersect(const Ray &ray, Point &impact) const override;
};


#endif //RAYTRACING_SQUARE_H
