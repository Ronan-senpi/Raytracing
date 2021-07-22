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
#include "Scene.h"

class Camera : public Entity {
private:
    float focal;
    Scene scene;

    bool CloserThan(const Point &oldImpact, const Point &newImpact) const;

public:
    Camera() = default;

    Camera(float foc, Scene s) : focal(foc), scene(s), Entity() {}

    Camera(float foc, const Point pos, const Vector &rot, const Vector &sca) : focal(foc), Entity(pos, rot, sca) {}

    ~Camera() = default;

    Ray getRay(float x, float y);

    void screenshot(const std::vector<Object *> &objects, const std::string &filename, int w, int h);

    Color getImpactColor(const Ray &ray, Object *obj, const Point &impact);
};


#endif //RAYTRACING_CAMERA_H
