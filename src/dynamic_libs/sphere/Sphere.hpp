/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "IPrimitive.hpp"
#include "IFactory.hpp"
#include <memory>

class Sphere: public IPrimitive {
    public:
        Sphere();
        Sphere(math::Point origin, double radius);
        ~Sphere() = default;

        bool intersect(math::Ray &ray) final;

    private:
        math::Point _origin;
        double _radius;
};

class SphereFactory: public rayTracer::IFactory {
    public:
        SphereFactory() = default;
        ~SphereFactory() = default;

        std::unique_ptr<IPrimitive> build() final;
        rayTracer::IFactory::ObjectType getObjectType() const final;
};

#endif /* !SPHERE_HPP_ */
