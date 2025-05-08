/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "IPrimitive.hpp"
#include "IFactory.hpp"
#include <memory>
#include "PluginTypes.hpp"

class Sphere: public IPrimitive {
    public:
        Sphere();
        Sphere(math::Point origin, double radius);

        ~Sphere() = default;

        bool Intersect(math::Ray& ray, const std::vector<math::Point>& lights,const std::vector <std::shared_ptr<IPrimitive>> &objs) final;
        void configure(const libconfig::Setting &setting) final;

        double getDiscriminant(math::Ray& ray) final;
        double &getSize() final;
        math::Point &getOrigin() final;
        Material &getMaterial() final;
        int &getID() final;
    private:
        Material _material;
        math::Point _origin;
        double _radius;
        int _ID;
};

class SphereFactory: public rayTracer::IFactory<IPrimitive> {
    public:
        SphereFactory() = default;
        ~SphereFactory() = default;

        std::shared_ptr<IPrimitive> build() final;
};

#endif /* !SPHERE_HPP_ */
