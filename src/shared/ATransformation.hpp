/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ATransformation
*/

#pragma once

#include "ITransformation.hpp"
#include "Matrix.hpp"

template<typename T>
class ATransformation : public ITransformation<T>
{
    public:
        ATransformation(size_t x, size_t y) :
            _matrix(x, y)
        {
        }

        ~ATransformation() = default;

        math::Matrix<T> getMatrix() const final
        {
            return this->_matrix;
        }

    protected:
        math::Matrix<T> _matrix;
};
