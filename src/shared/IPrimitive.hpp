/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Primitive
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include "../static_libs/math/Ray.hpp"
#include <vector>
class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual double getDiscriminant(math::Ray& ray) = 0;
        virtual bool Intersect(math::Ray& ray, const std::vector<math::Point>& lights,const std::vector <std::unique_ptr<IPrimitive>> &objs)= 0;
        virtual math::Point &getOrigin() = 0;
        virtual double &getSize() = 0;
        virtual void lightShadowSym(math::Vector normal, math::Vector hitPoint, math::Ray &ray, const std::vector<math::Point>& lights, const std::vector<std::unique_ptr<IPrimitive>>& objs) = 0;

};

#endif /* !IPRIMITIVE_HPP_ */
