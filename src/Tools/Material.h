//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "Color.h"
#include "Ray.h"
#include "Point.h"

class Object;

class Scene;

class Material {
private:
    Color ka, kd, ks;
    float shininess;
public:

    Material() = default;

    Material(Color kam, Color kdiff, Color kspec, float shin) : ka(kam), kd(kdiff), ks(kspec), shininess(shin) {}

    ~Material() = default;

    void Shininess(const float s) {
        shininess = s;
    }

    float Shininess() const {
        return shininess;
    }

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
