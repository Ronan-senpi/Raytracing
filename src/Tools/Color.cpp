//
// Created by rdher on 06/07/2021.
//

#include "Color.h"

Color Color::operator*(const Color c) const {
    return Color(r*c.r, g*c.g, b*c.g);
}

float Color::operator[](const int i) const {
    if (i == 0)
        return this->r;

    if (i == 1)
        return this->g;

    if (i == 2)
        return this->b;
    else
        throw "out of range";
}
