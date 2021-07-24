//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_PLAN_H
#define RAYTRACING_PLAN_H

#include "Object.h"

class Plan : public Object {
public:
    Plan(Vector trans, Vector rot, Vector sca, std::string n, Material m) : Object(trans, rot, sca, n, m) {}

    Plan(Vector trans, Vector rot, Vector sca, Material m) : Object(trans, rot, sca, "plan", m) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override;
};


#endif //RAYTRACING_PLAN_H