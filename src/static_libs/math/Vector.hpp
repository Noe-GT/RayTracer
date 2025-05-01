/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** math::Vector.hpp
*/

#pragma once
#include <memory>
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace math {
    class Point;
}

namespace math {
    class Vector {
        public:
            double _x;
            double _y;
            double _z;

            Vector();
            Vector(const math::Vector &vector);
            Vector(const math::Point &point);
            Vector(double x, double y, double z);
            ~Vector() = default;

            virtual Vector& operator=(const Vector &other);
            virtual math::Vector& operator-() const;
            virtual math::Vector& operator+=(const math::Vector& v);
            virtual math::Vector& operator-=(const math::Vector& v);
            virtual math::Vector& operator*=(double t);
            virtual math::Vector& operator/=(double t);

            virtual math::Vector operator+(const math::Vector& v);
            virtual math::Vector operator-(const math::Vector& v);
            virtual math::Vector operator*(double t);
            virtual math::Vector operator/(double t);

            double LengthSquared() const;
            double Length() const;
            double dotProduct(const math::Vector& other) const;
            Vector cross(const Vector& other) const;
            Vector normalize() const;

            friend std::ostream& operator<<(std::ostream& os, const math::Vector& v);
    };
};
