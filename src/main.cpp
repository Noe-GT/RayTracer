/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include "shared/include/Ray.hpp"

Color ray_color(const Ray& r) {
    Vector unit_direction(r._direction._x / r._direction.Length(),r._direction._y / r._direction.Length(),r._direction._z / r._direction.Length());
    auto a = 0.5 * (unit_direction._y + 1.0);
    return Color(1.0, 1.0, 1.0) * (1.0 - a) + Color(0.5, 0.7, 1.0) * a;
}


int main()
{
    auto picRatio = 16.0 / 9.0;
    int Picwidth = 500;

    int picHeigt = int(Picwidth / picRatio);
    picHeigt = (picHeigt < 1) ? 1 : picHeigt;
    auto viewHeight = 2.0;
    auto viewWidth = viewHeight * (double(Picwidth)/picHeigt);
    auto camPoint = Point(0, 0, 0);
    auto delta1= Vector(viewWidth, 0, 0);
    auto delta2 = Vector(0, -viewHeight, 0);
    auto fiirstPixel = camPoint - Vector(0, 0, 1) - delta1/2 - delta2/2 + (delta1 / Picwidth + delta2 / picHeigt) / 2;
    std::cout << "P3\n" << Picwidth << " " << picHeigt << "\n255\n";

    for (int j = 0; j < picHeigt; j++) {
        for (int i = 0; i < Picwidth; i++) {
            auto pixel_center = fiirstPixel + (delta1 / Picwidth * i) + (delta2 / picHeigt * j);
            Point tmp = pixel_center - camPoint;
            Vector ray_direction(tmp._x, tmp._y, tmp._z);
            Ray r(camPoint, ray_direction);

            Color pixel_color = ray_color(r);
            std::cout << pixel_color;
        }
    }
}