/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "IPrimitive.hpp"
#include "IFactory.hpp"

class DirectionalLight: public IPrimitive{
    public:
        DirectionalLight();
        DirectionalLight(math::Point origin);
        DirectionalLight(math::Point origin, math::Color color);
        ~DirectionalLight() = default;

        bool intersect(math::Ray &ray) final;

    private:
        math::Point _origin;
        math::Color _color;
};

class DirectionalLightFactory: public rayTracer::IFactory {
    public:
        DirectionalLightFactory() = default;
        ~DirectionalLightFactory() = default;

        std::unique_ptr<IPrimitive> build() final;
};

#endif /* !DIRECTIONALLIGHT_HPP_ */
