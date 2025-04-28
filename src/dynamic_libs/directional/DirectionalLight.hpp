/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "IPrimitive.hpp"

class DirectionalLight: public IPrimitive{
    public:
        DirectionalLight();
        DirectionalLight(math::Point origin);
        DirectionalLight(math::Point origin, math::Color color);
        ~DirectionalLight() = default;
    private:
        math::Point _origin;
        math::Color _color;
};

#endif /* !DIRECTIONALLIGHT_HPP_ */
