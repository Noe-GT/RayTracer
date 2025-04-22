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
}

bool Solid::Sphere::hits(int ray)
{
    (void)ray;
    return false;
}
