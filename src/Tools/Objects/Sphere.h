//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include "Object.h"

class Sphere : public Object {
public:
    Sphere(Vector trans, Vector rot, Vector sca, std::string n, Material m) : Object(trans, rot, sca, n, m) {}

    Sphere(Vector trans, Vector rot, Vector sca, Material m) : Object(trans, rot, sca, m) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override;
};


#endif //RAYTRACING_SPHERE_H
