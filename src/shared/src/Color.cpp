/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color.cpp
*/

#include "../include/Color.hpp"

Color::Color(): _x(0), _y(0), _z(0)
{
}

Color::Color(Color &Color): _x(Color._x), _y(Color._y), _z(Color._z)
{

}
Color::Color(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

Color& Color::operator-() const
{
    Color* result = new Color(-this->_x, -this->_y, -this->_z);
    return * result;
}

Color& Color::operator+=(const Color& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

Color& Color::operator-=(const Color& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    this->_z -= other._z;
    return *this;
}

Color& Color::operator*=(double scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;
    return *this;
}

Color& Color::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_x /= scalar;
    this->_y /= scalar;
    this->_z /= scalar;
    return *this;
}

Color Color::operator+(const Color& other)
{
    return Color(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

Color Color::operator-(const Color& other)
{
    return Color(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}

Color Color::operator*(double scalar)
{
    return Color(this->_x * scalar, this->_y * scalar, this->_z * scalar);
}

Color Color::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return Color(this->_x / scalar, this->_y / scalar, this->_z / scalar);
}

std::ostream& operator<<(std::ostream& out, const Color& v) {
    return out << v._x << ' ' << v._y << ' ' << v._z;
}