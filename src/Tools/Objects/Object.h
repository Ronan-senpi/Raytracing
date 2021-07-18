//
// Created by rdher on 05/07/2021.
//

#ifndef RAYTRACING_OBJECT_H
#define RAYTRACING_OBJECT_H

#include <string>
#include <utility>
#include "../Entity.h"
#include "../Point.h"
#include "../Material.h"
#include "../Ray.h"

class Object : public Entity {
private:
    std::string name;
    Material mat;
public:
    Object() = default;

    Object(std::string n, Material m) : name(std::move(n)), mat(m) {}

    ~Object() = default;

    Point getTextureCoordinates(const Point &p) const;

    Material getMaterial(const Point &p) const;

    virtual Ray getNormal(const Point &p, const Point &o);

    virtual bool intersect(const Ray &ray, Point &impact) { return false; };

    Material material() const {
        return mat;
    }

    void material(Material m) {
        mat = m;
    }
};


#endif //RAYTRACING_OBJECT_H
