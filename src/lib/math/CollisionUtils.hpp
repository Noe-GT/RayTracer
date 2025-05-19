/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** CollisionUtils.hpp
*/

#pragma once

#include "IPrimitive.hpp"
#include "Material.hpp"
#include <stdexcept>
#include <cmath>
#include "Ray.hpp"
#include <vector>

namespace rayTracer {
    class IPrimitive;
}

namespace math {
    class CollisionUtils {
        public:
            CollisionUtils();

            double getA() const;
            double getB() const;
            double getC() const;
            double getT() const;
            double getDiscriminant() const;
            math::Vector getHitPoint() const;
            math::Vector getNormal() const;
            bool hasCollision() const;

            void setHitPoint(math::Vector newVal);
            void setNormal(math::Vector newVal);
            void setT(double newVal);
            void setA(double newVal);
            void setB(double newVal);
            void setC(double newVal);
            void setDiscriminant(double newVal);
            void setHasCollision(bool newVal);

            void computeReflection(rayTracer::IPrimitive &me,
                math::Ray &ray,
                const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &light,
                const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &objs,
                const math::Color &ambiantColor);
            void computeShadows(rayTracer::IPrimitive &me,
                math::Ray &ray,
                const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &light,
                const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &objs,
                const math::Color &ambiantColor);
            void computeTransparency(rayTracer::IPrimitive &me,
                math::Ray &ray,
                const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &light,
                const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &objs,
                const math::Color &ambiantColor);

    private:
        float computeShadowsLight(const std::shared_ptr<rayTracer::IPrimitive> &light, rayTracer::IPrimitive &primitive, const std::vector<std::shared_ptr<rayTracer::IPrimitive>> &objs);

        double _a;
        double _b;
        double _c;
        double _t;
        double _discriminant;
        bool _hasCollision;
        math::Vector _hitPoint;
        math::Vector _normal;

    };
};