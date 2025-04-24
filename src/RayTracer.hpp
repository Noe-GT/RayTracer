/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** RayTracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "math/Ray.hpp"
// #include "solid/sphere/Sphere.hpp"

class RayTracer {
    public:
        RayTracer(const double &_pictureH, const double &_pictureW);
        ~RayTracer();
        void run();
        math::Color ray_color(const math::Ray& r);

    private:
        const double _pictureH;
        const double _pictureW;
        // std::vector<solid::IPrimitive> _solids;
};

#endif /* !RAYTRACER_HPP_ */
