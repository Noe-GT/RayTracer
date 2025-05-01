/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Pixel.cpp
*/

#include "Pixel.hpp"

rayTracer::Pixel::Pixel()
    : _colorMean(0, 0, 0)
{
}

rayTracer::Pixel::Pixel(int definition, int x, int y, int imageWidth, int imageHeight, const Scene& scene)
    : _x(x), _y(y)
{
    if (definition <= 0)
        throw std::invalid_argument("Definition must be > 0");

    this->_rays.reserve(definition);
    for (int i = 0; i < definition; i++) {
        double jitterX = (rand() / (double) RAND_MAX - 0.5);
        double jitterY = (rand() / (double) RAND_MAX - 0.5);

        math::Ray ray = scene._camera.generateRay(x + jitterX, y + jitterY, imageWidth, imageHeight);
        if (ray._direction.Length() < 0.0001) {
            throw std::runtime_error("Generated ray has zero direction");
        }
        this->_rays.push_back(ray);
    }
}

void rayTracer::Pixel::simulateRays(const Scene& scene)
{
    if (_rays.empty()) return;

    for (auto& ray : _rays) {
        for (const auto& obj : scene._obj) {
            if (obj->Intersect(ray, scene._lightPoses, scene._obj))
                break;
        }
        ray._color = ray._color * scene._ambiantLightIntensity;
        ray._color += {(scene._ambiantLightColor._r * (1.0 - scene._ambiantLightIntensity)), (scene._ambiantLightColor._g * (1.0 - scene._ambiantLightIntensity)), (scene._ambiantLightColor._b * (1.0 - scene._ambiantLightIntensity))};
        }
    calculateMeanColor();
}

void rayTracer::Pixel::calculateMeanColor() {
    if (_rays.empty()) {
        _colorMean = math::Color(0, 0, 0);
        return;
    }

    _colorMean = {0, 0, 0};
    for (const auto& ray : _rays) {
        _colorMean += ray._color;
    }
    _colorMean /= static_cast<double>(_rays.size());
}

const math::Color& rayTracer::Pixel::getColor() const
{
    return _colorMean;
}