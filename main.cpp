#include <iostream>
#include <vector>

#include "src/Tools/Vector.h"
#include "src/Tools/Entity.h"
#include "src/Tools/Images/Image.h"
#include "src/Tools/Camera.h"
#include "src/Tools/Objects/Include.h"

int main() {

    std::time_t start = time(0);
    std::vector<Object *> objs{};
    std::vector<Light *> lights{};
    std::shared_ptr<Image> TposeTexture = std::make_shared<Image>("resources/tpose.jpg");
    std::shared_ptr<Image> senTexture = std::make_shared<Image>("resources/sen.png");
    std::shared_ptr<Image> skyboxTexture = std::make_shared<Image>("resources/hakone-shrine.jpg");

    Material m(senTexture, {1.0f, 0.f, 0.}, {1.f, 0.f, 0.}, {1.f, 1.f, 1.f}, 100);
    Material m2(TposeTexture,
                {0.0f, 0.0f, 1}, {0.0f, 0.0f, 1}, {1.0f, 1.0f, 1}, 100);
    Material m3({0.0f, 1.0f, 1}, {0.0f, 1.0f, 1}, {1.0f, 1.0f, 1}, 100);
    Material m4({0.5f, 0.5f, 0.5}, {0.5f, 0.5f, 0.5f}, {1.0f, 1.0f, 1}, 100);
    Material mTex(TposeTexture,
                  {0.0f, 0.0f, 1},
                  {0.0f, 0.0f, 1},
                  {1.0f, 1.0f, 1},
                  100);
    Material skyboxMat(skyboxTexture, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}, 0.1);
    Vector trans(1, 0, -10);
    Vector trans2(-2, 0, -7);
    Vector trans3(0, 0, -12);
    Vector rot(0.785398, 0.785398, 0);
    Vector rot3(0.5, 0, 0.5);
    Vector sca(1, 1, 1);
    std::string name = "Sphere1";
    Sphere *s1 = new Sphere(trans, rot, sca, name, m);
    Cube *c2 = new Cube(trans2, rot, sca, name, m2);
    Cylinder *cy3 = new Cylinder(trans3, rot3, sca, name, m3);
    Square *squ = new Square({2, 0, -6},
                             {0, 0, 0},
                             {1, 1, 1},
                             "Square",
                             mTex);
    Plan *p4 = new Plan({0, 0, -20}, {0, 0, 0}, {1, 1, 1}, name, m4);

    Sphere *skybox = new Sphere(
            {0, 0, 0},
            {0, 0, 0},
            {20, 20, 20},
            "Skybox",
            skyboxMat
    );
    objs.push_back(s1);
    objs.push_back(c2);
    objs.push_back(cy3);
    objs.push_back(p4);
    objs.push_back(skybox);
//    objs.push_back(squ);
    Color bg = {0, 0, 0};
    Color amb = {0.1, 0.1, 0.1};

    Light *l = new Light({1, 1, 1}, {1, 1, 1}, {-10, 10, 0.1}, {0, 0, 0}, {1, 1, 1});
    lights.push_back(l);
    Scene scene(bg, amb, lights, objs, "Scene1");
    Camera cam(1, scene);
    cam.screenshot(objs, "SCENE1.jpg", 500, 500);

    std::time_t end = time(0);
    double seconds = difftime(end, start);
    std::cout << "execution time" + std::to_string(seconds) << std::endl;
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