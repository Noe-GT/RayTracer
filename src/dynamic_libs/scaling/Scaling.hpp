/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scaling
*/

#ifndef SCALING_HPP_
#define SCALING_HPP_

#include "../../shared/ATransformations.hpp"
#include "../../static_libs/math/Matrix.hpp"

class Scaling : public ATransformations<double>
{
    public:
        Scaling(double x, double y, double z);
        ~Scaling() = default;

    protected:
    private:
};

#endif /* !SCALING_HPP_ */
