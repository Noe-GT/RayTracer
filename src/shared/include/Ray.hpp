/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Ray.hpp
*/

#pragma once

#include "Point.hpp"
#include "Vector.hpp"
#include "Color.hpp"

class Ray {

    public:
        Point _origin;
        Vector _direction;
        Color _color;

        Ray();
        Ray(Point, Vector, Color);
        Ray(Point, Vector);
        Ray(double x, double y, double z);
        Ray(double ox, double oy, double oz, double dx, double dy, double dz);
        Ray(double ox, double oy, double oz, double dx, double dy, double dz, double r, double g, double b);
        ~Ray() = default;

        // virtual Ray& operator-() const;

        virtual Ray& operator+=(const Ray& other);
        virtual Ray& operator-=(const Ray& other);
        virtual Ray& operator*=(double t);
        virtual Ray& operator/=(double t);
        virtual Ray operator+(const Ray& other);
        virtual Ray operator-(const Ray& other);
        virtual Ray operator*(double t);
        virtual Ray operator/(double t);

        virtual Ray& operator+=(const Point& other);
        virtual Ray& operator-=(const Point& other);
        virtual Ray& operator*=(const Point& other);
        virtual Ray& operator/=(const Point& other);
        virtual Ray operator+(const Point& other);
        virtual Ray operator*(const Point& other);
        virtual Ray operator/(const Point& other);
        virtual Ray operator-(const Point& other);

        virtual Ray& operator+=(const Vector& other);
        virtual Ray& operator-=(const Vector& other);
        virtual Ray& operator*=(const Vector& other);
        virtual Ray& operator/=(const Vector& other);
        virtual Ray operator+(const Vector& other);
        virtual Ray operator-(const Vector& other);
        virtual Ray operator*(const Vector& other);
        virtual Ray operator/(const Vector& other);

        virtual Ray& operator+=(const Color& other);
        virtual Ray& operator-=(const Color& other);
        virtual Ray& operator*=(const Color& other);
        virtual Ray& operator/=(const Color& other);
        virtual Ray operator+(const Color& other);
        virtual Ray operator-(const Color& other);
        virtual Ray operator*(const Color& other);
        virtual Ray operator/(const Color& other);

        friend std::ostream& operator<<(std::ostream& os, const Ray& v);

        double length_squared() const;
        double length() const;
};
