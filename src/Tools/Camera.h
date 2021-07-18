//
// Created by Aedrinios on 18/07/2021.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "Entity.h"
#include "Ray.h"

class Camera : public Entity {
private:
    float focal{};
public:
    Camera() = default;

    Camera(float f);

    Ray getRay(float x, float y);
};


#endif //RAYTRACING_CAMERA_H
