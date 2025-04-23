/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color.cpp
*/

#include "../include/Color.hpp"

Color::Color(): _r(0), _g(0), _b(0)
{
}

Color::Color(Color &Color): _r(Color._r), _g(Color._g), _b(Color._b)
{

}
Color::Color(double x, double y, double z): _r(x), _g(y), _b(z)
{
}

Color& Color::operator-() const
{
    Color* result = new Color(-this->_r, -this->_g, -this->_b);
    return * result;
}

Color& Color::operator+=(const Color& other)
{
    this->_r += other._r;
    this->_g += other._g;
    this->_b += other._b;
    return *this;
}

Color& Color::operator-=(const Color& other)
{
    this->_r -= other._r;
    this->_g -= other._g;
    this->_b -= other._b;
    return *this;
}

Color& Color::operator*=(double scalar)
{
    this->_r *= scalar;
    this->_g *= scalar;
    this->_b *= scalar;
    return *this;
}

Color& Color::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_r /= scalar;
    this->_g /= scalar;
    this->_b /= scalar;
    return *this;
}

Color Color::operator+(const Color& other)
{
    return Color(this->_r + other._r, this->_g + other._g, this->_b + other._b);
}

Color Color::operator-(const Color& other)
{
    return Color(this->_r - other._r, this->_g - other._g, this->_b - other._b);
}

Color Color::operator*(double scalar)
{
    return Color(this->_r * scalar, this->_g * scalar, this->_b * scalar);
}

Color Color::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return Color(this->_r / scalar, this->_g / scalar, this->_b / scalar);
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    os << static_cast<int>(255.999 * c._r) << ' '
       << static_cast<int>(255.999 * c._g) << ' '
       << static_cast<int>(255.999 * c._b) << '\n';
    return os;
}