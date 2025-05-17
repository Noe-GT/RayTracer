/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scaling
*/

#include "Scaling.hpp"

Scaling::Scaling(double x, double y, double z) :
    ATransformations(3, 3)
{
    this->_matrix.setValue(1, 1, x);
    this->_matrix.setValue(2, 2, y);
    this->_matrix.setValue(3, 3, z);
}

std::shared_ptr<ITransformations> ScalingFactory::build(double x, double y, double z)
{
    return std::make_shared<Scaling>(x, y, z);
}

extern "C"
{
    rayTracer::IFactory<ITransformations> *entryPoint()
    {
        return new ScalingFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::TRANSFORMATION;
    }
}
