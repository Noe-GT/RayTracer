/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** ATransformation
*/

#pragma once

#include "ITransformation.hpp"
#include "Matrix.hpp"

template<typename T>
class ATransformation : public ITransformation<T>
{
    public:
        ATransformation(size_t x, size_t y, std::string name) :
            _matrix(x, y), _name(name)
        {
        }

        ~ATransformation() = default;

        math::Matrix<T> getMatrix() const final
        {
            return this->_matrix;
        }

        const std::string getName() override {
            return this->_name;
        }

    protected:
        math::Matrix<T> _matrix;
        std::string _name;
};
