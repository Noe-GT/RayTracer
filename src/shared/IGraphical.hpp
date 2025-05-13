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
#include "Color.hpp"

class IGraphical {
    public:
        virtual ~IGraphical() = default;
        virtual void display(std::vector<std::vector<math::Color>> image) = 0;
        virtual void idle() = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
