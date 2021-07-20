//
// Created by Aedrinios on 20/07/2021.
//

#ifndef RAYTRACING_SERIALIZER_H
#define RAYTRACING_SERIALIZER_H


namespace Serializer {
    static float serialize(float v, float min, float max) {
        return (v - min) / (max - min);
    }

    static int deserialize(float v, float min, float max) {
        return int(v * (max - min) + min);
    }
};


#endif //RAYTRACING_SERIALIZER_H
