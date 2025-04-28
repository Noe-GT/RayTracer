/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** RayTracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "math/Ray.hpp"
#include "pluginHandling/DLLoader.hpp"
#include "pluginHandling/LibLister.hpp"
#include "External.hpp"
#include "Config.hpp"
// #include "solid/sphere/Sphere.hpp"

namespace rayTracer {
    class RayTracer {
        public:
            RayTracer(const double &_pictureH, const double &_pictureW);
            ~RayTracer();
            void run();
            math::Color ray_color(const math::Ray& r);
            void loadPlugins();

        private:
            const double _pictureH;
            const double _pictureW;
            std::vector<rayTracer::DLLoader> _plugins;
            std::map<std::string, std::unique_ptr<rayTracer::DLLoader>> _primitivePLoaders;
    };
};

#endif /* !RAYTRACER_HPP_ */
