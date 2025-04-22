/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Primitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

namespace Solid {
    class IPrimitive {
        public:
            ~IPrimitive() = default;
            virtual int getOrigin() const = 0;
            virtual bool hits(int ray) = 0;
    };
};

#endif /* !IPRIMITIVE_HPP_ */
