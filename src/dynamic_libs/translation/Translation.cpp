/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#include "Translation.hpp"

Translation::Translation(int x, int y, int z) :
    ATransformations<int>(1, 3)
{
    this->_matrix.setMatrix(0, 0, x);
    this->_matrix.setMatrix(0, 1, y);
    this->_matrix.setMatrix(0, 2, z);
}

std::shared_ptr<ITransformations<int>> TranslationFactory::build(int x, int y, int z)
{
    return std::make_shared<Translation>(x, y, z);
}

extern "C"
{
    rayTracer::IFactory<ITransformations<int>> *entryPoint()
    {
        return new TranslationFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::TRANSFORMATION;
    }
}
