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

    // class IGraphicalFactory : public IFactory<IGraphical> {
    //     public:
    //         virtual ~IGraphicalFactory() = default;
    //         virtual std::shared_ptr<IGraphical> build() = 0;
    //         virtual std::shared_ptr<IGraphical> build(size_t width, size_t height) = 0;
    // };
};

#endif /* !IFACTORY_HPP_ */
