//
// Created by Aedrinios on 18/07/2021.
//

#include "Camera.h"
#include "Images/Image.h"
#include "Helpers/Serializer.h"
#include <algorithm>
#include <iostream>
#include <omp.h>

Ray Camera::getRay(const float x, const float y) {
    Ray r(-1 + 2 * x, -1 + 2 * y, 0, 0, 0, 0);
    Point foc(0, 0, focal);
    r.Direction(r.Origin() - foc);
    r = localToGlobal(r);
    return r.normalized();
}

void Camera::screenshot(const std::vector<Object *> &objects, const std::string &filename,
                        const int w, const int h) {
    Image im(w, h, scene.getBackground());

#pragma omp parallel for
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            Ray r = getRay(Serializer::serialize(x, 0, w - 1), Serializer::serialize(y, 0, h - 1));
            Point impact;
            Point nearestImpact;
            Object *nearestObj = nullptr;
            for (Object *o : objects) {
                if (o->intersect(r, impact)) {
                    if (!nearestObj || this->CloserThan(nearestImpact, impact)) {
                        nearestObj = o;
                        nearestImpact = impact;
                    }
                }
            }
            if (nearestObj) {
                Ray normal = nearestObj->getNormal(nearestImpact, r.Origin());
                Color pixel = getImpactColor(r, nearestObj, nearestImpact);
//                Color pixel(normal.Direction()[0], normal.Direction()[1], normal.Direction()[2]);
                im(h - y - 1, x, pixel);
            }
        }
    }
    im.write(filename);
}

bool
Camera::CloserThan(const Point &oldImpact, const Point &newImpact) const {
    float oldDistance = Vector(oldImpact - this->position()).norm();
    float newDistance = Vector(newImpact - this->position()).norm();
    return newDistance < oldDistance;
}

Color Camera::getImpactColor(const Ray &ray, Object *obj, const Point &impact) {
//    Material m = obj->getMaterial(impact);
//    Ray normal = obj->getNormal(impact, ray.Origin());
//    Color c = m.Ka() * scene.getAmbiant();
//
//    for (int l = 0; l < scene.nbLights(); l++) {
//        const Light *light = scene.getLight(l);
//        Vector lv = light->getVectorToLight(impact);
//        float alpha = lv.dot(normal.Direction());
//        alpha = alpha < 0 ? 0 : alpha;
//        c += light->id() * m.Kd() * alpha;
//    }
//    return c;
    Material m = obj->getMaterial(impact);
    Ray normal = obj->getNormal(impact, ray.Origin());
    Color c = m.Ka() * scene.getAmbiant();

    for (int l = 0; l < scene.nbLights(); l++) {
        const Light *light = scene.getLight(l);
        Vector lv = light->getVectorToLight(impact);
        float alpha = lv.dot(normal.Direction());
        if (alpha > 0)
            c += light->id() * m.Kd() * alpha;

        Vector rm = (normal.Direction() * (lv.dot(normal.Direction() * 2))) - lv;
        float beta = -rm.dot(ray.Direction());
        if (beta > 0)
            c += light->is() * m.Ks() * pow(beta, m.Shininess());
    }
    if (obj->hasTexture()) {
        Point texCoordinate = obj->getTextureCoordinates(impact);
        Color texColor = m.getTexture(texCoordinate);
        c = c * texColor;
    }
    return c;
}


