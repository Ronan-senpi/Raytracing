//
// Created by Aedrinios on 18/07/2021.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include <string>
#include <vector>
#include "Entity.h"
#include "Ray.h"
#include "Objects/Object.h"

class Camera : public Entity {
private:
    float focal = 5;

    bool CloserThan(const Point &oldPoint, const Point &newPoint);

public:
    Camera() = default;

    Camera(float foc) : focal(foc), Entity() {}

    Camera(float foc, const Point pos, const Vector &rot, const Vector &sca) : focal(foc), Entity(pos, rot, sca) {}

    ~Camera() = default;

    Ray getRay(float x, float y);

    void screenshot(const std::vector<Object *> &objects, const std::string &filename, int h, int w);
};


#endif //RAYTRACING_CAMERA_H
