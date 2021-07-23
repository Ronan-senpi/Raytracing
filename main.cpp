#include <iostream>
#include <vector>
#include <fstream>

#include "src/Tools/Vector.h"
#include "src/Tools/Entity.h"
#include "src/Tools/Images/Image.h"
#include "src/Tools/Camera.h"
#include "src/Tools/Objects/Include.h"
#include "json.hpp"

using json = nlohmann::json;

std::vector<std::shared_ptr<Image>> makeTextures(const json &paths) {
    std::vector<std::shared_ptr<Image>> l;
    for (const auto &path : paths) {
        l.push_back(std::make_shared<Image>(path));
    }
    return l;
}

template<typename T>
std::vector<Object *> makeObjects(const json &objs,
                                  const std::vector<Material> &mats) {
    std::vector<Object *> l;
    for (const auto &obj : objs) {
        Vector trans(obj["trans"]["x"],
                     obj["trans"]["y"],
                     obj["trans"]["z"]);

        Vector rot(obj["rot"]["x"],
                   obj["rot"]["y"],
                   obj["rot"]["z"]);

        Vector sca(obj["sca"]["x"],
                   obj["sca"]["y"],
                   obj["sca"]["z"]);

        int matId = obj["matId"];

        l.push_back(new T(trans, rot, sca, mats[matId]));
    }
    return l;
}

std::vector<Material> makeMaterials(const json &mats,
                                    const std::vector<std::shared_ptr<Image>> &textures) {
    std::vector<Material> l;
    for (const auto &mat : mats) {
        Color ka(mat["ka"]["r"],
                 mat["ka"]["g"],
                 mat["ka"]["b"]);

        Color kd(mat["kd"]["r"],
                 mat["kd"]["g"],
                 mat["kd"]["b"]);

        Color ks(mat["ks"]["r"],
                 mat["ks"]["g"],
                 mat["ks"]["b"]);

        float shininess = mat["shininess"];

        int texId = mat["texId"];
        l.emplace_back(textures[texId], ka, kd, ks, shininess);
    }
    return l;
}

std::vector<Light *> makeLights(const json &lights) {
    std::vector<Light *> l;
    for (const auto &light : lights) {
        Color id(light["id"]["r"],
                 light["id"]["g"],
                 light["id"]["b"]);

        Color is(light["is"]["r"],
                 light["is"]["g"],
                 light["is"]["b"]);

        Vector trans(light["trans"]["x"],
                     light["trans"]["y"],
                     light["trans"]["z"]);

        Vector rot(light["rot"]["x"],
                   light["rot"]["y"],
                   light["rot"]["z"]);

        Vector sca(light["sca"]["x"],
                   light["sca"]["y"],
                   light["sca"]["z"]);

        l.emplace_back(new Light(id, is, trans, rot, sca));
    }
    return l;
}

std::shared_ptr<Camera> makeCamera(const json &cam, const Scene &scene) {
    Vector trans(cam["trans"]["x"],
                 cam["trans"]["y"],
                 cam["trans"]["z"]);

    Vector rot(cam["rot"]["x"],
               cam["rot"]["y"],
               cam["rot"]["z"]);

    float focal = cam["focal"];
    int height = cam["height"];
    return std::make_shared<Camera>(focal, height, scene, trans, rot);

}

std::vector<std::shared_ptr<Camera>> prepareCamera(const json &scenes,
                                                   const std::vector<Material> &mats,
                                                   const std::vector<std::shared_ptr<Image>> &skybox) {
    std::vector<std::shared_ptr<Camera>> l;
    std::vector<Light *> lights;

    for (const auto &scene : scenes) {
        std::vector<Object *> objs;
        /// Begin : Objects
        // add cubes
        auto cubes = makeObjects<Cube>(scene["cubes"], mats);
        objs.insert(objs.end(), cubes.begin(), cubes.end());

        // add cylinders
        auto cylinders = makeObjects<Cylinder>(scene["cylinders"], mats);
        objs.insert(objs.end(), cylinders.begin(), cylinders.end());

        // add plans
        auto plans = makeObjects<Plan>(scene["plans"], mats);
        objs.insert(objs.end(), plans.begin(), plans.end());

        // add spheres
        auto spheres = makeObjects<Sphere>(scene["spheres"], mats);
        objs.insert(objs.end(), spheres.begin(), spheres.end());

        // add squares
        auto squares = makeObjects<Square>(scene["squares"], mats);
        objs.insert(objs.end(), squares.begin(), squares.end());
        /// End: Objects

        /// Begin: Lights
        lights = makeLights(scene["lights"]);
        /// End: Lights

        /// Begin : Colors
        Color bg(scene["bgColor"]["r"],
                 scene["bgColor"]["g"],
                 scene["bgColor"]["b"]);

        Color amb(scene["ambColor"]["r"],
                  scene["ambColor"]["g"],
                  scene["ambColor"]["b"]);
        /// End : Colors

        /// Begin : scene
        std::string name = scene["name"];
        Scene s(bg, amb, lights, objs, name);
        /// End : scene

        /// Begin : Camera

        auto camera = makeCamera(scene["camera"], s);
        l.emplace_back(camera);
        /// End: Camera

    }
    return l;
}

int main() {

    //Get json values
    std::ifstream config_file("resources/config.json", std::ifstream::binary);
    json j = json::parse(config_file);

    //Make images
    std::vector<std::shared_ptr<Image>> textures = makeTextures(j["Textures"]);
    std::vector<std::shared_ptr<Image>> skybox = makeTextures(j["Skybox"]);

    //Make materials
    std::vector<Material> materials = makeMaterials(j["Materials"], textures);

    //Make scene
    std::vector<std::shared_ptr<Camera>> cameras = prepareCamera(j["scene"], materials, skybox);

    for (const auto &cam : cameras) {
        cam->screenshot();
    }
}


int old() {

    std::time_t start = time(0);
    std::vector<Object *> objs{};
    std::vector<Light *> lights{};

    std::shared_ptr<Image> TposeTexture = std::make_shared<Image>("resources/sen.png");
    std::shared_ptr<Image> senTexture = std::make_shared<Image>("resources/sen.png");
    std::shared_ptr<Image> skyboxTexture = std::make_shared<Image>("resources/earth.png");

    Material m(senTexture,
               {1.0f, 0.f, 0.},
               {1.f, 0.f, 0.},
               {1.f, 1.f, 1.f}, 100);
    Material m2(TposeTexture,
                {0.0f, 0.0f, 1},
                {0.0f, 0.0f, 1},
                {1.0f, 1.0f, 1}, 100);
    Material m3({0.0f, 1.0f, 1},
                {0.0f, 1.0f, 1},
                {1.0f, 1.0f, 1}, 100);
    Material m4({0.5f, 0.5f, 0.5},
                {0.5f, 0.5f, 0.5f},
                {1.0f, 1.0f, 1}, 100);
    Material mTex(TposeTexture,
                  {0.0f, 0.0f, 1},
                  {0.0f, 0.0f, 1},
                  {1.0f, 1.0f, 1},
                  100);
    Material skyboxMat(skyboxTexture,
                       {1, 1, 1},
                       {1, 1, 1},
                       {1, 1, 1}, 0.1);
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

    Light *l = new Light(
            {1, 1, 1},
            {1, 1, 1},
            {-10, 10, 0.1},
            {0, 0, 0}, {1, 1, 1});
    lights.push_back(l);
    Scene scene(bg, amb, lights, objs, "Scene1");
    Camera cam(1, scene);
//    cam.screenshot(objs, "SCENE1.jpg", 500, 500);

    std::time_t end = time(0);
    double seconds = difftime(end, start);
    std::cout << "execution time" + std::to_string(seconds) << std::endl;
    return 0;
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