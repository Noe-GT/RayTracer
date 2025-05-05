/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Pixel.hpp
*/

#pragma once
#include "../static_libs/math/Ray.hpp"
#include "Scene.hpp"
#include <vector>
#include <memory>

namespace rayTracer {
    class Pixel {
    public:
        Pixel();
        Pixel(int definition, int x, int y, int imageWidth, int imageHeight, const Scene& scene);

        const math::Color& getColor() const;
        void simulateRays(const Scene& scene);
        std::pair<int, int> getPos() const;

    private:
        std::vector<math::Ray> _rays;
        math::Color _colorMean;
        int _x;
        int _y;

        void calculateMeanColor();
    };
}
