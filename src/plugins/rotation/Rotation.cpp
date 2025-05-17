/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Rotation
*/

#include "Rotation.hpp"

Rotation::Rotation(double x, double y, double z) :
    ATransformations(3, 3)
{
    for (size_t i = 1; i <= 3; i++)
        this->_matrix.setValue(i, i, 1.0);

    math::Matrix mX(this->_matrix);
    mX.setValue(2, 2, cos(x));
    mX.setValue(3, 2, -sin(x));
    mX.setValue(2, 3, sin(x));
    mX.setValue(3, 3, cos(x));

    math::Matrix mY(this->_matrix);
    mY.setValue(1, 1, cos(y));
    mY.setValue(3, 1, sin(y));
    mY.setValue(1, 3, -sin(y));
    mY.setValue(3, 3, cos(y));

    math::Matrix mZ(this->_matrix);
    mZ.setValue(1, 1, cos(z));
    mZ.setValue(2, 1, -sin(z));
    mZ.setValue(1, 2, sin(z));
    mZ.setValue(2, 2, cos(z));

    this->_matrix = mZ * (mY * mX);
}

std::shared_ptr<ITransformations> RotationFactory::build(double x, double y, double z)
{
    return std::make_shared<Rotation>(x, y, z);
}

extern "C"
{
    rayTracer::IFactory<ITransformations> *entryPoint()
    {
        return new RotationFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::TRANSFORMATION;
    }
}
