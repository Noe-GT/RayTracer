/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** InfinitePlan
*/

#include "InfinitePlan.hpp"

InfinitePlan::InfinitePlan():
    _radius(0.5)
{
}

InfinitePlan::InfinitePlan(math::Point origin, double radius) :
    _radius(radius)
{
    this->_origin = origin;
}

void InfinitePlan::configure(const libconfig::Setting &setting, int id)
{
    rayTracer::APrimitive::configure(setting, id);
    if (setting.exists("x"))
        this->_origin._x = setting["x"];
    if (setting.exists("y"))
        this->_origin._y = setting["y"];
    if (setting.exists("z"))
        this->_origin._z = setting["z"];
    if (setting.exists("r"))
        this->_radius = setting["r"];
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

double InfinitePlan::getDiscriminant(math::Ray &ray)
{
    math::Vector oc = ray._origin - _origin;
    double a = ray._direction.dotProduct(ray._direction);
    double b = 2 * oc.dotProduct(ray._direction);
    double c = oc.dotProduct(oc) - (_radius * _radius);

    return (b * b - 4 * a * c);
}

math::CollisionUtils InfinitePlan::Collide(math::Ray& ray)
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

bool InfinitePlan::Intersect(math::Ray& ray, const std::vector<std::shared_ptr<rayTracer::IPrimitive>>& lights, const std::vector<std::shared_ptr<rayTracer::IPrimitive>>& objs)
{
    math::Color ambiantColor(ray._color);
    math::CollisionUtils CU;

    float denom = ray._direction._y;
    if (fabs(denom) > 0.0001f) {
        float t =- (ray._origin._y - _origin._y) / denom;
        if (t >= 0.0001f) {
            CU.setT(t);
            CU.setHasCollision(true);
            CU.setHitPoint(ray._origin + ray._direction * t);
            math::Vector normal(0, 1, 0);
            if (denom > 0)
                normal = math::Vector(0, -1, 0);
            CU.setNormal(normal);
            math::Vector epsilon = normal * 0.001f;
            ray._origin._x = CU.getHitPoint()._x + epsilon._x;
            ray._origin._y = CU.getHitPoint()._y + epsilon._y;
            ray._origin._z = CU.getHitPoint()._z + epsilon._z;

            CU.computeShadows(*this, ray, lights, objs, ambiantColor);
            CU.computeTransparency(*this, ray, lights, objs, ambiantColor);
            CU.computeReflection(*this, ray, lights, objs, ambiantColor);
            return true;
        }
    }
    CU.setHasCollision(false);
    return false;
}

double &InfinitePlan::getSize()
{
    return this->_radius;
}

std::shared_ptr<rayTracer::IPrimitive> InfinitePlanFactory::build()
{
    return std::make_shared<InfinitePlan>();
}

extern "C"
{
    rayTracer::IFactory<rayTracer::IPrimitive> *entryPoint()
    {
        return new InfinitePlanFactory;
    }

    rayTracer::PluginType getLibType()
    {
        return rayTracer::PluginType::PRIMITIVE;
    }
}
