/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

light::DirectionalLight::DirectionalLight()
{
}

light::DirectionalLight::DirectionalLight(math::Point origin):
    ALight(origin)
{
}

light::DirectionalLight::DirectionalLight(math::Point origin, math::Color color):
    ALight(origin, color)
{
}
