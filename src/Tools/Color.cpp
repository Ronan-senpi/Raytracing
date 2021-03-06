//
// Created by rdher on 06/07/2021.
//

#include "Color.h"
#include <stdexcept>

Color Color::operator*(const Color c) const {
    return Color(r * c.r, g * c.g, b * c.b);
}

Color Color::operator+(Color c) const {
    return Color(r + c.r, g + c.g, b + c.b);
}

float Color::operator[](const int i) const {
    if (i == 0)
        return this->r;

    if (i == 1)
        return this->g;

    if (i == 2)
        return this->b;
    else
        throw std::out_of_range("0, 1 or 2");
}

float &Color::operator[](int i) {
    if (i == 0)
        return this->r;

    if (i == 1)
        return this->g;

    if (i == 2)
        return this->b;
    else
        throw std::out_of_range("0, 1 or 2");
}

Color Color::operator*(float factor) const {
    return Color(r * factor, g * factor, b * factor);
}

Color &Color::operator+=(Color c) {
    this->r = std::clamp(r + c[0], 0.f, 1.0f);
    this->g = std::clamp(g + c[1], 0.0f, 1.0f);
    this->b = std::clamp(b + c[2], 0.0f, 1.0f);
    return *this;
}

void Color::addNoClamp(Color c) {
    this->r += c[0];
    this->g += c[1];
    this->b += c[2];
}

Color &Color::operator/=(float f) {
    this->r = std::clamp(r / f, 0.f, 1.0f);
    this->g = std::clamp(g / f, 0.0f, 1.0f);
    this->b = std::clamp(b / f, 0.0f, 1.0f);
    return *this;
}



