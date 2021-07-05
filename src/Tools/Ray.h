//
// Created by Aedrinios on 05/07/2021.
//

#ifndef RAYTRACING_RAY_H
#define RAYTRACING_RAY_H

#include <iostream>
#include "Point.h"
#include "Vector.h"

class Ray {
private:
    Point m_origin;
    Vector m_direction;
public:
    Ray(float ox, float oy, float oz, float dx, float dy, float dz) : m_origin(ox, oy, oz), m_direction(dx,dy,dz){}
    Ray(Point origin, Vector direction) : m_origin(origin), m_direction(direction){}

    Point Origin()const{
        return m_origin;
    }
    void Origin(Point p){
        m_origin = p;
    }
    Vector Direction()const{
        return m_direction;
    }
    void Direction(Vector v){
        m_direction = v;
    }
};

std::ostream &operator<<(std::ostream &os, const Ray &r);

#endif //RAYTRACING_RAY_H
