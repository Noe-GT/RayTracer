/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Point.hpp
*/

#pragma once
#include <memory>
#include <cmath>
#include <iostream>
#include <stdexcept>

class Point {
    public:
        double _x;
        double _y;
        double _z;

        Point();
        Point(Point &Point);
        Point(double x, double y, double z);
        ~Point() = default;

        virtual Point& operator-() const;
        virtual Point& operator+=(const Point& v);
        virtual Point& operator-=(const Point& v);
        virtual Point& operator*=(double t);
        virtual Point& operator/=(double t);

        virtual Point operator+(const Point& v);
        virtual Point operator-(const Point& v);
        virtual Point operator*(double t);
        virtual Point operator/(double t);

        friend std::ostream& operator<<(std::ostream& os, const Point& v);
};
