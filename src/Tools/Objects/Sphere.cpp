//
// Created by rdher on 15/07/2021.
//
#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include "Sphere.h"
#include "../Vector.h"
#include <xmmintrin.h>

__m128 _mm_hadd_ps(__m128 val) {
    __m128 tmp = _mm_shuffle_ps(val, val, _MM_SHUFFLE(1, 0, 3, 2));
    __m128 tmp2 = _mm_add_ps(val, tmp);
    tmp = _mm_shuffle_ps(tmp2, tmp2, _MM_SHUFFLE(0, 1, 0, 1));
    return _mm_add_ps(tmp, tmp2);
}

bool Sphere::intersect(const Ray &ray, Point &impact) const {
    Ray r = globalToLocal(ray).normalized();

    __m128 zero = _mm_set_ss(0);
    __m128 zeroOne = _mm_set_ss(0.0001f);
    __m128 one = _mm_set_ss(1.f);
    __m128 negOne = _mm_set_ss(-1.f);
    __m128 two = _mm_set_ss(2.f);
    __m128 four = _mm_set_ss(4.f);

    __m128 rDirection = {r.Direction().X(),
                         r.Direction().Y(),
                         r.Direction().Z(),
                         0.f};

    __m128 rOrigin = {r.Origin().X(),
                      r.Origin().Y(),
                      r.Origin().Z(),
                      0.f};

    __m128 a = _mm_mul_ps(rDirection, rDirection);
    a = _mm_hadd_ps(a);

    __m128 b = _mm_mul_ps(rDirection, rOrigin);
    b = _mm_hadd_ps(b);
    b = _mm_mul_ps(b, two);

    __m128 c = _mm_mul_ps(rOrigin, rOrigin);
    c = _mm_hadd_ps(c);
    c = _mm_sub_ps(c, one);

    //float delta = b * b - 4.f * a * c;
    __m128 tmp2 = _mm_mul_ss(b, b);

    __m128 tmp = _mm_mul_ss(four, a);
    tmp = _mm_mul_ss(tmp, c);
    __m128 delt = _mm_sub_ss(tmp2, tmp);

    __m128 cond = _mm_cmplt_ss(delt, zero);

    // if (delta < 0)
    if (_mm_cvtss_f32(cond) != 0) return false;

//    if (delta < 0.0001f) {
    cond = _mm_cmplt_ss(delt, zeroOne);
    if (_mm_cvtss_f32(cond) != 0) {
        // t = -b / (2.f * a);
        tmp2 = _mm_mul_ss(b, negOne);
        tmp = _mm_mul_ss(two, a);
        tmp = _mm_div_ss(tmp2, tmp);
    } else {
        //t = (-b - sqrt(delta)) / (2.f * a);
        tmp = _mm_sub_ss(_mm_mul_ss(b, negOne), _mm_sqrt_ss(delt));
        tmp = _mm_div_ss(tmp, _mm_mul_ss(two, a));
        //if (t < 0)
        cond = _mm_cmplt_ss(tmp, zero);
        if (_mm_cvtss_f32(cond) != 0) {
            // t = (-b + sqrt(delta)) / (2.f * a);
            tmp = _mm_sub_ss(_mm_mul_ss(b, negOne), _mm_sqrt_ss(delt));
            tmp2 = _mm_mul_ss(two, a);
            tmp = _mm_div_ss(tmp, tmp2);
        }
    }
    //if (t < 0.f)
    cond = _mm_cmplt_ss(tmp, zero);
    if (_mm_cvtss_f32(cond) != 0) {
        return false;
    }

    //Point p = r.Origin() + (r.Direction() * t);
    tmp = _mm_shuffle_ps(
            tmp,
            tmp,
            _MM_SHUFFLE(0, 0, 0, 0)); // = t
    tmp2 = _mm_mul_ps(rDirection, tmp);
    tmp = _mm_add_ps(rOrigin, tmp2);
    float *f = new float[4];
    _mm_store_ps(f, tmp);
    impact = localToGlobal(
            Point(f[0], f[1], f[2]));
    return true;
    /*   float a = r.Direction().dot(r.Direction());
       float b = 2 * r.Direction().dot(r.Origin());
       float c = r.Origin().dot(r.Origin()) - 1.f;
       float delta = b * b - 4.f * a * c;

       if (delta < 0)
           return false;

       float t;
       if (delta < 0.0001f) {
           t = -b / (2.f * a);
       } else {
           t = (-b - sqrt(delta)) / (2.f * a);
           if (t < 0)
               t = (-b + sqrt(delta)) / (2.f * a);
       }
       if (t < 0.f)
           return false;

       Point p = r.Origin() + (r.Direction() * t);
       impact = localToGlobal(p);
       return true;*/
}


Ray Sphere::getNormal(const Point &p, const Point &o) const {
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    if (Vector((lo - Point(0, 0, 0))).norm() < 1)return localToGlobal(Ray(lp, -lp)).normalized();
    return localToGlobal(Ray(lp, lp)).normalized();
}

Point Sphere::getTextureCoordinates(const Point &p) const {
    Point lp = globalToLocal(p);
    float rho = std::sqrt(lp.dot(lp));
    float theta = std::atan2(lp.Y(), lp.X());
    float sigma = std::acos(lp.Z() / rho);
    float x = -theta / (2 * M_PI) + 0.5;
    float y = sigma / M_PI;
    return Point(x, y, 0);
}