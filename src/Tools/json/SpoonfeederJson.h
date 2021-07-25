//
// Created by rdher on 23/07/2021.
//

#ifndef RAYTRACING_SPOONFEEDERJSON_H
#define RAYTRACING_SPOONFEEDERJSON_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

#include "../Vector.h"
#include "../Entity.h"
#include "../Images/Image.h"
#include "../Camera.h"
#include "../Objects/Include.h"
#include "../Helpers/StringHelpers.h"
#include "json.hpp"

using json = nlohmann::json;

class SpoonfeederJson {
public:
    SpoonfeederJson(const bool &wizard) {
        //Get json values
        std::ifstream config_file("../resources/config.json", std::ifstream::binary);
        json j = json::parse(config_file);

        //Make images
        std::vector<std::shared_ptr<Image>> textures = makeTextures(j["Textures"]);
        std::vector<std::shared_ptr<Image>> skybox = makeTextures(j["Skybox"]);

        //Make materials
        std::vector<Material> materials = makeMaterials(j["Materials"], textures);

        //Make scene
        std::vector<std::shared_ptr<Camera>> cameras = prepareCamera(j["scenes"], materials, skybox);


        if (cameras.empty()) {
            std::cout << "Acune scene n'a été charger verifier le fichier config.json" << std::endl;
            return;
        }

        if (!wizard) {
            std::time_t start = time(0);
            int i = 0;
            for (auto &cam: cameras) {
                cam->screenshot(std::to_string(i), 500, true, 1);
                ++i;
            }
            std::time_t end = time(0);
            double seconds = difftime(end, start);
            std::cout << std::fixed;
            std::cout << std::setprecision(4);
            std::cout << "Rendu de .jpg fini en " << seconds << " seconds !" << std::endl;
        } else {
            bool shadows = false;
            std::string tmp;
            int sceneId;
            int imgSize;
            std::string imageName;
            int ssaa;
            /// Begin : scene to renderer
            std::cout << "ATTENTION AUCUN CONTROLE DE SAISIE N'A ETE FAIT" << std::endl;
            std::cout << "Nous faisons confiance aux utilisateur ! <3" << std::endl;
            std::cout << "Les scenes suivante on ete charges, la quel voulez vous rendre ? (0)" << std::endl;
            int ind = 0;
            for (const auto &cam : cameras) {
                std::cout << "Id : " << ind << " : " << cam->sceneName() << std::endl;
                ++ind;
            }
            getline(std::cin, tmp);
            if (tmp.empty()) {
                tmp = "0";
            }
            sceneId = StringHelper::StringToInt(tmp);

            /// End : scene to renderer
            ///Begin : Image name

            std::cout << "nom de l'image :" << std::endl;
            getline(std::cin, tmp);
            if (tmp.empty())
                tmp = cameras[sceneId]->sceneName();

            imageName = tmp;


            ///End : Image name
            ///Begin : Image size

            std::cout << "hauteur de l'image en pixels: (500px)" << std::endl;
            getline(std::cin, tmp);
            if (tmp.empty()) {
                tmp = "500";
            }
            imgSize = StringHelper::StringToInt(tmp);

            ///End : Image size

            ///Begin : shadows
            std::cout << "Voulez vous des ombres ? (y/n)" << std::endl;
            getline(std::cin, tmp);
            if (tmp.empty()) {
                tmp = "y";
            }

            shadows = tmp == "y";
            ///End : shadows

            ///Begin : SSAA

            std::cout << "SSAA: (1)" << std::endl;
            getline(std::cin, tmp);
            if (tmp.empty()) {
                tmp = "1";
            }
            ssaa = StringHelper::StringToInt(tmp);

            ///End : SSAA

            std::cout << "Debut du rendu de " << imageName << ".jpg !" << std::endl;
            ///Begin: Renderer

            std::time_t start = time(0);
            cameras[sceneId]->screenshot(imageName, imgSize, shadows, ssaa);
            std::time_t end = time(0);
            double seconds = difftime(end, start);
            std::cout << std::fixed;
            std::cout << std::setprecision(4);
            std::cout << "Rendu de " << imageName << ".jpg fini en " << seconds << " seconds !" << std::endl;

            ///End: Renderer

        }
    }


private :
    static std::vector<std::shared_ptr<Image>> makeTextures(const json &paths);

    template<typename T>
    static std::vector<Object *> makeObjects(const json &objs,
                                             const std::vector<Material> &mats);


    static std::vector<Material> makeMaterials(const json &mats,
                                               const std::vector<std::shared_ptr<Image>> &textures);


    static std::vector<Light *> makeLights(const json &lights);

    static std::shared_ptr<Camera> makeCamera(const json &cam, const Scene &scene);


    static std::vector<std::shared_ptr<Camera>> prepareCamera(const json &scenes,
                                                              const std::vector<Material> &mats,
                                                              const std::vector<std::shared_ptr<Image>> &skybox);
};

#endif //RAYTRACING_SPOONFEEDERJSON_H
