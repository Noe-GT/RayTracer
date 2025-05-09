/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scaling
*/

#include "Scaling.hpp"

Scaling::Scaling(double x, double y, double z) :
    ATransformations<double>(3, 3)
{
    this->_matrix.setMatrix(0, 0, x);
    this->_matrix.setMatrix(1, 1, y);
    this->_matrix.setMatrix(2, 2, z);
}
