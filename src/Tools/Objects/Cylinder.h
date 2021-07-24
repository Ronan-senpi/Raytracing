//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CYLINDER_H
#define RAYTRACING_CYLINDER_H

#include "Object.h"
#include <vector>

class Cylinder : public Object {
public:
    Cylinder(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca, n,
                                                                                                    std::move(m)) {}

    Cylinder(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "cube",
                                                                                     std::move(m)) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override { return {0, 0, 0}; }
};


#endif //RAYTRACING_CYLINDER_H
