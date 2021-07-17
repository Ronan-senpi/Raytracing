//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CUBE_H
#define RAYTRACING_CUBE_H

#include "Object.h"

class Cube : public Object {
public:
    bool intersect(const Ray &ray, Point &impact)  override;

    Ray getNormal(const Point &p, const Point &o)  override;
};


#endif //RAYTRACING_CUBE_H
