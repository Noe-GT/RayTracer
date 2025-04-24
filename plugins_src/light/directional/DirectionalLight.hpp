/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "ALight.hpp"

namespace light {
    class DirectionalLight : public ALight {
        public:
            DirectionalLight();
            DirectionalLight(math::Point origin);
            DirectionalLight(math::Point origin, math::Color color);
            ~DirectionalLight() = default;
        private:
    };
};

#endif /* !DIRECTIONALLIGHT_HPP_ */
