/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** math::Point.cpp
*/

#include "Point.hpp"

math::Point::Point(): _x(0), _y(0), _z(0)
{
}

math::Point::Point(const math::Point &point):
    _x(point._x),
    _y(point._y),
    _z(point._z)
{
}

math::Point::Point(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

math::Point& math::Point::operator-() const
{
    math::Point* result = new math::Point(-this->_x, -this->_y, -this->_z);
    return * result;
}

math::Point& math::Point::operator+=(const math::Point& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

math::Point& math::Point::operator-=(const math::Point& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    this->_z -= other._z;
    return *this;
}

math::Point& math::Point::operator*=(double scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;
    return *this;
}

math::Point& math::Point::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_x /= scalar;
    this->_y /= scalar;
    this->_z /= scalar;
    return *this;
}

math::Point math::Point::operator+(const math::Point& other)
{
    return math::Point(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

math::Point math::Point::operator-(const math::Point& other)
{
    return math::Point(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}

math::Point math::Point::operator*(double scalar)
{
    return math::Point(this->_x * scalar, this->_y * scalar, this->_z * scalar);
}

math::Point math::Point::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return math::Point(this->_x / scalar, this->_y / scalar, this->_z / scalar);
}

namespace math {
    std::ostream& operator<<(std::ostream& out, const math::Point& v) {
        return out << v._x << ' ' << v._y << ' ' << v._z;
    }
};

math::Point & math::Point::operator+=(const Vector& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

math::Point &math::Point::operator-=(const Vector& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

math::Point math::Point::operator+(const Vector& other)
{
    return math::Point(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

math::Point math::Point::operator-(const Vector& other)
{
    return math::Point(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}
