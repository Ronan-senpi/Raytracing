//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_VECTOR_H
#define RAYTRACING_VECTOR_H


class Vector {
private:
    float m_x, m_y, m_z;

public:

    Vector(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {}

    float norm();

    Vector normalized();

    float dot(Vector v);

    float operator[](const int i) const;

    Vector operator+(Vector v);

    Vector operator-(Vector v);

    Vector operator*(int factor);

    Vector operator/(int divide);

    float X() const {
        return m_x;
    }

    void X(float val) {
        m_x = val;
    }

    float Y() const {
        return m_y;
    }

    void Y(float val) {
        m_y = val;
    }

    float Z() const {
        return m_z;
    }

    void Z(float val) {
        m_z = val;
    }
};


#endif //RAYTRACING_VECTOR_H
