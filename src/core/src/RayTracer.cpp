/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RayTracer.cpp
*/
#include "RayTracer.hpp"

rayTracer::RayTracer::RayTracer(std::string configfilePath):
    _pluginHandler(),
    _scene(configfilePath, this->_pluginHandler)
{
    this->_image.resize(600);

    for (int y = 0; y < 600; ++y) {
        this->_image[y].resize(600);
        for (int x = 0; x < 600; ++x) {
            this->_image[y][x] = rayTracer::Pixel(5, x, y, 600, 600, this->_scene);
        }
    }
}

rayTracer::RayTracer::~RayTracer()
{
}

void rayTracer::RayTracer::render()
{
    for (std::size_t x = 0; x != this->_image.size(); x++) {
        for (std::size_t y = 0; y != this->_image[x].size(); y++) {
            this->_image[x][y].simulateRays(this->_scene);
        }
    }
}

void rayTracer::RayTracer::out()
{
    std::cout << "P3\n" << "600 600 " << "\n255\n";

    for (int y = 0; y < 600; ++y) {
        for (int x = 0; x < 600; ++x) {
            std::cout << this->_image[x][y].getColor();
        }
    }
}
