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

    Object(Vector trans, Vector rot, Vector sca, std::string n, Material m) : name(std::move(n)), mat(m),
                                                                              Entity(trans, rot, sca) {}

    ~Object() = default;

    virtual Point getTextureCoordinates(const Point &p) const = 0;

    virtual Ray getNormal(const Point &p, const Point &o) = 0;

    virtual bool intersect(const Ray &ray, Point &impact) = 0;

    Material getMaterial(const Point &p) const;

    bool hasTexture() const {
        return mat.hasTexture();
    }

    void material(Material m) {
        mat = m;
    }
};


#endif //RAYTRACING_OBJECT_H
