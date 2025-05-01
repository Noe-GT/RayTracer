/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** math::Vector.cpp
*/

#include "Vector.hpp"
#include "Point.hpp"

math::Vector::Vector():
    _x(0),
    _y(0),
    _z(0)
{
}

math::Vector::Vector(const math::Vector &vector):
    _x(vector._x),
    _y(vector._y),
    _z(vector._z)
{
}

math::Vector::Vector(const math::Point &point):
    _x(point._x),
    _y(point._y),
    _z(point._z)
{
}

math::Vector::Vector(double x, double y, double z):
    _x(x),
    _y(y),
    _z(z)
{
}

math::Vector& math::Vector::operator=(const math::Vector &other)
{
    if (this != &other) {
        this->_x = other._x;
        this->_y = other._y;
        this->_z = other._z;
    }
    return *this;
}


math::Vector& math::Vector::operator-() const
{
    math::Vector* result = new math::Vector(-this->_x, -this->_y, -this->_z);
    return * result;
}

math::Vector& math::Vector::operator+=(const math::Vector& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

math::Vector& math::Vector::operator-=(const math::Vector& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    this->_z -= other._z;
    return *this;
}

math::Vector& math::Vector::operator*=(double scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;
    return *this;
}

math::Vector& math::Vector::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_x /= scalar;
    this->_y /= scalar;
    this->_z /= scalar;
    return *this;
}

math::Vector math::Vector::operator+(const math::Vector& other)
{
    return math::Vector(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

math::Vector math::Vector::operator-(const math::Vector& other)
{
    return math::Vector(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}

math::Vector math::Vector::operator*(double scalar)
{
    return math::Vector(this->_x * scalar, this->_y * scalar, this->_z * scalar);
}

math::Vector math::Vector::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return math::Vector(this->_x / scalar, this->_y / scalar, this->_z / scalar);
}

double math::Vector::Length() const
{
    return std::sqrt(LengthSquared());
}

double math::Vector::LengthSquared() const
{
    return this->_x * this->_x + this->_y * this->_y + this->_z * this->_z;
}

double math::Vector::dotProduct(const math::Vector &other) const
{
    return (this->_x * other._x)
        + (this->_y * other._y)
        + (this->_z * other._z);
}

namespace math {
    std::ostream& operator<<(std::ostream& out, const math::Vector& v) {
        return out << v._x << ' ' << v._y << ' ' << v._z;
    }
};


math::Vector math::Vector::cross(const Vector& other) const
{
    return Vector(
        _y * other._z - _z * other._y,
        _z * other._x - _x * other._z,
        _x * other._y - _y * other._x
    );
}

math::Vector math::Vector::normalize() const
{
    double len = Length();
    if (len == 0) return *this;
    return Vector(_x / len, _y / len, _z / len);
}