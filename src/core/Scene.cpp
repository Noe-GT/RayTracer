/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene.cpp
*/

#include "Scene.hpp"
#include "DLLoader.hpp"

rayTracer::Scene::Scene(const rayTracer::PluginHandler &PluginHandler): _nextId(0)
{
    (void) PluginHandler;
    this->_ambiantLightIntensity = 1;
    this->_ambiantLightColor = {1, 1, 1};
}

rayTracer::Scene::~Scene()
{
}

void rayTracer::Scene::addComposite(const Composite &composite)
{
    _composites.push_back(composite);
}

int rayTracer::Scene::getNextId()
{
    this->_nextId++;
    return this->_nextId - 1;
}

const std::vector<Composite>& rayTracer::Scene::getComposites() const
{
    return _composites;
}