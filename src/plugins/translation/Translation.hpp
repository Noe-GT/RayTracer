/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#ifndef TRANSLATION_HPP_
#define TRANSLATION_HPP_

#include "ATransformation.hpp"
#include "Matrix.hpp"
#include "IFactory.hpp"
#include "PluginTypes.hpp"

class Translation : public ATransformation
{
    public:
        Translation(double x, double y, double z);
        ~Translation() = default;
};

class TranslationFactory: public rayTracer::IFactory<ITransformation> {
    public:
        TranslationFactory() = default;
        ~TranslationFactory() = default;

        std::shared_ptr<ITransformation> build(double x, double y, double z) final;
};

#endif /* !TRANSLATION_HPP_ */
