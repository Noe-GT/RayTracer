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
            enum ObjectType {
                PRIMITIVE,
                OTHER
            };

            ~IFactory() = default;
            virtual std::unique_ptr<IPrimitive> build() = 0;
            virtual rayTracer::IFactory::ObjectType getObjectType() const = 0;
    };
};

#endif /* !IFACTORY_HPP_ */
