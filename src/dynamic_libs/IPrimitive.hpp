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
        ~IPrimitive() = default;
        virtual bool Intersect(math::Ray &ray) = 0;
};

#endif /* !IPRIMITIVE_HPP_ */
