/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ALight
*/

#include "ALight.hpp"

light::ALight::ALight()
{
}

light::ALight::ALight(math::Point origin):
    _origin(origin)
{
}

void light::ALight::setColor(const math::Color &color)
{
    this->_color = color;
}

const math::Color &light::ALight::getColor() const
{
    return this->_color;
}
