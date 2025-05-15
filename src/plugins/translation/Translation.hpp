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

class Translation : public ATransformation<int>
{
    public:
        Translation(int x, int y, int z);
        ~Translation() = default;
};

class TranslationFactory: public rayTracer::IFactory<ITransformation<int>> {
    public:
        TranslationFactory() = default;
        ~TranslationFactory() = default;

        std::shared_ptr<ITransformation<int>> build(int x, int y, int z) final;
};

#endif /* !TRANSLATION_HPP_ */
