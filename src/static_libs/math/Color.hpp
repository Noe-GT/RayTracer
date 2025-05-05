/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color.hpp
*/

#pragma once
#include <memory>
#include <cmath>
#include <vector>
#include <iostream>
#include <stdexcept>

namespace math {
    class Color {
        public:
            double _r;
            double _g;
            double _b;

            Color();
            Color(const math::Color &color);
            Color(double x, double y, double z);
            ~Color() = default;

            virtual math::Color& operator=(const math::Color& v);

            virtual math::Color& operator-() const;
            virtual math::Color& operator+=(const math::Color& v);
            virtual math::Color& operator-=(const math::Color& v);
            virtual math::Color& operator*=(double t);
            virtual math::Color& operator/=(double t);

            virtual math::Color operator+(const math::Color& v);
            virtual math::Color operator-(const math::Color& v);
            virtual math::Color operator*(double t);
            virtual math::Color operator/(double t);

            friend std::ostream& operator<<(std::ostream& os, const math::Color& v);
    };
};