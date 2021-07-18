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
    Vector translation = Vector(0, 0, 0);
    Vector rotation = Vector(0, 0, 0);
    Vector scale = Vector(1, 1, 1);
    Matrix trans;
    Matrix transInv;
public:

    Entity() = default;

    Entity(Vector pos, Vector rot, Vector sca) /*: _position(pos), _rotation(rot), _scale(sca) */{
        trans = Matrix();
        translate(pos);
        rotate(rot);
        scaling(sca);
    }

    ~Entity() = default;

    void translate(Vector transVec); // effectue une translation de vecteur (x,y,z)

    void rotateX(float deg); // effectue une rotation sur l'axe X, de deg radians

    void rotateY(float deg); // effectue une rotation sur l'axe Y, de deg radians

    void rotateZ(float deg); // effectue une rotation sur l'axe Z, de deg radians

    void rotate(Vector deg); // effectue une rotation sur tous les axes, de de radians

    void scaling(Vector factor); // effectue un redimensionnement de facteur factor

    Point localToGlobal(const Point &p);

    Vector localToGlobal(const Vector &v);

    Ray localToGlobal(const Ray &r);

    Point globalToLocal(const Point &p);

    Vector globalToLocal(const Vector &v);

    Ray globalToLocal(const Ray &r);

    Vector position() const {
        return translation;
    }

    Vector getTranslation() {
        return translation;
    }

    Vector getRotation() const {
        return rotation;
    }

    Vector getScale() const {
        return scale;
    }
};

std::ostream &operator<<(std::ostream &os, const Entity &v);

#endif //RAYTRACING_ENTITY_H
