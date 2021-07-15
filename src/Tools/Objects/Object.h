//
// Created by rdher on 05/07/2021.
//

#ifndef RAYTRACING_OBJECT_H
#define RAYTRACING_OBJECT_H

#include "../Entity.h"
#include "../Point.h"
#include "../Material.h"
#include "../Ray.h"

class Object : public Entity {
public:
    Point getTextureCoordinates(const Point &p) const;

    Material getMaterial(const Point &p) const;

    Ray getNormal(const Point &p, const Point &o) const;

    virtual bool intersect(const Ray &ray, Point &impact) const { return false; };
};


#endif //RAYTRACING_OBJECT_H
