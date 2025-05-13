/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ATransformations
*/

#ifndef ATRANSFORMATIONS_HPP_
#define ATRANSFORMATIONS_HPP_

#include "ITransformations.hpp"
#include "Matrix.hpp"

class ATransformations : public ITransformations
{
    public:
        ATransformations(size_t x, size_t y) :
            _matrix(x, y)
        {
        }

        ~ATransformations() = default;

        math::Matrix<double> getMatrix() const final
        {
            return this->_matrix;
        }

    protected:
        math::Matrix<double> _matrix;
};

#endif /* !ATRANSFORMATIONS_HPP_ */
