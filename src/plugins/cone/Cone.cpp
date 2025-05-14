/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cone
*/

#include "Cone.hpp"

Cone::Cone():
    _radius(0.1),
    _height(1.0),
    _orientation(1, 0, 0)
{
}

Cone::Cone(math::Point origin, double radius) :
    _radius(radius)
{
    this->_origin = origin;
}

void Cone::configure(const libconfig::Setting &setting, int id)
{
    APrimitive::configure(setting, id);
    if (setting.exists("x"))
        this->_origin._x = setting["x"];
    if (setting.exists("y"))
        this->_origin._y = setting["y"];
    if (setting.exists("z"))
        this->_origin._z = setting["z"];
    if (setting.exists("radius"))
        this->_radius = setting["radius"];
    if (setting.exists("height")) {
        this->_height = setting["height"];
        if (this->_height <= 0)
            throw rayTracer::ConfigException("Cone height must be positive.");
    }
    if (setting.exists("orientation") &&
        setting["orientation"].exists("x") &&
        setting["orientation"].exists("y") &&
        setting["orientation"].exists("z")) {
        this->_orientation._x = setting["orientation"]["x"];
        this->_orientation._y = setting["orientation"]["y"];
        this->_orientation._z = setting["orientation"]["z"];
    }
}

double Cone::getDiscriminant(math::Ray &ray)
{
    math::Vector oc = ray._origin - this->_origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (_radius * this->_radius);

    return (b * b - 4 * a * c);
}

math::CollisionUtils Cone::Collide(math::Ray& ray)
{
    math::CollisionUtils CU;
    math::Vector coneAxis = this->_orientation.normalize();
    math::Vector oc = ray._origin - this->_origin;
    double k = this->_radius / this->_height; // radius to height ratio
    math::Vector rayDir = ray._direction - coneAxis * ray._direction.dotProduct(coneAxis);
    math::Vector rayOrigin = oc - coneAxis * oc.dotProduct(coneAxis);

    k *= k;

    CU.setA(rayDir.dotProduct(rayDir) - k * pow(ray._direction.dotProduct(coneAxis), 2));
    CU.setB(2 * (rayDir.dotProduct(rayOrigin) - k * ray._direction.dotProduct(coneAxis) * oc.dotProduct(coneAxis)));
    CU.setC(rayOrigin.dotProduct(rayOrigin) - k * pow(oc.dotProduct(coneAxis), 2));
    CU.setDiscriminant((CU.getB() * CU.getB()) - (4 * CU.getA() * CU.getC()));

    if (CU.getDiscriminant() >= 0)
        CU.setT((-CU.getB() - sqrt(CU.getDiscriminant())) / (2 * CU.getA()));
    return CU;
}

bool Cone::Intersect(math::Ray& ray, const std::vector<std::shared_ptr<IPrimitive>> &lights, const std::vector<std::shared_ptr<IPrimitive>> &objs)
{
    const math::Color ambiantColor(ray._color);
    math::CollisionUtils CU = this->Collide(ray);

    CU.setHasCollision(CU.getDiscriminant() >= 0);
    if (CU.getDiscriminant() < 0 || CU.getT() <= 0.0001)
        return false;

    math::Vector hitPoint = ray._origin + ray._direction * CU.getT();
    math::Vector coneAxis = this->_orientation.normalize();
    double heightAtHit = (hitPoint - this->_origin).dotProduct(coneAxis);

    if (heightAtHit < 0 || heightAtHit > this->_height)
        return false;

    CU.setHitPoint(hitPoint);
    CU.setNormal(math::Vector((hitPoint - this->_origin) - coneAxis * heightAtHit).normalize());
    CU.computeShadows(*this, ray, lights, objs, ambiantColor);
    CU.computeTransparency(*this, ray, lights, objs, ambiantColor);
    CU.computeReflection(*this, ray, lights, objs, ambiantColor);
    return true;
}

double &Cone::getSize()
{
    return this->_radius;
}

std::shared_ptr<IPrimitive> ConeFactory::build()
{
    return std::make_shared<Cone>();
}

extern "C"
{
    rayTracer::IFactory<IPrimitive> *entryPoint()
    {
        return new ConeFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::PRIMITIVE;
    }
}
