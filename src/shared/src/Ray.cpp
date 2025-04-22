/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray.cpp
*/
#include "../include/Ray.hpp"

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
    this->_color._x /= other._x;
    this->_color._y /= other._y;
    this->_color._z /= other._z;
    return *this;
}

Ray& Ray::operator/=(const Color& other)
{
    this->_color._x /= other._x;
    this->_color._y /= other._y;
    this->_color._z /= other._z;
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