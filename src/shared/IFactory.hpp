/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IFactory
*/

#ifndef IFACTORY_HPP_
#define IFACTORY_HPP_

#include "IPrimitive.hpp"

namespace rayTracer {
    template <typename T>
    class IFactory {
        public:
            virtual ~IFactory() = default;
            virtual std::shared_ptr<T> build() = 0;
    };
};

#endif /* !IFACTORY_HPP_ */
