/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

Sphere::Sphere():
    _radius(0.5)
{
}

Sphere::Sphere(math::Point origin, double radius) :
    _radius(radius)
{
    this->_origin = origin;
}

void Sphere::configure(const libconfig::Setting &setting, int id)
{
    APrimitive::configure(setting, id);
    if (setting.exists("x"))
        this->_origin._x = setting["x"];
    if (setting.exists("y"))
        this->_origin._y = setting["y"];
    if (setting.exists("z"))
        this->_origin._z = setting["z"];
    if (setting.exists("r"))
        this->_radius = setting["r"];
}

double Sphere::getDiscriminant(math::Ray &ray)
{
    math::Vector oc = ray._origin - _origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (_radius * _radius);

    return (b * b - 4 * a * c);
}

math::CollisionUtils Sphere::Collide(math::Ray& ray)
{
    math::CollisionUtils CU;
    double discr = getDiscriminant(ray);
    math::Vector oc = ray._origin - getOrigin();

    CU.setA(ray._direction.dotProduct(ray._direction));
    CU.setB(2 * oc.dotProduct(ray._direction));
    CU.setT((-CU.getB() - sqrt(discr)) / (2 * CU.getA()));
    CU.setC(oc.dotProduct(oc) - (_radius * _radius));
    CU.setDiscriminant((CU.getB() * CU.getB()) - (4 * CU.getA() * CU.getC()));
    return CU;
}

bool Sphere::Intersect(math::Ray& ray, const std::vector <std::shared_ptr<IPrimitive>> &lights,const std::vector <std::shared_ptr<IPrimitive>> &objs)
{
    math::Color ambiantColor(ray._color);
    math::CollisionUtils CU;
    const math::Vector oc = ray._origin - _origin;
    CU.setA(ray._direction.dotProduct(ray._direction));
    CU.setB(2 * oc.dotProduct(ray._direction));
    CU.setC(oc.dotProduct(oc) - (_radius * _radius));
    CU.setDiscriminant((CU.getB() * CU.getB()) - (4 * CU.getA() * CU.getC()));
    CU.setHasCollision(CU.getDiscriminant() >= 0);
    if (CU.getDiscriminant() < 0)
        return false;

    CU.setT((-CU.getB() - sqrt(CU.getDiscriminant())) / (2 * CU.getA()));
    if (CU.getT() <= 0.0001)
        return false;
    CU.setHitPoint(ray._origin + ray._direction * CU.getT());
    CU.setNormal((CU.getHitPoint() - _origin).normalize());
    if (CU.getNormal().dotProduct(ray._direction) > 0)
        CU.setNormal(CU.getNormal() * -1.0);

    CU.computeShadows(*this, ray, lights, objs, ambiantColor);
    CU.computeTransparency(*this, ray, lights, objs, ambiantColor);
    CU.computeReflection(*this, ray, lights, objs, ambiantColor);
    return true;
}

double &Sphere::getSize()
{
    return this->_radius;
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
