/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"

Translation::Translation(double x, double y, double z) :
    ATransformation(1, 3, "translation")
{
    this->_matrix.setValue(1, 1, x);
    this->_matrix.setValue(1, 2, y);
    this->_matrix.setValue(1, 3, z);
}

std::shared_ptr<ITransformation> TranslationFactory::build(double x, double y, double z)
{
    return std::make_shared<Translation>(x, y, z);
}

extern "C"
{
    rayTracer::IFactory<ITransformation> *entryPoint()
    {
        return new TranslationFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::TRANSFORMATION;
    }
}