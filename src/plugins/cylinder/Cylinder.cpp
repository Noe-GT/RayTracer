/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

Cylinder::Cylinder():
    _radius(0.1),
    _height(1.0)
{
}

Cylinder::Cylinder(math::Point origin, double radius) :
    _radius(radius)
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
    if (setting.exists("radius")) {
        this->_radius = setting["radius"];
        if (this->_radius <= 0)
            throw rayTracer::ConfigException("Cylinder radius must be positive.");
    }
    if (setting.exists("height")) {
        this->_height = setting["height"];
        if (this->_height <= 0)
            throw rayTracer::ConfigException("Cylinder height must be positive.");
    }
}

double Cylinder::getDiscriminant(math::Ray &ray)
{
    math::Vector oc = ray._origin - this->_origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (_radius * this->_radius);

    return (b * b - 4 * a * c);
}

math::CollisionUtils Cylinder::Collide(math::Ray& ray)
{
    math::CollisionUtils CU;
    math::Vector oc = ray._origin - this->_origin;

    CU.setA(ray._direction._x * ray._direction._x + ray._direction._z * ray._direction._z);
    CU.setB(2.0 * (oc._x * ray._direction._x + oc._z * ray._direction._z));
    CU.setC(oc._x * oc._x + oc._z * oc._z - _radius * _radius);
    CU.setDiscriminant(CU.getB() * CU.getB() - 4 * CU.getA() * CU.getC());
    return CU;
}

bool Cylinder::Intersect(math::Ray& ray, const std::vector<std::shared_ptr<IPrimitive>> &lights, const std::vector<std::shared_ptr<IPrimitive>> &objs)
{
    math::CollisionUtils CU = this->Collide(ray);
    bool hitSomething = false;

    hitSomething = this->intersectCylinder(ray, CU);
    // if (!hitSomething)
    //     hitSomething = this->intersectBase(ray, CU);
    if (hitSomething) {
        CU.computeShadows(*this, ray, lights, objs, ray._color);
        CU.computeTransparency(*this, ray, lights, objs, ray._color);
        CU.computeReflection(*this, ray, lights, objs, ray._color);
        return true;
    }
    return false;
}

bool Cylinder::intersectCylinder(math::Ray &ray, math::CollisionUtils &CU)
{
    double tMin = std::numeric_limits<double>::max();
    math::Point bestHit;
    math::Vector bestNormal;

    if (CU.getDiscriminant() >= 0 && fabs(CU.getA()) > 1e-6) {
        double sqrtDiscr = std::sqrt(CU.getDiscriminant());
        double t1 = (-CU.getB() - sqrtDiscr) / (2 * CU.getA());
        double t2 = (-CU.getB() + sqrtDiscr) / (2 * CU.getA());

        for (double t : {t1, t2}) {
            if (t > 1e-4) {
                math::Point p = ray._origin + ray._direction * t;
                double yMin = this->_origin._y;
                double yMax = this->_origin._y + _height;

                if (p._y >= yMin && p._y <= yMax && t < tMin) {
                    tMin = t;
                    bestHit = p;
                    bestNormal = math::Vector(p._x - this->_origin._x, 0, p._z - this->_origin._z).normalize();
                    CU.setT(tMin);
                    CU.setHitPoint(bestHit);
                    CU.setNormal(bestNormal);
                    return true;
                }
            }
        }
    }
    return false;
}

// bool Cylinder::intersectBase(math::Ray &ray, math::CollisionUtils &CU)
// {
//     math::Vector baseCenter = this->_origin + this->_orientation * this->_height;
//     math::Vector oc = ray._origin - baseCenter;
//     math::Vector hitPoint;
//     double denom = ray._direction.dotProduct(this->_orientation);
//     double t;

//     if (std::abs(denom) > 1e-6) {
//         t = -oc.dotProduct(this->_orientation) / denom;
//         if (t > 0.0001) {
//             hitPoint = ray._origin + ray._direction * t;
//             if ((hitPoint - baseCenter).Length() <= this->_radius) {
//                 CU.setT(t);
//                 CU.setHitPoint(hitPoint);
//                 CU.setNormal(this->_orientation);
//                 return true;
//             }
//         }
//     }
//     return false;
// }

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
