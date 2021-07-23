//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CUBE_H
#define RAYTRACING_CUBE_H

#include "Object.h"

class Cube : public Object {
private:
    float interSide(const Ray &r, int dim, float offset) const;

public:
    Cube(Vector trans, Vector rot, Vector sca, std::string n, Material m) : Object(trans, rot, sca, n, m) {}

    Cube(Vector trans, Vector rot, Vector sca, Material m) : Object(trans, rot, sca, m) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override;

};


#endif //RAYTRACING_CUBE_H
