//
// Created by rdher on 05/07/2021.
//

#include "Object.h"

//Point Object::getTextureCoordinates(const Point &p) const {
//    return Point(0, 0, 0);
//}

Material Object::getMaterial(const Point &p)const {
    Point lp = globalToLocal(p);
    if (mats.size() > 1) {
        if ((int(lp.X() * 10)) % 2 == 0) {
            return mats[0];
        } else {
            return mats[1];
        }
    }
    return mats[0];
}
