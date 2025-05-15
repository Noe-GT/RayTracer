/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Scaling
*/

#include "Scaling.hpp"

Scaling::Scaling(double x, double y, double z) :
    ATransformation(3, 3, "scaling")
{
    this->_matrix.setMatrix(0, 0, x);
    this->_matrix.setMatrix(1, 1, y);
    this->_matrix.setMatrix(2, 2, z);
}

std::shared_ptr<ITransformation> ScalingFactory::build(double x, double y, double z)
{
    return std::make_shared<Scaling>(x, y, z);
}

extern "C"
{
    rayTracer::IFactory<ITransformation> *entryPoint()
    {
        return new ScalingFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::TRANSFORMATION;
    }
}
