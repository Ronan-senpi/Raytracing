//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_CUBE_H
#define RAYTRACING_CUBE_H

#include <utility>

#include "Object.h"

class Cube : public Object {
private:
    float interSide(const Ray &r, int dim, float offset) const;

public:
    Cube(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : Object(trans, rot, sca,
                                                                                                std::move(n), m) {}

    Cube(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : Object(trans, rot, sca, "cube",
                                                                                 std::move(m)) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Ray getNormal(const Point &p, const Point &o) override;

    Point getTextureCoordinates(const Point &p) const override;

};


#endif //RAYTRACING_CUBE_H
