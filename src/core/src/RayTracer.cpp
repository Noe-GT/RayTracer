/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RayTracer.cpp
*/
#include "RayTracer.hpp"

rayTracer::RayTracer::RayTracer(std::string configFilePath):
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
    for (std::size_t y = 0; y != this->_image.size(); y++) {
        for (std::size_t x = 0; x != this->_image[y].size(); x++) {
            this->_image[y][x].simulateRays(this->_scene);
            math::Color color = this->_image[y][x].getColor();
            if (this->_graphical) {
                this->_graphical->drawPixel(x, y, this->_image[y][x].getColor());
            }
        }
    }
}

void rayTracer::RayTracer::out()
{
    const std::pair<int, int> &res = this->getImageResolution();

    std::cout << "P3\n" << res.first << " "<< res.second << " \n255\n";
    for (int y = 0; y < res.second; ++y) {
        for (int x = 0; x < res.first; ++x) {
            std::cout << this->_image[y][x].getColor();
        }
    }
}

rayTracer::Scene &rayTracer::RayTracer::getScene()
{
    return this->_scene;
}

void rayTracer::RayTracer::setGraphical(std::shared_ptr<IGraphical> graphical)
{
    this->_graphical = std::move(graphical);
}

std::pair<size_t, size_t> rayTracer::RayTracer::getImageResolution() const
{
    if (this->_image.size() <= 0)
        return std::pair<size_t, size_t>(0, 0);
    return std::pair<size_t, size_t>(this->_image[0].size(), this->_image.size());
}

void rayTracer::RayTracer::setImage(const std::pair<size_t, size_t> &resolution)
{
    this->_image.resize(resolution.second);
    for (size_t y = 0; y < resolution.second; ++y) {
        this->_image[y].resize(resolution.first);
        for (size_t x = 0; x < resolution.first; ++x) {
            this->_image[y][x] = rayTracer::Pixel(5, x, y, resolution.first, resolution.second, this->_scene);
        }
    }
}
