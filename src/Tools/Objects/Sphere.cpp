//
// Created by rdher on 15/07/2021.
//
#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <emmintrin.h>
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
    __m128 rDirection = {r.Direction().X(), r.Direction().Y(), r.Direction().Z(), 0};
    __m128 rOrigin = {r.Origin().X(), r.Origin().Y(), r.Origin().Z(), 0};

    __m128 zero = _mm_set_ss(0);
    __m128 zeroOne = _mm_set_ss(0.0001f);
    __m128 one = _mm_set_ss(1);
    __m128 two = _mm_set_ss(2);
    __m128 four = _mm_set_ss(4);
    __m128 minus = _mm_set_ss(-1);

    // float a = r.Direction().dot(r.Direction());
    __m128 a = _mm_mul_ps(rDirection, rDirection);
    a = _mm_hadd_ps(a);

    //float b = 2 * r.Direction().dot(r.Origin());
    __m128 b = _mm_mul_ps(rDirection, rOrigin);
    b = _mm_hadd_ps(b);
    b = _mm_mul_ss(b, two);

    //  float c = r.Origin().dot(r.Origin()) - 1.f;
    __m128 c = _mm_mul_ps(rOrigin, rOrigin);
    c = _mm_hadd_ps(c);
    c = _mm_sub_ss(c, one);

    // float delta = b * b - 4.f * a * c;
    __m128 delta = _mm_mul_ps(b, b);
    __m128 deltatmp = _mm_mul_ps(a, c);
    deltatmp = _mm_mul_ss(deltatmp, four);
    delta = _mm_sub_ss(delta, deltatmp);

    __m128 condition = _mm_cmplt_ss(delta, zero);

    if (((float *) (&condition))[0] != 0) return false;

    __m128 t;
    __m128 ttmp;
    condition = _mm_cmplt_ss(delta, zeroOne);
    if (((float *) (&condition))[0] != 0) {
        // t = -b / (2.f * a);
        t = _mm_mul_ss(b, minus);
        ttmp = _mm_mul_ss(two, a);
        t = _mm_div_ss(t, ttmp);
    } else {
        //t = (-b - sqrt(delta)) / (2.f * a);
        t = _mm_mul_ss(b, minus);
        ttmp = _mm_sqrt_ss(delta);
        t = _mm_sub_ss(t, ttmp);
        ttmp = _mm_mul_ss(two, a);
        t = _mm_div_ss(t, ttmp);
        condition = _mm_cmplt_ss(t, zero);
        if (((float *) (&condition))[0] != 0) {
            //t = (-b + sqrt(delta)) / (2.f * a);
            t = _mm_mul_ss(b, minus);
            ttmp = _mm_sqrt_ss(delta);
            t = _mm_add_ss(t, ttmp);
            ttmp = _mm_mul_ss(two, a);
            t = _mm_div_ss(t, ttmp);
        }
    }
    condition = _mm_cmplt_ss(t, zero);
    if (((float *) (&condition))[0] != 0)
        return false;


    Point p = r.Origin() + (r.Direction() * ((float *) (&t))[0]);
    impact = localToGlobal(p);
    return true;
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