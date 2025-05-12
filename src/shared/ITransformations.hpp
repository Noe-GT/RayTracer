/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ITransformations
*/

#ifndef ITRANSFORMATIONS_HPP_
#define ITRANSFORMATIONS_HPP_

#include "../static_libs/math/Matrix.hpp"

template<typename T>
class ITransformations
{
    public:
        virtual ~ITransformations() = default;
        virtual math::Matrix<T> getMatrix() const = 0;
};

#endif /* !ITRANSFORMATIONS_HPP_ */
