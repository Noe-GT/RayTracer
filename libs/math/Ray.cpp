/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray.cpp
*/
#include "Ray.hpp"

Ray::Ray()
{
}

Ray::Ray(Point origin, Vector direction, Color color): _origin(origin), _direction(direction), _color(color)
{
}

Ray::Ray(Point origin, Vector direction): _origin(origin), _direction(direction)
{
}

Ray::Ray(double x, double y, double z): _origin(x,y,z)
{
}

Ray::Ray(double ox, double oy, double oz, double dx, double dy, double dz): _origin(ox, oy, oz), _direction(dx, dy, dz)
{
}

Ray::Ray(double ox, double oy, double oz, double dx, double dy, double dz, double r, double g, double b): _origin(ox, oy, oz), _direction(dx, dy, dz), _color(r, g, b)
{
}

Ray& Ray::operator+=(const Ray& other)
{
    this->_origin += other._origin;
    this->_direction += other._direction;
    this->_color += other._color;
    return *this;
}

Ray& Ray::operator-=(const Ray& other)
{
    this->_origin -= other._origin;
    this->_direction -= other._direction;
    this->_color -= other._color;
    return *this;
}

Ray& Ray::operator*=(double t)
{
    this->_origin *= t;
    this->_direction *= t;
    this->_color *= t;
    return *this;
}

Ray& Ray::operator/=(double t) {
    if (t == 0.0)
        throw std::runtime_error("Division by zero");
    this->_origin /= t;
    this->_direction /= t;
    this->_color /= t;
    return *this;
}

Ray& Ray::operator+=(const Point& other)
{
    this->_origin += other;
    return *this;
}

Ray& Ray::operator-=(const Point& other)
{
    this->_origin -= other;
    return *this;
}

Ray& Ray::operator*=(const Point& other)
{
    this->_origin._x *= other._x;
    this->_origin._y *= other._y;
    this->_origin._z *= other._z;
    return *this;
}

Ray& Ray::operator/=(const Point& other)
{
    this->_origin._x /= other._x;
    this->_origin._y /= other._y;
    this->_origin._z /= other._z;
    return *this;
}

Ray& Ray::operator+=(const Vector& other)
{
    _direction += other;
    return *this;
}

Ray& Ray::operator-=(const Vector& other)
{
    _direction -= other;
    return *this;
}

Ray& Ray::operator*=(const Vector& other)
{
    this->_direction._x *= other._x;
    this->_direction._y *= other._y;
    this->_direction._z *= other._z;
    return *this;
}

Ray& Ray::operator/=(const Vector& other)
{
    this->_direction._x /= other._x;
    this->_direction._y /= other._y;
    this->_direction._z /= other._z;
    return *this;
}

Ray& Ray::operator+=(const Color& other)
{
    _color += other;
    return *this;
}

Ray& Ray::operator-=(const Color& other)
{
    _color -= other;
    return *this;
}

Ray& Ray::operator*=(const Color& other)
{
    this->_color._r /= other._r;
    this->_color._g /= other._g;
    this->_color._b /= other._b;
    return *this;
}

Ray& Ray::operator/=(const Color& other)
{
    this->_color._r /= other._r;
    this->_color._g /= other._g;
    this->_color._b /= other._b;
    return *this;
}

Ray Ray::operator+(const Ray& other)
{
    Ray result(*this);
    result += other;
    return result;
}

Ray Ray::operator+(const Point& other)
{
    Ray result(*this);
    result += other;
    return result;
}

Ray Ray::operator+(const Vector& other)
{
    Ray result(*this);
    result += other;
    return result;
}

Ray Ray::operator+(const Color& other)
{
    Ray result(*this);
    result += other;
    return result;
}

Ray Ray::operator-(const Ray& other)
{
    Ray result(*this);
    result -= other;
    return result;
}

Ray Ray::operator-(const Point& other)
{
    Ray result(*this);
    result -= other;
    return result;
}

Ray Ray::operator-(const Vector& other)
{
    Ray result(*this);
    result -= other;
    return result;
}

Ray Ray::operator-(const Color& other)
{
    Ray result(*this);
    result -= other;
    return result;
}

Ray Ray::operator*(const double t)
{
    Ray result(*this);
    result *= t;
    return result;
}

Ray Ray::operator*(const Point& other)
{
    Ray result(*this);
    result *= other;
    return result;
}

Ray Ray::operator*(const Vector& other)
{
    Ray result(*this);
    result *= other;
    return result;
}

Ray Ray::operator*(const Color& other)
{
    Ray result(*this);
    result *= other;
    return result;
}

Ray Ray::operator/(const double t)
{
    Ray result(*this);
    result /= t;
    return result;
}

Ray Ray::operator/(const Point& other)
{
    Ray result(*this);
    result /= other;
    return result;
}

Ray Ray::operator/(const Vector& other)
{
    Ray result(*this);
    result /= other;
    return result;
}

Ray Ray::operator/(const Color& other)
{
    Ray result(*this);
    result /= other;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Ray& v) {
    return out << "oringin: " << v._origin << "\ndestination: " << v._direction << "\ncolor " << v._color;
}

Ray operator-(const Ray& other)
{
    Ray result(0, 0, 0, 0, 0, 0, 0, 0, 0);

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