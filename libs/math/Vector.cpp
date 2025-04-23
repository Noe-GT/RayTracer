/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector.cpp
*/

#include "Vector.hpp"

Vector::Vector(): _x(0), _y(0), _z(0)
{
}

Vector::Vector(Vector &Vector): _x(Vector._x), _y(Vector._y), _z(Vector._z)
{

}
Vector::Vector(double x, double y, double z): _x(x), _y(y), _z(z)
{
}

Vector& Vector::operator-() const
{
    Vector* result = new Vector(-this->_x, -this->_y, -this->_z);
    return * result;
}

Vector& Vector::operator+=(const Vector& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

Vector& Vector::operator-=(const Vector& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    this->_z -= other._z;
    return *this;
}

Vector& Vector::operator*=(double scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;
    return *this;
}

Vector& Vector::operator/=(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    this->_x /= scalar;
    this->_y /= scalar;
    this->_z /= scalar;
    return *this;
}

Vector Vector::operator+(const Vector& other)
{
    return Vector(this->_x + other._x, this->_y + other._y, this->_z + other._z);
}

Vector Vector::operator-(const Vector& other)
{
    return Vector(this->_x - other._x, this->_y - other._y, this->_z - other._z);
}

Vector Vector::operator*(double scalar)
{
    return Vector(this->_x * scalar, this->_y * scalar, this->_z * scalar);
}

Vector Vector::operator/(double scalar)
{
    if (scalar == 0)
        throw std::invalid_argument("Division by zero");
    return Vector(this->_x / scalar, this->_y / scalar, this->_z / scalar);
}

double Vector::Length() const
{
    return std::sqrt(LengthSquared());
}

double Vector::LengthSquared() const
{
    return this->_x * this->_x + this->_y * this->_y + this->_z * this->_z;
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    return out << v._x << ' ' << v._y << ' ' << v._z;
}