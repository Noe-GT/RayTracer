/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Rotation
*/

#ifndef ROTATION_HPP_
#define ROTATION_HPP_

#include "../../shared/ATransformations.hpp"
#include "../../static_libs/math/Matrix.hpp"
#include "../../shared/Exceptions.hpp"
#include <cmath>

template<typename T>
class Rotation : public ATransformations<T>
{
    public:
        Rotation(T x, T y, T z)
        {
            if (!std::is_arithmetic_v<T>)
                rayTracer::TypeException("Rotation: T type must be arithmetic");

            math::Matrix<T> mRef(3, 3);
            for (size_t i = 0; i <= 2; i++)
                mRef.setMatrix(i, i, 1.0);

            math::Matrix mX(mRef);
            mX.setMatrix(1, 1, cos(x));
            mX.setMatrix(1, 2, -sin(x));
            mX.setMatrix(2, 1, sin(x));
            mX.setMatrix(2, 2, cos(x));

            math::Matrix mY(mRef);
            mY.setMatrix(0, 0, cos(y));
            mY.setMatrix(0, 2, sin(y));
            mY.setMatrix(2, 0, -sin(y));
            mY.setMatrix(2, 2, cos(y));

            math::Matrix mZ(mRef);
            mZ.setMatrix(0, 0, cos(z));
            mZ.setMatrix(0, 1, -sin(z));
            mZ.setMatrix(1, 0, sin(z));
            mZ.setMatrix(1, 1, cos(z));

            this->_matrix = mZ * (mY * mX);
        }

        ~Rotation() = default;
};

#endif /* !ROTATION_HPP_ */
