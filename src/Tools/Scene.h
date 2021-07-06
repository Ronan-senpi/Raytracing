//
// Created by rdher on 06/07/2021.
//

#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H
#include <vector>
#include "Color.h"
#include "Light.h"
#include "Object.h"

class Scene {
private:
    Color bgColor, ambiantColor;
    std::vector<Light> lights;
    std::vector<Object> objects;
public:
    /**
     * retourne un pointeur vers l'objet intersecté par le rayon passé en paramètre le plus proche,
     * et nullptr si il n'y en a pas.
     * Met à jour le point d'impact passé en paramètre par référence.
     * @param ray
     * @param impact met a jour ce point avec le point d'impact
     * @return
     */
    Object* closer_intersected(const Ray& ray, Point& impact)const;
    /**
     * Retourne la couleur d'arrière plan.
     * @return color
     */
    Color getBackground() const{
        return bgColor;
    }
    /**
     * Retourne la valeur de lumière ambiante.
     * @return Color
     */
    Color getAmbiant() const{
        return  ambiantColor;
    }
    /**
     * Retourne le nombre de lumières dans la scène.
     * @return int
     */
    int nbLights() const{
        return  lights.size();
    }

};


#endif //RAYTRACING_SCENE_H
