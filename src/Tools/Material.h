//
// Created by rdher on 15/07/2021.
//

#ifndef RAYTRACING_MATERIAL_H
#define RAYTRACING_MATERIAL_H

#include "Color.h"
#include "Ray.h"
#include "Point.h"
#include "Images/Image.h"

class Material {
private:
    Color ka, kd, ks;
    std::shared_ptr<Image> texture;
    float shininess;
public:

    Material() = default;

    Material(Color kam, Color kdiff, Color kspec, float shin) : ka(kam), kd(kdiff), ks(kspec), shininess(shin) {}

    Material(std::shared_ptr<Image> tex, Color kam, Color kdiff, Color kspec, float shin)
            : texture(tex), ka(kam), kd(kdiff), ks(kspec), shininess(shin) {}

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

    bool hasTexture() const {
        return texture != nullptr;
    }

    std::shared_ptr<Image> getTexture() const {
        return texture;
    }

    Color getTexture(const Point &coordinate) const {

        return (*texture)(1 - coordinate[1], coordinate[0]);
    }
};


#endif //RAYTRACING_MATERIAL_H
