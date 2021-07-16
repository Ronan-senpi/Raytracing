//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "Color.h"
#include "Ray.h"
#include "Objects/Object.h"
#include "Point.h"
#include "Scene.h"

class Material {
private:
    Color ka, kd, ks;
    float shininess;
public:
    void Shininess(const float s) {
        shininess = s;
    }

    float Shininess() const {
        return shininess;
    }

    Color getImpactColor(const Ray &ray, const Object &obj, const Point &impact, const Scene &scene) const;

    void Ka(const Color c) {
        ka = c;
    }

    void Kd(const Color c) {
        kd = c;
    }

    void Ks(const Color c) {
        ks = c;
    }

    Color Ka() const {
        return ka;
    }

    Color Kd() const {
        return kd;
    }

    Color Ks() const {
        return ks;
    }

};


#endif //RAYTRACING_MATERIAL_H
