/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Rotation
*/

#include "Rotation.hpp"

Rotation::Rotation(double x, double y, double z) :
    ATransformations<double>(3, 3)
{
    for (size_t i = 0; i <= 2; i++)
        this->_matrix.setMatrix(i, i, 1.0);

    math::Matrix mX(this->_matrix);
    mX.setMatrix(1, 1, cos(x));
    mX.setMatrix(2, 1, -sin(x));
    mX.setMatrix(1, 2, sin(x));
    mX.setMatrix(2, 2, cos(x));

    math::Matrix mY(this->_matrix);
    mY.setMatrix(0, 0, cos(y));
    mY.setMatrix(2, 0, sin(y));
    mY.setMatrix(0, 2, -sin(y));
    mY.setMatrix(2, 2, cos(y));

    math::Matrix mZ(this->_matrix);
    mZ.setMatrix(0, 0, cos(z));
    mZ.setMatrix(1, 0, -sin(z));
    mZ.setMatrix(0, 1, sin(z));
    mZ.setMatrix(1, 1, cos(z));

    this->_matrix = mZ * (mY * mX);
}
