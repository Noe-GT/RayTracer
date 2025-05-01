/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"
#include "../dlloader/DLLoader.hpp"

rayTracer::Scene::Scene(std::string confPath, rayTracer::PluginHandler &PluginHandler)
{
    (void) PluginHandler;
    (void) confPath;
    // try {
    //     DLLoader loader("./dynamic_libs_bin/Sphere.so");
    //     auto sphere = loader.getInstance<IPrimitive>("entryPoint");
    //     if (!sphere) {
    //         std::cerr << "Error: Failed to create sphere instance" << std::endl;
    //         return;
    //     }
    //     this->_obj.push_back(std::move(sphere));
    // } catch (const std::exception &e) {
    //     std::cerr << "Error loading plugin: " << e.what() << std::endl;
    // }
    this->_ambiantLightIntensity = 1;
}

rayTracer::Scene::~Scene()
{
}
