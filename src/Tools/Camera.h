//
// Created by Aedrinios on 18/07/2021.
//

#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include <string>
#include <utility>
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

    Camera(float foc, Scene s) : focal(foc), scene(std::move(s)), Entity() {}

    Camera(const float &foc,
           const int &h,
           Scene sce,
           const Point &pos,
           const Vector &rot)
            : focal(foc),
              scene(std::move(sce)),
              Entity(pos, rot, {1, 1, 1}) {}

    Camera(float foc, const Point pos, const Vector &rot, const Vector &sca) : focal(foc), Entity(pos, rot, sca) {}

    ~Camera() = default;

    Ray getRay(float x, float y);

    std::string sceneName() const {
        return scene.getName();
    }

    void screenshot(const std::string &name, const int &height, const bool &shadows);

    Color getImpactColor(const Ray &ray, Object *obj, const Point &impact);
};


#endif //RAYTRACING_CAMERA_H
