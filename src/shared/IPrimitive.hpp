/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Primitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "Ray.hpp"
#include "Noise.hpp"
#include "CollisionUtils.hpp"
#include "Material.hpp"
#include <libconfig.h++>

namespace math {
    class CollisionUtils;
};

namespace rayTracer {
    class IPrimitive {
        public:
            virtual ~IPrimitive() = default;
            virtual bool Intersect(math::Ray& ray, const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &lights,const std::vector <std::shared_ptr<rayTracer::IPrimitive>> &objs) = 0;
            virtual math::CollisionUtils Collide(math::Ray& ray) = 0;
            virtual void configure(const libconfig::Setting &setting, int id) = 0;
            virtual double getDiscriminant(math::Ray& ray) = 0;
            virtual math::Point &getOrigin() = 0;
            virtual double &getSize() = 0;
            virtual Material &getMaterial() = 0;
            virtual int &getID() = 0;
    };
};

#endif /* !IPRIMITIVE_HPP_ */
