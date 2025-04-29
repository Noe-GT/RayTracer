/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight()
{
}

DirectionalLight::DirectionalLight(math::Point origin):
    _origin(origin)
{
}

DirectionalLight::DirectionalLight(math::Point origin, math::Color color):
    _origin(origin),
    _color(color)
{
}

bool DirectionalLight::intersect(math::Ray &ray)
{
    (void)ray;
    return false;
}

std::unique_ptr<IPrimitive> DirectionalLightFactory::build()
{
    return std::make_unique<DirectionalLight>();
}

extern "C"
{
    rayTracer::IFactory *entryPoint()
    {
        return new DirectionalLightFactory;
    }
}
