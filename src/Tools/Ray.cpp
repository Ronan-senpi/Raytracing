//
// Created by Aedrinios on 05/07/2021.
//

#include "Ray.h"


std::ostream& operator<<(std::ostream& os, const Ray& r)
{
    return os << "(" << "Origin : " << r.Origin() << " and Direction : " << r.Direction() << std::endl;
}