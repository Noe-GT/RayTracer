/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Rotation
*/

#ifndef ROTATION_HPP_
#define ROTATION_HPP_

#include "ATransformation.hpp"
#include "../../static_libs/math/Matrix.hpp"
#include "IFactory.hpp"
#include "PluginTypes.hpp"
#include <cmath>

class Rotation : public ATransformation<double>
{
    public:
        Rotation(double x, double y, double z);
        ~Rotation() = default;
};

class RotationFactory: public rayTracer::IFactory<ITransformation<double>> {
    public:
        RotationFactory() = default;
        ~RotationFactory() = default;

        std::shared_ptr<ITransformation<double>> build(double x, double y, double z) final;
};

#endif /* !ROTATION_HPP_ */
