/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

#include <utility>

class IGraphical {
    public:
        ~IGraphical() = default;
        virtual void setSize(const std::pair<int, int> &size) = 0;
        virtual void drawPixel(int x, int y, int color) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
