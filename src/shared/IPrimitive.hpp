/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Primitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "../static_libs/math/Ray.hpp"

class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual bool intersect(math::Ray &ray) = 0;
};

#endif /* !IPRIMITIVE_HPP_ */
