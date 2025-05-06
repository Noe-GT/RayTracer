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
        virtual void display(std::vector<std::vector<math::Color>> image) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
