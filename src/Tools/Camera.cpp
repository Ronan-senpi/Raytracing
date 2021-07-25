//
// Created by Aedrinios on 18/07/2021.
//

#include "Camera.h"
#include <iostream>
#include "Helpers/StringHelpers.h"

Ray Camera::getRay(const float x, const float y) {
    Ray r(x, y, 0, 0, 0, 0);
    Point foc(0, 0, focal);
    r.Direction(r.Origin() - foc);
    r = localToGlobal(r);
    return r.normalized();
}

//void Camera::screenshot(const std::vector<Object *> &objects, const std::string &filename,
//                        const int w, const int h) {
void Camera::screenshot(const std::string &name, const int &height, const bool &displayShadows, const int &ssaa) {
    Image im(height, height, scene.getBackground());

#pragma omp parallel for
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < height; ++y) {

            Color pix(0.f);

            for (int subX = 0; subX < ssaa; ++subX) {
                for (int subY = 0; subY < ssaa; ++subY) {
                    float viewportX = ((x + ((float) subX / (float) ssaa)) / ((float) height - 1) * 2) - 1;
                    //+ 1/(float)subX
                    float viewportY = ((height - y + ((float) subY / (float) ssaa)) / ((float) height - 1) * 2) - 1;
                    // + 1/(float)subY
                    Ray r = getRay(viewportX, viewportY);
                    Point impact;
                    Point nearestImpact;
                    Object *nearestObj = nullptr;
                    for (Object *o : scene.getObjects()) {
                        if (o->intersect(r, impact)) {
                            if (!nearestObj || this->CloserThan(nearestImpact, impact, this->position())) {
                                nearestObj = o;
                                nearestImpact = impact;
                            }
                        }
                    }
                    if (nearestObj) {
                        pix.addNoClamp(getImpactColor(r, nearestObj, nearestImpact,displayShadows));
                    }
                }
            }
            im(height - y - 1, x, pix /= (float) (ssaa * ssaa));
            pix.clear();

        }
    }
    im.write(name + ".jpg");
}

bool Camera::CloserThan(const Point &oldImpact, const Point &newImpact, const Vector &comparison) const {
    float oldDistance = Vector(oldImpact - comparison).norm();
    float newDistance = Vector(newImpact - comparison).norm();
    return newDistance < oldDistance;
}

Color Camera::getImpactColor(const Ray &ray, Object *obj, const Point &impact, const bool &displayShadows) {

    Material m = obj->getMaterial(impact);
    Ray normal = obj->getNormal(impact, ray.Origin());
    Color c = m.Ka() * scene.getAmbiant();
    bool shadowDetected = false;
    for (int l = 0; l < scene.nbLights(); l++) {
        const Light *light = scene.getLight(l);
        Vector lv = light->getVectorToLight(impact);
        if (displayShadows) {
            Ray shadowRay(impact, lv);
            Point impactShadow;
            for (Object *o : scene.getObjects()) {
                if (o != obj
                    &&
                    o->intersect(shadowRay, impactShadow) && lv.dot(normal.Direction()) < 0) {
                    if (this->CloserThan(impactShadow, light->position(), impact)) {
                        shadowDetected = true;
                    }

                }
            }
        }
        if (!shadowDetected) {
            float alpha = lv.dot(normal.Direction());
            if (alpha > 0)
                c += light->id() * m.Kd() * alpha;

            Vector rm = (normal.Direction() * (lv.dot(normal.Direction() * 2))) - lv;
            float beta = -rm.dot(ray.Direction());
            if (beta > 0)
                c += light->is() * m.Ks() * pow(beta, m.Shininess());
        }

    }
    if (m.hasTexture()) {
        Point texCoordinate = obj->getTextureCoordinates(impact);
        Color texColor = m.getTexture(texCoordinate);
        c = c * texColor;
    }


    return c;
}


