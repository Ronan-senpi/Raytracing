//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CYLINDER_H
#define RAYTRACING_CYLINDER_H

#include "Object.h"

class Cylinder : public Object {
public:
    Cylinder(Vector trans, Vector rot, Vector sca, std::string n, Material m) : Object(trans, rot, sca, n, m) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override { return {0, 0, 0}; }
};


#endif //RAYTRACING_CYLINDER_H
