/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ITransformation
*/

#pragma once

#include "Matrix.hpp"

template<typename T>
class ITransformation
{
    public:
        virtual ~ITransformation() = default;
        virtual const std::string getName() = 0;
        virtual math::Matrix<T> getMatrix() const = 0;
};
