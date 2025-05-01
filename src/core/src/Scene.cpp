/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"
#include "../dlloader/DLLoader.hpp"

rayTracer::Scene::Scene(std::string confPath)
{
    (void) confPath;
    try {
        DLLoader loader("./dynamic_libs_bin/Sphere.so");
        auto sphere = loader.getInstance<IPrimitive>("entryPoint");
        this->_obj.push_back(std::move(sphere));
        auto sphere2 = loader.getInstance<IPrimitive>("entryPoint");
        this->_obj.push_back(std::move(sphere2));
    } catch (const std::exception &e) {
        std::cerr << "Error loading plugin: " << e.what() << std::endl;
    }
    this->_ambiantLightIntensity = 1;
    this->_ambiantLightColor = {1, 0, 1};
    this->_obj[0]->getOrigin() = math::Point(-0.4, -0.4, -1);
    this->_obj[1]->getOrigin() = math::Point(0.4, 0.4, -1.7);
    this->_obj[1]->getSize() = 0.7;
    this->_lightPoses.push_back({-2, -2, -1});
}

rayTracer::Scene::~Scene()
{
}
