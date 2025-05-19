/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** InfinitePlan
*/

#pragma once

#include "APrimitive.hpp"
#include "IFactory.hpp"
#include <memory>
#include "PluginTypes.hpp"

class InfinitePlan: public rayTracer::APrimitive {
    public:
        InfinitePlan();
        InfinitePlan(math::Point origin, double radius);
        ~InfinitePlan() = default;

        bool Intersect(math::Ray& ray, const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &lights,const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &objs) final;
        math::CollisionUtils Collide(math::Ray& ray) final;
        void configure(const libconfig::Setting &setting, int id) final;

        double getDiscriminant(math::Ray& ray) final;
        double &getSize() final;

    private:
        Material _material;
        double _radius;
};

class InfinitePlanFactory: public rayTracer::IFactory<rayTracer::IPrimitive> {
    public:
        InfinitePlanFactory() = default;
        ~InfinitePlanFactory() = default;

        std::shared_ptr<rayTracer::IPrimitive> build() final;
};
