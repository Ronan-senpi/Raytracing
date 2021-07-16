//
// Created by rdher on 06/07/2021.
//

#include "Color.h"
#include <stdexcept>

Color Color::operator*(const Color c) const {
    return Color(r * c.r, g * c.g, b * c.g);
}

Color Color::operator+(Color c) const {
    return Color(r + c.r, g + c.g, b + c.g);
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

Color Color::operator*(float factor) const {
    return Color(r * factor, g * factor, b * factor);
}

