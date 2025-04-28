/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "IPrimitive.hpp"

class Sphere: public IPrimitive {
    public:
        Sphere();
        Sphere(math::Point origin, double radius);
        ~Sphere() = default;

        bool Intersect(math::Ray &ray) final;

    private:
    math::Point _origin;
    double _radius;
};

#endif /* !SPHERE_HPP_ */
