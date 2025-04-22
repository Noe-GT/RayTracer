/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Vector.hpp
*/

#pragma once
#include <memory>
#include <cmath>
#include <iostream>
#include <stdexcept>

class Vector {
    public:
        double _x;
        double _y;
        double _z;

        Vector();
        Vector(Vector &Vector);
        Vector(double x, double y, double z);
        ~Vector() = default;

        virtual Vector& operator-() const;
        virtual Vector& operator+=(const Vector& v);
        virtual Vector& operator-=(const Vector& v);
        virtual Vector& operator*=(double t);
        virtual Vector& operator/=(double t);

        virtual Vector operator+(const Vector& v);
        virtual Vector operator-(const Vector& v);
        virtual Vector operator*(double t);
        virtual Vector operator/(double t);

        double LengthSquared() const;
        double Length() const;

        friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};
