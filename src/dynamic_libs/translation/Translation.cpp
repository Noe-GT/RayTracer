/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"

Translation::Translation(int x, int y, int z) :
    ATransformations<int>(1, 3)
{
    this->_matrix.setMatrix(0, 0, x);
    this->_matrix.setMatrix(0, 1, y);
    this->_matrix.setMatrix(0, 2, z);
}
