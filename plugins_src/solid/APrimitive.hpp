/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Primitive
*/

#ifndef APRIMITIVE_HPP_
#define APRIMITIVE_HPP_

#include "IPrimitive.hpp"

namespace Solid {
    class APrimitive : public Solid::IPrimitive
    {
        public:
            APrimitive();
            APrimitive(math::Point origin);
            ~APrimitive() = default;
            math::Point getOrigin() const final;
            virtual bool hits(math::Ray ray);
        protected:
            math::Point _origin;
    };
};

#endif /* !APRIMITIVE_HPP_ */
