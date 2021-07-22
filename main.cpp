#include <iostream>
#include <vector>

#include "src/Tools/Vector.h"
#include "src/Tools/Entity.h"
#include "src/Tools/Images/Image.h"
#include "src/Tools/Objects/Sphere.h"
#include "src/Tools/Camera.h"
#include "src/Tools/Light.h"
#include "src/Tools/Scene.h"
#include "src/Tools/Objects/Cube.h"
#include "src/Tools/Objects/Cylinder.h"
#include "src/Tools/Objects/Plan.h"
#include "src/Tools/Objects/Square.h"

int main() {
    std::vector<Object *> objs{};
    std::vector<Light *> lights{};
    Material m({1.0f, 0.f, 0.}, {1.f, 0.f, 0.}, {0.75f, 0.75f, 0.75}, 50);
    Material m2({1.0f, 1.0f, 1}, {0.0f, 0.0f, 1}, {0.0f, 0.0f, 1}, 1);
    Vector trans(1, 0, -10);
    Vector trans2(0.5, 0, -10);
    Vector rot(0.785398, 0.785398, 0);
    Vector sca(1, 1, 1);
    std::string name = "Sphere1";
    Sphere *s1 = new Sphere(trans, rot, sca, name, m);
    Sphere *s2 = new Sphere(trans2, rot, sca, name, m2);
    objs.push_back(s1);
//    objs.push_back(s2);
    Color bg = {0, 0, 0};
    Color amb = {0.1, 0.1, 0.1};

    Light *l = new Light({1, 1, 1}, {0.5, 0.5, 0.5}, {-10, 0, 0.1}, {0, 0, 0}, {1, 1, 1});
    lights.push_back(l);
    Scene scene(bg, amb, lights, objs, "Scene1");
    Camera cam(10, scene);
    cam.screenshot(objs, "SCENE1.jpg", 500, 500);

}


void test() {
    //    std::cout << "===============Start : Vector===============" << std::endl;
//    Vector v(1, 2, 3);
//    std::cout << v << std::endl;
//    Vector u(5, 6, 7);
//    Vector result = u + v;
//    std::cout << result << std::endl;
//    result = -v;
//    std::cout << result << std::endl;
//    result = u - v;
//    std::cout << result << std::endl;
//    float calcul = 2;
//    result = v * calcul;
//    std::cout << result << std::endl;
//    result = v / calcul;
//    std::cout << result << std::endl;
//    std::cout << "===============End : Vector===============" << std::endl;
//    std::cout << "===============Start : Ray===============" << std::endl;
//    Ray ray(1, 2, 3, 4, 5, 6);
//    std::cout << ray << std::endl;
//    std::cout << "===============Start : Entity===============" << std::endl;
//    Entity e;
//    std::cout << v << std::endl;
//    std::cout << e << std::endl;
//    e.translate(v);
//    e.rotateX(12);
//    e.rotateY(14);
//    e.rotateZ(16);
//    //e.scale(3);
//    std::cout << e << std::endl;
//    e.rotate(v);
//    std::cout << e << std::endl;
//    std::cout << "===============End : Entity===============" << std::endl;
//    std::cout << "===============Start : Matrix===============" << std::endl;
//    std::array<float, 16> tab{1, 0, 2, 4, 0, 1, 3, 2, 2, -1, 0, 3, 4, -1, 3, 9};
//    Matrix matrix(tab);
//    std::cout << matrix << std::endl;
//    Matrix inv = matrix.inverse();
//    std::cout << inv << std::endl;
//    std::array<float, 16> tabA{5, 7, 9, 10, 2, 3, 3, 8, 8, 10, 2, 3, 3, 3, 4, 8};
//    std::array<float, 16> tabB{3, 10, 12, 18, 12, 1, 4, 9, 9, 10, 12, 2, 3, 12, 4, 10};
//
//    Matrix a(tabA);
//    Matrix b(tabB);
//    Matrix mult = a * b;
//    std::cout << mult << std::endl;
//
//    Matrix multiplyPoint({1, 2, 5, 6, 8, 0, 4, 0, 6, 2, 4, 7, 8, 9, 2, 1});
//    Point pointFoisMat(4, 5, 9);
//    Vector vecFoisMat(4, 5, 9);
//    Point resultPointFoisMat = multiplyPoint * pointFoisMat;
//    Vector resultVecFoisMat = multiplyPoint * vecFoisMat;
//    std::cout << resultPointFoisMat << std::endl;
//    std::cout << resultVecFoisMat << std::endl;
//
//    Image(500, 500, {0.5, 0.5, 0}).write("out.png");
}