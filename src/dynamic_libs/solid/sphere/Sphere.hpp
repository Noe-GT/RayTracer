/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "APrimitive.hpp"

namespace solid {

    class Sphere : public solid::APrimitive
    // APrimitive::_origin is considered the center of the sphere
    {
        public:
            Sphere();
            Sphere(math::Point origin, double radius);
            ~Sphere() = default;
            bool hits(math::Ray ray) final;
        private:
            double _radius;
    };
};

#endif /* !SPHERE_HPP_ */
