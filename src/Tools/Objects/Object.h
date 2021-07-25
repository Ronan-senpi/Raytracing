//
// Created by rdher on 05/07/2021.
//

#ifndef RAYTRACING_OBJECT_H
#define RAYTRACING_OBJECT_H

#include <string>
#include <utility>
#include <vector>
#include "../Entity.h"
#include "../Point.h"
#include "../Material.h"
#include "../Ray.h"


class Object : public Entity {
private:
    std::string name;
    std::vector<Material> mats;
    int nbImpact;
public:
    Object() = default;

    Object(Vector trans, Vector rot, Vector sca, std::string n, std::vector<Material> m) : name(std::move(n)),
                                                                                           mats(std::move(m)),
                                                                                           Entity(trans, rot, sca) {}

    Object(Vector trans, Vector rot, Vector sca, std::vector<Material> m) : mats(std::move(m)),
                                                                            Entity(trans, rot, sca) {}

    ~Object() = default;

    virtual Point getTextureCoordinates(const Point &p) const = 0;

    virtual Ray getNormal(const Point &p, const Point &o) const = 0;

    virtual bool intersect(const Ray &ray, Point &impact) const = 0;

    Material getMaterial(const Point &p) const;

    bool hasTexture(int id) const {
        return mats[id].hasTexture();
    }

    int nbMat() const {
        return mats.size();
    }

    void material(Material m) {
        mats.push_back(m);
    }

    std::string getName() const {
        return name;
    }
};


#endif //RAYTRACING_OBJECT_H
