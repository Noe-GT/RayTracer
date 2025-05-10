/*
** EPITECH PROJECT, 2024
** math::raytracer
** File description:
** math::Ray.cpp
*/
#include "Ray.hpp"

math::Ray::Ray()
{
}

math::Ray::Ray(math::Point origin, math::Vector direction, math::Color color):
    _origin(origin),
    _direction(direction),
    _color(color)
{
}

math::Ray::Ray(math::Point origin, math::Vector direction):
    _origin(origin),
    _direction(direction)
{
}

math::Ray::Ray(double x, double y, double z):
    _origin(x,y,z)
{
}

math::Ray::Ray(double ox, double oy, double oz, double dx, double dy, double dz):
    _origin(ox, oy, oz),
    _direction(dx, dy, dz)
{
}

math::Ray::Ray(double ox, double oy, double oz, double dx, double dy, double dz, double r, double g, double b):
    _origin(ox, oy, oz),
    _direction(dx, dy, dz),
    _color(r, g, b)
{
}

math::Ray& math::Ray::operator+=(const math::Ray& other)
{
    this->_origin += other._origin;
    this->_direction += other._direction;
    this->_color += other._color;
    return *this;
}

math::Ray& math::Ray::operator-=(const math::Ray& other)
{
    this->_origin -= other._origin;
    this->_direction -= other._direction;
    this->_color -= other._color;
    return *this;
}

math::Ray& math::Ray::operator*=(double t)
{
    this->_origin *= t;
    this->_direction *= t;
    this->_color *= t;
    return *this;
}

math::Ray& math::Ray::operator/=(double t) {
    if (t == 0.0)
        throw std::runtime_error("Division by zero");
    this->_origin /= t;
    this->_direction /= t;
    this->_color /= t;
    return *this;
}

math::Ray& math::Ray::operator+=(const math::Point& other)
{
    this->_origin += other;
    return *this;
}

math::Ray& math::Ray::operator-=(const math::Point& other)
{
    this->_origin -= other;
    return *this;
}

math::Ray& math::Ray::operator*=(const math::Point& other)
{
    this->_origin._x *= other._x;
    this->_origin._y *= other._y;
    this->_origin._z *= other._z;
    return *this;
}

math::Ray& math::Ray::operator/=(const math::Point& other)
{
    this->_origin._x /= other._x;
    this->_origin._y /= other._y;
    this->_origin._z /= other._z;
    return *this;
}

math::Ray& math::Ray::operator+=(const math::Vector& other)
{
    _direction += other;
    return *this;
}

math::Ray& math::Ray::operator-=(const math::Vector& other)
{
    _direction -= other;
    return *this;
}

math::Ray& math::Ray::operator*=(const math::Vector& other)
{
    this->_direction._x *= other._x;
    this->_direction._y *= other._y;
    this->_direction._z *= other._z;
    return *this;
}

math::Ray& math::Ray::operator/=(const math::Vector& other)
{
    this->_direction._x /= other._x;
    this->_direction._y /= other._y;
    this->_direction._z /= other._z;
    return *this;
}

math::Ray& math::Ray::operator+=(const math::Color& other)
{
    _color += other;
    return *this;
}

math::Ray& math::Ray::operator-=(const math::Color& other)
{
    _color -= other;
    return *this;
}

math::Ray& math::Ray::operator*=(const math::Color& other)
{
    this->_color._r /= other._r;
    this->_color._g /= other._g;
    this->_color._b /= other._b;
    return *this;
}

math::Ray& math::Ray::operator/=(const math::Color& other)
{
    this->_color._r /= other._r;
    this->_color._g /= other._g;
    this->_color._b /= other._b;
    return *this;
}

math::Ray math::Ray::operator+(const math::Ray& other)
{
    math::Ray result(*this);
    result += other;
    return result;
}

math::Ray math::Ray::operator+(const math::Point& other)
{
    math::Ray result(*this);
    result += other;
    return result;
}

math::Ray math::Ray::operator+(const math::Vector& other)
{
    math::Ray result(*this);
    result += other;
    return result;
}

math::Ray math::Ray::operator+(const math::Color& other)
{
    math::Ray result(*this);
    result += other;
    return result;
}

math::Ray math::Ray::operator-(const math::Ray& other)
{
    math::Ray result(*this);
    result -= other;
    return result;
}

math::Ray math::Ray::operator-(const math::Point& other)
{
    math::Ray result(*this);
    result -= other;
    return result;
}

math::Ray math::Ray::operator-(const math::Vector& other)
{
    math::Ray result(*this);
    result -= other;
    return result;
}

math::Ray math::Ray::operator-(const math::Color& other)
{
    math::Ray result(*this);
    result -= other;
    return result;
}

math::Ray math::Ray::operator*(const double t)
{
    math::Ray result(*this);
    result *= t;
    return result;
}

math::Ray math::Ray::operator*(const math::Point& other)
{
    math::Ray result(*this);
    result *= other;
    return result;
}

math::Ray math::Ray::operator*(const math::Vector& other)
{
    math::Ray result(*this);
    result *= other;
    return result;
}

math::Ray math::Ray::operator*(const math::Color& other)
{
    math::Ray result(*this);
    result *= other;
    return result;
}

math::Ray math::Ray::operator/(const double t)
{
    math::Ray result(*this);
    result /= t;
    return result;
}

math::Ray math::Ray::operator/(const math::Point& other)
{
    math::Ray result(*this);
    result /= other;
    return result;
}

math::Ray math::Ray::operator/(const math::Vector& other)
{
    math::Ray result(*this);
    result /= other;
    return result;
}

math::Ray math::Ray::operator/(const math::Color& other)
{
    math::Ray result(*this);
    result /= other;
    return result;
}

namespace math {
    std::ostream& operator<<(std::ostream& out, const math::Ray& v) {
        return out << "oringin: " << v._origin << "\ndestination: " << v._direction << "\nmath::color " << v._color;
    }
};

math::Ray operator-(const math::Ray& other)
{
    math::Ray result(0, 0, 0, 0, 0, 0, 0, 0, 0);

    result._color._r = -other._color._r;
    result._color._g = -other._color._g;
    result._color._b = -other._color._b;
    result._direction._x = -other._direction._x;
    result._direction._y = -other._direction._y;
    result._direction._z = -other._direction._z;
    result._origin._x = -other._origin._x;
    result._origin._y = -other._origin._y;
    result._origin._z = -other._origin._z;
    return result;
}