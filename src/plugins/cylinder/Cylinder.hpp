/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "APrimitive.hpp"
#include "IFactory.hpp"
#include <memory>
#include "PluginTypes.hpp"
#include "Exceptions.hpp"

class Cylinder: public APrimitive {
    public:
        Cylinder();
        Cylinder(math::Point origin, double radius, double height);
        ~Cylinder() = default;

        bool Intersect(math::Ray& ray, const std::vector <std::shared_ptr<IPrimitive>> &lights,const std::vector <std::shared_ptr<IPrimitive>> &objs) final;
        math::CollisionUtils Collide(math::Ray& ray) final;
        void configure(const libconfig::Setting &setting, int id) final;

        double getDiscriminant(math::Ray& ray) final;
        double &getSize() final;

    private:
        bool intersectBottomBase(math::Ray& ray, math::CollisionUtils &CU);
        bool intersectTopBase(math::Ray& ray, math::CollisionUtils &CU);
        bool intersectCylinder(math::Ray& ray, math::CollisionUtils &CU);
        double _radius;
        double _height;
        math::Vector _rotation;
        Material _material;
};

class CylinderFactory: public rayTracer::IFactory<IPrimitive> {
    public:
        CylinderFactory() = default;
        ~CylinderFactory() = default;

        std::shared_ptr<IPrimitive> build() final;
};

#endif /* !CYLINDER_HPP_ */
