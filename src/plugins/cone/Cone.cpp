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
    _rotation(0, 1, 0)
{
}

Cone::Cone(math::Point origin, double radius, double height) :
    _radius(radius),
    _height(height),
    _rotation(0, 1, 0)
{
    if (this->_radius <= 0)
        throw rayTracer::ConfigException("Cone radius must be strictly positive.");
    if (this->_height <= 0)
        throw rayTracer::ConfigException("Cone height must be strictly positive.");
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
    if (setting.exists("radius")) {
        this->_radius = setting["radius"];
        if (this->_radius <= 0)
            throw rayTracer::ConfigException("Cone radius must be strictly positive.");
    }
    if (setting.exists("height")) {
        this->_height = setting["height"];
        if (this->_height <= 0)
            throw rayTracer::ConfigException("Cone height must be strictly positive.");
    }
    if (setting.exists("rotation") &&
        setting["rotation"].exists("x") &&
        setting["rotation"].exists("y") &&
        setting["rotation"].exists("z")) {
        this->_rotation._x = setting["rotation"]["x"];
        this->_rotation._y = setting["rotation"]["y"];
        this->_rotation._z = setting["rotation"]["z"];
        this->_rotation = this->_rotation.normalize();
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
    math::Vector oc = ray._origin - this->_origin;
    double k = pow(this->_radius / this->_height, 2.0);
    math::Vector rayDir = ray._direction - this->_rotation * ray._direction.dotProduct(this->_rotation);
    math::Vector rayOrigin = oc - this->_rotation * oc.dotProduct(this->_rotation);

    CU.setA(rayDir.dotProduct(rayDir) - k * pow(ray._direction.dotProduct(this->_rotation), 2));
    CU.setB(2 * (rayDir.dotProduct(rayOrigin) - k * ray._direction.dotProduct(this->_rotation) * oc.dotProduct(this->_rotation)));
    CU.setC(rayOrigin.dotProduct(rayOrigin) - k * pow(oc.dotProduct(this->_rotation), 2));
    CU.setDiscriminant((CU.getB() * CU.getB()) - (4 * CU.getA() * CU.getC()));
    if (CU.getDiscriminant() >= 0)
        CU.setT((-CU.getB() - sqrt(CU.getDiscriminant())) / (2 * CU.getA()));
    return CU;
}

bool Cone::Intersect(math::Ray& ray, const std::vector<std::shared_ptr<IPrimitive>> &lights, const std::vector<std::shared_ptr<IPrimitive>> &objs)
{
    math::CollisionUtils CU = this->Collide(ray);
    bool hitSomething = this->intersectCone(ray, CU);

    if (!hitSomething)
        hitSomething = this->intersectBase(ray, CU);
    if (hitSomething) {
        CU.computeShadows(*this, ray, lights, objs, ray._color);
        CU.computeTransparency(*this, ray, lights, objs, ray._color);
        CU.computeReflection(*this, ray, lights, objs, ray._color);
        return true;
    }
    return false;
}

bool Cone::intersectCone(math::Ray &ray, math::CollisionUtils &CU)
{
    math::Vector hitPoint;
    double hitHeight;

    if (CU.getDiscriminant() >= 0 && CU.getT() > 0.0001) {
        hitPoint = ray._origin + ray._direction * CU.getT();
        hitHeight = (hitPoint - this->_origin).dotProduct(this->_rotation);
        if (hitHeight >= 0 && hitHeight <= this->_height) {
            CU.setHitPoint(hitPoint);
            CU.setNormal(((hitPoint - this->_origin) - this->_rotation * hitHeight).normalize());
            return true;
        }
    }
    return false;
}

bool Cone::intersectBase(math::Ray &ray, math::CollisionUtils &CU)
{
    math::Vector baseCenter = this->_origin + this->_rotation * this->_height;
    math::Vector oc = ray._origin - baseCenter;
    math::Vector hitPoint;
    double denom = ray._direction.dotProduct(this->_rotation);
    double t;

    if (std::abs(denom) > 1e-6) {
        t = -oc.dotProduct(this->_rotation) / denom;
        if (t > 0.0001) {
            hitPoint = ray._origin + ray._direction * t;
            if ((hitPoint - baseCenter).Length() <= this->_radius) {
                CU.setT(t);
                CU.setHitPoint(hitPoint);
                CU.setNormal(this->_rotation);
                return true;
            }
        }
    }
    return false;
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
