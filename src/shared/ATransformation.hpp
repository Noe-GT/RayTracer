/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ATransformations
*/

#ifndef ATRANSFORMATIONS_HPP_
#define ATRANSFORMATIONS_HPP_

#include "ITransformation.hpp"
#include "Matrix.hpp"

class ATransformation : public ITransformation
{
    public:
        ATransformation(size_t x, size_t y, std::string name);
        ~ATransformation() = default;

        math::Matrix<double> getMatrix() const override;
        const std::string getName() override;

    protected:
        math::Matrix<double> _matrix;
        std::string _name;
};

#endif /* !ATRANSFORMATIONS_HPP_ */
