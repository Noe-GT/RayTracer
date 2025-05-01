/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Sphere::Sphere():
    _origin(),
    _radius(0)
{
}

Sphere::Sphere(math::Point origin, double radius) :
    _origin(origin),
    _radius(radius)
{
}

bool Sphere::intersect(math::Ray &ray)
{
    math::Vector coVec(this->_origin - ray._origin);
    double a = ray._direction.dotProduct(ray._direction);
    double b = -2.0 * ray._direction.dotProduct(coVec);
    double c = coVec.dotProduct(coVec) - this->_radius*this->_radius;
    double discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

std::shared_ptr<IPrimitive> SphereFactory::build()
{
    return std::make_shared<Sphere>();
}

extern "C"
{
    rayTracer::IFactory<IPrimitive> *entryPoint()
    {
        return new SphereFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::PRIMITIVE;
    }
}
