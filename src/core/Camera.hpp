/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera.hpp
*/

#pragma once
#include "Ray.hpp"
#include <cmath>

namespace rayTracer {
    class Camera {
    public:
        Camera();
        Camera(double fov, math::Point pos, math::Vector direction);
        ~Camera() {}

        void setPosition(const math::Point& position);
        void setDirection(const math::Vector& direction);
        void setFov(double fov);
        math::Ray generateRay(double x, double y, int imageWidth, int imageHeight) const;

    private:
        double _fov;
        math::Point _position;
        math::Vector _direction;

        void calculateViewVectors(math::Vector& right, math::Vector& up) const;
    };
}