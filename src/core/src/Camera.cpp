/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Camera.cpp
*/

#include "Camera.hpp"

namespace {
    constexpr double DEG_TO_RAD = M_PI / 180.0;
}

rayTracer::Camera::Camera():
    _fov(100),
    _position(0, 0, 0),
    _direction(0, 0, -1)
{
}

rayTracer::Camera::Camera(double fov, math::Point pos, math::Vector direction):
    _fov(fov),
    _position(pos),
    _direction(direction.normalize())
{
}

void rayTracer::Camera::calculateViewVectors(math::Vector& right, math::Vector& up) const
{
    math::Vector worldUp(0, 1, 0);
    if (std::abs(_direction.dotProduct(worldUp)) > 0.99)
        worldUp = math::Vector(0, 0, 1);

    right = _direction.cross(worldUp).normalize();
    up = right.cross(_direction).normalize();
}

math::Ray rayTracer::Camera::generateRay(double x, double y, int imageWidth, int imageHeight) const
{
    math::Vector right, up;
    calculateViewVectors(right, up);

    double ndcX = (2.0 * (x + 0.5) / imageWidth - 1.0);
    double ndcY = 1.0 - (2.0 * (y + 0.5) / imageHeight);

    double scale = tan(_fov * DEG_TO_RAD / 2.0);
    ndcX *= scale;
    ndcY *= scale;

    math::Vector rayDir = right * ndcX + up * ndcY;
    rayDir += _direction;
    return math::Ray(_position, rayDir.normalize() , {0.3, 0.7, 1});
}