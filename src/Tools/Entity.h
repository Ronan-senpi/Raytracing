//
// Created by rdher on 05/07/2021.
//

#ifndef RAYTRACING_ENTITY_H
#define RAYTRACING_ENTITY_H

#include "Vector.h"
#include "Ray.h"
#include "Matrix.h"
#include <iostream>

class Entity {
protected:
    Point _position = Vector(0, 0, 0);
    Vector _rotation = Vector(0, 0, 0);
    Vector _scale = Vector(1, 1, 1);
    Matrix _trans;
    Matrix _transInv;
public:

    Entity() = default;

    Entity(Point pos, Vector rot, Vector sca) : _position(pos), _rotation(rot), _scale(sca) {}

    ~Entity() = default;

    void translate(Vector transVec); // effectue une translation de vecteur (x,y,z)

    void rotateX(float deg); // effectue une rotation sur l'axe X, de deg radians

    void rotateY(float deg); // effectue une rotation sur l'axe Y, de deg radians

    void rotateZ(float deg); // effectue une rotation sur l'axe Z, de deg radians

    void rotate(Vector deg); // effectue une rotation sur tous les axes, de de radians

    void scale(float factor); // effectue un redimensionnement de facteur factor

    Point localToGlobal(const Point &p);

    Vector localToGlobal(const Vector &v);

    Ray localToGlobal(const Ray &r);

    Point globalToLocal(const Point &p);

    Vector globalToLocal(const Vector &v);

    Ray globalToLocal(const Ray &r);


    Vector position() const {
        return _position;
    }

    void position(Vector val) {
        _position = val;
    }

    Vector rotation() const {
        return _rotation;
    }

    void rotation(Vector val) {
        _rotation = val;
    }

    Vector scale() const {
        return _scale;
    }

    void scale(Vector val) {
        _scale = val;
    }
};

std::ostream &operator<<(std::ostream &os, const Entity &v);

#endif //RAYTRACING_ENTITY_H
