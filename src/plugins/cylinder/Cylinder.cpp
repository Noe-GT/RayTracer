/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

Cylinder::Cylinder() :
    _radius(0.5),
    _height(1.0)
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

    return b * b - 4 * a * c;
}

math::CollisionUtils Cylinder::Collide(math::Ray& ray)
{
    math::CollisionUtils CU;
    math::Vector oc = ray._origin - _origin;

    // Partie latérale : ignore la composante Y (cylindre vertical)
    double a = ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z;
    double b = 2.0 * (oc._x * ray._direction._x + oc._z * ray._direction._z);
    double c = oc._x * oc._x + oc._z * oc._z - _radius * _radius;
    double discriminant = b * b - 4 * a * c;

    CU.setA(a);
    CU.setB(b);
    CU.setC(c);
    CU.setDiscriminant(discriminant);
    CU.setHasCollision(false);

    double tMin = std::numeric_limits<double>::max();
    math::Point bestHit;
    math::Vector bestNormal;

    // === Surface latérale ===
    if (discriminant >= 0 && fabs(a) > 1e-6) {
        double sqrtDiscr = std::sqrt(discriminant);
        double t1 = (-b - sqrtDiscr) / (2 * a);
        double t2 = (-b + sqrtDiscr) / (2 * a);

        for (double t : {t1, t2}) {
            if (t > 1e-4) {
                math::Point p = ray._origin + ray._direction * t;
                double yMin = _origin._y;
                double yMax = _origin._y + _height;

                if (p._y >= yMin && p._y <= yMax && t < tMin) {
                    tMin = t;
                    bestHit = p;
                    bestNormal = math::Vector(p._x - _origin._x, 0, p._z - _origin._z).normalize();
                    CU.setHasCollision(true);
                }
            }
        }
    }

    if (CU.hasCollision()) {
        CU.setT(tMin);
        CU.setHitPoint(bestHit);
        CU.setNormal(bestNormal);
    }

    return CU;
}

bool Cylinder::Intersect(math::Ray& ray, const std::vector<std::shared_ptr<IPrimitive>> &lights, const std::vector<std::shared_ptr<IPrimitive>> &objs)
{
    math::CollisionUtils CU = Collide(ray);
    if (!CU.hasCollision())
        return false;
    if (CU.getT() <= 0.0001)
        return false;

    if (CU.getNormal().dotProduct(ray._direction) > 0)
        CU.setNormal(CU.getNormal() * -1.0);

    math::Color ambiantColor(ray._color);
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
