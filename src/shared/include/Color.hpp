/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Color.hpp
*/

#pragma once
#include <memory>
#include <cmath>
#include <iostream>
#include <stdexcept>

class Color {
    public:
        double _r;
        double _g;
        double _b;

        Color();
        Color(Color &Color);
        Color(double x, double y, double z);
        ~Color() = default;

        virtual Color& operator-() const;
        virtual Color& operator+=(const Color& v);
        virtual Color& operator-=(const Color& v);
        virtual Color& operator*=(double t);
        virtual Color& operator/=(double t);

        virtual Color operator+(const Color& v);
        virtual Color operator-(const Color& v);
        virtual Color operator*(double t);
        virtual Color operator/(double t);

        friend std::ostream& operator<<(std::ostream& os, const Color& v);
};
