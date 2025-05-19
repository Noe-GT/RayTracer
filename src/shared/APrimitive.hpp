/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** rayTracer::APrimitive
*/

#ifndef APRIMITIVE_HPP_
#define APRIMITIVE_HPP_

#include "IPrimitive.hpp"
#include <algorithm>

namespace math {
    class CollisionUtils;
};

namespace rayTracer {
    class APrimitive : public rayTracer::IPrimitive {
        public:
            APrimitive();
            ~APrimitive() = default;

            virtual int &getID() final;
            virtual Material &getMaterial() final;
            virtual math::Point &getOrigin() override;
            virtual bool Intersect(math::Ray& ray, const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &lights, const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &objs) override = 0;
            virtual math::CollisionUtils Collide(math::Ray& ray) override = 0;
            virtual void configure(const libconfig::Setting &setting, int id) override;
            virtual double getDiscriminant(math::Ray& ray) override = 0;
            virtual double &getSize() override = 0;

        protected:
            int _id;
            math::Point _origin;
            Material _material;
    };
};

#endif /* !APRIMITIVE_HPP_ */
