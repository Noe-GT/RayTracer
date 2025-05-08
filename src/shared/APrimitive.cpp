/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** APrimitive
*/

#include "APrimitive.hpp"

APrimitive::APrimitive():
    _origin(0, 0, -1)
{
}

int &APrimitive::getID()
{
    return this->_id;
}

Material &APrimitive::getMaterial()
{
    return this->_material;
}

math::Point &APrimitive::getOrigin()
{
    return this->_origin;
}
