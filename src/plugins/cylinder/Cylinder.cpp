/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"

Cylinder::Cylinder() :
    _radius(0.1),
    _height(1.0),
    _orientation(0, 1, 0)
{
}

Cylinder::Cylinder(math::Point origin, double radius, double height) :
    _radius(radius),
    _height(height),
    _orientation(0, 1, 0)
{
    if (this->_radius <= 0)
        throw rayTracer::ConfigException("Cylinder radius must be strictly positive.");
    if (this->_height <= 0)
        throw rayTracer::ConfigException("Cylinder height must be strictly positive.");
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
            throw rayTracer::ConfigException("Cylinder radius must be strictly positive.");
    }
    if (setting.exists("height")) {
        this->_height = setting["height"];
        if (this->_height <= 0)
            throw rayTracer::ConfigException("Cylinder height must be strictly positive.");
    }
    if (setting.exists("orientation") &&
        setting["orientation"].exists("x") &&
        setting["orientation"].exists("y") &&
        setting["orientation"].exists("z")) {
        this->_orientation._x = setting["orientation"]["x"];
        this->_orientation._y = setting["orientation"]["y"];
        this->_orientation._z = setting["orientation"]["z"];
        this->_orientation = this->_orientation.normalize();
    }
    if (setting.exists("translation")) {
        const libconfig::Setting &translation = setting["translation"];
        if (translation.exists("x")) {
            double tx= translation["x"];
            this->_origin._x += tx;
        }
        if (translation.exists("y")) {
            double ty= translation["y"];
            this->_origin._y += ty;
        }
        if (translation.exists("z")) {
            double tz= translation["z"];
            this->_origin._z += tz;
        }
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
    math::Vector d = ray._direction - this->_orientation * ray._direction.dotProduct(this->_orientation);
    math::Vector deltaP = ray._origin - this->_origin;
    math::Vector delta = deltaP - this->_orientation * deltaP.dotProduct(this->_orientation);

    CU.setA(d.dotProduct(d));
    CU.setB(2 * d.dotProduct(delta));
    CU.setC(delta.dotProduct(delta) - this->_radius * this->_radius);
    CU.setDiscriminant(CU.getB() * CU.getB() - 4 * CU.getA() * CU.getC());

    if (CU.getDiscriminant() >= 0)
        CU.setT((-CU.getB() - sqrt(CU.getDiscriminant())) / (2 * CU.getA()));
    return CU;
}

bool Cylinder::Intersect(math::Ray& ray, const std::vector<std::shared_ptr<IPrimitive>> &lights, const std::vector<std::shared_ptr<IPrimitive>> &objs)
{
    math::CollisionUtils CU = this->Collide(ray);
    bool hitSomething = intersectCylinder(ray, CU);

    if (!hitSomething)
        hitSomething = intersectBottomBase(ray, CU);
    if (!hitSomething)
        hitSomething = intersectTopBase(ray, CU);
    if (hitSomething) {
        CU.computeShadows(*this, ray, lights, objs, ray._color);
        CU.computeTransparency(*this, ray, lights, objs, ray._color);
        CU.computeReflection(*this, ray, lights, objs, ray._color);
        return true;
    }
    return false;
}

bool Cylinder::intersectCylinder(math::Ray& ray, math::CollisionUtils &CU)
{
    math::Vector hitPoint;
    double hitHeight;

    if (CU.getDiscriminant() >= 0 && CU.getT() > 0.0001) {
        hitPoint = ray._origin + ray._direction * CU.getT();
        hitHeight = (hitPoint - this->_origin).dotProduct(this->_orientation);
        if (hitHeight >= 0 && hitHeight <= this->_height) {
            CU.setHitPoint(hitPoint);
            CU.setNormal(((hitPoint - this->_origin) - this->_orientation * hitHeight).normalize());
            return true;
        }
    }
    return false;
}

bool Cylinder::intersectBottomBase(math::Ray &ray, math::CollisionUtils &CU)
{
    math::Vector baseCenter = this->_origin;
    math::Vector oc = ray._origin - baseCenter;
    math::Vector hitPoint;
    double denom = ray._direction.dotProduct(this->_orientation);
    double t;

    if (std::abs(denom) > 1e-6) {
        t = -oc.dotProduct(this->_orientation) / denom;
        if (t > 0.0001) {
            hitPoint = ray._origin + ray._direction * t;
            if ((hitPoint - baseCenter).Length() <= this->_radius) {
                CU.setT(t);
                CU.setHitPoint(hitPoint);
                CU.setNormal(-this->_orientation);
                return true;
            }
        }
    }
    return false;
}

bool Cylinder::intersectTopBase(math::Ray &ray, math::CollisionUtils &CU)
{
    math::Vector baseCenter = this->_origin + this->_orientation * this->_height;
    math::Vector oc = ray._origin - baseCenter;
    math::Vector hitPoint;
    double denom = ray._direction.dotProduct(this->_orientation);
    double t;

    if (std::abs(denom) > 1e-6) {
        t = -oc.dotProduct(this->_orientation) / denom;
        if (t > 0.0001) {
            hitPoint = ray._origin + ray._direction * t;
            if ((hitPoint - baseCenter).Length() <= this->_radius) {
                CU.setT(t);
                CU.setHitPoint(hitPoint);
                CU.setNormal(this->_orientation);
                return true;
            }
        }
    }
    return false;
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
