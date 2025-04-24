/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Solid::Sphere::Sphere(int origin, double radius) :
    APrimitive(origin),
    _radius(radius)
{
    (void)this->_radius;
}

bool Solid::Sphere::hits(int ray)
{
    // Advance
    // Get distance
    // if distance <= 0 -> return true
    // if distance > base distance -> return false
    (void)ray;
    return false;
}
