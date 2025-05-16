/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "APrimitive.hpp"
#include "IFactory.hpp"
#include <memory>
#include "PluginTypes.hpp"
#include "Exceptions.hpp"

class Cone: public APrimitive {
    public:
        Cone();
        Cone(math::Point origin, double radius, double height);
        ~Cone() = default;

        bool Intersect(math::Ray& ray, const std::vector <std::shared_ptr<IPrimitive>> &lights,const std::vector <std::shared_ptr<IPrimitive>> &objs) final;
        math::CollisionUtils Collide(math::Ray& ray) final;
        void configure(const libconfig::Setting &setting, int id) final;

        double getDiscriminant(math::Ray& ray) final;
        double &getSize() final;

    private:
        bool intersectBase(math::Ray& ray, math::CollisionUtils &CU);
        bool intersectCone(math::Ray& ray, math::CollisionUtils &CU);
        double _radius;
        double _height;
        math::Vector _orientation;
        Material _material;
};

class ConeFactory: public rayTracer::IFactory<IPrimitive> {
    public:
        ConeFactory() = default;
        ~ConeFactory() = default;

        std::shared_ptr<IPrimitive> build() final;
};

#endif /* !CONE_HPP_ */
