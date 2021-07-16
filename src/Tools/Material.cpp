//
// Created by rdher on 15/07/2021.
//

#include "Material.h"

Color Material::getImpactColor(const Ray &ray, const Object &obj, const Point &impact, const Scene &scene) const {
    Color ambiant = obj.getMaterial(impact).ka.mul(scene.getAmbiant());
    Ray normal = obj.getNormal(impact, ray.Origin());

    Color diffuse{};
    Color specular{};
    for (int i = 0; i < scene.nbLights(); i++) {

        Vector vtl = scene.getLight(i).getVectorToLight(impact);

        float dAngle = normal.Direction().dot(vtl) < 0 ? 0 : normal.Direction().dot(vtl);
        diffuse += obj.getMaterial(impact).kd.mul(scene.getLight(i).id()) * dAngle;

        //Peut-etre ca marche pas, calcule d'origine ;)
        //Vector reflected = vtl -2 * (vtl.dot(normal.vector)) * normal.vector;
        Vector reflected = vtl - (normal.Direction() * vtl.dot(normal.Direction())) * 2;
        float sAngle = reflected.dot(ray.Direction());
        sAngle = sAngle < 0 ? 0 : sAngle;
        sAngle = pow(sAngle, obj.getMaterial(impact).shininess);

        specular += scene.getLight(i).is() * obj.getMaterial(impact).ks * sAngle;

    }
    return ambiant + diffuse + specular;
}
