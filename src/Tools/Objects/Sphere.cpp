//
// Created by rdher on 15/07/2021.
//

#include "Sphere.h"
#include "../Vector.h"

bool Sphere::intersect(const Ray &ray, Point &impact) {
    Ray r = globalToLocal(ray);

    float a = r.Direction()[0] * r.Direction()[0] + r.Direction()[1] * r.Direction()[1] +
              r.Direction()[2] * r.Direction()[2];
    float b = 2 *
              (r.Origin()[0] * r.Direction()[0] + r.Origin()[1] * r.Direction()[1] + r.Origin()[2] * r.Direction()[2]);
    float c = r.Origin()[0] * r.Origin()[0] + r.Origin()[1] * r.Origin()[1] + r.Origin()[2] * r.Origin()[2] - 1;

    float delta = (b * b) - (4 * a * c);

    if (delta < 0) return false;
    else if (delta == 0) {
        float t = -b / (2 * a);
        if (t > 0) {
            float px = r.Origin()[0] + r.Direction()[0] * t;
            float py = r.Origin()[1] + r.Direction()[1] * t;
            float pz = r.Origin()[2] + r.Direction()[2] * t;
            impact[0] = px;
            impact[1] = py;
            impact[2] = pz;
            return true;
        } else return false;
    } else {
        float t1 = (-b - sqrt(delta)) / (2 * a);
        float t2 = (-b + sqrt(delta)) / (2 * a);
        float res = 0;
        if (t1 < 0) {
            res = t2;
        }
        if (t2 < 0) {
            res = t1;
        }
        if (t1 > 0 && t2 > 0) {
            res = (t1 < t2) ? t1 : t2;
        }
        if (res > 0) {
            float px = r.Origin()[0] + r.Direction()[0] * res;
            float py = r.Origin()[1] + r.Direction()[1] * res;
            float pz = r.Origin()[2] + r.Direction()[2] * res;
            impact[0] = px;
            impact[1] = py;
            impact[2] = pz;
            impact = localToGlobal(impact);
            return true;
        } else {
            return false;
        }
    }
}

Ray Sphere::getNormal(const Point &p, const Point &o) {
    const Point imp = this->globalToLocal(p);
    const Point obs = this->globalToLocal(o);
    const float distance(obs[0] * obs[0] + obs[1] * obs[1] + obs[2] * obs[2]);
    return Ray(p, Vector(imp[0], imp[1], imp[2]).normalized() * (distance < 1 ? -1 : 1));
    /*
    Point lp = globalToLocal(p);
    Point imp = p - position();
    return Ray(Point(0, 0, 0), Vector(imp[0], imp[1], imp[2]));*/
    /*Point temp = lo;
    bool isInside = (Vector(temp[0], temp[1], temp[2])).norm() < 1;
    Ray normal(lp, isInside ? -lp : lp);
    normal = normal.normalized();
    std::cout << "Impact point : " << lp << ", Observer point : " << o << ", Localspace normal : " << normal.Direction()
              << ", isInside : " << isInside << std::endl;
    return localToGlobal(normal).normalized();*/
}
