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
    Matrix trans = Matrix::identiy();
    Matrix transInv = Matrix::identiy();
public:

    Entity() = default;

    Entity(Vector pos, Vector rot, Vector sca) {
        trans = Matrix();
        scaling(sca);
        rotate(rot);
        translate(pos);
    }

    ~Entity() = default;

    void translate(Vector transVec); // effectue une translation de vecteur (x,y,z)

    void rotateX(float deg); // effectue une rotation sur l'axe X, de deg radians

    void rotateY(float deg); // effectue une rotation sur l'axe Y, de deg radians

    void rotateZ(float deg); // effectue une rotation sur l'axe Z, de deg radians

    void rotate(Vector deg); // effectue une rotation sur tous les axes, de de radians

    void scaling(Vector factor); // effectue un redimensionnement de facteur factor

    Point localToGlobal(const Point &p) const;

    Vector localToGlobal(const Vector &v) const;

    Ray localToGlobal(const Ray &r) const;

    Point globalToLocal(const Point &p) const;

    Vector globalToLocal(const Vector &v) const;

    Ray globalToLocal(const Ray &r) const;

    Matrix getMatrix() const {
        return trans;
    }

    Vector position() {
        return Vector(trans(0, 3), trans(1, 3), trans(2, 3));
    }
};

std::ostream &operator<<(std::ostream &os, const Entity &v);

#endif //RAYTRACING_ENTITY_H
