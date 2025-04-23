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
            APrimitive(int origin);
            ~APrimitive() = default;
            int getOrigin() const final;
            virtual bool hits(int ray);
        protected:
            int _origin;
    };
};

#endif /* !APRIMITIVE_HPP_ */
