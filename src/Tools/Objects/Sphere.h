//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_SPHERE_H
#define RAYTRACING_SPHERE_H

#include <utility>

#include "Object.h"

class Sphere : public Object {
public:
    Sphere(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca,
                                                                                                  std::move(n),
                                                                                                  std::move(m)) {}

    Sphere(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "sphere",
                                                                                   std::move(m)) {}

    bool intersect(const Ray &ray, Point &impact) const override;

    Ray getNormal(const Point &p, const Point &o) const override;

    Point getTextureCoordinates(const Point &p) const override;
};


#endif //RAYTRACING_SPHERE_H
