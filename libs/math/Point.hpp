/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** math::Point.hpp
*/

#pragma once
#include <memory>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "Vector.hpp"

namespace math {
    class Point {
        public:
            double _x;
            double _y;
            double _z;

            Point();
            Point(math::Point &point);
            Point(double x, double y, double z);
            ~Point() = default;

            virtual math::Point& operator-() const;
            virtual math::Point& operator+=(const math::Point& v);
            virtual math::Point& operator-=(const math::Point& v);
            virtual math::Point& operator*=(double t);
            virtual math::Point& operator/=(double t);

            virtual math::Point operator+(const math::Point& v);
            virtual math::Point operator-(const math::Point& v);
            virtual math::Point operator*(double t);
            virtual math::Point operator/(double t);

            virtual math::Point& operator+=(const math::Vector& v);
            virtual math::Point& operator-=(const math::Vector& v);
            virtual math::Point operator+(const math::Vector& v);
            virtual math::Point operator-(const math::Vector& v);


            friend std::ostream& operator<<(std::ostream& os, const math::Point& v);
    };
};
