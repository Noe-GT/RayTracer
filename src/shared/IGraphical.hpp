/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

class IGraphical {
    public:
        ~IGraphical() = default;
        virtual void setSize(int width, int height) = 0;
        virtual void drawPixel(int x, int y, int color) = 0;
};

#endif /* !IGRAPHICAL_HPP_ */
