/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

Solid::APrimitive::APrimitive()
{
}

Solid::APrimitive::APrimitive(int origin) :
    _origin(origin)
{
}

int Solid::APrimitive::getOrigin() const
{
    return _origin;
}
