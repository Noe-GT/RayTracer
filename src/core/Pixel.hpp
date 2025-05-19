/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Pixel.hpp
*/

#pragma once
#include "Ray.hpp"
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
        std::pair<size_t, size_t> getPos() const;
        std::vector<std::shared_ptr<rayTracer::IPrimitive>> getLights(const Scene &scene);
        void parseComposite(const Composite& node, std::vector<std::shared_ptr<rayTracer::IPrimitive>>& lights);
        bool processComposite(const Composite& composite, math::Ray& ray, const Scene& scene, std::vector<std::shared_ptr<rayTracer::IPrimitive>>& lights);
        math::Ray applyTransformation(const math::Ray& ray, const math::Matrix<double>& transformMatrix);

    private:
        std::vector<math::Ray> _rays;
        math::Color _colorMean;
        size_t _x;
        size_t _y;

        void calculateMeanColor();
    };
}
