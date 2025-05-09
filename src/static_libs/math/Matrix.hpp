/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Matrix
*/

#pragma once

#include <vector>
#include <utility>
#include "../../shared/Exceptions.hpp"

namespace math {
    class Matrix {
        public:
            class MatrixException : public rayTracer::Exception {
                public:
                    MatrixException(const std::string &exception) noexcept;
                    ~MatrixException() noexcept = default;
            };

            Matrix(size_t x, size_t y);
            Matrix(const Matrix &matrix);
            Matrix(const Matrix &&matrix);
            ~Matrix() = default;

            Matrix &operator=(const Matrix &matrix);

            Matrix operator+(const Matrix &matrix) const;
            Matrix &operator+=(const Matrix &matrix);
            Matrix operator-(const Matrix &matrix) const;
            Matrix &operator-=(const Matrix &matrix);
            Matrix operator*(const Matrix &matrix) const;
            Matrix &operator*=(const Matrix &matrix);

            void reset(size_t x, size_t y);
            void resize(size_t x, size_t y);

            size_t getWidth() const;
            size_t getHeight() const;
            std::pair<size_t, size_t> getDimensions() const;
            std::vector<std::vector<int>> getMatrix() const;
            void setMatrix(size_t x, size_t y, int newVal);
    
        private:
            std::vector<std::vector<int>> _matrix;
    };
}
