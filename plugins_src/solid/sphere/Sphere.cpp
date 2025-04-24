/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

solid::Sphere::Sphere():
    APrimitive(),
    _radius(0)
{
}

solid::Sphere::Sphere(math::Point origin, double radius) :
    APrimitive(origin),
    _radius(radius)
{
}

bool solid::Sphere::hits(math::Ray ray)
{
    math::Vector coVec(this->_origin - ray._origin);
    // vector from sphereCenter to rayOrigin
    double a = ray._direction.dotProduct(ray._direction);
    double b = -2.0 * ray._direction.dotProduct(coVec);
    double c = coVec.dotProduct(coVec) - this->_radius*this->_radius;
    double discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

extern "C"
{
    solid::IPrimitive *entryPoint()
    {
        return new solid::Sphere;
    }
}
