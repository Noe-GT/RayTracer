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

Solid::APrimitive::APrimitive(math::Point origin) :
    _origin(origin)
{
}

// math::Point Solid::APrimitive::getOrigin() const
// {
//     return this->_origin;
// }
