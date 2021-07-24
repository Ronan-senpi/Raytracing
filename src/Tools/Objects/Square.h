//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_SQUARE_H
#define RAYTRACING_SQUARE_H

#include "Plan.h"
#include "../Point.h"

class Square : public Plan {
public:
    Square(Vector trans, Vector rot, Vector sca, std::string n, Material m) : Plan(trans, rot, sca, n, m) {}

    Square(Vector trans, Vector rot, Vector sca, Material m) : Plan(trans, rot, sca, "square", m) {}

    bool intersect(const Ray &ray, Point &impact) override;

    Point getTextureCoordinates(const Point &p) const override;
};


#endif //RAYTRACING_SQUARE_H!g hu
