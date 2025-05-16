/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** RayTracer.cpp
*/
#include "RayTracer.hpp"

rayTracer::RayTracer::RayTracer(std::string configFilePath):
    _rayDefinition(1),
    _outputFilePath("render.ppm"),
    _showRender(false),
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
    // std::vector<std::vector<math::Color>> dispVector;

    // std::cout << "Rendering..." << std::endl;
    // for (std::size_t y = 0; y != this->_image.size(); y++) {
    //     if (this->_graphical)
    //         dispVector.push_back(std::vector<math::Color>());
    //     for (std::size_t x = 0; x != this->_image[y].size(); x++) {
    //         this->_image[y][x].simulateRays(this->_scene);
    //         if (this->_graphical)
    //             dispVector.back().push_back(this->_image[y][x].getColor());
    //     }
    //     if (this->_showRender && this->_graphical)
    //         this->_graphical->display(dispVector);
    // };
    // std::cout << "Render completed." << std::endl;
    // if (this->_graphical) {
    //     this->_graphical->display(dispVector);
    //     this->_graphical->idle();
    // }

    // std::vector<std::vector<rayTracer::Pixel>> baseQueue;
    // std::cout << "Rendering..." << std::endl;

    // for (size_t y = 0; y < 600; ++y) {
    //     std::vector<rayTracer::Pixel> vect;
    //     for (size_t x = 0; x < 600; ++x) {
    //         vect.push_back(rayTracer::Pixel(this->_rayDefinition, x, y, 600, 600, this->_scene));
    //     }
    //     baseQueue.push_back(vect);
    // }
    rayTracer::RenderPool(2, this->_image, this->_scene);
}

void rayTracer::RayTracer::out()
{
    std::ofstream file(this->_outputFilePath);
    const std::pair<int, int> &res = this->getImageResolution();

    file << "P3\n" << res.first << " "<< res.second << " \n255\n";
    for (int y = 0; y < res.second; ++y) {
        for (int x = 0; x < res.first; ++x) {
            file << this->_image[y][x].getColor();
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

void rayTracer::RayTracer::setRayDefinition(int rayDefinition)
{
    this->_rayDefinition = rayDefinition;
}

void rayTracer::RayTracer::setShowRender(bool showRender)
{
    this->_showRender = showRender;
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
            this->_image[y][x] = rayTracer::Pixel(this->_rayDefinition, x, y, resolution.first, resolution.second, this->_scene);
        }
    }
}

void rayTracer::RayTracer::setOutputFilePath(const std::string &outputFilePath)
{
    this->_outputFilePath = outputFilePath;
}
