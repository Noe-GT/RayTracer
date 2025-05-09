/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Translation
*/

#ifndef TRANSLATION_HPP_
#define TRANSLATION_HPP_

#include "../../shared/ATransformations.hpp"
#include "../../static_libs/math/Matrix.hpp"

class Translation : public ATransformations<int>
{
    public:
        Translation(int x, int y, int z);
        ~Translation() = default;
};

#endif /* !TRANSLATION_HPP_ */
