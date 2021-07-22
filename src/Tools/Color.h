//
// Created by rdher on 06/07/2021.
//

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include <algorithm>
#include <iostream>

#include "Point.h"
#include "Helpers/Serializer.h"

class Color {
private:
    float r, g, b;
public:
    Color() = default;

    Color(const Color &c) = default;

    Color(const Point &p) {
        this->r = std::clamp(p[0], 0.f, 1.0f);
        this->g = std::clamp(p[1], 0.0f, 1.0f);
        this->b = std::clamp(p[2], 0.0f, 1.0f);

    }

    Color(float red, float green, float blue) {
//        this->r = std::clamp(red, 0.0f, 1.0f);
//        this->g = std::clamp(green, 0.0f, 1.0f);
//        this->b = std::clamp(blue, 0.0f, 1.0f);

        this->r = std::clamp(red, 0.f, 1.0f);
        this->g = std::clamp(green, 0.0f, 1.0f);
        this->b = std::clamp(blue, 0.0f, 1.0f);
//        std::cout << "raw (" << red << "," << green << "," << blue << ")" << std::endl;
//        std::cout << "serialize (" << this->r << "," << this->g << "," << this->b << ")" << std::endl;
    }

    ~Color() = default;

    float operator[](int i) const;

    float &operator[](int i);

    Color operator*(Color c) const;

    Color operator+(Color c) const;

    Color operator*(float factor) const;

    Color &operator+=(Color c);

    void A(float val) const {

    }

    float A() const {
        return 1.f;
    }

};


#endif //RAYTRACING_COLOR_H
