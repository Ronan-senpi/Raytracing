//
// Created by rdher on 23/07/2021.
//

#include "SpoonfeederJson.h"

std::vector<std::shared_ptr<Image>> SpoonfeederJson::makeTextures(const json &paths) {
    std::vector<std::shared_ptr<Image>> l;
    for (const auto &path : paths) {
        l.push_back(std::make_shared<Image>(path));
    }
    return l;
}

template<typename T>
std::vector<Object *> SpoonfeederJson::makeObjects(const json &objs, const std::vector<Material> &mats) {
    std::vector<Object *> l;
    std::vector<Material> matToAdd;
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
        for (const int &mat : obj["matIds"]) {
            matToAdd.push_back(mats[mat]);
        }

        l.push_back(new T(trans, rot, sca, matToAdd));
        matToAdd.clear();
    }
    return l;

}

std::vector<Material>
SpoonfeederJson::makeMaterials(const json &mats, const std::vector<std::shared_ptr<Image>> &textures) {
    std::vector<Material> l;
    for (const auto &mat : mats) {
        float r = mat["ka"]["r"];
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
        if (mat["texId"] != "") {
            int texId = mat["texId"];
            l.emplace_back(textures[texId], ka, kd, ks, shininess);
        } else {
            l.emplace_back(ka, kd, ks, shininess);
        }
    }
    return l;
}

std::vector<Light *> SpoonfeederJson::makeLights(const json &lights) {
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

std::shared_ptr<Camera> SpoonfeederJson::makeCamera(const json &cam, const Scene &scene) {
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

std::vector<std::shared_ptr<Camera>>
SpoonfeederJson::prepareCamera(const json &scenes, const std::vector<Material> &mats,
                               const std::vector<std::shared_ptr<Image>> &skybox) {
    std::vector<std::shared_ptr<Camera>> l;
    std::vector<Light *> lights;

    for (const auto &scene : scenes) {
        std::vector<Object *> objs;
        /// Begin : Objects
        // add cubes
        auto cubes = makeObjects<Cube>(scene["Objects"]["cubes"], mats);
        objs.insert(objs.end(), cubes.begin(), cubes.end());

        // add cylinders
        auto cylinders = makeObjects<Cylinder>(scene["Objects"]["cylinders"], mats);
        objs.insert(objs.end(), cylinders.begin(), cylinders.end());

        // add plans
        auto plans = makeObjects<Plan>(scene["Objects"]["plans"], mats);
        objs.insert(objs.end(), plans.begin(), plans.end());

        // add spheres
        auto spheres = makeObjects<Sphere>(scene["Objects"]["spheres"], mats);
        objs.insert(objs.end(), spheres.begin(), spheres.end());

        // add squares
        auto squares = makeObjects<Square>(scene["Objects"]["squares"], mats);
        objs.insert(objs.end(), squares.begin(), squares.end());
        /// End: Objects

        ///Begin: skybox

        Vector trans(scene["camera"]["trans"]["x"],
                     scene["camera"]["trans"]["y"],
                     scene["camera"]["trans"]["z"]);
        if (scene["skyId"] != "") {
            int skyId = scene["skyId"];
            Material skyboxMat(skybox[skyId],
                               {1, 1, 1},
                               {1, 1, 1},
                               {1, 1, 1}, 0.1);
            std::vector<Material> mats;
            mats.push_back(skyboxMat);
            objs.push_back(new Sphere(
                    trans,
                    {1.5708, 0, 0},
                    {20, 20, 20},
                    "skybox",
                    mats));
        }
        ///End: Skybox

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

void SpoonfeederJson::displayTitle() {
    std::cout << R"(
__________                 __                       .__
\______   \_____  ___.__._/  |_____________    ____ |__| ____    ____
 |       _/\__  \<   |  |\   __\_  __ \__  \ _/ ___\|  |/    \  / ___\
 |    |   \ / __ \\___  | |  |  |  | \// __ \\  \___|  |   |  \/ /_/  >
 |____|_  /(____  / ____| |__|  |__|  (____  /\___  >__|___|  /\___  /
        \/      \/\/                       \/     \/        \//_____/

 ___    _                                    _       ___    _
(  _`\ (_ )                                 ( )_    (  _`\ (_ )
| ( (_) | |    __    ___ ___     __    ___  | ,_)   | ( (_) | |    __   _ __   ___
| |  _  | |  /'__`\/' _ ` _ `\ /'__`\/' _ `\| |     | |  _  | |  /'__`\( '__)/'___)
| (_( ) | | (  ___/| ( ) ( ) |(  ___/| ( ) || |_    | (_( ) | | (  ___/| |  ( (___
(____/'(___)`\____)(_) (_) (_)`\____)(_) (_)`\__)   (____/'(___)`\____)(_)  `\____)

 ___                                   ___    _
|  _`\                                (  _`\ ( )                        _                             _
| (_) )   _     ___     _ _   ___     | | ) || |__     __   _ __   ___ (_)   __    ___     __   _ __ (_)   __
| ,  /  /'_`\ /' _ `\ /'_` )/' _ `\   | | | )|  _ `\ /'__`\( '__)/',__)| | /'_ `\/' _ `\ /'__`\( '__)| | /'__`\
| |\ \ ( (_) )| ( ) |( (_| || ( ) |   | |_) || | | |(  ___/| |   \__, \| |( (_) || ( ) |(  ___/| |   | |(  ___/
(_) (_)`\___/'(_) (_)`\__,_)(_) (_)   (____/'(_) (_)`\____)(_)   (____/(_)`\__  |(_) (_)`\____)(_)   (_)`\____)
                                                                          ( )_) |
                                                                           \___/'

)" << std::endl;
}
