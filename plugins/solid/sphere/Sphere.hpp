/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "APrimitive.hpp"

namespace Solid {
    class Sphere : public Solid::APrimitive
    {
        public:
            Sphere(int origin, double radius);
            ~Sphere() = default;
            bool hits(int ray) final;
        private:
            double _radius;
    };
};

#endif /* !SPHERE_HPP_ */
