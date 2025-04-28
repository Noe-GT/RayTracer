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
    class IFactory {
        public:
            ~IFactory() = default;
            virtual std::unique_ptr<IPrimitive> build() = 0;
    };
};

#endif /* !IFACTORY_HPP_ */
