/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ATransformations
*/

#ifndef ATRANSFORMATIONS_HPP_
#define ATRANSFORMATIONS_HPP_

#include "ITransformations.hpp"
#include "../static_libs/math/Matrix.hpp"

template<typename T>
class ATransformations : public ITransformations<T>
{
    public:
        ATransformations(size_t x, size_t y) :
            _matrix(x, y)
        {
        }

        ~ATransformations() = default;

        math::Matrix<T> getMatrix() const final
        {
            return this->_matrix;
        }

    protected:
        math::Matrix<T> _matrix;
};

#endif /* !ATRANSFORMATIONS_HPP_ */
