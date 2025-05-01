/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../../shared/IPrimitive.hpp"
class Sphere: public IPrimitive {
    public:
        Sphere();
        Sphere(math::Point origin, double radius);
        ~Sphere() = default;
        double getDiscriminant(math::Ray& ray) final;
        bool Intersect(math::Ray& ray, const std::vector<math::Point>& lights, const std::vector <std::unique_ptr<IPrimitive>> &objs) final;
        math::Point &getOrigin() final;
        double &getSize() final;
        void lightShadowSym(math::Vector normal, math::Vector hitPoint, math::Ray &ray, const std::vector<math::Point>& lights, const std::vector<std::unique_ptr<IPrimitive>>& objs) final;

    private:
    math::Point _origin;
    double _radius;
};

#endif /* !SPHERE_HPP_ */
