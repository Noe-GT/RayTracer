/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scaling
*/

#ifndef SCALING_HPP_
#define SCALING_HPP_

#include "ATransformations.hpp"
#include "../../static_libs/math/Matrix.hpp"
#include "IFactory.hpp"
#include "PluginTypes.hpp"

class Scaling : public ATransformations<double>
{
    public:
        Scaling(double x, double y, double z);
        ~Scaling() = default;
};

class ScalingFactory: public rayTracer::IFactory<ITransformations<double>> {
    public:
        ScalingFactory() = default;
        ~ScalingFactory() = default;

        std::shared_ptr<ITransformations<double>> build(double x, double y, double z) final;
};

#endif /* !SCALING_HPP_ */
