/*
** EPITECH PROJECT, 2024
** math::raytracer
** File description:
** math::Ray.hpp
*/

#pragma once

#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"

namespace math {
    class Ray {
        public:
            Point _origin;
            math::Vector _direction;
            math::Color _color;

            Ray();
            Ray(Point, math::Vector, math::Color);
            Ray(Point, math::Vector);
            Ray(double x, double y, double z);
            Ray(double ox, double oy, double oz, double dx, double dy, double dz);
            Ray(double ox, double oy, double oz, double dx, double dy, double dz, double r, double g, double b);
            virtual ~Ray() = default;

            virtual math::Ray& operator+=(const math::Ray& other);
            virtual math::Ray& operator-=(const math::Ray& other);
            virtual math::Ray& operator*=(double t);
            virtual math::Ray& operator/=(double t);
            virtual math::Ray operator+(const math::Ray& other);
            virtual math::Ray operator-(const math::Ray& other);
            virtual math::Ray operator*(double t);
            virtual math::Ray operator/(double t);

            virtual math::Ray& operator+=(const Point& other);
            virtual math::Ray& operator-=(const Point& other);
            virtual math::Ray& operator*=(const Point& other);
            virtual math::Ray& operator/=(const Point& other);
            virtual math::Ray operator+(const Point& other);
            virtual math::Ray operator*(const Point& other);
            virtual math::Ray operator/(const Point& other);
            virtual math::Ray operator-(const Point& other);

            virtual math::Ray& operator+=(const math::Vector& other);
            virtual math::Ray& operator-=(const math::Vector& other);
            virtual math::Ray& operator*=(const math::Vector& other);
            virtual math::Ray& operator/=(const math::Vector& other);
            virtual math::Ray operator+(const math::Vector& other);
            virtual math::Ray operator-(const math::Vector& other);
            virtual math::Ray operator*(const math::Vector& other);
            virtual math::Ray operator/(const math::Vector& other);

            virtual math::Ray& operator+=(const math::Color& other);
            virtual math::Ray& operator-=(const math::Color& other);
            virtual math::Ray& operator*=(const math::Color& other);
            virtual math::Ray& operator/=(const math::Color& other);
            virtual math::Ray operator+(const math::Color& other);
            virtual math::Ray operator-(const math::Color& other);
            virtual math::Ray operator*(const math::Color& other);
            virtual math::Ray operator/(const math::Color& other);

            friend std::ostream& operator<<(std::ostream& os, const math::Ray& v);

            double length_squared() const;
            double length() const;
    };
};

math::Ray operator-(const math::Ray&);