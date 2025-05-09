/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Matrix
*/

#include "Matrix.hpp"

math::Matrix::MatrixException::MatrixException(const std::string &exception) noexcept :
    Exception(exception)
{
}

math::Matrix::Matrix(size_t x, size_t y)
{
    this->_matrix.resize(y, std::vector<int>());
    for (size_t i = 0; i < y; i++)
        this->_matrix[i].resize(0, x);
}

math::Matrix::Matrix(const Matrix &matrix) :
    _matrix(matrix._matrix)
{
}

math::Matrix::Matrix(const Matrix &&matrix) :
    _matrix(matrix._matrix)
{
}

math::Matrix &math::Matrix::operator=(const Matrix &matrix)
{
    this->_matrix = matrix._matrix;
    return *this;
}

math::Matrix math::Matrix::operator+(const math::Matrix &matrix) const
{
    if (this->getDimensions() != matrix.getDimensions())
        throw MatrixException("operator+: both matrices must be of the same size");

    Matrix res(*this);

    res += matrix;
    return res;
}

math::Matrix &math::Matrix::operator+=(const math::Matrix &matrix)
{
    if (this->getDimensions() != matrix.getDimensions())
        throw MatrixException("operator+=: both matrices must be of the same size");
    for (size_t y = 0; y < this->_matrix.size(); y++)
        for (size_t x = 0; x < this->_matrix[y].size(); x++)
            this->_matrix[y][x] += matrix._matrix[y][x];
    return *this;
}

math::Matrix math::Matrix::operator-(const math::Matrix &matrix) const
{
    if (this->getDimensions() != matrix.getDimensions())
        throw MatrixException("operator-: both matrices must be of the same size");

    Matrix res(*this);

    res -= matrix;
    return res;
}

math::Matrix &math::Matrix::operator-=(const math::Matrix &matrix)
{
    if (this->getDimensions() != matrix.getDimensions())
        throw MatrixException("operator-=: both matrices must be of the same size");
    for (size_t y = 0; y < this->_matrix.size(); y++)
        for (size_t x = 0; x < this->_matrix[y].size(); x++)
            this->_matrix[y][x] -= matrix._matrix[y][x];
    return *this;
}

math::Matrix math::Matrix::operator*(const math::Matrix &matrix) const
{
    if (this->getWidth() != matrix.getHeight())
        throw MatrixException("operator*: 1st matrix must have the same number of columns as 2nd matrix's number of rows");

    Matrix res(*this);

    res *= matrix;
    return res;
}

math::Matrix &math::Matrix::operator*=(const math::Matrix &matrix)
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

void math::Matrix::reset(size_t x, size_t y)
{
    for (size_t i = 0; i < y; i++)
        this->_matrix[i].clear();
    this->_matrix.clear();
    this->resize(x, y);
}

void math::Matrix::resize(size_t x, size_t y)
{
    this->_matrix.resize(y, std::vector<int>());
    for (size_t i = 0; i < y; i++)
        this->_matrix[i].resize(0, x);
}

size_t math::Matrix::getWidth() const
{
    if (this->_matrix.size() == 0)
        throw MatrixException("getWidth: empty matrix");
    return this->_matrix[0].size();
}

size_t math::Matrix::getHeight() const
{
    return this->_matrix.size();
}

std::pair<size_t, size_t> math::Matrix::getDimensions() const
{
    return std::make_pair<size_t, size_t>(this->getWidth(), this->getHeight());
}

std::vector<std::vector<int>> math::Matrix::getMatrix() const
{
    return this->_matrix;
}

void math::Matrix::setMatrix(size_t x, size_t y, int newVal)
{
    if (y >= this->getHeight())
        throw MatrixException("setMatrix: invalid y index");
    if (x >= this->getWidth())
        throw MatrixException("setMatrix: invalid x index");
    this->_matrix[y][x] = newVal;
}
