/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <algorithm>
Sphere::Sphere():
    _origin(0, 0, -1),
    _radius(0.2)
{
}

Sphere::Sphere(math::Point origin, double radius) :
    _origin(origin),
    _radius(radius)
{
}

void Sphere::lightShadowSym(math::Vector normal, math::Vector hitPoint, math::Ray &ray, const std::vector<math::Point>& lights, const std::vector<std::unique_ptr<IPrimitive>>& objs)
{

    math::Color sphereColor(1.0f, 0.0f, 0.0f);
    math::Color finalColor(0.1f, 0.1f, 0.1f);

    for (const auto& light : lights) {
        math::Vector lightDir = (math::Vector(light._x, light._y, light._z) - hitPoint).normalize();
        math::Ray shadowRay;
        shadowRay._origin._x = hitPoint._x + normal._x * 0.001f;
        shadowRay._origin._y = hitPoint._y + normal._y * 0.001f;
        shadowRay._origin._z = hitPoint._z + normal._z * 0.001f;
        shadowRay._direction = lightDir;
        bool inShadow = false;
        for (const auto& obj : objs) {
            if (obj.get() == this)
                continue;
            if (obj->getDiscriminant(shadowRay) >= 0) {
                inShadow = true;
                break;
            }
        }
        float diffuse = std::max(0.0, normal.dotProduct(lightDir));
        if (inShadow) {
            diffuse *= 0.1f;
        }

        finalColor._r += sphereColor._r * diffuse;
        finalColor._g += sphereColor._g * diffuse;
        finalColor._b += sphereColor._b * diffuse;
    }

    finalColor._r = std::min(1.0, finalColor._r);
    finalColor._g = std::min(1.0, finalColor._g);
    finalColor._b = std::min(1.0, finalColor._b);

    ray._color = finalColor;
}

double Sphere::getDiscriminant(math::Ray& ray)
{
    math::Vector oc = ray._origin - _origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (_radius * _radius);

    return (b * b - 4 * a * c);
}

bool Sphere::Intersect(math::Ray& ray, const std::vector<math::Point>& lights, const std::vector<std::unique_ptr<IPrimitive>>& objs)
{
    math::Vector oc = ray._origin - _origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (_radius * _radius);
    double discriminant = (b * b - 4 * a * c);

    if (discriminant < 0)
        return false;

    double t = (-b - sqrt(discriminant)) / (2 * a);
    math::Vector intersectionPoint = ray._origin + ray._direction * t;
    math::Vector normal = (intersectionPoint - _origin).normalize();
    lightShadowSym(normal, intersectionPoint, ray, lights, objs);
    return true;
}

extern "C"
{
    IPrimitive *entryPoint()
    {
        return new Sphere;
    }
}

math::Point &Sphere::getOrigin()
{
    return this->_origin;
}

double &Sphere::getSize()
{
    return this->_radius;
}