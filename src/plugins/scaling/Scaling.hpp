/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scaling
*/

#ifndef SCALING_HPP_
#define SCALING_HPP_

#include "ATransformations.hpp"
#include "Matrix.hpp"
#include "IFactory.hpp"
#include "PluginTypes.hpp"

class Scaling : public ATransformation<double>
{
    public:
        Scaling(double x, double y, double z);
        ~Scaling() = default;
};

class ScalingFactory: public rayTracer::IFactory<ITransformation<double>> {
    public:
        ScalingFactory() = default;
        ~ScalingFactory() = default;

        std::shared_ptr<ITransformation<double>> build(double x, double y, double z) final;
};

#endif /* !SCALING_HPP_ */
