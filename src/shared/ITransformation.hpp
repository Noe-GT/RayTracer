/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ITransformations
*/

#ifndef ITRANSFORMATIONS_HPP_
#define ITRANSFORMATIONS_HPP_

#include "Matrix.hpp"

class ITransformation
{
    public:
        virtual ~ITransformation() = default;
        virtual math::Matrix<double> getMatrix() const = 0;
        virtual const std::string getName() = 0;

};

#endif /* !ITRANSFORMATIONS_HPP_ */
