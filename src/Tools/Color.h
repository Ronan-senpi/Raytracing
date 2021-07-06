//
// Created by rdher on 06/07/2021.
//

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H


class Color {
private:
    float r,g,b;
public:
    Color() = default;
    Color(const Color& c)= default;
    Color(float r, float g, float b): r(r), g(g),b(b){}
    ~Color() = default;

    float operator[](int i) const;
    Color operator*(Color c) const;

    float R() const {
        return r;
    }

    void R(float val) {
        r = val;
    }

    float G() const {
        return g;
    }

    void G(float val) {
        g = val;
    }

    float B() const {
        return b;
    }

    void B(float val) {
        b = val;
    }
};


#endif //RAYTRACING_COLOR_H
