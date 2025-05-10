/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"
#include "DLLoader.hpp"

rayTracer::Scene::Scene(const rayTracer::PluginHandler &PluginHandler)
{
    (void) PluginHandler;
    this->_ambiantLightIntensity = 5;
}

rayTracer::Scene::~Scene()
{
}
