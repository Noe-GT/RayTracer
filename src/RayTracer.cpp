/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** RayTracer
*/

#include "RayTracer.hpp"

RayTracer::RayTracer(const double &_pictureH, const double &_pictureW):
    _pictureH(_pictureH),
    _pictureW(_pictureW)
{
}

RayTracer::~RayTracer()
{
}

void RayTracer::run()
{
    auto viewHeight = 2.0;
    auto viewWidth = viewHeight * (double(this->_pictureW)/this->_pictureH);
    auto camPoint = math::Point(0, 0, 0);
    auto delta1= math::Vector(viewWidth, 0, 0);
    auto delta2 = math::Vector(0, -viewHeight, 0);
    auto fiirstPixel = camPoint - math::Vector(0, 0, 1) - delta1/2 - delta2/2 + (delta1 / this->_pictureW + delta2 / this->_pictureH) / 2;
    std::cout << "P3\n" << this->_pictureW << " " << this->_pictureH << "\n255\n";

    for (int j = 0; j < this->_pictureH; j++) {
        for (int i = 0; i < this->_pictureW; i++) {
            auto pixel_center = fiirstPixel + (delta1 / this->_pictureW * i) + (delta2 / this->_pictureH * j);
            math::Point tmp = pixel_center - camPoint;
            math::Vector ray_direction(tmp._x, tmp._y, tmp._z);
            math::Ray r(camPoint, ray_direction);

            math::Color pixel_color = this->ray_color(r);
            std::cout << pixel_color;
        }
    }

}

math::Color RayTracer::ray_color(const math::Ray& r) {
    math::Vector unit_direction(r._direction._x / r._direction.Length(),r._direction._y / r._direction.Length(),r._direction._z / r._direction.Length());
    auto a = 0.5 * (unit_direction._y + 1.0);
    return math::Color(1.0, 1.0, 1.0) * (1.0 - a) + math::Color(0.5, 0.7, 1.0) * a;
}
