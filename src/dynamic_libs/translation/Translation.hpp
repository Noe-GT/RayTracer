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
        Translation(int x, int y, int z)
        {
            math::Matrix<int> mRef(1, 3);

            mRef.setMatrix(0, 0, x);
            mRef.setMatrix(0, 1, y);
            mRef.setMatrix(0, 2, z);
            this->_matrix = mRef;
        }

        ~Translation() = default;
};

#endif /* !TRANSLATION_HPP_ */
