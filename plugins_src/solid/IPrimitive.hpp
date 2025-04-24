/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Primitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "../../libs/math/Ray.hpp"

namespace Solid {
    class IPrimitive {
        public:
            ~IPrimitive() = default;
            virtual math::Point getOrigin() const = 0;
            virtual bool hits(math::Ray ray) = 0;
    };
};

#endif /* !IPRIMITIVE_HPP_ */
