//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CUBE_H
#define RAYTRACING_CUBE_H

#include "Object.h"

class Cube : public Object {
public:

    Cube(Vector trans, Vector rot, Vector sca, std::string n, Material m) : Object(trans, rot, sca, n, m) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    float interSide(const Ray &r, int dim, float offset) const;
};


#endif //RAYTRACING_CUBE_H
