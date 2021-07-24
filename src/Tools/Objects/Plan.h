//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_PLAN_H
#define RAYTRACING_PLAN_H

#include <utility>

#include "Object.h"

class Plan : public Object {
public:
    Plan(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca,
                                                                                                std::move(n), m) {}

    Plan(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "plan",
                                                                                 std::move(m)) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override;
};


#endif //RAYTRACING_PLAN_H