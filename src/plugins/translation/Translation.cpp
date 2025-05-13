/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"

Translation::Translation(double x, double y, double z) :
    ATransformations(1, 3)
{
    this->_matrix.setMatrix(0, 0, x);
    this->_matrix.setMatrix(0, 1, y);
    this->_matrix.setMatrix(0, 2, z);
}

std::shared_ptr<ITransformations> TranslationFactory::build(double x, double y, double z)
{
    return std::make_shared<Translation>(x, y, z);
}

extern "C"
{
    rayTracer::IFactory<ITransformations> *entryPoint()
    {
        return new TranslationFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::TRANSFORMATION;
    }
}
