/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "APrimitive.hpp"
#include "IFactory.hpp"
#include <memory>
#include "PluginTypes.hpp"

class Sphere: public rayTracer::APrimitive {
    public:
        Sphere();
        Sphere(math::Point origin, double radius);
        ~Sphere() = default;

        bool Intersect(math::Ray& ray, const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &lights,const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &objs) final;
        math::CollisionUtils Collide(math::Ray& ray) final;
        void configure(const libconfig::Setting &setting, int id) final;

        double getDiscriminant(math::Ray& ray) final;
        double &getSize() final;

    private:
        Material _material;
        double _radius;
};

class SphereFactory: public rayTracer::IFactory<rayTracer::IPrimitive> {
    public:
        SphereFactory() = default;
        ~SphereFactory() = default;

        std::shared_ptr<rayTracer::IPrimitive> build() final;
};

#endif /* !SPHERE_HPP_ */
