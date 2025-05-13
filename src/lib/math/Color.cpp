/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** math::Color.cpp
*/

#include "Color.hpp"

math::Color::Color(): _r(0), _g(0), _b(0)
{
}

math::Color::Color(const math::Color &color): _r(color._r), _g(color._g), _b(color._b)
{

}

math::Color::Color(double x, double y, double z): _r(x), _g(y), _b(z)
{
}

math::Color math::Color::operator-() const
{
    return Color(-this->_r, -this->_g, -this->_b);
}

math::Color& math::Color::operator=(const math::Color& other)
{
    this->_r = other._r;
    this->_g = other._g;
    this->_b = other._b;
    return *this;
}

math::Color& math::Color::operator+=(const math::Color& other)
{
    this->_r += other._r;
    this->_g += other._g;
    this->_b += other._b;
    return *this;
}

math::Color& math::Color::operator-=(const math::Color& other)
{
    this->_r -= other._r;
    this->_g -= other._g;
    this->_b -= other._b;
    return *this;
}

math::Color& math::Color::operator*=(double scalar)
{
    this->_r *= scalar;
    this->_g *= scalar;
    this->_b *= scalar;
    return *this;
}

math::Color& math::Color::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_r /= scalar;
    this->_g /= scalar;
    this->_b /= scalar;
    return *this;
}

math::Color math::Color::operator+(const math::Color& other)
{
    return math::Color(this->_r + other._r, this->_g + other._g, this->_b + other._b);
}

math::Color math::Color::operator-(const math::Color& other)
{
    return math::Color(this->_r - other._r, this->_g - other._g, this->_b - other._b);
}

math::Color math::Color::operator*(const math::Color& other)
{
    return math::Color(this->_r * other._r, this->_g * other._g, this->_b * other._b);
}

math::Color math::Color::operator*(double scalar)
{
    return math::Color(this->_r * scalar, this->_g * scalar, this->_b * scalar);
}

math::Color math::Color::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return math::Color(this->_r / scalar, this->_g / scalar, this->_b / scalar);
}

namespace math {
    std::ostream& operator<<(std::ostream& os, const math::Color& c) {
        os << static_cast<int>(255.999 * c._r) << ' '
        << static_cast<int>(255.999 * c._g) << ' '
        << static_cast<int>(255.999 * c._b) << '\n';
        return os;
    }
};
