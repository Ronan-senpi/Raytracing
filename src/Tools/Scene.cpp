//
// Created by rdher on 06/07/2021.
//

#include "Scene.h"

Object *Scene::closer_intersected(const Ray &ray, Point &impact) const {
    throw "Implem";
}

Color Scene::getImpactColor(const Ray &ray, Object &obj, const Point &impact) {
    Color ambiant = obj.getMaterial(impact).Ka() * (getAmbiant());
    Ray normal = obj.getNormal(impact, ray.Origin());

    Color diffuse{};
    Color specular{};
    for (int i = 0; i < nbLights(); i++) {

        Vector vtl = getLight(i).getVectorToLight(impact);

        float dAngle = normal.Direction().dot(vtl) < 0 ? 0 : normal.Direction().dot(vtl);
        diffuse += obj.getMaterial(impact).Kd() * (getLight(i).is() * dAngle);

        //Peut-etre ca marche pas, calcule d'origine ;)
        //Vector reflected = vtl -2 * (vtl.dot(normal.vector)) * normal.vector;
        Vector reflected = vtl - (normal.Direction() * vtl.dot(normal.Direction())) * 2;
        float sAngle = reflected.dot(ray.Direction());
        sAngle = sAngle < 0 ? 0 : sAngle;
        sAngle = pow(sAngle, obj.getMaterial(impact).Shininess());

        specular += getLight(i).is() * obj.getMaterial(impact).Ks() * sAngle;

    }
    return ambiant + diffuse + specular;
}

void Scene::screenshot() {
    camera.screenshot(objects, name + ".png", 250, 250);
}
