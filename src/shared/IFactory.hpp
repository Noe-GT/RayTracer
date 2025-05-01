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
            virtual std::shared_ptr<IPrimitive> build() = 0;
            virtual rayTracer::IFactory::ObjectType getObjectType() const = 0;
    };
};

// namespace rayTracer {
//     template <typename T>
//     class IFactory {
//         public:
//             enum ObjectType {
//                 PRIMITIVE,
//                 OTHER
//             };

//             virtual ~IFactory() = default;

//             // Pure virtual method to build an object of type T
//             virtual std::shared_ptr<T> build() = 0;

//             // Pure virtual method to get the object type
//             virtual rayTracer::IFactory<T>::ObjectType getObjectType() const = 0;
//     };
// };
#endif /* !IFACTORY_HPP_ */
