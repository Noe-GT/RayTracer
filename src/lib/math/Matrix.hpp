/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Matrix
*/

#pragma once

#include <vector>
#include <utility>
#include <type_traits>
#include "Exceptions.hpp"

namespace math
{
    template<typename T>
    class Matrix
    {
        public:
            class MatrixException : public rayTracer::Exception
            {
                public:
                    MatrixException(const std::string &exception) noexcept :
                        Exception(exception)
                    {
                    }

                    ~MatrixException() noexcept final = default;
            };

            Matrix(size_t x, size_t y)
            {
                if (!std::is_arithmetic_v<T>)
                    throw rayTracer::TypeException("Matrix: T type must be arithmetic");
                this->_matrix.resize(y, std::vector<T>());
                for (size_t i = 0; i < y; i++)
                    this->_matrix[i].resize(x, static_cast<T>(0));
            }

            Matrix(const Matrix &matrix) = default;

            Matrix(Matrix &&matrix) :
                _matrix(matrix._matrix)
            {
            }

            ~Matrix() = default;

            Matrix &operator=(const Matrix &matrix)
            {
                this->_matrix = matrix._matrix;
                return *this;
            }

            Matrix operator+(const Matrix &matrix) const
            {
                if (this->getDimensions() != matrix.getDimensions())
                    throw MatrixException("operator+: both matrices must be of the same size");
            
                Matrix res(*this);
            
                res += matrix;
                return res;
            }

            Matrix &operator+=(const Matrix &matrix)
            {
                if (this->getDimensions() != matrix.getDimensions())
                    throw MatrixException("operator+=: both matrices must be of the same size");
                for (size_t y = 0; y < this->_matrix.size(); y++)
                    for (size_t x = 0; x < this->_matrix[y].size(); x++)
                        this->_matrix[y][x] += matrix._matrix[y][x];
                return *this;
            }

            Matrix operator-(const Matrix &matrix) const
            {
                if (this->getDimensions() != matrix.getDimensions())
                    throw MatrixException("operator-: both matrices must be of the same size");
            
                Matrix res(*this);
            
                res -= matrix;
                return res;
            }

            Matrix &operator-=(const Matrix &matrix)
            {
                if (this->getDimensions() != matrix.getDimensions())
                    throw MatrixException("operator-=: both matrices must be of the same size");
                for (size_t y = 0; y < this->_matrix.size(); y++)
                    for (size_t x = 0; x < this->_matrix[y].size(); x++)
                        this->_matrix[y][x] -= matrix._matrix[y][x];
                return *this;
            }

            Matrix operator*(const Matrix &matrix) const
            {
                if (this->getWidth() != matrix.getHeight())
                    throw MatrixException("operator*: 1st matrix must have the same number of columns as 2nd matrix's number of rows");
            
                Matrix res(*this);
            
                res *= matrix;
                return res;
            }

            Matrix &operator*=(const Matrix &matrix)
            {
                if (this->getWidth() != matrix.getHeight())
                    throw MatrixException("operator*=: 1st matrix must have the same number of columns as 2nd matrix's number of rows");
            
                Matrix res(this->getHeight(), matrix.getWidth());
            
                for (size_t y = 0; y < res.getHeight(); y++)
                    for (size_t x = 0; x < res.getWidth(); x++)
                        for (size_t z = 0; z < this->getWidth(); z++)
                            res._matrix[y][x] += this->_matrix[y][z] * matrix._matrix[z][x];
                *this = res;
                return *this;
            }

            Matrix operator*(int n) const
            {
                Matrix res(*this);
            
                res *= n;
                return res;
            }

            Matrix &operator*=(int n)
            {
                for (size_t y = 0; y < this->getHeight(); y++)
                    for (size_t x = 0; x < this->getWidth(); x++)
                        this->_matrix[y][x] *= n;
                return *this;
            }

            void reset()
            {
                for (size_t y = 1; y <= this->getHeight(); y++)
                    for (size_t x = 1; x <= this->getWidth(); x++)
                        this->setValue(x, y, static_cast<T>(0));
            }

            void resize(size_t x, size_t y)
            {
                this->_matrix.resize(y, std::vector<T>());
                for (size_t i = 0; i < y; i++)
                    this->_matrix[i].resize(x, static_cast<T>(0));
            }

            size_t getWidth() const
            {
                if (this->_matrix.size() == 0)
                    throw MatrixException("getWidth: empty matrix");
                return this->_matrix[0].size();
            }

            size_t getHeight() const
            {
                return this->_matrix.size();
            }

            std::pair<size_t, size_t> getDimensions() const
            {
                return std::make_pair<size_t, size_t>(this->getWidth(), this->getHeight());
            }

            std::vector<std::vector<T>> getMatrix() const
            {
                return this->_matrix;
            }

            void setValue(size_t x, size_t y, T newVal)
            {
                if (y == 0 || y > this->getHeight())
                    throw MatrixException("setMatrix: invalid y index");
                if (x == 0 || x > this->getWidth())
                    throw MatrixException("setMatrix: invalid x index");
                this->_matrix[y - 1][x - 1] = newVal;
            }

            T getValue(size_t x, size_t y) const
            {
                if (y == 0 || y > this->getHeight())
                    throw MatrixException("setMatrix: invalid y index");
                if (x == 0 || x > this->getWidth())
                    throw MatrixException("setMatrix: invalid x index");
                return this->_matrix[y - 1][x - 1];
            }

        private:
            std::vector<std::vector<T>> _matrix;
    };
}
