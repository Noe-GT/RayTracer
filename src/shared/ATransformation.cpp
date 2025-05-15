/*
** EPITECH PROJECT, 2025
** RayTracer
** File description:
** ATransformation
*/

#include "ATransformation.hpp"

ATransformation::ATransformation(size_t x, size_t y, std::string name) : _matrix(x, y), _name(name)
{
}

math::Matrix<double> ATransformation::getMatrix() const
{
    return this->_matrix;
}

const std::string ATransformation::getName()
{
    return this->_name;
}
