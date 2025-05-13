/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ITransformations
*/

#ifndef ITRANSFORMATIONS_HPP_
#define ITRANSFORMATIONS_HPP_

#include "Matrix.hpp"

class ITransformations
{
    public:
        virtual ~ITransformations() = default;
        virtual math::Matrix<double> getMatrix() const = 0;
};

#endif /* !ITRANSFORMATIONS_HPP_ */
