/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Point.cpp
*/

#include "Point.hpp"

Point::Point(): _x(0), _y(0), _z(0)
{
}

Point::Point(Point &Point): _x(Point._x), _y(Point._y), _z(Point._z)
{

}
Point::Point(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

Point& Point::operator-() const
{
    Point* result = new Point(-this->_x, -this->_y, -this->_z);
    return * result;
}

Point& Point::operator+=(const Point& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

Point& Point::operator-=(const Point& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    this->_z -= other._z;
    return *this;
}

Point& Point::operator*=(double scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;
    return *this;
}

Point& Point::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_x /= scalar;
    this->_y /= scalar;
    this->_z /= scalar;
    return *this;
}

Point Point::operator+(const Point& other)
{
    return Point(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

Point Point::operator-(const Point& other)
{
    return Point(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}

Point Point::operator*(double scalar)
{
    return Point(this->_x * scalar, this->_y * scalar, this->_z * scalar);
}

Point Point::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return Point(this->_x / scalar, this->_y / scalar, this->_z / scalar);
}

std::ostream& operator<<(std::ostream& out, const Point& v) {
    return out << v._x << ' ' << v._y << ' ' << v._z;
}

Point & Point::operator+=(const Vector& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

Point &Point::operator-=(const Vector& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

Point Point::operator+(const Vector& other)
{
    return Point(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

Point Point::operator-(const Vector& other)
{
    return Point(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}
