/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IFactory
*/

#ifndef IFACTORY_HPP_
#define IFACTORY_HPP_

#include "IPrimitive.hpp"
#include "IGraphical.hpp"
#include "ITransformation.hpp"

namespace rayTracer {
    template <typename T>
    class IFactory {
        public:
            virtual ~IFactory() = default;
            virtual std::shared_ptr<T> build() = 0;
    };

    template <>
    class IFactory<IGraphical> {
        public:
            virtual ~IFactory() = default;
            virtual std::shared_ptr<IGraphical> build() = 0;
            virtual std::shared_ptr<IGraphical> build(size_t width, size_t height) = 0;
    };

    template <>
    class IFactory<ITransformation> {
        public:
            virtual ~IFactory() = default;
            virtual std::shared_ptr<ITransformation> build(double x, double y, double z) = 0;
    };
};

#endif /* !IFACTORY_HPP_ */
