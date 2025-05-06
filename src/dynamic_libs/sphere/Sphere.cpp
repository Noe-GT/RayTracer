/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Sphere::Sphere():
    _origin(0, 0, -1),
    _radius(0.5)
{
}

Sphere::Sphere(math::Point origin, double radius) :
    _origin(origin),
    _radius(radius)
{
}

void Sphere::configure(const libconfig::Setting &setting)
{
    if (setting.exists("x"))
        this->_origin._x = setting["x"];
    if (setting.exists("y"))
        this->_origin._y = setting["y"];
    if (setting.exists("z"))
        this->_origin._z = setting["z"];
    if (setting.exists("r"))
        this->_radius = setting["r"];
}

bool Sphere::intersect(math::Ray &ray)
{
    math::Vector oc = ray._origin - _origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2.0 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - _radius*_radius;
    double discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        ray._color = math::Color(0, 0, 1);
        return false;
    }

    ray._color = math::Color(1, 0, 0);
    return true;
}

std::shared_ptr<IPrimitive> SphereFactory::build()
{
    return std::make_shared<Sphere>();
}

extern "C"
{
    rayTracer::IFactory<IPrimitive> *entryPoint()
    {
        return new SphereFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::PRIMITIVE;
    }
}
