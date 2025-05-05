/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include <utility>
#include <vector>
#include "../static_libs/math/Color.hpp"

class IGraphical {
    public:
        ~IGraphical() = default;
        virtual void setSize(const std::pair<int, int> &size) = 0;
        virtual void drawPixel(size_t x, size_t y, const math::Color &color) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
