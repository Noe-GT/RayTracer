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
class IPrimitive;

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

            void computeReflection(IPrimitive &me,
                math::Ray &ray,
                const std::vector<std::shared_ptr<IPrimitive>> &light,
                const std::vector<std::shared_ptr<IPrimitive>> &objs,
                const math::Color &ambiantColor);
            void computeShadows(IPrimitive &me,
                math::Ray &ray,
                const std::vector<std::shared_ptr<IPrimitive>> &light,
                const std::vector<std::shared_ptr<IPrimitive>> &objs,
                const math::Color &ambiantColor);
            void computeTransparency(IPrimitive &me,
                math::Ray &ray,
                const std::vector<std::shared_ptr<IPrimitive>> &light,
                const std::vector<std::shared_ptr<IPrimitive>> &objs,
                const math::Color &ambiantColor);

    private:
        double _a;
        double _b;
        double _c;
        double _t;
        double _discriminant;
        bool _hasCollision;
        math::Vector _hitPoint;
        math::Vector _normal;

    };
}