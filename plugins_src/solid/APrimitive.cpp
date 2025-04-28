/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

solid::APrimitive::APrimitive():
    _origin(math::Point())
{
}

solid::APrimitive::APrimitive(math::Point origin) :
    _origin(origin)
{
}

const math::Point &solid::APrimitive::getOrigin() const
{
    return this->_origin;
}
