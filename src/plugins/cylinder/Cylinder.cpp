/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

Cylinder::Cylinder():
    _radius(0.5),
    _height(1)
{
}

Cylinder::Cylinder(math::Point origin, double radius, double height) :
    _radius(radius),
    _height(height)
{
    this->_origin = origin;
}

void Cylinder::configure(const libconfig::Setting &setting, int id)
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
    if (setting.exists("h"))
        this->_height = setting["h"];
}

double Cylinder::getDiscriminant(math::Ray &ray)
{
    math::Vector oc = ray._origin - this->_origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (this->_radius * this->_radius);

    return (b * b - 4 * a * c);
}

math::CollisionUtils Cylinder::Collide(math::Ray& ray)
{
    math::CollisionUtils CU;
    const math::Vector oc = ray._origin - this->_origin;

    CU.setA(ray._direction.dotProduct(ray._direction));
    CU.setB(2 * oc.dotProduct(ray._direction));
    CU.setC(oc.dotProduct(oc) - (this->_radius * this->_radius));
    CU.setDiscriminant((CU.getB() * CU.getB()) - (4 * CU.getA() * CU.getC()));
    CU.setT((-CU.getB() - sqrt(CU.getDiscriminant())) / (2 * CU.getA()));
    return CU;
}

bool Cylinder::Intersect(math::Ray& ray, const std::vector <std::shared_ptr<IPrimitive>> &lights, const std::vector <std::shared_ptr<IPrimitive>> &objs)
{
    const math::Color ambiantColor(ray._color);
    math::CollisionUtils CU = this->Collide(ray);

    CU.setHasCollision(CU.getDiscriminant() >= 0);
    if (CU.getDiscriminant() < 0 || CU.getT() <= 0.0001)
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

double &Cylinder::getSize()
{
    return this->_radius;
}

std::shared_ptr<IPrimitive> CylinderFactory::build()
{
    return std::make_shared<Cylinder>();
}

extern "C"
{
    rayTracer::IFactory<IPrimitive> *entryPoint()
    {
        return new CylinderFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::PRIMITIVE;
    }
}
