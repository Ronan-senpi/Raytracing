//
// Created by Aedrinios on 18/07/2021.
//

#include "Camera.h"
#include "Images/Image.h"
#include "Helpers/Serializer.h"

Ray Camera::getRay(const float x, const float y) {
//    const Point screenPos(x * 2 - 1, y * 2 - 1, 0);
//    return this->localToGlobal(Ray(screenPos, screenPos - Point(0, 0, this->focal))).normalized();

    Ray r(-1 + 2 * x, -1 + 2 * y, 0, 0, 0, 0);
    Point foc(0, 0, focal);
    r.Direction(r.Origin() - foc);
    r = localToGlobal(r);
    return r.normalized();
}

void Camera::screenshot(const std::vector<Object *> &objects, const std::string &filename,
                        const int w, const int h) {
    Image im(w, h, {0, 0.5, 0.5});
    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            Ray r = getRay(Serializer::serialize(x, 0, w - 1), Serializer::serialize(y, 0, h - 1));
            Point impact;
            Object *nearestObj = nullptr;
            for (Object *o : objects) {
                if (o->intersect(r, impact)) {
                    if (!nearestObj) {
                        nearestObj = o;
                    } else if (this->CloserThan(nearestObj->position(), o->position())) {
                        nearestObj = o;
                    }
                }
            }
            if (nearestObj) {
                Material m = nearestObj->getMaterial(impact);
                Ray normal = nearestObj->getNormal(impact, r.Origin());
                Point p = nearestObj->globalToLocal(impact);
                Color pixel = getImpactColor(r, nearestObj, impact);
//                Color pixel(normal.Direction()[0], normal.Direction()[1], normal.Direction()[2]);
                im(x, y, pixel);
            }
        }
    }
    im.write(filename);
}

bool Camera::CloserThan(const Point &oldPoint, const Point &newPoint) {
    return Vector(oldPoint - this->position()).norm() < Vector(newPoint - this->position()).norm();
}

Color Camera::getImpactColor(const Ray &ray, Object *obj, const Point &impact) {
    Material m = obj->getMaterial(impact);
    Ray normal = obj->getNormal(impact, ray.Origin());
    Color c = m.Ka() * (scene.getAmbiant());
    for (int l = 0; l < scene.nbLights(); l++) {
        const Light *light = scene.getLight(l);
        Vector lv = light->getVectorToLight(impact);
        float alpha = lv.dot(normal.Direction());
        if (alpha > 0)
            c += light->id() * m.Kd() * alpha;

        Vector rm = normal.Direction() * (2 * lv.dot(normal.Direction())) - lv;

        float beta = -rm.dot(ray.Direction());
        if (beta > 0)
            c += light->is() * m.Ks() * pow(beta, m.Shininess());
    }
    return c;
}


