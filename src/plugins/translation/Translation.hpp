/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#ifndef TRANSLATION_HPP_
#define TRANSLATION_HPP_

#include "ATransformations.hpp"
#include "Matrix.hpp"
#include "IFactory.hpp"
#include "PluginTypes.hpp"

class Translation : public ATransformations
{
    public:
        Translation(double x, double y, double z);
        ~Translation() = default;
};

class TranslationFactory: public rayTracer::IFactory<ITransformations> {
    public:
        TranslationFactory() = default;
        ~TranslationFactory() = default;

        std::shared_ptr<ITransformations> build(double x, double y, double z) final;
};

#endif /* !TRANSLATION_HPP_ */
