/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RayTracer.cpp
*/
#include "RayTracer.hpp"

rayTracer::RayTracer::RayTracer(std::string configFilePath):
    _rayDefinition(1),
    _workers(1),
    _outputFilePath("render.ppm"),
    _pluginHandler(),
    _parser(this->_pluginHandler),
    _scene(this->_pluginHandler)
{
    this->_parser.loadConfig(configFilePath, *this);
}

rayTracer::RayTracer::~RayTracer()
{
}

void rayTracer::RayTracer::render()
{
    std::cout << "Rendering..." << std::endl;
    std::cout << "[workers : " << this->_workers << " | ray definition : " << this->_rayDefinition << "]" << std::endl;
    rayTracer::RenderPool renderPool(this->_workers, this->_image);
    renderPool.render(this->_scene, this->_graphical);
}

void rayTracer::RayTracer::out()
{
    std::ofstream file(this->_outputFilePath);
    const std::pair<int, int> &res = this->getImageResolution();

    file << "P3\n" << res.first << " "<< res.second << " \n255\n";
    for (int y = 0; y < res.second; ++y) {
        for (int x = 0; x < res.first; ++x) {
            file << this->_image[y]->at(x).getColor() << std::endl;
        }
    }
    file.close();
    std::cout << "Render saved as: " << this->_outputFilePath << std::endl;
}

rayTracer::Scene &rayTracer::RayTracer::getScene()
{
    return this->_scene;
}

void rayTracer::RayTracer::setGraphical(std::shared_ptr<IGraphical> graphical)
{
    this->_graphical = std::move(graphical);
}

void rayTracer::RayTracer::setRayDefinition(size_t rayDefinition)
{
    this->_rayDefinition = rayDefinition;
}

void  rayTracer::RayTracer::setWorkers(size_t workers)
{
    this->_workers = workers;
}

std::pair<size_t, size_t> rayTracer::RayTracer::getImageResolution() const
{
    if (this->_image.size() <= 0)
        return std::pair<size_t, size_t>(0, 0);
    return std::pair<size_t, size_t>(this->_image[0]->size(), this->_image.size());
}

void rayTracer::RayTracer::setImage(const std::pair<size_t, size_t> &resolution)
{
    this->_image.resize(resolution.second);
    for (size_t y = 0; y < resolution.second; ++y) {
        this->_image[y] = std::make_shared<std::vector<rayTracer::Pixel>>(resolution.first);
        for (size_t x = 0; x < resolution.first; ++x) {
            this->_image[y]->at(x) = rayTracer::Pixel(this->_rayDefinition, x, y, resolution.first, resolution.second, this->_scene);
        }
    }
}

void rayTracer::RayTracer::setOutputFilePath(const std::string &outputFilePath)
{
    this->_outputFilePath = outputFilePath;
}
