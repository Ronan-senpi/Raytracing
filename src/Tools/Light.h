//
// Created by rdher on 06/07/2021.
//

#ifndef RAYTRACING_LIGHT_H
#define RAYTRACING_LIGHT_H
#include "Entity.h"
#include "Ray.h"
#include "Point.h"
#include "Vector.h"

class Light: public Entity {
public:
    /**
     * Retourne un Ray partant du Point passé en paramètre et orienté vers la lumière.
     * @param p Origine du ray
     * @return
     */
    Ray getRayToLight(const Point& p) const;
    /**
     * Retourne un Ray partant de la lumière et orienté vers le Point passé en paramètre.
     * @param p Arrivée du ray
     * @return
     */
    Ray getRayFromLight(const Point& p) const;
    /**
     * Retourne un Vector orienté du Point passé en paramètre vers la lumière.
     * @param p Origine du vector
     * @return
     */
    Vector getVectorToLight(const Point& p) const;
    /**
     * Retourne un Vector orienté de la lumière vers le Point passé en paramètre.
     * @param p "Arrivée" du vector
     * @return
     */
    Vector getVectorFromLight(const Point& p) const;
};


#endif //RAYTRACING_LIGHT_H
