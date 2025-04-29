/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Sphere::Sphere():
    _origin(0, 0, -1),
    _radius(0.5)
{
}

Sphere::Sphere(math::Point origin, double radius) :
    _origin(origin),
    _radius(radius)
{
}
bool Sphere::Intersect(math::Ray& ray)
{
    math::Vector oc = ray._origin - _origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2.0 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - _radius*_radius;
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        ray._color = math::Color(0, 0, 1);
        std::clog << "not Intersect\n";
        return false;
    }

    ray._color = math::Color(1, 0, 0);
    std::clog << "Intersect\n";
    return true;
}

extern "C"
{
    IPrimitive *entryPoint()
    {
        return new Sphere;
    }
}
