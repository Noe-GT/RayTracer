/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Rotation
*/

#ifndef ROTATION_HPP_
#define ROTATION_HPP_

#include "../../shared/ATransformations.hpp"
#include "../../static_libs/math/Matrix.hpp"
#include <cmath>

class Rotation : public ATransformations<double>
{
    public:
        Rotation(double x, double y, double z);
        ~Rotation() = default;
};

#endif /* !ROTATION_HPP_ */
